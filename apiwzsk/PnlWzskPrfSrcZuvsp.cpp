/**
	* \file PnlWzskPrfSrcZuvsp.cpp
	* API code for job PnlWzskPrfSrcZuvsp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskPrfSrcZuvsp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfSrcZuvsp::VecVDo
 ******************************************************************************/

uint PnlWzskPrfSrcZuvsp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfSrcZuvsp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfSrcZuvsp::ContIac
 ******************************************************************************/

PnlWzskPrfSrcZuvsp::ContIac::ContIac(
			const string& Txf1
		) :
			Block()
			, Txf1(Txf1)
		{
	mask = {TXF1};
};

bool PnlWzskPrfSrcZuvsp::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfSrcZuvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfSrcZuvsp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf1", Txf1)) add(TXF1);
	};

	return basefound;
};

void PnlWzskPrfSrcZuvsp::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfSrcZuvsp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfSrcZuvsp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf1", Txf1);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfSrcZuvsp::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf1 == comp->Txf1) insert(items, TXF1);

	return(items);
};

set<uint> PnlWzskPrfSrcZuvsp::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF1};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfSrcZuvsp::StatShr
 ******************************************************************************/

PnlWzskPrfSrcZuvsp::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Txf1Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Txf1Clean(Txf1Clean)
		{
	mask = {IXWZSKVEXPSTATE, TXF1CLEAN};
};

bool PnlWzskPrfSrcZuvsp::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskPrfSrcZuvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskPrfSrcZuvsp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf1Clean", Txf1Clean)) add(TXF1CLEAN);
	};

	return basefound;
};

set<uint> PnlWzskPrfSrcZuvsp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Txf1Clean == comp->Txf1Clean) insert(items, TXF1CLEAN);

	return(items);
};

set<uint> PnlWzskPrfSrcZuvsp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, TXF1CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfSrcZuvsp::Tag
 ******************************************************************************/

PnlWzskPrfSrcZuvsp::Tag::Tag(
			const string& Cpt
			, const string& Cpt1
		) :
			Block()
			, Cpt(Cpt)
			, Cpt1(Cpt1)
		{
	mask = {CPT, CPT1};
};

bool PnlWzskPrfSrcZuvsp::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskPrfSrcZuvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskPrfSrcZuvsp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt1", Cpt1)) add(CPT1);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskPrfSrcZuvsp::DpchAppData
 ******************************************************************************/

PnlWzskPrfSrcZuvsp::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFSRCZUVSPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskPrfSrcZuvsp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcZuvsp::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfSrcZuvspData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfSrcZuvsp::DpchAppDo
 ******************************************************************************/

PnlWzskPrfSrcZuvsp::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFSRCZUVSPDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskPrfSrcZuvsp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcZuvsp::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfSrcZuvspDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfSrcZuvsp::DpchEngData
 ******************************************************************************/

PnlWzskPrfSrcZuvsp::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFSRCZUVSPDATA)
		{
};

string PnlWzskPrfSrcZuvsp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcZuvsp::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskPrfSrcZuvspData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		statshr = StatShr();
		tag = Tag();
	};
};
