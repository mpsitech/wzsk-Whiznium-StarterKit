/**
	* \file WzskJMObjgroupTitle.h
	* database access for table TblWzskJMObjgroupTitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKJMOBJGROUPTITLE_H
#define WZSKJMOBJGROUPTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskJMObjgroupTitle: record of TblWzskJMObjgroupTitle
	*/
class WzskJMObjgroupTitle {

public:
	WzskJMObjgroupTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMObjgroup = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMObjgroup;
	Sbecore::uint x1IxWzskVLocale;
	std::string Title;

public:
	bool operator==(const WzskJMObjgroupTitle& comp);
	bool operator!=(const WzskJMObjgroupTitle& comp);
};

/**
	* ListWzskJMObjgroupTitle: recordset of TblWzskJMObjgroupTitle
	*/
class ListWzskJMObjgroupTitle {

public:
	ListWzskJMObjgroupTitle();
	ListWzskJMObjgroupTitle(const ListWzskJMObjgroupTitle& src);
	~ListWzskJMObjgroupTitle();

	void clear();
	unsigned int size() const;
	void append(WzskJMObjgroupTitle* rec);

	WzskJMObjgroupTitle* operator[](const Sbecore::uint ix);
	ListWzskJMObjgroupTitle& operator=(const ListWzskJMObjgroupTitle& src);
	bool operator==(const ListWzskJMObjgroupTitle& comp);
	bool operator!=(const ListWzskJMObjgroupTitle& comp);

public:
	std::vector<WzskJMObjgroupTitle*> nodes;
};

/**
	* TblWzskJMObjgroupTitle: C++ wrapper for table TblWzskJMObjgroupTitle
	*/
class TblWzskJMObjgroupTitle {

public:

public:
	TblWzskJMObjgroupTitle();
	virtual ~TblWzskJMObjgroupTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskJMObjgroupTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMObjgroupTitle& rst);

	virtual Sbecore::ubigint insertRec(WzskJMObjgroupTitle* rec);
	Sbecore::ubigint insertNewRec(WzskJMObjgroupTitle** rec = NULL, const Sbecore::ubigint refWzskMObjgroup = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskJMObjgroupTitle& rst, WzskJMObjgroupTitle** rec = NULL, const Sbecore::ubigint refWzskMObjgroup = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWzskJMObjgroupTitle& rst, bool transact = false);
	virtual void updateRec(WzskJMObjgroupTitle* rec);
	virtual void updateRst(ListWzskJMObjgroupTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskJMObjgroupTitle** rec);
	virtual bool loadRecByOgrLcl(Sbecore::ubigint refWzskMObjgroup, Sbecore::uint x1IxWzskVLocale, WzskJMObjgroupTitle** rec);
	virtual Sbecore::ubigint loadRstByOgr(Sbecore::ubigint refWzskMObjgroup, const bool append, ListWzskJMObjgroupTitle& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskJMObjgroupTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskJMObjgroupTitle: C++ wrapper for table TblWzskJMObjgroupTitle (MySQL database)
	*/
class MyTblWzskJMObjgroupTitle : public TblWzskJMObjgroupTitle, public Sbecore::MyTable {

public:
	MyTblWzskJMObjgroupTitle();
	~MyTblWzskJMObjgroupTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskJMObjgroupTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMObjgroupTitle& rst);

	Sbecore::ubigint insertRec(WzskJMObjgroupTitle* rec);
	void insertRst(ListWzskJMObjgroupTitle& rst, bool transact = false);
	void updateRec(WzskJMObjgroupTitle* rec);
	void updateRst(ListWzskJMObjgroupTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskJMObjgroupTitle** rec);
	bool loadRecByOgrLcl(Sbecore::ubigint refWzskMObjgroup, Sbecore::uint x1IxWzskVLocale, WzskJMObjgroupTitle** rec);
	Sbecore::ubigint loadRstByOgr(Sbecore::ubigint refWzskMObjgroup, const bool append, ListWzskJMObjgroupTitle& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskJMObjgroupTitle: C++ wrapper for table TblWzskJMObjgroupTitle (SQLite database)
	*/
class LiteTblWzskJMObjgroupTitle : public TblWzskJMObjgroupTitle, public Sbecore::LiteTable {

public:
	LiteTblWzskJMObjgroupTitle();
	~LiteTblWzskJMObjgroupTitle();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByOgrLcl;
	sqlite3_stmt* stmtLoadRstByOgr;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskJMObjgroupTitle** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskJMObjgroupTitle& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskJMObjgroupTitle** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskJMObjgroupTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskJMObjgroupTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMObjgroupTitle& rst);

	Sbecore::ubigint insertRec(WzskJMObjgroupTitle* rec);
	void insertRst(ListWzskJMObjgroupTitle& rst, bool transact = false);
	void updateRec(WzskJMObjgroupTitle* rec);
	void updateRst(ListWzskJMObjgroupTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskJMObjgroupTitle** rec);
	bool loadRecByOgrLcl(Sbecore::ubigint refWzskMObjgroup, Sbecore::uint x1IxWzskVLocale, WzskJMObjgroupTitle** rec);
	Sbecore::ubigint loadRstByOgr(Sbecore::ubigint refWzskMObjgroup, const bool append, ListWzskJMObjgroupTitle& rst);
};
#endif

#endif
