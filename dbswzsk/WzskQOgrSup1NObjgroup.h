/**
	* \file WzskQOgrSup1NObjgroup.h
	* Dbs and XML wrapper for table TblWzskQOgrSup1NObjgroup (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKQOGRSUP1NOBJGROUP_H
#define WZSKQOGRSUP1NOBJGROUP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQOgrSup1NObjgroup: record of TblWzskQOgrSup1NObjgroup
	*/
class WzskQOgrSup1NObjgroup {

public:
	WzskQOgrSup1NObjgroup(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzskQOgrSup1NObjgroup: recordset of TblWzskQOgrSup1NObjgroup
	*/
class ListWzskQOgrSup1NObjgroup {

public:
	ListWzskQOgrSup1NObjgroup();
	ListWzskQOgrSup1NObjgroup(const ListWzskQOgrSup1NObjgroup& src);
	~ListWzskQOgrSup1NObjgroup();

	void clear();
	unsigned int size() const;
	void append(WzskQOgrSup1NObjgroup* rec);

	ListWzskQOgrSup1NObjgroup& operator=(const ListWzskQOgrSup1NObjgroup& src);

public:
	std::vector<WzskQOgrSup1NObjgroup*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQOgrSup1NObjgroup: C++ wrapper for table TblWzskQOgrSup1NObjgroup
	*/
class TblWzskQOgrSup1NObjgroup {

public:
	TblWzskQOgrSup1NObjgroup();
	virtual ~TblWzskQOgrSup1NObjgroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQOgrSup1NObjgroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgrSup1NObjgroup& rst);

	virtual Sbecore::ubigint insertRec(WzskQOgrSup1NObjgroup* rec);
	Sbecore::ubigint insertNewRec(WzskQOgrSup1NObjgroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQOgrSup1NObjgroup& rst, WzskQOgrSup1NObjgroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzskQOgrSup1NObjgroup& rst);
	virtual void updateRec(WzskQOgrSup1NObjgroup* rec);
	virtual void updateRst(ListWzskQOgrSup1NObjgroup& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQOgrSup1NObjgroup** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgrSup1NObjgroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQOgrSup1NObjgroup: C++ wrapper for table TblWzskQOgrSup1NObjgroup (MySQL database)
	*/
class MyTblWzskQOgrSup1NObjgroup : public TblWzskQOgrSup1NObjgroup, public Sbecore::MyTable {

public:
	MyTblWzskQOgrSup1NObjgroup();
	~MyTblWzskQOgrSup1NObjgroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQOgrSup1NObjgroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgrSup1NObjgroup& rst);

	Sbecore::ubigint insertRec(WzskQOgrSup1NObjgroup* rec);
	void insertRst(ListWzskQOgrSup1NObjgroup& rst);
	void updateRec(WzskQOgrSup1NObjgroup* rec);
	void updateRst(ListWzskQOgrSup1NObjgroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQOgrSup1NObjgroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgrSup1NObjgroup& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQOgrSup1NObjgroup: C++ wrapper for table TblWzskQOgrSup1NObjgroup (SQLite database)
	*/
class LiteTblWzskQOgrSup1NObjgroup : public TblWzskQOgrSup1NObjgroup, public Sbecore::LiteTable {

public:
	LiteTblWzskQOgrSup1NObjgroup();
	~LiteTblWzskQOgrSup1NObjgroup();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQOgrSup1NObjgroup** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQOgrSup1NObjgroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQOgrSup1NObjgroup** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQOgrSup1NObjgroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQOgrSup1NObjgroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQOgrSup1NObjgroup& rst);

	Sbecore::ubigint insertRec(WzskQOgrSup1NObjgroup* rec);
	void insertRst(ListWzskQOgrSup1NObjgroup& rst);
	void updateRec(WzskQOgrSup1NObjgroup* rec);
	void updateRst(ListWzskQOgrSup1NObjgroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQOgrSup1NObjgroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQOgrSup1NObjgroup& rst);
};
#endif

#endif

