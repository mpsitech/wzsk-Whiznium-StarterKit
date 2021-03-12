/**
	* \file PnlWzskScfHeadbar_blks.cpp
	* job handler for job PnlWzskScfHeadbar (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskScfHeadbar::StgInf
 ******************************************************************************/

void PnlWzskScfHeadbar::StgInf::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgInfWzskScfHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["MenAppCptwidth"] = "200";
		me["MenAppWidth"] = "246";
		me["MenCrdCptwidth"] = "200";
		me["MenCrdWidth"] = "200";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["MenAppCptwidth"] = "200";
		me["MenAppWidth"] = "246";
		me["MenCrdCptwidth"] = "250";
		me["MenCrdWidth"] = "250";
	};
};

void PnlWzskScfHeadbar::StgInf::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfWzskScfHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfWzskScfHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "246");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "200");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "246");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "250");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "250");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskScfHeadbar::Tag
 ******************************************************************************/

void PnlWzskScfHeadbar::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskScfHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["MenApp"] = "Whiznium StarterKit";
		me["MenCrd"] = "System configuration";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["MenApp"] = "Whiznium StarterKit";
		me["MenCrd"] = "Systemkonfiguration";
	};
};

void PnlWzskScfHeadbar::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskScfHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskScfHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Whiznium StarterKit");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "System configuration");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Whiznium StarterKit");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Systemkonfiguration");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskScfHeadbar::DpchEngData
 ******************************************************************************/

PnlWzskScfHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSCFHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlWzskScfHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskScfHeadbar::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlWzskScfHeadbar::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskScfHeadbarData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STGINF)) StgInf::writeJSON(ixWzskVLocale, me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskScfHeadbar::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskScfHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixWzskVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
