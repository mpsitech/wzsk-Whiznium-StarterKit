/**
	* \file WzskQSesList.h
	* Dbs and XML wrapper for table TblWzskQSesList (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKQSESLIST_H
#define WZSKQSESLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQSesList: record of TblWzskQSesList
	*/
class WzskQSesList {

public:
	WzskQSesList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const std::string stubRefWzskMUser = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "", const std::string Ip = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUser;
	std::string stubRefWzskMUser;
	Sbecore::uint start;
	std::string ftmStart;
	Sbecore::uint stop;
	std::string ftmStop;
	std::string Ip;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQSesList: recordset of TblWzskQSesList
	*/
class ListWzskQSesList {

public:
	ListWzskQSesList();
	ListWzskQSesList(const ListWzskQSesList& src);
	~ListWzskQSesList();

	void clear();
	unsigned int size() const;
	void append(WzskQSesList* rec);

	ListWzskQSesList& operator=(const ListWzskQSesList& src);

public:
	std::vector<WzskQSesList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQSesList: C++ wrapper for table TblWzskQSesList
	*/
class TblWzskQSesList {

public:
	TblWzskQSesList();
	virtual ~TblWzskQSesList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQSesList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSesList& rst);

	virtual Sbecore::ubigint insertRec(WzskQSesList* rec);
	Sbecore::ubigint insertNewRec(WzskQSesList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const std::string stubRefWzskMUser = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "", const std::string Ip = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQSesList& rst, WzskQSesList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const std::string stubRefWzskMUser = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "", const std::string Ip = "");
	virtual void insertRst(ListWzskQSesList& rst);
	virtual void updateRec(WzskQSesList* rec);
	virtual void updateRst(ListWzskQSesList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQSesList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSesList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQSesList: C++ wrapper for table TblWzskQSesList (MySQL database)
	*/
class MyTblWzskQSesList : public TblWzskQSesList, public Sbecore::MyTable {

public:
	MyTblWzskQSesList();
	~MyTblWzskQSesList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQSesList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSesList& rst);

	Sbecore::ubigint insertRec(WzskQSesList* rec);
	void insertRst(ListWzskQSesList& rst);
	void updateRec(WzskQSesList* rec);
	void updateRst(ListWzskQSesList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQSesList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSesList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQSesList: C++ wrapper for table TblWzskQSesList (SQLite database)
	*/
class LiteTblWzskQSesList : public TblWzskQSesList, public Sbecore::LiteTable {

public:
	LiteTblWzskQSesList();
	~LiteTblWzskQSesList();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQSesList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQSesList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQSesList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQSesList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQSesList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSesList& rst);

	Sbecore::ubigint insertRec(WzskQSesList* rec);
	void insertRst(ListWzskQSesList& rst);
	void updateRec(WzskQSesList* rec);
	void updateRst(ListWzskQSesList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQSesList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSesList& rst);
};
#endif

#endif

