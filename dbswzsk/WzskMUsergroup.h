/**
	* \file WzskMUsergroup.h
	* database access for table TblWzskMUsergroup (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef WZSKMUSERGROUP_H
#define WZSKMUSERGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskMUsergroup: record of TblWzskMUsergroup
	*/
class WzskMUsergroup {

public:
	WzskMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WzskMUsergroup& comp);
	bool operator!=(const WzskMUsergroup& comp);
};

/**
	* ListWzskMUsergroup: recordset of TblWzskMUsergroup
	*/
class ListWzskMUsergroup {

public:
	ListWzskMUsergroup();
	ListWzskMUsergroup(const ListWzskMUsergroup& src);
	~ListWzskMUsergroup();

	void clear();
	unsigned int size() const;
	void append(WzskMUsergroup* rec);

	WzskMUsergroup* operator[](const Sbecore::uint ix);
	ListWzskMUsergroup& operator=(const ListWzskMUsergroup& src);
	bool operator==(const ListWzskMUsergroup& comp);
	bool operator!=(const ListWzskMUsergroup& comp);

public:
	std::vector<WzskMUsergroup*> nodes;
};

/**
	* TblWzskMUsergroup: C++ wrapper for table TblWzskMUsergroup
	*/
class TblWzskMUsergroup {

public:

public:
	TblWzskMUsergroup();
	virtual ~TblWzskMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WzskMUsergroup* rec);
	Sbecore::ubigint insertNewRec(WzskMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskMUsergroup& rst, WzskMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWzskMUsergroup& rst, bool transact = false);
	virtual void updateRec(WzskMUsergroup* rec);
	virtual void updateRst(ListWzskMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskMUsergroup** rec);
	virtual bool loadRecBySrf(std::string sref, WzskMUsergroup** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskMUsergroup: C++ wrapper for table TblWzskMUsergroup (MySQL database)
	*/
class MyTblWzskMUsergroup : public TblWzskMUsergroup, public Sbecore::MyTable {

public:
	MyTblWzskMUsergroup();
	~MyTblWzskMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMUsergroup& rst);

	Sbecore::ubigint insertRec(WzskMUsergroup* rec);
	void insertRst(ListWzskMUsergroup& rst, bool transact = false);
	void updateRec(WzskMUsergroup* rec);
	void updateRst(ListWzskMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMUsergroup** rec);
	bool loadRecBySrf(std::string sref, WzskMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskMUsergroup: C++ wrapper for table TblWzskMUsergroup (SQLite database)
	*/
class LiteTblWzskMUsergroup : public TblWzskMUsergroup, public Sbecore::LiteTable {

public:
	LiteTblWzskMUsergroup();
	~LiteTblWzskMUsergroup();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecBySrf;
	sqlite3_stmt* stmtLoadRefBySrf;
	sqlite3_stmt* stmtLoadSrfByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskMUsergroup** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskMUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskMUsergroup** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMUsergroup& rst);

	Sbecore::ubigint insertRec(WzskMUsergroup* rec);
	void insertRst(ListWzskMUsergroup& rst, bool transact = false);
	void updateRec(WzskMUsergroup* rec);
	void updateRst(ListWzskMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMUsergroup** rec);
	bool loadRecBySrf(std::string sref, WzskMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

