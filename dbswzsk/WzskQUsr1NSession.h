/**
	* \file WzskQUsr1NSession.h
	* Dbs and XML wrapper for table TblWzskQUsr1NSession (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKQUSR1NSESSION_H
#define WZSKQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQUsr1NSession: record of TblWzskQUsr1NSession
	*/
class WzskQUsr1NSession {

public:
	WzskQUsr1NSession(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzskQUsr1NSession: recordset of TblWzskQUsr1NSession
	*/
class ListWzskQUsr1NSession {

public:
	ListWzskQUsr1NSession();
	ListWzskQUsr1NSession(const ListWzskQUsr1NSession& src);
	~ListWzskQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(WzskQUsr1NSession* rec);

	ListWzskQUsr1NSession& operator=(const ListWzskQUsr1NSession& src);

public:
	std::vector<WzskQUsr1NSession*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQUsr1NSession: C++ wrapper for table TblWzskQUsr1NSession
	*/
class TblWzskQUsr1NSession {

public:
	TblWzskQUsr1NSession();
	virtual ~TblWzskQUsr1NSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsr1NSession& rst);

	virtual Sbecore::ubigint insertRec(WzskQUsr1NSession* rec);
	Sbecore::ubigint insertNewRec(WzskQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQUsr1NSession& rst, WzskQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzskQUsr1NSession& rst);
	virtual void updateRec(WzskQUsr1NSession* rec);
	virtual void updateRst(ListWzskQUsr1NSession& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsr1NSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQUsr1NSession: C++ wrapper for table TblWzskQUsr1NSession (MySQL database)
	*/
class MyTblWzskQUsr1NSession : public TblWzskQUsr1NSession, public Sbecore::MyTable {

public:
	MyTblWzskQUsr1NSession();
	~MyTblWzskQUsr1NSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WzskQUsr1NSession* rec);
	void insertRst(ListWzskQUsr1NSession& rst);
	void updateRec(WzskQUsr1NSession* rec);
	void updateRst(ListWzskQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsr1NSession& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQUsr1NSession: C++ wrapper for table TblWzskQUsr1NSession (SQLite database)
	*/
class LiteTblWzskQUsr1NSession : public TblWzskQUsr1NSession, public Sbecore::LiteTable {

public:
	LiteTblWzskQUsr1NSession();
	~LiteTblWzskQUsr1NSession();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQUsr1NSession** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQUsr1NSession& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQUsr1NSession** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQUsr1NSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WzskQUsr1NSession* rec);
	void insertRst(ListWzskQUsr1NSession& rst);
	void updateRec(WzskQUsr1NSession* rec);
	void updateRst(ListWzskQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsr1NSession& rst);
};
#endif

#endif

