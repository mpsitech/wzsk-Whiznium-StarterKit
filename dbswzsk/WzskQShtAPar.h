/**
	* \file WzskQShtAPar.h
	* Dbs and XML wrapper for table TblWzskQShtAPar (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKQSHTAPAR_H
#define WZSKQSHTAPAR_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQShtAPar: record of TblWzskQShtAPar
	*/
class WzskQShtAPar {

public:
	WzskQShtAPar(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQShtAPar: recordset of TblWzskQShtAPar
	*/
class ListWzskQShtAPar {

public:
	ListWzskQShtAPar();
	ListWzskQShtAPar(const ListWzskQShtAPar& src);
	~ListWzskQShtAPar();

	void clear();
	unsigned int size() const;
	void append(WzskQShtAPar* rec);

	ListWzskQShtAPar& operator=(const ListWzskQShtAPar& src);

public:
	std::vector<WzskQShtAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQShtAPar: C++ wrapper for table TblWzskQShtAPar
	*/
class TblWzskQShtAPar {

public:
	TblWzskQShtAPar();
	virtual ~TblWzskQShtAPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQShtAPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtAPar& rst);

	virtual Sbecore::ubigint insertRec(WzskQShtAPar* rec);
	Sbecore::ubigint insertNewRec(WzskQShtAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQShtAPar& rst, WzskQShtAPar** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWzskQShtAPar& rst);
	virtual void updateRec(WzskQShtAPar* rec);
	virtual void updateRst(ListWzskQShtAPar& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQShtAPar** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtAPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQShtAPar: C++ wrapper for table TblWzskQShtAPar (MySQL database)
	*/
class MyTblWzskQShtAPar : public TblWzskQShtAPar, public Sbecore::MyTable {

public:
	MyTblWzskQShtAPar();
	~MyTblWzskQShtAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQShtAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtAPar& rst);

	Sbecore::ubigint insertRec(WzskQShtAPar* rec);
	void insertRst(ListWzskQShtAPar& rst);
	void updateRec(WzskQShtAPar* rec);
	void updateRst(ListWzskQShtAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQShtAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtAPar& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQShtAPar: C++ wrapper for table TblWzskQShtAPar (SQLite database)
	*/
class LiteTblWzskQShtAPar : public TblWzskQShtAPar, public Sbecore::LiteTable {

public:
	LiteTblWzskQShtAPar();
	~LiteTblWzskQShtAPar();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQShtAPar** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQShtAPar& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQShtAPar** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQShtAPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQShtAPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtAPar& rst);

	Sbecore::ubigint insertRec(WzskQShtAPar* rec);
	void insertRst(ListWzskQShtAPar& rst);
	void updateRec(WzskQShtAPar* rec);
	void updateRst(ListWzskQShtAPar& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQShtAPar** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtAPar& rst);
};
#endif

#endif

