/**
	* \file WzskQFilList.cpp
	* Dbs and XML wrapper for table TblWzskQFilList (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "WzskQFilList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQFilList
 ******************************************************************************/

WzskQFilList::WzskQFilList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const usmallint Size
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->Filename = Filename;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->osrefKContent = osrefKContent;
	this->titOsrefKContent = titOsrefKContent;
	this->srefKMimetype = srefKMimetype;
	this->titSrefKMimetype = titSrefKMimetype;
	this->Size = Size;
};

void WzskQFilList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzskQFilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "fnm", Filename);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "cnt", osrefKContent);
		writeString(wr, "cnt2", titOsrefKContent);
		writeString(wr, "mim", srefKMimetype);
		writeString(wr, "mim2", titSrefKMimetype);
		writeUint(wr, "siz", Size);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "Filename", Filename);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "osrefKContent", osrefKContent);
		writeString(wr, "titOsrefKContent", titOsrefKContent);
		writeString(wr, "srefKMimetype", srefKMimetype);
		writeString(wr, "titSrefKMimetype", titSrefKMimetype);
		writeUint(wr, "Size", Size);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzskQFilList
 ******************************************************************************/

ListWzskQFilList::ListWzskQFilList() {
};

ListWzskQFilList::ListWzskQFilList(
			const ListWzskQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQFilList(*(src.nodes[i]));
};

ListWzskQFilList::~ListWzskQFilList() {
	clear();
};

void ListWzskQFilList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskQFilList::size() const {
	return(nodes.size());
};

void ListWzskQFilList::append(
			WzskQFilList* rec
		) {
	nodes.push_back(rec);
};

ListWzskQFilList& ListWzskQFilList::operator=(
			const ListWzskQFilList& src
		) {
	WzskQFilList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskQFilList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzskQFilList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzskQFilList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzskQFilList
 ******************************************************************************/

TblWzskQFilList::TblWzskQFilList() {
};

TblWzskQFilList::~TblWzskQFilList() {
};

bool TblWzskQFilList::loadRecBySQL(
			const string& sqlstr
			, WzskQFilList** rec
		) {
	return false;
};

ubigint TblWzskQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQFilList& rst
		) {
	return 0;
};

ubigint TblWzskQFilList::insertRec(
			WzskQFilList* rec
		) {
	return 0;
};

ubigint TblWzskQFilList::insertNewRec(
			WzskQFilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const usmallint Size
		) {
	ubigint retval = 0;
	WzskQFilList* _rec = NULL;

	_rec = new WzskQFilList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, Filename, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, osrefKContent, titOsrefKContent, srefKMimetype, titSrefKMimetype, Size);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskQFilList::appendNewRecToRst(
			ListWzskQFilList& rst
			, WzskQFilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const usmallint Size
		) {
	ubigint retval = 0;
	WzskQFilList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, Filename, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, osrefKContent, titOsrefKContent, srefKMimetype, titSrefKMimetype, Size);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskQFilList::insertRst(
			ListWzskQFilList& rst
		) {
};

void TblWzskQFilList::updateRec(
			WzskQFilList* rec
		) {
};

void TblWzskQFilList::updateRst(
			ListWzskQFilList& rst
		) {
};

void TblWzskQFilList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzskQFilList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzskQFilList::loadRecByQref(
			ubigint qref
			, WzskQFilList** rec
		) {
	return false;
};

ubigint TblWzskQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQFilList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskQFilList
 ******************************************************************************/

MyTblWzskQFilList::MyTblWzskQFilList() :
			TblWzskQFilList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzskQFilList::~MyTblWzskQFilList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzskQFilList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQFilList (jref, jnum, ref, grp, own, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskQFilList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, Filename = ?, refIxVTbl = ?, refUref = ?, osrefKContent = ?, srefKMimetype = ?, Size = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQFilList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQFilList WHERE jref = ?", false);
};

