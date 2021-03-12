/**
	* \file PnlWzskSesHeadbar_blks.cpp
	* job handler for job PnlWzskSesHeadbar (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskSesHeadbar::StgInf
 ******************************************************************************/

void PnlWzskSesHeadbar::StgInf::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgInfWzskSesHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["MenAppCptwidth"] = "200";
		me["MenAppWidth"] = "246";
		me["MenCrdCptwidth"] = "73";
		me["MenCrdWidth"] = "323";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["MenAppCptwidth"] = "200";
		me["MenAppWidth"] = "246";
		me["MenCrdCptwidth"] = "73";
		me["MenCrdWidth"] = "323";
	};
};

void PnlWzskSesHeadbar::StgInf::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfWzskSesHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfWzskSesHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "246");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "73");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "246");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "73");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskSesHeadbar::Tag
 ******************************************************************************/

void PnlWzskSesHeadbar::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskSesHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["MenApp"] = "Whiznium StarterKit";
		me["MenCrd"] = "Session";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["MenApp"] = "Whiznium StarterKit";
		me["MenCrd"] = "Sitzung";
	};
};

void PnlWzskSesHeadbar::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskSesHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskSesHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Whiznium StarterKit");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Session");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Whiznium StarterKit");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Sitzung");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskSesHeadbar::DpchEngData
 ******************************************************************************/

PnlWzskSesHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSESHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlWzskSesHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskSesHeadbar::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlWzskSesHeadbar::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskSesHeadbarData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STGINF)) StgInf::writeJSON(ixWzskVLocale, me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskSesHeadbar::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskSesHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixWzskVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
