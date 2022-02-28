/**
	* \file QryWzskUsgAAccess.cpp
	* job handler for job QryWzskUsgAAccess (implementation)
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

#include "QryWzskUsgAAccess.h"

#include "QryWzskUsgAAccess_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskUsgAAccess
 ******************************************************************************/

QryWzskUsgAAccess::QryWzskUsgAAccess(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKUSGAACCESS, jrefSup, ixWzskVLocale)
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

QryWzskUsgAAccess::~QryWzskUsgAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskUsgAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzskUsgAAccess::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFUSG, jref);
	uint preX1 = xchg->getIxPreset(VecWzskVPreset::PREWZSKUSGAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWzskVPreset::PREWZSKUSGAACCESS_X2, jref);

	xchg->removeClstns(VecWzskVCall::CALLWZSKUSGAACCMOD_USGEQ, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqusgaaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzskAMUsergroupAccess.ref)";
	sqlstr += " FROM TblWzskAMUsergroupAccess";
	sqlstr += " WHERE TblWzskAMUsergroupAccess.refWzskMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswzsk->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzskQUsgAAccess(jref, jnum, ref, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskAMUsergroupAccess.ref, TblWzskAMUsergroupAccess.x1IxWzskVFeatgroup, TblWzskAMUsergroupAccess.x2FeaSrefUix, TblWzskAMUsergroupAccess.ixWzskWAccess";
	sqlstr += " FROM TblWzskAMUsergroupAccess";
	sqlstr += " WHERE TblWzskAMUsergroupAccess.refWzskMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzsk->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzskQUsgAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

	xchg->addRefClstn(VecWzskVCall::CALLWZSKUSGAACCMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsg);
};

void QryWzskUsgAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskAMUsergroupAccess.x1IxWzskVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskAMUsergroupAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryWzskUsgAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzskUsgAAccess::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQUsgAAccess* rec = NULL;

	dbswzsk->tblwzskqusgaaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxWzskVFeatgroup = VecWzskVFeatgroup::getSref(rec->x1IxWzskVFeatgroup);
			rec->titX1IxWzskVFeatgroup = VecWzskVFeatgroup::getTitle(rec->x1IxWzskVFeatgroup, ixWzskVLocale);
			rec->srefsIxWzskWAccess = VecWzskWAccess::getSrefs(rec->ixWzskWAccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskUsgAAccess", "fetch");
	};

	refreshJnum();
};

uint QryWzskUsgAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQUsgAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskUsgAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQUsgAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQUsgAAccess* QryWzskUsgAAccess::getRecByJnum(
			const uint jnum
		) {
	WzskQUsgAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskUsgAAccess::handleRequest(
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

bool QryWzskUsgAAccess::handleRerun(
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

bool QryWzskUsgAAccess::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQUsgAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxWzskVFeatgroup";
	cout << "\tsrefX1IxWzskVFeatgroup";
	cout << "\ttitX1IxWzskVFeatgroup";
	cout << "\tx2FeaSrefUix";
	cout << "\tixWzskWAccess";
	cout << "\tsrefsIxWzskWAccess";
	cout << "\ttitsIxWzskWAccess";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxWzskVFeatgroup;
		cout << "\t" << rec->srefX1IxWzskVFeatgroup;
		cout << "\t" << rec->titX1IxWzskVFeatgroup;
		cout << "\t" << rec->x2FeaSrefUix;
		cout << "\t" << rec->ixWzskWAccess;
		cout << "\t" << rec->srefsIxWzskWAccess;
		cout << "\t" << rec->titsIxWzskWAccess;
		cout << endl;
	};
	return retval;
};

void QryWzskUsgAAccess::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKUSGAACCMOD_USGEQ) {
		call->abort = handleCallWzskUsgAaccMod_usgEq(dbswzsk, call->jref);
	};
};

bool QryWzskUsgAAccess::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

bool QryWzskUsgAAccess::handleCallWzskUsgAaccMod_usgEq(
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
