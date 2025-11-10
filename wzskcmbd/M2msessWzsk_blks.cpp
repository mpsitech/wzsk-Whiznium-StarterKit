/**
	* \file M2msessWzsk_blks.cpp
	* job handler for job M2msessWzsk (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class M2msessWzsk::StatShr
 ******************************************************************************/

M2msessWzsk::StatShr::StatShr(
			const ubigint jrefAcqcorner
			, const ubigint jrefAcqtrace
			, const ubigint jrefActlaser
			, const ubigint jrefActrotary
			, const ubigint jrefSrcfpgainfo
			, const ubigint jrefSrcsysinfo
		) :
			Block()
			, jrefAcqcorner(jrefAcqcorner)
			, jrefAcqtrace(jrefAcqtrace)
			, jrefActlaser(jrefActlaser)
			, jrefActrotary(jrefActrotary)
			, jrefSrcfpgainfo(jrefSrcfpgainfo)
			, jrefSrcsysinfo(jrefSrcsysinfo)
		{
	mask = {JREFACQCORNER, JREFACQTRACE, JREFACTLASER, JREFACTROTARY, JREFSRCFPGAINFO, JREFSRCSYSINFO};
};

void M2msessWzsk::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrM2msessWzsk";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefAcqcorner"] = Scr::scramble(jrefAcqcorner);
	me["scrJrefAcqtrace"] = Scr::scramble(jrefAcqtrace);
	me["scrJrefActlaser"] = Scr::scramble(jrefActlaser);
	me["scrJrefActrotary"] = Scr::scramble(jrefActrotary);
	me["scrJrefSrcfpgainfo"] = Scr::scramble(jrefSrcfpgainfo);
	me["scrJrefSrcsysinfo"] = Scr::scramble(jrefSrcsysinfo);
};

void M2msessWzsk::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrM2msessWzsk";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrM2msessWzsk";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqcorner", Scr::scramble(jrefAcqcorner));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqtrace", Scr::scramble(jrefAcqtrace));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActlaser", Scr::scramble(jrefActlaser));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActrotary", Scr::scramble(jrefActrotary));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrcfpgainfo", Scr::scramble(jrefSrcfpgainfo));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrcsysinfo", Scr::scramble(jrefSrcsysinfo));
	xmlTextWriterEndElement(wr);
};

set<uint> M2msessWzsk::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefAcqcorner == comp->jrefAcqcorner) insert(items, JREFACQCORNER);
	if (jrefAcqtrace == comp->jrefAcqtrace) insert(items, JREFACQTRACE);
	if (jrefActlaser == comp->jrefActlaser) insert(items, JREFACTLASER);
	if (jrefActrotary == comp->jrefActrotary) insert(items, JREFACTROTARY);
	if (jrefSrcfpgainfo == comp->jrefSrcfpgainfo) insert(items, JREFSRCFPGAINFO);
	if (jrefSrcsysinfo == comp->jrefSrcsysinfo) insert(items, JREFSRCSYSINFO);

	return(items);
};

set<uint> M2msessWzsk::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFACQCORNER, JREFACQTRACE, JREFACTLASER, JREFACTROTARY, JREFSRCFPGAINFO, JREFSRCSYSINFO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class M2msessWzsk::DpchEngData
 ******************************************************************************/

M2msessWzsk::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGM2MSESSWZSKDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STATSHR};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string M2msessWzsk::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void M2msessWzsk::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
};

void M2msessWzsk::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngM2msessWzskData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STATSHR)) statshr.writeJSON(me);
};

void M2msessWzsk::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngM2msessWzskData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STATSHR)) statshr.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
