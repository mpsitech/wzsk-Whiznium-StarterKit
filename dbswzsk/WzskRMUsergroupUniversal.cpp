/**
	* \file WzskRMUsergroupUniversal.cpp
	* database access for table TblWzskRMUsergroupUniversal (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "WzskRMUsergroupUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskRMUsergroupUniversal
 ******************************************************************************/

WzskRMUsergroupUniversal::WzskRMUsergroupUniversal(
			const ubigint ref
			, const ubigint refWzskMUsergroup
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVRecaccess
		) {

	this->ref = ref;
	this->refWzskMUsergroup = refWzskMUsergroup;
	this->unvIxWzskVMaintable = unvIxWzskVMaintable;
	this->unvUref = unvUref;
	this->ixWzskVRecaccess = ixWzskVRecaccess;
};

bool WzskRMUsergroupUniversal::operator==(
			const WzskRMUsergroupUniversal& comp
		) {
	return false;
};

bool WzskRMUsergroupUniversal::operator!=(
			const WzskRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskRMUsergroupUniversal
 ******************************************************************************/

ListWzskRMUsergroupUniversal::ListWzskRMUsergroupUniversal() {
};

ListWzskRMUsergroupUniversal::ListWzskRMUsergroupUniversal(
			const ListWzskRMUsergroupUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskRMUsergroupUniversal(*(src.nodes[i]));
};

ListWzskRMUsergroupUniversal::~ListWzskRMUsergroupUniversal() {
	clear();
};

void ListWzskRMUsergroupUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskRMUsergroupUniversal::size() const {
	return(nodes.size());
};

void ListWzskRMUsergroupUniversal::append(
			WzskRMUsergroupUniversal* rec
		) {
	nodes.push_back(rec);
};

WzskRMUsergroupUniversal* ListWzskRMUsergroupUniversal::operator[](
			const uint ix
		) {
	WzskRMUsergroupUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskRMUsergroupUniversal& ListWzskRMUsergroupUniversal::operator=(
			const ListWzskRMUsergroupUniversal& src
		) {
	WzskRMUsergroupUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskRMUsergroupUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskRMUsergroupUniversal::operator==(
			const ListWzskRMUsergroupUniversal& comp
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

bool ListWzskRMUsergroupUniversal::operator!=(
			const ListWzskRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskRMUsergroupUniversal
 ******************************************************************************/

TblWzskRMUsergroupUniversal::TblWzskRMUsergroupUniversal() {
};

TblWzskRMUsergroupUniversal::~TblWzskRMUsergroupUniversal() {
};

bool TblWzskRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblWzskRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskRMUsergroupUniversal& rst
		) {
	return 0;
};

ubigint TblWzskRMUsergroupUniversal::insertRec(
			WzskRMUsergroupUniversal* rec
		) {
	return 0;
};

ubigint TblWzskRMUsergroupUniversal::insertNewRec(
			WzskRMUsergroupUniversal** rec
			, const ubigint refWzskMUsergroup
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVRecaccess
		) {
	ubigint retval = 0;
	WzskRMUsergroupUniversal* _rec = NULL;

	_rec = new WzskRMUsergroupUniversal(0, refWzskMUsergroup, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskRMUsergroupUniversal::appendNewRecToRst(
			ListWzskRMUsergroupUniversal& rst
			, WzskRMUsergroupUniversal** rec
			, const ubigint refWzskMUsergroup
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVRecaccess
		) {
	ubigint retval = 0;
	WzskRMUsergroupUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMUsergroup, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskRMUsergroupUniversal::insertRst(
			ListWzskRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblWzskRMUsergroupUniversal::updateRec(
			WzskRMUsergroupUniversal* rec
		) {
};

void TblWzskRMUsergroupUniversal::updateRst(
			ListWzskRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblWzskRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WzskRMUsergroupUniversal** rec
		) {
	return false;
};

bool TblWzskRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWzskMUsergroup
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, WzskRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblWzskRMUsergroupUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskRMUsergroupUniversal& rst
		) {
	ubigint numload = 0;
	WzskRMUsergroupUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskRMUsergroupUniversal
 ******************************************************************************/

MyTblWzskRMUsergroupUniversal::MyTblWzskRMUsergroupUniversal() :
			TblWzskRMUsergroupUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskRMUsergroupUniversal::~MyTblWzskRMUsergroupUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskRMUsergroupUniversal (refWzskMUsergroup, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskRMUsergroupUniversal SET refWzskMUsergroup = ?, unvIxWzskVMaintable = ?, unvUref = ?, ixWzskVRecaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskRMUsergroupUniversal WHERE ref = ?", false);
};

bool MyTblWzskRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskRMUsergroupUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskRMUsergroupUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskRMUsergroupUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskRMUsergroupUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzskRMUsergroupUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMUsergroup = atoll((char*) dbrow[1]); else _rec->refWzskMUsergroup = 0;
		if (dbrow[2]) _rec->unvIxWzskVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWzskVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWzskVRecaccess = atol((char*) dbrow[4]); else _rec->ixWzskVRecaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskRMUsergroupUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskRMUsergroupUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskRMUsergroupUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzskRMUsergroupUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMUsergroup = atoll((char*) dbrow[1]); else rec->refWzskMUsergroup = 0;
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

ubigint MyTblWzskRMUsergroupUniversal::insertRec(
			WzskRMUsergroupUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzskVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskVRecaccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskRMUsergroupUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskRMUsergroupUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskRMUsergroupUniversal::insertRst(
			ListWzskRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskRMUsergroupUniversal::updateRec(
			WzskRMUsergroupUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzskVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskVRecaccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskRMUsergroupUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskRMUsergroupUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskRMUsergroupUniversal::updateRst(
			ListWzskRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskRMUsergroupUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskRMUsergroupUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WzskRMUsergroupUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskRMUsergroupUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWzskMUsergroup
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, WzskRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWzskMUsergroup, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess FROM TblWzskRMUsergroupUniversal WHERE refWzskMUsergroup = " + to_string(refWzskMUsergroup) + " AND unvIxWzskVMaintable = " + to_string(unvIxWzskVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskRMUsergroupUniversal
 ******************************************************************************/

LiteTblWzskRMUsergroupUniversal::LiteTblWzskRMUsergroupUniversal() :
			TblWzskRMUsergroupUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsgMtbUnv = NULL;
};

LiteTblWzskRMUsergroupUniversal::~LiteTblWzskRMUsergroupUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsgMtbUnv) sqlite3_finalize(stmtLoadRecByUsgMtbUnv);
};

void LiteTblWzskRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskRMUsergroupUniversal (refWzskMUsergroup, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskRMUsergroupUniversal SET refWzskMUsergroup = ?1, unvIxWzskVMaintable = ?2, unvUref = ?3, ixWzskVRecaccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskRMUsergroupUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMUsergroup, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess FROM TblWzskRMUsergroupUniversal WHERE ref = ?1");
	stmtLoadRecByUsgMtbUnv = createStatement("SELECT ref, refWzskMUsergroup, unvIxWzskVMaintable, unvUref, ixWzskVRecaccess FROM TblWzskRMUsergroupUniversal WHERE refWzskMUsergroup = ?1 AND unvIxWzskVMaintable = ?2 AND unvUref = ?3");
};

bool LiteTblWzskRMUsergroupUniversal::loadRec(
			sqlite3_stmt* stmt
			, WzskRMUsergroupUniversal** rec
		) {
	int res;

	WzskRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskRMUsergroupUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 1);
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

ubigint LiteTblWzskRMUsergroupUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskRMUsergroupUniversal& rst
		) {
	int res; ubigint numread = 0;

	WzskRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskRMUsergroupUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 1);
		rec->unvIxWzskVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixWzskVRecaccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskRMUsergroupUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskRMUsergroupUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskRMUsergroupUniversal** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskRMUsergroupUniversal::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskRMUsergroupUniversal& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskRMUsergroupUniversal::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskRMUsergroupUniversal::insertRec(
			WzskRMUsergroupUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzskVRecaccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskRMUsergroupUniversal::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskRMUsergroupUniversal::insertRst(
			ListWzskRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskRMUsergroupUniversal::updateRec(
			WzskRMUsergroupUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzskVRecaccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskRMUsergroupUniversal::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskRMUsergroupUniversal::updateRst(
			ListWzskRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskRMUsergroupUniversal::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WzskRMUsergroupUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWzskMUsergroup
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, WzskRMUsergroupUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsgMtbUnv, 1, refWzskMUsergroup);
	sqlite3_bind_int(stmtLoadRecByUsgMtbUnv, 2, unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtLoadRecByUsgMtbUnv, 3, unvUref);

	return loadRecByStmt(stmtLoadRecByUsgMtbUnv, rec);
};

#endif

