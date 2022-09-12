/**
	* \file PnlWzskFilDetail.cpp
	* job handler for job PnlWzskFilDetail (implementation)
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

#include "PnlWzskFilDetail.h"

#include "PnlWzskFilDetail_blks.cpp"
#include "PnlWzskFilDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskFilDetail
 ******************************************************************************/

PnlWzskFilDetail::PnlWzskFilDetail(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKFILDETAIL, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupCnt.tag = "FeedFPupCnt";
	dbswzsk->fillFeedFromKlst(VecWzskVKeylist::KLSTWZSKKMFILECONTENT, ixWzskVLocale, feedFPupCnt);
	feedFPupMim.tag = "FeedFPupMim";
	dbswzsk->fillFeedFromKlst(VecWzskVKeylist::KLSTWZSKKMFILEMIMETYPE, ixWzskVLocale, feedFPupMim);
	feedFPupRet.tag = "FeedFPupRet";
	VecWzskVMFileRefTbl::fillFeed(ixWzskVLocale, feedFPupRet);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKFIL_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKFIL_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKFIL_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWzskVCall::CALLWZSKKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVKeylist::KLSTWZSKKMFILECONTENT);
	xchg->addIxClstn(VecWzskVCall::CALLWZSKKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVKeylist::KLSTWZSKKMFILEMIMETYPE);

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFFIL, jref);
};

