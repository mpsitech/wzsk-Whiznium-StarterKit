/**
	* \file QryWzskObjRef1NFile.cpp
	* job handler for job QryWzskObjRef1NFile (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "QryWzskObjRef1NFile.h"

#include "QryWzskObjRef1NFile_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskObjRef1NFile
 ******************************************************************************/

QryWzskObjRef1NFile::QryWzskObjRef1NFile(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKOBJREF1NFILE, jrefSup, ixWzskVLocale)
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

QryWzskObjRef1NFile::~QryWzskObjRef1NFile() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskObjRef1NFile::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzskObjRef1NFile::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefObj = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);

	xchg->removeClstns(VecWzskVCall::CALLWZSKFILMOD_RETREUEQ, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqobjref1nfile->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzskMFile.ref)";
	sqlstr += " FROM TblWzskMFile";
	sqlstr += " WHERE TblWzskMFile.refIxVTbl = " + to_string(VecWzskVMFileRefTbl::OBJ);
	sqlstr += " AND TblWzskMFile.refUref = " + to_string(preRefObj) + "";
	dbswzsk->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzskQObjRef1NFile(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskMFile.ref";
	sqlstr += " FROM TblWzskMFile";
	sqlstr += " WHERE TblWzskMFile.refIxVTbl = " + to_string(VecWzskVMFileRefTbl::OBJ);
	sqlstr += " AND TblWzskMFile.refUref = " + to_string(preRefObj) + "";
	sqlstr += " ORDER BY Filename ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzsk->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzskQObjRef1NFile SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

	xchg->addIxRefClstn(VecWzskVCall::CALLWZSKFILMOD_RETREUEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzskVMFileRefTbl::OBJ, preRefObj);
};

void QryWzskObjRef1NFile::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQObjRef1NFile* rec = NULL;

	dbswzsk->tblwzskqobjref1nfile->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWzsk::getStubFilStd(dbswzsk, rec->ref, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskObjRef1NFile", "fetch");
	};

	refreshJnum();
};

uint QryWzskObjRef1NFile::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQObjRef1NFile* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskObjRef1NFile::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQObjRef1NFile* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQObjRef1NFile* QryWzskObjRef1NFile::getRecByJnum(
			const uint jnum
		) {
	WzskQObjRef1NFile* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskObjRef1NFile::handleRequest(
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

bool QryWzskObjRef1NFile::handleRerun(
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

bool QryWzskObjRef1NFile::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQObjRef1NFile* rec = NULL;

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

void QryWzskObjRef1NFile::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKFILMOD_RETREUEQ) {
		call->abort = handleCallWzskFilMod_retReuEq(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskObjRef1NFile::handleCallWzskFilMod_retReuEq(
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

bool QryWzskObjRef1NFile::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

