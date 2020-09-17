/**
	* \file WzskAccRMUserUniversal.cpp
	* database access for table TblWzskAccRMUserUniversal (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "WzskAccRMUserUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskAccRMUserUniversal
 ******************************************************************************/

WzskAccRMUserUniversal::WzskAccRMUserUniversal(
			const ubigint ref
			, const ubigint refWzskMUser
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVRecaccess
		) {

	this->ref = ref;
	this->refWzskMUser = refWzskMUser;
	this->unvIxWzskVMaintable = unvIxWzskVMaintable;
	this->unvUref = unvUref;
	this->ixWzskVRecaccess = ixWzskVRecaccess;
};

bool WzskAccRMUserUniversal::operator==(
			const WzskAccRMUserUniversal& comp
		) {
	return false;
};

bool WzskAccRMUserUniversal::operator!=(
			const WzskAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskAccRMUserUniversal
 ******************************************************************************/

ListWzskAccRMUserUniversal::ListWzskAccRMUserUniversal() {
};

ListWzskAccRMUserUniversal::ListWzskAccRMUserUniversal(
			const ListWzskAccRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskAccRMUserUniversal(*(src.nodes[i]));
};

ListWzskAccRMUserUniversal::~ListWzskAccRMUserUniversal() {
	clear();
};

void ListWzskAccRMUserUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskAccRMUserUniversal::size() const {
	return(nodes.size());
};

void ListWzskAccRMUserUniversal::append(
			WzskAccRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

WzskAccRMUserUniversal* ListWzskAccRMUserUniversal::operator[](
			const uint ix
		) {
	WzskAccRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskAccRMUserUniversal& ListWzskAccRMUserUniversal::operator=(
			const ListWzskAccRMUserUniversal& src
		) {
	WzskAccRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskAccRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskAccRMUserUniversal::operator==(
			const ListWzskAccRMUserUniversal& comp
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

bool ListWzskAccRMUserUniversal::operator!=(
			const ListWzskAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskAccRMUserUniversal
 ******************************************************************************/

TblWzskAccRMUserUniversal::TblWzskAccRMUserUniversal() {
};

TblWzskAccRMUserUniversal::~TblWzskAccRMUserUniversal() {
};

bool TblWzskAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWzskAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAccRMUserUniversal& rst
		) {
	return 0;
};

ubigint TblWzskAccRMUserUniversal::insertRec(
			WzskAccRMUserUniversal* rec
		) {
	return 0;
};

ubigint TblWzskAccRMUserUniversal::insertNewRec(
			WzskAccRMUserUniversal** rec
			, const ubigint refWzskMUser
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVRecaccess
		) {
	ubigint retval = 0;
	WzskAccRMUserUniversal* _rec = NULL;

	_rec = new WzskAccRMUserUniversal(0, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskAccRMUserUniversal::appendNewRecToRst(
			ListWzskAccRMUserUniversal& rst
			, WzskAccRMUserUniversal** rec
			, const ubigint refWzskMUser
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVRecaccess
		) {
	ubigint retval = 0;
	WzskAccRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskAccRMUserUniversal::insertRst(
			ListWzskAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblWzskAccRMUserUniversal::updateRec(
			WzskAccRMUserUniversal* rec
		) {
};

void TblWzskAccRMUserUniversal::updateRst(
			ListWzskAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblWzskAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzskAccRMUserUniversal** rec
		) {
	return false;
};

bool TblWzskAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, WzskAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWzskAccRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskAccRMUserUniversal& rst
		) {
	ubigint numload = 0;
	WzskAccRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskAccRMUserUniversal
 ******************************************************************************/

MyTblWzskAccRMUserUniversal::MyTblWzskAccRMUserUniversal() :
			TblWzskAccRMUserUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskAccRMUserUniversal::~MyTblWzskAccRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAccRMUserUniversal (refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskAccRMUserUniversal SET refWzskMUser = ?, unvIxWzskVMaintable = ?, unvUref = ?, ixWzskVRecaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAccRMUserUniversal WHERE ref = ?", false);
};

bool MyTblWzskAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskAccRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskAccRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAccRMUserUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAccRMUserUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzskAccRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMUser = atoll((char*) dbrow[1]); else _rec->refWzskMUser = 0;
		if (dbrow[2]) _rec->unvIxWzskVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWzskVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWzskVRecaccess = atol((char*) dbrow[4]); else _rec->ixWzskVRecaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAccRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskAccRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAccRMUserUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAccRMUserUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzskAccRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMUser = atoll((char*) dbrow[1]); else rec->refWzskMUser = 0;
			if (dbrow[2]) rec->unvIxWzskVMaintable = atol((char*) dbrow[2]); else rec->unvIxWzskVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixWzskVRecaccess = atol((char*) dbrow[4]); else rec->ixWzskVRecaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskAccRMUserUniversal::insertRec(
			WzskAccRMUserUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzskVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskVRecaccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskAccRMUserUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskAccRMUserUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskAccRMUserUniversal::insertRst(
			ListWzskAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskAccRMUserUniversal::updateRec(
			WzskAccRMUserUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzskVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskVRecaccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskAccRMUserUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskAccRMUserUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskAccRMUserUniversal::updateRst(
			ListWzskAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskAccRMUserUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskAccRMUserUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzskAccRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskAccRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, WzskAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess FROM TblWzskAccRMUserUniversal WHERE refWzskMUser = " + to_string(refWzskMUser) + " AND unvIxWzskVMaintable = " + to_string(unvIxWzskVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskAccRMUserUniversal
 ******************************************************************************/

LiteTblWzskAccRMUserUniversal::LiteTblWzskAccRMUserUniversal() :
			TblWzskAccRMUserUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsrMtbUnv = NULL;
};

LiteTblWzskAccRMUserUniversal::~LiteTblWzskAccRMUserUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsrMtbUnv) sqlite3_finalize(stmtLoadRecByUsrMtbUnv);
};

void LiteTblWzskAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAccRMUserUniversal (refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskAccRMUserUniversal SET refWzskMUser = ?1, unvIxWzskVMaintable = ?2, unvUref = ?3, ixWzskVRecaccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAccRMUserUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess FROM TblWzskAccRMUserUniversal WHERE ref = ?1");
	stmtLoadRecByUsrMtbUnv = createStatement("SELECT ref, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess FROM TblWzskAccRMUserUniversal WHERE refWzskMUser = ?1 AND unvIxWzskVMaintable = ?2 AND unvUref = ?3");
};

bool LiteTblWzskAccRMUserUniversal::loadRec(
			sqlite3_stmt* stmt
			, WzskAccRMUserUniversal** rec
		) {
	int res;

	WzskAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskAccRMUserUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		_rec->unvIxWzskVMaintable = sqlite3_column_int(stmt, 2);
		_rec->unvUref = sqlite3_column_int64(stmt, 3);
		_rec->ixWzskVRecaccess = sqlite3_column_int(stmt, 4);

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

ubigint LiteTblWzskAccRMUserUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAccRMUserUniversal& rst
		) {
	int res; ubigint numread = 0;

	WzskAccRMUserUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskAccRMUserUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		rec->unvIxWzskVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixWzskVRecaccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskAccRMUserUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskAccRMUserUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskAccRMUserUniversal** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAccRMUserUniversal::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAccRMUserUniversal& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAccRMUserUniversal::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAccRMUserUniversal::insertRec(
			WzskAccRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzskVRecaccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAccRMUserUniversal::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskAccRMUserUniversal::insertRst(
			ListWzskAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskAccRMUserUniversal::updateRec(
			WzskAccRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzskVRecaccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAccRMUserUniversal::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskAccRMUserUniversal::updateRst(
			ListWzskAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAccRMUserUniversal::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzskAccRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, WzskAccRMUserUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnv, 1, refWzskMUser);
	sqlite3_bind_int(stmtLoadRecByUsrMtbUnv, 2, unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnv, 3, unvUref);

	return loadRecByStmt(stmtLoadRecByUsrMtbUnv, rec);
};

#endif

