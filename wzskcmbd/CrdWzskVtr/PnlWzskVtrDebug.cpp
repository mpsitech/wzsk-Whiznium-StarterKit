/**
	* \file PnlWzskVtrDebug.cpp
	* job handler for job PnlWzskVtrDebug (implementation)
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

#include "PnlWzskVtrDebug.h"

#include "PnlWzskVtrDebug_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskVtrDebug
 ******************************************************************************/

PnlWzskVtrDebug::PnlWzskVtrDebug(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKVTRDEBUG, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	acqvtrtrack = NULL;

	// IP constructor.cust1 --- INSERT

	acqvtrtrack = new JobWzskAcqVtrtrack(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- IBEGIN
	numTrack = 0;
	refFilTrack = 0;
	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSGECHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, acqvtrtrack->jref, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskVtrDebug::~PnlWzskVtrDebug() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskVtrDebug::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskVtrDebug::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN

	bool takenNotAvailable, fulfilled;

	xchg->getCsjobClaim(acqvtrtrack, takenNotAvailable, fulfilled);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;
	continf.TxtTst = acqvtrtrack->getSquawk(dbswzsk);
	continf.TxtTtf = StubWzsk::getStubFilStd(dbswzsk, refFilTrack);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;

	statshr.TxfTfrActive = continf.ButClaimOn && (acqvtrtrack->ixVSge == VecVJobWzskAcqVtrtrackSge::IDLE);

	statshr.ButTsrActive = continf.ButClaimOn && (acqvtrtrack->ixVSge == VecVJobWzskAcqVtrtrackSge::IDLE);
	statshr.ButTspActive = continf.ButClaimOn && (acqvtrtrack->ixVSge != VecVJobWzskAcqVtrtrackSge::IDLE);

	statshr.ButTtfViewActive = (refFilTrack != 0);

	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskVtrDebug::handleRequest(
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

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKINIT) {
			handleDpchAppWzskInit(dbswzsk, (DpchAppWzskInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKVTRDEBUGDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKVTRDEBUGDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLAIMCLICK) {
					handleDpchAppDoButClaimClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTSRCLICK) {
					handleDpchAppDoButTsrClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTSPCLICK) {
					handleDpchAppDoButTspClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTTFVIEWCLICK) {
					handleDpchAppDoButTtfViewClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskVtrDebug::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskVtrDebug::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	if (has(diffitems, ContIac::TXFTFR)) {
		contiac.TxfTfr = _contiac->TxfTfr;
		numTrack = 0;
	};

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskVtrDebug::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskVtrDebug::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskVtrDebug::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, acqvtrtrack, new Claim(true));
		else xchg->removeCsjobClaim(dbswzsk, acqvtrtrack);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskVtrDebug::handleDpchAppDoButTsrClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButTsrClick --- IBEGIN
	string path;

	if (statshr.ButTsrActive) {
		muteRefresh = true;

		if (contiac.TxfTfr == "") path = "track";
		else path = contiac.TxfTfr;

		path += "_" + to_string(numTrack) + ".vcd";

		xchg->addCsjobClaim(dbswzsk, acqvtrtrack, new Wzsk::ClaimTrack(true, true, path));

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButTsrClick --- IEND
};

void PnlWzskVtrDebug::handleDpchAppDoButTspClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButTspClick --- IBEGIN
	if (statshr.ButTspActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqvtrtrack, new Wzsk::ClaimTrack(true, false, ""));

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButTspClick --- IEND
};

void PnlWzskVtrDebug::handleDpchAppDoButTtfViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButTtfViewClick --- IBEGIN
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButTtfViewActive) {
		if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref)) {
			sref = "CrdWzskFil";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, sref, refFilTrack, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
	// IP handleDpchAppDoButTtfViewClick --- IEND
};

void PnlWzskVtrDebug::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSGECHG) {
		call->abort = handleCallWzskSgeChg(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && (call->jref == acqvtrtrack->jref)) {
		call->abort = handleCallWzskResultNewFromAcqvtrtrack(dbswzsk, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	};
};

bool PnlWzskVtrDebug::handleCallWzskSgeChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskSgeChg --- IBEGIN

	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	// IP handleCallWzskSgeChg --- IEND
	return retval;
};

bool PnlWzskVtrDebug::handleCallWzskResultNewFromAcqvtrtrack(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromAcqvtrtrack --- IBEGIN

	set<uint> moditems;

	refFilTrack = refInv;
	numTrack++;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	// IP handleCallWzskResultNewFromAcqvtrtrack --- IEND
	return retval;
};
