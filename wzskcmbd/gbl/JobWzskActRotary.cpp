/**
	* \file JobWzskActRotary.cpp
	* job handler for job JobWzskActRotary (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskActRotary.h"

#include "JobWzskActRotary_blks.cpp"
#include "JobWzskActRotary_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskActRotary::Shrdat
 ******************************************************************************/

JobWzskActRotary::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskActRotary", "Shrdat")
		{
};

void JobWzskActRotary::Shrdat::init(
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
	// IP Shrdat.init --- IEND
};

void JobWzskActRotary::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskActRotary
 ******************************************************************************/

JobWzskActRotary::JobWzskActRotary(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACTROTARY, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcdcvsp = NULL;
	srctivsp = NULL;
	srczuvsp = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	if (srvNotCli) if (evalSrcdcvspConstr(dbswzsk)) srcdcvsp = new JobWzskSrcDcvsp(xchg, dbswzsk, jref, ixWzskVLocale);
	if (srvNotCli) if (evalSrctivspConstr(dbswzsk)) srctivsp = new JobWzskSrcTivsp(xchg, dbswzsk, jref, ixWzskVLocale);
	if (srvNotCli) if (evalSrczuvspConstr(dbswzsk)) srczuvsp = new JobWzskSrcZuvsp(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- IBEGIN
	if (srvNotCli) {
		unsigned int TStep = lround(10000.0/2.0 / (((float) stg.ppr) * stg.omega / 360.0)); // 10000/2: tkclk baseline, omega/360: unit is °/s

		if (srczuvsp) srczuvsp->shrdat.hw.rotary->config(VecVWskdZuvspRotaryStepmode::QUARTER, TStep); // tixVStepmode={full,half,quarter},TStep=[uint8]
	};
	// IP constructor.cust3 --- IEND

	// IP constructor.spec3 --- INSERT
};

JobWzskActRotary::~JobWzskActRotary() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void JobWzskActRotary::updateAngle(
			DbsWzsk* dbswzsk
		) {
	float angle_old;

	string s;

	shrdat.wlockAccess(jref, "updateAngle");

	angle_old = shrdat.angle;

	if (srcdcvsp) srcdcvsp->rotary_getInfo(s, shrdat.angle);
	else if (srctivsp) srctivsp->rotary_getInfo(s, shrdat.angle);
	else if (srczuvsp) srczuvsp->rotary_getInfo(s, shrdat.angle);

	shrdat.wunlockAccess(jref, "updateAngle");

	if (shrdat.angle != angle_old) xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "angleTarget");
};
// IP cust --- IEND

// IP spec --- INSERT

bool JobWzskActRotary::moveto(
			DbsWzsk* dbswzsk
			, const float target // in deg
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActRotary*) srv)->moveto(dbswzsk, target);

		} else retval = false;

		return retval;
	};

	lockAccess("moveto");

	// IP moveto --- IBEGIN
	if (ixVSge != VecVSge::IDLE) changeStage(dbswzsk, VecVSge::IDLE);

	shrdat.wlockAccess(jref, "moveto");

	//cout << "JobWzskActRotary::moveto() target = " << target << endl;

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

bool JobWzskActRotary::stop(
			DbsWzsk* dbswzsk
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActRotary*) srv)->stop(dbswzsk);

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

bool JobWzskActRotary::turn(
			DbsWzsk* dbswzsk
			, const bool ccwNotCw
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActRotary*) srv)->turn(dbswzsk, ccwNotCw);

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

bool JobWzskActRotary::zero(
			DbsWzsk* dbswzsk
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActRotary*) srv)->zero(dbswzsk);

		} else retval = false;

		return retval;
	};

	lockAccess("zero");

	// IP zero --- IBEGIN
	if (ixVSge == VecVSge::IDLE) {
		if (srcdcvsp) srcdcvsp->rotary_zero();
		else if (srctivsp) srctivsp->rotary_zero();
		else if (srczuvsp) srczuvsp->rotary_zero();

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

void JobWzskActRotary::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD)) {
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

void JobWzskActRotary::handleTimerWithSrefMonInSgeMove(
			DbsWzsk* dbswzsk
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP handleTimerWithSrefMonInSgeMove --- INSERT
	changeStage(dbswzsk, ixVSge);
};

void JobWzskActRotary::handleTimerWithSrefCallbackInSgeMove(
			DbsWzsk* dbswzsk
		) {
	changeStage(dbswzsk, ixVSge);
};

void JobWzskActRotary::changeStage(
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

string JobWzskActRotary::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::MOVE) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::MOVE) retval = "moving";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskActRotary::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void JobWzskActRotary::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskActRotary::enterSgeMove(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::MOVE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeMove --- IBEGIN
	float delta;
	unsigned int dt;

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

			if ((delta == -360.0) || (delta == 360.0)) {
				// no time limit
				shrdat.t1 = 1e99;

				if (srcdcvsp) srcdcvsp->rotary_set(true, (delta == -360.0));
				else if (srctivsp) srctivsp->rotary_set(true, (delta == -360.0));
				else if (srczuvsp) srczuvsp->rotary_set(true, (delta == -360.0));

			} else {
				shrdat.t1 = shrdat.t0 + 1.0e-6 * dt;

				if (srcdcvsp) srcdcvsp->rotary_moveto(shrdat.target);
				else if (srctivsp) srctivsp->rotary_moveto(shrdat.target);
				else if (srczuvsp) srczuvsp->rotary_moveto(shrdat.target);
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

void JobWzskActRotary::leaveSgeMove(
			DbsWzsk* dbswzsk
		) {
	invalidateWakeups();
	// IP leaveSgeMove --- IBEGIN
	updateAngle(dbswzsk);

	if (srcdcvsp) srcdcvsp->rotary_set(false, false);
	else if (srctivsp) srctivsp->rotary_set(false, false);
	else if (srczuvsp) srczuvsp->rotary_set(false, false);
	// IP leaveSgeMove --- IEND
};

bool JobWzskActRotary::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if src*vsp "step" claim can be fulfilled

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;

	bool available;
	bool reattributed;

	CsjobWzsk* srcvsp = NULL;
	bool vspTakenNotAvailable, vspFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
		};
	};

	// add or remove "step" claim with src*vsp
	if (srcdcvsp) srcvsp = srcdcvsp;
	else if (srctivsp)  srcvsp = srctivsp;
	else if (srczuvsp) srcvsp = srczuvsp;

	if (srcvsp) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcvsp);
		else xchg->addCsjobClaim(dbswzsk, srcvsp, new Wzsk::ClaimVsp(false, Wzsk::ClaimVsp::VecWDomain::STEP));

		xchg->getCsjobClaim(srcvsp, vspTakenNotAvailable, vspFulfilled);
	};

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && vspFulfilled;

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
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;
		claim->takenNotAvailable = !retractable;
	};

	mod = true; // for simplicity

	// IP handleClaim --- IEND

	return mod;
};
