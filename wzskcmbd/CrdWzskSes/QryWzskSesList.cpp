/**
	* \file QryWzskSesList.cpp
	* job handler for job QryWzskSesList (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "QryWzskSesList.h"

#include "QryWzskSesList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskSesList
 ******************************************************************************/

QryWzskSesList::QryWzskSesList(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKSESLIST, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzskVQrystate = VecWzskVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzsk);

	xchg->addClstn(VecWzskVCall::CALLWZSKSESMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzskSesList::~QryWzskSesList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskSesList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKSESUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKSESUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzskSesList::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXORD, jref);
	ubigint preUsr = xchg->getRefPreset(VecWzskVPreset::PREWZSKSESLIST_USR, jref);
	int preSta = xchg->getIntvalPreset(VecWzskVPreset::PREWZSKSESLIST_STA, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqseslist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzskMSession.ref)";
	sqlstr += " FROM TblWzskMSession";
	rerun_filtSQL(sqlstr, preUsr, preSta, true);
	dbswzsk->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzskQSesList(jref, jnum, ref, refWzskMUser, start, stop, Ip)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskMSession.ref, TblWzskMSession.refWzskMUser, TblWzskMSession.start, TblWzskMSession.stop, TblWzskMSession.Ip";
	sqlstr += " FROM TblWzskMSession";
	rerun_filtSQL(sqlstr, preUsr, preSta, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzsk->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzskQSesList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

};

void QryWzskSesList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preUsr
			, const int preSta
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preUsr != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMSession.refWzskMUser = " + to_string(preUsr) + "";
	};

	if (preSta != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMSession.start = " + to_string(preSta) + "";
	};
};

void QryWzskSesList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzskSesList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblWzskMSession.start ASC";
	else if (preIxOrd == VecVOrd::USR) sqlstr += " ORDER BY TblWzskMSession.refWzskMUser ASC";
};

void QryWzskSesList::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQSesList* rec = NULL;

	dbswzsk->tblwzskqseslist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWzskMUser = StubWzsk::getStubUsrStd(dbswzsk, rec->refWzskMUser, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmStart = Ftm::stamp(rec->start);
			rec->ftmStop = Ftm::stamp(rec->stop);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskSesList", "fetch");
	};

	refreshJnum();
};

uint QryWzskSesList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQSesList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskSesList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQSesList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQSesList* QryWzskSesList::getRecByJnum(
			const uint jnum
		) {
	WzskQSesList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskSesList::handleRequest(
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

bool QryWzskSesList::handleRerun(
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

bool QryWzskSesList::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQSesList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefWzskMUser";
	cout << "\tstubRefWzskMUser";
	cout << "\tstart";
	cout << "\tftmStart";
	cout << "\tstop";
	cout << "\tftmStop";
	cout << "\tIp";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refWzskMUser;
		cout << "\t" << rec->stubRefWzskMUser;
		cout << "\t" << rec->start;
		cout << "\t" << rec->ftmStart;
		cout << "\t" << rec->stop;
		cout << "\t" << rec->ftmStop;
		cout << "\t" << rec->Ip;
		cout << endl;
	};
	return retval;
};

void QryWzskSesList::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSESUPD_REFEQ) {
		call->abort = handleCallWzskSesUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSESMOD) {
		call->abort = handleCallWzskSesMod(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskSesList::handleCallWzskSesUpd_refEq(
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

bool QryWzskSesList::handleCallWzskSesMod(
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

bool QryWzskSesList::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