PnlWzskFilDetail::~PnlWzskFilDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskFilDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupCnt, &feedFPupMim, &feedFPupRet, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskFilDetail::refreshLstClu(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCluActive = evalLstCluActive(dbswzsk);
	statshr.ButCluViewActive = evalButCluViewActive(dbswzsk);
	statshr.ButCluClusterAvail = evalButCluClusterAvail(dbswzsk);
	statshr.ButCluUnclusterAvail = evalButCluUnclusterAvail(dbswzsk);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskFilDetail::refreshClu(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	vector<ubigint> refs;

	bool first;

	// contiac
	contiac.numFLstClu = 0;

	// feedFLstClu, continf
	feedFLstClu.clear();
	continf.TxtClu = "";

	if (recFil.refWzskCFile != 0) dbswzsk->tblwzskmfile->loadRefsByClu(recFil.refWzskCFile, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recFil.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWzsk::getStubFilStd(dbswzsk, refs[i], ixWzskVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWzsk::getStubFilStd(dbswzsk, refs[i], ixWzskVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswzsk, moditems);
};

void PnlWzskFilDetail::refreshPupCnt(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupCnt = 0;

	for (unsigned int i = 0; i < feedFPupCnt.size(); i++) {
		if (feedFPupCnt.getSrefByNum(i+1) == contiac.TxfCnt) {
			contiac.numFPupCnt = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfCntValid = (contiac.numFPupCnt != 0);
	statshr.PupCntActive = evalPupCntActive(dbswzsk);
	statshr.ButCntEditAvail = evalButCntEditAvail(dbswzsk);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskFilDetail::refreshTxfCnt(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfCnt = feedFPupCnt.getSrefByNum(contiac.numFPupCnt);

	// statshr
	statshr.TxfCntValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskFilDetail::refreshCnt(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	// feedFPupCnt
	dbswzsk->fillFeedFromKlst(VecWzskVKeylist::KLSTWZSKKMFILECONTENT, ixWzskVLocale, feedFPupCnt);

	insert(moditems, DpchEngData::FEEDFPUPCNT);

	refreshPupCnt(dbswzsk, moditems);
};

void PnlWzskFilDetail::refreshPupMim(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupMim = 0;

	for (unsigned int i = 0; i < feedFPupMim.size(); i++) {
		if (feedFPupMim.getSrefByNum(i+1) == contiac.TxfMim) {
			contiac.numFPupMim = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfMimValid = (contiac.numFPupMim != 0);
	statshr.PupMimActive = evalPupMimActive(dbswzsk);
	statshr.ButMimEditAvail = evalButMimEditAvail(dbswzsk);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskFilDetail::refreshTxfMim(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfMim = feedFPupMim.getSrefByNum(contiac.numFPupMim);

	// statshr
	statshr.TxfMimValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskFilDetail::refreshMim(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	// feedFPupMim
	dbswzsk->fillFeedFromKlst(VecWzskVKeylist::KLSTWZSKKMFILEMIMETYPE, ixWzskVLocale, feedFPupMim);

	insert(moditems, DpchEngData::FEEDFPUPMIM);

	refreshPupMim(dbswzsk, moditems);
};

void PnlWzskFilDetail::refreshRecFil(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzskMFile* _recFil = NULL;

	if (dbswzsk->tblwzskmfile->loadRecByRef(recFil.ref, &_recFil)) {
		recFil = *_recFil;
		delete _recFil;
	} else recFil = WzskMFile();

	dirty = false;

	if (recFil.refWzskCFile == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKFILMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKFILMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recFil.refWzskCFile);

	contiac.TxfFnm = recFil.Filename;
	contiac.numFPupRet = feedFPupRet.getNumByIx(recFil.refIxVTbl);
	if (recFil.refIxVTbl == VecWzskVMFileRefTbl::OBJ) continf.TxtReu = StubWzsk::getStubObjStd(dbswzsk, recFil.refUref, ixWzskVLocale, Stub::VecVNonetype::FULL);
	else if (recFil.refIxVTbl == VecWzskVMFileRefTbl::SHT) continf.TxtReu = StubWzsk::getStubShtStd(dbswzsk, recFil.refUref, ixWzskVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	contiac.TxfCnt = recFil.osrefKContent;
	contiac.TxfAcv = Ftm::stamp(recFil.Archived);
	contiac.TxfAnm = recFil.Archivename;
	contiac.TxfMim = recFil.srefKMimetype;
	contiac.TxfSiz = to_string(recFil.Size);
	contiac.TxfCmt = recFil.Comment;

	statshr.TxfFnmActive = evalTxfFnmActive(dbswzsk);
	statshr.TxtReuActive = evalTxtReuActive(dbswzsk);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswzsk);
	statshr.ButReuViewActive = evalButReuViewActive(dbswzsk);
	statshr.TxfAcvActive = evalTxfAcvActive(dbswzsk);
	statshr.TxfAnmActive = evalTxfAnmActive(dbswzsk);
	statshr.TxfSizActive = evalTxfSizActive(dbswzsk);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswzsk);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbswzsk, moditems);
	refreshPupCnt(dbswzsk, moditems);
	refreshPupMim(dbswzsk, moditems);

};

void PnlWzskFilDetail::refresh(
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

void PnlWzskFilDetail::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFFIL) {
		recFil.ref = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFFIL, jref);
		refreshRecFil(dbswzsk, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskFilDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCNTEDITCLICK) {
					handleDpchAppDoButCntEditClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMIMEDITCLICK) {
					handleDpchAppDoButMimEditClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskFilDetail::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskFilDetail::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFFNM, ContIac::TXFACV, ContIac::TXFANM, ContIac::TXFSIZ, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::TXFACV)) contiac.TxfAcv = _contiac->TxfAcv;
		if (has(diffitems, ContIac::TXFANM)) contiac.TxfAnm = _contiac->TxfAnm;
		if (has(diffitems, ContIac::TXFSIZ)) contiac.TxfSiz = _contiac->TxfSiz;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::TXFCNT)) {
		contiac.TxfCnt = _contiac->TxfCnt;
		refreshPupCnt(dbswzsk, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPCNT)) {
		contiac.numFPupCnt = _contiac->numFPupCnt;
		refreshTxfCnt(dbswzsk, moditems);
	};

	if (has(diffitems, ContIac::TXFMIM)) {
		contiac.TxfMim = _contiac->TxfMim;
		refreshPupMim(dbswzsk, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPMIM)) {
		contiac.numFPupMim = _contiac->numFPupMim;
		refreshTxfMim(dbswzsk, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskFilDetail::handleDpchAppDoButSaveClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzskFilDetail::handleDpchAppDoButCluViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWzskFilDetail::handleDpchAppDoButCluClusterClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWzskFilDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWzskFilDetail::handleDpchAppDoButReuViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref)) if (recFil.refIxVTbl == VecWzskVMFileRefTbl::SHT) if (ixPre == VecWzskVPreset::PREWZSKREFOBJ) {
			sref = "CrdWzskSht";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, ixPre, refPre, sref, recFil.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref)) if (recFil.refIxVTbl == VecWzskVMFileRefTbl::SHT) {
				sref = "CrdWzskSht";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, sref, recFil.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref)) if (recFil.refIxVTbl == VecWzskVMFileRefTbl::OBJ) {
				sref = "CrdWzskObj";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, sref, recFil.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
};

void PnlWzskFilDetail::handleDpchAppDoButCntEditClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButCntEditClick --- INSERT
};

void PnlWzskFilDetail::handleDpchAppDoButMimEditClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMimEditClick --- INSERT
};

void PnlWzskFilDetail::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKFILMOD_CLUEQ) {
		call->abort = handleCallWzskFilMod_cluEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWzskKlsAkeyMod_klsEq(dbswzsk, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKFILUPD_REFEQ) {
		call->abort = handleCallWzskFilUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKFIL_REUEQ) {
		call->abort = handleCallWzskFil_reuEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKFIL_CLUEQ) {
		call->abort = handleCallWzskFil_cluEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKFIL_RETEQ) {
		call->abort = handleCallWzskFil_retEq(dbswzsk, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWzskFilDetail::handleCallWzskFilMod_cluEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswzsk, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWzskFilDetail::handleCallWzskKlsAkeyMod_klsEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWzskVKeylist::KLSTWZSKKMFILECONTENT) {
		refreshCnt(dbswzsk, moditems);
	} else if (ixInv == VecWzskVKeylist::KLSTWZSKKMFILEMIMETYPE) {
		refreshMim(dbswzsk, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWzskFilDetail::handleCallWzskFilUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskFilUpd_refEq --- INSERT
	return retval;
};

bool PnlWzskFilDetail::handleCallWzskFil_reuEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFil.refUref == refInv); // IP handleCallWzskFil_reuEq --- LINE
	return retval;
};

bool PnlWzskFilDetail::handleCallWzskFil_cluEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFil.refWzskCFile == refInv); // IP handleCallWzskFil_cluEq --- LINE
	return retval;
};

bool PnlWzskFilDetail::handleCallWzskFil_retEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFil.refIxVTbl == ixInv); // IP handleCallWzskFil_retEq --- LINE
	return retval;
};
