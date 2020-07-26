/**
	* \file PnlWzskLiv2DView.cpp
	* job handler for job PnlWzskLiv2DView (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskLiv2DView.h"

#include "PnlWzskLiv2DView_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskLiv2DView
 ******************************************************************************/

PnlWzskLiv2DView::PnlWzskLiv2DView(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLIV2DVIEW, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupPvm.tag = "FeedFPupPvm";
	VecWzskVPvwmode::fillFeed(ixWzskVLocale, feedFPupPvm);

	iprtrace = NULL;
	iprcorner = NULL;
	actservo = NULL;
	acqpreview = NULL;

	// IP constructor.cust1 --- INSERT

	iprtrace = new JobWzskIprTrace(xchg, dbswzsk, jref, ixWzskVLocale);
	iprcorner = new JobWzskIprCorner(xchg, dbswzsk, jref, ixWzskVLocale);
	actservo = new JobWzskActServo(xchg, dbswzsk, jref, ixWzskVLocale);
	acqpreview = new JobWzskAcqPreview(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- IBEGIN
	// preliminary
	contiac.SldExt = statshr.SldExtMin;
	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSGECHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTGCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::SPEC, iprtrace->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::SPEC, iprcorner->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::TRY);
	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::SPEC, acqpreview->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLiv2DView::~PnlWzskLiv2DView() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void PnlWzskLiv2DView::refreshAlign(
			set<uint>& moditems
		) {
	ContIacCorner oldContiaccorner(contiaccorner);

	iprcorner->shrdat.rlockAccess("PnlWzskLiv2DView", "refreshAlign", "jref=" + to_string(jref));

	contiaccorner.roiAx = iprcorner->shrdat.roiAx;
	contiaccorner.roiAy = iprcorner->shrdat.roiAy;
	contiaccorner.roiBx = iprcorner->shrdat.roiBx;
	contiaccorner.roiBy = iprcorner->shrdat.roiBy;
	contiaccorner.roiCx = iprcorner->shrdat.roiCx;
	contiaccorner.roiCy = iprcorner->shrdat.roiCy;
	contiaccorner.roiDx = iprcorner->shrdat.roiDx;
	contiaccorner.roiDy = iprcorner->shrdat.roiDy;

	iprcorner->shrdat.runlockAccess("PnlWzskLiv2DView", "refreshAlign", "jref=" + to_string(jref));

	if (contiaccorner.diff(&oldContiaccorner).size() != 0) insert(moditems, DpchEngAlign::CONTIACCORNER);

	ContIacTrace oldContiactrace(contiactrace);

	iprtrace->shrdat.rlockAccess("PnlWzskLiv2DView", "refreshAlign", "jref=" + to_string(jref));

	contiactrace.roiAx = iprtrace->shrdat.roiAx;
	contiactrace.roiAy = iprtrace->shrdat.roiAy;
	contiactrace.roiBx = iprtrace->shrdat.roiBx;
	contiactrace.roiBy = iprtrace->shrdat.roiBy;
	contiactrace.roiCx = iprtrace->shrdat.roiCx;
	contiactrace.roiCy = iprtrace->shrdat.roiCy;
	contiactrace.roiDx = iprtrace->shrdat.roiDx;
	contiactrace.roiDy = iprtrace->shrdat.roiDy;

	iprtrace->shrdat.runlockAccess("PnlWzskLiv2DView", "refreshAlign", "jref=" + to_string(jref));

	if (contiactrace.diff(&oldContiactrace).size() != 0) insert(moditems, DpchEngAlign::CONTIACTRACE);
};
// IP cust --- IEND

DpchEngWzsk* PnlWzskLiv2DView::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupPvm, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskLiv2DView::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool takenNotAvailable, fulfilled, run;
	xchg->getCsjobClaim(acqpreview, takenNotAvailable, fulfilled, run);

	ubigint refWzskMObject;
	refWzskMObject = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);

	// contiac
	ContIac oldContiac(contiac);

	//contiac.SldFcs; // future: srcfgpa shrdat
	//contiac.SldExt;

	contiac.SldLle = lround(100.0 * iprtrace->shrdat.pOnLeft);
	contiac.SldLri = lround(100.0 * iprtrace->shrdat.pOnRight);

	contiac.UpdLlo = iprtrace->shrdat.levelOn;
	contiac.UpdLuo = iprtrace->shrdat.levelOff;

	contiac.UpdLmd = iprtrace->shrdat.levelOn - iprtrace->shrdat.levelOff;

	contiac.ChkLro = iprtrace->stg.roiNotFull;

	contiac.UpdPnt = iprcorner->shrdat.NTarget;

	contiac.ChkPro = iprcorner->stg.roiNotFull;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;
	continf.TxtOaf = StubWzsk::getStubObjStd(dbswzsk, refWzskMObject, ixWzskVLocale);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;

	statshr.SldFcsAvail = xchg->stgwzskglobal.fpgaNotV4l2gpio;
	statshr.SldFcsActive = fulfilled;

	statshr.SldExtAvail = xchg->stgwzskglobal.fpgaNotV4l2gpio;
	statshr.SldExtActive = fulfilled;

	statshr.ButPlayActive = fulfilled && !run;
	statshr.ButStopActive = fulfilled && run;

	statshr.TxtOafAvail = (refWzskMObject != 0);
	statshr.ButStsActive = (refWzskMObject != 0) && run;

	statshr.UpdLloAvail = iprtrace->stg.v4l2RdNotDelta;
	statshr.UpdLuoAvail = iprtrace->stg.v4l2RdNotDelta;

	statshr.UpdLmdAvail = !iprtrace->stg.v4l2RdNotDelta;
	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskLiv2DView::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWALIGN) {
			handleDpchAppAlign(dbswzsk, (DpchAppAlign*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDO) {
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
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTSCLICK) {
					handleDpchAppDoButStsClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTTBCLICK) {
					handleDpchAppDoButTtbClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLTRCLICK) {
					handleDpchAppDoButLtrClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPICCLICK) {
					handleDpchAppDoButPicClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskLiv2DView::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLiv2DView::handleDpchAppAlign(
			DbsWzsk* dbswzsk
			, DpchAppAlign* dpchappalign
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppAlign --- IBEGIN
	set<uint> diffitems;
	set<uint> moditems;

	muteRefresh = true;

	if (dpchappalign->has(DpchAppAlign::CONTIACCORNER)) {
		ContIacCorner& c = dpchappalign->contiaccorner;

		diffitems = c.diff(&contiaccorner);

		if (!diffitems.empty()) iprcorner->setRoi(dbswzsk, c.roiAx, c.roiAy, c.roiBx, c.roiBy, c.roiCx, c.roiCy, c.roiDx, c.roiDy);

		add(moditems, DpchEngAlign::CONTIACCORNER);
	};

	if (dpchappalign->has(DpchAppAlign::CONTIACTRACE)) {
		ContIacTrace& c = dpchappalign->contiactrace;

		diffitems = c.diff(&contiactrace);

		if (!diffitems.empty()) iprtrace->setRoi(dbswzsk, c.roiAx, c.roiAy, c.roiBx, c.roiBy, c.roiCx, c.roiCy, c.roiDx, c.roiDy);

		add(moditems, DpchEngAlign::CONTIACTRACE);
	};

	if (hasAny(dpchappalign->mask, {DpchAppAlign::CONTIACCORNER,DpchAppAlign::CONTIACTRACE})) refreshAlign(moditems);

	muteRefresh = false;

	add(moditems, DpchAppAlign::JREF);
	*dpcheng = new DpchEngAlign(jref, &contiaccorner, &contiactrace, moditems);
	// IP handleDpchAppAlign --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	muteRefresh = true;

	if (has(diffitems, ContIac::NUMFPUPPVM)) {
		if (feedFPupPvm.getIxByNum(_contiac->numFPupPvm) != 0) contiac.numFPupPvm = _contiac->numFPupPvm;
		else contiac.numFPupPvm = 1;
	};

	if (has(diffitems, ContIac::SLDFCS) && statshr.SldFcsActive) contiac.SldFcs = _contiac->SldFcs;
	if (has(diffitems, ContIac::SLDEXT) && statshr.SldExtActive) contiac.SldExt = _contiac->SldExt;

	if (has(diffitems, ContIac::SLDLLE)) iprtrace->setPOn(dbswzsk, 0.01 * _contiac->SldLle, iprtrace->shrdat.pOnRight);
	if (has(diffitems, ContIac::SLDLRI)) iprtrace->setPOn(dbswzsk, iprtrace->shrdat.pOnLeft, 0.01 * _contiac->SldLri);

	if (has(diffitems, ContIac::CHKLRO)) iprtrace->setRoiNotFull(dbswzsk, _contiac->ChkLro);

	if (has(diffitems, ContIac::UPDLLO)) iprtrace->setLevel(dbswzsk, _contiac->UpdLlo, iprtrace->shrdat.levelOff);
	if (has(diffitems, ContIac::UPDLUO)) iprtrace->setLevel(dbswzsk, iprtrace->shrdat.levelOn, _contiac->UpdLuo);

	if (has(diffitems, ContIac::UPDLMD)) iprtrace->setLevel(dbswzsk, 255, 255 - _contiac->UpdLmd);

	if (has(diffitems, ContIac::UPDPNT)) iprcorner->setNTarget(dbswzsk, _contiac->UpdPnt);

	if (has(diffitems, ContIac::CHKPRO)) iprtrace->setRoiNotFull(dbswzsk, _contiac->ChkPro);

	muteRefresh = false;

	refresh(dbswzsk, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskLiv2DView::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLiv2DView::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLiv2DView::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, false, feedFPupPvm.getIxByNum(contiac.numFPupPvm)));
		else xchg->removeCsjobClaim(dbswzsk, acqpreview);

		muteRefresh = false;

		refreshWithDpchEng(dbswzsk, dpcheng);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButPlayClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButPlayClick --- IBEGIN
	if (statshr.ButPlayActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, true, feedFPupPvm.getIxByNum(contiac.numFPupPvm)));

		muteRefresh = false;

		refreshWithDpchEng(dbswzsk, dpcheng);
	};
	// IP handleDpchAppDoButPlayClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButStopClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButStopClick --- IBEGIN
	if (statshr.ButStopActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, false, feedFPupPvm.getIxByNum(contiac.numFPupPvm)));

		muteRefresh = false;

		refreshWithDpchEng(dbswzsk, dpcheng);
	};
	// IP handleDpchAppDoButStopClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButStsClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButStsClick --- IBEGIN
	if (statshr.ButStsActive) {
		// ...
	};
	// IP handleDpchAppDoButStsClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButTtbClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButTtbClick --- INSERT
};

