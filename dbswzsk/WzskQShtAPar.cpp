/**
	* \file WzskQShtAPar.cpp
	* Dbs and XML wrapper for table TblWzskQShtAPar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQShtAPar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQShtAPar
 ******************************************************************************/

WzskQShtAPar::WzskQShtAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1SrefKKey = x1SrefKKey;
	this->titX1SrefKKey = titX1SrefKKey;
	this->Val = Val;
};

void WzskQShtAPar::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["key"] = x1SrefKKey;
		me["key2"] = titX1SrefKKey;
		me["val"] = Val;
	} else {
		me["x1SrefKKey"] = x1SrefKKey;
		me["titX1SrefKKey"] = titX1SrefKKey;
		me["Val"] = Val;
	};
};

void WzskQShtAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQShtAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "key", x1SrefKKey);
		writeString(wr, "key2", titX1SrefKKey);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x1SrefKKey", x1SrefKKey);
		writeString(wr, "titX1SrefKKey", titX1SrefKKey);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQShtAPar
 ******************************************************************************/

ListWzskQShtAPar::ListWzskQShtAPar() {
};

ListWzskQShtAPar::ListWzskQShtAPar(
			const ListWzskQShtAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQShtAPar(*(src.nodes[i]));
};

ListWzskQShtAPar::~ListWzskQShtAPar() {
	clear();
};

void ListWzskQShtAPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQShtAPar::size() const {
	return(nodes.size());
};

void ListWzskQShtAPar::append(
			WzskQShtAPar* rec
		) {
	nodes.push_back(rec);
};

ListWzskQShtAPar& ListWzskQShtAPar::operator=(
			const ListWzskQShtAPar& src
		) {
	WzskQShtAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQShtAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQShtAPar::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWzskQShtAPar";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWzskQShtAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQShtAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQShtAPar
 ******************************************************************************/

TblWzskQShtAPar::TblWzskQShtAPar() {
};

TblWzskQShtAPar::~TblWzskQShtAPar() {
};

bool TblWzskQShtAPar::loadRecBySQL(
			const string& sqlstr
			, WzskQShtAPar** rec
		) {
	return false;
};

ubigint TblWzskQShtAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQShtAPar& rst
		) {
	return 0;
};

ubigint TblWzskQShtAPar::insertRec(
			WzskQShtAPar* rec
		) {
	return 0;
};

ubigint TblWzskQShtAPar::insertNewRec(
			WzskQShtAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WzskQShtAPar* _rec = NULL;

	_rec = new WzskQShtAPar(0, jref, jnum, ref, x1SrefKKey, titX1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQShtAPar::appendNewRecToRst(
			ListWzskQShtAPar& rst
			, WzskQShtAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKKey
			, const string titX1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WzskQShtAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1SrefKKey, titX1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQShtAPar::insertRst(
			ListWzskQShtAPar& rst
		) {
};

void TblWzskQShtAPar::updateRec(
			WzskQShtAPar* rec
		) {
};

void TblWzskQShtAPar::updateRst(
			ListWzskQShtAPar& rst
		) {
};

void TblWzskQShtAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQShtAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQShtAPar::loadRecByQref(
			ubigint qref
			, WzskQShtAPar** rec
		) {
	return false;
};

ubigint TblWzskQShtAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQShtAPar& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQShtAPar
 ******************************************************************************/

MyTblWzskQShtAPar::MyTblWzskQShtAPar() :
			TblWzskQShtAPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQShtAPar::~MyTblWzskQShtAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQShtAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQShtAPar (jref, jnum, ref, x1SrefKKey, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQShtAPar SET jref = ?, jnum = ?, ref = ?, x1SrefKKey = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQShtAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQShtAPar WHERE jref = ?", false);
};

bool MyTblWzskQShtAPar::loadRecBySQL(
			const string& sqlstr
			, WzskQShtAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQShtAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQShtAPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQShtAPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskQShtAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1SrefKKey.assign(dbrow[4], dblengths[4]); else _rec->x1SrefKKey = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQShtAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQShtAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQShtAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQShtAPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQShtAPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskQShtAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1SrefKKey.assign(dbrow[4], dblengths[4]); else rec->x1SrefKKey = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQShtAPar::insertRec(
			WzskQShtAPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->x1SrefKKey.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQShtAPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQShtAPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQShtAPar::insertRst(
			ListWzskQShtAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQShtAPar::updateRec(
			WzskQShtAPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x1SrefKKey.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQShtAPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQShtAPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQShtAPar::updateRst(
			ListWzskQShtAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQShtAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQShtAPar::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQShtAPar::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQShtAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQShtAPar::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQShtAPar::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQShtAPar::loadRecByQref(
			ubigint qref
			, WzskQShtAPar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQShtAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQShtAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQShtAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQShtAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQShtAPar
 ******************************************************************************/

LiteTblWzskQShtAPar::LiteTblWzskQShtAPar() :
			TblWzskQShtAPar()
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

LiteTblWzskQShtAPar::~LiteTblWzskQShtAPar() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQShtAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQShtAPar (jref, jnum, ref, x1SrefKKey, Val) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQShtAPar SET jref = ?1, jnum = ?2, ref = ?3, x1SrefKKey = ?4, Val = ?5 WHERE qref = ?6");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQShtAPar WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQShtAPar WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, x1SrefKKey, Val FROM TblWzskQShtAPar WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, x1SrefKKey, Val FROM TblWzskQShtAPar WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQShtAPar::loadRec(
			sqlite3_stmt* stmt
			, WzskQShtAPar** rec
		) {
	int res;

	WzskQShtAPar* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQShtAPar();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->x1SrefKKey.assign((const char*) sqlite3_column_text(stmt, 4));
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

ubigint LiteTblWzskQShtAPar::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQShtAPar& rst
		) {
	int res; ubigint numread = 0;

	WzskQShtAPar* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQShtAPar();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->x1SrefKKey.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQShtAPar::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQShtAPar** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQShtAPar::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQShtAPar& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQShtAPar::loadRecBySQL(
			const string& sqlstr
			, WzskQShtAPar** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQShtAPar::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQShtAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQShtAPar& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQShtAPar::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQShtAPar::insertRec(
			WzskQShtAPar* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_text(stmtInsertRec, 4, rec->x1SrefKKey.c_str(), rec->x1SrefKKey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQShtAPar::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQShtAPar::insertRst(
			ListWzskQShtAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQShtAPar::updateRec(
			WzskQShtAPar* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->x1SrefKKey.c_str(), rec->x1SrefKKey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQShtAPar::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQShtAPar::updateRst(
			ListWzskQShtAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQShtAPar::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQShtAPar::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQShtAPar::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQShtAPar::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQShtAPar::loadRecByQref(
			ubigint qref
			, WzskQShtAPar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQShtAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQShtAPar& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif
