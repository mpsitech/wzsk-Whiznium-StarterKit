/**
	* \file WzskQUsgAAccess.h
	* Dbs and XML wrapper for table TblWzskQUsgAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef WZSKQUSGAACCESS_H
#define WZSKQUSGAACCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQUsgAAccess: record of TblWzskQUsgAAccess
	*/
class WzskQUsgAAccess {

public:
	WzskQUsgAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string srefX1IxWzskVFeatgroup = "", const std::string titX1IxWzskVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0, const std::string srefsIxWzskWAccess = "", const std::string titsIxWzskWAccess = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1IxWzskVFeatgroup;
	std::string srefX1IxWzskVFeatgroup;
	std::string titX1IxWzskVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWzskWAccess;
	std::string srefsIxWzskWAccess;
	std::string titsIxWzskWAccess;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQUsgAAccess: recordset of TblWzskQUsgAAccess
	*/
class ListWzskQUsgAAccess {

public:
	ListWzskQUsgAAccess();
	ListWzskQUsgAAccess(const ListWzskQUsgAAccess& src);
	~ListWzskQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(WzskQUsgAAccess* rec);

	ListWzskQUsgAAccess& operator=(const ListWzskQUsgAAccess& src);

public:
	std::vector<WzskQUsgAAccess*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQUsgAAccess: C++ wrapper for table TblWzskQUsgAAccess
	*/
class TblWzskQUsgAAccess {

public:
	TblWzskQUsgAAccess();
	virtual ~TblWzskQUsgAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgAAccess& rst);

	virtual Sbecore::ubigint insertRec(WzskQUsgAAccess* rec);
	Sbecore::ubigint insertNewRec(WzskQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string srefX1IxWzskVFeatgroup = "", const std::string titX1IxWzskVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0, const std::string srefsIxWzskWAccess = "", const std::string titsIxWzskWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQUsgAAccess& rst, WzskQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string srefX1IxWzskVFeatgroup = "", const std::string titX1IxWzskVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0, const std::string srefsIxWzskWAccess = "", const std::string titsIxWzskWAccess = "");
	virtual void insertRst(ListWzskQUsgAAccess& rst);
	virtual void updateRec(WzskQUsgAAccess* rec);
	virtual void updateRst(ListWzskQUsgAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQUsgAAccess: C++ wrapper for table TblWzskQUsgAAccess (MySQL database)
	*/
class MyTblWzskQUsgAAccess : public TblWzskQUsgAAccess, public Sbecore::MyTable {

public:
	MyTblWzskQUsgAAccess();
	~MyTblWzskQUsgAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WzskQUsgAAccess* rec);
	void insertRst(ListWzskQUsgAAccess& rst);
	void updateRec(WzskQUsgAAccess* rec);
	void updateRst(ListWzskQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgAAccess& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQUsgAAccess: C++ wrapper for table TblWzskQUsgAAccess (SQLite database)
	*/
class LiteTblWzskQUsgAAccess : public TblWzskQUsgAAccess, public Sbecore::LiteTable {

public:
	LiteTblWzskQUsgAAccess();
	~LiteTblWzskQUsgAAccess();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQUsgAAccess** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQUsgAAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQUsgAAccess** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQUsgAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WzskQUsgAAccess* rec);
	void insertRst(ListWzskQUsgAAccess& rst);
	void updateRec(WzskQUsgAAccess* rec);
	void updateRst(ListWzskQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsgAAccess& rst);
};
#endif

#endif
