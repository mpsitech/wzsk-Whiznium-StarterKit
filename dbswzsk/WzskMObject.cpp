/**
	* \file WzskMObject.cpp
	* database access for table TblWzskMObject (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "WzskMObject.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskMObject
 ******************************************************************************/

WzskMObject::WzskMObject(
			const ubigint ref
			, const ubigint refWzskMObjgroup
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refWzskMObjgroup = refWzskMObjgroup;
	this->Title = Title;
	this->Comment = Comment;
};

bool WzskMObject::operator==(
			const WzskMObject& comp
		) {
	return false;
};

bool WzskMObject::operator!=(
			const WzskMObject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskMObject
 ******************************************************************************/

ListWzskMObject::ListWzskMObject() {
};

ListWzskMObject::ListWzskMObject(
			const ListWzskMObject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskMObject(*(src.nodes[i]));
};

ListWzskMObject::~ListWzskMObject() {
	clear();
};

void ListWzskMObject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskMObject::size() const {
	return(nodes.size());
};

void ListWzskMObject::append(
			WzskMObject* rec
		) {
	nodes.push_back(rec);
};

WzskMObject* ListWzskMObject::operator[](
			const uint ix
		) {
	WzskMObject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskMObject& ListWzskMObject::operator=(
			const ListWzskMObject& src
		) {
	WzskMObject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskMObject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskMObject::operator==(
			const ListWzskMObject& comp
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

bool ListWzskMObject::operator!=(
			const ListWzskMObject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskMObject
 ******************************************************************************/

TblWzskMObject::TblWzskMObject() {
};

TblWzskMObject::~TblWzskMObject() {
};

bool TblWzskMObject::loadRecBySQL(
			const string& sqlstr
			, WzskMObject** rec
		) {
	return false;
};

ubigint TblWzskMObject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMObject& rst
		) {
	return 0;
};

ubigint TblWzskMObject::insertRec(
			WzskMObject* rec
		) {
	return 0;
};

ubigint TblWzskMObject::insertNewRec(
			WzskMObject** rec
			, const ubigint refWzskMObjgroup
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMObject* _rec = NULL;

	_rec = new WzskMObject(0, refWzskMObjgroup, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskMObject::appendNewRecToRst(
			ListWzskMObject& rst
			, WzskMObject** rec
			, const ubigint refWzskMObjgroup
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMObject* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMObjgroup, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskMObject::insertRst(
			ListWzskMObject& rst
			, bool transact
		) {
};

void TblWzskMObject::updateRec(
			WzskMObject* rec
		) {
};

void TblWzskMObject::updateRst(
			ListWzskMObject& rst
			, bool transact
		) {
};

void TblWzskMObject::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskMObject::loadRecByRef(
			ubigint ref
			, WzskMObject** rec
		) {
	return false;
};

ubigint TblWzskMObject::loadRstByOgr(
			ubigint refWzskMObjgroup
			, const bool append
			, ListWzskMObject& rst
		) {
	return 0;
};

bool TblWzskMObject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWzskMObject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskMObject& rst
		) {
	ubigint numload = 0;
	WzskMObject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskMObject
 ******************************************************************************/

MyTblWzskMObject::MyTblWzskMObject() :
			TblWzskMObject()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskMObject::~MyTblWzskMObject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskMObject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMObject (refWzskMObjgroup, Title, Comment) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskMObject SET refWzskMObjgroup = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMObject WHERE ref = ?", false);
};

bool MyTblWzskMObject::loadRecBySQL(
			const string& sqlstr
			, WzskMObject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskMObject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMObject::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMObject::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskMObject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMObjgroup = atoll((char*) dbrow[1]); else _rec->refWzskMObjgroup = 0;
		if (dbrow[2]) _rec->Title.assign(dbrow[2], dblengths[2]); else _rec->Title = "";
		if (dbrow[3]) _rec->Comment.assign(dbrow[3], dblengths[3]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskMObject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMObject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskMObject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMObject::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMObject::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskMObject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMObjgroup = atoll((char*) dbrow[1]); else rec->refWzskMObjgroup = 0;
			if (dbrow[2]) rec->Title.assign(dbrow[2], dblengths[2]); else rec->Title = "";
			if (dbrow[3]) rec->Comment.assign(dbrow[3], dblengths[3]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskMObject::insertRec(
			WzskMObject* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->Title.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMObjgroup,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskMObject::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskMObject::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskMObject::insertRst(
			ListWzskMObject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskMObject::updateRec(
			WzskMObject* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->Title.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMObjgroup,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskMObject::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskMObject::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskMObject::updateRst(
			ListWzskMObject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskMObject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskMObject::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskMObject::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskMObject::loadRecByRef(
			ubigint ref
			, WzskMObject** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskMObject WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzskMObject::loadRstByOgr(
			ubigint refWzskMObjgroup
			, const bool append
			, ListWzskMObject& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMObjgroup, Title, Comment FROM TblWzskMObject WHERE refWzskMObjgroup = " + to_string(refWzskMObjgroup) + " ORDER BY Title ASC", append, rst);
};

bool MyTblWzskMObject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWzskMObject WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskMObject
 ******************************************************************************/

LiteTblWzskMObject::LiteTblWzskMObject() :
			TblWzskMObject()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByOgr = NULL;
	stmtLoadTitByRef = NULL;
};

LiteTblWzskMObject::~LiteTblWzskMObject() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByOgr) sqlite3_finalize(stmtLoadRstByOgr);
	if (stmtLoadTitByRef) sqlite3_finalize(stmtLoadTitByRef);
};

void LiteTblWzskMObject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMObject (refWzskMObjgroup, Title, Comment) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzskMObject SET refWzskMObjgroup = ?1, Title = ?2, Comment = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMObject WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMObjgroup, Title, Comment FROM TblWzskMObject WHERE ref = ?1");
	stmtLoadRstByOgr = createStatement("SELECT ref, refWzskMObjgroup, Title, Comment FROM TblWzskMObject WHERE refWzskMObjgroup = ?1 ORDER BY Title ASC");
	stmtLoadTitByRef = createStatement("SELECT Title FROM TblWzskMObject WHERE ref = ?1");
};

bool LiteTblWzskMObject::loadRec(
			sqlite3_stmt* stmt
			, WzskMObject** rec
		) {
	int res;

	WzskMObject* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskMObject();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMObjgroup = sqlite3_column_int64(stmt, 1);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 2));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 3));

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

ubigint LiteTblWzskMObject::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMObject& rst
		) {
	int res; ubigint numread = 0;

	WzskMObject* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskMObject();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMObjgroup = sqlite3_column_int64(stmt, 1);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 2));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskMObject::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskMObject** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskMObject::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMObject& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskMObject::loadRecBySQL(
			const string& sqlstr
			, WzskMObject** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMObject::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMObject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMObject& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMObject::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMObject::insertRec(
			WzskMObject* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMObjgroup);
	sqlite3_bind_text(stmtInsertRec, 2, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMObject::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskMObject::insertRst(
			ListWzskMObject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskMObject::updateRec(
			WzskMObject* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMObjgroup);
	sqlite3_bind_text(stmtUpdateRec, 2, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMObject::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskMObject::updateRst(
			ListWzskMObject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskMObject::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMObject::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskMObject::loadRecByRef(
			ubigint ref
			, WzskMObject** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzskMObject::loadRstByOgr(
			ubigint refWzskMObjgroup
			, const bool append
			, ListWzskMObject& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByOgr, 1, refWzskMObjgroup);

	return loadRstByStmt(stmtLoadRstByOgr, append, rst);
};

bool LiteTblWzskMObject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	sqlite3_bind_int64(stmtLoadTitByRef, 1, ref);

	return loadStringByStmt(stmtLoadTitByRef, Title);
};

#endif

