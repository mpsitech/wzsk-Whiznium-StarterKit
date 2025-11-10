/**
	* \file PnlWzskFilRec.cpp
	* job handler for job PnlWzskFilRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskFilRec.h"

#include "PnlWzskFilRec_blks.cpp"
#include "PnlWzskFilRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskFilRec
 ******************************************************************************/

PnlWzskFilRec::PnlWzskFilRec(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKFILREC, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKFIL_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFFIL, jref);
};

PnlWzskFilRec::~PnlWzskFilRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskFilRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskFilRec::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWzsk::getStubFilStd(dbswzsk, recFil.ref, ixWzskVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recFil.ref == 0) statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzsk);

	if (statshr.ixWzskVExpstate == VecWzskVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzskFilDetail(xchg, dbswzsk, jref, ixWzskVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskFilRec::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFFIL) {
		WzskMFile* _recFil = NULL;

		if (dbswzsk->tblwzskmfile->loadRecByRef(xchg->getRefPreset(VecWzskVPreset::PREWZSKREFFIL, jref), &_recFil)) {
			recFil = *_recFil;
			delete _recFil;
		} else recFil = WzskMFile();

		if (recFil.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
		};

		refresh(dbswzsk, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskFilRec::minimize(
			DbsWzsk* dbswzsk
			, const bool notif
			, DpchEngWzsk** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWzskVExpstate != VecWzskVExpstate::MIND) {
		statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswzsk, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWzskFilRec::regularize(
			DbsWzsk* dbswzsk
			, const bool notif
			, DpchEngWzsk** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWzskVExpstate != VecWzskVExpstate::REGD) {
		statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswzsk, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWzskFilRec::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskFilRec::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskFilRec::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	minimize(dbswzsk, true, dpcheng);
};

void PnlWzskFilRec::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	regularize(dbswzsk, true, dpcheng);
};

void PnlWzskFilRec::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKFIL_CLUEQ) {
		call->abort = handleCallWzskFil_cluEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKFILUPD_REFEQ) {
		call->abort = handleCallWzskFilUpd_refEq(dbswzsk, call->jref);
	};
};

bool PnlWzskFilRec::handleCallWzskFil_cluEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFil.refWzskCFile == refInv); // IP handleCallWzskFil_cluEq --- LINE
	return retval;
};

bool PnlWzskFilRec::handleCallWzskFilUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskFilUpd_refEq --- INSERT
	return retval;
};
