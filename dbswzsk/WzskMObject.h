/**
	* \file WzskMObject.h
	* database access for table TblWzskMObject (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKMOBJECT_H
#define WZSKMOBJECT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskMObject: record of TblWzskMObject
	*/
class WzskMObject {

public:
	WzskMObject(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMObjgroup = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMObjgroup;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WzskMObject& comp);
	bool operator!=(const WzskMObject& comp);
};

/**
	* ListWzskMObject: recordset of TblWzskMObject
	*/
class ListWzskMObject {

public:
	ListWzskMObject();
	ListWzskMObject(const ListWzskMObject& src);
	~ListWzskMObject();

	void clear();
	unsigned int size() const;
	void append(WzskMObject* rec);

	WzskMObject* operator[](const Sbecore::uint ix);
	ListWzskMObject& operator=(const ListWzskMObject& src);
	bool operator==(const ListWzskMObject& comp);
	bool operator!=(const ListWzskMObject& comp);

public:
	std::vector<WzskMObject*> nodes;
};

/**
	* TblWzskMObject: C++ wrapper for table TblWzskMObject
	*/
class TblWzskMObject {

public:

public:
	TblWzskMObject();
	virtual ~TblWzskMObject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskMObject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMObject& rst);

	virtual Sbecore::ubigint insertRec(WzskMObject* rec);
	Sbecore::ubigint insertNewRec(WzskMObject** rec = NULL, const Sbecore::ubigint refWzskMObjgroup = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskMObject& rst, WzskMObject** rec = NULL, const Sbecore::ubigint refWzskMObjgroup = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWzskMObject& rst, bool transact = false);
	virtual void updateRec(WzskMObject* rec);
	virtual void updateRst(ListWzskMObject& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskMObject** rec);
	virtual Sbecore::ubigint loadRstByOgr(Sbecore::ubigint refWzskMObjgroup, const bool append, ListWzskMObject& rst);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskMObject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskMObject: C++ wrapper for table TblWzskMObject (MySQL database)
	*/
class MyTblWzskMObject : public TblWzskMObject, public Sbecore::MyTable {

public:
	MyTblWzskMObject();
	~MyTblWzskMObject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMObject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMObject& rst);

	Sbecore::ubigint insertRec(WzskMObject* rec);
	void insertRst(ListWzskMObject& rst, bool transact = false);
	void updateRec(WzskMObject* rec);
	void updateRst(ListWzskMObject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMObject** rec);
	Sbecore::ubigint loadRstByOgr(Sbecore::ubigint refWzskMObjgroup, const bool append, ListWzskMObject& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskMObject: C++ wrapper for table TblWzskMObject (SQLite database)
	*/
class LiteTblWzskMObject : public TblWzskMObject, public Sbecore::LiteTable {

public:
	LiteTblWzskMObject();
	~LiteTblWzskMObject();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByOgr;
	sqlite3_stmt* stmtLoadTitByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskMObject** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskMObject& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskMObject** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskMObject& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMObject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMObject& rst);

	Sbecore::ubigint insertRec(WzskMObject* rec);
	void insertRst(ListWzskMObject& rst, bool transact = false);
	void updateRec(WzskMObject* rec);
	void updateRst(ListWzskMObject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMObject** rec);
	Sbecore::ubigint loadRstByOgr(Sbecore::ubigint refWzskMObjgroup, const bool append, ListWzskMObject& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

