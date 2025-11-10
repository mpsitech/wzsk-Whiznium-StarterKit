/**
	* \file VecWzskVDpch.h
	* vector VecWzskVDpch (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef VECWZSKVDPCH_H
#define VECWZSKVDPCH_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVDpch
	*/
namespace VecWzskVDpch {
	const Sbecore::uint DPCHENGDLGWZSKFILDOWNLOADDATA = 1;
	const Sbecore::uint DPCHENGDLGWZSKNAVLOAINIDATA = 2;
	const Sbecore::uint DPCHENGM2MSESSWZSKDATA = 3;
	const Sbecore::uint DPCHENGROOTWZSKDATA = 4;
	const Sbecore::uint DPCHENGSESSWZSKDATA = 5;
	const Sbecore::uint DPCHENGWZSKACK = 6;
	const Sbecore::uint DPCHENGWZSKALERT = 7;
	const Sbecore::uint DPCHENGWZSKCONFIRM = 8;
	const Sbecore::uint DPCHENGWZSKFILDATA = 9;
	const Sbecore::uint DPCHENGWZSKFILDETAILDATA = 10;
	const Sbecore::uint DPCHENGWZSKFILHEADBARDATA = 11;
	const Sbecore::uint DPCHENGWZSKFILLISTDATA = 12;
	const Sbecore::uint DPCHENGWZSKFILRECDATA = 13;
	const Sbecore::uint DPCHENGWZSKHWCASYSDATA = 14;
	const Sbecore::uint DPCHENGWZSKHWCCONFIGALIGN = 15;
	const Sbecore::uint DPCHENGWZSKHWCCONFIGDATA = 16;
	const Sbecore::uint DPCHENGWZSKHWCCONFIGLIVE = 17;
	const Sbecore::uint DPCHENGWZSKHWCDATA = 18;
	const Sbecore::uint DPCHENGWZSKHWCDEBUGDATA = 19;
	const Sbecore::uint DPCHENGWZSKHWCHEADBARDATA = 20;
	const Sbecore::uint DPCHENGWZSKLLVDATA = 21;
	const Sbecore::uint DPCHENGWZSKLLVHEADBARDATA = 22;
	const Sbecore::uint DPCHENGWZSKLLVIDENTDATA = 23;
	const Sbecore::uint DPCHENGWZSKLLVLASERDATA = 24;
	const Sbecore::uint DPCHENGWZSKLLVROTARYDATA = 25;
	const Sbecore::uint DPCHENGWZSKLLVSYSMONDATA = 26;
	const Sbecore::uint DPCHENGWZSKLLVSYSMONLIVE = 27;
	const Sbecore::uint DPCHENGWZSKLLVTERMDCVSPDATA = 28;
	const Sbecore::uint DPCHENGWZSKLLVTERMTIVSPDATA = 29;
	const Sbecore::uint DPCHENGWZSKLLVTERMZUVSPDATA = 30;
	const Sbecore::uint DPCHENGWZSKNAVADMINDATA = 31;
	const Sbecore::uint DPCHENGWZSKNAVDATA = 32;
	const Sbecore::uint DPCHENGWZSKNAVHEADBARDATA = 33;
	const Sbecore::uint DPCHENGWZSKNAVOPDATA = 34;
	const Sbecore::uint DPCHENGWZSKPRFACQCORNERDATA = 35;
	const Sbecore::uint DPCHENGWZSKPRFACQPREVIEWDATA = 36;
	const Sbecore::uint DPCHENGWZSKPRFACQTRACEDATA = 37;
	const Sbecore::uint DPCHENGWZSKPRFACTLASERDATA = 38;
	const Sbecore::uint DPCHENGWZSKPRFACTVISTOROTDATA = 39;
	const Sbecore::uint DPCHENGWZSKPRFDAEMONDATA = 40;
	const Sbecore::uint DPCHENGWZSKPRFDATA = 41;
	const Sbecore::uint DPCHENGWZSKPRFGLOBALDATA = 42;
	const Sbecore::uint DPCHENGWZSKPRFHEADBARDATA = 43;
	const Sbecore::uint DPCHENGWZSKPRFSRCDCVSPDATA = 44;
	const Sbecore::uint DPCHENGWZSKPRFSRCSYSINFODATA = 45;
	const Sbecore::uint DPCHENGWZSKPRFSRCTIVSPDATA = 46;
	const Sbecore::uint DPCHENGWZSKPRFSRCZUVSPDATA = 47;
	const Sbecore::uint DPCHENGWZSKPRSADETAILDATA = 48;
	const Sbecore::uint DPCHENGWZSKPRSDATA = 49;
	const Sbecore::uint DPCHENGWZSKPRSDETAILDATA = 50;
	const Sbecore::uint DPCHENGWZSKPRSHEADBARDATA = 51;
	const Sbecore::uint DPCHENGWZSKPRSLISTDATA = 52;
	const Sbecore::uint DPCHENGWZSKPRSRECDATA = 53;
	const Sbecore::uint DPCHENGWZSKSUSPEND = 54;
	const Sbecore::uint DPCHENGWZSKUSGAACCESSDATA = 55;
	const Sbecore::uint DPCHENGWZSKUSGDATA = 56;
	const Sbecore::uint DPCHENGWZSKUSGDETAILDATA = 57;
	const Sbecore::uint DPCHENGWZSKUSGHEADBARDATA = 58;
	const Sbecore::uint DPCHENGWZSKUSGLISTDATA = 59;
	const Sbecore::uint DPCHENGWZSKUSGMNUSERDATA = 60;
	const Sbecore::uint DPCHENGWZSKUSGRECDATA = 61;
	const Sbecore::uint DPCHENGWZSKUSR1NSESSIONDATA = 62;
	const Sbecore::uint DPCHENGWZSKUSRAACCESSDATA = 63;
	const Sbecore::uint DPCHENGWZSKUSRDATA = 64;
	const Sbecore::uint DPCHENGWZSKUSRDETAILDATA = 65;
	const Sbecore::uint DPCHENGWZSKUSRHEADBARDATA = 66;
	const Sbecore::uint DPCHENGWZSKUSRLISTDATA = 67;
	const Sbecore::uint DPCHENGWZSKUSRMNUSERGROUPDATA = 68;
	const Sbecore::uint DPCHENGWZSKUSRRECDATA = 69;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGALIGN = 70;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGDATA = 71;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGLIVE = 72;
	const Sbecore::uint DPCHENGWZSKVTRDATA = 73;
	const Sbecore::uint DPCHENGWZSKVTRDEBUGDATA = 74;
	const Sbecore::uint DPCHENGWZSKVTRHEADBARDATA = 75;
	const Sbecore::uint DPCHENGWZSKVTRMONITORDATA = 76;
	const Sbecore::uint DPCHENGWZSKVTRMONITORLIVE = 77;
	const Sbecore::uint DPCHAPPDLGWZSKFILDOWNLOADDO = 78;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDATA = 79;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDO = 80;
	const Sbecore::uint DPCHAPPROOTWZSKLOGIN = 81;
	const Sbecore::uint DPCHAPPWZSKALERT = 82;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDATA = 83;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDO = 84;
	const Sbecore::uint DPCHAPPWZSKFILDO = 85;
	const Sbecore::uint DPCHAPPWZSKFILLISTDATA = 86;
	const Sbecore::uint DPCHAPPWZSKFILLISTDO = 87;
	const Sbecore::uint DPCHAPPWZSKFILRECDO = 88;
	const Sbecore::uint DPCHAPPWZSKHWCASYSDO = 89;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGALIGN = 90;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGDATA = 91;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGDO = 92;
	const Sbecore::uint DPCHAPPWZSKHWCDEBUGDATA = 93;
	const Sbecore::uint DPCHAPPWZSKHWCDEBUGDO = 94;
	const Sbecore::uint DPCHAPPWZSKHWCDO = 95;
	const Sbecore::uint DPCHAPPWZSKINIT = 96;
	const Sbecore::uint DPCHAPPWZSKLLVDO = 97;
	const Sbecore::uint DPCHAPPWZSKLLVIDENTDO = 98;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDATA = 99;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDO = 100;
	const Sbecore::uint DPCHAPPWZSKLLVROTARYDATA = 101;
	const Sbecore::uint DPCHAPPWZSKLLVROTARYDO = 102;
	const Sbecore::uint DPCHAPPWZSKLLVSYSMONDO = 103;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDCVSPDATA = 104;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDCVSPDO = 105;
	const Sbecore::uint DPCHAPPWZSKLLVTERMTIVSPDATA = 106;
	const Sbecore::uint DPCHAPPWZSKLLVTERMTIVSPDO = 107;
	const Sbecore::uint DPCHAPPWZSKLLVTERMZUVSPDATA = 108;
	const Sbecore::uint DPCHAPPWZSKLLVTERMZUVSPDO = 109;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDATA = 110;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDO = 111;
	const Sbecore::uint DPCHAPPWZSKNAVDO = 112;
	const Sbecore::uint DPCHAPPWZSKNAVOPDATA = 113;
	const Sbecore::uint DPCHAPPWZSKNAVOPDO = 114;
	const Sbecore::uint DPCHAPPWZSKPRFACQCORNERDATA = 115;
	const Sbecore::uint DPCHAPPWZSKPRFACQCORNERDO = 116;
	const Sbecore::uint DPCHAPPWZSKPRFACQPREVIEWDATA = 117;
	const Sbecore::uint DPCHAPPWZSKPRFACQPREVIEWDO = 118;
	const Sbecore::uint DPCHAPPWZSKPRFACQTRACEDATA = 119;
	const Sbecore::uint DPCHAPPWZSKPRFACQTRACEDO = 120;
	const Sbecore::uint DPCHAPPWZSKPRFACTLASERDATA = 121;
	const Sbecore::uint DPCHAPPWZSKPRFACTLASERDO = 122;
	const Sbecore::uint DPCHAPPWZSKPRFACTVISTOROTDATA = 123;
	const Sbecore::uint DPCHAPPWZSKPRFACTVISTOROTDO = 124;
	const Sbecore::uint DPCHAPPWZSKPRFDAEMONDATA = 125;
	const Sbecore::uint DPCHAPPWZSKPRFDAEMONDO = 126;
	const Sbecore::uint DPCHAPPWZSKPRFDO = 127;
	const Sbecore::uint DPCHAPPWZSKPRFGLOBALDATA = 128;
	const Sbecore::uint DPCHAPPWZSKPRFGLOBALDO = 129;
	const Sbecore::uint DPCHAPPWZSKPRFSRCDCVSPDATA = 130;
	const Sbecore::uint DPCHAPPWZSKPRFSRCDCVSPDO = 131;
	const Sbecore::uint DPCHAPPWZSKPRFSRCSYSINFODATA = 132;
	const Sbecore::uint DPCHAPPWZSKPRFSRCSYSINFODO = 133;
	const Sbecore::uint DPCHAPPWZSKPRFSRCTIVSPDATA = 134;
	const Sbecore::uint DPCHAPPWZSKPRFSRCTIVSPDO = 135;
	const Sbecore::uint DPCHAPPWZSKPRFSRCZUVSPDATA = 136;
	const Sbecore::uint DPCHAPPWZSKPRFSRCZUVSPDO = 137;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDATA = 138;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDO = 139;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDATA = 140;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDO = 141;
	const Sbecore::uint DPCHAPPWZSKPRSDO = 142;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDATA = 143;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDO = 144;
	const Sbecore::uint DPCHAPPWZSKPRSRECDO = 145;
	const Sbecore::uint DPCHAPPWZSKRESUME = 146;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDATA = 147;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDO = 148;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDATA = 149;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDO = 150;
	const Sbecore::uint DPCHAPPWZSKUSGDO = 151;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDATA = 152;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDO = 153;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDATA = 154;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDO = 155;
	const Sbecore::uint DPCHAPPWZSKUSGRECDO = 156;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDATA = 157;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDO = 158;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDATA = 159;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDO = 160;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDATA = 161;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDO = 162;
	const Sbecore::uint DPCHAPPWZSKUSRDO = 163;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDATA = 164;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDO = 165;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDATA = 166;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDO = 167;
	const Sbecore::uint DPCHAPPWZSKUSRRECDO = 168;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGALIGN = 169;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGDATA = 170;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGDO = 171;
	const Sbecore::uint DPCHAPPWZSKVTRDEBUGDATA = 172;
	const Sbecore::uint DPCHAPPWZSKVTRDEBUGDO = 173;
	const Sbecore::uint DPCHAPPWZSKVTRDO = 174;
	const Sbecore::uint DPCHAPPWZSKVTRMONITORDO = 175;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
