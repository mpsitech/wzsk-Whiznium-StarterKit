/**
	* \file JobWzskActServo.cpp
	* job handler for job JobWzskActServo (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskActServo.h"

#include "JobWzskActServo_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskActServo::Shrdat
 ******************************************************************************/

JobWzskActServo::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskActServo", "Shrdat")
		{
};

void JobWzskActServo::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	angle = 0.0;
	target = 0.0;

	ccwNotCw = false;
	start = 0.0;

	t0 = 0.0;
	t1 = 0.0;

	int fd;

	string root, path;

	if (!xchg->stgwzskglobal.fpgaNotV4l2gpio) {
		// set up PWM for sysfs access
		for (int i = 0; i < Npwm; i++) {
			root = stg.pathroot + to_string(i);

			path = root + "/export";

			fd = open(path.c_str(), O_WRONLY);

			if (fd < 0) throw WzskException(WzskException::PWM, {{"msg","error setting up " + path + " for sysfs access"}});

			write(fd, "0", 1);
			
			close(fd);
		};
	};
	// IP Shrdat.init --- IEND
};

void JobWzskActServo::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	int fd;

	string root, path;

	if (!xchg->stgwzskglobal.fpgaNotV4l2gpio) {
		// switch off
		stopGpio();

		// terminate PWM sysfs access
		for (int i = 0; i < Npwm; i++) {
			root = stg.pathroot + to_string(i);

			path = root + "/pwm0/enable";

			fd = open(path.c_str(), O_WRONLY);

			if (fd < 0) throw WzskException(WzskException::PWM, {{"msg","error terminating " + path + " sysfs access"}});

			write(fd, "0", 1);
			
			close(fd);
		};
	};
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskActServo
 ******************************************************************************/

JobWzskActServo::JobWzskActServo(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACTSERVO, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcfpga = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- IBEGIN
	if (srvNotCli) if (xchg->stgwzskglobal.fpgaNotV4l2gpio) srcfpga = new JobWzskSrcFpga(xchg, dbswzsk, jref, ixWzskVLocale);
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- IBEGIN
	if (srvNotCli && srcfpga) srcfpga->step_zero(); // disregards claim fulfilled status
	// IP constructor.cust3 --- IEND

	// IP constructor.spec3 --- INSERT
};

JobWzskActServo::~JobWzskActServo() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void JobWzskActServo::updateAngle(
			DbsWzsk* dbswzsk
		) {
	double t;

	float angle_old;

	shrdat.wlockAccess(jref, "updateAngle");

	angle_old = shrdat.angle;

	if (!srcfpga) {
		t = Wzsk::getNow();

		if (t >= shrdat.t1) {
			shrdat.angle = shrdat.target;

		} else {
			if (!shrdat.ccwNotCw) shrdat.angle = shrdat.start + 360.0 * (Wzsk::getNow() - shrdat.t0) * stg.omega;
			else shrdat.angle = shrdat.start - 360.0 * (Wzsk::getNow() - shrdat.t0) * stg.omega;

			while (shrdat.angle < 0.0) shrdat.angle += 360.0;
			while (shrdat.angle >= 360.0) shrdat.angle -= 360.0;
		};

	} else srcfpga->getAngle(shrdat.angle);

	shrdat.wunlockAccess(jref, "updateAngle");

	if (shrdat.angle != angle_old) xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "angleTarget");
};

void JobWzskActServo::stopGpio() {
	string root, path;

	int fd;

	for (int i = 0; i < Npwm; i++) {
		root = stg.pathroot + to_string(i);

		path = root + "/pwm0/enable";

		fd = open(path.c_str(), O_WRONLY);

		if (fd < 0) throw WzskException(WzskException::PWM, {{"msg","error switching off " + path}});

		write(fd, "0", 1);
		
		close(fd);
	};
};
// IP cust --- IEND

// IP spec --- INSERT

bool JobWzskActServo::moveto(
			DbsWzsk* dbswzsk
			, const float target
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActServo*) srv)->moveto(dbswzsk, target);

		} else retval = false;

		return retval;
	};

	lockAccess("moveto");

	// IP moveto --- IBEGIN
	if (ixVSge != VecVSge::IDLE) changeStage(dbswzsk, VecVSge::IDLE);

	shrdat.wlockAccess(jref, "moveto");

	shrdat.target = target;
	while (shrdat.target < 0.0) shrdat.target += 360.0;
	while (shrdat.target >= 360.0) shrdat.target -= 360.0;

	shrdat.wunlockAccess(jref, "moveto");

	if (shrdat.target != shrdat.angle) {
		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "angleTarget");
		changeStage(dbswzsk, VecVSge::MOVE);
	};
	// IP moveto --- IEND

	unlockAccess("moveto");

	return retval;
};

