/**
	* \file QryWzskUsrList.cpp
	* job handler for job QryWzskUsrList (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "QryWzskUsrList.h"

#include "QryWzskUsrList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskUsrList
 ******************************************************************************/

QryWzskUsrList::QryWzskUsrList(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKUSRLIST, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzskVQrystate = VecWzskVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzsk);

	xchg->addClstn(VecWzskVCall::CALLWZSKUSRMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzskUsrList::~QryWzskUsrList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskUsrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKUSRUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKUSRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzskUsrList::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWzskVPreset::PREWZSKUSRLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWzskVPreset::PREWZSKUSRLIST_OWN, jref);
	ubigint prePrs = xchg->getRefPreset(VecWzskVPreset::PREWZSKUSRLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecWzskVPreset::PREWZSKUSRLIST_SRF, jref);
	ubigint preUsg = xchg->getRefPreset(VecWzskVPreset::PREWZSKUSRLIST_USG, jref);
	uint preSte = xchg->getIxPreset(VecWzskVPreset::PREWZSKUSRLIST_STE, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqusrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzskMUser.ref)";
	sqlstr += " FROM TblWzskMUser, TblWzskQSelect";
	sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWzskMUser.grp = TblWzskQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, preSte, false);
	dbswzsk->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzskQUsrList(jref, jnum, ref, grp, own, refWzskMPerson, sref, refWzskMUsergroup, ixVState, ixWzskVLocale, ixWzskVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskMUser.ref, TblWzskMUser.grp, TblWzskMUser.own, TblWzskMUser.refWzskMPerson, TblWzskMUser.sref, TblWzskMUser.refWzskMUsergroup, TblWzskMUser.ixVState, TblWzskMUser.ixWzskVLocale, TblWzskMUser.ixWzskVUserlevel";
	sqlstr += " FROM TblWzskMUser, TblWzskQSelect";
	sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWzskMUser.grp = TblWzskQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, preSte, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzsk->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzskQUsrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

};

void QryWzskUsrList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preUsg
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMUser.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMUser.own = " + to_string(preOwn) + "";
	};

	if (prePrs != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMUser.refWzskMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMUser.sref = '" + preSrf + "'";
	};

	if (preUsg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMUser.refWzskMUsergroup = " + to_string(preUsg) + "";
	};

	if (preSte != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMUser.ixVState = " + to_string(preSte) + "";
	};
};

void QryWzskUsrList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzskUsrList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblWzskMUser.ixVState ASC";
	else if (preIxOrd == VecVOrd::USG) sqlstr += " ORDER BY TblWzskMUser.refWzskMUsergroup ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWzskMUser.sref ASC";
	else if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblWzskMUser.refWzskMPerson ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWzskMUser.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWzskMUser.grp ASC";
};

void QryWzskUsrList::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQUsrList* rec = NULL;

	dbswzsk->tblwzskqusrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubWzsk::getStubGroup(dbswzsk, rec->grp, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubWzsk::getStubOwner(dbswzsk, rec->own, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWzskMPerson = StubWzsk::getStubPrsStd(dbswzsk, rec->refWzskMPerson, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWzskMUsergroup = StubWzsk::getStubUsgStd(dbswzsk, rec->refWzskMUsergroup, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecWzskVMUserState::getSref(rec->ixVState);
			rec->titIxVState = VecWzskVMUserState::getTitle(rec->ixVState, ixWzskVLocale);
			rec->srefIxWzskVLocale = VecWzskVLocale::getSref(rec->ixWzskVLocale);
			rec->titIxWzskVLocale = VecWzskVLocale::getTitle(rec->ixWzskVLocale, ixWzskVLocale);
			rec->srefIxWzskVUserlevel = VecWzskVUserlevel::getSref(rec->ixWzskVUserlevel);
			rec->titIxWzskVUserlevel = VecWzskVUserlevel::getTitle(rec->ixWzskVUserlevel, ixWzskVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskUsrList", "fetch");
	};

	refreshJnum();
};

uint QryWzskUsrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskUsrList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQUsrList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQUsrList* QryWzskUsrList::getRecByJnum(
			const uint jnum
		) {
	WzskQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskUsrList::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\trerun" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "rerun") {
			req->retain = handleRerun(dbswzsk);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbswzsk);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool QryWzskUsrList::handleRerun(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	rerun(dbswzsk);
	return retval;
};

bool QryWzskUsrList::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQUsrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\trefWzskMPerson";
	cout << "\tstubRefWzskMPerson";
	cout << "\tsref";
	cout << "\trefWzskMUsergroup";
	cout << "\tstubRefWzskMUsergroup";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixWzskVLocale";
	cout << "\tsrefIxWzskVLocale";
	cout << "\ttitIxWzskVLocale";
	cout << "\tixWzskVUserlevel";
	cout << "\tsrefIxWzskVUserlevel";
	cout << "\ttitIxWzskVUserlevel";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->grp;
		cout << "\t" << rec->stubGrp;
		cout << "\t" << rec->own;
		cout << "\t" << rec->stubOwn;
		cout << "\t" << rec->refWzskMPerson;
		cout << "\t" << rec->stubRefWzskMPerson;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refWzskMUsergroup;
		cout << "\t" << rec->stubRefWzskMUsergroup;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixWzskVLocale;
		cout << "\t" << rec->srefIxWzskVLocale;
		cout << "\t" << rec->titIxWzskVLocale;
		cout << "\t" << rec->ixWzskVUserlevel;
		cout << "\t" << rec->srefIxWzskVUserlevel;
		cout << "\t" << rec->titIxWzskVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryWzskUsrList::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKUSRUPD_REFEQ) {
		call->abort = handleCallWzskUsrUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKUSRMOD) {
		call->abort = handleCallWzskUsrMod(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskUsrList::handleCallWzskUsrUpd_refEq(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixWzskVQrystate != VecWzskVQrystate::OOD) {
		ixWzskVQrystate = VecWzskVQrystate::OOD;
		xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);
	};

	return retval;
};

bool QryWzskUsrList::handleCallWzskUsrMod(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixWzskVQrystate == VecWzskVQrystate::UTD) || (ixWzskVQrystate == VecWzskVQrystate::SLM)) {
		ixWzskVQrystate = VecWzskVQrystate::MNR;
		xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);
	};

	return retval;
};

bool QryWzskUsrList::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

