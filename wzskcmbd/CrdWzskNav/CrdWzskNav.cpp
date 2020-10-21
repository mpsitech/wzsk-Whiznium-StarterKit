/**
	* \file CrdWzskNav.cpp
	* job handler for job CrdWzskNav (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "CrdWzskNav.h"

#include "CrdWzskNav_blks.cpp"
#include "CrdWzskNav_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzskNav
 ******************************************************************************/

CrdWzskNav::CrdWzskNav(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::CRDWZSKNAV, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlgalery = NULL;
	pnlop = NULL;
	pnladmin = NULL;
	pnlpre = NULL;
	pnlheadbar = NULL;
	dlgloaini = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	pnlgalery = new PnlWzskNavGalery(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlop = new PnlWzskNavOp(xchg, dbswzsk, jref, ixWzskVLocale);
	pnladmin = new PnlWzskNavAdmin(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlpre = new PnlWzskNavPre(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlheadbar = new PnlWzskNavHeadbar(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefPre = pnlpre->jref;
	statshr.jrefAdmin = pnladmin->jref;
	statshr.jrefOp = pnlop->jref;
	statshr.jrefGalery = pnlgalery->jref;

	changeStage(dbswzsk, VecVSge::IDLE);

	xchg->addClstn(VecWzskVCall::CALLWZSKDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWzskNav::~CrdWzskNav() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* CrdWzskNav::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdWzskNav::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	string s;
	vector<string> ss;

	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzskNav/" + VecWzskVLocale::getSref(ixWzskVLocale);

	s = StubWzsk::getStubSesMenu(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKSESS, jref), ixWzskVLocale, Stub::VecVNonetype::DASH);
	StrMod::stringToVector(s, ss);

	if (ss.size() == 3) {
		continf.MtxSesSes1 = ss[0];
		continf.MtxSesSes2 = ss[1];
		continf.MtxSesSes3 = ss[2];
	};

	// statshr
	statshr.pnlpreAvail = evalPnlpreAvail(dbswzsk);
	statshr.pnladminAvail = evalPnladminAvail(dbswzsk);
	statshr.pnlopAvail = evalPnlopAvail(dbswzsk);
	statshr.pnlgaleryAvail = evalPnlgaleryAvail(dbswzsk);
	statshr.MitSesSpsAvail = evalMitSesSpsAvail(dbswzsk);
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswzsk);
	statshr.MitCrdUsgAvail = evalMitCrdUsgAvail(dbswzsk);
	statshr.MitCrdUsrAvail = evalMitCrdUsrAvail(dbswzsk);
	statshr.MitCrdPrsAvail = evalMitCrdPrsAvail(dbswzsk);
	statshr.MitCrdScfAvail = evalMitCrdScfAvail(dbswzsk);
	statshr.MspCrd2Avail = evalMspCrd2Avail(dbswzsk);
	statshr.MitCrdLlvAvail = evalMitCrdLlvAvail(dbswzsk);
	statshr.MitCrdLivAvail = evalMitCrdLivAvail(dbswzsk);
	statshr.MspCrd3Avail = evalMspCrd3Avail(dbswzsk);
	statshr.MitCrdOgrAvail = evalMitCrdOgrAvail(dbswzsk);
	statshr.MitCrdObjAvail = evalMitCrdObjAvail(dbswzsk);
	statshr.MitCrdSesAvail = evalMitCrdSesAvail(dbswzsk);
	statshr.MitCrdShtAvail = evalMitCrdShtAvail(dbswzsk);
	statshr.MitCrdFilAvail = evalMitCrdFilAvail(dbswzsk);
	statshr.MspApp2Avail = evalMspApp2Avail(dbswzsk);
	statshr.MitAppLoiAvail = evalMitAppLoiAvail(dbswzsk);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWzskNav::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnlpre) if (jrefTrig != pnlpre->jref) pnlpre->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
	if (pnladmin) pnladmin->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
	if (pnlop) pnlop->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
	if (pnlgalery) pnlgalery->updatePreset(dbswzsk, ixWzskVPreset, jrefTrig, notif);
	// IP updatePreset --- END
};

void CrdWzskNav::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESSPSCLICK) {
					handleDpchAppDoMitSesSpsClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESTRMCLICK) {
					handleDpchAppDoMitSesTrmClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSGCLICK) {
					handleDpchAppDoMitCrdUsgClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSRCLICK) {
					handleDpchAppDoMitCrdUsrClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRSCLICK) {
					handleDpchAppDoMitCrdPrsClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSCFCLICK) {
					handleDpchAppDoMitCrdScfClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLLVCLICK) {
					handleDpchAppDoMitCrdLlvClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLIVCLICK) {
					handleDpchAppDoMitCrdLivClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDOGRCLICK) {
					handleDpchAppDoMitCrdOgrClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDOBJCLICK) {
					handleDpchAppDoMitCrdObjClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSESCLICK) {
					handleDpchAppDoMitCrdSesClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSHTCLICK) {
					handleDpchAppDoMitCrdShtClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFILCLICK) {
					handleDpchAppDoMitCrdFilClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPLOICLICK) {
					handleDpchAppDoMitAppLoiClick(dbswzsk, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKALERT) {
			handleDpchAppWzskAlert(dbswzsk, (DpchAppWzskAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWzskNav::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzskNav::handleDpchAppDoClose(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");

	if (xchg->stgwzskappearance.suspsess) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSUSPSESS, xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFSESS, jref));
	else xchg->triggerBoolvalCall(dbswzsk, VecWzskVCall::CALLWZSKLOGOUT, xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFSESS, jref), false);
};

void CrdWzskNav::handleDpchAppDoMitAppAbtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzsk, VecVSge::ALRWZSKABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzskNav::handleDpchAppDoMitSesSpsClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");

	xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSUSPSESS, xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFSESS, jref));
};

