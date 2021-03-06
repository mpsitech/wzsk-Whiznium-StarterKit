/**
	* \file WzskQPrsADetail.h
	* Dbs and XML wrapper for table TblWzskQPrsADetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQPRSADETAIL_H
#define WZSKQPRSADETAIL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQPrsADetail: record of TblWzskQPrsADetail
	*/
class WzskQPrsADetail {

public:
	WzskQPrsADetail(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQPrsADetail: recordset of TblWzskQPrsADetail
	*/
class ListWzskQPrsADetail {

public:
	ListWzskQPrsADetail();
	ListWzskQPrsADetail(const ListWzskQPrsADetail& src);
	~ListWzskQPrsADetail();

	void clear();
	unsigned int size() const;
	void append(WzskQPrsADetail* rec);

	ListWzskQPrsADetail& operator=(const ListWzskQPrsADetail& src);

public:
	std::vector<WzskQPrsADetail*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQPrsADetail: C++ wrapper for table TblWzskQPrsADetail
	*/
class TblWzskQPrsADetail {

public:
	TblWzskQPrsADetail();
	virtual ~TblWzskQPrsADetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPrsADetail& rst);

	virtual Sbecore::ubigint insertRec(WzskQPrsADetail* rec);
	Sbecore::ubigint insertNewRec(WzskQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQPrsADetail& rst, WzskQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListWzskQPrsADetail& rst);
	virtual void updateRec(WzskQPrsADetail* rec);
	virtual void updateRst(ListWzskQPrsADetail& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPrsADetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQPrsADetail: C++ wrapper for table TblWzskQPrsADetail (MySQL database)
	*/
class MyTblWzskQPrsADetail : public TblWzskQPrsADetail, public Sbecore::MyTable {

public:
	MyTblWzskQPrsADetail();
	~MyTblWzskQPrsADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPrsADetail& rst);

	Sbecore::ubigint insertRec(WzskQPrsADetail* rec);
	void insertRst(ListWzskQPrsADetail& rst);
	void updateRec(WzskQPrsADetail* rec);
	void updateRst(ListWzskQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPrsADetail& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQPrsADetail: C++ wrapper for table TblWzskQPrsADetail (SQLite database)
	*/
class LiteTblWzskQPrsADetail : public TblWzskQPrsADetail, public Sbecore::LiteTable {

public:
	LiteTblWzskQPrsADetail();
	~LiteTblWzskQPrsADetail();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQPrsADetail** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQPrsADetail& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQPrsADetail** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQPrsADetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPrsADetail& rst);

	Sbecore::ubigint insertRec(WzskQPrsADetail* rec);
	void insertRst(ListWzskQPrsADetail& rst);
	void updateRec(WzskQPrsADetail* rec);
	void updateRst(ListWzskQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPrsADetail& rst);
};
#endif

#endif
