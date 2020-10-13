/**
	* \file WzskQShtList.cpp
	* Dbs and XML wrapper for table TblWzskQShtList (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "WzskQShtList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQShtList
 ******************************************************************************/

WzskQShtList::WzskQShtList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzskMSession
			, const string stubRefWzskMSession
			, const ubigint refWzskMObject
			, const string stubRefWzskMObject
			, const uint start
			, const string ftmStart
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refWzskMSession = refWzskMSession;
	this->stubRefWzskMSession = stubRefWzskMSession;
	this->refWzskMObject = refWzskMObject;
	this->stubRefWzskMObject = stubRefWzskMObject;
	this->start = start;
	this->ftmStart = ftmStart;
};

void WzskQShtList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQShtList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ses", stubRefWzskMSession);
		writeString(wr, "obj", stubRefWzskMObject);
		writeString(wr, "sta", ftmStart);
	} else {
		writeString(wr, "stubRefWzskMSession", stubRefWzskMSession);
		writeString(wr, "stubRefWzskMObject", stubRefWzskMObject);
		writeString(wr, "ftmStart", ftmStart);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQShtList
 ******************************************************************************/

ListWzskQShtList::ListWzskQShtList() {
};

ListWzskQShtList::ListWzskQShtList(
			const ListWzskQShtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQShtList(*(src.nodes[i]));
};

ListWzskQShtList::~ListWzskQShtList() {
	clear();
};

void ListWzskQShtList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQShtList::size() const {
	return(nodes.size());
};

void ListWzskQShtList::append(
			WzskQShtList* rec
		) {
	nodes.push_back(rec);
};

ListWzskQShtList& ListWzskQShtList::operator=(
			const ListWzskQShtList& src
		) {
	WzskQShtList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQShtList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQShtList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQShtList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQShtList
 ******************************************************************************/

TblWzskQShtList::TblWzskQShtList() {
};

TblWzskQShtList::~TblWzskQShtList() {
};

bool TblWzskQShtList::loadRecBySQL(
			const string& sqlstr
			, WzskQShtList** rec
		) {
	return false;
};

ubigint TblWzskQShtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQShtList& rst
		) {
	return 0;
};

ubigint TblWzskQShtList::insertRec(
			WzskQShtList* rec
		) {
	return 0;
};

ubigint TblWzskQShtList::insertNewRec(
			WzskQShtList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzskMSession
			, const string stubRefWzskMSession
			, const ubigint refWzskMObject
			, const string stubRefWzskMObject
			, const uint start
			, const string ftmStart
		) {
	ubigint retval = 0;
	WzskQShtList* _rec = NULL;

	_rec = new WzskQShtList(0, jref, jnum, ref, refWzskMSession, stubRefWzskMSession, refWzskMObject, stubRefWzskMObject, start, ftmStart);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQShtList::appendNewRecToRst(
			ListWzskQShtList& rst
			, WzskQShtList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzskMSession
			, const string stubRefWzskMSession
			, const ubigint refWzskMObject
			, const string stubRefWzskMObject
			, const uint start
			, const string ftmStart
		) {
	ubigint retval = 0;
	WzskQShtList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refWzskMSession, stubRefWzskMSession, refWzskMObject, stubRefWzskMObject, start, ftmStart);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQShtList::insertRst(
			ListWzskQShtList& rst
		) {
};

void TblWzskQShtList::updateRec(
			WzskQShtList* rec
		) {
};

void TblWzskQShtList::updateRst(
			ListWzskQShtList& rst
		) {
};

void TblWzskQShtList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQShtList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQShtList::loadRecByQref(
			ubigint qref
			, WzskQShtList** rec
		) {
	return false;
};

ubigint TblWzskQShtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQShtList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQShtList
 ******************************************************************************/

MyTblWzskQShtList::MyTblWzskQShtList() :
			TblWzskQShtList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQShtList::~MyTblWzskQShtList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQShtList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQShtList (jref, jnum, ref, refWzskMSession, refWzskMObject, start) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQShtList SET jref = ?, jnum = ?, ref = ?, refWzskMSession = ?, refWzskMObject = ?, start = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQShtList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQShtList WHERE jref = ?", false);
};

bool MyTblWzskQShtList::loadRecBySQL(
			const string& sqlstr
			, WzskQShtList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQShtList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQShtList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQShtList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzskQShtList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refWzskMSession = atoll((char*) dbrow[4]); else _rec->refWzskMSession = 0;
		if (dbrow[5]) _rec->refWzskMObject = atoll((char*) dbrow[5]); else _rec->refWzskMObject = 0;
		if (dbrow[6]) _rec->start = atol((char*) dbrow[6]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQShtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQShtList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQShtList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQShtList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQShtList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzskQShtList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refWzskMSession = atoll((char*) dbrow[4]); else rec->refWzskMSession = 0;
			if (dbrow[5]) rec->refWzskMObject = atoll((char*) dbrow[5]); else rec->refWzskMObject = 0;
			if (dbrow[6]) rec->start = atol((char*) dbrow[6]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQShtList::insertRec(
			WzskQShtList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzskMSession,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWzskMObject,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->start,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQShtList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQShtList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQShtList::insertRst(
			ListWzskQShtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQShtList::updateRec(
			WzskQShtList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzskMSession,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWzskMObject,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->start,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQShtList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQShtList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQShtList::updateRst(
			ListWzskQShtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQShtList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQShtList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQShtList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQShtList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQShtList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQShtList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQShtList::loadRecByQref(
			ubigint qref
			, WzskQShtList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQShtList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQShtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQShtList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQShtList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQShtList
 ******************************************************************************/

LiteTblWzskQShtList::LiteTblWzskQShtList() :
			TblWzskQShtList()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;

	stmtLoadRecByQref = NULL;
	stmtLoadRecByJref = NULL;
	stmtLoadRstByJref = NULL;
};

LiteTblWzskQShtList::~LiteTblWzskQShtList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQShtList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQShtList (jref, jnum, ref, refWzskMSession, refWzskMObject, start) VALUES (?1,?2,?3,?4,?5,?6)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQShtList SET jref = ?1, jnum = ?2, ref = ?3, refWzskMSession = ?4, refWzskMObject = ?5, start = ?6 WHERE qref = ?7");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQShtList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQShtList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, refWzskMSession, refWzskMObject, start FROM TblWzskQShtList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, refWzskMSession, refWzskMObject, start FROM TblWzskQShtList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQShtList::loadRec(
			sqlite3_stmt* stmt
			, WzskQShtList** rec
		) {
	int res;

	WzskQShtList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQShtList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->refWzskMSession = sqlite3_column_int64(stmt, 4);
		_rec->refWzskMObject = sqlite3_column_int64(stmt, 5);
		_rec->start = sqlite3_column_int(stmt, 6);

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

ubigint LiteTblWzskQShtList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQShtList& rst
		) {
	int res; ubigint numread = 0;

	WzskQShtList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQShtList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->refWzskMSession = sqlite3_column_int64(stmt, 4);
		rec->refWzskMObject = sqlite3_column_int64(stmt, 5);
		rec->start = sqlite3_column_int(stmt, 6);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQShtList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQShtList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQShtList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQShtList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQShtList::loadRecBySQL(
			const string& sqlstr
			, WzskQShtList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQShtList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQShtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQShtList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQShtList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQShtList::insertRec(
			WzskQShtList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzskMSession);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->refWzskMObject);
	sqlite3_bind_int(stmtInsertRec, 6, rec->start);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQShtList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQShtList::insertRst(
			ListWzskQShtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQShtList::updateRec(
			WzskQShtList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzskMSession);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->refWzskMObject);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->start);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQShtList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQShtList::updateRst(
			ListWzskQShtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQShtList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQShtList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQShtList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQShtList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQShtList::loadRecByQref(
			ubigint qref
			, WzskQShtList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQShtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQShtList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

