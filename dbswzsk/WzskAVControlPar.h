/**
	* \file WzskAVControlPar.h
	* database access for table TblWzskAVControlPar (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef WZSKAVCONTROLPAR_H
#define WZSKAVCONTROLPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskAVControlPar: record of TblWzskAVControlPar
	*/
class WzskAVControlPar {

public:
	WzskAVControlPar(const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzskVControl = 0, const Sbecore::ubigint x1RefWzskMUser = 0, const Sbecore::uint x2IxWzskVLocale = 0, const std::string Par = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixWzskVControl;
	Sbecore::ubigint x1RefWzskMUser;
	Sbecore::uint x2IxWzskVLocale;
	std::string Par;
	std::string Val;

public:
	bool operator==(const WzskAVControlPar& comp);
	bool operator!=(const WzskAVControlPar& comp);
};

/**
	* ListWzskAVControlPar: recordset of TblWzskAVControlPar
	*/
class ListWzskAVControlPar {

public:
	ListWzskAVControlPar();
	ListWzskAVControlPar(const ListWzskAVControlPar& src);
	~ListWzskAVControlPar();

	void clear();
	unsigned int size() const;
	void append(WzskAVControlPar* rec);

	WzskAVControlPar* operator[](const Sbecore::uint ix);
	ListWzskAVControlPar& operator=(const ListWzskAVControlPar& src);
	bool operator==(const ListWzskAVControlPar& comp);
	bool operator!=(const ListWzskAVControlPar& comp);

public:
	std::vector<WzskAVControlPar*> nodes;
};

/**
	* TblWzskAVControlPar: C++ wrapper for table TblWzskAVControlPar
	*/
class TblWzskAVControlPar {

public:

public:
	TblWzskAVControlPar();
	virtual ~TblWzskAVControlPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskAVControlPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVControlPar& rst);

	virtual Sbecore::ubigint insertRec(WzskAVControlPar* rec);
	Sbecore::ubigint insertNewRec(WzskAVControlPar** rec = NULL, const Sbecore::uint ixWzskVControl = 0, const Sbecore::ubigint x1RefWzskMUser = 0, const Sbecore::uint x2IxWzskVLocale = 0, const std::string Par = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskAVControlPar& rst, WzskAVControlPar** rec = NULL, const Sbecore::uint ixWzskVControl = 0, const Sbecore::ubigint x1RefWzskMUser = 0, const Sbecore::uint x2IxWzskVLocale = 0, const std::string Par = "", const std::string Val = "");
	virtual void insertRst(ListWzskAVControlPar& rst, bool transact = false);
	virtual void updateRec(WzskAVControlPar* rec);
	virtual void updateRst(ListWzskAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskAVControlPar** rec);
	virtual bool loadRefByCtlUsrPar(Sbecore::uint ixWzskVControl, Sbecore::ubigint x1RefWzskMUser, std::string Par, Sbecore::ubigint& ref);
	virtual bool loadValByCtlUsrPar(Sbecore::uint ixWzskVControl, Sbecore::ubigint x1RefWzskMUser, std::string Par, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskAVControlPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskAVControlPar: C++ wrapper for table TblWzskAVControlPar (MySQL database)
	*/
class MyTblWzskAVControlPar : public TblWzskAVControlPar, public Sbecore::MyTable {

public:
	MyTblWzskAVControlPar();
	~MyTblWzskAVControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVControlPar& rst);

	Sbecore::ubigint insertRec(WzskAVControlPar* rec);
	void insertRst(ListWzskAVControlPar& rst, bool transact = false);
	void updateRec(WzskAVControlPar* rec);
	void updateRst(ListWzskAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixWzskVControl, Sbecore::ubigint x1RefWzskMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixWzskVControl, Sbecore::ubigint x1RefWzskMUser, std::string Par, std::string& Val);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskAVControlPar: C++ wrapper for table TblWzskAVControlPar (SQLite database)
	*/
class LiteTblWzskAVControlPar : public TblWzskAVControlPar, public Sbecore::LiteTable {

public:
	LiteTblWzskAVControlPar();
	~LiteTblWzskAVControlPar();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefByCtlUsrPar;
	sqlite3_stmt* stmtLoadValByCtlUsrPar;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskAVControlPar** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskAVControlPar& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskAVControlPar** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskAVControlPar& rst);

	Sbecore::ubigint insertRec(WzskAVControlPar* rec);
	void insertRst(ListWzskAVControlPar& rst, bool transact = false);
	void updateRec(WzskAVControlPar* rec);
	void updateRst(ListWzskAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixWzskVControl, Sbecore::ubigint x1RefWzskMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixWzskVControl, Sbecore::ubigint x1RefWzskMUser, std::string Par, std::string& Val);
};
#endif

#endif

