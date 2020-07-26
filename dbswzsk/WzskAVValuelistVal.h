/**
	* \file WzskAVValuelistVal.h
	* database access for table TblWzskAVValuelistVal (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKAVVALUELISTVAL_H
#define WZSKAVVALUELISTVAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskAVValuelistVal: record of TblWzskAVValuelistVal
	*/
class WzskAVValuelistVal {

public:
	WzskAVValuelistVal(const Sbecore::ubigint ref = 0, const Sbecore::uint vlsIxWzskVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint vlsIxWzskVValuelist;
	Sbecore::uint vlsNum;
	Sbecore::uint x1IxWzskVLocale;
	std::string Val;

public:
	bool operator==(const WzskAVValuelistVal& comp);
	bool operator!=(const WzskAVValuelistVal& comp);
};

/**
	* ListWzskAVValuelistVal: recordset of TblWzskAVValuelistVal
	*/
class ListWzskAVValuelistVal {

public:
	ListWzskAVValuelistVal();
	ListWzskAVValuelistVal(const ListWzskAVValuelistVal& src);
	~ListWzskAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(WzskAVValuelistVal* rec);

	WzskAVValuelistVal* operator[](const Sbecore::uint ix);
	ListWzskAVValuelistVal& operator=(const ListWzskAVValuelistVal& src);
	bool operator==(const ListWzskAVValuelistVal& comp);
	bool operator!=(const ListWzskAVValuelistVal& comp);

public:
	std::vector<WzskAVValuelistVal*> nodes;
};

/**
	* TblWzskAVValuelistVal: C++ wrapper for table TblWzskAVValuelistVal
	*/
class TblWzskAVValuelistVal {

public:

public:
	TblWzskAVValuelistVal();
	virtual ~TblWzskAVValuelistVal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVValuelistVal& rst);

	virtual Sbecore::ubigint insertRec(WzskAVValuelistVal* rec);
	Sbecore::ubigint insertNewRec(WzskAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxWzskVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskAVValuelistVal& rst, WzskAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxWzskVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string Val = "");
	virtual void insertRst(ListWzskAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(WzskAVValuelistVal* rec);
	virtual void updateRst(ListWzskAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWzskVValuelist, Sbecore::uint x1IxWzskVLocale, const bool append, ListWzskAVValuelistVal& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskAVValuelistVal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskAVValuelistVal: C++ wrapper for table TblWzskAVValuelistVal (MySQL database)
	*/
class MyTblWzskAVValuelistVal : public TblWzskAVValuelistVal, public Sbecore::MyTable {

public:
	MyTblWzskAVValuelistVal();
	~MyTblWzskAVValuelistVal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WzskAVValuelistVal* rec);
	void insertRst(ListWzskAVValuelistVal& rst, bool transact = false);
	void updateRec(WzskAVValuelistVal* rec);
	void updateRst(ListWzskAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWzskVValuelist, Sbecore::uint x1IxWzskVLocale, const bool append, ListWzskAVValuelistVal& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskAVValuelistVal: C++ wrapper for table TblWzskAVValuelistVal (SQLite database)
	*/
class LiteTblWzskAVValuelistVal : public TblWzskAVValuelistVal, public Sbecore::LiteTable {

public:
	LiteTblWzskAVValuelistVal();
	~LiteTblWzskAVValuelistVal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByVlsLcl;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskAVValuelistVal** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskAVValuelistVal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskAVValuelistVal** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskAVValuelistVal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WzskAVValuelistVal* rec);
	void insertRst(ListWzskAVValuelistVal& rst, bool transact = false);
	void updateRec(WzskAVValuelistVal* rec);
	void updateRst(ListWzskAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWzskVValuelist, Sbecore::uint x1IxWzskVLocale, const bool append, ListWzskAVValuelistVal& rst);
};
#endif

#endif

