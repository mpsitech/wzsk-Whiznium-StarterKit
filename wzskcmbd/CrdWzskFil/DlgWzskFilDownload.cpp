/**
	* \file DlgWzskFilDownload.cpp
	* job handler for job DlgWzskFilDownload (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "DlgWzskFilDownload.h"

#include "DlgWzskFilDownload_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWzskFilDownload
 ******************************************************************************/

DlgWzskFilDownload::DlgWzskFilDownload(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::DLGWZSKFILDOWNLOAD, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWzskFilDownload::~DlgWzskFilDownload() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* DlgWzskFilDownload::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, items);
	};

	return dpcheng;
};

void DlgWzskFilDownload::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- RBEGIN
	// continf
	continf.Dld = StubWzsk::getStubFilStd(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKREFFIL, jref));

	// IP refresh --- REND
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void DlgWzskFilDownload::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKFILDOWNLOADDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswzsk, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbswzsk);
	};
};

void DlgWzskFilDownload::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWzskFilDownload::handleDpchAppDoButDneClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	*dpcheng = new DpchEngWzskConfirm(true, jref, "");
	xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKDLGCLOSE, jref);
	// IP handleDpchAppDoButDneClick --- IEND
};

string DlgWzskFilDownload::handleDownload(
			DbsWzsk* dbswzsk
		) {
	// IP handleDownload --- RBEGIN
	string retval;

	retval = Acv::getfile(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKREFFIL, jref));
	if (retval != "") retval = xchg->acvpath + "/" + retval;

	return retval;
	// IP handleDownload --- REND
};



