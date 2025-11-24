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
	const Sbecore::uint DPCHENGWZSKPRFACQHDRDATA = 36;
	const Sbecore::uint DPCHENGWZSKPRFACQPREVIEWDATA = 37;
	const Sbecore::uint DPCHENGWZSKPRFACQTRACEDATA = 38;
	const Sbecore::uint DPCHENGWZSKPRFACTLASERDATA = 39;
	const Sbecore::uint DPCHENGWZSKPRFACTROTARYDATA = 40;
	const Sbecore::uint DPCHENGWZSKPRFACTVISTOROTDATA = 41;
	const Sbecore::uint DPCHENGWZSKPRFDAEMONDATA = 42;
	const Sbecore::uint DPCHENGWZSKPRFDATA = 43;
	const Sbecore::uint DPCHENGWZSKPRFGLOBALDATA = 44;
	const Sbecore::uint DPCHENGWZSKPRFHEADBARDATA = 45;
	const Sbecore::uint DPCHENGWZSKPRFSRCDCVSPDATA = 46;
	const Sbecore::uint DPCHENGWZSKPRFSRCSYSINFODATA = 47;
	const Sbecore::uint DPCHENGWZSKPRFSRCTIVSPDATA = 48;
	const Sbecore::uint DPCHENGWZSKPRFSRCZUVSPDATA = 49;
	const Sbecore::uint DPCHENGWZSKPRSADETAILDATA = 50;
	const Sbecore::uint DPCHENGWZSKPRSDATA = 51;
	const Sbecore::uint DPCHENGWZSKPRSDETAILDATA = 52;
	const Sbecore::uint DPCHENGWZSKPRSHEADBARDATA = 53;
	const Sbecore::uint DPCHENGWZSKPRSLISTDATA = 54;
	const Sbecore::uint DPCHENGWZSKPRSRECDATA = 55;
	const Sbecore::uint DPCHENGWZSKSUSPEND = 56;
	const Sbecore::uint DPCHENGWZSKUSGAACCESSDATA = 57;
	const Sbecore::uint DPCHENGWZSKUSGDATA = 58;
	const Sbecore::uint DPCHENGWZSKUSGDETAILDATA = 59;
	const Sbecore::uint DPCHENGWZSKUSGHEADBARDATA = 60;
	const Sbecore::uint DPCHENGWZSKUSGLISTDATA = 61;
	const Sbecore::uint DPCHENGWZSKUSGMNUSERDATA = 62;
	const Sbecore::uint DPCHENGWZSKUSGRECDATA = 63;
	const Sbecore::uint DPCHENGWZSKUSR1NSESSIONDATA = 64;
	const Sbecore::uint DPCHENGWZSKUSRAACCESSDATA = 65;
	const Sbecore::uint DPCHENGWZSKUSRDATA = 66;
	const Sbecore::uint DPCHENGWZSKUSRDETAILDATA = 67;
	const Sbecore::uint DPCHENGWZSKUSRHEADBARDATA = 68;
	const Sbecore::uint DPCHENGWZSKUSRLISTDATA = 69;
	const Sbecore::uint DPCHENGWZSKUSRMNUSERGROUPDATA = 70;
	const Sbecore::uint DPCHENGWZSKUSRRECDATA = 71;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGALIGN = 72;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGDATA = 73;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGLIVE = 74;
	const Sbecore::uint DPCHENGWZSKVTRDATA = 75;
	const Sbecore::uint DPCHENGWZSKVTRDEBUGDATA = 76;
	const Sbecore::uint DPCHENGWZSKVTRHEADBARDATA = 77;
	const Sbecore::uint DPCHENGWZSKVTRMONITORDATA = 78;
	const Sbecore::uint DPCHENGWZSKVTRMONITORLIVE = 79;
	const Sbecore::uint DPCHAPPDLGWZSKFILDOWNLOADDO = 80;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDATA = 81;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDO = 82;
	const Sbecore::uint DPCHAPPROOTWZSKLOGIN = 83;
	const Sbecore::uint DPCHAPPWZSKALERT = 84;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDATA = 85;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDO = 86;
	const Sbecore::uint DPCHAPPWZSKFILDO = 87;
	const Sbecore::uint DPCHAPPWZSKFILLISTDATA = 88;
	const Sbecore::uint DPCHAPPWZSKFILLISTDO = 89;
	const Sbecore::uint DPCHAPPWZSKFILRECDO = 90;
	const Sbecore::uint DPCHAPPWZSKHWCASYSDO = 91;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGALIGN = 92;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGDATA = 93;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGDO = 94;
	const Sbecore::uint DPCHAPPWZSKHWCDEBUGDATA = 95;
	const Sbecore::uint DPCHAPPWZSKHWCDEBUGDO = 96;
	const Sbecore::uint DPCHAPPWZSKHWCDO = 97;
	const Sbecore::uint DPCHAPPWZSKINIT = 98;
	const Sbecore::uint DPCHAPPWZSKLLVDO = 99;
	const Sbecore::uint DPCHAPPWZSKLLVIDENTDO = 100;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDATA = 101;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDO = 102;
	const Sbecore::uint DPCHAPPWZSKLLVROTARYDATA = 103;
	const Sbecore::uint DPCHAPPWZSKLLVROTARYDO = 104;
	const Sbecore::uint DPCHAPPWZSKLLVSYSMONDO = 105;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDCVSPDATA = 106;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDCVSPDO = 107;
	const Sbecore::uint DPCHAPPWZSKLLVTERMTIVSPDATA = 108;
	const Sbecore::uint DPCHAPPWZSKLLVTERMTIVSPDO = 109;
	const Sbecore::uint DPCHAPPWZSKLLVTERMZUVSPDATA = 110;
	const Sbecore::uint DPCHAPPWZSKLLVTERMZUVSPDO = 111;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDATA = 112;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDO = 113;
	const Sbecore::uint DPCHAPPWZSKNAVDO = 114;
	const Sbecore::uint DPCHAPPWZSKNAVOPDATA = 115;
	const Sbecore::uint DPCHAPPWZSKNAVOPDO = 116;
	const Sbecore::uint DPCHAPPWZSKPRFACQCORNERDATA = 117;
	const Sbecore::uint DPCHAPPWZSKPRFACQCORNERDO = 118;
	const Sbecore::uint DPCHAPPWZSKPRFACQHDRDATA = 119;
	const Sbecore::uint DPCHAPPWZSKPRFACQHDRDO = 120;
	const Sbecore::uint DPCHAPPWZSKPRFACQPREVIEWDATA = 121;
	const Sbecore::uint DPCHAPPWZSKPRFACQPREVIEWDO = 122;
	const Sbecore::uint DPCHAPPWZSKPRFACQTRACEDATA = 123;
	const Sbecore::uint DPCHAPPWZSKPRFACQTRACEDO = 124;
	const Sbecore::uint DPCHAPPWZSKPRFACTLASERDATA = 125;
	const Sbecore::uint DPCHAPPWZSKPRFACTLASERDO = 126;
	const Sbecore::uint DPCHAPPWZSKPRFACTROTARYDATA = 127;
	const Sbecore::uint DPCHAPPWZSKPRFACTROTARYDO = 128;
	const Sbecore::uint DPCHAPPWZSKPRFACTVISTOROTDATA = 129;
	const Sbecore::uint DPCHAPPWZSKPRFACTVISTOROTDO = 130;
	const Sbecore::uint DPCHAPPWZSKPRFDAEMONDATA = 131;
	const Sbecore::uint DPCHAPPWZSKPRFDAEMONDO = 132;
	const Sbecore::uint DPCHAPPWZSKPRFDO = 133;
	const Sbecore::uint DPCHAPPWZSKPRFGLOBALDATA = 134;
	const Sbecore::uint DPCHAPPWZSKPRFGLOBALDO = 135;
	const Sbecore::uint DPCHAPPWZSKPRFSRCDCVSPDATA = 136;
	const Sbecore::uint DPCHAPPWZSKPRFSRCDCVSPDO = 137;
	const Sbecore::uint DPCHAPPWZSKPRFSRCSYSINFODATA = 138;
	const Sbecore::uint DPCHAPPWZSKPRFSRCSYSINFODO = 139;
	const Sbecore::uint DPCHAPPWZSKPRFSRCTIVSPDATA = 140;
	const Sbecore::uint DPCHAPPWZSKPRFSRCTIVSPDO = 141;
	const Sbecore::uint DPCHAPPWZSKPRFSRCZUVSPDATA = 142;
	const Sbecore::uint DPCHAPPWZSKPRFSRCZUVSPDO = 143;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDATA = 144;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDO = 145;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDATA = 146;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDO = 147;
	const Sbecore::uint DPCHAPPWZSKPRSDO = 148;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDATA = 149;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDO = 150;
	const Sbecore::uint DPCHAPPWZSKPRSRECDO = 151;
	const Sbecore::uint DPCHAPPWZSKRESUME = 152;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDATA = 153;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDO = 154;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDATA = 155;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDO = 156;
	const Sbecore::uint DPCHAPPWZSKUSGDO = 157;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDATA = 158;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDO = 159;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDATA = 160;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDO = 161;
	const Sbecore::uint DPCHAPPWZSKUSGRECDO = 162;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDATA = 163;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDO = 164;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDATA = 165;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDO = 166;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDATA = 167;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDO = 168;
	const Sbecore::uint DPCHAPPWZSKUSRDO = 169;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDATA = 170;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDO = 171;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDATA = 172;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDO = 173;
	const Sbecore::uint DPCHAPPWZSKUSRRECDO = 174;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGALIGN = 175;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGDATA = 176;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGDO = 177;
	const Sbecore::uint DPCHAPPWZSKVTRDEBUGDATA = 178;
	const Sbecore::uint DPCHAPPWZSKVTRDEBUGDO = 179;
	const Sbecore::uint DPCHAPPWZSKVTRDO = 180;
	const Sbecore::uint DPCHAPPWZSKVTRMONITORDO = 181;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
