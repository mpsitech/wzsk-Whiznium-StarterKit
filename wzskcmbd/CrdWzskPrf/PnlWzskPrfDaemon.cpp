/**
	* \file PnlWzskPrfDaemon.cpp
	* job handler for job PnlWzskPrfDaemon (implementation)
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

#include "PnlWzskPrfDaemon.h"

#include "PnlWzskPrfDaemon_blks.cpp"
#include "PnlWzskPrfDaemon_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskPrfDaemon
 ******************************************************************************/

PnlWzskPrfDaemon::PnlWzskPrfDaemon(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKPRFDAEMON, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPup302.tag = "FeedFPup302";

	// IP constructor.cust1 --- INSERT

	setPref(dbswzsk); // IP constructor.cust2 --- LINE

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

};

PnlWzskPrfDaemon::~PnlWzskPrfDaemon() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- BEGIN
void PnlWzskPrfDaemon::getPref(
#ifdef WZSKD
			StgWzskBehavior*& _stgwzskbehavior
			,  StgWzskAppsrv*& _stgwzskappsrv
			,  StgWzskDatabase*& _stgwzskdatabase
			,  StgWzskPath*& _stgwzskpath
			,  StgWzskDdspub*& _stgwzskddspub
			,  StgWzskUasrv*& _stgwzskuasrv
#endif
#ifdef WZSKCMBD
			StgWzskBehavior*& _stgwzskbehavior
			,  StgWzskAppsrv*& _stgwzskappsrv
			,  StgWzskcmbd*& _stgwzskcmbd
			,  StgWzskDatabase*& _stgwzskdatabase
			,  StgWzskPath*& _stgwzskpath
			,  StgWzskDdspub*& _stgwzskddspub
			,  StgWzskUasrv*& _stgwzskuasrv
#endif
		) {
	if (!(statshr.Txf2Clean && statshr.Chk3Clean && statshr.Txf4Clean && statshr.Txf5Clean && statshr.Txf6Clean)) {
		_stgwzskbehavior = &stgwzskbehavior;
		stgwzskbehavior.histlength = atoi(contiac.Txf2.c_str());
		stgwzskbehavior.suspsess = contiac.Chk3;
		stgwzskbehavior.sesstterm = atol(contiac.Txf4.c_str());
		stgwzskbehavior.sesstwarn = atol(contiac.Txf5.c_str());
		stgwzskbehavior.roottterm = atol(contiac.Txf6.c_str());
	};

	if (!(statshr.Txf102Clean && statshr.Chk103Clean && statshr.Txf104Clean)) {
		_stgwzskappsrv = &stgwzskappsrv;
		stgwzskappsrv.port = atoi(contiac.Txf102.c_str());
		stgwzskappsrv.https = contiac.Chk103;
		stgwzskappsrv.cors = contiac.Txf104;
	};

#ifdef WZSKCMBD
	if (!(statshr.Txf202Clean && statshr.Txf203Clean && statshr.Chk204Clean && statshr.Chk205Clean && statshr.Chk206Clean)) {
		_stgwzskcmbd = &stgwzskcmbd;
		stgwzskcmbd.jobprcn = atoi(contiac.Txf202.c_str());
		stgwzskcmbd.opprcn = atoi(contiac.Txf203.c_str());
		stgwzskcmbd.appsrv = contiac.Chk204;
		stgwzskcmbd.ddspub = contiac.Chk205;
		stgwzskcmbd.uasrv = contiac.Chk206;
	};
#endif

	if (!(statshr.Pup302Clean && statshr.Txf303Clean && statshr.Txf304Clean && statshr.Txf305Clean && statshr.Txf306Clean && statshr.Txf307Clean && statshr.Txf308Clean)) {
		_stgwzskdatabase = &stgwzskdatabase;
		stgwzskdatabase.ixDbsVDbstype = feedFPup302.getIxByNum(contiac.numFPup302);
		stgwzskdatabase.dbspath = contiac.Txf303;
		stgwzskdatabase.dbsname = contiac.Txf304;
		stgwzskdatabase.username = contiac.Txf305;
		stgwzskdatabase.password = contiac.Txf306;
		stgwzskdatabase.ip = contiac.Txf307;
		stgwzskdatabase.port = atoi(contiac.Txf308.c_str());
	};

	if (!(statshr.Txf402Clean && statshr.Txf403Clean && statshr.Txf404Clean && statshr.Txf405Clean && statshr.Txf406Clean && statshr.Txf407Clean)) {
		_stgwzskpath = &stgwzskpath;
		stgwzskpath.acvpath = contiac.Txf402;
		stgwzskpath.keypath = contiac.Txf403;
		stgwzskpath.monpath = contiac.Txf404;
		stgwzskpath.tmppath = contiac.Txf405;
		stgwzskpath.webpath = contiac.Txf406;
		stgwzskpath.helpurl = contiac.Txf407;
	};

	if (!(statshr.Txf502Clean && statshr.Txf503Clean)) {
		_stgwzskddspub = &stgwzskddspub;
		stgwzskddspub.username = contiac.Txf502;
		stgwzskddspub.password = contiac.Txf503;
	};

	if (!(statshr.Txf602Clean && statshr.Txf603Clean && statshr.Txf604Clean && statshr.Txf605Clean && statshr.Txf606Clean)) {
		_stgwzskuasrv = &stgwzskuasrv;
		stgwzskuasrv.profile = contiac.Txf602;
		stgwzskuasrv.port = atoi(contiac.Txf603.c_str());
		stgwzskuasrv.cycle = atoi(contiac.Txf604.c_str());
		stgwzskuasrv.maxbrowse = atol(contiac.Txf605.c_str());
		stgwzskuasrv.maxmon = atol(contiac.Txf606.c_str());
	};

};

