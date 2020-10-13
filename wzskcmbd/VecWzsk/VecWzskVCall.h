/**
	* \file VecWzskVCall.h
	* vector VecWzskVCall (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef VECWZSKVCALL_H
#define VECWZSKVCALL_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVCall
	*/
namespace VecWzskVCall {
	const Sbecore::uint CALLWZSKACCESS = 1;
	const Sbecore::uint CALLWZSKBOOLVALPRESET = 2;
	const Sbecore::uint CALLWZSKCALLBACK = 3;
	const Sbecore::uint CALLWZSKCLAIMCHG = 4;
	const Sbecore::uint CALLWZSKCRDACTIVE = 5;
	const Sbecore::uint CALLWZSKCRDCLOSE = 6;
	const Sbecore::uint CALLWZSKCRDOPEN = 7;
	const Sbecore::uint CALLWZSKCTLAPARMOD_USREQ = 8;
	const Sbecore::uint CALLWZSKDATCHG = 9;
	const Sbecore::uint CALLWZSKDBLVALPRESET = 10;
	const Sbecore::uint CALLWZSKDLGCLOSE = 11;
	const Sbecore::uint CALLWZSKFIL_CLUEQ = 12;
	const Sbecore::uint CALLWZSKFIL_RETEQ = 13;
	const Sbecore::uint CALLWZSKFIL_REUEQ = 14;
	const Sbecore::uint CALLWZSKFILMOD = 15;
	const Sbecore::uint CALLWZSKFILMOD_CLUEQ = 16;
	const Sbecore::uint CALLWZSKFILMOD_RETREUEQ = 17;
	const Sbecore::uint CALLWZSKFILUPD_REFEQ = 18;
	const Sbecore::uint CALLWZSKHUSRRUNVMOD_CRDUSREQ = 19;
	const Sbecore::uint CALLWZSKINTVALPRESET = 20;
	const Sbecore::uint CALLWZSKIXPRESET = 21;
	const Sbecore::uint CALLWZSKKAKJKEYMOD_KLSAKEYEQ = 22;
	const Sbecore::uint CALLWZSKKLSAKEYMOD_KLSEQ = 23;
	const Sbecore::uint CALLWZSKKLSAKEYMOD_KLSMTBURFEQ = 24;
	const Sbecore::uint CALLWZSKLOG = 25;
	const Sbecore::uint CALLWZSKLOGOUT = 26;
	const Sbecore::uint CALLWZSKMONSTATCHG = 27;
	const Sbecore::uint CALLWZSKNODECHG = 28;
	const Sbecore::uint CALLWZSKOBJ_OGREQ = 29;
	const Sbecore::uint CALLWZSKOBJMOD = 30;
	const Sbecore::uint CALLWZSKOBJMOD_OGREQ = 31;
	const Sbecore::uint CALLWZSKOBJUPD_REFEQ = 32;
	const Sbecore::uint CALLWZSKOGR_SUPEQ = 33;
	const Sbecore::uint CALLWZSKOGRJTITMOD_OGREQ = 34;
	const Sbecore::uint CALLWZSKOGRMOD = 35;
	const Sbecore::uint CALLWZSKOGRMOD_SUPEQ = 36;
	const Sbecore::uint CALLWZSKOGRUPD_REFEQ = 37;
	const Sbecore::uint CALLWZSKPRSADETMOD_PRSEQ = 38;
	const Sbecore::uint CALLWZSKPRSJLNMMOD_PRSEQ = 39;
	const Sbecore::uint CALLWZSKPRSMOD = 40;
	const Sbecore::uint CALLWZSKPRSUPD_REFEQ = 41;
	const Sbecore::uint CALLWZSKRECACCESS = 42;
	const Sbecore::uint CALLWZSKREFPRESET = 43;
	const Sbecore::uint CALLWZSKREFSPRESET = 44;
	const Sbecore::uint CALLWZSKRESULTNEW = 45;
	const Sbecore::uint CALLWZSKSES_USREQ = 46;
	const Sbecore::uint CALLWZSKSESMOD = 47;
	const Sbecore::uint CALLWZSKSESMOD_USREQ = 48;
	const Sbecore::uint CALLWZSKSESUPD_REFEQ = 49;
	const Sbecore::uint CALLWZSKSGECHG = 50;
	const Sbecore::uint CALLWZSKSHRDATCHG = 51;
	const Sbecore::uint CALLWZSKSHT_OBJEQ = 52;
	const Sbecore::uint CALLWZSKSHT_SESEQ = 53;
	const Sbecore::uint CALLWZSKSHTAPARMOD_SHTEQ = 54;
	const Sbecore::uint CALLWZSKSHTMOD = 55;
	const Sbecore::uint CALLWZSKSHTMOD_OBJEQ = 56;
	const Sbecore::uint CALLWZSKSHTMOD_SESEQ = 57;
	const Sbecore::uint CALLWZSKSHTUPD_REFEQ = 58;
	const Sbecore::uint CALLWZSKSREFPRESET = 59;
	const Sbecore::uint CALLWZSKSTATCHG = 60;
	const Sbecore::uint CALLWZSKSTGCHG = 61;
	const Sbecore::uint CALLWZSKSTUBCHG = 62;
	const Sbecore::uint CALLWZSKSUSPSESS = 63;
	const Sbecore::uint CALLWZSKTXTVALPRESET = 64;
	const Sbecore::uint CALLWZSKUSGAACCMOD_USGEQ = 65;
	const Sbecore::uint CALLWZSKUSGMOD = 66;
	const Sbecore::uint CALLWZSKUSGUPD_REFEQ = 67;
	const Sbecore::uint CALLWZSKUSR_PRSEQ = 68;
	const Sbecore::uint CALLWZSKUSR_USGEQ = 69;
	const Sbecore::uint CALLWZSKUSRAACCMOD_USREQ = 70;
	const Sbecore::uint CALLWZSKUSRJSTEMOD_USREQ = 71;
	const Sbecore::uint CALLWZSKUSRMOD = 72;
	const Sbecore::uint CALLWZSKUSRRUSGMOD_USGEQ = 73;
	const Sbecore::uint CALLWZSKUSRRUSGMOD_USREQ = 74;
	const Sbecore::uint CALLWZSKUSRUPD_REFEQ = 75;
	const Sbecore::uint CALLWZSKWAITSECOND = 76;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

