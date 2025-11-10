/**
	* \file WzskMSession.h
	* database access for table TblWzskMSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef WZSKMSESSION_H
#define WZSKMSESSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskMSession: record of TblWzskMSession
	*/
class WzskMSession {

public:
	WzskMSession(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUser;
	Sbecore::uint start;
	Sbecore::uint stop;
	std::string Ip;

public:
	bool operator==(const WzskMSession& comp);
	bool operator!=(const WzskMSession& comp);
};

/**
	* ListWzskMSession: recordset of TblWzskMSession
	*/
class ListWzskMSession {

public:
	ListWzskMSession();
	ListWzskMSession(const ListWzskMSession& src);
	~ListWzskMSession();

	void clear();
	unsigned int size() const;
	void append(WzskMSession* rec);

	WzskMSession* operator[](const Sbecore::uint ix);
	ListWzskMSession& operator=(const ListWzskMSession& src);
	bool operator==(const ListWzskMSession& comp);
	bool operator!=(const ListWzskMSession& comp);

public:
	std::vector<WzskMSession*> nodes;
};

/**
	* TblWzskMSession: C++ wrapper for table TblWzskMSession
	*/
class TblWzskMSession {

public:

public:
	TblWzskMSession();
	virtual ~TblWzskMSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskMSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMSession& rst);

	virtual Sbecore::ubigint insertRec(WzskMSession* rec);
	Sbecore::ubigint insertNewRec(WzskMSession** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskMSession& rst, WzskMSession** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	virtual void insertRst(ListWzskMSession& rst, bool transact = false);
	virtual void updateRec(WzskMSession* rec);
	virtual void updateRst(ListWzskMSession& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskMSession** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskMSession& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskMSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskMSession: C++ wrapper for table TblWzskMSession (MySQL database)
	*/
class MyTblWzskMSession : public TblWzskMSession, public Sbecore::MyTable {

public:
	MyTblWzskMSession();
	~MyTblWzskMSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMSession& rst);

	Sbecore::ubigint insertRec(WzskMSession* rec);
	void insertRst(ListWzskMSession& rst, bool transact = false);
	void updateRec(WzskMSession* rec);
	void updateRst(ListWzskMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskMSession& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskMSession: C++ wrapper for table TblWzskMSession (SQLite database)
	*/
class LiteTblWzskMSession : public TblWzskMSession, public Sbecore::LiteTable {

public:
	LiteTblWzskMSession();
	~LiteTblWzskMSession();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefsByUsr;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskMSession** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskMSession& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskMSession** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskMSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMSession& rst);

	Sbecore::ubigint insertRec(WzskMSession* rec);
	void insertRst(ListWzskMSession& rst, bool transact = false);
	void updateRec(WzskMSession* rec);
	void updateRst(ListWzskMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskMSession& rst);
};
#endif

#endif
