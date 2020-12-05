/**
	* \file CrdWzskFil.cpp
	* job handler for job CrdWzskFil (implementation)
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

#include "CrdWzskFil.h"

#include "CrdWzskFil_blks.cpp"
#include "CrdWzskFil_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzskFil
 ******************************************************************************/

CrdWzskFil::CrdWzskFil(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
			, const ubigint ref
			, const uint ixWzskVPreset
			, const ubigint preUref
		) :
			JobWzsk(xchg, VecWzskVJob::CRDWZSKFIL, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;
	dlgdownload = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWzskVPreset::PREWZSKIXPRE, jref, ixWzskVPreset);
	if (ixWzskVPreset != VecWzskVPreset::VOID) xchg->addRefPreset(ixWzskVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKREFPRESET, jref, VecWzskVPreset::PREWZSKREFFIL, ref);

	// initialize according to ref
	changeRef(dbswzsk, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWzskFilList(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlheadbar = new PnlWzskFilHeadbar(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlrec = new PnlWzskFilRec(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	changeStage(dbswzsk, VecVSge::IDLE);

	xchg->addClstn(VecWzskVCall::CALLWZSKREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWzskFil::~CrdWzskFil() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* CrdWzskFil::getNewDpchEng(
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

void CrdWzskFil::refresh(
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
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzskFil/" + VecWzskVLocale::getSref(ixWzskVLocale);
	continf.MtxCrdFil = StubWzsk::getStubFilStd(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKREFFIL, jref), ixWzskVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MitCrdDldAvail = evalMitCrdDldAvail(dbswzsk);
	statshr.MitCrdDldActive = evalMitCrdDldActive(dbswzsk);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWzskFil::changeRef(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWzskVPreset = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXPRE, jref);

	uint ixWzskVRecaccess;
	xchg->triggerIxRefToIxCall(dbswzsk, VecWzskVCall::CALLWZSKRECACCESS, jref, VecWzskVCard::CRDWZSKFIL, ref, ixWzskVRecaccess);

	if (ixWzskVRecaccess != VecWzskVRecaccess::NONE) {
		xchg->addIxPreset(VecWzskVPreset::PREWZSKIXRECACC, jref, ixWzskVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswzsk, VecWzskVCall::CALLWZSKLOG, jref, ixWzskVPreset, xchg->getRefPreset(ixWzskVPreset, jref), "CrdWzskFil", ref);
		xchg->addRefPreset(VecWzskVPreset::PREWZSKREFFIL, jref, ref);

		if (pnllist) pnllist->updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFFIL, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFFIL, jrefTrig, notif);

		refresh(dbswzsk, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void CrdWzskFil::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWzskFil::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDDLDCLICK) {
					handleDpchAppDoMitCrdDldClick(dbswzsk, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKALERT) {
			handleDpchAppWzskAlert(dbswzsk, (DpchAppWzskAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWzskFil::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzskFil::handleDpchAppDoClose(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");
	xchg->triggerIxCall(dbswzsk, VecWzskVCall::CALLWZSKCRDCLOSE, jref, VecWzskVCard::CRDWZSKFIL);
};

void CrdWzskFil::handleDpchAppDoMitAppAbtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzsk, VecVSge::ALRWZSKABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzskFil::handleDpchAppDoMitCrdDldClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	if (!dlgdownload) {
		dlgdownload = new DlgWzskFilDownload(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefDlgdownload = dlgdownload->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWzskFil::handleDpchAppWzskAlert(
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

void CrdWzskFil::handleCall(
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

bool CrdWzskFil::handleCallWzskRefPreSet(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWzskVPreset::PREWZSKREFFIL) {
		changeRef(dbswzsk, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswzsk, true);
	};

	return retval;
};

bool CrdWzskFil::handleCallWzskStatChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWzskVExpstate == VecWzskVExpstate::REGD) && (pnlrec->statshr.ixWzskVExpstate == VecWzskVExpstate::REGD)) pnllist->minimize(dbswzsk, true);
	return retval;
};

bool CrdWzskFil::handleCallWzskDlgClose(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgdownload) {
		delete dlgdownload;
		dlgdownload = NULL;
		statshr.jrefDlgdownload = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWzskFil::changeStage(
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

string CrdWzskFil::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzskFil::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzskFil::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzskFil::enterSgeAlrwzskabt(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZSKABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzsk::prepareAlrAbt(jref, ixWzskVLocale, feedFMcbAlert)); // IP enterSgeAlrwzskabt --- LINE

	return retval;
};

void CrdWzskFil::leaveSgeAlrwzskabt(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAlrwzskabt --- INSERT
};

