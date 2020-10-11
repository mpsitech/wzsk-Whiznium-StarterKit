/**
	* \file VecWzskVJob.h
	* vector VecWzskVJob (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

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
	const Sbecore::uint JOBWZSKSRCFPGA = 31;
	const Sbecore::uint JOBWZSKSRCSYSINFO = 32;
	const Sbecore::uint JOBWZSKSRCV4L2 = 33;
	const Sbecore::uint M2MSESSWZSK = 34;
	const Sbecore::uint PNLWZSKFILDETAIL = 35;
	const Sbecore::uint PNLWZSKFILHEADBAR = 36;
	const Sbecore::uint PNLWZSKFILLIST = 37;
	const Sbecore::uint PNLWZSKFILREC = 38;
	const Sbecore::uint PNLWZSKLIV2DVIEW = 39;
	const Sbecore::uint PNLWZSKLIV3DVIEW = 40;
	const Sbecore::uint PNLWZSKLIVHEADBAR = 41;
	const Sbecore::uint PNLWZSKLIVSYSMON = 42;
	const Sbecore::uint PNLWZSKLLVCAMERA = 43;
	const Sbecore::uint PNLWZSKLLVHEADBAR = 44;
	const Sbecore::uint PNLWZSKLLVLASER = 45;
	const Sbecore::uint PNLWZSKLLVTERM = 46;
	const Sbecore::uint PNLWZSKLLVTTABLE = 47;
	const Sbecore::uint PNLWZSKNAVADMIN = 48;
	const Sbecore::uint PNLWZSKNAVGALERY = 49;
	const Sbecore::uint PNLWZSKNAVHEADBAR = 50;
	const Sbecore::uint PNLWZSKNAVOP = 51;
	const Sbecore::uint PNLWZSKNAVPRE = 52;
	const Sbecore::uint PNLWZSKOBJ1NSHOT = 53;
	const Sbecore::uint PNLWZSKOBJDETAIL = 54;
	const Sbecore::uint PNLWZSKOBJHEADBAR = 55;
	const Sbecore::uint PNLWZSKOBJLIST = 56;
	const Sbecore::uint PNLWZSKOBJREC = 57;
	const Sbecore::uint PNLWZSKOBJREF1NFILE = 58;
	const Sbecore::uint PNLWZSKOGR1NOBJECT = 59;
	const Sbecore::uint PNLWZSKOGRDETAIL = 60;
	const Sbecore::uint PNLWZSKOGRHEADBAR = 61;
	const Sbecore::uint PNLWZSKOGRLIST = 62;
	const Sbecore::uint PNLWZSKOGRREC = 63;
	const Sbecore::uint PNLWZSKOGRSUP1NOBJGROUP = 64;
	const Sbecore::uint PNLWZSKPRSADETAIL = 65;
	const Sbecore::uint PNLWZSKPRSDETAIL = 66;
	const Sbecore::uint PNLWZSKPRSHEADBAR = 67;
	const Sbecore::uint PNLWZSKPRSLIST = 68;
	const Sbecore::uint PNLWZSKPRSREC = 69;
	const Sbecore::uint PNLWZSKSCFCONN = 70;
	const Sbecore::uint PNLWZSKSCFGEOM = 71;
	const Sbecore::uint PNLWZSKSCFHEADBAR = 72;
	const Sbecore::uint PNLWZSKSES1NSHOT = 73;
	const Sbecore::uint PNLWZSKSESDETAIL = 74;
	const Sbecore::uint PNLWZSKSESHEADBAR = 75;
	const Sbecore::uint PNLWZSKSESLIST = 76;
	const Sbecore::uint PNLWZSKSESREC = 77;
	const Sbecore::uint PNLWZSKSHTAPAR = 78;
	const Sbecore::uint PNLWZSKSHTDETAIL = 79;
	const Sbecore::uint PNLWZSKSHTHEADBAR = 80;
	const Sbecore::uint PNLWZSKSHTLIST = 81;
	const Sbecore::uint PNLWZSKSHTREC = 82;
	const Sbecore::uint PNLWZSKSHTREF1NFILE = 83;
	const Sbecore::uint PNLWZSKUSGAACCESS = 84;
	const Sbecore::uint PNLWZSKUSGDETAIL = 85;
	const Sbecore::uint PNLWZSKUSGHEADBAR = 86;
	const Sbecore::uint PNLWZSKUSGLIST = 87;
	const Sbecore::uint PNLWZSKUSGMNUSER = 88;
	const Sbecore::uint PNLWZSKUSGREC = 89;
	const Sbecore::uint PNLWZSKUSR1NSESSION = 90;
	const Sbecore::uint PNLWZSKUSRAACCESS = 91;
	const Sbecore::uint PNLWZSKUSRDETAIL = 92;
	const Sbecore::uint PNLWZSKUSRHEADBAR = 93;
	const Sbecore::uint PNLWZSKUSRLIST = 94;
	const Sbecore::uint PNLWZSKUSRMNUSERGROUP = 95;
	const Sbecore::uint PNLWZSKUSRREC = 96;
	const Sbecore::uint QRYWZSKFILLIST = 97;
	const Sbecore::uint QRYWZSKOBJ1NSHOT = 98;
	const Sbecore::uint QRYWZSKOBJLIST = 99;
	const Sbecore::uint QRYWZSKOBJREF1NFILE = 100;
	const Sbecore::uint QRYWZSKOGR1NOBJECT = 101;
	const Sbecore::uint QRYWZSKOGRLIST = 102;
	const Sbecore::uint QRYWZSKOGRSUP1NOBJGROUP = 103;
	const Sbecore::uint QRYWZSKPRSADETAIL = 104;
	const Sbecore::uint QRYWZSKPRSLIST = 105;
	const Sbecore::uint QRYWZSKSES1NSHOT = 106;
	const Sbecore::uint QRYWZSKSESLIST = 107;
	const Sbecore::uint QRYWZSKSHTAPAR = 108;
	const Sbecore::uint QRYWZSKSHTLIST = 109;
	const Sbecore::uint QRYWZSKSHTREF1NFILE = 110;
	const Sbecore::uint QRYWZSKUSGAACCESS = 111;
	const Sbecore::uint QRYWZSKUSGLIST = 112;
	const Sbecore::uint QRYWZSKUSGMNUSER = 113;
	const Sbecore::uint QRYWZSKUSR1NSESSION = 114;
	const Sbecore::uint QRYWZSKUSRAACCESS = 115;
	const Sbecore::uint QRYWZSKUSRLIST = 116;
	const Sbecore::uint QRYWZSKUSRMNUSERGROUP = 117;
	const Sbecore::uint ROOTWZSK = 118;
	const Sbecore::uint SESSWZSK = 119;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

