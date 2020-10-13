/**
	* \file WzskMShot.h
	* database access for table TblWzskMShot (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef WZSKMSHOT_H
#define WZSKMSHOT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskMShot: record of TblWzskMShot
	*/
class WzskMShot {

public:
	WzskMShot(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMSession = 0, const Sbecore::ubigint refWzskMObject = 0, const Sbecore::uint start = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMSession;
	Sbecore::ubigint refWzskMObject;
	Sbecore::uint start;
	std::string Comment;

public:
	bool operator==(const WzskMShot& comp);
	bool operator!=(const WzskMShot& comp);
};

/**
	* ListWzskMShot: recordset of TblWzskMShot
	*/
class ListWzskMShot {

public:
	ListWzskMShot();
	ListWzskMShot(const ListWzskMShot& src);
	~ListWzskMShot();

	void clear();
	unsigned int size() const;
	void append(WzskMShot* rec);

	WzskMShot* operator[](const Sbecore::uint ix);
	ListWzskMShot& operator=(const ListWzskMShot& src);
	bool operator==(const ListWzskMShot& comp);
	bool operator!=(const ListWzskMShot& comp);

public:
	std::vector<WzskMShot*> nodes;
};

/**
	* TblWzskMShot: C++ wrapper for table TblWzskMShot
	*/
class TblWzskMShot {

public:

public:
	TblWzskMShot();
	virtual ~TblWzskMShot();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskMShot** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMShot& rst);

	virtual Sbecore::ubigint insertRec(WzskMShot* rec);
	Sbecore::ubigint insertNewRec(WzskMShot** rec = NULL, const Sbecore::ubigint refWzskMSession = 0, const Sbecore::ubigint refWzskMObject = 0, const Sbecore::uint start = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskMShot& rst, WzskMShot** rec = NULL, const Sbecore::ubigint refWzskMSession = 0, const Sbecore::ubigint refWzskMObject = 0, const Sbecore::uint start = 0, const std::string Comment = "");
	virtual void insertRst(ListWzskMShot& rst, bool transact = false);
	virtual void updateRec(WzskMShot* rec);
	virtual void updateRst(ListWzskMShot& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskMShot** rec);
	virtual Sbecore::ubigint loadRstByObj(Sbecore::ubigint refWzskMObject, const bool append, ListWzskMShot& rst);
	virtual Sbecore::ubigint loadRstBySes(Sbecore::ubigint refWzskMSession, const bool append, ListWzskMShot& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskMShot& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskMShot: C++ wrapper for table TblWzskMShot (MySQL database)
	*/
class MyTblWzskMShot : public TblWzskMShot, public Sbecore::MyTable {

public:
	MyTblWzskMShot();
	~MyTblWzskMShot();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMShot** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMShot& rst);

	Sbecore::ubigint insertRec(WzskMShot* rec);
	void insertRst(ListWzskMShot& rst, bool transact = false);
	void updateRec(WzskMShot* rec);
	void updateRst(ListWzskMShot& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMShot** rec);
	Sbecore::ubigint loadRstByObj(Sbecore::ubigint refWzskMObject, const bool append, ListWzskMShot& rst);
	Sbecore::ubigint loadRstBySes(Sbecore::ubigint refWzskMSession, const bool append, ListWzskMShot& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskMShot: C++ wrapper for table TblWzskMShot (SQLite database)
	*/
class LiteTblWzskMShot : public TblWzskMShot, public Sbecore::LiteTable {

public:
	LiteTblWzskMShot();
	~LiteTblWzskMShot();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByObj;
	sqlite3_stmt* stmtLoadRstBySes;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskMShot** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskMShot& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskMShot** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskMShot& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMShot** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMShot& rst);

	Sbecore::ubigint insertRec(WzskMShot* rec);
	void insertRst(ListWzskMShot& rst, bool transact = false);
	void updateRec(WzskMShot* rec);
	void updateRst(ListWzskMShot& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMShot** rec);
	Sbecore::ubigint loadRstByObj(Sbecore::ubigint refWzskMObject, const bool append, ListWzskMShot& rst);
	Sbecore::ubigint loadRstBySes(Sbecore::ubigint refWzskMSession, const bool append, ListWzskMShot& rst);
};
#endif

#endif

