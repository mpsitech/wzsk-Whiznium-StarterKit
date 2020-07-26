/**
	* \file WzskMSession.cpp
	* database access for table TblWzskMSession (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "WzskMSession.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskMSession
 ******************************************************************************/

WzskMSession::WzskMSession(
			const ubigint ref
			, const ubigint refWzskMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {

	this->ref = ref;
	this->refWzskMUser = refWzskMUser;
	this->start = start;
	this->stop = stop;
	this->Ip = Ip;
};

bool WzskMSession::operator==(
			const WzskMSession& comp
		) {
	return false;
};

bool WzskMSession::operator!=(
			const WzskMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskMSession
 ******************************************************************************/

ListWzskMSession::ListWzskMSession() {
};

ListWzskMSession::ListWzskMSession(
			const ListWzskMSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskMSession(*(src.nodes[i]));
};

ListWzskMSession::~ListWzskMSession() {
	clear();
};

void ListWzskMSession::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskMSession::size() const {
	return(nodes.size());
};

void ListWzskMSession::append(
			WzskMSession* rec
		) {
	nodes.push_back(rec);
};

WzskMSession* ListWzskMSession::operator[](
			const uint ix
		) {
	WzskMSession* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskMSession& ListWzskMSession::operator=(
			const ListWzskMSession& src
		) {
	WzskMSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskMSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskMSession::operator==(
			const ListWzskMSession& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWzskMSession::operator!=(
			const ListWzskMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskMSession
 ******************************************************************************/

TblWzskMSession::TblWzskMSession() {
};

TblWzskMSession::~TblWzskMSession() {
};

bool TblWzskMSession::loadRecBySQL(
			const string& sqlstr
			, WzskMSession** rec
		) {
	return false;
};

ubigint TblWzskMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMSession& rst
		) {
	return 0;
};

ubigint TblWzskMSession::insertRec(
			WzskMSession* rec
		) {
	return 0;
};

ubigint TblWzskMSession::insertNewRec(
			WzskMSession** rec
			, const ubigint refWzskMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	WzskMSession* _rec = NULL;

	_rec = new WzskMSession(0, refWzskMUser, start, stop, Ip);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskMSession::appendNewRecToRst(
			ListWzskMSession& rst
			, WzskMSession** rec
			, const ubigint refWzskMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	WzskMSession* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMUser, start, stop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskMSession::insertRst(
			ListWzskMSession& rst
			, bool transact
		) {
};

void TblWzskMSession::updateRec(
			WzskMSession* rec
		) {
};

void TblWzskMSession::updateRst(
			ListWzskMSession& rst
			, bool transact
		) {
};

void TblWzskMSession::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskMSession::loadRecByRef(
			ubigint ref
			, WzskMSession** rec
		) {
	return false;
};

ubigint TblWzskMSession::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzskMSession::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskMSession& rst
		) {
	return 0;
};

ubigint TblWzskMSession::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskMSession& rst
		) {
	ubigint numload = 0;
	WzskMSession* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskMSession
 ******************************************************************************/

MyTblWzskMSession::MyTblWzskMSession() :
			TblWzskMSession()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskMSession::~MyTblWzskMSession() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMSession (refWzskMUser, start, stop, Ip) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskMSession SET refWzskMUser = ?, start = ?, stop = ?, Ip = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMSession WHERE ref = ?", false);
};

bool MyTblWzskMSession::loadRecBySQL(
			const string& sqlstr
			, WzskMSession** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskMSession* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMSession::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMSession::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskMSession();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMUser = atoll((char*) dbrow[1]); else _rec->refWzskMUser = 0;
		if (dbrow[2]) _rec->start = atol((char*) dbrow[2]); else _rec->start = 0;
		if (dbrow[3]) _rec->stop = atol((char*) dbrow[3]); else _rec->stop = 0;
		if (dbrow[4]) _rec->Ip.assign(dbrow[4], dblengths[4]); else _rec->Ip = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMSession& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskMSession* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMSession::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMSession::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskMSession();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMUser = atoll((char*) dbrow[1]); else rec->refWzskMUser = 0;
			if (dbrow[2]) rec->start = atol((char*) dbrow[2]); else rec->start = 0;
			if (dbrow[3]) rec->stop = atol((char*) dbrow[3]); else rec->stop = 0;
			if (dbrow[4]) rec->Ip.assign(dbrow[4], dblengths[4]); else rec->Ip = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskMSession::insertRec(
			WzskMSession* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskMSession::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskMSession::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskMSession::insertRst(
			ListWzskMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskMSession::updateRec(
			WzskMSession* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskMSession::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskMSession::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskMSession::updateRst(
			ListWzskMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskMSession::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskMSession::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskMSession::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskMSession::loadRecByRef(
			ubigint ref
			, WzskMSession** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskMSession WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzskMSession::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskMSession WHERE refWzskMUser = " + to_string(refWzskMUser) + " ORDER BY start ASC", append, refs);
};

ubigint MyTblWzskMSession::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskMSession& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMUser, start, stop, Ip FROM TblWzskMSession WHERE refWzskMUser = " + to_string(refWzskMUser) + " ORDER BY start ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskMSession
 ******************************************************************************/

LiteTblWzskMSession::LiteTblWzskMSession() :
			TblWzskMSession()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblWzskMSession::~LiteTblWzskMSession() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblWzskMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMSession (refWzskMUser, start, stop, Ip) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskMSession SET refWzskMUser = ?1, start = ?2, stop = ?3, Ip = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMSession WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMUser, start, stop, Ip FROM TblWzskMSession WHERE ref = ?1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblWzskMSession WHERE refWzskMUser = ?1 ORDER BY start ASC");
	stmtLoadRstByUsr = createStatement("SELECT ref, refWzskMUser, start, stop, Ip FROM TblWzskMSession WHERE refWzskMUser = ?1 ORDER BY start ASC");
};

bool LiteTblWzskMSession::loadRec(
			sqlite3_stmt* stmt
			, WzskMSession** rec
		) {
	int res;

	WzskMSession* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskMSession();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		_rec->start = sqlite3_column_int(stmt, 2);
		_rec->stop = sqlite3_column_int(stmt, 3);
		_rec->Ip.assign((const char*) sqlite3_column_text(stmt, 4));

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) {
			*rec = _rec;
			retval = true;
		} else {
			delete _rec;
		};
	};

	return retval;
};

ubigint LiteTblWzskMSession::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMSession& rst
		) {
	int res; ubigint numread = 0;

	WzskMSession* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskMSession();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		rec->start = sqlite3_column_int(stmt, 2);
		rec->stop = sqlite3_column_int(stmt, 3);
		rec->Ip.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskMSession::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskMSession** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskMSession::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMSession& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskMSession::loadRecBySQL(
			const string& sqlstr
			, WzskMSession** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMSession::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMSession& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMSession::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMSession::insertRec(
			WzskMSession* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->start);
	sqlite3_bind_int(stmtInsertRec, 3, rec->stop);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMSession::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskMSession::insertRst(
			ListWzskMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskMSession::updateRec(
			WzskMSession* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->stop);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMSession::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskMSession::updateRst(
			ListWzskMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskMSession::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMSession::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskMSession::loadRecByRef(
			ubigint ref
			, WzskMSession** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzskMSession::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refWzskMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblWzskMSession::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskMSession& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refWzskMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

#endif

