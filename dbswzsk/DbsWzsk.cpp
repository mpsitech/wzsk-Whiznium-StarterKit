/**
	* \file DbsWzsk.cpp
	* C++ wrapper for database DbsWzsk (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "DbsWzsk.h"

#include "DbsWzsk_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class DbsWzsk
 ******************************************************************************/

DbsWzsk::DbsWzsk() {
	initdone = false;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	dbsMy = NULL;
#endif
#if defined(SBECORE_LITE)
	dbsLite = NULL;
#endif
};

DbsWzsk::~DbsWzsk() {
	if (initdone) term();
};

void DbsWzsk::init(
			const uint _ixDbsVDbstype
			, const string& _dbspath
			, const string& _dbsname
			, const string& _ip
			, const uint _port
			, const string& _username
			, const string& _password
		) {
	ixDbsVDbstype = _ixDbsVDbstype;
	dbspath = _dbspath;
	dbsname = _dbsname;
	username = _username;
	password = _password;
	ip = _ip;
	port = _port;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		initMy();
		initdone = true;
	};
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) {
		initLite();
		initdone = true;
	};
#endif
};

void DbsWzsk::term() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		termMy();
		initdone = false;
	};
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) {
		termLite();
		initdone = false;
	};
#endif
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
void DbsWzsk::initMy() {
	// connect to MySQL database
	dbsMy = mysql_init(NULL);

	mysql_options(dbsMy, MYSQL_READ_DEFAULT_GROUP, "MyccDatabase");
	if (!mysql_real_connect(dbsMy, ip.c_str(), username.c_str(), password.c_str(), dbsname.c_str(), port, NULL, 0)) {
		string dbms = "DbsWzsk::initMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	executeQuery("SET SESSION wait_timeout = 31536000");

	tblwzskaccrmuseruniversal = new MyTblWzskAccRMUserUniversal();
	((MyTblWzskAccRMUserUniversal*) tblwzskaccrmuseruniversal)->init(dbsMy);
	tblwzskampersondetail = new MyTblWzskAMPersonDetail();
	((MyTblWzskAMPersonDetail*) tblwzskampersondetail)->init(dbsMy);
	tblwzskamshotpar = new MyTblWzskAMShotPar();
	((MyTblWzskAMShotPar*) tblwzskamshotpar)->init(dbsMy);
	tblwzskamuseraccess = new MyTblWzskAMUserAccess();
	((MyTblWzskAMUserAccess*) tblwzskamuseraccess)->init(dbsMy);
	tblwzskamusergroupaccess = new MyTblWzskAMUsergroupAccess();
	((MyTblWzskAMUsergroupAccess*) tblwzskamusergroupaccess)->init(dbsMy);
	tblwzskavcontrolpar = new MyTblWzskAVControlPar();
	((MyTblWzskAVControlPar*) tblwzskavcontrolpar)->init(dbsMy);
	tblwzskavkeylistkey = new MyTblWzskAVKeylistKey();
	((MyTblWzskAVKeylistKey*) tblwzskavkeylistkey)->init(dbsMy);
	tblwzskavvaluelistval = new MyTblWzskAVValuelistVal();
	((MyTblWzskAVValuelistVal*) tblwzskavvaluelistval)->init(dbsMy);
	tblwzskcfile = new MyTblWzskCFile();
	((MyTblWzskCFile*) tblwzskcfile)->init(dbsMy);
	tblwzskhistrmuseruniversal = new MyTblWzskHistRMUserUniversal();
	((MyTblWzskHistRMUserUniversal*) tblwzskhistrmuseruniversal)->init(dbsMy);
	tblwzskjavkeylistkey = new MyTblWzskJAVKeylistKey();
	((MyTblWzskJAVKeylistKey*) tblwzskjavkeylistkey)->init(dbsMy);
	tblwzskjmobjgrouptitle = new MyTblWzskJMObjgroupTitle();
	((MyTblWzskJMObjgroupTitle*) tblwzskjmobjgrouptitle)->init(dbsMy);
	tblwzskjmpersonlastname = new MyTblWzskJMPersonLastname();
	((MyTblWzskJMPersonLastname*) tblwzskjmpersonlastname)->init(dbsMy);
	tblwzskjmuserstate = new MyTblWzskJMUserState();
	((MyTblWzskJMUserState*) tblwzskjmuserstate)->init(dbsMy);
	tblwzskmfile = new MyTblWzskMFile();
	((MyTblWzskMFile*) tblwzskmfile)->init(dbsMy);
	tblwzskmobject = new MyTblWzskMObject();
	((MyTblWzskMObject*) tblwzskmobject)->init(dbsMy);
	tblwzskmobjgroup = new MyTblWzskMObjgroup();
	((MyTblWzskMObjgroup*) tblwzskmobjgroup)->init(dbsMy);
	tblwzskmperson = new MyTblWzskMPerson();
	((MyTblWzskMPerson*) tblwzskmperson)->init(dbsMy);
	tblwzskmsession = new MyTblWzskMSession();
	((MyTblWzskMSession*) tblwzskmsession)->init(dbsMy);
	tblwzskmshot = new MyTblWzskMShot();
	((MyTblWzskMShot*) tblwzskmshot)->init(dbsMy);
	tblwzskmuser = new MyTblWzskMUser();
	((MyTblWzskMUser*) tblwzskmuser)->init(dbsMy);
	tblwzskmusergroup = new MyTblWzskMUsergroup();
	((MyTblWzskMUsergroup*) tblwzskmusergroup)->init(dbsMy);
	tblwzskrmusergroupuniversal = new MyTblWzskRMUsergroupUniversal();
	((MyTblWzskRMUsergroupUniversal*) tblwzskrmusergroupuniversal)->init(dbsMy);
	tblwzskrmusermusergroup = new MyTblWzskRMUserMUsergroup();
	((MyTblWzskRMUserMUsergroup*) tblwzskrmusermusergroup)->init(dbsMy);

	tblwzskqfillist = new MyTblWzskQFilList();
	((MyTblWzskQFilList*) tblwzskqfillist)->init(dbsMy);
	tblwzskqobj1nshot = new MyTblWzskQObj1NShot();
	((MyTblWzskQObj1NShot*) tblwzskqobj1nshot)->init(dbsMy);
	tblwzskqobjlist = new MyTblWzskQObjList();
	((MyTblWzskQObjList*) tblwzskqobjlist)->init(dbsMy);
	tblwzskqobjref1nfile = new MyTblWzskQObjRef1NFile();
	((MyTblWzskQObjRef1NFile*) tblwzskqobjref1nfile)->init(dbsMy);
	tblwzskqogr1nobject = new MyTblWzskQOgr1NObject();
	((MyTblWzskQOgr1NObject*) tblwzskqogr1nobject)->init(dbsMy);
	tblwzskqogrlist = new MyTblWzskQOgrList();
	((MyTblWzskQOgrList*) tblwzskqogrlist)->init(dbsMy);
	tblwzskqogrsup1nobjgroup = new MyTblWzskQOgrSup1NObjgroup();
	((MyTblWzskQOgrSup1NObjgroup*) tblwzskqogrsup1nobjgroup)->init(dbsMy);
	tblwzskqpreselect = new MyTblWzskQPreselect();
	((MyTblWzskQPreselect*) tblwzskqpreselect)->init(dbsMy);
	tblwzskqprsadetail = new MyTblWzskQPrsADetail();
	((MyTblWzskQPrsADetail*) tblwzskqprsadetail)->init(dbsMy);
	tblwzskqprslist = new MyTblWzskQPrsList();
	((MyTblWzskQPrsList*) tblwzskqprslist)->init(dbsMy);
	tblwzskqselect = new MyTblWzskQSelect();
	((MyTblWzskQSelect*) tblwzskqselect)->init(dbsMy);
	tblwzskqses1nshot = new MyTblWzskQSes1NShot();
	((MyTblWzskQSes1NShot*) tblwzskqses1nshot)->init(dbsMy);
	tblwzskqseslist = new MyTblWzskQSesList();
	((MyTblWzskQSesList*) tblwzskqseslist)->init(dbsMy);
	tblwzskqshtapar = new MyTblWzskQShtAPar();
	((MyTblWzskQShtAPar*) tblwzskqshtapar)->init(dbsMy);
	tblwzskqshtlist = new MyTblWzskQShtList();
	((MyTblWzskQShtList*) tblwzskqshtlist)->init(dbsMy);
	tblwzskqshtref1nfile = new MyTblWzskQShtRef1NFile();
	((MyTblWzskQShtRef1NFile*) tblwzskqshtref1nfile)->init(dbsMy);
	tblwzskqusgaaccess = new MyTblWzskQUsgAAccess();
	((MyTblWzskQUsgAAccess*) tblwzskqusgaaccess)->init(dbsMy);
	tblwzskqusglist = new MyTblWzskQUsgList();
	((MyTblWzskQUsgList*) tblwzskqusglist)->init(dbsMy);
	tblwzskqusgmnuser = new MyTblWzskQUsgMNUser();
	((MyTblWzskQUsgMNUser*) tblwzskqusgmnuser)->init(dbsMy);
	tblwzskqusr1nsession = new MyTblWzskQUsr1NSession();
	((MyTblWzskQUsr1NSession*) tblwzskqusr1nsession)->init(dbsMy);
	tblwzskqusraaccess = new MyTblWzskQUsrAAccess();
	((MyTblWzskQUsrAAccess*) tblwzskqusraaccess)->init(dbsMy);
	tblwzskqusrlist = new MyTblWzskQUsrList();
	((MyTblWzskQUsrList*) tblwzskqusrlist)->init(dbsMy);
	tblwzskqusrmnusergroup = new MyTblWzskQUsrMNUsergroup();
	((MyTblWzskQUsrMNUsergroup*) tblwzskqusrmnusergroup)->init(dbsMy);
};

void DbsWzsk::termMy() {
	mysql_close(dbsMy);
	mysql_thread_end();
};
#endif

#if defined(SBECORE_LITE)
void DbsWzsk::initLite() {
	int res;

	res = sqlite3_open_v2(dbspath.c_str(), &dbsLite, SQLITE_OPEN_READWRITE | SQLITE_OPEN_FULLMUTEX, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzsk::initLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	sqlite3_extended_result_codes(dbsLite, 1);
	sqlite3_busy_timeout(dbsLite, 5000);

	tblwzskaccrmuseruniversal = new LiteTblWzskAccRMUserUniversal();
	((LiteTblWzskAccRMUserUniversal*) tblwzskaccrmuseruniversal)->init(dbsLite);
	tblwzskampersondetail = new LiteTblWzskAMPersonDetail();
	((LiteTblWzskAMPersonDetail*) tblwzskampersondetail)->init(dbsLite);
	tblwzskamshotpar = new LiteTblWzskAMShotPar();
	((LiteTblWzskAMShotPar*) tblwzskamshotpar)->init(dbsLite);
	tblwzskamuseraccess = new LiteTblWzskAMUserAccess();
	((LiteTblWzskAMUserAccess*) tblwzskamuseraccess)->init(dbsLite);
	tblwzskamusergroupaccess = new LiteTblWzskAMUsergroupAccess();
	((LiteTblWzskAMUsergroupAccess*) tblwzskamusergroupaccess)->init(dbsLite);
	tblwzskavcontrolpar = new LiteTblWzskAVControlPar();
	((LiteTblWzskAVControlPar*) tblwzskavcontrolpar)->init(dbsLite);
	tblwzskavkeylistkey = new LiteTblWzskAVKeylistKey();
	((LiteTblWzskAVKeylistKey*) tblwzskavkeylistkey)->init(dbsLite);
	tblwzskavvaluelistval = new LiteTblWzskAVValuelistVal();
	((LiteTblWzskAVValuelistVal*) tblwzskavvaluelistval)->init(dbsLite);
	tblwzskcfile = new LiteTblWzskCFile();
	((LiteTblWzskCFile*) tblwzskcfile)->init(dbsLite);
	tblwzskhistrmuseruniversal = new LiteTblWzskHistRMUserUniversal();
	((LiteTblWzskHistRMUserUniversal*) tblwzskhistrmuseruniversal)->init(dbsLite);
	tblwzskjavkeylistkey = new LiteTblWzskJAVKeylistKey();
	((LiteTblWzskJAVKeylistKey*) tblwzskjavkeylistkey)->init(dbsLite);
	tblwzskjmobjgrouptitle = new LiteTblWzskJMObjgroupTitle();
	((LiteTblWzskJMObjgroupTitle*) tblwzskjmobjgrouptitle)->init(dbsLite);
	tblwzskjmpersonlastname = new LiteTblWzskJMPersonLastname();
	((LiteTblWzskJMPersonLastname*) tblwzskjmpersonlastname)->init(dbsLite);
	tblwzskjmuserstate = new LiteTblWzskJMUserState();
	((LiteTblWzskJMUserState*) tblwzskjmuserstate)->init(dbsLite);
	tblwzskmfile = new LiteTblWzskMFile();
	((LiteTblWzskMFile*) tblwzskmfile)->init(dbsLite);
	tblwzskmobject = new LiteTblWzskMObject();
	((LiteTblWzskMObject*) tblwzskmobject)->init(dbsLite);
	tblwzskmobjgroup = new LiteTblWzskMObjgroup();
	((LiteTblWzskMObjgroup*) tblwzskmobjgroup)->init(dbsLite);
	tblwzskmperson = new LiteTblWzskMPerson();
	((LiteTblWzskMPerson*) tblwzskmperson)->init(dbsLite);
	tblwzskmsession = new LiteTblWzskMSession();
	((LiteTblWzskMSession*) tblwzskmsession)->init(dbsLite);
	tblwzskmshot = new LiteTblWzskMShot();
	((LiteTblWzskMShot*) tblwzskmshot)->init(dbsLite);
	tblwzskmuser = new LiteTblWzskMUser();
	((LiteTblWzskMUser*) tblwzskmuser)->init(dbsLite);
	tblwzskmusergroup = new LiteTblWzskMUsergroup();
	((LiteTblWzskMUsergroup*) tblwzskmusergroup)->init(dbsLite);
	tblwzskrmusergroupuniversal = new LiteTblWzskRMUsergroupUniversal();
	((LiteTblWzskRMUsergroupUniversal*) tblwzskrmusergroupuniversal)->init(dbsLite);
	tblwzskrmusermusergroup = new LiteTblWzskRMUserMUsergroup();
	((LiteTblWzskRMUserMUsergroup*) tblwzskrmusermusergroup)->init(dbsLite);

	tblwzskqfillist = new LiteTblWzskQFilList();
	((LiteTblWzskQFilList*) tblwzskqfillist)->init(dbsLite);
	tblwzskqobj1nshot = new LiteTblWzskQObj1NShot();
	((LiteTblWzskQObj1NShot*) tblwzskqobj1nshot)->init(dbsLite);
	tblwzskqobjlist = new LiteTblWzskQObjList();
	((LiteTblWzskQObjList*) tblwzskqobjlist)->init(dbsLite);
	tblwzskqobjref1nfile = new LiteTblWzskQObjRef1NFile();
	((LiteTblWzskQObjRef1NFile*) tblwzskqobjref1nfile)->init(dbsLite);
	tblwzskqogr1nobject = new LiteTblWzskQOgr1NObject();
	((LiteTblWzskQOgr1NObject*) tblwzskqogr1nobject)->init(dbsLite);
	tblwzskqogrlist = new LiteTblWzskQOgrList();
	((LiteTblWzskQOgrList*) tblwzskqogrlist)->init(dbsLite);
	tblwzskqogrsup1nobjgroup = new LiteTblWzskQOgrSup1NObjgroup();
	((LiteTblWzskQOgrSup1NObjgroup*) tblwzskqogrsup1nobjgroup)->init(dbsLite);
	tblwzskqpreselect = new LiteTblWzskQPreselect();
	((LiteTblWzskQPreselect*) tblwzskqpreselect)->init(dbsLite);
	tblwzskqprsadetail = new LiteTblWzskQPrsADetail();
	((LiteTblWzskQPrsADetail*) tblwzskqprsadetail)->init(dbsLite);
	tblwzskqprslist = new LiteTblWzskQPrsList();
	((LiteTblWzskQPrsList*) tblwzskqprslist)->init(dbsLite);
	tblwzskqselect = new LiteTblWzskQSelect();
	((LiteTblWzskQSelect*) tblwzskqselect)->init(dbsLite);
	tblwzskqses1nshot = new LiteTblWzskQSes1NShot();
	((LiteTblWzskQSes1NShot*) tblwzskqses1nshot)->init(dbsLite);
	tblwzskqseslist = new LiteTblWzskQSesList();
	((LiteTblWzskQSesList*) tblwzskqseslist)->init(dbsLite);
	tblwzskqshtapar = new LiteTblWzskQShtAPar();
	((LiteTblWzskQShtAPar*) tblwzskqshtapar)->init(dbsLite);
	tblwzskqshtlist = new LiteTblWzskQShtList();
	((LiteTblWzskQShtList*) tblwzskqshtlist)->init(dbsLite);
	tblwzskqshtref1nfile = new LiteTblWzskQShtRef1NFile();
	((LiteTblWzskQShtRef1NFile*) tblwzskqshtref1nfile)->init(dbsLite);
	tblwzskqusgaaccess = new LiteTblWzskQUsgAAccess();
	((LiteTblWzskQUsgAAccess*) tblwzskqusgaaccess)->init(dbsLite);
	tblwzskqusglist = new LiteTblWzskQUsgList();
	((LiteTblWzskQUsgList*) tblwzskqusglist)->init(dbsLite);
	tblwzskqusgmnuser = new LiteTblWzskQUsgMNUser();
	((LiteTblWzskQUsgMNUser*) tblwzskqusgmnuser)->init(dbsLite);
	tblwzskqusr1nsession = new LiteTblWzskQUsr1NSession();
	((LiteTblWzskQUsr1NSession*) tblwzskqusr1nsession)->init(dbsLite);
	tblwzskqusraaccess = new LiteTblWzskQUsrAAccess();
	((LiteTblWzskQUsrAAccess*) tblwzskqusraaccess)->init(dbsLite);
	tblwzskqusrlist = new LiteTblWzskQUsrList();
	((LiteTblWzskQUsrList*) tblwzskqusrlist)->init(dbsLite);
	tblwzskqusrmnusergroup = new LiteTblWzskQUsrMNUsergroup();
	((LiteTblWzskQUsrMNUsergroup*) tblwzskqusrmnusergroup)->init(dbsLite);
};

void DbsWzsk::termLite() {
	sqlite3_close(dbsLite);
};
#endif

void DbsWzsk::begin() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) beginMy();
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) beginLite();
#endif
};

