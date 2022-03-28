/**
	* \file PnlWzskPrsDetail.cpp
	* job handler for job PnlWzskPrsDetail (implementation)
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

#include "PnlWzskPrsDetail.h"

#include "PnlWzskPrsDetail_blks.cpp"
#include "PnlWzskPrsDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskPrsDetail
 ******************************************************************************/

PnlWzskPrsDetail::PnlWzskPrsDetail(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKPRSDETAIL, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFLstDrv.tag = "FeedFLstDrv";
	VecWzskWMPersonDerivate::fillFeed(ixWzskVLocale, feedFLstDrv);
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSex.tag = "FeedFPupSex";
	VecWzskVMPersonSex::fillFeed(ixWzskVLocale, feedFPupSex);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFPRS, jref);
};

PnlWzskPrsDetail::~PnlWzskPrsDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskPrsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDrv, &feedFPupJ, &feedFPupSex, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskPrsDetail::refreshJ(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ListWzskJMPersonLastname prsJlnms;
	WzskJMPersonLastname* prsJlnm = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbswzsk->tblwzskjmpersonlastname->loadRstByPrs(recPrs.ref, false, prsJlnms);

	for (unsigned int i = 0; i < prsJlnms.nodes.size(); i++) {
		prsJlnm = prsJlnms.nodes[i];

		s = "";
		if (prsJlnm->x1Startd != 0) {
			s = Ftm::date(prsJlnm->x1Startd) + " -";
			if ((i+2) < prsJlnms.nodes.size()) if (prsJlnms.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(prsJlnms.nodes[i+1]->x1Startd);
		} else s = "(" + VecWzskVTag::getTitle(VecWzskVTag::ALWAYS, ixWzskVLocale) + ")";
		feedFPupJ.appendRefTitles(prsJlnm->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecPrsJlnm(dbswzsk, moditems);

};

void PnlWzskPrsDetail::refreshTxtDrv(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstDrv.size(); i++) ix |= feedFLstDrv.getIxByNum(contiac.numsFLstDrv[i]);
	continf.TxtDrv = VecWzskWMPersonDerivate::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWzskPrsDetail::refreshRecPrs(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WzskMPerson* _recPrs = NULL;

	if (dbswzsk->tblwzskmperson->loadRecByRef(recPrs.ref, &_recPrs)) {
		recPrs = *_recPrs;
		delete _recPrs;
	} else recPrs = WzskMPerson();

	dirty = false;

	recPrsJlnm.ref = recPrs.refJLastname;
	if (recPrs.ref == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKPRSJLNMMOD_PRSEQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKPRSJLNMMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPrs.ref);

	contiac.TxfTit = recPrs.Title;
	contiac.TxfFnm = recPrs.Firstname;
	contiac.numsFLstDrv.clear();
	VecWzskWMPersonDerivate::getIcs(recPrs.ixWDerivate, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstDrv.push_back(feedFLstDrv.getNumByIx(*it));
	contiac.numFPupSex = feedFPupSex.getNumByIx(recPrs.ixVSex);
	contiac.TxfTel = recPrs.telVal;
	contiac.TxfEml = recPrs.emlVal;
	contiac.TxfSal = recPrs.Salutation;

	statshr.TxfTitActive = evalTxfTitActive(dbswzsk);
	statshr.TxfFnmActive = evalTxfFnmActive(dbswzsk);
	statshr.LstDrvActive = evalLstDrvActive(dbswzsk);
	statshr.PupSexActive = evalPupSexActive(dbswzsk);
	statshr.TxfTelActive = evalTxfTelActive(dbswzsk);
	statshr.TxfEmlActive = evalTxfEmlActive(dbswzsk);
	statshr.TxfSalActive = evalTxfSalActive(dbswzsk);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbswzsk, moditems);
	refreshTxtDrv(dbswzsk, moditems);

};

void PnlWzskPrsDetail::refreshRecPrsJlnm(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WzskJMPersonLastname* _recPrsJlnm = NULL;

	if (dbswzsk->tblwzskjmpersonlastname->loadRecByRef(recPrsJlnm.ref, &_recPrsJlnm)) {
		recPrsJlnm = *_recPrsJlnm;
		delete _recPrsJlnm;
	} else recPrsJlnm = WzskJMPersonLastname();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recPrsJlnm.ref);
	continf.TxtLnm = recPrsJlnm.Lastname;

	statshr.PupJActive = evalPupJActive(dbswzsk);
	statshr.ButJEditAvail = evalButJEditAvail(dbswzsk);
	statshr.TxtLnmActive = evalTxtLnmActive(dbswzsk);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzskPrsDetail::refresh(
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

void PnlWzskPrsDetail::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFPRS) {
		recPrs.ref = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFPRS, jref);
		refreshRecPrs(dbswzsk, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskPrsDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskPrsDetail::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskPrsDetail::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFFNM, ContIac::NUMFPUPSEX, ContIac::TXFTEL, ContIac::TXFEML, ContIac::TXFSAL})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::NUMFPUPSEX)) contiac.numFPupSex = _contiac->numFPupSex;
		if (has(diffitems, ContIac::TXFTEL)) contiac.TxfTel = _contiac->TxfTel;
		if (has(diffitems, ContIac::TXFEML)) contiac.TxfEml = _contiac->TxfEml;
		if (has(diffitems, ContIac::TXFSAL)) contiac.TxfSal = _contiac->TxfSal;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recPrsJlnm.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecPrsJlnm(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTDRV)) {
		contiac.numsFLstDrv = _contiac->numsFLstDrv;
		refreshTxtDrv(dbswzsk, moditems);
		refresh(dbswzsk, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskPrsDetail::handleDpchAppDoButSaveClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzskPrsDetail::handleDpchAppDoButJEditClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlWzskPrsDetail::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKPRSJLNMMOD_PRSEQ) {
		call->abort = handleCallWzskPrsJlnmMod_prsEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKPRSUPD_REFEQ) {
		call->abort = handleCallWzskPrsUpd_refEq(dbswzsk, call->jref);
	};
};

bool PnlWzskPrsDetail::handleCallWzskPrsJlnmMod_prsEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbswzsk, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWzskPrsDetail::handleCallWzskPrsUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskPrsUpd_refEq --- INSERT
	return retval;
};
