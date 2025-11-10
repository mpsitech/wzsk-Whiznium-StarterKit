/**
	* \file PnlWzskPrfSrcSysinfo.cpp
	* API code for job PnlWzskPrfSrcSysinfo (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskPrfSrcSysinfo.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfSrcSysinfo::VecVDo
 ******************************************************************************/

uint PnlWzskPrfSrcSysinfo::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfSrcSysinfo::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfSrcSysinfo::ContIac
 ******************************************************************************/

PnlWzskPrfSrcSysinfo::ContIac::ContIac(
			const string& Txf1
			, const string& Txf2
		) :
			Block()
			, Txf1(Txf1)
			, Txf2(Txf2)
		{
	mask = {TXF1, TXF2};
};

bool PnlWzskPrfSrcSysinfo::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfSrcSysinfo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfSrcSysinfo";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf1", Txf1)) add(TXF1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
	};

	return basefound;
};

void PnlWzskPrfSrcSysinfo::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfSrcSysinfo";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfSrcSysinfo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf1", Txf1);
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfSrcSysinfo::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf1 == comp->Txf1) insert(items, TXF1);
	if (Txf2 == comp->Txf2) insert(items, TXF2);

	return(items);
};

set<uint> PnlWzskPrfSrcSysinfo::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF1, TXF2};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfSrcSysinfo::StatShr
 ******************************************************************************/

PnlWzskPrfSrcSysinfo::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Txf1Clean
			, const bool Txf2Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Txf1Clean(Txf1Clean)
			, Txf2Clean(Txf2Clean)
		{
	mask = {IXWZSKVEXPSTATE, TXF1CLEAN, TXF2CLEAN};
};

bool PnlWzskPrfSrcSysinfo::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskPrfSrcSysinfo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskPrfSrcSysinfo";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf1Clean", Txf1Clean)) add(TXF1CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf2Clean", Txf2Clean)) add(TXF2CLEAN);
	};

	return basefound;
};

set<uint> PnlWzskPrfSrcSysinfo::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Txf1Clean == comp->Txf1Clean) insert(items, TXF1CLEAN);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);

	return(items);
};

set<uint> PnlWzskPrfSrcSysinfo::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, TXF1CLEAN, TXF2CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfSrcSysinfo::Tag
 ******************************************************************************/

PnlWzskPrfSrcSysinfo::Tag::Tag(
			const string& Cpt
			, const string& Cpt1
			, const string& Cpt2
		) :
			Block()
			, Cpt(Cpt)
			, Cpt1(Cpt1)
			, Cpt2(Cpt2)
		{
	mask = {CPT, CPT1, CPT2};
};

bool PnlWzskPrfSrcSysinfo::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskPrfSrcSysinfo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskPrfSrcSysinfo";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt1", Cpt1)) add(CPT1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt2", Cpt2)) add(CPT2);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskPrfSrcSysinfo::DpchAppData
 ******************************************************************************/

PnlWzskPrfSrcSysinfo::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFSRCSYSINFODATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskPrfSrcSysinfo::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcSysinfo::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfSrcSysinfoData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfSrcSysinfo::DpchAppDo
 ******************************************************************************/

PnlWzskPrfSrcSysinfo::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFSRCSYSINFODO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskPrfSrcSysinfo::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcSysinfo::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfSrcSysinfoDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfSrcSysinfo::DpchEngData
 ******************************************************************************/

PnlWzskPrfSrcSysinfo::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFSRCSYSINFODATA)
		{
};

string PnlWzskPrfSrcSysinfo::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfSrcSysinfo::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskPrfSrcSysinfoData");
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
