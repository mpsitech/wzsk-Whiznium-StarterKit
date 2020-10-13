/**
	* \file WzskQUsrAAccess.h
	* Dbs and XML wrapper for table TblWzskQUsrAAccess (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef WZSKQUSRAACCESS_H
#define WZSKQUSRAACCESS_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQUsrAAccess: record of TblWzskQUsrAAccess
	*/
class WzskQUsrAAccess {

public:
	WzskQUsrAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string srefX1IxWzskVFeatgroup = "", const std::string titX1IxWzskVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0, const std::string srefsIxWzskWAccess = "", const std::string titsIxWzskWAccess = "");

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
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQUsrAAccess: recordset of TblWzskQUsrAAccess
	*/
class ListWzskQUsrAAccess {

public:
	ListWzskQUsrAAccess();
	ListWzskQUsrAAccess(const ListWzskQUsrAAccess& src);
	~ListWzskQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(WzskQUsrAAccess* rec);

	ListWzskQUsrAAccess& operator=(const ListWzskQUsrAAccess& src);

public:
	std::vector<WzskQUsrAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQUsrAAccess: C++ wrapper for table TblWzskQUsrAAccess
	*/
class TblWzskQUsrAAccess {

public:
	TblWzskQUsrAAccess();
	virtual ~TblWzskQUsrAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrAAccess& rst);

	virtual Sbecore::ubigint insertRec(WzskQUsrAAccess* rec);
	Sbecore::ubigint insertNewRec(WzskQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string srefX1IxWzskVFeatgroup = "", const std::string titX1IxWzskVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0, const std::string srefsIxWzskWAccess = "", const std::string titsIxWzskWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQUsrAAccess& rst, WzskQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string srefX1IxWzskVFeatgroup = "", const std::string titX1IxWzskVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0, const std::string srefsIxWzskWAccess = "", const std::string titsIxWzskWAccess = "");
	virtual void insertRst(ListWzskQUsrAAccess& rst);
	virtual void updateRec(WzskQUsrAAccess* rec);
	virtual void updateRst(ListWzskQUsrAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQUsrAAccess: C++ wrapper for table TblWzskQUsrAAccess (MySQL database)
	*/
class MyTblWzskQUsrAAccess : public TblWzskQUsrAAccess, public Sbecore::MyTable {

public:
	MyTblWzskQUsrAAccess();
	~MyTblWzskQUsrAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WzskQUsrAAccess* rec);
	void insertRst(ListWzskQUsrAAccess& rst);
	void updateRec(WzskQUsrAAccess* rec);
	void updateRst(ListWzskQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrAAccess& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQUsrAAccess: C++ wrapper for table TblWzskQUsrAAccess (SQLite database)
	*/
class LiteTblWzskQUsrAAccess : public TblWzskQUsrAAccess, public Sbecore::LiteTable {

public:
	LiteTblWzskQUsrAAccess();
	~LiteTblWzskQUsrAAccess();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQUsrAAccess** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQUsrAAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQUsrAAccess** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQUsrAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WzskQUsrAAccess* rec);
	void insertRst(ListWzskQUsrAAccess& rst);
	void updateRec(WzskQUsrAAccess* rec);
	void updateRst(ListWzskQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQUsrAAccess& rst);
};
#endif

#endif

