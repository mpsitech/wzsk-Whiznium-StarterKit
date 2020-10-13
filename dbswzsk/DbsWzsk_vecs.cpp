/**
	* \file DbsWzsk_vecs.cpp
	* C++ wrapper for database DbsWzsk (implementation of vectors)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DbsWzsk::VecVCard
 ******************************************************************************/

uint DbsWzsk::VecVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdwzskusg") return CRDWZSKUSG;
	if (s == "crdwzskusr") return CRDWZSKUSR;
	if (s == "crdwzskprs") return CRDWZSKPRS;
	if (s == "crdwzskscf") return CRDWZSKSCF;
	if (s == "crdwzsknav") return CRDWZSKNAV;
	if (s == "crdwzskllv") return CRDWZSKLLV;
	if (s == "crdwzskliv") return CRDWZSKLIV;
	if (s == "crdwzskogr") return CRDWZSKOGR;
	if (s == "crdwzskobj") return CRDWZSKOBJ;
	if (s == "crdwzskses") return CRDWZSKSES;
	if (s == "crdwzsksht") return CRDWZSKSHT;
	if (s == "crdwzskfil") return CRDWZSKFIL;

	return(0);
};

string DbsWzsk::VecVCard::getSref(
			const uint ix
		) {
	if (ix == CRDWZSKUSG) return("CrdWzskUsg");
	if (ix == CRDWZSKUSR) return("CrdWzskUsr");
	if (ix == CRDWZSKPRS) return("CrdWzskPrs");
	if (ix == CRDWZSKSCF) return("CrdWzskScf");
	if (ix == CRDWZSKNAV) return("CrdWzskNav");
	if (ix == CRDWZSKLLV) return("CrdWzskLlv");
	if (ix == CRDWZSKLIV) return("CrdWzskLiv");
	if (ix == CRDWZSKOGR) return("CrdWzskOgr");
	if (ix == CRDWZSKOBJ) return("CrdWzskObj");
	if (ix == CRDWZSKSES) return("CrdWzskSes");
	if (ix == CRDWZSKSHT) return("CrdWzskSht");
	if (ix == CRDWZSKFIL) return("CrdWzskFil");

	return("");
};

string DbsWzsk::VecVCard::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == CRDWZSKUSG) return("user groups");
		if (ix == CRDWZSKUSR) return("users");
		if (ix == CRDWZSKPRS) return("persons");
		if (ix == CRDWZSKSCF) return("system configuration");
		if (ix == CRDWZSKLLV) return("low-level access");
		if (ix == CRDWZSKLIV) return("live data");
		if (ix == CRDWZSKOGR) return("object groups");
		if (ix == CRDWZSKOBJ) return("objects");
		if (ix == CRDWZSKSES) return("sessions");
		if (ix == CRDWZSKSHT) return("shots");
		if (ix == CRDWZSKFIL) return("files");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == CRDWZSKUSG) return("Benutzergruppen");
		if (ix == CRDWZSKUSR) return("Benutzer");
		if (ix == CRDWZSKPRS) return("Personen");
		if (ix == CRDWZSKSCF) return("Systemkonfiguration");
		if (ix == CRDWZSKLLV) return("Low-level Zugriff");
		if (ix == CRDWZSKLIV) return("Livedaten");
		if (ix == CRDWZSKOGR) return("Objektgruppen");
		if (ix == CRDWZSKOBJ) return("Objekte");
		if (ix == CRDWZSKSES) return("Sitzungen");
		if (ix == CRDWZSKSHT) return("Aufnahmen");
		if (ix == CRDWZSKFIL) return("Dateien");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsWzsk::VecVCard::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 12; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

/******************************************************************************
 class DbsWzsk::VecVControl
 ******************************************************************************/

