/**
	* \file PnlWzskVtrMonitor_blks.cpp
	* job handler for job PnlWzskVtrMonitor (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskVtrMonitor::VecVDo
 ******************************************************************************/

uint PnlWzskVtrMonitor::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskVtrMonitor::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskVtrMonitor::StatShr
 ******************************************************************************/

PnlWzskVtrMonitor::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const uint CusAplHeight
			, const uint CusVplHeight
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, CusAplHeight(CusAplHeight)
			, CusVplHeight(CusVplHeight)
		{
	mask = {IXWZSKVEXPSTATE, CUSAPLHEIGHT, CUSVPLHEIGHT};
};

void PnlWzskVtrMonitor::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskVtrMonitor";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["CusAplHeight"] = (Json::Value::UInt) CusAplHeight;
	me["CusVplHeight"] = (Json::Value::UInt) CusVplHeight;
};

void PnlWzskVtrMonitor::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskVtrMonitor";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskVtrMonitor";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeUintAttr(wr, itemtag, "sref", "CusAplHeight", CusAplHeight);
		writeUintAttr(wr, itemtag, "sref", "CusVplHeight", CusVplHeight);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskVtrMonitor::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (CusAplHeight == comp->CusAplHeight) insert(items, CUSAPLHEIGHT);
	if (CusVplHeight == comp->CusVplHeight) insert(items, CUSVPLHEIGHT);

	return(items);
};

set<uint> PnlWzskVtrMonitor::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, CUSAPLHEIGHT, CUSVPLHEIGHT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskVtrMonitor::Tag
 ******************************************************************************/

void PnlWzskVtrMonitor::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskVtrMonitor";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Monitor";
		me["CptAplTme"] = "time [s]";
		me["CptAplAng"] = "angle [\\u00b0]";
		me["CptVplTme"] = "time [s]";
		me["CptVplAng"] = "ang. velocity [\\u00b0/s]";
	};
};

void PnlWzskVtrMonitor::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskVtrMonitor";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskVtrMonitor";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Monitor");
			writeStringAttr(wr, itemtag, "sref", "CptAplTme", "time [s]");
			writeStringAttr(wr, itemtag, "sref", "CptAplAng", "angle [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptVplTme", "time [s]");
			writeStringAttr(wr, itemtag, "sref", "CptVplAng", "ang. velocity [\\u00b0/s]");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrMonitor::DpchAppDo
 ******************************************************************************/

PnlWzskVtrMonitor::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRMONITORDO)
		{
	ixVDo = 0;
};

string PnlWzskVtrMonitor::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrMonitor::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskVtrMonitorDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskVtrMonitor::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskVtrMonitorDo");
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
 class PnlWzskVtrMonitor::DpchEngData
 ******************************************************************************/

PnlWzskVtrMonitor::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRMONITORDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskVtrMonitor::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrMonitor::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskVtrMonitor::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskVtrMonitorData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskVtrMonitor::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskVtrMonitorData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrMonitor::DpchEngLive
 ******************************************************************************/

PnlWzskVtrMonitor::DpchEngLive::DpchEngLive(
			const ubigint jref
			, const vector<float>& ts
			, const vector<float>& phis
			, const float phiMin
			, const float phiMax
			, const vector<float>& omegas
			, const float omegaMin
			, const float omegaMax
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRMONITORLIVE, jref)
			, ts(ts)
			, phis(phis)
			, phiMin(phiMin)
			, phiMax(phiMax)
			, omegas(omegas)
			, omegaMin(omegaMin)
			, omegaMax(omegaMax)
		{
	if (find(mask, ALL)) this->mask = {JREF, TS, PHIS, PHIMIN, PHIMAX, OMEGAS, OMEGAMIN, OMEGAMAX};
	else this->mask = mask;

};

string PnlWzskVtrMonitor::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(TS)) ss.push_back("ts");
	if (has(PHIS)) ss.push_back("phis");
	if (has(PHIMIN)) ss.push_back("phiMin");
	if (has(PHIMAX)) ss.push_back("phiMax");
	if (has(OMEGAS)) ss.push_back("omegas");
	if (has(OMEGAMIN)) ss.push_back("omegaMin");
	if (has(OMEGAMAX)) ss.push_back("omegaMax");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrMonitor::DpchEngLive::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(TS)) {ts = src->ts; add(TS);};
	if (src->has(PHIS)) {phis = src->phis; add(PHIS);};
	if (src->has(PHIMIN)) {phiMin = src->phiMin; add(PHIMIN);};
	if (src->has(PHIMAX)) {phiMax = src->phiMax; add(PHIMAX);};
	if (src->has(OMEGAS)) {omegas = src->omegas; add(OMEGAS);};
	if (src->has(OMEGAMIN)) {omegaMin = src->omegaMin; add(OMEGAMIN);};
	if (src->has(OMEGAMAX)) {omegaMax = src->omegaMax; add(OMEGAMAX);};
};

void PnlWzskVtrMonitor::DpchEngLive::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskVtrMonitorLive"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(TS)) Jsonio::writeFloatvec(me, "ts", ts);
	if (has(PHIS)) Jsonio::writeFloatvec(me, "phis", phis);
	if (has(PHIMIN)) me["phiMin"] = phiMin;
	if (has(PHIMAX)) me["phiMax"] = phiMax;
	if (has(OMEGAS)) Jsonio::writeFloatvec(me, "omegas", omegas);
	if (has(OMEGAMIN)) me["omegaMin"] = omegaMin;
	if (has(OMEGAMAX)) me["omegaMax"] = omegaMax;
};

void PnlWzskVtrMonitor::DpchEngLive::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskVtrMonitorLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(TS)) writeFloatvec(wr, "ts", ts);
		if (has(PHIS)) writeFloatvec(wr, "phis", phis);
		if (has(PHIMIN)) writeFloat(wr, "phiMin", phiMin);
		if (has(PHIMAX)) writeFloat(wr, "phiMax", phiMax);
		if (has(OMEGAS)) writeFloatvec(wr, "omegas", omegas);
		if (has(OMEGAMIN)) writeFloat(wr, "omegaMin", omegaMin);
		if (has(OMEGAMAX)) writeFloat(wr, "omegaMax", omegaMax);
	xmlTextWriterEndElement(wr);
};
