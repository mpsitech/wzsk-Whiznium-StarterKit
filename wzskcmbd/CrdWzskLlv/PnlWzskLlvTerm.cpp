/**
	* \file PnlWzskLlvTerm.cpp
	* job handler for job PnlWzskLlvTerm (implementation)
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

#include "PnlWzskLlvTerm.h"

#include "PnlWzskLlvTerm_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

/******************************************************************************
 class PnlWzskLlvTerm
 ******************************************************************************/

PnlWzskLlvTerm::PnlWzskLlvTerm(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLLVTERM, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupCmd.tag = "FeedFPupCmd";

	srcfpga = NULL;

	// IP constructor.cust1 --- INSERT

	srcfpga = new JobWzskSrcFpga(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- IBEGIN
	UntWskdArty& hw = srcfpga->shrdat.hw;

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

	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::SPEC, srcfpga->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLlvTerm::~PnlWzskLlvTerm() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void PnlWzskLlvTerm::parseCmd(
			UntWskd& unt
			, string s
			, Cmd*& cmd
		) {
	string cmdsref;
	uint cmdix;

	utinyint tixVController;
	utinyint tixVCommand;

	if (cmd) delete cmd;
	cmd = NULL;

	size_t ptr;

	if (s.length() == 0) return;
	if (s[s.length()-1] != ')') return;
	s = s.substr(0, s.length()-1);
	ptr = s.find('(');
	if (ptr == string::npos) return;

	cmdix = getCmdix(unt, s.substr(0, ptr));
	tixVController = (cmdix >> 8);
	tixVCommand = (cmdix & 0xFF);
	s = s.substr(ptr+1);

	cmd = unt.getNewCmd(tixVController, tixVCommand);
	if (cmd) cmd->parlistToParsInv(s);
};

uint PnlWzskLlvTerm::getCmdix(
			UntWskd& unt
			, const string& cmdsref
		) {
	utinyint tixVController = 0;
	utinyint tixVCommand = 0;

	size_t ptr;

	ptr = cmdsref.find('.');

	if (ptr != string::npos) {
		tixVController = unt.getTixVControllerBySref(cmdsref.substr(0, ptr));
		tixVCommand = unt.getTixVCommandBySref(tixVController, cmdsref.substr(ptr+1));

		return((tixVController << 8) + tixVCommand);

	} else return 0;
};

string PnlWzskLlvTerm::getCmdsref(
			UntWskd& unt
			, const uint cmdix
		) {
	string cmdsref;

	utinyint tixVController = (cmdix >> 8);
	utinyint tixVCommand = (cmdix & 0xFF);

	cmdsref = unt.getSrefByTixVController(tixVController);
	cmdsref += ".";
	cmdsref += unt.getSrefByTixVCommand(tixVController, tixVCommand);

	return cmdsref;
};
// IP cust --- IEND

DpchEngWzsk* PnlWzskLlvTerm::getNewDpchEng(
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

void PnlWzskLlvTerm::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool takenNotAvailable, fulfilled;

	xchg->getCsjobClaim(srcfpga, takenNotAvailable, fulfilled);

	// continf 
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;
	continf.TxtCst = srcfpga->getSquawk(dbswzsk);

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

void PnlWzskLlvTerm::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMDO) {
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

void PnlWzskLlvTerm::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLlvTerm::handleDpchAppDataContiac(
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

void PnlWzskLlvTerm::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLlvTerm::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLlvTerm::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, srcfpga, new JobWzskSrcFpga::Claim(true, true, false, false, false, false));
		else xchg->removeCsjobClaim(dbswzsk, srcfpga);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLlvTerm::handleDpchAppDoButApdClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButApdClick --- IBEGIN
	UntWskdArty& hw = srcfpga->shrdat.hw;

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

void PnlWzskLlvTerm::handleDpchAppDoButSmtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButSmtClick --- IBEGIN
	set<uint> moditems;

	UntWskdArty& hw = srcfpga->shrdat.hw;

	vector<string> ss;
	string s;

	Cmd* cmd = NULL;
	bool truncated;

	if (statshr.ButSmtActive) {
		StrMod::stringToVector(contiac.TxfCsq, ss);

		contiac.TxfCsq = "";
		insert(moditems, DpchEngData::CONTIAC);

		for (unsigned int i = 0; i < ss.size(); i++) {
			parseCmd(hw, ss[i], cmd);

			if (cmd) {
				hw.hist.clear();

				s = cmd->getInvText(true, &truncated);
				hist.push_back(getCmdsref(hw, 256 * cmd->tixVController + cmd->tixVCommand) + "(" + s + ")");

				hw.runCmd(cmd);

				for (unsigned int j = 0; j < hw.hist.size(); j++) hist.push_back("\t" + hw.hist[j]);

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

void PnlWzskLlvTerm::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) && (call->jref == srcfpga->jref)) {
		call->abort = handleCallWzskClaimChgFromSrcfpga(dbswzsk);
	};
};

bool PnlWzskLlvTerm::handleCallWzskClaimChgFromSrcfpga(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskClaimChgFromSrcfpga --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskClaimChgFromSrcfpga --- IEND
	return retval;
};