uint DbsWzsk::VecVControl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pnlwzskusglist.tcogrp") return PNLWZSKUSGLIST_TCOGRP;
	if (s == "pnlwzskusglist.tcoown") return PNLWZSKUSGLIST_TCOOWN;
	if (s == "pnlwzskusglist.tcosrf") return PNLWZSKUSGLIST_TCOSRF;
	if (s == "pnlwzskusgaaccess.tcofeg") return PNLWZSKUSGAACCESS_TCOFEG;
	if (s == "pnlwzskusgaaccess.tcofea") return PNLWZSKUSGAACCESS_TCOFEA;
	if (s == "pnlwzskusgaaccess.tcoacc") return PNLWZSKUSGAACCESS_TCOACC;
	if (s == "pnlwzskusgmnuser.tcomref") return PNLWZSKUSGMNUSER_TCOMREF;
	if (s == "pnlwzskusgmnuser.tcoulv") return PNLWZSKUSGMNUSER_TCOULV;
	if (s == "pnlwzskusrlist.tcogrp") return PNLWZSKUSRLIST_TCOGRP;
	if (s == "pnlwzskusrlist.tcoown") return PNLWZSKUSRLIST_TCOOWN;
	if (s == "pnlwzskusrlist.tcoprs") return PNLWZSKUSRLIST_TCOPRS;
	if (s == "pnlwzskusrlist.tcosrf") return PNLWZSKUSRLIST_TCOSRF;
	if (s == "pnlwzskusrlist.tcousg") return PNLWZSKUSRLIST_TCOUSG;
	if (s == "pnlwzskusrlist.tcoste") return PNLWZSKUSRLIST_TCOSTE;
	if (s == "pnlwzskusrlist.tcolcl") return PNLWZSKUSRLIST_TCOLCL;
	if (s == "pnlwzskusrlist.tcoulv") return PNLWZSKUSRLIST_TCOULV;
	if (s == "pnlwzskusraaccess.tcofeg") return PNLWZSKUSRAACCESS_TCOFEG;
	if (s == "pnlwzskusraaccess.tcofea") return PNLWZSKUSRAACCESS_TCOFEA;
	if (s == "pnlwzskusraaccess.tcoacc") return PNLWZSKUSRAACCESS_TCOACC;
	if (s == "pnlwzskusr1nsession.tcoref") return PNLWZSKUSR1NSESSION_TCOREF;
	if (s == "pnlwzskusrmnusergroup.tcomref") return PNLWZSKUSRMNUSERGROUP_TCOMREF;
	if (s == "pnlwzskusrmnusergroup.tcoulv") return PNLWZSKUSRMNUSERGROUP_TCOULV;
	if (s == "pnlwzskprslist.tcogrp") return PNLWZSKPRSLIST_TCOGRP;
	if (s == "pnlwzskprslist.tcoown") return PNLWZSKPRSLIST_TCOOWN;
	if (s == "pnlwzskprslist.tcotit") return PNLWZSKPRSLIST_TCOTIT;
	if (s == "pnlwzskprslist.tcofnm") return PNLWZSKPRSLIST_TCOFNM;
	if (s == "pnlwzskprslist.tcolnm") return PNLWZSKPRSLIST_TCOLNM;
	if (s == "pnlwzskprslist.tcosex") return PNLWZSKPRSLIST_TCOSEX;
	if (s == "pnlwzskprslist.tcotel") return PNLWZSKPRSLIST_TCOTEL;
	if (s == "pnlwzskprslist.tcoeml") return PNLWZSKPRSLIST_TCOEML;
	if (s == "pnlwzskprsadetail.tcotyp") return PNLWZSKPRSADETAIL_TCOTYP;
	if (s == "pnlwzskprsadetail.tcoval") return PNLWZSKPRSADETAIL_TCOVAL;
	if (s == "pnlwzskogrlist.tcosrf") return PNLWZSKOGRLIST_TCOSRF;
	if (s == "pnlwzskogrlist.tcotit") return PNLWZSKOGRLIST_TCOTIT;
	if (s == "pnlwzskogrlist.tcosup") return PNLWZSKOGRLIST_TCOSUP;
	if (s == "pnlwzskogr1nobject.tcoref") return PNLWZSKOGR1NOBJECT_TCOREF;
	if (s == "pnlwzskogrsup1nobjgroup.tcoref") return PNLWZSKOGRSUP1NOBJGROUP_TCOREF;
	if (s == "pnlwzskobjlist.tcotit") return PNLWZSKOBJLIST_TCOTIT;
	if (s == "pnlwzskobjlist.tcoogr") return PNLWZSKOBJLIST_TCOOGR;
	if (s == "pnlwzskobj1nshot.tcoref") return PNLWZSKOBJ1NSHOT_TCOREF;
	if (s == "pnlwzskobjref1nfile.tcoref") return PNLWZSKOBJREF1NFILE_TCOREF;
	if (s == "pnlwzskseslist.tcousr") return PNLWZSKSESLIST_TCOUSR;
	if (s == "pnlwzskseslist.tcosta") return PNLWZSKSESLIST_TCOSTA;
	if (s == "pnlwzskseslist.tcosto") return PNLWZSKSESLIST_TCOSTO;
	if (s == "pnlwzskseslist.tcoip") return PNLWZSKSESLIST_TCOIP;
	if (s == "pnlwzskses1nshot.tcoref") return PNLWZSKSES1NSHOT_TCOREF;
	if (s == "pnlwzskshtlist.tcoses") return PNLWZSKSHTLIST_TCOSES;
	if (s == "pnlwzskshtlist.tcoobj") return PNLWZSKSHTLIST_TCOOBJ;
	if (s == "pnlwzskshtlist.tcosta") return PNLWZSKSHTLIST_TCOSTA;
	if (s == "pnlwzskshtapar.tcokey") return PNLWZSKSHTAPAR_TCOKEY;
	if (s == "pnlwzskshtapar.tcoval") return PNLWZSKSHTAPAR_TCOVAL;
	if (s == "pnlwzskshtref1nfile.tcoref") return PNLWZSKSHTREF1NFILE_TCOREF;
	if (s == "pnlwzskfillist.tcogrp") return PNLWZSKFILLIST_TCOGRP;
	if (s == "pnlwzskfillist.tcoown") return PNLWZSKFILLIST_TCOOWN;
	if (s == "pnlwzskfillist.tcofnm") return PNLWZSKFILLIST_TCOFNM;
	if (s == "pnlwzskfillist.tcoret") return PNLWZSKFILLIST_TCORET;
	if (s == "pnlwzskfillist.tcoreu") return PNLWZSKFILLIST_TCOREU;
	if (s == "pnlwzskfillist.tcocnt") return PNLWZSKFILLIST_TCOCNT;
	if (s == "pnlwzskfillist.tcomim") return PNLWZSKFILLIST_TCOMIM;
	if (s == "pnlwzskfillist.tcosiz") return PNLWZSKFILLIST_TCOSIZ;

	return(0);
};

