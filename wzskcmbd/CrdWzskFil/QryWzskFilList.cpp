/**
	* \file QryWzskFilList.cpp
	* job handler for job QryWzskFilList (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "QryWzskFilList.h"

#include "QryWzskFilList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzskFilList
 ******************************************************************************/

QryWzskFilList::QryWzskFilList(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::QRYWZSKFILLIST, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzskVQrystate = VecWzskVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzsk);

	xchg->addClstn(VecWzskVCall::CALLWZSKFILMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzskFilList::~QryWzskFilList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzskFilList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzskVCall::CALLWZSKFILUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzskVCall::CALLWZSKFILUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzskFilList::rerun(
			DbsWzsk* dbswzsk
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	bool preNoadm = xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFSESS, jref);
	uint preIxPre = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWzskVPreset::PREWZSKIXORD, jref);
	ubigint preRefObj = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);
	ubigint preGrp = xchg->getRefPreset(VecWzskVPreset::PREWZSKFILLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWzskVPreset::PREWZSKFILLIST_OWN, jref);
	string preFnm = xchg->getTxtvalPreset(VecWzskVPreset::PREWZSKFILLIST_FNM, jref);
	uint preRet = xchg->getIxPreset(VecWzskVPreset::PREWZSKFILLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWzskVPreset::PREWZSKFILLIST_REU, jref);

	dbswzsk->tblwzskqselect->removeRstByJref(jref);
	dbswzsk->tblwzskqfillist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWzskVPreset::PREWZSKREFOBJ) {
		sqlstr = "SELECT COUNT(TblWzskMFile.ref)";
		sqlstr += " FROM TblWzskMFile, TblWzskQSelect";
		sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWzskMFile.grp = TblWzskQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWzskMFile.refIxVTbl = " + to_string(VecWzskVMFileRefTbl::OBJ);
		sqlstr += " AND TblWzskMFile.refUref = " + to_string(preRefObj) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
		dbswzsk->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWzskMFile.ref)";
		sqlstr += " FROM TblWzskMFile, TblWzskQSelect, TblWzskMShot";
		sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWzskMFile.grp = TblWzskQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWzskMFile.refIxVTbl = " + to_string(VecWzskVMFileRefTbl::SHT);
		sqlstr += " AND TblWzskMFile.refUref = TblWzskMShot.ref";
		sqlstr += " AND TblWzskMShot.refWzskMObject = " + to_string(preRefObj) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
		dbswzsk->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWzskMFile.ref)";
		sqlstr += " FROM TblWzskMFile, TblWzskQSelect";
		sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWzskMFile.grp = TblWzskQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
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
		sqlstr += " FROM TblWzskMFile, TblWzskQSelect";
		sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWzskMFile.grp = TblWzskQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWzskMFile.refIxVTbl = " + to_string(VecWzskVMFileRefTbl::OBJ);
		sqlstr += " AND TblWzskMFile.refUref = " + to_string(preRefObj) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswzsk->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWzskMFile, TblWzskQSelect, TblWzskMShot";
		sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWzskMFile.grp = TblWzskQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWzskMFile.refIxVTbl = " + to_string(VecWzskVMFileRefTbl::SHT);
		sqlstr += " AND TblWzskMFile.refUref = TblWzskMShot.ref";
		sqlstr += " AND TblWzskMShot.refWzskMObject = " + to_string(preRefObj) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbswzsk->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWzskMFile, TblWzskQSelect";
		sqlstr += " WHERE TblWzskQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWzskMFile.grp = TblWzskQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzskMFile.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preFnm, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswzsk->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWzskQFilList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzsk->executeQuery(sqlstr);

	ixWzskVQrystate = VecWzskVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzsk);

	if (call) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTATCHG, jref);

};

void QryWzskFilList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWzskQFilList(jref, jnum, ref, grp, own, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzskMFile.ref, TblWzskMFile.grp, TblWzskMFile.own, TblWzskMFile.Filename, TblWzskMFile.refIxVTbl, TblWzskMFile.refUref, TblWzskMFile.osrefKContent, TblWzskMFile.srefKMimetype, TblWzskMFile.Size";
};

void QryWzskFilList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preFnm
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMFile.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMFile.own = " + to_string(preOwn) + "";
	};

	if (preFnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMFile.Filename LIKE '" + preFnm + "'";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMFile.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzskMFile.refUref = " + to_string(preReu) + "";
	};
};

void QryWzskFilList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzskFilList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWzskMFile.refUref ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWzskMFile.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::FNM) sqlstr += " ORDER BY TblWzskMFile.Filename ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWzskMFile.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWzskMFile.grp ASC";
};

void QryWzskFilList::fetch(
			DbsWzsk* dbswzsk
		) {
	string sqlstr;

	StmgrWzsk* stmgr = NULL;
	Stcch* stcch = NULL;

	WzskQFilList* rec = NULL;

	dbswzsk->tblwzskqfillist->loadRstByJref(jref, false, rst);
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
			rec->srefRefIxVTbl = VecWzskVMFileRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWzskVMFileRefTbl::getTitle(rec->refIxVTbl, ixWzskVLocale);
			if (rec->refIxVTbl == VecWzskVMFileRefTbl::OBJ) {
				rec->stubRefUref = StubWzsk::getStubObjStd(dbswzsk, rec->refUref, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWzskVMFileRefTbl::SHT) {
				rec->stubRefUref = StubWzsk::getStubShtStd(dbswzsk, rec->refUref, ixWzskVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->titOsrefKContent = dbswzsk->getKlstTitleBySref(VecWzskVKeylist::KLSTWZSKKMFILECONTENT, rec->osrefKContent, ixWzskVLocale);
			rec->titSrefKMimetype = dbswzsk->getKlstTitleBySref(VecWzskVKeylist::KLSTWZSKKMFILEMIMETYPE, rec->srefKMimetype, ixWzskVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzskFilList", "fetch");
	};

	refreshJnum();
};

uint QryWzskFilList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzskQFilList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzskFilList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzskQFilList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzskQFilList* QryWzskFilList::getRecByJnum(
			const uint jnum
		) {
	WzskQFilList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzskFilList::handleRequest(
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

bool QryWzskFilList::handleRerun(
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

bool QryWzskFilList::handleShow(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	WzskQFilList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tFilename";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\tosrefKContent";
	cout << "\ttitOsrefKContent";
	cout << "\tsrefKMimetype";
	cout << "\ttitSrefKMimetype";
	cout << "\tSize";
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
		cout << "\t" << rec->Filename;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->osrefKContent;
		cout << "\t" << rec->titOsrefKContent;
		cout << "\t" << rec->srefKMimetype;
		cout << "\t" << rec->titSrefKMimetype;
		cout << "\t" << rec->Size;
		cout << endl;
	};
	return retval;
};

void QryWzskFilList::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKFILUPD_REFEQ) {
		call->abort = handleCallWzskFilUpd_refEq(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKFILMOD) {
		call->abort = handleCallWzskFilMod(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzskStubChgFromSelf(dbswzsk);
	};
};

bool QryWzskFilList::handleCallWzskFilUpd_refEq(
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

bool QryWzskFilList::handleCallWzskFilMod(
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

bool QryWzskFilList::handleCallWzskStubChgFromSelf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskStubChgFromSelf --- INSERT
	return retval;
};

