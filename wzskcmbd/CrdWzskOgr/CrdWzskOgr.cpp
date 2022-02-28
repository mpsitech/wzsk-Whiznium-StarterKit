/**
	* \file CrdWzskOgr.cpp
	* job handler for job CrdWzskOgr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "CrdWzskOgr.h"

#include "CrdWzskOgr_blks.cpp"
#include "CrdWzskOgr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzskOgr
 ******************************************************************************/

CrdWzskOgr::CrdWzskOgr(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
			, const ubigint ref
		) :
			JobWzsk(xchg, VecWzskVJob::CRDWZSKOGR, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgnew = NULL;
	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

	// IP constructor.cust1 --- INSERT

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKREFPRESET, jref, VecWzskVPreset::PREWZSKREFOGR, ref);

	// initialize according to ref
	changeRef(dbswzsk, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnlrec = new PnlWzskOgrRec(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlheadbar = new PnlWzskOgrHeadbar(xchg, dbswzsk, jref, ixWzskVLocale);
	pnllist = new PnlWzskOgrList(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	if ((ref + 1) == 0) {
		dlgnew = new DlgWzskOgrNew(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbswzsk, VecVSge::IDLE);

	xchg->addClstn(VecWzskVCall::CALLWZSKDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWzskOgr::~CrdWzskOgr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* CrdWzskOgr::getNewDpchEng(
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

void CrdWzskOgr::refresh(
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
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzskOgr/" + VecWzskVLocale::getSref(ixWzskVLocale);
	continf.MtxCrdOgr = StubWzsk::getStubOgrStd(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOGR, jref), ixWzskVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswzsk);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbswzsk);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWzskOgr::changeRef(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswzsk, VecWzskVCall::CALLWZSKLOG, jref, VecWzskVPreset::VOID, 0, "CrdWzskOgr", ref);
	xchg->addRefPreset(VecWzskVPreset::PREWZSKREFOGR, jref, ref);

	if (pnllist) pnllist->updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFOGR, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFOGR, jrefTrig, notif);

	refresh(dbswzsk, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWzskOgr::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWzskOgr::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRDO) {
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

void CrdWzskOgr::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzskOgr::handleDpchAppDoClose(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");
	xchg->triggerIxCall(dbswzsk, VecWzskVCall::CALLWZSKCRDCLOSE, jref, VecWzskVCard::CRDWZSKOGR);
};

void CrdWzskOgr::handleDpchAppDoMitAppAbtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzsk, VecVSge::ALRWZSKABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzskOgr::handleDpchAppDoMitCrdNewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgWzskOgrNew(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWzskOgr::handleDpchAppWzskAlert(
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

void CrdWzskOgr::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKDLGCLOSE) {
		call->abort = handleCallWzskDlgClose(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSTATCHG) {
		call->abort = handleCallWzskStatChg(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKREFPRESET) {
		call->abort = handleCallWzskRefPreSet(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool CrdWzskOgr::handleCallWzskDlgClose(
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

bool CrdWzskOgr::handleCallWzskStatChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWzskVExpstate == VecWzskVExpstate::REGD) && (pnlrec->statshr.ixWzskVExpstate == VecWzskVExpstate::REGD)) pnllist->minimize(dbswzsk, true);
	return retval;
};

bool CrdWzskOgr::handleCallWzskRefPreSet(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWzskVPreset::PREWZSKREFOGR) {
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

void CrdWzskOgr::changeStage(
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

string CrdWzskOgr::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzskOgr::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzskOgr::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzskOgr::enterSgeAlrwzskabt(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZSKABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzsk::prepareAlrAbt(jref, ixWzskVLocale, feedFMcbAlert)); // IP enterSgeAlrwzskabt --- LINE

	return retval;
};

void CrdWzskOgr::leaveSgeAlrwzskabt(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAlrwzskabt --- INSERT
};
