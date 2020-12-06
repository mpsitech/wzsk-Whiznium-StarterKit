/**
	* \file PnlWzskOgrDetail.cpp
	* job handler for job PnlWzskOgrDetail (implementation)
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

#include "PnlWzskOgrDetail.h"

#include "PnlWzskOgrDetail_blks.cpp"
#include "PnlWzskOgrDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskOgrDetail
 ******************************************************************************/

PnlWzskOgrDetail::PnlWzskOgrDetail(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKOGRDETAIL, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupJ.tag = "FeedFPupJ";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKOGR_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFOGR, jref);
};

PnlWzskOgrDetail::~PnlWzskOgrDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskOgrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskOgrDetail::refreshJ(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ListWzskJMObjgroupTitle ogrJtits;
	WzskJMObjgroupTitle* ogrJtit = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbswzsk->tblwzskjmobjgrouptitle->loadRstByOgr(recOgr.ref, false, ogrJtits);

	for (unsigned int i = 0; i < ogrJtits.nodes.size(); i++) {
		ogrJtit = ogrJtits.nodes[i];

		s = "";
		feedFPupJ.appendRefTitles(ogrJtit->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecOgrJtit(dbswzsk, moditems);

};

void PnlWzskOgrDetail::refreshRecOgr(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzskMObjgroup* _recOgr = NULL;

	if (dbswzsk->tblwzskmobjgroup->loadRecByRef(recOgr.ref, &_recOgr)) {
		recOgr = *_recOgr;
		delete _recOgr;
	} else recOgr = WzskMObjgroup();

	dirty = false;

	recOgrJtit.ref = recOgr.refJTitle;
	if (recOgr.ref == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKOGRJTITMOD_OGREQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKOGRJTITMOD_OGREQ, jref, Clstn::VecVJobmask::ALL, 0, true, recOgr.ref);

	continf.TxtSrf = recOgr.sref;
	continf.TxtSup = StubWzsk::getStubOgrStd(dbswzsk, recOgr.supRefWzskMObjgroup, ixWzskVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recOgr.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswzsk);
	statshr.TxtSupActive = evalTxtSupActive(dbswzsk);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbswzsk);
	statshr.ButSupViewActive = evalButSupViewActive(dbswzsk);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswzsk);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbswzsk, moditems);

};

void PnlWzskOgrDetail::refreshRecOgrJtit(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzskJMObjgroupTitle* _recOgrJtit = NULL;

	if (dbswzsk->tblwzskjmobjgrouptitle->loadRecByRef(recOgrJtit.ref, &_recOgrJtit)) {
		recOgrJtit = *_recOgrJtit;
		delete _recOgrJtit;
	} else recOgrJtit = WzskJMObjgroupTitle();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recOgrJtit.ref);
	continf.TxtTit = recOgrJtit.Title;

	statshr.PupJActive = evalPupJActive(dbswzsk);
	statshr.ButJEditAvail = evalButJEditAvail(dbswzsk);
	statshr.TxtTitActive = evalTxtTitActive(dbswzsk);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzskOgrDetail::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswzsk);
	statshr.ButSaveActive = evalButSaveActive(dbswzsk);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskOgrDetail::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFOGR) {
		recOgr.ref = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOGR, jref);
		refreshRecOgr(dbswzsk, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskOgrDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskOgrDetail::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskOgrDetail::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recOgrJtit.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecOgrJtit(dbswzsk, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskOgrDetail::handleDpchAppDoButSaveClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzskOgrDetail::handleDpchAppDoButJEditClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlWzskOgrDetail::handleDpchAppDoButSupViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref)) {
			sref = "CrdWzskOgr";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, sref, recOgr.supRefWzskMObjgroup, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
};

void PnlWzskOgrDetail::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKOGRJTITMOD_OGREQ) {
		call->abort = handleCallWzskOgrJtitMod_ogrEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKOGRUPD_REFEQ) {
		call->abort = handleCallWzskOgrUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKOGR_SUPEQ) {
		call->abort = handleCallWzskOgr_supEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzskOgrDetail::handleCallWzskOgrJtitMod_ogrEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbswzsk, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWzskOgrDetail::handleCallWzskOgrUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskOgrUpd_refEq --- INSERT
	return retval;
};

bool PnlWzskOgrDetail::handleCallWzskOgr_supEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOgr.supRefWzskMObjgroup == refInv); // IP handleCallWzskOgr_supEq --- LINE
	return retval;
};
