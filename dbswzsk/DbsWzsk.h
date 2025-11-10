/**
	* \file DbsWzsk.h
	* C++ wrapper for database DbsWzsk (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef DBSWZSK_H
#define DBSWZSK_H

#define WZSK_VERSION "1.2.6"
#define WZSK_VERSION_MAJOR 1
#define WZSK_VERSION_MINOR 2
#define WZSK_VERSION_SUB 6

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

#include "WzskAccRMUserUniversal.h"
#include "WzskAMPersonDetail.h"
#include "WzskAMUserAccess.h"
#include "WzskAMUsergroupAccess.h"
#include "WzskAVControlPar.h"
#include "WzskAVKeylistKey.h"
#include "WzskAVValuelistVal.h"
#include "WzskCFile.h"
#include "WzskHistRMUserUniversal.h"
#include "WzskJAVKeylistKey.h"
#include "WzskJMPersonLastname.h"
#include "WzskJMUserState.h"
#include "WzskMFile.h"
#include "WzskMPerson.h"
#include "WzskMSession.h"
#include "WzskMUser.h"
#include "WzskMUsergroup.h"
#include "WzskRMUsergroupUniversal.h"
#include "WzskRMUserMUsergroup.h"

#include "WzskQFilList.h"
#include "WzskQPreselect.h"
#include "WzskQPrsADetail.h"
#include "WzskQPrsList.h"
#include "WzskQSelect.h"
#include "WzskQUsgAAccess.h"
#include "WzskQUsgList.h"
#include "WzskQUsgMNUser.h"
#include "WzskQUsr1NSession.h"
#include "WzskQUsrAAccess.h"
#include "WzskQUsrList.h"
#include "WzskQUsrMNUsergroup.h"

#define VecWzskVCard DbsWzsk::VecVCard
#define VecWzskVControl DbsWzsk::VecVControl
#define VecWzskVFeatgroup DbsWzsk::VecVFeatgroup
#define VecWzskVKeylist DbsWzsk::VecVKeylist
#define VecWzskVLat DbsWzsk::VecVLat
#define VecWzskVLocale DbsWzsk::VecVLocale
#define VecWzskVLop DbsWzsk::VecVLop
#define VecWzskVMaintable DbsWzsk::VecVMaintable
#define VecWzskVOolop DbsWzsk::VecVOolop
#define VecWzskVPreset DbsWzsk::VecVPreset
#define VecWzskVRecaccess DbsWzsk::VecVRecaccess
#define VecWzskVUserlevel DbsWzsk::VecVUserlevel
#define VecWzskVValuelist DbsWzsk::VecVValuelist
#define VecWzskWAccess DbsWzsk::VecWAccess

/**
	* DbsWzsk
	*/
class DbsWzsk {

public:
	/**
		* VecVCard (full: VecWzskVCard)
		*/
	class VecVCard {

	public:
		static const Sbecore::uint CRDWZSKNAV = 1;
		static const Sbecore::uint CRDWZSKUSG = 2;
		static const Sbecore::uint CRDWZSKUSR = 3;
		static const Sbecore::uint CRDWZSKPRS = 4;
		static const Sbecore::uint CRDWZSKPRF = 5;
		static const Sbecore::uint CRDWZSKLLV = 6;
		static const Sbecore::uint CRDWZSKVTR = 7;
		static const Sbecore::uint CRDWZSKHWC = 8;
		static const Sbecore::uint CRDWZSKFIL = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVControl (full: VecWzskVControl)
		*/
	class VecVControl {