bool JobWzskActServo::stop(
			DbsWzsk* dbswzsk
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActServo*) srv)->stop(dbswzsk);

		} else retval = false;

		return retval;
	};

	lockAccess("stop");

	// IP stop --- IBEGIN
	if (ixVSge != VecVSge::IDLE) changeStage(dbswzsk, VecVSge::IDLE);
	// IP stop --- IEND

	unlockAccess("stop");

	return retval;
};

bool JobWzskActServo::turn(
			DbsWzsk* dbswzsk
			, const bool ccwNotCw
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActServo*) srv)->turn(dbswzsk, ccwNotCw);

		} else retval = false;

		return retval;
	};

	lockAccess("turn");

	// IP turn --- IBEGIN
	if (ixVSge != VecVSge::IDLE) changeStage(dbswzsk, VecVSge::IDLE);

	shrdat.wlockAccess(jref, "turn");

	shrdat.target = ((ccwNotCw) ? -360.0 : 360.0);

	shrdat.wunlockAccess(jref, "turn");

	xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "angleTarget");
	changeStage(dbswzsk, VecVSge::MOVE);
	// IP turn --- IEND

	unlockAccess("turn");

	return retval;
};

bool JobWzskActServo::zero(
			DbsWzsk* dbswzsk
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActServo*) srv)->zero(dbswzsk);

		} else retval = false;

		return retval;
	};

	lockAccess("zero");

	// IP zero --- IBEGIN
	if (ixVSge == VecVSge::IDLE) {
		if (srcfpga) srcfpga->step_zero();

		shrdat.wlockAccess(jref, "zero");

		shrdat.angle = 0.0;
		shrdat.target = 0.0;

		shrdat.wunlockAccess(jref, "zero");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "angleTarget");

	} else retval = false;
	// IP zero --- IEND

	unlockAccess("zero");

	return retval;
};

