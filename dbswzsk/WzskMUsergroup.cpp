/**
	* \file WzskMUsergroup.cpp
	* database access for table TblWzskMUsergroup (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "WzskMUsergroup.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskMUsergroup
 ******************************************************************************/

WzskMUsergroup::WzskMUsergroup(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->sref = sref;
	this->Comment = Comment;
};

bool WzskMUsergroup::operator==(
			const WzskMUsergroup& comp
		) {
	return false;
};

bool WzskMUsergroup::operator!=(
			const WzskMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskMUsergroup
 ******************************************************************************/

ListWzskMUsergroup::ListWzskMUsergroup() {
};

ListWzskMUsergroup::ListWzskMUsergroup(
			const ListWzskMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskMUsergroup(*(src.nodes[i]));
};

ListWzskMUsergroup::~ListWzskMUsergroup() {
	clear();
};

void ListWzskMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskMUsergroup::size() const {
	return(nodes.size());
};

void ListWzskMUsergroup::append(
			WzskMUsergroup* rec
		) {
	nodes.push_back(rec);
};

WzskMUsergroup* ListWzskMUsergroup::operator[](
			const uint ix
		) {
	WzskMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskMUsergroup& ListWzskMUsergroup::operator=(
			const ListWzskMUsergroup& src
		) {
	WzskMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskMUsergroup::operator==(
			const ListWzskMUsergroup& comp
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

bool ListWzskMUsergroup::operator!=(
			const ListWzskMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskMUsergroup
 ******************************************************************************/

TblWzskMUsergroup::TblWzskMUsergroup() {
};

TblWzskMUsergroup::~TblWzskMUsergroup() {
};

bool TblWzskMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzskMUsergroup** rec
		) {
	return false;
};

ubigint TblWzskMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMUsergroup& rst
		) {
	return 0;
};

ubigint TblWzskMUsergroup::insertRec(
			WzskMUsergroup* rec
		) {
	return 0;
};

ubigint TblWzskMUsergroup::insertNewRec(
			WzskMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMUsergroup* _rec = NULL;

	_rec = new WzskMUsergroup(0, grp, own, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskMUsergroup::appendNewRecToRst(
			ListWzskMUsergroup& rst
			, WzskMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskMUsergroup::insertRst(
			ListWzskMUsergroup& rst
			, bool transact
		) {
};

void TblWzskMUsergroup::updateRec(
			WzskMUsergroup* rec
		) {
};

void TblWzskMUsergroup::updateRst(
			ListWzskMUsergroup& rst
			, bool transact
		) {
};

void TblWzskMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskMUsergroup::loadRecByRef(
			ubigint ref
			, WzskMUsergroup** rec
		) {
	return false;
};

bool TblWzskMUsergroup::loadRecBySrf(
			string sref
			, WzskMUsergroup** rec
		) {
	return false;
};

bool TblWzskMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWzskMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWzskMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskMUsergroup& rst
		) {
	ubigint numload = 0;
	WzskMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskMUsergroup
 ******************************************************************************/

MyTblWzskMUsergroup::MyTblWzskMUsergroup() :
			TblWzskMUsergroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskMUsergroup::~MyTblWzskMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMUsergroup (grp, own, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskMUsergroup SET grp = ?, own = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMUsergroup WHERE ref = ?", false);
};

bool MyTblWzskMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzskMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMUsergroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMUsergroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMUsergroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMUsergroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskMUsergroup::insertRec(
			WzskMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskMUsergroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskMUsergroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskMUsergroup::insertRst(
			ListWzskMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskMUsergroup::updateRec(
			WzskMUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskMUsergroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskMUsergroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskMUsergroup::updateRst(
			ListWzskMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskMUsergroup::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskMUsergroup::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskMUsergroup::loadRecByRef(
			ubigint ref
			, WzskMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskMUsergroup WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskMUsergroup::loadRecBySrf(
			string sref
			, WzskMUsergroup** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, sref, Comment FROM TblWzskMUsergroup WHERE sref = '" + sref + "'", rec);
};

bool MyTblWzskMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzskMUsergroup WHERE sref = '" + sref + "'", ref);
};

bool MyTblWzskMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWzskMUsergroup WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskMUsergroup
 ******************************************************************************/

LiteTblWzskMUsergroup::LiteTblWzskMUsergroup() :
			TblWzskMUsergroup()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecBySrf = NULL;
	stmtLoadRefBySrf = NULL;
	stmtLoadSrfByRef = NULL;
};

LiteTblWzskMUsergroup::~LiteTblWzskMUsergroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecBySrf) sqlite3_finalize(stmtLoadRecBySrf);
	if (stmtLoadRefBySrf) sqlite3_finalize(stmtLoadRefBySrf);
	if (stmtLoadSrfByRef) sqlite3_finalize(stmtLoadSrfByRef);
};

void LiteTblWzskMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMUsergroup (grp, own, sref, Comment) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzskMUsergroup SET grp = ?1, own = ?2, sref = ?3, Comment = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMUsergroup WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, grp, own, sref, Comment FROM TblWzskMUsergroup WHERE ref = ?1");
	stmtLoadRecBySrf = createStatement("SELECT ref, grp, own, sref, Comment FROM TblWzskMUsergroup WHERE sref = ?1");
	stmtLoadRefBySrf = createStatement("SELECT ref FROM TblWzskMUsergroup WHERE sref = ?1");
	stmtLoadSrfByRef = createStatement("SELECT sref FROM TblWzskMUsergroup WHERE ref = ?1");
};

bool LiteTblWzskMUsergroup::loadRec(
			sqlite3_stmt* stmt
			, WzskMUsergroup** rec
		) {
	int res;

	WzskMUsergroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskMUsergroup();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->grp = sqlite3_column_int64(stmt, 1);
		_rec->own = sqlite3_column_int64(stmt, 2);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblWzskMUsergroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMUsergroup& rst
		) {
	int res; ubigint numread = 0;

	WzskMUsergroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskMUsergroup();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->grp = sqlite3_column_int64(stmt, 1);
		rec->own = sqlite3_column_int64(stmt, 2);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskMUsergroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskMUsergroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzskMUsergroup** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMUsergroup::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMUsergroup& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMUsergroup::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMUsergroup::insertRec(
			WzskMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->own);
	sqlite3_bind_text(stmtInsertRec, 3, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMUsergroup::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskMUsergroup::insertRst(
			ListWzskMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskMUsergroup::updateRec(
			WzskMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->own);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMUsergroup::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskMUsergroup::updateRst(
			ListWzskMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskMUsergroup::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMUsergroup::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskMUsergroup::loadRecByRef(
			ubigint ref
			, WzskMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskMUsergroup::loadRecBySrf(
			string sref
			, WzskMUsergroup** rec
		) {
	sqlite3_bind_text(stmtLoadRecBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecBySrf, rec);
};

bool LiteTblWzskMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	sqlite3_bind_text(stmtLoadRefBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefBySrf, ref);
};

bool LiteTblWzskMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	sqlite3_bind_int64(stmtLoadSrfByRef, 1, ref);

	return loadStringByStmt(stmtLoadSrfByRef, sref);
};

#endif

