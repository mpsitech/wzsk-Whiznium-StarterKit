/**
	* \file WzskQUsrList.cpp
	* Dbs and XML wrapper for table TblWzskQUsrList (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "WzskQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsrList
 ******************************************************************************/

WzskQUsrList::WzskQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWzskMPerson
			, const string stubRefWzskMPerson
			, const string sref
			, const ubigint refWzskMUsergroup
			, const string stubRefWzskMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWzskVLocale
			, const string srefIxWzskVLocale
			, const string titIxWzskVLocale
			, const uint ixWzskVUserlevel
			, const string srefIxWzskVUserlevel
			, const string titIxWzskVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->refWzskMPerson = refWzskMPerson;
	this->stubRefWzskMPerson = stubRefWzskMPerson;
	this->sref = sref;
	this->refWzskMUsergroup = refWzskMUsergroup;
	this->stubRefWzskMUsergroup = stubRefWzskMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixWzskVLocale = ixWzskVLocale;
	this->srefIxWzskVLocale = srefIxWzskVLocale;
	this->titIxWzskVLocale = titIxWzskVLocale;
	this->ixWzskVUserlevel = ixWzskVUserlevel;
	this->srefIxWzskVUserlevel = srefIxWzskVUserlevel;
	this->titIxWzskVUserlevel = titIxWzskVUserlevel;
};

void WzskQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "prs", stubRefWzskMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefWzskMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxWzskVLocale);
		writeString(wr, "lcl2", titIxWzskVLocale);
		writeString(wr, "ulv", srefIxWzskVUserlevel);
		writeString(wr, "ulv2", titIxWzskVUserlevel);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubRefWzskMPerson", stubRefWzskMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWzskMUsergroup", stubRefWzskMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxWzskVLocale", srefIxWzskVLocale);
		writeString(wr, "titIxWzskVLocale", titIxWzskVLocale);
		writeString(wr, "srefIxWzskVUserlevel", srefIxWzskVUserlevel);
		writeString(wr, "titIxWzskVUserlevel", titIxWzskVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQUsrList
 ******************************************************************************/

ListWzskQUsrList::ListWzskQUsrList() {
};

ListWzskQUsrList::ListWzskQUsrList(
			const ListWzskQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsrList(*(src.nodes[i]));
};

ListWzskQUsrList::~ListWzskQUsrList() {
	clear();
};

void ListWzskQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQUsrList::size() const {
	return(nodes.size());
};

void ListWzskQUsrList::append(
			WzskQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListWzskQUsrList& ListWzskQUsrList::operator=(
			const ListWzskQUsrList& src
		) {
	WzskQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQUsrList
 ******************************************************************************/

TblWzskQUsrList::TblWzskQUsrList() {
};

TblWzskQUsrList::~TblWzskQUsrList() {
};

bool TblWzskQUsrList::loadRecBySQL(
			const string& sqlstr
			, WzskQUsrList** rec
		) {
	return false;
};

ubigint TblWzskQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsrList& rst
		) {
	return 0;
};

ubigint TblWzskQUsrList::insertRec(
			WzskQUsrList* rec
		) {
	return 0;
};

ubigint TblWzskQUsrList::insertNewRec(
			WzskQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWzskMPerson
			, const string stubRefWzskMPerson
			, const string sref
			, const ubigint refWzskMUsergroup
			, const string stubRefWzskMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWzskVLocale
			, const string srefIxWzskVLocale
			, const string titIxWzskVLocale
			, const uint ixWzskVUserlevel
			, const string srefIxWzskVUserlevel
			, const string titIxWzskVUserlevel
		) {
	ubigint retval = 0;
	WzskQUsrList* _rec = NULL;

	_rec = new WzskQUsrList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWzskMPerson, stubRefWzskMPerson, sref, refWzskMUsergroup, stubRefWzskMUsergroup, ixVState, srefIxVState, titIxVState, ixWzskVLocale, srefIxWzskVLocale, titIxWzskVLocale, ixWzskVUserlevel, srefIxWzskVUserlevel, titIxWzskVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQUsrList::appendNewRecToRst(
			ListWzskQUsrList& rst
			, WzskQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWzskMPerson
			, const string stubRefWzskMPerson
			, const string sref
			, const ubigint refWzskMUsergroup
			, const string stubRefWzskMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWzskVLocale
			, const string srefIxWzskVLocale
			, const string titIxWzskVLocale
			, const uint ixWzskVUserlevel
			, const string srefIxWzskVUserlevel
			, const string titIxWzskVUserlevel
		) {
	ubigint retval = 0;
	WzskQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWzskMPerson, stubRefWzskMPerson, sref, refWzskMUsergroup, stubRefWzskMUsergroup, ixVState, srefIxVState, titIxVState, ixWzskVLocale, srefIxWzskVLocale, titIxWzskVLocale, ixWzskVUserlevel, srefIxWzskVUserlevel, titIxWzskVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQUsrList::insertRst(
			ListWzskQUsrList& rst
		) {
};

void TblWzskQUsrList::updateRec(
			WzskQUsrList* rec
		) {
};

void TblWzskQUsrList::updateRst(
			ListWzskQUsrList& rst
		) {
};

void TblWzskQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQUsrList::loadRecByQref(
			ubigint qref
			, WzskQUsrList** rec
		) {
	return false;
};

ubigint TblWzskQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsrList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQUsrList
 ******************************************************************************/

MyTblWzskQUsrList::MyTblWzskQUsrList() :
			TblWzskQUsrList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQUsrList::~MyTblWzskQUsrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQUsrList (jref, jnum, ref, grp, own, refWzskMPerson, sref, refWzskMUsergroup, ixVState, ixWzskVLocale, ixWzskVUserlevel) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQUsrList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, refWzskMPerson = ?, sref = ?, refWzskMUsergroup = ?, ixVState = ?, ixWzskVLocale = ?, ixWzskVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQUsrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQUsrList WHERE jref = ?", false);
};

bool MyTblWzskQUsrList::loadRecBySQL(
			const string& sqlstr
			, WzskQUsrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQUsrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQUsrList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQUsrList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskQUsrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->refWzskMPerson = atoll((char*) dbrow[6]); else _rec->refWzskMPerson = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->refWzskMUsergroup = atoll((char*) dbrow[8]); else _rec->refWzskMUsergroup = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;
		if (dbrow[10]) _rec->ixWzskVLocale = atol((char*) dbrow[10]); else _rec->ixWzskVLocale = 0;
		if (dbrow[11]) _rec->ixWzskVUserlevel = atol((char*) dbrow[11]); else _rec->ixWzskVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQUsrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQUsrList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQUsrList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskQUsrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->refWzskMPerson = atoll((char*) dbrow[6]); else rec->refWzskMPerson = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->refWzskMUsergroup = atoll((char*) dbrow[8]); else rec->refWzskMUsergroup = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			if (dbrow[10]) rec->ixWzskVLocale = atol((char*) dbrow[10]); else rec->ixWzskVLocale = 0;
			if (dbrow[11]) rec->ixWzskVUserlevel = atol((char*) dbrow[11]); else rec->ixWzskVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQUsrList::insertRec(
			WzskQUsrList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWzskMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWzskMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWzskVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWzskVUserlevel,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQUsrList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQUsrList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQUsrList::insertRst(
			ListWzskQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQUsrList::updateRec(
			WzskQUsrList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWzskMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWzskMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWzskVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWzskVUserlevel,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQUsrList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQUsrList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQUsrList::updateRst(
			ListWzskQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQUsrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQUsrList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQUsrList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQUsrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQUsrList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQUsrList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQUsrList::loadRecByQref(
			ubigint qref
			, WzskQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQUsrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQUsrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQUsrList
 ******************************************************************************/

LiteTblWzskQUsrList::LiteTblWzskQUsrList() :
			TblWzskQUsrList()
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

LiteTblWzskQUsrList::~LiteTblWzskQUsrList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQUsrList (jref, jnum, ref, grp, own, refWzskMPerson, sref, refWzskMUsergroup, ixVState, ixWzskVLocale, ixWzskVUserlevel) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQUsrList SET jref = ?1, jnum = ?2, ref = ?3, grp = ?4, own = ?5, refWzskMPerson = ?6, sref = ?7, refWzskMUsergroup = ?8, ixVState = ?9, ixWzskVLocale = ?10, ixWzskVUserlevel = ?11 WHERE qref = ?12");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQUsrList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQUsrList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, grp, own, refWzskMPerson, sref, refWzskMUsergroup, ixVState, ixWzskVLocale, ixWzskVUserlevel FROM TblWzskQUsrList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, grp, own, refWzskMPerson, sref, refWzskMUsergroup, ixVState, ixWzskVLocale, ixWzskVUserlevel FROM TblWzskQUsrList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQUsrList::loadRec(
			sqlite3_stmt* stmt
			, WzskQUsrList** rec
		) {
	int res;

	WzskQUsrList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQUsrList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->grp = sqlite3_column_int64(stmt, 4);
		_rec->own = sqlite3_column_int64(stmt, 5);
		_rec->refWzskMPerson = sqlite3_column_int64(stmt, 6);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 7));
		_rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 8);
		_rec->ixVState = sqlite3_column_int(stmt, 9);
		_rec->ixWzskVLocale = sqlite3_column_int(stmt, 10);
		_rec->ixWzskVUserlevel = sqlite3_column_int(stmt, 11);

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

ubigint LiteTblWzskQUsrList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQUsrList& rst
		) {
	int res; ubigint numread = 0;

	WzskQUsrList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQUsrList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->grp = sqlite3_column_int64(stmt, 4);
		rec->own = sqlite3_column_int64(stmt, 5);
		rec->refWzskMPerson = sqlite3_column_int64(stmt, 6);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 7));
		rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 8);
		rec->ixVState = sqlite3_column_int(stmt, 9);
		rec->ixWzskVLocale = sqlite3_column_int(stmt, 10);
		rec->ixWzskVUserlevel = sqlite3_column_int(stmt, 11);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQUsrList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQUsrList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQUsrList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQUsrList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQUsrList::loadRecBySQL(
			const string& sqlstr
			, WzskQUsrList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQUsrList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQUsrList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQUsrList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQUsrList::insertRec(
			WzskQUsrList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->own);
	sqlite3_bind_int64(stmtInsertRec, 6, rec->refWzskMPerson);
	sqlite3_bind_text(stmtInsertRec, 7, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 8, rec->refWzskMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 9, rec->ixVState);
	sqlite3_bind_int(stmtInsertRec, 10, rec->ixWzskVLocale);
	sqlite3_bind_int(stmtInsertRec, 11, rec->ixWzskVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsrList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQUsrList::insertRst(
			ListWzskQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQUsrList::updateRec(
			WzskQUsrList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->own);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->refWzskMPerson);
	sqlite3_bind_text(stmtUpdateRec, 7, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->refWzskMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->ixVState);
	sqlite3_bind_int(stmtUpdateRec, 10, rec->ixWzskVLocale);
	sqlite3_bind_int(stmtUpdateRec, 11, rec->ixWzskVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsrList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQUsrList::updateRst(
			ListWzskQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQUsrList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsrList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQUsrList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQUsrList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQUsrList::loadRecByQref(
			ubigint qref
			, WzskQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQUsrList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

