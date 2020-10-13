/**
	* \file WzskQOgr1NObject.h
	* Dbs and XML wrapper for table TblWzskQOgr1NObject (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef WZSKQOGR1NOBJECT_H
#define WZSKQOGR1NOBJECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQOgr1NObject: record of TblWzskQOgr1NObject
	*/
class WzskQOgr1NObject {

public:
	WzskQOgr1NObject(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzskQOgr1NObject: recordset of TblWzskQOgr1NObject
	*/
class ListWzskQOgr1NObject {

public:
	ListWzskQOgr1NObject();
	ListWzskQOgr1NObject(const ListWzskQOgr1NObject& src);
	~ListWzskQOgr1NObject();

	void clear();
	unsigned int size() const;
	void append(WzskQOgr1NObject* rec);

	ListWzskQOgr1NObject& operator=(const ListWzskQOgr1NObject& src);

public:
	std::vector<WzskQOgr1NObject*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQOgr1NObject: C++ wrapper for table TblWzskQOgr1NObject
	*/
class TblWzskQOgr1NObject {

public:
	TblWzskQOgr1NObject();
	virtual ~TblWzskQOgr1NObject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQOgr1NObject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgr1NObject& rst);

	virtual Sbecore::ubigint insertRec(WzskQOgr1NObject* rec);
	Sbecore::ubigint insertNewRec(WzskQOgr1NObject** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQOgr1NObject& rst, WzskQOgr1NObject** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzskQOgr1NObject& rst);
	virtual void updateRec(WzskQOgr1NObject* rec);
	virtual void updateRst(ListWzskQOgr1NObject& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQOgr1NObject** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgr1NObject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQOgr1NObject: C++ wrapper for table TblWzskQOgr1NObject (MySQL database)
	*/
class MyTblWzskQOgr1NObject : public TblWzskQOgr1NObject, public Sbecore::MyTable {

public:
	MyTblWzskQOgr1NObject();
	~MyTblWzskQOgr1NObject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQOgr1NObject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgr1NObject& rst);

	Sbecore::ubigint insertRec(WzskQOgr1NObject* rec);
	void insertRst(ListWzskQOgr1NObject& rst);
	void updateRec(WzskQOgr1NObject* rec);
	void updateRst(ListWzskQOgr1NObject& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQOgr1NObject** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgr1NObject& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQOgr1NObject: C++ wrapper for table TblWzskQOgr1NObject (SQLite database)
	*/
class LiteTblWzskQOgr1NObject : public TblWzskQOgr1NObject, public Sbecore::LiteTable {

public:
	LiteTblWzskQOgr1NObject();
	~LiteTblWzskQOgr1NObject();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQOgr1NObject** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQOgr1NObject& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQOgr1NObject** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQOgr1NObject& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQOgr1NObject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgr1NObject& rst);

	Sbecore::ubigint insertRec(WzskQOgr1NObject* rec);
	void insertRst(ListWzskQOgr1NObject& rst);
	void updateRec(WzskQOgr1NObject* rec);
	void updateRst(ListWzskQOgr1NObject& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQOgr1NObject** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgr1NObject& rst);
};
#endif

#endif

