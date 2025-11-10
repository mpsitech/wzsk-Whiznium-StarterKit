/**
	* \file PnlWzskPrfAcqTrace_blks.cpp
	* job handler for job PnlWzskPrfAcqTrace (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfAcqTrace::VecVDo
 ******************************************************************************/

uint PnlWzskPrfAcqTrace::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfAcqTrace::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::ContIac
 ******************************************************************************/

PnlWzskPrfAcqTrace::ContIac::ContIac(
			const string& Txf1
			, const string& Txf2
			, const string& Txf3
			, const string& Txf4
		) :
			Block()
			, Txf1(Txf1)
			, Txf2(Txf2)
			, Txf3(Txf3)
			, Txf4(Txf4)
		{
	mask = {TXF1, TXF2, TXF3, TXF4};
};

bool PnlWzskPrfAcqTrace::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskPrfAcqTrace"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("Txf1")) {Txf1 = me["Txf1"].asString(); add(TXF1);};
		if (me.isMember("Txf2")) {Txf2 = me["Txf2"].asString(); add(TXF2);};
		if (me.isMember("Txf3")) {Txf3 = me["Txf3"].asString(); add(TXF3);};
		if (me.isMember("Txf4")) {Txf4 = me["Txf4"].asString(); add(TXF4);};
	};

	return basefound;
};

bool PnlWzskPrfAcqTrace::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfAcqTrace");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfAcqTrace";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf1", Txf1)) add(TXF1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf3", Txf3)) add(TXF3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf4", Txf4)) add(TXF4);
	};

	return basefound;
};

void PnlWzskPrfAcqTrace::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfAcqTrace";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["Txf1"] = Txf1;
	me["Txf2"] = Txf2;
	me["Txf3"] = Txf3;
	me["Txf4"] = Txf4;
};

void PnlWzskPrfAcqTrace::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfAcqTrace";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfAcqTrace";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf1", Txf1);
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
		writeStringAttr(wr, itemtag, "sref", "Txf3", Txf3);
		writeStringAttr(wr, itemtag, "sref", "Txf4", Txf4);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfAcqTrace::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf1 == comp->Txf1) insert(items, TXF1);
	if (Txf2 == comp->Txf2) insert(items, TXF2);
	if (Txf3 == comp->Txf3) insert(items, TXF3);
	if (Txf4 == comp->Txf4) insert(items, TXF4);

	return(items);
};

set<uint> PnlWzskPrfAcqTrace::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF1, TXF2, TXF3, TXF4};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::StatShr
 ******************************************************************************/

PnlWzskPrfAcqTrace::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Txf1Clean
			, const bool Txf2Clean
			, const bool Txf3Clean
			, const bool Txf4Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Txf1Clean(Txf1Clean)
			, Txf2Clean(Txf2Clean)
			, Txf3Clean(Txf3Clean)
			, Txf4Clean(Txf4Clean)
		{
	mask = {IXWZSKVEXPSTATE, TXF1CLEAN, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN};
};

void PnlWzskPrfAcqTrace::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrfAcqTrace";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["Txf1Clean"] = Txf1Clean;
	me["Txf2Clean"] = Txf2Clean;
	me["Txf3Clean"] = Txf3Clean;
	me["Txf4Clean"] = Txf4Clean;
};

void PnlWzskPrfAcqTrace::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrfAcqTrace";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskPrfAcqTrace";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "Txf1Clean", Txf1Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf2Clean", Txf2Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf3Clean", Txf3Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf4Clean", Txf4Clean);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfAcqTrace::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Txf1Clean == comp->Txf1Clean) insert(items, TXF1CLEAN);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);
	if (Txf3Clean == comp->Txf3Clean) insert(items, TXF3CLEAN);
	if (Txf4Clean == comp->Txf4Clean) insert(items, TXF4CLEAN);

	return(items);
};

set<uint> PnlWzskPrfAcqTrace::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, TXF1CLEAN, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::Tag
 ******************************************************************************/

void PnlWzskPrfAcqTrace::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrfAcqTrace";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "JobWzskAcqTrace settings";
		me["Cpt1"] = "row0";
		me["Cpt2"] = "col0";
		me["Cpt3"] = "w";
		me["Cpt4"] = "h";
	};
};

void PnlWzskPrfAcqTrace::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrfAcqTrace";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskPrfAcqTrace";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "JobWzskAcqTrace settings");
			writeStringAttr(wr, itemtag, "sref", "Cpt1", "row0");
			writeStringAttr(wr, itemtag, "sref", "Cpt2", "col0");
			writeStringAttr(wr, itemtag, "sref", "Cpt3", "w");
			writeStringAttr(wr, itemtag, "sref", "Cpt4", "h");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::DpchAppData
 ******************************************************************************/

PnlWzskPrfAcqTrace::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFACQTRACEDATA)
		{
};

string PnlWzskPrfAcqTrace::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqTrace::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskPrfAcqTraceData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskPrfAcqTrace::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrfAcqTraceData");
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
 class PnlWzskPrfAcqTrace::DpchAppDo
 ******************************************************************************/

PnlWzskPrfAcqTrace::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFACQTRACEDO)
		{
	ixVDo = 0;
};

string PnlWzskPrfAcqTrace::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqTrace::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskPrfAcqTraceDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskPrfAcqTrace::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrfAcqTraceDo");
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
 class PnlWzskPrfAcqTrace::DpchEngData
 ******************************************************************************/

PnlWzskPrfAcqTrace::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFACQTRACEDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskPrfAcqTrace::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqTrace::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskPrfAcqTrace::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskPrfAcqTraceData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskPrfAcqTrace::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskPrfAcqTraceData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
