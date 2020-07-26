/**
	* \file WzskMShot.cpp
	* database access for table TblWzskMShot (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "WzskMShot.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskMShot
 ******************************************************************************/

WzskMShot::WzskMShot(
			const ubigint ref
			, const ubigint refWzskMSession
			, const ubigint refWzskMObject
			, const uint start
			, const string Comment
		) {

	this->ref = ref;
	this->refWzskMSession = refWzskMSession;
	this->refWzskMObject = refWzskMObject;
	this->start = start;
	this->Comment = Comment;
};

bool WzskMShot::operator==(
			const WzskMShot& comp
		) {
	return false;
};

bool WzskMShot::operator!=(
			const WzskMShot& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskMShot
 ******************************************************************************/

ListWzskMShot::ListWzskMShot() {
};

ListWzskMShot::ListWzskMShot(
			const ListWzskMShot& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskMShot(*(src.nodes[i]));
};

ListWzskMShot::~ListWzskMShot() {
	clear();
};

void ListWzskMShot::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskMShot::size() const {
	return(nodes.size());
};

void ListWzskMShot::append(
			WzskMShot* rec
		) {
	nodes.push_back(rec);
};

WzskMShot* ListWzskMShot::operator[](
			const uint ix
		) {
	WzskMShot* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskMShot& ListWzskMShot::operator=(
			const ListWzskMShot& src
		) {
	WzskMShot* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskMShot(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskMShot::operator==(
			const ListWzskMShot& comp
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

bool ListWzskMShot::operator!=(
			const ListWzskMShot& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskMShot
 ******************************************************************************/

TblWzskMShot::TblWzskMShot() {
};

TblWzskMShot::~TblWzskMShot() {
};

bool TblWzskMShot::loadRecBySQL(
			const string& sqlstr
			, WzskMShot** rec
		) {
	return false;
};

ubigint TblWzskMShot::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMShot& rst
		) {
	return 0;
};

ubigint TblWzskMShot::insertRec(
			WzskMShot* rec
		) {
	return 0;
};

ubigint TblWzskMShot::insertNewRec(
			WzskMShot** rec
			, const ubigint refWzskMSession
			, const ubigint refWzskMObject
			, const uint start
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMShot* _rec = NULL;

	_rec = new WzskMShot(0, refWzskMSession, refWzskMObject, start, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskMShot::appendNewRecToRst(
			ListWzskMShot& rst
			, WzskMShot** rec
			, const ubigint refWzskMSession
			, const ubigint refWzskMObject
			, const uint start
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMShot* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMSession, refWzskMObject, start, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskMShot::insertRst(
			ListWzskMShot& rst
			, bool transact
		) {
};

void TblWzskMShot::updateRec(
			WzskMShot* rec
		) {
};

void TblWzskMShot::updateRst(
			ListWzskMShot& rst
			, bool transact
		) {
};

void TblWzskMShot::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskMShot::loadRecByRef(
			ubigint ref
			, WzskMShot** rec
		) {
	return false;
};

ubigint TblWzskMShot::loadRstBySes(
			ubigint refWzskMSession
			, const bool append
			, ListWzskMShot& rst
		) {
	return 0;
};

ubigint TblWzskMShot::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskMShot& rst
		) {
	ubigint numload = 0;
	WzskMShot* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskMShot
 ******************************************************************************/

MyTblWzskMShot::MyTblWzskMShot() :
			TblWzskMShot()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskMShot::~MyTblWzskMShot() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskMShot::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMShot (refWzskMSession, refWzskMObject, start, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskMShot SET refWzskMSession = ?, refWzskMObject = ?, start = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMShot WHERE ref = ?", false);
};

bool MyTblWzskMShot::loadRecBySQL(
			const string& sqlstr
			, WzskMShot** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskMShot* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMShot::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMShot::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskMShot();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMSession = atoll((char*) dbrow[1]); else _rec->refWzskMSession = 0;
		if (dbrow[2]) _rec->refWzskMObject = atoll((char*) dbrow[2]); else _rec->refWzskMObject = 0;
		if (dbrow[3]) _rec->start = atol((char*) dbrow[3]); else _rec->start = 0;
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskMShot::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMShot& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskMShot* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMShot::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMShot::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskMShot();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMSession = atoll((char*) dbrow[1]); else rec->refWzskMSession = 0;
			if (dbrow[2]) rec->refWzskMObject = atoll((char*) dbrow[2]); else rec->refWzskMObject = 0;
			if (dbrow[3]) rec->start = atol((char*) dbrow[3]); else rec->start = 0;
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskMShot::insertRec(
			WzskMShot* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMSession,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWzskMObject,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->start,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskMShot::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskMShot::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskMShot::insertRst(
			ListWzskMShot& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskMShot::updateRec(
			WzskMShot* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMSession,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWzskMObject,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->start,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskMShot::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskMShot::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskMShot::updateRst(
			ListWzskMShot& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskMShot::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskMShot::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskMShot::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskMShot::loadRecByRef(
			ubigint ref
			, WzskMShot** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskMShot WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzskMShot::loadRstBySes(
			ubigint refWzskMSession
			, const bool append
			, ListWzskMShot& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMSession, refWzskMObject, start, Comment FROM TblWzskMShot WHERE refWzskMSession = " + to_string(refWzskMSession) + "", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskMShot
 ******************************************************************************/

LiteTblWzskMShot::LiteTblWzskMShot() :
			TblWzskMShot()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstBySes = NULL;
};

LiteTblWzskMShot::~LiteTblWzskMShot() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstBySes) sqlite3_finalize(stmtLoadRstBySes);
};

void LiteTblWzskMShot::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMShot (refWzskMSession, refWzskMObject, start, Comment) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskMShot SET refWzskMSession = ?1, refWzskMObject = ?2, start = ?3, Comment = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMShot WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMSession, refWzskMObject, start, Comment FROM TblWzskMShot WHERE ref = ?1");
	stmtLoadRstBySes = createStatement("SELECT ref, refWzskMSession, refWzskMObject, start, Comment FROM TblWzskMShot WHERE refWzskMSession = ?1");
};

bool LiteTblWzskMShot::loadRec(
			sqlite3_stmt* stmt
			, WzskMShot** rec
		) {
	int res;

	WzskMShot* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskMShot();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMSession = sqlite3_column_int64(stmt, 1);
		_rec->refWzskMObject = sqlite3_column_int64(stmt, 2);
		_rec->start = sqlite3_column_int(stmt, 3);
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblWzskMShot::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMShot& rst
		) {
	int res; ubigint numread = 0;

	WzskMShot* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskMShot();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMSession = sqlite3_column_int64(stmt, 1);
		rec->refWzskMObject = sqlite3_column_int64(stmt, 2);
		rec->start = sqlite3_column_int(stmt, 3);
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskMShot::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskMShot** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskMShot::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMShot& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskMShot::loadRecBySQL(
			const string& sqlstr
			, WzskMShot** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMShot::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMShot::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMShot& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMShot::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMShot::insertRec(
			WzskMShot* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMSession);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->refWzskMObject);
	sqlite3_bind_int(stmtInsertRec, 3, rec->start);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMShot::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskMShot::insertRst(
			ListWzskMShot& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskMShot::updateRec(
			WzskMShot* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMSession);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->refWzskMObject);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->start);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMShot::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskMShot::updateRst(
			ListWzskMShot& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskMShot::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMShot::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskMShot::loadRecByRef(
			ubigint ref
			, WzskMShot** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzskMShot::loadRstBySes(
			ubigint refWzskMSession
			, const bool append
			, ListWzskMShot& rst
		) {
	sqlite3_bind_int64(stmtLoadRstBySes, 1, refWzskMSession);

	return loadRstByStmt(stmtLoadRstBySes, append, rst);
};

#endif

