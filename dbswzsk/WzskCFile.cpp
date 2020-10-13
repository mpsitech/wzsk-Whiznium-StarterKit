/**
	* \file WzskCFile.cpp
	* Dbs and XML wrapper for table TblWzskCFile (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "WzskCFile.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWzskCFile
 ******************************************************************************/

TblWzskCFile::TblWzskCFile() {
};

TblWzskCFile::~TblWzskCFile() {
};

ubigint TblWzskCFile::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzskCFile
 ******************************************************************************/

MyTblWzskCFile::MyTblWzskCFile() :
			TblWzskCFile()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWzskCFile::~MyTblWzskCFile() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWzskCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWzskCFile () VALUES ()", false);
};

ubigint MyTblWzskCFile::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWzskCFile::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWzskCFile::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzskCFile
 ******************************************************************************/

LiteTblWzskCFile::LiteTblWzskCFile() :
			TblWzskCFile()
			, LiteTable()
		{
	stmtGetNewRef = NULL;
};

LiteTblWzskCFile::~LiteTblWzskCFile() {
	if (stmtGetNewRef) sqlite3_finalize(stmtGetNewRef);
};

void LiteTblWzskCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWzskCFile (void) VALUES (0)");
};

ubigint LiteTblWzskCFile::getNewRef() {
	if (sqlite3_step(stmtGetNewRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzskCFile::getNewRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return sqlite3_last_insert_rowid(dbs);
};
#endif

