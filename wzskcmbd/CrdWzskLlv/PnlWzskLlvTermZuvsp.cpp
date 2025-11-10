/**
	* \file PnlWzskLlvTermZuvsp.cpp
	* job handler for job PnlWzskLlvTermZuvsp (implementation)
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

#include "PnlWzskLlvTermZuvsp.h"

#include "PnlWzskLlvTermZuvsp_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- BEGIN
using namespace Dbecore;
// IP ns.cust --- END

/******************************************************************************
 class PnlWzskLlvTermZuvsp
 ******************************************************************************/

PnlWzskLlvTermZuvsp::PnlWzskLlvTermZuvsp(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLLVTERMZUVSP, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupCmd.tag = "FeedFPupCmd";

	srczuvsp = NULL;

	// IP constructor.cust1 --- INSERT

	srczuvsp = new JobWzskSrcZuvsp(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- BEGIN
	UntWskdZuvsp& hw = srczuvsp->shrdat.hw;

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
	// IP constructor.cust2 --- END

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::SPEC, srczuvsp->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLlvTermZuvsp::~PnlWzskLlvTermZuvsp() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskLlvTermZuvsp::getNewDpchEng(
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

void PnlWzskLlvTermZuvsp::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	bool takenNotAvailable, fulfilled;

	xchg->getCsjobClaim(srczuvsp, takenNotAvailable, fulfilled);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;
	continf.TxtCst = srczuvsp->getSquawk(dbswzsk);

	if (hist.size() > 50) continf.TxtDatLog = "(" + to_string(hist.size() - 50) + " previous log entries);";
	else continf.TxtDatLog = "";
	for (unsigned int i = (hist.size() > 50) ? hist.size() - 50 : 0; i < hist.size(); i++) continf.TxtDatLog += hist[i] + ";";

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;
	statshr.ButSmtActive = continf.ButClaimOn && (contiac.TxfCsq != "");

	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskLlvTermZuvsp::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMZUVSPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMZUVSPDO) {
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

void PnlWzskLlvTermZuvsp::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLlvTermZuvsp::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- BEGIN
	if (has(diffitems, ContIac::NUMFPUPCMD)) {
		if (feedFPupCmd.getSrefByNum(_contiac->numFPupCmd) != "") contiac.numFPupCmd = _contiac->numFPupCmd;
		else contiac.numFPupCmd = 0;
	};

	if (has(diffitems, ContIac::TXFCSQ)) contiac.TxfCsq = _contiac->TxfCsq;

	refresh(dbswzsk, moditems);
	// IP handleDpchAppDataContiac --- END
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskLlvTermZuvsp::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLlvTermZuvsp::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLlvTermZuvsp::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- BEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, srczuvsp, new Claim(true, true));
		else xchg->removeCsjobClaim(dbswzsk, srczuvsp);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- END
};

void PnlWzskLlvTermZuvsp::handleDpchAppDoButApdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButApdClick --- BEGIN
	UntWskdZuvsp& hw = srczuvsp->shrdat.hw;

	set<uint> moditems;

	uint ix = feedFPupCmd.getIxByNum(contiac.numFPupCmd);

	if (ix != 0) {
		if (contiac.TxfCsq != "") if (contiac.TxfCsq[contiac.TxfCsq.length() - 1] != ';') contiac.TxfCsq += ";";
		contiac.TxfCsq += hw.getCmdTemplate(ix >> 8, ix & 0xFF, false);
		insert(moditems, DpchEngData::CONTIAC);

		refresh(dbswzsk, moditems);
		*dpcheng = getNewDpchEng(moditems);
	};
	// IP handleDpchAppDoButApdClick --- END
};

void PnlWzskLlvTermZuvsp::handleDpchAppDoButSmtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSmtClick --- BEGIN
	set<uint> moditems;

	UntWskdZuvsp& hw = srczuvsp->shrdat.hw;

	vector<string> ss;
	string s;

	Cmd* cmd = NULL;
	bool truncated;

	bool rxtxdump_old, histNotDump_old;

	size_t ptr;

	if (statshr.ButSmtActive) {
		StrMod::stringToVector(contiac.TxfCsq, ss);

		contiac.TxfCsq = "";
		insert(moditems, DpchEngData::CONTIAC);

		rxtxdump_old = hw.rxtxdump;
		hw.rxtxdump = true;

		histNotDump_old = hw.histNotDump;
		hw.histNotDump = true;

		for (unsigned int i = 0; i < ss.size(); i++) {
			hw.parseCmd(ss[i], cmd);

			if (cmd) {
				s = cmd->getParsText(false, true, &truncated);
				hist.push_back(hw.getCmdsref(256 * cmd->tixVController + cmd->tixVCommand) + "(" + s + ")");

				hw.clearHist();
				hw.runCmd(cmd);

				ptr = hist.size();
				hw.copyHist(hist, true);
				for (; ptr < hist.size(); ptr++) hist[ptr] = "	" + hist[ptr];

				s = cmd->getParsText(true, true, &truncated);
				hist.push_back(" = (" + s + ")");

				delete cmd;
				cmd = NULL;
			};
		};

		hw.rxtxdump = rxtxdump_old;
		hw.histNotDump = histNotDump_old;

		refresh(dbswzsk, moditems);
		*dpcheng = getNewDpchEng(moditems);
	};
	// IP handleDpchAppDoButSmtClick --- END
};

void PnlWzskLlvTermZuvsp::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) && (call->jref == srczuvsp->jref)) {
		call->abort = handleCallWzskClaimChgFromSrczuvsp(dbswzsk);
	};
};

bool PnlWzskLlvTermZuvsp::handleCallWzskClaimChgFromSrczuvsp(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskClaimChgFromSrczuvsp --- BEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskClaimChgFromSrczuvsp --- END
	return retval;
};
