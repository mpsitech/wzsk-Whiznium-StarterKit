/**
	* \file WzskQFilList.h
	* Dbs and XML wrapper for table TblWzskQFilList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQFILLIST_H
#define WZSKQFILLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQFilList: record of TblWzskQFilList
	*/
class WzskQFilList {

public:
	WzskQFilList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Filename;
	Sbecore::uint refIxVTbl;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	Sbecore::ubigint refUref;
	std::string stubRefUref;
	std::string osrefKContent;
	std::string titOsrefKContent;
	std::string srefKMimetype;
	std::string titSrefKMimetype;
	Sbecore::usmallint Size;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQFilList: recordset of TblWzskQFilList
	*/
class ListWzskQFilList {

public:
	ListWzskQFilList();
	ListWzskQFilList(const ListWzskQFilList& src);
	~ListWzskQFilList();

	void clear();
	unsigned int size() const;
	void append(WzskQFilList* rec);

	ListWzskQFilList& operator=(const ListWzskQFilList& src);

public:
	std::vector<WzskQFilList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQFilList: C++ wrapper for table TblWzskQFilList
	*/
class TblWzskQFilList {

public:
	TblWzskQFilList();
	virtual ~TblWzskQFilList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQFilList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQFilList& rst);

	virtual Sbecore::ubigint insertRec(WzskQFilList* rec);
	Sbecore::ubigint insertNewRec(WzskQFilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskQFilList& rst, WzskQFilList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Filename = "", const Sbecore::uint refIxVTbl = 0, const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const Sbecore::ubigint refUref = 0, const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);
	virtual void insertRst(ListWzskQFilList& rst);
	virtual void updateRec(WzskQFilList* rec);
	virtual void updateRst(ListWzskQFilList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQFilList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQFilList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQFilList: C++ wrapper for table TblWzskQFilList (MySQL database)
	*/
class MyTblWzskQFilList : public TblWzskQFilList, public Sbecore::MyTable {

public:
	MyTblWzskQFilList();
	~MyTblWzskQFilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQFilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQFilList& rst);

	Sbecore::ubigint insertRec(WzskQFilList* rec);
	void insertRst(ListWzskQFilList& rst);
	void updateRec(WzskQFilList* rec);
	void updateRst(ListWzskQFilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQFilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQFilList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQFilList: C++ wrapper for table TblWzskQFilList (SQLite database)
	*/
class LiteTblWzskQFilList : public TblWzskQFilList, public Sbecore::LiteTable {

public:
	LiteTblWzskQFilList();
	~LiteTblWzskQFilList();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQFilList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQFilList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQFilList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQFilList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQFilList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQFilList& rst);

	Sbecore::ubigint insertRec(WzskQFilList* rec);
	void insertRst(ListWzskQFilList& rst);
	void updateRec(WzskQFilList* rec);
	void updateRst(ListWzskQFilList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQFilList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQFilList& rst);
};
#endif

#endif
