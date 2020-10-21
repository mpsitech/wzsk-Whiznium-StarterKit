/**
	* \file QryWzskPrsList.cpp
	* job handler for job QryWzskPrsList (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "QryWzskPrsList.h"

#include "QryWzskPrsList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskPrsList
 ******************************************************************************/

QryWzskPrsList::QryWzskPrsList(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKPRSLIST, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzskVQrystate = VecWzskVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzsk);

	xchg->addClstn(VecWzskVCall::CALLWZSKPRSMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzskPrsList::~QryWzskPrsList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskPrsList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKPRSUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKPRSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzskPrsList::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWzskVPreset::PREWZSKPRSLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWzskVPreset::PREWZSKPRSLIST_OWN, jref);
	string preLnm = xchg->getTxtvalPreset(VecWzskVPreset::PREWZSKPRSLIST_LNM, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqprslist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzskMPerson.ref)";
	sqlstr += " FROM TblWzskMPerson, TblWzskQSelect";
	sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWzskMPerson.grp = TblWzskQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMPerson.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preLnm, false);
	dbswzsk->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzskQPrsList(jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskMPerson.ref, TblWzskMPerson.grp, TblWzskMPerson.own, TblWzskMPerson.Title, TblWzskMPerson.Firstname, TblWzskMPerson.Lastname, TblWzskMPerson.ixVSex, TblWzskMPerson.telVal, TblWzskMPerson.emlVal";
	sqlstr += " FROM TblWzskMPerson, TblWzskQSelect";
	sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWzskMPerson.grp = TblWzskQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMPerson.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preLnm, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzsk->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzskQPrsList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

};

void QryWzskPrsList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preLnm
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMPerson.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMPerson.own = " + to_string(preOwn) + "";
	};

	if (preLnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMPerson.Lastname LIKE '" + preLnm + "'";
	};
};

void QryWzskPrsList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzskPrsList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::LNM) sqlstr += " ORDER BY TblWzskMPerson.Lastname ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWzskMPerson.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWzskMPerson.grp ASC";
};

void QryWzskPrsList::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQPrsList* rec = NULL;

	dbswzsk->tblwzskqprslist->loadRstByJref(jref, false, rst);
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
			rec->srefIxVSex = VecWzskVMPersonSex::getSref(rec->ixVSex);
			rec->titIxVSex = VecWzskVMPersonSex::getTitle(rec->ixVSex, ixWzskVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskPrsList", "fetch");
	};

	refreshJnum();
};

uint QryWzskPrsList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQPrsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskPrsList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQPrsList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQPrsList* QryWzskPrsList::getRecByJnum(
			const uint jnum
		) {
	WzskQPrsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskPrsList::handleRequest(
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

bool QryWzskPrsList::handleRerun(
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

bool QryWzskPrsList::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQPrsList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tTitle";
	cout << "\tFirstname";
	cout << "\tLastname";
	cout << "\tixVSex";
	cout << "\tsrefIxVSex";
	cout << "\ttitIxVSex";
	cout << "\ttelVal";
	cout << "\temlVal";
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
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Firstname;
		cout << "\t" << rec->Lastname;
		cout << "\t" << rec->ixVSex;
		cout << "\t" << rec->srefIxVSex;
		cout << "\t" << rec->titIxVSex;
		cout << "\t" << rec->telVal;
		cout << "\t" << rec->emlVal;
		cout << endl;
	};
	return retval;
};

void QryWzskPrsList::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKPRSUPD_REFEQ) {
		call->abort = handleCallWzskPrsUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKPRSMOD) {
		call->abort = handleCallWzskPrsMod(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskPrsList::handleCallWzskPrsUpd_refEq(
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

bool QryWzskPrsList::handleCallWzskPrsMod(
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

bool QryWzskPrsList::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

