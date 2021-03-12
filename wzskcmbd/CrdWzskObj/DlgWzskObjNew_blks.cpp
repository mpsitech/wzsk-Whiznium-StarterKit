/**
	* \file DlgWzskObjNew_blks.cpp
	* job handler for job DlgWzskObjNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWzskObjNew::VecVDo
 ******************************************************************************/

uint DlgWzskObjNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWzskObjNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWzskObjNew::VecVSge
 ******************************************************************************/

uint DlgWzskObjNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWzskObjNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == DONE) return("done");

	return("");
};

void DlgWzskObjNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWzskObjNew::ContIac
 ******************************************************************************/

DlgWzskObjNew::ContIac::ContIac(
			const uint numFPupOgr
			, const string& TxfTit
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupOgr = numFPupOgr;
	this->TxfTit = TxfTit;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPOGR, TXFTIT, TXFCMT};
};

bool DlgWzskObjNew::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacDlgWzskObjNew"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupOgr")) {numFPupOgr = me["numFPupOgr"].asUInt(); add(NUMFPUPOGR);};
		if (me.isMember("TxfTit")) {TxfTit = me["TxfTit"].asString(); add(TXFTIT);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool DlgWzskObjNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWzskObjNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWzskObjNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupOgr", numFPupOgr)) add(NUMFPUPOGR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void DlgWzskObjNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWzskObjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupOgr"] = numFPupOgr;
	me["TxfTit"] = TxfTit;
	me["TxfCmt"] = TxfCmt;
};

void DlgWzskObjNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWzskObjNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWzskObjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupOgr", numFPupOgr);
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWzskObjNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupOgr == comp->numFPupOgr) insert(items, NUMFPUPOGR);
	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> DlgWzskObjNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPOGR, TXFTIT, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWzskObjNew::ContInf
 ******************************************************************************/

DlgWzskObjNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWzskObjNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWzskObjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
};

void DlgWzskObjNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWzskObjNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWzskObjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWzskObjNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWzskObjNew::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWzskObjNew::StatApp
 ******************************************************************************/

void DlgWzskObjNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWzskObjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
};

void DlgWzskObjNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWzskObjNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWzskObjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWzskObjNew::StatShr
 ******************************************************************************/

DlgWzskObjNew::StatShr::StatShr(
			const bool ButCncActive
			, const bool ButCreActive
		) :
			Block()
		{
	this->ButCncActive = ButCncActive;
	this->ButCreActive = ButCreActive;

	mask = {BUTCNCACTIVE, BUTCREACTIVE};
};

void DlgWzskObjNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWzskObjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButCncActive"] = ButCncActive;
	me["ButCreActive"] = ButCreActive;
};

void DlgWzskObjNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWzskObjNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWzskObjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCncActive", ButCncActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWzskObjNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButCncActive == comp->ButCncActive) insert(items, BUTCNCACTIVE);
	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWzskObjNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCNCACTIVE, BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWzskObjNew::Tag
 ******************************************************************************/

void DlgWzskObjNew::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWzskObjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Create new object";
		me["CptOgr"] = "Object group";
		me["CptTit"] = "Name";
		me["CptCmt"] = "Comment";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["Cpt"] = "Neues Objekt anlegen";
		me["CptOgr"] = "Objektgruppe";
		me["CptTit"] = "Name";
		me["CptCmt"] = "Notiz";
	};
	me["ButCnc"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::CANCEL, ixWzskVLocale));
	me["ButCre"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::CREATE, ixWzskVLocale));
};

void DlgWzskObjNew::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWzskObjNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWzskObjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Create new object");
			writeStringAttr(wr, itemtag, "sref", "CptOgr", "Object group");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Comment");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Neues Objekt anlegen");
			writeStringAttr(wr, itemtag, "sref", "CptOgr", "Objektgruppe");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Notiz");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCnc", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::CANCEL, ixWzskVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::CREATE, ixWzskVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWzskObjNew::DpchAppData
 ******************************************************************************/

DlgWzskObjNew::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPDLGWZSKOBJNEWDATA)
		{
};

string DlgWzskObjNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWzskObjNew::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWzskObjNewData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgWzskObjNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWzskObjNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class DlgWzskObjNew::DpchAppDo
 ******************************************************************************/

DlgWzskObjNew::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPDLGWZSKOBJNEWDO)
		{
	ixVDo = 0;
};

string DlgWzskObjNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWzskObjNew::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWzskObjNewDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWzskObjNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWzskObjNewDo");
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
 class DlgWzskObjNew::DpchEngData
 ******************************************************************************/

DlgWzskObjNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupOgr
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGDLGWZSKOBJNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPOGR, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPOGR) && feedFPupOgr) this->feedFPupOgr = *feedFPupOgr;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWzskObjNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPOGR)) ss.push_back("feedFPupOgr");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWzskObjNew::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPOGR)) {feedFPupOgr = src->feedFPupOgr; add(FEEDFPUPOGR);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWzskObjNew::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWzskObjNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPOGR)) feedFPupOgr.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void DlgWzskObjNew::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWzskObjNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPOGR)) feedFPupOgr.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
