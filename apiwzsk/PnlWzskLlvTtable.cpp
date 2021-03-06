/**
	* \file PnlWzskLlvTtable.cpp
	* API code for job PnlWzskLlvTtable (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzskLlvTtable.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvTtable::VecVDo
 ******************************************************************************/

uint PnlWzskLlvTtable::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;

	return(0);
};

string PnlWzskLlvTtable::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");

	return("");
};

/******************************************************************************
 class PnlWzskLlvTtable::ContIac
 ******************************************************************************/

PnlWzskLlvTtable::ContIac::ContIac(
			const double SldTrg
		) :
			Block()
		{
	this->SldTrg = SldTrg;

	mask = {SLDTRG};
};

bool PnlWzskLlvTtable::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLlvTtable");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLlvTtable";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldTrg", SldTrg)) add(SLDTRG);
	};

	return basefound;
};

void PnlWzskLlvTtable::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLlvTtable";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLlvTtable";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldTrg", SldTrg);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvTtable::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldTrg, comp->SldTrg) < 1.0e-4) insert(items, SLDTRG);

	return(items);
};

set<uint> PnlWzskLlvTtable::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDTRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvTtable::ContInf
 ******************************************************************************/

PnlWzskLlvTtable::ContInf::ContInf(
			const bool ButClaimOn
		) :
			Block()
		{
	this->ButClaimOn = ButClaimOn;

	mask = {BUTCLAIMON};
};

bool PnlWzskLlvTtable::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLlvTtable");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLlvTtable";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButClaimOn", ButClaimOn)) add(BUTCLAIMON);
	};

	return basefound;
};

set<uint> PnlWzskLlvTtable::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);

	return(items);
};

set<uint> PnlWzskLlvTtable::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCLAIMON};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvTtable::StatShr
 ******************************************************************************/

PnlWzskLlvTtable::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool SldTrgActive
			, const double SldTrgMin
			, const double SldTrgMax
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->ButClaimActive = ButClaimActive;
	this->SldTrgActive = SldTrgActive;
	this->SldTrgMin = SldTrgMin;
	this->SldTrgMax = SldTrgMax;

	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTRGACTIVE, SLDTRGMIN, SLDTRGMAX};
};

bool PnlWzskLlvTtable::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLlvTtable");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLlvTtable";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClaimActive", ButClaimActive)) add(BUTCLAIMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTrgActive", SldTrgActive)) add(SLDTRGACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTrgMin", SldTrgMin)) add(SLDTRGMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTrgMax", SldTrgMax)) add(SLDTRGMAX);
	};

	return basefound;
};

set<uint> PnlWzskLlvTtable::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (SldTrgActive == comp->SldTrgActive) insert(items, SLDTRGACTIVE);
	if (compareDouble(SldTrgMin, comp->SldTrgMin) < 1.0e-4) insert(items, SLDTRGMIN);
	if (compareDouble(SldTrgMax, comp->SldTrgMax) < 1.0e-4) insert(items, SLDTRGMAX);

	return(items);
};

set<uint> PnlWzskLlvTtable::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTRGACTIVE, SLDTRGMIN, SLDTRGMAX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvTtable::Tag
 ******************************************************************************/

PnlWzskLlvTtable::Tag::Tag(
			const string& Cpt
			, const string& CptTrg
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptTrg = CptTrg;

	mask = {CPT, CPTTRG};
};

bool PnlWzskLlvTtable::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLlvTtable");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLlvTtable";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTrg", CptTrg)) add(CPTTRG);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLlvTtable::DpchAppData
 ******************************************************************************/

PnlWzskLlvTtable::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVTTABLEDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskLlvTtable::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvTtable::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvTtableData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvTtable::DpchAppDo
 ******************************************************************************/

PnlWzskLlvTtable::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVTTABLEDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskLlvTtable::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvTtable::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvTtableDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvTtable::DpchEngData
 ******************************************************************************/

PnlWzskLlvTtable::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVTTABLEDATA)
		{
};

string PnlWzskLlvTtable::DpchEngData::getSrefsMask() {
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

void PnlWzskLlvTtable::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLlvTtableData");
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
