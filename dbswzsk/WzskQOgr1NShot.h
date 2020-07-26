/**
	* \file WzskQOgr1NShot.h
	* Dbs and XML wrapper for table TblWzskQOgr1NShot (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQOGR1NSHOT_H
#define WZSKQOGR1NSHOT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQOgr1NShot: record of TblWzskQOgr1NShot
	*/
class WzskQOgr1NShot {

public:
	WzskQOgr1NShot(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQOgr1NShot: recordset of TblWzskQOgr1NShot
	*/
class ListWzskQOgr1NShot {

public:
	ListWzskQOgr1NShot();
	ListWzskQOgr1NShot(const ListWzskQOgr1NShot& src);
	~ListWzskQOgr1NShot();

	void clear();
	unsigned int size() const;
	void append(WzskQOgr1NShot* rec);

	ListWzskQOgr1NShot& operator=(const ListWzskQOgr1NShot& src);

public:
	std::vector<WzskQOgr1NShot*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQOgr1NShot: C++ wrapper for table TblWzskQOgr1NShot
	*/
class TblWzskQOgr1NShot {

public:
	TblWzskQOgr1NShot();
	virtual ~TblWzskQOgr1NShot();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQOgr1NShot** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgr1NShot& rst);

	virtual Sbecore::ubigint insertRec(WzskQOgr1NShot* rec);
	Sbecore::ubigint insertNewRec(WzskQOgr1NShot** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQOgr1NShot& rst, WzskQOgr1NShot** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzskQOgr1NShot& rst);
	virtual void updateRec(WzskQOgr1NShot* rec);
	virtual void updateRst(ListWzskQOgr1NShot& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQOgr1NShot** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgr1NShot& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQOgr1NShot: C++ wrapper for table TblWzskQOgr1NShot (MySQL database)
	*/
class MyTblWzskQOgr1NShot : public TblWzskQOgr1NShot, public Sbecore::MyTable {

public:
	MyTblWzskQOgr1NShot();
	~MyTblWzskQOgr1NShot();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQOgr1NShot** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgr1NShot& rst);

	Sbecore::ubigint insertRec(WzskQOgr1NShot* rec);
	void insertRst(ListWzskQOgr1NShot& rst);
	void updateRec(WzskQOgr1NShot* rec);
	void updateRst(ListWzskQOgr1NShot& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQOgr1NShot** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgr1NShot& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQOgr1NShot: C++ wrapper for table TblWzskQOgr1NShot (SQLite database)
	*/
class LiteTblWzskQOgr1NShot : public TblWzskQOgr1NShot, public Sbecore::LiteTable {

public:
	LiteTblWzskQOgr1NShot();
	~LiteTblWzskQOgr1NShot();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQOgr1NShot** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQOgr1NShot& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQOgr1NShot** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQOgr1NShot& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQOgr1NShot** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgr1NShot& rst);

	Sbecore::ubigint insertRec(WzskQOgr1NShot* rec);
	void insertRst(ListWzskQOgr1NShot& rst);
	void updateRec(WzskQOgr1NShot* rec);
	void updateRst(ListWzskQOgr1NShot& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQOgr1NShot** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgr1NShot& rst);
};
#endif

#endif

