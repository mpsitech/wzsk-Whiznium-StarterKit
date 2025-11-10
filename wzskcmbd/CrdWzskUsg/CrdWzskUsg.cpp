/**
	* \file CrdWzskUsg.cpp
	* job handler for job CrdWzskUsg (implementation)
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

#include "CrdWzskUsg.h"

#include "CrdWzskUsg_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzskUsg
 ******************************************************************************/

CrdWzskUsg::CrdWzskUsg(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
			, const ubigint ref
		) :
			JobWzsk(xchg, VecWzskVJob::CRDWZSKUSG, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

	// IP constructor.cust1 --- INSERT

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKREFPRESET, jref, VecWzskVPreset::PREWZSKREFUSG, ref);

	// initialize according to ref
	changeRef(dbswzsk, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnlrec = new PnlWzskUsgRec(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlheadbar = new PnlWzskUsgHeadbar(xchg, dbswzsk, jref, ixWzskVLocale);
	pnllist = new PnlWzskUsgList(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	changeStage(dbswzsk, VecVSge::IDLE);

	xchg->addClstn(VecWzskVCall::CALLWZSKDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWzskUsg::~CrdWzskUsg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* CrdWzskUsg::getNewDpchEng(
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

void CrdWzskUsg::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzskUsg/" + VecWzskVLocale::getSref(ixWzskVLocale);
	continf.MtxCrdUsg = StubWzsk::getStubUsgStd(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKREFUSG, jref), ixWzskVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdWzskUsg::changeRef(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWzskVRecaccess;
	xchg->triggerIxRefToIxCall(dbswzsk, VecWzskVCall::CALLWZSKRECACCESS, jref, VecWzskVCard::CRDWZSKUSG, ref, ixWzskVRecaccess);

	if (ixWzskVRecaccess != VecWzskVRecaccess::NONE) {
		xchg->addIxPreset(VecWzskVPreset::PREWZSKIXRECACC, jref, ixWzskVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswzsk, VecWzskVCall::CALLWZSKLOG, jref, VecWzskVPreset::VOID, 0, "CrdWzskUsg", ref);
		xchg->addRefPreset(VecWzskVPreset::PREWZSKREFUSG, jref, ref);

		if (pnllist) pnllist->updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFUSG, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFUSG, jrefTrig, notif);

		refresh(dbswzsk, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void CrdWzskUsg::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWzskUsg::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswzsk, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKALERT) {
			handleDpchAppWzskAlert(dbswzsk, (DpchAppWzskAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWzskUsg::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzskUsg::handleDpchAppDoClose(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");
	xchg->triggerIxCall(dbswzsk, VecWzskVCall::CALLWZSKCRDCLOSE, jref, VecWzskVCard::CRDWZSKUSG);
};

void CrdWzskUsg::handleDpchAppDoMitAppAbtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzsk, VecVSge::ALRWZSKABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzskUsg::handleDpchAppWzskAlert(
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

void CrdWzskUsg::handleCall(
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

bool CrdWzskUsg::handleCallWzskDlgClose(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskDlgClose --- INSERT
	return retval;
};

bool CrdWzskUsg::handleCallWzskStatChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWzskVExpstate == VecWzskVExpstate::REGD) && (pnlrec->statshr.ixWzskVExpstate == VecWzskVExpstate::REGD)) pnllist->minimize(dbswzsk, true);
	return retval;
};

bool CrdWzskUsg::handleCallWzskRefPreSet(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWzskVPreset::PREWZSKREFUSG) {
		changeRef(dbswzsk, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswzsk, true);
	};

	return retval;
};

void CrdWzskUsg::changeStage(
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

string CrdWzskUsg::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzskUsg::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzskUsg::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzskUsg::enterSgeAlrwzskabt(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZSKABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzsk::prepareAlrAbt(jref, ixWzskVLocale, feedFMcbAlert)); // IP enterSgeAlrwzskabt --- LINE

	return retval;
};

void CrdWzskUsg::leaveSgeAlrwzskabt(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAlrwzskabt --- INSERT
};
