/**
	* \file WzskQPrsList.h
	* Dbs and XML wrapper for table TblWzskQPrsList (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQPRSLIST_H
#define WZSKQPRSLIST_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQPrsList: record of TblWzskQPrsList
	*/
class WzskQPrsList {

public:
	WzskQPrsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	Sbecore::uint ixVSex;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQPrsList: recordset of TblWzskQPrsList
	*/
class ListWzskQPrsList {

public:
	ListWzskQPrsList();
	ListWzskQPrsList(const ListWzskQPrsList& src);
	~ListWzskQPrsList();

	void clear();
	unsigned int size() const;
	void append(WzskQPrsList* rec);

	ListWzskQPrsList& operator=(const ListWzskQPrsList& src);

public:
	std::vector<WzskQPrsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQPrsList: C++ wrapper for table TblWzskQPrsList
	*/
class TblWzskQPrsList {

public:
	TblWzskQPrsList();
	virtual ~TblWzskQPrsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQPrsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPrsList& rst);

	virtual Sbecore::ubigint insertRec(WzskQPrsList* rec);
	Sbecore::ubigint insertNewRec(WzskQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQPrsList& rst, WzskQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	virtual void insertRst(ListWzskQPrsList& rst);
	virtual void updateRec(WzskQPrsList* rec);
	virtual void updateRst(ListWzskQPrsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQPrsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPrsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQPrsList: C++ wrapper for table TblWzskQPrsList (MySQL database)
	*/
class MyTblWzskQPrsList : public TblWzskQPrsList, public Sbecore::MyTable {

public:
	MyTblWzskQPrsList();
	~MyTblWzskQPrsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPrsList& rst);

	Sbecore::ubigint insertRec(WzskQPrsList* rec);
	void insertRst(ListWzskQPrsList& rst);
	void updateRec(WzskQPrsList* rec);
	void updateRst(ListWzskQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPrsList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQPrsList: C++ wrapper for table TblWzskQPrsList (SQLite database)
	*/
class LiteTblWzskQPrsList : public TblWzskQPrsList, public Sbecore::LiteTable {

public:
	LiteTblWzskQPrsList();
	~LiteTblWzskQPrsList();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQPrsList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQPrsList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQPrsList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQPrsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPrsList& rst);

	Sbecore::ubigint insertRec(WzskQPrsList* rec);
	void insertRst(ListWzskQPrsList& rst);
	void updateRec(WzskQPrsList* rec);
	void updateRst(ListWzskQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPrsList& rst);
};
#endif

#endif

