/**
	* \file WzskQPreselect.h
	* Dbs and XML wrapper for table TblWzskQPreselect (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQPRESELECT_H
#define WZSKQPRESELECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQPreselect: record of TblWzskQPreselect
	*/
class WzskQPreselect {

public:
	WzskQPreselect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQPreselect: recordset of TblWzskQPreselect
	*/
class ListWzskQPreselect {

public:
	ListWzskQPreselect();
	ListWzskQPreselect(const ListWzskQPreselect& src);
	~ListWzskQPreselect();

	void clear();
	unsigned int size() const;
	void append(WzskQPreselect* rec);

	ListWzskQPreselect& operator=(const ListWzskQPreselect& src);

public:
	std::vector<WzskQPreselect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQPreselect: C++ wrapper for table TblWzskQPreselect
	*/
class TblWzskQPreselect {

public:
	TblWzskQPreselect();
	virtual ~TblWzskQPreselect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQPreselect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPreselect& rst);

	virtual Sbecore::ubigint insertRec(WzskQPreselect* rec);
	Sbecore::ubigint insertNewRec(WzskQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskQPreselect& rst, WzskQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWzskQPreselect& rst);
	virtual void updateRec(WzskQPreselect* rec);
	virtual void updateRst(ListWzskQPreselect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQPreselect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPreselect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQPreselect: C++ wrapper for table TblWzskQPreselect (MySQL database)
	*/
class MyTblWzskQPreselect : public TblWzskQPreselect, public Sbecore::MyTable {

public:
	MyTblWzskQPreselect();
	~MyTblWzskQPreselect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPreselect& rst);

	Sbecore::ubigint insertRec(WzskQPreselect* rec);
	void insertRst(ListWzskQPreselect& rst);
	void updateRec(WzskQPreselect* rec);
	void updateRst(ListWzskQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPreselect& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQPreselect: C++ wrapper for table TblWzskQPreselect (SQLite database)
	*/
class LiteTblWzskQPreselect : public TblWzskQPreselect, public Sbecore::LiteTable {

public:
	LiteTblWzskQPreselect();
	~LiteTblWzskQPreselect();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQPreselect** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQPreselect& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQPreselect** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQPreselect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQPreselect& rst);

	Sbecore::ubigint insertRec(WzskQPreselect* rec);
	void insertRst(ListWzskQPreselect& rst);
	void updateRec(WzskQPreselect* rec);
	void updateRst(ListWzskQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQPreselect& rst);
};
#endif

#endif

