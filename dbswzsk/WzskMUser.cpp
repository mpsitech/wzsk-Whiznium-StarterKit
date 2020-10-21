/**
	* \file WzskMUser.cpp
	* database access for table TblWzskMUser (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "WzskMUser.h"

#include "WzskMUser_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzskMUser
 ******************************************************************************/

WzskMUser::WzskMUser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWzskMUsergroup
			, const ubigint refWzskMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWzskVLocale
			, const uint ixWzskVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refRUsergroup = refRUsergroup;
	this->refWzskMUsergroup = refWzskMUsergroup;
	this->refWzskMPerson = refWzskMPerson;
	this->sref = sref;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixWzskVLocale = ixWzskVLocale;
	this->ixWzskVUserlevel = ixWzskVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

bool WzskMUser::operator==(
			const WzskMUser& comp
		) {
	return false;
};

bool WzskMUser::operator!=(
			const WzskMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzskMUser
 ******************************************************************************/

ListWzskMUser::ListWzskMUser() {
};

ListWzskMUser::ListWzskMUser(
			const ListWzskMUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskMUser(*(src.nodes[i]));
};

ListWzskMUser::~ListWzskMUser() {
	clear();
};

void ListWzskMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzskMUser::size() const {
	return(nodes.size());
};

void ListWzskMUser::append(
			WzskMUser* rec
		) {
	nodes.push_back(rec);
};

WzskMUser* ListWzskMUser::operator[](
			const uint ix
		) {
	WzskMUser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzskMUser& ListWzskMUser::operator=(
			const ListWzskMUser& src
		) {
	WzskMUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzskMUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzskMUser::operator==(
			const ListWzskMUser& comp
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

bool ListWzskMUser::operator!=(
			const ListWzskMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzskMUser
 ******************************************************************************/

TblWzskMUser::TblWzskMUser() {
};

TblWzskMUser::~TblWzskMUser() {
};

bool TblWzskMUser::loadRecBySQL(
			const string& sqlstr
			, WzskMUser** rec
		) {
	return false;
};

ubigint TblWzskMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMUser& rst
		) {
	return 0;
};

ubigint TblWzskMUser::insertRec(
			WzskMUser* rec
		) {
	return 0;
};

ubigint TblWzskMUser::insertNewRec(
			WzskMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWzskMUsergroup
			, const ubigint refWzskMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWzskVLocale
			, const uint ixWzskVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMUser* _rec = NULL;

	_rec = new WzskMUser(0, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzskMUser::appendNewRecToRst(
			ListWzskMUser& rst
			, WzskMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWzskMUsergroup
			, const ubigint refWzskMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWzskVLocale
			, const uint ixWzskVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	WzskMUser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzskMUser::insertRst(
			ListWzskMUser& rst
			, bool transact
		) {
};

void TblWzskMUser::updateRec(
			WzskMUser* rec
		) {
};

void TblWzskMUser::updateRst(
			ListWzskMUser& rst
			, bool transact
		) {
};

void TblWzskMUser::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzskMUser::loadRecByRef(
			ubigint ref
			, WzskMUser** rec
		) {
	return false;
};

bool TblWzskMUser::loadRecByPrs(
			ubigint refWzskMPerson
			, WzskMUser** rec
		) {
	return false;
};

bool TblWzskMUser::loadRecBySrf(
			string sref
			, WzskMUser** rec
		) {
	return false;
};

bool TblWzskMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WzskMUser** rec
		) {
	return false;
};

bool TblWzskMUser::loadRefByPrs(
			ubigint refWzskMPerson
			, ubigint& ref
		) {
	return false;
};

bool TblWzskMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWzskMUser::loadRefsByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblWzskMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWzskMUser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzskMUser& rst
		) {
	ubigint numload = 0;
	WzskMUser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskMUser
 ******************************************************************************/

MyTblWzskMUser::MyTblWzskMUser() :
			TblWzskMUser()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzskMUser::~MyTblWzskMUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzskMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMUser (grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzskMUser SET grp = ?, own = ?, refRUsergroup = ?, refWzskMUsergroup = ?, refWzskMPerson = ?, sref = ?, refJState = ?, ixVState = ?, ixWzskVLocale = ?, ixWzskVUserlevel = ?, Password = ?, Fullkey = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMUser WHERE ref = ?", false);
};

bool MyTblWzskMUser::loadRecBySQL(
			const string& sqlstr
			, WzskMUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzskMUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMUser::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMUser::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzskMUser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refRUsergroup = atoll((char*) dbrow[3]); else _rec->refRUsergroup = 0;
		if (dbrow[4]) _rec->refWzskMUsergroup = atoll((char*) dbrow[4]); else _rec->refWzskMUsergroup = 0;
		if (dbrow[5]) _rec->refWzskMPerson = atoll((char*) dbrow[5]); else _rec->refWzskMPerson = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->ixWzskVLocale = atol((char*) dbrow[9]); else _rec->ixWzskVLocale = 0;
		if (dbrow[10]) _rec->ixWzskVUserlevel = atol((char*) dbrow[10]); else _rec->ixWzskVUserlevel = 0;
		if (dbrow[11]) _rec->Password.assign(dbrow[11], dblengths[11]); else _rec->Password = "";
		if (dbrow[12]) _rec->Fullkey.assign(dbrow[12], dblengths[12]); else _rec->Fullkey = "";
		if (dbrow[13]) _rec->Comment.assign(dbrow[13], dblengths[13]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzskMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzskMUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzskMUser::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzskMUser::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzskMUser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refRUsergroup = atoll((char*) dbrow[3]); else rec->refRUsergroup = 0;
			if (dbrow[4]) rec->refWzskMUsergroup = atoll((char*) dbrow[4]); else rec->refWzskMUsergroup = 0;
			if (dbrow[5]) rec->refWzskMPerson = atoll((char*) dbrow[5]); else rec->refWzskMPerson = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->ixWzskVLocale = atol((char*) dbrow[9]); else rec->ixWzskVLocale = 0;
			if (dbrow[10]) rec->ixWzskVUserlevel = atol((char*) dbrow[10]); else rec->ixWzskVUserlevel = 0;
			if (dbrow[11]) rec->Password.assign(dbrow[11], dblengths[11]); else rec->Password = "";
			if (dbrow[12]) rec->Fullkey.assign(dbrow[12], dblengths[12]); else rec->Fullkey = "";
			if (dbrow[13]) rec->Comment.assign(dbrow[13], dblengths[13]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzskMUser::insertRec(
			WzskMUser* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzskMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWzskMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWzskVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWzskVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzskMUser::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzskMUser::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzskMUser::insertRst(
			ListWzskMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzskMUser::updateRec(
			WzskMUser* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzskMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWzskMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWzskVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWzskVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzskMUser::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzskMUser::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzskMUser::updateRst(
			ListWzskMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzskMUser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzskMUser::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzskMUser::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzskMUser::loadRecByRef(
			ubigint ref
			, WzskMUser** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzskMUser WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzskMUser::loadRecByPrs(
			ubigint refWzskMPerson
			, WzskMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment FROM TblWzskMUser WHERE refWzskMPerson = " + to_string(refWzskMPerson) + "", rec);
};

bool MyTblWzskMUser::loadRecBySrf(
			string sref
			, WzskMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment FROM TblWzskMUser WHERE sref = '" + sref + "'", rec);
};

bool MyTblWzskMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WzskMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment FROM TblWzskMUser WHERE sref = '" + sref + "' AND Password = '" + Password + "'", rec);
};

bool MyTblWzskMUser::loadRefByPrs(
			ubigint refWzskMPerson
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzskMUser WHERE refWzskMPerson = " + to_string(refWzskMPerson) + "", ref);
};

bool MyTblWzskMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzskMUser WHERE sref = '" + sref + "'", ref);
};

ubigint MyTblWzskMUser::loadRefsByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzskMUser WHERE refWzskMUsergroup = " + to_string(refWzskMUsergroup) + "", append, refs);
};

bool MyTblWzskMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWzskMUser WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskMUser
 ******************************************************************************/

LiteTblWzskMUser::LiteTblWzskMUser() :
			TblWzskMUser()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByPrs = NULL;
	stmtLoadRecBySrf = NULL;
	stmtLoadRecBySrfPwd = NULL;
	stmtLoadRefByPrs = NULL;
	stmtLoadRefBySrf = NULL;
	stmtLoadRefsByUsg = NULL;
	stmtLoadSrfByRef = NULL;
};

LiteTblWzskMUser::~LiteTblWzskMUser() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByPrs) sqlite3_finalize(stmtLoadRecByPrs);
	if (stmtLoadRecBySrf) sqlite3_finalize(stmtLoadRecBySrf);
	if (stmtLoadRecBySrfPwd) sqlite3_finalize(stmtLoadRecBySrfPwd);
	if (stmtLoadRefByPrs) sqlite3_finalize(stmtLoadRefByPrs);
	if (stmtLoadRefBySrf) sqlite3_finalize(stmtLoadRefBySrf);
	if (stmtLoadRefsByUsg) sqlite3_finalize(stmtLoadRefsByUsg);
	if (stmtLoadSrfByRef) sqlite3_finalize(stmtLoadSrfByRef);
};

void LiteTblWzskMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzskMUser (grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11,?12,?13)");
	stmtUpdateRec = createStatement("UPDATE TblWzskMUser SET grp = ?1, own = ?2, refRUsergroup = ?3, refWzskMUsergroup = ?4, refWzskMPerson = ?5, sref = ?6, refJState = ?7, ixVState = ?8, ixWzskVLocale = ?9, ixWzskVUserlevel = ?10, Password = ?11, Fullkey = ?12, Comment = ?13 WHERE ref = ?14");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzskMUser WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment FROM TblWzskMUser WHERE ref = ?1");
	stmtLoadRecByPrs = createStatement("SELECT ref, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment FROM TblWzskMUser WHERE refWzskMPerson = ?1");
	stmtLoadRecBySrf = createStatement("SELECT ref, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment FROM TblWzskMUser WHERE sref = ?1");
	stmtLoadRecBySrfPwd = createStatement("SELECT ref, grp, own, refRUsergroup, refWzskMUsergroup, refWzskMPerson, sref, refJState, ixVState, ixWzskVLocale, ixWzskVUserlevel, Password, Fullkey, Comment FROM TblWzskMUser WHERE sref = ?1 AND Password = ?2");
	stmtLoadRefByPrs = createStatement("SELECT ref FROM TblWzskMUser WHERE refWzskMPerson = ?1");
	stmtLoadRefBySrf = createStatement("SELECT ref FROM TblWzskMUser WHERE sref = ?1");
	stmtLoadRefsByUsg = createStatement("SELECT ref FROM TblWzskMUser WHERE refWzskMUsergroup = ?1");
	stmtLoadSrfByRef = createStatement("SELECT sref FROM TblWzskMUser WHERE ref = ?1");
};

bool LiteTblWzskMUser::loadRec(
			sqlite3_stmt* stmt
			, WzskMUser** rec
		) {
	int res;

	WzskMUser* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzskMUser();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->grp = sqlite3_column_int64(stmt, 1);
		_rec->own = sqlite3_column_int64(stmt, 2);
		_rec->refRUsergroup = sqlite3_column_int64(stmt, 3);
		_rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 4);
		_rec->refWzskMPerson = sqlite3_column_int64(stmt, 5);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->refJState = sqlite3_column_int64(stmt, 7);
		_rec->ixVState = sqlite3_column_int(stmt, 8);
		_rec->ixWzskVLocale = sqlite3_column_int(stmt, 9);
		_rec->ixWzskVUserlevel = sqlite3_column_int(stmt, 10);
		_rec->Password.assign((const char*) sqlite3_column_text(stmt, 11));
		_rec->Fullkey.assign((const char*) sqlite3_column_text(stmt, 12));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 13));

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

ubigint LiteTblWzskMUser::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzskMUser& rst
		) {
	int res; ubigint numread = 0;

	WzskMUser* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzskMUser();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->grp = sqlite3_column_int64(stmt, 1);
		rec->own = sqlite3_column_int64(stmt, 2);
		rec->refRUsergroup = sqlite3_column_int64(stmt, 3);
		rec->refWzskMUsergroup = sqlite3_column_int64(stmt, 4);
		rec->refWzskMPerson = sqlite3_column_int64(stmt, 5);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->refJState = sqlite3_column_int64(stmt, 7);
		rec->ixVState = sqlite3_column_int(stmt, 8);
		rec->ixWzskVLocale = sqlite3_column_int(stmt, 9);
		rec->ixWzskVUserlevel = sqlite3_column_int(stmt, 10);
		rec->Password.assign((const char*) sqlite3_column_text(stmt, 11));
		rec->Fullkey.assign((const char*) sqlite3_column_text(stmt, 12));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 13));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzskMUser::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzskMUser** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzskMUser::loadRecBySQL(
			const string& sqlstr
			, WzskMUser** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMUser::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzskMUser& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzskMUser::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzskMUser::insertRec(
			WzskMUser* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->own);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refRUsergroup);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzskMUsergroup);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->refWzskMPerson);
	sqlite3_bind_text(stmtInsertRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->refJState);
	sqlite3_bind_int(stmtInsertRec, 8, rec->ixVState);
	sqlite3_bind_int(stmtInsertRec, 9, rec->ixWzskVLocale);
	sqlite3_bind_int(stmtInsertRec, 10, rec->ixWzskVUserlevel);
	sqlite3_bind_text(stmtInsertRec, 11, rec->Password.c_str(), rec->Password.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 12, rec->Fullkey.c_str(), rec->Fullkey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 13, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMUser::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzskMUser::insertRst(
			ListWzskMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzskMUser::updateRec(
			WzskMUser* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->own);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refRUsergroup);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzskMUsergroup);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->refWzskMPerson);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->refJState);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->ixVState);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->ixWzskVLocale);
	sqlite3_bind_int(stmtUpdateRec, 10, rec->ixWzskVUserlevel);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->Password.c_str(), rec->Password.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 12, rec->Fullkey.c_str(), rec->Fullkey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 13, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 14, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMUser::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzskMUser::updateRst(
			ListWzskMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzskMUser::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskMUser::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzskMUser::loadRecByRef(
			ubigint ref
			, WzskMUser** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzskMUser::loadRecByPrs(
			ubigint refWzskMPerson
			, WzskMUser** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByPrs, 1, refWzskMPerson);

	return loadRecByStmt(stmtLoadRecByPrs, rec);
};

bool LiteTblWzskMUser::loadRecBySrf(
			string sref
			, WzskMUser** rec
		) {
	sqlite3_bind_text(stmtLoadRecBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecBySrf, rec);
};

bool LiteTblWzskMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WzskMUser** rec
		) {
	sqlite3_bind_text(stmtLoadRecBySrfPwd, 1, sref.c_str(), sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtLoadRecBySrfPwd, 2, Password.c_str(), Password.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecBySrfPwd, rec);
};

bool LiteTblWzskMUser::loadRefByPrs(
			ubigint refWzskMPerson
			, ubigint& ref
		) {
	sqlite3_bind_int64(stmtLoadRefByPrs, 1, refWzskMPerson);

	return loadRefByStmt(stmtLoadRefByPrs, ref);
};

bool LiteTblWzskMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	sqlite3_bind_text(stmtLoadRefBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefBySrf, ref);
};

ubigint LiteTblWzskMUser::loadRefsByUsg(
			ubigint refWzskMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsg, 1, refWzskMUsergroup);

	return loadRefsByStmt(stmtLoadRefsByUsg, append, refs);
};

bool LiteTblWzskMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	sqlite3_bind_int64(stmtLoadSrfByRef, 1, ref);

	return loadStringByStmt(stmtLoadSrfByRef, sref);
};

#endif

