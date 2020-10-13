/**
	* \file WzskMObjgroup.cpp
	* database access for table TblWzskMObjgroup (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "WzskMObjgroup.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskMObjgroup
 ******************************************************************************/

WzskMObjgroup::WzskMObjgroup(
			const ubigint ref
			, const ubigint supRefWzskMObjgroup
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->supRefWzskMObjgroup = supRefWzskMObjgroup;
	this->sref = sref;
	this->refJTitle = refJTitle;
	this->Title = Title;
	this->Comment = Comment;
};

bool WzskMObjgroup::operator==(
			const WzskMObjgroup& comp
		) {
	return false;
};

bool WzskMObjgroup::operator!=(
			const WzskMObjgroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskMObjgroup
 ******************************************************************************/

ListWzskMObjgroup::ListWzskMObjgroup() {
};

ListWzskMObjgroup::ListWzskMObjgroup(
			const ListWzskMObjgroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskMObjgroup(*(src.nodes[i]));
};

ListWzskMObjgroup::~ListWzskMObjgroup() {
	clear();
};

void ListWzskMObjgroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskMObjgroup::size() const {
	return(nodes.size());
};

void ListWzskMObjgroup::append(
			WzskMObjgroup* rec
		) {
	nodes.push_back(rec);
};

WzskMObjgroup* ListWzskMObjgroup::operator[](
			const uint ix
		) {
	WzskMObjgroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskMObjgroup& ListWzskMObjgroup::operator=(
			const ListWzskMObjgroup& src
		) {
	WzskMObjgroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskMObjgroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskMObjgroup::operator==(
			const ListWzskMObjgroup& comp
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

bool ListWzskMObjgroup::operator!=(
			const ListWzskMObjgroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskMObjgroup
 ******************************************************************************/

TblWzskMObjgroup::TblWzskMObjgroup() {
};

TblWzskMObjgroup::~TblWzskMObjgroup() {
};

bool TblWzskMObjgroup::loadRecBySQL(
			const string& sqlstr
			, WzskMObjgroup** rec
		) {
	return false;
};

ubigint TblWzskMObjgroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	return 0;
};

ubigint TblWzskMObjgroup::insertRec(
			WzskMObjgroup* rec
		) {
	return 0;
};

ubigint TblWzskMObjgroup::insertNewRec(
			WzskMObjgroup** rec
			, const ubigint supRefWzskMObjgroup
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMObjgroup* _rec = NULL;

	_rec = new WzskMObjgroup(0, supRefWzskMObjgroup, sref, refJTitle, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskMObjgroup::appendNewRecToRst(
			ListWzskMObjgroup& rst
			, WzskMObjgroup** rec
			, const ubigint supRefWzskMObjgroup
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMObjgroup* _rec = NULL;

	retval = insertNewRec(&_rec, supRefWzskMObjgroup, sref, refJTitle, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskMObjgroup::insertRst(
			ListWzskMObjgroup& rst
			, bool transact
		) {
};

void TblWzskMObjgroup::updateRec(
			WzskMObjgroup* rec
		) {
};

void TblWzskMObjgroup::updateRst(
			ListWzskMObjgroup& rst
			, bool transact
		) {
};

void TblWzskMObjgroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskMObjgroup::loadRecByRef(
			ubigint ref
			, WzskMObjgroup** rec
		) {
	return false;
};

bool TblWzskMObjgroup::confirmByRef(
			ubigint ref
		) {
	return false;
};

ubigint TblWzskMObjgroup::loadRefsBySup(
			ubigint supRefWzskMObjgroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzskMObjgroup::loadRstBySup(
			ubigint supRefWzskMObjgroup
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	return 0;
};

bool TblWzskMObjgroup::loadSupByRef(
			ubigint ref
			, ubigint& supRefWzskMObjgroup
		) {
	return false;
};

ubigint TblWzskMObjgroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	ubigint numload = 0;
	WzskMObjgroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWzskMObjgroup::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWzskMObjgroup::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

ubigint TblWzskMObjgroup::loadHrstup(
			ubigint ref
			, ListWzskMObjgroup& rst
		) {
	WzskMObjgroup* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWzskMObjgroup;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWzskMObjgroup::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWzskMObjgroup& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WzskMObjgroup* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskMObjgroup
 ******************************************************************************/

MyTblWzskMObjgroup::MyTblWzskMObjgroup() :
			TblWzskMObjgroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskMObjgroup::~MyTblWzskMObjgroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskMObjgroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMObjgroup (supRefWzskMObjgroup, sref, refJTitle, Title, Comment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskMObjgroup SET supRefWzskMObjgroup = ?, sref = ?, refJTitle = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMObjgroup WHERE ref = ?", false);
};

bool MyTblWzskMObjgroup::loadRecBySQL(
			const string& sqlstr
			, WzskMObjgroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskMObjgroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMObjgroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMObjgroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskMObjgroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->supRefWzskMObjgroup = atoll((char*) dbrow[1]); else _rec->supRefWzskMObjgroup = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->refJTitle = atoll((char*) dbrow[3]); else _rec->refJTitle = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->Comment.assign(dbrow[5], dblengths[5]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskMObjgroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskMObjgroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMObjgroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMObjgroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskMObjgroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->supRefWzskMObjgroup = atoll((char*) dbrow[1]); else rec->supRefWzskMObjgroup = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->refJTitle = atoll((char*) dbrow[3]); else rec->refJTitle = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->Comment.assign(dbrow[5], dblengths[5]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskMObjgroup::insertRec(
			WzskMObjgroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->sref.length();
	l[3] = rec->Title.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWzskMObjgroup,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refJTitle,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskMObjgroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskMObjgroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskMObjgroup::insertRst(
			ListWzskMObjgroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskMObjgroup::updateRec(
			WzskMObjgroup* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[1] = rec->sref.length();
	l[3] = rec->Title.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWzskMObjgroup,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refJTitle,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskMObjgroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskMObjgroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskMObjgroup::updateRst(
			ListWzskMObjgroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskMObjgroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskMObjgroup::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskMObjgroup::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskMObjgroup::loadRecByRef(
			ubigint ref
			, WzskMObjgroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskMObjgroup WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskMObjgroup::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWzskMObjgroup WHERE ref = " + to_string(ref) + "", val);
};

ubigint MyTblWzskMObjgroup::loadRefsBySup(
			ubigint supRefWzskMObjgroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskMObjgroup WHERE supRefWzskMObjgroup = " + to_string(supRefWzskMObjgroup) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblWzskMObjgroup::loadRstBySup(
			ubigint supRefWzskMObjgroup
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	return loadRstBySQL("SELECT ref, supRefWzskMObjgroup, sref, refJTitle, Title, Comment FROM TblWzskMObjgroup WHERE supRefWzskMObjgroup = " + to_string(supRefWzskMObjgroup) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWzskMObjgroup::loadSupByRef(
			ubigint ref
			, ubigint& supRefWzskMObjgroup
		) {
	return loadRefBySQL("SELECT supRefWzskMObjgroup FROM TblWzskMObjgroup WHERE ref = " + to_string(ref) + "", supRefWzskMObjgroup);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskMObjgroup
 ******************************************************************************/

LiteTblWzskMObjgroup::LiteTblWzskMObjgroup() :
			TblWzskMObjgroup()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtConfirmByRef = NULL;
	stmtLoadRefsBySup = NULL;
	stmtLoadRstBySup = NULL;
	stmtLoadSupByRef = NULL;
};

LiteTblWzskMObjgroup::~LiteTblWzskMObjgroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtConfirmByRef) sqlite3_finalize(stmtConfirmByRef);
	if (stmtLoadRefsBySup) sqlite3_finalize(stmtLoadRefsBySup);
	if (stmtLoadRstBySup) sqlite3_finalize(stmtLoadRstBySup);
	if (stmtLoadSupByRef) sqlite3_finalize(stmtLoadSupByRef);
};

void LiteTblWzskMObjgroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMObjgroup (supRefWzskMObjgroup, sref, refJTitle, Title, Comment) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzskMObjgroup SET supRefWzskMObjgroup = ?1, sref = ?2, refJTitle = ?3, Title = ?4, Comment = ?5 WHERE ref = ?6");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMObjgroup WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, supRefWzskMObjgroup, sref, refJTitle, Title, Comment FROM TblWzskMObjgroup WHERE ref = ?1");
	stmtConfirmByRef = createStatement("SELECT ref FROM TblWzskMObjgroup WHERE ref = ?1");
	stmtLoadRefsBySup = createStatement("SELECT ref FROM TblWzskMObjgroup WHERE supRefWzskMObjgroup = ?1 ORDER BY sref ASC");
	stmtLoadRstBySup = createStatement("SELECT ref, supRefWzskMObjgroup, sref, refJTitle, Title, Comment FROM TblWzskMObjgroup WHERE supRefWzskMObjgroup = ?1 ORDER BY sref ASC");
	stmtLoadSupByRef = createStatement("SELECT supRefWzskMObjgroup FROM TblWzskMObjgroup WHERE ref = ?1");
};

bool LiteTblWzskMObjgroup::loadRec(
			sqlite3_stmt* stmt
			, WzskMObjgroup** rec
		) {
	int res;

	WzskMObjgroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskMObjgroup();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->supRefWzskMObjgroup = sqlite3_column_int64(stmt, 1);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 2));
		_rec->refJTitle = sqlite3_column_int64(stmt, 3);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 5));

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

ubigint LiteTblWzskMObjgroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	int res; ubigint numread = 0;

	WzskMObjgroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskMObjgroup();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->supRefWzskMObjgroup = sqlite3_column_int64(stmt, 1);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 2));
		rec->refJTitle = sqlite3_column_int64(stmt, 3);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 5));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskMObjgroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskMObjgroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskMObjgroup::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskMObjgroup::loadRecBySQL(
			const string& sqlstr
			, WzskMObjgroup** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMObjgroup::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMObjgroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMObjgroup::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMObjgroup::insertRec(
			WzskMObjgroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->supRefWzskMObjgroup);
	sqlite3_bind_text(stmtInsertRec, 2, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refJTitle);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMObjgroup::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskMObjgroup::insertRst(
			ListWzskMObjgroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskMObjgroup::updateRec(
			WzskMObjgroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->supRefWzskMObjgroup);
	sqlite3_bind_text(stmtUpdateRec, 2, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refJTitle);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMObjgroup::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskMObjgroup::updateRst(
			ListWzskMObjgroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskMObjgroup::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMObjgroup::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskMObjgroup::loadRecByRef(
			ubigint ref
			, WzskMObjgroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskMObjgroup::confirmByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtConfirmByRef, 1, ref);

	ubigint val;
	return loadRefByStmt(stmtConfirmByRef, val);
};

ubigint LiteTblWzskMObjgroup::loadRefsBySup(
			ubigint supRefWzskMObjgroup
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsBySup, 1, supRefWzskMObjgroup);

	return loadRefsByStmt(stmtLoadRefsBySup, append, refs);
};

ubigint LiteTblWzskMObjgroup::loadRstBySup(
			ubigint supRefWzskMObjgroup
			, const bool append
			, ListWzskMObjgroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstBySup, 1, supRefWzskMObjgroup);

	return loadRstByStmt(stmtLoadRstBySup, append, rst);
};

bool LiteTblWzskMObjgroup::loadSupByRef(
			ubigint ref
			, ubigint& supRefWzskMObjgroup
		) {
	sqlite3_bind_int64(stmtLoadSupByRef, 1, ref);

	return loadRefByStmt(stmtLoadSupByRef, supRefWzskMObjgroup);
};

#endif

