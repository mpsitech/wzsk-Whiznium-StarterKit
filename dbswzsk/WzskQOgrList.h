/**
	* \file WzskQOgrList.h
	* Dbs and XML wrapper for table TblWzskQOgrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQOGRLIST_H
#define WZSKQOGRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQOgrList: record of TblWzskQOgrList
	*/
class WzskQOgrList {

public:
	WzskQOgrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint supRefWzskMObjgroup = 0, const std::string stubSupRefWzskMObjgroup = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	Sbecore::ubigint supRefWzskMObjgroup;
	std::string stubSupRefWzskMObjgroup;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQOgrList: recordset of TblWzskQOgrList
	*/
class ListWzskQOgrList {

public:
	ListWzskQOgrList();
	ListWzskQOgrList(const ListWzskQOgrList& src);
	~ListWzskQOgrList();

	void clear();
	unsigned int size() const;
	void append(WzskQOgrList* rec);

	ListWzskQOgrList& operator=(const ListWzskQOgrList& src);

public:
	std::vector<WzskQOgrList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQOgrList: C++ wrapper for table TblWzskQOgrList
	*/
class TblWzskQOgrList {

public:
	TblWzskQOgrList();
	virtual ~TblWzskQOgrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQOgrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgrList& rst);

	virtual Sbecore::ubigint insertRec(WzskQOgrList* rec);
	Sbecore::ubigint insertNewRec(WzskQOgrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint supRefWzskMObjgroup = 0, const std::string stubSupRefWzskMObjgroup = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQOgrList& rst, WzskQOgrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const Sbecore::ubigint supRefWzskMObjgroup = 0, const std::string stubSupRefWzskMObjgroup = "");
	virtual void insertRst(ListWzskQOgrList& rst);
	virtual void updateRec(WzskQOgrList* rec);
	virtual void updateRst(ListWzskQOgrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQOgrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQOgrList: C++ wrapper for table TblWzskQOgrList (MySQL database)
	*/
class MyTblWzskQOgrList : public TblWzskQOgrList, public Sbecore::MyTable {

public:
	MyTblWzskQOgrList();
	~MyTblWzskQOgrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQOgrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgrList& rst);

	Sbecore::ubigint insertRec(WzskQOgrList* rec);
	void insertRst(ListWzskQOgrList& rst);
	void updateRec(WzskQOgrList* rec);
	void updateRst(ListWzskQOgrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQOgrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgrList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQOgrList: C++ wrapper for table TblWzskQOgrList (SQLite database)
	*/
class LiteTblWzskQOgrList : public TblWzskQOgrList, public Sbecore::LiteTable {

public:
	LiteTblWzskQOgrList();
	~LiteTblWzskQOgrList();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQOgrList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQOgrList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQOgrList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQOgrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQOgrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgrList& rst);

	Sbecore::ubigint insertRec(WzskQOgrList* rec);
	void insertRst(ListWzskQOgrList& rst);
	void updateRec(WzskQOgrList* rec);
	void updateRst(ListWzskQOgrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQOgrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgrList& rst);
};
#endif

#endif
