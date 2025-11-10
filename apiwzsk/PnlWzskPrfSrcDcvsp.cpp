/**
	* \file PnlWzskPrfSrcDcvsp.cpp
	* API code for job PnlWzskPrfSrcDcvsp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Oct 2025
	*/
// IP header --- ABOVE

#include "PnlWzskPrfSrcDcvsp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfSrcDcvsp::VecVDo
 ******************************************************************************/

uint PnlWzskPrfSrcDcvsp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfSrcDcvsp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfSrcDcvsp::ContIac
 ******************************************************************************/

PnlWzskPrfSrcDcvsp::ContIac::ContIac(
			const string& Txf1
		) :
			Block()
			, Txf1(Txf1)
		{
	mask = {TXF1};
};

bool PnlWzskPrfSrcDcvsp::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfSrcDcvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfSrcDcvsp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf1", Txf1)) add(TXF1);
	};

	return basefound;
};

void PnlWzskPrfSrcDcvsp::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfSrcDcvsp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfSrcDcvsp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf1", Txf1);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfSrcDcvsp::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf1 == comp->Txf1) insert(items, TXF1);

	return(items);
};

set<uint> PnlWzskPrfSrcDcvsp::ContIac::diff(
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
 class PnlWzskPrfSrcDcvsp::StatShr
 ******************************************************************************/

PnlWzskPrfSrcDcvsp::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Txf1Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Txf1Clean(Txf1Clean)
		{
	mask = {IXWZSKVEXPSTATE, TXF1CLEAN};
};

bool PnlWzskPrfSrcDcvsp::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskPrfSrcDcvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskPrfSrcDcvsp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf1Clean", Txf1Clean)) add(TXF1CLEAN);
	};

	return basefound;
};

set<uint> PnlWzskPrfSrcDcvsp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Txf1Clean == comp->Txf1Clean) insert(items, TXF1CLEAN);

	return(items);
};

set<uint> PnlWzskPrfSrcDcvsp::StatShr::diff(
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
 class PnlWzskPrfSrcDcvsp::Tag
 ******************************************************************************/

PnlWzskPrfSrcDcvsp::Tag::Tag(
			const string& Cpt
			, const string& Cpt1
		) :
			Block()
			, Cpt(Cpt)
			, Cpt1(Cpt1)
		{
	mask = {CPT, CPT1};
};

bool PnlWzskPrfSrcDcvsp::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskPrfSrcDcvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskPrfSrcDcvsp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt1", Cpt1)) add(CPT1);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskPrfSrcDcvsp::DpchAppData
 ******************************************************************************/

PnlWzskPrfSrcDcvsp::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFSRCDCVSPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskPrfSrcDcvsp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcDcvsp::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfSrcDcvspData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfSrcDcvsp::DpchAppDo
 ******************************************************************************/

PnlWzskPrfSrcDcvsp::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFSRCDCVSPDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskPrfSrcDcvsp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcDcvsp::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfSrcDcvspDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfSrcDcvsp::DpchEngData
 ******************************************************************************/

PnlWzskPrfSrcDcvsp::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFSRCDCVSPDATA)
		{
};

string PnlWzskPrfSrcDcvsp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcDcvsp::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskPrfSrcDcvspData");
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
