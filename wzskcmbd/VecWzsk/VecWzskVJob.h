/**
	* \file VecWzskVJob.h
	* vector VecWzskVJob (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
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
	const Sbecore::uint JOBWZSKACTLASER = 24;
	const Sbecore::uint JOBWZSKACTSERVO = 25;
	const Sbecore::uint JOBWZSKIEXINI = 26;
	const Sbecore::uint JOBWZSKIPRANGLE = 27;
	const Sbecore::uint JOBWZSKIPRCORNER = 28;
	const Sbecore::uint JOBWZSKIPRTRACE = 29;
	const Sbecore::uint JOBWZSKSRCFPGA = 30;
	const Sbecore::uint JOBWZSKSRCV4L2 = 31;
	const Sbecore::uint M2MSESSWZSK = 32;
	const Sbecore::uint PNLWZSKFILDETAIL = 33;
	const Sbecore::uint PNLWZSKFILHEADBAR = 34;
	const Sbecore::uint PNLWZSKFILLIST = 35;
	const Sbecore::uint PNLWZSKFILREC = 36;
	const Sbecore::uint PNLWZSKLIV2DVIEW = 37;
	const Sbecore::uint PNLWZSKLIV3DVIEW = 38;
	const Sbecore::uint PNLWZSKLIVHEADBAR = 39;
	const Sbecore::uint PNLWZSKLLVCAMERA = 40;
	const Sbecore::uint PNLWZSKLLVHEADBAR = 41;
	const Sbecore::uint PNLWZSKLLVLASER = 42;
	const Sbecore::uint PNLWZSKLLVTERM = 43;
	const Sbecore::uint PNLWZSKLLVTTABLE = 44;
	const Sbecore::uint PNLWZSKNAVADMIN = 45;
	const Sbecore::uint PNLWZSKNAVGALERY = 46;
	const Sbecore::uint PNLWZSKNAVHEADBAR = 47;
	const Sbecore::uint PNLWZSKNAVOP = 48;
	const Sbecore::uint PNLWZSKNAVPRE = 49;
	const Sbecore::uint PNLWZSKOBJDETAIL = 50;
	const Sbecore::uint PNLWZSKOBJHEADBAR = 51;
	const Sbecore::uint PNLWZSKOBJLIST = 52;
	const Sbecore::uint PNLWZSKOBJREC = 53;
	const Sbecore::uint PNLWZSKOBJREF1NFILE = 54;
	const Sbecore::uint PNLWZSKOGR1NOBJECT = 55;
	const Sbecore::uint PNLWZSKOGR1NSHOT = 56;
	const Sbecore::uint PNLWZSKOGRDETAIL = 57;
	const Sbecore::uint PNLWZSKOGRHEADBAR = 58;
	const Sbecore::uint PNLWZSKOGRLIST = 59;
	const Sbecore::uint PNLWZSKOGRREC = 60;
	const Sbecore::uint PNLWZSKOGRSUP1NOBJGROUP = 61;
	const Sbecore::uint PNLWZSKPRSADETAIL = 62;
	const Sbecore::uint PNLWZSKPRSDETAIL = 63;
	const Sbecore::uint PNLWZSKPRSHEADBAR = 64;
	const Sbecore::uint PNLWZSKPRSLIST = 65;
	const Sbecore::uint PNLWZSKPRSREC = 66;
	const Sbecore::uint PNLWZSKSCFCONN = 67;
	const Sbecore::uint PNLWZSKSCFGEOM = 68;
	const Sbecore::uint PNLWZSKSCFHEADBAR = 69;
	const Sbecore::uint PNLWZSKSES1NSHOT = 70;
	const Sbecore::uint PNLWZSKSESDETAIL = 71;
	const Sbecore::uint PNLWZSKSESHEADBAR = 72;
	const Sbecore::uint PNLWZSKSESLIST = 73;
	const Sbecore::uint PNLWZSKSESREC = 74;
	const Sbecore::uint PNLWZSKSHTAPAR = 75;
	const Sbecore::uint PNLWZSKSHTDETAIL = 76;
	const Sbecore::uint PNLWZSKSHTHEADBAR = 77;
	const Sbecore::uint PNLWZSKSHTLIST = 78;
	const Sbecore::uint PNLWZSKSHTREC = 79;
	const Sbecore::uint PNLWZSKSHTREF1NFILE = 80;
	const Sbecore::uint PNLWZSKUSGAACCESS = 81;
	const Sbecore::uint PNLWZSKUSGDETAIL = 82;
	const Sbecore::uint PNLWZSKUSGHEADBAR = 83;
	const Sbecore::uint PNLWZSKUSGLIST = 84;
	const Sbecore::uint PNLWZSKUSGMNUSER = 85;
	const Sbecore::uint PNLWZSKUSGREC = 86;
	const Sbecore::uint PNLWZSKUSR1NSESSION = 87;
	const Sbecore::uint PNLWZSKUSRAACCESS = 88;
	const Sbecore::uint PNLWZSKUSRDETAIL = 89;
	const Sbecore::uint PNLWZSKUSRHEADBAR = 90;
	const Sbecore::uint PNLWZSKUSRLIST = 91;
	const Sbecore::uint PNLWZSKUSRMNUSERGROUP = 92;
	const Sbecore::uint PNLWZSKUSRREC = 93;
	const Sbecore::uint QRYWZSKFILLIST = 94;
	const Sbecore::uint QRYWZSKOBJLIST = 95;
	const Sbecore::uint QRYWZSKOBJREF1NFILE = 96;
	const Sbecore::uint QRYWZSKOGR1NOBJECT = 97;
	const Sbecore::uint QRYWZSKOGR1NSHOT = 98;
	const Sbecore::uint QRYWZSKOGRLIST = 99;
	const Sbecore::uint QRYWZSKOGRSUP1NOBJGROUP = 100;
	const Sbecore::uint QRYWZSKPRSADETAIL = 101;
	const Sbecore::uint QRYWZSKPRSLIST = 102;
	const Sbecore::uint QRYWZSKSES1NSHOT = 103;
	const Sbecore::uint QRYWZSKSESLIST = 104;
	const Sbecore::uint QRYWZSKSHTAPAR = 105;
	const Sbecore::uint QRYWZSKSHTLIST = 106;
	const Sbecore::uint QRYWZSKSHTREF1NFILE = 107;
	const Sbecore::uint QRYWZSKUSGAACCESS = 108;
	const Sbecore::uint QRYWZSKUSGLIST = 109;
	const Sbecore::uint QRYWZSKUSGMNUSER = 110;
	const Sbecore::uint QRYWZSKUSR1NSESSION = 111;
	const Sbecore::uint QRYWZSKUSRAACCESS = 112;
	const Sbecore::uint QRYWZSKUSRLIST = 113;
	const Sbecore::uint QRYWZSKUSRMNUSERGROUP = 114;
	const Sbecore::uint ROOTWZSK = 115;
	const Sbecore::uint SESSWZSK = 116;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

