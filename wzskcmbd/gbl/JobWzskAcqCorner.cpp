/**
	* \file JobWzskAcqCorner.cpp
	* job handler for job JobWzskAcqCorner (implementation)
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

#include "JobWzskAcqCorner.h"

#include "JobWzskAcqCorner_blks.cpp"
#include "JobWzskAcqCorner_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskAcqCorner::Shrdat
 ******************************************************************************/

JobWzskAcqCorner::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqCorner", "Shrdat")
		{
};

void JobWzskAcqCorner::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- INSERT
};

void JobWzskAcqCorner::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskAcqCorner
 ******************************************************************************/

JobWzskAcqCorner::JobWzskAcqCorner(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQCORNER, jrefSup, ixWzskVLocale)
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

	if (srvNotCli) xchg->addClstn(VecWzskVCall::CALLWZSKCALLBACK, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), VecVSge::ACQ, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskAcqCorner::~JobWzskAcqCorner() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

// IP spec --- INSERT

bool JobWzskAcqCorner::setRoi(
			DbsWzsk* dbswzsk
			, const int roiX0
			, const int roiY0
			, const int roiX1
			, const int roiY1
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskAcqCorner*) srv)->setRoi(dbswzsk, roiX0, roiY0, roiX1, roiY1);

		} else retval = false;

		return retval;
	};

	lockAccess("setRoi");

	// IP setRoi --- INSERT

	unlockAccess("setRoi");

	return retval;
};

void JobWzskAcqCorner::handleRequest(
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

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETROI) && (req->method->parsInv.size() == 4) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setRoi(dbswzsk, *((const int*) (req->method->parsInv[0])), *((const int*) (req->method->parsInv[1])), *((const int*) (req->method->parsInv[2])), *((const int*) (req->method->parsInv[3])));
		};

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::CALCIDLE) handleTimerInSgeCalcidle(dbswzsk, req->sref);
	};
};

bool JobWzskAcqCorner::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskAcqCorner::handleTimerInSgeCalcidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void JobWzskAcqCorner::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCALLBACK) && (call->jref == jref) && (ixVSge == VecVSge::ACQ)) {
		call->abort = handleCallWzskCallbackFromSelfInSgeAcq(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskAcqCorner::handleCallWzskCallbackFromSelfInSgeAcq(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskCallbackFromSelfInSgeAcq --- INSERT
	return retval;
};

void JobWzskAcqCorner::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::ACQ: leaveSgeAcq(dbswzsk); break;
				case VecVSge::CALCIDLE: leaveSgeCalcidle(dbswzsk); break;
				case VecVSge::CALC: leaveSgeCalc(dbswzsk); break;
				case VecVSge::DONE: leaveSgeDone(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::ACQ: _ixVSge = enterSgeAcq(dbswzsk, reenter); break;
			case VecVSge::CALCIDLE: _ixVSge = enterSgeCalcidle(dbswzsk, reenter); break;
			case VecVSge::CALC: _ixVSge = enterSgeCalc(dbswzsk, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskAcqCorner::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::ACQ) || (ixVSge == VecVSge::CALC) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::ACQ) retval = "acquiring corner coordinates";
			else if (ixVSge == VecVSge::CALC) retval = "calculating rotation angle";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskAcqCorner::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void JobWzskAcqCorner::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqCorner::enterSgeAcq(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ACQ;

	// IP enterSgeAcq --- INSERT

	return retval;
};

void JobWzskAcqCorner::leaveSgeAcq(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAcq --- INSERT
};

uint JobWzskAcqCorner::enterSgeCalcidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::CALCIDLE;
	nextIxVSgeSuccess = VecVSge::CALC;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeCalcidle --- INSERT

	return retval;
};

void JobWzskAcqCorner::leaveSgeCalcidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeCalcidle --- INSERT
};

uint JobWzskAcqCorner::enterSgeCalc(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::CALC;

	// IP enterSgeCalc --- INSERT

	return retval;
};

void JobWzskAcqCorner::leaveSgeCalc(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeCalc --- INSERT
};

uint JobWzskAcqCorner::enterSgeDone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWzskAcqCorner::leaveSgeDone(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeDone --- INSERT
};

bool JobWzskAcqCorner::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if src*vsp "corner" claim can be fulfilled

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

	// add or remove "corner" claim with src*vsp
	if (srcdcvsp) srcvsp = srcdcvsp;
	else if (srctivsp)  srcvsp = srctivsp;
	else if (srczuvsp) srcvsp = srczuvsp;

	if (srcvsp) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcvsp);
		else xchg->addCsjobClaim(dbswzsk, srcvsp, new Wzsk::ClaimVsp(false, Wzsk::ClaimVsp::VecWDomain::CORNER));

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
