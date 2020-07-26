/**
	* \file PnlWzskLlvLaser.cpp
	* job handler for job PnlWzskLlvLaser (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool takenNotAvailable, fulfilled;

	xchg->getCsjobClaim(actlaser, takenNotAvailable, fulfilled);

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

	usmallint min_backup, max_backup;

	if (has(diffitems, ContIac::CHKERG)) contiac.ChkErg = _contiac->ChkErg;
	if (has(diffitems, ContIac::SLDLLE) && statshr.SldLleActive) contiac.SldLle = _contiac->SldLle;
	if (has(diffitems, ContIac::SLDLRI) && statshr.SldLriActive) contiac.SldLri = _contiac->SldLri;

	if (hasAny(diffitems, {ContIac::CHKERG,ContIac::SLDLLE})) {
		if (contiac.ChkErg) {
			min_backup = actlaser->stg.leftMin;
			max_backup = actlaser->stg.leftMax;

			actlaser->stg.leftMin = 0;
			actlaser->stg.leftMax = 1023;
		};

		actlaser->setLeft(dbswzsk, 0.01 * contiac.SldLle);

		if (contiac.ChkErg) {
			actlaser->stg.leftMin = min_backup;
			actlaser->stg.leftMax = max_backup;
		};
	};

	if (hasAny(diffitems, {ContIac::CHKERG,ContIac::SLDLRI})) {
		if (contiac.ChkErg) {
			min_backup = actlaser->stg.rightMin;
			max_backup = actlaser->stg.rightMax;

			actlaser->stg.rightMin = 0;
			actlaser->stg.rightMax = 1023;
		};

		actlaser->setRight(dbswzsk, 0.01 * contiac.SldLri);

		if (contiac.ChkErg) {
			actlaser->stg.rightMin = min_backup;
			actlaser->stg.rightMax = max_backup;
		};
	};

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

		muteRefresh = false;

		refreshWithDpchEng(dbswzsk, dpcheng);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLlvLaser::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) {
		call->abort = handleCallWzskClaimChg(dbswzsk, call->jref);
	};
};

bool PnlWzskLlvLaser::handleCallWzskClaimChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskClaimChg --- IBEGIN
	set<uint> moditems;

	if (!muteRefresh) {
		refresh(dbswzsk, moditems);
		if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP handleCallWzskClaimChg --- IEND
	return retval;
};


