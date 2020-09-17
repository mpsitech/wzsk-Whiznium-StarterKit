/**
	* \file WzskMPerson.h
	* database access for table TblWzskMPerson (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKMPERSON_H
#define WZSKMPERSON_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWzskVMPersonSex TblWzskMPerson::VecVSex
#define VecWzskWMPersonDerivate TblWzskMPerson::VecWDerivate

/**
	* WzskMPerson: record of TblWzskMPerson
	*/
class WzskMPerson {

public:
	WzskMPerson(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixWDerivate;
	Sbecore::uint ixVSex;
	std::string Title;
	std::string Firstname;
	Sbecore::ubigint refJLastname;
	std::string Lastname;
	Sbecore::ubigint telRefADetail;
	std::string telVal;
	Sbecore::ubigint emlRefADetail;
	std::string emlVal;
	std::string Salutation;

public:
	bool operator==(const WzskMPerson& comp);
	bool operator!=(const WzskMPerson& comp);
};

/**
	* ListWzskMPerson: recordset of TblWzskMPerson
	*/
class ListWzskMPerson {

public:
	ListWzskMPerson();
	ListWzskMPerson(const ListWzskMPerson& src);
	~ListWzskMPerson();

	void clear();
	unsigned int size() const;
	void append(WzskMPerson* rec);

	WzskMPerson* operator[](const Sbecore::uint ix);
	ListWzskMPerson& operator=(const ListWzskMPerson& src);
	bool operator==(const ListWzskMPerson& comp);
	bool operator!=(const ListWzskMPerson& comp);

public:
	std::vector<WzskMPerson*> nodes;
};

/**
	* TblWzskMPerson: C++ wrapper for table TblWzskMPerson
	*/
class TblWzskMPerson {

public:
	/**
		* VecVSex (full: VecWzskVMPersonSex)
		*/
	class VecVSex {

	public:
		static const Sbecore::uint F = 1;
		static const Sbecore::uint M = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWDerivate (full: VecWzskWMPersonDerivate)
		*/
	class VecWDerivate {

	public:
		static const Sbecore::uint USR = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWzskMPerson();
	virtual ~TblWzskMPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskMPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMPerson& rst);

	virtual Sbecore::ubigint insertRec(WzskMPerson* rec);
	Sbecore::ubigint insertNewRec(WzskMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskMPerson& rst, WzskMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	virtual void insertRst(ListWzskMPerson& rst, bool transact = false);
	virtual void updateRec(WzskMPerson* rec);
	virtual void updateRst(ListWzskMPerson& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskMPerson** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskMPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskMPerson: C++ wrapper for table TblWzskMPerson (MySQL database)
	*/
class MyTblWzskMPerson : public TblWzskMPerson, public Sbecore::MyTable {

public:
	MyTblWzskMPerson();
	~MyTblWzskMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMPerson& rst);

	Sbecore::ubigint insertRec(WzskMPerson* rec);
	void insertRst(ListWzskMPerson& rst, bool transact = false);
	void updateRec(WzskMPerson* rec);
	void updateRst(ListWzskMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMPerson** rec);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskMPerson: C++ wrapper for table TblWzskMPerson (SQLite database)
	*/
class LiteTblWzskMPerson : public TblWzskMPerson, public Sbecore::LiteTable {

public:
	LiteTblWzskMPerson();
	~LiteTblWzskMPerson();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskMPerson** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskMPerson& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskMPerson** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMPerson& rst);

	Sbecore::ubigint insertRec(WzskMPerson* rec);
	void insertRst(ListWzskMPerson& rst, bool transact = false);
	void updateRec(WzskMPerson* rec);
	void updateRst(ListWzskMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMPerson** rec);
};
#endif

#endif

