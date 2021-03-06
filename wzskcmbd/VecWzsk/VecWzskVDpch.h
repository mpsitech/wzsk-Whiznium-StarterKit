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
	const Sbecore::uint DPCHAPPDLGWZSKFILDOWNLOADDO = 1;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDATA = 2;
	const Sbecore::uint DPCHAPPDLGWZSKNAVLOAINIDO = 3;
	const Sbecore::uint DPCHAPPDLGWZSKOBJNEWDATA = 4;
	const Sbecore::uint DPCHAPPDLGWZSKOBJNEWDO = 5;
	const Sbecore::uint DPCHAPPDLGWZSKOGRNEWDATA = 6;
	const Sbecore::uint DPCHAPPDLGWZSKOGRNEWDO = 7;
	const Sbecore::uint DPCHAPPDLGWZSKSCFCAMERAMATDATA = 8;
	const Sbecore::uint DPCHAPPDLGWZSKSCFCAMERAMATDO = 9;
	const Sbecore::uint DPCHAPPDLGWZSKSCFLASERPOSDATA = 10;
	const Sbecore::uint DPCHAPPDLGWZSKSCFLASERPOSDO = 11;
	const Sbecore::uint DPCHAPPDLGWZSKSCFTTABLECOORDDATA = 12;
	const Sbecore::uint DPCHAPPDLGWZSKSCFTTABLECOORDDO = 13;
	const Sbecore::uint DPCHAPPROOTWZSKLOGIN = 14;
	const Sbecore::uint DPCHAPPWZSKALERT = 15;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDATA = 16;
	const Sbecore::uint DPCHAPPWZSKFILDETAILDO = 17;
	const Sbecore::uint DPCHAPPWZSKFILDO = 18;
	const Sbecore::uint DPCHAPPWZSKFILLISTDATA = 19;
	const Sbecore::uint DPCHAPPWZSKFILLISTDO = 20;
	const Sbecore::uint DPCHAPPWZSKFILRECDO = 21;
	const Sbecore::uint DPCHAPPWZSKINIT = 22;
	const Sbecore::uint DPCHAPPWZSKLIV2DVIEWALIGN = 23;
	const Sbecore::uint DPCHAPPWZSKLIV2DVIEWDATA = 24;
	const Sbecore::uint DPCHAPPWZSKLIV2DVIEWDO = 25;
	const Sbecore::uint DPCHAPPWZSKLIV3DVIEWDATA = 26;
	const Sbecore::uint DPCHAPPWZSKLIV3DVIEWDO = 27;
	const Sbecore::uint DPCHAPPWZSKLIVDO = 28;
	const Sbecore::uint DPCHAPPWZSKLIVSYSMONDO = 29;
	const Sbecore::uint DPCHAPPWZSKLLVCAMERADATA = 30;
	const Sbecore::uint DPCHAPPWZSKLLVCAMERADO = 31;
	const Sbecore::uint DPCHAPPWZSKLLVDO = 32;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDATA = 33;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDO = 34;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDATA = 35;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDO = 36;
	const Sbecore::uint DPCHAPPWZSKLLVTTABLEDATA = 37;
	const Sbecore::uint DPCHAPPWZSKLLVTTABLEDO = 38;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDATA = 39;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDO = 40;
	const Sbecore::uint DPCHAPPWZSKNAVDO = 41;
	const Sbecore::uint DPCHAPPWZSKNAVGLRYDATA = 42;
	const Sbecore::uint DPCHAPPWZSKNAVGLRYDO = 43;
	const Sbecore::uint DPCHAPPWZSKNAVOPDO = 44;
	const Sbecore::uint DPCHAPPWZSKNAVPREDO = 45;
	const Sbecore::uint DPCHAPPWZSKOBJ1NSHOTDATA = 46;
	const Sbecore::uint DPCHAPPWZSKOBJ1NSHOTDO = 47;
	const Sbecore::uint DPCHAPPWZSKOBJDETAILDATA = 48;
	const Sbecore::uint DPCHAPPWZSKOBJDETAILDO = 49;
	const Sbecore::uint DPCHAPPWZSKOBJDO = 50;
	const Sbecore::uint DPCHAPPWZSKOBJLISTDATA = 51;
	const Sbecore::uint DPCHAPPWZSKOBJLISTDO = 52;
	const Sbecore::uint DPCHAPPWZSKOBJRECDO = 53;
	const Sbecore::uint DPCHAPPWZSKOBJREF1NFILEDATA = 54;
	const Sbecore::uint DPCHAPPWZSKOBJREF1NFILEDO = 55;
	const Sbecore::uint DPCHAPPWZSKOGR1NOBJECTDATA = 56;
	const Sbecore::uint DPCHAPPWZSKOGR1NOBJECTDO = 57;
	const Sbecore::uint DPCHAPPWZSKOGRDETAILDATA = 58;
	const Sbecore::uint DPCHAPPWZSKOGRDETAILDO = 59;
	const Sbecore::uint DPCHAPPWZSKOGRDO = 60;
	const Sbecore::uint DPCHAPPWZSKOGRLISTDATA = 61;
	const Sbecore::uint DPCHAPPWZSKOGRLISTDO = 62;
	const Sbecore::uint DPCHAPPWZSKOGRRECDO = 63;
	const Sbecore::uint DPCHAPPWZSKOGRSUP1NOBJGROUPDATA = 64;
	const Sbecore::uint DPCHAPPWZSKOGRSUP1NOBJGROUPDO = 65;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDATA = 66;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDO = 67;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDATA = 68;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDO = 69;
	const Sbecore::uint DPCHAPPWZSKPRSDO = 70;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDATA = 71;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDO = 72;
	const Sbecore::uint DPCHAPPWZSKPRSRECDO = 73;
	const Sbecore::uint DPCHAPPWZSKRESUME = 74;
	const Sbecore::uint DPCHAPPWZSKSCFCONNDO = 75;
	const Sbecore::uint DPCHAPPWZSKSCFDO = 76;
	const Sbecore::uint DPCHAPPWZSKSCFGEOMDO = 77;
	const Sbecore::uint DPCHAPPWZSKSES1NSHOTDATA = 78;
	const Sbecore::uint DPCHAPPWZSKSES1NSHOTDO = 79;
	const Sbecore::uint DPCHAPPWZSKSESDETAILDATA = 80;
	const Sbecore::uint DPCHAPPWZSKSESDETAILDO = 81;
	const Sbecore::uint DPCHAPPWZSKSESDO = 82;
	const Sbecore::uint DPCHAPPWZSKSESLISTDATA = 83;
	const Sbecore::uint DPCHAPPWZSKSESLISTDO = 84;
	const Sbecore::uint DPCHAPPWZSKSESRECDO = 85;
	const Sbecore::uint DPCHAPPWZSKSHTAPARDATA = 86;
	const Sbecore::uint DPCHAPPWZSKSHTAPARDO = 87;
	const Sbecore::uint DPCHAPPWZSKSHTDETAILDATA = 88;
	const Sbecore::uint DPCHAPPWZSKSHTDETAILDO = 89;
	const Sbecore::uint DPCHAPPWZSKSHTDO = 90;
	const Sbecore::uint DPCHAPPWZSKSHTLISTDATA = 91;
	const Sbecore::uint DPCHAPPWZSKSHTLISTDO = 92;
	const Sbecore::uint DPCHAPPWZSKSHTRECDO = 93;
	const Sbecore::uint DPCHAPPWZSKSHTREF1NFILEDATA = 94;
	const Sbecore::uint DPCHAPPWZSKSHTREF1NFILEDO = 95;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDATA = 96;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDO = 97;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDATA = 98;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDO = 99;
	const Sbecore::uint DPCHAPPWZSKUSGDO = 100;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDATA = 101;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDO = 102;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDATA = 103;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDO = 104;
	const Sbecore::uint DPCHAPPWZSKUSGRECDO = 105;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDATA = 106;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDO = 107;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDATA = 108;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDO = 109;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDATA = 110;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDO = 111;
	const Sbecore::uint DPCHAPPWZSKUSRDO = 112;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDATA = 113;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDO = 114;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDATA = 115;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDO = 116;
	const Sbecore::uint DPCHAPPWZSKUSRRECDO = 117;
	const Sbecore::uint DPCHENGDLGWZSKFILDOWNLOADDATA = 118;
	const Sbecore::uint DPCHENGDLGWZSKNAVLOAINIDATA = 119;
	const Sbecore::uint DPCHENGDLGWZSKOBJNEWDATA = 120;
	const Sbecore::uint DPCHENGDLGWZSKOGRNEWDATA = 121;
	const Sbecore::uint DPCHENGDLGWZSKSCFCAMERAMATDATA = 122;
	const Sbecore::uint DPCHENGDLGWZSKSCFLASERPOSDATA = 123;
	const Sbecore::uint DPCHENGDLGWZSKSCFTTABLECOORDDATA = 124;
	const Sbecore::uint DPCHENGM2MSESSWZSKDATA = 125;
	const Sbecore::uint DPCHENGROOTWZSKDATA = 126;
	const Sbecore::uint DPCHENGSESSWZSKDATA = 127;
	const Sbecore::uint DPCHENGWZSKACK = 128;
	const Sbecore::uint DPCHENGWZSKALERT = 129;
	const Sbecore::uint DPCHENGWZSKCONFIRM = 130;
	const Sbecore::uint DPCHENGWZSKFILDATA = 131;
	const Sbecore::uint DPCHENGWZSKFILDETAILDATA = 132;
	const Sbecore::uint DPCHENGWZSKFILHEADBARDATA = 133;
	const Sbecore::uint DPCHENGWZSKFILLISTDATA = 134;
	const Sbecore::uint DPCHENGWZSKFILRECDATA = 135;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWALIGN = 136;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWDATA = 137;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWLIVE = 138;
	const Sbecore::uint DPCHENGWZSKLIV3DVIEWDATA = 139;
	const Sbecore::uint DPCHENGWZSKLIV3DVIEWLIVE = 140;
	const Sbecore::uint DPCHENGWZSKLIVDATA = 141;
	const Sbecore::uint DPCHENGWZSKLIVHEADBARDATA = 142;
	const Sbecore::uint DPCHENGWZSKLIVSYSMONDATA = 143;
	const Sbecore::uint DPCHENGWZSKLIVSYSMONLIVE = 144;
	const Sbecore::uint DPCHENGWZSKLLVCAMERADATA = 145;
	const Sbecore::uint DPCHENGWZSKLLVCAMERALIVE = 146;
	const Sbecore::uint DPCHENGWZSKLLVDATA = 147;
	const Sbecore::uint DPCHENGWZSKLLVHEADBARDATA = 148;
	const Sbecore::uint DPCHENGWZSKLLVLASERDATA = 149;
	const Sbecore::uint DPCHENGWZSKLLVTERMDATA = 150;
	const Sbecore::uint DPCHENGWZSKLLVTTABLEDATA = 151;
	const Sbecore::uint DPCHENGWZSKNAVADMINDATA = 152;
	const Sbecore::uint DPCHENGWZSKNAVDATA = 153;
	const Sbecore::uint DPCHENGWZSKNAVGLRYDATA = 154;
	const Sbecore::uint DPCHENGWZSKNAVHEADBARDATA = 155;
	const Sbecore::uint DPCHENGWZSKNAVOPDATA = 156;
	const Sbecore::uint DPCHENGWZSKNAVPREDATA = 157;
	const Sbecore::uint DPCHENGWZSKOBJ1NSHOTDATA = 158;
	const Sbecore::uint DPCHENGWZSKOBJDATA = 159;
	const Sbecore::uint DPCHENGWZSKOBJDETAILDATA = 160;
	const Sbecore::uint DPCHENGWZSKOBJHEADBARDATA = 161;
	const Sbecore::uint DPCHENGWZSKOBJLISTDATA = 162;
	const Sbecore::uint DPCHENGWZSKOBJRECDATA = 163;
	const Sbecore::uint DPCHENGWZSKOBJREF1NFILEDATA = 164;
	const Sbecore::uint DPCHENGWZSKOGR1NOBJECTDATA = 165;
	const Sbecore::uint DPCHENGWZSKOGRDATA = 166;
	const Sbecore::uint DPCHENGWZSKOGRDETAILDATA = 167;
	const Sbecore::uint DPCHENGWZSKOGRHEADBARDATA = 168;
	const Sbecore::uint DPCHENGWZSKOGRLISTDATA = 169;
	const Sbecore::uint DPCHENGWZSKOGRRECDATA = 170;
	const Sbecore::uint DPCHENGWZSKOGRSUP1NOBJGROUPDATA = 171;
	const Sbecore::uint DPCHENGWZSKPRSADETAILDATA = 172;
	const Sbecore::uint DPCHENGWZSKPRSDATA = 173;
	const Sbecore::uint DPCHENGWZSKPRSDETAILDATA = 174;
	const Sbecore::uint DPCHENGWZSKPRSHEADBARDATA = 175;
	const Sbecore::uint DPCHENGWZSKPRSLISTDATA = 176;
	const Sbecore::uint DPCHENGWZSKPRSRECDATA = 177;
	const Sbecore::uint DPCHENGWZSKSCFCONNDATA = 178;
	const Sbecore::uint DPCHENGWZSKSCFDATA = 179;
	const Sbecore::uint DPCHENGWZSKSCFGEOMDATA = 180;
	const Sbecore::uint DPCHENGWZSKSCFHEADBARDATA = 181;
	const Sbecore::uint DPCHENGWZSKSES1NSHOTDATA = 182;
	const Sbecore::uint DPCHENGWZSKSESDATA = 183;
	const Sbecore::uint DPCHENGWZSKSESDETAILDATA = 184;
	const Sbecore::uint DPCHENGWZSKSESHEADBARDATA = 185;
	const Sbecore::uint DPCHENGWZSKSESLISTDATA = 186;
	const Sbecore::uint DPCHENGWZSKSESRECDATA = 187;
	const Sbecore::uint DPCHENGWZSKSHTAPARDATA = 188;
	const Sbecore::uint DPCHENGWZSKSHTDATA = 189;
	const Sbecore::uint DPCHENGWZSKSHTDETAILDATA = 190;
	const Sbecore::uint DPCHENGWZSKSHTHEADBARDATA = 191;
	const Sbecore::uint DPCHENGWZSKSHTLISTDATA = 192;
	const Sbecore::uint DPCHENGWZSKSHTRECDATA = 193;
	const Sbecore::uint DPCHENGWZSKSHTREF1NFILEDATA = 194;
	const Sbecore::uint DPCHENGWZSKSUSPEND = 195;
	const Sbecore::uint DPCHENGWZSKUSGAACCESSDATA = 196;
	const Sbecore::uint DPCHENGWZSKUSGDATA = 197;
	const Sbecore::uint DPCHENGWZSKUSGDETAILDATA = 198;
	const Sbecore::uint DPCHENGWZSKUSGHEADBARDATA = 199;
	const Sbecore::uint DPCHENGWZSKUSGLISTDATA = 200;
	const Sbecore::uint DPCHENGWZSKUSGMNUSERDATA = 201;
	const Sbecore::uint DPCHENGWZSKUSGRECDATA = 202;
	const Sbecore::uint DPCHENGWZSKUSR1NSESSIONDATA = 203;
	const Sbecore::uint DPCHENGWZSKUSRAACCESSDATA = 204;
	const Sbecore::uint DPCHENGWZSKUSRDATA = 205;
	const Sbecore::uint DPCHENGWZSKUSRDETAILDATA = 206;
	const Sbecore::uint DPCHENGWZSKUSRHEADBARDATA = 207;
	const Sbecore::uint DPCHENGWZSKUSRLISTDATA = 208;
	const Sbecore::uint DPCHENGWZSKUSRMNUSERGROUPDATA = 209;
	const Sbecore::uint DPCHENGWZSKUSRRECDATA = 210;
	const Sbecore::uint DPCHINVWZSK = 211;
	const Sbecore::uint DPCHRETWZSK = 212;
	const Sbecore::uint DPCHWZSKDACK = 213;
	const Sbecore::uint DPCHWZSKDQUIT = 214;
	const Sbecore::uint DPCHWZSKDREG = 215;
	const Sbecore::uint DPCHWZSKOPDREG = 216;
	const Sbecore::uint DPCHWZSKOPDUNREG = 217;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
