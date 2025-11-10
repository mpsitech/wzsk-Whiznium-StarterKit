/**
	* \file PnlWzskPrfGlobal_blks.cpp
	* job handler for job PnlWzskPrfGlobal (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfGlobal::VecVDo
 ******************************************************************************/

uint PnlWzskPrfGlobal::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfGlobal::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfGlobal::ContIac
 ******************************************************************************/

PnlWzskPrfGlobal::ContIac::ContIac(
			const string& Txf2
			, const string& Txf3
			, const string& Txf4
			, const string& Txf5
			, const string& Txf6
			, const uint numFPup102
		) :
			Block()
			, Txf2(Txf2)
			, Txf3(Txf3)
			, Txf4(Txf4)
			, Txf5(Txf5)
			, Txf6(Txf6)
			, numFPup102(numFPup102)
		{
	mask = {TXF2, TXF3, TXF4, TXF5, TXF6, NUMFPUP102};
};

bool PnlWzskPrfGlobal::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskPrfGlobal"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("Txf2")) {Txf2 = me["Txf2"].asString(); add(TXF2);};
		if (me.isMember("Txf3")) {Txf3 = me["Txf3"].asString(); add(TXF3);};
		if (me.isMember("Txf4")) {Txf4 = me["Txf4"].asString(); add(TXF4);};
		if (me.isMember("Txf5")) {Txf5 = me["Txf5"].asString(); add(TXF5);};
		if (me.isMember("Txf6")) {Txf6 = me["Txf6"].asString(); add(TXF6);};
		if (me.isMember("numFPup102")) {numFPup102 = me["numFPup102"].asUInt(); add(NUMFPUP102);};
	};

	return basefound;
};

bool PnlWzskPrfGlobal::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf3", Txf3)) add(TXF3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf4", Txf4)) add(TXF4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf5", Txf5)) add(TXF5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf6", Txf6)) add(TXF6);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPup102", numFPup102)) add(NUMFPUP102);
	};

	return basefound;
};

void PnlWzskPrfGlobal::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["Txf2"] = Txf2;
	me["Txf3"] = Txf3;
	me["Txf4"] = Txf4;
	me["Txf5"] = Txf5;
	me["Txf6"] = Txf6;
	me["numFPup102"] = (Json::Value::UInt) numFPup102;
};

void PnlWzskPrfGlobal::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
		writeStringAttr(wr, itemtag, "sref", "Txf3", Txf3);
		writeStringAttr(wr, itemtag, "sref", "Txf4", Txf4);
		writeStringAttr(wr, itemtag, "sref", "Txf5", Txf5);
		writeStringAttr(wr, itemtag, "sref", "Txf6", Txf6);
		writeUintAttr(wr, itemtag, "sref", "numFPup102", numFPup102);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfGlobal::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf2 == comp->Txf2) insert(items, TXF2);
	if (Txf3 == comp->Txf3) insert(items, TXF3);
	if (Txf4 == comp->Txf4) insert(items, TXF4);
	if (Txf5 == comp->Txf5) insert(items, TXF5);
	if (Txf6 == comp->Txf6) insert(items, TXF6);
	if (numFPup102 == comp->numFPup102) insert(items, NUMFPUP102);

	return(items);
};

set<uint> PnlWzskPrfGlobal::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF2, TXF3, TXF4, TXF5, TXF6, NUMFPUP102};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfGlobal::StatShr
 ******************************************************************************/

PnlWzskPrfGlobal::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Txf2Clean
			, const bool Txf3Clean
			, const bool Txf4Clean
			, const bool Txf5Clean
			, const bool Txf6Clean
			, const bool Pup102Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Txf2Clean(Txf2Clean)
			, Txf3Clean(Txf3Clean)
			, Txf4Clean(Txf4Clean)
			, Txf5Clean(Txf5Clean)
			, Txf6Clean(Txf6Clean)
			, Pup102Clean(Pup102Clean)
		{
	mask = {IXWZSKVEXPSTATE, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, PUP102CLEAN};
};

