/**
	* \file CrdWzskNav.cpp
	* API code for job CrdWzskNav (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "CrdWzskNav.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskNav::VecVDo
 ******************************************************************************/

uint CrdWzskNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitsesspsclick") return MITSESSPSCLICK;
	if (s == "mitsestrmclick") return MITSESTRMCLICK;
	if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	if (s == "mitcrdprfclick") return MITCRDPRFCLICK;
	if (s == "mitcrdllvclick") return MITCRDLLVCLICK;
	if (s == "mitcrdvtrclick") return MITCRDVTRCLICK;
	if (s == "mitcrdhwcclick") return MITCRDHWCCLICK;
	if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	if (s == "mitapploiclick") return MITAPPLOICLICK;

	return(0);
};

string CrdWzskNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
	if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	if (ix == MITCRDPRFCLICK) return("MitCrdPrfClick");
	if (ix == MITCRDLLVCLICK) return("MitCrdLlvClick");
	if (ix == MITCRDVTRCLICK) return("MitCrdVtrClick");
	if (ix == MITCRDHWCCLICK) return("MitCrdHwcClick");
	if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdWzskNav::VecVSge
 ******************************************************************************/

uint CrdWzskNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;
	if (s == "alrwzsktrm") return ALRWZSKTRM;

	return(0);
};

string CrdWzskNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");
	if (ix == ALRWZSKTRM) return("alrwzsktrm");

	return("");
};

/******************************************************************************
 class CrdWzskNav::ContInf
 ******************************************************************************/

CrdWzskNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxSesSes1(MtxSesSes1)
			, MtxSesSes2(MtxSesSes2)
			, MtxSesSes3(MtxSesSes3)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

bool CrdWzskNav::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskNav";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", MtxSesSes1)) add(MTXSESSES1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", MtxSesSes2)) add(MTXSESSES2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", MtxSesSes3)) add(MTXSESSES3);
	};

	return basefound;
};

set<uint> CrdWzskNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdWzskNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskNav::StatApp
 ******************************************************************************/

CrdWzskNav::StatApp::StatApp(
			const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneAdmin
			, const bool initdoneOp
		) :
			Block()
			, ixWzskVReqitmode(ixWzskVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneHeadbar(initdoneHeadbar)
			, initdoneAdmin(initdoneAdmin)
			, initdoneOp(initdoneOp)
		{
	mask = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEADMIN, INITDONEOP};
};

bool CrdWzskNav::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", srefIxWzskVReqitmode)) {
			ixWzskVReqitmode = VecWzskVReqitmode::getIx(srefIxWzskVReqitmode);
			add(IXWZSKVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAdmin", initdoneAdmin)) add(INITDONEADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneOp", initdoneOp)) add(INITDONEOP);
	};

	return basefound;
};

set<uint> CrdWzskNav::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVReqitmode == comp->ixWzskVReqitmode) insert(items, IXWZSKVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneAdmin == comp->initdoneAdmin) insert(items, INITDONEADMIN);
	if (initdoneOp == comp->initdoneOp) insert(items, INITDONEOP);

	return(items);
};

set<uint> CrdWzskNav::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEADMIN, INITDONEOP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskNav::StatShr
 ******************************************************************************/

CrdWzskNav::StatShr::StatShr(
			const string& scrJrefDlgloaini
			, const string& scrJrefHeadbar
			, const string& scrJrefAdmin
			, const bool pnladminAvail
			, const string& scrJrefOp
			, const bool pnlopAvail
			, const bool MitSesSpsAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdPrfAvail
			, const bool MspCrd2Avail
			, const bool MitCrdLlvAvail
			, const bool MitCrdVtrAvail
			, const bool MitCrdHwcAvail
			, const bool MitCrdFilAvail
			, const bool MspApp2Avail
			, const bool MitAppLoiAvail
		) :
			Block()
			, scrJrefDlgloaini(scrJrefDlgloaini)
			, scrJrefHeadbar(scrJrefHeadbar)
			, scrJrefAdmin(scrJrefAdmin)
			, pnladminAvail(pnladminAvail)
			, scrJrefOp(scrJrefOp)
			, pnlopAvail(pnlopAvail)
			, MitSesSpsAvail(MitSesSpsAvail)
			, MspCrd1Avail(MspCrd1Avail)
			, MitCrdUsgAvail(MitCrdUsgAvail)
			, MitCrdUsrAvail(MitCrdUsrAvail)
			, MitCrdPrsAvail(MitCrdPrsAvail)
			, MitCrdPrfAvail(MitCrdPrfAvail)
			, MspCrd2Avail(MspCrd2Avail)
			, MitCrdLlvAvail(MitCrdLlvAvail)
			, MitCrdVtrAvail(MitCrdVtrAvail)
			, MitCrdHwcAvail(MitCrdHwcAvail)
			, MitCrdFilAvail(MitCrdFilAvail)
			, MspApp2Avail(MspApp2Avail)
			, MitAppLoiAvail(MitAppLoiAvail)
		{
	mask = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFOP, PNLOPAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDPRFAVAIL, MSPCRD2AVAIL, MITCRDLLVAVAIL, MITCRDVTRAVAIL, MITCRDHWCAVAIL, MITCRDFILAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

bool CrdWzskNav::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", scrJrefDlgloaini)) add(SCRJREFDLGLOAINI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", scrJrefAdmin)) add(SCRJREFADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnladminAvail", pnladminAvail)) add(PNLADMINAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefOp", scrJrefOp)) add(SCRJREFOP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlopAvail", pnlopAvail)) add(PNLOPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitSesSpsAvail", MitSesSpsAvail)) add(MITSESSPSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", MitCrdUsgAvail)) add(MITCRDUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", MitCrdUsrAvail)) add(MITCRDUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", MitCrdPrsAvail)) add(MITCRDPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrfAvail", MitCrdPrfAvail)) add(MITCRDPRFAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", MspCrd2Avail)) add(MSPCRD2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdLlvAvail", MitCrdLlvAvail)) add(MITCRDLLVAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVtrAvail", MitCrdVtrAvail)) add(MITCRDVTRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdHwcAvail", MitCrdHwcAvail)) add(MITCRDHWCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", MitCrdFilAvail)) add(MITCRDFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspApp2Avail", MspApp2Avail)) add(MSPAPP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", MitAppLoiAvail)) add(MITAPPLOIAVAIL);
	};

	return basefound;
};

