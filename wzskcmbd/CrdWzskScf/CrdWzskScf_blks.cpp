/**
	* \file CrdWzskScf_blks.cpp
	* job handler for job CrdWzskScf (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

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

void CrdWzskScf::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void CrdWzskScf::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskScf";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskScf";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
	xmlTextWriterEndElement(wr);
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

void CrdWzskScf::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneConn
			, const bool initdoneGeom
			, const bool initdoneHeadbar
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskScf";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskScf";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVReqitmode", VecWzskVReqitmode::getSref(ixWzskVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneConn", initdoneConn);
		writeBoolAttr(wr, itemtag, "sref", "initdoneGeom", initdoneGeom);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskScf::StatShr
 ******************************************************************************/

CrdWzskScf::StatShr::StatShr(
			const ubigint jrefDlgcameramat
			, const ubigint jrefDlglaserpos
			, const ubigint jrefDlgttablecoord
			, const ubigint jrefConn
			, const ubigint jrefGeom
			, const ubigint jrefHeadbar
		) :
			Block()
		{
	this->jrefDlgcameramat = jrefDlgcameramat;
	this->jrefDlglaserpos = jrefDlglaserpos;
	this->jrefDlgttablecoord = jrefDlgttablecoord;
	this->jrefConn = jrefConn;
	this->jrefGeom = jrefGeom;
	this->jrefHeadbar = jrefHeadbar;

	mask = {JREFDLGCAMERAMAT, JREFDLGLASERPOS, JREFDLGTTABLECOORD, JREFCONN, JREFGEOM, JREFHEADBAR};
};

void CrdWzskScf::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskScf";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskScf";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgcameramat", Scr::scramble(jrefDlgcameramat));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlglaserpos", Scr::scramble(jrefDlglaserpos));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgttablecoord", Scr::scramble(jrefDlgttablecoord));
		writeStringAttr(wr, itemtag, "sref", "scrJrefConn", Scr::scramble(jrefConn));
		writeStringAttr(wr, itemtag, "sref", "scrJrefGeom", Scr::scramble(jrefGeom));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWzskScf::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgcameramat == comp->jrefDlgcameramat) insert(items, JREFDLGCAMERAMAT);
	if (jrefDlglaserpos == comp->jrefDlglaserpos) insert(items, JREFDLGLASERPOS);
	if (jrefDlgttablecoord == comp->jrefDlgttablecoord) insert(items, JREFDLGTTABLECOORD);
	if (jrefConn == comp->jrefConn) insert(items, JREFCONN);
	if (jrefGeom == comp->jrefGeom) insert(items, JREFGEOM);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);

	return(items);
};

set<uint> CrdWzskScf::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGCAMERAMAT, JREFDLGLASERPOS, JREFDLGTTABLECOORD, JREFCONN, JREFGEOM, JREFHEADBAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskScf::Tag
 ******************************************************************************/

void CrdWzskScf::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskScf";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskScf";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdCmm", "Calibrate camera matrix ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTtc", "Calibrate turntable coordinates ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLsp", "Calibrate line laser positions ...");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdCmm", "Kameramatrix kalibrieren ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTtc", "Drehteller-Koordinaten kalibrieren ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLsp", "Linienlaser-Positionen kalibrieren ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::HELP, ixWzskVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskScf::DpchAppDo
 ******************************************************************************/

CrdWzskScf::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSCFDO)
		{
	ixVDo = 0;
};

string CrdWzskScf::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskScf::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskScfDo");
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
 class CrdWzskScf::DpchEngData
 ******************************************************************************/

CrdWzskScf::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSCFDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWzskScf::DpchEngData::getSrefsMask() {
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

void CrdWzskScf::DpchEngData::merge(
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

void CrdWzskScf::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskScfData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

