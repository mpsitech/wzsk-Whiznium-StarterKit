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
	const Sbecore::uint DPCHAPPDLGWZSKFILDOWNLOADDO = 1;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDATA = 2;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDO = 3;
	const Sbecore::uint DPCHAPPROOTWZSKLOGIN = 4;
	const Sbecore::uint DPCHAPPWZSKALERT = 5;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDATA = 6;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDO = 7;
	const Sbecore::uint DPCHAPPWZSKFILDO = 8;
	const Sbecore::uint DPCHAPPWZSKFILLISTDATA = 9;
	const Sbecore::uint DPCHAPPWZSKFILLISTDO = 10;
	const Sbecore::uint DPCHAPPWZSKFILRECDO = 11;
	const Sbecore::uint DPCHAPPWZSKHWCASYSDO = 12;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGALIGN = 13;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGDATA = 14;
	const Sbecore::uint DPCHAPPWZSKHWCCONFIGDO = 15;
	const Sbecore::uint DPCHAPPWZSKHWCDEBUGDATA = 16;
	const Sbecore::uint DPCHAPPWZSKHWCDEBUGDO = 17;
	const Sbecore::uint DPCHAPPWZSKHWCDO = 18;
	const Sbecore::uint DPCHAPPWZSKINIT = 19;
	const Sbecore::uint DPCHAPPWZSKLLVDO = 20;
	const Sbecore::uint DPCHAPPWZSKLLVIDENTDO = 21;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDATA = 22;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDO = 23;
	const Sbecore::uint DPCHAPPWZSKLLVROTARYDATA = 24;
	const Sbecore::uint DPCHAPPWZSKLLVROTARYDO = 25;
	const Sbecore::uint DPCHAPPWZSKLLVSYSMONDO = 26;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDCVSPDATA = 27;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDCVSPDO = 28;
	const Sbecore::uint DPCHAPPWZSKLLVTERMTIVSPDATA = 29;
	const Sbecore::uint DPCHAPPWZSKLLVTERMTIVSPDO = 30;
	const Sbecore::uint DPCHAPPWZSKLLVTERMZUVSPDATA = 31;
	const Sbecore::uint DPCHAPPWZSKLLVTERMZUVSPDO = 32;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDATA = 33;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDO = 34;
	const Sbecore::uint DPCHAPPWZSKNAVDO = 35;
	const Sbecore::uint DPCHAPPWZSKNAVOPDATA = 36;
	const Sbecore::uint DPCHAPPWZSKNAVOPDO = 37;
	const Sbecore::uint DPCHAPPWZSKPRFACQCORNERDATA = 38;
	const Sbecore::uint DPCHAPPWZSKPRFACQCORNERDO = 39;
	const Sbecore::uint DPCHAPPWZSKPRFACQPREVIEWDATA = 40;
	const Sbecore::uint DPCHAPPWZSKPRFACQPREVIEWDO = 41;
	const Sbecore::uint DPCHAPPWZSKPRFACQTRACEDATA = 42;
	const Sbecore::uint DPCHAPPWZSKPRFACQTRACEDO = 43;
	const Sbecore::uint DPCHAPPWZSKPRFACTLASERDATA = 44;
	const Sbecore::uint DPCHAPPWZSKPRFACTLASERDO = 45;
	const Sbecore::uint DPCHAPPWZSKPRFACTVISTOROTDATA = 46;
	const Sbecore::uint DPCHAPPWZSKPRFACTVISTOROTDO = 47;
	const Sbecore::uint DPCHAPPWZSKPRFDAEMONDATA = 48;
	const Sbecore::uint DPCHAPPWZSKPRFDAEMONDO = 49;
	const Sbecore::uint DPCHAPPWZSKPRFDO = 50;
	const Sbecore::uint DPCHAPPWZSKPRFGLOBALDATA = 51;
	const Sbecore::uint DPCHAPPWZSKPRFGLOBALDO = 52;
	const Sbecore::uint DPCHAPPWZSKPRFSRCDCVSPDATA = 53;
	const Sbecore::uint DPCHAPPWZSKPRFSRCDCVSPDO = 54;
	const Sbecore::uint DPCHAPPWZSKPRFSRCSYSINFODATA = 55;
	const Sbecore::uint DPCHAPPWZSKPRFSRCSYSINFODO = 56;
	const Sbecore::uint DPCHAPPWZSKPRFSRCTIVSPDATA = 57;
	const Sbecore::uint DPCHAPPWZSKPRFSRCTIVSPDO = 58;
	const Sbecore::uint DPCHAPPWZSKPRFSRCZUVSPDATA = 59;
	const Sbecore::uint DPCHAPPWZSKPRFSRCZUVSPDO = 60;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDATA = 61;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDO = 62;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDATA = 63;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDO = 64;
	const Sbecore::uint DPCHAPPWZSKPRSDO = 65;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDATA = 66;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDO = 67;
	const Sbecore::uint DPCHAPPWZSKPRSRECDO = 68;
	const Sbecore::uint DPCHAPPWZSKRESUME = 69;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDATA = 70;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDO = 71;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDATA = 72;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDO = 73;
	const Sbecore::uint DPCHAPPWZSKUSGDO = 74;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDATA = 75;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDO = 76;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDATA = 77;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDO = 78;
	const Sbecore::uint DPCHAPPWZSKUSGRECDO = 79;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDATA = 80;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDO = 81;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDATA = 82;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDO = 83;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDATA = 84;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDO = 85;
	const Sbecore::uint DPCHAPPWZSKUSRDO = 86;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDATA = 87;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDO = 88;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDATA = 89;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDO = 90;
	const Sbecore::uint DPCHAPPWZSKUSRRECDO = 91;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGALIGN = 92;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGDATA = 93;
	const Sbecore::uint DPCHAPPWZSKVTRCONFIGDO = 94;
	const Sbecore::uint DPCHAPPWZSKVTRDEBUGDATA = 95;
	const Sbecore::uint DPCHAPPWZSKVTRDEBUGDO = 96;
	const Sbecore::uint DPCHAPPWZSKVTRDO = 97;
	const Sbecore::uint DPCHAPPWZSKVTRMONITORDO = 98;
	const Sbecore::uint DPCHENGDLGWZSKFILDOWNLOADDATA = 99;
	const Sbecore::uint DPCHENGDLGWZSKNAVLOAINIDATA = 100;
	const Sbecore::uint DPCHENGM2MSESSWZSKDATA = 101;
	const Sbecore::uint DPCHENGROOTWZSKDATA = 102;
	const Sbecore::uint DPCHENGSESSWZSKDATA = 103;
	const Sbecore::uint DPCHENGWZSKACK = 104;
	const Sbecore::uint DPCHENGWZSKALERT = 105;
	const Sbecore::uint DPCHENGWZSKCONFIRM = 106;
	const Sbecore::uint DPCHENGWZSKFILDATA = 107;
	const Sbecore::uint DPCHENGWZSKFILDETAILDATA = 108;
	const Sbecore::uint DPCHENGWZSKFILHEADBARDATA = 109;
	const Sbecore::uint DPCHENGWZSKFILLISTDATA = 110;
	const Sbecore::uint DPCHENGWZSKFILRECDATA = 111;
	const Sbecore::uint DPCHENGWZSKHWCASYSDATA = 112;
	const Sbecore::uint DPCHENGWZSKHWCCONFIGALIGN = 113;
	const Sbecore::uint DPCHENGWZSKHWCCONFIGDATA = 114;
	const Sbecore::uint DPCHENGWZSKHWCCONFIGLIVE = 115;
	const Sbecore::uint DPCHENGWZSKHWCDATA = 116;
	const Sbecore::uint DPCHENGWZSKHWCDEBUGDATA = 117;
	const Sbecore::uint DPCHENGWZSKHWCHEADBARDATA = 118;
	const Sbecore::uint DPCHENGWZSKLLVDATA = 119;
	const Sbecore::uint DPCHENGWZSKLLVHEADBARDATA = 120;
	const Sbecore::uint DPCHENGWZSKLLVIDENTDATA = 121;
	const Sbecore::uint DPCHENGWZSKLLVLASERDATA = 122;
	const Sbecore::uint DPCHENGWZSKLLVROTARYDATA = 123;
	const Sbecore::uint DPCHENGWZSKLLVSYSMONDATA = 124;
	const Sbecore::uint DPCHENGWZSKLLVSYSMONLIVE = 125;
	const Sbecore::uint DPCHENGWZSKLLVTERMDCVSPDATA = 126;
	const Sbecore::uint DPCHENGWZSKLLVTERMTIVSPDATA = 127;
	const Sbecore::uint DPCHENGWZSKLLVTERMZUVSPDATA = 128;
	const Sbecore::uint DPCHENGWZSKNAVADMINDATA = 129;
	const Sbecore::uint DPCHENGWZSKNAVDATA = 130;
	const Sbecore::uint DPCHENGWZSKNAVHEADBARDATA = 131;
	const Sbecore::uint DPCHENGWZSKNAVOPDATA = 132;
	const Sbecore::uint DPCHENGWZSKPRFACQCORNERDATA = 133;
	const Sbecore::uint DPCHENGWZSKPRFACQPREVIEWDATA = 134;
	const Sbecore::uint DPCHENGWZSKPRFACQTRACEDATA = 135;
	const Sbecore::uint DPCHENGWZSKPRFACTLASERDATA = 136;
	const Sbecore::uint DPCHENGWZSKPRFACTVISTOROTDATA = 137;
	const Sbecore::uint DPCHENGWZSKPRFDAEMONDATA = 138;
	const Sbecore::uint DPCHENGWZSKPRFDATA = 139;
	const Sbecore::uint DPCHENGWZSKPRFGLOBALDATA = 140;
	const Sbecore::uint DPCHENGWZSKPRFHEADBARDATA = 141;
	const Sbecore::uint DPCHENGWZSKPRFSRCDCVSPDATA = 142;
	const Sbecore::uint DPCHENGWZSKPRFSRCSYSINFODATA = 143;
	const Sbecore::uint DPCHENGWZSKPRFSRCTIVSPDATA = 144;
	const Sbecore::uint DPCHENGWZSKPRFSRCZUVSPDATA = 145;
	const Sbecore::uint DPCHENGWZSKPRSADETAILDATA = 146;
	const Sbecore::uint DPCHENGWZSKPRSDATA = 147;
	const Sbecore::uint DPCHENGWZSKPRSDETAILDATA = 148;
	const Sbecore::uint DPCHENGWZSKPRSHEADBARDATA = 149;
	const Sbecore::uint DPCHENGWZSKPRSLISTDATA = 150;
	const Sbecore::uint DPCHENGWZSKPRSRECDATA = 151;
	const Sbecore::uint DPCHENGWZSKSUSPEND = 152;
	const Sbecore::uint DPCHENGWZSKUSGAACCESSDATA = 153;
	const Sbecore::uint DPCHENGWZSKUSGDATA = 154;
	const Sbecore::uint DPCHENGWZSKUSGDETAILDATA = 155;
	const Sbecore::uint DPCHENGWZSKUSGHEADBARDATA = 156;
	const Sbecore::uint DPCHENGWZSKUSGLISTDATA = 157;
	const Sbecore::uint DPCHENGWZSKUSGMNUSERDATA = 158;
	const Sbecore::uint DPCHENGWZSKUSGRECDATA = 159;
	const Sbecore::uint DPCHENGWZSKUSR1NSESSIONDATA = 160;
	const Sbecore::uint DPCHENGWZSKUSRAACCESSDATA = 161;
	const Sbecore::uint DPCHENGWZSKUSRDATA = 162;
	const Sbecore::uint DPCHENGWZSKUSRDETAILDATA = 163;
	const Sbecore::uint DPCHENGWZSKUSRHEADBARDATA = 164;
	const Sbecore::uint DPCHENGWZSKUSRLISTDATA = 165;
	const Sbecore::uint DPCHENGWZSKUSRMNUSERGROUPDATA = 166;
	const Sbecore::uint DPCHENGWZSKUSRRECDATA = 167;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGALIGN = 168;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGDATA = 169;
	const Sbecore::uint DPCHENGWZSKVTRCONFIGLIVE = 170;
	const Sbecore::uint DPCHENGWZSKVTRDATA = 171;
	const Sbecore::uint DPCHENGWZSKVTRDEBUGDATA = 172;
	const Sbecore::uint DPCHENGWZSKVTRHEADBARDATA = 173;
	const Sbecore::uint DPCHENGWZSKVTRMONITORDATA = 174;
	const Sbecore::uint DPCHENGWZSKVTRMONITORLIVE = 175;
	const Sbecore::uint DPCHINVWZSK = 176;
	const Sbecore::uint DPCHRETWZSK = 177;
	const Sbecore::uint DPCHWZSKDACK = 178;
	const Sbecore::uint DPCHWZSKDQUIT = 179;
	const Sbecore::uint DPCHWZSKDREG = 180;
	const Sbecore::uint DPCHWZSKOPDREG = 181;
	const Sbecore::uint DPCHWZSKOPDUNREG = 182;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
