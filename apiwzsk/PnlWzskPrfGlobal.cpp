/**
	* \file PnlWzskPrfGlobal.cpp
	* API code for job PnlWzskPrfGlobal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskPrfGlobal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfGlobal::VecVDo
 ******************************************************************************/

uint PnlWzskPrfGlobal::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfGlobal::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfGlobal::ContIac
 ******************************************************************************/

PnlWzskPrfGlobal::ContIac::ContIac(
			const string& Txf2
			, const string& Txf3
			, const string& Txf4
			, const string& Txf5
			, const string& Txf6
			, const uint numFPup102
		) :
			Block()
			, Txf2(Txf2)
			, Txf3(Txf3)
			, Txf4(Txf4)
			, Txf5(Txf5)
			, Txf6(Txf6)
			, numFPup102(numFPup102)
		{
	mask = {TXF2, TXF3, TXF4, TXF5, TXF6, NUMFPUP102};
};

bool PnlWzskPrfGlobal::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf3", Txf3)) add(TXF3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf4", Txf4)) add(TXF4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf5", Txf5)) add(TXF5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf6", Txf6)) add(TXF6);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPup102", numFPup102)) add(NUMFPUP102);
	};

	return basefound;
};

void PnlWzskPrfGlobal::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
		writeStringAttr(wr, itemtag, "sref", "Txf3", Txf3);
		writeStringAttr(wr, itemtag, "sref", "Txf4", Txf4);
		writeStringAttr(wr, itemtag, "sref", "Txf5", Txf5);
		writeStringAttr(wr, itemtag, "sref", "Txf6", Txf6);
		writeUintAttr(wr, itemtag, "sref", "numFPup102", numFPup102);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfGlobal::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf2 == comp->Txf2) insert(items, TXF2);
	if (Txf3 == comp->Txf3) insert(items, TXF3);
	if (Txf4 == comp->Txf4) insert(items, TXF4);
	if (Txf5 == comp->Txf5) insert(items, TXF5);
	if (Txf6 == comp->Txf6) insert(items, TXF6);
	if (numFPup102 == comp->numFPup102) insert(items, NUMFPUP102);

	return(items);
};

set<uint> PnlWzskPrfGlobal::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF2, TXF3, TXF4, TXF5, TXF6, NUMFPUP102};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfGlobal::StatShr
 ******************************************************************************/

PnlWzskPrfGlobal::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Txf2Clean
			, const bool Txf3Clean
			, const bool Txf4Clean
			, const bool Txf5Clean
			, const bool Txf6Clean
			, const bool Pup102Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Txf2Clean(Txf2Clean)
			, Txf3Clean(Txf3Clean)
			, Txf4Clean(Txf4Clean)
			, Txf5Clean(Txf5Clean)
			, Txf6Clean(Txf6Clean)
			, Pup102Clean(Pup102Clean)
		{
	mask = {IXWZSKVEXPSTATE, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, PUP102CLEAN};
};

bool PnlWzskPrfGlobal::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskPrfGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskPrfGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf2Clean", Txf2Clean)) add(TXF2CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf3Clean", Txf3Clean)) add(TXF3CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf4Clean", Txf4Clean)) add(TXF4CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf5Clean", Txf5Clean)) add(TXF5CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf6Clean", Txf6Clean)) add(TXF6CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Pup102Clean", Pup102Clean)) add(PUP102CLEAN);
	};

	return basefound;
};

set<uint> PnlWzskPrfGlobal::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);
	if (Txf3Clean == comp->Txf3Clean) insert(items, TXF3CLEAN);
	if (Txf4Clean == comp->Txf4Clean) insert(items, TXF4CLEAN);
	if (Txf5Clean == comp->Txf5Clean) insert(items, TXF5CLEAN);
	if (Txf6Clean == comp->Txf6Clean) insert(items, TXF6CLEAN);
	if (Pup102Clean == comp->Pup102Clean) insert(items, PUP102CLEAN);

	return(items);
};

set<uint> PnlWzskPrfGlobal::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, PUP102CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfGlobal::Tag
 ******************************************************************************/

PnlWzskPrfGlobal::Tag::Tag(
			const string& Cpt
			, const string& Hdg1
			, const string& Cpt2
			, const string& Cpt3
			, const string& Cpt4
			, const string& Cpt5
			, const string& Cpt6
			, const string& Hdg101
			, const string& Cpt102
		) :
			Block()
			, Cpt(Cpt)
			, Hdg1(Hdg1)
			, Cpt2(Cpt2)
			, Cpt3(Cpt3)
			, Cpt4(Cpt4)
			, Cpt5(Cpt5)
			, Cpt6(Cpt6)
			, Hdg101(Hdg101)
			, Cpt102(Cpt102)
		{
	mask = {CPT, HDG1, CPT2, CPT3, CPT4, CPT5, CPT6, HDG101, CPT102};
};

bool PnlWzskPrfGlobal::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskPrfGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskPrfGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg1", Hdg1)) add(HDG1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt2", Cpt2)) add(CPT2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt3", Cpt3)) add(CPT3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt4", Cpt4)) add(CPT4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt5", Cpt5)) add(CPT5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt6", Cpt6)) add(CPT6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg101", Hdg101)) add(HDG101);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt102", Cpt102)) add(CPT102);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskPrfGlobal::DpchAppData
 ******************************************************************************/

PnlWzskPrfGlobal::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFGLOBALDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskPrfGlobal::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfGlobal::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfGlobalData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfGlobal::DpchAppDo
 ******************************************************************************/

PnlWzskPrfGlobal::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFGLOBALDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskPrfGlobal::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfGlobal::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfGlobalDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfGlobal::DpchEngData
 ******************************************************************************/

PnlWzskPrfGlobal::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFGLOBALDATA)
		{
	feedFPup102.tag = "FeedFPup102";
};

string PnlWzskPrfGlobal::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFPUP102)) ss.push_back("feedFPup102");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfGlobal::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskPrfGlobalData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFPup102.readXML(docctx, basexpath, true)) add(FEEDFPUP102);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFPup102.clear();
		statshr = StatShr();
		tag = Tag();
	};
};