set<uint> CrdWzskNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgloaini == comp->scrJrefDlgloaini) insert(items, SCRJREFDLGLOAINI);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefAdmin == comp->scrJrefAdmin) insert(items, SCRJREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (scrJrefOp == comp->scrJrefOp) insert(items, SCRJREFOP);
	if (pnlopAvail == comp->pnlopAvail) insert(items, PNLOPAVAIL);
	if (MitSesSpsAvail == comp->MitSesSpsAvail) insert(items, MITSESSPSAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdPrfAvail == comp->MitCrdPrfAvail) insert(items, MITCRDPRFAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdLlvAvail == comp->MitCrdLlvAvail) insert(items, MITCRDLLVAVAIL);
	if (MitCrdVtrAvail == comp->MitCrdVtrAvail) insert(items, MITCRDVTRAVAIL);
	if (MitCrdHwcAvail == comp->MitCrdHwcAvail) insert(items, MITCRDHWCAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdWzskNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFOP, PNLOPAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDPRFAVAIL, MSPCRD2AVAIL, MITCRDLLVAVAIL, MITCRDVTRAVAIL, MITCRDHWCAVAIL, MITCRDFILAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskNav::Tag
 ******************************************************************************/

CrdWzskNav::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitSesSps
			, const string& MitSesTrm
			, const string& MitCrdUsg
			, const string& MitCrdUsr
			, const string& MitCrdPrs
			, const string& MitCrdPrf
			, const string& MitCrdLlv
			, const string& MitCrdVtr
			, const string& MitCrdHwc
			, const string& MitCrdFil
			, const string& MitAppLoi
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
			, MitSesSps(MitSesSps)
			, MitSesTrm(MitSesTrm)
			, MitCrdUsg(MitCrdUsg)
			, MitCrdUsr(MitCrdUsr)
			, MitCrdPrs(MitCrdPrs)
			, MitCrdPrf(MitCrdPrf)
			, MitCrdLlv(MitCrdLlv)
			, MitCrdVtr(MitCrdVtr)
			, MitCrdHwc(MitCrdHwc)
			, MitCrdFil(MitCrdFil)
			, MitAppLoi(MitAppLoi)
		{
	mask = {MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDPRF, MITCRDLLV, MITCRDVTR, MITCRDHWC, MITCRDFIL, MITAPPLOI};
};

bool CrdWzskNav::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesSps", MitSesSps)) add(MITSESSPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesTrm", MitSesTrm)) add(MITSESTRM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", MitCrdUsg)) add(MITCRDUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", MitCrdUsr)) add(MITCRDUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", MitCrdPrs)) add(MITCRDPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrf", MitCrdPrf)) add(MITCRDPRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdLlv", MitCrdLlv)) add(MITCRDLLV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdVtr", MitCrdVtr)) add(MITCRDVTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdHwc", MitCrdHwc)) add(MITCRDHWC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFil", MitCrdFil)) add(MITCRDFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppLoi", MitAppLoi)) add(MITAPPLOI);
	};

	return basefound;
};

/******************************************************************************
 class CrdWzskNav::DpchAppDo
 ******************************************************************************/

CrdWzskNav::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWzskNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskNav::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskNavDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskNav::DpchEngData
 ******************************************************************************/

CrdWzskNav::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWzskNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskNav::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskNavData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
