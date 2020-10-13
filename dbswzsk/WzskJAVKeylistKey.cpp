/**
	* \file WzskJAVKeylistKey.cpp
	* database access for table TblWzskJAVKeylistKey (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "WzskJAVKeylistKey.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskJAVKeylistKey
 ******************************************************************************/

WzskJAVKeylistKey::WzskJAVKeylistKey(
			const ubigint ref
			, const ubigint refWzskAVKeylistKey
			, const uint x1IxWzskVLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refWzskAVKeylistKey = refWzskAVKeylistKey;
	this->x1IxWzskVLocale = x1IxWzskVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool WzskJAVKeylistKey::operator==(
			const WzskJAVKeylistKey& comp
		) {
	return false;
};

bool WzskJAVKeylistKey::operator!=(
			const WzskJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskJAVKeylistKey
 ******************************************************************************/

ListWzskJAVKeylistKey::ListWzskJAVKeylistKey() {
};

ListWzskJAVKeylistKey::ListWzskJAVKeylistKey(
			const ListWzskJAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskJAVKeylistKey(*(src.nodes[i]));
};

ListWzskJAVKeylistKey::~ListWzskJAVKeylistKey() {
	clear();
};

void ListWzskJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskJAVKeylistKey::size() const {
	return(nodes.size());
};

void ListWzskJAVKeylistKey::append(
			WzskJAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

WzskJAVKeylistKey* ListWzskJAVKeylistKey::operator[](
			const uint ix
		) {
	WzskJAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskJAVKeylistKey& ListWzskJAVKeylistKey::operator=(
			const ListWzskJAVKeylistKey& src
		) {
	WzskJAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskJAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskJAVKeylistKey::operator==(
			const ListWzskJAVKeylistKey& comp
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

bool ListWzskJAVKeylistKey::operator!=(
			const ListWzskJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskJAVKeylistKey
 ******************************************************************************/

TblWzskJAVKeylistKey::TblWzskJAVKeylistKey() {
};

TblWzskJAVKeylistKey::~TblWzskJAVKeylistKey() {
};

bool TblWzskJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzskJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWzskJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWzskJAVKeylistKey::insertRec(
			WzskJAVKeylistKey* rec
		) {
	return 0;
};

ubigint TblWzskJAVKeylistKey::insertNewRec(
			WzskJAVKeylistKey** rec
			, const ubigint refWzskAVKeylistKey
			, const uint x1IxWzskVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzskJAVKeylistKey* _rec = NULL;

	_rec = new WzskJAVKeylistKey(0, refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskJAVKeylistKey::appendNewRecToRst(
			ListWzskJAVKeylistKey& rst
			, WzskJAVKeylistKey** rec
			, const ubigint refWzskAVKeylistKey
			, const uint x1IxWzskVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzskJAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskJAVKeylistKey::insertRst(
			ListWzskJAVKeylistKey& rst
			, bool transact
		) {
};

void TblWzskJAVKeylistKey::updateRec(
			WzskJAVKeylistKey* rec
		) {
};

void TblWzskJAVKeylistKey::updateRst(
			ListWzskJAVKeylistKey& rst
			, bool transact
		) {
};

void TblWzskJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzskJAVKeylistKey** rec
		) {
	return false;
};

bool TblWzskJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWzskAVKeylistKey
			, uint x1IxWzskVLocale
			, WzskJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWzskJAVKeylistKey::loadRefsByKlk(
			ubigint refWzskAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzskJAVKeylistKey::loadRstByKlk(
			ubigint refWzskAVKeylistKey
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	return 0;
};

bool TblWzskJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWzskAVKeylistKey
			, uint x1IxWzskVLocale
			, string& Title
		) {
	return false;
};

ubigint TblWzskJAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	ubigint numload = 0;
	WzskJAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskJAVKeylistKey
 ******************************************************************************/

MyTblWzskJAVKeylistKey::MyTblWzskJAVKeylistKey() :
			TblWzskJAVKeylistKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskJAVKeylistKey::~MyTblWzskJAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskJAVKeylistKey (refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskJAVKeylistKey SET refWzskAVKeylistKey = ?, x1IxWzskVLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskJAVKeylistKey WHERE ref = ?", false);
};

bool MyTblWzskJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzskJAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskJAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskJAVKeylistKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskJAVKeylistKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskJAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskAVKeylistKey = atoll((char*) dbrow[1]); else _rec->refWzskAVKeylistKey = 0;
		if (dbrow[2]) _rec->x1IxWzskVLocale = atol((char*) dbrow[2]); else _rec->x1IxWzskVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskJAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskJAVKeylistKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskJAVKeylistKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskJAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskAVKeylistKey = atoll((char*) dbrow[1]); else rec->refWzskAVKeylistKey = 0;
			if (dbrow[2]) rec->x1IxWzskVLocale = atol((char*) dbrow[2]); else rec->x1IxWzskVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskJAVKeylistKey::insertRec(
			WzskJAVKeylistKey* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzskVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskJAVKeylistKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskJAVKeylistKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskJAVKeylistKey::insertRst(
			ListWzskJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskJAVKeylistKey::updateRec(
			WzskJAVKeylistKey* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzskVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskJAVKeylistKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskJAVKeylistKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskJAVKeylistKey::updateRst(
			ListWzskJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskJAVKeylistKey::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskJAVKeylistKey::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzskJAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskJAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWzskAVKeylistKey
			, uint x1IxWzskVLocale
			, WzskJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT ref, refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment FROM TblWzskJAVKeylistKey WHERE refWzskAVKeylistKey = " + to_string(refWzskAVKeylistKey) + " AND x1IxWzskVLocale = " + to_string(x1IxWzskVLocale) + "", rec);
};

ubigint MyTblWzskJAVKeylistKey::loadRefsByKlk(
			ubigint refWzskAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskJAVKeylistKey WHERE refWzskAVKeylistKey = " + to_string(refWzskAVKeylistKey) + "", append, refs);
};

ubigint MyTblWzskJAVKeylistKey::loadRstByKlk(
			ubigint refWzskAVKeylistKey
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment FROM TblWzskJAVKeylistKey WHERE refWzskAVKeylistKey = " + to_string(refWzskAVKeylistKey) + " ORDER BY x1IxWzskVLocale ASC", append, rst);
};

bool MyTblWzskJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWzskAVKeylistKey
			, uint x1IxWzskVLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWzskJAVKeylistKey WHERE refWzskAVKeylistKey = " + to_string(refWzskAVKeylistKey) + " AND x1IxWzskVLocale = " + to_string(x1IxWzskVLocale) + "", Title);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskJAVKeylistKey
 ******************************************************************************/

LiteTblWzskJAVKeylistKey::LiteTblWzskJAVKeylistKey() :
			TblWzskJAVKeylistKey()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByKlkLcl = NULL;
	stmtLoadRefsByKlk = NULL;
	stmtLoadRstByKlk = NULL;
	stmtLoadTitByKlkLcl = NULL;
};

LiteTblWzskJAVKeylistKey::~LiteTblWzskJAVKeylistKey() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByKlkLcl) sqlite3_finalize(stmtLoadRecByKlkLcl);
	if (stmtLoadRefsByKlk) sqlite3_finalize(stmtLoadRefsByKlk);
	if (stmtLoadRstByKlk) sqlite3_finalize(stmtLoadRstByKlk);
	if (stmtLoadTitByKlkLcl) sqlite3_finalize(stmtLoadTitByKlkLcl);
};

void LiteTblWzskJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskJAVKeylistKey (refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskJAVKeylistKey SET refWzskAVKeylistKey = ?1, x1IxWzskVLocale = ?2, Title = ?3, Comment = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskJAVKeylistKey WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment FROM TblWzskJAVKeylistKey WHERE ref = ?1");
	stmtLoadRecByKlkLcl = createStatement("SELECT ref, refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment FROM TblWzskJAVKeylistKey WHERE refWzskAVKeylistKey = ?1 AND x1IxWzskVLocale = ?2");
	stmtLoadRefsByKlk = createStatement("SELECT ref FROM TblWzskJAVKeylistKey WHERE refWzskAVKeylistKey = ?1");
	stmtLoadRstByKlk = createStatement("SELECT ref, refWzskAVKeylistKey, x1IxWzskVLocale, Title, Comment FROM TblWzskJAVKeylistKey WHERE refWzskAVKeylistKey = ?1 ORDER BY x1IxWzskVLocale ASC");
	stmtLoadTitByKlkLcl = createStatement("SELECT Title FROM TblWzskJAVKeylistKey WHERE refWzskAVKeylistKey = ?1 AND x1IxWzskVLocale = ?2");
};

bool LiteTblWzskJAVKeylistKey::loadRec(
			sqlite3_stmt* stmt
			, WzskJAVKeylistKey** rec
		) {
	int res;

	WzskJAVKeylistKey* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskJAVKeylistKey();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskAVKeylistKey = sqlite3_column_int64(stmt, 1);
		_rec->x1IxWzskVLocale = sqlite3_column_int(stmt, 2);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 3));
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

ubigint LiteTblWzskJAVKeylistKey::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	int res; ubigint numread = 0;

	WzskJAVKeylistKey* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskJAVKeylistKey();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskAVKeylistKey = sqlite3_column_int64(stmt, 1);
		rec->x1IxWzskVLocale = sqlite3_column_int(stmt, 2);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskJAVKeylistKey::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskJAVKeylistKey** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskJAVKeylistKey::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzskJAVKeylistKey** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskJAVKeylistKey::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskJAVKeylistKey::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskJAVKeylistKey::insertRec(
			WzskJAVKeylistKey* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskAVKeylistKey);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxWzskVLocale);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJAVKeylistKey::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskJAVKeylistKey::insertRst(
			ListWzskJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskJAVKeylistKey::updateRec(
			WzskJAVKeylistKey* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskAVKeylistKey);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxWzskVLocale);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJAVKeylistKey::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskJAVKeylistKey::updateRst(
			ListWzskJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJAVKeylistKey::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzskJAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWzskAVKeylistKey
			, uint x1IxWzskVLocale
			, WzskJAVKeylistKey** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByKlkLcl, 1, refWzskAVKeylistKey);
	sqlite3_bind_int(stmtLoadRecByKlkLcl, 2, x1IxWzskVLocale);

	return loadRecByStmt(stmtLoadRecByKlkLcl, rec);
};

ubigint LiteTblWzskJAVKeylistKey::loadRefsByKlk(
			ubigint refWzskAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByKlk, 1, refWzskAVKeylistKey);

	return loadRefsByStmt(stmtLoadRefsByKlk, append, refs);
};

ubigint LiteTblWzskJAVKeylistKey::loadRstByKlk(
			ubigint refWzskAVKeylistKey
			, const bool append
			, ListWzskJAVKeylistKey& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByKlk, 1, refWzskAVKeylistKey);

	return loadRstByStmt(stmtLoadRstByKlk, append, rst);
};

bool LiteTblWzskJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWzskAVKeylistKey
			, uint x1IxWzskVLocale
			, string& Title
		) {
	sqlite3_bind_int64(stmtLoadTitByKlkLcl, 1, refWzskAVKeylistKey);
	sqlite3_bind_int(stmtLoadTitByKlkLcl, 2, x1IxWzskVLocale);

	return loadStringByStmt(stmtLoadTitByKlkLcl, Title);
};

#endif

