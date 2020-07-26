/**
	* \file WzskQUsgMNUser.h
	* Dbs and XML wrapper for table TblWzskQUsgMNUser (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQUSGMNUSER_H
#define WZSKQUSGMNUSER_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQUsgMNUser: record of TblWzskQUsgMNUser
	*/
class WzskQUsgMNUser {

public:
	WzskQUsgMNUser(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint ixWzskVUserlevel;
	std::string srefIxWzskVUserlevel;
	std::string titIxWzskVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQUsgMNUser: recordset of TblWzskQUsgMNUser
	*/
class ListWzskQUsgMNUser {

public:
	ListWzskQUsgMNUser();
	ListWzskQUsgMNUser(const ListWzskQUsgMNUser& src);
	~ListWzskQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(WzskQUsgMNUser* rec);

	ListWzskQUsgMNUser& operator=(const ListWzskQUsgMNUser& src);

public:
	std::vector<WzskQUsgMNUser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQUsgMNUser: C++ wrapper for table TblWzskQUsgMNUser
	*/
class TblWzskQUsgMNUser {

public:
	TblWzskQUsgMNUser();
	virtual ~TblWzskQUsgMNUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgMNUser& rst);

	virtual Sbecore::ubigint insertRec(WzskQUsgMNUser* rec);
	Sbecore::ubigint insertNewRec(WzskQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQUsgMNUser& rst, WzskQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");
	virtual void insertRst(ListWzskQUsgMNUser& rst);
	virtual void updateRec(WzskQUsgMNUser* rec);
	virtual void updateRst(ListWzskQUsgMNUser& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgMNUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQUsgMNUser: C++ wrapper for table TblWzskQUsgMNUser (MySQL database)
	*/
class MyTblWzskQUsgMNUser : public TblWzskQUsgMNUser, public Sbecore::MyTable {

public:
	MyTblWzskQUsgMNUser();
	~MyTblWzskQUsgMNUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WzskQUsgMNUser* rec);
	void insertRst(ListWzskQUsgMNUser& rst);
	void updateRec(WzskQUsgMNUser* rec);
	void updateRst(ListWzskQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgMNUser& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQUsgMNUser: C++ wrapper for table TblWzskQUsgMNUser (SQLite database)
	*/
class LiteTblWzskQUsgMNUser : public TblWzskQUsgMNUser, public Sbecore::LiteTable {

public:
	LiteTblWzskQUsgMNUser();
	~LiteTblWzskQUsgMNUser();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQUsgMNUser** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQUsgMNUser& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQUsgMNUser** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQUsgMNUser& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WzskQUsgMNUser* rec);
	void insertRst(ListWzskQUsgMNUser& rst);
	void updateRec(WzskQUsgMNUser* rec);
	void updateRst(ListWzskQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgMNUser& rst);
};
#endif

#endif