void JobWzskActServo::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\ttest" << endl;
		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswzsk);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::MOVETO) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = moveto(dbswzsk, *((const float*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::STOP) && (req->method->parsInv.size() == 0) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = stop(dbswzsk);
		} else if ((ixVMethod == VecVMethod::TURN) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = turn(dbswzsk, *((const bool*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::ZERO) && (req->method->parsInv.size() == 0) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = zero(dbswzsk);
		};

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if ((req->sref == "mon") && (ixVSge == VecVSge::MOVE)) handleTimerWithSrefMonInSgeMove(dbswzsk);
		else if ((req->sref == "callback") && (ixVSge == VecVSge::MOVE)) handleTimerWithSrefCallbackInSgeMove(dbswzsk);
	};
};

bool JobWzskActServo::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskActServo::handleTimerWithSrefMonInSgeMove(
			DbsWzsk* dbswzsk
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP handleTimerWithSrefMonInSgeMove --- INSERT
	changeStage(dbswzsk, ixVSge);
};

void JobWzskActServo::handleTimerWithSrefCallbackInSgeMove(
			DbsWzsk* dbswzsk
		) {
	changeStage(dbswzsk, ixVSge);
};

void JobWzskActServo::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::MOVE: leaveSgeMove(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::MOVE: _ixVSge = enterSgeMove(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskActServo::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::MOVE) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::MOVE) {
				retval = "moving";
				if (shrdat.target == -360.0) retval += " counter-clockwise";
				else if (shrdat.target == 360.0) retval += " clockwise";
				else retval += " towards angle " + to_string(shrdat.target) + "\\u00b0";
			};
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::MOVE) {
				retval = "Bewegung";
				if (shrdat.target == -360.0) retval += " gegen den Uhrzeigersinn";
				else if (shrdat.target == 360.0) retval += " im Uhrzeigersinn";
				else retval += " zu Winkel " + to_string(shrdat.target) + "\\u00b0";
			};
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWzskActServo::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void JobWzskActServo::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskActServo::enterSgeMove(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::MOVE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeMove --- IBEGIN
	float delta;
	unsigned int dt;

	unsigned int period;
	timespec deltat = {0};

	int fd;

	string root, path;

	string s;

	if (!reenter) {
		shrdat.start = shrdat.angle;

		delta = shrdat.target;
		if ((delta != -360.0) && (delta != 360.0)) delta -= shrdat.angle;

		if (delta != 0.0) {
			// determine in which direction to turn, and for how long
			if (delta == -360.0) {
				shrdat.ccwNotCw = true;

			} else if ((delta > -360.0) && (delta <= -180.0)) {
				shrdat.ccwNotCw = false;
				delta += 360.0; // 0 .. 180.0, e.g. -330 becomes +60

			} else if ((delta > -180.0) && (delta <= 0.0)) {
				shrdat.ccwNotCw = true;

			} else if ((delta > 0.0) && (delta <= 180.0)) {
				shrdat.ccwNotCw = false;

			} else if ((delta > 180.0) && (delta < 360.0)) {
				shrdat.ccwNotCw = true;
				delta -= 360.0; // -180 .. 0.0, e.g. 330 becomes -60

			} else if (delta == 360.0) {
				shrdat.ccwNotCw = false;
			};

			dt = fabs(1e6 * delta / 360.0 / stg.omega); // in microseconds

			shrdat.t0 = Wzsk::getNow();

			if ((delta == -360.0) || (delta == 360.0)) shrdat.t1 = 1e99; // no time limit
			else shrdat.t1 = shrdat.t0 + 1.0e-6 * dt;

			if (!srcfpga) {
				// omega in 1/s, 4x 512 pulses per revolution, period in ns
				period = lround(1e9 / 512.0 / stg.omega);
				deltat.tv_nsec = period / 4; // delay between four phases

				// set parameters
				for (int i = 0; i < Npwm; i++) {
					root = stg.pathroot + to_string(i);

					path = root + "/pwm0/duty_cycle";

					fd = open(path.c_str(), O_WRONLY);

					if (fd < 0) throw WzskException(WzskException::PWM, {{"msg","error setting duty cycle for " + path}});

					// duty_cycle 3/8 (half-step) or 1/2 (full-step, higher torque)
					if (!stg.halfstepNotTorque) s = to_string(period/2);
					else s = to_string(3 * period / 8);

					write(fd, s.c_str(), s.length());

					close(fd);

					// period
					path = root + "/pwm0/period";

					fd = open(path.c_str(), O_WRONLY);

					if (fd < 0) throw WzskException(WzskException::PWM, {{"msg","error setting period for " + path}});

					s = to_string(period);
					write(fd, s.c_str(), s.length());

					close(fd);
				};

				if ((delta != -360.0) && (delta != 360.0)) wrefLast = xchg->addWakeup(jref, "mon", dt);

				// switch on in synchronized fashion
				for (int i = 0; i < Npwm; i++) {
					if (shrdat.ccwNotCw) root = stg.pathroot + to_string(Npwm - i - 1);
					else root = stg.pathroot + to_string(i);

					path = root + "/pwm0/enable";

					fd = open(path.c_str(), O_WRONLY);

					if (fd < 0) throw WzskException(WzskException::PWM, {{"msg","error switching on " + path}});

					write(fd, "1", 1);
					
					close(fd);

					if ((i + 1) < Npwm) nanosleep(&deltat, NULL);
				};

			} else {
				if ((delta == -360.0) || (delta == 360.0)) srcfpga->setStep(true, (delta == -360.0), stg.omega);
				else srcfpga->moveto(shrdat.target, stg.omega);
			};
		};

	} else {
		// update angle and/or stop movement
		updateAngle(dbswzsk);

		if (shrdat.angle == shrdat.target) retval = VecVSge::IDLE;
	};
	// IP enterSgeMove --- IEND

	return retval;
};

void JobWzskActServo::leaveSgeMove(
			DbsWzsk* dbswzsk
		) {
	invalidateWakeups();
	// IP leaveSgeMove --- IBEGIN
	updateAngle(dbswzsk);

	if (!srcfpga) stopGpio();
	else srcfpga->setStep(false, false, 0.0);
	// IP leaveSgeMove --- IEND
};

bool JobWzskActServo::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if srcfpga "step" claim can be fulfilled

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;

	bool available;
	bool reattributed;

	bool stepTakenNotAvailable, stepFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
		};
	};

	if (srcfpga) {
		// add or remove "step" claim with srcfpga
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcfpga);
		else xchg->addCsjobClaim(dbswzsk, srcfpga, new JobWzskSrcFpga::Claim(false, false, false, false, false, true));

		xchg->getCsjobClaim(srcfpga, stepTakenNotAvailable, stepFulfilled);

	} else stepFulfilled = true;

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && stepFulfilled;

			if (!available) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim
				if (it->first != jrefFulfilled) {
					if (jrefFulfilled != 0) claims[jrefFulfilled]->fulfilled = false;

					claim->fulfilled = true;
					retractable = claim->retractable;
					reattributed = true;
				};

				if (reattributed) break;
			};
		};

		if (!available) break;
		if (reattributed) break;
	};

	// update taken status
	available = retractable;

	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		claim->takenNotAvailable = !available;
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};



