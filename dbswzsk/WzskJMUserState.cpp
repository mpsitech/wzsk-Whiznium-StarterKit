/**
	* \file WzskJMUserState.cpp
	* database access for table TblWzskJMUserState (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskJMUserState.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskJMUserState
 ******************************************************************************/

WzskJMUserState::WzskJMUserState(
			const ubigint ref
			, const ubigint refWzskMUser
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refWzskMUser = refWzskMUser;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool WzskJMUserState::operator==(
			const WzskJMUserState& comp
		) {
	return false;
};

bool WzskJMUserState::operator!=(
			const WzskJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskJMUserState
 ******************************************************************************/

ListWzskJMUserState::ListWzskJMUserState() {
};

ListWzskJMUserState::ListWzskJMUserState(
			const ListWzskJMUserState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskJMUserState(*(src.nodes[i]));
};

ListWzskJMUserState::~ListWzskJMUserState() {
	clear();
};

void ListWzskJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskJMUserState::size() const {
	return(nodes.size());
};

void ListWzskJMUserState::append(
			WzskJMUserState* rec
		) {
	nodes.push_back(rec);
};

WzskJMUserState* ListWzskJMUserState::operator[](
			const uint ix
		) {
	WzskJMUserState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskJMUserState& ListWzskJMUserState::operator=(
			const ListWzskJMUserState& src
		) {
	WzskJMUserState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskJMUserState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskJMUserState::operator==(
			const ListWzskJMUserState& comp
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

bool ListWzskJMUserState::operator!=(
			const ListWzskJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskJMUserState
 ******************************************************************************/

TblWzskJMUserState::TblWzskJMUserState() {
};

TblWzskJMUserState::~TblWzskJMUserState() {
};

bool TblWzskJMUserState::loadRecBySQL(
			const string& sqlstr
			, WzskJMUserState** rec
		) {
	return false;
};

ubigint TblWzskJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMUserState& rst
		) {
	return 0;
};

ubigint TblWzskJMUserState::insertRec(
			WzskJMUserState* rec
		) {
	return 0;
};

ubigint TblWzskJMUserState::insertNewRec(
			WzskJMUserState** rec
			, const ubigint refWzskMUser
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WzskJMUserState* _rec = NULL;

	_rec = new WzskJMUserState(0, refWzskMUser, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskJMUserState::appendNewRecToRst(
			ListWzskJMUserState& rst
			, WzskJMUserState** rec
			, const ubigint refWzskMUser
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WzskJMUserState* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMUser, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskJMUserState::insertRst(
			ListWzskJMUserState& rst
			, bool transact
		) {
};

void TblWzskJMUserState::updateRec(
			WzskJMUserState* rec
		) {
};

void TblWzskJMUserState::updateRst(
			ListWzskJMUserState& rst
			, bool transact
		) {
};

void TblWzskJMUserState::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskJMUserState::loadRecByRef(
			ubigint ref
			, WzskJMUserState** rec
		) {
	return false;
};

bool TblWzskJMUserState::loadRecByUsrSta(
			ubigint refWzskMUser
			, uint x1Start
			, WzskJMUserState** rec
		) {
	return false;
};

ubigint TblWzskJMUserState::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzskJMUserState::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskJMUserState& rst
		) {
	return 0;
};

ubigint TblWzskJMUserState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskJMUserState& rst
		) {
	ubigint numload = 0;
	WzskJMUserState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskJMUserState
 ******************************************************************************/

MyTblWzskJMUserState::MyTblWzskJMUserState() :
			TblWzskJMUserState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskJMUserState::~MyTblWzskJMUserState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskJMUserState (refWzskMUser, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskJMUserState SET refWzskMUser = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskJMUserState WHERE ref = ?", false);
};

bool MyTblWzskJMUserState::loadRecBySQL(
			const string& sqlstr
			, WzskJMUserState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskJMUserState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskJMUserState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskJMUserState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzskJMUserState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMUser = atoll((char*) dbrow[1]); else _rec->refWzskMUser = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMUserState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskJMUserState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskJMUserState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskJMUserState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzskJMUserState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMUser = atoll((char*) dbrow[1]); else rec->refWzskMUser = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskJMUserState::insertRec(
			WzskJMUserState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskJMUserState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskJMUserState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskJMUserState::insertRst(
			ListWzskJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskJMUserState::updateRec(
			WzskJMUserState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskJMUserState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskJMUserState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskJMUserState::updateRst(
			ListWzskJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskJMUserState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskJMUserState::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskJMUserState::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskJMUserState::loadRecByRef(
			ubigint ref
			, WzskJMUserState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskJMUserState WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskJMUserState::loadRecByUsrSta(
			ubigint refWzskMUser
			, uint x1Start
			, WzskJMUserState** rec
		) {
	return loadRecBySQL("SELECT ref, refWzskMUser, x1Start, ixVState FROM TblWzskJMUserState WHERE refWzskMUser = " + to_string(refWzskMUser) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblWzskJMUserState::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskJMUserState WHERE refWzskMUser = " + to_string(refWzskMUser) + "", append, refs);
};

ubigint MyTblWzskJMUserState::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskJMUserState& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMUser, x1Start, ixVState FROM TblWzskJMUserState WHERE refWzskMUser = " + to_string(refWzskMUser) + " ORDER BY x1Start ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskJMUserState
 ******************************************************************************/

LiteTblWzskJMUserState::LiteTblWzskJMUserState() :
			TblWzskJMUserState()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsrSta = NULL;
	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblWzskJMUserState::~LiteTblWzskJMUserState() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsrSta) sqlite3_finalize(stmtLoadRecByUsrSta);
	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblWzskJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskJMUserState (refWzskMUser, x1Start, ixVState) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzskJMUserState SET refWzskMUser = ?1, x1Start = ?2, ixVState = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskJMUserState WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMUser, x1Start, ixVState FROM TblWzskJMUserState WHERE ref = ?1");
	stmtLoadRecByUsrSta = createStatement("SELECT ref, refWzskMUser, x1Start, ixVState FROM TblWzskJMUserState WHERE refWzskMUser = ?1 AND x1Start <= ?2 ORDER BY x1Start DESC LIMIT 0,1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblWzskJMUserState WHERE refWzskMUser = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refWzskMUser, x1Start, ixVState FROM TblWzskJMUserState WHERE refWzskMUser = ?1 ORDER BY x1Start ASC");
};

bool LiteTblWzskJMUserState::loadRec(
			sqlite3_stmt* stmt
			, WzskJMUserState** rec
		) {
	int res;

	WzskJMUserState* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskJMUserState();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		_rec->x1Start = sqlite3_column_int(stmt, 2);
		_rec->ixVState = sqlite3_column_int(stmt, 3);

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

ubigint LiteTblWzskJMUserState::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskJMUserState& rst
		) {
	int res; ubigint numread = 0;

	WzskJMUserState* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskJMUserState();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		rec->x1Start = sqlite3_column_int(stmt, 2);
		rec->ixVState = sqlite3_column_int(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskJMUserState::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskJMUserState** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskJMUserState::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskJMUserState& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskJMUserState::loadRecBySQL(
			const string& sqlstr
			, WzskJMUserState** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskJMUserState::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMUserState& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskJMUserState::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskJMUserState::insertRec(
			WzskJMUserState* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1Start);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ixVState);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMUserState::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskJMUserState::insertRst(
			ListWzskJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskJMUserState::updateRec(
			WzskJMUserState* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1Start);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ixVState);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMUserState::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskJMUserState::updateRst(
			ListWzskJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskJMUserState::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMUserState::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskJMUserState::loadRecByRef(
			ubigint ref
			, WzskJMUserState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskJMUserState::loadRecByUsrSta(
			ubigint refWzskMUser
			, uint x1Start
			, WzskJMUserState** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsrSta, 1, refWzskMUser);
	sqlite3_bind_int(stmtLoadRecByUsrSta, 2, x1Start);

	return loadRecByStmt(stmtLoadRecByUsrSta, rec);
};

ubigint LiteTblWzskJMUserState::loadRefsByUsr(
			ubigint refWzskMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refWzskMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblWzskJMUserState::loadRstByUsr(
			ubigint refWzskMUser
			, const bool append
			, ListWzskJMUserState& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refWzskMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

#endif
