-- file CreateDbsWzskLite.sql
-- SQLite database create script
-- copyright: (C) 2016-2020 MPSI Technologies GmbH
-- author: Alexander Wirthmueller (auto-generation)
-- date created: 23 Nov 2025
-- IP header --- ABOVE

DROP TABLE IF EXISTS TblWzskAccRMUserUniversal;
DROP TABLE IF EXISTS TblWzskAMPersonDetail;
DROP TABLE IF EXISTS TblWzskAMUserAccess;
DROP TABLE IF EXISTS TblWzskAMUsergroupAccess;
DROP TABLE IF EXISTS TblWzskAVControlPar;
DROP TABLE IF EXISTS TblWzskAVKeylistKey;
DROP TABLE IF EXISTS TblWzskAVValuelistVal;
DROP TABLE IF EXISTS TblWzskCFile;
DROP TABLE IF EXISTS TblWzskHistRMUserUniversal;
DROP TABLE IF EXISTS TblWzskJAVKeylistKey;
DROP TABLE IF EXISTS TblWzskJMPersonLastname;
DROP TABLE IF EXISTS TblWzskJMUserState;
DROP TABLE IF EXISTS TblWzskMFile;
DROP TABLE IF EXISTS TblWzskMPerson;
DROP TABLE IF EXISTS TblWzskMSession;
DROP TABLE IF EXISTS TblWzskMUser;
DROP TABLE IF EXISTS TblWzskMUsergroup;
DROP TABLE IF EXISTS TblWzskRMUsergroupUniversal;
DROP TABLE IF EXISTS TblWzskRMUserMUsergroup;

DROP TABLE IF EXISTS TblWzskQFilList;
DROP TABLE IF EXISTS TblWzskQPreselect;
DROP TABLE IF EXISTS TblWzskQPrsADetail;
DROP TABLE IF EXISTS TblWzskQPrsList;
DROP TABLE IF EXISTS TblWzskQSelect;
DROP TABLE IF EXISTS TblWzskQUsgAAccess;
DROP TABLE IF EXISTS TblWzskQUsgList;
DROP TABLE IF EXISTS TblWzskQUsgMNUser;
DROP TABLE IF EXISTS TblWzskQUsr1NSession;
DROP TABLE IF EXISTS TblWzskQUsrAAccess;
DROP TABLE IF EXISTS TblWzskQUsrList;
DROP TABLE IF EXISTS TblWzskQUsrMNUsergroup;

CREATE TABLE TblWzskAccRMUserUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMUser BIGINT,
	unvIxWzskVMaintable INT,
	unvUref BIGINT,
	ixWzskVRecaccess INT
);
CREATE INDEX TblWzskAccRMUserUniversal_refWzskMUser ON TblWzskAccRMUserUniversal (refWzskMUser);
CREATE INDEX TblWzskAccRMUserUniversal_unvIxWzskVMaintable ON TblWzskAccRMUserUniversal (unvIxWzskVMaintable);
CREATE INDEX TblWzskAccRMUserUniversal_unvUref ON TblWzskAccRMUserUniversal (unvUref);

