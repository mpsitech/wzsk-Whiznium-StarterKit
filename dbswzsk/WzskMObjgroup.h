/**
	* \file WzskMObjgroup.h
	* database access for table TblWzskMObjgroup (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKMOBJGROUP_H
#define WZSKMOBJGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskMObjgroup: record of TblWzskMObjgroup
	*/
class WzskMObjgroup {

public:
	WzskMObjgroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint supRefWzskMObjgroup = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint supRefWzskMObjgroup;
	std::string sref;
	Sbecore::ubigint refJTitle;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WzskMObjgroup& comp);
	bool operator!=(const WzskMObjgroup& comp);
};

/**
	* ListWzskMObjgroup: recordset of TblWzskMObjgroup
	*/
class ListWzskMObjgroup {

public:
	ListWzskMObjgroup();
	ListWzskMObjgroup(const ListWzskMObjgroup& src);
	~ListWzskMObjgroup();

	void clear();
	unsigned int size() const;
	void append(WzskMObjgroup* rec);

	WzskMObjgroup* operator[](const Sbecore::uint ix);
	ListWzskMObjgroup& operator=(const ListWzskMObjgroup& src);
	bool operator==(const ListWzskMObjgroup& comp);
	bool operator!=(const ListWzskMObjgroup& comp);

public:
	std::vector<WzskMObjgroup*> nodes;
};

/**
	* TblWzskMObjgroup: C++ wrapper for table TblWzskMObjgroup
	*/
class TblWzskMObjgroup {

public:

public:
	TblWzskMObjgroup();
	virtual ~TblWzskMObjgroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskMObjgroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMObjgroup& rst);

	virtual Sbecore::ubigint insertRec(WzskMObjgroup* rec);
	Sbecore::ubigint insertNewRec(WzskMObjgroup** rec = NULL, const Sbecore::ubigint supRefWzskMObjgroup = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskMObjgroup& rst, WzskMObjgroup** rec = NULL, const Sbecore::ubigint supRefWzskMObjgroup = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWzskMObjgroup& rst, bool transact = false);
	virtual void updateRec(WzskMObjgroup* rec);
	virtual void updateRst(ListWzskMObjgroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskMObjgroup** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWzskMObjgroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWzskMObjgroup, const bool append, ListWzskMObjgroup& rst);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWzskMObjgroup);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskMObjgroup& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListWzskMObjgroup& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListWzskMObjgroup& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskMObjgroup: C++ wrapper for table TblWzskMObjgroup (MySQL database)
	*/
class MyTblWzskMObjgroup : public TblWzskMObjgroup, public Sbecore::MyTable {

public:
	MyTblWzskMObjgroup();
	~MyTblWzskMObjgroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMObjgroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMObjgroup& rst);

	Sbecore::ubigint insertRec(WzskMObjgroup* rec);
	void insertRst(ListWzskMObjgroup& rst, bool transact = false);
	void updateRec(WzskMObjgroup* rec);
	void updateRst(ListWzskMObjgroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMObjgroup** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWzskMObjgroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWzskMObjgroup, const bool append, ListWzskMObjgroup& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWzskMObjgroup);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskMObjgroup: C++ wrapper for table TblWzskMObjgroup (SQLite database)
	*/
class LiteTblWzskMObjgroup : public TblWzskMObjgroup, public Sbecore::LiteTable {

public:
	LiteTblWzskMObjgroup();
	~LiteTblWzskMObjgroup();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtConfirmByRef;
	sqlite3_stmt* stmtLoadRefsBySup;
	sqlite3_stmt* stmtLoadRstBySup;
	sqlite3_stmt* stmtLoadSupByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskMObjgroup** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskMObjgroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskMObjgroup** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskMObjgroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMObjgroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMObjgroup& rst);

	Sbecore::ubigint insertRec(WzskMObjgroup* rec);
	void insertRst(ListWzskMObjgroup& rst, bool transact = false);
	void updateRec(WzskMObjgroup* rec);
	void updateRst(ListWzskMObjgroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMObjgroup** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWzskMObjgroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWzskMObjgroup, const bool append, ListWzskMObjgroup& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWzskMObjgroup);
};
#endif

#endif

