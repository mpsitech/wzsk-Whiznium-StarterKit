/**
	* \file JobWzskSrcFpgainfo.cpp
	* job handler for job JobWzskSrcFpgainfo (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 2 Jul 2025
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskSrcFpgainfo.h"

#include "JobWzskSrcFpgainfo_blks.cpp"
#include "JobWzskSrcFpgainfo_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskSrcFpgainfo::Shrdat
 ******************************************************************************/

JobWzskSrcFpgainfo::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskSrcFpgainfo", "Shrdat")
		{
};

void JobWzskSrcFpgainfo::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	hdrDRd = 0.0;
	hdrDWr = 0.0;

	rndDRd = 0.0;
	rndDWr = 0.0;
	// IP Shrdat.init --- IEND
};

void JobWzskSrcFpgainfo::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskSrcFpgainfo
 ******************************************************************************/

JobWzskSrcFpgainfo::JobWzskSrcFpgainfo(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKSRCFPGAINFO, jrefSup, ixWzskVLocale)
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

	if (srvNotCli) changeStage(dbswzsk, VecVSge::RUN); // IP constructor.cust3 --- ILINE

	// IP constructor.spec3 --- INSERT
};

JobWzskSrcFpgainfo::~JobWzskSrcFpgainfo() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

// IP spec --- INSERT

void JobWzskSrcFpgainfo::handleRequest(
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

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if ((req->sref == "mon") && (ixVSge == VecVSge::RUN)) handleTimerWithSrefMonInSgeRun(dbswzsk);
	};
};

bool JobWzskSrcFpgainfo::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskSrcFpgainfo::handleTimerWithSrefMonInSgeRun(
			DbsWzsk* dbswzsk
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	changeStage(dbswzsk, ixVSge); // IP handleTimerWithSrefMonInSgeRun --- ILINE
};

void JobWzskSrcFpgainfo::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::RUN: leaveSgeRun(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::RUN: _ixVSge = enterSgeRun(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskSrcFpgainfo::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::RUN) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::RUN) retval = "running";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskSrcFpgainfo::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void JobWzskSrcFpgainfo::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskSrcFpgainfo::enterSgeRun(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RUN;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeRun --- IBEGIN
	shrdat.wlockAccess(jref, "enterSgeRun");

	srczuvsp->ddrif_getStats(shrdat.hdrDRd, shrdat.hdrDWr, shrdat.rndDRd, shrdat.rndDWr);

	shrdat.wunlockAccess(jref, "enterSgeRun");

	xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref); // omit sref as all members are updated at the same time
	// IP enterSgeRun --- IEND

	return retval;
};

void JobWzskSrcFpgainfo::leaveSgeRun(
			DbsWzsk* dbswzsk
		) {
	invalidateWakeups();
	// IP leaveSgeRun --- INSERT
};

bool JobWzskSrcFpgainfo::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- INSERT

	return mod;
};
