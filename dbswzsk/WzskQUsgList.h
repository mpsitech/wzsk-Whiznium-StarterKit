/**
	* \file WzskQUsgList.h
	* Dbs and XML wrapper for table TblWzskQUsgList (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKQUSGLIST_H
#define WZSKQUSGLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQUsgList: record of TblWzskQUsgList
	*/
class WzskQUsgList {

public:
	WzskQUsgList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string sref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQUsgList: recordset of TblWzskQUsgList
	*/
class ListWzskQUsgList {

public:
	ListWzskQUsgList();
	ListWzskQUsgList(const ListWzskQUsgList& src);
	~ListWzskQUsgList();

	void clear();
	unsigned int size() const;
	void append(WzskQUsgList* rec);

	ListWzskQUsgList& operator=(const ListWzskQUsgList& src);

public:
	std::vector<WzskQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQUsgList: C++ wrapper for table TblWzskQUsgList
	*/
class TblWzskQUsgList {

public:
	TblWzskQUsgList();
	virtual ~TblWzskQUsgList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQUsgList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgList& rst);

	virtual Sbecore::ubigint insertRec(WzskQUsgList* rec);
	Sbecore::ubigint insertNewRec(WzskQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQUsgList& rst, WzskQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	virtual void insertRst(ListWzskQUsgList& rst);
	virtual void updateRec(WzskQUsgList* rec);
	virtual void updateRst(ListWzskQUsgList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQUsgList: C++ wrapper for table TblWzskQUsgList (MySQL database)
	*/
class MyTblWzskQUsgList : public TblWzskQUsgList, public Sbecore::MyTable {

public:
	MyTblWzskQUsgList();
	~MyTblWzskQUsgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgList& rst);

	Sbecore::ubigint insertRec(WzskQUsgList* rec);
	void insertRst(ListWzskQUsgList& rst);
	void updateRec(WzskQUsgList* rec);
	void updateRst(ListWzskQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQUsgList: C++ wrapper for table TblWzskQUsgList (SQLite database)
	*/
class LiteTblWzskQUsgList : public TblWzskQUsgList, public Sbecore::LiteTable {

public:
	LiteTblWzskQUsgList();
	~LiteTblWzskQUsgList();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQUsgList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQUsgList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQUsgList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQUsgList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgList& rst);

	Sbecore::ubigint insertRec(WzskQUsgList* rec);
	void insertRst(ListWzskQUsgList& rst);
	void updateRec(WzskQUsgList* rec);
	void updateRst(ListWzskQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgList& rst);
};
#endif

#endif

