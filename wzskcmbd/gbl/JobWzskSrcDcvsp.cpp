/**
	* \file JobWzskSrcDcvsp.cpp
	* job handler for job JobWzskSrcDcvsp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Oct 2025
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskSrcDcvsp.h"

#include "JobWzskSrcDcvsp_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskSrcDcvsp::Shrdat
 ******************************************************************************/

JobWzskSrcDcvsp::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskSrcDcvsp", "Shrdat")
		{
};

void JobWzskSrcDcvsp::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	if (xchg->stgwzskglobal.ixWzskVTarget != VecWzskVTarget::DISCO) return;

	try {
		hw.init(stg.path);
		hw.reset();

		t0 = Wzsk::getNow();

		// version check can fail if either ident.getVer() is not recognized by device or return value doesn't match API version
		bool success;
		string unt, ver, hash, who;

		success = ident_get(unt, ver, hash, who);
		if (!success) cout << "JobWzskSrcDcvsp device version mismatch: identification command not recognized" << endl;

		if (success) {
			success = (unt == "zuvsp");
			if (!success) cout << "JobWzskSrcDcvsp unit mismatch: identified " << unt << " expected zuvsp at path " << stg.path << endl;
		};

		if (success) {
			success = (Version(ver) == Version(WSKD_VERSION));
			if (!success) cout << "JobWzskSrcDcvsp device version mismatch: identified " << ver << " expected " WSKD_VERSION << endl;
		};

		if (success) cout << "JobWzskSrcDcvsp device version " WSKD_VERSION " identified" << endl;

	} catch (DbeException& e) {
		cout << e.err << endl;
	};

	excdump = true;
	verbose = true;
	// IP Shrdat.init --- IEND
};

void JobWzskSrcDcvsp::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	if (xchg->stgwzskglobal.ixWzskVTarget != VecWzskVTarget::DISCO) return;

	hw.term();
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskSrcDcvsp
 ******************************************************************************/

JobWzskSrcDcvsp::JobWzskSrcDcvsp(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKSRCDCVSP, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskSrcDcvsp::~JobWzskSrcDcvsp() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN

// ident
bool JobWzskSrcDcvsp::ident_get(
			string& unt
			, string& ver
			, string& hash
			, string& who
		) {
	bool success = false;

	unsigned char* _unt = NULL;
	size_t untlen;
	unsigned char* _ver = NULL;
	size_t verlen;
	unsigned char* _hash = NULL;
	size_t hashlen;
	unsigned char* _who = NULL;
	size_t wholen;

	try {
		shrdat.hw.ident->get(_unt, untlen, _ver, verlen, _hash, hashlen, _who, wholen);

		unt = StrMod::spcex(string((const char*) _unt, untlen));
		ver = StrMod::spcex(string((const char*) _ver, verlen));
		hash = StrMod::spcex(string((const char*) _hash, hashlen));
		who = StrMod::spcex(string((const char*) _who, wholen));

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	if (_unt) delete[] _unt;
	if (_ver) delete[] _ver;
	if (_hash) delete[] _hash;
	if (_who) delete[] _who;

	return success;
};

bool JobWzskSrcDcvsp::ident_getCfg(
			float& fMclk
			, float& fMemclk
		) {
	bool success = false;

	uint32_t _fMclk;
	uint32_t _fMemclk;

	try {
		shrdat.hw.ident->getCfg(_fMclk, _fMemclk);

		fMclk = 1e-3 * ((float) _fMclk);
		fMemclk = 1e-3 * ((float) _fMemclk);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// laser
bool JobWzskSrcDcvsp::laser_set(
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

// rotary
bool JobWzskSrcDcvsp::rotary_getInfo(
			string& srefTixVState
			, float& angle
		) {
	bool success = false;

	uint8_t tixVState;
	uint16_t _angle;

	try {
		shrdat.hw.rotary->getInfo(tixVState, _angle);

		srefTixVState = VecVWskdDcvspRotaryState::getSref(tixVState);
		angle = ((float) _angle) * 360.0/16000.0;

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcDcvsp::rotary_moveto(
			float& _angle
		) {
	bool success = false;

	uint16_t angle;

	float angle_imd = _angle;

	while (angle_imd >= 360.0) angle_imd -= 360.0;
	while (angle_imd < 0.0) angle_imd += 360.0;

	angle = lround(1000.0 * angle_imd/360.0);
	if (angle == 1000) angle = 0;

	try {
		shrdat.hw.rotary->moveto(angle);
		_angle = 360.0 * ((float) angle) / 16000.0; // fix target to raster

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcDcvsp::rotary_set(
			const bool rng
			, const bool ccwNotCw
		) {
	bool success = false;

	try {
		shrdat.hw.rotary->set(rng, ccwNotCw);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobWzskSrcDcvsp::rotary_zero() {
	bool success = false;

	try {
		shrdat.hw.rotary->zero();

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// 10kHz clock source
double JobWzskSrcDcvsp::tkstToT(
			const uint32_t tkst
		) {
	return(shrdat.t0 + ((double) tkst) / 10000.0);
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskSrcDcvsp::handleRequest(
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

bool JobWzskSrcDcvsp::handleStartRxtxdump(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleStartRxtxdump --- INSERT
	return retval;
};

bool JobWzskSrcDcvsp::handleStopRxtxdump(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleStopRxtxdump --- INSERT
	return retval;
};

bool JobWzskSrcDcvsp::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskSrcDcvsp::changeStage(
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

string JobWzskSrcDcvsp::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::NC) || (ixVSge == VecVSge::READY) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::NC) retval = "not connected";
			else if (ixVSge == VecVSge::READY) retval = "ready";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskSrcDcvsp::enterSgeNc(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::NC;

	// IP enterSgeNc --- INSERT

	return retval;
};

void JobWzskSrcDcvsp::leaveSgeNc(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeNc --- INSERT
};

uint JobWzskSrcDcvsp::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- INSERT

	return retval;
};

void JobWzskSrcDcvsp::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

bool JobWzskSrcDcvsp::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN
	mod = Wzsk::ClaimVsp::handleClaim(dbswzsk, claims, jrefNewest);
	// IP handleClaim --- IEND

	return mod;
};