string DbsWzsk::VecVControl::getSref(
			const uint ix
		) {
	if (ix == PNLWZSKUSGLIST_TCOGRP) return("PnlWzskUsgList.TcoGrp");
	if (ix == PNLWZSKUSGLIST_TCOOWN) return("PnlWzskUsgList.TcoOwn");
	if (ix == PNLWZSKUSGLIST_TCOSRF) return("PnlWzskUsgList.TcoSrf");
	if (ix == PNLWZSKUSGAACCESS_TCOFEG) return("PnlWzskUsgAAccess.TcoFeg");
	if (ix == PNLWZSKUSGAACCESS_TCOFEA) return("PnlWzskUsgAAccess.TcoFea");
	if (ix == PNLWZSKUSGAACCESS_TCOACC) return("PnlWzskUsgAAccess.TcoAcc");
	if (ix == PNLWZSKUSGMNUSER_TCOMREF) return("PnlWzskUsgMNUser.TcoMref");
	if (ix == PNLWZSKUSGMNUSER_TCOULV) return("PnlWzskUsgMNUser.TcoUlv");
	if (ix == PNLWZSKUSRLIST_TCOGRP) return("PnlWzskUsrList.TcoGrp");
	if (ix == PNLWZSKUSRLIST_TCOOWN) return("PnlWzskUsrList.TcoOwn");
	if (ix == PNLWZSKUSRLIST_TCOPRS) return("PnlWzskUsrList.TcoPrs");
	if (ix == PNLWZSKUSRLIST_TCOSRF) return("PnlWzskUsrList.TcoSrf");
	if (ix == PNLWZSKUSRLIST_TCOUSG) return("PnlWzskUsrList.TcoUsg");
	if (ix == PNLWZSKUSRLIST_TCOSTE) return("PnlWzskUsrList.TcoSte");
	if (ix == PNLWZSKUSRLIST_TCOLCL) return("PnlWzskUsrList.TcoLcl");
	if (ix == PNLWZSKUSRLIST_TCOULV) return("PnlWzskUsrList.TcoUlv");
	if (ix == PNLWZSKUSRAACCESS_TCOFEG) return("PnlWzskUsrAAccess.TcoFeg");
	if (ix == PNLWZSKUSRAACCESS_TCOFEA) return("PnlWzskUsrAAccess.TcoFea");
	if (ix == PNLWZSKUSRAACCESS_TCOACC) return("PnlWzskUsrAAccess.TcoAcc");
	if (ix == PNLWZSKUSR1NSESSION_TCOREF) return("PnlWzskUsr1NSession.TcoRef");
	if (ix == PNLWZSKUSRMNUSERGROUP_TCOMREF) return("PnlWzskUsrMNUsergroup.TcoMref");
	if (ix == PNLWZSKUSRMNUSERGROUP_TCOULV) return("PnlWzskUsrMNUsergroup.TcoUlv");
	if (ix == PNLWZSKPRSLIST_TCOGRP) return("PnlWzskPrsList.TcoGrp");
	if (ix == PNLWZSKPRSLIST_TCOOWN) return("PnlWzskPrsList.TcoOwn");
	if (ix == PNLWZSKPRSLIST_TCOTIT) return("PnlWzskPrsList.TcoTit");
	if (ix == PNLWZSKPRSLIST_TCOFNM) return("PnlWzskPrsList.TcoFnm");
	if (ix == PNLWZSKPRSLIST_TCOLNM) return("PnlWzskPrsList.TcoLnm");
	if (ix == PNLWZSKPRSLIST_TCOSEX) return("PnlWzskPrsList.TcoSex");
	if (ix == PNLWZSKPRSLIST_TCOTEL) return("PnlWzskPrsList.TcoTel");
	if (ix == PNLWZSKPRSLIST_TCOEML) return("PnlWzskPrsList.TcoEml");
	if (ix == PNLWZSKPRSADETAIL_TCOTYP) return("PnlWzskPrsADetail.TcoTyp");
	if (ix == PNLWZSKPRSADETAIL_TCOVAL) return("PnlWzskPrsADetail.TcoVal");
	if (ix == PNLWZSKOGRLIST_TCOSRF) return("PnlWzskOgrList.TcoSrf");
	if (ix == PNLWZSKOGRLIST_TCOTIT) return("PnlWzskOgrList.TcoTit");
	if (ix == PNLWZSKOGRLIST_TCOSUP) return("PnlWzskOgrList.TcoSup");
	if (ix == PNLWZSKOGR1NOBJECT_TCOREF) return("PnlWzskOgr1NObject.TcoRef");
	if (ix == PNLWZSKOGRSUP1NOBJGROUP_TCOREF) return("PnlWzskOgrSup1NObjgroup.TcoRef");
	if (ix == PNLWZSKOBJLIST_TCOTIT) return("PnlWzskObjList.TcoTit");
	if (ix == PNLWZSKOBJLIST_TCOOGR) return("PnlWzskObjList.TcoOgr");
	if (ix == PNLWZSKOBJ1NSHOT_TCOREF) return("PnlWzskObj1NShot.TcoRef");
	if (ix == PNLWZSKOBJREF1NFILE_TCOREF) return("PnlWzskObjRef1NFile.TcoRef");
	if (ix == PNLWZSKSESLIST_TCOUSR) return("PnlWzskSesList.TcoUsr");
	if (ix == PNLWZSKSESLIST_TCOSTA) return("PnlWzskSesList.TcoSta");
	if (ix == PNLWZSKSESLIST_TCOSTO) return("PnlWzskSesList.TcoSto");
	if (ix == PNLWZSKSESLIST_TCOIP) return("PnlWzskSesList.TcoIp");
	if (ix == PNLWZSKSES1NSHOT_TCOREF) return("PnlWzskSes1NShot.TcoRef");
	if (ix == PNLWZSKSHTLIST_TCOSES) return("PnlWzskShtList.TcoSes");
	if (ix == PNLWZSKSHTLIST_TCOOBJ) return("PnlWzskShtList.TcoObj");
	if (ix == PNLWZSKSHTLIST_TCOSTA) return("PnlWzskShtList.TcoSta");
	if (ix == PNLWZSKSHTAPAR_TCOKEY) return("PnlWzskShtAPar.TcoKey");
	if (ix == PNLWZSKSHTAPAR_TCOVAL) return("PnlWzskShtAPar.TcoVal");
	if (ix == PNLWZSKSHTREF1NFILE_TCOREF) return("PnlWzskShtRef1NFile.TcoRef");
	if (ix == PNLWZSKFILLIST_TCOGRP) return("PnlWzskFilList.TcoGrp");
	if (ix == PNLWZSKFILLIST_TCOOWN) return("PnlWzskFilList.TcoOwn");
	if (ix == PNLWZSKFILLIST_TCOFNM) return("PnlWzskFilList.TcoFnm");
	if (ix == PNLWZSKFILLIST_TCORET) return("PnlWzskFilList.TcoRet");
	if (ix == PNLWZSKFILLIST_TCOREU) return("PnlWzskFilList.TcoReu");
	if (ix == PNLWZSKFILLIST_TCOCNT) return("PnlWzskFilList.TcoCnt");
	if (ix == PNLWZSKFILLIST_TCOMIM) return("PnlWzskFilList.TcoMim");
	if (ix == PNLWZSKFILLIST_TCOSIZ) return("PnlWzskFilList.TcoSiz");

	return("");
};

