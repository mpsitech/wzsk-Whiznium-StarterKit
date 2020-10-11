/**
	* \file CrdWzskOgr.cpp
	* API code for job CrdWzskOgr (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "CrdWzskOgr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskOgr::VecVDo
 ******************************************************************************/

uint CrdWzskOgr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;

	return(0);
};

string CrdWzskOgr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");

	return("");
};

/******************************************************************************
 class CrdWzskOgr::VecVSge
 ******************************************************************************/

uint CrdWzskOgr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;

	return(0);
};

string CrdWzskOgr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");

	return("");
};

/******************************************************************************
 class CrdWzskOgr::ContInf
 ******************************************************************************/

CrdWzskOgr::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdOgr
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdOgr = MtxCrdOgr;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDOGR};
};

bool CrdWzskOgr::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskOgr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskOgr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdOgr", MtxCrdOgr)) add(MTXCRDOGR);
	};

	return basefound;
};

set<uint> CrdWzskOgr::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdOgr == comp->MtxCrdOgr) insert(items, MTXCRDOGR);

	return(items);
};

set<uint> CrdWzskOgr::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDOGR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskOgr::StatApp
 ******************************************************************************/

CrdWzskOgr::StatApp::StatApp(
			const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) :
			Block()
		{
	this->ixWzskVReqitmode = ixWzskVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneList = initdoneList;
	this->initdoneRec = initdoneRec;

	mask = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdWzskOgr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskOgr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskOgr";

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

set<uint> CrdWzskOgr::StatApp::comm(
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

set<uint> CrdWzskOgr::StatApp::diff(
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
 class CrdWzskOgr::StatShr
 ******************************************************************************/

CrdWzskOgr::StatShr::StatShr(
			const string& scrJrefDlgnew
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
		) :
			Block()
		{
	this->scrJrefDlgnew = scrJrefDlgnew;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;

	mask = {SCRJREFDLGNEW, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL};
};

bool CrdWzskOgr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskOgr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskOgr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", scrJrefDlgnew)) add(SCRJREFDLGNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", MitCrdNewAvail)) add(MITCRDNEWAVAIL);
	};

	return basefound;
};

set<uint> CrdWzskOgr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgnew == comp->scrJrefDlgnew) insert(items, SCRJREFDLGNEW);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);

	return(items);
};

set<uint> CrdWzskOgr::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGNEW, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskOgr::Tag
 ******************************************************************************/

CrdWzskOgr::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdNew
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdNew = MitCrdNew;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDNEW};
};

bool CrdWzskOgr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskOgr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskOgr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNew", MitCrdNew)) add(MITCRDNEW);
	};

	return basefound;
};

/******************************************************************************
 class CrdWzskOgr::DpchAppDo
 ******************************************************************************/

CrdWzskOgr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKOGRDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWzskOgr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskOgr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskOgrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskOgr::DpchEngData
 ******************************************************************************/

CrdWzskOgr::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKOGRDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWzskOgr::DpchEngData::getSrefsMask() {
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

void CrdWzskOgr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskOgrData");
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

