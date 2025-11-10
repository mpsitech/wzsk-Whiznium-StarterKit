/**
	* \file DbsWzsk_vecs.cpp
	* C++ wrapper for database DbsWzsk (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

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

	if (s == "crdwzsknav") return CRDWZSKNAV;
	if (s == "crdwzskusg") return CRDWZSKUSG;
	if (s == "crdwzskusr") return CRDWZSKUSR;
	if (s == "crdwzskprs") return CRDWZSKPRS;
	if (s == "crdwzskprf") return CRDWZSKPRF;
	if (s == "crdwzskllv") return CRDWZSKLLV;
	if (s == "crdwzskvtr") return CRDWZSKVTR;
	if (s == "crdwzskhwc") return CRDWZSKHWC;
	if (s == "crdwzskfil") return CRDWZSKFIL;

	return(0);
};

string DbsWzsk::VecVCard::getSref(
			const uint ix
		) {
	if (ix == CRDWZSKNAV) return("CrdWzskNav");
	if (ix == CRDWZSKUSG) return("CrdWzskUsg");
	if (ix == CRDWZSKUSR) return("CrdWzskUsr");
	if (ix == CRDWZSKPRS) return("CrdWzskPrs");
	if (ix == CRDWZSKPRF) return("CrdWzskPrf");
	if (ix == CRDWZSKLLV) return("CrdWzskLlv");
	if (ix == CRDWZSKVTR) return("CrdWzskVtr");
	if (ix == CRDWZSKHWC) return("CrdWzskHwc");
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
		if (ix == CRDWZSKPRF) return("preferences");
		if (ix == CRDWZSKLLV) return("low-level access");
		if (ix == CRDWZSKVTR) return("vision-to-rotary");
		if (ix == CRDWZSKHWC) return("HDR wavelet classification");
		if (ix == CRDWZSKFIL) return("files");
		return(getSref(ix));
	};

	return("");
};

void DbsWzsk::VecVCard::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 9; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
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
	if (s == "vecvjobwzskacqcornermethod") return VECVJOBWZSKACQCORNERMETHOD;
	if (s == "vecvjobwzskacqcornervar") return VECVJOBWZSKACQCORNERVAR;
	if (s == "vecvjobwzskacqtracemethod") return VECVJOBWZSKACQTRACEMETHOD;
	if (s == "vecvjobwzskacqtracevar") return VECVJOBWZSKACQTRACEVAR;
	if (s == "vecvjobwzskactlasermethod") return VECVJOBWZSKACTLASERMETHOD;
	if (s == "vecvjobwzskactlaservar") return VECVJOBWZSKACTLASERVAR;
	if (s == "vecvjobwzskactrotarymethod") return VECVJOBWZSKACTROTARYMETHOD;
	if (s == "vecvjobwzskactrotaryvar") return VECVJOBWZSKACTROTARYVAR;
	if (s == "vecvjobwzsksrcfpgainfovar") return VECVJOBWZSKSRCFPGAINFOVAR;
	if (s == "vecvjobwzsksrcsysinfovar") return VECVJOBWZSKSRCSYSINFOVAR;

	return(0);
};

string DbsWzsk::VecVFeatgroup::getSref(
			const uint ix
		) {
	if (ix == VECWZSKVCARD) return("VecWzskVCard");
	if (ix == VECVJOBWZSKACQCORNERMETHOD) return("VecVJobWzskAcqCornerMethod");
	if (ix == VECVJOBWZSKACQCORNERVAR) return("VecVJobWzskAcqCornerVar");
	if (ix == VECVJOBWZSKACQTRACEMETHOD) return("VecVJobWzskAcqTraceMethod");
	if (ix == VECVJOBWZSKACQTRACEVAR) return("VecVJobWzskAcqTraceVar");
	if (ix == VECVJOBWZSKACTLASERMETHOD) return("VecVJobWzskActLaserMethod");
	if (ix == VECVJOBWZSKACTLASERVAR) return("VecVJobWzskActLaserVar");
	if (ix == VECVJOBWZSKACTROTARYMETHOD) return("VecVJobWzskActRotaryMethod");
	if (ix == VECVJOBWZSKACTROTARYVAR) return("VecVJobWzskActRotaryVar");
	if (ix == VECVJOBWZSKSRCFPGAINFOVAR) return("VecVJobWzskSrcFpgainfoVar");
	if (ix == VECVJOBWZSKSRCSYSINFOVAR) return("VecVJobWzskSrcSysinfoVar");

	return("");
};

string DbsWzsk::VecVFeatgroup::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == VECWZSKVCARD) return("card");
		if (ix == VECVJOBWZSKACQCORNERMETHOD) return("JobWzskAcqCorner method");
		if (ix == VECVJOBWZSKACQCORNERVAR) return("JobWzskAcqCorner variable");
		if (ix == VECVJOBWZSKACQTRACEMETHOD) return("JobWzskAcqTrace method");
		if (ix == VECVJOBWZSKACQTRACEVAR) return("JobWzskAcqTrace variable");
		if (ix == VECVJOBWZSKACTLASERMETHOD) return("JobWzskActLaser method");
		if (ix == VECVJOBWZSKACTLASERVAR) return("JobWzskActLaser variable");
		if (ix == VECVJOBWZSKACTROTARYMETHOD) return("JobWzskActRotary method");
		if (ix == VECVJOBWZSKACTROTARYVAR) return("JobWzskActRotary variable");
		if (ix == VECVJOBWZSKSRCFPGAINFOVAR) return("JobWzskSrcFpgainfo variable");
		if (ix == VECVJOBWZSKSRCSYSINFOVAR) return("JobWzskSrcSysinfo variable");
		return(getSref(ix));
	};

	return("");
};

void DbsWzsk::VecVFeatgroup::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 11; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
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

	return(0);
};

string DbsWzsk::VecVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTWZSKKAMPERSONDETAILTYPE) return("KlstWzskKAMPersonDetailType");
	if (ix == KLSTWZSKKMFILECONTENT) return("KlstWzskKMFileContent");
	if (ix == KLSTWZSKKMFILEMIMETYPE) return("KlstWzskKMFileMimetype");

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
		return(getSref(ix));
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

	return(0);
};

string DbsWzsk::VecVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");

	return("");
};

string DbsWzsk::VecVLocale::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		return(getSref(ix));
	};

	return("");
};

void DbsWzsk::VecVLocale::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
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
	if (s == "tblwzskmperson") return TBLWZSKMPERSON;
	if (s == "tblwzskmsession") return TBLWZSKMSESSION;
	if (s == "tblwzskmuser") return TBLWZSKMUSER;
	if (s == "tblwzskmusergroup") return TBLWZSKMUSERGROUP;

	return(0);
};

string DbsWzsk::VecVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBLWZSKMFILE) return("TblWzskMFile");
	if (ix == TBLWZSKMPERSON) return("TblWzskMPerson");
	if (ix == TBLWZSKMSESSION) return("TblWzskMSession");
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
		if (ix == TBLWZSKMPERSON) return("person");
		if (ix == TBLWZSKMSESSION) return("session");
		if (ix == TBLWZSKMUSER) return("user");
		if (ix == TBLWZSKMUSERGROUP) return("user group");
		return(getSref(ix));
	};

	return("");
};

void DbsWzsk::VecVMaintable::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
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
	if (s == "prewzskixcrdacchwc") return PREWZSKIXCRDACCHWC;
	if (s == "prewzskixcrdaccllv") return PREWZSKIXCRDACCLLV;
	if (s == "prewzskixcrdaccprf") return PREWZSKIXCRDACCPRF;
	if (s == "prewzskixcrdaccprs") return PREWZSKIXCRDACCPRS;
	if (s == "prewzskixcrdaccusg") return PREWZSKIXCRDACCUSG;
	if (s == "prewzskixcrdaccusr") return PREWZSKIXCRDACCUSR;
	if (s == "prewzskixcrdaccvtr") return PREWZSKIXCRDACCVTR;
	if (s == "prewzskixlcl") return PREWZSKIXLCL;
	if (s == "prewzskixord") return PREWZSKIXORD;
	if (s == "prewzskixpre") return PREWZSKIXPRE;
	if (s == "prewzskixrecacc") return PREWZSKIXRECACC;
	if (s == "prewzskjrefnotify") return PREWZSKJREFNOTIFY;
	if (s == "prewzskjrefsess") return PREWZSKJREFSESS;
	if (s == "prewzsknoadm") return PREWZSKNOADM;
	if (s == "prewzskowner") return PREWZSKOWNER;
	if (s == "prewzskprsadetail.x1") return PREWZSKPRSADETAIL_X1;
	if (s == "prewzskprslist.grp") return PREWZSKPRSLIST_GRP;
	if (s == "prewzskprslist.lnm") return PREWZSKPRSLIST_LNM;
	if (s == "prewzskprslist.own") return PREWZSKPRSLIST_OWN;
	if (s == "prewzskreffil") return PREWZSKREFFIL;
	if (s == "prewzskrefprs") return PREWZSKREFPRS;
	if (s == "prewzskrefsel") return PREWZSKREFSEL;
	if (s == "prewzskrefses") return PREWZSKREFSES;
	if (s == "prewzskrefusg") return PREWZSKREFUSG;
	if (s == "prewzskrefusr") return PREWZSKREFUSR;
	if (s == "prewzsksess") return PREWZSKSESS;
	if (s == "prewzsksuspsess") return PREWZSKSUSPSESS;
	if (s == "prewzsksysdate") return PREWZSKSYSDATE;
	if (s == "prewzsksysstamp") return PREWZSKSYSSTAMP;
	if (s == "prewzsksystime") return PREWZSKSYSTIME;
	if (s == "prewzsktlast") return PREWZSKTLAST;
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
	if (ix == PREWZSKIXCRDACCHWC) return("PreWzskIxCrdaccHwc");
	if (ix == PREWZSKIXCRDACCLLV) return("PreWzskIxCrdaccLlv");
	if (ix == PREWZSKIXCRDACCPRF) return("PreWzskIxCrdaccPrf");
	if (ix == PREWZSKIXCRDACCPRS) return("PreWzskIxCrdaccPrs");
	if (ix == PREWZSKIXCRDACCUSG) return("PreWzskIxCrdaccUsg");
	if (ix == PREWZSKIXCRDACCUSR) return("PreWzskIxCrdaccUsr");
	if (ix == PREWZSKIXCRDACCVTR) return("PreWzskIxCrdaccVtr");
	if (ix == PREWZSKIXLCL) return("PreWzskIxLcl");
	if (ix == PREWZSKIXORD) return("PreWzskIxOrd");
	if (ix == PREWZSKIXPRE) return("PreWzskIxPre");
	if (ix == PREWZSKIXRECACC) return("PreWzskIxRecacc");
	if (ix == PREWZSKJREFNOTIFY) return("PreWzskJrefNotify");
	if (ix == PREWZSKJREFSESS) return("PreWzskJrefSess");
	if (ix == PREWZSKNOADM) return("PreWzskNoadm");
	if (ix == PREWZSKOWNER) return("PreWzskOwner");
	if (ix == PREWZSKPRSADETAIL_X1) return("PreWzskPrsADetail.x1");
	if (ix == PREWZSKPRSLIST_GRP) return("PreWzskPrsList.grp");
	if (ix == PREWZSKPRSLIST_LNM) return("PreWzskPrsList.lnm");
	if (ix == PREWZSKPRSLIST_OWN) return("PreWzskPrsList.own");
	if (ix == PREWZSKREFFIL) return("PreWzskRefFil");
	if (ix == PREWZSKREFPRS) return("PreWzskRefPrs");
	if (ix == PREWZSKREFSEL) return("PreWzskRefSel");
	if (ix == PREWZSKREFSES) return("PreWzskRefSes");
	if (ix == PREWZSKREFUSG) return("PreWzskRefUsg");
	if (ix == PREWZSKREFUSR) return("PreWzskRefUsr");
	if (ix == PREWZSKSESS) return("PreWzskSess");
	if (ix == PREWZSKSUSPSESS) return("PreWzskSuspsess");
	if (ix == PREWZSKSYSDATE) return("PreWzskSysdate");
	if (ix == PREWZSKSYSSTAMP) return("PreWzskSysstamp");
	if (ix == PREWZSKSYSTIME) return("PreWzskSystime");
	if (ix == PREWZSKTLAST) return("PreWzskTlast");
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
		if (ix == PREWZSKREFPRS) return("person");
		if (ix == PREWZSKREFSES) return("session");
		if (ix == PREWZSKREFUSG) return("user group");
		if (ix == PREWZSKREFUSR) return("user");
		return(getSref(ix));
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
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

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