/******************************************************************************
 class DbsWzsk::VecVFeatgroup
 ******************************************************************************/

uint DbsWzsk::VecVFeatgroup::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vecwzskvcard") return VECWZSKVCARD;
	if (s == "vecvjobwzskacqpreviewvar") return VECVJOBWZSKACQPREVIEWVAR;
	if (s == "vecvjobwzskacqptcloudmethod") return VECVJOBWZSKACQPTCLOUDMETHOD;
	if (s == "vecvjobwzskacqptcloudvar") return VECVJOBWZSKACQPTCLOUDVAR;
	if (s == "vecvjobwzskactexposuremethod") return VECVJOBWZSKACTEXPOSUREMETHOD;
	if (s == "vecvjobwzskactexposurevar") return VECVJOBWZSKACTEXPOSUREVAR;
	if (s == "vecvjobwzskactlasermethod") return VECVJOBWZSKACTLASERMETHOD;
	if (s == "vecvjobwzskactlaservar") return VECVJOBWZSKACTLASERVAR;
	if (s == "vecvjobwzskactservomethod") return VECVJOBWZSKACTSERVOMETHOD;
	if (s == "vecvjobwzskactservovar") return VECVJOBWZSKACTSERVOVAR;
	if (s == "vecvjobwzskiprcornermethod") return VECVJOBWZSKIPRCORNERMETHOD;
	if (s == "vecvjobwzskiprcornervar") return VECVJOBWZSKIPRCORNERVAR;
	if (s == "vecvjobwzskiprtracemethod") return VECVJOBWZSKIPRTRACEMETHOD;
	if (s == "vecvjobwzskiprtracevar") return VECVJOBWZSKIPRTRACEVAR;
	if (s == "vecvjobwzsksrcsysinfovar") return VECVJOBWZSKSRCSYSINFOVAR;

	return(0);
};

string DbsWzsk::VecVFeatgroup::getSref(
			const uint ix
		) {
	if (ix == VECWZSKVCARD) return("VecWzskVCard");
	if (ix == VECVJOBWZSKACQPREVIEWVAR) return("VecVJobWzskAcqPreviewVar");
	if (ix == VECVJOBWZSKACQPTCLOUDMETHOD) return("VecVJobWzskAcqPtcloudMethod");
	if (ix == VECVJOBWZSKACQPTCLOUDVAR) return("VecVJobWzskAcqPtcloudVar");
	if (ix == VECVJOBWZSKACTEXPOSUREMETHOD) return("VecVJobWzskActExposureMethod");
	if (ix == VECVJOBWZSKACTEXPOSUREVAR) return("VecVJobWzskActExposureVar");
	if (ix == VECVJOBWZSKACTLASERMETHOD) return("VecVJobWzskActLaserMethod");
	if (ix == VECVJOBWZSKACTLASERVAR) return("VecVJobWzskActLaserVar");
	if (ix == VECVJOBWZSKACTSERVOMETHOD) return("VecVJobWzskActServoMethod");
	if (ix == VECVJOBWZSKACTSERVOVAR) return("VecVJobWzskActServoVar");
	if (ix == VECVJOBWZSKIPRCORNERMETHOD) return("VecVJobWzskIprCornerMethod");
	if (ix == VECVJOBWZSKIPRCORNERVAR) return("VecVJobWzskIprCornerVar");
	if (ix == VECVJOBWZSKIPRTRACEMETHOD) return("VecVJobWzskIprTraceMethod");
	if (ix == VECVJOBWZSKIPRTRACEVAR) return("VecVJobWzskIprTraceVar");
	if (ix == VECVJOBWZSKSRCSYSINFOVAR) return("VecVJobWzskSrcSysinfoVar");

	return("");
};

string DbsWzsk::VecVFeatgroup::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == VECWZSKVCARD) return("card");
		if (ix == VECVJOBWZSKACQPREVIEWVAR) return("JobWzskAcqPreview variable");
		if (ix == VECVJOBWZSKACQPTCLOUDMETHOD) return("JobWzskAcqPtcloud method");
		if (ix == VECVJOBWZSKACQPTCLOUDVAR) return("JobWzskAcqPtcloud variable");
		if (ix == VECVJOBWZSKACTEXPOSUREMETHOD) return("JobWzskActExposure method");
		if (ix == VECVJOBWZSKACTEXPOSUREVAR) return("JobWzskActExposure variable");
		if (ix == VECVJOBWZSKACTLASERMETHOD) return("JobWzskActLaser method");
		if (ix == VECVJOBWZSKACTLASERVAR) return("JobWzskActLaser variable");
		if (ix == VECVJOBWZSKACTSERVOMETHOD) return("JobWzskActServo method");
		if (ix == VECVJOBWZSKACTSERVOVAR) return("JobWzskActServo variable");
		if (ix == VECVJOBWZSKIPRCORNERMETHOD) return("JobWzskIprCorner method");
		if (ix == VECVJOBWZSKIPRCORNERVAR) return("JobWzskIprCorner variable");
		if (ix == VECVJOBWZSKIPRTRACEMETHOD) return("JobWzskIprTrace method");
		if (ix == VECVJOBWZSKIPRTRACEVAR) return("JobWzskIprTrace variable");
		if (ix == VECVJOBWZSKSRCSYSINFOVAR) return("JobWzskSrcSysinfo variable");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == VECWZSKVCARD) return("Karte");
		if (ix == VECVJOBWZSKACQPREVIEWVAR) return("JobWzskAcqPreview Variable");
		if (ix == VECVJOBWZSKACQPTCLOUDMETHOD) return("JobWzskAcqPtcloud Methode");
		if (ix == VECVJOBWZSKACQPTCLOUDVAR) return("JobWzskAcqPtcloud Variable");
		if (ix == VECVJOBWZSKACTEXPOSUREMETHOD) return("JobWzskActExposure Methode");
		if (ix == VECVJOBWZSKACTEXPOSUREVAR) return("JobWzskActExposure Variable");
		if (ix == VECVJOBWZSKACTLASERMETHOD) return("JobWzskActLaser Methode");
		if (ix == VECVJOBWZSKACTLASERVAR) return("JobWzskActLaser Variable");
		if (ix == VECVJOBWZSKACTSERVOMETHOD) return("JobWzskActServo Methode");
		if (ix == VECVJOBWZSKACTSERVOVAR) return("JobWzskActServo Variable");
		if (ix == VECVJOBWZSKIPRCORNERMETHOD) return("JobWzskIprCorner Methode");
		if (ix == VECVJOBWZSKIPRCORNERVAR) return("JobWzskIprCorner Variable");
		if (ix == VECVJOBWZSKIPRTRACEMETHOD) return("JobWzskIprTrace Methode");
		if (ix == VECVJOBWZSKIPRTRACEVAR) return("JobWzskIprTrace Variable");
		if (ix == VECVJOBWZSKSRCSYSINFOVAR) return("JobWzskSrcSysinfo Variable");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsWzsk::VecVFeatgroup::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 15; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

