/**
	* \file WzskMFile.cpp
	* database access for table TblWzskMFile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "WzskMFile.h"

#include "WzskMFile_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskMFile
 ******************************************************************************/

WzskMFile::WzskMFile(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refWzskCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const uint Size
			, const string Comment
		) :
			ref(ref)
			, grp(grp)
			, own(own)
			, refWzskCFile(refWzskCFile)
			, refIxVTbl(refIxVTbl)
			, refUref(refUref)
			, osrefKContent(osrefKContent)
			, Archived(Archived)
			, Filename(Filename)
			, Archivename(Archivename)
			, srefKMimetype(srefKMimetype)
			, Size(Size)
			, Comment(Comment)
		{
};

bool WzskMFile::operator==(
			const WzskMFile& comp
		) {
	return false;
};

bool WzskMFile::operator!=(
			const WzskMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskMFile
 ******************************************************************************/

ListWzskMFile::ListWzskMFile() {
};

ListWzskMFile::ListWzskMFile(
			const ListWzskMFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskMFile(*(src.nodes[i]));
};

ListWzskMFile::~ListWzskMFile() {
	clear();
};

void ListWzskMFile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskMFile::size() const {
	return(nodes.size());
};

void ListWzskMFile::append(
			WzskMFile* rec
		) {
	nodes.push_back(rec);
};

WzskMFile* ListWzskMFile::operator[](
			const uint ix
		) {
	WzskMFile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskMFile& ListWzskMFile::operator=(
			const ListWzskMFile& src
		) {
	WzskMFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskMFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskMFile::operator==(
			const ListWzskMFile& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWzskMFile::operator!=(
			const ListWzskMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskMFile
 ******************************************************************************/

TblWzskMFile::TblWzskMFile() {
};

TblWzskMFile::~TblWzskMFile() {
};

bool TblWzskMFile::loadRecBySQL(
			const string& sqlstr
			, WzskMFile** rec
		) {
	return false;
};

ubigint TblWzskMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMFile& rst
		) {
	return 0;
};

ubigint TblWzskMFile::insertRec(
			WzskMFile* rec
		) {
	return 0;
};

ubigint TblWzskMFile::insertNewRec(
			WzskMFile** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWzskCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const uint Size
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMFile* _rec = NULL;

	_rec = new WzskMFile(0, grp, own, refWzskCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskMFile::appendNewRecToRst(
			ListWzskMFile& rst
			, WzskMFile** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWzskCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const uint Size
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMFile* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refWzskCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskMFile::insertRst(
			ListWzskMFile& rst
			, bool transact
		) {
};

void TblWzskMFile::updateRec(
			WzskMFile* rec
		) {
};

void TblWzskMFile::updateRst(
			ListWzskMFile& rst
			, bool transact
		) {
};

void TblWzskMFile::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskMFile::loadRecByRef(
			ubigint ref
			, WzskMFile** rec
		) {
	return false;
};

bool TblWzskMFile::loadFnmByRef(
			ubigint ref
			, string& Filename
		) {
	return false;
};

ubigint TblWzskMFile::loadRefsByClu(
			ubigint refWzskCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzskMFile::loadRstByClu(
			ubigint refWzskCFile
			, const bool append
			, ListWzskMFile& rst
		) {
	return 0;
};

ubigint TblWzskMFile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskMFile& rst
		) {
	ubigint numload = 0;
	WzskMFile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskMFile
 ******************************************************************************/

MyTblWzskMFile::MyTblWzskMFile() :
			TblWzskMFile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskMFile::~MyTblWzskMFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskMFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMFile (grp, own, refWzskCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskMFile SET grp = ?, own = ?, refWzskCFile = ?, refIxVTbl = ?, refUref = ?, osrefKContent = ?, Archived = ?, Filename = ?, Archivename = ?, srefKMimetype = ?, Size = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMFile WHERE ref = ?", false);
};

bool MyTblWzskMFile::loadRecBySQL(
			const string& sqlstr
			, WzskMFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskMFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMFile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMFile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskMFile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refWzskCFile = atoll((char*) dbrow[3]); else _rec->refWzskCFile = 0;
		if (dbrow[4]) _rec->refIxVTbl = atol((char*) dbrow[4]); else _rec->refIxVTbl = 0;
		if (dbrow[5]) _rec->refUref = atoll((char*) dbrow[5]); else _rec->refUref = 0;
		if (dbrow[6]) _rec->osrefKContent.assign(dbrow[6], dblengths[6]); else _rec->osrefKContent = "";
		if (dbrow[7]) _rec->Archived = atol((char*) dbrow[7]); else _rec->Archived = 0;
		if (dbrow[8]) _rec->Filename.assign(dbrow[8], dblengths[8]); else _rec->Filename = "";
		if (dbrow[9]) _rec->Archivename.assign(dbrow[9], dblengths[9]); else _rec->Archivename = "";
		if (dbrow[10]) _rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else _rec->srefKMimetype = "";
		if (dbrow[11]) _rec->Size = atol((char*) dbrow[11]); else _rec->Size = 0;
		if (dbrow[12]) _rec->Comment.assign(dbrow[12], dblengths[12]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskMFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMFile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMFile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskMFile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refWzskCFile = atoll((char*) dbrow[3]); else rec->refWzskCFile = 0;
			if (dbrow[4]) rec->refIxVTbl = atol((char*) dbrow[4]); else rec->refIxVTbl = 0;
			if (dbrow[5]) rec->refUref = atoll((char*) dbrow[5]); else rec->refUref = 0;
			if (dbrow[6]) rec->osrefKContent.assign(dbrow[6], dblengths[6]); else rec->osrefKContent = "";
			if (dbrow[7]) rec->Archived = atol((char*) dbrow[7]); else rec->Archived = 0;
			if (dbrow[8]) rec->Filename.assign(dbrow[8], dblengths[8]); else rec->Filename = "";
			if (dbrow[9]) rec->Archivename.assign(dbrow[9], dblengths[9]); else rec->Archivename = "";
			if (dbrow[10]) rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else rec->srefKMimetype = "";
			if (dbrow[11]) rec->Size = atol((char*) dbrow[11]); else rec->Size = 0;
			if (dbrow[12]) rec->Comment.assign(dbrow[12], dblengths[12]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskMFile::insertRec(
			WzskMFile* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->osrefKContent.length();
	l[7] = rec->Filename.length();
	l[8] = rec->Archivename.length();
	l[9] = rec->srefKMimetype.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzskCFile,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Archived,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Archivename.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->Size,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskMFile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskMFile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskMFile::insertRst(
			ListWzskMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskMFile::updateRec(
			WzskMFile* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->osrefKContent.length();
	l[7] = rec->Filename.length();
	l[8] = rec->Archivename.length();
	l[9] = rec->srefKMimetype.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzskCFile,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Archived,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Archivename.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->Size,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskMFile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskMFile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskMFile::updateRst(
			ListWzskMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskMFile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskMFile::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskMFile::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskMFile::loadRecByRef(
			ubigint ref
			, WzskMFile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskMFile WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskMFile::loadFnmByRef(
			ubigint ref
			, string& Filename
		) {
	return loadStringBySQL("SELECT Filename FROM TblWzskMFile WHERE ref = " + to_string(ref) + "", Filename);
};

ubigint MyTblWzskMFile::loadRefsByClu(
			ubigint refWzskCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskMFile WHERE refWzskCFile = " + to_string(refWzskCFile) + "", append, refs);
};

ubigint MyTblWzskMFile::loadRstByClu(
			ubigint refWzskCFile
			, const bool append
			, ListWzskMFile& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refWzskCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblWzskMFile WHERE refWzskCFile = " + to_string(refWzskCFile) + "", append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskMFile
 ******************************************************************************/

LiteTblWzskMFile::LiteTblWzskMFile() :
			TblWzskMFile()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadFnmByRef = NULL;
	stmtLoadRefsByClu = NULL;
	stmtLoadRstByClu = NULL;
};

LiteTblWzskMFile::~LiteTblWzskMFile() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadFnmByRef) sqlite3_finalize(stmtLoadFnmByRef);
	if (stmtLoadRefsByClu) sqlite3_finalize(stmtLoadRefsByClu);
	if (stmtLoadRstByClu) sqlite3_finalize(stmtLoadRstByClu);
};

void LiteTblWzskMFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMFile (grp, own, refWzskCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11,?12)");
	stmtUpdateRec = createStatement("UPDATE TblWzskMFile SET grp = ?1, own = ?2, refWzskCFile = ?3, refIxVTbl = ?4, refUref = ?5, osrefKContent = ?6, Archived = ?7, Filename = ?8, Archivename = ?9, srefKMimetype = ?10, Size = ?11, Comment = ?12 WHERE ref = ?13");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMFile WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, grp, own, refWzskCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblWzskMFile WHERE ref = ?1");
	stmtLoadFnmByRef = createStatement("SELECT Filename FROM TblWzskMFile WHERE ref = ?1");
	stmtLoadRefsByClu = createStatement("SELECT ref FROM TblWzskMFile WHERE refWzskCFile = ?1");
	stmtLoadRstByClu = createStatement("SELECT ref, grp, own, refWzskCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblWzskMFile WHERE refWzskCFile = ?1");
};

bool LiteTblWzskMFile::loadRec(
			sqlite3_stmt* stmt
			, WzskMFile** rec
		) {
	int res;

	WzskMFile* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskMFile();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->grp = sqlite3_column_int64(stmt, 1);
		_rec->own = sqlite3_column_int64(stmt, 2);
		_rec->refWzskCFile = sqlite3_column_int64(stmt, 3);
		_rec->refIxVTbl = sqlite3_column_int(stmt, 4);
		_rec->refUref = sqlite3_column_int64(stmt, 5);
		_rec->osrefKContent.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->Archived = sqlite3_column_int(stmt, 7);
		_rec->Filename.assign((const char*) sqlite3_column_text(stmt, 8));
		_rec->Archivename.assign((const char*) sqlite3_column_text(stmt, 9));
		_rec->srefKMimetype.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->Size = sqlite3_column_int(stmt, 11);
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 12));

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

ubigint LiteTblWzskMFile::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMFile& rst
		) {
	int res; ubigint numread = 0;

	WzskMFile* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskMFile();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->grp = sqlite3_column_int64(stmt, 1);
		rec->own = sqlite3_column_int64(stmt, 2);
		rec->refWzskCFile = sqlite3_column_int64(stmt, 3);
		rec->refIxVTbl = sqlite3_column_int(stmt, 4);
		rec->refUref = sqlite3_column_int64(stmt, 5);
		rec->osrefKContent.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->Archived = sqlite3_column_int(stmt, 7);
		rec->Filename.assign((const char*) sqlite3_column_text(stmt, 8));
		rec->Archivename.assign((const char*) sqlite3_column_text(stmt, 9));
		rec->srefKMimetype.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->Size = sqlite3_column_int(stmt, 11);
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 12));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskMFile::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskMFile** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskMFile::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMFile& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskMFile::loadRecBySQL(
			const string& sqlstr
			, WzskMFile** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMFile::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMFile& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMFile::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMFile::insertRec(
			WzskMFile* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->own);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refWzskCFile);
	sqlite3_bind_int(stmtInsertRec, 4, rec->refIxVTbl);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->refUref);
	sqlite3_bind_text(stmtInsertRec, 6, rec->osrefKContent.c_str(), rec->osrefKContent.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 7, rec->Archived);
	sqlite3_bind_text(stmtInsertRec, 8, rec->Filename.c_str(), rec->Filename.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 9, rec->Archivename.c_str(), rec->Archivename.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 10, rec->srefKMimetype.c_str(), rec->srefKMimetype.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 11, rec->Size);
	sqlite3_bind_text(stmtInsertRec, 12, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMFile::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskMFile::insertRst(
			ListWzskMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskMFile::updateRec(
			WzskMFile* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->own);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refWzskCFile);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->refIxVTbl);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->refUref);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->osrefKContent.c_str(), rec->osrefKContent.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 7, rec->Archived);
	sqlite3_bind_text(stmtUpdateRec, 8, rec->Filename.c_str(), rec->Filename.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 9, rec->Archivename.c_str(), rec->Archivename.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->srefKMimetype.c_str(), rec->srefKMimetype.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 11, rec->Size);
	sqlite3_bind_text(stmtUpdateRec, 12, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 13, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMFile::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskMFile::updateRst(
			ListWzskMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskMFile::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMFile::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskMFile::loadRecByRef(
			ubigint ref
			, WzskMFile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskMFile::loadFnmByRef(
			ubigint ref
			, string& Filename
		) {
	sqlite3_bind_int64(stmtLoadFnmByRef, 1, ref);

	return loadStringByStmt(stmtLoadFnmByRef, Filename);
};

ubigint LiteTblWzskMFile::loadRefsByClu(
			ubigint refWzskCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByClu, 1, refWzskCFile);

	return loadRefsByStmt(stmtLoadRefsByClu, append, refs);
};

ubigint LiteTblWzskMFile::loadRstByClu(
			ubigint refWzskCFile
			, const bool append
			, ListWzskMFile& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByClu, 1, refWzskCFile);

	return loadRstByStmt(stmtLoadRstByClu, append, rst);
};

#endif
