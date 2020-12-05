/**
	* \file DlgWzskObjNew.cpp
	* job handler for job DlgWzskObjNew (implementation)
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

#include "DlgWzskObjNew.h"

#include "DlgWzskObjNew_blks.cpp"
#include "DlgWzskObjNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWzskObjNew
 ******************************************************************************/

DlgWzskObjNew::DlgWzskObjNew(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::DLGWZSKOBJNEW, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupOgr.tag = "FeedFPupOgr";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	vector<ubigint> refs;

	// object groups
	dbswzsk->loadRefsBySQL("SELECT ref FROM TblWzskMObjgroup ORDER BY supRefWzskMObjgroup ASC, sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) feedFPupOgr.appendRefTitles(refs[i], StubWzsk::getStubOgrStd(dbswzsk, refs[i], ixWzskVLocale));
	// IP constructor.cust1 --- IEND

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWzskObjNew::~DlgWzskObjNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* DlgWzskObjNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupOgr, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWzskObjNew::refresh(
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

void DlgWzskObjNew::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKOBJNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKOBJNEWDO) {
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

void DlgWzskObjNew::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWzskObjNew::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	if (has(diffitems, ContIac::NUMFPUPOGR)) {
		if (feedFPupOgr.getRefByNum(_contiac->numFPupOgr) != 0) contiac.numFPupOgr = _contiac->numFPupOgr;
		else contiac.numFPupOgr = 0;
	};

	if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
	if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;

	valid = (contiac.numFPupOgr != 0) && (contiac.TxfTit.length() >= 5);

	refresh(dbswzsk, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWzskObjNew::handleDpchAppDoButCncClick(
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

void DlgWzskObjNew::handleDpchAppDoButCreClick(
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

void DlgWzskObjNew::changeStage(
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

string DlgWzskObjNew::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint DlgWzskObjNew::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWzskObjNew::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWzskObjNew::enterSgeCreate(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN
	WzskMObject obj;

	obj.refWzskMObjgroup = feedFPupOgr.getRefByNum(contiac.numFPupOgr);
	obj.Title = contiac.TxfTit;
	obj.Comment = contiac.TxfCmt;

	dbswzsk->tblwzskmobject->insertRec(&obj);

	xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKOBJMOD, jref);
	xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKREFPRESET, jref, VecWzskVPreset::PREWZSKREFOBJ, obj.ref);
	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWzskObjNew::leaveSgeCreate(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWzskObjNew::enterSgeDone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWzskObjNew::leaveSgeDone(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeDone --- INSERT
};







