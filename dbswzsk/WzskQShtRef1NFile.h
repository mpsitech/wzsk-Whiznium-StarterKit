/**
	* \file WzskQShtRef1NFile.h
	* Dbs and XML wrapper for table TblWzskQShtRef1NFile (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQSHTREF1NFILE_H
#define WZSKQSHTREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

/**
	* WzskQShtRef1NFile: record of TblWzskQShtRef1NFile
	*/
class WzskQShtRef1NFile {

public:
	WzskQShtRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzskQShtRef1NFile: recordset of TblWzskQShtRef1NFile
	*/
class ListWzskQShtRef1NFile {

public:
	ListWzskQShtRef1NFile();
	ListWzskQShtRef1NFile(const ListWzskQShtRef1NFile& src);
	~ListWzskQShtRef1NFile();

	void clear();
	unsigned int size() const;
	void append(WzskQShtRef1NFile* rec);

	ListWzskQShtRef1NFile& operator=(const ListWzskQShtRef1NFile& src);

public:
	std::vector<WzskQShtRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzskQShtRef1NFile: C++ wrapper for table TblWzskQShtRef1NFile
	*/
class TblWzskQShtRef1NFile {

public:
	TblWzskQShtRef1NFile();
	virtual ~TblWzskQShtRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzskQShtRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(WzskQShtRef1NFile* rec);
	Sbecore::ubigint insertNewRec(WzskQShtRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzskQShtRef1NFile& rst, WzskQShtRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzskQShtRef1NFile& rst);
	virtual void updateRec(WzskQShtRef1NFile* rec);
	virtual void updateRst(ListWzskQShtRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzskQShtRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzskQShtRef1NFile: C++ wrapper for table TblWzskQShtRef1NFile (MySQL database)
	*/
class MyTblWzskQShtRef1NFile : public TblWzskQShtRef1NFile, public Sbecore::MyTable {

public:
	MyTblWzskQShtRef1NFile();
	~MyTblWzskQShtRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQShtRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtRef1NFile& rst);

	Sbecore::ubigint insertRec(WzskQShtRef1NFile* rec);
	void insertRst(ListWzskQShtRef1NFile& rst);
	void updateRec(WzskQShtRef1NFile* rec);
	void updateRst(ListWzskQShtRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQShtRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtRef1NFile& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzskQShtRef1NFile: C++ wrapper for table TblWzskQShtRef1NFile (SQLite database)
	*/
class LiteTblWzskQShtRef1NFile : public TblWzskQShtRef1NFile, public Sbecore::LiteTable {

public:
	LiteTblWzskQShtRef1NFile();
	~LiteTblWzskQShtRef1NFile();

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
	bool loadRec(sqlite3_stmt* stmt, WzskQShtRef1NFile** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzskQShtRef1NFile& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzskQShtRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzskQShtRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzskQShtRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzskQShtRef1NFile& rst);

	Sbecore::ubigint insertRec(WzskQShtRef1NFile* rec);
	void insertRst(ListWzskQShtRef1NFile& rst);
	void updateRec(WzskQShtRef1NFile* rec);
	void updateRst(ListWzskQShtRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzskQShtRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzskQShtRef1NFile& rst);
};
#endif

#endif

