/**
	* \file WzskJMPersonLastname.cpp
	* database access for table TblWzskJMPersonLastname (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "WzskJMPersonLastname.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskJMPersonLastname
 ******************************************************************************/

WzskJMPersonLastname::WzskJMPersonLastname(
			const ubigint ref
			, const ubigint refWzskMPerson
			, const uint x1Startd
			, const string Lastname
		) {

	this->ref = ref;
	this->refWzskMPerson = refWzskMPerson;
	this->x1Startd = x1Startd;
	this->Lastname = Lastname;
};

bool WzskJMPersonLastname::operator==(
			const WzskJMPersonLastname& comp
		) {
	return false;
};

bool WzskJMPersonLastname::operator!=(
			const WzskJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskJMPersonLastname
 ******************************************************************************/

ListWzskJMPersonLastname::ListWzskJMPersonLastname() {
};

ListWzskJMPersonLastname::ListWzskJMPersonLastname(
			const ListWzskJMPersonLastname& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskJMPersonLastname(*(src.nodes[i]));
};

ListWzskJMPersonLastname::~ListWzskJMPersonLastname() {
	clear();
};

void ListWzskJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskJMPersonLastname::size() const {
	return(nodes.size());
};

void ListWzskJMPersonLastname::append(
			WzskJMPersonLastname* rec
		) {
	nodes.push_back(rec);
};

WzskJMPersonLastname* ListWzskJMPersonLastname::operator[](
			const uint ix
		) {
	WzskJMPersonLastname* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskJMPersonLastname& ListWzskJMPersonLastname::operator=(
			const ListWzskJMPersonLastname& src
		) {
	WzskJMPersonLastname* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskJMPersonLastname(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskJMPersonLastname::operator==(
			const ListWzskJMPersonLastname& comp
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

bool ListWzskJMPersonLastname::operator!=(
			const ListWzskJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskJMPersonLastname
 ******************************************************************************/

TblWzskJMPersonLastname::TblWzskJMPersonLastname() {
};

TblWzskJMPersonLastname::~TblWzskJMPersonLastname() {
};

bool TblWzskJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WzskJMPersonLastname** rec
		) {
	return false;
};

ubigint TblWzskJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblWzskJMPersonLastname::insertRec(
			WzskJMPersonLastname* rec
		) {
	return 0;
};

ubigint TblWzskJMPersonLastname::insertNewRec(
			WzskJMPersonLastname** rec
			, const ubigint refWzskMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	WzskJMPersonLastname* _rec = NULL;

	_rec = new WzskJMPersonLastname(0, refWzskMPerson, x1Startd, Lastname);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskJMPersonLastname::appendNewRecToRst(
			ListWzskJMPersonLastname& rst
			, WzskJMPersonLastname** rec
			, const ubigint refWzskMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	WzskJMPersonLastname* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMPerson, x1Startd, Lastname);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskJMPersonLastname::insertRst(
			ListWzskJMPersonLastname& rst
			, bool transact
		) {
};

void TblWzskJMPersonLastname::updateRec(
			WzskJMPersonLastname* rec
		) {
};

void TblWzskJMPersonLastname::updateRst(
			ListWzskJMPersonLastname& rst
			, bool transact
		) {
};

void TblWzskJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskJMPersonLastname::loadRecByRef(
			ubigint ref
			, WzskJMPersonLastname** rec
		) {
	return false;
};

bool TblWzskJMPersonLastname::loadRecByPrsSta(
			ubigint refWzskMPerson
			, uint x1Startd
			, WzskJMPersonLastname** rec
		) {
	return false;
};

ubigint TblWzskJMPersonLastname::loadRefsByPrs(
			ubigint refWzskMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzskJMPersonLastname::loadRstByPrs(
			ubigint refWzskMPerson
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblWzskJMPersonLastname::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	ubigint numload = 0;
	WzskJMPersonLastname* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskJMPersonLastname
 ******************************************************************************/

MyTblWzskJMPersonLastname::MyTblWzskJMPersonLastname() :
			TblWzskJMPersonLastname()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskJMPersonLastname::~MyTblWzskJMPersonLastname() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskJMPersonLastname (refWzskMPerson, x1Startd, Lastname) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskJMPersonLastname SET refWzskMPerson = ?, x1Startd = ?, Lastname = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskJMPersonLastname WHERE ref = ?", false);
};

bool MyTblWzskJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WzskJMPersonLastname** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskJMPersonLastname* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskJMPersonLastname::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskJMPersonLastname::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskJMPersonLastname();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMPerson = atoll((char*) dbrow[1]); else _rec->refWzskMPerson = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Lastname.assign(dbrow[3], dblengths[3]); else _rec->Lastname = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskJMPersonLastname* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskJMPersonLastname::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskJMPersonLastname::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskJMPersonLastname();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMPerson = atoll((char*) dbrow[1]); else rec->refWzskMPerson = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Lastname.assign(dbrow[3], dblengths[3]); else rec->Lastname = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskJMPersonLastname::insertRec(
			WzskJMPersonLastname* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskJMPersonLastname::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskJMPersonLastname::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskJMPersonLastname::insertRst(
			ListWzskJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskJMPersonLastname::updateRec(
			WzskJMPersonLastname* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskJMPersonLastname::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskJMPersonLastname::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskJMPersonLastname::updateRst(
			ListWzskJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskJMPersonLastname::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskJMPersonLastname::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskJMPersonLastname::loadRecByRef(
			ubigint ref
			, WzskJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskJMPersonLastname WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskJMPersonLastname::loadRecByPrsSta(
			ubigint refWzskMPerson
			, uint x1Startd
			, WzskJMPersonLastname** rec
		) {
	return loadRecBySQL("SELECT ref, refWzskMPerson, x1Startd, Lastname FROM TblWzskJMPersonLastname WHERE refWzskMPerson = " + to_string(refWzskMPerson) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblWzskJMPersonLastname::loadRefsByPrs(
			ubigint refWzskMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskJMPersonLastname WHERE refWzskMPerson = " + to_string(refWzskMPerson) + "", append, refs);
};

ubigint MyTblWzskJMPersonLastname::loadRstByPrs(
			ubigint refWzskMPerson
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMPerson, x1Startd, Lastname FROM TblWzskJMPersonLastname WHERE refWzskMPerson = " + to_string(refWzskMPerson) + " ORDER BY x1Startd ASC", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskJMPersonLastname
 ******************************************************************************/

LiteTblWzskJMPersonLastname::LiteTblWzskJMPersonLastname() :
			TblWzskJMPersonLastname()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByPrsSta = NULL;
	stmtLoadRefsByPrs = NULL;
	stmtLoadRstByPrs = NULL;
};

LiteTblWzskJMPersonLastname::~LiteTblWzskJMPersonLastname() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByPrsSta) sqlite3_finalize(stmtLoadRecByPrsSta);
	if (stmtLoadRefsByPrs) sqlite3_finalize(stmtLoadRefsByPrs);
	if (stmtLoadRstByPrs) sqlite3_finalize(stmtLoadRstByPrs);
};

void LiteTblWzskJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskJMPersonLastname (refWzskMPerson, x1Startd, Lastname) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzskJMPersonLastname SET refWzskMPerson = ?1, x1Startd = ?2, Lastname = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskJMPersonLastname WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMPerson, x1Startd, Lastname FROM TblWzskJMPersonLastname WHERE ref = ?1");
	stmtLoadRecByPrsSta = createStatement("SELECT ref, refWzskMPerson, x1Startd, Lastname FROM TblWzskJMPersonLastname WHERE refWzskMPerson = ?1 AND x1Startd <= ?2 ORDER BY x1Startd DESC LIMIT 0,1");
	stmtLoadRefsByPrs = createStatement("SELECT ref FROM TblWzskJMPersonLastname WHERE refWzskMPerson = ?1");
	stmtLoadRstByPrs = createStatement("SELECT ref, refWzskMPerson, x1Startd, Lastname FROM TblWzskJMPersonLastname WHERE refWzskMPerson = ?1 ORDER BY x1Startd ASC");
};

bool LiteTblWzskJMPersonLastname::loadRec(
			sqlite3_stmt* stmt
			, WzskJMPersonLastname** rec
		) {
	int res;

	WzskJMPersonLastname* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskJMPersonLastname();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMPerson = sqlite3_column_int64(stmt, 1);
		_rec->x1Startd = sqlite3_column_int(stmt, 2);
		_rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 3));

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

ubigint LiteTblWzskJMPersonLastname::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	int res; ubigint numread = 0;

	WzskJMPersonLastname* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskJMPersonLastname();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMPerson = sqlite3_column_int64(stmt, 1);
		rec->x1Startd = sqlite3_column_int(stmt, 2);
		rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskJMPersonLastname::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskJMPersonLastname** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskJMPersonLastname::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WzskJMPersonLastname** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskJMPersonLastname::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskJMPersonLastname::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskJMPersonLastname::insertRec(
			WzskJMPersonLastname* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMPerson);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1Startd);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMPersonLastname::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskJMPersonLastname::insertRst(
			ListWzskJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskJMPersonLastname::updateRec(
			WzskJMPersonLastname* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMPerson);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1Startd);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMPersonLastname::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskJMPersonLastname::updateRst(
			ListWzskJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskJMPersonLastname::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskJMPersonLastname::loadRecByRef(
			ubigint ref
			, WzskJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskJMPersonLastname::loadRecByPrsSta(
			ubigint refWzskMPerson
			, uint x1Startd
			, WzskJMPersonLastname** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByPrsSta, 1, refWzskMPerson);
	sqlite3_bind_int(stmtLoadRecByPrsSta, 2, x1Startd);

	return loadRecByStmt(stmtLoadRecByPrsSta, rec);
};

ubigint LiteTblWzskJMPersonLastname::loadRefsByPrs(
			ubigint refWzskMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByPrs, 1, refWzskMPerson);

	return loadRefsByStmt(stmtLoadRefsByPrs, append, refs);
};

ubigint LiteTblWzskJMPersonLastname::loadRstByPrs(
			ubigint refWzskMPerson
			, const bool append
			, ListWzskJMPersonLastname& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrs, 1, refWzskMPerson);

	return loadRstByStmt(stmtLoadRstByPrs, append, rst);
};

#endif

