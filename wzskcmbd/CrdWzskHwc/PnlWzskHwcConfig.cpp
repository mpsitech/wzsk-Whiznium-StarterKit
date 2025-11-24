/**
	* \file PnlWzskHwcConfig.cpp
	* job handler for job PnlWzskHwcConfig (implementation)
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

#include "PnlWzskHwcConfig.h"

#include "PnlWzskHwcConfig_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskHwcConfig
 ******************************************************************************/

PnlWzskHwcConfig::PnlWzskHwcConfig(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKHWCCONFIG, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFRbuMde.tag = "FeedFRbuMde";
	VecVMode::fillFeed(ixWzskVLocale, feedFRbuMde);

	acqhdr = NULL;
	acqpreview = NULL;
	prcwavelet = NULL;

	// IP constructor.cust1 --- INSERT

	acqhdr = new JobWzskAcqHdr(xchg, dbswzsk, jref, ixWzskVLocale);
	acqpreview = new JobWzskAcqPreview(xchg, dbswzsk, jref, ixWzskVLocale);
	prcwavelet = new JobWzskPrcWavelet(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- IBEGIN
	scale = 0;

	numSshot = 0;
	refFilSshot = 0;

	ixRiHdr = 0;
	ixRiPvw = 0;

	updateScale(dbswzsk);
	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSGECHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, acqpreview->jref, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, acqhdr->jref, false, Arg(), VecVSge::CAPTURE, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskHwcConfig::~PnlWzskHwcConfig() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void PnlWzskHwcConfig::updateScale(
			DbsWzsk* dbswzsk
		) {
	set<uint> moditems;

	unsigned int scale_old = scale;

	scale = 690 / ((JobWzskAcqPreview::Shrdat::Resultitem*) (acqpreview->shrdat.resultPvw[ixRiPvw]))->w;

	if ((scale_old != 0) && (scale != scale_old)) {
		refresh(dbswzsk, moditems);
		if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};


void PnlWzskHwcConfig::writeRGBE(
			const string& fullpath
		) {
	fstream outfile;

	JobWzskAcqHdr::Shrdat::Resultitem* ri = (JobWzskAcqHdr::Shrdat::Resultitem*) JobWzskAcqHdr::shrdat.resultHdr[ixRiHdr];

	outfile.open(fullpath.c_str(), ios::out | ios::binary);

	outfile << "#?RGBE\n";
	outfile << "FORMAT=32-bit_rle_rgbe\n\n";
	outfile << "-Y " << ri->h << " +X " << ri->w << "\n";

	outfile.write((const char*) (ri->buf), ri->lenBuf);

	outfile.close();
};
// IP cust --- IEND

DpchEngWzsk* PnlWzskHwcConfig::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFRbuMde, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskHwcConfig::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool hdrTakenNotAvailable, hdrFulfilled, hdrRun;
	bool pvwTakenNotAvailable, pvwFulfilled, pvwRun;

	xchg->getCsjobClaim(acqhdr, hdrTakenNotAvailable, hdrFulfilled, hdrRun);
	xchg->getCsjobClaim(acqpreview, pvwTakenNotAvailable, pvwFulfilled, pvwRun);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = hdrFulfilled && pvwFulfilled;
	continf.TxtPfi = StubWzsk::getStubFilStd(dbswzsk, refFilSshot);
	continf.TxtSte = acqhdr->getSquawk(dbswzsk);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !hdrTakenNotAvailable || hdrFulfilled;

	statshr.CusImgHeight = scale * ((JobWzskAcqPreview::Shrdat::Resultitem*) (acqpreview->shrdat.resultPvw[ixRiPvw]))->h;

	statshr.ButPlayActive = pvwFulfilled & !pvwRun;
	statshr.ButStopActive = pvwFulfilled & pvwRun;

	statshr.ButSnapActive = hdrRun & (ixVSge == VecVSge::IDLE);

	statshr.ButPfiViewActive = (refFilSshot != 0);

	statshr.UpdNfrActive = !hdrRun;
	statshr.SldFstActive = !hdrRun;
	statshr.SldFspActive = !hdrRun;

	statshr.ButStaActive = hdrFulfilled & !hdrRun;
	statshr.ButStoActive = hdrFulfilled & hdrRun;

	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskHwcConfig::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKHWCCONFIGALIGN) {
			handleDpchAppAlign(dbswzsk, (DpchAppAlign*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKHWCCONFIGDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKHWCCONFIGDO) {
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
				} else if (dpchappdo->ixVDo == VecVDo::BUTSNAPCLICK) {
					handleDpchAppDoButSnapClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPFIVIEWCLICK) {
					handleDpchAppDoButPfiViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTACLICK) {
					handleDpchAppDoButStaClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTOCLICK) {
					handleDpchAppDoButStoClick(dbswzsk, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::STOIDLE) handleTimerInSgeStoidle(dbswzsk, req->sref);
	};
};

void PnlWzskHwcConfig::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskHwcConfig::handleDpchAppAlign(
			DbsWzsk* dbswzsk
			, DpchAppAlign* dpchappalign
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppAlign --- INSERT
};

void PnlWzskHwcConfig::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	muteRefresh = true;

	if (has(diffitems, ContIac::NUMFRBUMDE)) {
		if (feedFRbuMde.getIxByNum(_contiac->numFRbuMde) != 0) contiac.numFRbuMde = _contiac->numFRbuMde;
		else contiac.numFRbuMde = 1;

		if (statshr.ButStopActive) {
			// allow live mode changes
			xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, true, feedFRbuMde.getIxByNum(contiac.numFRbuMde) == VecVMode::RGB, 0));
		};
	};

	if (has(diffitems, ContIac::UPDNFR) && statshr.UpdNfrActive) contiac.UpdNfr = _contiac->UpdNfr;
	if (has(diffitems, ContIac::SLDFST) && statshr.SldFstActive) contiac.SldFst = _contiac->SldFst;
	if (has(diffitems, ContIac::SLDFSP) && statshr.SldFspActive) contiac.SldFsp = _contiac->SldFsp;

	refresh(dbswzsk, moditems, true);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskHwcConfig::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskHwcConfig::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskHwcConfig::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	bool b;

	bool hdrFulfilled = false;
	bool pvwFulfilled = false;

	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) {
			xchg->addCsjobClaim(dbswzsk, acqhdr, new Claim(true, false));
			xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, false, feedFRbuMde.getIxByNum(contiac.numFRbuMde) == VecVMode::RGB, 0));

			xchg->getCsjobClaim(acqhdr, b, hdrFulfilled);
			xchg->getCsjobClaim(acqpreview, b, pvwFulfilled);
		};

		if (!hdrFulfilled || !pvwFulfilled) {
			xchg->removeCsjobClaim(dbswzsk, acqhdr);
			xchg->removeCsjobClaim(dbswzsk, acqpreview);
		};

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskHwcConfig::handleDpchAppDoButPlayClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButPlayClick --- IBEGIN
	if (statshr.ButPlayActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, true, feedFRbuMde.getIxByNum(contiac.numFRbuMde) == VecVMode::RGB, 0));

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButPlayClick --- IEND
};

