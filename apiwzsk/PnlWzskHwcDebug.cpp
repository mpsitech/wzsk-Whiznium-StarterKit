/**
	* \file PnlWzskHwcDebug.cpp
	* API code for job PnlWzskHwcDebug (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskHwcDebug.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskHwcDebug::VecVDo
 ******************************************************************************/

uint PnlWzskHwcDebug::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;
	if (s == "buttsrclick") return BUTTSRCLICK;
	if (s == "buttspclick") return BUTTSPCLICK;
	if (s == "butttfviewclick") return BUTTTFVIEWCLICK;

	return(0);
};

string PnlWzskHwcDebug::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTTSRCLICK) return("ButTsrClick");
	if (ix == BUTTSPCLICK) return("ButTspClick");
	if (ix == BUTTTFVIEWCLICK) return("ButTtfViewClick");

	return("");
};

/******************************************************************************
 class PnlWzskHwcDebug::ContIac
 ******************************************************************************/

PnlWzskHwcDebug::ContIac::ContIac(
			const string& TxfTfr
		) :
			Block()
			, TxfTfr(TxfTfr)
		{
	mask = {TXFTFR};
};

bool PnlWzskHwcDebug::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskHwcDebug");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskHwcDebug";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTfr", TxfTfr)) add(TXFTFR);
	};

	return basefound;
};

void PnlWzskHwcDebug::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskHwcDebug";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskHwcDebug";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTfr", TxfTfr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskHwcDebug::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTfr == comp->TxfTfr) insert(items, TXFTFR);

	return(items);
};

set<uint> PnlWzskHwcDebug::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTFR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskHwcDebug::ContInf
 ******************************************************************************/

PnlWzskHwcDebug::ContInf::ContInf(
			const bool ButClaimOn
			, const string& TxtTst
			, const string& TxtTtf
		) :
			Block()
			, ButClaimOn(ButClaimOn)
			, TxtTst(TxtTst)
			, TxtTtf(TxtTtf)
		{
	mask = {BUTCLAIMON, TXTTST, TXTTTF};
};

bool PnlWzskHwcDebug::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskHwcDebug");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskHwcDebug";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButClaimOn", ButClaimOn)) add(BUTCLAIMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTst", TxtTst)) add(TXTTST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTtf", TxtTtf)) add(TXTTTF);
	};

	return basefound;
};

set<uint> PnlWzskHwcDebug::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtTst == comp->TxtTst) insert(items, TXTTST);
	if (TxtTtf == comp->TxtTtf) insert(items, TXTTTF);

	return(items);
};

set<uint> PnlWzskHwcDebug::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCLAIMON, TXTTST, TXTTTF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskHwcDebug::StatShr
 ******************************************************************************/

PnlWzskHwcDebug::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool TxfTfrActive
			, const bool ButTsrActive
			, const bool ButTspActive
			, const bool ButTtfViewActive
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, ButClaimActive(ButClaimActive)
			, TxfTfrActive(TxfTfrActive)
			, ButTsrActive(ButTsrActive)
			, ButTspActive(ButTspActive)
			, ButTtfViewActive(ButTtfViewActive)
		{
	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, TXFTFRACTIVE, BUTTSRACTIVE, BUTTSPACTIVE, BUTTTFVIEWACTIVE};
};

bool PnlWzskHwcDebug::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskHwcDebug");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskHwcDebug";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClaimActive", ButClaimActive)) add(BUTCLAIMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTfrActive", TxfTfrActive)) add(TXFTFRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTsrActive", ButTsrActive)) add(BUTTSRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTspActive", ButTspActive)) add(BUTTSPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTtfViewActive", ButTtfViewActive)) add(BUTTTFVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskHwcDebug::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (TxfTfrActive == comp->TxfTfrActive) insert(items, TXFTFRACTIVE);
	if (ButTsrActive == comp->ButTsrActive) insert(items, BUTTSRACTIVE);
	if (ButTspActive == comp->ButTspActive) insert(items, BUTTSPACTIVE);
	if (ButTtfViewActive == comp->ButTtfViewActive) insert(items, BUTTTFVIEWACTIVE);

	return(items);
};

set<uint> PnlWzskHwcDebug::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, TXFTFRACTIVE, BUTTSRACTIVE, BUTTSPACTIVE, BUTTTFVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskHwcDebug::Tag
 ******************************************************************************/

PnlWzskHwcDebug::Tag::Tag(
			const string& Cpt
			, const string& HdgTrk
			, const string& CptTfr
			, const string& CptTst
			, const string& ButTsr
			, const string& ButTsp
			, const string& CptTtf
		) :
			Block()
			, Cpt(Cpt)
			, HdgTrk(HdgTrk)
			, CptTfr(CptTfr)
			, CptTst(CptTst)
			, ButTsr(ButTsr)
			, ButTsp(ButTsp)
			, CptTtf(CptTtf)
		{
	mask = {CPT, HDGTRK, CPTTFR, CPTTST, BUTTSR, BUTTSP, CPTTTF};
};

bool PnlWzskHwcDebug::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskHwcDebug");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskHwcDebug";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgTrk", HdgTrk)) add(HDGTRK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTfr", CptTfr)) add(CPTTFR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTst", CptTst)) add(CPTTST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButTsr", ButTsr)) add(BUTTSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButTsp", ButTsp)) add(BUTTSP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTtf", CptTtf)) add(CPTTTF);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskHwcDebug::DpchAppData
 ******************************************************************************/

PnlWzskHwcDebug::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCDEBUGDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskHwcDebug::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcDebug::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskHwcDebugData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskHwcDebug::DpchAppDo
 ******************************************************************************/

PnlWzskHwcDebug::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCDEBUGDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskHwcDebug::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcDebug::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskHwcDebugDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskHwcDebug::DpchEngData
 ******************************************************************************/

PnlWzskHwcDebug::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKHWCDEBUGDATA)
		{
};

string PnlWzskHwcDebug::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcDebug::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskHwcDebugData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};
