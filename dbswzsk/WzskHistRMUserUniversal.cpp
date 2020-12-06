/**
	* \file WzskHistRMUserUniversal.cpp
	* database access for table TblWzskHistRMUserUniversal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskHistRMUserUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskHistRMUserUniversal
 ******************************************************************************/

WzskHistRMUserUniversal::WzskHistRMUserUniversal(
			const ubigint ref
			, const ubigint refWzskMUser
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVCard
			, const uint ixWzskVPreset
			, const uint preIxWzskVMaintable
			, const ubigint preUref
			, const uint start
		) {

	this->ref = ref;
	this->refWzskMUser = refWzskMUser;
	this->unvIxWzskVMaintable = unvIxWzskVMaintable;
	this->unvUref = unvUref;
	this->ixWzskVCard = ixWzskVCard;
	this->ixWzskVPreset = ixWzskVPreset;
	this->preIxWzskVMaintable = preIxWzskVMaintable;
	this->preUref = preUref;
	this->start = start;
};

bool WzskHistRMUserUniversal::operator==(
			const WzskHistRMUserUniversal& comp
		) {
	return false;
};

bool WzskHistRMUserUniversal::operator!=(
			const WzskHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskHistRMUserUniversal
 ******************************************************************************/

ListWzskHistRMUserUniversal::ListWzskHistRMUserUniversal() {
};

ListWzskHistRMUserUniversal::ListWzskHistRMUserUniversal(
			const ListWzskHistRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskHistRMUserUniversal(*(src.nodes[i]));
};

ListWzskHistRMUserUniversal::~ListWzskHistRMUserUniversal() {
	clear();
};

void ListWzskHistRMUserUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskHistRMUserUniversal::size() const {
	return(nodes.size());
};

void ListWzskHistRMUserUniversal::append(
			WzskHistRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

WzskHistRMUserUniversal* ListWzskHistRMUserUniversal::operator[](
			const uint ix
		) {
	WzskHistRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskHistRMUserUniversal& ListWzskHistRMUserUniversal::operator=(
			const ListWzskHistRMUserUniversal& src
		) {
	WzskHistRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskHistRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskHistRMUserUniversal::operator==(
			const ListWzskHistRMUserUniversal& comp
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

bool ListWzskHistRMUserUniversal::operator!=(
			const ListWzskHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskHistRMUserUniversal
 ******************************************************************************/

TblWzskHistRMUserUniversal::TblWzskHistRMUserUniversal() {
};

TblWzskHistRMUserUniversal::~TblWzskHistRMUserUniversal() {
};

bool TblWzskHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWzskHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	return 0;
};

ubigint TblWzskHistRMUserUniversal::insertRec(
			WzskHistRMUserUniversal* rec
		) {
	return 0;
};

ubigint TblWzskHistRMUserUniversal::insertNewRec(
			WzskHistRMUserUniversal** rec
			, const ubigint refWzskMUser
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVCard
			, const uint ixWzskVPreset
			, const uint preIxWzskVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	WzskHistRMUserUniversal* _rec = NULL;

	_rec = new WzskHistRMUserUniversal(0, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskHistRMUserUniversal::appendNewRecToRst(
			ListWzskHistRMUserUniversal& rst
			, WzskHistRMUserUniversal** rec
			, const ubigint refWzskMUser
			, const uint unvIxWzskVMaintable
			, const ubigint unvUref
			, const uint ixWzskVCard
			, const uint ixWzskVPreset
			, const uint preIxWzskVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	WzskHistRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskHistRMUserUniversal::insertRst(
			ListWzskHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblWzskHistRMUserUniversal::updateRec(
			WzskHistRMUserUniversal* rec
		) {
};

void TblWzskHistRMUserUniversal::updateRst(
			ListWzskHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblWzskHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzskHistRMUserUniversal** rec
		) {
	return false;
};

bool TblWzskHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, uint ixWzskVCard
			, WzskHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWzskHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, uint ixWzskVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	return 0;
};

ubigint TblWzskHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWzskMUser
			, uint ixWzskVCard
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	return 0;
};

bool TblWzskHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return false;
};

ubigint TblWzskHistRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	ubigint numload = 0;
	WzskHistRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskHistRMUserUniversal
 ******************************************************************************/

MyTblWzskHistRMUserUniversal::MyTblWzskHistRMUserUniversal() :
			TblWzskHistRMUserUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskHistRMUserUniversal::~MyTblWzskHistRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskHistRMUserUniversal (refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskHistRMUserUniversal SET refWzskMUser = ?, unvIxWzskVMaintable = ?, unvUref = ?, ixWzskVCard = ?, ixWzskVPreset = ?, preIxWzskVMaintable = ?, preUref = ?, start = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskHistRMUserUniversal WHERE ref = ?", false);
};

bool MyTblWzskHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskHistRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskHistRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskHistRMUserUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskHistRMUserUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzskHistRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzskMUser = atoll((char*) dbrow[1]); else _rec->refWzskMUser = 0;
		if (dbrow[2]) _rec->unvIxWzskVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWzskVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWzskVCard = atol((char*) dbrow[4]); else _rec->ixWzskVCard = 0;
		if (dbrow[5]) _rec->ixWzskVPreset = atol((char*) dbrow[5]); else _rec->ixWzskVPreset = 0;
		if (dbrow[6]) _rec->preIxWzskVMaintable = atol((char*) dbrow[6]); else _rec->preIxWzskVMaintable = 0;
		if (dbrow[7]) _rec->preUref = atoll((char*) dbrow[7]); else _rec->preUref = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskHistRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskHistRMUserUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskHistRMUserUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzskHistRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzskMUser = atoll((char*) dbrow[1]); else rec->refWzskMUser = 0;
			if (dbrow[2]) rec->unvIxWzskVMaintable = atol((char*) dbrow[2]); else rec->unvIxWzskVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixWzskVCard = atol((char*) dbrow[4]); else rec->ixWzskVCard = 0;
			if (dbrow[5]) rec->ixWzskVPreset = atol((char*) dbrow[5]); else rec->ixWzskVPreset = 0;
			if (dbrow[6]) rec->preIxWzskVMaintable = atol((char*) dbrow[6]); else rec->preIxWzskVMaintable = 0;
			if (dbrow[7]) rec->preUref = atoll((char*) dbrow[7]); else rec->preUref = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskHistRMUserUniversal::insertRec(
			WzskHistRMUserUniversal* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzskVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWzskVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxWzskVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskHistRMUserUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskHistRMUserUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskHistRMUserUniversal::insertRst(
			ListWzskHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskHistRMUserUniversal::updateRec(
			WzskHistRMUserUniversal* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzskMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzskVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzskVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWzskVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxWzskVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskHistRMUserUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskHistRMUserUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskHistRMUserUniversal::updateRst(
			ListWzskHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskHistRMUserUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskHistRMUserUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzskHistRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskHistRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, uint ixWzskVCard
			, WzskHistRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start FROM TblWzskHistRMUserUniversal WHERE refWzskMUser = " + to_string(refWzskMUser) + " AND unvIxWzskVMaintable = " + to_string(unvIxWzskVMaintable) + " AND unvUref = " + to_string(unvUref) + " AND ixWzskVCard = " + to_string(ixWzskVCard) + "", rec);
};

ubigint MyTblWzskHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, uint ixWzskVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	if ((limit == 0) && (offset == 0)) limit--;

	return loadRefsBySQL("SELECT ref FROM TblWzskHistRMUserUniversal WHERE refWzskMUser = " + to_string(refWzskMUser) + " AND unvIxWzskVMaintable = " + to_string(unvIxWzskVMaintable) + " AND ixWzskVCard = " + to_string(ixWzskVCard) + " ORDER BY start DESC LIMIT " + to_string(offset) + "," + to_string(limit) + "", append, refs);
};

ubigint MyTblWzskHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWzskMUser
			, uint ixWzskVCard
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	return loadRstBySQL("SELECT ref, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start FROM TblWzskHistRMUserUniversal WHERE refWzskMUser = " + to_string(refWzskMUser) + " AND ixWzskVCard = " + to_string(ixWzskVCard) + " ORDER BY start DESC", append, rst);
};

bool MyTblWzskHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return loadRefBySQL("SELECT unvUref FROM TblWzskHistRMUserUniversal WHERE ref = " + to_string(ref) + "", unvUref);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskHistRMUserUniversal
 ******************************************************************************/

LiteTblWzskHistRMUserUniversal::LiteTblWzskHistRMUserUniversal() :
			TblWzskHistRMUserUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsrMtbUnvCrd = NULL;
	stmtLoadRefsByUsrMtbCrd = NULL;
	stmtLoadRstByUsrCrd = NULL;
	stmtLoadUnuByRef = NULL;
};

LiteTblWzskHistRMUserUniversal::~LiteTblWzskHistRMUserUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsrMtbUnvCrd) sqlite3_finalize(stmtLoadRecByUsrMtbUnvCrd);
	if (stmtLoadRefsByUsrMtbCrd) sqlite3_finalize(stmtLoadRefsByUsrMtbCrd);
	if (stmtLoadRstByUsrCrd) sqlite3_finalize(stmtLoadRstByUsrCrd);
	if (stmtLoadUnuByRef) sqlite3_finalize(stmtLoadUnuByRef);
};

void LiteTblWzskHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskHistRMUserUniversal (refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start) VALUES (?1,?2,?3,?4,?5,?6,?7,?8)");
	stmtUpdateRec = createStatement("UPDATE TblWzskHistRMUserUniversal SET refWzskMUser = ?1, unvIxWzskVMaintable = ?2, unvUref = ?3, ixWzskVCard = ?4, ixWzskVPreset = ?5, preIxWzskVMaintable = ?6, preUref = ?7, start = ?8 WHERE ref = ?9");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskHistRMUserUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start FROM TblWzskHistRMUserUniversal WHERE ref = ?1");
	stmtLoadRecByUsrMtbUnvCrd = createStatement("SELECT ref, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start FROM TblWzskHistRMUserUniversal WHERE refWzskMUser = ?1 AND unvIxWzskVMaintable = ?2 AND unvUref = ?3 AND ixWzskVCard = ?4");
	stmtLoadRefsByUsrMtbCrd = createStatement("SELECT ref FROM TblWzskHistRMUserUniversal WHERE refWzskMUser = ?1 AND unvIxWzskVMaintable = ?2 AND ixWzskVCard = ?3 ORDER BY start DESC LIMIT ?,?");
	stmtLoadRstByUsrCrd = createStatement("SELECT ref, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, start FROM TblWzskHistRMUserUniversal WHERE refWzskMUser = ?1 AND ixWzskVCard = ?2 ORDER BY start DESC");
	stmtLoadUnuByRef = createStatement("SELECT unvUref FROM TblWzskHistRMUserUniversal WHERE ref = ?1");
};

bool LiteTblWzskHistRMUserUniversal::loadRec(
			sqlite3_stmt* stmt
			, WzskHistRMUserUniversal** rec
		) {
	int res;

	WzskHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskHistRMUserUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		_rec->unvIxWzskVMaintable = sqlite3_column_int(stmt, 2);
		_rec->unvUref = sqlite3_column_int64(stmt, 3);
		_rec->ixWzskVCard = sqlite3_column_int(stmt, 4);
		_rec->ixWzskVPreset = sqlite3_column_int(stmt, 5);
		_rec->preIxWzskVMaintable = sqlite3_column_int(stmt, 6);
		_rec->preUref = sqlite3_column_int64(stmt, 7);
		_rec->start = sqlite3_column_int(stmt, 8);

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

ubigint LiteTblWzskHistRMUserUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	int res; ubigint numread = 0;

	WzskHistRMUserUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskHistRMUserUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzskMUser = sqlite3_column_int64(stmt, 1);
		rec->unvIxWzskVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixWzskVCard = sqlite3_column_int(stmt, 4);
		rec->ixWzskVPreset = sqlite3_column_int(stmt, 5);
		rec->preIxWzskVMaintable = sqlite3_column_int(stmt, 6);
		rec->preUref = sqlite3_column_int64(stmt, 7);
		rec->start = sqlite3_column_int(stmt, 8);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskHistRMUserUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskHistRMUserUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzskHistRMUserUniversal::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzskHistRMUserUniversal** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskHistRMUserUniversal::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskHistRMUserUniversal::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskHistRMUserUniversal::insertRec(
			WzskHistRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzskVCard);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixWzskVPreset);
	sqlite3_bind_int(stmtInsertRec, 6, rec->preIxWzskVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->preUref);
	sqlite3_bind_int(stmtInsertRec, 8, rec->start);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskHistRMUserUniversal::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskHistRMUserUniversal::insertRst(
			ListWzskHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskHistRMUserUniversal::updateRec(
			WzskHistRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzskMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzskVCard);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixWzskVPreset);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->preIxWzskVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->preUref);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->start);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskHistRMUserUniversal::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskHistRMUserUniversal::updateRst(
			ListWzskHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskHistRMUserUniversal::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzskHistRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, ubigint unvUref
			, uint ixWzskVCard
			, WzskHistRMUserUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnvCrd, 1, refWzskMUser);
	sqlite3_bind_int(stmtLoadRecByUsrMtbUnvCrd, 2, unvIxWzskVMaintable);
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnvCrd, 3, unvUref);
	sqlite3_bind_int(stmtLoadRecByUsrMtbUnvCrd, 4, ixWzskVCard);

	return loadRecByStmt(stmtLoadRecByUsrMtbUnvCrd, rec);
};

