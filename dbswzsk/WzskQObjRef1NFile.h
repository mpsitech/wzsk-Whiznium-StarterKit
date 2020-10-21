/**
	* \file WzskQObjRef1NFile.h
	* Dbs and XML wrapper for table TblWzskQObjRef1NFile (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKQOBJREF1NFILE_H
#define WZSKQOBJREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQObjRef1NFile: record of TblWzskQObjRef1NFile
	*/
class WzskQObjRef1NFile {

public:
	WzskQObjRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzskQObjRef1NFile: recordset of TblWzskQObjRef1NFile
	*/
class ListWzskQObjRef1NFile {

public:
	ListWzskQObjRef1NFile();
	ListWzskQObjRef1NFile(const ListWzskQObjRef1NFile& src);
	~ListWzskQObjRef1NFile();

	void clear();
	unsigned int size() const;
	void append(WzskQObjRef1NFile* rec);

	ListWzskQObjRef1NFile& operator=(const ListWzskQObjRef1NFile& src);

public:
	std::vector<WzskQObjRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQObjRef1NFile: C++ wrapper for table TblWzskQObjRef1NFile
	*/
class TblWzskQObjRef1NFile {

public:
	TblWzskQObjRef1NFile();
	virtual ~TblWzskQObjRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQObjRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObjRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(WzskQObjRef1NFile* rec);
	Sbecore::ubigint insertNewRec(WzskQObjRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQObjRef1NFile& rst, WzskQObjRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzskQObjRef1NFile& rst);
	virtual void updateRec(WzskQObjRef1NFile* rec);
	virtual void updateRst(ListWzskQObjRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQObjRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObjRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQObjRef1NFile: C++ wrapper for table TblWzskQObjRef1NFile (MySQL database)
	*/
class MyTblWzskQObjRef1NFile : public TblWzskQObjRef1NFile, public Sbecore::MyTable {

public:
	MyTblWzskQObjRef1NFile();
	~MyTblWzskQObjRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQObjRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObjRef1NFile& rst);

	Sbecore::ubigint insertRec(WzskQObjRef1NFile* rec);
	void insertRst(ListWzskQObjRef1NFile& rst);
	void updateRec(WzskQObjRef1NFile* rec);
	void updateRst(ListWzskQObjRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQObjRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObjRef1NFile& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQObjRef1NFile: C++ wrapper for table TblWzskQObjRef1NFile (SQLite database)
	*/
class LiteTblWzskQObjRef1NFile : public TblWzskQObjRef1NFile, public Sbecore::LiteTable {

public:
	LiteTblWzskQObjRef1NFile();
	~LiteTblWzskQObjRef1NFile();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQObjRef1NFile** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQObjRef1NFile& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQObjRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQObjRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQObjRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQObjRef1NFile& rst);

	Sbecore::ubigint insertRec(WzskQObjRef1NFile* rec);
	void insertRst(ListWzskQObjRef1NFile& rst);
	void updateRec(WzskQObjRef1NFile* rec);
	void updateRst(ListWzskQObjRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQObjRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQObjRef1NFile& rst);
};
#endif

#endif

