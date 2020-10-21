/**
	* \file WzskAMPersonDetail.cpp
	* database access for table TblWzskAMPersonDetail (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "WzskAMPersonDetail.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskAMPersonDetail
 ******************************************************************************/

WzskAMPersonDetail::WzskAMPersonDetail(
			const ubigint ref
			, const ubigint refWzskMPerson
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refWzskMPerson = refWzskMPerson;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool WzskAMPersonDetail::operator==(
			const WzskAMPersonDetail& comp
		) {
	return false;
};

bool WzskAMPersonDetail::operator!=(
			const WzskAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskAMPersonDetail
 ******************************************************************************/

ListWzskAMPersonDetail::ListWzskAMPersonDetail() {
};

ListWzskAMPersonDetail::ListWzskAMPersonDetail(
			const ListWzskAMPersonDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskAMPersonDetail(*(src.nodes[i]));
};

ListWzskAMPersonDetail::~ListWzskAMPersonDetail() {
	clear();
};

void ListWzskAMPersonDetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskAMPersonDetail::size() const {
	return(nodes.size());
};

void ListWzskAMPersonDetail::append(
			WzskAMPersonDetail* rec
		) {
	nodes.push_back(rec);
};

WzskAMPersonDetail* ListWzskAMPersonDetail::operator[](
			const uint ix
		) {
	WzskAMPersonDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskAMPersonDetail& ListWzskAMPersonDetail::operator=(
			const ListWzskAMPersonDetail& src
		) {
	WzskAMPersonDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskAMPersonDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskAMPersonDetail::operator==(
			const ListWzskAMPersonDetail& comp
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

bool ListWzskAMPersonDetail::operator!=(
			const ListWzskAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskAMPersonDetail
 ******************************************************************************/

TblWzskAMPersonDetail::TblWzskAMPersonDetail() {
};

TblWzskAMPersonDetail::~TblWzskAMPersonDetail() {
};

bool TblWzskAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WzskAMPersonDetail** rec
		) {
	return false;
};

ubigint TblWzskAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblWzskAMPersonDetail::insertRec(
			WzskAMPersonDetail* rec
		) {
	return 0;
};

ubigint TblWzskAMPersonDetail::insertNewRec(
			WzskAMPersonDetail** rec
			, const ubigint refWzskMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WzskAMPersonDetail* _rec = NULL;

	_rec = new WzskAMPersonDetail(0, refWzskMPerson, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskAMPersonDetail::appendNewRecToRst(
			ListWzskAMPersonDetail& rst
			, WzskAMPersonDetail** rec
			, const ubigint refWzskMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WzskAMPersonDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMPerson, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskAMPersonDetail::insertRst(
			ListWzskAMPersonDetail& rst
			, bool transact
		) {
};

void TblWzskAMPersonDetail::updateRec(
			WzskAMPersonDetail* rec
		) {
};

void TblWzskAMPersonDetail::updateRst(
			ListWzskAMPersonDetail& rst
			, bool transact
		) {
};

void TblWzskAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskAMPersonDetail::loadRecByRef(
			ubigint ref
			, WzskAMPersonDetail** rec
		) {
	return false;
};

bool TblWzskAMPersonDetail::loadRecByPrsTyp(
			ubigint refWzskMPerson
			, string x1SrefKType
			, WzskAMPersonDetail** rec
		) {
	return false;
};

ubigint TblWzskAMPersonDetail::loadRstByPrs(
			ubigint refWzskMPerson
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblWzskAMPersonDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	ubigint numload = 0;
	WzskAMPersonDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskAMPersonDetail
 ******************************************************************************/

MyTblWzskAMPersonDetail::MyTblWzskAMPersonDetail() :
			TblWzskAMPersonDetail()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskAMPersonDetail::~MyTblWzskAMPersonDetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAMPersonDetail (refWzskMPerson, x1SrefKType, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskAMPersonDetail SET refWzskMPerson = ?, x1SrefKType = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAMPersonDetail WHERE ref = ?", false);
};

bool MyTblWzskAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WzskAMPersonDetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskAMPersonDetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAMPersonDetail::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAMPersonDetail::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskAMPersonDetail();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMPerson = atoll((char*) dbrow[1]); else _rec->refWzskMPerson = 0;
		if (dbrow[2]) _rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKType = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskAMPersonDetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAMPersonDetail::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAMPersonDetail::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskAMPersonDetail();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMPerson = atoll((char*) dbrow[1]); else rec->refWzskMPerson = 0;
			if (dbrow[2]) rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else rec->x1SrefKType = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskAMPersonDetail::insertRec(
			WzskAMPersonDetail* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskAMPersonDetail::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskAMPersonDetail::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskAMPersonDetail::insertRst(
			ListWzskAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskAMPersonDetail::updateRec(
			WzskAMPersonDetail* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskAMPersonDetail::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskAMPersonDetail::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskAMPersonDetail::updateRst(
			ListWzskAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskAMPersonDetail::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskAMPersonDetail::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskAMPersonDetail::loadRecByRef(
			ubigint ref
			, WzskAMPersonDetail** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskAMPersonDetail WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskAMPersonDetail::loadRecByPrsTyp(
			ubigint refWzskMPerson
			, string x1SrefKType
			, WzskAMPersonDetail** rec
		) {
	return loadRecBySQL("SELECT ref, refWzskMPerson, x1SrefKType, Val FROM TblWzskAMPersonDetail WHERE refWzskMPerson = " + to_string(refWzskMPerson) + " AND x1SrefKType = '" + x1SrefKType + "'", rec);
};

ubigint MyTblWzskAMPersonDetail::loadRstByPrs(
			ubigint refWzskMPerson
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMPerson, x1SrefKType, Val FROM TblWzskAMPersonDetail WHERE refWzskMPerson = " + to_string(refWzskMPerson) + " ORDER BY x1SrefKType ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskAMPersonDetail
 ******************************************************************************/

LiteTblWzskAMPersonDetail::LiteTblWzskAMPersonDetail() :
			TblWzskAMPersonDetail()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByPrsTyp = NULL;
	stmtLoadRstByPrs = NULL;
};

LiteTblWzskAMPersonDetail::~LiteTblWzskAMPersonDetail() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByPrsTyp) sqlite3_finalize(stmtLoadRecByPrsTyp);
	if (stmtLoadRstByPrs) sqlite3_finalize(stmtLoadRstByPrs);
};

void LiteTblWzskAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAMPersonDetail (refWzskMPerson, x1SrefKType, Val) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzskAMPersonDetail SET refWzskMPerson = ?1, x1SrefKType = ?2, Val = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAMPersonDetail WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMPerson, x1SrefKType, Val FROM TblWzskAMPersonDetail WHERE ref = ?1");
	stmtLoadRecByPrsTyp = createStatement("SELECT ref, refWzskMPerson, x1SrefKType, Val FROM TblWzskAMPersonDetail WHERE refWzskMPerson = ?1 AND x1SrefKType = ?2");
	stmtLoadRstByPrs = createStatement("SELECT ref, refWzskMPerson, x1SrefKType, Val FROM TblWzskAMPersonDetail WHERE refWzskMPerson = ?1 ORDER BY x1SrefKType ASC");
};

bool LiteTblWzskAMPersonDetail::loadRec(
			sqlite3_stmt* stmt
			, WzskAMPersonDetail** rec
		) {
	int res;

	WzskAMPersonDetail* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskAMPersonDetail();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMPerson = sqlite3_column_int64(stmt, 1);
		_rec->x1SrefKType.assign((const char*) sqlite3_column_text(stmt, 2));
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

ubigint LiteTblWzskAMPersonDetail::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	int res; ubigint numread = 0;

	WzskAMPersonDetail* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskAMPersonDetail();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMPerson = sqlite3_column_int64(stmt, 1);
		rec->x1SrefKType.assign((const char*) sqlite3_column_text(stmt, 2));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskAMPersonDetail::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskAMPersonDetail** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskAMPersonDetail::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WzskAMPersonDetail** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAMPersonDetail::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAMPersonDetail::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAMPersonDetail::insertRec(
			WzskAMPersonDetail* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMPerson);
	sqlite3_bind_text(stmtInsertRec, 2, rec->x1SrefKType.c_str(), rec->x1SrefKType.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMPersonDetail::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskAMPersonDetail::insertRst(
			ListWzskAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskAMPersonDetail::updateRec(
			WzskAMPersonDetail* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMPerson);
	sqlite3_bind_text(stmtUpdateRec, 2, rec->x1SrefKType.c_str(), rec->x1SrefKType.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMPersonDetail::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskAMPersonDetail::updateRst(
			ListWzskAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAMPersonDetail::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskAMPersonDetail::loadRecByRef(
			ubigint ref
			, WzskAMPersonDetail** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskAMPersonDetail::loadRecByPrsTyp(
			ubigint refWzskMPerson
			, string x1SrefKType
			, WzskAMPersonDetail** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByPrsTyp, 1, refWzskMPerson);
	sqlite3_bind_text(stmtLoadRecByPrsTyp, 2, x1SrefKType.c_str(), x1SrefKType.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecByPrsTyp, rec);
};

ubigint LiteTblWzskAMPersonDetail::loadRstByPrs(
			ubigint refWzskMPerson
			, const bool append
			, ListWzskAMPersonDetail& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrs, 1, refWzskMPerson);

	return loadRstByStmt(stmtLoadRstByPrs, append, rst);
};

#endif

