/**
	* \file WzskHistRMUserUniversal.h
	* database access for table TblWzskHistRMUserUniversal (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef WZSKHISTRMUSERUNIVERSAL_H
#define WZSKHISTRMUSERUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskHistRMUserUniversal: record of TblWzskHistRMUserUniversal
	*/
class WzskHistRMUserUniversal {

public:
	WzskHistRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVCard = 0, const Sbecore::uint ixWzskVPreset = 0, const Sbecore::uint preIxWzskVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzskMUser;
	Sbecore::uint unvIxWzskVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWzskVCard;
	Sbecore::uint ixWzskVPreset;
	Sbecore::uint preIxWzskVMaintable;
	Sbecore::ubigint preUref;
	Sbecore::uint start;

public:
	bool operator==(const WzskHistRMUserUniversal& comp);
	bool operator!=(const WzskHistRMUserUniversal& comp);
};

/**
	* ListWzskHistRMUserUniversal: recordset of TblWzskHistRMUserUniversal
	*/
class ListWzskHistRMUserUniversal {

public:
	ListWzskHistRMUserUniversal();
	ListWzskHistRMUserUniversal(const ListWzskHistRMUserUniversal& src);
	~ListWzskHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(WzskHistRMUserUniversal* rec);

	WzskHistRMUserUniversal* operator[](const Sbecore::uint ix);
	ListWzskHistRMUserUniversal& operator=(const ListWzskHistRMUserUniversal& src);
	bool operator==(const ListWzskHistRMUserUniversal& comp);
	bool operator!=(const ListWzskHistRMUserUniversal& comp);

public:
	std::vector<WzskHistRMUserUniversal*> nodes;
};

/**
	* TblWzskHistRMUserUniversal: C++ wrapper for table TblWzskHistRMUserUniversal
	*/
class TblWzskHistRMUserUniversal {

public:

public:
	TblWzskHistRMUserUniversal();
	virtual ~TblWzskHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskHistRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(WzskHistRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(WzskHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVCard = 0, const Sbecore::uint ixWzskVPreset = 0, const Sbecore::uint preIxWzskVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzskHistRMUserUniversal& rst, WzskHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refWzskMUser = 0, const Sbecore::uint unvIxWzskVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzskVCard = 0, const Sbecore::uint ixWzskVPreset = 0, const Sbecore::uint preIxWzskVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	virtual void insertRst(ListWzskHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(WzskHistRMUserUniversal* rec);
	virtual void updateRst(ListWzskHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskHistRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWzskVCard, WzskHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::uint ixWzskVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	virtual Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint ixWzskVCard, const bool append, ListWzskHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskHistRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskHistRMUserUniversal: C++ wrapper for table TblWzskHistRMUserUniversal (MySQL database)
	*/
class MyTblWzskHistRMUserUniversal : public TblWzskHistRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblWzskHistRMUserUniversal();
	~MyTblWzskHistRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzskHistRMUserUniversal* rec);
	void insertRst(ListWzskHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WzskHistRMUserUniversal* rec);
	void updateRst(ListWzskHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWzskVCard, WzskHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::uint ixWzskVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint ixWzskVCard, const bool append, ListWzskHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskHistRMUserUniversal: C++ wrapper for table TblWzskHistRMUserUniversal (SQLite database)
	*/
class LiteTblWzskHistRMUserUniversal : public TblWzskHistRMUserUniversal, public Sbecore::LiteTable {

public:
	LiteTblWzskHistRMUserUniversal();
	~LiteTblWzskHistRMUserUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsrMtbUnvCrd;
	sqlite3_stmt* stmtLoadRefsByUsrMtbCrd;
	sqlite3_stmt* stmtLoadRstByUsrCrd;
	sqlite3_stmt* stmtLoadUnuByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskHistRMUserUniversal** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskHistRMUserUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskHistRMUserUniversal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzskHistRMUserUniversal* rec);
	void insertRst(ListWzskHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WzskHistRMUserUniversal* rec);
	void updateRst(ListWzskHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWzskVCard, WzskHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint unvIxWzskVMaintable, Sbecore::uint ixWzskVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWzskMUser, Sbecore::uint ixWzskVCard, const bool append, ListWzskHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#endif

