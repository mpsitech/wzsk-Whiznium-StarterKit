/**
	* \file SessWzsk_blks.cpp
	* job handler for job SessWzsk (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class SessWzsk::StatShr
 ******************************************************************************/

SessWzsk::StatShr::StatShr(
			const ubigint jrefCrdnav
		) :
			Block()
			, jrefCrdnav(jrefCrdnav)
		{
	mask = {JREFCRDNAV};
};

void SessWzsk::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrSessWzsk";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefCrdnav"] = Scr::scramble(jrefCrdnav);
};

void SessWzsk::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrSessWzsk";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrSessWzsk";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefCrdnav", Scr::scramble(jrefCrdnav));
	xmlTextWriterEndElement(wr);
};

set<uint> SessWzsk::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefCrdnav == comp->jrefCrdnav) insert(items, JREFCRDNAV);

	return(items);
};

set<uint> SessWzsk::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFCRDNAV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessWzsk::DpchEngData
 ******************************************************************************/

SessWzsk::DpchEngData::DpchEngData(
			const ubigint jref
			, Feed* feedFEnsSec
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGSESSWZSKDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, FEEDFENSSEC, STATSHR};
	else this->mask = mask;

	if (find(this->mask, FEEDFENSSEC) && feedFEnsSec) this->feedFEnsSec = *feedFEnsSec;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string SessWzsk::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(FEEDFENSSEC)) ss.push_back("feedFEnsSec");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void SessWzsk::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(FEEDFENSSEC)) {feedFEnsSec = src->feedFEnsSec; add(FEEDFENSSEC);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
};

void SessWzsk::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngSessWzskData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(FEEDFENSSEC)) feedFEnsSec.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
};

void SessWzsk::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngSessWzskData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(FEEDFENSSEC)) feedFEnsSec.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
