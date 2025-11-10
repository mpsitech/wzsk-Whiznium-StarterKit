/**
	* \file VecWzskVJob.cpp
	* vector VecWzskVJob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "VecWzskVJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVJob
 ******************************************************************************/

uint VecWzskVJob::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdwzskfil") return CRDWZSKFIL;
	if (s == "crdwzskhwc") return CRDWZSKHWC;
	if (s == "crdwzskllv") return CRDWZSKLLV;
	if (s == "crdwzsknav") return CRDWZSKNAV;
	if (s == "crdwzskprf") return CRDWZSKPRF;
	if (s == "crdwzskprs") return CRDWZSKPRS;
	if (s == "crdwzskusg") return CRDWZSKUSG;
	if (s == "crdwzskusr") return CRDWZSKUSR;
	if (s == "crdwzskvtr") return CRDWZSKVTR;
	if (s == "dlgwzskfildownload") return DLGWZSKFILDOWNLOAD;
	if (s == "dlgwzsknavloaini") return DLGWZSKNAVLOAINI;
	if (s == "jobwzskacqcorner") return JOBWZSKACQCORNER;
	if (s == "jobwzskacqhdr") return JOBWZSKACQHDR;
	if (s == "jobwzskacqmemtrack") return JOBWZSKACQMEMTRACK;
	if (s == "jobwzskacqpreview") return JOBWZSKACQPREVIEW;
	if (s == "jobwzskacqtrace") return JOBWZSKACQTRACE;
	if (s == "jobwzskacqvtrtrack") return JOBWZSKACQVTRTRACK;
	if (s == "jobwzskactlaser") return JOBWZSKACTLASER;
	if (s == "jobwzskactrotary") return JOBWZSKACTROTARY;
	if (s == "jobwzskactvistorot") return JOBWZSKACTVISTOROT;
	if (s == "jobwzskiexini") return JOBWZSKIEXINI;
	if (s == "jobwzskprcangle") return JOBWZSKPRCANGLE;
	if (s == "jobwzskprcwavelet") return JOBWZSKPRCWAVELET;
	if (s == "jobwzsksrcdcvsp") return JOBWZSKSRCDCVSP;
	if (s == "jobwzsksrcfpgainfo") return JOBWZSKSRCFPGAINFO;
	if (s == "jobwzsksrcsysinfo") return JOBWZSKSRCSYSINFO;
	if (s == "jobwzsksrctivsp") return JOBWZSKSRCTIVSP;
	if (s == "jobwzsksrczuvsp") return JOBWZSKSRCZUVSP;
	if (s == "m2msesswzsk") return M2MSESSWZSK;
	if (s == "pnlwzskfildetail") return PNLWZSKFILDETAIL;
	if (s == "pnlwzskfilheadbar") return PNLWZSKFILHEADBAR;
	if (s == "pnlwzskfillist") return PNLWZSKFILLIST;
	if (s == "pnlwzskfilrec") return PNLWZSKFILREC;
	if (s == "pnlwzskhwcasys") return PNLWZSKHWCASYS;
	if (s == "pnlwzskhwcconfig") return PNLWZSKHWCCONFIG;
	if (s == "pnlwzskhwcdebug") return PNLWZSKHWCDEBUG;
	if (s == "pnlwzskhwcheadbar") return PNLWZSKHWCHEADBAR;
	if (s == "pnlwzskllvheadbar") return PNLWZSKLLVHEADBAR;
	if (s == "pnlwzskllvident") return PNLWZSKLLVIDENT;
	if (s == "pnlwzskllvlaser") return PNLWZSKLLVLASER;
	if (s == "pnlwzskllvrotary") return PNLWZSKLLVROTARY;
	if (s == "pnlwzskllvsysmon") return PNLWZSKLLVSYSMON;
	if (s == "pnlwzskllvtermdcvsp") return PNLWZSKLLVTERMDCVSP;
	if (s == "pnlwzskllvtermtivsp") return PNLWZSKLLVTERMTIVSP;
	if (s == "pnlwzskllvtermzuvsp") return PNLWZSKLLVTERMZUVSP;
	if (s == "pnlwzsknavadmin") return PNLWZSKNAVADMIN;
	if (s == "pnlwzsknavheadbar") return PNLWZSKNAVHEADBAR;
	if (s == "pnlwzsknavop") return PNLWZSKNAVOP;
	if (s == "pnlwzskprfacqcorner") return PNLWZSKPRFACQCORNER;
	if (s == "pnlwzskprfacqpreview") return PNLWZSKPRFACQPREVIEW;
	if (s == "pnlwzskprfacqtrace") return PNLWZSKPRFACQTRACE;
	if (s == "pnlwzskprfactlaser") return PNLWZSKPRFACTLASER;
	if (s == "pnlwzskprfactvistorot") return PNLWZSKPRFACTVISTOROT;
	if (s == "pnlwzskprfdaemon") return PNLWZSKPRFDAEMON;
	if (s == "pnlwzskprfglobal") return PNLWZSKPRFGLOBAL;
	if (s == "pnlwzskprfheadbar") return PNLWZSKPRFHEADBAR;
	if (s == "pnlwzskprfsrcdcvsp") return PNLWZSKPRFSRCDCVSP;
	if (s == "pnlwzskprfsrcsysinfo") return PNLWZSKPRFSRCSYSINFO;
	if (s == "pnlwzskprfsrctivsp") return PNLWZSKPRFSRCTIVSP;
	if (s == "pnlwzskprfsrczuvsp") return PNLWZSKPRFSRCZUVSP;
	if (s == "pnlwzskprsadetail") return PNLWZSKPRSADETAIL;
	if (s == "pnlwzskprsdetail") return PNLWZSKPRSDETAIL;
	if (s == "pnlwzskprsheadbar") return PNLWZSKPRSHEADBAR;
	if (s == "pnlwzskprslist") return PNLWZSKPRSLIST;
	if (s == "pnlwzskprsrec") return PNLWZSKPRSREC;
	if (s == "pnlwzskusgaaccess") return PNLWZSKUSGAACCESS;
	if (s == "pnlwzskusgdetail") return PNLWZSKUSGDETAIL;
	if (s == "pnlwzskusgheadbar") return PNLWZSKUSGHEADBAR;
	if (s == "pnlwzskusglist") return PNLWZSKUSGLIST;
	if (s == "pnlwzskusgmnuser") return PNLWZSKUSGMNUSER;
	if (s == "pnlwzskusgrec") return PNLWZSKUSGREC;
	if (s == "pnlwzskusr1nsession") return PNLWZSKUSR1NSESSION;
	if (s == "pnlwzskusraaccess") return PNLWZSKUSRAACCESS;
	if (s == "pnlwzskusrdetail") return PNLWZSKUSRDETAIL;
	if (s == "pnlwzskusrheadbar") return PNLWZSKUSRHEADBAR;
	if (s == "pnlwzskusrlist") return PNLWZSKUSRLIST;
	if (s == "pnlwzskusrmnusergroup") return PNLWZSKUSRMNUSERGROUP;
	if (s == "pnlwzskusrrec") return PNLWZSKUSRREC;
	if (s == "pnlwzskvtrconfig") return PNLWZSKVTRCONFIG;
	if (s == "pnlwzskvtrdebug") return PNLWZSKVTRDEBUG;
	if (s == "pnlwzskvtrheadbar") return PNLWZSKVTRHEADBAR;
	if (s == "pnlwzskvtrmonitor") return PNLWZSKVTRMONITOR;
	if (s == "qrywzskfillist") return QRYWZSKFILLIST;
	if (s == "qrywzskprsadetail") return QRYWZSKPRSADETAIL;
	if (s == "qrywzskprslist") return QRYWZSKPRSLIST;
	if (s == "qrywzskusgaaccess") return QRYWZSKUSGAACCESS;
	if (s == "qrywzskusglist") return QRYWZSKUSGLIST;
	if (s == "qrywzskusgmnuser") return QRYWZSKUSGMNUSER;
	if (s == "qrywzskusr1nsession") return QRYWZSKUSR1NSESSION;
	if (s == "qrywzskusraaccess") return QRYWZSKUSRAACCESS;
	if (s == "qrywzskusrlist") return QRYWZSKUSRLIST;
	if (s == "qrywzskusrmnusergroup") return QRYWZSKUSRMNUSERGROUP;
	if (s == "rootwzsk") return ROOTWZSK;
	if (s == "sesswzsk") return SESSWZSK;

	return(0);
};

string VecWzskVJob::getSref(
			const uint ix
		) {
	if (ix == CRDWZSKFIL) return("CrdWzskFil");
	if (ix == CRDWZSKHWC) return("CrdWzskHwc");
	if (ix == CRDWZSKLLV) return("CrdWzskLlv");
	if (ix == CRDWZSKNAV) return("CrdWzskNav");
	if (ix == CRDWZSKPRF) return("CrdWzskPrf");
	if (ix == CRDWZSKPRS) return("CrdWzskPrs");
	if (ix == CRDWZSKUSG) return("CrdWzskUsg");
	if (ix == CRDWZSKUSR) return("CrdWzskUsr");
	if (ix == CRDWZSKVTR) return("CrdWzskVtr");
	if (ix == DLGWZSKFILDOWNLOAD) return("DlgWzskFilDownload");
	if (ix == DLGWZSKNAVLOAINI) return("DlgWzskNavLoaini");
	if (ix == JOBWZSKACQCORNER) return("JobWzskAcqCorner");
	if (ix == JOBWZSKACQHDR) return("JobWzskAcqHdr");
	if (ix == JOBWZSKACQMEMTRACK) return("JobWzskAcqMemtrack");
	if (ix == JOBWZSKACQPREVIEW) return("JobWzskAcqPreview");
	if (ix == JOBWZSKACQTRACE) return("JobWzskAcqTrace");
	if (ix == JOBWZSKACQVTRTRACK) return("JobWzskAcqVtrtrack");
	if (ix == JOBWZSKACTLASER) return("JobWzskActLaser");
	if (ix == JOBWZSKACTROTARY) return("JobWzskActRotary");
	if (ix == JOBWZSKACTVISTOROT) return("JobWzskActVistorot");
	if (ix == JOBWZSKIEXINI) return("JobWzskIexIni");
	if (ix == JOBWZSKPRCANGLE) return("JobWzskPrcAngle");
	if (ix == JOBWZSKPRCWAVELET) return("JobWzskPrcWavelet");
	if (ix == JOBWZSKSRCDCVSP) return("JobWzskSrcDcvsp");
	if (ix == JOBWZSKSRCFPGAINFO) return("JobWzskSrcFpgainfo");
	if (ix == JOBWZSKSRCSYSINFO) return("JobWzskSrcSysinfo");
	if (ix == JOBWZSKSRCTIVSP) return("JobWzskSrcTivsp");
	if (ix == JOBWZSKSRCZUVSP) return("JobWzskSrcZuvsp");
	if (ix == M2MSESSWZSK) return("M2msessWzsk");
	if (ix == PNLWZSKFILDETAIL) return("PnlWzskFilDetail");
	if (ix == PNLWZSKFILHEADBAR) return("PnlWzskFilHeadbar");
	if (ix == PNLWZSKFILLIST) return("PnlWzskFilList");
	if (ix == PNLWZSKFILREC) return("PnlWzskFilRec");
	if (ix == PNLWZSKHWCASYS) return("PnlWzskHwcAsys");
	if (ix == PNLWZSKHWCCONFIG) return("PnlWzskHwcConfig");
	if (ix == PNLWZSKHWCDEBUG) return("PnlWzskHwcDebug");
	if (ix == PNLWZSKHWCHEADBAR) return("PnlWzskHwcHeadbar");
	if (ix == PNLWZSKLLVHEADBAR) return("PnlWzskLlvHeadbar");
	if (ix == PNLWZSKLLVIDENT) return("PnlWzskLlvIdent");
	if (ix == PNLWZSKLLVLASER) return("PnlWzskLlvLaser");
	if (ix == PNLWZSKLLVROTARY) return("PnlWzskLlvRotary");
	if (ix == PNLWZSKLLVSYSMON) return("PnlWzskLlvSysmon");
	if (ix == PNLWZSKLLVTERMDCVSP) return("PnlWzskLlvTermDcvsp");
	if (ix == PNLWZSKLLVTERMTIVSP) return("PnlWzskLlvTermTivsp");
	if (ix == PNLWZSKLLVTERMZUVSP) return("PnlWzskLlvTermZuvsp");
	if (ix == PNLWZSKNAVADMIN) return("PnlWzskNavAdmin");
	if (ix == PNLWZSKNAVHEADBAR) return("PnlWzskNavHeadbar");
	if (ix == PNLWZSKNAVOP) return("PnlWzskNavOp");
	if (ix == PNLWZSKPRFACQCORNER) return("PnlWzskPrfAcqCorner");
	if (ix == PNLWZSKPRFACQPREVIEW) return("PnlWzskPrfAcqPreview");
	if (ix == PNLWZSKPRFACQTRACE) return("PnlWzskPrfAcqTrace");
	if (ix == PNLWZSKPRFACTLASER) return("PnlWzskPrfActLaser");
	if (ix == PNLWZSKPRFACTVISTOROT) return("PnlWzskPrfActVistorot");
	if (ix == PNLWZSKPRFDAEMON) return("PnlWzskPrfDaemon");
	if (ix == PNLWZSKPRFGLOBAL) return("PnlWzskPrfGlobal");
	if (ix == PNLWZSKPRFHEADBAR) return("PnlWzskPrfHeadbar");
	if (ix == PNLWZSKPRFSRCDCVSP) return("PnlWzskPrfSrcDcvsp");
	if (ix == PNLWZSKPRFSRCSYSINFO) return("PnlWzskPrfSrcSysinfo");
	if (ix == PNLWZSKPRFSRCTIVSP) return("PnlWzskPrfSrcTivsp");
	if (ix == PNLWZSKPRFSRCZUVSP) return("PnlWzskPrfSrcZuvsp");
	if (ix == PNLWZSKPRSADETAIL) return("PnlWzskPrsADetail");
	if (ix == PNLWZSKPRSDETAIL) return("PnlWzskPrsDetail");
	if (ix == PNLWZSKPRSHEADBAR) return("PnlWzskPrsHeadbar");
	if (ix == PNLWZSKPRSLIST) return("PnlWzskPrsList");
	if (ix == PNLWZSKPRSREC) return("PnlWzskPrsRec");
	if (ix == PNLWZSKUSGAACCESS) return("PnlWzskUsgAAccess");
	if (ix == PNLWZSKUSGDETAIL) return("PnlWzskUsgDetail");
	if (ix == PNLWZSKUSGHEADBAR) return("PnlWzskUsgHeadbar");
	if (ix == PNLWZSKUSGLIST) return("PnlWzskUsgList");
	if (ix == PNLWZSKUSGMNUSER) return("PnlWzskUsgMNUser");
	if (ix == PNLWZSKUSGREC) return("PnlWzskUsgRec");
	if (ix == PNLWZSKUSR1NSESSION) return("PnlWzskUsr1NSession");
	if (ix == PNLWZSKUSRAACCESS) return("PnlWzskUsrAAccess");
	if (ix == PNLWZSKUSRDETAIL) return("PnlWzskUsrDetail");
	if (ix == PNLWZSKUSRHEADBAR) return("PnlWzskUsrHeadbar");
	if (ix == PNLWZSKUSRLIST) return("PnlWzskUsrList");
	if (ix == PNLWZSKUSRMNUSERGROUP) return("PnlWzskUsrMNUsergroup");
	if (ix == PNLWZSKUSRREC) return("PnlWzskUsrRec");
	if (ix == PNLWZSKVTRCONFIG) return("PnlWzskVtrConfig");
	if (ix == PNLWZSKVTRDEBUG) return("PnlWzskVtrDebug");
	if (ix == PNLWZSKVTRHEADBAR) return("PnlWzskVtrHeadbar");
	if (ix == PNLWZSKVTRMONITOR) return("PnlWzskVtrMonitor");
	if (ix == QRYWZSKFILLIST) return("QryWzskFilList");
	if (ix == QRYWZSKPRSADETAIL) return("QryWzskPrsADetail");
	if (ix == QRYWZSKPRSLIST) return("QryWzskPrsList");
	if (ix == QRYWZSKUSGAACCESS) return("QryWzskUsgAAccess");
	if (ix == QRYWZSKUSGLIST) return("QryWzskUsgList");
	if (ix == QRYWZSKUSGMNUSER) return("QryWzskUsgMNUser");
	if (ix == QRYWZSKUSR1NSESSION) return("QryWzskUsr1NSession");
	if (ix == QRYWZSKUSRAACCESS) return("QryWzskUsrAAccess");
	if (ix == QRYWZSKUSRLIST) return("QryWzskUsrList");
	if (ix == QRYWZSKUSRMNUSERGROUP) return("QryWzskUsrMNUsergroup");
	if (ix == ROOTWZSK) return("RootWzsk");
	if (ix == SESSWZSK) return("SessWzsk");

	return("");
};