void PnlWzskHwcConfig::handleDpchAppDoButStopClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButStopClick --- IBEGIN
	if (statshr.ButStopActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, false, feedFRbuMde.getIxByNum(contiac.numFRbuMde) == VecVMode::RGB, 0));

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButStopClick --- IEND
};

void PnlWzskHwcConfig::handleDpchAppDoButSnapClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSnapClick --- IBEGIN
	set<uint> moditems;

	if (statshr.ButSnapActive) {
		muteRefresh = true;

		changeStage(dbswzsk, VecVSge::CAPTURE);

		refresh(dbswzsk, moditems, true);
		*dpcheng = getNewDpchEng(moditems);
	};
	// IP handleDpchAppDoButSnapClick --- IEND
};

void PnlWzskHwcConfig::handleDpchAppDoButPfiViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButPfiViewClick --- IBEGIN
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPfiViewActive) {
		if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref)) {
			sref = "CrdWzskFil";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, sref, refFilSshot, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
	// IP handleDpchAppDoButPfiViewClick --- IEND
};

void PnlWzskHwcConfig::handleDpchAppDoButStaClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButStaClick --- IBEGIN
	if (statshr.ButStaActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqhdr, new Claim(true, true));

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButStaClick --- IEND
};

void PnlWzskHwcConfig::handleDpchAppDoButStoClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButStoClick --- IBEGIN
	if (statshr.ButStoActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqhdr, new Claim(true, false));

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButStoClick --- IEND
};

