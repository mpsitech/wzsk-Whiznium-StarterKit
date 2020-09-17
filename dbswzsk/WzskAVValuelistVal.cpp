/**
	* \file WzskAVValuelistVal.cpp
	* database access for table TblWzskAVValuelistVal (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "WzskAVValuelistVal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskAVValuelistVal
 ******************************************************************************/

WzskAVValuelistVal::WzskAVValuelistVal(
			const ubigint ref
			, const uint vlsIxWzskVValuelist
			, const uint vlsNum
			, const uint x1IxWzskVLocale
			, const string Val
		) {

	this->ref = ref;
	this->vlsIxWzskVValuelist = vlsIxWzskVValuelist;
	this->vlsNum = vlsNum;
	this->x1IxWzskVLocale = x1IxWzskVLocale;
	this->Val = Val;
};

bool WzskAVValuelistVal::operator==(
			const WzskAVValuelistVal& comp
		) {
	return false;
};

bool WzskAVValuelistVal::operator!=(
			const WzskAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskAVValuelistVal
 ******************************************************************************/

ListWzskAVValuelistVal::ListWzskAVValuelistVal() {
};

ListWzskAVValuelistVal::ListWzskAVValuelistVal(
			const ListWzskAVValuelistVal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskAVValuelistVal(*(src.nodes[i]));
};

ListWzskAVValuelistVal::~ListWzskAVValuelistVal() {
	clear();
};

void ListWzskAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskAVValuelistVal::size() const {
	return(nodes.size());
};

void ListWzskAVValuelistVal::append(
			WzskAVValuelistVal* rec
		) {
	nodes.push_back(rec);
};

WzskAVValuelistVal* ListWzskAVValuelistVal::operator[](
			const uint ix
		) {
	WzskAVValuelistVal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskAVValuelistVal& ListWzskAVValuelistVal::operator=(
			const ListWzskAVValuelistVal& src
		) {
	WzskAVValuelistVal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskAVValuelistVal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskAVValuelistVal::operator==(
			const ListWzskAVValuelistVal& comp
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

bool ListWzskAVValuelistVal::operator!=(
			const ListWzskAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskAVValuelistVal
 ******************************************************************************/

TblWzskAVValuelistVal::TblWzskAVValuelistVal() {
};

TblWzskAVValuelistVal::~TblWzskAVValuelistVal() {
};

bool TblWzskAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WzskAVValuelistVal** rec
		) {
	return false;
};

ubigint TblWzskAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblWzskAVValuelistVal::insertRec(
			WzskAVValuelistVal* rec
		) {
	return 0;
};

ubigint TblWzskAVValuelistVal::insertNewRec(
			WzskAVValuelistVal** rec
			, const uint vlsIxWzskVValuelist
			, const uint vlsNum
			, const uint x1IxWzskVLocale
			, const string Val
		) {
	ubigint retval = 0;
	WzskAVValuelistVal* _rec = NULL;

	_rec = new WzskAVValuelistVal(0, vlsIxWzskVValuelist, vlsNum, x1IxWzskVLocale, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskAVValuelistVal::appendNewRecToRst(
			ListWzskAVValuelistVal& rst
			, WzskAVValuelistVal** rec
			, const uint vlsIxWzskVValuelist
			, const uint vlsNum
			, const uint x1IxWzskVLocale
			, const string Val
		) {
	ubigint retval = 0;
	WzskAVValuelistVal* _rec = NULL;

	retval = insertNewRec(&_rec, vlsIxWzskVValuelist, vlsNum, x1IxWzskVLocale, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskAVValuelistVal::insertRst(
			ListWzskAVValuelistVal& rst
			, bool transact
		) {
};

void TblWzskAVValuelistVal::updateRec(
			WzskAVValuelistVal* rec
		) {
};

void TblWzskAVValuelistVal::updateRst(
			ListWzskAVValuelistVal& rst
			, bool transact
		) {
};

void TblWzskAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskAVValuelistVal::loadRecByRef(
			ubigint ref
			, WzskAVValuelistVal** rec
		) {
	return false;
};

ubigint TblWzskAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWzskVValuelist
			, uint x1IxWzskVLocale
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblWzskAVValuelistVal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	ubigint numload = 0;
	WzskAVValuelistVal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskAVValuelistVal
 ******************************************************************************/

MyTblWzskAVValuelistVal::MyTblWzskAVValuelistVal() :
			TblWzskAVValuelistVal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskAVValuelistVal::~MyTblWzskAVValuelistVal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAVValuelistVal (vlsIxWzskVValuelist, vlsNum, x1IxWzskVLocale, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskAVValuelistVal SET vlsIxWzskVValuelist = ?, vlsNum = ?, x1IxWzskVLocale = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAVValuelistVal WHERE ref = ?", false);
};

bool MyTblWzskAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WzskAVValuelistVal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskAVValuelistVal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAVValuelistVal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAVValuelistVal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskAVValuelistVal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->vlsIxWzskVValuelist = atol((char*) dbrow[1]); else _rec->vlsIxWzskVValuelist = 0;
		if (dbrow[2]) _rec->vlsNum = atol((char*) dbrow[2]); else _rec->vlsNum = 0;
		if (dbrow[3]) _rec->x1IxWzskVLocale = atol((char*) dbrow[3]); else _rec->x1IxWzskVLocale = 0;
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskAVValuelistVal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAVValuelistVal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAVValuelistVal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskAVValuelistVal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->vlsIxWzskVValuelist = atol((char*) dbrow[1]); else rec->vlsIxWzskVValuelist = 0;
			if (dbrow[2]) rec->vlsNum = atol((char*) dbrow[2]); else rec->vlsNum = 0;
			if (dbrow[3]) rec->x1IxWzskVLocale = atol((char*) dbrow[3]); else rec->x1IxWzskVLocale = 0;
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskAVValuelistVal::insertRec(
			WzskAVValuelistVal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxWzskVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWzskVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskAVValuelistVal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskAVValuelistVal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskAVValuelistVal::insertRst(
			ListWzskAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskAVValuelistVal::updateRec(
			WzskAVValuelistVal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxWzskVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWzskVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskAVValuelistVal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskAVValuelistVal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskAVValuelistVal::updateRst(
			ListWzskAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskAVValuelistVal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskAVValuelistVal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskAVValuelistVal::loadRecByRef(
			ubigint ref
			, WzskAVValuelistVal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskAVValuelistVal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzskAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWzskVValuelist
			, uint x1IxWzskVLocale
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	return loadRstBySQL("SELECT ref, vlsIxWzskVValuelist, vlsNum, x1IxWzskVLocale, Val FROM TblWzskAVValuelistVal WHERE vlsIxWzskVValuelist = " + to_string(vlsIxWzskVValuelist) + " AND x1IxWzskVLocale = " + to_string(x1IxWzskVLocale) + " ORDER BY vlsNum ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskAVValuelistVal
 ******************************************************************************/

LiteTblWzskAVValuelistVal::LiteTblWzskAVValuelistVal() :
			TblWzskAVValuelistVal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByVlsLcl = NULL;
};

LiteTblWzskAVValuelistVal::~LiteTblWzskAVValuelistVal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByVlsLcl) sqlite3_finalize(stmtLoadRstByVlsLcl);
};

void LiteTblWzskAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAVValuelistVal (vlsIxWzskVValuelist, vlsNum, x1IxWzskVLocale, Val) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskAVValuelistVal SET vlsIxWzskVValuelist = ?1, vlsNum = ?2, x1IxWzskVLocale = ?3, Val = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAVValuelistVal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, vlsIxWzskVValuelist, vlsNum, x1IxWzskVLocale, Val FROM TblWzskAVValuelistVal WHERE ref = ?1");
	stmtLoadRstByVlsLcl = createStatement("SELECT ref, vlsIxWzskVValuelist, vlsNum, x1IxWzskVLocale, Val FROM TblWzskAVValuelistVal WHERE vlsIxWzskVValuelist = ?1 AND x1IxWzskVLocale = ?2 ORDER BY vlsNum ASC");
};

bool LiteTblWzskAVValuelistVal::loadRec(
			sqlite3_stmt* stmt
			, WzskAVValuelistVal** rec
		) {
	int res;

	WzskAVValuelistVal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskAVValuelistVal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->vlsIxWzskVValuelist = sqlite3_column_int(stmt, 1);
		_rec->vlsNum = sqlite3_column_int(stmt, 2);
		_rec->x1IxWzskVLocale = sqlite3_column_int(stmt, 3);
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblWzskAVValuelistVal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	int res; ubigint numread = 0;

	WzskAVValuelistVal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskAVValuelistVal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->vlsIxWzskVValuelist = sqlite3_column_int(stmt, 1);
		rec->vlsNum = sqlite3_column_int(stmt, 2);
		rec->x1IxWzskVLocale = sqlite3_column_int(stmt, 3);
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskAVValuelistVal::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskAVValuelistVal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskAVValuelistVal::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WzskAVValuelistVal** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAVValuelistVal::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAVValuelistVal::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAVValuelistVal::insertRec(
			WzskAVValuelistVal* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->vlsIxWzskVValuelist);
	sqlite3_bind_int(stmtInsertRec, 2, rec->vlsNum);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x1IxWzskVLocale);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVValuelistVal::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskAVValuelistVal::insertRst(
			ListWzskAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskAVValuelistVal::updateRec(
			WzskAVValuelistVal* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->vlsIxWzskVValuelist);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->vlsNum);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x1IxWzskVLocale);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVValuelistVal::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskAVValuelistVal::updateRst(
			ListWzskAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVValuelistVal::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskAVValuelistVal::loadRecByRef(
			ubigint ref
			, WzskAVValuelistVal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzskAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWzskVValuelist
			, uint x1IxWzskVLocale
			, const bool append
			, ListWzskAVValuelistVal& rst
		) {
	sqlite3_bind_int(stmtLoadRstByVlsLcl, 1, vlsIxWzskVValuelist);
	sqlite3_bind_int(stmtLoadRstByVlsLcl, 2, x1IxWzskVLocale);

	return loadRstByStmt(stmtLoadRstByVlsLcl, append, rst);
};

#endif

