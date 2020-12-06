/**
	* \file PnlWzskSesDetail.cpp
	* job handler for job PnlWzskSesDetail (implementation)
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

#include "PnlWzskSesDetail.h"

#include "PnlWzskSesDetail_blks.cpp"
#include "PnlWzskSesDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskSesDetail
 ******************************************************************************/

PnlWzskSesDetail::PnlWzskSesDetail(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKSESDETAIL, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKSES_USREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFSES, jref);
};

PnlWzskSesDetail::~PnlWzskSesDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskSesDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskSesDetail::refreshRecSes(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzskMSession* _recSes = NULL;

	if (dbswzsk->tblwzskmsession->loadRecByRef(recSes.ref, &_recSes)) {
		recSes = *_recSes;
		delete _recSes;
	} else recSes = WzskMSession();

	dirty = false;

	continf.TxtUsr = StubWzsk::getStubUsrStd(dbswzsk, recSes.refWzskMUser, ixWzskVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfSta = Ftm::stamp(recSes.start);
	contiac.TxfSto = Ftm::stamp(recSes.stop);
	contiac.TxfIp = recSes.Ip;

	statshr.TxtUsrActive = evalTxtUsrActive(dbswzsk);
	statshr.ButUsrViewAvail = evalButUsrViewAvail(dbswzsk);
	statshr.ButUsrViewActive = evalButUsrViewActive(dbswzsk);
	statshr.TxfStaActive = evalTxfStaActive(dbswzsk);
	statshr.TxfStoActive = evalTxfStoActive(dbswzsk);
	statshr.TxfIpActive = evalTxfIpActive(dbswzsk);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzskSesDetail::refresh(
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

void PnlWzskSesDetail::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFSES) {
		recSes.ref = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSES, jref);
		refreshRecSes(dbswzsk, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskSesDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSESDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSESDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRVIEWCLICK) {
					handleDpchAppDoButUsrViewClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskSesDetail::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskSesDetail::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSTA, ContIac::TXFSTO, ContIac::TXFIP})) {
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::TXFIP)) contiac.TxfIp = _contiac->TxfIp;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskSesDetail::handleDpchAppDoButSaveClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzskSesDetail::handleDpchAppDoButUsrViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButUsrViewAvail && statshr.ButUsrViewActive) {
		if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref)) {
			sref = "CrdWzskUsr";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, sref, recSes.refWzskMUser, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
};

void PnlWzskSesDetail::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSESUPD_REFEQ) {
		call->abort = handleCallWzskSesUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSES_USREQ) {
		call->abort = handleCallWzskSes_usrEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzskSesDetail::handleCallWzskSesUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskSesUpd_refEq --- INSERT
	return retval;
};

bool PnlWzskSesDetail::handleCallWzskSes_usrEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSes.refWzskMUser == refInv); // IP handleCallWzskSes_usrEq --- LINE
	return retval;
};
