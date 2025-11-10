/**
	* \file PnlWzskPrfAcqPreview.cpp
	* job handler for job PnlWzskPrfAcqPreview (implementation)
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

#include "PnlWzskPrfAcqPreview.h"

#include "PnlWzskPrfAcqPreview_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskPrfAcqPreview
 ******************************************************************************/

PnlWzskPrfAcqPreview::PnlWzskPrfAcqPreview(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKPRFACQPREVIEW, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	setPref(dbswzsk); // IP constructor.cust2 --- LINE

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

};

PnlWzskPrfAcqPreview::~PnlWzskPrfAcqPreview() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- BEGIN
void PnlWzskPrfAcqPreview::getPref(
			JobWzskAcqPreview::Stg*& _stgjobwzskacqpreview
		) {
	if (!(statshr.Chk1Clean && statshr.Txf2Clean)) {
		_stgjobwzskacqpreview = &stgjobwzskacqpreview;
		stgjobwzskacqpreview.rgbNotGray = contiac.Chk1;
		stgjobwzskacqpreview.decim = atoi(contiac.Txf2.c_str());
	};

};

void PnlWzskPrfAcqPreview::setPref(
			DbsWzsk* dbswzsk
			, const bool _refresh
		) {
	set<uint> moditems;

	contiac.Chk1 = JobWzskAcqPreview::stg.rgbNotGray;
	contiac.Txf2 = to_string(JobWzskAcqPreview::stg.decim);

	if (_refresh) {
		refresh(dbswzsk, moditems);
		insert(moditems, DpchEngData::CONTIAC);
		xchg->submitDpch(getNewDpchEng(moditems));
	};
};
// IP cust --- END

DpchEngWzsk* PnlWzskPrfAcqPreview::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskPrfAcqPreview::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- BEGIN
	// statshr
	statshr.Chk1Clean = (contiac.Chk1 == JobWzskAcqPreview::stg.rgbNotGray);
	statshr.Txf2Clean = (contiac.Txf2 == to_string(JobWzskAcqPreview::stg.decim));

	// IP refresh --- END

	muteRefresh = false;
};

void PnlWzskPrfAcqPreview::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFACQPREVIEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFACQPREVIEWDO) {
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

void PnlWzskPrfAcqPreview::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskPrfAcqPreview::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- BEGIN
	if (has(diffitems, ContIac::CHK1)) contiac.Chk1 = _contiac->Chk1;
	if (has(diffitems, ContIac::TXF2)) contiac.Txf2 = _contiac->Txf2;

	if (!diffitems.empty()) refresh(dbswzsk, moditems);
	// IP handleDpchAppDataContiac --- END
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskPrfAcqPreview::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskPrfAcqPreview::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};
