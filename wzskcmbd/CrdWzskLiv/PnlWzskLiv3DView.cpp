/**
	* \file PnlWzskLiv3DView.cpp
	* job handler for job PnlWzskLiv3DView (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
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
	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, acqptcloud->jref, false, Arg(), 0, Clstn::VecVJactype::TRY);

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
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskLiv3DView::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	ubigint refWzskMObject;
	bool takenNotAvailable, fulfilled, run;

	refWzskMObject = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);
	xchg->getCsjobClaim(acqptcloud, takenNotAvailable, fulfilled, run);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;

	continf.TxtAst = acqptcloud->getSquawk(dbswzsk);
	continf.TxtAoa = StubWzsk::getStubObjStd(dbswzsk, refWzskMObject, ixWzskVLocale);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;

	statshr.ButPlayActive = fulfilled && !run;
	statshr.ButStopActive = fulfilled && run;

	statshr.TxtAoaAvail = (refWzskMObject != 0);
	statshr.ButAstActive = true; // (refWzskMObject != 0) && run;

	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLAIMCLICK) {
					handleDpchAppDoButClaimClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPLAYCLICK) {
					handleDpchAppDoButPlayClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTOPCLICK) {
					handleDpchAppDoButStopClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTASTCLICK) {
					handleDpchAppDoButAstClick(dbswzsk, &(req->dpcheng));
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

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, acqptcloud, new Claim(true, false));
		else xchg->removeCsjobClaim(dbswzsk, acqptcloud);

		muteRefresh = false;

		refreshWithDpchEng(dbswzsk, dpcheng);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLiv3DView::handleDpchAppDoButPlayClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButPlayClick --- IBEGIN
	muteRefresh = true;

	xchg->addCsjobClaim(dbswzsk, acqptcloud, new Claim(true, true));

	muteRefresh = false;
	// IP handleDpchAppDoButPlayClick --- IEND
};

void PnlWzskLiv3DView::handleDpchAppDoButStopClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButStopClick --- IBEGIN
	muteRefresh = true;

	muteRefresh = false;
	// IP handleDpchAppDoButStopClick --- IEND
};

void PnlWzskLiv3DView::handleDpchAppDoButAstClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButAstClick --- INSERT
};

void PnlWzskLiv3DView::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSGECHG) {
		call->abort = handleCallWzskSgeChg(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) {
		call->abort = handleCallWzskClaimChg(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && (call->jref == acqptcloud->jref)) {
		call->abort = handleCallWzskResultNewFromAcqptcloud(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool PnlWzskLiv3DView::handleCallWzskSgeChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskSgeChg --- IBEGIN
	set<uint> moditems;

	if (!muteRefresh) {
		refresh(dbswzsk, moditems);
		if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP handleCallWzskSgeChg --- IEND
	return retval;
};

bool PnlWzskLiv3DView::handleCallWzskClaimChg(
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

bool PnlWzskLiv3DView::handleCallWzskResultNewFromAcqptcloud(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromAcqptcloud --- IBEGIN
	bool takenNotAvailable, fulfilled, run;

	JobWzskAcqPtcloud::Shrdat::ResultitemBody* ri = NULL;

	xchg->getCsjobClaim(acqptcloud, takenNotAvailable, fulfilled, run);

	if (run) {
		ri = (JobWzskAcqPtcloud::Shrdat::ResultitemBody*) acqptcloud->shrdat.resultBody[ixInv];

		xchg->submitDpch(new DpchEngLive(jref, ri->rNotL, ri->x, ri->y, ri->z, {DpchEngLive::ALL}));
	};
	// IP handleCallWzskResultNewFromAcqptcloud --- IEND
	return retval;
};



