/**
	* \file PnlWzskShtRef1NFile_blks.cpp
	* job handler for job PnlWzskShtRef1NFile (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskShtRef1NFile::VecVDo
 ******************************************************************************/

uint PnlWzskShtRef1NFile::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWzskShtRef1NFile::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWzskShtRef1NFile::ContInf
 ******************************************************************************/

PnlWzskShtRef1NFile::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlWzskShtRef1NFile::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskShtRef1NFile";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFCsiQst"] = numFCsiQst;
};

void PnlWzskShtRef1NFile::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskShtRef1NFile";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskShtRef1NFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskShtRef1NFile::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWzskShtRef1NFile::ContInf::diff(
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
 class PnlWzskShtRef1NFile::StatApp
 ******************************************************************************/

void PnlWzskShtRef1NFile::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzskVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskShtRef1NFile";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
};

void PnlWzskShtRef1NFile::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskShtRef1NFile";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskShtRef1NFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskShtRef1NFile::StatShr
 ******************************************************************************/

PnlWzskShtRef1NFile::StatShr::StatShr(
			const bool ButViewAvail
			, const bool ButViewActive
			, const bool ButNewAvail
			, const bool ButDeleteAvail
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ButViewAvail = ButViewAvail;
	this->ButViewActive = ButViewActive;
	this->ButNewAvail = ButNewAvail;
	this->ButDeleteAvail = ButDeleteAvail;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTNEWAVAIL, BUTDELETEAVAIL, BUTDELETEACTIVE};
};

void PnlWzskShtRef1NFile::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskShtRef1NFile";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButViewAvail"] = ButViewAvail;
	me["ButViewActive"] = ButViewActive;
	me["ButNewAvail"] = ButNewAvail;
	me["ButDeleteAvail"] = ButDeleteAvail;
	me["ButDeleteActive"] = ButDeleteActive;
};

void PnlWzskShtRef1NFile::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskShtRef1NFile";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskShtRef1NFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButViewAvail", ButViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButViewActive", ButViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButNewAvail", ButNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteAvail", ButDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskShtRef1NFile::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewAvail == comp->ButViewAvail) insert(items, BUTVIEWAVAIL);
	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButNewAvail == comp->ButNewAvail) insert(items, BUTNEWAVAIL);
	if (ButDeleteAvail == comp->ButDeleteAvail) insert(items, BUTDELETEAVAIL);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWzskShtRef1NFile::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTNEWAVAIL, BUTDELETEAVAIL, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskShtRef1NFile::StgIac
 ******************************************************************************/

PnlWzskShtRef1NFile::StgIac::StgIac(
			const uint TcoRefWidth
		) :
			Block()
		{
	this->TcoRefWidth = TcoRefWidth;
	mask = {TCOREFWIDTH};
};

bool PnlWzskShtRef1NFile::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacWzskShtRef1NFile"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoRefWidth")) {TcoRefWidth = me["TcoRefWidth"].asUInt(); add(TCOREFWIDTH);};
	};

	return basefound;
};

bool PnlWzskShtRef1NFile::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWzskShtRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWzskShtRef1NFile";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRefWidth", TcoRefWidth)) add(TCOREFWIDTH);
	};

	return basefound;
};

void PnlWzskShtRef1NFile::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacWzskShtRef1NFile";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoRefWidth"] = TcoRefWidth;
};

void PnlWzskShtRef1NFile::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWzskShtRef1NFile";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWzskShtRef1NFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoRefWidth", TcoRefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskShtRef1NFile::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoRefWidth == comp->TcoRefWidth) insert(items, TCOREFWIDTH);

	return(items);
};

set<uint> PnlWzskShtRef1NFile::StgIac::diff(
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
 class PnlWzskShtRef1NFile::Tag
 ******************************************************************************/

void PnlWzskShtRef1NFile::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskShtRef1NFile";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Files";
		me["TcoRef"] = "File";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["Cpt"] = "Dateien";
		me["TcoRef"] = "Datei";
	};
	me["TxtRecord1"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::REC, ixWzskVLocale));
	me["TxtRecord2"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::EMPLONG, ixWzskVLocale));
	me["Trs"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::GOTO, ixWzskVLocale)) + " ...";
	me["TxtShowing1"] = VecWzskVTag::getTitle(VecWzskVTag::SHOWSHORT, ixWzskVLocale);
	me["TxtShowing2"] = VecWzskVTag::getTitle(VecWzskVTag::EMPSHORT, ixWzskVLocale);
};

void PnlWzskShtRef1NFile::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskShtRef1NFile";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskShtRef1NFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Files");
			writeStringAttr(wr, itemtag, "sref", "TcoRef", "File");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Dateien");
			writeStringAttr(wr, itemtag, "sref", "TcoRef", "Datei");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::REC, ixWzskVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::EMPLONG, ixWzskVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::GOTO, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecWzskVTag::getTitle(VecWzskVTag::SHOWSHORT, ixWzskVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecWzskVTag::getTitle(VecWzskVTag::EMPSHORT, ixWzskVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskShtRef1NFile::DpchAppData
 ******************************************************************************/

PnlWzskShtRef1NFile::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSHTREF1NFILEDATA)
		{
};

string PnlWzskShtRef1NFile::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskShtRef1NFile::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskShtRef1NFileData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryWzskShtRef1NFile::StgIac();
	};
};

void PnlWzskShtRef1NFile::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskShtRef1NFileData");
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
		stgiacqry = QryWzskShtRef1NFile::StgIac();
	};
};

/******************************************************************************
 class PnlWzskShtRef1NFile::DpchAppDo
 ******************************************************************************/

PnlWzskShtRef1NFile::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSHTREF1NFILEDO)
		{
	ixVDo = 0;
};

string PnlWzskShtRef1NFile::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskShtRef1NFile::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskShtRef1NFileDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskShtRef1NFile::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskShtRef1NFileDo");
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
 class PnlWzskShtRef1NFile::DpchEngData
 ******************************************************************************/

PnlWzskShtRef1NFile::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListWzskQShtRef1NFile* rst
			, QryWzskShtRef1NFile::StatShr* statshrqry
			, QryWzskShtRef1NFile::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSHTREF1NFILEDATA, jref)
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

string PnlWzskShtRef1NFile::DpchEngData::getSrefsMask() {
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

void PnlWzskShtRef1NFile::DpchEngData::merge(
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

void PnlWzskShtRef1NFile::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskShtRef1NFileData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryWzskShtRef1NFile::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlWzskShtRef1NFile::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskShtRef1NFileData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWzskShtRef1NFile::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
