/**
	* \file VecWzskVCall.h
	* vector VecWzskVCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

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
	const Sbecore::uint CALLWZSKFILMOD = 13;
	const Sbecore::uint CALLWZSKFILMOD_CLUEQ = 14;
	const Sbecore::uint CALLWZSKFILMOD_RETREUEQ = 15;
	const Sbecore::uint CALLWZSKFILUPD_REFEQ = 16;
	const Sbecore::uint CALLWZSKHUSRRUNVMOD_CRDUSREQ = 17;
	const Sbecore::uint CALLWZSKINTVALPRESET = 18;
	const Sbecore::uint CALLWZSKIXPRESET = 19;
	const Sbecore::uint CALLWZSKKAKJKEYMOD_KLSAKEYEQ = 20;
	const Sbecore::uint CALLWZSKKLSAKEYMOD_KLSEQ = 21;
	const Sbecore::uint CALLWZSKKLSAKEYMOD_KLSMTBURFEQ = 22;
	const Sbecore::uint CALLWZSKLOG = 23;
	const Sbecore::uint CALLWZSKLOGOUT = 24;
	const Sbecore::uint CALLWZSKMONSTATCHG = 25;
	const Sbecore::uint CALLWZSKNODECHG = 26;
	const Sbecore::uint CALLWZSKPRSADETMOD_PRSEQ = 27;
	const Sbecore::uint CALLWZSKPRSJLNMMOD_PRSEQ = 28;
	const Sbecore::uint CALLWZSKPRSMOD = 29;
	const Sbecore::uint CALLWZSKPRSUPD_REFEQ = 30;
	const Sbecore::uint CALLWZSKRECACCESS = 31;
	const Sbecore::uint CALLWZSKREFPRESET = 32;
	const Sbecore::uint CALLWZSKREFSPRESET = 33;
	const Sbecore::uint CALLWZSKRESULTNEW = 34;
	const Sbecore::uint CALLWZSKSESMOD = 35;
	const Sbecore::uint CALLWZSKSESMOD_USREQ = 36;
	const Sbecore::uint CALLWZSKSESUPD_REFEQ = 37;
	const Sbecore::uint CALLWZSKSGECHG = 38;
	const Sbecore::uint CALLWZSKSHRDATCHG = 39;
	const Sbecore::uint CALLWZSKSREFPRESET = 40;
	const Sbecore::uint CALLWZSKSTATCHG = 41;
	const Sbecore::uint CALLWZSKSTGCHG = 42;
	const Sbecore::uint CALLWZSKSTUBCHG = 43;
	const Sbecore::uint CALLWZSKSUSPSESS = 44;
	const Sbecore::uint CALLWZSKTXTVALPRESET = 45;
	const Sbecore::uint CALLWZSKUSGAACCMOD_USGEQ = 46;
	const Sbecore::uint CALLWZSKUSGMOD = 47;
	const Sbecore::uint CALLWZSKUSGUPD_REFEQ = 48;
	const Sbecore::uint CALLWZSKUSR_PRSEQ = 49;
	const Sbecore::uint CALLWZSKUSR_USGEQ = 50;
	const Sbecore::uint CALLWZSKUSRAACCMOD_USREQ = 51;
	const Sbecore::uint CALLWZSKUSRJSTEMOD_USREQ = 52;
	const Sbecore::uint CALLWZSKUSRMOD = 53;
	const Sbecore::uint CALLWZSKUSRRUSGMOD_USGEQ = 54;
	const Sbecore::uint CALLWZSKUSRRUSGMOD_USREQ = 55;
	const Sbecore::uint CALLWZSKUSRUPD_REFEQ = 56;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