	public:
		static const Sbecore::uint PNLWZSKUSGLIST_TCOGRP = 1;
		static const Sbecore::uint PNLWZSKUSGLIST_TCOOWN = 2;
		static const Sbecore::uint PNLWZSKUSGLIST_TCOSRF = 3;
		static const Sbecore::uint PNLWZSKUSGAACCESS_TCOFEG = 4;
		static const Sbecore::uint PNLWZSKUSGAACCESS_TCOFEA = 5;
		static const Sbecore::uint PNLWZSKUSGAACCESS_TCOACC = 6;
		static const Sbecore::uint PNLWZSKUSGMNUSER_TCOMREF = 7;
		static const Sbecore::uint PNLWZSKUSGMNUSER_TCOULV = 8;
		static const Sbecore::uint PNLWZSKUSRLIST_TCOGRP = 9;
		static const Sbecore::uint PNLWZSKUSRLIST_TCOOWN = 10;
		static const Sbecore::uint PNLWZSKUSRLIST_TCOPRS = 11;
		static const Sbecore::uint PNLWZSKUSRLIST_TCOSRF = 12;
		static const Sbecore::uint PNLWZSKUSRLIST_TCOUSG = 13;
		static const Sbecore::uint PNLWZSKUSRLIST_TCOSTE = 14;
		static const Sbecore::uint PNLWZSKUSRLIST_TCOLCL = 15;
		static const Sbecore::uint PNLWZSKUSRLIST_TCOULV = 16;
		static const Sbecore::uint PNLWZSKUSRAACCESS_TCOFEG = 17;
		static const Sbecore::uint PNLWZSKUSRAACCESS_TCOFEA = 18;
		static const Sbecore::uint PNLWZSKUSRAACCESS_TCOACC = 19;
		static const Sbecore::uint PNLWZSKUSR1NSESSION_TCOREF = 20;
		static const Sbecore::uint PNLWZSKUSRMNUSERGROUP_TCOMREF = 21;
		static const Sbecore::uint PNLWZSKUSRMNUSERGROUP_TCOULV = 22;
		static const Sbecore::uint PNLWZSKPRSLIST_TCOGRP = 23;
		static const Sbecore::uint PNLWZSKPRSLIST_TCOOWN = 24;
		static const Sbecore::uint PNLWZSKPRSLIST_TCOTIT = 25;
		static const Sbecore::uint PNLWZSKPRSLIST_TCOFNM = 26;
		static const Sbecore::uint PNLWZSKPRSLIST_TCOLNM = 27;
		static const Sbecore::uint PNLWZSKPRSLIST_TCOSEX = 28;
		static const Sbecore::uint PNLWZSKPRSLIST_TCOTEL = 29;
		static const Sbecore::uint PNLWZSKPRSLIST_TCOEML = 30;
		static const Sbecore::uint PNLWZSKPRSADETAIL_TCOTYP = 31;
		static const Sbecore::uint PNLWZSKPRSADETAIL_TCOVAL = 32;
		static const Sbecore::uint PNLWZSKFILLIST_TCOGRP = 33;
		static const Sbecore::uint PNLWZSKFILLIST_TCOOWN = 34;
		static const Sbecore::uint PNLWZSKFILLIST_TCOFNM = 35;
		static const Sbecore::uint PNLWZSKFILLIST_TCORET = 36;
		static const Sbecore::uint PNLWZSKFILLIST_TCOREU = 37;
		static const Sbecore::uint PNLWZSKFILLIST_TCOCNT = 38;
		static const Sbecore::uint PNLWZSKFILLIST_TCOMIM = 39;
		static const Sbecore::uint PNLWZSKFILLIST_TCOSIZ = 40;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVFeatgroup (full: VecWzskVFeatgroup)
		*/
	class VecVFeatgroup {

	public:
		static const Sbecore::uint VECWZSKVCARD = 1;
		static const Sbecore::uint VECVJOBWZSKACQCORNERMETHOD = 2;
		static const Sbecore::uint VECVJOBWZSKACQCORNERVAR = 3;
		static const Sbecore::uint VECVJOBWZSKACQTRACEMETHOD = 4;
		static const Sbecore::uint VECVJOBWZSKACQTRACEVAR = 5;
		static const Sbecore::uint VECVJOBWZSKACTLASERMETHOD = 6;
		static const Sbecore::uint VECVJOBWZSKACTLASERVAR = 7;
		static const Sbecore::uint VECVJOBWZSKACTROTARYMETHOD = 8;
		static const Sbecore::uint VECVJOBWZSKACTROTARYVAR = 9;
		static const Sbecore::uint VECVJOBWZSKSRCFPGAINFOVAR = 10;
		static const Sbecore::uint VECVJOBWZSKSRCSYSINFOVAR = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVKeylist (full: VecWzskVKeylist)
		*/
	class VecVKeylist {

