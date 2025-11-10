/**
	* \file PnlWzskPrfGlobal.cpp
	* job handler for job PnlWzskPrfGlobal (implementation)
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

#include "PnlWzskPrfGlobal.h"

#include "PnlWzskPrfGlobal_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskPrfGlobal
 ******************************************************************************/

PnlWzskPrfGlobal::PnlWzskPrfGlobal(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKPRFGLOBAL, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPup102.tag = "FeedFPup102";
	VecWzskVTarget::fillFeed(ixWzskVLocale, feedFPup102);

	// IP constructor.cust1 --- INSERT

	setPref(dbswzsk); // IP constructor.cust2 --- LINE

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

};

PnlWzskPrfGlobal::~PnlWzskPrfGlobal() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- BEGIN
void PnlWzskPrfGlobal::getPref(
			StgWzskCamera*& _stgwzskcamera
		) {
	if (!(statshr.Txf2Clean && statshr.Txf3Clean && statshr.Txf4Clean && statshr.Txf5Clean && statshr.Txf6Clean)) {
		_stgwzskcamera = &stgwzskcamera;
		stgwzskcamera.hpix = atof(contiac.Txf2.c_str());
		stgwzskcamera.f = atof(contiac.Txf3.c_str());
		stgwzskcamera.fn = atof(contiac.Txf4.c_str());
		stgwzskcamera.NColRaw = atol(contiac.Txf5.c_str());
		stgwzskcamera.NRowRaw = atol(contiac.Txf6.c_str());
	};

};

void PnlWzskPrfGlobal::setPref(
			DbsWzsk* dbswzsk
			, const bool _refresh
		) {
	set<uint> moditems;

	contiac.Txf2 = to_string(xchg->stgwzskcamera.hpix);
	contiac.Txf3 = to_string(xchg->stgwzskcamera.f);
	contiac.Txf4 = to_string(xchg->stgwzskcamera.fn);
	contiac.Txf5 = to_string(xchg->stgwzskcamera.NColRaw);
	contiac.Txf6 = to_string(xchg->stgwzskcamera.NRowRaw);

	if (_refresh) {
		refresh(dbswzsk, moditems);
		insert(moditems, DpchEngData::CONTIAC);
		xchg->submitDpch(getNewDpchEng(moditems));
	};
};
// IP cust --- END

DpchEngWzsk* PnlWzskPrfGlobal::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFPup102, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskPrfGlobal::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- BEGIN
	// statshr
	statshr.Txf2Clean = (contiac.Txf2 == to_string(xchg->stgwzskcamera.hpix));
	statshr.Txf3Clean = (contiac.Txf3 == to_string(xchg->stgwzskcamera.f));
	statshr.Txf4Clean = (contiac.Txf4 == to_string(xchg->stgwzskcamera.fn));
	statshr.Txf5Clean = (contiac.Txf5 == to_string(xchg->stgwzskcamera.NColRaw));
	statshr.Txf6Clean = (contiac.Txf6 == to_string(xchg->stgwzskcamera.NRowRaw));

	// IP refresh --- END

	muteRefresh = false;
};

void PnlWzskPrfGlobal::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFGLOBALDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFGLOBALDO) {
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

void PnlWzskPrfGlobal::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskPrfGlobal::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- BEGIN
	if (has(diffitems, ContIac::TXF2)) contiac.Txf2 = _contiac->Txf2;
	if (has(diffitems, ContIac::TXF3)) contiac.Txf3 = _contiac->Txf3;
	if (has(diffitems, ContIac::TXF4)) contiac.Txf4 = _contiac->Txf4;
	if (has(diffitems, ContIac::TXF5)) contiac.Txf5 = _contiac->Txf5;
	if (has(diffitems, ContIac::TXF6)) contiac.Txf6 = _contiac->Txf6;

	if (!diffitems.empty()) refresh(dbswzsk, moditems);
	// IP handleDpchAppDataContiac --- END
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskPrfGlobal::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskPrfGlobal::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};
