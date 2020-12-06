/**
	* \file PnlWzskObjRef1NFile.cpp
	* job handler for job PnlWzskObjRef1NFile (implementation)
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

#include "PnlWzskObjRef1NFile.h"

#include "PnlWzskObjRef1NFile_blks.cpp"
#include "PnlWzskObjRef1NFile_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskObjRef1NFile
 ******************************************************************************/

PnlWzskObjRef1NFile::PnlWzskObjRef1NFile(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKOBJREF1NFILE, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecWzskVQrystate::MNR, "ong", VecWzskVQrystate::getTitle(VecWzskVQrystate::MNR, ixWzskVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzskVQrystate::OOD, "red", VecWzskVQrystate::getTitle(VecWzskVQrystate::OOD, ixWzskVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzskVQrystate::SLM, "yel", VecWzskVQrystate::getTitle(VecWzskVQrystate::SLM, ixWzskVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzskVQrystate::UTD, "grn", VecWzskVQrystate::getTitle(VecWzskVQrystate::UTD, ixWzskVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref, 0);

	qry = new QryWzskObjRef1NFile(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskObjRef1NFile::~PnlWzskObjRef1NFile() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskObjRef1NFile::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlWzskObjRef1NFile::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixWzskVQrystate);

	// statshr
	statshr.ButViewAvail = evalButViewAvail(dbswzsk);
	statshr.ButViewActive = evalButViewActive(dbswzsk);
	statshr.ButNewAvail = evalButNewAvail(dbswzsk);
	statshr.ButDeleteAvail = evalButDeleteAvail(dbswzsk);
	statshr.ButDeleteActive = evalButDeleteActive(dbswzsk);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskObjRef1NFile::updatePreset(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFOBJ) {
		recFil = WzskMFile();

		xchg->addRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref, 0);

		qry->stgiac.jnumFirstload = 1;

		qry->rerun(dbswzsk);
		refresh(dbswzsk, moditems);

		if (notif) {
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			xchg->submitDpch(getNewDpchEng(moditems));
		};
	};
	// IP updatePreset --- END
};

void PnlWzskObjRef1NFile::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJREF1NFILEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswzsk, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswzsk, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJREF1NFILEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskObjRef1NFile::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskObjRef1NFile::handleDpchAppDataStgiac(
			DbsWzsk* dbswzsk
			, StgIac* _stgiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiac->diff(&stgiac);
	// IP handleDpchAppDataStgiac --- INSERT
	insert(moditems, DpchEngData::STGIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskObjRef1NFile::handleDpchAppDataStgiacqry(
			DbsWzsk* dbswzsk
			, QryWzskObjRef1NFile::StgIac* _stgiacqry
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	WzskQObjRef1NFile* recSelNew = NULL;

	WzskMFile* _recFil = NULL;

	if (!diffitems.empty()) {
		muteRefresh = true;

		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWzskObjRef1NFile::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWzskObjRef1NFile::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswzsk);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWzskObjRef1NFile::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recFil = WzskMFile();

			if (recSelNew) {
				if (dbswzsk->tblwzskmfile->loadRecByRef(recSelNew->ref, &_recFil)) {
					recFil = *_recFil;
					delete _recFil;
				};
			};

			xchg->addRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));
			qry->refreshJnum();
		};

		refresh(dbswzsk, moditems, true);
	};

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskObjRef1NFile::handleDpchAppDoButViewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refObj = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref)) if (refObj != 0) {
			sref = "CrdWzskFil";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, VecWzskVPreset::PREWZSKREFOBJ, refObj, sref, recFil.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
};

void PnlWzskObjRef1NFile::handleDpchAppDoButNewClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refObj = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);

	if (statshr.ButNewAvail) {
		if ((xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) & VecWzskWAccess::EDIT) != 0) if (refObj != 0) {
			sref = "CrdWzskFil";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzsk, VecWzskVCall::CALLWZSKCRDOPEN, jref, VecWzskVPreset::PREWZSKREFOBJ, refObj, sref, -1, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzskConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzskConfirm(true, jrefNew, sref);
	};
};

void PnlWzskObjRef1NFile::handleDpchAppDoButDeleteClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlWzskObjRef1NFile::handleDpchAppDoButRefreshClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->rerun(dbswzsk, false);

	refresh(dbswzsk, moditems, true);

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskObjRef1NFile::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSTATCHG) {
		call->abort = handleCallWzskStatChg(dbswzsk, call->jref);
	};
};

bool PnlWzskObjRef1NFile::handleCallWzskStatChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskStatChg --- BEGIN

	set<uint> moditems;

	if (jrefTrig == qry->jref) {
		if (!muteRefresh) {
			refresh(dbswzsk, moditems);
			if (qry->ixWzskVQrystate == VecWzskVQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
		};
	};

	// IP handleCallWzskStatChg --- END
	return retval;
};
