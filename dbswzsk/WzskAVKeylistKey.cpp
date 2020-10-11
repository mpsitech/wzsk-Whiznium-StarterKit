/**
	* \file WzskAVKeylistKey.cpp
	* database access for table TblWzskAVKeylistKey (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "WzskAVKeylistKey.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskAVKeylistKey
 ******************************************************************************/

WzskAVKeylistKey::WzskAVKeylistKey(
			const ubigint ref
			, const uint klsIxWzskVKeylist
			, const uint klsNum
			, const uint x1IxWzskVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->klsIxWzskVKeylist = klsIxWzskVKeylist;
	this->klsNum = klsNum;
	this->x1IxWzskVMaintable = x1IxWzskVMaintable;
	this->x1Uref = x1Uref;
	this->Fixed = Fixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool WzskAVKeylistKey::operator==(
			const WzskAVKeylistKey& comp
		) {
	return false;
};

bool WzskAVKeylistKey::operator!=(
			const WzskAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskAVKeylistKey
 ******************************************************************************/

ListWzskAVKeylistKey::ListWzskAVKeylistKey() {
};

ListWzskAVKeylistKey::ListWzskAVKeylistKey(
			const ListWzskAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskAVKeylistKey(*(src.nodes[i]));
};

ListWzskAVKeylistKey::~ListWzskAVKeylistKey() {
	clear();
};

void ListWzskAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskAVKeylistKey::size() const {
	return(nodes.size());
};

void ListWzskAVKeylistKey::append(
			WzskAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

WzskAVKeylistKey* ListWzskAVKeylistKey::operator[](
			const uint ix
		) {
	WzskAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskAVKeylistKey& ListWzskAVKeylistKey::operator=(
			const ListWzskAVKeylistKey& src
		) {
	WzskAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskAVKeylistKey::operator==(
			const ListWzskAVKeylistKey& comp
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

bool ListWzskAVKeylistKey::operator!=(
			const ListWzskAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskAVKeylistKey
 ******************************************************************************/

TblWzskAVKeylistKey::TblWzskAVKeylistKey() {
};

TblWzskAVKeylistKey::~TblWzskAVKeylistKey() {
};

bool TblWzskAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzskAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWzskAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWzskAVKeylistKey::insertRec(
			WzskAVKeylistKey* rec
		) {
	return 0;
};

ubigint TblWzskAVKeylistKey::insertNewRec(
			WzskAVKeylistKey** rec
			, const uint klsIxWzskVKeylist
			, const uint klsNum
			, const uint x1IxWzskVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzskAVKeylistKey* _rec = NULL;

	_rec = new WzskAVKeylistKey(0, klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskAVKeylistKey::appendNewRecToRst(
			ListWzskAVKeylistKey& rst
			, WzskAVKeylistKey** rec
			, const uint klsIxWzskVKeylist
			, const uint klsNum
			, const uint x1IxWzskVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzskAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskAVKeylistKey::insertRst(
			ListWzskAVKeylistKey& rst
			, bool transact
		) {
};

void TblWzskAVKeylistKey::updateRec(
			WzskAVKeylistKey* rec
		) {
};

void TblWzskAVKeylistKey::updateRst(
			ListWzskAVKeylistKey& rst
			, bool transact
		) {
};

void TblWzskAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzskAVKeylistKey** rec
		) {
	return false;
};

bool TblWzskAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWzskVKeylist
			, uint x1IxWzskVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWzskAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWzskVKeylist
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWzskAVKeylistKey::loadRstByKls(
			uint klsIxWzskVKeylist
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWzskAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWzskVKeylist
			, uint x1IxWzskVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	return 0;
};

bool TblWzskAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWzskAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	ubigint numload = 0;
	WzskAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskAVKeylistKey
 ******************************************************************************/

MyTblWzskAVKeylistKey::MyTblWzskAVKeylistKey() :
			TblWzskAVKeylistKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskAVKeylistKey::~MyTblWzskAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAVKeylistKey (klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskAVKeylistKey SET klsIxWzskVKeylist = ?, klsNum = ?, x1IxWzskVMaintable = ?, x1Uref = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAVKeylistKey WHERE ref = ?", false);
};

bool MyTblWzskAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzskAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAVKeylistKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAVKeylistKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->klsIxWzskVKeylist = atol((char*) dbrow[1]); else _rec->klsIxWzskVKeylist = 0;
		if (dbrow[2]) _rec->klsNum = atol((char*) dbrow[2]); else _rec->klsNum = 0;
		if (dbrow[3]) _rec->x1IxWzskVMaintable = atol((char*) dbrow[3]); else _rec->x1IxWzskVMaintable = 0;
		if (dbrow[4]) _rec->x1Uref = atoll((char*) dbrow[4]); else _rec->x1Uref = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskAVKeylistKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskAVKeylistKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->klsIxWzskVKeylist = atol((char*) dbrow[1]); else rec->klsIxWzskVKeylist = 0;
			if (dbrow[2]) rec->klsNum = atol((char*) dbrow[2]); else rec->klsNum = 0;
			if (dbrow[3]) rec->x1IxWzskVMaintable = atol((char*) dbrow[3]); else rec->x1IxWzskVMaintable = 0;
			if (dbrow[4]) rec->x1Uref = atoll((char*) dbrow[4]); else rec->x1Uref = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskAVKeylistKey::insertRec(
			WzskAVKeylistKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxWzskVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWzskVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskAVKeylistKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskAVKeylistKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskAVKeylistKey::insertRst(
			ListWzskAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskAVKeylistKey::updateRec(
			WzskAVKeylistKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxWzskVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWzskVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskAVKeylistKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskAVKeylistKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskAVKeylistKey::updateRst(
			ListWzskAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskAVKeylistKey::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskAVKeylistKey::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzskAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWzskVKeylist
			, uint x1IxWzskVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzskAVKeylistKey WHERE klsIxWzskVKeylist = " + to_string(klsIxWzskVKeylist) + " AND x1IxWzskVMaintable = " + to_string(x1IxWzskVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " AND sref = '" + sref + "'", ref);
};

bool MyTblWzskAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWzskVKeylist
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzskAVKeylistKey WHERE klsIxWzskVKeylist = " + to_string(klsIxWzskVKeylist) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWzskAVKeylistKey::loadRstByKls(
			uint klsIxWzskVKeylist
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzskAVKeylistKey WHERE klsIxWzskVKeylist = " + to_string(klsIxWzskVKeylist) + " ORDER BY klsNum ASC", append, rst);
};

ubigint MyTblWzskAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWzskVKeylist
			, uint x1IxWzskVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzskAVKeylistKey WHERE klsIxWzskVKeylist = " + to_string(klsIxWzskVKeylist) + " AND x1IxWzskVMaintable = " + to_string(x1IxWzskVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " ORDER BY klsNum ASC", append, rst);
};

bool MyTblWzskAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWzskAVKeylistKey WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskAVKeylistKey
 ******************************************************************************/

LiteTblWzskAVKeylistKey::LiteTblWzskAVKeylistKey() :
			TblWzskAVKeylistKey()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefByKlsMtbUrfSrf = NULL;
	stmtLoadRefByKlsSrf = NULL;
	stmtLoadRstByKls = NULL;
	stmtLoadRstByKlsMtbUrf = NULL;
	stmtLoadTitByRef = NULL;
};

LiteTblWzskAVKeylistKey::~LiteTblWzskAVKeylistKey() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefByKlsMtbUrfSrf) sqlite3_finalize(stmtLoadRefByKlsMtbUrfSrf);
	if (stmtLoadRefByKlsSrf) sqlite3_finalize(stmtLoadRefByKlsSrf);
	if (stmtLoadRstByKls) sqlite3_finalize(stmtLoadRstByKls);
	if (stmtLoadRstByKlsMtbUrf) sqlite3_finalize(stmtLoadRstByKlsMtbUrf);
	if (stmtLoadTitByRef) sqlite3_finalize(stmtLoadTitByRef);
};

void LiteTblWzskAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskAVKeylistKey (klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblWzskAVKeylistKey SET klsIxWzskVKeylist = ?1, klsNum = ?2, x1IxWzskVMaintable = ?3, x1Uref = ?4, Fixed = ?5, sref = ?6, Avail = ?7, Implied = ?8, refJ = ?9, Title = ?10, Comment = ?11 WHERE ref = ?12");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskAVKeylistKey WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzskAVKeylistKey WHERE ref = ?1");
	stmtLoadRefByKlsMtbUrfSrf = createStatement("SELECT ref FROM TblWzskAVKeylistKey WHERE klsIxWzskVKeylist = ?1 AND x1IxWzskVMaintable = ?2 AND x1Uref = ?3 AND sref = ?4");
	stmtLoadRefByKlsSrf = createStatement("SELECT ref FROM TblWzskAVKeylistKey WHERE klsIxWzskVKeylist = ?1 AND sref = ?2");
	stmtLoadRstByKls = createStatement("SELECT ref, klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzskAVKeylistKey WHERE klsIxWzskVKeylist = ?1 ORDER BY klsNum ASC");
	stmtLoadRstByKlsMtbUrf = createStatement("SELECT ref, klsIxWzskVKeylist, klsNum, x1IxWzskVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzskAVKeylistKey WHERE klsIxWzskVKeylist = ?1 AND x1IxWzskVMaintable = ?2 AND x1Uref = ?3 ORDER BY klsNum ASC");
	stmtLoadTitByRef = createStatement("SELECT Title FROM TblWzskAVKeylistKey WHERE ref = ?1");
};

bool LiteTblWzskAVKeylistKey::loadRec(
			sqlite3_stmt* stmt
			, WzskAVKeylistKey** rec
		) {
	int res;

	WzskAVKeylistKey* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskAVKeylistKey();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->klsIxWzskVKeylist = sqlite3_column_int(stmt, 1);
		_rec->klsNum = sqlite3_column_int(stmt, 2);
		_rec->x1IxWzskVMaintable = sqlite3_column_int(stmt, 3);
		_rec->x1Uref = sqlite3_column_int64(stmt, 4);
		_rec->Fixed = (sqlite3_column_int(stmt, 5) != 0);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->Avail.assign((const char*) sqlite3_column_text(stmt, 7));
		_rec->Implied.assign((const char*) sqlite3_column_text(stmt, 8));
		_rec->refJ = sqlite3_column_int64(stmt, 9);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 11));

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

ubigint LiteTblWzskAVKeylistKey::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	int res; ubigint numread = 0;

	WzskAVKeylistKey* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskAVKeylistKey();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->klsIxWzskVKeylist = sqlite3_column_int(stmt, 1);
		rec->klsNum = sqlite3_column_int(stmt, 2);
		rec->x1IxWzskVMaintable = sqlite3_column_int(stmt, 3);
		rec->x1Uref = sqlite3_column_int64(stmt, 4);
		rec->Fixed = (sqlite3_column_int(stmt, 5) != 0);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->Avail.assign((const char*) sqlite3_column_text(stmt, 7));
		rec->Implied.assign((const char*) sqlite3_column_text(stmt, 8));
		rec->refJ = sqlite3_column_int64(stmt, 9);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 11));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskAVKeylistKey::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskAVKeylistKey** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskAVKeylistKey::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzskAVKeylistKey** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAVKeylistKey::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskAVKeylistKey::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskAVKeylistKey::insertRec(
			WzskAVKeylistKey* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->klsIxWzskVKeylist);
	sqlite3_bind_int(stmtInsertRec, 2, rec->klsNum);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x1IxWzskVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->x1Uref);
	sqlite3_bind_int(stmtInsertRec, 5, rec->Fixed);
	sqlite3_bind_text(stmtInsertRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 7, rec->Avail.c_str(), rec->Avail.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 8, rec->Implied.c_str(), rec->Implied.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 9, rec->refJ);
	sqlite3_bind_text(stmtInsertRec, 10, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 11, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVKeylistKey::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskAVKeylistKey::insertRst(
			ListWzskAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskAVKeylistKey::updateRec(
			WzskAVKeylistKey* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->klsIxWzskVKeylist);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->klsNum);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x1IxWzskVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->x1Uref);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->Fixed);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 7, rec->Avail.c_str(), rec->Avail.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 8, rec->Implied.c_str(), rec->Implied.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->refJ);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVKeylistKey::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskAVKeylistKey::updateRst(
			ListWzskAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskAVKeylistKey::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzskAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWzskVKeylist
			, uint x1IxWzskVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByKlsMtbUrfSrf, 1, klsIxWzskVKeylist);
	sqlite3_bind_int(stmtLoadRefByKlsMtbUrfSrf, 2, x1IxWzskVMaintable);
	sqlite3_bind_int64(stmtLoadRefByKlsMtbUrfSrf, 3, x1Uref);
	sqlite3_bind_text(stmtLoadRefByKlsMtbUrfSrf, 4, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByKlsMtbUrfSrf, ref);
};

