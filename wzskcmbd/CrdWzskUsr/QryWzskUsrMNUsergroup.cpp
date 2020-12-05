/**
	* \file QryWzskUsrMNUsergroup.cpp
	* job handler for job QryWzskUsrMNUsergroup (implementation)
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

#include "QryWzskUsrMNUsergroup.h"

#include "QryWzskUsrMNUsergroup_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskUsrMNUsergroup
 ******************************************************************************/

QryWzskUsrMNUsergroup::QryWzskUsrMNUsergroup(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKUSRMNUSERGROUP, jrefSup, ixWzskVLocale)
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

QryWzskUsrMNUsergroup::~QryWzskUsrMNUsergroup() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskUsrMNUsergroup::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzskUsrMNUsergroup::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFUSR, jref);

	xchg->removeClstns(VecWzskVCall::CALLWZSKUSRRUSGMOD_USREQ, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqusrmnusergroup->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzskRMUserMUsergroup.ref)";
	sqlstr += " FROM TblWzskMUsergroup, TblWzskRMUserMUsergroup";
	sqlstr += " WHERE TblWzskRMUserMUsergroup.refWzskMUsergroup = TblWzskMUsergroup.ref";
	sqlstr += " AND TblWzskRMUserMUsergroup.refWzskMUser = " + to_string(preRefUsr) + "";
	dbswzsk->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzskQUsrMNUsergroup(jref, jnum, mref, ref, ixWzskVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskMUsergroup.ref, TblWzskRMUserMUsergroup.ref, TblWzskRMUserMUsergroup.ixWzskVUserlevel";
	sqlstr += " FROM TblWzskMUsergroup, TblWzskRMUserMUsergroup";
	sqlstr += " WHERE TblWzskRMUserMUsergroup.refWzskMUsergroup = TblWzskMUsergroup.ref";
	sqlstr += " AND TblWzskRMUserMUsergroup.refWzskMUser = " + to_string(preRefUsr) + "";
	sqlstr += " ORDER BY TblWzskMUsergroup.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzsk->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzskQUsrMNUsergroup SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

	xchg->addRefClstn(VecWzskVCall::CALLWZSKUSRRUSGMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsr);
};

void QryWzskUsrMNUsergroup::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQUsrMNUsergroup* rec = NULL;

	dbswzsk->tblwzskqusrmnusergroup->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWzsk::getStubUsgStd(dbswzsk, rec->mref, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxWzskVUserlevel = VecWzskVUserlevel::getSref(rec->ixWzskVUserlevel);
			rec->titIxWzskVUserlevel = VecWzskVUserlevel::getTitle(rec->ixWzskVUserlevel, ixWzskVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskUsrMNUsergroup", "fetch");
	};

	refreshJnum();
};

uint QryWzskUsrMNUsergroup::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQUsrMNUsergroup* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskUsrMNUsergroup::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQUsrMNUsergroup* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQUsrMNUsergroup* QryWzskUsrMNUsergroup::getRecByJnum(
			const uint jnum
		) {
	WzskQUsrMNUsergroup* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskUsrMNUsergroup::handleRequest(
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

bool QryWzskUsrMNUsergroup::handleRerun(
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

bool QryWzskUsrMNUsergroup::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQUsrMNUsergroup* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
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
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixWzskVUserlevel;
		cout << "\t" << rec->srefIxWzskVUserlevel;
		cout << "\t" << rec->titIxWzskVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryWzskUsrMNUsergroup::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKUSRRUSGMOD_USREQ) {
		call->abort = handleCallWzskUsrRusgMod_usrEq(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskUsrMNUsergroup::handleCallWzskUsrRusgMod_usrEq(
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

bool QryWzskUsrMNUsergroup::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

