/**
	* \file WzskMPerson.cpp
	* database access for table TblWzskMPerson (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "WzskMPerson.h"

#include "WzskMPerson_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskMPerson
 ******************************************************************************/

WzskMPerson::WzskMPerson(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string telVal
			, const ubigint emlRefADetail
			, const string emlVal
			, const string Salutation
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixWDerivate = ixWDerivate;
	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
	this->refJLastname = refJLastname;
	this->Lastname = Lastname;
	this->telRefADetail = telRefADetail;
	this->telVal = telVal;
	this->emlRefADetail = emlRefADetail;
	this->emlVal = emlVal;
	this->Salutation = Salutation;
};

bool WzskMPerson::operator==(
			const WzskMPerson& comp
		) {
	return false;
};

bool WzskMPerson::operator!=(
			const WzskMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskMPerson
 ******************************************************************************/

ListWzskMPerson::ListWzskMPerson() {
};

ListWzskMPerson::ListWzskMPerson(
			const ListWzskMPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskMPerson(*(src.nodes[i]));
};

ListWzskMPerson::~ListWzskMPerson() {
	clear();
};

void ListWzskMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskMPerson::size() const {
	return(nodes.size());
};

void ListWzskMPerson::append(
			WzskMPerson* rec
		) {
	nodes.push_back(rec);
};

WzskMPerson* ListWzskMPerson::operator[](
			const uint ix
		) {
	WzskMPerson* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskMPerson& ListWzskMPerson::operator=(
			const ListWzskMPerson& src
		) {
	WzskMPerson* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskMPerson(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskMPerson::operator==(
			const ListWzskMPerson& comp
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

bool ListWzskMPerson::operator!=(
			const ListWzskMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskMPerson
 ******************************************************************************/

TblWzskMPerson::TblWzskMPerson() {
};

TblWzskMPerson::~TblWzskMPerson() {
};

bool TblWzskMPerson::loadRecBySQL(
			const string& sqlstr
			, WzskMPerson** rec
		) {
	return false;
};

ubigint TblWzskMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMPerson& rst
		) {
	return 0;
};

ubigint TblWzskMPerson::insertRec(
			WzskMPerson* rec
		) {
	return 0;
};

ubigint TblWzskMPerson::insertNewRec(
			WzskMPerson** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string telVal
			, const ubigint emlRefADetail
			, const string emlVal
			, const string Salutation
		) {
	ubigint retval = 0;
	WzskMPerson* _rec = NULL;

	_rec = new WzskMPerson(0, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskMPerson::appendNewRecToRst(
			ListWzskMPerson& rst
			, WzskMPerson** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string telVal
			, const ubigint emlRefADetail
			, const string emlVal
			, const string Salutation
		) {
	ubigint retval = 0;
	WzskMPerson* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskMPerson::insertRst(
			ListWzskMPerson& rst
			, bool transact
		) {
};

void TblWzskMPerson::updateRec(
			WzskMPerson* rec
		) {
};

void TblWzskMPerson::updateRst(
			ListWzskMPerson& rst
			, bool transact
		) {
};

void TblWzskMPerson::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskMPerson::loadRecByRef(
			ubigint ref
			, WzskMPerson** rec
		) {
	return false;
};

ubigint TblWzskMPerson::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskMPerson& rst
		) {
	ubigint numload = 0;
	WzskMPerson* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskMPerson
 ******************************************************************************/

MyTblWzskMPerson::MyTblWzskMPerson() :
			TblWzskMPerson()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskMPerson::~MyTblWzskMPerson() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskMPerson::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMPerson (grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskMPerson SET grp = ?, own = ?, ixWDerivate = ?, ixVSex = ?, Title = ?, Firstname = ?, refJLastname = ?, Lastname = ?, telRefADetail = ?, telVal = ?, emlRefADetail = ?, emlVal = ?, Salutation = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMPerson WHERE ref = ?", false);
};

bool MyTblWzskMPerson::loadRecBySQL(
			const string& sqlstr
			, WzskMPerson** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskMPerson* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMPerson::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMPerson::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskMPerson();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixWDerivate = atol((char*) dbrow[3]); else _rec->ixWDerivate = 0;
		if (dbrow[4]) _rec->ixVSex = atol((char*) dbrow[4]); else _rec->ixVSex = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Firstname.assign(dbrow[6], dblengths[6]); else _rec->Firstname = "";
		if (dbrow[7]) _rec->refJLastname = atoll((char*) dbrow[7]); else _rec->refJLastname = 0;
		if (dbrow[8]) _rec->Lastname.assign(dbrow[8], dblengths[8]); else _rec->Lastname = "";
		if (dbrow[9]) _rec->telRefADetail = atoll((char*) dbrow[9]); else _rec->telRefADetail = 0;
		if (dbrow[10]) _rec->telVal.assign(dbrow[10], dblengths[10]); else _rec->telVal = "";
		if (dbrow[11]) _rec->emlRefADetail = atoll((char*) dbrow[11]); else _rec->emlRefADetail = 0;
		if (dbrow[12]) _rec->emlVal.assign(dbrow[12], dblengths[12]); else _rec->emlVal = "";
		if (dbrow[13]) _rec->Salutation.assign(dbrow[13], dblengths[13]); else _rec->Salutation = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMPerson& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskMPerson* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMPerson::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMPerson::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskMPerson();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixWDerivate = atol((char*) dbrow[3]); else rec->ixWDerivate = 0;
			if (dbrow[4]) rec->ixVSex = atol((char*) dbrow[4]); else rec->ixVSex = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Firstname.assign(dbrow[6], dblengths[6]); else rec->Firstname = "";
			if (dbrow[7]) rec->refJLastname = atoll((char*) dbrow[7]); else rec->refJLastname = 0;
			if (dbrow[8]) rec->Lastname.assign(dbrow[8], dblengths[8]); else rec->Lastname = "";
			if (dbrow[9]) rec->telRefADetail = atoll((char*) dbrow[9]); else rec->telRefADetail = 0;
			if (dbrow[10]) rec->telVal.assign(dbrow[10], dblengths[10]); else rec->telVal = "";
			if (dbrow[11]) rec->emlRefADetail = atoll((char*) dbrow[11]); else rec->emlRefADetail = 0;
			if (dbrow[12]) rec->emlVal.assign(dbrow[12], dblengths[12]); else rec->emlVal = "";
			if (dbrow[13]) rec->Salutation.assign(dbrow[13], dblengths[13]); else rec->Salutation = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskMPerson::insertRec(
			WzskMPerson* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[4] = rec->Title.length();
	l[5] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[11] = rec->emlVal.length();
	l[12] = rec->Salutation.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWDerivate,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVSex,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJLastname,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->telRefADetail,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->emlRefADetail,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Salutation.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskMPerson::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskMPerson::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskMPerson::insertRst(
			ListWzskMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskMPerson::updateRec(
			WzskMPerson* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[4] = rec->Title.length();
	l[5] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[11] = rec->emlVal.length();
	l[12] = rec->Salutation.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWDerivate,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVSex,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJLastname,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->telRefADetail,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->emlRefADetail,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Salutation.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskMPerson::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskMPerson::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskMPerson::updateRst(
			ListWzskMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskMPerson::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskMPerson::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskMPerson::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskMPerson::loadRecByRef(
			ubigint ref
			, WzskMPerson** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskMPerson WHERE ref = " + to_string(ref), rec);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskMPerson
 ******************************************************************************/

LiteTblWzskMPerson::LiteTblWzskMPerson() :
			TblWzskMPerson()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

};

LiteTblWzskMPerson::~LiteTblWzskMPerson() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

};

void LiteTblWzskMPerson::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMPerson (grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11,?12,?13)");
	stmtUpdateRec = createStatement("UPDATE TblWzskMPerson SET grp = ?1, own = ?2, ixWDerivate = ?3, ixVSex = ?4, Title = ?5, Firstname = ?6, refJLastname = ?7, Lastname = ?8, telRefADetail = ?9, telVal = ?10, emlRefADetail = ?11, emlVal = ?12, Salutation = ?13 WHERE ref = ?14");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMPerson WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation FROM TblWzskMPerson WHERE ref = ?1");
};

bool LiteTblWzskMPerson::loadRec(
			sqlite3_stmt* stmt
			, WzskMPerson** rec
		) {
	int res;

	WzskMPerson* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskMPerson();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->grp = sqlite3_column_int64(stmt, 1);
		_rec->own = sqlite3_column_int64(stmt, 2);
		_rec->ixWDerivate = sqlite3_column_int(stmt, 3);
		_rec->ixVSex = sqlite3_column_int(stmt, 4);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->Firstname.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->refJLastname = sqlite3_column_int64(stmt, 7);
		_rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 8));
		_rec->telRefADetail = sqlite3_column_int64(stmt, 9);
		_rec->telVal.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->emlRefADetail = sqlite3_column_int64(stmt, 11);
		_rec->emlVal.assign((const char*) sqlite3_column_text(stmt, 12));
		_rec->Salutation.assign((const char*) sqlite3_column_text(stmt, 13));

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

ubigint LiteTblWzskMPerson::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMPerson& rst
		) {
	int res; ubigint numread = 0;

	WzskMPerson* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskMPerson();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->grp = sqlite3_column_int64(stmt, 1);
		rec->own = sqlite3_column_int64(stmt, 2);
		rec->ixWDerivate = sqlite3_column_int(stmt, 3);
		rec->ixVSex = sqlite3_column_int(stmt, 4);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->Firstname.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->refJLastname = sqlite3_column_int64(stmt, 7);
		rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 8));
		rec->telRefADetail = sqlite3_column_int64(stmt, 9);
		rec->telVal.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->emlRefADetail = sqlite3_column_int64(stmt, 11);
		rec->emlVal.assign((const char*) sqlite3_column_text(stmt, 12));
		rec->Salutation.assign((const char*) sqlite3_column_text(stmt, 13));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskMPerson::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskMPerson** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskMPerson::loadRecBySQL(
			const string& sqlstr
			, WzskMPerson** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMPerson::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMPerson& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMPerson::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMPerson::insertRec(
			WzskMPerson* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->own);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ixWDerivate);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixVSex);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 6, rec->Firstname.c_str(), rec->Firstname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->refJLastname);
	sqlite3_bind_text(stmtInsertRec, 8, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 9, rec->telRefADetail);
	sqlite3_bind_text(stmtInsertRec, 10, rec->telVal.c_str(), rec->telVal.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 11, rec->emlRefADetail);
	sqlite3_bind_text(stmtInsertRec, 12, rec->emlVal.c_str(), rec->emlVal.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 13, rec->Salutation.c_str(), rec->Salutation.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMPerson::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskMPerson::insertRst(
			ListWzskMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskMPerson::updateRec(
			WzskMPerson* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->own);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ixWDerivate);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixVSex);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->Firstname.c_str(), rec->Firstname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->refJLastname);
	sqlite3_bind_text(stmtUpdateRec, 8, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->telRefADetail);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->telVal.c_str(), rec->telVal.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 11, rec->emlRefADetail);
	sqlite3_bind_text(stmtUpdateRec, 12, rec->emlVal.c_str(), rec->emlVal.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 13, rec->Salutation.c_str(), rec->Salutation.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 14, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMPerson::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskMPerson::updateRst(
			ListWzskMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskMPerson::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMPerson::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskMPerson::loadRecByRef(
			ubigint ref
			, WzskMPerson** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

#endif

