/**
	* \file PnlWzskOgrSup1NObjgroup_blks.cpp
	* job handler for job PnlWzskOgrSup1NObjgroup (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskOgrSup1NObjgroup::VecVDo
 ******************************************************************************/

uint PnlWzskOgrSup1NObjgroup::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWzskOgrSup1NObjgroup::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWzskOgrSup1NObjgroup::ContInf
 ******************************************************************************/

PnlWzskOgrSup1NObjgroup::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlWzskOgrSup1NObjgroup::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskOgrSup1NObjgroup";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFCsiQst"] = numFCsiQst;
};

void PnlWzskOgrSup1NObjgroup::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskOgrSup1NObjgroup";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskOgrSup1NObjgroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskOgrSup1NObjgroup::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWzskOgrSup1NObjgroup::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskOgrSup1NObjgroup::StatApp
 ******************************************************************************/

void PnlWzskOgrSup1NObjgroup::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzskVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskOgrSup1NObjgroup";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
};

void PnlWzskOgrSup1NObjgroup::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskOgrSup1NObjgroup";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskOgrSup1NObjgroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskOgrSup1NObjgroup::StatShr
 ******************************************************************************/

PnlWzskOgrSup1NObjgroup::StatShr::StatShr(
			const bool ButViewAvail
			, const bool ButViewActive
		) :
			Block()
		{
	this->ButViewAvail = ButViewAvail;
	this->ButViewActive = ButViewActive;

	mask = {BUTVIEWAVAIL, BUTVIEWACTIVE};
};

void PnlWzskOgrSup1NObjgroup::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskOgrSup1NObjgroup";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButViewAvail"] = ButViewAvail;
	me["ButViewActive"] = ButViewActive;
};

void PnlWzskOgrSup1NObjgroup::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskOgrSup1NObjgroup";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskOgrSup1NObjgroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButViewAvail", ButViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButViewActive", ButViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskOgrSup1NObjgroup::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewAvail == comp->ButViewAvail) insert(items, BUTVIEWAVAIL);
	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);

	return(items);
};

set<uint> PnlWzskOgrSup1NObjgroup::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWAVAIL, BUTVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskOgrSup1NObjgroup::StgIac
 ******************************************************************************/

PnlWzskOgrSup1NObjgroup::StgIac::StgIac(
			const uint TcoRefWidth
		) :
			Block()
		{
	this->TcoRefWidth = TcoRefWidth;
	mask = {TCOREFWIDTH};
};

bool PnlWzskOgrSup1NObjgroup::StgIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["StgIacWzskOgrSup1NObjgroup"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoRefWidth")) {TcoRefWidth = me["TcoRefWidth"].asUInt(); add(TCOREFWIDTH);};
	};

	return basefound;
};

bool PnlWzskOgrSup1NObjgroup::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWzskOgrSup1NObjgroup");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWzskOgrSup1NObjgroup";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRefWidth", TcoRefWidth)) add(TCOREFWIDTH);
	};

	return basefound;
};

void PnlWzskOgrSup1NObjgroup::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacWzskOgrSup1NObjgroup";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoRefWidth"] = TcoRefWidth;
};

void PnlWzskOgrSup1NObjgroup::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWzskOgrSup1NObjgroup";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWzskOgrSup1NObjgroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoRefWidth", TcoRefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskOgrSup1NObjgroup::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoRefWidth == comp->TcoRefWidth) insert(items, TCOREFWIDTH);

	return(items);
};

set<uint> PnlWzskOgrSup1NObjgroup::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOREFWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskOgrSup1NObjgroup::Tag
 ******************************************************************************/

void PnlWzskOgrSup1NObjgroup::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskOgrSup1NObjgroup";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Sub-groups";
		me["TcoRef"] = "Object group";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["Cpt"] = "Untergruppen";
		me["TcoRef"] = "Objektgruppe";
	};
	me["TxtRecord1"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::REC, ixWzskVLocale));
	me["TxtRecord2"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::EMPLONG, ixWzskVLocale));
	me["Trs"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::GOTO, ixWzskVLocale)) + " ...";
	me["TxtShowing1"] = VecWzskVTag::getTitle(VecWzskVTag::SHOWSHORT, ixWzskVLocale);
	me["TxtShowing2"] = VecWzskVTag::getTitle(VecWzskVTag::EMPSHORT, ixWzskVLocale);
};

void PnlWzskOgrSup1NObjgroup::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskOgrSup1NObjgroup";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskOgrSup1NObjgroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Sub-groups");
			writeStringAttr(wr, itemtag, "sref", "TcoRef", "Object group");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Untergruppen");
			writeStringAttr(wr, itemtag, "sref", "TcoRef", "Objektgruppe");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::REC, ixWzskVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::EMPLONG, ixWzskVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::GOTO, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecWzskVTag::getTitle(VecWzskVTag::SHOWSHORT, ixWzskVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecWzskVTag::getTitle(VecWzskVTag::EMPSHORT, ixWzskVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskOgrSup1NObjgroup::DpchAppData
 ******************************************************************************/

PnlWzskOgrSup1NObjgroup::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKOGRSUP1NOBJGROUPDATA)
		{
};

string PnlWzskOgrSup1NObjgroup::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskOgrSup1NObjgroup::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzskOgrSup1NObjgroupData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryWzskOgrSup1NObjgroup::StgIac();
	};
};

void PnlWzskOgrSup1NObjgroup::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskOgrSup1NObjgroupData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryWzskOgrSup1NObjgroup::StgIac();
	};
};

/******************************************************************************
 class PnlWzskOgrSup1NObjgroup::DpchAppDo
 ******************************************************************************/

PnlWzskOgrSup1NObjgroup::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKOGRSUP1NOBJGROUPDO)
		{
	ixVDo = 0;
};

string PnlWzskOgrSup1NObjgroup::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskOgrSup1NObjgroup::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzskOgrSup1NObjgroupDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskOgrSup1NObjgroup::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskOgrSup1NObjgroupDo");
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
 class PnlWzskOgrSup1NObjgroup::DpchEngData
 ******************************************************************************/

PnlWzskOgrSup1NObjgroup::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListWzskQOgrSup1NObjgroup* rst
			, QryWzskOgrSup1NObjgroup::StatShr* statshrqry
			, QryWzskOgrSup1NObjgroup::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKOGRSUP1NOBJGROUPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFCSIQST, STATAPP, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWzskOgrSup1NObjgroup::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskOgrSup1NObjgroup::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlWzskOgrSup1NObjgroup::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskOgrSup1NObjgroupData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryWzskOgrSup1NObjgroup::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlWzskOgrSup1NObjgroup::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskOgrSup1NObjgroupData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWzskOgrSup1NObjgroup::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
