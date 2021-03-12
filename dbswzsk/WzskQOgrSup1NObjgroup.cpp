/**
	* \file WzskQOgrSup1NObjgroup.cpp
	* Dbs and XML wrapper for table TblWzskQOgrSup1NObjgroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQOgrSup1NObjgroup.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQOgrSup1NObjgroup
 ******************************************************************************/

WzskQOgrSup1NObjgroup::WzskQOgrSup1NObjgroup(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void WzskQOgrSup1NObjgroup::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ref"] = stubRef;
	} else {
		me["stubRef"] = stubRef;
	};
};

void WzskQOgrSup1NObjgroup::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQOgrSup1NObjgroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQOgrSup1NObjgroup
 ******************************************************************************/

ListWzskQOgrSup1NObjgroup::ListWzskQOgrSup1NObjgroup() {
};

ListWzskQOgrSup1NObjgroup::ListWzskQOgrSup1NObjgroup(
			const ListWzskQOgrSup1NObjgroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQOgrSup1NObjgroup(*(src.nodes[i]));
};

ListWzskQOgrSup1NObjgroup::~ListWzskQOgrSup1NObjgroup() {
	clear();
};

void ListWzskQOgrSup1NObjgroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQOgrSup1NObjgroup::size() const {
	return(nodes.size());
};

void ListWzskQOgrSup1NObjgroup::append(
			WzskQOgrSup1NObjgroup* rec
		) {
	nodes.push_back(rec);
};

ListWzskQOgrSup1NObjgroup& ListWzskQOgrSup1NObjgroup::operator=(
			const ListWzskQOgrSup1NObjgroup& src
		) {
	WzskQOgrSup1NObjgroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQOgrSup1NObjgroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQOgrSup1NObjgroup::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWzskQOgrSup1NObjgroup";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWzskQOgrSup1NObjgroup::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQOgrSup1NObjgroup";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQOgrSup1NObjgroup
 ******************************************************************************/

TblWzskQOgrSup1NObjgroup::TblWzskQOgrSup1NObjgroup() {
};

TblWzskQOgrSup1NObjgroup::~TblWzskQOgrSup1NObjgroup() {
};

bool TblWzskQOgrSup1NObjgroup::loadRecBySQL(
			const string& sqlstr
			, WzskQOgrSup1NObjgroup** rec
		) {
	return false;
};

ubigint TblWzskQOgrSup1NObjgroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQOgrSup1NObjgroup& rst
		) {
	return 0;
};

ubigint TblWzskQOgrSup1NObjgroup::insertRec(
			WzskQOgrSup1NObjgroup* rec
		) {
	return 0;
};