bool DbsWzsk::commit() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return commitMy();
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return commitLite();
#endif

	return false;
};

void DbsWzsk::rollback() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) rollbackMy();
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) rollbackLite();
#endif
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
void DbsWzsk::beginMy() {
	if (mysql_query(dbsMy, "BEGIN")) {
		string dbms = "DbsWzsk::beginMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};
};

bool DbsWzsk::commitMy() {
	if (mysql_query(dbsMy, "COMMIT")) {
		rollbackMy();
		return false;
	};

	return true;
};

void DbsWzsk::rollbackMy() {
	if (mysql_query(dbsMy, "ROLLBACK")) {
		string dbms = "DbsWzsk::rollbackMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};
};
#endif

#if defined(SBECORE_LITE)
void DbsWzsk::beginLite() {
	if (sqlite3_exec(dbsLite, "BEGIN", NULL, NULL, NULL) != SQLITE_OK) {
		string dbms = "DbsWzsk::beginLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};
};

bool DbsWzsk::commitLite() {
	if (sqlite3_exec(dbsLite, "COMMIT", NULL, NULL, NULL) != SQLITE_OK) {
		rollbackLite();
		return false;
	};

	return true;
};

void DbsWzsk::rollbackLite() {
	if (sqlite3_exec(dbsLite, "ROLLBACK", NULL, NULL, NULL) != SQLITE_OK) {
		string dbms = "DbsWzsk::rollbackLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};
};
#endif

bool DbsWzsk::loadUintBySQL(
			const string& sqlstr
			, uint& val
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadUintBySQLMy(sqlstr, val);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadUintBySQLLite(sqlstr, val);
#endif

	return false;
};

bool DbsWzsk::loadStringBySQL(
			const string& sqlstr
			, string& val
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadStringBySQLMy(sqlstr, val);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadStringBySQLLite(sqlstr, val);
#endif

	return false;
};

bool DbsWzsk::loadRefBySQL(
			const string& sqlstr
			, ubigint& ref
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefBySQLMy(sqlstr, ref);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadRefBySQLLite(sqlstr, ref);
#endif

	return false;
};

ubigint DbsWzsk::loadRefsBySQL(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefsBySQLMy(sqlstr, append, refs);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadRefsBySQLLite(sqlstr, append, refs);
#endif

	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
bool DbsWzsk::loadUintBySQLMy(
			const string& sqlstr
			, uint& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWzsk::loadUintBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWzsk::loadUintBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		val = atol((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsWzsk::loadStringBySQLMy(
			const string& sqlstr
			, string& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWzsk::loadStringBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWzsk::loadStringBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);
		val.assign(dbrow[0], dblengths[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsWzsk::loadRefBySQLMy(
			const string& sqlstr
			, ubigint& ref
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWzsk::loadRefBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWzsk::loadRefBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		ref = atoll((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

ubigint DbsWzsk::loadRefsBySQLMy(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWzsk::loadRefsBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWzsk::loadRefsBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		dbrow = mysql_fetch_row(dbresult);
		refs.push_back(atoll((char*) dbrow[0]));
		numread++;
	};

	mysql_free_result(dbresult);
	
	return(numread);
};
#endif

#if defined(SBECORE_LITE)
bool DbsWzsk::loadUintBySQLLite(
			const string& sqlstr
			, uint& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), -1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzsk::loadUintBySQLLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val = sqlite3_column_int(stmt, 0);

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

bool DbsWzsk::loadStringBySQLLite(
			const string& sqlstr
			, string& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzsk::loadStringBySQLLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val.assign((const char*) sqlite3_column_text(stmt, 0));

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

bool DbsWzsk::loadRefBySQLLite(
			const string& sqlstr
			, ubigint& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzsk::loadRefBySQLLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val = sqlite3_column_int64(stmt, 0);

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

ubigint DbsWzsk::loadRefsBySQLLite(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	int res; ubigint numread = 0;
	sqlite3_stmt* stmt;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzsk::loadRefsBySQLLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (!append) refs.resize(0);

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		refs.push_back(sqlite3_column_int64(stmt, 0));
		numread++;

		res = sqlite3_step(stmt);
	};

	sqlite3_finalize(stmt);

	return(numread);
};
#endif

void DbsWzsk::executeQuery(
			const string& sqlstr
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY)
		if (mysql_real_query(dbsMy, sqlstr.c_str(), strlen(sqlstr.c_str()))) {
			string dbms = "DbsWzsk::executeQuery() / MySQL / " + string(mysql_error(dbsMy));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
#endif

#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) {
		int res;

		res = sqlite3_exec(dbsLite, sqlstr.c_str(), NULL, NULL, NULL);
		if (res != SQLITE_OK) {
			string dbms = "DbsWzsk::executeQuery() / SQLite / " + string(sqlite3_errmsg(dbsLite));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
	};
#endif
};

void DbsWzsk::executeQueryDiv(
			const string& sqlstrmy
			, const string& sqlstrlite
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) executeQuery(sqlstrmy);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) executeQuery(sqlstrlite);
#endif
};

void DbsWzsk::executeFile(
			const string& fullpath
		) {
	string sqlstr = "";
	char c;
	
	ifstream sqlfile(fullpath.c_str());

	while (sqlfile.get(c)) {
		switch (c) {
			case '\n':
				break;
			case '\t':
				break;
			case ';':
				executeQuery(sqlstr);
				sqlstr = "";
				break;
			default:
				sqlstr = sqlstr + c;
				break;
		};
	};
	sqlfile.close();
};

void DbsWzsk::fillFeedFromKlst(
			const uint klsIxWzskVKeylist
			, const uint ixWzskVLocale
			, Feed& feed
		) {
	ListWzskAVKeylistKey klsAkeys;
	WzskAVKeylistKey* klsAkey = NULL;

	tblwzskavkeylistkey->loadRstByKls(klsIxWzskVKeylist, false, klsAkeys);

	feed.clear();
	for (unsigned int i = 0; i < klsAkeys.nodes.size(); i++) {
		klsAkey = klsAkeys.nodes[i];

		tblwzskjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixWzskVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

void DbsWzsk::fillFeedFromKlstByMtbUref(
			const uint klsIxWzskVKeylist
			, const uint x1IxWzskVMaintable
			, const ubigint x1Uref
			, const uint ixWzskVLocale
			, Feed& feed
		) {
	ListWzskAVKeylistKey klsAkeys;
	WzskAVKeylistKey* klsAkey = NULL;

	tblwzskavkeylistkey->loadRstByKlsMtbUrf(klsIxWzskVKeylist, x1IxWzskVMaintable, x1Uref, false, klsAkeys);

	feed.clear();
	for (unsigned int i = 0; i < klsAkeys.nodes.size(); i++) {
		klsAkey = klsAkeys.nodes[i];

		tblwzskjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixWzskVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

string DbsWzsk::getKlstTitleBySref(
			const uint klsIxWzskVKeylist
			, const string& sref
			, const uint ixWzskVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblwzskavkeylistkey->loadRefByKlsSrf(klsIxWzskVKeylist, sref, refKlk))
		if (!tblwzskjavkeylistkey->loadTitByKlkLcl(refKlk, ixWzskVLocale, retval))
			tblwzskavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

string DbsWzsk::getKlstTitleByMtbUrefSref(
			const uint klsIxWzskVKeylist
			, const uint x1IxWzskVMaintable
			, const ubigint x1Uref
			, const string& sref
			, const uint ixWzskVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblwzskavkeylistkey->loadRefByKlsMtbUrfSrf(klsIxWzskVKeylist, x1IxWzskVMaintable, x1Uref, sref, refKlk))
		if (!tblwzskjavkeylistkey->loadTitByKlkLcl(refKlk, ixWzskVLocale, retval))
			tblwzskavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

void DbsWzsk::fillFeedFromVlst(
			const uint vlsIxWzskVValuelist
			, const uint x1IxWzskVLocale
			, Feed& feed
		) {
	ListWzskAVValuelistVal vlsAvals;
	WzskAVValuelistVal* vlsAval = NULL;

	tblwzskavvaluelistval->loadRstByVlsLcl(vlsIxWzskVValuelist, x1IxWzskVLocale, false, vlsAvals);

	feed.clear();
	for (unsigned int i = 0; i < vlsAvals.nodes.size(); i++) {
		vlsAval = vlsAvals.nodes[i];

		feed.appendTitles(vlsAval->Val);
	};
};
