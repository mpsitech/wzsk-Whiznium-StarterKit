/**
	* \file QryWzskShtList.cpp
	* job handler for job QryWzskShtList (implementation)
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

#include "QryWzskShtList.h"

#include "QryWzskShtList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskShtList
 ******************************************************************************/

QryWzskShtList::QryWzskShtList(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKSHTLIST, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzskVQrystate = VecWzskVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzsk);

	xchg->addClstn(VecWzskVCall::CALLWZSKSHTMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzskShtList::~QryWzskShtList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskShtList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKSHTUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKSHTUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzskShtList::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXORD, jref);
	ubigint preRefObj = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);
	ubigint preSes = xchg->getRefPreset(VecWzskVPreset::PREWZSKSHTLIST_SES, jref);
	ubigint preObj = xchg->getRefPreset(VecWzskVPreset::PREWZSKSHTLIST_OBJ, jref);
	int preSta = xchg->getIntvalPreset(VecWzskVPreset::PREWZSKSHTLIST_STA, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqshtlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWzskVPreset::PREWZSKREFOBJ) {
		sqlstr = "SELECT COUNT(TblWzskMShot.ref)";
		sqlstr += " FROM TblWzskMShot";
		sqlstr += " WHERE TblWzskMShot.refWzskMObject = " + to_string(preRefObj) + "";
		rerun_filtSQL(sqlstr, preSes, preObj, preSta, false);
		dbswzsk->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWzskMShot.ref)";
		sqlstr += " FROM TblWzskMShot";
		rerun_filtSQL(sqlstr, preSes, preObj, preSta, true);
		dbswzsk->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i = 0; i < cnts.size(); i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecWzskVPreset::PREWZSKREFOBJ) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWzskMShot";
		sqlstr += " WHERE TblWzskMShot.refWzskMObject = " + to_string(preRefObj) + "";
		rerun_filtSQL(sqlstr, preSes, preObj, preSta, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswzsk->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWzskMShot";
		rerun_filtSQL(sqlstr, preSes, preObj, preSta, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswzsk->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWzskQShtList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

};

void QryWzskShtList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWzskQShtList(jref, jnum, ref, refWzskMSession, refWzskMObject, start)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskMShot.ref, TblWzskMShot.refWzskMSession, TblWzskMShot.refWzskMObject, TblWzskMShot.start";
};

void QryWzskShtList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preSes
			, const ubigint preObj
			, const int preSta
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSes != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMShot.refWzskMSession = " + to_string(preSes) + "";
	};

	if (preObj != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMShot.refWzskMObject = " + to_string(preObj) + "";
	};

	if (preSta != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMShot.start = " + to_string(preSta) + "";
	};
};

void QryWzskShtList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzskShtList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblWzskMShot.start ASC";
	else if (preIxOrd == VecVOrd::OBJ) sqlstr += " ORDER BY TblWzskMShot.refWzskMObject ASC";
	else if (preIxOrd == VecVOrd::SES) sqlstr += " ORDER BY TblWzskMShot.refWzskMSession ASC";
};

void QryWzskShtList::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQShtList* rec = NULL;

	dbswzsk->tblwzskqshtlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWzskMSession = StubWzsk::getStubSesStd(dbswzsk, rec->refWzskMSession, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWzskMObject = StubWzsk::getStubObjStd(dbswzsk, rec->refWzskMObject, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmStart = Ftm::stamp(rec->start);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskShtList", "fetch");
	};

	refreshJnum();
};

uint QryWzskShtList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQShtList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskShtList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQShtList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQShtList* QryWzskShtList::getRecByJnum(
			const uint jnum
		) {
	WzskQShtList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskShtList::handleRequest(
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

bool QryWzskShtList::handleRerun(
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

bool QryWzskShtList::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQShtList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefWzskMSession";
	cout << "\tstubRefWzskMSession";
	cout << "\trefWzskMObject";
	cout << "\tstubRefWzskMObject";
	cout << "\tstart";
	cout << "\tftmStart";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refWzskMSession;
		cout << "\t" << rec->stubRefWzskMSession;
		cout << "\t" << rec->refWzskMObject;
		cout << "\t" << rec->stubRefWzskMObject;
		cout << "\t" << rec->start;
		cout << "\t" << rec->ftmStart;
		cout << endl;
	};
	return retval;
};

void QryWzskShtList::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSHTUPD_REFEQ) {
		call->abort = handleCallWzskShtUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSHTMOD) {
		call->abort = handleCallWzskShtMod(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskShtList::handleCallWzskShtUpd_refEq(
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

bool QryWzskShtList::handleCallWzskShtMod(
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

bool QryWzskShtList::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};
