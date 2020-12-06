/**
	* \file WzskRMUsergroupUniversal.h
	* database access for table TblWzskRMUsergroupUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKRMUSERGROUPUNIVERSAL_H
#define WZSKRMUSERGROUPUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskRMUsergroupUniversal: record of TblWzskRMUsergroupUniversal
	*/
class WzskRMUsergroupUniversal {

public:
	WzskRMUsergroupUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUsergroup;
	Sbecore::uint unvIxWzskVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWzskVRecaccess;

public:
	bool operator==(const WzskRMUsergroupUniversal& comp);
	bool operator!=(const WzskRMUsergroupUniversal& comp);
};

/**
	* ListWzskRMUsergroupUniversal: recordset of TblWzskRMUsergroupUniversal
	*/
class ListWzskRMUsergroupUniversal {

public:
	ListWzskRMUsergroupUniversal();
	ListWzskRMUsergroupUniversal(const ListWzskRMUsergroupUniversal& src);
	~ListWzskRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(WzskRMUsergroupUniversal* rec);

	WzskRMUsergroupUniversal* operator[](const Sbecore::uint ix);
	ListWzskRMUsergroupUniversal& operator=(const ListWzskRMUsergroupUniversal& src);
	bool operator==(const ListWzskRMUsergroupUniversal& comp);
	bool operator!=(const ListWzskRMUsergroupUniversal& comp);

public:
	std::vector<WzskRMUsergroupUniversal*> nodes;
};

/**
	* TblWzskRMUsergroupUniversal: C++ wrapper for table TblWzskRMUsergroupUniversal
	*/
class TblWzskRMUsergroupUniversal {

public:

public:
	TblWzskRMUsergroupUniversal();
	virtual ~TblWzskRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskRMUsergroupUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskRMUsergroupUniversal& rst);

	virtual Sbecore::ubigint insertRec(WzskRMUsergroupUniversal* rec);
	Sbecore::ubigint insertNewRec(WzskRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskRMUsergroupUniversal& rst, WzskRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVRecaccess = 0);
	virtual void insertRst(ListWzskRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(WzskRMUsergroupUniversal* rec);
	virtual void updateRst(ListWzskRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(Sbecore::ubigint refWzskMUsergroup, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, WzskRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskRMUsergroupUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskRMUsergroupUniversal: C++ wrapper for table TblWzskRMUsergroupUniversal (MySQL database)
	*/
class MyTblWzskRMUsergroupUniversal : public TblWzskRMUsergroupUniversal, public Sbecore::MyTable {

public:
	MyTblWzskRMUsergroupUniversal();
	~MyTblWzskRMUsergroupUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WzskRMUsergroupUniversal* rec);
	void insertRst(ListWzskRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WzskRMUsergroupUniversal* rec);
	void updateRst(ListWzskRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWzskMUsergroup, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, WzskRMUsergroupUniversal** rec);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskRMUsergroupUniversal: C++ wrapper for table TblWzskRMUsergroupUniversal (SQLite database)
	*/
class LiteTblWzskRMUsergroupUniversal : public TblWzskRMUsergroupUniversal, public Sbecore::LiteTable {

public:
	LiteTblWzskRMUsergroupUniversal();
	~LiteTblWzskRMUsergroupUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsgMtbUnv;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskRMUsergroupUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WzskRMUsergroupUniversal* rec);
	void insertRst(ListWzskRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WzskRMUsergroupUniversal* rec);
	void updateRst(ListWzskRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWzskMUsergroup, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, WzskRMUsergroupUniversal** rec);
};
#endif

#endif