void PnlWzskPrfDaemon::setPref(
			DbsWzsk* dbswzsk
			, const bool _refresh
		) {
	set<uint> moditems;

	contiac.Txf2 = to_string(xchg->stgwzskbehavior.histlength);
	contiac.Chk3 = xchg->stgwzskbehavior.suspsess;
	contiac.Txf4 = to_string(xchg->stgwzskbehavior.sesstterm);
	contiac.Txf5 = to_string(xchg->stgwzskbehavior.sesstwarn);
	contiac.Txf6 = to_string(xchg->stgwzskbehavior.roottterm);

	contiac.Txf102 = to_string(xchg->stgwzskappsrv.port);
	contiac.Chk103 = xchg->stgwzskappsrv.https;
	contiac.Txf104 = xchg->stgwzskappsrv.cors;

#ifdef WZSKCMBD
	contiac.Txf202 = to_string(xchg->stgwzskcmbd.jobprcn);
	contiac.Txf203 = to_string(xchg->stgwzskcmbd.opprcn);
	contiac.Chk204 = xchg->stgwzskcmbd.appsrv;
	contiac.Chk205 = xchg->stgwzskcmbd.ddspub;
	contiac.Chk206 = xchg->stgwzskcmbd.uasrv;
#endif

	contiac.numFPup302 = feedFPup302.getNumByIx(xchg->stgwzskdatabase.ixDbsVDbstype);
	contiac.Txf303 = xchg->stgwzskdatabase.dbspath;
	contiac.Txf304 = xchg->stgwzskdatabase.dbsname;
	contiac.Txf305 = xchg->stgwzskdatabase.username;
	contiac.Txf306 = xchg->stgwzskdatabase.password;
	contiac.Txf307 = xchg->stgwzskdatabase.ip;
	contiac.Txf308 = to_string(xchg->stgwzskdatabase.port);

	contiac.Txf402 = xchg->stgwzskpath.acvpath;
	contiac.Txf403 = xchg->stgwzskpath.keypath;
	contiac.Txf404 = xchg->stgwzskpath.monpath;
	contiac.Txf405 = xchg->stgwzskpath.tmppath;
	contiac.Txf406 = xchg->stgwzskpath.webpath;
	contiac.Txf407 = xchg->stgwzskpath.helpurl;

	contiac.Txf502 = xchg->stgwzskddspub.username;
	contiac.Txf503 = xchg->stgwzskddspub.password;

	contiac.Txf602 = xchg->stgwzskuasrv.profile;
	contiac.Txf603 = to_string(xchg->stgwzskuasrv.port);
	contiac.Txf604 = to_string(xchg->stgwzskuasrv.cycle);
	contiac.Txf605 = to_string(xchg->stgwzskuasrv.maxbrowse);
	contiac.Txf606 = to_string(xchg->stgwzskuasrv.maxmon);

	if (_refresh) {
		refresh(dbswzsk, moditems);
		insert(moditems, DpchEngData::CONTIAC);
		xchg->submitDpch(getNewDpchEng(moditems));
	};
};
// IP cust --- END

