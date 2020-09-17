/**
	* \file JobWzskActExposure.cpp
	* job handler for job JobWzskActExposure (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskActExposure.h"

#include "JobWzskActExposure_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskActExposure::Shrdat
 ******************************************************************************/

JobWzskActExposure::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskActExposure", "Shrdat")
		{
};

void JobWzskActExposure::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	autoNotManual = true;
	Texp = 1e-6;

	focus = 0.3;
	// IP Shrdat.init --- IEND
};

void JobWzskActExposure::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskActExposure
 ******************************************************************************/

JobWzskActExposure::JobWzskActExposure(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACTEXPOSURE, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcv4l2 = NULL;
	srcfpga = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- IBEGIN
	if (srvNotCli) {
		if (!xchg->stgwzskglobal.fpgaNotV4l2gpio) srcv4l2 = new JobWzskSrcV4l2(xchg, dbswzsk, jref, ixWzskVLocale);
		else srcfpga = new JobWzskSrcFpga(xchg, dbswzsk, jref, ixWzskVLocale);
	};
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskActExposure::~JobWzskActExposure() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

// IP spec --- INSERT

bool JobWzskActExposure::setExposure(
			DbsWzsk* dbswzsk
			, const bool autoNotManual
			, const float Texp
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActExposure*) srv)->setExposure(dbswzsk, autoNotManual, Texp);

		} else retval = false;

		return retval;
	};

	lockAccess("setExposure");

	// IP setExposure --- IBEGIN
	if (srcv4l2) retval = srcv4l2->setExposure(autoNotManual, Texp);
	else if (srcfpga) retval = srcfpga->camif_setTexp(Texp);

	if (retval) {
		shrdat.wlockAccess(jref, "setExposure");

		shrdat.autoNotManual = autoNotManual;
		shrdat.Texp = Texp;

		shrdat.wunlockAccess(jref, "setExposure");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "autoNotManualTexp");
	};
	// IP setExposure --- IEND

	unlockAccess("setExposure");

	return retval;
};

bool JobWzskActExposure::setFocus(
			DbsWzsk* dbswzsk
			, const float focus
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActExposure*) srv)->setFocus(dbswzsk, focus);

		} else retval = false;

		return retval;
	};

	lockAccess("setFocus");

	// IP setFocus --- IBEGIN
	if (srcv4l2) retval = srcv4l2->setFocus(focus);
	else if (srcfpga) retval = srcfpga->camif_setFocus(focus);

	if (retval) {
		shrdat.wlockAccess(jref, "setFocus");

		shrdat.focus = focus;

		shrdat.wunlockAccess(jref, "setFocus");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "focus");
	};
	// IP setFocus --- IEND

	unlockAccess("setFocus");

	return retval;
};

void JobWzskActExposure::handleRequest(
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

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTEXPOSUREMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETEXPOSURE) && (req->method->parsInv.size() == 2) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setExposure(dbswzsk, *((const bool*) (req->method->parsInv[0])), *((const float*) (req->method->parsInv[1])));
		} else if ((ixVMethod == VecVMethod::SETFOCUS) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setFocus(dbswzsk, *((const float*) (req->method->parsInv[0])));
		};
	};
};

bool JobWzskActExposure::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- INSERT

	return mod;
};



