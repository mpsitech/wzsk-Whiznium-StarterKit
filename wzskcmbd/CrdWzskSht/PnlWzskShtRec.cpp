/**
	* \file PnlWzskShtRec.cpp
	* job handler for job PnlWzskShtRec (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskShtRec.h"

#include "PnlWzskShtRec_blks.cpp"
#include "PnlWzskShtRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskShtRec
 ******************************************************************************/

PnlWzskShtRec::PnlWzskShtRec(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKSHTREC, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	pnlref1nfile = NULL;
	pnlapar = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKSHT_SESEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHT_OBJEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFSHT, jref);
};

PnlWzskShtRec::~PnlWzskShtRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskShtRec::getNewDpchEng(
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

void PnlWzskShtRec::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWzsk::getStubShtStd(dbswzsk, recSht.ref, ixWzskVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recSht.ref == 0) statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzsk);

	if (statshr.ixWzskVExpstate == VecWzskVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzskShtDetail(xchg, dbswzsk, jref, ixWzskVLocale);
		if (!pnlapar) pnlapar = new PnlWzskShtAPar(xchg, dbswzsk, jref, ixWzskVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlWzskShtRef1NFile(xchg, dbswzsk, jref, ixWzskVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzskShtRec::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFSHT) {
		WzskMShot* _recSht = NULL;

		if (dbswzsk->tblwzskmshot->loadRecByRef(xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSHT, jref), &_recSht)) {
			recSht = *_recSht;
			delete _recSht;
		} else recSht = WzskMShot();

		if (recSht.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
		};

		refresh(dbswzsk, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskShtRec::minimize(
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

void PnlWzskShtRec::regularize(
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

void PnlWzskShtRec::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTRECDO) {
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

void PnlWzskShtRec::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskShtRec::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	minimize(dbswzsk, true, dpcheng);
};

void PnlWzskShtRec::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	regularize(dbswzsk, true, dpcheng);
};

void PnlWzskShtRec::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSHTUPD_REFEQ) {
		call->abort = handleCallWzskShtUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSHT_SESEQ) {
		call->abort = handleCallWzskSht_sesEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSHT_OBJEQ) {
		call->abort = handleCallWzskSht_objEq(dbswzsk, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzskShtRec::handleCallWzskShtUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskShtUpd_refEq --- INSERT
	return retval;
};

bool PnlWzskShtRec::handleCallWzskSht_sesEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSht.refWzskMSession == refInv); // IP handleCallWzskSht_sesEq --- LINE
	return retval;
};

bool PnlWzskShtRec::handleCallWzskSht_objEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSht.refWzskMObject == refInv); // IP handleCallWzskSht_objEq --- LINE
	return retval;
};

