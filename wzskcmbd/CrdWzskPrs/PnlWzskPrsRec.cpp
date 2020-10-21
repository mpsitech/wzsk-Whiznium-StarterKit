/**
	* \file PnlWzskPrsRec.cpp
	* job handler for job PnlWzskPrsRec (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskPrsRec.h"

#include "PnlWzskPrsRec_blks.cpp"
#include "PnlWzskPrsRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskPrsRec
 ******************************************************************************/

PnlWzskPrsRec::PnlWzskPrsRec(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKPRSREC, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	pnladetail = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzsk, VecWzskVPreset::PREWZSKREFPRS, jref);
};

PnlWzskPrsRec::~PnlWzskPrsRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskPrsRec::getNewDpchEng(
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

void PnlWzskPrsRec::refresh(
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
	continf.TxtRef = StubWzsk::getStubPrsStd(dbswzsk, recPrs.ref, ixWzskVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recPrs.ref == 0) statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzsk);

	if (statshr.ixWzskVExpstate == VecWzskVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnladetail) {delete pnladetail; pnladetail = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzskPrsDetail(xchg, dbswzsk, jref, ixWzskVLocale);
		if (!pnladetail) pnladetail = new PnlWzskPrsADetail(xchg, dbswzsk, jref, ixWzskVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefADetail = ((pnladetail) ? pnladetail->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskPrsRec::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFPRS) {
		WzskMPerson* _recPrs = NULL;

		if (dbswzsk->tblwzskmperson->loadRecByRef(xchg->getRefPreset(VecWzskVPreset::PREWZSKREFPRS, jref), &_recPrs)) {
			recPrs = *_recPrs;
			delete _recPrs;
		} else recPrs = WzskMPerson();

		if (recPrs.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
			if (pnladetail) pnladetail->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
		};

		refresh(dbswzsk, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzskPrsRec::minimize(
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

void PnlWzskPrsRec::regularize(
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

void PnlWzskPrsRec::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSRECDO) {
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

void PnlWzskPrsRec::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskPrsRec::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	minimize(dbswzsk, true, dpcheng);
};

void PnlWzskPrsRec::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	regularize(dbswzsk, true, dpcheng);
};

void PnlWzskPrsRec::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKPRSUPD_REFEQ) {
		call->abort = handleCallWzskPrsUpd_refEq(dbswzsk, call->jref);
	};
};

bool PnlWzskPrsRec::handleCallWzskPrsUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskPrsUpd_refEq --- INSERT
	return retval;
};