void PnlWzskLiv2DView::handleDpchAppDoButLtrClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButLtrClick --- IBEGIN
	muteRefresh = true;

	xchg->addCsjobClaim(dbswzsk, iprtrace, new Claim(true, true));

	muteRefresh = false;
	// IP handleDpchAppDoButLtrClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButPicClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButPicClick --- IBEGIN
	muteRefresh = true;

	xchg->addCsjobClaim(dbswzsk, iprcorner, new Claim(true, true));

	muteRefresh = false;
	// IP handleDpchAppDoButPicClick --- IEND
};

void PnlWzskLiv2DView::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSGECHG) {
		call->abort = handleCallWzskSgeChg(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSTGCHG) {
		call->abort = handleCallWzskStgChg(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) && (call->jref == iprtrace->jref)) {
		call->abort = handleCallWzskShrdatChgFromIprtrace(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) && (call->jref == iprcorner->jref)) {
		call->abort = handleCallWzskShrdatChgFromIprcorner(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) {
		call->abort = handleCallWzskResultNew(dbswzsk, call->jref, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) && (call->jref == acqpreview->jref)) {
		call->abort = handleCallWzskClaimChgFromAcqpreview(dbswzsk);
	};
};

bool PnlWzskLiv2DView::handleCallWzskSgeChg(
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

bool PnlWzskLiv2DView::handleCallWzskStgChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskStgChg --- IBEGIN
	set<uint> moditems;

	if (!muteRefresh) {
		refreshAlign(moditems);

		if (!moditems.empty()) {
			add(moditems, DpchEngAlign::JREF);
			xchg->submitDpch(new DpchEngAlign(jref, &contiaccorner, &contiactrace, moditems));
		};
	};
	// IP handleCallWzskStgChg --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskShrdatChgFromIprtrace(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChgFromIprtrace --- IBEGIN
	set<uint> moditems;

	if (!muteRefresh) {
		refreshAlign(moditems);

		if (!moditems.empty()) {
			add(moditems, DpchEngAlign::JREF);
			xchg->submitDpch(new DpchEngAlign(jref, &contiaccorner, &contiactrace, moditems));
		};
	};
	// IP handleCallWzskShrdatChgFromIprtrace --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskShrdatChgFromIprcorner(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChgFromIprcorner --- IBEGIN
	set<uint> moditems;

	if (!muteRefresh) {
		refreshAlign(moditems);

		if (!moditems.empty()) {
			add(moditems, DpchEngAlign::JREF);
			xchg->submitDpch(new DpchEngAlign(jref, &contiaccorner, &contiactrace, moditems));
		};
	};
	// IP handleCallWzskShrdatChgFromIprcorner --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskResultNew(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNew --- IBEGIN
	set<uint> mask;

	bool takenNotAvailable, fulfilled, run;

	uint ixWzskVPvwmode;

	JobWzskAcqPreview::Shrdat::ResultitemGray* riGray = NULL;
	JobWzskAcqPreview::Shrdat::ResultitemRgb* riRgb = NULL;

	JobWzskIprTrace::Shrdat::ResultitemTrace* riTrace = NULL;

	JobWzskIprCorner::Shrdat::ResultitemCorner* riCorner = NULL;

	vector<utinyint> gray;

	vector<utinyint> red;
	vector<utinyint> green;
	vector<utinyint> blue;

	vector<int> xTraceL;
	vector<int> yTraceL;

	vector<int> xTraceR;
	vector<int> yTraceR;

	vector<int> xCorner;
	vector<int> yCorner;

	if (jrefTrig == acqpreview->jref) {
		xchg->getCsjobClaim(acqpreview, takenNotAvailable, fulfilled, run);

		ixWzskVPvwmode = VecWzskVPvwmode::getIx(srefInv);

		if ((ixWzskVPvwmode == feedFPupPvm.getIxByNum(contiac.numFPupPvm)) && run) {
			if (ixWzskVPvwmode == VecWzskVPvwmode::BINGRAY) riGray = (JobWzskAcqPreview::Shrdat::ResultitemGray*) acqpreview->shrdat.resultBingray[ixInv];
			else if (ixWzskVPvwmode == VecWzskVPvwmode::BINREDDOM) riGray = (JobWzskAcqPreview::Shrdat::ResultitemGray*) acqpreview->shrdat.resultBinreddom[ixInv];
			else if (ixWzskVPvwmode == VecWzskVPvwmode::BINRGB) riRgb = (JobWzskAcqPreview::Shrdat::ResultitemRgb*) acqpreview->shrdat.resultBinrgb[ixInv];
			else if (ixWzskVPvwmode == VecWzskVPvwmode::RAWGRAY) riGray = (JobWzskAcqPreview::Shrdat::ResultitemGray*) acqpreview->shrdat.resultRawgray[ixInv];
			else if (ixWzskVPvwmode == VecWzskVPvwmode::RAWRGB) riRgb = (JobWzskAcqPreview::Shrdat::ResultitemRgb*) acqpreview->shrdat.resultRawrgb[ixInv];

			if (riGray) {
				gray.resize(riGray->sizeBuf);
				
				memcpy(gray.data(), riGray->gr8, riGray->sizeBuf);

				insert(mask, DpchEngLive::GRAY);

			} else if (riRgb) {
				red.resize(riRgb->sizeBuf);
				green.resize(riRgb->sizeBuf);
				blue.resize(riRgb->sizeBuf);

				memcpy(red.data(), riRgb->r8, riRgb->sizeBuf);
				memcpy(green.data(), riRgb->g8, riRgb->sizeBuf);
				memcpy(blue.data(), riRgb->b8, riRgb->sizeBuf);

				insert(mask, DpchEngLive::RED);
				insert(mask, DpchEngLive::GREEN);
				insert(mask, DpchEngLive::BLUE);
			};
		};

	} else if (jrefTrig == iprtrace->jref) {
		xchg->getCsjobClaim(iprtrace, takenNotAvailable, fulfilled, run);

		//if (run) {
			riTrace = (JobWzskIprTrace::Shrdat::ResultitemTrace*) iprtrace->shrdat.result[ixInv];

			if (riTrace->Nleft > 0) {
				xTraceL.resize(riTrace->Nleft);
				yTraceL.resize(riTrace->Nleft);

				memcpy(xTraceL.data(), riTrace->x.data(), riTrace->Nleft * sizeof(int));
				memcpy(yTraceL.data(), riTrace->y.data(), riTrace->Nleft * sizeof(int));

				insert(mask, DpchEngLive::XTRACEL);
				insert(mask, DpchEngLive::YTRACEL);
			};

			if (riTrace->Nright > 0) {
				xTraceR.resize(riTrace->Nright);
				yTraceR.resize(riTrace->Nright);

				memcpy(xTraceR.data(), &(riTrace->x.data()[riTrace->Nleft]), riTrace->Nright * sizeof(int));
				memcpy(yTraceR.data(), &(riTrace->y.data()[riTrace->Nleft]), riTrace->Nright * sizeof(int));

				insert(mask, DpchEngLive::XTRACER);
				insert(mask, DpchEngLive::YTRACER);
			};
		//};

	} else if (jrefTrig == iprcorner->jref) {
		xchg->getCsjobClaim(iprcorner, takenNotAvailable, fulfilled, run);

		//if (run) {
			riCorner = (JobWzskIprCorner::Shrdat::ResultitemCorner*) iprcorner->shrdat.result[ixInv];

			xCorner = riCorner->x;
			yCorner = riCorner->y;

			insert(mask, DpchEngLive::XCORNER);
			insert(mask, DpchEngLive::YCORNER);
		//};
	};

	if (!mask.empty()) {
		insert(mask, DpchEngLive::JREF);
		xchg->submitDpch(new DpchEngLive(jref, gray, red, green, blue, xCorner, yCorner, xTraceL, yTraceL, xTraceR, yTraceR, mask));
	};
	// IP handleCallWzskResultNew --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskClaimChgFromAcqpreview(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskClaimChgFromAcqpreview --- IBEGIN
	set<uint> moditems;

	if (!muteRefresh) {
		refresh(dbswzsk, moditems);
		if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP handleCallWzskClaimChgFromAcqpreview --- IEND
	return retval;
};



