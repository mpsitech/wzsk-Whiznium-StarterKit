/**
	* \file WzskAMUsergroupAccess.cpp
	* database access for table TblWzskAMUsergroupAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskAMUsergroupAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskAMUsergroupAccess
 ******************************************************************************/

WzskAMUsergroupAccess::WzskAMUsergroupAccess(
			const ubigint ref
			, const ubigint refWzskMUsergroup
			, const uint x1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
		) {

	this->ref = ref;
	this->refWzskMUsergroup = refWzskMUsergroup;
	this->x1IxWzskVFeatgroup = x1IxWzskVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzskWAccess = ixWzskWAccess;
};

bool WzskAMUsergroupAccess::operator==(
			const WzskAMUsergroupAccess& comp
		) {
	return false;
};

bool WzskAMUsergroupAccess::operator!=(
			const WzskAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskAMUsergroupAccess
 ******************************************************************************/

ListWzskAMUsergroupAccess::ListWzskAMUsergroupAccess() {
};

ListWzskAMUsergroupAccess::ListWzskAMUsergroupAccess(
			const ListWzskAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskAMUsergroupAccess(*(src.nodes[i]));
};

ListWzskAMUsergroupAccess::~ListWzskAMUsergroupAccess() {
	clear();
};

void ListWzskAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListWzskAMUsergroupAccess::append(
			WzskAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

WzskAMUsergroupAccess* ListWzskAMUsergroupAccess::operator[](
			const uint ix
		) {
	WzskAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskAMUsergroupAccess& ListWzskAMUsergroupAccess::operator=(
			const ListWzskAMUsergroupAccess& src
		) {
	WzskAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskAMUsergroupAccess::operator==(
			const ListWzskAMUsergroupAccess& comp
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

bool ListWzskAMUsergroupAccess::operator!=(
			const ListWzskAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskAMUsergroupAccess
 ******************************************************************************/

TblWzskAMUsergroupAccess::TblWzskAMUsergroupAccess() {
};

TblWzskAMUsergroupAccess::~TblWzskAMUsergroupAccess() {
};

bool TblWzskAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WzskAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblWzskAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblWzskAMUsergroupAccess::insertRec(
			WzskAMUsergroupAccess* rec
		) {
	return 0;
};

ubigint TblWzskAMUsergroupAccess::insertNewRec(
			WzskAMUsergroupAccess** rec
			, const ubigint refWzskMUsergroup
			, const uint x1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
		) {
	ubigint retval = 0;
	WzskAMUsergroupAccess* _rec = NULL;

	_rec = new WzskAMUsergroupAccess(0, refWzskMUsergroup, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskAMUsergroupAccess::appendNewRecToRst(
			ListWzskAMUsergroupAccess& rst
			, WzskAMUsergroupAccess** rec
			, const ubigint refWzskMUsergroup
			, const uint x1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
		) {
	ubigint retval = 0;
	WzskAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMUsergroup, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskAMUsergroupAccess::insertRst(
			ListWzskAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblWzskAMUsergroupAccess::updateRec(
			WzskAMUsergroupAccess* rec
		) {
};

void TblWzskAMUsergroupAccess::updateRst(
			ListWzskAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblWzskAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WzskAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblWzskAMUsergroupAccess::loadRefsByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzskAMUsergroupAccess::loadRstByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblWzskAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	WzskAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskAMUsergroupAccess
 ******************************************************************************/

MyTblWzskAMUsergroupAccess::MyTblWzskAMUsergroupAccess() :
			TblWzskAMUsergroupAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskAMUsergroupAccess::~MyTblWzskAMUsergroupAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAMUsergroupAccess (refWzskMUsergroup, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskAMUsergroupAccess SET refWzskMUsergroup = ?, x1IxWzskVFeatgroup = ?, x2FeaSrefUix = ?, ixWzskWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAMUsergroupAccess WHERE ref = ?", false);
};

bool MyTblWzskAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WzskAMUsergroupAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskAMUsergroupAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAMUsergroupAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAMUsergroupAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskAMUsergroupAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMUsergroup = atoll((char*) dbrow[1]); else _rec->refWzskMUsergroup = 0;
		if (dbrow[2]) _rec->x1IxWzskVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxWzskVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixWzskWAccess = atol((char*) dbrow[4]); else _rec->ixWzskWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskAMUsergroupAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAMUsergroupAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAMUsergroupAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskAMUsergroupAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMUsergroup = atoll((char*) dbrow[1]); else rec->refWzskMUsergroup = 0;
			if (dbrow[2]) rec->x1IxWzskVFeatgroup = atol((char*) dbrow[2]); else rec->x1IxWzskVFeatgroup = 0;
			if (dbrow[3]) rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else rec->x2FeaSrefUix = "";
			if (dbrow[4]) rec->ixWzskWAccess = atol((char*) dbrow[4]); else rec->ixWzskWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskAMUsergroupAccess::insertRec(
			WzskAMUsergroupAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzskVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskAMUsergroupAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskAMUsergroupAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskAMUsergroupAccess::insertRst(
			ListWzskAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskAMUsergroupAccess::updateRec(
			WzskAMUsergroupAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzskVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskAMUsergroupAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskAMUsergroupAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskAMUsergroupAccess::updateRst(
			ListWzskAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskAMUsergroupAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskAMUsergroupAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WzskAMUsergroupAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskAMUsergroupAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzskAMUsergroupAccess::loadRefsByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskAMUsergroupAccess WHERE refWzskMUsergroup = " + to_string(refWzskMUsergroup) + "", append, refs);
};

ubigint MyTblWzskAMUsergroupAccess::loadRstByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMUsergroup, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess FROM TblWzskAMUsergroupAccess WHERE refWzskMUsergroup = " + to_string(refWzskMUsergroup) + " ORDER BY x1IxWzskVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskAMUsergroupAccess
 ******************************************************************************/

LiteTblWzskAMUsergroupAccess::LiteTblWzskAMUsergroupAccess() :
			TblWzskAMUsergroupAccess()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsg = NULL;
	stmtLoadRstByUsg = NULL;
};

LiteTblWzskAMUsergroupAccess::~LiteTblWzskAMUsergroupAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsg) sqlite3_finalize(stmtLoadRefsByUsg);
	if (stmtLoadRstByUsg) sqlite3_finalize(stmtLoadRstByUsg);
};

void LiteTblWzskAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAMUsergroupAccess (refWzskMUsergroup, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskAMUsergroupAccess SET refWzskMUsergroup = ?1, x1IxWzskVFeatgroup = ?2, x2FeaSrefUix = ?3, ixWzskWAccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAMUsergroupAccess WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMUsergroup, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess FROM TblWzskAMUsergroupAccess WHERE ref = ?1");
	stmtLoadRefsByUsg = createStatement("SELECT ref FROM TblWzskAMUsergroupAccess WHERE refWzskMUsergroup = ?1");
	stmtLoadRstByUsg = createStatement("SELECT ref, refWzskMUsergroup, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess FROM TblWzskAMUsergroupAccess WHERE refWzskMUsergroup = ?1 ORDER BY x1IxWzskVFeatgroup ASC, x2FeaSrefUix ASC");
};

bool LiteTblWzskAMUsergroupAccess::loadRec(
			sqlite3_stmt* stmt
			, WzskAMUsergroupAccess** rec
		) {
	int res;

	WzskAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskAMUsergroupAccess();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 1);
		_rec->x1IxWzskVFeatgroup = sqlite3_column_int(stmt, 2);
		_rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->ixWzskWAccess = sqlite3_column_int(stmt, 4);

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

ubigint LiteTblWzskAMUsergroupAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	int res; ubigint numread = 0;

	WzskAMUsergroupAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskAMUsergroupAccess();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 1);
		rec->x1IxWzskVFeatgroup = sqlite3_column_int(stmt, 2);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->ixWzskWAccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskAMUsergroupAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskAMUsergroupAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskAMUsergroupAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WzskAMUsergroupAccess** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAMUsergroupAccess::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAMUsergroupAccess::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAMUsergroupAccess::insertRec(
			WzskAMUsergroupAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxWzskVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzskWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMUsergroupAccess::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskAMUsergroupAccess::insertRst(
			ListWzskAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskAMUsergroupAccess::updateRec(
			WzskAMUsergroupAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxWzskVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzskWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMUsergroupAccess::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskAMUsergroupAccess::updateRst(
			ListWzskAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMUsergroupAccess::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WzskAMUsergroupAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzskAMUsergroupAccess::loadRefsByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsg, 1, refWzskMUsergroup);

	return loadRefsByStmt(stmtLoadRefsByUsg, append, refs);
};

ubigint LiteTblWzskAMUsergroupAccess::loadRstByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, ListWzskAMUsergroupAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsg, 1, refWzskMUsergroup);

	return loadRstByStmt(stmtLoadRstByUsg, append, rst);
};

#endif
