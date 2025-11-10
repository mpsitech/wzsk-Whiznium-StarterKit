/**
	* \file WzskJMPersonLastname.h
	* database access for table TblWzskJMPersonLastname (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef WZSKJMPERSONLASTNAME_H
#define WZSKJMPERSONLASTNAME_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskJMPersonLastname: record of TblWzskJMPersonLastname
	*/
class WzskJMPersonLastname {

public:
	WzskJMPersonLastname(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMPerson;
	Sbecore::uint x1Startd;
	std::string Lastname;

public:
	bool operator==(const WzskJMPersonLastname& comp);
	bool operator!=(const WzskJMPersonLastname& comp);
};

/**
	* ListWzskJMPersonLastname: recordset of TblWzskJMPersonLastname
	*/
class ListWzskJMPersonLastname {

public:
	ListWzskJMPersonLastname();
	ListWzskJMPersonLastname(const ListWzskJMPersonLastname& src);
	~ListWzskJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(WzskJMPersonLastname* rec);

	WzskJMPersonLastname* operator[](const Sbecore::uint ix);
	ListWzskJMPersonLastname& operator=(const ListWzskJMPersonLastname& src);
	bool operator==(const ListWzskJMPersonLastname& comp);
	bool operator!=(const ListWzskJMPersonLastname& comp);

public:
	std::vector<WzskJMPersonLastname*> nodes;
};

/**
	* TblWzskJMPersonLastname: C++ wrapper for table TblWzskJMPersonLastname
	*/
class TblWzskJMPersonLastname {

public:

public:
	TblWzskJMPersonLastname();
	virtual ~TblWzskJMPersonLastname();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMPersonLastname& rst);

	virtual Sbecore::ubigint insertRec(WzskJMPersonLastname* rec);
	Sbecore::ubigint insertNewRec(WzskJMPersonLastname** rec = NULL, const Sbecore::ubigint refWzskMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskJMPersonLastname& rst, WzskJMPersonLastname** rec = NULL, const Sbecore::ubigint refWzskMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	virtual void insertRst(ListWzskJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(WzskJMPersonLastname* rec);
	virtual void updateRst(ListWzskJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskJMPersonLastname** rec);
	virtual bool loadRecByPrsSta(Sbecore::ubigint refWzskMPerson, Sbecore::uint x1Startd, WzskJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWzskMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzskMPerson, const bool append, ListWzskJMPersonLastname& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskJMPersonLastname& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskJMPersonLastname: C++ wrapper for table TblWzskJMPersonLastname (MySQL database)
	*/
class MyTblWzskJMPersonLastname : public TblWzskJMPersonLastname, public Sbecore::MyTable {

public:
	MyTblWzskJMPersonLastname();
	~MyTblWzskJMPersonLastname();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WzskJMPersonLastname* rec);
	void insertRst(ListWzskJMPersonLastname& rst, bool transact = false);
	void updateRec(WzskJMPersonLastname* rec);
	void updateRst(ListWzskJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskJMPersonLastname** rec);
	bool loadRecByPrsSta(Sbecore::ubigint refWzskMPerson, Sbecore::uint x1Startd, WzskJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWzskMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzskMPerson, const bool append, ListWzskJMPersonLastname& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskJMPersonLastname: C++ wrapper for table TblWzskJMPersonLastname (SQLite database)
	*/
class LiteTblWzskJMPersonLastname : public TblWzskJMPersonLastname, public Sbecore::LiteTable {

public:
	LiteTblWzskJMPersonLastname();
	~LiteTblWzskJMPersonLastname();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByPrsSta;
	sqlite3_stmt* stmtLoadRefsByPrs;
	sqlite3_stmt* stmtLoadRstByPrs;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskJMPersonLastname** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskJMPersonLastname& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskJMPersonLastname** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskJMPersonLastname& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WzskJMPersonLastname* rec);
	void insertRst(ListWzskJMPersonLastname& rst, bool transact = false);
	void updateRec(WzskJMPersonLastname* rec);
	void updateRst(ListWzskJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskJMPersonLastname** rec);
	bool loadRecByPrsSta(Sbecore::ubigint refWzskMPerson, Sbecore::uint x1Startd, WzskJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWzskMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzskMPerson, const bool append, ListWzskJMPersonLastname& rst);
};
#endif

#endif
