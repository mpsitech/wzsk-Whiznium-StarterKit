/**
	* \file VecWzskVDpch.h
	* vector VecWzskVDpch (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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
	const Sbecore::uint DPCHENGDLGWZSKOBJNEWDATA = 3;
	const Sbecore::uint DPCHENGDLGWZSKOGRNEWDATA = 4;
	const Sbecore::uint DPCHENGDLGWZSKSCFCAMERAMATDATA = 5;
	const Sbecore::uint DPCHENGDLGWZSKSCFLASERPOSDATA = 6;
	const Sbecore::uint DPCHENGDLGWZSKSCFTTABLECOORDDATA = 7;
	const Sbecore::uint DPCHENGM2MSESSWZSKDATA = 8;
	const Sbecore::uint DPCHENGROOTWZSKDATA = 9;
	const Sbecore::uint DPCHENGSESSWZSKDATA = 10;
	const Sbecore::uint DPCHENGWZSKACK = 11;
	const Sbecore::uint DPCHENGWZSKALERT = 12;
	const Sbecore::uint DPCHENGWZSKCONFIRM = 13;
	const Sbecore::uint DPCHENGWZSKFILDATA = 14;
	const Sbecore::uint DPCHENGWZSKFILDETAILDATA = 15;
	const Sbecore::uint DPCHENGWZSKFILHEADBARDATA = 16;
	const Sbecore::uint DPCHENGWZSKFILLISTDATA = 17;
	const Sbecore::uint DPCHENGWZSKFILRECDATA = 18;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWALIGN = 19;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWDATA = 20;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWLIVE = 21;
	const Sbecore::uint DPCHENGWZSKLIV3DVIEWDATA = 22;
	const Sbecore::uint DPCHENGWZSKLIV3DVIEWLIVE = 23;
	const Sbecore::uint DPCHENGWZSKLIVDATA = 24;
	const Sbecore::uint DPCHENGWZSKLIVHEADBARDATA = 25;
	const Sbecore::uint DPCHENGWZSKLIVSYSMONDATA = 26;
	const Sbecore::uint DPCHENGWZSKLIVSYSMONLIVE = 27;
	const Sbecore::uint DPCHENGWZSKLLVCAMERADATA = 28;
	const Sbecore::uint DPCHENGWZSKLLVCAMERALIVE = 29;
	const Sbecore::uint DPCHENGWZSKLLVDATA = 30;
	const Sbecore::uint DPCHENGWZSKLLVHEADBARDATA = 31;
	const Sbecore::uint DPCHENGWZSKLLVLASERDATA = 32;
	const Sbecore::uint DPCHENGWZSKLLVTERMDATA = 33;
	const Sbecore::uint DPCHENGWZSKLLVTTABLEDATA = 34;
	const Sbecore::uint DPCHENGWZSKNAVADMINDATA = 35;
	const Sbecore::uint DPCHENGWZSKNAVDATA = 36;
	const Sbecore::uint DPCHENGWZSKNAVGALERYDATA = 37;
	const Sbecore::uint DPCHENGWZSKNAVHEADBARDATA = 38;
	const Sbecore::uint DPCHENGWZSKNAVOPDATA = 39;
	const Sbecore::uint DPCHENGWZSKNAVPREDATA = 40;
	const Sbecore::uint DPCHENGWZSKOBJ1NSHOTDATA = 41;
	const Sbecore::uint DPCHENGWZSKOBJDATA = 42;
	const Sbecore::uint DPCHENGWZSKOBJDETAILDATA = 43;
	const Sbecore::uint DPCHENGWZSKOBJHEADBARDATA = 44;
	const Sbecore::uint DPCHENGWZSKOBJLISTDATA = 45;
	const Sbecore::uint DPCHENGWZSKOBJRECDATA = 46;
	const Sbecore::uint DPCHENGWZSKOBJREF1NFILEDATA = 47;
	const Sbecore::uint DPCHENGWZSKOGR1NOBJECTDATA = 48;
	const Sbecore::uint DPCHENGWZSKOGRDATA = 49;
	const Sbecore::uint DPCHENGWZSKOGRDETAILDATA = 50;
	const Sbecore::uint DPCHENGWZSKOGRHEADBARDATA = 51;
	const Sbecore::uint DPCHENGWZSKOGRLISTDATA = 52;
	const Sbecore::uint DPCHENGWZSKOGRRECDATA = 53;
	const Sbecore::uint DPCHENGWZSKOGRSUP1NOBJGROUPDATA = 54;
	const Sbecore::uint DPCHENGWZSKPRSADETAILDATA = 55;
	const Sbecore::uint DPCHENGWZSKPRSDATA = 56;
	const Sbecore::uint DPCHENGWZSKPRSDETAILDATA = 57;
	const Sbecore::uint DPCHENGWZSKPRSHEADBARDATA = 58;
	const Sbecore::uint DPCHENGWZSKPRSLISTDATA = 59;
	const Sbecore::uint DPCHENGWZSKPRSRECDATA = 60;
	const Sbecore::uint DPCHENGWZSKSCFCONNDATA = 61;
	const Sbecore::uint DPCHENGWZSKSCFDATA = 62;
	const Sbecore::uint DPCHENGWZSKSCFGEOMDATA = 63;
	const Sbecore::uint DPCHENGWZSKSCFHEADBARDATA = 64;
	const Sbecore::uint DPCHENGWZSKSES1NSHOTDATA = 65;
	const Sbecore::uint DPCHENGWZSKSESDATA = 66;
	const Sbecore::uint DPCHENGWZSKSESDETAILDATA = 67;
	const Sbecore::uint DPCHENGWZSKSESHEADBARDATA = 68;
	const Sbecore::uint DPCHENGWZSKSESLISTDATA = 69;
	const Sbecore::uint DPCHENGWZSKSESRECDATA = 70;
	const Sbecore::uint DPCHENGWZSKSHTAPARDATA = 71;
	const Sbecore::uint DPCHENGWZSKSHTDATA = 72;
	const Sbecore::uint DPCHENGWZSKSHTDETAILDATA = 73;
	const Sbecore::uint DPCHENGWZSKSHTHEADBARDATA = 74;
	const Sbecore::uint DPCHENGWZSKSHTLISTDATA = 75;
	const Sbecore::uint DPCHENGWZSKSHTRECDATA = 76;
	const Sbecore::uint DPCHENGWZSKSHTREF1NFILEDATA = 77;
	const Sbecore::uint DPCHENGWZSKSUSPEND = 78;
	const Sbecore::uint DPCHENGWZSKUSGAACCESSDATA = 79;
	const Sbecore::uint DPCHENGWZSKUSGDATA = 80;
	const Sbecore::uint DPCHENGWZSKUSGDETAILDATA = 81;
	const Sbecore::uint DPCHENGWZSKUSGHEADBARDATA = 82;
	const Sbecore::uint DPCHENGWZSKUSGLISTDATA = 83;
	const Sbecore::uint DPCHENGWZSKUSGMNUSERDATA = 84;
	const Sbecore::uint DPCHENGWZSKUSGRECDATA = 85;
	const Sbecore::uint DPCHENGWZSKUSR1NSESSIONDATA = 86;
	const Sbecore::uint DPCHENGWZSKUSRAACCESSDATA = 87;
	const Sbecore::uint DPCHENGWZSKUSRDATA = 88;
	const Sbecore::uint DPCHENGWZSKUSRDETAILDATA = 89;
	const Sbecore::uint DPCHENGWZSKUSRHEADBARDATA = 90;
	const Sbecore::uint DPCHENGWZSKUSRLISTDATA = 91;
	const Sbecore::uint DPCHENGWZSKUSRMNUSERGROUPDATA = 92;
	const Sbecore::uint DPCHENGWZSKUSRRECDATA = 93;
	const Sbecore::uint DPCHAPPDLGWZSKFILDOWNLOADDO = 94;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDATA = 95;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDO = 96;
	const Sbecore::uint DPCHAPPDLGWZSKOBJNEWDATA = 97;
	const Sbecore::uint DPCHAPPDLGWZSKOBJNEWDO = 98;
	const Sbecore::uint DPCHAPPDLGWZSKOGRNEWDATA = 99;
	const Sbecore::uint DPCHAPPDLGWZSKOGRNEWDO = 100;
	const Sbecore::uint DPCHAPPDLGWZSKSCFCAMERAMATDATA = 101;
	const Sbecore::uint DPCHAPPDLGWZSKSCFCAMERAMATDO = 102;
	const Sbecore::uint DPCHAPPDLGWZSKSCFLASERPOSDATA = 103;
	const Sbecore::uint DPCHAPPDLGWZSKSCFLASERPOSDO = 104;
	const Sbecore::uint DPCHAPPDLGWZSKSCFTTABLECOORDDATA = 105;
	const Sbecore::uint DPCHAPPDLGWZSKSCFTTABLECOORDDO = 106;
	const Sbecore::uint DPCHAPPROOTWZSKLOGIN = 107;
	const Sbecore::uint DPCHAPPWZSKALERT = 108;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDATA = 109;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDO = 110;
	const Sbecore::uint DPCHAPPWZSKFILDO = 111;
	const Sbecore::uint DPCHAPPWZSKFILLISTDATA = 112;
	const Sbecore::uint DPCHAPPWZSKFILLISTDO = 113;
	const Sbecore::uint DPCHAPPWZSKFILRECDO = 114;
	const Sbecore::uint DPCHAPPWZSKINIT = 115;
	const Sbecore::uint DPCHAPPWZSKLIV2DVIEWALIGN = 116;
	const Sbecore::uint DPCHAPPWZSKLIV2DVIEWDATA = 117;
	const Sbecore::uint DPCHAPPWZSKLIV2DVIEWDO = 118;
	const Sbecore::uint DPCHAPPWZSKLIV3DVIEWDATA = 119;
	const Sbecore::uint DPCHAPPWZSKLIV3DVIEWDO = 120;
	const Sbecore::uint DPCHAPPWZSKLIVDO = 121;
	const Sbecore::uint DPCHAPPWZSKLIVSYSMONDO = 122;
	const Sbecore::uint DPCHAPPWZSKLLVCAMERADATA = 123;
	const Sbecore::uint DPCHAPPWZSKLLVCAMERADO = 124;
	const Sbecore::uint DPCHAPPWZSKLLVDO = 125;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDATA = 126;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDO = 127;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDATA = 128;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDO = 129;
	const Sbecore::uint DPCHAPPWZSKLLVTTABLEDATA = 130;
	const Sbecore::uint DPCHAPPWZSKLLVTTABLEDO = 131;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDATA = 132;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDO = 133;
	const Sbecore::uint DPCHAPPWZSKNAVDO = 134;
	const Sbecore::uint DPCHAPPWZSKNAVGALERYDATA = 135;
	const Sbecore::uint DPCHAPPWZSKNAVGALERYDO = 136;
	const Sbecore::uint DPCHAPPWZSKNAVOPDO = 137;
	const Sbecore::uint DPCHAPPWZSKNAVPREDO = 138;
	const Sbecore::uint DPCHAPPWZSKOBJ1NSHOTDATA = 139;
	const Sbecore::uint DPCHAPPWZSKOBJ1NSHOTDO = 140;
	const Sbecore::uint DPCHAPPWZSKOBJDETAILDATA = 141;
	const Sbecore::uint DPCHAPPWZSKOBJDETAILDO = 142;
	const Sbecore::uint DPCHAPPWZSKOBJDO = 143;
	const Sbecore::uint DPCHAPPWZSKOBJLISTDATA = 144;
	const Sbecore::uint DPCHAPPWZSKOBJLISTDO = 145;
	const Sbecore::uint DPCHAPPWZSKOBJRECDO = 146;
	const Sbecore::uint DPCHAPPWZSKOBJREF1NFILEDATA = 147;
	const Sbecore::uint DPCHAPPWZSKOBJREF1NFILEDO = 148;
	const Sbecore::uint DPCHAPPWZSKOGR1NOBJECTDATA = 149;
	const Sbecore::uint DPCHAPPWZSKOGR1NOBJECTDO = 150;
	const Sbecore::uint DPCHAPPWZSKOGRDETAILDATA = 151;
	const Sbecore::uint DPCHAPPWZSKOGRDETAILDO = 152;
	const Sbecore::uint DPCHAPPWZSKOGRDO = 153;
	const Sbecore::uint DPCHAPPWZSKOGRLISTDATA = 154;
	const Sbecore::uint DPCHAPPWZSKOGRLISTDO = 155;
	const Sbecore::uint DPCHAPPWZSKOGRRECDO = 156;
	const Sbecore::uint DPCHAPPWZSKOGRSUP1NOBJGROUPDATA = 157;
	const Sbecore::uint DPCHAPPWZSKOGRSUP1NOBJGROUPDO = 158;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDATA = 159;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDO = 160;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDATA = 161;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDO = 162;
	const Sbecore::uint DPCHAPPWZSKPRSDO = 163;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDATA = 164;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDO = 165;
	const Sbecore::uint DPCHAPPWZSKPRSRECDO = 166;
	const Sbecore::uint DPCHAPPWZSKRESUME = 167;
	const Sbecore::uint DPCHAPPWZSKSCFCONNDO = 168;
	const Sbecore::uint DPCHAPPWZSKSCFDO = 169;
	const Sbecore::uint DPCHAPPWZSKSCFGEOMDO = 170;
	const Sbecore::uint DPCHAPPWZSKSES1NSHOTDATA = 171;
	const Sbecore::uint DPCHAPPWZSKSES1NSHOTDO = 172;
	const Sbecore::uint DPCHAPPWZSKSESDETAILDATA = 173;
	const Sbecore::uint DPCHAPPWZSKSESDETAILDO = 174;
	const Sbecore::uint DPCHAPPWZSKSESDO = 175;
	const Sbecore::uint DPCHAPPWZSKSESLISTDATA = 176;
	const Sbecore::uint DPCHAPPWZSKSESLISTDO = 177;
	const Sbecore::uint DPCHAPPWZSKSESRECDO = 178;
	const Sbecore::uint DPCHAPPWZSKSHTAPARDATA = 179;
	const Sbecore::uint DPCHAPPWZSKSHTAPARDO = 180;
	const Sbecore::uint DPCHAPPWZSKSHTDETAILDATA = 181;
	const Sbecore::uint DPCHAPPWZSKSHTDETAILDO = 182;
	const Sbecore::uint DPCHAPPWZSKSHTDO = 183;
	const Sbecore::uint DPCHAPPWZSKSHTLISTDATA = 184;
	const Sbecore::uint DPCHAPPWZSKSHTLISTDO = 185;
	const Sbecore::uint DPCHAPPWZSKSHTRECDO = 186;
	const Sbecore::uint DPCHAPPWZSKSHTREF1NFILEDATA = 187;
	const Sbecore::uint DPCHAPPWZSKSHTREF1NFILEDO = 188;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDATA = 189;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDO = 190;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDATA = 191;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDO = 192;
	const Sbecore::uint DPCHAPPWZSKUSGDO = 193;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDATA = 194;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDO = 195;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDATA = 196;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDO = 197;
	const Sbecore::uint DPCHAPPWZSKUSGRECDO = 198;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDATA = 199;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDO = 200;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDATA = 201;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDO = 202;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDATA = 203;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDO = 204;
	const Sbecore::uint DPCHAPPWZSKUSRDO = 205;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDATA = 206;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDO = 207;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDATA = 208;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDO = 209;
	const Sbecore::uint DPCHAPPWZSKUSRRECDO = 210;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