void PnlWzskPrfGlobal::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrfGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["Txf2Clean"] = Txf2Clean;
	me["Txf3Clean"] = Txf3Clean;
	me["Txf4Clean"] = Txf4Clean;
	me["Txf5Clean"] = Txf5Clean;
	me["Txf6Clean"] = Txf6Clean;
	me["Pup102Clean"] = Pup102Clean;
};

void PnlWzskPrfGlobal::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrfGlobal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskPrfGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "Txf2Clean", Txf2Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf3Clean", Txf3Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf4Clean", Txf4Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf5Clean", Txf5Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf6Clean", Txf6Clean);
		writeBoolAttr(wr, itemtag, "sref", "Pup102Clean", Pup102Clean);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfGlobal::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);
	if (Txf3Clean == comp->Txf3Clean) insert(items, TXF3CLEAN);
	if (Txf4Clean == comp->Txf4Clean) insert(items, TXF4CLEAN);
	if (Txf5Clean == comp->Txf5Clean) insert(items, TXF5CLEAN);
	if (Txf6Clean == comp->Txf6Clean) insert(items, TXF6CLEAN);
	if (Pup102Clean == comp->Pup102Clean) insert(items, PUP102CLEAN);

	return(items);
};

set<uint> PnlWzskPrfGlobal::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, PUP102CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfGlobal::Tag
 ******************************************************************************/

void PnlWzskPrfGlobal::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrfGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Global settings";
		me["Hdg1"] = "StgWzskCamera";
		me["Cpt2"] = "hpix";
		me["Cpt3"] = "f";
		me["Cpt4"] = "fn";
		me["Cpt5"] = "NColRaw";
		me["Cpt6"] = "NRowRaw";
		me["Hdg101"] = "StgWzskGlobal";
		me["Cpt102"] = "ixWzskVTarget";
	};
};

void PnlWzskPrfGlobal::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrfGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskPrfGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Global settings");
			writeStringAttr(wr, itemtag, "sref", "Hdg1", "StgWzskCamera");
			writeStringAttr(wr, itemtag, "sref", "Cpt2", "hpix");
			writeStringAttr(wr, itemtag, "sref", "Cpt3", "f");
			writeStringAttr(wr, itemtag, "sref", "Cpt4", "fn");
			writeStringAttr(wr, itemtag, "sref", "Cpt5", "NColRaw");
			writeStringAttr(wr, itemtag, "sref", "Cpt6", "NRowRaw");
			writeStringAttr(wr, itemtag, "sref", "Hdg101", "StgWzskGlobal");
			writeStringAttr(wr, itemtag, "sref", "Cpt102", "ixWzskVTarget");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfGlobal::DpchAppData
 ******************************************************************************/

PnlWzskPrfGlobal::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFGLOBALDATA)
		{
};

string PnlWzskPrfGlobal::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfGlobal::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskPrfGlobalData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskPrfGlobal::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrfGlobalData");
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
 class PnlWzskPrfGlobal::DpchAppDo
 ******************************************************************************/

PnlWzskPrfGlobal::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFGLOBALDO)
		{
	ixVDo = 0;
};

string PnlWzskPrfGlobal::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfGlobal::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskPrfGlobalDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskPrfGlobal::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrfGlobalDo");
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
 class PnlWzskPrfGlobal::DpchEngData
 ******************************************************************************/

PnlWzskPrfGlobal::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFPup102
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFGLOBALDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFPUP102, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFPUP102) && feedFPup102) this->feedFPup102 = *feedFPup102;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskPrfGlobal::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFPUP102)) ss.push_back("feedFPup102");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfGlobal::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFPUP102)) {feedFPup102 = src->feedFPup102; add(FEEDFPUP102);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskPrfGlobal::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskPrfGlobalData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFPUP102)) feedFPup102.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskPrfGlobal::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskPrfGlobalData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFPUP102)) feedFPup102.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
