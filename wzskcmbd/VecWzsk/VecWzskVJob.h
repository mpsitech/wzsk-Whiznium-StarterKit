/**
	* \file VecWzskVJob.h
	* vector VecWzskVJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef VECWZSKVJOB_H
#define VECWZSKVJOB_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVJob
	*/
namespace VecWzskVJob {
	const Sbecore::uint CRDWZSKFIL = 1;
	const Sbecore::uint CRDWZSKLIV = 2;
	const Sbecore::uint CRDWZSKLLV = 3;
	const Sbecore::uint CRDWZSKNAV = 4;
	const Sbecore::uint CRDWZSKOBJ = 5;
	const Sbecore::uint CRDWZSKOGR = 6;
	const Sbecore::uint CRDWZSKPRS = 7;
	const Sbecore::uint CRDWZSKSCF = 8;
	const Sbecore::uint CRDWZSKSES = 9;
	const Sbecore::uint CRDWZSKSHT = 10;
	const Sbecore::uint CRDWZSKUSG = 11;
	const Sbecore::uint CRDWZSKUSR = 12;
	const Sbecore::uint DLGWZSKFILDOWNLOAD = 13;
	const Sbecore::uint DLGWZSKNAVLOAINI = 14;
	const Sbecore::uint DLGWZSKOBJNEW = 15;
	const Sbecore::uint DLGWZSKOGRNEW = 16;
	const Sbecore::uint DLGWZSKSCFCAMERAMAT = 17;
	const Sbecore::uint DLGWZSKSCFLASERPOS = 18;
	const Sbecore::uint DLGWZSKSCFTTABLECOORD = 19;
	const Sbecore::uint JOBWZSKACQFPGAFLG = 20;
	const Sbecore::uint JOBWZSKACQFPGAPVW = 21;
	const Sbecore::uint JOBWZSKACQPREVIEW = 22;
	const Sbecore::uint JOBWZSKACQPTCLOUD = 23;
	const Sbecore::uint JOBWZSKACTEXPOSURE = 24;
	const Sbecore::uint JOBWZSKACTLASER = 25;
	const Sbecore::uint JOBWZSKACTSERVO = 26;
	const Sbecore::uint JOBWZSKIEXINI = 27;
	const Sbecore::uint JOBWZSKIPRANGLE = 28;
	const Sbecore::uint JOBWZSKIPRCORNER = 29;
	const Sbecore::uint JOBWZSKIPRTRACE = 30;
	const Sbecore::uint JOBWZSKSRCARTY = 31;
	const Sbecore::uint JOBWZSKSRCCLNXEVB = 32;
	const Sbecore::uint JOBWZSKSRCICICLE = 33;
	const Sbecore::uint JOBWZSKSRCMCVEVP = 34;
	const Sbecore::uint JOBWZSKSRCSYSINFO = 35;
	const Sbecore::uint JOBWZSKSRCUVBDVK = 36;
	const Sbecore::uint JOBWZSKSRCV4L2 = 37;
	const Sbecore::uint M2MSESSWZSK = 38;
	const Sbecore::uint PNLWZSKFILDETAIL = 39;
	const Sbecore::uint PNLWZSKFILHEADBAR = 40;
	const Sbecore::uint PNLWZSKFILLIST = 41;
	const Sbecore::uint PNLWZSKFILREC = 42;
	const Sbecore::uint PNLWZSKLIV2DVIEW = 43;
	const Sbecore::uint PNLWZSKLIV3DVIEW = 44;
	const Sbecore::uint PNLWZSKLIVHEADBAR = 45;
	const Sbecore::uint PNLWZSKLIVSYSMON = 46;
	const Sbecore::uint PNLWZSKLLVCAMERA = 47;
	const Sbecore::uint PNLWZSKLLVHEADBAR = 48;
	const Sbecore::uint PNLWZSKLLVLASER = 49;
	const Sbecore::uint PNLWZSKLLVTERMARTY = 50;
	const Sbecore::uint PNLWZSKLLVTERMCLNXEVB = 51;
	const Sbecore::uint PNLWZSKLLVTERMICICLE = 52;
	const Sbecore::uint PNLWZSKLLVTERMMCVEVP = 53;
	const Sbecore::uint PNLWZSKLLVTERMUVBDVK = 54;
	const Sbecore::uint PNLWZSKLLVTTABLE = 55;
	const Sbecore::uint PNLWZSKNAVADMIN = 56;
	const Sbecore::uint PNLWZSKNAVGLRY = 57;
	const Sbecore::uint PNLWZSKNAVHEADBAR = 58;
	const Sbecore::uint PNLWZSKNAVOP = 59;
	const Sbecore::uint PNLWZSKNAVPRE = 60;
	const Sbecore::uint PNLWZSKOBJ1NSHOT = 61;
	const Sbecore::uint PNLWZSKOBJDETAIL = 62;
	const Sbecore::uint PNLWZSKOBJHEADBAR = 63;
	const Sbecore::uint PNLWZSKOBJLIST = 64;
	const Sbecore::uint PNLWZSKOBJREC = 65;
	const Sbecore::uint PNLWZSKOBJREF1NFILE = 66;
	const Sbecore::uint PNLWZSKOGR1NOBJECT = 67;
	const Sbecore::uint PNLWZSKOGRDETAIL = 68;
	const Sbecore::uint PNLWZSKOGRHEADBAR = 69;
	const Sbecore::uint PNLWZSKOGRLIST = 70;
	const Sbecore::uint PNLWZSKOGRREC = 71;
	const Sbecore::uint PNLWZSKOGRSUP1NOBJGROUP = 72;
	const Sbecore::uint PNLWZSKPRSADETAIL = 73;
	const Sbecore::uint PNLWZSKPRSDETAIL = 74;
	const Sbecore::uint PNLWZSKPRSHEADBAR = 75;
	const Sbecore::uint PNLWZSKPRSLIST = 76;
	const Sbecore::uint PNLWZSKPRSREC = 77;
	const Sbecore::uint PNLWZSKSCFCONN = 78;
	const Sbecore::uint PNLWZSKSCFGEOM = 79;
	const Sbecore::uint PNLWZSKSCFHEADBAR = 80;
	const Sbecore::uint PNLWZSKSES1NSHOT = 81;
	const Sbecore::uint PNLWZSKSESDETAIL = 82;
	const Sbecore::uint PNLWZSKSESHEADBAR = 83;
	const Sbecore::uint PNLWZSKSESLIST = 84;
	const Sbecore::uint PNLWZSKSESREC = 85;
	const Sbecore::uint PNLWZSKSHTAPAR = 86;
	const Sbecore::uint PNLWZSKSHTDETAIL = 87;
	const Sbecore::uint PNLWZSKSHTHEADBAR = 88;
	const Sbecore::uint PNLWZSKSHTLIST = 89;
	const Sbecore::uint PNLWZSKSHTREC = 90;
	const Sbecore::uint PNLWZSKSHTREF1NFILE = 91;
	const Sbecore::uint PNLWZSKUSGAACCESS = 92;
	const Sbecore::uint PNLWZSKUSGDETAIL = 93;
	const Sbecore::uint PNLWZSKUSGHEADBAR = 94;
	const Sbecore::uint PNLWZSKUSGLIST = 95;
	const Sbecore::uint PNLWZSKUSGMNUSER = 96;
	const Sbecore::uint PNLWZSKUSGREC = 97;
	const Sbecore::uint PNLWZSKUSR1NSESSION = 98;
	const Sbecore::uint PNLWZSKUSRAACCESS = 99;
	const Sbecore::uint PNLWZSKUSRDETAIL = 100;
	const Sbecore::uint PNLWZSKUSRHEADBAR = 101;
	const Sbecore::uint PNLWZSKUSRLIST = 102;
	const Sbecore::uint PNLWZSKUSRMNUSERGROUP = 103;
	const Sbecore::uint PNLWZSKUSRREC = 104;
	const Sbecore::uint QRYWZSKFILLIST = 105;
	const Sbecore::uint QRYWZSKOBJ1NSHOT = 106;
	const Sbecore::uint QRYWZSKOBJLIST = 107;
	const Sbecore::uint QRYWZSKOBJREF1NFILE = 108;
	const Sbecore::uint QRYWZSKOGR1NOBJECT = 109;
	const Sbecore::uint QRYWZSKOGRLIST = 110;
	const Sbecore::uint QRYWZSKOGRSUP1NOBJGROUP = 111;
	const Sbecore::uint QRYWZSKPRSADETAIL = 112;
	const Sbecore::uint QRYWZSKPRSLIST = 113;
	const Sbecore::uint QRYWZSKSES1NSHOT = 114;
	const Sbecore::uint QRYWZSKSESLIST = 115;
	const Sbecore::uint QRYWZSKSHTAPAR = 116;
	const Sbecore::uint QRYWZSKSHTLIST = 117;
	const Sbecore::uint QRYWZSKSHTREF1NFILE = 118;
	const Sbecore::uint QRYWZSKUSGAACCESS = 119;
	const Sbecore::uint QRYWZSKUSGLIST = 120;
	const Sbecore::uint QRYWZSKUSGMNUSER = 121;
	const Sbecore::uint QRYWZSKUSR1NSESSION = 122;
	const Sbecore::uint QRYWZSKUSRAACCESS = 123;
	const Sbecore::uint QRYWZSKUSRLIST = 124;
	const Sbecore::uint QRYWZSKUSRMNUSERGROUP = 125;
	const Sbecore::uint ROOTWZSK = 126;
	const Sbecore::uint SESSWZSK = 127;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
