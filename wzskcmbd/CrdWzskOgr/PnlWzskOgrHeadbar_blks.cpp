/**
	* \file PnlWzskOgrHeadbar_blks.cpp
	* job handler for job PnlWzskOgrHeadbar (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskOgrHeadbar::StgInf
 ******************************************************************************/

void PnlWzskOgrHeadbar::StgInf::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgInfWzskOgrHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["MenAppCptwidth"] = "200";
		me["MenAppWidth"] = "246";
		me["MenCrdCptwidth"] = "118";
		me["MenCrdWidth"] = "323";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["MenAppCptwidth"] = "200";
		me["MenAppWidth"] = "246";
		me["MenCrdCptwidth"] = "118";
		me["MenCrdWidth"] = "323";
	};
};

void PnlWzskOgrHeadbar::StgInf::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfWzskOgrHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfWzskOgrHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "246");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "118");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "246");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "118");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskOgrHeadbar::Tag
 ******************************************************************************/

void PnlWzskOgrHeadbar::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskOgrHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["MenApp"] = "Whiznium StarterKit";
		me["MenCrd"] = "Object group";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["MenApp"] = "Whiznium StarterKit";
		me["MenCrd"] = "Objektgruppe";
	};
};

void PnlWzskOgrHeadbar::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskOgrHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskOgrHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Whiznium StarterKit");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Object group");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Whiznium StarterKit");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Objektgruppe");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskOgrHeadbar::DpchEngData
 ******************************************************************************/

PnlWzskOgrHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKOGRHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlWzskOgrHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskOgrHeadbar::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlWzskOgrHeadbar::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskOgrHeadbarData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STGINF)) StgInf::writeJSON(ixWzskVLocale, me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskOgrHeadbar::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskOgrHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixWzskVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
