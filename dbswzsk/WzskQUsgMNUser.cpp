/**
	* \file WzskQUsgMNUser.cpp
	* Dbs and XML wrapper for table TblWzskQUsgMNUser (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "WzskQUsgMNUser.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsgMNUser
 ******************************************************************************/

WzskQUsgMNUser::WzskQUsgMNUser(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWzskVUserlevel
			, const string srefIxWzskVUserlevel
			, const string titIxWzskVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixWzskVUserlevel = ixWzskVUserlevel;
	this->srefIxWzskVUserlevel = srefIxWzskVUserlevel;
	this->titIxWzskVUserlevel = titIxWzskVUserlevel;
};

void WzskQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQUsgMNUser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxWzskVUserlevel);
		writeString(wr, "ulv2", titIxWzskVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxWzskVUserlevel", srefIxWzskVUserlevel);
		writeString(wr, "titIxWzskVUserlevel", titIxWzskVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQUsgMNUser
 ******************************************************************************/

ListWzskQUsgMNUser::ListWzskQUsgMNUser() {
};

ListWzskQUsgMNUser::ListWzskQUsgMNUser(
			const ListWzskQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsgMNUser(*(src.nodes[i]));
};

ListWzskQUsgMNUser::~ListWzskQUsgMNUser() {
	clear();
};

void ListWzskQUsgMNUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQUsgMNUser::size() const {
	return(nodes.size());
};

void ListWzskQUsgMNUser::append(
			WzskQUsgMNUser* rec
		) {
	nodes.push_back(rec);
};

ListWzskQUsgMNUser& ListWzskQUsgMNUser::operator=(
			const ListWzskQUsgMNUser& src
		) {
	WzskQUsgMNUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQUsgMNUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQUsgMNUser";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQUsgMNUser
 ******************************************************************************/

TblWzskQUsgMNUser::TblWzskQUsgMNUser() {
};

TblWzskQUsgMNUser::~TblWzskQUsgMNUser() {
};

bool TblWzskQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, WzskQUsgMNUser** rec
		) {
	return false;
};

ubigint TblWzskQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsgMNUser& rst
		) {
	return 0;
};

ubigint TblWzskQUsgMNUser::insertRec(
			WzskQUsgMNUser* rec
		) {
	return 0;
};

ubigint TblWzskQUsgMNUser::insertNewRec(
			WzskQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWzskVUserlevel
			, const string srefIxWzskVUserlevel
			, const string titIxWzskVUserlevel
		) {
	ubigint retval = 0;
	WzskQUsgMNUser* _rec = NULL;

	_rec = new WzskQUsgMNUser(0, jref, jnum, mref, stubMref, ref, ixWzskVUserlevel, srefIxWzskVUserlevel, titIxWzskVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQUsgMNUser::appendNewRecToRst(
			ListWzskQUsgMNUser& rst
			, WzskQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWzskVUserlevel
			, const string srefIxWzskVUserlevel
			, const string titIxWzskVUserlevel
		) {
	ubigint retval = 0;
	WzskQUsgMNUser* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixWzskVUserlevel, srefIxWzskVUserlevel, titIxWzskVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQUsgMNUser::insertRst(
			ListWzskQUsgMNUser& rst
		) {
};

void TblWzskQUsgMNUser::updateRec(
			WzskQUsgMNUser* rec
		) {
};

void TblWzskQUsgMNUser::updateRst(
			ListWzskQUsgMNUser& rst
		) {
};

void TblWzskQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQUsgMNUser::loadRecByQref(
			ubigint qref
			, WzskQUsgMNUser** rec
		) {
	return false;
};

ubigint TblWzskQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsgMNUser& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQUsgMNUser
 ******************************************************************************/

MyTblWzskQUsgMNUser::MyTblWzskQUsgMNUser() :
			TblWzskQUsgMNUser()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQUsgMNUser::~MyTblWzskQUsgMNUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQUsgMNUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQUsgMNUser (jref, jnum, mref, ref, ixWzskVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQUsgMNUser SET jref = ?, jnum = ?, mref = ?, ref = ?, ixWzskVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQUsgMNUser WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQUsgMNUser WHERE jref = ?", false);
};

bool MyTblWzskQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, WzskQUsgMNUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQUsgMNUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQUsgMNUser::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQUsgMNUser::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzskQUsgMNUser();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixWzskVUserlevel = atol((char*) dbrow[5]); else _rec->ixWzskVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsgMNUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQUsgMNUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQUsgMNUser::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQUsgMNUser::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzskQUsgMNUser();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixWzskVUserlevel = atol((char*) dbrow[5]); else rec->ixWzskVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQUsgMNUser::insertRec(
			WzskQUsgMNUser* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWzskVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQUsgMNUser::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQUsgMNUser::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQUsgMNUser::insertRst(
			ListWzskQUsgMNUser& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQUsgMNUser::updateRec(
			WzskQUsgMNUser* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWzskVUserlevel,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQUsgMNUser::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQUsgMNUser::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQUsgMNUser::updateRst(
			ListWzskQUsgMNUser& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQUsgMNUser::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQUsgMNUser::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQUsgMNUser::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQUsgMNUser::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQUsgMNUser::loadRecByQref(
			ubigint qref
			, WzskQUsgMNUser** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQUsgMNUser WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsgMNUser& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQUsgMNUser WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQUsgMNUser
 ******************************************************************************/

LiteTblWzskQUsgMNUser::LiteTblWzskQUsgMNUser() :
			TblWzskQUsgMNUser()
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

LiteTblWzskQUsgMNUser::~LiteTblWzskQUsgMNUser() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQUsgMNUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQUsgMNUser (jref, jnum, mref, ref, ixWzskVUserlevel) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQUsgMNUser SET jref = ?1, jnum = ?2, mref = ?3, ref = ?4, ixWzskVUserlevel = ?5 WHERE qref = ?6");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQUsgMNUser WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQUsgMNUser WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, mref, ref, ixWzskVUserlevel FROM TblWzskQUsgMNUser WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, mref, ref, ixWzskVUserlevel FROM TblWzskQUsgMNUser WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQUsgMNUser::loadRec(
			sqlite3_stmt* stmt
			, WzskQUsgMNUser** rec
		) {
	int res;

	WzskQUsgMNUser* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQUsgMNUser();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->mref = sqlite3_column_int64(stmt, 3);
		_rec->ref = sqlite3_column_int64(stmt, 4);
		_rec->ixWzskVUserlevel = sqlite3_column_int(stmt, 5);

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

ubigint LiteTblWzskQUsgMNUser::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQUsgMNUser& rst
		) {
	int res; ubigint numread = 0;

	WzskQUsgMNUser* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQUsgMNUser();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->mref = sqlite3_column_int64(stmt, 3);
		rec->ref = sqlite3_column_int64(stmt, 4);
		rec->ixWzskVUserlevel = sqlite3_column_int(stmt, 5);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQUsgMNUser::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQUsgMNUser** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQUsgMNUser::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQUsgMNUser& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, WzskQUsgMNUser** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQUsgMNUser::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsgMNUser& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQUsgMNUser::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQUsgMNUser::insertRec(
			WzskQUsgMNUser* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->mref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixWzskVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsgMNUser::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQUsgMNUser::insertRst(
			ListWzskQUsgMNUser& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQUsgMNUser::updateRec(
			WzskQUsgMNUser* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->mref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixWzskVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsgMNUser::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQUsgMNUser::updateRst(
			ListWzskQUsgMNUser& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsgMNUser::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsgMNUser::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQUsgMNUser::loadRecByQref(
			ubigint qref
			, WzskQUsgMNUser** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsgMNUser& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