/******************************************************************************
 class DbsWzsk::VecVKeylist
 ******************************************************************************/

uint DbsWzsk::VecVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstwzskkampersondetailtype") return KLSTWZSKKAMPERSONDETAILTYPE;
	if (s == "klstwzskkmfilecontent") return KLSTWZSKKMFILECONTENT;
	if (s == "klstwzskkmfilemimetype") return KLSTWZSKKMFILEMIMETYPE;
	if (s == "klstwzskkmshotparkey") return KLSTWZSKKMSHOTPARKEY;

	return(0);
};

string DbsWzsk::VecVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTWZSKKAMPERSONDETAILTYPE) return("KlstWzskKAMPersonDetailType");
	if (ix == KLSTWZSKKMFILECONTENT) return("KlstWzskKMFileContent");
	if (ix == KLSTWZSKKMFILEMIMETYPE) return("KlstWzskKMFileMimetype");
	if (ix == KLSTWZSKKMSHOTPARKEY) return("KlstWzskKMShotParKey");

	return("");
};

string DbsWzsk::VecVKeylist::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == KLSTWZSKKAMPERSONDETAILTYPE) return("type");
		if (ix == KLSTWZSKKMFILECONTENT) return("content");
		if (ix == KLSTWZSKKMFILEMIMETYPE) return("MIME type");
		if (ix == KLSTWZSKKMSHOTPARKEY) return("key");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == KLSTWZSKKAMPERSONDETAILTYPE) return("Typ");
		if (ix == KLSTWZSKKMFILECONTENT) return("Inhalt");
		if (ix == KLSTWZSKKMFILEMIMETYPE) return("MIME-Typ");
		if (ix == KLSTWZSKKMSHOTPARKEY) return("Schl\\u00fcssel");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsWzsk::VecVLat
 ******************************************************************************/

uint DbsWzsk::VecVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	if (s == "ini") return INI;

	return(0);
};

string DbsWzsk::VecVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	if (ix == INI) return("ini");

	return("");
};

/******************************************************************************
 class DbsWzsk::VecVLocale
 ******************************************************************************/

uint DbsWzsk::VecVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;
	if (s == "dech") return DECH;

	return(0);
};

string DbsWzsk::VecVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");
	if (ix == DECH) return("dech");

	return("");
};

string DbsWzsk::VecVLocale::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		if (ix == DECH) return("German (Switzerland)");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == ENUS) return("Englisch (Vereinigte Staaten)");
		if (ix == DECH) return("Deutsch (Schweiz)");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsWzsk::VecVLocale::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

/******************************************************************************
 class DbsWzsk::VecVLop
 ******************************************************************************/

uint DbsWzsk::VecVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "rmv") return RMV;

	return(0);
};

string DbsWzsk::VecVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RMV) return("rmv");

	return("");
};

/******************************************************************************
 class DbsWzsk::VecVMaintable
 ******************************************************************************/

uint DbsWzsk::VecVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tblwzskmfile") return TBLWZSKMFILE;
	if (s == "tblwzskmobject") return TBLWZSKMOBJECT;
	if (s == "tblwzskmobjgroup") return TBLWZSKMOBJGROUP;
	if (s == "tblwzskmperson") return TBLWZSKMPERSON;
	if (s == "tblwzskmsession") return TBLWZSKMSESSION;
	if (s == "tblwzskmshot") return TBLWZSKMSHOT;
	if (s == "tblwzskmuser") return TBLWZSKMUSER;
	if (s == "tblwzskmusergroup") return TBLWZSKMUSERGROUP;

	return(0);
};

string DbsWzsk::VecVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBLWZSKMFILE) return("TblWzskMFile");
	if (ix == TBLWZSKMOBJECT) return("TblWzskMObject");
	if (ix == TBLWZSKMOBJGROUP) return("TblWzskMObjgroup");
	if (ix == TBLWZSKMPERSON) return("TblWzskMPerson");
	if (ix == TBLWZSKMSESSION) return("TblWzskMSession");
	if (ix == TBLWZSKMSHOT) return("TblWzskMShot");
	if (ix == TBLWZSKMUSER) return("TblWzskMUser");
	if (ix == TBLWZSKMUSERGROUP) return("TblWzskMUsergroup");

	return("");
};

