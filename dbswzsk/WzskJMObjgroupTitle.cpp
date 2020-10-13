/**
	* \file WzskJMObjgroupTitle.cpp
	* database access for table TblWzskJMObjgroupTitle (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "WzskJMObjgroupTitle.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskJMObjgroupTitle
 ******************************************************************************/

WzskJMObjgroupTitle::WzskJMObjgroupTitle(
			const ubigint ref
			, const ubigint refWzskMObjgroup
			, const uint x1IxWzskVLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWzskMObjgroup = refWzskMObjgroup;
	this->x1IxWzskVLocale = x1IxWzskVLocale;
	this->Title = Title;
};

bool WzskJMObjgroupTitle::operator==(
			const WzskJMObjgroupTitle& comp
		) {
	return false;
};

bool WzskJMObjgroupTitle::operator!=(
			const WzskJMObjgroupTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskJMObjgroupTitle
 ******************************************************************************/

ListWzskJMObjgroupTitle::ListWzskJMObjgroupTitle() {
};

ListWzskJMObjgroupTitle::ListWzskJMObjgroupTitle(
			const ListWzskJMObjgroupTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskJMObjgroupTitle(*(src.nodes[i]));
};

ListWzskJMObjgroupTitle::~ListWzskJMObjgroupTitle() {
	clear();
};

void ListWzskJMObjgroupTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskJMObjgroupTitle::size() const {
	return(nodes.size());
};

void ListWzskJMObjgroupTitle::append(
			WzskJMObjgroupTitle* rec
		) {
	nodes.push_back(rec);
};

WzskJMObjgroupTitle* ListWzskJMObjgroupTitle::operator[](
			const uint ix
		) {
	WzskJMObjgroupTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskJMObjgroupTitle& ListWzskJMObjgroupTitle::operator=(
			const ListWzskJMObjgroupTitle& src
		) {
	WzskJMObjgroupTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskJMObjgroupTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskJMObjgroupTitle::operator==(
			const ListWzskJMObjgroupTitle& comp
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

bool ListWzskJMObjgroupTitle::operator!=(
			const ListWzskJMObjgroupTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskJMObjgroupTitle
 ******************************************************************************/

TblWzskJMObjgroupTitle::TblWzskJMObjgroupTitle() {
};

TblWzskJMObjgroupTitle::~TblWzskJMObjgroupTitle() {
};

bool TblWzskJMObjgroupTitle::loadRecBySQL(
			const string& sqlstr
			, WzskJMObjgroupTitle** rec
		) {
	return false;
};

ubigint TblWzskJMObjgroupTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	return 0;
};

ubigint TblWzskJMObjgroupTitle::insertRec(
			WzskJMObjgroupTitle* rec
		) {
	return 0;
};

ubigint TblWzskJMObjgroupTitle::insertNewRec(
			WzskJMObjgroupTitle** rec
			, const ubigint refWzskMObjgroup
			, const uint x1IxWzskVLocale
			, const string Title
		) {
	ubigint retval = 0;
	WzskJMObjgroupTitle* _rec = NULL;

	_rec = new WzskJMObjgroupTitle(0, refWzskMObjgroup, x1IxWzskVLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskJMObjgroupTitle::appendNewRecToRst(
			ListWzskJMObjgroupTitle& rst
			, WzskJMObjgroupTitle** rec
			, const ubigint refWzskMObjgroup
			, const uint x1IxWzskVLocale
			, const string Title
		) {
	ubigint retval = 0;
	WzskJMObjgroupTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMObjgroup, x1IxWzskVLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskJMObjgroupTitle::insertRst(
			ListWzskJMObjgroupTitle& rst
			, bool transact
		) {
};

void TblWzskJMObjgroupTitle::updateRec(
			WzskJMObjgroupTitle* rec
		) {
};

void TblWzskJMObjgroupTitle::updateRst(
			ListWzskJMObjgroupTitle& rst
			, bool transact
		) {
};

void TblWzskJMObjgroupTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskJMObjgroupTitle::loadRecByRef(
			ubigint ref
			, WzskJMObjgroupTitle** rec
		) {
	return false;
};

bool TblWzskJMObjgroupTitle::loadRecByOgrLcl(
			ubigint refWzskMObjgroup
			, uint x1IxWzskVLocale
			, WzskJMObjgroupTitle** rec
		) {
	return false;
};

ubigint TblWzskJMObjgroupTitle::loadRstByOgr(
			ubigint refWzskMObjgroup
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	return 0;
};

ubigint TblWzskJMObjgroupTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	ubigint numload = 0;
	WzskJMObjgroupTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskJMObjgroupTitle
 ******************************************************************************/

MyTblWzskJMObjgroupTitle::MyTblWzskJMObjgroupTitle() :
			TblWzskJMObjgroupTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskJMObjgroupTitle::~MyTblWzskJMObjgroupTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskJMObjgroupTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskJMObjgroupTitle (refWzskMObjgroup, x1IxWzskVLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskJMObjgroupTitle SET refWzskMObjgroup = ?, x1IxWzskVLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskJMObjgroupTitle WHERE ref = ?", false);
};

bool MyTblWzskJMObjgroupTitle::loadRecBySQL(
			const string& sqlstr
			, WzskJMObjgroupTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskJMObjgroupTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskJMObjgroupTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskJMObjgroupTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskJMObjgroupTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMObjgroup = atoll((char*) dbrow[1]); else _rec->refWzskMObjgroup = 0;
		if (dbrow[2]) _rec->x1IxWzskVLocale = atol((char*) dbrow[2]); else _rec->x1IxWzskVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskJMObjgroupTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskJMObjgroupTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskJMObjgroupTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskJMObjgroupTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskJMObjgroupTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMObjgroup = atoll((char*) dbrow[1]); else rec->refWzskMObjgroup = 0;
			if (dbrow[2]) rec->x1IxWzskVLocale = atol((char*) dbrow[2]); else rec->x1IxWzskVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskJMObjgroupTitle::insertRec(
			WzskJMObjgroupTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMObjgroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzskVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskJMObjgroupTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskJMObjgroupTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskJMObjgroupTitle::insertRst(
			ListWzskJMObjgroupTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskJMObjgroupTitle::updateRec(
			WzskJMObjgroupTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMObjgroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzskVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskJMObjgroupTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskJMObjgroupTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskJMObjgroupTitle::updateRst(
			ListWzskJMObjgroupTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskJMObjgroupTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskJMObjgroupTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskJMObjgroupTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskJMObjgroupTitle::loadRecByRef(
			ubigint ref
			, WzskJMObjgroupTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskJMObjgroupTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskJMObjgroupTitle::loadRecByOgrLcl(
			ubigint refWzskMObjgroup
			, uint x1IxWzskVLocale
			, WzskJMObjgroupTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refWzskMObjgroup, x1IxWzskVLocale, Title FROM TblWzskJMObjgroupTitle WHERE refWzskMObjgroup = " + to_string(refWzskMObjgroup) + " AND x1IxWzskVLocale = " + to_string(x1IxWzskVLocale) + "", rec);
};

ubigint MyTblWzskJMObjgroupTitle::loadRstByOgr(
			ubigint refWzskMObjgroup
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMObjgroup, x1IxWzskVLocale, Title FROM TblWzskJMObjgroupTitle WHERE refWzskMObjgroup = " + to_string(refWzskMObjgroup) + " ORDER BY x1IxWzskVLocale ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskJMObjgroupTitle
 ******************************************************************************/

LiteTblWzskJMObjgroupTitle::LiteTblWzskJMObjgroupTitle() :
			TblWzskJMObjgroupTitle()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByOgrLcl = NULL;
	stmtLoadRstByOgr = NULL;
};

LiteTblWzskJMObjgroupTitle::~LiteTblWzskJMObjgroupTitle() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByOgrLcl) sqlite3_finalize(stmtLoadRecByOgrLcl);
	if (stmtLoadRstByOgr) sqlite3_finalize(stmtLoadRstByOgr);
};

void LiteTblWzskJMObjgroupTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskJMObjgroupTitle (refWzskMObjgroup, x1IxWzskVLocale, Title) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzskJMObjgroupTitle SET refWzskMObjgroup = ?1, x1IxWzskVLocale = ?2, Title = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskJMObjgroupTitle WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMObjgroup, x1IxWzskVLocale, Title FROM TblWzskJMObjgroupTitle WHERE ref = ?1");
	stmtLoadRecByOgrLcl = createStatement("SELECT ref, refWzskMObjgroup, x1IxWzskVLocale, Title FROM TblWzskJMObjgroupTitle WHERE refWzskMObjgroup = ?1 AND x1IxWzskVLocale = ?2");
	stmtLoadRstByOgr = createStatement("SELECT ref, refWzskMObjgroup, x1IxWzskVLocale, Title FROM TblWzskJMObjgroupTitle WHERE refWzskMObjgroup = ?1 ORDER BY x1IxWzskVLocale ASC");
};

bool LiteTblWzskJMObjgroupTitle::loadRec(
			sqlite3_stmt* stmt
			, WzskJMObjgroupTitle** rec
		) {
	int res;

	WzskJMObjgroupTitle* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskJMObjgroupTitle();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMObjgroup = sqlite3_column_int64(stmt, 1);
		_rec->x1IxWzskVLocale = sqlite3_column_int(stmt, 2);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 3));

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

ubigint LiteTblWzskJMObjgroupTitle::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	int res; ubigint numread = 0;

	WzskJMObjgroupTitle* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskJMObjgroupTitle();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMObjgroup = sqlite3_column_int64(stmt, 1);
		rec->x1IxWzskVLocale = sqlite3_column_int(stmt, 2);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskJMObjgroupTitle::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskJMObjgroupTitle** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskJMObjgroupTitle::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskJMObjgroupTitle::loadRecBySQL(
			const string& sqlstr
			, WzskJMObjgroupTitle** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskJMObjgroupTitle::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskJMObjgroupTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskJMObjgroupTitle::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskJMObjgroupTitle::insertRec(
			WzskJMObjgroupTitle* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMObjgroup);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxWzskVLocale);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMObjgroupTitle::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskJMObjgroupTitle::insertRst(
			ListWzskJMObjgroupTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskJMObjgroupTitle::updateRec(
			WzskJMObjgroupTitle* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMObjgroup);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxWzskVLocale);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMObjgroupTitle::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskJMObjgroupTitle::updateRst(
			ListWzskJMObjgroupTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskJMObjgroupTitle::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMObjgroupTitle::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskJMObjgroupTitle::loadRecByRef(
			ubigint ref
			, WzskJMObjgroupTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskJMObjgroupTitle::loadRecByOgrLcl(
			ubigint refWzskMObjgroup
			, uint x1IxWzskVLocale
			, WzskJMObjgroupTitle** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByOgrLcl, 1, refWzskMObjgroup);
	sqlite3_bind_int(stmtLoadRecByOgrLcl, 2, x1IxWzskVLocale);

	return loadRecByStmt(stmtLoadRecByOgrLcl, rec);
};

ubigint LiteTblWzskJMObjgroupTitle::loadRstByOgr(
			ubigint refWzskMObjgroup
			, const bool append
			, ListWzskJMObjgroupTitle& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByOgr, 1, refWzskMObjgroup);

	return loadRstByStmt(stmtLoadRstByOgr, append, rst);
};

#endif

