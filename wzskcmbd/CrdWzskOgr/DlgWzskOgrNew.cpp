/**
	* \file DlgWzskOgrNew.cpp
	* job handler for job DlgWzskOgrNew (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "DlgWzskOgrNew.h"

#include "DlgWzskOgrNew_blks.cpp"
#include "DlgWzskOgrNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWzskOgrNew
 ******************************************************************************/

DlgWzskOgrNew::DlgWzskOgrNew(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::DLGWZSKOGRNEW, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupLcl.tag = "FeedFPupLcl";
	VecWzskVLocale::fillFeed(ixWzskVLocale, feedFPupLcl);
	feedFPupSup.tag = "FeedFPupSup";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	vector<ubigint> refs;

	// existing object groups
	dbswzsk->loadRefsBySQL("SELECT ref FROM TblWzskMObjgroup ORDER BY supRefWzskMObjgroup ASC, sref ASC", false, refs);
	feedFPupSup.appendRefTitles(0, StubWzsk::getStubOgrStd(dbswzsk, 0, ixWzskVLocale, Stub::VecVNonetype::FULL));
	for (unsigned int i = 0; i < refs.size(); i++) feedFPupSup.appendRefTitles(refs[i], StubWzsk::getStubOgrStd(dbswzsk, refs[i], ixWzskVLocale));
	// IP constructor.cust1 --- IEND

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWzskOgrNew::~DlgWzskOgrNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* DlgWzskOgrNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupLcl, &feedFPupSup, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWzskOgrNew::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButCncActive = evalButCncActive(dbswzsk);
	statshr.ButCreActive = evalButCreActive(dbswzsk);

	// contiac

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void DlgWzskOgrNew::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKOGRNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKOGRNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void DlgWzskOgrNew::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWzskOgrNew::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	if (has(diffitems, ContIac::NUMFPUPSUP)) {
		if (feedFPupSup.getRefByNum(_contiac->numFPupSup) != 0) contiac.numFPupSup = _contiac->numFPupSup;
		else contiac.numFPupSup = 0;
	};

	if (has(diffitems, ContIac::TXFSRF)) contiac.TxfSrf = _contiac->TxfSrf;

	if (has(diffitems, ContIac::NUMFPUPLCL)) {
		if (feedFPupLcl.getIxByNum(_contiac->numFPupLcl) != 0) contiac.numFPupLcl = _contiac->numFPupLcl;
		else contiac.numFPupLcl = 0;
	};

	if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
	if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;

	valid = (contiac.TxfSrf.length() >= 3) && (contiac.numFPupLcl != 0) && (contiac.TxfTit.length() >= 5);

	refresh(dbswzsk, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWzskOgrNew::handleDpchAppDoButCncClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButCncClick --- IBEGIN
	if (statshr.ButCncActive) {
		*dpcheng = new DpchEngWzskConfirm(true, jref, "");
		xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButCncClick --- IEND
};

void DlgWzskOgrNew::handleDpchAppDoButCreClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		changeStage(dbswzsk, VecVSge::CREATE, dpcheng);

		if (ixVSge == VecVSge::DONE) {
			*dpcheng = new DpchEngWzskConfirm(true, jref, "");
			xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKDLGCLOSE, jref);
		};
	};
	// IP handleDpchAppDoButCreClick --- REND
};

void DlgWzskOgrNew::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
			, DpchEngWzsk** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswzsk); break;
				case VecVSge::DONE: leaveSgeDone(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswzsk, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswzsk, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWzskOgrNew::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint DlgWzskOgrNew::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWzskOgrNew::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWzskOgrNew::enterSgeCreate(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN
	WzskMObjgroup ogr;
	WzskJMObjgroupTitle* ogrJtit = NULL;

	ogr.supRefWzskMObjgroup = feedFPupSup.getRefByNum(contiac.numFPupSup);
	ogr.sref = contiac.TxfSrf;

	ogr.refJTitle = dbswzsk->tblwzskjmobjgrouptitle->insertNewRec(&ogrJtit, 0, feedFPupLcl.getIxByNum(contiac.numFPupLcl), contiac.TxfTit);
	ogr.Title = contiac.TxfTit;

	ogr.Comment = contiac.TxfCmt;

	dbswzsk->tblwzskmobjgroup->insertRec(&ogr);

	ogrJtit->refWzskMObjgroup = ogr.ref;
	dbswzsk->tblwzskjmobjgrouptitle->updateRec(ogrJtit);

	xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKOGRMOD, jref);
	xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKREFPRESET, jref, VecWzskVPreset::PREWZSKREFOGR, ogr.ref);
	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWzskOgrNew::leaveSgeCreate(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWzskOgrNew::enterSgeDone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWzskOgrNew::leaveSgeDone(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeDone --- INSERT
};



