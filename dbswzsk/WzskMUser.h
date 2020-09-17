/**
	* \file WzskMUser.h
	* database access for table TblWzskMUser (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKMUSER_H
#define WZSKMUSER_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWzskVMUserState TblWzskMUser::VecVState

/**
	* WzskMUser: record of TblWzskMUser
	*/
class WzskMUser {

public:
	WzskMUser(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::ubigint refWzskMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWzskVLocale = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refRUsergroup;
	Sbecore::ubigint refWzskMUsergroup;
	Sbecore::ubigint refWzskMPerson;
	std::string sref;
	Sbecore::ubigint refJState;
	Sbecore::uint ixVState;
	Sbecore::uint ixWzskVLocale;
	Sbecore::uint ixWzskVUserlevel;
	std::string Password;
	std::string Fullkey;
	std::string Comment;

public:
	bool operator==(const WzskMUser& comp);
	bool operator!=(const WzskMUser& comp);
};

/**
	* ListWzskMUser: recordset of TblWzskMUser
	*/
class ListWzskMUser {

public:
	ListWzskMUser();
	ListWzskMUser(const ListWzskMUser& src);
	~ListWzskMUser();

	void clear();
	unsigned int size() const;
	void append(WzskMUser* rec);

	WzskMUser* operator[](const Sbecore::uint ix);
	ListWzskMUser& operator=(const ListWzskMUser& src);
	bool operator==(const ListWzskMUser& comp);
	bool operator!=(const ListWzskMUser& comp);

public:
	std::vector<WzskMUser*> nodes;
};

/**
	* TblWzskMUser: C++ wrapper for table TblWzskMUser
	*/
class TblWzskMUser {

public:
	/**
		* VecVState (full: VecWzskVMUserState)
		*/
	class VecVState {

	public:
		static const Sbecore::uint ACT = 1;
		static const Sbecore::uint DSG = 2;
		static const Sbecore::uint DUE = 3;
		static const Sbecore::uint EXP = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWzskMUser();
	virtual ~TblWzskMUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskMUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMUser& rst);

	virtual Sbecore::ubigint insertRec(WzskMUser* rec);
	Sbecore::ubigint insertNewRec(WzskMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::ubigint refWzskMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWzskVLocale = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskMUser& rst, WzskMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWzskMUsergroup = 0, const Sbecore::ubigint refWzskMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWzskVLocale = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	virtual void insertRst(ListWzskMUser& rst, bool transact = false);
	virtual void updateRec(WzskMUser* rec);
	virtual void updateRst(ListWzskMUser& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskMUser** rec);
	virtual bool loadRecByPrs(Sbecore::ubigint refWzskMPerson, WzskMUser** rec);
	virtual bool loadRecBySrf(std::string sref, WzskMUser** rec);
	virtual bool loadRecBySrfPwd(std::string sref, std::string Password, WzskMUser** rec);
	virtual bool loadRefByPrs(Sbecore::ubigint refWzskMPerson, Sbecore::ubigint& ref);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskMUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskMUser: C++ wrapper for table TblWzskMUser (MySQL database)
	*/
class MyTblWzskMUser : public TblWzskMUser, public Sbecore::MyTable {

public:
	MyTblWzskMUser();
	~MyTblWzskMUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMUser& rst);

	Sbecore::ubigint insertRec(WzskMUser* rec);
	void insertRst(ListWzskMUser& rst, bool transact = false);
	void updateRec(WzskMUser* rec);
	void updateRst(ListWzskMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refWzskMPerson, WzskMUser** rec);
	bool loadRecBySrf(std::string sref, WzskMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WzskMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refWzskMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskMUser: C++ wrapper for table TblWzskMUser (SQLite database)
	*/
class LiteTblWzskMUser : public TblWzskMUser, public Sbecore::LiteTable {

public:
	LiteTblWzskMUser();
	~LiteTblWzskMUser();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByPrs;
	sqlite3_stmt* stmtLoadRecBySrf;
	sqlite3_stmt* stmtLoadRecBySrfPwd;
	sqlite3_stmt* stmtLoadRefByPrs;
	sqlite3_stmt* stmtLoadRefBySrf;
	sqlite3_stmt* stmtLoadRefsByUsg;
	sqlite3_stmt* stmtLoadSrfByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskMUser** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskMUser& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskMUser** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMUser& rst);

	Sbecore::ubigint insertRec(WzskMUser* rec);
	void insertRst(ListWzskMUser& rst, bool transact = false);
	void updateRec(WzskMUser* rec);
	void updateRst(ListWzskMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refWzskMPerson, WzskMUser** rec);
	bool loadRecBySrf(std::string sref, WzskMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WzskMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refWzskMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzskMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

