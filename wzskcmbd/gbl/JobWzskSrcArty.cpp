/**
	* \file JobWzskSrcArty.cpp
	* job handler for job JobWzskSrcArty (implementation)
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

#include "JobWzskSrcArty.h"

#include "JobWzskSrcArty_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskSrcArty::Shrdat
 ******************************************************************************/

JobWzskSrcArty::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskSrcArty", "Shrdat")
		{
};

void JobWzskSrcArty::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	if (xchg->stgwzskglobal.ixWzskVTarget != VecWzskVTarget::ARTY) return;

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

void JobWzskSrcArty::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	hw.term();
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskSrcArty
 ******************************************************************************/

JobWzskSrcArty::JobWzskSrcArty(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKSRCARTY, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskSrcArty::~JobWzskSrcArty() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
JobWzskSrcArty::Claim::Claim(
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

bool JobWzskSrcArty::setExposure(
			const bool autoNotManual
			, const float _Texp
		) {
	bool success = false;

	uint16_t Texp;
	
	float Texp_imd = 16.0 * _Texp / (2844.0/25e6); // units of line*16, one line takes (2844/25e6)s = 113.76µs at pclk = 25MHz

	if (Texp_imd < 1.0) Texp = 1;
	else if (Texp_imd > 65535.0) Texp = 65535;
	else Texp = lround(Texp_imd);

	if (!autoNotManual) {
		success = camif_modReg(0x3503, 0x03, 0x03);

		if (success) success = camif_setReg(0x3502, (Texp & 0x000F) << 4);
		if (success) success = camif_setReg(0x3501, Texp >> 4);
		if (success) success = camif_setReg(0x3500, Texp >> 12);

	} else {
		success = camif_modReg(0x3503, 0x03, 0x00);
	};

	return success;
};

bool JobWzskSrcArty::setFocus(
			const float _focus
		) {
	bool success = false;

	uint16_t focus;
	
	if (_focus < 0.0) focus = 0;
	else if (_focus > 1.0) focus = 1023;
	else focus = lround(1023.0 * _focus);

	success = camif_modReg(0x3603, 0x3F, focus >> 4);
	if (success) success = camif_modReg(0x3602, 0xF0, focus << 4);

	return success;
};

bool JobWzskSrcArty::getAngle(
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

bool JobWzskSrcArty::moveto(
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

bool JobWzskSrcArty::setStep(
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

double JobWzskSrcArty::tkstToT(
			const uint32_t tkst
		) {
	return(shrdat.t0 + ((double) tkst) / 10000.0);
};

bool JobWzskSrcArty::camacq_setGrrd(
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

bool JobWzskSrcArty::camacq_setPvw(
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

bool JobWzskSrcArty::camacq_getPvwinfo(
			uint8_t& tixVPvwbufstate
			, uint32_t& tkst
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

bool JobWzskSrcArty::camif_setRng(
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

bool JobWzskSrcArty::camif_setReg(
			const uint16_t regaddr
			, const uint8_t val
		) {
	bool success = false;

	try {
		shrdat.hw.camif->setReg(regaddr, val);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcArty::camif_getReg(
			const uint16_t regaddr
			, uint8_t& val
		) {
	bool success = false;

	try {
		shrdat.hw.camif->setRegaddr(regaddr);
		shrdat.hw.camif->getReg(val);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcArty::camif_modReg(
			const uint16_t regaddr
			, const uint8_t mask
			, const uint8_t val
		) {
	bool success = false;

	try {
		shrdat.hw.camif->modReg(regaddr, mask, val);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcArty::featdet_set(
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

bool JobWzskSrcArty::featdet_getInfo(
			uint8_t& tixVFlgbufstate
			, uint8_t& tixVThdstate
			, uint32_t& tkst
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

bool JobWzskSrcArty::featdet_getCornerinfo(
			uint8_t& shift
			, uint8_t& scoreMin
			, uint8_t& scoreMax
		) {
	bool success = false;

	try {
		shrdat.hw.featdet->getCornerinfo(shift, scoreMin, scoreMax);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcArty::featdet_setCorner(
			const bool linNotLog
			, const uint32_t Ntrg
		) {
	bool success = false;

	try {
		shrdat.hw.featdet->setCorner(linNotLog, Ntrg);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcArty::featdet_setThd(
			const uint8_t lvlFirst
			, const uint8_t lvlSecond
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

bool JobWzskSrcArty::featdet_triggerThd() {
	bool success = false;

	try {
		shrdat.hw.featdet->triggerThd();

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcArty::laser_set(
			const uint16_t l
			, const uint16_t r
		) {
	bool success = false;

	try {
		//shrdat.hw.laser->set(l, r);
		shrdat.hw.laser->set(r, l); // this is because the prototype has short laser wires and L/R are interchanged

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcArty::step_zero() {
	bool success = false;

	try {
		shrdat.hw.step->zero();

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcArty::tkclksrc_getTkst(
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

void JobWzskSrcArty::handleRequest(
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

bool JobWzskSrcArty::handleStartRxtxdump(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	shrdat.hw.rxtxdump = true; // IP handleStartRxtxdump --- ILINE
	return retval;
};

bool JobWzskSrcArty::handleStopRxtxdump(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	shrdat.hw.rxtxdump = false; // IP handleStopRxtxdump --- ILINE
	return retval;
};

bool JobWzskSrcArty::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- IBEGIN

	// stress test for AXI
	const unsigned int Ntick = 10000;
	const unsigned int Nmax = 10000000;

	unsigned int Nfail = 0;

	uint tkst;

	for (unsigned int i = 0; i < Nmax; i++) {
		if (!tkclksrc_getTkst(tkst)) Nfail++;
		else Nfail = 0;

		if (Nfail > 5) {
			cout << "\taborting." << endl;
			break;
		};

		if ((i > 0) && ((i%Ntick) == 0)) cout << "\tat " << (tkst/10000) << "." << (tkst%10000) <<  ", " << i << " transfers completed." << endl;
	};

	// IP handleTest --- IEND
	return retval;
};

void JobWzskSrcArty::changeStage(
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

string JobWzskSrcArty::getSquawk(
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

uint JobWzskSrcArty::enterSgeNc(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::NC;

	// IP enterSgeNc --- INSERT

	return retval;
};

void JobWzskSrcArty::leaveSgeNc(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeNc --- INSERT
};

uint JobWzskSrcArty::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- INSERT

	return retval;
};

void JobWzskSrcArty::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

bool JobWzskSrcArty::handleClaim(
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
