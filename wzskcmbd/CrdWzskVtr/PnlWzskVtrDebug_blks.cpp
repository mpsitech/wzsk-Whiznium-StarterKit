/**
	* \file PnlWzskVtrDebug_blks.cpp
	* job handler for job PnlWzskVtrDebug (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskVtrDebug::VecVDo
 ******************************************************************************/

uint PnlWzskVtrDebug::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;
	if (s == "buttsrclick") return BUTTSRCLICK;
	if (s == "buttspclick") return BUTTSPCLICK;
	if (s == "butttfviewclick") return BUTTTFVIEWCLICK;

	return(0);
};

string PnlWzskVtrDebug::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTTSRCLICK) return("ButTsrClick");
	if (ix == BUTTSPCLICK) return("ButTspClick");
	if (ix == BUTTTFVIEWCLICK) return("ButTtfViewClick");

	return("");
};

/******************************************************************************
 class PnlWzskVtrDebug::ContIac
 ******************************************************************************/

PnlWzskVtrDebug::ContIac::ContIac(
			const string& TxfTfr
		) :
			Block()
			, TxfTfr(TxfTfr)
		{
	mask = {TXFTFR};
};

bool PnlWzskVtrDebug::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskVtrDebug"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfTfr")) {TxfTfr = me["TxfTfr"].asString(); add(TXFTFR);};
	};

	return basefound;
};

bool PnlWzskVtrDebug::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskVtrDebug");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskVtrDebug";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTfr", TxfTfr)) add(TXFTFR);
	};

	return basefound;
};

void PnlWzskVtrDebug::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskVtrDebug";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfTfr"] = TxfTfr;
};

void PnlWzskVtrDebug::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskVtrDebug";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskVtrDebug";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTfr", TxfTfr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskVtrDebug::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTfr == comp->TxfTfr) insert(items, TXFTFR);

	return(items);
};

set<uint> PnlWzskVtrDebug::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTFR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskVtrDebug::ContInf
 ******************************************************************************/

PnlWzskVtrDebug::ContInf::ContInf(
			const bool ButClaimOn
			, const string& TxtTst
			, const string& TxtTtf
		) :
			Block()
			, ButClaimOn(ButClaimOn)
			, TxtTst(TxtTst)
			, TxtTtf(TxtTtf)
		{
	mask = {BUTCLAIMON, TXTTST, TXTTTF};
};

void PnlWzskVtrDebug::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskVtrDebug";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButClaimOn"] = ButClaimOn;
	me["TxtTst"] = TxtTst;
	me["TxtTtf"] = TxtTtf;
};

void PnlWzskVtrDebug::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskVtrDebug";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskVtrDebug";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButClaimOn", ButClaimOn);
		writeStringAttr(wr, itemtag, "sref", "TxtTst", TxtTst);
		writeStringAttr(wr, itemtag, "sref", "TxtTtf", TxtTtf);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskVtrDebug::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtTst == comp->TxtTst) insert(items, TXTTST);
	if (TxtTtf == comp->TxtTtf) insert(items, TXTTTF);

	return(items);
};

set<uint> PnlWzskVtrDebug::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCLAIMON, TXTTST, TXTTTF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskVtrDebug::StatShr
 ******************************************************************************/

PnlWzskVtrDebug::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool TxfTfrActive
			, const bool ButTsrActive
			, const bool ButTspActive
			, const bool ButTtfViewActive
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, ButClaimActive(ButClaimActive)
			, TxfTfrActive(TxfTfrActive)
			, ButTsrActive(ButTsrActive)
			, ButTspActive(ButTspActive)
			, ButTtfViewActive(ButTtfViewActive)
		{
	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, TXFTFRACTIVE, BUTTSRACTIVE, BUTTSPACTIVE, BUTTTFVIEWACTIVE};
};

void PnlWzskVtrDebug::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskVtrDebug";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["ButClaimActive"] = ButClaimActive;
	me["TxfTfrActive"] = TxfTfrActive;
	me["ButTsrActive"] = ButTsrActive;
	me["ButTspActive"] = ButTspActive;
	me["ButTtfViewActive"] = ButTtfViewActive;
};

void PnlWzskVtrDebug::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskVtrDebug";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskVtrDebug";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButClaimActive", ButClaimActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTfrActive", TxfTfrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTsrActive", ButTsrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTspActive", ButTspActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTtfViewActive", ButTtfViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskVtrDebug::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (TxfTfrActive == comp->TxfTfrActive) insert(items, TXFTFRACTIVE);
	if (ButTsrActive == comp->ButTsrActive) insert(items, BUTTSRACTIVE);
	if (ButTspActive == comp->ButTspActive) insert(items, BUTTSPACTIVE);
	if (ButTtfViewActive == comp->ButTtfViewActive) insert(items, BUTTTFVIEWACTIVE);

	return(items);
};

set<uint> PnlWzskVtrDebug::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, TXFTFRACTIVE, BUTTSRACTIVE, BUTTSPACTIVE, BUTTTFVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskVtrDebug::Tag
 ******************************************************************************/

void PnlWzskVtrDebug::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskVtrDebug";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Debug";
		me["HdgTrk"] = "CPU-FPGA signal track acquisition";
		me["CptTfr"] = "track file root";
		me["CptTst"] = "state";
		me["ButTsr"] = "Start";
		me["ButTsp"] = "Stop";
		me["CptTtf"] = "track file";
	};
};

void PnlWzskVtrDebug::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskVtrDebug";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskVtrDebug";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Debug");
			writeStringAttr(wr, itemtag, "sref", "HdgTrk", "CPU-FPGA signal track acquisition");
			writeStringAttr(wr, itemtag, "sref", "CptTfr", "track file root");
			writeStringAttr(wr, itemtag, "sref", "CptTst", "state");
			writeStringAttr(wr, itemtag, "sref", "ButTsr", "Start");
			writeStringAttr(wr, itemtag, "sref", "ButTsp", "Stop");
			writeStringAttr(wr, itemtag, "sref", "CptTtf", "track file");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrDebug::DpchAppData
 ******************************************************************************/

PnlWzskVtrDebug::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRDEBUGDATA)
		{
};

string PnlWzskVtrDebug::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrDebug::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskVtrDebugData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskVtrDebug::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskVtrDebugData");
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
 class PnlWzskVtrDebug::DpchAppDo
 ******************************************************************************/

PnlWzskVtrDebug::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRDEBUGDO)
		{
	ixVDo = 0;
};

string PnlWzskVtrDebug::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrDebug::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskVtrDebugDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskVtrDebug::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskVtrDebugDo");
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
 class PnlWzskVtrDebug::DpchEngData
 ******************************************************************************/

PnlWzskVtrDebug::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRDEBUGDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskVtrDebug::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrDebug::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskVtrDebug::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskVtrDebugData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskVtrDebug::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskVtrDebugData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
