/**
	* \file PnlWzskNavGalery.cpp
	* job handler for job PnlWzskNavGalery (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskNavGalery.h"

#include "PnlWzskNavGalery_blks.cpp"
#include "PnlWzskNavGalery_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskNavGalery
 ******************************************************************************/

PnlWzskNavGalery::PnlWzskNavGalery(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKNAVGALERY, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFLstFil.tag = "FeedFLstFil";
	feedFLstObj.tag = "FeedFLstObj";
	feedFLstOgr.tag = "FeedFLstOgr";
	feedFLstSes.tag = "FeedFLstSes";
	feedFLstSht.tag = "FeedFLstSht";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshOgr(dbswzsk, moditems);
	refreshObj(dbswzsk, moditems);
	refreshSes(dbswzsk, moditems);
	refreshSht(dbswzsk, moditems);
	refreshFil(dbswzsk, moditems);
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKOGR, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKOBJ, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKSES, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKSHT, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVCard::CRDWZSKFIL, xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref));
};

PnlWzskNavGalery::~PnlWzskNavGalery() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskNavGalery::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstFil, &feedFLstObj, &feedFLstOgr, &feedFLstSes, &feedFLstSht, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskNavGalery::refreshLstOgr(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstOgrAvail = evalLstOgrAvail(dbswzsk);
	statshr.ButOgrViewActive = evalButOgrViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavGalery::refreshOgr(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzskHistRMUserUniversal rst;
	WzskHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstOgr = 0;

	// feedFLstOgr
	feedFLstOgr.clear();

	dbswzsk->tblwzskhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVCard::CRDWZSKOGR, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstOgr.appendRefTitles(rec->ref, StubWzsk::getStubOgrStd(dbswzsk, rec->unvUref, ixWzskVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTOGR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstOgr(dbswzsk, moditems);
};

void PnlWzskNavGalery::refreshLstObj(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstObjAvail = evalLstObjAvail(dbswzsk);
	statshr.ButObjViewActive = evalButObjViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavGalery::refreshObj(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzskHistRMUserUniversal rst;
	WzskHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstObj = 0;

	// feedFLstObj
	feedFLstObj.clear();

	dbswzsk->tblwzskhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVCard::CRDWZSKOBJ, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstObj.appendRefTitles(rec->ref, StubWzsk::getStubObjStd(dbswzsk, rec->unvUref, ixWzskVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTOBJ);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstObj(dbswzsk, moditems);
};

void PnlWzskNavGalery::refreshLstSes(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSesAvail = evalLstSesAvail(dbswzsk);
	statshr.ButSesViewActive = evalButSesViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavGalery::refreshSes(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzskHistRMUserUniversal rst;
	WzskHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSes = 0;

	// feedFLstSes
	feedFLstSes.clear();

	dbswzsk->tblwzskhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVCard::CRDWZSKSES, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstSes.appendRefTitles(rec->ref, StubWzsk::getStubSesStd(dbswzsk, rec->unvUref, ixWzskVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSES);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSes(dbswzsk, moditems);
};

void PnlWzskNavGalery::refreshLstSht(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstShtAvail = evalLstShtAvail(dbswzsk);
	statshr.ButShtViewActive = evalButShtViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavGalery::refreshSht(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzskHistRMUserUniversal rst;
	WzskHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSht = 0;

	// feedFLstSht
	feedFLstSht.clear();

	dbswzsk->tblwzskhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVCard::CRDWZSKSHT, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstSht.appendRefTitles(rec->ref, StubWzsk::getStubShtStd(dbswzsk, rec->unvUref, ixWzskVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSHT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSht(dbswzsk, moditems);
};

void PnlWzskNavGalery::refreshLstFil(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFilAvail = evalLstFilAvail(dbswzsk);
	statshr.ButFilViewActive = evalButFilViewActive(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskNavGalery::refreshFil(
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

void PnlWzskNavGalery::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWzskNavGalery::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);

	refreshLstOgr(dbswzsk, moditems);
	refreshLstObj(dbswzsk, moditems);
	refreshLstSes(dbswzsk, moditems);
	refreshLstSht(dbswzsk, moditems);
	refreshLstFil(dbswzsk, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWzskNavGalery::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVGALERYDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVGALERYDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTOGRVIEWCLICK) {
					handleDpchAppDoButOgrViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOGRNEWCRDCLICK) {
					handleDpchAppDoButOgrNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOBJVIEWCLICK) {
					handleDpchAppDoButObjViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOBJNEWCRDCLICK) {
					handleDpchAppDoButObjNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSESVIEWCLICK) {
					handleDpchAppDoButSesViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSESNEWCRDCLICK) {
					handleDpchAppDoButSesNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSHTVIEWCLICK) {
					handleDpchAppDoButShtViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSHTNEWCRDCLICK) {
					handleDpchAppDoButShtNewcrdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILNEWCRDCLICK) {
					handleDpchAppDoButFilNewcrdClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskNavGalery::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskNavGalery::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	ubigint ref;

	if (has(diffitems, ContIac::NUMFLSTOGR)) {
		contiac.numFLstOgr = _contiac->numFLstOgr;
		refreshLstOgr(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTOBJ)) {
		contiac.numFLstObj = _contiac->numFLstObj;
		if (dbswzsk->tblwzskhistrmuseruniversal->loadUnuByRef(feedFLstObj.getRefByNum(contiac.numFLstObj), ref)) xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKREFPRESET, jref, VecWzskVPreset::PREWZSKREFOBJ, ref);
		refreshLstObj(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSES)) {
		contiac.numFLstSes = _contiac->numFLstSes;
		refreshLstSes(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSHT)) {
		contiac.numFLstSht = _contiac->numFLstSht;
		refreshLstSht(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFIL)) {
		contiac.numFLstFil = _contiac->numFLstFil;
		refreshLstFil(dbswzsk, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskNavGalery::handleDpchAppDoButOgrViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	WzskHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstOgrAvail && statshr.ButOgrViewActive) {
		if (dbswzsk->tblwzskhistrmuseruniversal->loadRecByRef(feedFLstOgr.getRefByNum(contiac.numFLstOgr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, husrRunv->ixWzskVPreset, husrRunv->preUref, "CrdWzskOgr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskOgr");
	};
};

void PnlWzskNavGalery::handleDpchAppDoButOgrNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskOgr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskOgr");
};

void PnlWzskNavGalery::handleDpchAppDoButObjViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	WzskHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstObjAvail && statshr.ButObjViewActive) {
		if (dbswzsk->tblwzskhistrmuseruniversal->loadRecByRef(feedFLstObj.getRefByNum(contiac.numFLstObj), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, husrRunv->ixWzskVPreset, husrRunv->preUref, "CrdWzskObj", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskObj");
	};
};

void PnlWzskNavGalery::handleDpchAppDoButObjNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskObj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskObj");
};

void PnlWzskNavGalery::handleDpchAppDoButSesViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	WzskHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSesAvail && statshr.ButSesViewActive) {
		if (dbswzsk->tblwzskhistrmuseruniversal->loadRecByRef(feedFLstSes.getRefByNum(contiac.numFLstSes), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, husrRunv->ixWzskVPreset, husrRunv->preUref, "CrdWzskSes", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskSes");
	};
};

void PnlWzskNavGalery::handleDpchAppDoButSesNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskSes", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskSes");
};

void PnlWzskNavGalery::handleDpchAppDoButShtViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	WzskHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstShtAvail && statshr.ButShtViewActive) {
		if (dbswzsk->tblwzskhistrmuseruniversal->loadRecByRef(feedFLstSht.getRefByNum(contiac.numFLstSht), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, husrRunv->ixWzskVPreset, husrRunv->preUref, "CrdWzskSht", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskSht");
	};
};

void PnlWzskNavGalery::handleDpchAppDoButShtNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskSht", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskSht");
};

void PnlWzskNavGalery::handleDpchAppDoButFilViewClick(
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

void PnlWzskNavGalery::handleDpchAppDoButFilNewcrdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskFil");
};

void PnlWzskNavGalery::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWzskHusrRunvMod_crdUsrEq(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWzskNavGalery::handleCallWzskHusrRunvMod_crdUsrEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWzskVCard::CRDWZSKOGR) {
		refreshOgr(dbswzsk, moditems);
	} else if (ixInv == VecWzskVCard::CRDWZSKOBJ) {
		refreshObj(dbswzsk, moditems);
	} else if (ixInv == VecWzskVCard::CRDWZSKSES) {
		refreshSes(dbswzsk, moditems);
	} else if (ixInv == VecWzskVCard::CRDWZSKSHT) {
		refreshSht(dbswzsk, moditems);
	} else if (ixInv == VecWzskVCard::CRDWZSKFIL) {
		refreshFil(dbswzsk, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

