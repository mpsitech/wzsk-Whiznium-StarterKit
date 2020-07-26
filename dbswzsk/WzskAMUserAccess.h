/**
	* \file WzskAMUserAccess.h
	* database access for table TblWzskAMUserAccess (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKAMUSERACCESS_H
#define WZSKAMUSERACCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskAMUserAccess: record of TblWzskAMUserAccess
	*/
class WzskAMUserAccess {

public:
	WzskAMUserAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUser;
	Sbecore::uint x1IxWzskVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWzskWAccess;

public:
	bool operator==(const WzskAMUserAccess& comp);
	bool operator!=(const WzskAMUserAccess& comp);
};

/**
	* ListWzskAMUserAccess: recordset of TblWzskAMUserAccess
	*/
class ListWzskAMUserAccess {

public:
	ListWzskAMUserAccess();
	ListWzskAMUserAccess(const ListWzskAMUserAccess& src);
	~ListWzskAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(WzskAMUserAccess* rec);

	WzskAMUserAccess* operator[](const Sbecore::uint ix);
	ListWzskAMUserAccess& operator=(const ListWzskAMUserAccess& src);
	bool operator==(const ListWzskAMUserAccess& comp);
	bool operator!=(const ListWzskAMUserAccess& comp);

public:
	std::vector<WzskAMUserAccess*> nodes;
};

/**
	* TblWzskAMUserAccess: C++ wrapper for table TblWzskAMUserAccess
	*/
class TblWzskAMUserAccess {

public:

public:
	TblWzskAMUserAccess();
	virtual ~TblWzskAMUserAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskAMUserAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMUserAccess& rst);

	virtual Sbecore::ubigint insertRec(WzskAMUserAccess* rec);
	Sbecore::ubigint insertNewRec(WzskAMUserAccess** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskAMUserAccess& rst, WzskAMUserAccess** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0);
	virtual void insertRst(ListWzskAMUserAccess& rst, bool transact = false);
	virtual void updateRec(WzskAMUserAccess* rec);
	virtual void updateRst(ListWzskAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskAMUserAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskAMUserAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskAMUserAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskAMUserAccess: C++ wrapper for table TblWzskAMUserAccess (MySQL database)
	*/
class MyTblWzskAMUserAccess : public TblWzskAMUserAccess, public Sbecore::MyTable {

public:
	MyTblWzskAMUserAccess();
	~MyTblWzskAMUserAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMUserAccess& rst);

	Sbecore::ubigint insertRec(WzskAMUserAccess* rec);
	void insertRst(ListWzskAMUserAccess& rst, bool transact = false);
	void updateRec(WzskAMUserAccess* rec);
	void updateRst(ListWzskAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskAMUserAccess& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskAMUserAccess: C++ wrapper for table TblWzskAMUserAccess (SQLite database)
	*/
class LiteTblWzskAMUserAccess : public TblWzskAMUserAccess, public Sbecore::LiteTable {

public:
	LiteTblWzskAMUserAccess();
	~LiteTblWzskAMUserAccess();

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
	bool loadRec(sqlite3_stmt* stmt, WzskAMUserAccess** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskAMUserAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskAMUserAccess** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskAMUserAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMUserAccess& rst);

	Sbecore::ubigint insertRec(WzskAMUserAccess* rec);
	void insertRst(ListWzskAMUserAccess& rst, bool transact = false);
	void updateRec(WzskAMUserAccess* rec);
	void updateRst(ListWzskAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzskMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskAMUserAccess& rst);
};
#endif

#endif

