/**
	* \file WzskQSelect.h
	* Dbs and XML wrapper for table TblWzskQSelect (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQSELECT_H
#define WZSKQSELECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQSelect: record of TblWzskQSelect
	*/
class WzskQSelect {

public:
	WzskQSelect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::uint ix;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQSelect: recordset of TblWzskQSelect
	*/
class ListWzskQSelect {

public:
	ListWzskQSelect();
	ListWzskQSelect(const ListWzskQSelect& src);
	~ListWzskQSelect();

	void clear();
	unsigned int size() const;
	void append(WzskQSelect* rec);

	ListWzskQSelect& operator=(const ListWzskQSelect& src);

public:
	std::vector<WzskQSelect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQSelect: C++ wrapper for table TblWzskQSelect
	*/
class TblWzskQSelect {

public:
	TblWzskQSelect();
	virtual ~TblWzskQSelect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQSelect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSelect& rst);

	virtual Sbecore::ubigint insertRec(WzskQSelect* rec);
	Sbecore::ubigint insertNewRec(WzskQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskQSelect& rst, WzskQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWzskQSelect& rst);
	virtual void updateRec(WzskQSelect* rec);
	virtual void updateRst(ListWzskQSelect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQSelect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSelect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQSelect: C++ wrapper for table TblWzskQSelect (MySQL database)
	*/
class MyTblWzskQSelect : public TblWzskQSelect, public Sbecore::MyTable {

public:
	MyTblWzskQSelect();
	~MyTblWzskQSelect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSelect& rst);

	Sbecore::ubigint insertRec(WzskQSelect* rec);
	void insertRst(ListWzskQSelect& rst);
	void updateRec(WzskQSelect* rec);
	void updateRst(ListWzskQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSelect& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQSelect: C++ wrapper for table TblWzskQSelect (SQLite database)
	*/
class LiteTblWzskQSelect : public TblWzskQSelect, public Sbecore::LiteTable {

public:
	LiteTblWzskQSelect();
	~LiteTblWzskQSelect();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQSelect** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQSelect& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQSelect** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQSelect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQSelect& rst);

	Sbecore::ubigint insertRec(WzskQSelect* rec);
	void insertRst(ListWzskQSelect& rst);
	void updateRec(WzskQSelect* rec);
	void updateRst(ListWzskQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQSelect& rst);
};
#endif

#endif

