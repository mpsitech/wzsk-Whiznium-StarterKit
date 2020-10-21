/**
	* \file QryWzskUsrAAccess.cpp
	* job handler for job QryWzskUsrAAccess (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "QryWzskUsrAAccess.h"

#include "QryWzskUsrAAccess_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskUsrAAccess
 ******************************************************************************/

QryWzskUsrAAccess::QryWzskUsrAAccess(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKUSRAACCESS, jrefSup, ixWzskVLocale)
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

QryWzskUsrAAccess::~QryWzskUsrAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskUsrAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzskUsrAAccess::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFUSR, jref);
	uint preX1 = xchg->getIxPreset(VecWzskVPreset::PREWZSKUSRAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWzskVPreset::PREWZSKUSRAACCESS_X2, jref);

	xchg->removeClstns(VecWzskVCall::CALLWZSKUSRAACCMOD_USREQ, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqusraaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzskAMUserAccess.ref)";
	sqlstr += " FROM TblWzskAMUserAccess";
	sqlstr += " WHERE TblWzskAMUserAccess.refWzskMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswzsk->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzskQUsrAAccess(jref, jnum, ref, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskAMUserAccess.ref, TblWzskAMUserAccess.x1IxWzskVFeatgroup, TblWzskAMUserAccess.x2FeaSrefUix, TblWzskAMUserAccess.ixWzskWAccess";
	sqlstr += " FROM TblWzskAMUserAccess";
	sqlstr += " WHERE TblWzskAMUserAccess.refWzskMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzsk->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzskQUsrAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

	xchg->addRefClstn(VecWzskVCall::CALLWZSKUSRAACCMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsr);
};

void QryWzskUsrAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskAMUserAccess.x1IxWzskVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskAMUserAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryWzskUsrAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzskUsrAAccess::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQUsrAAccess* rec = NULL;

	dbswzsk->tblwzskqusraaccess->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryWzskUsrAAccess", "fetch");
	};

	refreshJnum();
};

uint QryWzskUsrAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQUsrAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskUsrAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQUsrAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQUsrAAccess* QryWzskUsrAAccess::getRecByJnum(
			const uint jnum
		) {
	WzskQUsrAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskUsrAAccess::handleRequest(
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

bool QryWzskUsrAAccess::handleRerun(
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

bool QryWzskUsrAAccess::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQUsrAAccess* rec = NULL;

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

void QryWzskUsrAAccess::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKUSRAACCMOD_USREQ) {
		call->abort = handleCallWzskUsrAaccMod_usrEq(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskUsrAAccess::handleCallWzskUsrAaccMod_usrEq(
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

bool QryWzskUsrAAccess::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

