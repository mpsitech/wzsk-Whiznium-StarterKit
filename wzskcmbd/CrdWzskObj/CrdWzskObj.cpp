/**
	* \file CrdWzskObj.cpp
	* job handler for job CrdWzskObj (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "CrdWzskObj.h"

#include "CrdWzskObj_blks.cpp"
#include "CrdWzskObj_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzskObj
 ******************************************************************************/

CrdWzskObj::CrdWzskObj(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
			, const ubigint ref
		) :
			JobWzsk(xchg, VecWzskVJob::CRDWZSKOBJ, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	dlgnew = NULL;
	pnlrec = NULL;

	// IP constructor.cust1 --- INSERT

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKREFPRESET, jref, VecWzskVPreset::PREWZSKREFOBJ, ref);

	// initialize according to ref
	changeRef(dbswzsk, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWzskObjList(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlheadbar = new PnlWzskObjHeadbar(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlrec = new PnlWzskObjRec(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	if ((ref + 1) == 0) {
		dlgnew = new DlgWzskObjNew(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbswzsk, VecVSge::IDLE);

	xchg->addClstn(VecWzskVCall::CALLWZSKREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWzskObj::~CrdWzskObj() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* CrdWzskObj::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdWzskObj::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzskObj/" + VecWzskVLocale::getSref(ixWzskVLocale);
	continf.MtxCrdObj = StubWzsk::getStubObjStd(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref), ixWzskVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswzsk);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbswzsk);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWzskObj::changeRef(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswzsk, VecWzskVCall::CALLWZSKLOG, jref, VecWzskVPreset::VOID, 0, "CrdWzskObj", ref);
	xchg->addRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref, ref);

	if (pnllist) pnllist->updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFOBJ, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFOBJ, jrefTrig, notif);

	refresh(dbswzsk, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWzskObj::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWzskObj::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbswzsk, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKALERT) {
			handleDpchAppWzskAlert(dbswzsk, (DpchAppWzskAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWzskObj::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzskObj::handleDpchAppDoClose(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");
	xchg->triggerIxCall(dbswzsk, VecWzskVCall::CALLWZSKCRDCLOSE, jref, VecWzskVCard::CRDWZSKOBJ);
};

void CrdWzskObj::handleDpchAppDoMitAppAbtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzsk, VecVSge::ALRWZSKABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzskObj::handleDpchAppDoMitCrdNewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgWzskObjNew(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWzskObj::handleDpchAppWzskAlert(
			DbsWzsk* dbswzsk
			, DpchAppWzskAlert* dpchappwzskalert
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppWzskAlert --- BEGIN
	if (ixVSge == VecVSge::ALRWZSKABT) {
		changeStage(dbswzsk, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");
	// IP handleDpchAppWzskAlert --- END
};

void CrdWzskObj::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKREFPRESET) {
		call->abort = handleCallWzskRefPreSet(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSTATCHG) {
		call->abort = handleCallWzskStatChg(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKDLGCLOSE) {
		call->abort = handleCallWzskDlgClose(dbswzsk, call->jref);
	};
};

bool CrdWzskObj::handleCallWzskRefPreSet(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWzskVPreset::PREWZSKREFOBJ) {
		changeRef(dbswzsk, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswzsk, true);
		else if ((jrefTrig == statshr.jrefDlgnew) && (refInv != 0)) {
			pnllist->qry->rerun(dbswzsk, true);
			pnllist->minimize(dbswzsk, true);
			pnlrec->regularize(dbswzsk, true);
		};
	};

	return retval;
};

bool CrdWzskObj::handleCallWzskStatChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWzskVExpstate == VecWzskVExpstate::REGD) && (pnlrec->statshr.ixWzskVExpstate == VecWzskVExpstate::REGD)) pnllist->minimize(dbswzsk, true);
	return retval;
};

bool CrdWzskObj::handleCallWzskDlgClose(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWzskObj::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
			, DpchEngWzsk** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::ALRWZSKABT: leaveSgeAlrwzskabt(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswzsk, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::ALRWZSKABT: _ixVSge = enterSgeAlrwzskabt(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWzskObj::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzskObj::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzskObj::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzskObj::enterSgeAlrwzskabt(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZSKABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzsk::prepareAlrAbt(jref, ixWzskVLocale, feedFMcbAlert)); // IP enterSgeAlrwzskabt --- LINE

	return retval;
};

void CrdWzskObj::leaveSgeAlrwzskabt(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAlrwzskabt --- INSERT
};

