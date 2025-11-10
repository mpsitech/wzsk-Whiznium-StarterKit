/**
	* \file JobWzskSrcTivsp.cpp
	* job handler for job JobWzskSrcTivsp (implementation)
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

#include "JobWzskSrcTivsp.h"

#include "JobWzskSrcTivsp_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskSrcTivsp::Shrdat
 ******************************************************************************/

JobWzskSrcTivsp::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskSrcTivsp", "Shrdat")
		{
};

void JobWzskSrcTivsp::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	if (xchg->stgwzskglobal.ixWzskVTarget != VecWzskVTarget::TITDVK) return;

	try {
		hw.init(stg.path);
		hw.reset();

		t0 = Wzsk::getNow();

		// version check can fail if either ident.getVer() is not recognized by device or return value doesn't match API version
		bool success;
		string ver, hash, who;

		success = ident_get(ver, hash, who);
		if (!success) cout << "JobWzskSrcTivsp device version mismatch: identification command not recognized" << endl;
		else {
			if (Version(ver) == Version(WSKD_VERSION)) cout << "JobWzskSrcTivsp device version " WSKD_VERSION " identified" << endl;
			else cout << "JobWzskSrcTivsp device version mismatch: identified " << ver << "expected " WSKD_VERSION << endl;
		};

	} catch (DbeException& e) {
		cout << e.err << endl;
	};

	excdump = true;
	verbose = true;
	// IP Shrdat.init --- IEND
};

void JobWzskSrcTivsp::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	if (xchg->stgwzskglobal.ixWzskVTarget != VecWzskVTarget::TITDVK) return;

	hw.term();
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskSrcTivsp
 ******************************************************************************/

JobWzskSrcTivsp::JobWzskSrcTivsp(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKSRCTIVSP, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskSrcTivsp::~JobWzskSrcTivsp() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN

// ident
bool JobWzskSrcTivsp::ident_get(
			string& ver
			, string& hash
			, string& who
		) {
	bool success = false;

	unsigned char* _ver = NULL;
	size_t verlen;
	unsigned char* _hash = NULL;
	size_t hashlen;
	unsigned char* _who = NULL;
	size_t wholen;

	try {
		shrdat.hw.ident->get(_ver, verlen, _hash, hashlen, _who, wholen);

		ver = string((const char*) _ver, verlen);
		hash = string((const char*) _hash, hashlen);
		who = string((const char*) _who, wholen);

		success = true;

	} catch (DbeException& e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	if (_ver) delete[] _ver;
	if (_hash) delete[] _hash;
	if (_who) delete[] _who;

	return success;
};

// 10kHz clock source
double JobWzskSrcTivsp::tkstToT(
			const uint32_t tkst
		) {
	return(shrdat.t0 + ((double) tkst) / 10000.0);
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskSrcTivsp::handleRequest(
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

bool JobWzskSrcTivsp::handleStartRxtxdump(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleStartRxtxdump --- INSERT
	return retval;
};

bool JobWzskSrcTivsp::handleStopRxtxdump(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleStopRxtxdump --- INSERT
	return retval;
};

bool JobWzskSrcTivsp::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskSrcTivsp::changeStage(
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

string JobWzskSrcTivsp::getSquawk(
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

uint JobWzskSrcTivsp::enterSgeNc(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::NC;

	// IP enterSgeNc --- INSERT

	return retval;
};

void JobWzskSrcTivsp::leaveSgeNc(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeNc --- INSERT
};

uint JobWzskSrcTivsp::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- INSERT

	return retval;
};

void JobWzskSrcTivsp::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

bool JobWzskSrcTivsp::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- INSERT

	return mod;
};
