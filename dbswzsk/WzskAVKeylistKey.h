/**
	* \file WzskAVKeylistKey.h
	* database access for table TblWzskAVKeylistKey (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKAVKEYLISTKEY_H
#define WZSKAVKEYLISTKEY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskAVKeylistKey: record of TblWzskAVKeylistKey
	*/
class WzskAVKeylistKey {

public:
	WzskAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::uint klsIxWzskVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWzskVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint klsIxWzskVKeylist;
	Sbecore::uint klsNum;
	Sbecore::uint x1IxWzskVMaintable;
	Sbecore::ubigint x1Uref;
	bool Fixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WzskAVKeylistKey& comp);
	bool operator!=(const WzskAVKeylistKey& comp);
};

/**
	* ListWzskAVKeylistKey: recordset of TblWzskAVKeylistKey
	*/
class ListWzskAVKeylistKey {

public:
	ListWzskAVKeylistKey();
	ListWzskAVKeylistKey(const ListWzskAVKeylistKey& src);
	~ListWzskAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(WzskAVKeylistKey* rec);

	WzskAVKeylistKey* operator[](const Sbecore::uint ix);
	ListWzskAVKeylistKey& operator=(const ListWzskAVKeylistKey& src);
	bool operator==(const ListWzskAVKeylistKey& comp);
	bool operator!=(const ListWzskAVKeylistKey& comp);

public:
	std::vector<WzskAVKeylistKey*> nodes;
};

/**
	* TblWzskAVKeylistKey: C++ wrapper for table TblWzskAVKeylistKey
	*/
class TblWzskAVKeylistKey {

public:

public:
	TblWzskAVKeylistKey();
	virtual ~TblWzskAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(WzskAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(WzskAVKeylistKey** rec = NULL, const Sbecore::uint klsIxWzskVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWzskVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskAVKeylistKey& rst, WzskAVKeylistKey** rec = NULL, const Sbecore::uint klsIxWzskVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWzskVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWzskAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(WzskAVKeylistKey* rec);
	virtual void updateRst(ListWzskAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWzskVKeylist, Sbecore::uint x1IxWzskVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	virtual bool loadRefByKlsSrf(Sbecore::uint klsIxWzskVKeylist, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWzskVKeylist, const bool append, ListWzskAVKeylistKey& rst);
	virtual Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWzskVKeylist, Sbecore::uint x1IxWzskVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWzskAVKeylistKey& rst);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskAVKeylistKey: C++ wrapper for table TblWzskAVKeylistKey (MySQL database)
	*/
class MyTblWzskAVKeylistKey : public TblWzskAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblWzskAVKeylistKey();
	~MyTblWzskAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzskAVKeylistKey* rec);
	void insertRst(ListWzskAVKeylistKey& rst, bool transact = false);
	void updateRec(WzskAVKeylistKey* rec);
	void updateRst(ListWzskAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWzskVKeylist, Sbecore::uint x1IxWzskVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWzskVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWzskVKeylist, const bool append, ListWzskAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWzskVKeylist, Sbecore::uint x1IxWzskVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWzskAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskAVKeylistKey: C++ wrapper for table TblWzskAVKeylistKey (SQLite database)
	*/
class LiteTblWzskAVKeylistKey : public TblWzskAVKeylistKey, public Sbecore::LiteTable {

public:
	LiteTblWzskAVKeylistKey();
	~LiteTblWzskAVKeylistKey();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefByKlsMtbUrfSrf;
	sqlite3_stmt* stmtLoadRefByKlsSrf;
	sqlite3_stmt* stmtLoadRstByKls;
	sqlite3_stmt* stmtLoadRstByKlsMtbUrf;
	sqlite3_stmt* stmtLoadTitByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskAVKeylistKey** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskAVKeylistKey& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzskAVKeylistKey* rec);
	void insertRst(ListWzskAVKeylistKey& rst, bool transact = false);
	void updateRec(WzskAVKeylistKey* rec);
	void updateRst(ListWzskAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWzskVKeylist, Sbecore::uint x1IxWzskVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWzskVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWzskVKeylist, const bool append, ListWzskAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWzskVKeylist, Sbecore::uint x1IxWzskVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWzskAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