bool MyTblWzskQFilList::loadRecBySQL(
			const string& sqlstr
			, WzskQFilList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskQFilList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQFilList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQFilList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskQFilList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->Filename.assign(dbrow[6], dblengths[6]); else _rec->Filename = "";
		if (dbrow[7]) _rec->refIxVTbl = atol((char*) dbrow[7]); else _rec->refIxVTbl = 0;
		if (dbrow[8]) _rec->refUref = atoll((char*) dbrow[8]); else _rec->refUref = 0;
		if (dbrow[9]) _rec->osrefKContent.assign(dbrow[9], dblengths[9]); else _rec->osrefKContent = "";
		if (dbrow[10]) _rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else _rec->srefKMimetype = "";
		if (dbrow[11]) _rec->Size = atoi((char*) dbrow[11]); else _rec->Size = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQFilList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskQFilList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskQFilList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskQFilList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskQFilList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->Filename.assign(dbrow[6], dblengths[6]); else rec->Filename = "";
			if (dbrow[7]) rec->refIxVTbl = atol((char*) dbrow[7]); else rec->refIxVTbl = 0;
			if (dbrow[8]) rec->refUref = atoll((char*) dbrow[8]); else rec->refUref = 0;
			if (dbrow[9]) rec->osrefKContent.assign(dbrow[9], dblengths[9]); else rec->osrefKContent = "";
			if (dbrow[10]) rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else rec->srefKMimetype = "";
			if (dbrow[11]) rec->Size = atoi((char*) dbrow[11]); else rec->Size = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskQFilList::insertRec(
			WzskQFilList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->Filename.length();
	l[8] = rec->osrefKContent.length();
	l[9] = rec->srefKMimetype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUsmallint(&rec->Size,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskQFilList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskQFilList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzskQFilList::insertRst(
			ListWzskQFilList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzskQFilList::updateRec(
			WzskQFilList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->Filename.length();
	l[8] = rec->osrefKContent.length();
	l[9] = rec->srefKMimetype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUsmallint(&rec->Size,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskQFilList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskQFilList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQFilList::updateRst(
			ListWzskQFilList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskQFilList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzskQFilList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzskQFilList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskQFilList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzskQFilList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzskQFilList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskQFilList::loadRecByQref(
			ubigint qref
			, WzskQFilList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskQFilList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzskQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQFilList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzskQFilList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskQFilList
 ******************************************************************************/

LiteTblWzskQFilList::LiteTblWzskQFilList() :
			TblWzskQFilList()
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

LiteTblWzskQFilList::~LiteTblWzskQFilList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzskQFilList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskQFilList (jref, jnum, ref, grp, own, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblWzskQFilList SET jref = ?1, jnum = ?2, ref = ?3, grp = ?4, own = ?5, Filename = ?6, refIxVTbl = ?7, refUref = ?8, osrefKContent = ?9, srefKMimetype = ?10, Size = ?11 WHERE qref = ?12");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzskQFilList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzskQFilList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, grp, own, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size FROM TblWzskQFilList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, grp, own, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size FROM TblWzskQFilList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzskQFilList::loadRec(
			sqlite3_stmt* stmt
			, WzskQFilList** rec
		) {
	int res;

	WzskQFilList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskQFilList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->grp = sqlite3_column_int64(stmt, 4);
		_rec->own = sqlite3_column_int64(stmt, 5);
		_rec->Filename.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->refIxVTbl = sqlite3_column_int(stmt, 7);
		_rec->refUref = sqlite3_column_int64(stmt, 8);
		_rec->osrefKContent.assign((const char*) sqlite3_column_text(stmt, 9));
		_rec->srefKMimetype.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->Size = sqlite3_column_int(stmt, 11);

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

ubigint LiteTblWzskQFilList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQFilList& rst
		) {
	int res; ubigint numread = 0;

	WzskQFilList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskQFilList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->grp = sqlite3_column_int64(stmt, 4);
		rec->own = sqlite3_column_int64(stmt, 5);
		rec->Filename.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->refIxVTbl = sqlite3_column_int(stmt, 7);
		rec->refUref = sqlite3_column_int64(stmt, 8);
		rec->osrefKContent.assign((const char*) sqlite3_column_text(stmt, 9));
		rec->srefKMimetype.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->Size = sqlite3_column_int(stmt, 11);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskQFilList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskQFilList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskQFilList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskQFilList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskQFilList::loadRecBySQL(
			const string& sqlstr
			, WzskQFilList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQFilList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskQFilList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskQFilList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskQFilList::insertRec(
			WzskQFilList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->own);
	sqlite3_bind_text(stmtInsertRec, 6, rec->Filename.c_str(), rec->Filename.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 7, rec->refIxVTbl);
	sqlite3_bind_int64(stmtInsertRec, 8, rec->refUref);
	sqlite3_bind_text(stmtInsertRec, 9, rec->osrefKContent.c_str(), rec->osrefKContent.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 10, rec->srefKMimetype.c_str(), rec->srefKMimetype.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 11, rec->Size);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQFilList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzskQFilList::insertRst(
			ListWzskQFilList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskQFilList::updateRec(
			WzskQFilList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->own);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->Filename.c_str(), rec->Filename.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 7, rec->refIxVTbl);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->refUref);
	sqlite3_bind_text(stmtUpdateRec, 9, rec->osrefKContent.c_str(), rec->osrefKContent.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->srefKMimetype.c_str(), rec->srefKMimetype.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 11, rec->Size);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQFilList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskQFilList::updateRst(
			ListWzskQFilList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskQFilList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQFilList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzskQFilList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzskQFilList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzskQFilList::loadRecByQref(
			ubigint qref
			, WzskQFilList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzskQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzskQFilList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

