/**
	* \file PnlWzskPrfAcqTrace.cpp
	* job handler for job PnlWzskPrfAcqTrace (implementation)
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

#include "PnlWzskPrfAcqTrace.h"

#include "PnlWzskPrfAcqTrace_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskPrfAcqTrace
 ******************************************************************************/

PnlWzskPrfAcqTrace::PnlWzskPrfAcqTrace(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKPRFACQTRACE, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	setPref(dbswzsk); // IP constructor.cust2 --- LINE

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

};

PnlWzskPrfAcqTrace::~PnlWzskPrfAcqTrace() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- BEGIN
void PnlWzskPrfAcqTrace::getPref(
			JobWzskAcqTrace::Stg*& _stgjobwzskacqtrace
		) {
	if (!(statshr.Txf1Clean && statshr.Txf2Clean && statshr.Txf3Clean && statshr.Txf4Clean)) {
		_stgjobwzskacqtrace = &stgjobwzskacqtrace;
		stgjobwzskacqtrace.row0 = atoi(contiac.Txf1.c_str());
		stgjobwzskacqtrace.col0 = atoi(contiac.Txf2.c_str());
		stgjobwzskacqtrace.w = atoi(contiac.Txf3.c_str());
		stgjobwzskacqtrace.h = atoi(contiac.Txf4.c_str());
	};

};

void PnlWzskPrfAcqTrace::setPref(
			DbsWzsk* dbswzsk
			, const bool _refresh
		) {
	set<uint> moditems;

	contiac.Txf1 = to_string(JobWzskAcqTrace::stg.row0);
	contiac.Txf2 = to_string(JobWzskAcqTrace::stg.col0);
	contiac.Txf3 = to_string(JobWzskAcqTrace::stg.w);
	contiac.Txf4 = to_string(JobWzskAcqTrace::stg.h);

	if (_refresh) {
		refresh(dbswzsk, moditems);
		insert(moditems, DpchEngData::CONTIAC);
		xchg->submitDpch(getNewDpchEng(moditems));
	};
};
// IP cust --- END

DpchEngWzsk* PnlWzskPrfAcqTrace::getNewDpchEng(
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

void PnlWzskPrfAcqTrace::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- BEGIN
	// statshr
	statshr.Txf1Clean = (contiac.Txf1 == to_string(JobWzskAcqTrace::stg.row0));
	statshr.Txf2Clean = (contiac.Txf2 == to_string(JobWzskAcqTrace::stg.col0));
	statshr.Txf3Clean = (contiac.Txf3 == to_string(JobWzskAcqTrace::stg.w));
	statshr.Txf4Clean = (contiac.Txf4 == to_string(JobWzskAcqTrace::stg.h));

	// IP refresh --- END

	muteRefresh = false;
};

void PnlWzskPrfAcqTrace::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFACQTRACEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRFACQTRACEDO) {
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

void PnlWzskPrfAcqTrace::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskPrfAcqTrace::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- BEGIN
	if (has(diffitems, ContIac::TXF1)) contiac.Txf1 = _contiac->Txf1;
	if (has(diffitems, ContIac::TXF2)) contiac.Txf2 = _contiac->Txf2;
	if (has(diffitems, ContIac::TXF3)) contiac.Txf3 = _contiac->Txf3;
	if (has(diffitems, ContIac::TXF4)) contiac.Txf4 = _contiac->Txf4;

	if (!diffitems.empty()) refresh(dbswzsk, moditems);
	// IP handleDpchAppDataContiac --- END
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskPrfAcqTrace::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskPrfAcqTrace::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};