CREATE TABLE TblWzskAMPersonDetail(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
CREATE INDEX TblWzskAMPersonDetail_refWzskMPerson ON TblWzskAMPersonDetail (refWzskMPerson);

CREATE TABLE TblWzskAMUserAccess(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMUser BIGINT,
	x1IxWzskVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzskWAccess INT
);
CREATE INDEX TblWzskAMUserAccess_refWzskMUser ON TblWzskAMUserAccess (refWzskMUser);
CREATE INDEX TblWzskAMUserAccess_x1IxWzskVFeatgroup ON TblWzskAMUserAccess (x1IxWzskVFeatgroup);
CREATE INDEX TblWzskAMUserAccess_x2FeaSrefUix ON TblWzskAMUserAccess (x2FeaSrefUix);

CREATE TABLE TblWzskAMUsergroupAccess(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMUsergroup BIGINT,
	x1IxWzskVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzskWAccess INT
);
CREATE INDEX TblWzskAMUsergroupAccess_refWzskMUsergroup ON TblWzskAMUsergroupAccess (refWzskMUsergroup);
CREATE INDEX TblWzskAMUsergroupAccess_x1IxWzskVFeatgroup ON TblWzskAMUsergroupAccess (x1IxWzskVFeatgroup);
CREATE INDEX TblWzskAMUsergroupAccess_x2FeaSrefUix ON TblWzskAMUsergroupAccess (x2FeaSrefUix);

CREATE TABLE TblWzskAVControlPar(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	ixWzskVControl INT,
	x1RefWzskMUser BIGINT,
	x2IxWzskVLocale INT,
	Par VARCHAR(192),
	Val VARCHAR(192)
);
CREATE INDEX TblWzskAVControlPar_ixWzskVControl ON TblWzskAVControlPar (ixWzskVControl);
CREATE INDEX TblWzskAVControlPar_x1RefWzskMUser ON TblWzskAVControlPar (x1RefWzskMUser);
CREATE INDEX TblWzskAVControlPar_x2IxWzskVLocale ON TblWzskAVControlPar (x2IxWzskVLocale);
CREATE INDEX TblWzskAVControlPar_Par ON TblWzskAVControlPar (Par);

CREATE TABLE TblWzskAVKeylistKey(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	klsIxWzskVKeylist INT,
	klsNum INT,
	x1IxWzskVMaintable INT,
	x1Uref BIGINT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
CREATE INDEX TblWzskAVKeylistKey_klsIxWzskVKeylist ON TblWzskAVKeylistKey (klsIxWzskVKeylist);
CREATE INDEX TblWzskAVKeylistKey_klsNum ON TblWzskAVKeylistKey (klsNum);
CREATE INDEX TblWzskAVKeylistKey_x1IxWzskVMaintable ON TblWzskAVKeylistKey (x1IxWzskVMaintable);
CREATE INDEX TblWzskAVKeylistKey_x1Uref ON TblWzskAVKeylistKey (x1Uref);
CREATE INDEX TblWzskAVKeylistKey_sref ON TblWzskAVKeylistKey (sref);

CREATE TABLE TblWzskAVValuelistVal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	vlsIxWzskVValuelist INT,
	vlsNum INT,
	x1IxWzskVLocale INT,
	Val VARCHAR(192)
);
CREATE INDEX TblWzskAVValuelistVal_vlsIxWzskVValuelist ON TblWzskAVValuelistVal (vlsIxWzskVValuelist);
CREATE INDEX TblWzskAVValuelistVal_vlsNum ON TblWzskAVValuelistVal (vlsNum);
CREATE INDEX TblWzskAVValuelistVal_x1IxWzskVLocale ON TblWzskAVValuelistVal (x1IxWzskVLocale);

CREATE TABLE TblWzskCFile(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	void SMALLINT

);

CREATE TABLE TblWzskHistRMUserUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMUser BIGINT,
	unvIxWzskVMaintable INT,
	unvUref BIGINT,
	ixWzskVCard INT,
	ixWzskVPreset INT,
	preIxWzskVMaintable INT,
	preUref BIGINT,
	start INT
);
CREATE INDEX TblWzskHistRMUserUniversal_refWzskMUser ON TblWzskHistRMUserUniversal (refWzskMUser);
CREATE INDEX TblWzskHistRMUserUniversal_unvIxWzskVMaintable ON TblWzskHistRMUserUniversal (unvIxWzskVMaintable);
CREATE INDEX TblWzskHistRMUserUniversal_unvUref ON TblWzskHistRMUserUniversal (unvUref);
CREATE INDEX TblWzskHistRMUserUniversal_ixWzskVCard ON TblWzskHistRMUserUniversal (ixWzskVCard);
CREATE INDEX TblWzskHistRMUserUniversal_ixWzskVPreset ON TblWzskHistRMUserUniversal (ixWzskVPreset);
CREATE INDEX TblWzskHistRMUserUniversal_preIxWzskVMaintable ON TblWzskHistRMUserUniversal (preIxWzskVMaintable);
CREATE INDEX TblWzskHistRMUserUniversal_preUref ON TblWzskHistRMUserUniversal (preUref);

CREATE TABLE TblWzskJAVKeylistKey(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskAVKeylistKey BIGINT,
	x1IxWzskVLocale INT,
	Title VARCHAR(192),
	Comment TEXT
);
CREATE INDEX TblWzskJAVKeylistKey_refWzskAVKeylistKey ON TblWzskJAVKeylistKey (refWzskAVKeylistKey);
CREATE INDEX TblWzskJAVKeylistKey_x1IxWzskVLocale ON TblWzskJAVKeylistKey (x1IxWzskVLocale);