	public:
		static const Sbecore::uint KLSTWZSKKAMPERSONDETAILTYPE = 1;
		static const Sbecore::uint KLSTWZSKKMFILECONTENT = 2;
		static const Sbecore::uint KLSTWZSKKMFILEMIMETYPE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);
	};

	/**
		* VecVLat (full: VecWzskVLat)
		*/
	class VecVLat {

	public:
		static const Sbecore::uint DLO = 1;
		static const Sbecore::uint INI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVLocale (full: VecWzskVLocale)
		*/
	class VecVLocale {

	public:
		static const Sbecore::uint ENUS = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVLop (full: VecWzskVLop)
		*/
	class VecVLop {

	public:
		static const Sbecore::uint INS = 1;
		static const Sbecore::uint RMV = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVMaintable (full: VecWzskVMaintable)
		*/
	class VecVMaintable {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBLWZSKMFILE = 2;
		static const Sbecore::uint TBLWZSKMPERSON = 3;
		static const Sbecore::uint TBLWZSKMSESSION = 4;
		static const Sbecore::uint TBLWZSKMUSER = 5;
		static const Sbecore::uint TBLWZSKMUSERGROUP = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVOolop (full: VecWzskVOolop)
		*/
	class VecVOolop {

	public:
		static const Sbecore::uint INA = 1;
		static const Sbecore::uint INB = 2;
		static const Sbecore::uint RMV = 3;
		static const Sbecore::uint SWP = 4;
		static const Sbecore::uint TOA = 5;
		static const Sbecore::uint TOB = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVPreset (full: VecWzskVPreset)
		*/
	class VecVPreset {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint PREWZSKADMIN = 2;
		static const Sbecore::uint PREWZSKFILLIST_FNM = 3;
		static const Sbecore::uint PREWZSKFILLIST_GRP = 4;
		static const Sbecore::uint PREWZSKFILLIST_OWN = 5;
		static const Sbecore::uint PREWZSKFILLIST_RET = 6;
		static const Sbecore::uint PREWZSKFILLIST_REU = 7;
		static const Sbecore::uint PREWZSKGROUP = 8;
		static const Sbecore::uint PREWZSKIP = 9;
		static const Sbecore::uint PREWZSKIXCRDACCFIL = 10;
		static const Sbecore::uint PREWZSKIXCRDACCHWC = 11;
		static const Sbecore::uint PREWZSKIXCRDACCLLV = 12;
		static const Sbecore::uint PREWZSKIXCRDACCPRF = 13;
		static const Sbecore::uint PREWZSKIXCRDACCPRS = 14;
		static const Sbecore::uint PREWZSKIXCRDACCUSG = 15;
		static const Sbecore::uint PREWZSKIXCRDACCUSR = 16;
		static const Sbecore::uint PREWZSKIXCRDACCVTR = 17;
		static const Sbecore::uint PREWZSKIXLCL = 18;
		static const Sbecore::uint PREWZSKIXORD = 19;
		static const Sbecore::uint PREWZSKIXPRE = 20;
		static const Sbecore::uint PREWZSKIXRECACC = 21;
		static const Sbecore::uint PREWZSKJREFNOTIFY = 22;
		static const Sbecore::uint PREWZSKJREFSESS = 23;
		static const Sbecore::uint PREWZSKNOADM = 24;
		static const Sbecore::uint PREWZSKOWNER = 25;
		static const Sbecore::uint PREWZSKPRSADETAIL_X1 = 26;
		static const Sbecore::uint PREWZSKPRSLIST_GRP = 27;
		static const Sbecore::uint PREWZSKPRSLIST_LNM = 28;
		static const Sbecore::uint PREWZSKPRSLIST_OWN = 29;
		static const Sbecore::uint PREWZSKREFFIL = 30;
		static const Sbecore::uint PREWZSKREFPRS = 31;
		static const Sbecore::uint PREWZSKREFSEL = 32;
		static const Sbecore::uint PREWZSKREFSES = 33;
		static const Sbecore::uint PREWZSKREFUSG = 34;
		static const Sbecore::uint PREWZSKREFUSR = 35;
		static const Sbecore::uint PREWZSKSESS = 36;
		static const Sbecore::uint PREWZSKSUSPSESS = 37;
		static const Sbecore::uint PREWZSKSYSDATE = 38;
		static const Sbecore::uint PREWZSKSYSSTAMP = 39;
		static const Sbecore::uint PREWZSKSYSTIME = 40;
		static const Sbecore::uint PREWZSKTLAST = 41;
		static const Sbecore::uint PREWZSKUSGAACCESS_X1 = 42;
		static const Sbecore::uint PREWZSKUSGAACCESS_X2 = 43;
		static const Sbecore::uint PREWZSKUSGLIST_GRP = 44;
		static const Sbecore::uint PREWZSKUSGLIST_OWN = 45;
		static const Sbecore::uint PREWZSKUSGLIST_SRF = 46;
		static const Sbecore::uint PREWZSKUSRAACCESS_X1 = 47;
		static const Sbecore::uint PREWZSKUSRAACCESS_X2 = 48;
		static const Sbecore::uint PREWZSKUSRLIST_GRP = 49;
		static const Sbecore::uint PREWZSKUSRLIST_OWN = 50;
		static const Sbecore::uint PREWZSKUSRLIST_PRS = 51;
		static const Sbecore::uint PREWZSKUSRLIST_SRF = 52;
		static const Sbecore::uint PREWZSKUSRLIST_STE = 53;
		static const Sbecore::uint PREWZSKUSRLIST_USG = 54;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);
	};

