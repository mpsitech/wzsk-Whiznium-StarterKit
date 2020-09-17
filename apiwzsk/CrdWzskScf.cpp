/**
	* \file CrdWzskScf.cpp
	* API code for job CrdWzskScf (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "CrdWzskScf.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskScf::VecVDo
 ******************************************************************************/

uint CrdWzskScf::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdcmmclick") return MITCRDCMMCLICK;
	if (s == "mitcrdttcclick") return MITCRDTTCCLICK;
	if (s == "mitcrdlspclick") return MITCRDLSPCLICK;

	return(0);
};

string CrdWzskScf::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDCMMCLICK) return("MitCrdCmmClick");
	if (ix == MITCRDTTCCLICK) return("MitCrdTtcClick");
	if (ix == MITCRDLSPCLICK) return("MitCrdLspClick");

	return("");
};

/******************************************************************************
 class CrdWzskScf::VecVSge
 ******************************************************************************/

uint CrdWzskScf::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;

	return(0);
};

string CrdWzskScf::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");

	return("");
};

/******************************************************************************
 class CrdWzskScf::ContInf
 ******************************************************************************/

CrdWzskScf::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;

	mask = {NUMFSGE, MRLAPPHLP};
};

bool CrdWzskScf::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskScf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskScf";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

set<uint> CrdWzskScf::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);

	return(items);
};

set<uint> CrdWzskScf::ContInf::diff(
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
 class CrdWzskScf::StatApp
 ******************************************************************************/

CrdWzskScf::StatApp::StatApp(
			const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneConn
			, const bool initdoneGeom
			, const bool initdoneHeadbar
		) :
			Block()
		{
	this->ixWzskVReqitmode = ixWzskVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneConn = initdoneConn;
	this->initdoneGeom = initdoneGeom;
	this->initdoneHeadbar = initdoneHeadbar;

	mask = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONECONN, INITDONEGEOM, INITDONEHEADBAR};
};

bool CrdWzskScf::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskScf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskScf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", srefIxWzskVReqitmode)) {
			ixWzskVReqitmode = VecWzskVReqitmode::getIx(srefIxWzskVReqitmode);
			add(IXWZSKVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneConn", initdoneConn)) add(INITDONECONN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneGeom", initdoneGeom)) add(INITDONEGEOM);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
	};

	return basefound;
};

set<uint> CrdWzskScf::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVReqitmode == comp->ixWzskVReqitmode) insert(items, IXWZSKVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneConn == comp->initdoneConn) insert(items, INITDONECONN);
	if (initdoneGeom == comp->initdoneGeom) insert(items, INITDONEGEOM);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);

	return(items);
};

set<uint> CrdWzskScf::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONECONN, INITDONEGEOM, INITDONEHEADBAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskScf::StatShr
 ******************************************************************************/

CrdWzskScf::StatShr::StatShr(
			const string& scrJrefDlgcameramat
			, const string& scrJrefDlglaserpos
			, const string& scrJrefDlgttablecoord
			, const string& scrJrefConn
			, const string& scrJrefGeom
			, const string& scrJrefHeadbar
		) :
			Block()
		{
	this->scrJrefDlgcameramat = scrJrefDlgcameramat;
	this->scrJrefDlglaserpos = scrJrefDlglaserpos;
	this->scrJrefDlgttablecoord = scrJrefDlgttablecoord;
	this->scrJrefConn = scrJrefConn;
	this->scrJrefGeom = scrJrefGeom;
	this->scrJrefHeadbar = scrJrefHeadbar;

	mask = {SCRJREFDLGCAMERAMAT, SCRJREFDLGLASERPOS, SCRJREFDLGTTABLECOORD, SCRJREFCONN, SCRJREFGEOM, SCRJREFHEADBAR};
};

bool CrdWzskScf::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskScf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskScf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgcameramat", scrJrefDlgcameramat)) add(SCRJREFDLGCAMERAMAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlglaserpos", scrJrefDlglaserpos)) add(SCRJREFDLGLASERPOS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgttablecoord", scrJrefDlgttablecoord)) add(SCRJREFDLGTTABLECOORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefConn", scrJrefConn)) add(SCRJREFCONN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefGeom", scrJrefGeom)) add(SCRJREFGEOM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
	};

	return basefound;
};

set<uint> CrdWzskScf::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgcameramat == comp->scrJrefDlgcameramat) insert(items, SCRJREFDLGCAMERAMAT);
	if (scrJrefDlglaserpos == comp->scrJrefDlglaserpos) insert(items, SCRJREFDLGLASERPOS);
	if (scrJrefDlgttablecoord == comp->scrJrefDlgttablecoord) insert(items, SCRJREFDLGTTABLECOORD);
	if (scrJrefConn == comp->scrJrefConn) insert(items, SCRJREFCONN);
	if (scrJrefGeom == comp->scrJrefGeom) insert(items, SCRJREFGEOM);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);

	return(items);
};

set<uint> CrdWzskScf::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGCAMERAMAT, SCRJREFDLGLASERPOS, SCRJREFDLGTTABLECOORD, SCRJREFCONN, SCRJREFGEOM, SCRJREFHEADBAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskScf::Tag
 ******************************************************************************/

CrdWzskScf::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdCmm
			, const string& MitCrdTtc
			, const string& MitCrdLsp
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdCmm = MitCrdCmm;
	this->MitCrdTtc = MitCrdTtc;
	this->MitCrdLsp = MitCrdLsp;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDCMM, MITCRDTTC, MITCRDLSP};
};

bool CrdWzskScf::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskScf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskScf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCmm", MitCrdCmm)) add(MITCRDCMM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTtc", MitCrdTtc)) add(MITCRDTTC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdLsp", MitCrdLsp)) add(MITCRDLSP);
	};

	return basefound;
};

/******************************************************************************
 class CrdWzskScf::DpchAppDo
 ******************************************************************************/

CrdWzskScf::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSCFDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWzskScf::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskScf::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskScfDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskScf::DpchEngData
 ******************************************************************************/

CrdWzskScf::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSCFDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWzskScf::DpchEngData::getSrefsMask() {
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

void CrdWzskScf::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskScfData");
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

