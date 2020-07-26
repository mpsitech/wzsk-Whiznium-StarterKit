/**
	* \file WzskAVControlPar.cpp
	* database access for table TblWzskAVControlPar (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "WzskAVControlPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskAVControlPar
 ******************************************************************************/

WzskAVControlPar::WzskAVControlPar(
			const ubigint ref
			, const uint ixWzskVControl
			, const ubigint x1RefWzskMUser
			, const uint x2IxWzskVLocale
			, const string Par
			, const string Val
		) {

	this->ref = ref;
	this->ixWzskVControl = ixWzskVControl;
	this->x1RefWzskMUser = x1RefWzskMUser;
	this->x2IxWzskVLocale = x2IxWzskVLocale;
	this->Par = Par;
	this->Val = Val;
};

bool WzskAVControlPar::operator==(
			const WzskAVControlPar& comp
		) {
	return false;
};

bool WzskAVControlPar::operator!=(
			const WzskAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskAVControlPar
 ******************************************************************************/

ListWzskAVControlPar::ListWzskAVControlPar() {
};

ListWzskAVControlPar::ListWzskAVControlPar(
			const ListWzskAVControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskAVControlPar(*(src.nodes[i]));
};

ListWzskAVControlPar::~ListWzskAVControlPar() {
	clear();
};

void ListWzskAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskAVControlPar::size() const {
	return(nodes.size());
};

void ListWzskAVControlPar::append(
			WzskAVControlPar* rec
		) {
	nodes.push_back(rec);
};

WzskAVControlPar* ListWzskAVControlPar::operator[](
			const uint ix
		) {
	WzskAVControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskAVControlPar& ListWzskAVControlPar::operator=(
			const ListWzskAVControlPar& src
		) {
	WzskAVControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskAVControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskAVControlPar::operator==(
			const ListWzskAVControlPar& comp
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

bool ListWzskAVControlPar::operator!=(
			const ListWzskAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskAVControlPar
 ******************************************************************************/

TblWzskAVControlPar::TblWzskAVControlPar() {
};

TblWzskAVControlPar::~TblWzskAVControlPar() {
};

bool TblWzskAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WzskAVControlPar** rec
		) {
	return false;
};

ubigint TblWzskAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVControlPar& rst
		) {
	return 0;
};

ubigint TblWzskAVControlPar::insertRec(
			WzskAVControlPar* rec
		) {
	return 0;
};

ubigint TblWzskAVControlPar::insertNewRec(
			WzskAVControlPar** rec
			, const uint ixWzskVControl
			, const ubigint x1RefWzskMUser
			, const uint x2IxWzskVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	WzskAVControlPar* _rec = NULL;

	_rec = new WzskAVControlPar(0, ixWzskVControl, x1RefWzskMUser, x2IxWzskVLocale, Par, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskAVControlPar::appendNewRecToRst(
			ListWzskAVControlPar& rst
			, WzskAVControlPar** rec
			, const uint ixWzskVControl
			, const ubigint x1RefWzskMUser
			, const uint x2IxWzskVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	WzskAVControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, ixWzskVControl, x1RefWzskMUser, x2IxWzskVLocale, Par, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskAVControlPar::insertRst(
			ListWzskAVControlPar& rst
			, bool transact
		) {
};

void TblWzskAVControlPar::updateRec(
			WzskAVControlPar* rec
		) {
};

void TblWzskAVControlPar::updateRst(
			ListWzskAVControlPar& rst
			, bool transact
		) {
};

void TblWzskAVControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskAVControlPar::loadRecByRef(
			ubigint ref
			, WzskAVControlPar** rec
		) {
	return false;
};

bool TblWzskAVControlPar::loadRefByCtlUsrPar(
			uint ixWzskVControl
			, ubigint x1RefWzskMUser
			, string Par
			, ubigint& ref
		) {
	return false;
};

bool TblWzskAVControlPar::loadValByCtlUsrPar(
			uint ixWzskVControl
			, ubigint x1RefWzskMUser
			, string Par
			, string& Val
		) {
	return false;
};

ubigint TblWzskAVControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskAVControlPar& rst
		) {
	ubigint numload = 0;
	WzskAVControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskAVControlPar
 ******************************************************************************/

MyTblWzskAVControlPar::MyTblWzskAVControlPar() :
			TblWzskAVControlPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskAVControlPar::~MyTblWzskAVControlPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAVControlPar (ixWzskVControl, x1RefWzskMUser, x2IxWzskVLocale, Par, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskAVControlPar SET ixWzskVControl = ?, x1RefWzskMUser = ?, x2IxWzskVLocale = ?, Par = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAVControlPar WHERE ref = ?", false);
};

bool MyTblWzskAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WzskAVControlPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskAVControlPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAVControlPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAVControlPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskAVControlPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixWzskVControl = atol((char*) dbrow[1]); else _rec->ixWzskVControl = 0;
		if (dbrow[2]) _rec->x1RefWzskMUser = atoll((char*) dbrow[2]); else _rec->x1RefWzskMUser = 0;
		if (dbrow[3]) _rec->x2IxWzskVLocale = atol((char*) dbrow[3]); else _rec->x2IxWzskVLocale = 0;
		if (dbrow[4]) _rec->Par.assign(dbrow[4], dblengths[4]); else _rec->Par = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVControlPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskAVControlPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAVControlPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAVControlPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskAVControlPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixWzskVControl = atol((char*) dbrow[1]); else rec->ixWzskVControl = 0;
			if (dbrow[2]) rec->x1RefWzskMUser = atoll((char*) dbrow[2]); else rec->x1RefWzskMUser = 0;
			if (dbrow[3]) rec->x2IxWzskVLocale = atol((char*) dbrow[3]); else rec->x2IxWzskVLocale = 0;
			if (dbrow[4]) rec->Par.assign(dbrow[4], dblengths[4]); else rec->Par = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskAVControlPar::insertRec(
			WzskAVControlPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWzskVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWzskMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxWzskVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskAVControlPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskAVControlPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskAVControlPar::insertRst(
			ListWzskAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskAVControlPar::updateRec(
			WzskAVControlPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWzskVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWzskMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxWzskVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskAVControlPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskAVControlPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskAVControlPar::updateRst(
			ListWzskAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskAVControlPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskAVControlPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskAVControlPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskAVControlPar::loadRecByRef(
			ubigint ref
			, WzskAVControlPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskAVControlPar WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskAVControlPar::loadRefByCtlUsrPar(
			uint ixWzskVControl
			, ubigint x1RefWzskMUser
			, string Par
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzskAVControlPar WHERE ixWzskVControl = " + to_string(ixWzskVControl) + " AND x1RefWzskMUser = " + to_string(x1RefWzskMUser) + " AND Par = '" + Par + "'", ref);
};

bool MyTblWzskAVControlPar::loadValByCtlUsrPar(
			uint ixWzskVControl
			, ubigint x1RefWzskMUser
			, string Par
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWzskAVControlPar WHERE ixWzskVControl = " + to_string(ixWzskVControl) + " AND x1RefWzskMUser = " + to_string(x1RefWzskMUser) + " AND Par = '" + Par + "'", Val);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskAVControlPar
 ******************************************************************************/

LiteTblWzskAVControlPar::LiteTblWzskAVControlPar() :
			TblWzskAVControlPar()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefByCtlUsrPar = NULL;
	stmtLoadValByCtlUsrPar = NULL;
};

LiteTblWzskAVControlPar::~LiteTblWzskAVControlPar() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefByCtlUsrPar) sqlite3_finalize(stmtLoadRefByCtlUsrPar);
	if (stmtLoadValByCtlUsrPar) sqlite3_finalize(stmtLoadValByCtlUsrPar);
};

void LiteTblWzskAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAVControlPar (ixWzskVControl, x1RefWzskMUser, x2IxWzskVLocale, Par, Val) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzskAVControlPar SET ixWzskVControl = ?1, x1RefWzskMUser = ?2, x2IxWzskVLocale = ?3, Par = ?4, Val = ?5 WHERE ref = ?6");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAVControlPar WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, ixWzskVControl, x1RefWzskMUser, x2IxWzskVLocale, Par, Val FROM TblWzskAVControlPar WHERE ref = ?1");
	stmtLoadRefByCtlUsrPar = createStatement("SELECT ref FROM TblWzskAVControlPar WHERE ixWzskVControl = ?1 AND x1RefWzskMUser = ?2 AND Par = ?3");
	stmtLoadValByCtlUsrPar = createStatement("SELECT Val FROM TblWzskAVControlPar WHERE ixWzskVControl = ?1 AND x1RefWzskMUser = ?2 AND Par = ?3");
};

bool LiteTblWzskAVControlPar::loadRec(
			sqlite3_stmt* stmt
			, WzskAVControlPar** rec
		) {
	int res;

	WzskAVControlPar* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskAVControlPar();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->ixWzskVControl = sqlite3_column_int(stmt, 1);
		_rec->x1RefWzskMUser = sqlite3_column_int64(stmt, 2);
		_rec->x2IxWzskVLocale = sqlite3_column_int(stmt, 3);
		_rec->Par.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));

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

ubigint LiteTblWzskAVControlPar::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAVControlPar& rst
		) {
	int res; ubigint numread = 0;

	WzskAVControlPar* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskAVControlPar();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->ixWzskVControl = sqlite3_column_int(stmt, 1);
		rec->x1RefWzskMUser = sqlite3_column_int64(stmt, 2);
		rec->x2IxWzskVLocale = sqlite3_column_int(stmt, 3);
		rec->Par.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskAVControlPar::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskAVControlPar** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WzskAVControlPar** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAVControlPar::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVControlPar& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAVControlPar::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAVControlPar::insertRec(
			WzskAVControlPar* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->ixWzskVControl);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->x1RefWzskMUser);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x2IxWzskVLocale);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Par.c_str(), rec->Par.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVControlPar::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskAVControlPar::insertRst(
			ListWzskAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskAVControlPar::updateRec(
			WzskAVControlPar* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->ixWzskVControl);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->x1RefWzskMUser);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x2IxWzskVLocale);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Par.c_str(), rec->Par.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVControlPar::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskAVControlPar::updateRst(
			ListWzskAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskAVControlPar::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVControlPar::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskAVControlPar::loadRecByRef(
			ubigint ref
			, WzskAVControlPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskAVControlPar::loadRefByCtlUsrPar(
			uint ixWzskVControl
			, ubigint x1RefWzskMUser
			, string Par
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByCtlUsrPar, 1, ixWzskVControl);
	sqlite3_bind_int64(stmtLoadRefByCtlUsrPar, 2, x1RefWzskMUser);
	sqlite3_bind_text(stmtLoadRefByCtlUsrPar, 3, Par.c_str(), Par.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByCtlUsrPar, ref);
};

bool LiteTblWzskAVControlPar::loadValByCtlUsrPar(
			uint ixWzskVControl
			, ubigint x1RefWzskMUser
			, string Par
			, string& Val
		) {
	sqlite3_bind_int(stmtLoadValByCtlUsrPar, 1, ixWzskVControl);
	sqlite3_bind_int64(stmtLoadValByCtlUsrPar, 2, x1RefWzskMUser);
	sqlite3_bind_text(stmtLoadValByCtlUsrPar, 3, Par.c_str(), Par.length(), SQLITE_STATIC);

	return loadStringByStmt(stmtLoadValByCtlUsrPar, Val);
};

#endif

