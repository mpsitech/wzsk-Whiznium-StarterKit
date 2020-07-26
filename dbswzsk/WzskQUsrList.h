/**
	* \file WzskQUsrList.h
	* Dbs and XML wrapper for table TblWzskQUsrList (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQUSRLIST_H
#define WZSKQUSRLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQUsrList: record of TblWzskQUsrList
	*/
class WzskQUsrList {

public:
	WzskQUsrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWzskMPerson = 0, const std::string stubRefWzskMPerson = "", const std::string sref = "", const Sbecore::ubigint refWzskMUsergroup = 0, const std::string stubRefWzskMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWzskVLocale = 0, const std::string srefIxWzskVLocale = "", const std::string titIxWzskVLocale = "", const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint refWzskMPerson;
	std::string stubRefWzskMPerson;
	std::string sref;
	Sbecore::ubigint refWzskMUsergroup;
	std::string stubRefWzskMUsergroup;
	Sbecore::uint ixVState;
	std::string srefIxVState;
	std::string titIxVState;
	Sbecore::uint ixWzskVLocale;
	std::string srefIxWzskVLocale;
	std::string titIxWzskVLocale;
	Sbecore::uint ixWzskVUserlevel;
	std::string srefIxWzskVUserlevel;
	std::string titIxWzskVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQUsrList: recordset of TblWzskQUsrList
	*/
class ListWzskQUsrList {

public:
	ListWzskQUsrList();
	ListWzskQUsrList(const ListWzskQUsrList& src);
	~ListWzskQUsrList();

	void clear();
	unsigned int size() const;
	void append(WzskQUsrList* rec);

	ListWzskQUsrList& operator=(const ListWzskQUsrList& src);

public:
	std::vector<WzskQUsrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQUsrList: C++ wrapper for table TblWzskQUsrList
	*/
class TblWzskQUsrList {

public:
	TblWzskQUsrList();
	virtual ~TblWzskQUsrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQUsrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrList& rst);

	virtual Sbecore::ubigint insertRec(WzskQUsrList* rec);
	Sbecore::ubigint insertNewRec(WzskQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWzskMPerson = 0, const std::string stubRefWzskMPerson = "", const std::string sref = "", const Sbecore::ubigint refWzskMUsergroup = 0, const std::string stubRefWzskMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWzskVLocale = 0, const std::string srefIxWzskVLocale = "", const std::string titIxWzskVLocale = "", const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQUsrList& rst, WzskQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWzskMPerson = 0, const std::string stubRefWzskMPerson = "", const std::string sref = "", const Sbecore::ubigint refWzskMUsergroup = 0, const std::string stubRefWzskMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWzskVLocale = 0, const std::string srefIxWzskVLocale = "", const std::string titIxWzskVLocale = "", const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");
	virtual void insertRst(ListWzskQUsrList& rst);
	virtual void updateRec(WzskQUsrList* rec);
	virtual void updateRst(ListWzskQUsrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQUsrList: C++ wrapper for table TblWzskQUsrList (MySQL database)
	*/
class MyTblWzskQUsrList : public TblWzskQUsrList, public Sbecore::MyTable {

public:
	MyTblWzskQUsrList();
	~MyTblWzskQUsrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrList& rst);

	Sbecore::ubigint insertRec(WzskQUsrList* rec);
	void insertRst(ListWzskQUsrList& rst);
	void updateRec(WzskQUsrList* rec);
	void updateRst(ListWzskQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQUsrList: C++ wrapper for table TblWzskQUsrList (SQLite database)
	*/
class LiteTblWzskQUsrList : public TblWzskQUsrList, public Sbecore::LiteTable {

public:
	LiteTblWzskQUsrList();
	~LiteTblWzskQUsrList();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQUsrList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQUsrList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQUsrList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQUsrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrList& rst);

	Sbecore::ubigint insertRec(WzskQUsrList* rec);
	void insertRst(ListWzskQUsrList& rst);
	void updateRec(WzskQUsrList* rec);
	void updateRst(ListWzskQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrList& rst);
};
#endif

#endif

