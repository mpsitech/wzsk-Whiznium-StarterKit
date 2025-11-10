/**
	* \file PnlWzskPrfAcqPreview.cpp
	* API code for job PnlWzskPrfAcqPreview (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskPrfAcqPreview.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfAcqPreview::VecVDo
 ******************************************************************************/

uint PnlWzskPrfAcqPreview::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfAcqPreview::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfAcqPreview::ContIac
 ******************************************************************************/

PnlWzskPrfAcqPreview::ContIac::ContIac(
			const bool Chk1
			, const string& Txf2
		) :
			Block()
			, Chk1(Chk1)
			, Txf2(Txf2)
		{
	mask = {CHK1, TXF2};
};

bool PnlWzskPrfAcqPreview::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfAcqPreview");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfAcqPreview";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk1", Chk1)) add(CHK1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
	};

	return basefound;
};

void PnlWzskPrfAcqPreview::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfAcqPreview";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfAcqPreview";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "Chk1", Chk1);
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfAcqPreview::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Chk1 == comp->Chk1) insert(items, CHK1);
	if (Txf2 == comp->Txf2) insert(items, TXF2);

	return(items);
};

set<uint> PnlWzskPrfAcqPreview::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {CHK1, TXF2};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfAcqPreview::StatShr
 ******************************************************************************/

PnlWzskPrfAcqPreview::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Chk1Clean
			, const bool Txf2Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Chk1Clean(Chk1Clean)
			, Txf2Clean(Txf2Clean)
		{
	mask = {IXWZSKVEXPSTATE, CHK1CLEAN, TXF2CLEAN};
};

bool PnlWzskPrfAcqPreview::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskPrfAcqPreview");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskPrfAcqPreview";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk1Clean", Chk1Clean)) add(CHK1CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf2Clean", Txf2Clean)) add(TXF2CLEAN);
	};

	return basefound;
};

set<uint> PnlWzskPrfAcqPreview::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Chk1Clean == comp->Chk1Clean) insert(items, CHK1CLEAN);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);

	return(items);
};

set<uint> PnlWzskPrfAcqPreview::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, CHK1CLEAN, TXF2CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfAcqPreview::Tag
 ******************************************************************************/

PnlWzskPrfAcqPreview::Tag::Tag(
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

bool PnlWzskPrfAcqPreview::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskPrfAcqPreview");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskPrfAcqPreview";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt1", Cpt1)) add(CPT1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt2", Cpt2)) add(CPT2);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskPrfAcqPreview::DpchAppData
 ******************************************************************************/

PnlWzskPrfAcqPreview::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFACQPREVIEWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskPrfAcqPreview::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqPreview::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfAcqPreviewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfAcqPreview::DpchAppDo
 ******************************************************************************/

PnlWzskPrfAcqPreview::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFACQPREVIEWDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskPrfAcqPreview::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqPreview::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfAcqPreviewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfAcqPreview::DpchEngData
 ******************************************************************************/

PnlWzskPrfAcqPreview::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFACQPREVIEWDATA)
		{
};

string PnlWzskPrfAcqPreview::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfAcqPreview::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskPrfAcqPreviewData");
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
