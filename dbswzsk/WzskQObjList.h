/**
	* \file WzskQObjList.h
	* Dbs and XML wrapper for table TblWzskQObjList (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef WZSKQOBJLIST_H
#define WZSKQOBJLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQObjList: record of TblWzskQObjList
	*/
class WzskQObjList {

public:
	WzskQObjList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint refWzskMObjgroup = 0, const std::string stubRefWzskMObjgroup = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string Title;
	Sbecore::ubigint refWzskMObjgroup;
	std::string stubRefWzskMObjgroup;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQObjList: recordset of TblWzskQObjList
	*/
class ListWzskQObjList {

public:
	ListWzskQObjList();
	ListWzskQObjList(const ListWzskQObjList& src);
	~ListWzskQObjList();

	void clear();
	unsigned int size() const;
	void append(WzskQObjList* rec);

	ListWzskQObjList& operator=(const ListWzskQObjList& src);

public:
	std::vector<WzskQObjList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQObjList: C++ wrapper for table TblWzskQObjList
	*/
class TblWzskQObjList {

public:
	TblWzskQObjList();
	virtual ~TblWzskQObjList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQObjList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObjList& rst);

	virtual Sbecore::ubigint insertRec(WzskQObjList* rec);
	Sbecore::ubigint insertNewRec(WzskQObjList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint refWzskMObjgroup = 0, const std::string stubRefWzskMObjgroup = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQObjList& rst, WzskQObjList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string Title = "", const Sbecore::ubigint refWzskMObjgroup = 0, const std::string stubRefWzskMObjgroup = "");
	virtual void insertRst(ListWzskQObjList& rst);
	virtual void updateRec(WzskQObjList* rec);
	virtual void updateRst(ListWzskQObjList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQObjList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObjList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQObjList: C++ wrapper for table TblWzskQObjList (MySQL database)
	*/
class MyTblWzskQObjList : public TblWzskQObjList, public Sbecore::MyTable {

public:
	MyTblWzskQObjList();
	~MyTblWzskQObjList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQObjList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObjList& rst);

	Sbecore::ubigint insertRec(WzskQObjList* rec);
	void insertRst(ListWzskQObjList& rst);
	void updateRec(WzskQObjList* rec);
	void updateRst(ListWzskQObjList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQObjList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObjList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQObjList: C++ wrapper for table TblWzskQObjList (SQLite database)
	*/
class LiteTblWzskQObjList : public TblWzskQObjList, public Sbecore::LiteTable {

public:
	LiteTblWzskQObjList();
	~LiteTblWzskQObjList();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQObjList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQObjList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQObjList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQObjList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQObjList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObjList& rst);

	Sbecore::ubigint insertRec(WzskQObjList* rec);
	void insertRst(ListWzskQObjList& rst);
	void updateRec(WzskQObjList* rec);
	void updateRst(ListWzskQObjList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQObjList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObjList& rst);
};
#endif

#endif

