/**
	* \file JobWzskSrcFpga.cpp
	* job handler for job JobWzskSrcFpga (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskSrcFpga.h"

#include "JobWzskSrcFpga_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskSrcFpga::Shrdat
 ******************************************************************************/

JobWzskSrcFpga::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskSrcFpga", "Shrdat")
		{
};

void JobWzskSrcFpga::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	try {
		hw.init(stg.path);

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

void JobWzskSrcFpga::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	hw.term();
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskSrcFpga
 ******************************************************************************/

JobWzskSrcFpga::JobWzskSrcFpga(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKSRCFPGA, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskSrcFpga::~JobWzskSrcFpga() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
JobWzskSrcFpga::Claim::Claim(
			const bool retractable
			, const bool all
			, const bool flg
			, const bool pvw
			, const bool laser
			, const bool step
		) :
			Sbecore::Claim(retractable)
		{
	this->all = all;
	this->flg = flg;
	this->pvw = pvw;
	this->laser = laser;
	this->step = step;
};

bool JobWzskSrcFpga::setOmega(
			const float omega // in 1/s
		) {
	bool success = false;

	utinyint Tstep;

	// rotational speed is 1 / (4096 * Tstep * 1e-4s)
	float Tstep_imd = 1.0 / (4096.0 * omega * 1e-4);

	if (Tstep_imd < 50.0) Tstep = 50;
	else if (Tstep_imd > 255.0) Tstep = 255;
	else Tstep = lround(Tstep_imd);

	try {
		shrdat.hw.step->set(false, false, Tstep);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::getAngle(
			float& angle // in °
		) {
	bool success = false;

	utinyint tixVState;
	usmallint _angle;

	try {
		shrdat.hw.step->getInfo(tixVState, _angle);

		angle = ((float) _angle) * 360.0/4096.0;

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

double JobWzskSrcFpga::tkstToT(
			const uint tkst
		) {
	return(shrdat.t0 + ((double) tkst) / 10000.0);
};

bool JobWzskSrcFpga::camacq_setGrrd(
			const bool rng
			, const bool redNotGray
		) {
	bool success = false;

	try {
		shrdat.hw.camacq->setGrrd(rng, redNotGray);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::camacq_setPvw(
			const bool rng
			, const bool rawNotBin
			, const bool grayNotRgb
		) {
	bool success = false;

	try {
		shrdat.hw.camacq->setPvw(rng, rawNotBin, grayNotRgb);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::camacq_getPvwinfo(
			utinyint& tixVPvwbufstate
			, uint& tkst
		) {
	bool success = false;

	try {
		shrdat.hw.camacq->getPvwinfo(tixVPvwbufstate, tkst);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::camif_setRng(
			const bool rng
		) {
	bool success = false;

	try {
		shrdat.hw.camif->setRng(rng);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::camif_setFocus(
			const float _focus // 0 .. 1
		) {
	bool success = false;

	usmallint focus;
	
	if (_focus < 0.0) focus = 0;
	else if (_focus > 1.0) focus = 1023;
	else focus = lround(1023.0 * _focus);

	try {
		shrdat.hw.camif->setFocus(focus);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::camif_setTexp(
			const float _Texp // in s
		) {
	bool success = false;

	usmallint Texp;
	
	float Texp_imd = 16.0 * _Texp / (2844.0/25e6); // units of line*16, one line takes (2844/25e6)s = 113.76µs at pclk = 25MHz

	if (Texp_imd < 1.0) Texp = 1;
	else if (Texp_imd > 65535.0) Texp = 65535;
	else Texp = lround(Texp_imd);

	try {
		shrdat.hw.camif->setTexp(Texp);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::featdet_set(
			const bool rng
			, const bool thdNotCorner
			, const bool thdDeltaNotAbs
		) {
	bool success = false;

	try {
		shrdat.hw.featdet->set(rng, thdNotCorner, thdDeltaNotAbs);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::featdet_getInfo(
			utinyint& tixVFlgbufstate
			, utinyint& tixVThdstate
			, uint& tkst
		) {
	bool success = false;

	try {
		shrdat.hw.featdet->getInfo(tixVFlgbufstate, tixVThdstate, tkst);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::featdet_getCornerinfo(
			usmallint& scoreMinMsb
			, uint& scoreMinLsb
			, usmallint& scoreMaxMsb
			, uint& scoreMaxLsb
			, utinyint& shift
			, uint& NCorner
			, utinyint& thd
		) {
	bool success = false;

	try {
		shrdat.hw.featdet->getCornerinfo(scoreMinMsb, scoreMinLsb, scoreMaxMsb, scoreMaxLsb, shift, NCorner, thd);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::featdet_setCorner(
			const uint Ntrg
		) {
	bool success = false;

	try {
		shrdat.hw.featdet->setCorner(Ntrg);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::featdet_setThd(
			const unsigned char lvlFirst
			, const unsigned char lvlSecond
		) {
	bool success = false;

	try {
		shrdat.hw.featdet->setThd(lvlFirst, lvlSecond);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::featdet_triggerThd() {
	bool success = false;

	try {
		shrdat.hw.featdet->triggerThd();

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::laser_set(
			const float _l // 0 .. 1
			, const float _r // 0 .. 1
		) {
	bool success = false;

	usmallint l, r;

	if (_l < 0.0) l = 0.0;
	else if (_l > 1.0) l = 1023.0;
	else l = 1023.0 * _l;

	if (_r < 0.0) r = 0.0;
	else if (_r > 1.0) r = 1023.0;
	else r = 1023.0 * _r;

	try {
		shrdat.hw.laser->set(l, r);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::step_moveto(
			const float _angle // in °
		) {
	bool success = false;

	usmallint angle;

	float angle_imd = _angle;

	while (angle_imd >= 360.0) angle_imd -= 360.0;
	while (angle_imd < 0.0) angle_imd += 360.0;

	angle = lround(4096.0 * angle_imd/360.0);
	if (angle == 4096) angle = 0;

	try {
		shrdat.hw.step->moveto(angle);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::step_zero() {
	bool success = false;

	try {
		shrdat.hw.step->zero();

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcFpga::tkclksrc_getTkst(
			uint& tkst
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

void JobWzskSrcFpga::handleRequest(
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

	};
};

bool JobWzskSrcFpga::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskSrcFpga::changeStage(
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

string JobWzskSrcFpga::getSquawk(
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

uint JobWzskSrcFpga::enterSgeNc(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::NC;

	// IP enterSgeNc --- INSERT

	return retval;
};

void JobWzskSrcFpga::leaveSgeNc(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeNc --- INSERT
};

uint JobWzskSrcFpga::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- INSERT

	return retval;
};

void JobWzskSrcFpga::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

bool JobWzskSrcFpga::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - flag/pvw/laser/step can be taken up independently by one client at a time
	// - one client taking all trumps flag/pvw/laser/step

	Claim* claim = NULL;

	ubigint jrefAll = 0;
	ubigint jrefFlg = 0;
	ubigint jrefPvw = 0;
	ubigint jrefLaser = 0;
	ubigint jrefStep = 0;

	bool allRetractable = true;
	bool flgRetractable = true;
	bool pvwRetractable = true;
	bool laserRetractable = true;
	bool stepRetractable = true;

	bool allAvailable, flgAvailable, pvwAvailable, laserAvailable, stepAvailable;
	bool allReattributed, flgReattributed, pvwReattributed, laserReattributed, stepReattributed;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			if (claim->all) {
				jrefAll = it->first;
				allRetractable = claim->retractable;
			};
			if (claim->flg) {
				jrefFlg = it->first;
				flgRetractable = claim->retractable;
			};
			if (claim->pvw) {
				jrefPvw = it->first;
				pvwRetractable = claim->retractable;
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
	flgReattributed = false;
	pvwReattributed = false;
	laserReattributed = false;
	stepReattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			allAvailable = allRetractable && flgRetractable && pvwRetractable && laserRetractable && stepRetractable;
			flgAvailable = allRetractable && flgRetractable;
			pvwAvailable = allRetractable && pvwRetractable;
			laserAvailable = allRetractable && laserRetractable;
			stepAvailable = allRetractable && stepRetractable;

			if (!allAvailable && !flgAvailable && !pvwAvailable && !laserAvailable && !stepAvailable) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim

				if (claim->all && allAvailable && !flgReattributed && !pvwReattributed && !laserReattributed && !stepReattributed) {
					if (jrefAll != 0) claims[jrefAll]->fulfilled = false;
					if (jrefFlg != 0) claims[jrefFlg]->fulfilled = false;
					if (jrefPvw != 0) claims[jrefPvw]->fulfilled = false;
					if (jrefLaser != 0) claims[jrefLaser]->fulfilled = false;
					if (jrefStep != 0) claims[jrefStep]->fulfilled = false;

					claim->fulfilled = true;
					allRetractable = claim->retractable;
					allReattributed = true;

				} else if (claim->flg && flgAvailable && !flgReattributed) {
					if (jrefAll != 0) claims[jrefAll]->fulfilled = false;
					if (jrefFlg != 0) claims[jrefFlg]->fulfilled = false;

					claim->fulfilled = true;
					flgRetractable = claim->retractable;
					flgReattributed = true;

				} else if (claim->pvw && pvwAvailable && !pvwReattributed) {
					if (jrefAll != 0) claims[jrefAll]->fulfilled = false;
					if (jrefPvw != 0) claims[jrefPvw]->fulfilled = false;

					claim->fulfilled = true;
					pvwRetractable = claim->retractable;
					pvwReattributed = true;

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

				if (allReattributed || (flgReattributed && pvwReattributed && laserReattributed && stepReattributed)) break;
			};

		};

		if (!allAvailable && !flgAvailable && !pvwAvailable && !laserAvailable && !stepAvailable) break;
		if (allReattributed || (flgReattributed && pvwReattributed && laserReattributed && stepReattributed)) break;
	};

	// update taken status
	allAvailable = allRetractable && flgRetractable && pvwRetractable && laserRetractable && stepRetractable;
	flgAvailable = allRetractable && flgRetractable;
	pvwAvailable = allRetractable && pvwRetractable;
	laserAvailable = allRetractable && laserRetractable;
	stepAvailable = allRetractable && stepRetractable;

	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->all) claim->takenNotAvailable = !allAvailable;
		else if (claim->flg) claim->takenNotAvailable = !flgAvailable;
		else if (claim->pvw) claim->takenNotAvailable = !pvwAvailable;
		else if (claim->laser) claim->takenNotAvailable = !laserAvailable;
		else if (claim->step) claim->takenNotAvailable = !stepAvailable;
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};