string DbsWzsk::VecVMaintable::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBLWZSKMFILE) return("file");
		if (ix == TBLWZSKMOBJECT) return("object");
		if (ix == TBLWZSKMOBJGROUP) return("object group");
		if (ix == TBLWZSKMPERSON) return("person");
		if (ix == TBLWZSKMSESSION) return("session");
		if (ix == TBLWZSKMSHOT) return("shot");
		if (ix == TBLWZSKMUSER) return("user");
		if (ix == TBLWZSKMUSERGROUP) return("user group");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == VOID) return("kein");
		if (ix == TBLWZSKMFILE) return("Datei");
		if (ix == TBLWZSKMOBJECT) return("Objekt");
		if (ix == TBLWZSKMOBJGROUP) return("Objektgruppe");
		if (ix == TBLWZSKMPERSON) return("Person");
		if (ix == TBLWZSKMSESSION) return("Sitzung");
		if (ix == TBLWZSKMSHOT) return("Aufnahme");
		if (ix == TBLWZSKMUSER) return("Benutzer");
		if (ix == TBLWZSKMUSERGROUP) return("Benutzergruppe");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsWzsk::VecVMaintable::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 9; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

/******************************************************************************
 class DbsWzsk::VecVOolop
 ******************************************************************************/

uint DbsWzsk::VecVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	if (s == "inb") return INB;
	if (s == "rmv") return RMV;
	if (s == "swp") return SWP;
	if (s == "toa") return TOA;
	if (s == "tob") return TOB;

	return(0);
};

string DbsWzsk::VecVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	if (ix == INB) return("inb");
	if (ix == RMV) return("rmv");
	if (ix == SWP) return("swp");
	if (ix == TOA) return("toa");
	if (ix == TOB) return("tob");

	return("");
};

/******************************************************************************
 class DbsWzsk::VecVPreset
 ******************************************************************************/

uint DbsWzsk::VecVPreset::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "prewzskadmin") return PREWZSKADMIN;
	if (s == "prewzskfillist.fnm") return PREWZSKFILLIST_FNM;
	if (s == "prewzskfillist.grp") return PREWZSKFILLIST_GRP;
	if (s == "prewzskfillist.own") return PREWZSKFILLIST_OWN;
	if (s == "prewzskfillist.ret") return PREWZSKFILLIST_RET;
	if (s == "prewzskfillist.reu") return PREWZSKFILLIST_REU;
	if (s == "prewzskgroup") return PREWZSKGROUP;
	if (s == "prewzskip") return PREWZSKIP;
	if (s == "prewzskixcrdaccfil") return PREWZSKIXCRDACCFIL;
	if (s == "prewzskixcrdaccliv") return PREWZSKIXCRDACCLIV;
	if (s == "prewzskixcrdaccllv") return PREWZSKIXCRDACCLLV;
	if (s == "prewzskixcrdaccobj") return PREWZSKIXCRDACCOBJ;
	if (s == "prewzskixcrdaccogr") return PREWZSKIXCRDACCOGR;
	if (s == "prewzskixcrdaccprs") return PREWZSKIXCRDACCPRS;
	if (s == "prewzskixcrdaccscf") return PREWZSKIXCRDACCSCF;
	if (s == "prewzskixcrdaccses") return PREWZSKIXCRDACCSES;
	if (s == "prewzskixcrdaccsht") return PREWZSKIXCRDACCSHT;
	if (s == "prewzskixcrdaccusg") return PREWZSKIXCRDACCUSG;
	if (s == "prewzskixcrdaccusr") return PREWZSKIXCRDACCUSR;
	if (s == "prewzskixlcl") return PREWZSKIXLCL;
	if (s == "prewzskixord") return PREWZSKIXORD;
	if (s == "prewzskixpre") return PREWZSKIXPRE;
	if (s == "prewzskixrecacc") return PREWZSKIXRECACC;
	if (s == "prewzskjrefnotify") return PREWZSKJREFNOTIFY;
	if (s == "prewzskjrefsess") return PREWZSKJREFSESS;
	if (s == "prewzsknoadm") return PREWZSKNOADM;
	if (s == "prewzskobjlist.ogr") return PREWZSKOBJLIST_OGR;
	if (s == "prewzskobjlist.tit") return PREWZSKOBJLIST_TIT;
	if (s == "prewzskogrlist.srf") return PREWZSKOGRLIST_SRF;
	if (s == "prewzskogrlist.sup") return PREWZSKOGRLIST_SUP;
	if (s == "prewzskogrlist.tit") return PREWZSKOGRLIST_TIT;
	if (s == "prewzskowner") return PREWZSKOWNER;
	if (s == "prewzskprsadetail.x1") return PREWZSKPRSADETAIL_X1;
	if (s == "prewzskprslist.grp") return PREWZSKPRSLIST_GRP;
	if (s == "prewzskprslist.lnm") return PREWZSKPRSLIST_LNM;
	if (s == "prewzskprslist.own") return PREWZSKPRSLIST_OWN;
	if (s == "prewzskreffil") return PREWZSKREFFIL;
	if (s == "prewzskrefobj") return PREWZSKREFOBJ;
	if (s == "prewzskrefogr") return PREWZSKREFOGR;
	if (s == "prewzskrefprs") return PREWZSKREFPRS;
	if (s == "prewzskrefsel") return PREWZSKREFSEL;
	if (s == "prewzskrefses") return PREWZSKREFSES;
	if (s == "prewzskrefsht") return PREWZSKREFSHT;
	if (s == "prewzskrefusg") return PREWZSKREFUSG;
	if (s == "prewzskrefusr") return PREWZSKREFUSR;
	if (s == "prewzskseslist.sta") return PREWZSKSESLIST_STA;
	if (s == "prewzskseslist.usr") return PREWZSKSESLIST_USR;
	if (s == "prewzsksess") return PREWZSKSESS;
	if (s == "prewzskshtapar.x1") return PREWZSKSHTAPAR_X1;
	if (s == "prewzskshtlist.obj") return PREWZSKSHTLIST_OBJ;
	if (s == "prewzskshtlist.ses") return PREWZSKSHTLIST_SES;
	if (s == "prewzskshtlist.sta") return PREWZSKSHTLIST_STA;
	if (s == "prewzsksuspsess") return PREWZSKSUSPSESS;
	if (s == "prewzsksysdate") return PREWZSKSYSDATE;
	if (s == "prewzsksysstamp") return PREWZSKSYSSTAMP;
	if (s == "prewzsksystime") return PREWZSKSYSTIME;
	if (s == "prewzskusgaaccess.x1") return PREWZSKUSGAACCESS_X1;
	if (s == "prewzskusgaaccess.x2") return PREWZSKUSGAACCESS_X2;
	if (s == "prewzskusglist.grp") return PREWZSKUSGLIST_GRP;
	if (s == "prewzskusglist.own") return PREWZSKUSGLIST_OWN;
	if (s == "prewzskusglist.srf") return PREWZSKUSGLIST_SRF;
	if (s == "prewzskusraaccess.x1") return PREWZSKUSRAACCESS_X1;
	if (s == "prewzskusraaccess.x2") return PREWZSKUSRAACCESS_X2;
	if (s == "prewzskusrlist.grp") return PREWZSKUSRLIST_GRP;
	if (s == "prewzskusrlist.own") return PREWZSKUSRLIST_OWN;
	if (s == "prewzskusrlist.prs") return PREWZSKUSRLIST_PRS;
	if (s == "prewzskusrlist.srf") return PREWZSKUSRLIST_SRF;
	if (s == "prewzskusrlist.ste") return PREWZSKUSRLIST_STE;
	if (s == "prewzskusrlist.usg") return PREWZSKUSRLIST_USG;

	return(0);
};