	/**
		* VecVRecaccess (full: VecWzskVRecaccess)
		*/
	class VecVRecaccess {

	public:
		static const Sbecore::uint FULL = 1;
		static const Sbecore::uint NONE = 2;
		static const Sbecore::uint VIEW = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVUserlevel (full: VecWzskVUserlevel)
		*/
	class VecVUserlevel {

	public:
		static const Sbecore::uint ADM = 1;
		static const Sbecore::uint GADM = 2;
		static const Sbecore::uint REG = 3;
		static const Sbecore::uint VTOR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVValuelist (full: VecWzskVValuelist)
		*/
	class VecVValuelist {

	public:
		static const Sbecore::uint VLSTWZSKUMPERSONTITLE = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);
	};

	/**
		* VecWAccess (full: VecWzskWAccess)
		*/
	class VecWAccess {

	public:
		static const Sbecore::uint EDIT = 1;
		static const Sbecore::uint EXEC = 2;
		static const Sbecore::uint VIEW = 4;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

public:
	DbsWzsk();
	~DbsWzsk();

	void init(const Sbecore::uint _ixDbsVDbstype, const std::string& _dbspath, const std::string& _dbsname, const std::string& _ip, const Sbecore::uint _port, const std::string& _username, const std::string& _password);
	void term();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void initMy();
	void termMy();
#endif
#if defined(SBECORE_LITE)
	void initLite();
	void termLite();
#endif

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	int port;

	bool initdone;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	MYSQL* dbsMy;
#endif
#if defined(SBECORE_LITE)
	sqlite3* dbsLite;
#endif

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void beginMy();
	bool commitMy();
	void rollbackMy();
#endif
#if defined(SBECORE_LITE)
	void beginLite();
	bool commitLite();
	void rollbackLite();
#endif

