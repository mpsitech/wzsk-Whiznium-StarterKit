/**
	* \file CrdWzskHwc.cpp
	* API code for job CrdWzskHwc (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "CrdWzskHwc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskHwc::VecVDo
 ******************************************************************************/

uint CrdWzskHwc::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;

	return(0);
};

string CrdWzskHwc::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdWzskHwc::VecVSge
 ******************************************************************************/

uint CrdWzskHwc::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;

	return(0);
};

string CrdWzskHwc::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");

	return("");
};

/******************************************************************************
 class CrdWzskHwc::ContInf
 ******************************************************************************/

CrdWzskHwc::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
		{
	mask = {NUMFSGE, MRLAPPHLP};
};

bool CrdWzskHwc::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskHwc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskHwc";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

set<uint> CrdWzskHwc::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);

	return(items);
};

set<uint> CrdWzskHwc::ContInf::diff(
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
 class CrdWzskHwc::StatApp
 ******************************************************************************/

CrdWzskHwc::StatApp::StatApp(
			const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneConfig
			, const bool initdoneAsys
			, const bool initdoneDebug
			, const bool initdoneHeadbar
		) :
			Block()
			, ixWzskVReqitmode(ixWzskVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneConfig(initdoneConfig)
			, initdoneAsys(initdoneAsys)
			, initdoneDebug(initdoneDebug)
			, initdoneHeadbar(initdoneHeadbar)
		{
	mask = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONECONFIG, INITDONEASYS, INITDONEDEBUG, INITDONEHEADBAR};
};

bool CrdWzskHwc::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskHwc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskHwc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", srefIxWzskVReqitmode)) {
			ixWzskVReqitmode = VecWzskVReqitmode::getIx(srefIxWzskVReqitmode);
			add(IXWZSKVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneConfig", initdoneConfig)) add(INITDONECONFIG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAsys", initdoneAsys)) add(INITDONEASYS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDebug", initdoneDebug)) add(INITDONEDEBUG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
	};

	return basefound;
};

set<uint> CrdWzskHwc::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVReqitmode == comp->ixWzskVReqitmode) insert(items, IXWZSKVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneConfig == comp->initdoneConfig) insert(items, INITDONECONFIG);
	if (initdoneAsys == comp->initdoneAsys) insert(items, INITDONEASYS);
	if (initdoneDebug == comp->initdoneDebug) insert(items, INITDONEDEBUG);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);

	return(items);
};

set<uint> CrdWzskHwc::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONECONFIG, INITDONEASYS, INITDONEDEBUG, INITDONEHEADBAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskHwc::StatShr
 ******************************************************************************/

CrdWzskHwc::StatShr::StatShr(
			const string& scrJrefConfig
			, const string& scrJrefAsys
			, const string& scrJrefDebug
			, const string& scrJrefHeadbar
		) :
			Block()
			, scrJrefConfig(scrJrefConfig)
			, scrJrefAsys(scrJrefAsys)
			, scrJrefDebug(scrJrefDebug)
			, scrJrefHeadbar(scrJrefHeadbar)
		{
	mask = {SCRJREFCONFIG, SCRJREFASYS, SCRJREFDEBUG, SCRJREFHEADBAR};
};

bool CrdWzskHwc::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskHwc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskHwc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefConfig", scrJrefConfig)) add(SCRJREFCONFIG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAsys", scrJrefAsys)) add(SCRJREFASYS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDebug", scrJrefDebug)) add(SCRJREFDEBUG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
	};

	return basefound;
};

set<uint> CrdWzskHwc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefConfig == comp->scrJrefConfig) insert(items, SCRJREFCONFIG);
	if (scrJrefAsys == comp->scrJrefAsys) insert(items, SCRJREFASYS);
	if (scrJrefDebug == comp->scrJrefDebug) insert(items, SCRJREFDEBUG);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);

	return(items);
};

set<uint> CrdWzskHwc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFCONFIG, SCRJREFASYS, SCRJREFDEBUG, SCRJREFHEADBAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskHwc::Tag
 ******************************************************************************/

CrdWzskHwc::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
		{
	mask = {MITAPPABT, MRLAPPHLP};
};

bool CrdWzskHwc::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskHwc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskHwc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

/******************************************************************************
 class CrdWzskHwc::DpchAppDo
 ******************************************************************************/

CrdWzskHwc::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWzskHwc::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskHwc::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskHwcDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskHwc::DpchEngData
 ******************************************************************************/

CrdWzskHwc::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKHWCDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWzskHwc::DpchEngData::getSrefsMask() {
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

void CrdWzskHwc::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskHwcData");
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