string DbsWzsk::VecVPreset::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PREWZSKADMIN) return("PreWzskAdmin");
	if (ix == PREWZSKFILLIST_FNM) return("PreWzskFilList.fnm");
	if (ix == PREWZSKFILLIST_GRP) return("PreWzskFilList.grp");
	if (ix == PREWZSKFILLIST_OWN) return("PreWzskFilList.own");
	if (ix == PREWZSKFILLIST_RET) return("PreWzskFilList.ret");
	if (ix == PREWZSKFILLIST_REU) return("PreWzskFilList.reu");
	if (ix == PREWZSKGROUP) return("PreWzskGroup");
	if (ix == PREWZSKIP) return("PreWzskIp");
	if (ix == PREWZSKIXCRDACCFIL) return("PreWzskIxCrdaccFil");
	if (ix == PREWZSKIXCRDACCLIV) return("PreWzskIxCrdaccLiv");
	if (ix == PREWZSKIXCRDACCLLV) return("PreWzskIxCrdaccLlv");
	if (ix == PREWZSKIXCRDACCOBJ) return("PreWzskIxCrdaccObj");
	if (ix == PREWZSKIXCRDACCOGR) return("PreWzskIxCrdaccOgr");
	if (ix == PREWZSKIXCRDACCPRS) return("PreWzskIxCrdaccPrs");
	if (ix == PREWZSKIXCRDACCSCF) return("PreWzskIxCrdaccScf");
	if (ix == PREWZSKIXCRDACCSES) return("PreWzskIxCrdaccSes");
	if (ix == PREWZSKIXCRDACCSHT) return("PreWzskIxCrdaccSht");
	if (ix == PREWZSKIXCRDACCUSG) return("PreWzskIxCrdaccUsg");
	if (ix == PREWZSKIXCRDACCUSR) return("PreWzskIxCrdaccUsr");
	if (ix == PREWZSKIXLCL) return("PreWzskIxLcl");
	if (ix == PREWZSKIXORD) return("PreWzskIxOrd");
	if (ix == PREWZSKIXPRE) return("PreWzskIxPre");
	if (ix == PREWZSKIXRECACC) return("PreWzskIxRecacc");
	if (ix == PREWZSKJREFNOTIFY) return("PreWzskJrefNotify");
	if (ix == PREWZSKJREFSESS) return("PreWzskJrefSess");
	if (ix == PREWZSKNOADM) return("PreWzskNoadm");
	if (ix == PREWZSKOBJLIST_OGR) return("PreWzskObjList.ogr");
	if (ix == PREWZSKOBJLIST_TIT) return("PreWzskObjList.tit");
	if (ix == PREWZSKOGRLIST_SRF) return("PreWzskOgrList.srf");
	if (ix == PREWZSKOGRLIST_SUP) return("PreWzskOgrList.sup");
	if (ix == PREWZSKOGRLIST_TIT) return("PreWzskOgrList.tit");
	if (ix == PREWZSKOWNER) return("PreWzskOwner");
	if (ix == PREWZSKPRSADETAIL_X1) return("PreWzskPrsADetail.x1");
	if (ix == PREWZSKPRSLIST_GRP) return("PreWzskPrsList.grp");
	if (ix == PREWZSKPRSLIST_LNM) return("PreWzskPrsList.lnm");
	if (ix == PREWZSKPRSLIST_OWN) return("PreWzskPrsList.own");
	if (ix == PREWZSKREFFIL) return("PreWzskRefFil");
	if (ix == PREWZSKREFOBJ) return("PreWzskRefObj");
	if (ix == PREWZSKREFOGR) return("PreWzskRefOgr");
	if (ix == PREWZSKREFPRS) return("PreWzskRefPrs");
	if (ix == PREWZSKREFSEL) return("PreWzskRefSel");
	if (ix == PREWZSKREFSES) return("PreWzskRefSes");
	if (ix == PREWZSKREFSHT) return("PreWzskRefSht");
	if (ix == PREWZSKREFUSG) return("PreWzskRefUsg");
	if (ix == PREWZSKREFUSR) return("PreWzskRefUsr");
	if (ix == PREWZSKSESLIST_STA) return("PreWzskSesList.sta");
	if (ix == PREWZSKSESLIST_USR) return("PreWzskSesList.usr");
	if (ix == PREWZSKSESS) return("PreWzskSess");
	if (ix == PREWZSKSHTAPAR_X1) return("PreWzskShtAPar.x1");
	if (ix == PREWZSKSHTLIST_OBJ) return("PreWzskShtList.obj");
	if (ix == PREWZSKSHTLIST_SES) return("PreWzskShtList.ses");
	if (ix == PREWZSKSHTLIST_STA) return("PreWzskShtList.sta");
	if (ix == PREWZSKSUSPSESS) return("PreWzskSuspsess");
	if (ix == PREWZSKSYSDATE) return("PreWzskSysdate");
	if (ix == PREWZSKSYSSTAMP) return("PreWzskSysstamp");
	if (ix == PREWZSKSYSTIME) return("PreWzskSystime");
	if (ix == PREWZSKUSGAACCESS_X1) return("PreWzskUsgAAccess.x1");
	if (ix == PREWZSKUSGAACCESS_X2) return("PreWzskUsgAAccess.x2");
	if (ix == PREWZSKUSGLIST_GRP) return("PreWzskUsgList.grp");
	if (ix == PREWZSKUSGLIST_OWN) return("PreWzskUsgList.own");
	if (ix == PREWZSKUSGLIST_SRF) return("PreWzskUsgList.srf");
	if (ix == PREWZSKUSRAACCESS_X1) return("PreWzskUsrAAccess.x1");
	if (ix == PREWZSKUSRAACCESS_X2) return("PreWzskUsrAAccess.x2");
	if (ix == PREWZSKUSRLIST_GRP) return("PreWzskUsrList.grp");
	if (ix == PREWZSKUSRLIST_OWN) return("PreWzskUsrList.own");
	if (ix == PREWZSKUSRLIST_PRS) return("PreWzskUsrList.prs");
	if (ix == PREWZSKUSRLIST_SRF) return("PreWzskUsrList.srf");
	if (ix == PREWZSKUSRLIST_STE) return("PreWzskUsrList.ste");
	if (ix == PREWZSKUSRLIST_USG) return("PreWzskUsrList.usg");

	return("");
};

string DbsWzsk::VecVPreset::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == PREWZSKREFFIL) return("file");
		if (ix == PREWZSKREFOBJ) return("object");
		if (ix == PREWZSKREFOGR) return("object group");
		if (ix == PREWZSKREFPRS) return("person");
		if (ix == PREWZSKREFSES) return("session");
		if (ix == PREWZSKREFSHT) return("shot");
		if (ix == PREWZSKREFUSG) return("user group");
		if (ix == PREWZSKREFUSR) return("user");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == VOID) return("kein");
		if (ix == PREWZSKREFFIL) return("Datei");
		if (ix == PREWZSKREFOBJ) return("Objekt");
		if (ix == PREWZSKREFOGR) return("Objektgruppe");
		if (ix == PREWZSKREFPRS) return("Person");
		if (ix == PREWZSKREFSES) return("Sitzung");
		if (ix == PREWZSKREFSHT) return("Aufnahme");
		if (ix == PREWZSKREFUSG) return("Benutzergruppe");
		if (ix == PREWZSKREFUSR) return("Benutzer");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsWzsk::VecVRecaccess
 ******************************************************************************/

uint DbsWzsk::VecVRecaccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	if (s == "none") return NONE;
	if (s == "view") return VIEW;

	return(0);
};

string DbsWzsk::VecVRecaccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	if (ix == NONE) return("none");
	if (ix == VIEW) return("view");

	return("");
};

string DbsWzsk::VecVRecaccess::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == FULL) return("full");
		if (ix == NONE) return("none");
		if (ix == VIEW) return("view");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == FULL) return("voll");
		if (ix == NONE) return("kein");
		if (ix == VIEW) return("anschauen");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsWzsk::VecVRecaccess::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

/******************************************************************************
 class DbsWzsk::VecVUserlevel
 ******************************************************************************/

uint DbsWzsk::VecVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	if (s == "gadm") return GADM;
	if (s == "reg") return REG;
	if (s == "vtor") return VTOR;

	return(0);
};

string DbsWzsk::VecVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	if (ix == GADM) return("gadm");
	if (ix == REG) return("reg");
	if (ix == VTOR) return("vtor");

	return("");
};

string DbsWzsk::VecVUserlevel::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == ADM) return("administrator");
		if (ix == GADM) return("user group administrator");
		if (ix == REG) return("regular user");
		if (ix == VTOR) return("visitor");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == ADM) return("Administrator");
		if (ix == GADM) return("Gruppenadministrator");
		if (ix == REG) return("regul\\u00e4rer Benutzer");
		if (ix == VTOR) return("Besucher");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsWzsk::VecVUserlevel::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

/******************************************************************************
 class DbsWzsk::VecVValuelist
 ******************************************************************************/

uint DbsWzsk::VecVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstwzskumpersontitle") return VLSTWZSKUMPERSONTITLE;

	return(0);
};

string DbsWzsk::VecVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTWZSKUMPERSONTITLE) return("VlstWzskUMPersonTitle");

	return("");
};

string DbsWzsk::VecVValuelist::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == VLSTWZSKUMPERSONTITLE) return("title");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == VLSTWZSKUMPERSONTITLE) return("Anrede");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsWzsk::VecWAccess
 ******************************************************************************/

uint DbsWzsk::VecWAccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void DbsWzsk::VecWAccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VIEW); i *= 2) if (ix & i) ics.insert(i);
};

string DbsWzsk::VecWAccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsWzsk::VecWAccess::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == EDIT) return("edit");
		if (ix == EXEC) return("execute");
		if (ix == VIEW) return("view");
		return(getSrefs(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == EDIT) return("\\u00e4ndern");
		if (ix == EXEC) return("ausf\\u00fchren");
		if (ix == VIEW) return("anschauen");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsWzsk::VecWAccess::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= VIEW; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWzskVLocale));
};

