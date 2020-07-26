/**
	* \file WzskJAVKeylistKey.h
	* database access for table TblWzskJAVKeylistKey (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKJAVKEYLISTKEY_H
#define WZSKJAVKEYLISTKEY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskJAVKeylistKey: record of TblWzskJAVKeylistKey
	*/
class WzskJAVKeylistKey {

public:
	WzskJAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskAVKeylistKey = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskAVKeylistKey;
	Sbecore::uint x1IxWzskVLocale;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WzskJAVKeylistKey& comp);
	bool operator!=(const WzskJAVKeylistKey& comp);
};

/**
	* ListWzskJAVKeylistKey: recordset of TblWzskJAVKeylistKey
	*/
class ListWzskJAVKeylistKey {

public:
	ListWzskJAVKeylistKey();
	ListWzskJAVKeylistKey(const ListWzskJAVKeylistKey& src);
	~ListWzskJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(WzskJAVKeylistKey* rec);

	WzskJAVKeylistKey* operator[](const Sbecore::uint ix);
	ListWzskJAVKeylistKey& operator=(const ListWzskJAVKeylistKey& src);
	bool operator==(const ListWzskJAVKeylistKey& comp);
	bool operator!=(const ListWzskJAVKeylistKey& comp);

public:
	std::vector<WzskJAVKeylistKey*> nodes;
};

/**
	* TblWzskJAVKeylistKey: C++ wrapper for table TblWzskJAVKeylistKey
	*/
class TblWzskJAVKeylistKey {

public:

public:
	TblWzskJAVKeylistKey();
	virtual ~TblWzskJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(WzskJAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(WzskJAVKeylistKey** rec = NULL, const Sbecore::ubigint refWzskAVKeylistKey = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskJAVKeylistKey& rst, WzskJAVKeylistKey** rec = NULL, const Sbecore::ubigint refWzskAVKeylistKey = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWzskJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(WzskJAVKeylistKey* rec);
	virtual void updateRst(ListWzskJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(Sbecore::ubigint refWzskAVKeylistKey, Sbecore::uint x1IxWzskVLocale, WzskJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWzskAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWzskAVKeylistKey, const bool append, ListWzskJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(Sbecore::ubigint refWzskAVKeylistKey, Sbecore::uint x1IxWzskVLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskJAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskJAVKeylistKey: C++ wrapper for table TblWzskJAVKeylistKey (MySQL database)
	*/
class MyTblWzskJAVKeylistKey : public TblWzskJAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblWzskJAVKeylistKey();
	~MyTblWzskJAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzskJAVKeylistKey* rec);
	void insertRst(ListWzskJAVKeylistKey& rst, bool transact = false);
	void updateRec(WzskJAVKeylistKey* rec);
	void updateRst(ListWzskJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWzskAVKeylistKey, Sbecore::uint x1IxWzskVLocale, WzskJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWzskAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWzskAVKeylistKey, const bool append, ListWzskJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWzskAVKeylistKey, Sbecore::uint x1IxWzskVLocale, std::string& Title);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskJAVKeylistKey: C++ wrapper for table TblWzskJAVKeylistKey (SQLite database)
	*/
class LiteTblWzskJAVKeylistKey : public TblWzskJAVKeylistKey, public Sbecore::LiteTable {

public:
	LiteTblWzskJAVKeylistKey();
	~LiteTblWzskJAVKeylistKey();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByKlkLcl;
	sqlite3_stmt* stmtLoadRefsByKlk;
	sqlite3_stmt* stmtLoadRstByKlk;
	sqlite3_stmt* stmtLoadTitByKlkLcl;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskJAVKeylistKey** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskJAVKeylistKey& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskJAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskJAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzskJAVKeylistKey* rec);
	void insertRst(ListWzskJAVKeylistKey& rst, bool transact = false);
	void updateRec(WzskJAVKeylistKey* rec);
	void updateRst(ListWzskJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWzskAVKeylistKey, Sbecore::uint x1IxWzskVLocale, WzskJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWzskAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWzskAVKeylistKey, const bool append, ListWzskJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWzskAVKeylistKey, Sbecore::uint x1IxWzskVLocale, std::string& Title);
};
#endif

#endif

