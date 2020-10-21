/**
	* \file WzskAMShotPar.h
	* database access for table TblWzskAMShotPar (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKAMSHOTPAR_H
#define WZSKAMSHOTPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskAMShotPar: record of TblWzskAMShotPar
	*/
class WzskAMShotPar {

public:
	WzskAMShotPar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMShot = 0, const std::string x1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMShot;
	std::string x1SrefKKey;
	std::string Val;

public:
	bool operator==(const WzskAMShotPar& comp);
	bool operator!=(const WzskAMShotPar& comp);
};

/**
	* ListWzskAMShotPar: recordset of TblWzskAMShotPar
	*/
class ListWzskAMShotPar {

public:
	ListWzskAMShotPar();
	ListWzskAMShotPar(const ListWzskAMShotPar& src);
	~ListWzskAMShotPar();

	void clear();
	unsigned int size() const;
	void append(WzskAMShotPar* rec);

	WzskAMShotPar* operator[](const Sbecore::uint ix);
	ListWzskAMShotPar& operator=(const ListWzskAMShotPar& src);
	bool operator==(const ListWzskAMShotPar& comp);
	bool operator!=(const ListWzskAMShotPar& comp);

public:
	std::vector<WzskAMShotPar*> nodes;
};

/**
	* TblWzskAMShotPar: C++ wrapper for table TblWzskAMShotPar
	*/
class TblWzskAMShotPar {

public:

public:
	TblWzskAMShotPar();
	virtual ~TblWzskAMShotPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskAMShotPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMShotPar& rst);

	virtual Sbecore::ubigint insertRec(WzskAMShotPar* rec);
	Sbecore::ubigint insertNewRec(WzskAMShotPar** rec = NULL, const Sbecore::ubigint refWzskMShot = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskAMShotPar& rst, WzskAMShotPar** rec = NULL, const Sbecore::ubigint refWzskMShot = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWzskAMShotPar& rst, bool transact = false);
	virtual void updateRec(WzskAMShotPar* rec);
	virtual void updateRst(ListWzskAMShotPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskAMShotPar** rec);
	virtual Sbecore::ubigint loadRstBySht(Sbecore::ubigint refWzskMShot, const bool append, ListWzskAMShotPar& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskAMShotPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskAMShotPar: C++ wrapper for table TblWzskAMShotPar (MySQL database)
	*/
class MyTblWzskAMShotPar : public TblWzskAMShotPar, public Sbecore::MyTable {

public:
	MyTblWzskAMShotPar();
	~MyTblWzskAMShotPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAMShotPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMShotPar& rst);

	Sbecore::ubigint insertRec(WzskAMShotPar* rec);
	void insertRst(ListWzskAMShotPar& rst, bool transact = false);
	void updateRec(WzskAMShotPar* rec);
	void updateRst(ListWzskAMShotPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAMShotPar** rec);
	Sbecore::ubigint loadRstBySht(Sbecore::ubigint refWzskMShot, const bool append, ListWzskAMShotPar& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskAMShotPar: C++ wrapper for table TblWzskAMShotPar (SQLite database)
	*/
class LiteTblWzskAMShotPar : public TblWzskAMShotPar, public Sbecore::LiteTable {

public:
	LiteTblWzskAMShotPar();
	~LiteTblWzskAMShotPar();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstBySht;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskAMShotPar** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskAMShotPar& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskAMShotPar** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskAMShotPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAMShotPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMShotPar& rst);

	Sbecore::ubigint insertRec(WzskAMShotPar* rec);
	void insertRst(ListWzskAMShotPar& rst, bool transact = false);
	void updateRec(WzskAMShotPar* rec);
	void updateRst(ListWzskAMShotPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAMShotPar** rec);
	Sbecore::ubigint loadRstBySht(Sbecore::ubigint refWzskMShot, const bool append, ListWzskAMShotPar& rst);
};
#endif

#endif

