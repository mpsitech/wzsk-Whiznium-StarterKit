/**
	* \file VecWzskVJob.h
	* vector VecWzskVJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
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
	const Sbecore::uint CRDWZSKHWC = 2;
	const Sbecore::uint CRDWZSKLLV = 3;
	const Sbecore::uint CRDWZSKNAV = 4;
	const Sbecore::uint CRDWZSKPRF = 5;
	const Sbecore::uint CRDWZSKPRS = 6;
	const Sbecore::uint CRDWZSKUSG = 7;
	const Sbecore::uint CRDWZSKUSR = 8;
	const Sbecore::uint CRDWZSKVTR = 9;
	const Sbecore::uint DLGWZSKFILDOWNLOAD = 10;
	const Sbecore::uint DLGWZSKNAVLOAINI = 11;
	const Sbecore::uint JOBWZSKACQCORNER = 12;
	const Sbecore::uint JOBWZSKACQHDR = 13;
	const Sbecore::uint JOBWZSKACQMEMTRACK = 14;
	const Sbecore::uint JOBWZSKACQPREVIEW = 15;
	const Sbecore::uint JOBWZSKACQTRACE = 16;
	const Sbecore::uint JOBWZSKACQVTRTRACK = 17;
	const Sbecore::uint JOBWZSKACTLASER = 18;
	const Sbecore::uint JOBWZSKACTROTARY = 19;
	const Sbecore::uint JOBWZSKACTVISTOROT = 20;
	const Sbecore::uint JOBWZSKIEXINI = 21;
	const Sbecore::uint JOBWZSKPRCANGLE = 22;
	const Sbecore::uint JOBWZSKPRCWAVELET = 23;
	const Sbecore::uint JOBWZSKSRCDCVSP = 24;
	const Sbecore::uint JOBWZSKSRCFPGAINFO = 25;
	const Sbecore::uint JOBWZSKSRCSYSINFO = 26;
	const Sbecore::uint JOBWZSKSRCTIVSP = 27;
	const Sbecore::uint JOBWZSKSRCZUVSP = 28;
	const Sbecore::uint M2MSESSWZSK = 29;
	const Sbecore::uint PNLWZSKFILDETAIL = 30;
	const Sbecore::uint PNLWZSKFILHEADBAR = 31;
	const Sbecore::uint PNLWZSKFILLIST = 32;
	const Sbecore::uint PNLWZSKFILREC = 33;
	const Sbecore::uint PNLWZSKHWCASYS = 34;
	const Sbecore::uint PNLWZSKHWCCONFIG = 35;
	const Sbecore::uint PNLWZSKHWCDEBUG = 36;
	const Sbecore::uint PNLWZSKHWCHEADBAR = 37;
	const Sbecore::uint PNLWZSKLLVHEADBAR = 38;
	const Sbecore::uint PNLWZSKLLVIDENT = 39;
	const Sbecore::uint PNLWZSKLLVLASER = 40;
	const Sbecore::uint PNLWZSKLLVROTARY = 41;
	const Sbecore::uint PNLWZSKLLVSYSMON = 42;
	const Sbecore::uint PNLWZSKLLVTERMDCVSP = 43;
	const Sbecore::uint PNLWZSKLLVTERMTIVSP = 44;
	const Sbecore::uint PNLWZSKLLVTERMZUVSP = 45;
	const Sbecore::uint PNLWZSKNAVADMIN = 46;
	const Sbecore::uint PNLWZSKNAVHEADBAR = 47;
	const Sbecore::uint PNLWZSKNAVOP = 48;
	const Sbecore::uint PNLWZSKPRFACQCORNER = 49;
	const Sbecore::uint PNLWZSKPRFACQPREVIEW = 50;
	const Sbecore::uint PNLWZSKPRFACQTRACE = 51;
	const Sbecore::uint PNLWZSKPRFACTLASER = 52;
	const Sbecore::uint PNLWZSKPRFACTVISTOROT = 53;
	const Sbecore::uint PNLWZSKPRFDAEMON = 54;
	const Sbecore::uint PNLWZSKPRFGLOBAL = 55;
	const Sbecore::uint PNLWZSKPRFHEADBAR = 56;
	const Sbecore::uint PNLWZSKPRFSRCDCVSP = 57;
	const Sbecore::uint PNLWZSKPRFSRCSYSINFO = 58;
	const Sbecore::uint PNLWZSKPRFSRCTIVSP = 59;
	const Sbecore::uint PNLWZSKPRFSRCZUVSP = 60;
	const Sbecore::uint PNLWZSKPRSADETAIL = 61;
	const Sbecore::uint PNLWZSKPRSDETAIL = 62;
	const Sbecore::uint PNLWZSKPRSHEADBAR = 63;
	const Sbecore::uint PNLWZSKPRSLIST = 64;
	const Sbecore::uint PNLWZSKPRSREC = 65;
	const Sbecore::uint PNLWZSKUSGAACCESS = 66;
	const Sbecore::uint PNLWZSKUSGDETAIL = 67;
	const Sbecore::uint PNLWZSKUSGHEADBAR = 68;
	const Sbecore::uint PNLWZSKUSGLIST = 69;
	const Sbecore::uint PNLWZSKUSGMNUSER = 70;
	const Sbecore::uint PNLWZSKUSGREC = 71;
	const Sbecore::uint PNLWZSKUSR1NSESSION = 72;
	const Sbecore::uint PNLWZSKUSRAACCESS = 73;
	const Sbecore::uint PNLWZSKUSRDETAIL = 74;
	const Sbecore::uint PNLWZSKUSRHEADBAR = 75;
	const Sbecore::uint PNLWZSKUSRLIST = 76;
	const Sbecore::uint PNLWZSKUSRMNUSERGROUP = 77;
	const Sbecore::uint PNLWZSKUSRREC = 78;
	const Sbecore::uint PNLWZSKVTRCONFIG = 79;
	const Sbecore::uint PNLWZSKVTRDEBUG = 80;
	const Sbecore::uint PNLWZSKVTRHEADBAR = 81;
	const Sbecore::uint PNLWZSKVTRMONITOR = 82;
	const Sbecore::uint QRYWZSKFILLIST = 83;
	const Sbecore::uint QRYWZSKPRSADETAIL = 84;
	const Sbecore::uint QRYWZSKPRSLIST = 85;
	const Sbecore::uint QRYWZSKUSGAACCESS = 86;
	const Sbecore::uint QRYWZSKUSGLIST = 87;
	const Sbecore::uint QRYWZSKUSGMNUSER = 88;
	const Sbecore::uint QRYWZSKUSR1NSESSION = 89;
	const Sbecore::uint QRYWZSKUSRAACCESS = 90;
	const Sbecore::uint QRYWZSKUSRLIST = 91;
	const Sbecore::uint QRYWZSKUSRMNUSERGROUP = 92;
	const Sbecore::uint ROOTWZSK = 93;
	const Sbecore::uint SESSWZSK = 94;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
