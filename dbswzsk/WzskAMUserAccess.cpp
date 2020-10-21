/**
	* \file WzskAMUserAccess.cpp
	* database access for table TblWzskAMUserAccess (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "WzskAMUserAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskAMUserAccess
 ******************************************************************************/

WzskAMUserAccess::WzskAMUserAccess(
			const ubigint ref
			, const ubigint refWzskMUser
			, const uint x1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
		) {

	this->ref = ref;
	this->refWzskMUser = refWzskMUser;
	this->x1IxWzskVFeatgroup = x1IxWzskVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzskWAccess = ixWzskWAccess;
};

bool WzskAMUserAccess::operator==(
			const WzskAMUserAccess& comp
		) {
	return false;
};

bool WzskAMUserAccess::operator!=(
			const WzskAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskAMUserAccess
 ******************************************************************************/

ListWzskAMUserAccess::ListWzskAMUserAccess() {
};

ListWzskAMUserAccess::ListWzskAMUserAccess(
			const ListWzskAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskAMUserAccess(*(src.nodes[i]));
};

ListWzskAMUserAccess::~ListWzskAMUserAccess() {
	clear();
};

void ListWzskAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskAMUserAccess::size() const {
	return(nodes.size());
};

void ListWzskAMUserAccess::append(
			WzskAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

WzskAMUserAccess* ListWzskAMUserAccess::operator[](
			const uint ix
		) {
	WzskAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskAMUserAccess& ListWzskAMUserAccess::operator=(
			const ListWzskAMUserAccess& src
		) {
	WzskAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskAMUserAccess::operator==(
			const ListWzskAMUserAccess& comp
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

bool ListWzskAMUserAccess::operator!=(
			const ListWzskAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskAMUserAccess
 ******************************************************************************/

TblWzskAMUserAccess::TblWzskAMUserAccess() {
};

TblWzskAMUserAccess::~TblWzskAMUserAccess() {
};

bool TblWzskAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WzskAMUserAccess** rec
		) {
	return false;
};

ubigint TblWzskAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	return 0;
};

ubigint TblWzskAMUserAccess::insertRec(
			WzskAMUserAccess* rec
		) {
	return 0;
};

ubigint TblWzskAMUserAccess::insertNewRec(
			WzskAMUserAccess** rec
			, const ubigint refWzskMUser
			, const uint x1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
		) {
	ubigint retval = 0;
	WzskAMUserAccess* _rec = NULL;

	_rec = new WzskAMUserAccess(0, refWzskMUser, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskAMUserAccess::appendNewRecToRst(
			ListWzskAMUserAccess& rst
			, WzskAMUserAccess** rec
			, const ubigint refWzskMUser
			, const uint x1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
		) {
	ubigint retval = 0;
	WzskAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMUser, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskAMUserAccess::insertRst(
			ListWzskAMUserAccess& rst
			, bool transact
		) {
};

void TblWzskAMUserAccess::updateRec(
			WzskAMUserAccess* rec
		) {
};

void TblWzskAMUserAccess::updateRst(
			ListWzskAMUserAccess& rst
			, bool transact
		) {
};

void TblWzskAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskAMUserAccess::loadRecByRef(
			ubigint ref
			, WzskAMUserAccess** rec
		) {
	return false;
};

ubigint TblWzskAMUserAccess::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzskAMUserAccess::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	return 0;
};

ubigint TblWzskAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	ubigint numload = 0;
	WzskAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskAMUserAccess
 ******************************************************************************/

MyTblWzskAMUserAccess::MyTblWzskAMUserAccess() :
			TblWzskAMUserAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskAMUserAccess::~MyTblWzskAMUserAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAMUserAccess (refWzskMUser, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskAMUserAccess SET refWzskMUser = ?, x1IxWzskVFeatgroup = ?, x2FeaSrefUix = ?, ixWzskWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAMUserAccess WHERE ref = ?", false);
};

bool MyTblWzskAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WzskAMUserAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskAMUserAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAMUserAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAMUserAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskAMUserAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMUser = atoll((char*) dbrow[1]); else _rec->refWzskMUser = 0;
		if (dbrow[2]) _rec->x1IxWzskVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxWzskVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixWzskWAccess = atol((char*) dbrow[4]); else _rec->ixWzskWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskAMUserAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAMUserAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAMUserAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskAMUserAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMUser = atoll((char*) dbrow[1]); else rec->refWzskMUser = 0;
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

ubigint MyTblWzskAMUserAccess::insertRec(
			WzskAMUserAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzskVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskAMUserAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskAMUserAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskAMUserAccess::insertRst(
			ListWzskAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskAMUserAccess::updateRec(
			WzskAMUserAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzskVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskAMUserAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskAMUserAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskAMUserAccess::updateRst(
			ListWzskAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskAMUserAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskAMUserAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskAMUserAccess::loadRecByRef(
			ubigint ref
			, WzskAMUserAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskAMUserAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzskAMUserAccess::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskAMUserAccess WHERE refWzskMUser = " + to_string(refWzskMUser) + "", append, refs);
};

ubigint MyTblWzskAMUserAccess::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMUser, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess FROM TblWzskAMUserAccess WHERE refWzskMUser = " + to_string(refWzskMUser) + " ORDER BY x1IxWzskVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskAMUserAccess
 ******************************************************************************/

LiteTblWzskAMUserAccess::LiteTblWzskAMUserAccess() :
			TblWzskAMUserAccess()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblWzskAMUserAccess::~LiteTblWzskAMUserAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblWzskAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAMUserAccess (refWzskMUser, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskAMUserAccess SET refWzskMUser = ?1, x1IxWzskVFeatgroup = ?2, x2FeaSrefUix = ?3, ixWzskWAccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAMUserAccess WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMUser, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess FROM TblWzskAMUserAccess WHERE ref = ?1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblWzskAMUserAccess WHERE refWzskMUser = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refWzskMUser, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess FROM TblWzskAMUserAccess WHERE refWzskMUser = ?1 ORDER BY x1IxWzskVFeatgroup ASC, x2FeaSrefUix ASC");
};

bool LiteTblWzskAMUserAccess::loadRec(
			sqlite3_stmt* stmt
			, WzskAMUserAccess** rec
		) {
	int res;

	WzskAMUserAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskAMUserAccess();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
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

ubigint LiteTblWzskAMUserAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	int res; ubigint numread = 0;

	WzskAMUserAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskAMUserAccess();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		rec->x1IxWzskVFeatgroup = sqlite3_column_int(stmt, 2);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->ixWzskWAccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskAMUserAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskAMUserAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskAMUserAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WzskAMUserAccess** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAMUserAccess::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAMUserAccess::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAMUserAccess::insertRec(
			WzskAMUserAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxWzskVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzskWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMUserAccess::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskAMUserAccess::insertRst(
			ListWzskAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskAMUserAccess::updateRec(
			WzskAMUserAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxWzskVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzskWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMUserAccess::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskAMUserAccess::updateRst(
			ListWzskAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMUserAccess::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskAMUserAccess::loadRecByRef(
			ubigint ref
			, WzskAMUserAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzskAMUserAccess::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refWzskMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblWzskAMUserAccess::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskAMUserAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refWzskMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

#endif

