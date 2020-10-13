/**
	* \file WzskQShtList.h
	* Dbs and XML wrapper for table TblWzskQShtList (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef WZSKQSHTLIST_H
#define WZSKQSHTLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQShtList: record of TblWzskQShtList
	*/
class WzskQShtList {

public:
	WzskQShtList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMSession = 0, const std::string stubRefWzskMSession = "", const Sbecore::ubigint refWzskMObject = 0, const std::string stubRefWzskMObject = "", const Sbecore::uint start = 0, const std::string ftmStart = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMSession;
	std::string stubRefWzskMSession;
	Sbecore::ubigint refWzskMObject;
	std::string stubRefWzskMObject;
	Sbecore::uint start;
	std::string ftmStart;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQShtList: recordset of TblWzskQShtList
	*/
class ListWzskQShtList {

public:
	ListWzskQShtList();
	ListWzskQShtList(const ListWzskQShtList& src);
	~ListWzskQShtList();

	void clear();
	unsigned int size() const;
	void append(WzskQShtList* rec);

	ListWzskQShtList& operator=(const ListWzskQShtList& src);

public:
	std::vector<WzskQShtList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQShtList: C++ wrapper for table TblWzskQShtList
	*/
class TblWzskQShtList {

public:
	TblWzskQShtList();
	virtual ~TblWzskQShtList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQShtList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtList& rst);

	virtual Sbecore::ubigint insertRec(WzskQShtList* rec);
	Sbecore::ubigint insertNewRec(WzskQShtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMSession = 0, const std::string stubRefWzskMSession = "", const Sbecore::ubigint refWzskMObject = 0, const std::string stubRefWzskMObject = "", const Sbecore::uint start = 0, const std::string ftmStart = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQShtList& rst, WzskQShtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMSession = 0, const std::string stubRefWzskMSession = "", const Sbecore::ubigint refWzskMObject = 0, const std::string stubRefWzskMObject = "", const Sbecore::uint start = 0, const std::string ftmStart = "");
	virtual void insertRst(ListWzskQShtList& rst);
	virtual void updateRec(WzskQShtList* rec);
	virtual void updateRst(ListWzskQShtList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQShtList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQShtList: C++ wrapper for table TblWzskQShtList (MySQL database)
	*/
class MyTblWzskQShtList : public TblWzskQShtList, public Sbecore::MyTable {

public:
	MyTblWzskQShtList();
	~MyTblWzskQShtList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQShtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtList& rst);

	Sbecore::ubigint insertRec(WzskQShtList* rec);
	void insertRst(ListWzskQShtList& rst);
	void updateRec(WzskQShtList* rec);
	void updateRst(ListWzskQShtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQShtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQShtList: C++ wrapper for table TblWzskQShtList (SQLite database)
	*/
class LiteTblWzskQShtList : public TblWzskQShtList, public Sbecore::LiteTable {

public:
	LiteTblWzskQShtList();
	~LiteTblWzskQShtList();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByQref;
	sqlite3_stmt* stmtRemoveRstByJref;

	sqlite3_stmt* stmtLoadRecByQref;
	sqlite3_stmt* stmtLoadRecByJref;
	sqlite3_stmt* stmtLoadRstByJref;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskQShtList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQShtList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQShtList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQShtList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQShtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtList& rst);

	Sbecore::ubigint insertRec(WzskQShtList* rec);
	void insertRst(ListWzskQShtList& rst);
	void updateRec(WzskQShtList* rec);
	void updateRst(ListWzskQShtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQShtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtList& rst);
};
#endif

#endif

