/**
	* \file PnlWzskLlvSysmon_blks.cpp
	* job handler for job PnlWzskLlvSysmon (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvSysmon::VecVDo
 ******************************************************************************/

uint PnlWzskLlvSysmon::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskLlvSysmon::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskLlvSysmon::ContInf
 ******************************************************************************/

PnlWzskLlvSysmon::ContInf::ContInf(
			const string& TxtCtp
			, const string& TxtDhr
			, const string& TxtDhw
			, const string& TxtDrr
			, const string& TxtDrw
		) :
			Block()
			, TxtCtp(TxtCtp)
			, TxtDhr(TxtDhr)
			, TxtDhw(TxtDhw)
			, TxtDrr(TxtDrr)
			, TxtDrw(TxtDrw)
		{
	mask = {TXTCTP, TXTDHR, TXTDHW, TXTDRR, TXTDRW};
};

void PnlWzskLlvSysmon::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLlvSysmon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtCtp"] = TxtCtp;
	me["TxtDhr"] = TxtDhr;
	me["TxtDhw"] = TxtDhw;
	me["TxtDrr"] = TxtDrr;
	me["TxtDrw"] = TxtDrw;
};

void PnlWzskLlvSysmon::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLlvSysmon";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskLlvSysmon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCtp", TxtCtp);
		writeStringAttr(wr, itemtag, "sref", "TxtDhr", TxtDhr);
		writeStringAttr(wr, itemtag, "sref", "TxtDhw", TxtDhw);
		writeStringAttr(wr, itemtag, "sref", "TxtDrr", TxtDrr);
		writeStringAttr(wr, itemtag, "sref", "TxtDrw", TxtDrw);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvSysmon::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtCtp == comp->TxtCtp) insert(items, TXTCTP);
	if (TxtDhr == comp->TxtDhr) insert(items, TXTDHR);
	if (TxtDhw == comp->TxtDhw) insert(items, TXTDHW);
	if (TxtDrr == comp->TxtDrr) insert(items, TXTDRR);
	if (TxtDrw == comp->TxtDrw) insert(items, TXTDRW);

	return(items);
};

set<uint> PnlWzskLlvSysmon::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCTP, TXTDHR, TXTDHW, TXTDRR, TXTDRW};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvSysmon::StatShr
 ******************************************************************************/

PnlWzskLlvSysmon::StatShr::StatShr(
			const uint ixWzskVExpstate
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
		{
	mask = {IXWZSKVEXPSTATE};
};

void PnlWzskLlvSysmon::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLlvSysmon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
};

void PnlWzskLlvSysmon::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLlvSysmon";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskLlvSysmon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvSysmon::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);

	return(items);
};

set<uint> PnlWzskLlvSysmon::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvSysmon::Tag
 ******************************************************************************/

void PnlWzskLlvSysmon::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskLlvSysmon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "System monitor";
		me["CptCtp"] = "CPU temperature [\\u00b0C]";
		me["CptPltTme"] = "time [s]";
		me["CptPltCld"] = "CPU load [\\u0025]";
		me["CptPltTot"] = "total";
		me["CptPltCor"] = "core";
		me["CptDhr"] = "HDR DDR read [MByte/s]";
		me["CptDhw"] = "HDR DDR write [MByte/s]";
		me["CptDrr"] = "render DDR read [MByte/s]";
		me["CptDrw"] = "render DDR write [MByte/s]";
	};
};

void PnlWzskLlvSysmon::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskLlvSysmon";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskLlvSysmon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "System monitor");
			writeStringAttr(wr, itemtag, "sref", "CptCtp", "CPU temperature [\\u00b0C]");
			writeStringAttr(wr, itemtag, "sref", "CptPltTme", "time [s]");
			writeStringAttr(wr, itemtag, "sref", "CptPltCld", "CPU load [\\u0025]");
			writeStringAttr(wr, itemtag, "sref", "CptPltTot", "total");
			writeStringAttr(wr, itemtag, "sref", "CptPltCor", "core");
			writeStringAttr(wr, itemtag, "sref", "CptDhr", "HDR DDR read [MByte/s]");
			writeStringAttr(wr, itemtag, "sref", "CptDhw", "HDR DDR write [MByte/s]");
			writeStringAttr(wr, itemtag, "sref", "CptDrr", "render DDR read [MByte/s]");
			writeStringAttr(wr, itemtag, "sref", "CptDrw", "render DDR write [MByte/s]");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvSysmon::DpchAppDo
 ******************************************************************************/

