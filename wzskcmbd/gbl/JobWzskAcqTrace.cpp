/**
	* \file JobWzskAcqTrace.cpp
	* job handler for job JobWzskAcqTrace (implementation)
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

#include "JobWzskAcqTrace.h"

#include "JobWzskAcqTrace_blks.cpp"
#include "JobWzskAcqTrace_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskAcqTrace::Shrdat
 ******************************************************************************/

JobWzskAcqTrace::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqTrace", "Shrdat")
		{
};

void JobWzskAcqTrace::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- INSERT
};

void JobWzskAcqTrace::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskAcqTrace
 ******************************************************************************/

JobWzskAcqTrace::JobWzskAcqTrace(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQTRACE, jrefSup, ixWzskVLocale)
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

JobWzskAcqTrace::~JobWzskAcqTrace() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

// IP spec --- INSERT

bool JobWzskAcqTrace::setRoi(
			DbsWzsk* dbswzsk
			, const int roiX0
			, const int roiY0
			, const int roiX1
			, const int roiY1
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskAcqTrace*) srv)->setRoi(dbswzsk, roiX0, roiY0, roiX1, roiY1);

		} else retval = false;

		return retval;
	};

	lockAccess("setRoi");

	// IP setRoi --- INSERT

	unlockAccess("setRoi");

	return retval;
};

void JobWzskAcqTrace::handleRequest(
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

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETROI) && (req->method->parsInv.size() == 4) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setRoi(dbswzsk, *((const int*) (req->method->parsInv[0])), *((const int*) (req->method->parsInv[1])), *((const int*) (req->method->parsInv[2])), *((const int*) (req->method->parsInv[3])));
		};
	};
};

bool JobWzskAcqTrace::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// preliminary: fulfill all claims

	Claim* claim = NULL;

	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;
		claim->fulfilled = true;
	};

	mod = true; // for simplicity

	// IP handleClaim --- IEND

	return mod;
};
