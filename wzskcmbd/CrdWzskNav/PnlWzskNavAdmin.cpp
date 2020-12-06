/**
	* \file PnlWzskNavAdmin.cpp
	* job handler for job PnlWzskNavAdmin (implementation)
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

#include "PnlWzskNavAdmin.h"

#include "PnlWzskNavAdmin_blks.cpp"
#include "PnlWzskNavAdmin_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskNavAdmin
 ******************************************************************************/

PnlWzskNavAdmin::PnlWzskNavAdmin(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKNAVADMIN, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshUsg(dbswzsk, moditems);
	refreshUsr(dbswzsk, moditems);
	refreshPrs(dbswzsk, moditems);
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKUSG, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKUSR, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKPRS, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
};

PnlWzskNavAdmin::~PnlWzskNavAdmin() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskNavAdmin::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstPrs, &feedFLstUsg, &feedFLstUsr, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskNavAdmin::refreshLstUsg(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsgAvail = evalLstUsgAvail(dbswzsk);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavAdmin::refreshUsg(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzskHistRMUserUniversal rst;
	WzskHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsg = 0;

	// feedFLstUsg
	feedFLstUsg.clear();

	dbswzsk->tblwzskhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVCard::CRDWZSKUSG, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstUsg.appendRefTitles(rec->ref, StubWzsk::getStubUsgStd(dbswzsk, rec->unvUref, ixWzskVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsg(dbswzsk, moditems);
};

void PnlWzskNavAdmin::refreshLstUsr(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsrAvail = evalLstUsrAvail(dbswzsk);
	statshr.ButUsrViewActive = evalButUsrViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavAdmin::refreshUsr(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzskHistRMUserUniversal rst;
	WzskHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsr = 0;

	// feedFLstUsr
	feedFLstUsr.clear();

	dbswzsk->tblwzskhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVCard::CRDWZSKUSR, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstUsr.appendRefTitles(rec->ref, StubWzsk::getStubUsrStd(dbswzsk, rec->unvUref, ixWzskVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsr(dbswzsk, moditems);
};

void PnlWzskNavAdmin::refreshLstPrs(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrsAvail = evalLstPrsAvail(dbswzsk);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavAdmin::refreshPrs(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzskHistRMUserUniversal rst;
	WzskHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrs = 0;

	// feedFLstPrs
	feedFLstPrs.clear();

	dbswzsk->tblwzskhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVCard::CRDWZSKPRS, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPrs.appendRefTitles(rec->ref, StubWzsk::getStubPrsStd(dbswzsk, rec->unvUref, ixWzskVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrs(dbswzsk, moditems);
};

void PnlWzskNavAdmin::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButScfNewcrdAvail = evalButScfNewcrdAvail(dbswzsk);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskNavAdmin::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);

	refreshLstUsg(dbswzsk, moditems);
	refreshLstUsr(dbswzsk, moditems);
	refreshLstPrs(dbswzsk, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWzskNavAdmin::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVADMINDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVADMINDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGNEWCRDCLICK) {
					handleDpchAppDoButUsgNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRVIEWCLICK) {
					handleDpchAppDoButUsrViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRNEWCRDCLICK) {
					handleDpchAppDoButUsrNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSNEWCRDCLICK) {
					handleDpchAppDoButPrsNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSCFNEWCRDCLICK) {
					handleDpchAppDoButScfNewcrdClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskNavAdmin::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskNavAdmin::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTUSG)) {
		contiac.numFLstUsg = _contiac->numFLstUsg;
		refreshLstUsg(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUSR)) {
		contiac.numFLstUsr = _contiac->numFLstUsr;
		refreshLstUsr(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRS)) {
		contiac.numFLstPrs = _contiac->numFLstPrs;
		refreshLstPrs(dbswzsk, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskNavAdmin::handleDpchAppDoButUsgViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	WzskHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsgAvail && statshr.ButUsgViewActive) {
		if (dbswzsk->tblwzskhistrmuseruniversal->loadRecByRef(feedFLstUsg.getRefByNum(contiac.numFLstUsg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, husrRunv->ixWzskVPreset, husrRunv->preUref, "CrdWzskUsg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskUsg");
	};
};

void PnlWzskNavAdmin::handleDpchAppDoButUsgNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskUsg");
};

void PnlWzskNavAdmin::handleDpchAppDoButUsrViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	WzskHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsrAvail && statshr.ButUsrViewActive) {
		if (dbswzsk->tblwzskhistrmuseruniversal->loadRecByRef(feedFLstUsr.getRefByNum(contiac.numFLstUsr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, husrRunv->ixWzskVPreset, husrRunv->preUref, "CrdWzskUsr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskUsr");
	};
};

void PnlWzskNavAdmin::handleDpchAppDoButUsrNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskUsr");
};

void PnlWzskNavAdmin::handleDpchAppDoButPrsViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	WzskHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrsAvail && statshr.ButPrsViewActive) {
		if (dbswzsk->tblwzskhistrmuseruniversal->loadRecByRef(feedFLstPrs.getRefByNum(contiac.numFLstPrs), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, husrRunv->ixWzskVPreset, husrRunv->preUref, "CrdWzskPrs", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskPrs");
	};
};

void PnlWzskNavAdmin::handleDpchAppDoButPrsNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskPrs");
};

void PnlWzskNavAdmin::handleDpchAppDoButScfNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskScf", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskScf");
};

void PnlWzskNavAdmin::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWzskHusrRunvMod_crdUsrEq(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWzskNavAdmin::handleCallWzskHusrRunvMod_crdUsrEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWzskVCard::CRDWZSKUSG) {
		refreshUsg(dbswzsk, moditems);
	} else if (ixInv == VecWzskVCard::CRDWZSKUSR) {
		refreshUsr(dbswzsk, moditems);
	} else if (ixInv == VecWzskVCard::CRDWZSKPRS) {
		refreshPrs(dbswzsk, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
