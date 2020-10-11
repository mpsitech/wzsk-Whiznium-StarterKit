/**
	* \file PnlWzskLiv3DView.cpp
	* job handler for job PnlWzskLiv3DView (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskLiv3DView.h"

#include "PnlWzskLiv3DView_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskLiv3DView
 ******************************************************************************/

PnlWzskLiv3DView::PnlWzskLiv3DView(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLIV3DVIEW, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	acqptcloud = NULL;

	// IP constructor.cust1 --- INSERT

	acqptcloud = new JobWzskAcqPtcloud(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSGECHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::TRY);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLiv3DView::~PnlWzskLiv3DView() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskLiv3DView::getNewDpchEng(
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

void PnlWzskLiv3DView::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	ubigint refWzskMObject;
	bool takenNotAvailable, fulfilled, run;

	refWzskMObject = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);
	xchg->getCsjobClaim(acqptcloud, takenNotAvailable, fulfilled, run);

	// contiac
	ContIac oldContiac(contiac);

	contiac.SldAin = acqptcloud->shrdat.deltaTheta;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;

	if (dbswzsk) {
		continf.TxtAst = acqptcloud->getSquawk(dbswzsk);
		continf.TxtAoa = StubWzsk::getStubObjStd(dbswzsk, refWzskMObject, ixWzskVLocale);
	};

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;

	statshr.SldAinActive = fulfilled && (acqptcloud->ixVSge == JobWzskAcqPtcloud::VecVSge::IDLE);

	statshr.TxtAoaAvail = (refWzskMObject != 0);

	statshr.ButAsrActive = (refWzskMObject != 0) && !run;
	statshr.ButAirActive = run;
	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskLiv3DView::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLAIMCLICK) {
					handleDpchAppDoButClaimClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTASRCLICK) {
					handleDpchAppDoButAsrClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTAIRCLICK) {
					handleDpchAppDoButAirClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskLiv3DView::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLiv3DView::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	muteRefresh = true;

	if (has(diffitems, ContIac::SLDAIN) && statshr.SldAinActive) acqptcloud->setDeltaTheta(dbswzsk, _contiac->SldAin);

	refresh(dbswzsk, moditems, true);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskLiv3DView::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLiv3DView::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLiv3DView::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, acqptcloud, new JobWzskAcqPtcloud::Claim(true, false, 0, 0));
		else xchg->removeCsjobClaim(dbswzsk, acqptcloud);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLiv3DView::handleDpchAppDoButAsrClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButAsrClick --- IBEGIN
	ubigint refWzskMSession, refWzskMObject;

	muteRefresh = true;

	refWzskMSession = xchg->getRefPreset(VecWzskVPreset::PREWZSKSESS, jref);
	refWzskMObject = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);

	if ((refWzskMSession != 0) && (refWzskMObject != 0)) xchg->addCsjobClaim(dbswzsk, acqptcloud, new JobWzskAcqPtcloud::Claim(false, true, refWzskMSession, refWzskMObject));

	refreshWithDpchEng(dbswzsk, dpcheng, true);
	// IP handleDpchAppDoButAsrClick --- IEND
};

void PnlWzskLiv3DView::handleDpchAppDoButAirClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButAirClick --- IBEGIN
	muteRefresh = true;

	xchg->addCsjobClaim(dbswzsk, acqptcloud, new JobWzskAcqPtcloud::Claim(true, false, 0, 0));

	refreshWithDpchEng(dbswzsk, dpcheng, true);
	// IP handleDpchAppDoButAirClick --- IEND
};

void PnlWzskLiv3DView::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSGECHG) {
		call->abort = handleCallWzskSgeChg(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) {
		call->abort = handleCallWzskResultNew(dbswzsk, call->jref, call->argInv.ix, call->argInv.sref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) {
		call->abort = handleCallWzskShrdatChg(dbswzsk, call->jref, call->argInv.ix, call->argInv.sref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) {
		call->abort = handleCallWzskClaimChg(dbswzsk, call->jref);
	};
};

bool PnlWzskLiv3DView::handleCallWzskSgeChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskSgeChg --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskSgeChg --- IEND
	return retval;
};

bool PnlWzskLiv3DView::handleCallWzskResultNew(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNew --- IBEGIN
	bool takenNotAvailable, fulfilled, run;

	JobWzskAcqPtcloud::Shrdat::ResultitemBody* ri = NULL;

	xchg->getCsjobClaim(acqptcloud, takenNotAvailable, fulfilled, run);

	if (run) {
		ri = (JobWzskAcqPtcloud::Shrdat::ResultitemBody*) acqptcloud->shrdat.resultBody[ixInv];

		xchg->submitDpch(new DpchEngLive(jref, ri->rNotL, ri->x, ri->y, ri->z, {DpchEngLive::ALL}));
	};
	// IP handleCallWzskResultNew --- IEND
	return retval;
};

bool PnlWzskLiv3DView::handleCallWzskShrdatChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChg --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskShrdatChg --- IEND
	return retval;
};

bool PnlWzskLiv3DView::handleCallWzskClaimChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskClaimChg --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskClaimChg --- IEND
	return retval;
};



