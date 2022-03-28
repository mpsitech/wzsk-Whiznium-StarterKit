/**
	* \file PnlWzskUsrDetail.cpp
	* job handler for job PnlWzskUsrDetail (implementation)
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

#include "PnlWzskUsrDetail.h"

#include "PnlWzskUsrDetail_blks.cpp"
#include "PnlWzskUsrDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskUsrDetail
 ******************************************************************************/

PnlWzskUsrDetail::PnlWzskUsrDetail(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKUSRDETAIL, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupLcl.tag = "FeedFPupLcl";
	VecWzskVLocale::fillFeed(ixWzskVLocale, feedFPupLcl);
	feedFPupSte.tag = "FeedFPupSte";
	VecWzskVMUserState::fillFeed(ixWzskVLocale, feedFPupSte);
	feedFPupUlv.tag = "FeedFPupUlv";
	VecWzskVUserlevel::fillFeed(ixWzskVLocale, feedFPupUlv);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKUSR_USGEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKUSR_PRSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFUSR, jref);
};

PnlWzskUsrDetail::~PnlWzskUsrDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskUsrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &feedFPupLcl, &feedFPupSte, &feedFPupUlv, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskUsrDetail::refreshJ(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ListWzskJMUserState usrJstes;
	WzskJMUserState* usrJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbswzsk->tblwzskjmuserstate->loadRstByUsr(recUsr.ref, false, usrJstes);

	for (unsigned int i = 0; i < usrJstes.nodes.size(); i++) {
		usrJste = usrJstes.nodes[i];

		s = "";
		if (usrJste->x1Start != 0) {
			s = Ftm::stamp(usrJste->x1Start) + " -";
			if ((i+2) < usrJstes.nodes.size()) if (usrJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::stamp(usrJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecWzskVTag::getTitle(VecWzskVTag::ALWAYS, ixWzskVLocale) + ")";
		feedFPupJ.appendRefTitles(usrJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecUsrJste(dbswzsk, moditems);

};

void PnlWzskUsrDetail::refreshRecUsr(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzskMUser* _recUsr = NULL;

	if (dbswzsk->tblwzskmuser->loadRecByRef(recUsr.ref, &_recUsr)) {
		recUsr = *_recUsr;
		delete _recUsr;
	} else recUsr = WzskMUser();

	dirty = false;

	recUsrJste.ref = recUsr.refJState;
	if (recUsr.ref == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKUSRJSTEMOD_USREQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKUSRJSTEMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, true, recUsr.ref);

	continf.TxtPrs = StubWzsk::getStubPrsStd(dbswzsk, recUsr.refWzskMPerson, ixWzskVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSrf = recUsr.sref;
	continf.TxtUsg = StubWzsk::getStubUsgStd(dbswzsk, recUsr.refWzskMUsergroup, ixWzskVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupLcl = feedFPupLcl.getNumByIx(recUsr.ixWzskVLocale);
	contiac.numFPupUlv = feedFPupUlv.getNumByIx(recUsr.ixWzskVUserlevel);
	contiac.TxfPwd = recUsr.Password;
	contiac.TxfFky = recUsr.Fullkey;
	contiac.TxfCmt = recUsr.Comment;

	statshr.TxtPrsActive = evalTxtPrsActive(dbswzsk);
	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbswzsk);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbswzsk);
	statshr.TxtSrfActive = evalTxtSrfActive(dbswzsk);
	statshr.TxtUsgActive = evalTxtUsgActive(dbswzsk);
	statshr.ButUsgViewAvail = evalButUsgViewAvail(dbswzsk);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbswzsk);
	statshr.PupLclActive = evalPupLclActive(dbswzsk);
	statshr.PupUlvActive = evalPupUlvActive(dbswzsk);
	statshr.TxfPwdActive = evalTxfPwdActive(dbswzsk);
	statshr.TxfFkyActive = evalTxfFkyActive(dbswzsk);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswzsk);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbswzsk, moditems);

};

void PnlWzskUsrDetail::refreshRecUsrJste(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzskJMUserState* _recUsrJste = NULL;

	if (dbswzsk->tblwzskjmuserstate->loadRecByRef(recUsrJste.ref, &_recUsrJste)) {
		recUsrJste = *_recUsrJste;
		delete _recUsrJste;
	} else recUsrJste = WzskJMUserState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recUsrJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recUsrJste.ixVState);

	statshr.PupJActive = evalPupJActive(dbswzsk);
	statshr.ButJEditAvail = evalButJEditAvail(dbswzsk);
	statshr.PupSteActive = evalPupSteActive(dbswzsk);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzskUsrDetail::refresh(
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

void PnlWzskUsrDetail::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFUSR) {
		recUsr.ref = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFUSR, jref);
		refreshRecUsr(dbswzsk, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskUsrDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskUsrDetail::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskUsrDetail::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSTE, ContIac::NUMFPUPLCL, ContIac::NUMFPUPULV, ContIac::TXFPWD, ContIac::TXFFKY, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::NUMFPUPLCL)) contiac.numFPupLcl = _contiac->numFPupLcl;
		if (has(diffitems, ContIac::NUMFPUPULV)) contiac.numFPupUlv = _contiac->numFPupUlv;
		if (has(diffitems, ContIac::TXFPWD)) contiac.TxfPwd = _contiac->TxfPwd;
		if (has(diffitems, ContIac::TXFFKY)) contiac.TxfFky = _contiac->TxfFky;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recUsrJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecUsrJste(dbswzsk, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskUsrDetail::handleDpchAppDoButSaveClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzskUsrDetail::handleDpchAppDoButPrsViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrsViewAvail && statshr.ButPrsViewActive) {
		if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref)) {
			sref = "CrdWzskPrs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, sref, recUsr.refWzskMPerson, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
};

void PnlWzskUsrDetail::handleDpchAppDoButUsgViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButUsgViewAvail && statshr.ButUsgViewActive) {
		if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref)) {
			sref = "CrdWzskUsg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, sref, recUsr.refWzskMUsergroup, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
};

void PnlWzskUsrDetail::handleDpchAppDoButJEditClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlWzskUsrDetail::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKUSRJSTEMOD_USREQ) {
		call->abort = handleCallWzskUsrJsteMod_usrEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKUSRUPD_REFEQ) {
		call->abort = handleCallWzskUsrUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKUSR_USGEQ) {
		call->abort = handleCallWzskUsr_usgEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKUSR_PRSEQ) {
		call->abort = handleCallWzskUsr_prsEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzskUsrDetail::handleCallWzskUsrJsteMod_usrEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbswzsk, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWzskUsrDetail::handleCallWzskUsrUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlWzskUsrDetail::handleCallWzskUsr_usgEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWzskMUsergroup == refInv); // IP handleCallWzskUsr_usgEq --- LINE
	return retval;
};

bool PnlWzskUsrDetail::handleCallWzskUsr_prsEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWzskMPerson == refInv); // IP handleCallWzskUsr_prsEq --- LINE
	return retval;
};
