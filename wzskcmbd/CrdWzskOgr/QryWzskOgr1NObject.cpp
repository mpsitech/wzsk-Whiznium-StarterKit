/**
	* \file QryWzskOgr1NObject.cpp
	* job handler for job QryWzskOgr1NObject (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "QryWzskOgr1NObject.h"

#include "QryWzskOgr1NObject_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskOgr1NObject
 ******************************************************************************/

QryWzskOgr1NObject::QryWzskOgr1NObject(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKOGR1NOBJECT, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzskVQrystate = VecWzskVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzsk);

	xchg->addClstn(VecWzskVCall::CALLWZSKSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzskOgr1NObject::~QryWzskOgr1NObject() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskOgr1NObject::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzskOgr1NObject::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefOgr = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOGR, jref);

	xchg->removeClstns(VecWzskVCall::CALLWZSKOBJMOD_OGREQ, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqogr1nobject->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzskMObject.ref)";
	sqlstr += " FROM TblWzskMObject";
	sqlstr += " WHERE TblWzskMObject.refWzskMObjgroup = " + to_string(preRefOgr) + "";
	dbswzsk->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzskQOgr1NObject(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskMObject.ref";
	sqlstr += " FROM TblWzskMObject";
	sqlstr += " WHERE TblWzskMObject.refWzskMObjgroup = " + to_string(preRefOgr) + "";
	sqlstr += " ORDER BY Title ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzsk->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzskQOgr1NObject SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

	xchg->addRefClstn(VecWzskVCall::CALLWZSKOBJMOD_OGREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefOgr);
};

void QryWzskOgr1NObject::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQOgr1NObject* rec = NULL;

	dbswzsk->tblwzskqogr1nobject->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWzsk::getStubObjStd(dbswzsk, rec->ref, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskOgr1NObject", "fetch");
	};

	refreshJnum();
};

uint QryWzskOgr1NObject::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQOgr1NObject* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskOgr1NObject::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQOgr1NObject* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQOgr1NObject* QryWzskOgr1NObject::getRecByJnum(
			const uint jnum
		) {
	WzskQOgr1NObject* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskOgr1NObject::handleRequest(
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

bool QryWzskOgr1NObject::handleRerun(
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

bool QryWzskOgr1NObject::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQOgr1NObject* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryWzskOgr1NObject::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKOBJMOD_OGREQ) {
		call->abort = handleCallWzskObjMod_ogrEq(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskOgr1NObject::handleCallWzskObjMod_ogrEq(
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

bool QryWzskOgr1NObject::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

