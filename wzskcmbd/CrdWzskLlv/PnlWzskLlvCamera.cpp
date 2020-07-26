/**
	* \file PnlWzskLlvCamera.cpp
	* job handler for job PnlWzskLlvCamera (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskLlvCamera.h"

#include "PnlWzskLlvCamera_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskLlvCamera
 ******************************************************************************/

PnlWzskLlvCamera::PnlWzskLlvCamera(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLLVCAMERA, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupMde.tag = "FeedFPupMde";
	VecWzskVPvwmode::fillFeed(ixWzskVLocale, feedFPupMde);

	acqpreview = NULL;

	// IP constructor.cust1 --- INSERT

	acqpreview = new JobWzskAcqPreview(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSGECHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::TRY);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLlvCamera::~PnlWzskLlvCamera() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskLlvCamera::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupMde, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskLlvCamera::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool takenNotAvailable, fulfilled, run;

	xchg->getCsjobClaim(acqpreview, takenNotAvailable, fulfilled, run);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;

	statshr.ButPlayActive = fulfilled && !run;
	statshr.ButStopActive = fulfilled && run;

	statshr.SldFcsAvail = xchg->stgwzskglobal.fpgaNotV4l2gpio;
	statshr.SldFcsActive = fulfilled;

	statshr.SldExtAvail = xchg->stgwzskglobal.fpgaNotV4l2gpio;
	statshr.SldExtActive = fulfilled;
	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzskLlvCamera::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVCAMERADATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVCAMERADO) {
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
				};

			};

		};
	};
};

void PnlWzskLlvCamera::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLlvCamera::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	if (has(diffitems, ContIac::NUMFPUPMDE)) {
		if (feedFPupMde.getIxByNum(_contiac->numFPupMde) != 0) contiac.numFPupMde = _contiac->numFPupMde;
		else contiac.numFPupMde = 1;
	};

	if (has(diffitems, ContIac::SLDFCS) && statshr.SldFcsActive) contiac.SldFcs = _contiac->SldFcs;
	if (has(diffitems, ContIac::SLDEXT) && statshr.SldExtActive) contiac.SldExt = _contiac->SldExt;

	refresh(dbswzsk, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskLlvCamera::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLlvCamera::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLlvCamera::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, false, feedFPupMde.getIxByNum(contiac.numFPupMde)));
		else xchg->removeCsjobClaim(dbswzsk, acqpreview);

		muteRefresh = false;

		refreshWithDpchEng(dbswzsk, dpcheng);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLlvCamera::handleDpchAppDoButPlayClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButPlayClick --- IBEGIN
	if (statshr.ButPlayActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, true, feedFPupMde.getIxByNum(contiac.numFPupMde)));

		muteRefresh = false;

		refreshWithDpchEng(dbswzsk, dpcheng);
	};
	// IP handleDpchAppDoButPlayClick --- IEND
};

void PnlWzskLlvCamera::handleDpchAppDoButStopClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButStopClick --- IBEGIN
	if (statshr.ButStopActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, false, feedFPupMde.getIxByNum(contiac.numFPupMde)));

		muteRefresh = false;

		refreshWithDpchEng(dbswzsk, dpcheng);
	};
	// IP handleDpchAppDoButStopClick --- IEND
};

void PnlWzskLlvCamera::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSGECHG) {
		call->abort = handleCallWzskSgeChg(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) {
		call->abort = handleCallWzskClaimChg(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) {
		call->abort = handleCallWzskResultNew(dbswzsk, call->jref, call->argInv.ix, call->argInv.sref);
	};
};

bool PnlWzskLlvCamera::handleCallWzskSgeChg(
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

bool PnlWzskLlvCamera::handleCallWzskClaimChg(
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

bool PnlWzskLlvCamera::handleCallWzskResultNew(
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

	vector<utinyint> gray;

	vector<utinyint> red;
	vector<utinyint> green;
	vector<utinyint> blue;

	if (jrefTrig == acqpreview->jref) {
		xchg->getCsjobClaim(acqpreview, takenNotAvailable, fulfilled, run);

		ixWzskVPvwmode = VecWzskVPvwmode::getIx(srefInv);

		if ((ixWzskVPvwmode == feedFPupMde.getIxByNum(contiac.numFPupMde)) && run) {
			if (ixWzskVPvwmode == VecWzskVPvwmode::BINGRAY) riGray = (JobWzskAcqPreview::Shrdat::ResultitemGray*) acqpreview->shrdat.resultBingray[ixInv];
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

	};

	if (!mask.empty()) {
		insert(mask, DpchEngLive::JREF);
		xchg->submitDpch(new DpchEngLive(jref, gray, red, green, blue, mask));
	};
	// IP handleCallWzskResultNew --- IEND
	return retval;
};



