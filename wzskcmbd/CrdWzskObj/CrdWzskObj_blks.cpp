/**
	* \file CrdWzskObj_blks.cpp
	* job handler for job CrdWzskObj (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskObj::VecVDo
 ******************************************************************************/

uint CrdWzskObj::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;

	return(0);
};

string CrdWzskObj::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");

	return("");
};

/******************************************************************************
 class CrdWzskObj::VecVSge
 ******************************************************************************/

uint CrdWzskObj::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;

	return(0);
};

string CrdWzskObj::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");

	return("");
};

void CrdWzskObj::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdWzskObj::ContInf
 ******************************************************************************/

CrdWzskObj::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdObj
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdObj = MtxCrdObj;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDOBJ};
};

void CrdWzskObj::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskObj";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxCrdObj"] = MtxCrdObj;
};

void CrdWzskObj::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskObj";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskObj";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdObj", MtxCrdObj);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWzskObj::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdObj == comp->MtxCrdObj) insert(items, MTXCRDOBJ);

	return(items);
};

set<uint> CrdWzskObj::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDOBJ};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskObj::StatApp
 ******************************************************************************/

void CrdWzskObj::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskObj";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVReqitmode"] = VecWzskVReqitmode::getSref(ixWzskVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneList"] = initdoneList;
	me["initdoneRec"] = initdoneRec;
};

void CrdWzskObj::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskObj";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskObj";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVReqitmode", VecWzskVReqitmode::getSref(ixWzskVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskObj::StatShr
 ******************************************************************************/

CrdWzskObj::StatShr::StatShr(
			const ubigint jrefDlgnew
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
		) :
			Block()
		{
	this->jrefDlgnew = jrefDlgnew;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;

	mask = {JREFDLGNEW, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL};
};

void CrdWzskObj::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskObj";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgnew"] = Scr::scramble(jrefDlgnew);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefList"] = Scr::scramble(jrefList);
	me["scrJrefRec"] = Scr::scramble(jrefRec);
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdNewAvail"] = MitCrdNewAvail;
};

void CrdWzskObj::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskObj";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskObj";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgnew", Scr::scramble(jrefDlgnew));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNewAvail", MitCrdNewAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWzskObj::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgnew == comp->jrefDlgnew) insert(items, JREFDLGNEW);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);

	return(items);
};

set<uint> CrdWzskObj::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGNEW, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskObj::Tag
 ******************************************************************************/

void CrdWzskObj::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskObj";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
	};
	me["MitAppAbt"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::HELP, ixWzskVLocale)) + " ...";
	me["MitCrdNew"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::NEW, ixWzskVLocale)) + " ...";
};

void CrdWzskObj::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskObj";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskObj";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::HELP, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitCrdNew", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::NEW, ixWzskVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskObj::DpchAppDo
 ******************************************************************************/

CrdWzskObj::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKOBJDO)
		{
	ixVDo = 0;
};

string CrdWzskObj::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskObj::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzskObjDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWzskObj::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskObjDo");
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
 class CrdWzskObj::DpchEngData
 ******************************************************************************/

CrdWzskObj::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKOBJDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWzskObj::DpchEngData::getSrefsMask() {
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

void CrdWzskObj::DpchEngData::merge(
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

void CrdWzskObj::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskObjData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void CrdWzskObj::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskObjData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
