/**
	* \file CrdWzskLlv.cpp
	* API code for job CrdWzskLlv (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;

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
			, const bool initdoneHeadbar
			, const bool initdoneTermArty
			, const bool initdoneTermClnxevb
			, const bool initdoneTermIcicle
			, const bool initdoneTermMcvevp
			, const bool initdoneTermUvbdvk
			, const bool initdoneCamera
			, const bool initdoneTtable
			, const bool initdoneLaser
			, const bool initdoneTermPwmonuart
			, const bool initdoneTermPwmonusb
		) :
			Block()
		{
	this->ixWzskVReqitmode = ixWzskVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneTermArty = initdoneTermArty;
	this->initdoneTermClnxevb = initdoneTermClnxevb;
	this->initdoneTermIcicle = initdoneTermIcicle;
	this->initdoneTermMcvevp = initdoneTermMcvevp;
	this->initdoneTermUvbdvk = initdoneTermUvbdvk;
	this->initdoneCamera = initdoneCamera;
	this->initdoneTtable = initdoneTtable;
	this->initdoneLaser = initdoneLaser;
	this->initdoneTermPwmonuart = initdoneTermPwmonuart;
	this->initdoneTermPwmonusb = initdoneTermPwmonusb;

	mask = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONETERMARTY, INITDONETERMCLNXEVB, INITDONETERMICICLE, INITDONETERMMCVEVP, INITDONETERMUVBDVK, INITDONECAMERA, INITDONETTABLE, INITDONELASER, INITDONETERMPWMONUART, INITDONETERMPWMONUSB};
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
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermArty", initdoneTermArty)) add(INITDONETERMARTY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermClnxevb", initdoneTermClnxevb)) add(INITDONETERMCLNXEVB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermIcicle", initdoneTermIcicle)) add(INITDONETERMICICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermMcvevp", initdoneTermMcvevp)) add(INITDONETERMMCVEVP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermUvbdvk", initdoneTermUvbdvk)) add(INITDONETERMUVBDVK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCamera", initdoneCamera)) add(INITDONECAMERA);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTtable", initdoneTtable)) add(INITDONETTABLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneLaser", initdoneLaser)) add(INITDONELASER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermPwmonuart", initdoneTermPwmonuart)) add(INITDONETERMPWMONUART);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTermPwmonusb", initdoneTermPwmonusb)) add(INITDONETERMPWMONUSB);
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
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneTermArty == comp->initdoneTermArty) insert(items, INITDONETERMARTY);
	if (initdoneTermClnxevb == comp->initdoneTermClnxevb) insert(items, INITDONETERMCLNXEVB);
	if (initdoneTermIcicle == comp->initdoneTermIcicle) insert(items, INITDONETERMICICLE);
	if (initdoneTermMcvevp == comp->initdoneTermMcvevp) insert(items, INITDONETERMMCVEVP);
	if (initdoneTermUvbdvk == comp->initdoneTermUvbdvk) insert(items, INITDONETERMUVBDVK);
	if (initdoneCamera == comp->initdoneCamera) insert(items, INITDONECAMERA);
	if (initdoneTtable == comp->initdoneTtable) insert(items, INITDONETTABLE);
	if (initdoneLaser == comp->initdoneLaser) insert(items, INITDONELASER);
	if (initdoneTermPwmonuart == comp->initdoneTermPwmonuart) insert(items, INITDONETERMPWMONUART);
	if (initdoneTermPwmonusb == comp->initdoneTermPwmonusb) insert(items, INITDONETERMPWMONUSB);

	return(items);
};

set<uint> CrdWzskLlv::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONETERMARTY, INITDONETERMCLNXEVB, INITDONETERMICICLE, INITDONETERMMCVEVP, INITDONETERMUVBDVK, INITDONECAMERA, INITDONETTABLE, INITDONELASER, INITDONETERMPWMONUART, INITDONETERMPWMONUSB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskLlv::StatShr
 ******************************************************************************/

