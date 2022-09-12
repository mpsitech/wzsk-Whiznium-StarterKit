/**
	* \file PnlWzskLlvTermPwmonusb.cpp
	* job handler for job PnlWzskLlvTermPwmonusb (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Jun 2022
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskLlvTermPwmonusb.h"

#include "PnlWzskLlvTermPwmonusb_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

/******************************************************************************
 class PnlWzskLlvTermPwmonusb
 ******************************************************************************/

PnlWzskLlvTermPwmonusb::PnlWzskLlvTermPwmonusb(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLLVTERMPWMONUSB, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupCmd.tag = "FeedFPupCmd";

	srcpwmonusb = NULL;

	// IP constructor.cust1 --- INSERT

	srcpwmonusb = new JobWzskSrcPwmonusb(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- IBEGIN
	UntPmndUbdk& hw = srcpwmonusb->shrdat.hw;

	Feed feedFCtr;
	Feed feedFCmd;
	Feeditem* fi = NULL;
	Feeditem* fi2 = NULL;

	// establish command set
	hw.fillFeedFController(feedFCtr);

	for (unsigned int i = 0; i < feedFCtr.size(); i++) {
		fi = feedFCtr.getByNum(i + 1);

		hw.fillFeedFCommand(fi->ix, feedFCmd);
		
		for (unsigned int j = 0; j < feedFCmd.size(); j++) {
			fi2 = feedFCmd.getByNum(j + 1);
			feedFPupCmd.appendIxSrefTitles(256 * fi->ix + fi2->ix, fi->sref + "." + fi2->sref, fi->sref + "." + fi2->sref);
		};
	};
	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::SPEC, srcpwmonusb->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLlvTermPwmonusb::~PnlWzskLlvTermPwmonusb() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskLlvTermPwmonusb::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupCmd, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskLlvTermPwmonusb::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool takenNotAvailable, fulfilled;

	xchg->getCsjobClaim(srcpwmonusb, takenNotAvailable, fulfilled);

	// continf 
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;
	continf.TxtCst = srcpwmonusb->getSquawk(dbswzsk);

	if (hist.size() > 50) continf.TxtDatLog = "(" + to_string(hist.size() - 50) + " previous log entries);";
	else continf.TxtDatLog = "";
	for (unsigned int i = (hist.size() > 50) ? hist.size() - 50 : 0; i < hist.size(); i++) continf.TxtDatLog += hist[i] + ";";

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;
	statshr.ButSmtActive = continf.ButClaimOn && (contiac.TxfCsq != "");
	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskLlvTermPwmonusb::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMPWMONUSBDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMPWMONUSBDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLAIMCLICK) {
					handleDpchAppDoButClaimClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTAPDCLICK) {
					handleDpchAppDoButApdClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSMTCLICK) {
					handleDpchAppDoButSmtClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskLlvTermPwmonusb::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLlvTermPwmonusb::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	if (has(diffitems, ContIac::NUMFPUPCMD)) {
		if (feedFPupCmd.getSrefByNum(_contiac->numFPupCmd) != "") contiac.numFPupCmd = _contiac->numFPupCmd;
		else contiac.numFPupCmd = 0;
	};

	if (has(diffitems, ContIac::TXFCSQ)) contiac.TxfCsq = _contiac->TxfCsq;

	refresh(dbswzsk, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskLlvTermPwmonusb::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLlvTermPwmonusb::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLlvTermPwmonusb::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, srcpwmonusb, new Claim());
		else xchg->removeCsjobClaim(dbswzsk, srcpwmonusb);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLlvTermPwmonusb::handleDpchAppDoButApdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButApdClick --- IBEGIN
	UntPmndUbdk& hw = srcpwmonusb->shrdat.hw;

	set<uint> moditems;

	uint ix = feedFPupCmd.getIxByNum(contiac.numFPupCmd);
	
	if (ix != 0) {
		if (contiac.TxfCsq != "") if (contiac.TxfCsq[contiac.TxfCsq.length() - 1] != ';') contiac.TxfCsq += ";";
		contiac.TxfCsq += hw.getCmdTemplate(ix >> 8, ix & 0xFF, false);
		insert(moditems, DpchEngData::CONTIAC);

		refresh(dbswzsk, moditems);
		*dpcheng = getNewDpchEng(moditems);
	};
	// IP handleDpchAppDoButApdClick --- IEND
};

void PnlWzskLlvTermPwmonusb::handleDpchAppDoButSmtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSmtClick --- IBEGIN
	set<uint> moditems;

	UntPmndUbdk& hw = srcpwmonusb->shrdat.hw;

	vector<string> ss;
	string s;

	Cmd* cmd = NULL;
	bool truncated;

	size_t ptr;

	if (statshr.ButSmtActive) {
		StrMod::stringToVector(contiac.TxfCsq, ss);

		contiac.TxfCsq = "";
		insert(moditems, DpchEngData::CONTIAC);

		for (unsigned int i = 0; i < ss.size(); i++) {
			hw.parseCmd(ss[i], cmd);

			if (cmd) {
				s = cmd->getInvText(true, &truncated);
				hist.push_back(hw.getCmdsref(256 * cmd->tixVController + cmd->tixVCommand) + "(" + s + ")");

				hw.clearHist();
				hw.runCmd(cmd);

				ptr = hist.size();
				hw.copyHist(hist, true);
				for (; ptr < hist.size(); ptr++) hist[ptr] = "\t" + hist[ptr];

				s = cmd->getRetText(true, &truncated);
				hist.push_back(" = (" + s + ")");

				delete cmd;
				cmd = NULL;
			};
		};

		refresh(dbswzsk, moditems);
		*dpcheng = getNewDpchEng(moditems);
	};
	// IP handleDpchAppDoButSmtClick --- IEND
};

void PnlWzskLlvTermPwmonusb::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) && (call->jref == srcpwmonusb->jref)) {
		call->abort = handleCallWzskClaimChgFromSrcpwmonusb(dbswzsk);
	};
};

bool PnlWzskLlvTermPwmonusb::handleCallWzskClaimChgFromSrcpwmonusb(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskClaimChgFromSrcpwmonusb --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskClaimChgFromSrcpwmonusb --- IEND
	return retval;
};
