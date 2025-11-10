/**
	* \file CrdWzskLlv.cpp
	* API code for job CrdWzskLlv (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "CrdWzskLlv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskLlv::VecVDo
 ******************************************************************************/

uint CrdWzskLlv::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;

	return(0);
};

string CrdWzskLlv::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdWzskLlv::VecVSge
 ******************************************************************************/

uint CrdWzskLlv::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;

	return(0);
};

string CrdWzskLlv::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");

	return("");
};

/******************************************************************************
 class CrdWzskLlv::ContInf
 ******************************************************************************/

CrdWzskLlv::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
		{
	mask = {NUMFSGE, MRLAPPHLP};
};

bool CrdWzskLlv::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLlv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLlv";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

set<uint> CrdWzskLlv::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);

	return(items);
};

set<uint> CrdWzskLlv::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskLlv::StatApp
 ******************************************************************************/

CrdWzskLlv::StatApp::StatApp(
			const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneIdent
			, const bool initdoneHeadbar
			, const bool initdoneTermDcvsp
			, const bool initdoneTermTivsp
			, const bool initdoneLaser
			, const bool initdoneRotary
			, const bool initdoneSysmon
			, const bool initdoneTermZuvsp
		) :
			Block()
			, ixWzskVReqitmode(ixWzskVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneIdent(initdoneIdent)
			, initdoneHeadbar(initdoneHeadbar)
			, initdoneTermDcvsp(initdoneTermDcvsp)
			, initdoneTermTivsp(initdoneTermTivsp)
			, initdoneLaser(initdoneLaser)
			, initdoneRotary(initdoneRotary)
			, initdoneSysmon(initdoneSysmon)
			, initdoneTermZuvsp(initdoneTermZuvsp)
		{
	mask = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEIDENT, INITDONEHEADBAR, INITDONETERMDCVSP, INITDONETERMTIVSP, INITDONELASER, INITDONEROTARY, INITDONESYSMON, INITDONETERMZUVSP};
};

bool CrdWzskLlv::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskLlv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskLlv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", srefIxWzskVReqitmode)) {
			ixWzskVReqitmode = VecWzskVReqitmode::getIx(srefIxWzskVReqitmode);
			add(IXWZSKVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneIdent", initdoneIdent)) add(INITDONEIDENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermDcvsp", initdoneTermDcvsp)) add(INITDONETERMDCVSP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermTivsp", initdoneTermTivsp)) add(INITDONETERMTIVSP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneLaser", initdoneLaser)) add(INITDONELASER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRotary", initdoneRotary)) add(INITDONEROTARY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSysmon", initdoneSysmon)) add(INITDONESYSMON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermZuvsp", initdoneTermZuvsp)) add(INITDONETERMZUVSP);
	};

	return basefound;
};

set<uint> CrdWzskLlv::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVReqitmode == comp->ixWzskVReqitmode) insert(items, IXWZSKVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneIdent == comp->initdoneIdent) insert(items, INITDONEIDENT);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneTermDcvsp == comp->initdoneTermDcvsp) insert(items, INITDONETERMDCVSP);
	if (initdoneTermTivsp == comp->initdoneTermTivsp) insert(items, INITDONETERMTIVSP);
	if (initdoneLaser == comp->initdoneLaser) insert(items, INITDONELASER);
	if (initdoneRotary == comp->initdoneRotary) insert(items, INITDONEROTARY);
	if (initdoneSysmon == comp->initdoneSysmon) insert(items, INITDONESYSMON);
	if (initdoneTermZuvsp == comp->initdoneTermZuvsp) insert(items, INITDONETERMZUVSP);

	return(items);
};

set<uint> CrdWzskLlv::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEIDENT, INITDONEHEADBAR, INITDONETERMDCVSP, INITDONETERMTIVSP, INITDONELASER, INITDONEROTARY, INITDONESYSMON, INITDONETERMZUVSP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskLlv::StatShr
 ******************************************************************************/

CrdWzskLlv::StatShr::StatShr(
			const string& scrJrefIdent
			, const string& scrJrefHeadbar
			, const string& scrJrefTermDcvsp
			, const bool pnltermdcvspAvail
			, const string& scrJrefTermTivsp
			, const bool pnltermtivspAvail
			, const string& scrJrefLaser
			, const string& scrJrefRotary
			, const string& scrJrefSysmon
			, const string& scrJrefTermZuvsp
			, const bool pnltermzuvspAvail
		) :
			Block()
			, scrJrefIdent(scrJrefIdent)
			, scrJrefHeadbar(scrJrefHeadbar)
			, scrJrefTermDcvsp(scrJrefTermDcvsp)
			, pnltermdcvspAvail(pnltermdcvspAvail)
			, scrJrefTermTivsp(scrJrefTermTivsp)
			, pnltermtivspAvail(pnltermtivspAvail)
			, scrJrefLaser(scrJrefLaser)
			, scrJrefRotary(scrJrefRotary)
			, scrJrefSysmon(scrJrefSysmon)
			, scrJrefTermZuvsp(scrJrefTermZuvsp)
			, pnltermzuvspAvail(pnltermzuvspAvail)
		{
	mask = {SCRJREFIDENT, SCRJREFHEADBAR, SCRJREFTERMDCVSP, PNLTERMDCVSPAVAIL, SCRJREFTERMTIVSP, PNLTERMTIVSPAVAIL, SCRJREFLASER, SCRJREFROTARY, SCRJREFSYSMON, SCRJREFTERMZUVSP, PNLTERMZUVSPAVAIL};
};

bool CrdWzskLlv::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLlv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLlv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefIdent", scrJrefIdent)) add(SCRJREFIDENT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermDcvsp", scrJrefTermDcvsp)) add(SCRJREFTERMDCVSP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermdcvspAvail", pnltermdcvspAvail)) add(PNLTERMDCVSPAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermTivsp", scrJrefTermTivsp)) add(SCRJREFTERMTIVSP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermtivspAvail", pnltermtivspAvail)) add(PNLTERMTIVSPAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefLaser", scrJrefLaser)) add(SCRJREFLASER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRotary", scrJrefRotary)) add(SCRJREFROTARY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSysmon", scrJrefSysmon)) add(SCRJREFSYSMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermZuvsp", scrJrefTermZuvsp)) add(SCRJREFTERMZUVSP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermzuvspAvail", pnltermzuvspAvail)) add(PNLTERMZUVSPAVAIL);
	};

	return basefound;
};

set<uint> CrdWzskLlv::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefIdent == comp->scrJrefIdent) insert(items, SCRJREFIDENT);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefTermDcvsp == comp->scrJrefTermDcvsp) insert(items, SCRJREFTERMDCVSP);
	if (pnltermdcvspAvail == comp->pnltermdcvspAvail) insert(items, PNLTERMDCVSPAVAIL);
	if (scrJrefTermTivsp == comp->scrJrefTermTivsp) insert(items, SCRJREFTERMTIVSP);
	if (pnltermtivspAvail == comp->pnltermtivspAvail) insert(items, PNLTERMTIVSPAVAIL);
	if (scrJrefLaser == comp->scrJrefLaser) insert(items, SCRJREFLASER);
	if (scrJrefRotary == comp->scrJrefRotary) insert(items, SCRJREFROTARY);
	if (scrJrefSysmon == comp->scrJrefSysmon) insert(items, SCRJREFSYSMON);
	if (scrJrefTermZuvsp == comp->scrJrefTermZuvsp) insert(items, SCRJREFTERMZUVSP);
	if (pnltermzuvspAvail == comp->pnltermzuvspAvail) insert(items, PNLTERMZUVSPAVAIL);

	return(items);
};

set<uint> CrdWzskLlv::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFIDENT, SCRJREFHEADBAR, SCRJREFTERMDCVSP, PNLTERMDCVSPAVAIL, SCRJREFTERMTIVSP, PNLTERMTIVSPAVAIL, SCRJREFLASER, SCRJREFROTARY, SCRJREFSYSMON, SCRJREFTERMZUVSP, PNLTERMZUVSPAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskLlv::Tag
 ******************************************************************************/

CrdWzskLlv::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
		{
	mask = {MITAPPABT, MRLAPPHLP};
};

bool CrdWzskLlv::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLlv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLlv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

/******************************************************************************
 class CrdWzskLlv::DpchAppDo
 ******************************************************************************/

CrdWzskLlv::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWzskLlv::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskLlv::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskLlv::DpchEngData
 ******************************************************************************/

CrdWzskLlv::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWzskLlv::DpchEngData::getSrefsMask() {
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

void CrdWzskLlv::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLlvData");
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
