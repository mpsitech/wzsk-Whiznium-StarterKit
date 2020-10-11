/**
	* \file WzskQUsrMNUsergroup.h
	* Dbs and XML wrapper for table TblWzskQUsrMNUsergroup (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef WZSKQUSRMNUSERGROUP_H
#define WZSKQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQUsrMNUsergroup: record of TblWzskQUsrMNUsergroup
	*/
class WzskQUsrMNUsergroup {

public:
	WzskQUsrMNUsergroup(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");

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
	* ListWzskQUsrMNUsergroup: recordset of TblWzskQUsrMNUsergroup
	*/
class ListWzskQUsrMNUsergroup {

public:
	ListWzskQUsrMNUsergroup();
	ListWzskQUsrMNUsergroup(const ListWzskQUsrMNUsergroup& src);
	~ListWzskQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(WzskQUsrMNUsergroup* rec);

	ListWzskQUsrMNUsergroup& operator=(const ListWzskQUsrMNUsergroup& src);

public:
	std::vector<WzskQUsrMNUsergroup*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQUsrMNUsergroup: C++ wrapper for table TblWzskQUsrMNUsergroup
	*/
class TblWzskQUsrMNUsergroup {

public:
	TblWzskQUsrMNUsergroup();
	virtual ~TblWzskQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrMNUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WzskQUsrMNUsergroup* rec);
	Sbecore::ubigint insertNewRec(WzskQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQUsrMNUsergroup& rst, WzskQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");
	virtual void insertRst(ListWzskQUsrMNUsergroup& rst);
	virtual void updateRec(WzskQUsrMNUsergroup* rec);
	virtual void updateRst(ListWzskQUsrMNUsergroup& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrMNUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQUsrMNUsergroup: C++ wrapper for table TblWzskQUsrMNUsergroup (MySQL database)
	*/
class MyTblWzskQUsrMNUsergroup : public TblWzskQUsrMNUsergroup, public Sbecore::MyTable {

public:
	MyTblWzskQUsrMNUsergroup();
	~MyTblWzskQUsrMNUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WzskQUsrMNUsergroup* rec);
	void insertRst(ListWzskQUsrMNUsergroup& rst);
	void updateRec(WzskQUsrMNUsergroup* rec);
	void updateRst(ListWzskQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrMNUsergroup& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQUsrMNUsergroup: C++ wrapper for table TblWzskQUsrMNUsergroup (SQLite database)
	*/
class LiteTblWzskQUsrMNUsergroup : public TblWzskQUsrMNUsergroup, public Sbecore::LiteTable {

public:
	LiteTblWzskQUsrMNUsergroup();
	~LiteTblWzskQUsrMNUsergroup();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQUsrMNUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WzskQUsrMNUsergroup* rec);
	void insertRst(ListWzskQUsrMNUsergroup& rst);
	void updateRec(WzskQUsrMNUsergroup* rec);
	void updateRst(ListWzskQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrMNUsergroup& rst);
};
#endif

#endif