void PnlWzskHwcConfig::handleTimerInSgeStoidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void PnlWzskHwcConfig::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSGECHG) {
		call->abort = handleCallWzskSgeChg(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && (call->jref == acqpreview->jref)) {
		call->abort = handleCallWzskResultNewFromAcqpreview(dbswzsk, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && (call->jref == acqhdr->jref) && (ixVSge == VecVSge::CAPTURE)) {
		call->abort = handleCallWzskResultNewFromAcqhdrInSgeCapture(dbswzsk, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	};
};

bool PnlWzskHwcConfig::handleCallWzskSgeChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskSgeChg --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskSgeChg --- IEND
	return retval;
};

bool PnlWzskHwcConfig::handleCallWzskResultNewFromAcqpreview(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromAcqpreview --- IBEGIN

	JobWzskAcqPreview::Shrdat::Resultitem* riPvw = NULL;

	vector<utinyint> gray;
	vector<utinyint> rgb;

	if (ixInv < acqpreview->shrdat.resultPvw.size()) {
		ixRiPvw = ixInv;
		riPvw = (JobWzskAcqPreview::Shrdat::Resultitem*) acqpreview->shrdat.resultPvw[ixRiPvw];

		cout << "PnlWzskHwcConfig new preview frame with ixRiPvw = " << ixRiPvw << endl;

		updateScale(dbswzsk);

		if (!(riPvw->rgbNotGray)) {
			gray.resize(riPvw->lenBuf);
			memcpy(gray.data(), riPvw->buf, riPvw->lenBuf);
			xchg->submitDpch(new DpchEngLive(jref, gray, rgb, {DpchEngLive::JREF, DpchEngLive::GRAY}));

		} else {
			rgb.resize(riPvw->lenBuf);
			memcpy(rgb.data(), riPvw->buf, riPvw->lenBuf);
			xchg->submitDpch(new DpchEngLive(jref, gray, rgb, {DpchEngLive::JREF, DpchEngLive::RGB}));
		};
	};

	// IP handleCallWzskResultNewFromAcqpreview --- IEND
	return retval;
};

bool PnlWzskHwcConfig::handleCallWzskResultNewFromAcqhdrInSgeCapture(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromAcqhdrInSgeCapture --- IBEGIN
	acqhdr->shrdat.resultHdr.lock(jref, ixInv);
	ixRiHdr = ixInv;

	changeStage(dbswzsk, VecVSge::STOIDLE);
	// IP handleCallWzskResultNewFromAcqhdrInSgeCapture --- IEND
	return retval;
};

void PnlWzskHwcConfig::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
			, DpchEngWzsk** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::CAPTURE: leaveSgeCapture(dbswzsk); break;
				case VecVSge::STOIDLE: leaveSgeStoidle(dbswzsk); break;
				case VecVSge::STORE: leaveSgeStore(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswzsk, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::CAPTURE: _ixVSge = enterSgeCapture(dbswzsk, reenter); break;
			case VecVSge::STOIDLE: _ixVSge = enterSgeStoidle(dbswzsk, reenter); break;
			case VecVSge::STORE: _ixVSge = enterSgeStore(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string PnlWzskHwcConfig::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CAPTURE) || (ixVSge == VecVSge::STORE) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::CAPTURE) retval = "capturing HDR frame";
			else if (ixVSge == VecVSge::STORE) retval = "storing data to RGBE file";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint PnlWzskHwcConfig::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void PnlWzskHwcConfig::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint PnlWzskHwcConfig::enterSgeCapture(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::CAPTURE;

	// IP enterSgeCapture --- INSERT

	return retval;
};

void PnlWzskHwcConfig::leaveSgeCapture(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeCapture --- INSERT
};

uint PnlWzskHwcConfig::enterSgeStoidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::STOIDLE;
	nextIxVSgeSuccess = VecVSge::STORE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeStoidle --- INSERT

	return retval;
};

void PnlWzskHwcConfig::leaveSgeStoidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeStoidle --- INSERT
};

uint PnlWzskHwcConfig::enterSgeStore(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::STORE;

	// IP enterSgeStore --- IBEGIN
	fstream outfile;

	string path = xchg->tmppath + "/" + Tmp::newfile(xchg->tmppath, "");

	outfile.open(path.c_str(), ios::out);
	outfile.close();

	refFilSshot = Acv::addfile(dbswzsk, xchg->acvpath, path, 0, 0, VecWzskVMFileRefTbl::VOID, 0, "sshot", "hdrframe_" + to_string(numSshot++) + ".hdre", "hdre", "");

	path = xchg->acvpath + "/" + Acv::getfile(dbswzsk, refFilSshot);
	writeRGBE(path);

	acqhdr->shrdat.resultHdr.unlock(jref, ixRiHdr);

	retval = VecVSge::IDLE;
	// IP enterSgeStore --- IEND

	return retval;
};

void PnlWzskHwcConfig::leaveSgeStore(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeStore --- INSERT
};
