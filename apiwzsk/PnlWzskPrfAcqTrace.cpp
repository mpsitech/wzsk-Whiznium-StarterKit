/**
	* \file PnlWzskPrfAcqTrace.cpp
	* API code for job PnlWzskPrfAcqTrace (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskPrfAcqTrace.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfAcqTrace::VecVDo
 ******************************************************************************/

uint PnlWzskPrfAcqTrace::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfAcqTrace::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::ContIac
 ******************************************************************************/

PnlWzskPrfAcqTrace::ContIac::ContIac(
			const string& Txf1
			, const string& Txf2
			, const string& Txf3
			, const string& Txf4
		) :
			Block()
			, Txf1(Txf1)
			, Txf2(Txf2)
			, Txf3(Txf3)
			, Txf4(Txf4)
		{
	mask = {TXF1, TXF2, TXF3, TXF4};
};

bool PnlWzskPrfAcqTrace::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfAcqTrace");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfAcqTrace";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf1", Txf1)) add(TXF1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf3", Txf3)) add(TXF3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf4", Txf4)) add(TXF4);
	};

	return basefound;
};

void PnlWzskPrfAcqTrace::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfAcqTrace";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfAcqTrace";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf1", Txf1);
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
		writeStringAttr(wr, itemtag, "sref", "Txf3", Txf3);
		writeStringAttr(wr, itemtag, "sref", "Txf4", Txf4);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfAcqTrace::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf1 == comp->Txf1) insert(items, TXF1);
	if (Txf2 == comp->Txf2) insert(items, TXF2);
	if (Txf3 == comp->Txf3) insert(items, TXF3);
	if (Txf4 == comp->Txf4) insert(items, TXF4);

	return(items);
};

set<uint> PnlWzskPrfAcqTrace::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF1, TXF2, TXF3, TXF4};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::StatShr
 ******************************************************************************/

PnlWzskPrfAcqTrace::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Txf1Clean
			, const bool Txf2Clean
			, const bool Txf3Clean
			, const bool Txf4Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Txf1Clean(Txf1Clean)
			, Txf2Clean(Txf2Clean)
			, Txf3Clean(Txf3Clean)
			, Txf4Clean(Txf4Clean)
		{
	mask = {IXWZSKVEXPSTATE, TXF1CLEAN, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN};
};

bool PnlWzskPrfAcqTrace::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskPrfAcqTrace");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskPrfAcqTrace";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf1Clean", Txf1Clean)) add(TXF1CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf2Clean", Txf2Clean)) add(TXF2CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf3Clean", Txf3Clean)) add(TXF3CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf4Clean", Txf4Clean)) add(TXF4CLEAN);
	};

	return basefound;
};

set<uint> PnlWzskPrfAcqTrace::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Txf1Clean == comp->Txf1Clean) insert(items, TXF1CLEAN);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);
	if (Txf3Clean == comp->Txf3Clean) insert(items, TXF3CLEAN);
	if (Txf4Clean == comp->Txf4Clean) insert(items, TXF4CLEAN);

	return(items);
};

set<uint> PnlWzskPrfAcqTrace::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, TXF1CLEAN, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::Tag
 ******************************************************************************/

PnlWzskPrfAcqTrace::Tag::Tag(
			const string& Cpt
			, const string& Cpt1
			, const string& Cpt2
			, const string& Cpt3
			, const string& Cpt4
		) :
			Block()
			, Cpt(Cpt)
			, Cpt1(Cpt1)
			, Cpt2(Cpt2)
			, Cpt3(Cpt3)
			, Cpt4(Cpt4)
		{
	mask = {CPT, CPT1, CPT2, CPT3, CPT4};
};

bool PnlWzskPrfAcqTrace::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskPrfAcqTrace");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskPrfAcqTrace";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt1", Cpt1)) add(CPT1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt2", Cpt2)) add(CPT2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt3", Cpt3)) add(CPT3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt4", Cpt4)) add(CPT4);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::DpchAppData
 ******************************************************************************/

PnlWzskPrfAcqTrace::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFACQTRACEDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskPrfAcqTrace::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqTrace::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfAcqTraceData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::DpchAppDo
 ******************************************************************************/

PnlWzskPrfAcqTrace::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFACQTRACEDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskPrfAcqTrace::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqTrace::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfAcqTraceDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfAcqTrace::DpchEngData
 ******************************************************************************/

PnlWzskPrfAcqTrace::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFACQTRACEDATA)
		{
};

string PnlWzskPrfAcqTrace::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqTrace::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskPrfAcqTraceData");
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
