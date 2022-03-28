/**
	* \file PnlWzskObjRec.cpp
	* job handler for job PnlWzskObjRec (implementation)
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

#include "PnlWzskObjRec.h"

#include "PnlWzskObjRec_blks.cpp"
#include "PnlWzskObjRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskObjRec
 ******************************************************************************/

PnlWzskObjRec::PnlWzskObjRec(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKOBJREC, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	pnlref1nfile = NULL;
	pnl1nshot = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKOBJ_OGREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFOBJ, jref);
};

PnlWzskObjRec::~PnlWzskObjRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskObjRec::getNewDpchEng(
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

void PnlWzskObjRec::refresh(
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
	continf.TxtRef = StubWzsk::getStubObjStd(dbswzsk, recObj.ref, ixWzskVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recObj.ref == 0) statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzsk);

	if (statshr.ixWzskVExpstate == VecWzskVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nshot) {delete pnl1nshot; pnl1nshot = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzskObjDetail(xchg, dbswzsk, jref, ixWzskVLocale);
		if (!pnl1nshot) pnl1nshot = new PnlWzskObj1NShot(xchg, dbswzsk, jref, ixWzskVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlWzskObjRef1NFile(xchg, dbswzsk, jref, ixWzskVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NShot = ((pnl1nshot) ? pnl1nshot->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskObjRec::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFOBJ) {
		WzskMObject* _recObj = NULL;

		if (dbswzsk->tblwzskmobject->loadRecByRef(xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref), &_recObj)) {
			recObj = *_recObj;
			delete _recObj;
		} else recObj = WzskMObject();

		if (recObj.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
			if (pnl1nshot) pnl1nshot->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
		};

		refresh(dbswzsk, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskObjRec::minimize(
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

void PnlWzskObjRec::regularize(
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

void PnlWzskObjRec::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJRECDO) {
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

void PnlWzskObjRec::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskObjRec::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	minimize(dbswzsk, true, dpcheng);
};

void PnlWzskObjRec::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	regularize(dbswzsk, true, dpcheng);
};

void PnlWzskObjRec::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKOBJUPD_REFEQ) {
		call->abort = handleCallWzskObjUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKOBJ_OGREQ) {
		call->abort = handleCallWzskObj_ogrEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzskObjRec::handleCallWzskObjUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskObjUpd_refEq --- INSERT
	return retval;
};

bool PnlWzskObjRec::handleCallWzskObj_ogrEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recObj.refWzskMObjgroup == refInv); // IP handleCallWzskObj_ogrEq --- LINE
	return retval;
};