CrdWzskLlv::StatShr::StatShr(
			const string& scrJrefHeadbar
			, const string& scrJrefTermArty
			, const bool pnltermartyAvail
			, const string& scrJrefTermClnxevb
			, const bool pnltermclnxevbAvail
			, const string& scrJrefTermIcicle
			, const bool pnltermicicleAvail
			, const string& scrJrefTermMcvevp
			, const bool pnltermmcvevpAvail
			, const string& scrJrefTermUvbdvk
			, const bool pnltermuvbdvkAvail
			, const string& scrJrefCamera
			, const string& scrJrefTtable
			, const string& scrJrefLaser
			, const string& scrJrefTermPwmonuart
			, const bool pnltermpwmonuartAvail
			, const string& scrJrefTermPwmonusb
			, const bool pnltermpwmonusbAvail
		) :
			Block()
		{
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefTermArty = scrJrefTermArty;
	this->pnltermartyAvail = pnltermartyAvail;
	this->scrJrefTermClnxevb = scrJrefTermClnxevb;
	this->pnltermclnxevbAvail = pnltermclnxevbAvail;
	this->scrJrefTermIcicle = scrJrefTermIcicle;
	this->pnltermicicleAvail = pnltermicicleAvail;
	this->scrJrefTermMcvevp = scrJrefTermMcvevp;
	this->pnltermmcvevpAvail = pnltermmcvevpAvail;
	this->scrJrefTermUvbdvk = scrJrefTermUvbdvk;
	this->pnltermuvbdvkAvail = pnltermuvbdvkAvail;
	this->scrJrefCamera = scrJrefCamera;
	this->scrJrefTtable = scrJrefTtable;
	this->scrJrefLaser = scrJrefLaser;
	this->scrJrefTermPwmonuart = scrJrefTermPwmonuart;
	this->pnltermpwmonuartAvail = pnltermpwmonuartAvail;
	this->scrJrefTermPwmonusb = scrJrefTermPwmonusb;
	this->pnltermpwmonusbAvail = pnltermpwmonusbAvail;

	mask = {SCRJREFHEADBAR, SCRJREFTERMARTY, PNLTERMARTYAVAIL, SCRJREFTERMCLNXEVB, PNLTERMCLNXEVBAVAIL, SCRJREFTERMICICLE, PNLTERMICICLEAVAIL, SCRJREFTERMMCVEVP, PNLTERMMCVEVPAVAIL, SCRJREFTERMUVBDVK, PNLTERMUVBDVKAVAIL, SCRJREFCAMERA, SCRJREFTTABLE, SCRJREFLASER, SCRJREFTERMPWMONUART, PNLTERMPWMONUARTAVAIL, SCRJREFTERMPWMONUSB, PNLTERMPWMONUSBAVAIL};
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
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermArty", scrJrefTermArty)) add(SCRJREFTERMARTY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermartyAvail", pnltermartyAvail)) add(PNLTERMARTYAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermClnxevb", scrJrefTermClnxevb)) add(SCRJREFTERMCLNXEVB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermclnxevbAvail", pnltermclnxevbAvail)) add(PNLTERMCLNXEVBAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermIcicle", scrJrefTermIcicle)) add(SCRJREFTERMICICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermicicleAvail", pnltermicicleAvail)) add(PNLTERMICICLEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermMcvevp", scrJrefTermMcvevp)) add(SCRJREFTERMMCVEVP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermmcvevpAvail", pnltermmcvevpAvail)) add(PNLTERMMCVEVPAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermUvbdvk", scrJrefTermUvbdvk)) add(SCRJREFTERMUVBDVK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermuvbdvkAvail", pnltermuvbdvkAvail)) add(PNLTERMUVBDVKAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCamera", scrJrefCamera)) add(SCRJREFCAMERA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTtable", scrJrefTtable)) add(SCRJREFTTABLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefLaser", scrJrefLaser)) add(SCRJREFLASER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermPwmonuart", scrJrefTermPwmonuart)) add(SCRJREFTERMPWMONUART);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermpwmonuartAvail", pnltermpwmonuartAvail)) add(PNLTERMPWMONUARTAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTermPwmonusb", scrJrefTermPwmonusb)) add(SCRJREFTERMPWMONUSB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnltermpwmonusbAvail", pnltermpwmonusbAvail)) add(PNLTERMPWMONUSBAVAIL);
	};

	return basefound;
};

set<uint> CrdWzskLlv::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefTermArty == comp->scrJrefTermArty) insert(items, SCRJREFTERMARTY);
	if (pnltermartyAvail == comp->pnltermartyAvail) insert(items, PNLTERMARTYAVAIL);
	if (scrJrefTermClnxevb == comp->scrJrefTermClnxevb) insert(items, SCRJREFTERMCLNXEVB);
	if (pnltermclnxevbAvail == comp->pnltermclnxevbAvail) insert(items, PNLTERMCLNXEVBAVAIL);
	if (scrJrefTermIcicle == comp->scrJrefTermIcicle) insert(items, SCRJREFTERMICICLE);
	if (pnltermicicleAvail == comp->pnltermicicleAvail) insert(items, PNLTERMICICLEAVAIL);
	if (scrJrefTermMcvevp == comp->scrJrefTermMcvevp) insert(items, SCRJREFTERMMCVEVP);
	if (pnltermmcvevpAvail == comp->pnltermmcvevpAvail) insert(items, PNLTERMMCVEVPAVAIL);
	if (scrJrefTermUvbdvk == comp->scrJrefTermUvbdvk) insert(items, SCRJREFTERMUVBDVK);
	if (pnltermuvbdvkAvail == comp->pnltermuvbdvkAvail) insert(items, PNLTERMUVBDVKAVAIL);
	if (scrJrefCamera == comp->scrJrefCamera) insert(items, SCRJREFCAMERA);
	if (scrJrefTtable == comp->scrJrefTtable) insert(items, SCRJREFTTABLE);
	if (scrJrefLaser == comp->scrJrefLaser) insert(items, SCRJREFLASER);
	if (scrJrefTermPwmonuart == comp->scrJrefTermPwmonuart) insert(items, SCRJREFTERMPWMONUART);
	if (pnltermpwmonuartAvail == comp->pnltermpwmonuartAvail) insert(items, PNLTERMPWMONUARTAVAIL);
	if (scrJrefTermPwmonusb == comp->scrJrefTermPwmonusb) insert(items, SCRJREFTERMPWMONUSB);
	if (pnltermpwmonusbAvail == comp->pnltermpwmonusbAvail) insert(items, PNLTERMPWMONUSBAVAIL);

	return(items);
};

set<uint> CrdWzskLlv::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFHEADBAR, SCRJREFTERMARTY, PNLTERMARTYAVAIL, SCRJREFTERMCLNXEVB, PNLTERMCLNXEVBAVAIL, SCRJREFTERMICICLE, PNLTERMICICLEAVAIL, SCRJREFTERMMCVEVP, PNLTERMMCVEVPAVAIL, SCRJREFTERMUVBDVK, PNLTERMUVBDVKAVAIL, SCRJREFCAMERA, SCRJREFTTABLE, SCRJREFLASER, SCRJREFTERMPWMONUART, PNLTERMPWMONUARTAVAIL, SCRJREFTERMPWMONUSB, PNLTERMPWMONUSBAVAIL};
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
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;

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
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
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
