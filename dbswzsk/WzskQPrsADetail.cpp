/**
	* \file WzskQPrsADetail.cpp
	* Dbs and XML wrapper for table TblWzskQPrsADetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQPrsADetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQPrsADetail
 ******************************************************************************/

WzskQPrsADetail::WzskQPrsADetail(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1SrefKType = x1SrefKType;
	this->titX1SrefKType = titX1SrefKType;
	this->Val = Val;
};

void WzskQPrsADetail::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["typ"] = x1SrefKType;
		me["typ2"] = titX1SrefKType;
		me["val"] = Val;
	} else {
		me["x1SrefKType"] = x1SrefKType;
		me["titX1SrefKType"] = titX1SrefKType;
		me["Val"] = Val;
	};
};

void WzskQPrsADetail::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQPrsADetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", x1SrefKType);
		writeString(wr, "typ2", titX1SrefKType);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x1SrefKType", x1SrefKType);
		writeString(wr, "titX1SrefKType", titX1SrefKType);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQPrsADetail
 ******************************************************************************/

ListWzskQPrsADetail::ListWzskQPrsADetail() {
};

ListWzskQPrsADetail::ListWzskQPrsADetail(
			const ListWzskQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQPrsADetail(*(src.nodes[i]));
};

ListWzskQPrsADetail::~ListWzskQPrsADetail() {
	clear();
};

void ListWzskQPrsADetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQPrsADetail::size() const {
	return(nodes.size());
};

void ListWzskQPrsADetail::append(
			WzskQPrsADetail* rec
		) {
	nodes.push_back(rec);
};

ListWzskQPrsADetail& ListWzskQPrsADetail::operator=(
			const ListWzskQPrsADetail& src
		) {
	WzskQPrsADetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQPrsADetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQPrsADetail::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWzskQPrsADetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWzskQPrsADetail::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQPrsADetail";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQPrsADetail
 ******************************************************************************/

TblWzskQPrsADetail::TblWzskQPrsADetail() {
};

TblWzskQPrsADetail::~TblWzskQPrsADetail() {
};

bool TblWzskQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, WzskQPrsADetail** rec
		) {
	return false;
};

ubigint TblWzskQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQPrsADetail& rst
		) {
	return 0;
};

ubigint TblWzskQPrsADetail::insertRec(
			WzskQPrsADetail* rec
		) {
	return 0;
};

ubigint TblWzskQPrsADetail::insertNewRec(
			WzskQPrsADetail** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WzskQPrsADetail* _rec = NULL;

	_rec = new WzskQPrsADetail(0, jref, jnum, ref, x1SrefKType, titX1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQPrsADetail::appendNewRecToRst(
			ListWzskQPrsADetail& rst
			, WzskQPrsADetail** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WzskQPrsADetail* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1SrefKType, titX1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQPrsADetail::insertRst(
			ListWzskQPrsADetail& rst
		) {
};

void TblWzskQPrsADetail::updateRec(
			WzskQPrsADetail* rec
		) {
};

void TblWzskQPrsADetail::updateRst(
			ListWzskQPrsADetail& rst
		) {
};

void TblWzskQPrsADetail::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQPrsADetail::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQPrsADetail::loadRecByQref(
			ubigint qref
			, WzskQPrsADetail** rec
		) {
	return false;
};

ubigint TblWzskQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQPrsADetail& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQPrsADetail
 ******************************************************************************/

MyTblWzskQPrsADetail::MyTblWzskQPrsADetail() :
			TblWzskQPrsADetail()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQPrsADetail::~MyTblWzskQPrsADetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQPrsADetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQPrsADetail (jref, jnum, ref, x1SrefKType, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQPrsADetail SET jref = ?, jnum = ?, ref = ?, x1SrefKType = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQPrsADetail WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQPrsADetail WHERE jref = ?", false);
};

bool MyTblWzskQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, WzskQPrsADetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQPrsADetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQPrsADetail::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQPrsADetail::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskQPrsADetail();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1SrefKType.assign(dbrow[4], dblengths[4]); else _rec->x1SrefKType = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQPrsADetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQPrsADetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQPrsADetail::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQPrsADetail::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskQPrsADetail();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1SrefKType.assign(dbrow[4], dblengths[4]); else rec->x1SrefKType = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQPrsADetail::insertRec(
			WzskQPrsADetail* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->x1SrefKType.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQPrsADetail::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQPrsADetail::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQPrsADetail::insertRst(
			ListWzskQPrsADetail& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQPrsADetail::updateRec(
			WzskQPrsADetail* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x1SrefKType.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQPrsADetail::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQPrsADetail::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQPrsADetail::updateRst(
			ListWzskQPrsADetail& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQPrsADetail::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQPrsADetail::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQPrsADetail::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQPrsADetail::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQPrsADetail::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQPrsADetail::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQPrsADetail::loadRecByQref(
			ubigint qref
			, WzskQPrsADetail** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQPrsADetail WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQPrsADetail& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQPrsADetail WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQPrsADetail
 ******************************************************************************/

LiteTblWzskQPrsADetail::LiteTblWzskQPrsADetail() :
			TblWzskQPrsADetail()
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

LiteTblWzskQPrsADetail::~LiteTblWzskQPrsADetail() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQPrsADetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQPrsADetail (jref, jnum, ref, x1SrefKType, Val) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQPrsADetail SET jref = ?1, jnum = ?2, ref = ?3, x1SrefKType = ?4, Val = ?5 WHERE qref = ?6");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQPrsADetail WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQPrsADetail WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, x1SrefKType, Val FROM TblWzskQPrsADetail WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, x1SrefKType, Val FROM TblWzskQPrsADetail WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQPrsADetail::loadRec(
			sqlite3_stmt* stmt
			, WzskQPrsADetail** rec
		) {
	int res;

	WzskQPrsADetail* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQPrsADetail();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->x1SrefKType.assign((const char*) sqlite3_column_text(stmt, 4));
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

ubigint LiteTblWzskQPrsADetail::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQPrsADetail& rst
		) {
	int res; ubigint numread = 0;

	WzskQPrsADetail* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQPrsADetail();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->x1SrefKType.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQPrsADetail::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQPrsADetail** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQPrsADetail::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQPrsADetail& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, WzskQPrsADetail** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQPrsADetail::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQPrsADetail& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQPrsADetail::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQPrsADetail::insertRec(
			WzskQPrsADetail* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_text(stmtInsertRec, 4, rec->x1SrefKType.c_str(), rec->x1SrefKType.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQPrsADetail::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQPrsADetail::insertRst(
			ListWzskQPrsADetail& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQPrsADetail::updateRec(
			WzskQPrsADetail* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->x1SrefKType.c_str(), rec->x1SrefKType.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQPrsADetail::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQPrsADetail::updateRst(
			ListWzskQPrsADetail& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQPrsADetail::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQPrsADetail::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQPrsADetail::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQPrsADetail::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQPrsADetail::loadRecByQref(
			ubigint qref
			, WzskQPrsADetail** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQPrsADetail& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif
