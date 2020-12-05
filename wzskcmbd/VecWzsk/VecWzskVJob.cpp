/**
	* \file VecWzskVJob.cpp
	* vector VecWzskVJob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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
	if (s == "crdwzskliv") return CRDWZSKLIV;
	if (s == "crdwzskllv") return CRDWZSKLLV;
	if (s == "crdwzsknav") return CRDWZSKNAV;
	if (s == "crdwzskobj") return CRDWZSKOBJ;
	if (s == "crdwzskogr") return CRDWZSKOGR;
	if (s == "crdwzskprs") return CRDWZSKPRS;
	if (s == "crdwzskscf") return CRDWZSKSCF;
	if (s == "crdwzskses") return CRDWZSKSES;
	if (s == "crdwzsksht") return CRDWZSKSHT;
	if (s == "crdwzskusg") return CRDWZSKUSG;
	if (s == "crdwzskusr") return CRDWZSKUSR;
	if (s == "dlgwzskfildownload") return DLGWZSKFILDOWNLOAD;
	if (s == "dlgwzsknavloaini") return DLGWZSKNAVLOAINI;
	if (s == "dlgwzskobjnew") return DLGWZSKOBJNEW;
	if (s == "dlgwzskogrnew") return DLGWZSKOGRNEW;
	if (s == "dlgwzskscfcameramat") return DLGWZSKSCFCAMERAMAT;
	if (s == "dlgwzskscflaserpos") return DLGWZSKSCFLASERPOS;
	if (s == "dlgwzskscfttablecoord") return DLGWZSKSCFTTABLECOORD;
	if (s == "jobwzskacqfpgaflg") return JOBWZSKACQFPGAFLG;
	if (s == "jobwzskacqfpgapvw") return JOBWZSKACQFPGAPVW;
	if (s == "jobwzskacqpreview") return JOBWZSKACQPREVIEW;
	if (s == "jobwzskacqptcloud") return JOBWZSKACQPTCLOUD;
	if (s == "jobwzskactexposure") return JOBWZSKACTEXPOSURE;
	if (s == "jobwzskactlaser") return JOBWZSKACTLASER;
	if (s == "jobwzskactservo") return JOBWZSKACTSERVO;
	if (s == "jobwzskiexini") return JOBWZSKIEXINI;
	if (s == "jobwzskiprangle") return JOBWZSKIPRANGLE;
	if (s == "jobwzskiprcorner") return JOBWZSKIPRCORNER;
	if (s == "jobwzskiprtrace") return JOBWZSKIPRTRACE;
	if (s == "jobwzsksrcfpga") return JOBWZSKSRCFPGA;
	if (s == "jobwzsksrcsysinfo") return JOBWZSKSRCSYSINFO;
	if (s == "jobwzsksrcv4l2") return JOBWZSKSRCV4L2;
	if (s == "m2msesswzsk") return M2MSESSWZSK;
	if (s == "pnlwzskfildetail") return PNLWZSKFILDETAIL;
	if (s == "pnlwzskfilheadbar") return PNLWZSKFILHEADBAR;
	if (s == "pnlwzskfillist") return PNLWZSKFILLIST;
	if (s == "pnlwzskfilrec") return PNLWZSKFILREC;
	if (s == "pnlwzskliv2dview") return PNLWZSKLIV2DVIEW;
	if (s == "pnlwzskliv3dview") return PNLWZSKLIV3DVIEW;
	if (s == "pnlwzsklivheadbar") return PNLWZSKLIVHEADBAR;
	if (s == "pnlwzsklivsysmon") return PNLWZSKLIVSYSMON;
	if (s == "pnlwzskllvcamera") return PNLWZSKLLVCAMERA;
	if (s == "pnlwzskllvheadbar") return PNLWZSKLLVHEADBAR;
	if (s == "pnlwzskllvlaser") return PNLWZSKLLVLASER;
	if (s == "pnlwzskllvterm") return PNLWZSKLLVTERM;
	if (s == "pnlwzskllvttable") return PNLWZSKLLVTTABLE;
	if (s == "pnlwzsknavadmin") return PNLWZSKNAVADMIN;
	if (s == "pnlwzsknavgalery") return PNLWZSKNAVGALERY;
	if (s == "pnlwzsknavheadbar") return PNLWZSKNAVHEADBAR;
	if (s == "pnlwzsknavop") return PNLWZSKNAVOP;
	if (s == "pnlwzsknavpre") return PNLWZSKNAVPRE;
	if (s == "pnlwzskobj1nshot") return PNLWZSKOBJ1NSHOT;
	if (s == "pnlwzskobjdetail") return PNLWZSKOBJDETAIL;
	if (s == "pnlwzskobjheadbar") return PNLWZSKOBJHEADBAR;
	if (s == "pnlwzskobjlist") return PNLWZSKOBJLIST;
	if (s == "pnlwzskobjrec") return PNLWZSKOBJREC;
	if (s == "pnlwzskobjref1nfile") return PNLWZSKOBJREF1NFILE;
	if (s == "pnlwzskogr1nobject") return PNLWZSKOGR1NOBJECT;
	if (s == "pnlwzskogrdetail") return PNLWZSKOGRDETAIL;
	if (s == "pnlwzskogrheadbar") return PNLWZSKOGRHEADBAR;
	if (s == "pnlwzskogrlist") return PNLWZSKOGRLIST;
	if (s == "pnlwzskogrrec") return PNLWZSKOGRREC;
	if (s == "pnlwzskogrsup1nobjgroup") return PNLWZSKOGRSUP1NOBJGROUP;
	if (s == "pnlwzskprsadetail") return PNLWZSKPRSADETAIL;
	if (s == "pnlwzskprsdetail") return PNLWZSKPRSDETAIL;
	if (s == "pnlwzskprsheadbar") return PNLWZSKPRSHEADBAR;
	if (s == "pnlwzskprslist") return PNLWZSKPRSLIST;
	if (s == "pnlwzskprsrec") return PNLWZSKPRSREC;
	if (s == "pnlwzskscfconn") return PNLWZSKSCFCONN;
	if (s == "pnlwzskscfgeom") return PNLWZSKSCFGEOM;
	if (s == "pnlwzskscfheadbar") return PNLWZSKSCFHEADBAR;
	if (s == "pnlwzskses1nshot") return PNLWZSKSES1NSHOT;
	if (s == "pnlwzsksesdetail") return PNLWZSKSESDETAIL;
	if (s == "pnlwzsksesheadbar") return PNLWZSKSESHEADBAR;
	if (s == "pnlwzskseslist") return PNLWZSKSESLIST;
	if (s == "pnlwzsksesrec") return PNLWZSKSESREC;
	if (s == "pnlwzskshtapar") return PNLWZSKSHTAPAR;
	if (s == "pnlwzskshtdetail") return PNLWZSKSHTDETAIL;
	if (s == "pnlwzskshtheadbar") return PNLWZSKSHTHEADBAR;
	if (s == "pnlwzskshtlist") return PNLWZSKSHTLIST;
	if (s == "pnlwzskshtrec") return PNLWZSKSHTREC;
	if (s == "pnlwzskshtref1nfile") return PNLWZSKSHTREF1NFILE;
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
	if (s == "qrywzskfillist") return QRYWZSKFILLIST;
	if (s == "qrywzskobj1nshot") return QRYWZSKOBJ1NSHOT;
	if (s == "qrywzskobjlist") return QRYWZSKOBJLIST;
	if (s == "qrywzskobjref1nfile") return QRYWZSKOBJREF1NFILE;
	if (s == "qrywzskogr1nobject") return QRYWZSKOGR1NOBJECT;
	if (s == "qrywzskogrlist") return QRYWZSKOGRLIST;
	if (s == "qrywzskogrsup1nobjgroup") return QRYWZSKOGRSUP1NOBJGROUP;
	if (s == "qrywzskprsadetail") return QRYWZSKPRSADETAIL;
	if (s == "qrywzskprslist") return QRYWZSKPRSLIST;
	if (s == "qrywzskses1nshot") return QRYWZSKSES1NSHOT;
	if (s == "qrywzskseslist") return QRYWZSKSESLIST;
	if (s == "qrywzskshtapar") return QRYWZSKSHTAPAR;
	if (s == "qrywzskshtlist") return QRYWZSKSHTLIST;
	if (s == "qrywzskshtref1nfile") return QRYWZSKSHTREF1NFILE;
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
	if (ix == CRDWZSKLIV) return("CrdWzskLiv");
	if (ix == CRDWZSKLLV) return("CrdWzskLlv");
	if (ix == CRDWZSKNAV) return("CrdWzskNav");
	if (ix == CRDWZSKOBJ) return("CrdWzskObj");
	if (ix == CRDWZSKOGR) return("CrdWzskOgr");
	if (ix == CRDWZSKPRS) return("CrdWzskPrs");
	if (ix == CRDWZSKSCF) return("CrdWzskScf");
	if (ix == CRDWZSKSES) return("CrdWzskSes");
	if (ix == CRDWZSKSHT) return("CrdWzskSht");
	if (ix == CRDWZSKUSG) return("CrdWzskUsg");
	if (ix == CRDWZSKUSR) return("CrdWzskUsr");
	if (ix == DLGWZSKFILDOWNLOAD) return("DlgWzskFilDownload");
	if (ix == DLGWZSKNAVLOAINI) return("DlgWzskNavLoaini");
	if (ix == DLGWZSKOBJNEW) return("DlgWzskObjNew");
	if (ix == DLGWZSKOGRNEW) return("DlgWzskOgrNew");
	if (ix == DLGWZSKSCFCAMERAMAT) return("DlgWzskScfCameramat");
	if (ix == DLGWZSKSCFLASERPOS) return("DlgWzskScfLaserpos");
	if (ix == DLGWZSKSCFTTABLECOORD) return("DlgWzskScfTtablecoord");
	if (ix == JOBWZSKACQFPGAFLG) return("JobWzskAcqFpgaflg");
	if (ix == JOBWZSKACQFPGAPVW) return("JobWzskAcqFpgapvw");
	if (ix == JOBWZSKACQPREVIEW) return("JobWzskAcqPreview");
	if (ix == JOBWZSKACQPTCLOUD) return("JobWzskAcqPtcloud");
	if (ix == JOBWZSKACTEXPOSURE) return("JobWzskActExposure");
	if (ix == JOBWZSKACTLASER) return("JobWzskActLaser");
	if (ix == JOBWZSKACTSERVO) return("JobWzskActServo");
	if (ix == JOBWZSKIEXINI) return("JobWzskIexIni");
	if (ix == JOBWZSKIPRANGLE) return("JobWzskIprAngle");
	if (ix == JOBWZSKIPRCORNER) return("JobWzskIprCorner");
	if (ix == JOBWZSKIPRTRACE) return("JobWzskIprTrace");
	if (ix == JOBWZSKSRCFPGA) return("JobWzskSrcFpga");
	if (ix == JOBWZSKSRCSYSINFO) return("JobWzskSrcSysinfo");
	if (ix == JOBWZSKSRCV4L2) return("JobWzskSrcV4l2");
	if (ix == M2MSESSWZSK) return("M2msessWzsk");
	if (ix == PNLWZSKFILDETAIL) return("PnlWzskFilDetail");
	if (ix == PNLWZSKFILHEADBAR) return("PnlWzskFilHeadbar");
	if (ix == PNLWZSKFILLIST) return("PnlWzskFilList");
	if (ix == PNLWZSKFILREC) return("PnlWzskFilRec");
	if (ix == PNLWZSKLIV2DVIEW) return("PnlWzskLiv2DView");
	if (ix == PNLWZSKLIV3DVIEW) return("PnlWzskLiv3DView");
	if (ix == PNLWZSKLIVHEADBAR) return("PnlWzskLivHeadbar");
	if (ix == PNLWZSKLIVSYSMON) return("PnlWzskLivSysmon");
	if (ix == PNLWZSKLLVCAMERA) return("PnlWzskLlvCamera");
	if (ix == PNLWZSKLLVHEADBAR) return("PnlWzskLlvHeadbar");
	if (ix == PNLWZSKLLVLASER) return("PnlWzskLlvLaser");
	if (ix == PNLWZSKLLVTERM) return("PnlWzskLlvTerm");
	if (ix == PNLWZSKLLVTTABLE) return("PnlWzskLlvTtable");
	if (ix == PNLWZSKNAVADMIN) return("PnlWzskNavAdmin");
	if (ix == PNLWZSKNAVGALERY) return("PnlWzskNavGalery");
	if (ix == PNLWZSKNAVHEADBAR) return("PnlWzskNavHeadbar");
	if (ix == PNLWZSKNAVOP) return("PnlWzskNavOp");
	if (ix == PNLWZSKNAVPRE) return("PnlWzskNavPre");
	if (ix == PNLWZSKOBJ1NSHOT) return("PnlWzskObj1NShot");
	if (ix == PNLWZSKOBJDETAIL) return("PnlWzskObjDetail");
	if (ix == PNLWZSKOBJHEADBAR) return("PnlWzskObjHeadbar");
	if (ix == PNLWZSKOBJLIST) return("PnlWzskObjList");
	if (ix == PNLWZSKOBJREC) return("PnlWzskObjRec");
	if (ix == PNLWZSKOBJREF1NFILE) return("PnlWzskObjRef1NFile");
	if (ix == PNLWZSKOGR1NOBJECT) return("PnlWzskOgr1NObject");
	if (ix == PNLWZSKOGRDETAIL) return("PnlWzskOgrDetail");
	if (ix == PNLWZSKOGRHEADBAR) return("PnlWzskOgrHeadbar");
	if (ix == PNLWZSKOGRLIST) return("PnlWzskOgrList");
	if (ix == PNLWZSKOGRREC) return("PnlWzskOgrRec");
	if (ix == PNLWZSKOGRSUP1NOBJGROUP) return("PnlWzskOgrSup1NObjgroup");
	if (ix == PNLWZSKPRSADETAIL) return("PnlWzskPrsADetail");
	if (ix == PNLWZSKPRSDETAIL) return("PnlWzskPrsDetail");
	if (ix == PNLWZSKPRSHEADBAR) return("PnlWzskPrsHeadbar");
	if (ix == PNLWZSKPRSLIST) return("PnlWzskPrsList");
	if (ix == PNLWZSKPRSREC) return("PnlWzskPrsRec");
	if (ix == PNLWZSKSCFCONN) return("PnlWzskScfConn");
	if (ix == PNLWZSKSCFGEOM) return("PnlWzskScfGeom");
	if (ix == PNLWZSKSCFHEADBAR) return("PnlWzskScfHeadbar");
	if (ix == PNLWZSKSES1NSHOT) return("PnlWzskSes1NShot");
	if (ix == PNLWZSKSESDETAIL) return("PnlWzskSesDetail");
	if (ix == PNLWZSKSESHEADBAR) return("PnlWzskSesHeadbar");
	if (ix == PNLWZSKSESLIST) return("PnlWzskSesList");
	if (ix == PNLWZSKSESREC) return("PnlWzskSesRec");
	if (ix == PNLWZSKSHTAPAR) return("PnlWzskShtAPar");
	if (ix == PNLWZSKSHTDETAIL) return("PnlWzskShtDetail");
	if (ix == PNLWZSKSHTHEADBAR) return("PnlWzskShtHeadbar");
	if (ix == PNLWZSKSHTLIST) return("PnlWzskShtList");
	if (ix == PNLWZSKSHTREC) return("PnlWzskShtRec");
	if (ix == PNLWZSKSHTREF1NFILE) return("PnlWzskShtRef1NFile");
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
	if (ix == QRYWZSKFILLIST) return("QryWzskFilList");
	if (ix == QRYWZSKOBJ1NSHOT) return("QryWzskObj1NShot");
	if (ix == QRYWZSKOBJLIST) return("QryWzskObjList");
	if (ix == QRYWZSKOBJREF1NFILE) return("QryWzskObjRef1NFile");
	if (ix == QRYWZSKOGR1NOBJECT) return("QryWzskOgr1NObject");
	if (ix == QRYWZSKOGRLIST) return("QryWzskOgrList");
	if (ix == QRYWZSKOGRSUP1NOBJGROUP) return("QryWzskOgrSup1NObjgroup");
	if (ix == QRYWZSKPRSADETAIL) return("QryWzskPrsADetail");
	if (ix == QRYWZSKPRSLIST) return("QryWzskPrsList");
	if (ix == QRYWZSKSES1NSHOT) return("QryWzskSes1NShot");
	if (ix == QRYWZSKSESLIST) return("QryWzskSesList");
	if (ix == QRYWZSKSHTAPAR) return("QryWzskShtAPar");
	if (ix == QRYWZSKSHTLIST) return("QryWzskShtList");
	if (ix == QRYWZSKSHTREF1NFILE) return("QryWzskShtRef1NFile");
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

