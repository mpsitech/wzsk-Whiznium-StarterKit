/**
	* \file CrdWzskPrf.cpp
	* job handler for job CrdWzskPrf (implementation)
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

#include "CrdWzskPrf.h"

#include "CrdWzskPrf_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzskPrf
 ******************************************************************************/

CrdWzskPrf::CrdWzskPrf(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::CRDWZSKPRF, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlheadbar = NULL;
	pnldaemon = NULL;
	pnlglobal = NULL;
	pnlacqcorner = NULL;
	pnlacqhdr = NULL;
	pnlacqpreview = NULL;
	pnlacqtrace = NULL;
	pnlactlaser = NULL;
	pnlactrotary = NULL;
	pnlactvistorot = NULL;
	pnlsrcdcvsp = NULL;
	pnlsrcsysinfo = NULL;
	pnlsrctivsp = NULL;
	pnlsrczuvsp = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	pnlheadbar = new PnlWzskPrfHeadbar(xchg, dbswzsk, jref, ixWzskVLocale);
	pnldaemon = new PnlWzskPrfDaemon(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlglobal = new PnlWzskPrfGlobal(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlacqcorner = new PnlWzskPrfAcqCorner(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlacqhdr = new PnlWzskPrfAcqHdr(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlacqpreview = new PnlWzskPrfAcqPreview(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlacqtrace = new PnlWzskPrfAcqTrace(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlactlaser = new PnlWzskPrfActLaser(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlactrotary = new PnlWzskPrfActRotary(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlactvistorot = new PnlWzskPrfActVistorot(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlsrcdcvsp = new PnlWzskPrfSrcDcvsp(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlsrcsysinfo = new PnlWzskPrfSrcSysinfo(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlsrctivsp = new PnlWzskPrfSrcTivsp(xchg, dbswzsk, jref, ixWzskVLocale);
	pnlsrczuvsp = new PnlWzskPrfSrcZuvsp(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefDaemon = pnldaemon->jref;
	statshr.jrefGlobal = pnlglobal->jref;
	statshr.jrefAcqCorner = pnlacqcorner->jref;
	statshr.jrefAcqHdr = pnlacqhdr->jref;
	statshr.jrefAcqPreview = pnlacqpreview->jref;
	statshr.jrefAcqTrace = pnlacqtrace->jref;
	statshr.jrefActLaser = pnlactlaser->jref;
	statshr.jrefActRotary = pnlactrotary->jref;
	statshr.jrefActVistorot = pnlactvistorot->jref;
	statshr.jrefSrcDcvsp = pnlsrcdcvsp->jref;
	statshr.jrefSrcSysinfo = pnlsrcsysinfo->jref;
	statshr.jrefSrcTivsp = pnlsrctivsp->jref;
	statshr.jrefSrcZuvsp = pnlsrczuvsp->jref;

	changeStage(dbswzsk, VecVSge::IDLE);

	xchg->addClstn(VecWzskVCall::CALLWZSKDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWzskPrf::~CrdWzskPrf() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- BEGIN
void CrdWzskPrf::setPref(
			DbsWzsk* dbswzsk
		) {
	pnldaemon->setPref(dbswzsk, true);
	pnlglobal->setPref(dbswzsk, true);
	pnlacqcorner->setPref(dbswzsk, true);
	pnlacqhdr->setPref(dbswzsk, true);
	pnlacqpreview->setPref(dbswzsk, true);
	pnlacqtrace->setPref(dbswzsk, true);
	pnlactlaser->setPref(dbswzsk, true);
	pnlactrotary->setPref(dbswzsk, true);
	pnlactvistorot->setPref(dbswzsk, true);
	pnlsrcdcvsp->setPref(dbswzsk, true);
	pnlsrcsysinfo->setPref(dbswzsk, true);
	pnlsrctivsp->setPref(dbswzsk, true);
	pnlsrczuvsp->setPref(dbswzsk, true);
};

void CrdWzskPrf::storePref() {
	xmlTextWriter* wr = NULL;

	StgWzskBehavior* stgwzskbehavior = &(xchg->stgwzskbehavior);
	StgWzskAppsrv* stgwzskappsrv = &(xchg->stgwzskappsrv);
#ifdef WZSKCMBD
	StgWzskcmbd* stgwzskcmbd = &(xchg->stgwzskcmbd);
#endif
	StgWzskDatabase* stgwzskdatabase = &(xchg->stgwzskdatabase);
	StgWzskPath* stgwzskpath = &(xchg->stgwzskpath);
	StgWzskDdspub* stgwzskddspub = &(xchg->stgwzskddspub);
	StgWzskUasrv* stgwzskuasrv = &(xchg->stgwzskuasrv);
	StgWzskCamera* stgwzskcamera = &(xchg->stgwzskcamera);
	JobWzskAcqCorner::Stg* stgjobwzskacqcorner = &(JobWzskAcqCorner::stg);
	JobWzskAcqHdr::Stg* stgjobwzskacqhdr = &(JobWzskAcqHdr::stg);
	JobWzskAcqPreview::Stg* stgjobwzskacqpreview = &(JobWzskAcqPreview::stg);
	JobWzskAcqTrace::Stg* stgjobwzskacqtrace = &(JobWzskAcqTrace::stg);
	JobWzskActLaser::Stg* stgjobwzskactlaser = &(JobWzskActLaser::stg);
	JobWzskActRotary::Stg* stgjobwzskactrotary = &(JobWzskActRotary::stg);
	JobWzskActVistorot::Stg* stgjobwzskactvistorot = &(JobWzskActVistorot::stg);
	JobWzskSrcDcvsp::Stg* stgjobwzsksrcdcvsp = &(JobWzskSrcDcvsp::stg);
	JobWzskSrcSysinfo::Stg* stgjobwzsksrcsysinfo = &(JobWzskSrcSysinfo::stg);
	JobWzskSrcTivsp::Stg* stgjobwzsksrctivsp = &(JobWzskSrcTivsp::stg);
	JobWzskSrcZuvsp::Stg* stgjobwzsksrczuvsp = &(JobWzskSrcZuvsp::stg);

	time_t now;

	int res;

	string s;

#if defined(WZSKD)
	const string fileroot = "PrefWzskd";
#elif defined(WZSKCMBD)
	const string fileroot = "PrefWzskcmbd";
#endif

	// create backup of current preferences file
	time(&now);
	s = "cp -p " + xchg->exedir + "/" + fileroot + ".xml " + xchg->exedir + "/" + fileroot + "_" + to_string(now) + ".xml";
	res = system(s.c_str());
	if (res != 0) throw SbeException(SbeException::PATHNF, {{"path",xchg->exedir + "/" + fileroot + ".xml"}});

#ifdef WZSKD
	pnldaemon->getPref(stgwzskbehavior, stgwzskappsrv, stgwzskdatabase, stgwzskpath, stgwzskddspub, stgwzskuasrv);
#endif
#ifdef WZSKCMBD
	pnldaemon->getPref(stgwzskbehavior, stgwzskappsrv, stgwzskcmbd, stgwzskdatabase, stgwzskpath, stgwzskddspub, stgwzskuasrv);
#endif
	pnlglobal->getPref(stgwzskcamera);
	pnlacqcorner->getPref(stgjobwzskacqcorner);
	pnlacqhdr->getPref(stgjobwzskacqhdr);
	pnlacqpreview->getPref(stgjobwzskacqpreview);
	pnlacqtrace->getPref(stgjobwzskacqtrace);
	pnlactlaser->getPref(stgjobwzskactlaser);
	pnlactrotary->getPref(stgjobwzskactrotary);
	pnlactvistorot->getPref(stgjobwzskactvistorot);
	pnlsrcdcvsp->getPref(stgjobwzsksrcdcvsp);
	pnlsrcsysinfo->getPref(stgjobwzsksrcsysinfo);
	pnlsrctivsp->getPref(stgjobwzsksrctivsp);
	pnlsrczuvsp->getPref(stgjobwzsksrczuvsp);

	startwriteFile(xchg->exedir + "/" + fileroot + ".xml", &wr);
	xmlTextWriterSetIndent(wr, 1);
	xmlTextWriterSetIndentString(wr, BAD_CAST "	");
	xmlTextWriterStartElement(wr, BAD_CAST fileroot.c_str());
		stgwzskbehavior->writeXML(wr);
		stgwzskappsrv->writeXML(wr);
#ifdef WZSKCMBD
		stgwzskcmbd->writeXML(wr);
#endif
		stgwzskdatabase->writeXML(wr);
		stgwzskpath->writeXML(wr);
		stgwzskddspub->writeXML(wr);
		stgwzskuasrv->writeXML(wr);
		stgwzskcamera->writeXML(wr);
		stgjobwzskacqcorner->writeXML(wr);
		stgjobwzskacqhdr->writeXML(wr);
		stgjobwzskacqpreview->writeXML(wr);
		stgjobwzskacqtrace->writeXML(wr);
		stgjobwzskactlaser->writeXML(wr);
		stgjobwzskactrotary->writeXML(wr);
		stgjobwzskactvistorot->writeXML(wr);
		stgjobwzsksrcdcvsp->writeXML(wr);
		stgjobwzsksrcsysinfo->writeXML(wr);
		stgjobwzsksrctivsp->writeXML(wr);
		stgjobwzsksrczuvsp->writeXML(wr);
	xmlTextWriterEndElement(wr);
	closewriteFile(wr);
};
// IP cust --- END

DpchEngWzsk* CrdWzskPrf::getNewDpchEng(
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

void CrdWzskPrf::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzskPrf/" + VecWzskVLocale::getSref(ixWzskVLocale);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdWzskPrf::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWzskPrf::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDRVRCLICK) {
					handleDpchAppDoMitCrdRvrClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSTOCLICK) {
					handleDpchAppDoMitCrdStoClick(dbswzsk, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKALERT) {
			handleDpchAppWzskAlert(dbswzsk, (DpchAppWzskAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWzskPrf::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzskPrf::handleDpchAppDoClose(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzskConfirm(true, jref, "");
	xchg->triggerIxCall(dbswzsk, VecWzskVCall::CALLWZSKCRDCLOSE, jref, VecWzskVCard::CRDWZSKPRF);
};

void CrdWzskPrf::handleDpchAppDoMitAppAbtClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzsk, VecVSge::ALRWZSKABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzskPrf::handleDpchAppDoMitCrdRvrClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	setPref(dbswzsk); // IP handleDpchAppDoMitCrdRvrClick --- LINE
};

void CrdWzskPrf::handleDpchAppDoMitCrdStoClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	storePref(); // IP handleDpchAppDoMitCrdStoClick --- LINE
};

void CrdWzskPrf::handleDpchAppWzskAlert(
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

void CrdWzskPrf::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKDLGCLOSE) {
		call->abort = handleCallWzskDlgClose(dbswzsk, call->jref);
	};
};

bool CrdWzskPrf::handleCallWzskDlgClose(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskDlgClose --- INSERT
	return retval;
};

void CrdWzskPrf::changeStage(
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

string CrdWzskPrf::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzskPrf::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzskPrf::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzskPrf::enterSgeAlrwzskabt(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZSKABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzsk::prepareAlrAbt(jref, ixWzskVLocale, feedFMcbAlert)); // IP enterSgeAlrwzskabt --- LINE

	return retval;
};

void CrdWzskPrf::leaveSgeAlrwzskabt(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAlrwzskabt --- INSERT
};
