/**
	* \file WzskQSes1NShot.h
	* Dbs and XML wrapper for table TblWzskQSes1NShot (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKQSES1NSHOT_H
#define WZSKQSES1NSHOT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQSes1NShot: record of TblWzskQSes1NShot
	*/
class WzskQSes1NShot {

public:
	WzskQSes1NShot(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzskQSes1NShot: recordset of TblWzskQSes1NShot
	*/
class ListWzskQSes1NShot {

public:
	ListWzskQSes1NShot();
	ListWzskQSes1NShot(const ListWzskQSes1NShot& src);
	~ListWzskQSes1NShot();

	void clear();
	unsigned int size() const;
	void append(WzskQSes1NShot* rec);

	ListWzskQSes1NShot& operator=(const ListWzskQSes1NShot& src);

public:
	std::vector<WzskQSes1NShot*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQSes1NShot: C++ wrapper for table TblWzskQSes1NShot
	*/
class TblWzskQSes1NShot {

public:
	TblWzskQSes1NShot();
	virtual ~TblWzskQSes1NShot();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQSes1NShot** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSes1NShot& rst);

	virtual Sbecore::ubigint insertRec(WzskQSes1NShot* rec);
	Sbecore::ubigint insertNewRec(WzskQSes1NShot** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQSes1NShot& rst, WzskQSes1NShot** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzskQSes1NShot& rst);
	virtual void updateRec(WzskQSes1NShot* rec);
	virtual void updateRst(ListWzskQSes1NShot& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQSes1NShot** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSes1NShot& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQSes1NShot: C++ wrapper for table TblWzskQSes1NShot (MySQL database)
	*/
class MyTblWzskQSes1NShot : public TblWzskQSes1NShot, public Sbecore::MyTable {

public:
	MyTblWzskQSes1NShot();
	~MyTblWzskQSes1NShot();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQSes1NShot** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSes1NShot& rst);

	Sbecore::ubigint insertRec(WzskQSes1NShot* rec);
	void insertRst(ListWzskQSes1NShot& rst);
	void updateRec(WzskQSes1NShot* rec);
	void updateRst(ListWzskQSes1NShot& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQSes1NShot** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSes1NShot& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQSes1NShot: C++ wrapper for table TblWzskQSes1NShot (SQLite database)
	*/
class LiteTblWzskQSes1NShot : public TblWzskQSes1NShot, public Sbecore::LiteTable {

public:
	LiteTblWzskQSes1NShot();
	~LiteTblWzskQSes1NShot();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQSes1NShot** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQSes1NShot& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQSes1NShot** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQSes1NShot& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQSes1NShot** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSes1NShot& rst);

	Sbecore::ubigint insertRec(WzskQSes1NShot* rec);
	void insertRst(ListWzskQSes1NShot& rst);
	void updateRec(WzskQSes1NShot* rec);
	void updateRst(ListWzskQSes1NShot& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQSes1NShot** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSes1NShot& rst);
};
#endif

#endif

