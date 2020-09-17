/**
	* \file WzskAMShotPar.cpp
	* database access for table TblWzskAMShotPar (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "WzskAMShotPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskAMShotPar
 ******************************************************************************/

WzskAMShotPar::WzskAMShotPar(
			const ubigint ref
			, const ubigint refWzskMShot
			, const string x1SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->refWzskMShot = refWzskMShot;
	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

bool WzskAMShotPar::operator==(
			const WzskAMShotPar& comp
		) {
	return false;
};

bool WzskAMShotPar::operator!=(
			const WzskAMShotPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskAMShotPar
 ******************************************************************************/

ListWzskAMShotPar::ListWzskAMShotPar() {
};

ListWzskAMShotPar::ListWzskAMShotPar(
			const ListWzskAMShotPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskAMShotPar(*(src.nodes[i]));
};

ListWzskAMShotPar::~ListWzskAMShotPar() {
	clear();
};

void ListWzskAMShotPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskAMShotPar::size() const {
	return(nodes.size());
};

void ListWzskAMShotPar::append(
			WzskAMShotPar* rec
		) {
	nodes.push_back(rec);
};

WzskAMShotPar* ListWzskAMShotPar::operator[](
			const uint ix
		) {
	WzskAMShotPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskAMShotPar& ListWzskAMShotPar::operator=(
			const ListWzskAMShotPar& src
		) {
	WzskAMShotPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskAMShotPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskAMShotPar::operator==(
			const ListWzskAMShotPar& comp
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

bool ListWzskAMShotPar::operator!=(
			const ListWzskAMShotPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskAMShotPar
 ******************************************************************************/

TblWzskAMShotPar::TblWzskAMShotPar() {
};

TblWzskAMShotPar::~TblWzskAMShotPar() {
};

bool TblWzskAMShotPar::loadRecBySQL(
			const string& sqlstr
			, WzskAMShotPar** rec
		) {
	return false;
};

ubigint TblWzskAMShotPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	return 0;
};

ubigint TblWzskAMShotPar::insertRec(
			WzskAMShotPar* rec
		) {
	return 0;
};

ubigint TblWzskAMShotPar::insertNewRec(
			WzskAMShotPar** rec
			, const ubigint refWzskMShot
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WzskAMShotPar* _rec = NULL;

	_rec = new WzskAMShotPar(0, refWzskMShot, x1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskAMShotPar::appendNewRecToRst(
			ListWzskAMShotPar& rst
			, WzskAMShotPar** rec
			, const ubigint refWzskMShot
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WzskAMShotPar* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMShot, x1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskAMShotPar::insertRst(
			ListWzskAMShotPar& rst
			, bool transact
		) {
};

void TblWzskAMShotPar::updateRec(
			WzskAMShotPar* rec
		) {
};

void TblWzskAMShotPar::updateRst(
			ListWzskAMShotPar& rst
			, bool transact
		) {
};

void TblWzskAMShotPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskAMShotPar::loadRecByRef(
			ubigint ref
			, WzskAMShotPar** rec
		) {
	return false;
};

ubigint TblWzskAMShotPar::loadRstBySht(
			ubigint refWzskMShot
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	return 0;
};

ubigint TblWzskAMShotPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	ubigint numload = 0;
	WzskAMShotPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskAMShotPar
 ******************************************************************************/

MyTblWzskAMShotPar::MyTblWzskAMShotPar() :
			TblWzskAMShotPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskAMShotPar::~MyTblWzskAMShotPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskAMShotPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAMShotPar (refWzskMShot, x1SrefKKey, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskAMShotPar SET refWzskMShot = ?, x1SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAMShotPar WHERE ref = ?", false);
};

bool MyTblWzskAMShotPar::loadRecBySQL(
			const string& sqlstr
			, WzskAMShotPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskAMShotPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAMShotPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAMShotPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskAMShotPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMShot = atoll((char*) dbrow[1]); else _rec->refWzskMShot = 0;
		if (dbrow[2]) _rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKKey = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskAMShotPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskAMShotPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAMShotPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAMShotPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskAMShotPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMShot = atoll((char*) dbrow[1]); else rec->refWzskMShot = 0;
			if (dbrow[2]) rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else rec->x1SrefKKey = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskAMShotPar::insertRec(
			WzskAMShotPar* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMShot,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskAMShotPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskAMShotPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskAMShotPar::insertRst(
			ListWzskAMShotPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskAMShotPar::updateRec(
			WzskAMShotPar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMShot,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskAMShotPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskAMShotPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskAMShotPar::updateRst(
			ListWzskAMShotPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskAMShotPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskAMShotPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskAMShotPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskAMShotPar::loadRecByRef(
			ubigint ref
			, WzskAMShotPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskAMShotPar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzskAMShotPar::loadRstBySht(
			ubigint refWzskMShot
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMShot, x1SrefKKey, Val FROM TblWzskAMShotPar WHERE refWzskMShot = " + to_string(refWzskMShot) + " ORDER BY x1SrefKKey ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskAMShotPar
 ******************************************************************************/

LiteTblWzskAMShotPar::LiteTblWzskAMShotPar() :
			TblWzskAMShotPar()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstBySht = NULL;
};

LiteTblWzskAMShotPar::~LiteTblWzskAMShotPar() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstBySht) sqlite3_finalize(stmtLoadRstBySht);
};

void LiteTblWzskAMShotPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAMShotPar (refWzskMShot, x1SrefKKey, Val) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzskAMShotPar SET refWzskMShot = ?1, x1SrefKKey = ?2, Val = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAMShotPar WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMShot, x1SrefKKey, Val FROM TblWzskAMShotPar WHERE ref = ?1");
	stmtLoadRstBySht = createStatement("SELECT ref, refWzskMShot, x1SrefKKey, Val FROM TblWzskAMShotPar WHERE refWzskMShot = ?1 ORDER BY x1SrefKKey ASC");
};

bool LiteTblWzskAMShotPar::loadRec(
			sqlite3_stmt* stmt
			, WzskAMShotPar** rec
		) {
	int res;

	WzskAMShotPar* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskAMShotPar();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMShot = sqlite3_column_int64(stmt, 1);
		_rec->x1SrefKKey.assign((const char*) sqlite3_column_text(stmt, 2));
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 3));

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

ubigint LiteTblWzskAMShotPar::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	int res; ubigint numread = 0;

	WzskAMShotPar* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskAMShotPar();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMShot = sqlite3_column_int64(stmt, 1);
		rec->x1SrefKKey.assign((const char*) sqlite3_column_text(stmt, 2));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskAMShotPar::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskAMShotPar** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskAMShotPar::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskAMShotPar::loadRecBySQL(
			const string& sqlstr
			, WzskAMShotPar** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAMShotPar::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAMShotPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAMShotPar::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAMShotPar::insertRec(
			WzskAMShotPar* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMShot);
	sqlite3_bind_text(stmtInsertRec, 2, rec->x1SrefKKey.c_str(), rec->x1SrefKKey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMShotPar::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskAMShotPar::insertRst(
			ListWzskAMShotPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskAMShotPar::updateRec(
			WzskAMShotPar* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMShot);
	sqlite3_bind_text(stmtUpdateRec, 2, rec->x1SrefKKey.c_str(), rec->x1SrefKKey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMShotPar::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskAMShotPar::updateRst(
			ListWzskAMShotPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskAMShotPar::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMShotPar::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskAMShotPar::loadRecByRef(
			ubigint ref
			, WzskAMShotPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzskAMShotPar::loadRstBySht(
			ubigint refWzskMShot
			, const bool append
			, ListWzskAMShotPar& rst
		) {
	sqlite3_bind_int64(stmtLoadRstBySht, 1, refWzskMShot);

	return loadRstByStmt(stmtLoadRstBySht, append, rst);
};

#endif