PnlWzskLlvSysmon::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVSYSMONDO)
		{
	ixVDo = 0;
};

string PnlWzskLlvSysmon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvSysmon::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskLlvSysmonDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskLlvSysmon::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLlvSysmonDo");
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
 class PnlWzskLlvSysmon::DpchEngData
 ******************************************************************************/

PnlWzskLlvSysmon::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVSYSMONDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskLlvSysmon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvSysmon::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskLlvSysmon::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskLlvSysmonData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskLlvSysmon::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLlvSysmonData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvSysmon::DpchEngLive
 ******************************************************************************/

PnlWzskLlvSysmon::DpchEngLive::DpchEngLive(
			const ubigint jref
			, const vector<float>& ts
			, const vector<float>& cldtots
			, const vector<float>& cld1s
			, const vector<float>& cld2s
			, const vector<float>& cld3s
			, const vector<float>& cld4s
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVSYSMONLIVE, jref)
			, ts(ts)
			, cldtots(cldtots)
			, cld1s(cld1s)
			, cld2s(cld2s)
			, cld3s(cld3s)
			, cld4s(cld4s)
		{
	if (find(mask, ALL)) this->mask = {JREF, TS, CLDTOTS, CLD1S, CLD2S, CLD3S, CLD4S};
	else this->mask = mask;

};

string PnlWzskLlvSysmon::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(TS)) ss.push_back("ts");
	if (has(CLDTOTS)) ss.push_back("cldtots");
	if (has(CLD1S)) ss.push_back("cld1s");
	if (has(CLD2S)) ss.push_back("cld2s");
	if (has(CLD3S)) ss.push_back("cld3s");
	if (has(CLD4S)) ss.push_back("cld4s");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvSysmon::DpchEngLive::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(TS)) {ts = src->ts; add(TS);};
	if (src->has(CLDTOTS)) {cldtots = src->cldtots; add(CLDTOTS);};
	if (src->has(CLD1S)) {cld1s = src->cld1s; add(CLD1S);};
	if (src->has(CLD2S)) {cld2s = src->cld2s; add(CLD2S);};
	if (src->has(CLD3S)) {cld3s = src->cld3s; add(CLD3S);};
	if (src->has(CLD4S)) {cld4s = src->cld4s; add(CLD4S);};
};

void PnlWzskLlvSysmon::DpchEngLive::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskLlvSysmonLive"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(TS)) Jsonio::writeFloatvec(me, "ts", ts);
	if (has(CLDTOTS)) Jsonio::writeFloatvec(me, "cldtots", cldtots);
	if (has(CLD1S)) Jsonio::writeFloatvec(me, "cld1s", cld1s);
	if (has(CLD2S)) Jsonio::writeFloatvec(me, "cld2s", cld2s);
	if (has(CLD3S)) Jsonio::writeFloatvec(me, "cld3s", cld3s);
	if (has(CLD4S)) Jsonio::writeFloatvec(me, "cld4s", cld4s);
};

void PnlWzskLlvSysmon::DpchEngLive::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLlvSysmonLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(TS)) writeFloatvec(wr, "ts", ts);
		if (has(CLDTOTS)) writeFloatvec(wr, "cldtots", cldtots);
		if (has(CLD1S)) writeFloatvec(wr, "cld1s", cld1s);
		if (has(CLD2S)) writeFloatvec(wr, "cld2s", cld2s);
		if (has(CLD3S)) writeFloatvec(wr, "cld3s", cld3s);
		if (has(CLD4S)) writeFloatvec(wr, "cld4s", cld4s);
	xmlTextWriterEndElement(wr);
};
