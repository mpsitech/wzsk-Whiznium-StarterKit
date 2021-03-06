/**
	* \file WzskRMUserMUsergroup.cpp
	* database access for table TblWzskRMUserMUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskRMUserMUsergroup.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskRMUserMUsergroup
 ******************************************************************************/

WzskRMUserMUsergroup::WzskRMUserMUsergroup(
			const ubigint ref
			, const ubigint refWzskMUser
			, const ubigint refWzskMUsergroup
			, const uint ixWzskVUserlevel
		) {

	this->ref = ref;
	this->refWzskMUser = refWzskMUser;
	this->refWzskMUsergroup = refWzskMUsergroup;
	this->ixWzskVUserlevel = ixWzskVUserlevel;
};

bool WzskRMUserMUsergroup::operator==(
			const WzskRMUserMUsergroup& comp
		) {
	return false;
};

bool WzskRMUserMUsergroup::operator!=(
			const WzskRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskRMUserMUsergroup
 ******************************************************************************/

ListWzskRMUserMUsergroup::ListWzskRMUserMUsergroup() {
};

ListWzskRMUserMUsergroup::ListWzskRMUserMUsergroup(
			const ListWzskRMUserMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskRMUserMUsergroup(*(src.nodes[i]));
};

ListWzskRMUserMUsergroup::~ListWzskRMUserMUsergroup() {
	clear();
};

void ListWzskRMUserMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskRMUserMUsergroup::size() const {
	return(nodes.size());
};

void ListWzskRMUserMUsergroup::append(
			WzskRMUserMUsergroup* rec
		) {
	nodes.push_back(rec);
};

WzskRMUserMUsergroup* ListWzskRMUserMUsergroup::operator[](
			const uint ix
		) {
	WzskRMUserMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskRMUserMUsergroup& ListWzskRMUserMUsergroup::operator=(
			const ListWzskRMUserMUsergroup& src
		) {
	WzskRMUserMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskRMUserMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskRMUserMUsergroup::operator==(
			const ListWzskRMUserMUsergroup& comp
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

bool ListWzskRMUserMUsergroup::operator!=(
			const ListWzskRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskRMUserMUsergroup
 ******************************************************************************/

TblWzskRMUserMUsergroup::TblWzskRMUserMUsergroup() {
};

TblWzskRMUserMUsergroup::~TblWzskRMUserMUsergroup() {
};

bool TblWzskRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzskRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblWzskRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWzskRMUserMUsergroup::insertRec(
			WzskRMUserMUsergroup* rec
		) {
	return 0;
};

ubigint TblWzskRMUserMUsergroup::insertNewRec(
			WzskRMUserMUsergroup** rec
			, const ubigint refWzskMUser
			, const ubigint refWzskMUsergroup
			, const uint ixWzskVUserlevel
		) {
	ubigint retval = 0;
	WzskRMUserMUsergroup* _rec = NULL;

	_rec = new WzskRMUserMUsergroup(0, refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskRMUserMUsergroup::appendNewRecToRst(
			ListWzskRMUserMUsergroup& rst
			, WzskRMUserMUsergroup** rec
			, const ubigint refWzskMUser
			, const ubigint refWzskMUsergroup
			, const uint ixWzskVUserlevel
		) {
	ubigint retval = 0;
	WzskRMUserMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskRMUserMUsergroup::insertRst(
			ListWzskRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblWzskRMUserMUsergroup::updateRec(
			WzskRMUserMUsergroup* rec
		) {
};

void TblWzskRMUserMUsergroup::updateRst(
			ListWzskRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblWzskRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WzskRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblWzskRMUserMUsergroup::loadRstByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWzskRMUserMUsergroup::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWzskRMUserMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	ubigint numload = 0;
	WzskRMUserMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskRMUserMUsergroup
 ******************************************************************************/

MyTblWzskRMUserMUsergroup::MyTblWzskRMUserMUsergroup() :
			TblWzskRMUserMUsergroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskRMUserMUsergroup::~MyTblWzskRMUserMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskRMUserMUsergroup (refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskRMUserMUsergroup SET refWzskMUser = ?, refWzskMUsergroup = ?, ixWzskVUserlevel = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskRMUserMUsergroup WHERE ref = ?", false);
};

bool MyTblWzskRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzskRMUserMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskRMUserMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskRMUserMUsergroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskRMUserMUsergroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzskRMUserMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMUser = atoll((char*) dbrow[1]); else _rec->refWzskMUser = 0;
		if (dbrow[2]) _rec->refWzskMUsergroup = atoll((char*) dbrow[2]); else _rec->refWzskMUsergroup = 0;
		if (dbrow[3]) _rec->ixWzskVUserlevel = atol((char*) dbrow[3]); else _rec->ixWzskVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskRMUserMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskRMUserMUsergroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskRMUserMUsergroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzskRMUserMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMUser = atoll((char*) dbrow[1]); else rec->refWzskMUser = 0;
			if (dbrow[2]) rec->refWzskMUsergroup = atoll((char*) dbrow[2]); else rec->refWzskMUsergroup = 0;
			if (dbrow[3]) rec->ixWzskVUserlevel = atol((char*) dbrow[3]); else rec->ixWzskVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskRMUserMUsergroup::insertRec(
			WzskRMUserMUsergroup* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWzskMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWzskVUserlevel,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskRMUserMUsergroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskRMUserMUsergroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskRMUserMUsergroup::insertRst(
			ListWzskRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskRMUserMUsergroup::updateRec(
			WzskRMUserMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWzskMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWzskVUserlevel,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskRMUserMUsergroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskRMUserMUsergroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskRMUserMUsergroup::updateRst(
			ListWzskRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskRMUserMUsergroup::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskRMUserMUsergroup::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WzskRMUserMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskRMUserMUsergroup WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzskRMUserMUsergroup::loadRstByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel FROM TblWzskRMUserMUsergroup WHERE refWzskMUsergroup = " + to_string(refWzskMUsergroup) + "", append, rst);
};

ubigint MyTblWzskRMUserMUsergroup::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel FROM TblWzskRMUserMUsergroup WHERE refWzskMUser = " + to_string(refWzskMUser) + "", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskRMUserMUsergroup
 ******************************************************************************/

LiteTblWzskRMUserMUsergroup::LiteTblWzskRMUserMUsergroup() :
			TblWzskRMUserMUsergroup()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByUsg = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblWzskRMUserMUsergroup::~LiteTblWzskRMUserMUsergroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByUsg) sqlite3_finalize(stmtLoadRstByUsg);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblWzskRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskRMUserMUsergroup (refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzskRMUserMUsergroup SET refWzskMUser = ?1, refWzskMUsergroup = ?2, ixWzskVUserlevel = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskRMUserMUsergroup WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel FROM TblWzskRMUserMUsergroup WHERE ref = ?1");
	stmtLoadRstByUsg = createStatement("SELECT ref, refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel FROM TblWzskRMUserMUsergroup WHERE refWzskMUsergroup = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refWzskMUser, refWzskMUsergroup, ixWzskVUserlevel FROM TblWzskRMUserMUsergroup WHERE refWzskMUser = ?1");
};

bool LiteTblWzskRMUserMUsergroup::loadRec(
			sqlite3_stmt* stmt
			, WzskRMUserMUsergroup** rec
		) {
	int res;

	WzskRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskRMUserMUsergroup();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		_rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 2);
		_rec->ixWzskVUserlevel = sqlite3_column_int(stmt, 3);

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

ubigint LiteTblWzskRMUserMUsergroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	int res; ubigint numread = 0;

	WzskRMUserMUsergroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskRMUserMUsergroup();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 2);
		rec->ixWzskVUserlevel = sqlite3_column_int(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskRMUserMUsergroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskRMUserMUsergroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskRMUserMUsergroup::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzskRMUserMUsergroup** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskRMUserMUsergroup::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskRMUserMUsergroup::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskRMUserMUsergroup::insertRec(
			WzskRMUserMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMUser);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->refWzskMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ixWzskVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskRMUserMUsergroup::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskRMUserMUsergroup::insertRst(
			ListWzskRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskRMUserMUsergroup::updateRec(
			WzskRMUserMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMUser);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->refWzskMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ixWzskVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskRMUserMUsergroup::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskRMUserMUsergroup::updateRst(
			ListWzskRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskRMUserMUsergroup::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WzskRMUserMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzskRMUserMUsergroup::loadRstByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsg, 1, refWzskMUsergroup);

	return loadRstByStmt(stmtLoadRstByUsg, append, rst);
};

ubigint LiteTblWzskRMUserMUsergroup::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskRMUserMUsergroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refWzskMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

#endif
