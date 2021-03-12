/**
	* \file WzskMFile.h
	* database access for table TblWzskMFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKMFILE_H
#define WZSKMFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWzskVMFileRefTbl TblWzskMFile::VecVRefTbl

/**
	* WzskMFile: record of TblWzskMFile
	*/
class WzskMFile {

public:
	WzskMFile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWzskCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refWzskCFile;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	std::string osrefKContent;
	Sbecore::uint Archived;
	std::string Filename;
	std::string Archivename;
	std::string srefKMimetype;
	Sbecore::usmallint Size;
	std::string Comment;

public:
	bool operator==(const WzskMFile& comp);
	bool operator!=(const WzskMFile& comp);
};

/**
	* ListWzskMFile: recordset of TblWzskMFile
	*/
class ListWzskMFile {

public:
	ListWzskMFile();
	ListWzskMFile(const ListWzskMFile& src);
	~ListWzskMFile();

	void clear();
	unsigned int size() const;
	void append(WzskMFile* rec);

	WzskMFile* operator[](const Sbecore::uint ix);
	ListWzskMFile& operator=(const ListWzskMFile& src);
	bool operator==(const ListWzskMFile& comp);
	bool operator!=(const ListWzskMFile& comp);

public:
	std::vector<WzskMFile*> nodes;
};

/**
	* TblWzskMFile: C++ wrapper for table TblWzskMFile
	*/
class TblWzskMFile {

public:
	/**
		* VecVRefTbl (full: VecWzskVMFileRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint OBJ = 2;
		static const Sbecore::uint SHT = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

public:
	TblWzskMFile();
	virtual ~TblWzskMFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskMFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMFile& rst);

	virtual Sbecore::ubigint insertRec(WzskMFile* rec);
	Sbecore::ubigint insertNewRec(WzskMFile** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWzskCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskMFile& rst, WzskMFile** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWzskCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::usmallint Size = 0, const std::string Comment = "");
	virtual void insertRst(ListWzskMFile& rst, bool transact = false);
	virtual void updateRec(WzskMFile* rec);
	virtual void updateRst(ListWzskMFile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzskMFile** rec);
	virtual bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWzskCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWzskCFile, const bool append, ListWzskMFile& rst);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWzskMFile& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzskMFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskMFile: C++ wrapper for table TblWzskMFile (MySQL database)
	*/
class MyTblWzskMFile : public TblWzskMFile, public Sbecore::MyTable {

public:
	MyTblWzskMFile();
	~MyTblWzskMFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMFile& rst);

	Sbecore::ubigint insertRec(WzskMFile* rec);
	void insertRst(ListWzskMFile& rst, bool transact = false);
	void updateRec(WzskMFile* rec);
	void updateRst(ListWzskMFile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMFile** rec);
	bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWzskCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWzskCFile, const bool append, ListWzskMFile& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWzskMFile& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzskMFile: C++ wrapper for table TblWzskMFile (SQLite database)
	*/
class LiteTblWzskMFile : public TblWzskMFile, public Sbecore::LiteTable {

public:
	LiteTblWzskMFile();
	~LiteTblWzskMFile();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadFnmByRef;
	sqlite3_stmt* stmtLoadRefsByClu;
	sqlite3_stmt* stmtLoadRstByClu;
	sqlite3_stmt* stmtLoadRstByRetReu;

private:
	bool loadRec(sqlite3_stmt* stmt, WzskMFile** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskMFile& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskMFile** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskMFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskMFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskMFile& rst);

	Sbecore::ubigint insertRec(WzskMFile* rec);
	void insertRst(ListWzskMFile& rst, bool transact = false);
	void updateRec(WzskMFile* rec);
	void updateRst(ListWzskMFile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzskMFile** rec);
	bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWzskCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWzskCFile, const bool append, ListWzskMFile& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWzskMFile& rst);
};
#endif

#endif