CREATE TABLE TblWzskJMPersonLastname(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
CREATE INDEX TblWzskJMPersonLastname_refWzskMPerson ON TblWzskJMPersonLastname (refWzskMPerson);
CREATE INDEX TblWzskJMPersonLastname_x1Startd ON TblWzskJMPersonLastname (x1Startd);
CREATE INDEX TblWzskJMPersonLastname_Lastname ON TblWzskJMPersonLastname (Lastname);

CREATE TABLE TblWzskJMUserState(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMUser BIGINT,
	x1Start INT,
	ixVState INT
);
CREATE INDEX TblWzskJMUserState_refWzskMUser ON TblWzskJMUserState (refWzskMUser);
CREATE INDEX TblWzskJMUserState_x1Start ON TblWzskJMUserState (x1Start);

CREATE TABLE TblWzskMFile(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	refWzskCFile BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	Archived INT,
	Filename VARCHAR(50),
	Archivename VARCHAR(30),
	srefKMimetype VARCHAR(50),
	Size INT,
	Comment TEXT
);
CREATE INDEX TblWzskMFile_grp ON TblWzskMFile (grp);
CREATE INDEX TblWzskMFile_own ON TblWzskMFile (own);
CREATE INDEX TblWzskMFile_refWzskCFile ON TblWzskMFile (refWzskCFile);
CREATE INDEX TblWzskMFile_refIxVTbl ON TblWzskMFile (refIxVTbl);
CREATE INDEX TblWzskMFile_refUref ON TblWzskMFile (refUref);
CREATE INDEX TblWzskMFile_Filename ON TblWzskMFile (Filename);

CREATE TABLE TblWzskMPerson(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	ixWDerivate INT,
	ixVSex INT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT,
	Lastname VARCHAR(50),
	telRefADetail BIGINT,
	telVal VARCHAR(192),
	emlRefADetail BIGINT,
	emlVal VARCHAR(192),
	Salutation VARCHAR(100)
);
CREATE INDEX TblWzskMPerson_grp ON TblWzskMPerson (grp);
CREATE INDEX TblWzskMPerson_own ON TblWzskMPerson (own);
CREATE INDEX TblWzskMPerson_ixWDerivate ON TblWzskMPerson (ixWDerivate);
CREATE INDEX TblWzskMPerson_Lastname ON TblWzskMPerson (Lastname);

CREATE TABLE TblWzskMSession(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
CREATE INDEX TblWzskMSession_refWzskMUser ON TblWzskMSession (refWzskMUser);
CREATE INDEX TblWzskMSession_start ON TblWzskMSession (start);

CREATE TABLE TblWzskMUser(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	refRUsergroup BIGINT,
	refWzskMUsergroup BIGINT,
	refWzskMPerson BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	ixWzskVLocale INT,
	ixWzskVUserlevel INT,
	Password VARCHAR(30),
	Fullkey TEXT,
	Comment TEXT
);
CREATE INDEX TblWzskMUser_grp ON TblWzskMUser (grp);
CREATE INDEX TblWzskMUser_own ON TblWzskMUser (own);
CREATE INDEX TblWzskMUser_refWzskMUsergroup ON TblWzskMUser (refWzskMUsergroup);
CREATE INDEX TblWzskMUser_refWzskMPerson ON TblWzskMUser (refWzskMPerson);
CREATE INDEX TblWzskMUser_sref ON TblWzskMUser (sref);
CREATE INDEX TblWzskMUser_ixVState ON TblWzskMUser (ixVState);

CREATE TABLE TblWzskMUsergroup(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
CREATE INDEX TblWzskMUsergroup_grp ON TblWzskMUsergroup (grp);
CREATE INDEX TblWzskMUsergroup_own ON TblWzskMUsergroup (own);
CREATE INDEX TblWzskMUsergroup_sref ON TblWzskMUsergroup (sref);

CREATE TABLE TblWzskRMUsergroupUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMUsergroup BIGINT,
	unvIxWzskVMaintable INT,
	unvUref BIGINT,
	ixWzskVRecaccess INT
);
CREATE INDEX TblWzskRMUsergroupUniversal_refWzskMUsergroup ON TblWzskRMUsergroupUniversal (refWzskMUsergroup);
CREATE INDEX TblWzskRMUsergroupUniversal_unvIxWzskVMaintable ON TblWzskRMUsergroupUniversal (unvIxWzskVMaintable);
CREATE INDEX TblWzskRMUsergroupUniversal_unvUref ON TblWzskRMUsergroupUniversal (unvUref);

CREATE TABLE TblWzskRMUserMUsergroup(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzskMUser BIGINT,
	refWzskMUsergroup BIGINT,
	ixWzskVUserlevel INT
);
CREATE INDEX TblWzskRMUserMUsergroup_refWzskMUser ON TblWzskRMUserMUsergroup (refWzskMUser);
CREATE INDEX TblWzskRMUserMUsergroup_refWzskMUsergroup ON TblWzskRMUserMUsergroup (refWzskMUsergroup);

CREATE TABLE TblWzskQFilList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Filename VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	srefKMimetype VARCHAR(50),
	Size INT
);
CREATE INDEX TblWzskQFilList_jref ON TblWzskQFilList (jref);
CREATE INDEX TblWzskQFilList_jnum ON TblWzskQFilList (jnum);

CREATE TABLE TblWzskQPreselect(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzskQPreselect_jref ON TblWzskQPreselect (jref);

CREATE TABLE TblWzskQPrsADetail(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
CREATE INDEX TblWzskQPrsADetail_jref ON TblWzskQPrsADetail (jref);
CREATE INDEX TblWzskQPrsADetail_jnum ON TblWzskQPrsADetail (jnum);

CREATE TABLE TblWzskQPrsList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	ixVSex INT,
	telVal VARCHAR(192),
	emlVal VARCHAR(192)
);
CREATE INDEX TblWzskQPrsList_jref ON TblWzskQPrsList (jref);
CREATE INDEX TblWzskQPrsList_jnum ON TblWzskQPrsList (jnum);

CREATE TABLE TblWzskQSelect(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
CREATE INDEX TblWzskQSelect_jref ON TblWzskQSelect (jref);
CREATE INDEX TblWzskQSelect_ix ON TblWzskQSelect (ix);

CREATE TABLE TblWzskQUsgAAccess(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWzskVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzskWAccess INT
);
CREATE INDEX TblWzskQUsgAAccess_jref ON TblWzskQUsgAAccess (jref);
CREATE INDEX TblWzskQUsgAAccess_jnum ON TblWzskQUsgAAccess (jnum);

CREATE TABLE TblWzskQUsgList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50)
);
CREATE INDEX TblWzskQUsgList_jref ON TblWzskQUsgList (jref);
CREATE INDEX TblWzskQUsgList_jnum ON TblWzskQUsgList (jnum);

CREATE TABLE TblWzskQUsgMNUser(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWzskVUserlevel INT
);
CREATE INDEX TblWzskQUsgMNUser_jref ON TblWzskQUsgMNUser (jref);
CREATE INDEX TblWzskQUsgMNUser_jnum ON TblWzskQUsgMNUser (jnum);

CREATE TABLE TblWzskQUsr1NSession(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzskQUsr1NSession_jref ON TblWzskQUsr1NSession (jref);
CREATE INDEX TblWzskQUsr1NSession_jnum ON TblWzskQUsr1NSession (jnum);

CREATE TABLE TblWzskQUsrAAccess(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWzskVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzskWAccess INT
);
CREATE INDEX TblWzskQUsrAAccess_jref ON TblWzskQUsrAAccess (jref);
CREATE INDEX TblWzskQUsrAAccess_jnum ON TblWzskQUsrAAccess (jnum);

CREATE TABLE TblWzskQUsrList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	refWzskMPerson BIGINT,
	sref VARCHAR(50),
	refWzskMUsergroup BIGINT,
	ixVState INT,
	ixWzskVLocale INT,
	ixWzskVUserlevel INT
);
CREATE INDEX TblWzskQUsrList_jref ON TblWzskQUsrList (jref);
CREATE INDEX TblWzskQUsrList_jnum ON TblWzskQUsrList (jnum);

CREATE TABLE TblWzskQUsrMNUsergroup(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWzskVUserlevel INT
);
CREATE INDEX TblWzskQUsrMNUsergroup_jref ON TblWzskQUsrMNUsergroup (jref);
CREATE INDEX TblWzskQUsrMNUsergroup_jnum ON TblWzskQUsrMNUsergroup (jnum);
