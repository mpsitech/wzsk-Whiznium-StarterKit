/**
	* \file PnlWzskLlvLaser.cpp
	* job handler for job PnlWzskLlvLaser (implementation)
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

#include "PnlWzskLlvLaser.h"

#include "PnlWzskLlvLaser_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskLlvLaser
 ******************************************************************************/

PnlWzskLlvLaser::PnlWzskLlvLaser(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLLVLASER, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	actlaser = NULL;

	// IP constructor.cust1 --- INSERT

	actlaser = new JobWzskActLaser(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::TRY);
	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLlvLaser::~PnlWzskLlvLaser() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskLlvLaser::getNewDpchEng(
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

void PnlWzskLlvLaser::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool takenNotAvailable, fulfilled;

	xchg->getCsjobClaim(actlaser, takenNotAvailable, fulfilled);

	// contiac
	ContIac oldContiac(contiac);

	contiac.SldLle = 100.0 * actlaser->shrdat.left;
	contiac.SldLri = 100.0 * actlaser->shrdat.right;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;

	statshr.SldLleActive = fulfilled;
	statshr.SldLriActive = fulfilled;

	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskLlvLaser::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVLASERDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVLASERDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLAIMCLICK) {
					handleDpchAppDoButClaimClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskLlvLaser::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLlvLaser::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	StgJobWzskActLaser stg_backup;

	muteRefresh = true;

	if (has(diffitems, ContIac::CHKERG)) contiac.ChkErg = _contiac->ChkErg;

	if (hasAny(diffitems, {ContIac::CHKERG,ContIac::SLDLLE}) && statshr.SldLleActive) {
		if (contiac.ChkErg) {
			stg_backup = actlaser->stg;

			actlaser->stg.leftMin = 0;
			actlaser->stg.leftMax = 1023;
			actlaser->stg.rightMin = 0;
			actlaser->stg.rightMax = 1023;
		};

		actlaser->setLeft(dbswzsk, 0.01 * _contiac->SldLle);

		if (contiac.ChkErg) actlaser->stg = stg_backup;
	};

	if (hasAny(diffitems, {ContIac::CHKERG,ContIac::SLDLRI}) && statshr.SldLriActive) {
		if (contiac.ChkErg) {
			stg_backup = actlaser->stg;

			actlaser->stg.leftMin = 0;
			actlaser->stg.leftMax = 1023;
			actlaser->stg.rightMin = 0;
			actlaser->stg.rightMax = 1023;
		};

		actlaser->setRight(dbswzsk, 0.01 * _contiac->SldLri);

		if (contiac.ChkErg) actlaser->stg = stg_backup;
	};

	muteRefresh = false;
	refresh(dbswzsk, moditems, true);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskLlvLaser::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLlvLaser::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLlvLaser::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, actlaser, new Claim(true));
		else xchg->removeCsjobClaim(dbswzsk, actlaser);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLlvLaser::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) {
		call->abort = handleCallWzskShrdatChg(dbswzsk, call->jref, call->argInv.ix, call->argInv.sref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) {
		call->abort = handleCallWzskClaimChg(dbswzsk, call->jref);
	};
};

bool PnlWzskLlvLaser::handleCallWzskShrdatChg(
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

bool PnlWzskLlvLaser::handleCallWzskClaimChg(
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
