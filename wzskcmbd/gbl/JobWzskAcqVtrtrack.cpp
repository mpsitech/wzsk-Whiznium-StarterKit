/**
	* \file JobWzskAcqVtrtrack.cpp
	* job handler for job JobWzskAcqVtrtrack (implementation)
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

#include "JobWzskAcqVtrtrack.h"

#include "JobWzskAcqVtrtrack_blks.cpp"
#include "JobWzskAcqVtrtrack_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskAcqVtrtrack::Shrdat
 ******************************************************************************/

JobWzskAcqVtrtrack::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqVtrtrack", "Shrdat")
		{
};

void JobWzskAcqVtrtrack::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- INSERT
};

void JobWzskAcqVtrtrack::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskAcqVtrtrack
 ******************************************************************************/

JobWzskAcqVtrtrack::JobWzskAcqVtrtrack(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQVTRTRACK, jrefSup, ixWzskVLocale)
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

	if (srvNotCli) xchg->addClstn(VecWzskVCall::CALLWZSKCALLBACK, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), VecVSge::RNG, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskAcqVtrtrack::~JobWzskAcqVtrtrack() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

// IP spec --- INSERT

void JobWzskAcqVtrtrack::handleRequest(
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

bool JobWzskAcqVtrtrack::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskAcqVtrtrack::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCALLBACK) && (call->jref == jref) && (ixVSge == VecVSge::RNG)) {
		call->abort = handleCallWzskCallbackFromSelfInSgeRng(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskAcqVtrtrack::handleCallWzskCallbackFromSelfInSgeRng(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskCallbackFromSelfInSgeRng --- INSERT
	return retval;
};

void JobWzskAcqVtrtrack::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::RNG: leaveSgeRng(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::RNG: _ixVSge = enterSgeRng(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskAcqVtrtrack::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::RNG) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::RNG) retval = "tracking signals";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskAcqVtrtrack::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void JobWzskAcqVtrtrack::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqVtrtrack::enterSgeRng(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RNG;

	// IP enterSgeRng --- INSERT

	return retval;
};

void JobWzskAcqVtrtrack::leaveSgeRng(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeRng --- INSERT
};

bool JobWzskAcqVtrtrack::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - no modification while running
	// - exactly one claim can be fulfilled
	// - only possible if src*vsp "hshktrack" claim can be fulfilled
	// - change stage to rng if fulfilled claim is run

	if (ixVSge != VecVSge::IDLE) return false;

	Wzsk::ClaimTrack* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;
	bool run = false;

	string path;

	bool available;
	bool reattributed;

	CsjobWzsk* srcvsp = NULL;
	bool vspTakenNotAvailable, vspFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Wzsk::ClaimTrack*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
			run = claim->run;

			path = claim->path;

			break;
		};
	};

	// add or remove "hshktrack" claim with src*vsp
	if (srcdcvsp) srcvsp = srcdcvsp;
	else if (srctivsp)  srcvsp = srctivsp;
	else if (srczuvsp) srcvsp = srczuvsp;

	if (srcvsp) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcvsp);
		else xchg->addCsjobClaim(dbswzsk, srcvsp, new Wzsk::ClaimVsp(false, Wzsk::ClaimVsp::VecWDomain::HSHKTRACK));

		xchg->getCsjobClaim(srcvsp, vspTakenNotAvailable, vspFulfilled);
	};

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Wzsk::ClaimTrack*) it->second;

			available = retractable && vspFulfilled;

			if (!available) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim
				if (it->first != jrefFulfilled) {
					if (jrefFulfilled != 0) claims[jrefFulfilled]->fulfilled = false;

					claim->fulfilled = true;
					retractable = claim->retractable;
					run = claim->run;

					path = claim->path;

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
		claim = (Wzsk::ClaimTrack*) it->second;
		claim->takenNotAvailable = !retractable;
	};

	// initiate stage change
	if (!run || !vspFulfilled) {
		changeStage(dbswzsk, VecVSge::IDLE);

	} else if (run && (ixVSge == VecVSge::IDLE)) {
		shrdat.path = path;

		nextIxVSgeFailure = VecVSge::RNG;
		changeStage(dbswzsk, VecVSge::RNG);
	};

	mod = true; // for simplicity

	// IP handleClaim --- IEND

	return mod;
};
