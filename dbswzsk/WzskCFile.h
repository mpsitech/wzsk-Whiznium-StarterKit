/**
	* \file WzskCFile.h
	* Dbs and XML wrapper for table TblWzskCFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKCFILE_H
#define WZSKCFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* TblWzskCFile: C++ wrapper for table TblWzskCFile
	*/
class TblWzskCFile {

public:
	TblWzskCFile();
	virtual ~TblWzskCFile();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWzskCFile: C++ wrapper for table TblWzskCFile (MySQL database)
	*/
class MyTblWzskCFile : public TblWzskCFile, public Sbecore::MyTable {

public:
	MyTblWzskCFile();
	~MyTblWzskCFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	Sbecore::ubigint getNewRef();
};
#endif

#if defined(SBECORE_LITE)

/**
	* LiteTblWzskCFile: C++ wrapper for table TblWzskCFile (SQLite database)
	*/
class LiteTblWzskCFile : public TblWzskCFile, public Sbecore::LiteTable {

public:
	LiteTblWzskCFile();
	~LiteTblWzskCFile();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtGetNewRef;

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

