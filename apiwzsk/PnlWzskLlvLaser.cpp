/**
	* \file PnlWzskLlvLaser.cpp
	* API code for job PnlWzskLlvLaser (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzskLlvLaser.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvLaser::VecVDo
 ******************************************************************************/

uint PnlWzskLlvLaser::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;

	return(0);
};

string PnlWzskLlvLaser::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");

	return("");
};

/******************************************************************************
 class PnlWzskLlvLaser::ContIac
 ******************************************************************************/

PnlWzskLlvLaser::ContIac::ContIac(
			const bool ChkErg
			, const double SldLle
			, const double SldLri
		) :
			Block()
		{
	this->ChkErg = ChkErg;
	this->SldLle = SldLle;
	this->SldLri = SldLri;

	mask = {CHKERG, SLDLLE, SLDLRI};
};

bool PnlWzskLlvLaser::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLlvLaser");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLlvLaser";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkErg", ChkErg)) add(CHKERG);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldLle", SldLle)) add(SLDLLE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldLri", SldLri)) add(SLDLRI);
	};

	return basefound;
};

void PnlWzskLlvLaser::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLlvLaser";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLlvLaser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ChkErg", ChkErg);
		writeDoubleAttr(wr, itemtag, "sref", "SldLle", SldLle);
		writeDoubleAttr(wr, itemtag, "sref", "SldLri", SldLri);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvLaser::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (ChkErg == comp->ChkErg) insert(items, CHKERG);
	if (compareDouble(SldLle, comp->SldLle) < 1.0e-4) insert(items, SLDLLE);
	if (compareDouble(SldLri, comp->SldLri) < 1.0e-4) insert(items, SLDLRI);

	return(items);
};

set<uint> PnlWzskLlvLaser::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {CHKERG, SLDLLE, SLDLRI};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvLaser::ContInf
 ******************************************************************************/

PnlWzskLlvLaser::ContInf::ContInf(
			const bool ButClaimOn
		) :
			Block()
		{
	this->ButClaimOn = ButClaimOn;

	mask = {BUTCLAIMON};
};

bool PnlWzskLlvLaser::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLlvLaser");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLlvLaser";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButClaimOn", ButClaimOn)) add(BUTCLAIMON);
	};

	return basefound;
};

set<uint> PnlWzskLlvLaser::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);

	return(items);
};

set<uint> PnlWzskLlvLaser::ContInf::diff(
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
 class PnlWzskLlvLaser::StatShr
 ******************************************************************************/

PnlWzskLlvLaser::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool SldLleActive
			, const double SldLleMin
			, const double SldLleMax
			, const bool SldLriActive
			, const double SldLriMin
			, const double SldLriMax
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->ButClaimActive = ButClaimActive;
	this->SldLleActive = SldLleActive;
	this->SldLleMin = SldLleMin;
	this->SldLleMax = SldLleMax;
	this->SldLriActive = SldLriActive;
	this->SldLriMin = SldLriMin;
	this->SldLriMax = SldLriMax;

	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDLLEACTIVE, SLDLLEMIN, SLDLLEMAX, SLDLRIACTIVE, SLDLRIMIN, SLDLRIMAX};
};

bool PnlWzskLlvLaser::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLlvLaser");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLlvLaser";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClaimActive", ButClaimActive)) add(BUTCLAIMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldLleActive", SldLleActive)) add(SLDLLEACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldLleMin", SldLleMin)) add(SLDLLEMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldLleMax", SldLleMax)) add(SLDLLEMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldLriActive", SldLriActive)) add(SLDLRIACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldLriMin", SldLriMin)) add(SLDLRIMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldLriMax", SldLriMax)) add(SLDLRIMAX);
	};

	return basefound;
};

set<uint> PnlWzskLlvLaser::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (SldLleActive == comp->SldLleActive) insert(items, SLDLLEACTIVE);
	if (compareDouble(SldLleMin, comp->SldLleMin) < 1.0e-4) insert(items, SLDLLEMIN);
	if (compareDouble(SldLleMax, comp->SldLleMax) < 1.0e-4) insert(items, SLDLLEMAX);
	if (SldLriActive == comp->SldLriActive) insert(items, SLDLRIACTIVE);
	if (compareDouble(SldLriMin, comp->SldLriMin) < 1.0e-4) insert(items, SLDLRIMIN);
	if (compareDouble(SldLriMax, comp->SldLriMax) < 1.0e-4) insert(items, SLDLRIMAX);

	return(items);
};

set<uint> PnlWzskLlvLaser::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDLLEACTIVE, SLDLLEMIN, SLDLLEMAX, SLDLRIACTIVE, SLDLRIMIN, SLDLRIMAX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvLaser::Tag
 ******************************************************************************/

PnlWzskLlvLaser::Tag::Tag(
			const string& Cpt
			, const string& CptErg
			, const string& CptLle
			, const string& CptLri
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptErg = CptErg;
	this->CptLle = CptLle;
	this->CptLri = CptLri;

	mask = {CPT, CPTERG, CPTLLE, CPTLRI};
};

bool PnlWzskLlvLaser::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLlvLaser");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLlvLaser";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptErg", CptErg)) add(CPTERG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLle", CptLle)) add(CPTLLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLri", CptLri)) add(CPTLRI);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLlvLaser::DpchAppData
 ******************************************************************************/

PnlWzskLlvLaser::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVLASERDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskLlvLaser::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvLaser::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvLaserData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvLaser::DpchAppDo
 ******************************************************************************/

PnlWzskLlvLaser::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVLASERDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskLlvLaser::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvLaser::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvLaserDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvLaser::DpchEngData
 ******************************************************************************/

PnlWzskLlvLaser::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVLASERDATA)
		{
};

string PnlWzskLlvLaser::DpchEngData::getSrefsMask() {
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

void PnlWzskLlvLaser::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLlvLaserData");
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