bool LiteTblWzskAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWzskVKeylist
			, string sref
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByKlsSrf, 1, klsIxWzskVKeylist);
	sqlite3_bind_text(stmtLoadRefByKlsSrf, 2, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByKlsSrf, ref);
};

ubigint LiteTblWzskAVKeylistKey::loadRstByKls(
			uint klsIxWzskVKeylist
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	sqlite3_bind_int(stmtLoadRstByKls, 1, klsIxWzskVKeylist);

	return loadRstByStmt(stmtLoadRstByKls, append, rst);
};

ubigint LiteTblWzskAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWzskVKeylist
			, uint x1IxWzskVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWzskAVKeylistKey& rst
		) {
	sqlite3_bind_int(stmtLoadRstByKlsMtbUrf, 1, klsIxWzskVKeylist);
	sqlite3_bind_int(stmtLoadRstByKlsMtbUrf, 2, x1IxWzskVMaintable);
	sqlite3_bind_int64(stmtLoadRstByKlsMtbUrf, 3, x1Uref);

	return loadRstByStmt(stmtLoadRstByKlsMtbUrf, append, rst);
};

bool LiteTblWzskAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	sqlite3_bind_int64(stmtLoadTitByRef, 1, ref);

	return loadStringByStmt(stmtLoadTitByRef, Title);
};

#endif

