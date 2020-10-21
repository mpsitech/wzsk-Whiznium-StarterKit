/**
	* \file VecWzskVCall.cpp
	* vector VecWzskVCall (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "VecWzskVCall.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVCall
 ******************************************************************************/

uint VecWzskVCall::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "callwzskaccess") return CALLWZSKACCESS;
	if (s == "callwzskboolvalpreset") return CALLWZSKBOOLVALPRESET;
	if (s == "callwzskcallback") return CALLWZSKCALLBACK;
	if (s == "callwzskclaimchg") return CALLWZSKCLAIMCHG;
	if (s == "callwzskcrdactive") return CALLWZSKCRDACTIVE;
	if (s == "callwzskcrdclose") return CALLWZSKCRDCLOSE;
	if (s == "callwzskcrdopen") return CALLWZSKCRDOPEN;
	if (s == "callwzskctlaparmod.usreq") return CALLWZSKCTLAPARMOD_USREQ;
	if (s == "callwzskdatchg") return CALLWZSKDATCHG;
	if (s == "callwzskdblvalpreset") return CALLWZSKDBLVALPRESET;
	if (s == "callwzskdlgclose") return CALLWZSKDLGCLOSE;
	if (s == "callwzskfil.clueq") return CALLWZSKFIL_CLUEQ;
	if (s == "callwzskfil.reteq") return CALLWZSKFIL_RETEQ;
	if (s == "callwzskfil.reueq") return CALLWZSKFIL_REUEQ;
	if (s == "callwzskfilmod") return CALLWZSKFILMOD;
	if (s == "callwzskfilmod.clueq") return CALLWZSKFILMOD_CLUEQ;
	if (s == "callwzskfilmod.retreueq") return CALLWZSKFILMOD_RETREUEQ;
	if (s == "callwzskfilupd.refeq") return CALLWZSKFILUPD_REFEQ;
	if (s == "callwzskhusrrunvmod.crdusreq") return CALLWZSKHUSRRUNVMOD_CRDUSREQ;
	if (s == "callwzskintvalpreset") return CALLWZSKINTVALPRESET;
	if (s == "callwzskixpreset") return CALLWZSKIXPRESET;
	if (s == "callwzskkakjkeymod.klsakeyeq") return CALLWZSKKAKJKEYMOD_KLSAKEYEQ;
	if (s == "callwzskklsakeymod.klseq") return CALLWZSKKLSAKEYMOD_KLSEQ;
	if (s == "callwzskklsakeymod.klsmtburfeq") return CALLWZSKKLSAKEYMOD_KLSMTBURFEQ;
	if (s == "callwzsklog") return CALLWZSKLOG;
	if (s == "callwzsklogout") return CALLWZSKLOGOUT;
	if (s == "callwzskmonstatchg") return CALLWZSKMONSTATCHG;
	if (s == "callwzsknodechg") return CALLWZSKNODECHG;
	if (s == "callwzskobj.ogreq") return CALLWZSKOBJ_OGREQ;
	if (s == "callwzskobjmod") return CALLWZSKOBJMOD;
	if (s == "callwzskobjmod.ogreq") return CALLWZSKOBJMOD_OGREQ;
	if (s == "callwzskobjupd.refeq") return CALLWZSKOBJUPD_REFEQ;
	if (s == "callwzskogr.supeq") return CALLWZSKOGR_SUPEQ;
	if (s == "callwzskogrjtitmod.ogreq") return CALLWZSKOGRJTITMOD_OGREQ;
	if (s == "callwzskogrmod") return CALLWZSKOGRMOD;
	if (s == "callwzskogrmod.supeq") return CALLWZSKOGRMOD_SUPEQ;
	if (s == "callwzskogrupd.refeq") return CALLWZSKOGRUPD_REFEQ;
	if (s == "callwzskprsadetmod.prseq") return CALLWZSKPRSADETMOD_PRSEQ;
	if (s == "callwzskprsjlnmmod.prseq") return CALLWZSKPRSJLNMMOD_PRSEQ;
	if (s == "callwzskprsmod") return CALLWZSKPRSMOD;
	if (s == "callwzskprsupd.refeq") return CALLWZSKPRSUPD_REFEQ;
	if (s == "callwzskrecaccess") return CALLWZSKRECACCESS;
	if (s == "callwzskrefpreset") return CALLWZSKREFPRESET;
	if (s == "callwzskrefspreset") return CALLWZSKREFSPRESET;
	if (s == "callwzskresultnew") return CALLWZSKRESULTNEW;
	if (s == "callwzskses.usreq") return CALLWZSKSES_USREQ;
	if (s == "callwzsksesmod") return CALLWZSKSESMOD;
	if (s == "callwzsksesmod.usreq") return CALLWZSKSESMOD_USREQ;
	if (s == "callwzsksesupd.refeq") return CALLWZSKSESUPD_REFEQ;
	if (s == "callwzsksgechg") return CALLWZSKSGECHG;
	if (s == "callwzskshrdatchg") return CALLWZSKSHRDATCHG;
	if (s == "callwzsksht.objeq") return CALLWZSKSHT_OBJEQ;
	if (s == "callwzsksht.seseq") return CALLWZSKSHT_SESEQ;
	if (s == "callwzskshtaparmod.shteq") return CALLWZSKSHTAPARMOD_SHTEQ;
	if (s == "callwzskshtmod") return CALLWZSKSHTMOD;
	if (s == "callwzskshtmod.objeq") return CALLWZSKSHTMOD_OBJEQ;
	if (s == "callwzskshtmod.seseq") return CALLWZSKSHTMOD_SESEQ;
	if (s == "callwzskshtupd.refeq") return CALLWZSKSHTUPD_REFEQ;
	if (s == "callwzsksrefpreset") return CALLWZSKSREFPRESET;
	if (s == "callwzskstatchg") return CALLWZSKSTATCHG;
	if (s == "callwzskstgchg") return CALLWZSKSTGCHG;
	if (s == "callwzskstubchg") return CALLWZSKSTUBCHG;
	if (s == "callwzsksuspsess") return CALLWZSKSUSPSESS;
	if (s == "callwzsktxtvalpreset") return CALLWZSKTXTVALPRESET;
	if (s == "callwzskusgaaccmod.usgeq") return CALLWZSKUSGAACCMOD_USGEQ;
	if (s == "callwzskusgmod") return CALLWZSKUSGMOD;
	if (s == "callwzskusgupd.refeq") return CALLWZSKUSGUPD_REFEQ;
	if (s == "callwzskusr.prseq") return CALLWZSKUSR_PRSEQ;
	if (s == "callwzskusr.usgeq") return CALLWZSKUSR_USGEQ;
	if (s == "callwzskusraaccmod.usreq") return CALLWZSKUSRAACCMOD_USREQ;
	if (s == "callwzskusrjstemod.usreq") return CALLWZSKUSRJSTEMOD_USREQ;
	if (s == "callwzskusrmod") return CALLWZSKUSRMOD;
	if (s == "callwzskusrrusgmod.usgeq") return CALLWZSKUSRRUSGMOD_USGEQ;
	if (s == "callwzskusrrusgmod.usreq") return CALLWZSKUSRRUSGMOD_USREQ;
	if (s == "callwzskusrupd.refeq") return CALLWZSKUSRUPD_REFEQ;
	if (s == "callwzskwaitsecond") return CALLWZSKWAITSECOND;

	return(0);
};

string VecWzskVCall::getSref(
			const uint ix
		) {
	if (ix == CALLWZSKACCESS) return("CallWzskAccess");
	if (ix == CALLWZSKBOOLVALPRESET) return("CallWzskBoolvalPreSet");
	if (ix == CALLWZSKCALLBACK) return("CallWzskCallback");
	if (ix == CALLWZSKCLAIMCHG) return("CallWzskClaimChg");
	if (ix == CALLWZSKCRDACTIVE) return("CallWzskCrdActive");
	if (ix == CALLWZSKCRDCLOSE) return("CallWzskCrdClose");
	if (ix == CALLWZSKCRDOPEN) return("CallWzskCrdOpen");
	if (ix == CALLWZSKCTLAPARMOD_USREQ) return("CallWzskCtlAparMod.usrEq");
	if (ix == CALLWZSKDATCHG) return("CallWzskDatChg");
	if (ix == CALLWZSKDBLVALPRESET) return("CallWzskDblvalPreSet");
	if (ix == CALLWZSKDLGCLOSE) return("CallWzskDlgClose");
	if (ix == CALLWZSKFIL_CLUEQ) return("CallWzskFil.cluEq");
	if (ix == CALLWZSKFIL_RETEQ) return("CallWzskFil.retEq");
	if (ix == CALLWZSKFIL_REUEQ) return("CallWzskFil.reuEq");
	if (ix == CALLWZSKFILMOD) return("CallWzskFilMod");
	if (ix == CALLWZSKFILMOD_CLUEQ) return("CallWzskFilMod.cluEq");
	if (ix == CALLWZSKFILMOD_RETREUEQ) return("CallWzskFilMod.retReuEq");
	if (ix == CALLWZSKFILUPD_REFEQ) return("CallWzskFilUpd.refEq");
	if (ix == CALLWZSKHUSRRUNVMOD_CRDUSREQ) return("CallWzskHusrRunvMod.crdUsrEq");
	if (ix == CALLWZSKINTVALPRESET) return("CallWzskIntvalPreSet");
	if (ix == CALLWZSKIXPRESET) return("CallWzskIxPreSet");
	if (ix == CALLWZSKKAKJKEYMOD_KLSAKEYEQ) return("CallWzskKakJkeyMod.klsAkeyEq");
	if (ix == CALLWZSKKLSAKEYMOD_KLSEQ) return("CallWzskKlsAkeyMod.klsEq");
	if (ix == CALLWZSKKLSAKEYMOD_KLSMTBURFEQ) return("CallWzskKlsAkeyMod.klsMtbUrfEq");
	if (ix == CALLWZSKLOG) return("CallWzskLog");
	if (ix == CALLWZSKLOGOUT) return("CallWzskLogout");
	if (ix == CALLWZSKMONSTATCHG) return("CallWzskMonstatChg");
	if (ix == CALLWZSKNODECHG) return("CallWzskNodeChg");
	if (ix == CALLWZSKOBJ_OGREQ) return("CallWzskObj.ogrEq");
	if (ix == CALLWZSKOBJMOD) return("CallWzskObjMod");
	if (ix == CALLWZSKOBJMOD_OGREQ) return("CallWzskObjMod.ogrEq");
	if (ix == CALLWZSKOBJUPD_REFEQ) return("CallWzskObjUpd.refEq");
	if (ix == CALLWZSKOGR_SUPEQ) return("CallWzskOgr.supEq");
	if (ix == CALLWZSKOGRJTITMOD_OGREQ) return("CallWzskOgrJtitMod.ogrEq");
	if (ix == CALLWZSKOGRMOD) return("CallWzskOgrMod");
	if (ix == CALLWZSKOGRMOD_SUPEQ) return("CallWzskOgrMod.supEq");
	if (ix == CALLWZSKOGRUPD_REFEQ) return("CallWzskOgrUpd.refEq");
	if (ix == CALLWZSKPRSADETMOD_PRSEQ) return("CallWzskPrsAdetMod.prsEq");
	if (ix == CALLWZSKPRSJLNMMOD_PRSEQ) return("CallWzskPrsJlnmMod.prsEq");
	if (ix == CALLWZSKPRSMOD) return("CallWzskPrsMod");
	if (ix == CALLWZSKPRSUPD_REFEQ) return("CallWzskPrsUpd.refEq");
	if (ix == CALLWZSKRECACCESS) return("CallWzskRecaccess");
	if (ix == CALLWZSKREFPRESET) return("CallWzskRefPreSet");
	if (ix == CALLWZSKREFSPRESET) return("CallWzskRefsPreSet");
	if (ix == CALLWZSKRESULTNEW) return("CallWzskResultNew");
	if (ix == CALLWZSKSES_USREQ) return("CallWzskSes.usrEq");
	if (ix == CALLWZSKSESMOD) return("CallWzskSesMod");
	if (ix == CALLWZSKSESMOD_USREQ) return("CallWzskSesMod.usrEq");
	if (ix == CALLWZSKSESUPD_REFEQ) return("CallWzskSesUpd.refEq");
	if (ix == CALLWZSKSGECHG) return("CallWzskSgeChg");
	if (ix == CALLWZSKSHRDATCHG) return("CallWzskShrdatChg");
	if (ix == CALLWZSKSHT_OBJEQ) return("CallWzskSht.objEq");
	if (ix == CALLWZSKSHT_SESEQ) return("CallWzskSht.sesEq");
	if (ix == CALLWZSKSHTAPARMOD_SHTEQ) return("CallWzskShtAparMod.shtEq");
	if (ix == CALLWZSKSHTMOD) return("CallWzskShtMod");
	if (ix == CALLWZSKSHTMOD_OBJEQ) return("CallWzskShtMod.objEq");
	if (ix == CALLWZSKSHTMOD_SESEQ) return("CallWzskShtMod.sesEq");
	if (ix == CALLWZSKSHTUPD_REFEQ) return("CallWzskShtUpd.refEq");
	if (ix == CALLWZSKSREFPRESET) return("CallWzskSrefPreSet");
	if (ix == CALLWZSKSTATCHG) return("CallWzskStatChg");
	if (ix == CALLWZSKSTGCHG) return("CallWzskStgChg");
	if (ix == CALLWZSKSTUBCHG) return("CallWzskStubChg");
	if (ix == CALLWZSKSUSPSESS) return("CallWzskSuspsess");
	if (ix == CALLWZSKTXTVALPRESET) return("CallWzskTxtvalPreSet");
	if (ix == CALLWZSKUSGAACCMOD_USGEQ) return("CallWzskUsgAaccMod.usgEq");
	if (ix == CALLWZSKUSGMOD) return("CallWzskUsgMod");
	if (ix == CALLWZSKUSGUPD_REFEQ) return("CallWzskUsgUpd.refEq");
	if (ix == CALLWZSKUSR_PRSEQ) return("CallWzskUsr.prsEq");
	if (ix == CALLWZSKUSR_USGEQ) return("CallWzskUsr.usgEq");
	if (ix == CALLWZSKUSRAACCMOD_USREQ) return("CallWzskUsrAaccMod.usrEq");
	if (ix == CALLWZSKUSRJSTEMOD_USREQ) return("CallWzskUsrJsteMod.usrEq");
	if (ix == CALLWZSKUSRMOD) return("CallWzskUsrMod");
	if (ix == CALLWZSKUSRRUSGMOD_USGEQ) return("CallWzskUsrRusgMod.usgEq");
	if (ix == CALLWZSKUSRRUSGMOD_USREQ) return("CallWzskUsrRusgMod.usrEq");
	if (ix == CALLWZSKUSRUPD_REFEQ) return("CallWzskUsrUpd.refEq");
	if (ix == CALLWZSKWAITSECOND) return("CallWzskWaitsecond");

	return("");
};

