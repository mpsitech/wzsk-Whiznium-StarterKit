/**
	* \file PnlWzskLlvTermIcicle.cpp
	* job handler for job PnlWzskLlvTermIcicle (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskLlvTermIcicle.h"

#include "PnlWzskLlvTermIcicle_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

/******************************************************************************
 class PnlWzskLlvTermIcicle
 ******************************************************************************/

PnlWzskLlvTermIcicle::PnlWzskLlvTermIcicle(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLLVTERMICICLE, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupCmd.tag = "FeedFPupCmd";

	srcicicle = NULL;

	// IP constructor.cust1 --- INSERT

	srcicicle = new JobWzskSrcIcicle(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- IBEGIN
	UntWskdIccl& hw = srcicicle->shrdat.hw;

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

	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::SPEC, srcicicle->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLlvTermIcicle::~PnlWzskLlvTermIcicle() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskLlvTermIcicle::getNewDpchEng(
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

void PnlWzskLlvTermIcicle::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool takenNotAvailable, fulfilled;

	xchg->getCsjobClaim(srcicicle, takenNotAvailable, fulfilled);

	// continf 
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;
	continf.TxtCst = srcicicle->getSquawk(dbswzsk);

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

void PnlWzskLlvTermIcicle::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMICICLEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMICICLEDO) {
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

void PnlWzskLlvTermIcicle::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLlvTermIcicle::handleDpchAppDataContiac(
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

void PnlWzskLlvTermIcicle::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLlvTermIcicle::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLlvTermIcicle::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, srcicicle, new JobWzskSrcIcicle::Claim(true, true, false, false, false, false));
		else xchg->removeCsjobClaim(dbswzsk, srcicicle);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLlvTermIcicle::handleDpchAppDoButApdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButApdClick --- IBEGIN
	UntWskdIccl& hw = srcicicle->shrdat.hw;

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

void PnlWzskLlvTermIcicle::handleDpchAppDoButSmtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSmtClick --- IBEGIN
	set<uint> moditems;

	UntWskdIccl& hw = srcicicle->shrdat.hw;

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

void PnlWzskLlvTermIcicle::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) && (call->jref == srcicicle->jref)) {
		call->abort = handleCallWzskClaimChgFromSrcicicle(dbswzsk);
	};
};

bool PnlWzskLlvTermIcicle::handleCallWzskClaimChgFromSrcicicle(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskClaimChgFromSrcicicle --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskClaimChgFromSrcicicle --- IEND
	return retval;
};
