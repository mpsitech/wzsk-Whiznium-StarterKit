/**
	* \file VecWzskVDpch.h
	* vector VecWzskVDpch (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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
	const Sbecore::uint DPCHAPPWZSKLIV3DVIEWDO = 26;
	const Sbecore::uint DPCHAPPWZSKLIVDO = 27;
	const Sbecore::uint DPCHAPPWZSKLLVCAMERADATA = 28;
	const Sbecore::uint DPCHAPPWZSKLLVCAMERADO = 29;
	const Sbecore::uint DPCHAPPWZSKLLVDO = 30;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDATA = 31;
	const Sbecore::uint DPCHAPPWZSKLLVLASERDO = 32;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDATA = 33;
	const Sbecore::uint DPCHAPPWZSKLLVTERMDO = 34;
	const Sbecore::uint DPCHAPPWZSKLLVTTABLEDATA = 35;
	const Sbecore::uint DPCHAPPWZSKLLVTTABLEDO = 36;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDATA = 37;
	const Sbecore::uint DPCHAPPWZSKNAVADMINDO = 38;
	const Sbecore::uint DPCHAPPWZSKNAVDO = 39;
	const Sbecore::uint DPCHAPPWZSKNAVGALERYDATA = 40;
	const Sbecore::uint DPCHAPPWZSKNAVGALERYDO = 41;
	const Sbecore::uint DPCHAPPWZSKNAVOPDO = 42;
	const Sbecore::uint DPCHAPPWZSKNAVPREDO = 43;
	const Sbecore::uint DPCHAPPWZSKOBJDETAILDATA = 44;
	const Sbecore::uint DPCHAPPWZSKOBJDETAILDO = 45;
	const Sbecore::uint DPCHAPPWZSKOBJDO = 46;
	const Sbecore::uint DPCHAPPWZSKOBJLISTDATA = 47;
	const Sbecore::uint DPCHAPPWZSKOBJLISTDO = 48;
	const Sbecore::uint DPCHAPPWZSKOBJRECDO = 49;
	const Sbecore::uint DPCHAPPWZSKOBJREF1NFILEDATA = 50;
	const Sbecore::uint DPCHAPPWZSKOBJREF1NFILEDO = 51;
	const Sbecore::uint DPCHAPPWZSKOGR1NOBJECTDATA = 52;
	const Sbecore::uint DPCHAPPWZSKOGR1NOBJECTDO = 53;
	const Sbecore::uint DPCHAPPWZSKOGR1NSHOTDATA = 54;
	const Sbecore::uint DPCHAPPWZSKOGR1NSHOTDO = 55;
	const Sbecore::uint DPCHAPPWZSKOGRDETAILDATA = 56;
	const Sbecore::uint DPCHAPPWZSKOGRDETAILDO = 57;
	const Sbecore::uint DPCHAPPWZSKOGRDO = 58;
	const Sbecore::uint DPCHAPPWZSKOGRLISTDATA = 59;
	const Sbecore::uint DPCHAPPWZSKOGRLISTDO = 60;
	const Sbecore::uint DPCHAPPWZSKOGRRECDO = 61;
	const Sbecore::uint DPCHAPPWZSKOGRSUP1NOBJGROUPDATA = 62;
	const Sbecore::uint DPCHAPPWZSKOGRSUP1NOBJGROUPDO = 63;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDATA = 64;
	const Sbecore::uint DPCHAPPWZSKPRSADETAILDO = 65;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDATA = 66;
	const Sbecore::uint DPCHAPPWZSKPRSDETAILDO = 67;
	const Sbecore::uint DPCHAPPWZSKPRSDO = 68;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDATA = 69;
	const Sbecore::uint DPCHAPPWZSKPRSLISTDO = 70;
	const Sbecore::uint DPCHAPPWZSKPRSRECDO = 71;
	const Sbecore::uint DPCHAPPWZSKRESUME = 72;
	const Sbecore::uint DPCHAPPWZSKSCFCONNDO = 73;
	const Sbecore::uint DPCHAPPWZSKSCFDO = 74;
	const Sbecore::uint DPCHAPPWZSKSCFGEOMDO = 75;
	const Sbecore::uint DPCHAPPWZSKSES1NSHOTDATA = 76;
	const Sbecore::uint DPCHAPPWZSKSES1NSHOTDO = 77;
	const Sbecore::uint DPCHAPPWZSKSESDETAILDATA = 78;
	const Sbecore::uint DPCHAPPWZSKSESDETAILDO = 79;
	const Sbecore::uint DPCHAPPWZSKSESDO = 80;
	const Sbecore::uint DPCHAPPWZSKSESLISTDATA = 81;
	const Sbecore::uint DPCHAPPWZSKSESLISTDO = 82;
	const Sbecore::uint DPCHAPPWZSKSESRECDO = 83;
	const Sbecore::uint DPCHAPPWZSKSHTAPARDATA = 84;
	const Sbecore::uint DPCHAPPWZSKSHTAPARDO = 85;
	const Sbecore::uint DPCHAPPWZSKSHTDETAILDATA = 86;
	const Sbecore::uint DPCHAPPWZSKSHTDETAILDO = 87;
	const Sbecore::uint DPCHAPPWZSKSHTDO = 88;
	const Sbecore::uint DPCHAPPWZSKSHTLISTDATA = 89;
	const Sbecore::uint DPCHAPPWZSKSHTLISTDO = 90;
	const Sbecore::uint DPCHAPPWZSKSHTRECDO = 91;
	const Sbecore::uint DPCHAPPWZSKSHTREF1NFILEDATA = 92;
	const Sbecore::uint DPCHAPPWZSKSHTREF1NFILEDO = 93;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDATA = 94;
	const Sbecore::uint DPCHAPPWZSKUSGAACCESSDO = 95;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDATA = 96;
	const Sbecore::uint DPCHAPPWZSKUSGDETAILDO = 97;
	const Sbecore::uint DPCHAPPWZSKUSGDO = 98;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDATA = 99;
	const Sbecore::uint DPCHAPPWZSKUSGLISTDO = 100;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDATA = 101;
	const Sbecore::uint DPCHAPPWZSKUSGMNUSERDO = 102;
	const Sbecore::uint DPCHAPPWZSKUSGRECDO = 103;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDATA = 104;
	const Sbecore::uint DPCHAPPWZSKUSR1NSESSIONDO = 105;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDATA = 106;
	const Sbecore::uint DPCHAPPWZSKUSRAACCESSDO = 107;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDATA = 108;
	const Sbecore::uint DPCHAPPWZSKUSRDETAILDO = 109;
	const Sbecore::uint DPCHAPPWZSKUSRDO = 110;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDATA = 111;
	const Sbecore::uint DPCHAPPWZSKUSRLISTDO = 112;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDATA = 113;
	const Sbecore::uint DPCHAPPWZSKUSRMNUSERGROUPDO = 114;
	const Sbecore::uint DPCHAPPWZSKUSRRECDO = 115;
	const Sbecore::uint DPCHENGDLGWZSKFILDOWNLOADDATA = 116;
	const Sbecore::uint DPCHENGDLGWZSKNAVLOAINIDATA = 117;
	const Sbecore::uint DPCHENGDLGWZSKOBJNEWDATA = 118;
	const Sbecore::uint DPCHENGDLGWZSKOGRNEWDATA = 119;
	const Sbecore::uint DPCHENGDLGWZSKSCFCAMERAMATDATA = 120;
	const Sbecore::uint DPCHENGDLGWZSKSCFLASERPOSDATA = 121;
	const Sbecore::uint DPCHENGDLGWZSKSCFTTABLECOORDDATA = 122;
	const Sbecore::uint DPCHENGM2MSESSWZSKDATA = 123;
	const Sbecore::uint DPCHENGROOTWZSKDATA = 124;
	const Sbecore::uint DPCHENGSESSWZSKDATA = 125;
	const Sbecore::uint DPCHENGWZSKACK = 126;
	const Sbecore::uint DPCHENGWZSKALERT = 127;
	const Sbecore::uint DPCHENGWZSKCONFIRM = 128;
	const Sbecore::uint DPCHENGWZSKFILDATA = 129;
	const Sbecore::uint DPCHENGWZSKFILDETAILDATA = 130;
	const Sbecore::uint DPCHENGWZSKFILHEADBARDATA = 131;
	const Sbecore::uint DPCHENGWZSKFILLISTDATA = 132;
	const Sbecore::uint DPCHENGWZSKFILRECDATA = 133;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWALIGN = 134;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWDATA = 135;
	const Sbecore::uint DPCHENGWZSKLIV2DVIEWLIVE = 136;
	const Sbecore::uint DPCHENGWZSKLIV3DVIEWDATA = 137;
	const Sbecore::uint DPCHENGWZSKLIV3DVIEWLIVE = 138;
	const Sbecore::uint DPCHENGWZSKLIVDATA = 139;
	const Sbecore::uint DPCHENGWZSKLIVHEADBARDATA = 140;
	const Sbecore::uint DPCHENGWZSKLLVCAMERADATA = 141;
	const Sbecore::uint DPCHENGWZSKLLVCAMERALIVE = 142;
	const Sbecore::uint DPCHENGWZSKLLVDATA = 143;
	const Sbecore::uint DPCHENGWZSKLLVHEADBARDATA = 144;
	const Sbecore::uint DPCHENGWZSKLLVLASERDATA = 145;
	const Sbecore::uint DPCHENGWZSKLLVTERMDATA = 146;
	const Sbecore::uint DPCHENGWZSKLLVTTABLEDATA = 147;
	const Sbecore::uint DPCHENGWZSKNAVADMINDATA = 148;
	const Sbecore::uint DPCHENGWZSKNAVDATA = 149;
	const Sbecore::uint DPCHENGWZSKNAVGALERYDATA = 150;
	const Sbecore::uint DPCHENGWZSKNAVHEADBARDATA = 151;
	const Sbecore::uint DPCHENGWZSKNAVOPDATA = 152;
	const Sbecore::uint DPCHENGWZSKNAVPREDATA = 153;
	const Sbecore::uint DPCHENGWZSKOBJDATA = 154;
	const Sbecore::uint DPCHENGWZSKOBJDETAILDATA = 155;
	const Sbecore::uint DPCHENGWZSKOBJHEADBARDATA = 156;
	const Sbecore::uint DPCHENGWZSKOBJLISTDATA = 157;
	const Sbecore::uint DPCHENGWZSKOBJRECDATA = 158;
	const Sbecore::uint DPCHENGWZSKOBJREF1NFILEDATA = 159;
	const Sbecore::uint DPCHENGWZSKOGR1NOBJECTDATA = 160;
	const Sbecore::uint DPCHENGWZSKOGR1NSHOTDATA = 161;
	const Sbecore::uint DPCHENGWZSKOGRDATA = 162;
	const Sbecore::uint DPCHENGWZSKOGRDETAILDATA = 163;
	const Sbecore::uint DPCHENGWZSKOGRHEADBARDATA = 164;
	const Sbecore::uint DPCHENGWZSKOGRLISTDATA = 165;
	const Sbecore::uint DPCHENGWZSKOGRRECDATA = 166;
	const Sbecore::uint DPCHENGWZSKOGRSUP1NOBJGROUPDATA = 167;
	const Sbecore::uint DPCHENGWZSKPRSADETAILDATA = 168;
	const Sbecore::uint DPCHENGWZSKPRSDATA = 169;
	const Sbecore::uint DPCHENGWZSKPRSDETAILDATA = 170;
	const Sbecore::uint DPCHENGWZSKPRSHEADBARDATA = 171;
	const Sbecore::uint DPCHENGWZSKPRSLISTDATA = 172;
	const Sbecore::uint DPCHENGWZSKPRSRECDATA = 173;
	const Sbecore::uint DPCHENGWZSKSCFCONNDATA = 174;
	const Sbecore::uint DPCHENGWZSKSCFDATA = 175;
	const Sbecore::uint DPCHENGWZSKSCFGEOMDATA = 176;
	const Sbecore::uint DPCHENGWZSKSCFHEADBARDATA = 177;
	const Sbecore::uint DPCHENGWZSKSES1NSHOTDATA = 178;
	const Sbecore::uint DPCHENGWZSKSESDATA = 179;
	const Sbecore::uint DPCHENGWZSKSESDETAILDATA = 180;
	const Sbecore::uint DPCHENGWZSKSESHEADBARDATA = 181;
	const Sbecore::uint DPCHENGWZSKSESLISTDATA = 182;
	const Sbecore::uint DPCHENGWZSKSESRECDATA = 183;
	const Sbecore::uint DPCHENGWZSKSHTAPARDATA = 184;
	const Sbecore::uint DPCHENGWZSKSHTDATA = 185;
	const Sbecore::uint DPCHENGWZSKSHTDETAILDATA = 186;
	const Sbecore::uint DPCHENGWZSKSHTHEADBARDATA = 187;
	const Sbecore::uint DPCHENGWZSKSHTLISTDATA = 188;
	const Sbecore::uint DPCHENGWZSKSHTRECDATA = 189;
	const Sbecore::uint DPCHENGWZSKSHTREF1NFILEDATA = 190;
	const Sbecore::uint DPCHENGWZSKSUSPEND = 191;
	const Sbecore::uint DPCHENGWZSKUSGAACCESSDATA = 192;
	const Sbecore::uint DPCHENGWZSKUSGDATA = 193;
	const Sbecore::uint DPCHENGWZSKUSGDETAILDATA = 194;
	const Sbecore::uint DPCHENGWZSKUSGHEADBARDATA = 195;
	const Sbecore::uint DPCHENGWZSKUSGLISTDATA = 196;
	const Sbecore::uint DPCHENGWZSKUSGMNUSERDATA = 197;
	const Sbecore::uint DPCHENGWZSKUSGRECDATA = 198;
	const Sbecore::uint DPCHENGWZSKUSR1NSESSIONDATA = 199;
	const Sbecore::uint DPCHENGWZSKUSRAACCESSDATA = 200;
	const Sbecore::uint DPCHENGWZSKUSRDATA = 201;
	const Sbecore::uint DPCHENGWZSKUSRDETAILDATA = 202;
	const Sbecore::uint DPCHENGWZSKUSRHEADBARDATA = 203;
	const Sbecore::uint DPCHENGWZSKUSRLISTDATA = 204;
	const Sbecore::uint DPCHENGWZSKUSRMNUSERGROUPDATA = 205;
	const Sbecore::uint DPCHENGWZSKUSRRECDATA = 206;
	const Sbecore::uint DPCHINVWZSK = 207;
	const Sbecore::uint DPCHRETWZSK = 208;
	const Sbecore::uint DPCHWZSKDACK = 209;
	const Sbecore::uint DPCHWZSKDQUIT = 210;
	const Sbecore::uint DPCHWZSKDREG = 211;
	const Sbecore::uint DPCHWZSKOPDREG = 212;
	const Sbecore::uint DPCHWZSKOPDUNREG = 213;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
