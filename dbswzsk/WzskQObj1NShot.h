/**
	* \file WzskQObj1NShot.h
	* Dbs and XML wrapper for table TblWzskQObj1NShot (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQOBJ1NSHOT_H
#define WZSKQOBJ1NSHOT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQObj1NShot: record of TblWzskQObj1NShot
	*/
class WzskQObj1NShot {

public:
	WzskQObj1NShot(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQObj1NShot: recordset of TblWzskQObj1NShot
	*/
class ListWzskQObj1NShot {

public:
	ListWzskQObj1NShot();
	ListWzskQObj1NShot(const ListWzskQObj1NShot& src);
	~ListWzskQObj1NShot();

	void clear();
	unsigned int size() const;
	void append(WzskQObj1NShot* rec);

	ListWzskQObj1NShot& operator=(const ListWzskQObj1NShot& src);

public:
	std::vector<WzskQObj1NShot*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQObj1NShot: C++ wrapper for table TblWzskQObj1NShot
	*/
class TblWzskQObj1NShot {

public:
	TblWzskQObj1NShot();
	virtual ~TblWzskQObj1NShot();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQObj1NShot** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObj1NShot& rst);

	virtual Sbecore::ubigint insertRec(WzskQObj1NShot* rec);
	Sbecore::ubigint insertNewRec(WzskQObj1NShot** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQObj1NShot& rst, WzskQObj1NShot** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzskQObj1NShot& rst);
	virtual void updateRec(WzskQObj1NShot* rec);
	virtual void updateRst(ListWzskQObj1NShot& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQObj1NShot** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObj1NShot& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQObj1NShot: C++ wrapper for table TblWzskQObj1NShot (MySQL database)
	*/
class MyTblWzskQObj1NShot : public TblWzskQObj1NShot, public Sbecore::MyTable {

public:
	MyTblWzskQObj1NShot();
	~MyTblWzskQObj1NShot();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQObj1NShot** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObj1NShot& rst);

	Sbecore::ubigint insertRec(WzskQObj1NShot* rec);
	void insertRst(ListWzskQObj1NShot& rst);
	void updateRec(WzskQObj1NShot* rec);
	void updateRst(ListWzskQObj1NShot& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQObj1NShot** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObj1NShot& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQObj1NShot: C++ wrapper for table TblWzskQObj1NShot (SQLite database)
	*/
class LiteTblWzskQObj1NShot : public TblWzskQObj1NShot, public Sbecore::LiteTable {

public:
	LiteTblWzskQObj1NShot();
	~LiteTblWzskQObj1NShot();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQObj1NShot** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQObj1NShot& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQObj1NShot** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQObj1NShot& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQObj1NShot** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObj1NShot& rst);

	Sbecore::ubigint insertRec(WzskQObj1NShot* rec);
	void insertRst(ListWzskQObj1NShot& rst);
	void updateRec(WzskQObj1NShot* rec);
	void updateRst(ListWzskQObj1NShot& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQObj1NShot** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObj1NShot& rst);
};
#endif

#endif