	bool loadUintBySQL(const std::string& sqlstr, Sbecore::uint& val);		//!< execute a SQL query returning a single uint (arbitrary tables)
	bool loadStringBySQL(const std::string& sqlstr, std::string& val);//!< execute a SQL query returning a single string (arbitrary tables)

	bool loadRefBySQL(const std::string& sqlstr, Sbecore::ubigint& ref);	//!< execute a SQL query returning a single reference (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	Sbecore::ubigint loadRefsBySQL(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	bool loadUintBySQLMy(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLMy(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLMy(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLMy(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

#if defined(SBECORE_LITE)
	bool loadUintBySQLLite(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLLite(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLLite(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLLite(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

	void executeQuery(const std::string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const std::string& sqlstrmy, const std::string& sqlstrlite);
	void executeFile(const std::string& fullpath);								//!< SQL file batch execution

public:

	void fillFeedFromKlst(const Sbecore::uint klsIxWzskVKeylist, const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	void fillFeedFromKlstByMtbUref(const Sbecore::uint klsIxWzskVKeylist, const Sbecore::uint x1IxWzskVMaintable, const Sbecore::ubigint x1Uref, const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);

	std::string getKlstTitleBySref(const Sbecore::uint klsIxWzskVKeylist, const std::string& sref, const Sbecore::uint ixWzskVLocale = 0);
	std::string getKlstTitleByMtbUrefSref(const Sbecore::uint klsIxWzskVKeylist, const Sbecore::uint x1IxWzskVMaintable, const Sbecore::ubigint x1Uref, const std::string& sref, const Sbecore::uint ixWzskVLocale = 0);

	void fillFeedFromVlst(const Sbecore::uint vlsIxWzskVValuelist, const Sbecore::uint x1IxWzskVLocale, Sbecore::Feed& feed);

public:
	TblWzskAccRMUserUniversal* tblwzskaccrmuseruniversal;
	TblWzskAMPersonDetail* tblwzskampersondetail;
	TblWzskAMUserAccess* tblwzskamuseraccess;
	TblWzskAMUsergroupAccess* tblwzskamusergroupaccess;
	TblWzskAVControlPar* tblwzskavcontrolpar;
	TblWzskAVKeylistKey* tblwzskavkeylistkey;
	TblWzskAVValuelistVal* tblwzskavvaluelistval;
	TblWzskCFile* tblwzskcfile;
	TblWzskHistRMUserUniversal* tblwzskhistrmuseruniversal;
	TblWzskJAVKeylistKey* tblwzskjavkeylistkey;
	TblWzskJMPersonLastname* tblwzskjmpersonlastname;
	TblWzskJMUserState* tblwzskjmuserstate;
	TblWzskMFile* tblwzskmfile;
	TblWzskMPerson* tblwzskmperson;
	TblWzskMSession* tblwzskmsession;
	TblWzskMUser* tblwzskmuser;
	TblWzskMUsergroup* tblwzskmusergroup;
	TblWzskRMUsergroupUniversal* tblwzskrmusergroupuniversal;
	TblWzskRMUserMUsergroup* tblwzskrmusermusergroup;

	TblWzskQFilList* tblwzskqfillist;
	TblWzskQPreselect* tblwzskqpreselect;
	TblWzskQPrsADetail* tblwzskqprsadetail;
	TblWzskQPrsList* tblwzskqprslist;
	TblWzskQSelect* tblwzskqselect;
	TblWzskQUsgAAccess* tblwzskqusgaaccess;
	TblWzskQUsgList* tblwzskqusglist;
	TblWzskQUsgMNUser* tblwzskqusgmnuser;
	TblWzskQUsr1NSession* tblwzskqusr1nsession;
	TblWzskQUsrAAccess* tblwzskqusraaccess;
	TblWzskQUsrList* tblwzskqusrlist;
	TblWzskQUsrMNUsergroup* tblwzskqusrmnusergroup;
};
#endif