ubigint TblWzskQOgrSup1NObjgroup::insertNewRec(
			WzskQOgrSup1NObjgroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WzskQOgrSup1NObjgroup* _rec = NULL;

	_rec = new WzskQOgrSup1NObjgroup(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQOgrSup1NObjgroup::appendNewRecToRst(
			ListWzskQOgrSup1NObjgroup& rst
			, WzskQOgrSup1NObjgroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WzskQOgrSup1NObjgroup* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQOgrSup1NObjgroup::insertRst(
			ListWzskQOgrSup1NObjgroup& rst
		) {
};

void TblWzskQOgrSup1NObjgroup::updateRec(
			WzskQOgrSup1NObjgroup* rec
		) {
};

void TblWzskQOgrSup1NObjgroup::updateRst(
			ListWzskQOgrSup1NObjgroup& rst
		) {
};

void TblWzskQOgrSup1NObjgroup::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQOgrSup1NObjgroup::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQOgrSup1NObjgroup::loadRecByQref(
			ubigint qref
			, WzskQOgrSup1NObjgroup** rec
		) {
	return false;
};

ubigint TblWzskQOgrSup1NObjgroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQOgrSup1NObjgroup& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQOgrSup1NObjgroup
 ******************************************************************************/

MyTblWzskQOgrSup1NObjgroup::MyTblWzskQOgrSup1NObjgroup() :
			TblWzskQOgrSup1NObjgroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQOgrSup1NObjgroup::~MyTblWzskQOgrSup1NObjgroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQOgrSup1NObjgroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQOgrSup1NObjgroup (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQOgrSup1NObjgroup SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQOgrSup1NObjgroup WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQOgrSup1NObjgroup WHERE jref = ?", false);
};

bool MyTblWzskQOgrSup1NObjgroup::loadRecBySQL(
			const string& sqlstr
			, WzskQOgrSup1NObjgroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQOgrSup1NObjgroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzskQOgrSup1NObjgroup();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQOgrSup1NObjgroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQOgrSup1NObjgroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQOgrSup1NObjgroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzskQOgrSup1NObjgroup();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQOgrSup1NObjgroup::insertRec(
			WzskQOgrSup1NObjgroup* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQOgrSup1NObjgroup::insertRst(
			ListWzskQOgrSup1NObjgroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQOgrSup1NObjgroup::updateRec(
			WzskQOgrSup1NObjgroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQOgrSup1NObjgroup::updateRst(
			ListWzskQOgrSup1NObjgroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQOgrSup1NObjgroup::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQOgrSup1NObjgroup::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQOgrSup1NObjgroup::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQOgrSup1NObjgroup::loadRecByQref(
			ubigint qref
			, WzskQOgrSup1NObjgroup** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQOgrSup1NObjgroup WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQOgrSup1NObjgroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQOgrSup1NObjgroup& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQOgrSup1NObjgroup WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQOgrSup1NObjgroup
 ******************************************************************************/

LiteTblWzskQOgrSup1NObjgroup::LiteTblWzskQOgrSup1NObjgroup() :
			TblWzskQOgrSup1NObjgroup()
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

LiteTblWzskQOgrSup1NObjgroup::~LiteTblWzskQOgrSup1NObjgroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQOgrSup1NObjgroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQOgrSup1NObjgroup (jref, jnum, ref) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQOgrSup1NObjgroup SET jref = ?1, jnum = ?2, ref = ?3 WHERE qref = ?4");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQOgrSup1NObjgroup WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQOgrSup1NObjgroup WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref FROM TblWzskQOgrSup1NObjgroup WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref FROM TblWzskQOgrSup1NObjgroup WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQOgrSup1NObjgroup::loadRec(
			sqlite3_stmt* stmt
			, WzskQOgrSup1NObjgroup** rec
		) {
	int res;

	WzskQOgrSup1NObjgroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQOgrSup1NObjgroup();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);

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

ubigint LiteTblWzskQOgrSup1NObjgroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQOgrSup1NObjgroup& rst
		) {
	int res; ubigint numread = 0;

	WzskQOgrSup1NObjgroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQOgrSup1NObjgroup();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQOgrSup1NObjgroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQOgrSup1NObjgroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQOgrSup1NObjgroup::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQOgrSup1NObjgroup& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQOgrSup1NObjgroup::loadRecBySQL(
			const string& sqlstr
			, WzskQOgrSup1NObjgroup** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQOgrSup1NObjgroup::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQOgrSup1NObjgroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQOgrSup1NObjgroup& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQOgrSup1NObjgroup::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQOgrSup1NObjgroup::insertRec(
			WzskQOgrSup1NObjgroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQOgrSup1NObjgroup::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQOgrSup1NObjgroup::insertRst(
			ListWzskQOgrSup1NObjgroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQOgrSup1NObjgroup::updateRec(
			WzskQOgrSup1NObjgroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQOgrSup1NObjgroup::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQOgrSup1NObjgroup::updateRst(
			ListWzskQOgrSup1NObjgroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQOgrSup1NObjgroup::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQOgrSup1NObjgroup::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQOgrSup1NObjgroup::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQOgrSup1NObjgroup::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQOgrSup1NObjgroup::loadRecByQref(
			ubigint qref
			, WzskQOgrSup1NObjgroup** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQOgrSup1NObjgroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQOgrSup1NObjgroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif
