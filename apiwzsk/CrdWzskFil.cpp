/**
	* \file CrdWzskFil.cpp
	* API code for job CrdWzskFil (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "CrdWzskFil.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskFil::VecVDo
 ******************************************************************************/

uint CrdWzskFil::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrddldclick") return MITCRDDLDCLICK;

	return(0);
};

string CrdWzskFil::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDDLDCLICK) return("MitCrdDldClick");

	return("");
};

/******************************************************************************
 class CrdWzskFil::VecVSge
 ******************************************************************************/

uint CrdWzskFil::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;

	return(0);
};

string CrdWzskFil::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");

	return("");
};

/******************************************************************************
 class CrdWzskFil::ContInf
 ******************************************************************************/

CrdWzskFil::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdFil
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxCrdFil(MtxCrdFil)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXCRDFIL};
};

bool CrdWzskFil::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskFil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskFil";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdFil", MtxCrdFil)) add(MTXCRDFIL);
	};

	return basefound;
};

set<uint> CrdWzskFil::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdFil == comp->MtxCrdFil) insert(items, MTXCRDFIL);

	return(items);
};

set<uint> CrdWzskFil::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDFIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskFil::StatApp
 ******************************************************************************/

CrdWzskFil::StatApp::StatApp(
			const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) :
			Block()
			, ixWzskVReqitmode(ixWzskVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneHeadbar(initdoneHeadbar)
			, initdoneList(initdoneList)
			, initdoneRec(initdoneRec)
		{
	mask = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdWzskFil::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskFil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskFil";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", srefIxWzskVReqitmode)) {
			ixWzskVReqitmode = VecWzskVReqitmode::getIx(srefIxWzskVReqitmode);
			add(IXWZSKVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneList", initdoneList)) add(INITDONELIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRec", initdoneRec)) add(INITDONEREC);
	};

	return basefound;
};

set<uint> CrdWzskFil::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVReqitmode == comp->ixWzskVReqitmode) insert(items, IXWZSKVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneList == comp->initdoneList) insert(items, INITDONELIST);
	if (initdoneRec == comp->initdoneRec) insert(items, INITDONEREC);

	return(items);
};

set<uint> CrdWzskFil::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskFil::StatShr
 ******************************************************************************/

CrdWzskFil::StatShr::StatShr(
			const string& scrJrefDlgdownload
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MitCrdDldAvail
			, const bool MitCrdDldActive
		) :
			Block()
			, scrJrefDlgdownload(scrJrefDlgdownload)
			, scrJrefHeadbar(scrJrefHeadbar)
			, scrJrefList(scrJrefList)
			, scrJrefRec(scrJrefRec)
			, MitCrdDldAvail(MitCrdDldAvail)
			, MitCrdDldActive(MitCrdDldActive)
		{
	mask = {SCRJREFDLGDOWNLOAD, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MITCRDDLDAVAIL, MITCRDDLDACTIVE};
};

bool CrdWzskFil::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskFil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskFil";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgdownload", scrJrefDlgdownload)) add(SCRJREFDLGDOWNLOAD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDldAvail", MitCrdDldAvail)) add(MITCRDDLDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDldActive", MitCrdDldActive)) add(MITCRDDLDACTIVE);
	};

	return basefound;
};

set<uint> CrdWzskFil::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgdownload == comp->scrJrefDlgdownload) insert(items, SCRJREFDLGDOWNLOAD);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
	if (MitCrdDldAvail == comp->MitCrdDldAvail) insert(items, MITCRDDLDAVAIL);
	if (MitCrdDldActive == comp->MitCrdDldActive) insert(items, MITCRDDLDACTIVE);

	return(items);
};

set<uint> CrdWzskFil::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGDOWNLOAD, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MITCRDDLDAVAIL, MITCRDDLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskFil::Tag
 ******************************************************************************/

CrdWzskFil::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdDld
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
			, MitCrdDld(MitCrdDld)
		{
	mask = {MITAPPABT, MRLAPPHLP, MITCRDDLD};
};

bool CrdWzskFil::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskFil");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskFil";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdDld", MitCrdDld)) add(MITCRDDLD);
	};

	return basefound;
};

/******************************************************************************
 class CrdWzskFil::DpchAppDo
 ******************************************************************************/

CrdWzskFil::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKFILDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWzskFil::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskFil::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskFilDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskFil::DpchEngData
 ******************************************************************************/

CrdWzskFil::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKFILDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWzskFil::DpchEngData::getSrefsMask() {
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

void CrdWzskFil::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskFilData");
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