ubigint LiteTblWzskHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWzskMUser
			, uint unvIxWzskVMaintable
			, uint ixWzskVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsrMtbCrd, 1, refWzskMUser);
	sqlite3_bind_int(stmtLoadRefsByUsrMtbCrd, 2, unvIxWzskVMaintable);
	sqlite3_bind_int(stmtLoadRefsByUsrMtbCrd, 3, ixWzskVCard);
	sqlite3_bind_int64(stmtLoadRefsByUsrMtbCrd, 4, offset);
	if (limit == 0) sqlite3_bind_int64(stmtLoadRefsByUsrMtbCrd, 5, -1); else sqlite3_bind_int64(stmtLoadRefsByUsrMtbCrd, 5, limit);

	return loadRefsByStmt(stmtLoadRefsByUsrMtbCrd, append, refs);
};

ubigint LiteTblWzskHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWzskMUser
			, uint ixWzskVCard
			, const bool append
			, ListWzskHistRMUserUniversal& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsrCrd, 1, refWzskMUser);
	sqlite3_bind_int(stmtLoadRstByUsrCrd, 2, ixWzskVCard);

	return loadRstByStmt(stmtLoadRstByUsrCrd, append, rst);
};

bool LiteTblWzskHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	sqlite3_bind_int64(stmtLoadUnuByRef, 1, ref);

	return loadRefByStmt(stmtLoadUnuByRef, unvUref);
};

#endif
