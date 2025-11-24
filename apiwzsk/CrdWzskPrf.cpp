/**
	* \file CrdWzskPrf.cpp
	* API code for job CrdWzskPrf (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "CrdWzskPrf.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskPrf::VecVDo
 ******************************************************************************/

uint CrdWzskPrf::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdrvrclick") return MITCRDRVRCLICK;
	if (s == "mitcrdstoclick") return MITCRDSTOCLICK;

	return(0);
};

string CrdWzskPrf::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDRVRCLICK) return("MitCrdRvrClick");
	if (ix == MITCRDSTOCLICK) return("MitCrdStoClick");

	return("");
};

/******************************************************************************
 class CrdWzskPrf::VecVSge
 ******************************************************************************/

uint CrdWzskPrf::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;

	return(0);
};

string CrdWzskPrf::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");

	return("");
};

/******************************************************************************
 class CrdWzskPrf::ContInf
 ******************************************************************************/

CrdWzskPrf::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
		{
	mask = {NUMFSGE, MRLAPPHLP};
};

bool CrdWzskPrf::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskPrf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskPrf";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

set<uint> CrdWzskPrf::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);

	return(items);
};

set<uint> CrdWzskPrf::ContInf::diff(
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
 class CrdWzskPrf::StatApp
 ******************************************************************************/

CrdWzskPrf::StatApp::StatApp(
			const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneDaemon
			, const bool initdoneGlobal
			, const bool initdoneAcqCorner
			, const bool initdoneAcqHdr
			, const bool initdoneAcqPreview
			, const bool initdoneAcqTrace
			, const bool initdoneActLaser
			, const bool initdoneActRotary
			, const bool initdoneActVistorot
			, const bool initdoneSrcDcvsp
			, const bool initdoneSrcSysinfo
			, const bool initdoneSrcTivsp
			, const bool initdoneSrcZuvsp
		) :
			Block()
			, ixWzskVReqitmode(ixWzskVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneHeadbar(initdoneHeadbar)
			, initdoneDaemon(initdoneDaemon)
			, initdoneGlobal(initdoneGlobal)
			, initdoneAcqCorner(initdoneAcqCorner)
			, initdoneAcqHdr(initdoneAcqHdr)
			, initdoneAcqPreview(initdoneAcqPreview)
			, initdoneAcqTrace(initdoneAcqTrace)
			, initdoneActLaser(initdoneActLaser)
			, initdoneActRotary(initdoneActRotary)
			, initdoneActVistorot(initdoneActVistorot)
			, initdoneSrcDcvsp(initdoneSrcDcvsp)
			, initdoneSrcSysinfo(initdoneSrcSysinfo)
			, initdoneSrcTivsp(initdoneSrcTivsp)
			, initdoneSrcZuvsp(initdoneSrcZuvsp)
		{
	mask = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEDAEMON, INITDONEGLOBAL, INITDONEACQCORNER, INITDONEACQHDR, INITDONEACQPREVIEW, INITDONEACQTRACE, INITDONEACTLASER, INITDONEACTROTARY, INITDONEACTVISTOROT, INITDONESRCDCVSP, INITDONESRCSYSINFO, INITDONESRCTIVSP, INITDONESRCZUVSP};
};

bool CrdWzskPrf::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskPrf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskPrf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", srefIxWzskVReqitmode)) {
			ixWzskVReqitmode = VecWzskVReqitmode::getIx(srefIxWzskVReqitmode);
			add(IXWZSKVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDaemon", initdoneDaemon)) add(INITDONEDAEMON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneGlobal", initdoneGlobal)) add(INITDONEGLOBAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAcqCorner", initdoneAcqCorner)) add(INITDONEACQCORNER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAcqHdr", initdoneAcqHdr)) add(INITDONEACQHDR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAcqPreview", initdoneAcqPreview)) add(INITDONEACQPREVIEW);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAcqTrace", initdoneAcqTrace)) add(INITDONEACQTRACE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneActLaser", initdoneActLaser)) add(INITDONEACTLASER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneActRotary", initdoneActRotary)) add(INITDONEACTROTARY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneActVistorot", initdoneActVistorot)) add(INITDONEACTVISTOROT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSrcDcvsp", initdoneSrcDcvsp)) add(INITDONESRCDCVSP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSrcSysinfo", initdoneSrcSysinfo)) add(INITDONESRCSYSINFO);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSrcTivsp", initdoneSrcTivsp)) add(INITDONESRCTIVSP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSrcZuvsp", initdoneSrcZuvsp)) add(INITDONESRCZUVSP);
	};

	return basefound;
};

