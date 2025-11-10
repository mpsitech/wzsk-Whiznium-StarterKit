/**
	* \file PnlWzskNavOp.cpp
	* job handler for job PnlWzskNavOp (implementation)
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

#include "PnlWzskNavOp.h"

#include "PnlWzskNavOp_blks.cpp"
#include "PnlWzskNavOp_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskNavOp
 ******************************************************************************/

PnlWzskNavOp::PnlWzskNavOp(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKNAVOP, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFLstFil.tag = "FeedFLstFil";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshFil(dbswzsk, moditems);
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKFIL, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
};

PnlWzskNavOp::~PnlWzskNavOp() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskNavOp::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstFil, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskNavOp::refreshLstFil(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFilAvail = evalLstFilAvail(dbswzsk);
	statshr.ButFilViewActive = evalButFilViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavOp::refreshFil(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzskHistRMUserUniversal rst;
	WzskHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFil = 0;

	// feedFLstFil
	feedFLstFil.clear();

	dbswzsk->tblwzskhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVCard::CRDWZSKFIL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstFil.appendRefTitles(rec->ref, StubWzsk::getStubFilStd(dbswzsk, rec->unvUref, ixWzskVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFIL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFil(dbswzsk, moditems);
};

void PnlWzskNavOp::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButLlvNewcrdAvail = evalButLlvNewcrdAvail(dbswzsk);
	statshr.ButVtrNewcrdAvail = evalButVtrNewcrdAvail(dbswzsk);
	statshr.ButHwcNewcrdAvail = evalButHwcNewcrdAvail(dbswzsk);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskNavOp::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);

	refreshLstFil(dbswzsk, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWzskNavOp::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVOPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVOPDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTLLVNEWCRDCLICK) {
					handleDpchAppDoButLlvNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVTRNEWCRDCLICK) {
					handleDpchAppDoButVtrNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHWCNEWCRDCLICK) {
					handleDpchAppDoButHwcNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILNEWCRDCLICK) {
					handleDpchAppDoButFilNewcrdClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskNavOp::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskNavOp::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTFIL)) {
		contiac.numFLstFil = _contiac->numFLstFil;
		refreshLstFil(dbswzsk, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskNavOp::handleDpchAppDoButLlvNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskLlv", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskLlv");
};

void PnlWzskNavOp::handleDpchAppDoButVtrNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskVtr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskVtr");
};

void PnlWzskNavOp::handleDpchAppDoButHwcNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskHwc", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskHwc");
};

void PnlWzskNavOp::handleDpchAppDoButFilViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	WzskHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFilAvail && statshr.ButFilViewActive) {
		if (dbswzsk->tblwzskhistrmuseruniversal->loadRecByRef(feedFLstFil.getRefByNum(contiac.numFLstFil), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, husrRunv->ixWzskVPreset, husrRunv->preUref, "CrdWzskFil", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskFil");
	};
};

void PnlWzskNavOp::handleDpchAppDoButFilNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskFil");
};

void PnlWzskNavOp::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWzskHusrRunvMod_crdUsrEq(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWzskNavOp::handleCallWzskHusrRunvMod_crdUsrEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWzskVCard::CRDWZSKFIL) {
		refreshFil(dbswzsk, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
