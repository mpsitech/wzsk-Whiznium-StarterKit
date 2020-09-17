/**
	* \file WzskAccRMUserUniversal.h
	* database access for table TblWzskAccRMUserUniversal (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKACCRMUSERUNIVERSAL_H
#define WZSKACCRMUSERUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskAccRMUserUniversal: record of TblWzskAccRMUserUniversal
	*/
class WzskAccRMUserUniversal {

public:
	WzskAccRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUser;
	Sbecore::uint unvIxWzskVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWzskVRecaccess;

public:
	bool operator==(const WzskAccRMUserUniversal& comp);
	bool operator!=(const WzskAccRMUserUniversal& comp);
};

/**
	* ListWzskAccRMUserUniversal: recordset of TblWzskAccRMUserUniversal
	*/
class ListWzskAccRMUserUniversal {

public:
	ListWzskAccRMUserUniversal();
	ListWzskAccRMUserUniversal(const ListWzskAccRMUserUniversal& src);
	~ListWzskAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(WzskAccRMUserUniversal* rec);

	WzskAccRMUserUniversal* operator[](const Sbecore::uint ix);
	ListWzskAccRMUserUniversal& operator=(const ListWzskAccRMUserUniversal& src);
	bool operator==(const ListWzskAccRMUserUniversal& comp);
	bool operator!=(const ListWzskAccRMUserUniversal& comp);

public:
	std::vector<WzskAccRMUserUniversal*> nodes;
};

/**
	* TblWzskAccRMUserUniversal: C++ wrapper for table TblWzskAccRMUserUniversal
	*/
class TblWzskAccRMUserUniversal {

public:

public:
	TblWzskAccRMUserUniversal();
	virtual ~TblWzskAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskAccRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAccRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(WzskAccRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(WzskAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskAccRMUserUniversal& rst, WzskAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVRecaccess = 0);
	virtual void insertRst(ListWzskAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(WzskAccRMUserUniversal* rec);
	virtual void updateRst(ListWzskAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, WzskAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskAccRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskAccRMUserUniversal: C++ wrapper for table TblWzskAccRMUserUniversal (MySQL database)
	*/
class MyTblWzskAccRMUserUniversal : public TblWzskAccRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblWzskAccRMUserUniversal();
	~MyTblWzskAccRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzskAccRMUserUniversal* rec);
	void insertRst(ListWzskAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WzskAccRMUserUniversal* rec);
	void updateRst(ListWzskAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, WzskAccRMUserUniversal** rec);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskAccRMUserUniversal: C++ wrapper for table TblWzskAccRMUserUniversal (SQLite database)
	*/
class LiteTblWzskAccRMUserUniversal : public TblWzskAccRMUserUniversal, public Sbecore::LiteTable {

public:
	LiteTblWzskAccRMUserUniversal();
	~LiteTblWzskAccRMUserUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsrMtbUnv;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskAccRMUserUniversal** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskAccRMUserUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzskAccRMUserUniversal* rec);
	void insertRst(ListWzskAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WzskAccRMUserUniversal* rec);
	void updateRst(ListWzskAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, WzskAccRMUserUniversal** rec);
};
#endif

#endif

