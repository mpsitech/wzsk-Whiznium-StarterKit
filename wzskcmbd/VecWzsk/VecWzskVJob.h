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
	const Sbecore::uint JOBWZSKSRCMERCBB = 35;
	const Sbecore::uint JOBWZSKSRCPWMONUART = 36;
	const Sbecore::uint JOBWZSKSRCPWMONUSB = 37;
	const Sbecore::uint JOBWZSKSRCSYSINFO = 38;
	const Sbecore::uint JOBWZSKSRCUVBDVK = 39;
	const Sbecore::uint JOBWZSKSRCV4L2 = 40;
	const Sbecore::uint M2MSESSWZSK = 41;
	const Sbecore::uint PNLWZSKFILDETAIL = 42;
	const Sbecore::uint PNLWZSKFILHEADBAR = 43;
	const Sbecore::uint PNLWZSKFILLIST = 44;
	const Sbecore::uint PNLWZSKFILREC = 45;
	const Sbecore::uint PNLWZSKLIV2DVIEW = 46;
	const Sbecore::uint PNLWZSKLIV3DVIEW = 47;
	const Sbecore::uint PNLWZSKLIVHEADBAR = 48;
	const Sbecore::uint PNLWZSKLIVSYSMON = 49;
	const Sbecore::uint PNLWZSKLLVCAMERA = 50;
	const Sbecore::uint PNLWZSKLLVHEADBAR = 51;
	const Sbecore::uint PNLWZSKLLVLASER = 52;
	const Sbecore::uint PNLWZSKLLVTERMARTY = 53;
	const Sbecore::uint PNLWZSKLLVTERMCLNXEVB = 54;
	const Sbecore::uint PNLWZSKLLVTERMICICLE = 55;
	const Sbecore::uint PNLWZSKLLVTERMMCVEVP = 56;
	const Sbecore::uint PNLWZSKLLVTERMPWMONUART = 57;
	const Sbecore::uint PNLWZSKLLVTERMPWMONUSB = 58;
	const Sbecore::uint PNLWZSKLLVTERMUVBDVK = 59;
	const Sbecore::uint PNLWZSKLLVTTABLE = 60;
	const Sbecore::uint PNLWZSKNAVADMIN = 61;
	const Sbecore::uint PNLWZSKNAVGLRY = 62;
	const Sbecore::uint PNLWZSKNAVHEADBAR = 63;
	const Sbecore::uint PNLWZSKNAVOP = 64;
	const Sbecore::uint PNLWZSKNAVPRE = 65;
	const Sbecore::uint PNLWZSKOBJ1NSHOT = 66;
	const Sbecore::uint PNLWZSKOBJDETAIL = 67;
	const Sbecore::uint PNLWZSKOBJHEADBAR = 68;
	const Sbecore::uint PNLWZSKOBJLIST = 69;
	const Sbecore::uint PNLWZSKOBJREC = 70;
	const Sbecore::uint PNLWZSKOBJREF1NFILE = 71;
	const Sbecore::uint PNLWZSKOGR1NOBJECT = 72;
	const Sbecore::uint PNLWZSKOGRDETAIL = 73;
	const Sbecore::uint PNLWZSKOGRHEADBAR = 74;
	const Sbecore::uint PNLWZSKOGRLIST = 75;
	const Sbecore::uint PNLWZSKOGRREC = 76;
	const Sbecore::uint PNLWZSKOGRSUP1NOBJGROUP = 77;
	const Sbecore::uint PNLWZSKPRSADETAIL = 78;
	const Sbecore::uint PNLWZSKPRSDETAIL = 79;
	const Sbecore::uint PNLWZSKPRSHEADBAR = 80;
	const Sbecore::uint PNLWZSKPRSLIST = 81;
	const Sbecore::uint PNLWZSKPRSREC = 82;
	const Sbecore::uint PNLWZSKSCFCONN = 83;
	const Sbecore::uint PNLWZSKSCFGEOM = 84;
	const Sbecore::uint PNLWZSKSCFHEADBAR = 85;
	const Sbecore::uint PNLWZSKSES1NSHOT = 86;
	const Sbecore::uint PNLWZSKSESDETAIL = 87;
	const Sbecore::uint PNLWZSKSESHEADBAR = 88;
	const Sbecore::uint PNLWZSKSESLIST = 89;
	const Sbecore::uint PNLWZSKSESREC = 90;
	const Sbecore::uint PNLWZSKSHTAPAR = 91;
	const Sbecore::uint PNLWZSKSHTDETAIL = 92;
	const Sbecore::uint PNLWZSKSHTHEADBAR = 93;
	const Sbecore::uint PNLWZSKSHTLIST = 94;
	const Sbecore::uint PNLWZSKSHTREC = 95;
	const Sbecore::uint PNLWZSKSHTREF1NFILE = 96;
	const Sbecore::uint PNLWZSKUSGAACCESS = 97;
	const Sbecore::uint PNLWZSKUSGDETAIL = 98;
	const Sbecore::uint PNLWZSKUSGHEADBAR = 99;
	const Sbecore::uint PNLWZSKUSGLIST = 100;
	const Sbecore::uint PNLWZSKUSGMNUSER = 101;
	const Sbecore::uint PNLWZSKUSGREC = 102;
	const Sbecore::uint PNLWZSKUSR1NSESSION = 103;
	const Sbecore::uint PNLWZSKUSRAACCESS = 104;
	const Sbecore::uint PNLWZSKUSRDETAIL = 105;
	const Sbecore::uint PNLWZSKUSRHEADBAR = 106;
	const Sbecore::uint PNLWZSKUSRLIST = 107;
	const Sbecore::uint PNLWZSKUSRMNUSERGROUP = 108;
	const Sbecore::uint PNLWZSKUSRREC = 109;
	const Sbecore::uint QRYWZSKFILLIST = 110;
	const Sbecore::uint QRYWZSKOBJ1NSHOT = 111;
	const Sbecore::uint QRYWZSKOBJLIST = 112;
	const Sbecore::uint QRYWZSKOBJREF1NFILE = 113;
	const Sbecore::uint QRYWZSKOGR1NOBJECT = 114;
	const Sbecore::uint QRYWZSKOGRLIST = 115;
	const Sbecore::uint QRYWZSKOGRSUP1NOBJGROUP = 116;
	const Sbecore::uint QRYWZSKPRSADETAIL = 117;
	const Sbecore::uint QRYWZSKPRSLIST = 118;
	const Sbecore::uint QRYWZSKSES1NSHOT = 119;
	const Sbecore::uint QRYWZSKSESLIST = 120;
	const Sbecore::uint QRYWZSKSHTAPAR = 121;
	const Sbecore::uint QRYWZSKSHTLIST = 122;
	const Sbecore::uint QRYWZSKSHTREF1NFILE = 123;
	const Sbecore::uint QRYWZSKUSGAACCESS = 124;
	const Sbecore::uint QRYWZSKUSGLIST = 125;
	const Sbecore::uint QRYWZSKUSGMNUSER = 126;
	const Sbecore::uint QRYWZSKUSR1NSESSION = 127;
	const Sbecore::uint QRYWZSKUSRAACCESS = 128;
	const Sbecore::uint QRYWZSKUSRLIST = 129;
	const Sbecore::uint QRYWZSKUSRMNUSERGROUP = 130;
	const Sbecore::uint ROOTWZSK = 131;
	const Sbecore::uint SESSWZSK = 132;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
