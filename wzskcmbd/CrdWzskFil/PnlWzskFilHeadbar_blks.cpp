/**
	* \file PnlWzskFilHeadbar_blks.cpp
	* job handler for job PnlWzskFilHeadbar (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskFilHeadbar::StgInf
 ******************************************************************************/

void PnlWzskFilHeadbar::StgInf::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfWzskFilHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfWzskFilHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "246");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "46");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "200");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "246");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "55");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskFilHeadbar::Tag
 ******************************************************************************/

void PnlWzskFilHeadbar::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskFilHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskFilHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Whiznium StarterKit");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "File");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "Whiznium StarterKit");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Datei");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskFilHeadbar::DpchEngData
 ******************************************************************************/

PnlWzskFilHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKFILHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlWzskFilHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskFilHeadbar::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlWzskFilHeadbar::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskFilHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixWzskVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