DpchEngWzsk* PnlWzskPrfDaemon::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFPup302, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskPrfDaemon::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.Txf2Clean = (contiac.Txf2 == to_string(xchg->stgwzskbehavior.histlength));
	statshr.Chk3Clean = (contiac.Chk3 == xchg->stgwzskbehavior.suspsess);
	statshr.Txf4Clean = (contiac.Txf4 == to_string(xchg->stgwzskbehavior.sesstterm));
	statshr.Txf5Clean = (contiac.Txf5 == to_string(xchg->stgwzskbehavior.sesstwarn));
	statshr.Txf6Clean = (contiac.Txf6 == to_string(xchg->stgwzskbehavior.roottterm));

	statshr.Txf102Clean = (contiac.Txf102 == to_string(xchg->stgwzskappsrv.port));
	statshr.Chk103Clean = (contiac.Chk103 == xchg->stgwzskappsrv.https);
	statshr.Txf104Clean = (contiac.Txf104 == xchg->stgwzskappsrv.cors);

	statshr.Sep2Avail = evalSep2Avail(dbswzsk);
	statshr.Hdg201Avail = evalHdg201Avail(dbswzsk);
	statshr.Txf202Avail = evalTxf202Avail(dbswzsk);
	statshr.Txf203Avail = evalTxf203Avail(dbswzsk);
	statshr.Chk204Avail = evalChk204Avail(dbswzsk);
	statshr.Chk205Avail = evalChk205Avail(dbswzsk);
	statshr.Chk206Avail = evalChk206Avail(dbswzsk);

#ifdef WZSKCMBD
	statshr.Txf202Clean = (contiac.Txf202 == to_string(xchg->stgwzskcmbd.jobprcn));
	statshr.Txf203Clean = (contiac.Txf203 == to_string(xchg->stgwzskcmbd.opprcn));
	statshr.Chk204Clean = (contiac.Chk204 == xchg->stgwzskcmbd.appsrv);
	statshr.Chk205Clean = (contiac.Chk205 == xchg->stgwzskcmbd.ddspub);
	statshr.Chk206Clean = (contiac.Chk206 == xchg->stgwzskcmbd.uasrv);
