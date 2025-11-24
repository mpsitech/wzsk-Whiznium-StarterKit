/**
	* \file CrdWzskPrf_blks.cpp
	* job handler for job CrdWzskPrf (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

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

void CrdWzskPrf::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void CrdWzskPrf::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskPrf";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
};

void CrdWzskPrf::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskPrf";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskPrf";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
	xmlTextWriterEndElement(wr);
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

void CrdWzskPrf::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzskVReqitmode
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskPrf";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVReqitmode"] = VecWzskVReqitmode::getSref(ixWzskVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = (Json::Value::UInt) widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneDaemon"] = initdoneDaemon;
	me["initdoneGlobal"] = initdoneGlobal;
	me["initdoneAcqCorner"] = initdoneAcqCorner;
	me["initdoneAcqHdr"] = initdoneAcqHdr;
	me["initdoneAcqPreview"] = initdoneAcqPreview;
	me["initdoneAcqTrace"] = initdoneAcqTrace;
	me["initdoneActLaser"] = initdoneActLaser;
	me["initdoneActRotary"] = initdoneActRotary;
	me["initdoneActVistorot"] = initdoneActVistorot;
	me["initdoneSrcDcvsp"] = initdoneSrcDcvsp;
	me["initdoneSrcSysinfo"] = initdoneSrcSysinfo;
	me["initdoneSrcTivsp"] = initdoneSrcTivsp;
	me["initdoneSrcZuvsp"] = initdoneSrcZuvsp;
};

void CrdWzskPrf::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVReqitmode
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskPrf";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskPrf";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVReqitmode", VecWzskVReqitmode::getSref(ixWzskVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDaemon", initdoneDaemon);
		writeBoolAttr(wr, itemtag, "sref", "initdoneGlobal", initdoneGlobal);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAcqCorner", initdoneAcqCorner);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAcqHdr", initdoneAcqHdr);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAcqPreview", initdoneAcqPreview);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAcqTrace", initdoneAcqTrace);
		writeBoolAttr(wr, itemtag, "sref", "initdoneActLaser", initdoneActLaser);
		writeBoolAttr(wr, itemtag, "sref", "initdoneActRotary", initdoneActRotary);
		writeBoolAttr(wr, itemtag, "sref", "initdoneActVistorot", initdoneActVistorot);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSrcDcvsp", initdoneSrcDcvsp);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSrcSysinfo", initdoneSrcSysinfo);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSrcTivsp", initdoneSrcTivsp);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSrcZuvsp", initdoneSrcZuvsp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskPrf::StatShr
 ******************************************************************************/

CrdWzskPrf::StatShr::StatShr(
			const ubigint jrefHeadbar
			, const ubigint jrefDaemon
			, const ubigint jrefGlobal
			, const ubigint jrefAcqCorner
			, const ubigint jrefAcqHdr
			, const ubigint jrefAcqPreview
			, const ubigint jrefAcqTrace
			, const ubigint jrefActLaser
			, const ubigint jrefActRotary
			, const ubigint jrefActVistorot
			, const ubigint jrefSrcDcvsp
			, const ubigint jrefSrcSysinfo
			, const ubigint jrefSrcTivsp
			, const ubigint jrefSrcZuvsp
		) :
			Block()
			, jrefHeadbar(jrefHeadbar)
			, jrefDaemon(jrefDaemon)
			, jrefGlobal(jrefGlobal)
			, jrefAcqCorner(jrefAcqCorner)
			, jrefAcqHdr(jrefAcqHdr)
			, jrefAcqPreview(jrefAcqPreview)
			, jrefAcqTrace(jrefAcqTrace)
			, jrefActLaser(jrefActLaser)
			, jrefActRotary(jrefActRotary)
			, jrefActVistorot(jrefActVistorot)
			, jrefSrcDcvsp(jrefSrcDcvsp)
			, jrefSrcSysinfo(jrefSrcSysinfo)
			, jrefSrcTivsp(jrefSrcTivsp)
			, jrefSrcZuvsp(jrefSrcZuvsp)
		{
	mask = {JREFHEADBAR, JREFDAEMON, JREFGLOBAL, JREFACQCORNER, JREFACQHDR, JREFACQPREVIEW, JREFACQTRACE, JREFACTLASER, JREFACTROTARY, JREFACTVISTOROT, JREFSRCDCVSP, JREFSRCSYSINFO, JREFSRCTIVSP, JREFSRCZUVSP};
};

