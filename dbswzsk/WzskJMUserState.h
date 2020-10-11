/**
	* \file WzskJMUserState.h
	* database access for table TblWzskJMUserState (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef WZSKJMUSERSTATE_H
#define WZSKJMUSERSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskJMUserState: record of TblWzskJMUserState
	*/
class WzskJMUserState {

public:
	WzskJMUserState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUser;
	Sbecore::uint x1Start;
	Sbecore::uint ixVState;

public:
	bool operator==(const WzskJMUserState& comp);
	bool operator!=(const WzskJMUserState& comp);
};

/**
	* ListWzskJMUserState: recordset of TblWzskJMUserState
	*/
class ListWzskJMUserState {

public:
	ListWzskJMUserState();
	ListWzskJMUserState(const ListWzskJMUserState& src);
	~ListWzskJMUserState();

	void clear();
	unsigned int size() const;
	void append(WzskJMUserState* rec);

	WzskJMUserState* operator[](const Sbecore::uint ix);
	ListWzskJMUserState& operator=(const ListWzskJMUserState& src);
	bool operator==(const ListWzskJMUserState& comp);
	bool operator!=(const ListWzskJMUserState& comp);

public:
	std::vector<WzskJMUserState*> nodes;
};

/**
	* TblWzskJMUserState: C++ wrapper for table TblWzskJMUserState
	*/
class TblWzskJMUserState {

public:

public:
	TblWzskJMUserState();
	virtual ~TblWzskJMUserState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskJMUserState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMUserState& rst);

	virtual Sbecore::ubigint insertRec(WzskJMUserState* rec);
	Sbecore::ubigint insertNewRec(WzskJMUserState** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskJMUserState& rst, WzskJMUserState** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	virtual void insertRst(ListWzskJMUserState& rst, bool transact = false);
	virtual void updateRec(WzskJMUserState* rec);
	virtual void updateRst(ListWzskJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskJMUserState** rec);
	virtual bool loadRecByUsrSta(Sbecore::ubigint refWzskMUser, Sbecore::uint x1Start, WzskJMUserState** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskJMUserState& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskJMUserState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskJMUserState: C++ wrapper for table TblWzskJMUserState (MySQL database)
	*/
class MyTblWzskJMUserState : public TblWzskJMUserState, public Sbecore::MyTable {

public:
	MyTblWzskJMUserState();
	~MyTblWzskJMUserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMUserState& rst);

	Sbecore::ubigint insertRec(WzskJMUserState* rec);
	void insertRst(ListWzskJMUserState& rst, bool transact = false);
	void updateRec(WzskJMUserState* rec);
	void updateRst(ListWzskJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWzskMUser, Sbecore::uint x1Start, WzskJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskJMUserState& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskJMUserState: C++ wrapper for table TblWzskJMUserState (SQLite database)
	*/
class LiteTblWzskJMUserState : public TblWzskJMUserState, public Sbecore::LiteTable {

public:
	LiteTblWzskJMUserState();
	~LiteTblWzskJMUserState();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsrSta;
	sqlite3_stmt* stmtLoadRefsByUsr;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskJMUserState** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskJMUserState& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskJMUserState** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskJMUserState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMUserState& rst);

	Sbecore::ubigint insertRec(WzskJMUserState* rec);
	void insertRst(ListWzskJMUserState& rst, bool transact = false);
	void updateRec(WzskJMUserState* rec);
	void updateRst(ListWzskJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWzskMUser, Sbecore::uint x1Start, WzskJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskJMUserState& rst);
};
#endif

#endif