set<uint> CrdWzskPrf::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVReqitmode == comp->ixWzskVReqitmode) insert(items, IXWZSKVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneDaemon == comp->initdoneDaemon) insert(items, INITDONEDAEMON);
	if (initdoneGlobal == comp->initdoneGlobal) insert(items, INITDONEGLOBAL);
	if (initdoneAcqCorner == comp->initdoneAcqCorner) insert(items, INITDONEACQCORNER);
	if (initdoneAcqHdr == comp->initdoneAcqHdr) insert(items, INITDONEACQHDR);
	if (initdoneAcqPreview == comp->initdoneAcqPreview) insert(items, INITDONEACQPREVIEW);
	if (initdoneAcqTrace == comp->initdoneAcqTrace) insert(items, INITDONEACQTRACE);
	if (initdoneActLaser == comp->initdoneActLaser) insert(items, INITDONEACTLASER);
	if (initdoneActRotary == comp->initdoneActRotary) insert(items, INITDONEACTROTARY);
	if (initdoneActVistorot == comp->initdoneActVistorot) insert(items, INITDONEACTVISTOROT);
	if (initdoneSrcDcvsp == comp->initdoneSrcDcvsp) insert(items, INITDONESRCDCVSP);
	if (initdoneSrcSysinfo == comp->initdoneSrcSysinfo) insert(items, INITDONESRCSYSINFO);
	if (initdoneSrcTivsp == comp->initdoneSrcTivsp) insert(items, INITDONESRCTIVSP);
	if (initdoneSrcZuvsp == comp->initdoneSrcZuvsp) insert(items, INITDONESRCZUVSP);

	return(items);
};

set<uint> CrdWzskPrf::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEDAEMON, INITDONEGLOBAL, INITDONEACQCORNER, INITDONEACQHDR, INITDONEACQPREVIEW, INITDONEACQTRACE, INITDONEACTLASER, INITDONEACTROTARY, INITDONEACTVISTOROT, INITDONESRCDCVSP, INITDONESRCSYSINFO, INITDONESRCTIVSP, INITDONESRCZUVSP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskPrf::StatShr
 ******************************************************************************/

CrdWzskPrf::StatShr::StatShr(
			const string& scrJrefHeadbar
			, const string& scrJrefDaemon
			, const string& scrJrefGlobal
			, const string& scrJrefAcqCorner
			, const string& scrJrefAcqHdr
			, const string& scrJrefAcqPreview
			, const string& scrJrefAcqTrace
			, const string& scrJrefActLaser
			, const string& scrJrefActRotary
			, const string& scrJrefActVistorot
			, const string& scrJrefSrcDcvsp
			, const string& scrJrefSrcSysinfo
			, const string& scrJrefSrcTivsp
			, const string& scrJrefSrcZuvsp
		) :
			Block()
			, scrJrefHeadbar(scrJrefHeadbar)
			, scrJrefDaemon(scrJrefDaemon)
			, scrJrefGlobal(scrJrefGlobal)
			, scrJrefAcqCorner(scrJrefAcqCorner)
			, scrJrefAcqHdr(scrJrefAcqHdr)
			, scrJrefAcqPreview(scrJrefAcqPreview)
			, scrJrefAcqTrace(scrJrefAcqTrace)
			, scrJrefActLaser(scrJrefActLaser)
			, scrJrefActRotary(scrJrefActRotary)
			, scrJrefActVistorot(scrJrefActVistorot)
			, scrJrefSrcDcvsp(scrJrefSrcDcvsp)
			, scrJrefSrcSysinfo(scrJrefSrcSysinfo)
			, scrJrefSrcTivsp(scrJrefSrcTivsp)
			, scrJrefSrcZuvsp(scrJrefSrcZuvsp)
		{
	mask = {SCRJREFHEADBAR, SCRJREFDAEMON, SCRJREFGLOBAL, SCRJREFACQCORNER, SCRJREFACQHDR, SCRJREFACQPREVIEW, SCRJREFACQTRACE, SCRJREFACTLASER, SCRJREFACTROTARY, SCRJREFACTVISTOROT, SCRJREFSRCDCVSP, SCRJREFSRCSYSINFO, SCRJREFSRCTIVSP, SCRJREFSRCZUVSP};
};

