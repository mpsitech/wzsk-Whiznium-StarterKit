/**
	* \file WzskAMUsergroupAccess.h
	* database access for table TblWzskAMUsergroupAccess (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKAMUSERGROUPACCESS_H
#define WZSKAMUSERGROUPACCESS_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskAMUsergroupAccess: record of TblWzskAMUsergroupAccess
	*/
class WzskAMUsergroupAccess {

public:
	WzskAMUsergroupAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUsergroup;
	Sbecore::uint x1IxWzskVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWzskWAccess;

public:
	bool operator==(const WzskAMUsergroupAccess& comp);
	bool operator!=(const WzskAMUsergroupAccess& comp);
};

/**
	* ListWzskAMUsergroupAccess: recordset of TblWzskAMUsergroupAccess
	*/
class ListWzskAMUsergroupAccess {

public:
	ListWzskAMUsergroupAccess();
	ListWzskAMUsergroupAccess(const ListWzskAMUsergroupAccess& src);
	~ListWzskAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(WzskAMUsergroupAccess* rec);

	WzskAMUsergroupAccess* operator[](const Sbecore::uint ix);
	ListWzskAMUsergroupAccess& operator=(const ListWzskAMUsergroupAccess& src);
	bool operator==(const ListWzskAMUsergroupAccess& comp);
	bool operator!=(const ListWzskAMUsergroupAccess& comp);

public:
	std::vector<WzskAMUsergroupAccess*> nodes;
};

/**
	* TblWzskAMUsergroupAccess: C++ wrapper for table TblWzskAMUsergroupAccess
	*/
class TblWzskAMUsergroupAccess {

public:

public:
	TblWzskAMUsergroupAccess();
	virtual ~TblWzskAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMUsergroupAccess& rst);

	virtual Sbecore::ubigint insertRec(WzskAMUsergroupAccess* rec);
	Sbecore::ubigint insertNewRec(WzskAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskAMUsergroupAccess& rst, WzskAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0);
	virtual void insertRst(ListWzskAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(WzskAMUsergroupAccess* rec);
	virtual void updateRst(ListWzskAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, ListWzskAMUsergroupAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskAMUsergroupAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskAMUsergroupAccess: C++ wrapper for table TblWzskAMUsergroupAccess (MySQL database)
	*/
class MyTblWzskAMUsergroupAccess : public TblWzskAMUsergroupAccess, public Sbecore::MyTable {

public:
	MyTblWzskAMUsergroupAccess();
	~MyTblWzskAMUsergroupAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WzskAMUsergroupAccess* rec);
	void insertRst(ListWzskAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WzskAMUsergroupAccess* rec);
	void updateRst(ListWzskAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, ListWzskAMUsergroupAccess& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskAMUsergroupAccess: C++ wrapper for table TblWzskAMUsergroupAccess (SQLite database)
	*/
class LiteTblWzskAMUsergroupAccess : public TblWzskAMUsergroupAccess, public Sbecore::LiteTable {

public:
	LiteTblWzskAMUsergroupAccess();
	~LiteTblWzskAMUsergroupAccess();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefsByUsg;
	sqlite3_stmt* stmtLoadRstByUsg;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskAMUsergroupAccess** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskAMUsergroupAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskAMUsergroupAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WzskAMUsergroupAccess* rec);
	void insertRst(ListWzskAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WzskAMUsergroupAccess* rec);
	void updateRst(ListWzskAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, ListWzskAMUsergroupAccess& rst);
};
#endif

#endif

