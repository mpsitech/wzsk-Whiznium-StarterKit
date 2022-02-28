/**
	* \file JobWzskSrcClnxevb.cpp
	* job handler for job JobWzskSrcClnxevb (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskSrcClnxevb.h"

#include "JobWzskSrcClnxevb_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskSrcClnxevb::Shrdat
 ******************************************************************************/

JobWzskSrcClnxevb::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskSrcClnxevb", "Shrdat")
		{
};

void JobWzskSrcClnxevb::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	if (xchg->stgwzskglobal.ixWzskVTarget != VecWzskVTarget::CLNXEVB) return;

	try {
		hw.init(stg.path, 115200, 115200);//5000000, 5000000);

		hw.rxtxdump = true;
		hw.reset();

		t0 = Wzsk::getNow();

	} catch (DbeException& e) {
		cout << e.err << endl;
	};

	excdump = true;
	verbose = true;
	// IP Shrdat.init --- IEND
};

void JobWzskSrcClnxevb::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	hw.term();
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskSrcClnxevb
 ******************************************************************************/

JobWzskSrcClnxevb::JobWzskSrcClnxevb(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKSRCCLNXEVB, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskSrcClnxevb::~JobWzskSrcClnxevb() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
JobWzskSrcClnxevb::Claim::Claim(
			const bool retractable
			, const bool all
			, const bool laser
			, const bool step
		) :
			Sbecore::Claim(retractable)
		{
	this->all = all;
	this->laser = laser;
	this->step = step;
};


bool JobWzskSrcClnxevb::getAngle(
			float& angle // in °
		) {
	bool success = false;

	uint8_t tixVState;
	uint16_t _angle;

	try {
		shrdat.hw.step->getInfo(tixVState, _angle);

		angle = ((float) _angle) * 360.0/1000.0;

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcClnxevb::moveto(
			float& _angle
			, const float omega // in 1/s
		) {
	bool success = false;

	uint16_t angle;

	uint8_t Tstep;

	float angle_imd = _angle;

	while (angle_imd >= 360.0) angle_imd -= 360.0;
	while (angle_imd < 0.0) angle_imd += 360.0;

	angle = lround(1000.0 * angle_imd/360.0);
	if (angle == 1000) angle = 0;

	// rotational speed is 1 / (1000 * Tstep * 2e-4s)
	float Tstep_imd = 1.0 / (1000.0 * omega * 2e-4);

	if (Tstep_imd < 25.0) Tstep = 25;
	else if (Tstep_imd > 255.0) Tstep = 255;
	else Tstep = lround(Tstep_imd);

	try {
		shrdat.hw.step->moveto(angle, Tstep);
		_angle = 360.0 * ((float) angle) / 1000.0; // fix target to raster

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcClnxevb::setStep(
			const bool rng
			, const bool ccwNotCw
			, const float omega // in 1/s
		) {
	bool success = false;

	uint8_t Tstep;

	// rotational speed is 1 / (1000 * Tstep * 2e-4s)
	float Tstep_imd = 1.0 / (1000.0 * omega * 2e-4);

	if (Tstep_imd < 25.0) Tstep = 25;
	else if (Tstep_imd > 255.0) Tstep = 255;
	else Tstep = lround(Tstep_imd);

	try {
		shrdat.hw.step->set(rng, ccwNotCw, Tstep);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

double JobWzskSrcClnxevb::tkstToT(
			const uint32_t tkst
		) {
	return(shrdat.t0 + ((double) tkst) / 10000.0);
};

bool JobWzskSrcClnxevb::laser_set(
			const uint16_t l
			, const uint16_t r
		) {
	bool success = false;

	try {
		shrdat.hw.laser->set(l, r);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcClnxevb::step_zero() {
	bool success = false;

	try {
		shrdat.hw.step->zero();

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcClnxevb::tkclksrc_getTkst(
			uint32_t& tkst
		) {
	bool success = false;

	try {
		shrdat.hw.tkclksrc->getTkst(tkst);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskSrcClnxevb::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tstartRxtxdump" << endl;
			cout << "\tstopRxtxdump" << endl;
			cout << "\ttest" << endl;
		} else if (req->cmd == "startRxtxdump") {
			req->retain = handleStartRxtxdump(dbswzsk);

		} else if (req->cmd == "stopRxtxdump") {
			req->retain = handleStopRxtxdump(dbswzsk);

		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswzsk);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool JobWzskSrcClnxevb::handleStartRxtxdump(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	shrdat.hw.rxtxdump = true; // IP handleStartRxtxdump --- ILINE
	return retval;
};

bool JobWzskSrcClnxevb::handleStopRxtxdump(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	shrdat.hw.rxtxdump = false; // IP handleStopRxtxdump --- ILINE
	return retval;
};

bool JobWzskSrcClnxevb::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskSrcClnxevb::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::NC: leaveSgeNc(dbswzsk); break;
				case VecVSge::READY: leaveSgeReady(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::NC: _ixVSge = enterSgeNc(dbswzsk, reenter); break;
			case VecVSge::READY: _ixVSge = enterSgeReady(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskSrcClnxevb::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::NC) || (ixVSge == VecVSge::READY) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::NC) retval = "not connected";
			else if (ixVSge == VecVSge::READY) retval = "ready";
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::NC) retval = "nicht verbunden";
			else if (ixVSge == VecVSge::READY) retval = "bereit";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskSrcClnxevb::enterSgeNc(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::NC;

	// IP enterSgeNc --- INSERT

	return retval;
};

void JobWzskSrcClnxevb::leaveSgeNc(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeNc --- INSERT
};

uint JobWzskSrcClnxevb::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- INSERT

	return retval;
};

void JobWzskSrcClnxevb::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

bool JobWzskSrcClnxevb::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - laser/step can be taken up independently by one client at a time
	// - one client taking all trumps laser/step

	Claim* claim = NULL;

	ubigint jrefAll = 0;
	ubigint jrefLaser = 0;
	ubigint jrefStep = 0;

	bool allRetractable = true;
	bool laserRetractable = true;
	bool stepRetractable = true;

	bool allAvailable, laserAvailable, stepAvailable;
	bool allReattributed, laserReattributed, stepReattributed;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			if (claim->all) {
				jrefAll = it->first;
				allRetractable = claim->retractable;
			};
			if (claim->laser) {
				jrefLaser = it->first;
				laserRetractable = claim->retractable;
			};
			if (claim->step) {
				jrefStep = it->first;
				stepRetractable = claim->retractable;
			};
		};
	};

	// try to fulfill, at most one re-attribution per feature
	allReattributed = false;
	laserReattributed = false;
	stepReattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			allAvailable = allRetractable && laserRetractable && stepRetractable;
			laserAvailable = allRetractable && laserRetractable;
			stepAvailable = allRetractable && stepRetractable;

			if (!allAvailable && !laserAvailable && !stepAvailable) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim

				if (claim->all && allAvailable && !laserReattributed && !stepReattributed) {
					if (jrefAll != 0) claims[jrefAll]->fulfilled = false;
					if (jrefLaser != 0) claims[jrefLaser]->fulfilled = false;
					if (jrefStep != 0) claims[jrefStep]->fulfilled = false;

					claim->fulfilled = true;
					allRetractable = claim->retractable;
					allReattributed = true;

				} else if (claim->laser && laserAvailable && !laserReattributed) {
					if (jrefAll != 0) claims[jrefAll]->fulfilled = false;
					if (jrefLaser != 0) claims[jrefLaser]->fulfilled = false;

					claim->fulfilled = true;
					laserRetractable = claim->retractable;
					laserReattributed = true;

				} else if (claim->step && stepAvailable && !stepReattributed) {
					if (jrefAll != 0) claims[jrefAll]->fulfilled = false;
					if (jrefStep != 0) claims[jrefStep]->fulfilled = false;

					claim->fulfilled = true;
					stepRetractable = claim->retractable;
					stepReattributed = true;
				};

				if (allReattributed || (laserReattributed && stepReattributed)) break;
			};

		};

		if (!allAvailable && !laserAvailable && !stepAvailable) break;
		if (allReattributed || (laserReattributed && stepReattributed)) break;
	};

	// update taken status
	allAvailable = allRetractable && laserRetractable && stepRetractable;
	laserAvailable = allRetractable && laserRetractable;
	stepAvailable = allRetractable && stepRetractable;

	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->all) claim->takenNotAvailable = !allAvailable;
		else if (claim->laser) claim->takenNotAvailable = !laserAvailable;
		else if (claim->step) claim->takenNotAvailable = !stepAvailable;
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};