bool CrdWzskPrf::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskPrf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskPrf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDaemon", scrJrefDaemon)) add(SCRJREFDAEMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefGlobal", scrJrefGlobal)) add(SCRJREFGLOBAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqCorner", scrJrefAcqCorner)) add(SCRJREFACQCORNER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqHdr", scrJrefAcqHdr)) add(SCRJREFACQHDR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqPreview", scrJrefAcqPreview)) add(SCRJREFACQPREVIEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqTrace", scrJrefAcqTrace)) add(SCRJREFACQTRACE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActLaser", scrJrefActLaser)) add(SCRJREFACTLASER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActRotary", scrJrefActRotary)) add(SCRJREFACTROTARY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActVistorot", scrJrefActVistorot)) add(SCRJREFACTVISTOROT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrcDcvsp", scrJrefSrcDcvsp)) add(SCRJREFSRCDCVSP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrcSysinfo", scrJrefSrcSysinfo)) add(SCRJREFSRCSYSINFO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrcTivsp", scrJrefSrcTivsp)) add(SCRJREFSRCTIVSP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrcZuvsp", scrJrefSrcZuvsp)) add(SCRJREFSRCZUVSP);
	};

	return basefound;
};

set<uint> CrdWzskPrf::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefDaemon == comp->scrJrefDaemon) insert(items, SCRJREFDAEMON);
	if (scrJrefGlobal == comp->scrJrefGlobal) insert(items, SCRJREFGLOBAL);
	if (scrJrefAcqCorner == comp->scrJrefAcqCorner) insert(items, SCRJREFACQCORNER);
	if (scrJrefAcqHdr == comp->scrJrefAcqHdr) insert(items, SCRJREFACQHDR);
	if (scrJrefAcqPreview == comp->scrJrefAcqPreview) insert(items, SCRJREFACQPREVIEW);
	if (scrJrefAcqTrace == comp->scrJrefAcqTrace) insert(items, SCRJREFACQTRACE);
	if (scrJrefActLaser == comp->scrJrefActLaser) insert(items, SCRJREFACTLASER);
	if (scrJrefActRotary == comp->scrJrefActRotary) insert(items, SCRJREFACTROTARY);
	if (scrJrefActVistorot == comp->scrJrefActVistorot) insert(items, SCRJREFACTVISTOROT);
	if (scrJrefSrcDcvsp == comp->scrJrefSrcDcvsp) insert(items, SCRJREFSRCDCVSP);
	if (scrJrefSrcSysinfo == comp->scrJrefSrcSysinfo) insert(items, SCRJREFSRCSYSINFO);
	if (scrJrefSrcTivsp == comp->scrJrefSrcTivsp) insert(items, SCRJREFSRCTIVSP);
	if (scrJrefSrcZuvsp == comp->scrJrefSrcZuvsp) insert(items, SCRJREFSRCZUVSP);

	return(items);
};

set<uint> CrdWzskPrf::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFHEADBAR, SCRJREFDAEMON, SCRJREFGLOBAL, SCRJREFACQCORNER, SCRJREFACQHDR, SCRJREFACQPREVIEW, SCRJREFACQTRACE, SCRJREFACTLASER, SCRJREFACTROTARY, SCRJREFACTVISTOROT, SCRJREFSRCDCVSP, SCRJREFSRCSYSINFO, SCRJREFSRCTIVSP, SCRJREFSRCZUVSP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskPrf::Tag
 ******************************************************************************/

CrdWzskPrf::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdRvr
			, const string& MitCrdSto
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
			, MitCrdRvr(MitCrdRvr)
			, MitCrdSto(MitCrdSto)
		{
	mask = {MITAPPABT, MRLAPPHLP, MITCRDRVR, MITCRDSTO};
};

bool CrdWzskPrf::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskPrf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskPrf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdRvr", MitCrdRvr)) add(MITCRDRVR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSto", MitCrdSto)) add(MITCRDSTO);
	};

	return basefound;
};

/******************************************************************************
 class CrdWzskPrf::DpchAppDo
 ******************************************************************************/

CrdWzskPrf::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWzskPrf::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskPrf::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskPrf::DpchEngData
 ******************************************************************************/

CrdWzskPrf::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWzskPrf::DpchEngData::getSrefsMask() {
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

void CrdWzskPrf::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskPrfData");
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