void CrdWzskPrf::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrf";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefDaemon"] = Scr::scramble(jrefDaemon);
	me["scrJrefGlobal"] = Scr::scramble(jrefGlobal);
	me["scrJrefAcqCorner"] = Scr::scramble(jrefAcqCorner);
	me["scrJrefAcqHdr"] = Scr::scramble(jrefAcqHdr);
	me["scrJrefAcqPreview"] = Scr::scramble(jrefAcqPreview);
	me["scrJrefAcqTrace"] = Scr::scramble(jrefAcqTrace);
	me["scrJrefActLaser"] = Scr::scramble(jrefActLaser);
	me["scrJrefActRotary"] = Scr::scramble(jrefActRotary);
	me["scrJrefActVistorot"] = Scr::scramble(jrefActVistorot);
	me["scrJrefSrcDcvsp"] = Scr::scramble(jrefSrcDcvsp);
	me["scrJrefSrcSysinfo"] = Scr::scramble(jrefSrcSysinfo);
	me["scrJrefSrcTivsp"] = Scr::scramble(jrefSrcTivsp);
	me["scrJrefSrcZuvsp"] = Scr::scramble(jrefSrcZuvsp);
};

void CrdWzskPrf::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrf";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskPrf";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDaemon", Scr::scramble(jrefDaemon));
		writeStringAttr(wr, itemtag, "sref", "scrJrefGlobal", Scr::scramble(jrefGlobal));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqCorner", Scr::scramble(jrefAcqCorner));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqHdr", Scr::scramble(jrefAcqHdr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqPreview", Scr::scramble(jrefAcqPreview));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqTrace", Scr::scramble(jrefAcqTrace));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActLaser", Scr::scramble(jrefActLaser));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActRotary", Scr::scramble(jrefActRotary));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActVistorot", Scr::scramble(jrefActVistorot));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrcDcvsp", Scr::scramble(jrefSrcDcvsp));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrcSysinfo", Scr::scramble(jrefSrcSysinfo));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrcTivsp", Scr::scramble(jrefSrcTivsp));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrcZuvsp", Scr::scramble(jrefSrcZuvsp));
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWzskPrf::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefDaemon == comp->jrefDaemon) insert(items, JREFDAEMON);
	if (jrefGlobal == comp->jrefGlobal) insert(items, JREFGLOBAL);
	if (jrefAcqCorner == comp->jrefAcqCorner) insert(items, JREFACQCORNER);
	if (jrefAcqHdr == comp->jrefAcqHdr) insert(items, JREFACQHDR);
	if (jrefAcqPreview == comp->jrefAcqPreview) insert(items, JREFACQPREVIEW);
	if (jrefAcqTrace == comp->jrefAcqTrace) insert(items, JREFACQTRACE);
	if (jrefActLaser == comp->jrefActLaser) insert(items, JREFACTLASER);
	if (jrefActRotary == comp->jrefActRotary) insert(items, JREFACTROTARY);
	if (jrefActVistorot == comp->jrefActVistorot) insert(items, JREFACTVISTOROT);
	if (jrefSrcDcvsp == comp->jrefSrcDcvsp) insert(items, JREFSRCDCVSP);
	if (jrefSrcSysinfo == comp->jrefSrcSysinfo) insert(items, JREFSRCSYSINFO);
	if (jrefSrcTivsp == comp->jrefSrcTivsp) insert(items, JREFSRCTIVSP);
	if (jrefSrcZuvsp == comp->jrefSrcZuvsp) insert(items, JREFSRCZUVSP);

	return(items);
};

set<uint> CrdWzskPrf::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFHEADBAR, JREFDAEMON, JREFGLOBAL, JREFACQCORNER, JREFACQHDR, JREFACQPREVIEW, JREFACQTRACE, JREFACTLASER, JREFACTROTARY, JREFACTVISTOROT, JREFSRCDCVSP, JREFSRCSYSINFO, JREFSRCTIVSP, JREFSRCZUVSP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskPrf::Tag
 ******************************************************************************/

void CrdWzskPrf::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrf";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["MitCrdRvr"] = "Revert to saved values";
		me["MitCrdSto"] = "Store to file";
	};
	me["MitAppAbt"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::HELP, ixWzskVLocale)) + " ...";
};

void CrdWzskPrf::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrf";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskPrf";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdRvr", "Revert to saved values");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSto", "Store to file");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::HELP, ixWzskVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskPrf::DpchAppDo
 ******************************************************************************/

CrdWzskPrf::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFDO)
		{
	ixVDo = 0;
};

string CrdWzskPrf::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskPrf::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskPrfDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWzskPrf::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrfDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class CrdWzskPrf::DpchEngData
 ******************************************************************************/

CrdWzskPrf::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWzskPrf::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskPrf::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdWzskPrf::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskPrfData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void CrdWzskPrf::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskPrfData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
