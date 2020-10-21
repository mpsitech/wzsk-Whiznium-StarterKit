/**
	* \file WzskAMPersonDetail.h
	* database access for table TblWzskAMPersonDetail (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKAMPERSONDETAIL_H
#define WZSKAMPERSONDETAIL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskAMPersonDetail: record of TblWzskAMPersonDetail
	*/
class WzskAMPersonDetail {

public:
	WzskAMPersonDetail(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMPerson;
	std::string x1SrefKType;
	std::string Val;

public:
	bool operator==(const WzskAMPersonDetail& comp);
	bool operator!=(const WzskAMPersonDetail& comp);
};

/**
	* ListWzskAMPersonDetail: recordset of TblWzskAMPersonDetail
	*/
class ListWzskAMPersonDetail {

public:
	ListWzskAMPersonDetail();
	ListWzskAMPersonDetail(const ListWzskAMPersonDetail& src);
	~ListWzskAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(WzskAMPersonDetail* rec);

	WzskAMPersonDetail* operator[](const Sbecore::uint ix);
	ListWzskAMPersonDetail& operator=(const ListWzskAMPersonDetail& src);
	bool operator==(const ListWzskAMPersonDetail& comp);
	bool operator!=(const ListWzskAMPersonDetail& comp);

public:
	std::vector<WzskAMPersonDetail*> nodes;
};

/**
	* TblWzskAMPersonDetail: C++ wrapper for table TblWzskAMPersonDetail
	*/
class TblWzskAMPersonDetail {

public:

public:
	TblWzskAMPersonDetail();
	virtual ~TblWzskAMPersonDetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMPersonDetail& rst);

	virtual Sbecore::ubigint insertRec(WzskAMPersonDetail* rec);
	Sbecore::ubigint insertNewRec(WzskAMPersonDetail** rec = NULL, const Sbecore::ubigint refWzskMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskAMPersonDetail& rst, WzskAMPersonDetail** rec = NULL, const Sbecore::ubigint refWzskMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListWzskAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(WzskAMPersonDetail* rec);
	virtual void updateRst(ListWzskAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskAMPersonDetail** rec);
	virtual bool loadRecByPrsTyp(Sbecore::ubigint refWzskMPerson, std::string x1SrefKType, WzskAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzskMPerson, const bool append, ListWzskAMPersonDetail& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskAMPersonDetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskAMPersonDetail: C++ wrapper for table TblWzskAMPersonDetail (MySQL database)
	*/
class MyTblWzskAMPersonDetail : public TblWzskAMPersonDetail, public Sbecore::MyTable {

public:
	MyTblWzskAMPersonDetail();
	~MyTblWzskAMPersonDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WzskAMPersonDetail* rec);
	void insertRst(ListWzskAMPersonDetail& rst, bool transact = false);
	void updateRec(WzskAMPersonDetail* rec);
	void updateRst(ListWzskAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refWzskMPerson, std::string x1SrefKType, WzskAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzskMPerson, const bool append, ListWzskAMPersonDetail& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskAMPersonDetail: C++ wrapper for table TblWzskAMPersonDetail (SQLite database)
	*/
class LiteTblWzskAMPersonDetail : public TblWzskAMPersonDetail, public Sbecore::LiteTable {

public:
	LiteTblWzskAMPersonDetail();
	~LiteTblWzskAMPersonDetail();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByPrsTyp;
	sqlite3_stmt* stmtLoadRstByPrs;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskAMPersonDetail** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskAMPersonDetail& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskAMPersonDetail** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskAMPersonDetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WzskAMPersonDetail* rec);
	void insertRst(ListWzskAMPersonDetail& rst, bool transact = false);
	void updateRec(WzskAMPersonDetail* rec);
	void updateRst(ListWzskAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refWzskMPerson, std::string x1SrefKType, WzskAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzskMPerson, const bool append, ListWzskAMPersonDetail& rst);
};
#endif

#endif

