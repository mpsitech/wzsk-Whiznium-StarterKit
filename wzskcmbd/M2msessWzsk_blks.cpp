/**
	* \file M2msessWzsk_blks.cpp
	* job handler for job M2msessWzsk (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class M2msessWzsk::StatShr
 ******************************************************************************/

M2msessWzsk::StatShr::StatShr(
			const ubigint jrefAcqpreview
			, const ubigint jrefAcqptcloud
			, const ubigint jrefActexposure
			, const ubigint jrefActlaser
			, const ubigint jrefActservo
			, const ubigint jrefIprcorner
			, const ubigint jrefIprtrace
			, const ubigint jrefSrcsysinfo
		) :
			Block()
		{
	this->jrefAcqpreview = jrefAcqpreview;
	this->jrefAcqptcloud = jrefAcqptcloud;
	this->jrefActexposure = jrefActexposure;
	this->jrefActlaser = jrefActlaser;
	this->jrefActservo = jrefActservo;
	this->jrefIprcorner = jrefIprcorner;
	this->jrefIprtrace = jrefIprtrace;
	this->jrefSrcsysinfo = jrefSrcsysinfo;

	mask = {JREFACQPREVIEW, JREFACQPTCLOUD, JREFACTEXPOSURE, JREFACTLASER, JREFACTSERVO, JREFIPRCORNER, JREFIPRTRACE, JREFSRCSYSINFO};
};

void M2msessWzsk::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrM2msessWzsk";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefAcqpreview"] = Scr::scramble(jrefAcqpreview);
	me["scrJrefAcqptcloud"] = Scr::scramble(jrefAcqptcloud);
	me["scrJrefActexposure"] = Scr::scramble(jrefActexposure);
	me["scrJrefActlaser"] = Scr::scramble(jrefActlaser);
	me["scrJrefActservo"] = Scr::scramble(jrefActservo);
	me["scrJrefIprcorner"] = Scr::scramble(jrefIprcorner);
	me["scrJrefIprtrace"] = Scr::scramble(jrefIprtrace);
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
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqpreview", Scr::scramble(jrefAcqpreview));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqptcloud", Scr::scramble(jrefAcqptcloud));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActexposure", Scr::scramble(jrefActexposure));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActlaser", Scr::scramble(jrefActlaser));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActservo", Scr::scramble(jrefActservo));
		writeStringAttr(wr, itemtag, "sref", "scrJrefIprcorner", Scr::scramble(jrefIprcorner));
		writeStringAttr(wr, itemtag, "sref", "scrJrefIprtrace", Scr::scramble(jrefIprtrace));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrcsysinfo", Scr::scramble(jrefSrcsysinfo));
	xmlTextWriterEndElement(wr);
};

set<uint> M2msessWzsk::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefAcqpreview == comp->jrefAcqpreview) insert(items, JREFACQPREVIEW);
	if (jrefAcqptcloud == comp->jrefAcqptcloud) insert(items, JREFACQPTCLOUD);
	if (jrefActexposure == comp->jrefActexposure) insert(items, JREFACTEXPOSURE);
	if (jrefActlaser == comp->jrefActlaser) insert(items, JREFACTLASER);
	if (jrefActservo == comp->jrefActservo) insert(items, JREFACTSERVO);
	if (jrefIprcorner == comp->jrefIprcorner) insert(items, JREFIPRCORNER);
	if (jrefIprtrace == comp->jrefIprtrace) insert(items, JREFIPRTRACE);
	if (jrefSrcsysinfo == comp->jrefSrcsysinfo) insert(items, JREFSRCSYSINFO);

	return(items);
};

set<uint> M2msessWzsk::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFACQPREVIEW, JREFACQPTCLOUD, JREFACTEXPOSURE, JREFACTLASER, JREFACTSERVO, JREFIPRCORNER, JREFIPRTRACE, JREFSRCSYSINFO};
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