#endif

	statshr.Pup302Clean = (contiac.numFPup302 == feedFPup302.getNumByIx(xchg->stgwzskdatabase.ixDbsVDbstype));
	statshr.Txf303Clean = (contiac.Txf303 == xchg->stgwzskdatabase.dbspath);
	statshr.Txf304Clean = (contiac.Txf304 == xchg->stgwzskdatabase.dbsname);
	statshr.Txf305Clean = (contiac.Txf305 == xchg->stgwzskdatabase.username);
	statshr.Txf306Clean = (contiac.Txf306 == xchg->stgwzskdatabase.password);
	statshr.Txf307Clean = (contiac.Txf307 == xchg->stgwzskdatabase.ip);
	statshr.Txf308Clean = (contiac.Txf308 == to_string(xchg->stgwzskdatabase.port));

	statshr.Txf402Clean = (contiac.Txf402 == xchg->stgwzskpath.acvpath);
	statshr.Txf403Clean = (contiac.Txf403 == xchg->stgwzskpath.keypath);
	statshr.Txf404Clean = (contiac.Txf404 == xchg->stgwzskpath.monpath);
	statshr.Txf405Clean = (contiac.Txf405 == xchg->stgwzskpath.tmppath);
	statshr.Txf406Clean = (contiac.Txf406 == xchg->stgwzskpath.webpath);
	statshr.Txf407Clean = (contiac.Txf407 == xchg->stgwzskpath.helpurl);

	statshr.Txf502Clean = (contiac.Txf502 == xchg->stgwzskddspub.username);
	statshr.Txf503Clean = (contiac.Txf503 == xchg->stgwzskddspub.password);

	statshr.Txf602Clean = (contiac.Txf602 == xchg->stgwzskuasrv.profile);
	statshr.Txf603Clean = (contiac.Txf603 == to_string(xchg->stgwzskuasrv.port));
	statshr.Txf604Clean = (contiac.Txf604 == to_string(xchg->stgwzskuasrv.cycle));
	statshr.Txf605Clean = (contiac.Txf605 == to_string(xchg->stgwzskuasrv.maxbrowse));
	statshr.Txf606Clean = (contiac.Txf606 == to_string(xchg->stgwzskuasrv.maxmon));

	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskPrfDaemon::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFDAEMONDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFDAEMONDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskPrfDaemon::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskPrfDaemon::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- BEGIN
	if (has(diffitems, ContIac::TXF2)) contiac.Txf2 = _contiac->Txf2;
	if (has(diffitems, ContIac::CHK3)) contiac.Chk3 = _contiac->Chk3;
	if (has(diffitems, ContIac::TXF4)) contiac.Txf4 = _contiac->Txf4;
	if (has(diffitems, ContIac::TXF5)) contiac.Txf5 = _contiac->Txf5;
	if (has(diffitems, ContIac::TXF6)) contiac.Txf6 = _contiac->Txf6;

	if (has(diffitems, ContIac::TXF102)) contiac.Txf102 = _contiac->Txf102;
	if (has(diffitems, ContIac::CHK103)) contiac.Chk103 = _contiac->Chk103;
	if (has(diffitems, ContIac::TXF104)) contiac.Txf104 = _contiac->Txf104;

	if (has(diffitems, ContIac::TXF202)) contiac.Txf202 = _contiac->Txf202;
	if (has(diffitems, ContIac::TXF203)) contiac.Txf203 = _contiac->Txf203;
	if (has(diffitems, ContIac::CHK204)) contiac.Chk204 = _contiac->Chk204;
	if (has(diffitems, ContIac::CHK205)) contiac.Chk205 = _contiac->Chk205;
	if (has(diffitems, ContIac::CHK206)) contiac.Chk206 = _contiac->Chk206;

	if (has(diffitems, ContIac::NUMFPUP302)) {
		if (feedFPup302.getIxByNum(_contiac->numFPup302) != 0) contiac.numFPup302 = _contiac->numFPup302;
		else contiac.numFPup302 = 1;
	};
	if (has(diffitems, ContIac::TXF303)) contiac.Txf303 = _contiac->Txf303;
	if (has(diffitems, ContIac::TXF304)) contiac.Txf304 = _contiac->Txf304;
	if (has(diffitems, ContIac::TXF305)) contiac.Txf305 = _contiac->Txf305;
	if (has(diffitems, ContIac::TXF306)) contiac.Txf306 = _contiac->Txf306;
	if (has(diffitems, ContIac::TXF307)) contiac.Txf307 = _contiac->Txf307;
	if (has(diffitems, ContIac::TXF308)) contiac.Txf308 = _contiac->Txf308;

	if (has(diffitems, ContIac::TXF402)) contiac.Txf402 = _contiac->Txf402;
	if (has(diffitems, ContIac::TXF403)) contiac.Txf403 = _contiac->Txf403;
	if (has(diffitems, ContIac::TXF404)) contiac.Txf404 = _contiac->Txf404;
	if (has(diffitems, ContIac::TXF405)) contiac.Txf405 = _contiac->Txf405;
	if (has(diffitems, ContIac::TXF406)) contiac.Txf406 = _contiac->Txf406;
	if (has(diffitems, ContIac::TXF407)) contiac.Txf407 = _contiac->Txf407;

	if (has(diffitems, ContIac::TXF502)) contiac.Txf502 = _contiac->Txf502;
	if (has(diffitems, ContIac::TXF503)) contiac.Txf503 = _contiac->Txf503;

	if (has(diffitems, ContIac::TXF602)) contiac.Txf602 = _contiac->Txf602;
	if (has(diffitems, ContIac::TXF603)) contiac.Txf603 = _contiac->Txf603;
	if (has(diffitems, ContIac::TXF604)) contiac.Txf604 = _contiac->Txf604;
	if (has(diffitems, ContIac::TXF605)) contiac.Txf605 = _contiac->Txf605;
	if (has(diffitems, ContIac::TXF606)) contiac.Txf606 = _contiac->Txf606;

	if (!diffitems.empty()) refresh(dbswzsk, moditems);
	// IP handleDpchAppDataContiac --- END
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskPrfDaemon::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskPrfDaemon::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};
