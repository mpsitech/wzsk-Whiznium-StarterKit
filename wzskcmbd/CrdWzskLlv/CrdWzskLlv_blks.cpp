/**
	* \file CrdWzskLlv_blks.cpp
	* job handler for job CrdWzskLlv (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

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

void CrdWzskLlv::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void CrdWzskLlv::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLlv";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskLlv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
	xmlTextWriterEndElement(wr);
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

void CrdWzskLlv::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneTerm
			, const bool initdoneCamera
			, const bool initdoneTtable
			, const bool initdoneLaser
			, const bool initdoneHeadbar
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskLlv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskLlv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVReqitmode", VecWzskVReqitmode::getSref(ixWzskVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneTerm", initdoneTerm);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCamera", initdoneCamera);
		writeBoolAttr(wr, itemtag, "sref", "initdoneTtable", initdoneTtable);
		writeBoolAttr(wr, itemtag, "sref", "initdoneLaser", initdoneLaser);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskLlv::StatShr
 ******************************************************************************/

CrdWzskLlv::StatShr::StatShr(
			const ubigint jrefTerm
			, const bool pnltermAvail
			, const ubigint jrefCamera
			, const ubigint jrefTtable
			, const ubigint jrefLaser
			, const ubigint jrefHeadbar
		) :
			Block()
		{
	this->jrefTerm = jrefTerm;
	this->pnltermAvail = pnltermAvail;
	this->jrefCamera = jrefCamera;
	this->jrefTtable = jrefTtable;
	this->jrefLaser = jrefLaser;
	this->jrefHeadbar = jrefHeadbar;

	mask = {JREFTERM, PNLTERMAVAIL, JREFCAMERA, JREFTTABLE, JREFLASER, JREFHEADBAR};
};

void CrdWzskLlv::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLlv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskLlv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefTerm", Scr::scramble(jrefTerm));
		writeBoolAttr(wr, itemtag, "sref", "pnltermAvail", pnltermAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCamera", Scr::scramble(jrefCamera));
		writeStringAttr(wr, itemtag, "sref", "scrJrefTtable", Scr::scramble(jrefTtable));
		writeStringAttr(wr, itemtag, "sref", "scrJrefLaser", Scr::scramble(jrefLaser));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWzskLlv::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefTerm == comp->jrefTerm) insert(items, JREFTERM);
	if (pnltermAvail == comp->pnltermAvail) insert(items, PNLTERMAVAIL);
	if (jrefCamera == comp->jrefCamera) insert(items, JREFCAMERA);
	if (jrefTtable == comp->jrefTtable) insert(items, JREFTTABLE);
	if (jrefLaser == comp->jrefLaser) insert(items, JREFLASER);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);

	return(items);
};

set<uint> CrdWzskLlv::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFTERM, PNLTERMAVAIL, JREFCAMERA, JREFTTABLE, JREFLASER, JREFHEADBAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskLlv::Tag
 ******************************************************************************/

void CrdWzskLlv::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskLlv";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskLlv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::HELP, ixWzskVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskLlv::DpchAppDo
 ******************************************************************************/

CrdWzskLlv::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVDO)
		{
	ixVDo = 0;
};

string CrdWzskLlv::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskLlv::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLlvDo");
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
 class CrdWzskLlv::DpchEngData
 ******************************************************************************/

CrdWzskLlv::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWzskLlv::DpchEngData::getSrefsMask() {
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

void CrdWzskLlv::DpchEngData::merge(
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

void CrdWzskLlv::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLlvData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

