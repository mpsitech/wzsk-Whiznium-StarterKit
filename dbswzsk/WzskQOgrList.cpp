/**
	* \file WzskQOgrList.cpp
	* Dbs and XML wrapper for table TblWzskQOgrList (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "WzskQOgrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQOgrList
 ******************************************************************************/

WzskQOgrList::WzskQOgrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint supRefWzskMObjgroup
			, const string stubSupRefWzskMObjgroup
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->supRefWzskMObjgroup = supRefWzskMObjgroup;
	this->stubSupRefWzskMObjgroup = stubSupRefWzskMObjgroup;
};

void WzskQOgrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQOgrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "sup", stubSupRefWzskMObjgroup);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "stubSupRefWzskMObjgroup", stubSupRefWzskMObjgroup);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQOgrList
 ******************************************************************************/

ListWzskQOgrList::ListWzskQOgrList() {
};

ListWzskQOgrList::ListWzskQOgrList(
			const ListWzskQOgrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQOgrList(*(src.nodes[i]));
};

ListWzskQOgrList::~ListWzskQOgrList() {
	clear();
};

void ListWzskQOgrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQOgrList::size() const {
	return(nodes.size());
};

void ListWzskQOgrList::append(
			WzskQOgrList* rec
		) {
	nodes.push_back(rec);
};

ListWzskQOgrList& ListWzskQOgrList::operator=(
			const ListWzskQOgrList& src
		) {
	WzskQOgrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQOgrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQOgrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQOgrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQOgrList
 ******************************************************************************/

TblWzskQOgrList::TblWzskQOgrList() {
};

TblWzskQOgrList::~TblWzskQOgrList() {
};

bool TblWzskQOgrList::loadRecBySQL(
			const string& sqlstr
			, WzskQOgrList** rec
		) {
	return false;
};

ubigint TblWzskQOgrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQOgrList& rst
		) {
	return 0;
};

ubigint TblWzskQOgrList::insertRec(
			WzskQOgrList* rec
		) {
	return 0;
};

ubigint TblWzskQOgrList::insertNewRec(
			WzskQOgrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint supRefWzskMObjgroup
			, const string stubSupRefWzskMObjgroup
		) {
	ubigint retval = 0;
	WzskQOgrList* _rec = NULL;

	_rec = new WzskQOgrList(0, jref, jnum, ref, sref, Title, supRefWzskMObjgroup, stubSupRefWzskMObjgroup);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQOgrList::appendNewRecToRst(
			ListWzskQOgrList& rst
			, WzskQOgrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint supRefWzskMObjgroup
			, const string stubSupRefWzskMObjgroup
		) {
	ubigint retval = 0;
	WzskQOgrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, supRefWzskMObjgroup, stubSupRefWzskMObjgroup);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQOgrList::insertRst(
			ListWzskQOgrList& rst
		) {
};

void TblWzskQOgrList::updateRec(
			WzskQOgrList* rec
		) {
};

void TblWzskQOgrList::updateRst(
			ListWzskQOgrList& rst
		) {
};

void TblWzskQOgrList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQOgrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQOgrList::loadRecByQref(
			ubigint qref
			, WzskQOgrList** rec
		) {
	return false;
};

ubigint TblWzskQOgrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQOgrList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQOgrList
 ******************************************************************************/

MyTblWzskQOgrList::MyTblWzskQOgrList() :
			TblWzskQOgrList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQOgrList::~MyTblWzskQOgrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQOgrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQOgrList (jref, jnum, ref, sref, Title, supRefWzskMObjgroup) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQOgrList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, supRefWzskMObjgroup = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQOgrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQOgrList WHERE jref = ?", false);
};

bool MyTblWzskQOgrList::loadRecBySQL(
			const string& sqlstr
			, WzskQOgrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQOgrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQOgrList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQOgrList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskQOgrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->supRefWzskMObjgroup = atoll((char*) dbrow[6]); else _rec->supRefWzskMObjgroup = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQOgrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQOgrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQOgrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQOgrList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQOgrList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskQOgrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->supRefWzskMObjgroup = atoll((char*) dbrow[6]); else rec->supRefWzskMObjgroup = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQOgrList::insertRec(
			WzskQOgrList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefWzskMObjgroup,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQOgrList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQOgrList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQOgrList::insertRst(
			ListWzskQOgrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQOgrList::updateRec(
			WzskQOgrList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefWzskMObjgroup,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQOgrList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQOgrList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQOgrList::updateRst(
			ListWzskQOgrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQOgrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQOgrList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQOgrList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQOgrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQOgrList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQOgrList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQOgrList::loadRecByQref(
			ubigint qref
			, WzskQOgrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQOgrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQOgrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQOgrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQOgrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQOgrList
 ******************************************************************************/

LiteTblWzskQOgrList::LiteTblWzskQOgrList() :
			TblWzskQOgrList()
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

LiteTblWzskQOgrList::~LiteTblWzskQOgrList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQOgrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQOgrList (jref, jnum, ref, sref, Title, supRefWzskMObjgroup) VALUES (?1,?2,?3,?4,?5,?6)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQOgrList SET jref = ?1, jnum = ?2, ref = ?3, sref = ?4, Title = ?5, supRefWzskMObjgroup = ?6 WHERE qref = ?7");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQOgrList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQOgrList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, sref, Title, supRefWzskMObjgroup FROM TblWzskQOgrList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, sref, Title, supRefWzskMObjgroup FROM TblWzskQOgrList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQOgrList::loadRec(
			sqlite3_stmt* stmt
			, WzskQOgrList** rec
		) {
	int res;

	WzskQOgrList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQOgrList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->supRefWzskMObjgroup = sqlite3_column_int64(stmt, 6);

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

ubigint LiteTblWzskQOgrList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQOgrList& rst
		) {
	int res; ubigint numread = 0;

	WzskQOgrList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQOgrList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->supRefWzskMObjgroup = sqlite3_column_int64(stmt, 6);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQOgrList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQOgrList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQOgrList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQOgrList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQOgrList::loadRecBySQL(
			const string& sqlstr
			, WzskQOgrList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQOgrList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQOgrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQOgrList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQOgrList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQOgrList::insertRec(
			WzskQOgrList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_text(stmtInsertRec, 4, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 6, rec->supRefWzskMObjgroup);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQOgrList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQOgrList::insertRst(
			ListWzskQOgrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQOgrList::updateRec(
			WzskQOgrList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->supRefWzskMObjgroup);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQOgrList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQOgrList::updateRst(
			ListWzskQOgrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQOgrList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQOgrList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQOgrList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQOgrList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQOgrList::loadRecByQref(
			ubigint qref
			, WzskQOgrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQOgrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQOgrList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

