/**
	* \file WzskQUsgAAccess.cpp
	* Dbs and XML wrapper for table TblWzskQUsgAAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "WzskQUsgAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsgAAccess
 ******************************************************************************/

WzskQUsgAAccess::WzskQUsgAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWzskVFeatgroup
			, const string srefX1IxWzskVFeatgroup
			, const string titX1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
			, const string srefsIxWzskWAccess
			, const string titsIxWzskWAccess
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, x1IxWzskVFeatgroup(x1IxWzskVFeatgroup)
			, srefX1IxWzskVFeatgroup(srefX1IxWzskVFeatgroup)
			, titX1IxWzskVFeatgroup(titX1IxWzskVFeatgroup)
			, x2FeaSrefUix(x2FeaSrefUix)
			, ixWzskWAccess(ixWzskWAccess)
			, srefsIxWzskWAccess(srefsIxWzskWAccess)
			, titsIxWzskWAccess(titsIxWzskWAccess)
		{
};

void WzskQUsgAAccess::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["feg"] = srefX1IxWzskVFeatgroup;
		me["feg2"] = titX1IxWzskVFeatgroup;
		me["fea"] = x2FeaSrefUix;
		me["acc"] = srefsIxWzskWAccess;
		me["acc2"] = titsIxWzskWAccess;
	} else {
		me["srefX1IxWzskVFeatgroup"] = srefX1IxWzskVFeatgroup;
		me["titX1IxWzskVFeatgroup"] = titX1IxWzskVFeatgroup;
		me["x2FeaSrefUix"] = x2FeaSrefUix;
		me["srefsIxWzskWAccess"] = srefsIxWzskWAccess;
		me["titsIxWzskWAccess"] = titsIxWzskWAccess;
	};
};

void WzskQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQUsgAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "feg", srefX1IxWzskVFeatgroup);
		writeString(wr, "feg2", titX1IxWzskVFeatgroup);
		writeString(wr, "fea", x2FeaSrefUix);
		writeString(wr, "acc", srefsIxWzskWAccess);
		writeString(wr, "acc2", titsIxWzskWAccess);
	} else {
		writeString(wr, "srefX1IxWzskVFeatgroup", srefX1IxWzskVFeatgroup);
		writeString(wr, "titX1IxWzskVFeatgroup", titX1IxWzskVFeatgroup);
		writeString(wr, "x2FeaSrefUix", x2FeaSrefUix);
		writeString(wr, "srefsIxWzskWAccess", srefsIxWzskWAccess);
		writeString(wr, "titsIxWzskWAccess", titsIxWzskWAccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQUsgAAccess
 ******************************************************************************/

ListWzskQUsgAAccess::ListWzskQUsgAAccess() {
};

ListWzskQUsgAAccess::ListWzskQUsgAAccess(
			const ListWzskQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsgAAccess(*(src.nodes[i]));
};

ListWzskQUsgAAccess::~ListWzskQUsgAAccess() {
	clear();
};

void ListWzskQUsgAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQUsgAAccess::size() const {
	return(nodes.size());
};

void ListWzskQUsgAAccess::append(
			WzskQUsgAAccess* rec
		) {
	nodes.push_back(rec);
};

ListWzskQUsgAAccess& ListWzskQUsgAAccess::operator=(
			const ListWzskQUsgAAccess& src
		) {
	WzskQUsgAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQUsgAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQUsgAAccess::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWzskQUsgAAccess";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWzskQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQUsgAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQUsgAAccess
 ******************************************************************************/

TblWzskQUsgAAccess::TblWzskQUsgAAccess() {
};

TblWzskQUsgAAccess::~TblWzskQUsgAAccess() {
};

bool TblWzskQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, WzskQUsgAAccess** rec
		) {
	return false;
};

ubigint TblWzskQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsgAAccess& rst
		) {
	return 0;
};

ubigint TblWzskQUsgAAccess::insertRec(
			WzskQUsgAAccess* rec
		) {
	return 0;
};

ubigint TblWzskQUsgAAccess::insertNewRec(
			WzskQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWzskVFeatgroup
			, const string srefX1IxWzskVFeatgroup
			, const string titX1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
			, const string srefsIxWzskWAccess
			, const string titsIxWzskWAccess
		) {
	ubigint retval = 0;
	WzskQUsgAAccess* _rec = NULL;

	_rec = new WzskQUsgAAccess(0, jref, jnum, ref, x1IxWzskVFeatgroup, srefX1IxWzskVFeatgroup, titX1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess, srefsIxWzskWAccess, titsIxWzskWAccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQUsgAAccess::appendNewRecToRst(
			ListWzskQUsgAAccess& rst
			, WzskQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWzskVFeatgroup
			, const string srefX1IxWzskVFeatgroup
			, const string titX1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzskWAccess
			, const string srefsIxWzskWAccess
			, const string titsIxWzskWAccess
		) {
	ubigint retval = 0;
	WzskQUsgAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxWzskVFeatgroup, srefX1IxWzskVFeatgroup, titX1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess, srefsIxWzskWAccess, titsIxWzskWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQUsgAAccess::insertRst(
			ListWzskQUsgAAccess& rst
		) {
};

void TblWzskQUsgAAccess::updateRec(
			WzskQUsgAAccess* rec
		) {
};

void TblWzskQUsgAAccess::updateRst(
			ListWzskQUsgAAccess& rst
		) {
};

void TblWzskQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQUsgAAccess::loadRecByQref(
			ubigint qref
			, WzskQUsgAAccess** rec
		) {
	return false;
};

ubigint TblWzskQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsgAAccess& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQUsgAAccess
 ******************************************************************************/

MyTblWzskQUsgAAccess::MyTblWzskQUsgAAccess() :
			TblWzskQUsgAAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQUsgAAccess::~MyTblWzskQUsgAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQUsgAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQUsgAAccess (jref, jnum, ref, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQUsgAAccess SET jref = ?, jnum = ?, ref = ?, x1IxWzskVFeatgroup = ?, x2FeaSrefUix = ?, ixWzskWAccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQUsgAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQUsgAAccess WHERE jref = ?", false);
};

bool MyTblWzskQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, WzskQUsgAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQUsgAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQUsgAAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQUsgAAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskQUsgAAccess();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxWzskVFeatgroup = atol((char*) dbrow[4]); else _rec->x1IxWzskVFeatgroup = 0;
		if (dbrow[5]) _rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else _rec->x2FeaSrefUix = "";
		if (dbrow[6]) _rec->ixWzskWAccess = atol((char*) dbrow[6]); else _rec->ixWzskWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsgAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQUsgAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQUsgAAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQUsgAAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskQUsgAAccess();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxWzskVFeatgroup = atol((char*) dbrow[4]); else rec->x1IxWzskVFeatgroup = 0;
			if (dbrow[5]) rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else rec->x2FeaSrefUix = "";
			if (dbrow[6]) rec->ixWzskWAccess = atol((char*) dbrow[6]); else rec->ixWzskWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQUsgAAccess::insertRec(
			WzskQUsgAAccess* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxWzskVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWzskWAccess,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQUsgAAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQUsgAAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQUsgAAccess::insertRst(
			ListWzskQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQUsgAAccess::updateRec(
			WzskQUsgAAccess* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxWzskVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWzskWAccess,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQUsgAAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQUsgAAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQUsgAAccess::updateRst(
			ListWzskQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQUsgAAccess::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQUsgAAccess::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQUsgAAccess::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQUsgAAccess::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQUsgAAccess::loadRecByQref(
			ubigint qref
			, WzskQUsgAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQUsgAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsgAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQUsgAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQUsgAAccess
 ******************************************************************************/

LiteTblWzskQUsgAAccess::LiteTblWzskQUsgAAccess() :
			TblWzskQUsgAAccess()
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

LiteTblWzskQUsgAAccess::~LiteTblWzskQUsgAAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQUsgAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQUsgAAccess (jref, jnum, ref, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess) VALUES (?1,?2,?3,?4,?5,?6)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQUsgAAccess SET jref = ?1, jnum = ?2, ref = ?3, x1IxWzskVFeatgroup = ?4, x2FeaSrefUix = ?5, ixWzskWAccess = ?6 WHERE qref = ?7");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQUsgAAccess WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQUsgAAccess WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess FROM TblWzskQUsgAAccess WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, x1IxWzskVFeatgroup, x2FeaSrefUix, ixWzskWAccess FROM TblWzskQUsgAAccess WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQUsgAAccess::loadRec(
			sqlite3_stmt* stmt
			, WzskQUsgAAccess** rec
		) {
	int res;

	WzskQUsgAAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQUsgAAccess();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->x1IxWzskVFeatgroup = sqlite3_column_int(stmt, 4);
		_rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->ixWzskWAccess = sqlite3_column_int(stmt, 6);

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

ubigint LiteTblWzskQUsgAAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQUsgAAccess& rst
		) {
	int res; ubigint numread = 0;

	WzskQUsgAAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQUsgAAccess();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->x1IxWzskVFeatgroup = sqlite3_column_int(stmt, 4);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->ixWzskWAccess = sqlite3_column_int(stmt, 6);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQUsgAAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQUsgAAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQUsgAAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQUsgAAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, WzskQUsgAAccess** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQUsgAAccess::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsgAAccess& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQUsgAAccess::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQUsgAAccess::insertRec(
			WzskQUsgAAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->x1IxWzskVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 5, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 6, rec->ixWzskWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsgAAccess::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQUsgAAccess::insertRst(
			ListWzskQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQUsgAAccess::updateRec(
			WzskQUsgAAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->x1IxWzskVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->ixWzskWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsgAAccess::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQUsgAAccess::updateRst(
			ListWzskQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsgAAccess::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsgAAccess::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQUsgAAccess::loadRecByQref(
			ubigint qref
			, WzskQUsgAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsgAAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif
