/**
	* \file WzskQSesList.cpp
	* Dbs and XML wrapper for table TblWzskQSesList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQSesList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQSesList
 ******************************************************************************/

WzskQSesList::WzskQSesList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzskMUser
			, const string stubRefWzskMUser
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
			, const string Ip
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refWzskMUser = refWzskMUser;
	this->stubRefWzskMUser = stubRefWzskMUser;
	this->start = start;
	this->ftmStart = ftmStart;
	this->stop = stop;
	this->ftmStop = ftmStop;
	this->Ip = Ip;
};

void WzskQSesList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQSesList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "usr", stubRefWzskMUser);
		writeString(wr, "sta", ftmStart);
		writeString(wr, "sto", ftmStop);
		writeString(wr, "ip", Ip);
	} else {
		writeString(wr, "stubRefWzskMUser", stubRefWzskMUser);
		writeString(wr, "ftmStart", ftmStart);
		writeString(wr, "ftmStop", ftmStop);
		writeString(wr, "Ip", Ip);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQSesList
 ******************************************************************************/

ListWzskQSesList::ListWzskQSesList() {
};

ListWzskQSesList::ListWzskQSesList(
			const ListWzskQSesList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQSesList(*(src.nodes[i]));
};

ListWzskQSesList::~ListWzskQSesList() {
	clear();
};

void ListWzskQSesList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQSesList::size() const {
	return(nodes.size());
};

void ListWzskQSesList::append(
			WzskQSesList* rec
		) {
	nodes.push_back(rec);
};

ListWzskQSesList& ListWzskQSesList::operator=(
			const ListWzskQSesList& src
		) {
	WzskQSesList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQSesList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQSesList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQSesList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQSesList
 ******************************************************************************/

TblWzskQSesList::TblWzskQSesList() {
};

TblWzskQSesList::~TblWzskQSesList() {
};

bool TblWzskQSesList::loadRecBySQL(
			const string& sqlstr
			, WzskQSesList** rec
		) {
	return false;
};

ubigint TblWzskQSesList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQSesList& rst
		) {
	return 0;
};

ubigint TblWzskQSesList::insertRec(
			WzskQSesList* rec
		) {
	return 0;
};

ubigint TblWzskQSesList::insertNewRec(
			WzskQSesList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzskMUser
			, const string stubRefWzskMUser
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
			, const string Ip
		) {
	ubigint retval = 0;
	WzskQSesList* _rec = NULL;

	_rec = new WzskQSesList(0, jref, jnum, ref, refWzskMUser, stubRefWzskMUser, start, ftmStart, stop, ftmStop, Ip);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQSesList::appendNewRecToRst(
			ListWzskQSesList& rst
			, WzskQSesList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzskMUser
			, const string stubRefWzskMUser
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
			, const string Ip
		) {
	ubigint retval = 0;
	WzskQSesList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refWzskMUser, stubRefWzskMUser, start, ftmStart, stop, ftmStop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQSesList::insertRst(
			ListWzskQSesList& rst
		) {
};

void TblWzskQSesList::updateRec(
			WzskQSesList* rec
		) {
};

void TblWzskQSesList::updateRst(
			ListWzskQSesList& rst
		) {
};

void TblWzskQSesList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQSesList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQSesList::loadRecByQref(
			ubigint qref
			, WzskQSesList** rec
		) {
	return false;
};

ubigint TblWzskQSesList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQSesList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQSesList
 ******************************************************************************/

MyTblWzskQSesList::MyTblWzskQSesList() :
			TblWzskQSesList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQSesList::~MyTblWzskQSesList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQSesList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQSesList (jref, jnum, ref, refWzskMUser, start, stop, Ip) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQSesList SET jref = ?, jnum = ?, ref = ?, refWzskMUser = ?, start = ?, stop = ?, Ip = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQSesList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQSesList WHERE jref = ?", false);
};

bool MyTblWzskQSesList::loadRecBySQL(
			const string& sqlstr
			, WzskQSesList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQSesList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQSesList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQSesList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskQSesList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refWzskMUser = atoll((char*) dbrow[4]); else _rec->refWzskMUser = 0;
		if (dbrow[5]) _rec->start = atol((char*) dbrow[5]); else _rec->start = 0;
		if (dbrow[6]) _rec->stop = atol((char*) dbrow[6]); else _rec->stop = 0;
		if (dbrow[7]) _rec->Ip.assign(dbrow[7], dblengths[7]); else _rec->Ip = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQSesList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQSesList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQSesList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQSesList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQSesList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskQSesList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refWzskMUser = atoll((char*) dbrow[4]); else rec->refWzskMUser = 0;
			if (dbrow[5]) rec->start = atol((char*) dbrow[5]); else rec->start = 0;
			if (dbrow[6]) rec->stop = atol((char*) dbrow[6]); else rec->stop = 0;
			if (dbrow[7]) rec->Ip.assign(dbrow[7], dblengths[7]); else rec->Ip = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQSesList::insertRec(
			WzskQSesList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[6] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzskMUser,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->stop,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQSesList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQSesList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQSesList::insertRst(
			ListWzskQSesList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQSesList::updateRec(
			WzskQSesList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzskMUser,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->stop,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQSesList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQSesList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQSesList::updateRst(
			ListWzskQSesList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQSesList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQSesList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQSesList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQSesList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQSesList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQSesList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQSesList::loadRecByQref(
			ubigint qref
			, WzskQSesList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQSesList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQSesList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQSesList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQSesList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQSesList
 ******************************************************************************/

LiteTblWzskQSesList::LiteTblWzskQSesList() :
			TblWzskQSesList()
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

LiteTblWzskQSesList::~LiteTblWzskQSesList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQSesList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQSesList (jref, jnum, ref, refWzskMUser, start, stop, Ip) VALUES (?1,?2,?3,?4,?5,?6,?7)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQSesList SET jref = ?1, jnum = ?2, ref = ?3, refWzskMUser = ?4, start = ?5, stop = ?6, Ip = ?7 WHERE qref = ?8");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQSesList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQSesList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, refWzskMUser, start, stop, Ip FROM TblWzskQSesList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, refWzskMUser, start, stop, Ip FROM TblWzskQSesList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQSesList::loadRec(
			sqlite3_stmt* stmt
			, WzskQSesList** rec
		) {
	int res;

	WzskQSesList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQSesList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->refWzskMUser = sqlite3_column_int64(stmt, 4);
		_rec->start = sqlite3_column_int(stmt, 5);
		_rec->stop = sqlite3_column_int(stmt, 6);
		_rec->Ip.assign((const char*) sqlite3_column_text(stmt, 7));

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

ubigint LiteTblWzskQSesList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQSesList& rst
		) {
	int res; ubigint numread = 0;

	WzskQSesList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQSesList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->refWzskMUser = sqlite3_column_int64(stmt, 4);
		rec->start = sqlite3_column_int(stmt, 5);
		rec->stop = sqlite3_column_int(stmt, 6);
		rec->Ip.assign((const char*) sqlite3_column_text(stmt, 7));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQSesList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQSesList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQSesList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQSesList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQSesList::loadRecBySQL(
			const string& sqlstr
			, WzskQSesList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQSesList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQSesList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQSesList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQSesList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQSesList::insertRec(
			WzskQSesList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzskMUser);
	sqlite3_bind_int(stmtInsertRec, 5, rec->start);
	sqlite3_bind_int(stmtInsertRec, 6, rec->stop);
	sqlite3_bind_text(stmtInsertRec, 7, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQSesList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQSesList::insertRst(
			ListWzskQSesList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQSesList::updateRec(
			WzskQSesList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzskMUser);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->stop);
	sqlite3_bind_text(stmtUpdateRec, 7, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQSesList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQSesList::updateRst(
			ListWzskQSesList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQSesList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQSesList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQSesList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQSesList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQSesList::loadRecByQref(
			ubigint qref
			, WzskQSesList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQSesList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQSesList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