void CrdWzskNav::handleDpchAppDoMitSesTrmClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");

	xchg->triggerBoolvalCall(dbswzsk, VecWzskVCall::CALLWZSKLOGOUT, xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFSESS, jref), false);
};

void CrdWzskNav::handleDpchAppDoMitCrdUsgClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskUsg");
};

void CrdWzskNav::handleDpchAppDoMitCrdUsrClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskUsr");
};

void CrdWzskNav::handleDpchAppDoMitCrdPrsClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskPrs");
};

void CrdWzskNav::handleDpchAppDoMitCrdScfClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskScf", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskScf");
};

void CrdWzskNav::handleDpchAppDoMitCrdLlvClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskLlv", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskLlv");
};

void CrdWzskNav::handleDpchAppDoMitCrdLivClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskLiv", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskLiv");
};

void CrdWzskNav::handleDpchAppDoMitCrdOgrClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskOgr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskOgr");
};

void CrdWzskNav::handleDpchAppDoMitCrdObjClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskObj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskObj");
};

void CrdWzskNav::handleDpchAppDoMitCrdSesClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskSes", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskSes");
};

void CrdWzskNav::handleDpchAppDoMitCrdShtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskSht", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskSht");
};

void CrdWzskNav::handleDpchAppDoMitCrdFilClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, 0, 0, "CrdWzskFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, "CrdWzskFil");
};

void CrdWzskNav::handleDpchAppDoMitAppLoiClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	if (!dlgloaini) {
		dlgloaini = new DlgWzskNavLoaini(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefDlgloaini = dlgloaini->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWzskNav::handleDpchAppWzskAlert(
			DbsWzsk* dbswzsk
			, DpchAppWzskAlert* dpchappwzskalert
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppWzskAlert --- BEGIN
	if (ixVSge == VecVSge::ALRWZSKABT) {
		changeStage(dbswzsk, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");
	// IP handleDpchAppWzskAlert --- END
};

void CrdWzskNav::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKDLGCLOSE) {
		call->abort = handleCallWzskDlgClose(dbswzsk, call->jref);
	};
};

bool CrdWzskNav::handleCallWzskDlgClose(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgloaini) {
		delete dlgloaini;
		dlgloaini = NULL;
		statshr.jrefDlgloaini = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWzskNav::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
			, DpchEngWzsk** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::ALRWZSKABT: leaveSgeAlrwzskabt(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswzsk, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::ALRWZSKABT: _ixVSge = enterSgeAlrwzskabt(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWzskNav::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzskNav::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzskNav::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzskNav::enterSgeAlrwzskabt(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZSKABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzsk::prepareAlrAbt(jref, ixWzskVLocale, feedFMcbAlert)); // IP enterSgeAlrwzskabt --- LINE

	return retval;
};

void CrdWzskNav::leaveSgeAlrwzskabt(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAlrwzskabt --- INSERT
};

