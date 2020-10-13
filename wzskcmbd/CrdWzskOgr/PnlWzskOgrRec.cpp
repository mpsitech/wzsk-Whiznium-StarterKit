/**
	* \file PnlWzskOgrRec.cpp
	* job handler for job PnlWzskOgrRec (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskOgrRec.h"

#include "PnlWzskOgrRec_blks.cpp"
#include "PnlWzskOgrRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskOgrRec
 ******************************************************************************/

PnlWzskOgrRec::PnlWzskOgrRec(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKOGRREC, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	pnlsup1nobjgroup = NULL;
	pnl1nobject = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKOGR_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFOGR, jref);
};

PnlWzskOgrRec::~PnlWzskOgrRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskOgrRec::getNewDpchEng(
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

void PnlWzskOgrRec::refresh(
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
	continf.TxtRef = StubWzsk::getStubOgrStd(dbswzsk, recOgr.ref, ixWzskVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recOgr.ref == 0) statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzsk);

	if (statshr.ixWzskVExpstate == VecWzskVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nobject) {delete pnl1nobject; pnl1nobject = NULL;};
		if (pnlsup1nobjgroup) {delete pnlsup1nobjgroup; pnlsup1nobjgroup = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzskOgrDetail(xchg, dbswzsk, jref, ixWzskVLocale);
		if (!pnl1nobject) pnl1nobject = new PnlWzskOgr1NObject(xchg, dbswzsk, jref, ixWzskVLocale);
		if (!pnlsup1nobjgroup) pnlsup1nobjgroup = new PnlWzskOgrSup1NObjgroup(xchg, dbswzsk, jref, ixWzskVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NObject = ((pnl1nobject) ? pnl1nobject->jref : 0);
	statshr.jrefSup1NObjgroup = ((pnlsup1nobjgroup) ? pnlsup1nobjgroup->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskOgrRec::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFOGR) {
		WzskMObjgroup* _recOgr = NULL;

		if (dbswzsk->tblwzskmobjgroup->loadRecByRef(xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOGR, jref), &_recOgr)) {
			recOgr = *_recOgr;
			delete _recOgr;
		} else recOgr = WzskMObjgroup();

		if (recOgr.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
			if (pnl1nobject) pnl1nobject->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
			if (pnlsup1nobjgroup) pnlsup1nobjgroup->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
		};

		refresh(dbswzsk, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskOgrRec::minimize(
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

void PnlWzskOgrRec::regularize(
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

void PnlWzskOgrRec::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRRECDO) {
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

void PnlWzskOgrRec::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskOgrRec::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	minimize(dbswzsk, true, dpcheng);
};

void PnlWzskOgrRec::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	regularize(dbswzsk, true, dpcheng);
};

void PnlWzskOgrRec::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKOGRUPD_REFEQ) {
		call->abort = handleCallWzskOgrUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKOGR_SUPEQ) {
		call->abort = handleCallWzskOgr_supEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzskOgrRec::handleCallWzskOgrUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskOgrUpd_refEq --- INSERT
	return retval;
};

bool PnlWzskOgrRec::handleCallWzskOgr_supEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOgr.supRefWzskMObjgroup == refInv); // IP handleCallWzskOgr_supEq --- LINE
	return retval;
};

