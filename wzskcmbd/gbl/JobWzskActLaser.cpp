/**
	* \file JobWzskActLaser.cpp
	* job handler for job JobWzskActLaser (implementation)
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

#include "JobWzskActLaser.h"

#include "JobWzskActLaser_blks.cpp"
#include "JobWzskActLaser_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskActLaser::Shrdat
 ******************************************************************************/

JobWzskActLaser::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskActLaser", "Shrdat")
		{
};

void JobWzskActLaser::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- INSERT
};

void JobWzskActLaser::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskActLaser
 ******************************************************************************/

JobWzskActLaser::JobWzskActLaser(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACTLASER, jrefSup, ixWzskVLocale)
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

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskActLaser::~JobWzskActLaser() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
usmallint JobWzskActLaser::pToAbs(
			const bool rightNotLeft
			, const float p
		) {
	if (p == 0.0) return 0;
	if (p >= 1.0) return 1023;

	if (!rightNotLeft) return(stg.leftMin + lround(p * ((float) (stg.leftMax - stg.leftMin))));
	else return(stg.rightMin + lround(p * ((float) (stg.rightMax - stg.rightMin))));
};
// IP cust --- IEND

// IP spec --- INSERT

bool JobWzskActLaser::setLeft(
			DbsWzsk* dbswzsk
			, const float left // 0..1
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActLaser*) srv)->setLeft(dbswzsk, left);

		} else retval = false;

		return retval;
	};

	lockAccess("setLeft");

	// IP setLeft --- IBEGIN
	int res;

	usmallint i = pToAbs(false, left);

	if (srczuvsp) retval = srczuvsp->laser_set(pToAbs(false, shrdat.left), i);

	if (retval) {
		shrdat.wlockAccess(jref, "setLeft");

		shrdat.left = left;

		shrdat.wunlockAccess(jref, "setLeft");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "leftRight");
	};
	// IP setLeft --- IEND

	unlockAccess("setLeft");

	return retval;
};

bool JobWzskActLaser::setRight(
			DbsWzsk* dbswzsk
			, const float right // 0..1
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActLaser*) srv)->setRight(dbswzsk, right);

		} else retval = false;

		return retval;
	};

	lockAccess("setRight");

	// IP setRight --- IBEGIN
	int res;

	usmallint i = pToAbs(true, right);

	if (srczuvsp) retval = srczuvsp->laser_set(pToAbs(true, shrdat.right), i);

	if (retval) {
		shrdat.wlockAccess(jref, "setRight");

		shrdat.right = right;

		shrdat.wunlockAccess(jref, "setRight");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "leftRight");
	};
	// IP setRight --- IEND

	unlockAccess("setRight");

	return retval;
};

void JobWzskActLaser::handleRequest(
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

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETLEFT) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setLeft(dbswzsk, *((const float*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::SETRIGHT) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setRight(dbswzsk, *((const float*) (req->method->parsInv[0])));
		};
	};
};

bool JobWzskActLaser::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if srcfpga "laser" claim can be fulfilled

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;

	bool available;
	bool reattributed;

	bool laserTakenNotAvailable, laserFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
		};
	};

	if (srczuvsp) {
		// add or remove "laser" claim with srczuvsp
		//if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srczuvsp);
		//else xchg->addCsjobClaim(dbswzsk, srczuvsp, new Wzsk::ClaimFull(false, false, true, false));

		//xchg->getCsjobClaim(srczuvsp, laserTakenNotAvailable, laserFulfilled);

		laserFulfilled = true;

	} else laserFulfilled = true;

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && laserFulfilled;

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
