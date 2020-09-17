/**
	* \file WzskRMUserMUsergroup.h
	* database access for table TblWzskRMUserMUsergroup (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKRMUSERMUSERGROUP_H
#define WZSKRMUSERMUSERGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskRMUserMUsergroup: record of TblWzskRMUserMUsergroup
	*/
class WzskRMUserMUsergroup {

public:
	WzskRMUserMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint ixWzskVUserlevel = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUser;
	Sbecore::ubigint refWzskMUsergroup;
	Sbecore::uint ixWzskVUserlevel;

public:
	bool operator==(const WzskRMUserMUsergroup& comp);
	bool operator!=(const WzskRMUserMUsergroup& comp);
};

/**
	* ListWzskRMUserMUsergroup: recordset of TblWzskRMUserMUsergroup
	*/
class ListWzskRMUserMUsergroup {

public:
	ListWzskRMUserMUsergroup();
	ListWzskRMUserMUsergroup(const ListWzskRMUserMUsergroup& src);
	~ListWzskRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(WzskRMUserMUsergroup* rec);

	WzskRMUserMUsergroup* operator[](const Sbecore::uint ix);
	ListWzskRMUserMUsergroup& operator=(const ListWzskRMUserMUsergroup& src);
	bool operator==(const ListWzskRMUserMUsergroup& comp);
	bool operator!=(const ListWzskRMUserMUsergroup& comp);

public:
	std::vector<WzskRMUserMUsergroup*> nodes;
};

/**
	* TblWzskRMUserMUsergroup: C++ wrapper for table TblWzskRMUserMUsergroup
	*/
class TblWzskRMUserMUsergroup {

public:

public:
	TblWzskRMUserMUsergroup();
	virtual ~TblWzskRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskRMUserMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WzskRMUserMUsergroup* rec);
	Sbecore::ubigint insertNewRec(WzskRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint ixWzskVUserlevel = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskRMUserMUsergroup& rst, WzskRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint ixWzskVUserlevel = 0);
	virtual void insertRst(ListWzskRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(WzskRMUserMUsergroup* rec);
	virtual void updateRst(ListWzskRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, ListWzskRMUserMUsergroup& rst);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskRMUserMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskRMUserMUsergroup: C++ wrapper for table TblWzskRMUserMUsergroup (MySQL database)
	*/
class MyTblWzskRMUserMUsergroup : public TblWzskRMUserMUsergroup, public Sbecore::MyTable {

public:
	MyTblWzskRMUserMUsergroup();
	~MyTblWzskRMUserMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WzskRMUserMUsergroup* rec);
	void insertRst(ListWzskRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WzskRMUserMUsergroup* rec);
	void updateRst(ListWzskRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, ListWzskRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskRMUserMUsergroup& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskRMUserMUsergroup: C++ wrapper for table TblWzskRMUserMUsergroup (SQLite database)
	*/
class LiteTblWzskRMUserMUsergroup : public TblWzskRMUserMUsergroup, public Sbecore::LiteTable {

public:
	LiteTblWzskRMUserMUsergroup();
	~LiteTblWzskRMUserMUsergroup();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByUsg;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskRMUserMUsergroup** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskRMUserMUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskRMUserMUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WzskRMUserMUsergroup* rec);
	void insertRst(ListWzskRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WzskRMUserMUsergroup* rec);
	void updateRst(ListWzskRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, ListWzskRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzskMUser, const bool append, ListWzskRMUserMUsergroup& rst);
};
#endif

#endif

