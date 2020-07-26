/**
	* \file PnlWzskLiv3DView.cpp
	* API code for job PnlWzskLiv3DView (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "PnlWzskLiv3DView.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLiv3DView::VecVDo
 ******************************************************************************/

uint PnlWzskLiv3DView::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;
	if (s == "butplayclick") return BUTPLAYCLICK;
	if (s == "butstopclick") return BUTSTOPCLICK;
	if (s == "butastclick") return BUTASTCLICK;

	return(0);
};

string PnlWzskLiv3DView::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTPLAYCLICK) return("ButPlayClick");
	if (ix == BUTSTOPCLICK) return("ButStopClick");
	if (ix == BUTASTCLICK) return("ButAstClick");

	return("");
};

/******************************************************************************
 class PnlWzskLiv3DView::ContInf
 ******************************************************************************/

PnlWzskLiv3DView::ContInf::ContInf(
			const bool ButClaimOn
			, const string& TxtAst
			, const string& TxtAoa
		) :
			Block()
		{
	this->ButClaimOn = ButClaimOn;
	this->TxtAst = TxtAst;
	this->TxtAoa = TxtAoa;

	mask = {BUTCLAIMON, TXTAST, TXTAOA};
};

bool PnlWzskLiv3DView::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLiv3DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLiv3DView";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButClaimOn", ButClaimOn)) add(BUTCLAIMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAst", TxtAst)) add(TXTAST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAoa", TxtAoa)) add(TXTAOA);
	};

	return basefound;
};

set<uint> PnlWzskLiv3DView::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtAst == comp->TxtAst) insert(items, TXTAST);
	if (TxtAoa == comp->TxtAoa) insert(items, TXTAOA);

	return(items);
};

set<uint> PnlWzskLiv3DView::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCLAIMON, TXTAST, TXTAOA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv3DView::StatShr
 ******************************************************************************/

PnlWzskLiv3DView::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const double SldTreHMin
			, const double SldTreHMax
			, const double SldTreVMin
			, const double SldTreVMax
			, const bool ButPlayActive
			, const bool ButStopActive
			, const bool TxtAoaAvail
			, const bool ButAstActive
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->ButClaimActive = ButClaimActive;
	this->SldTreHMin = SldTreHMin;
	this->SldTreHMax = SldTreHMax;
	this->SldTreVMin = SldTreVMin;
	this->SldTreVMax = SldTreVMax;
	this->ButPlayActive = ButPlayActive;
	this->ButStopActive = ButStopActive;
	this->TxtAoaAvail = TxtAoaAvail;
	this->ButAstActive = ButAstActive;

	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTREHMIN, SLDTREHMAX, SLDTREVMIN, SLDTREVMAX, BUTPLAYACTIVE, BUTSTOPACTIVE, TXTAOAAVAIL, BUTASTACTIVE};
};

bool PnlWzskLiv3DView::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLiv3DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLiv3DView";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClaimActive", ButClaimActive)) add(BUTCLAIMACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTreHMin", SldTreHMin)) add(SLDTREHMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTreHMax", SldTreHMax)) add(SLDTREHMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTreVMin", SldTreVMin)) add(SLDTREVMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTreVMax", SldTreVMax)) add(SLDTREVMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPlayActive", ButPlayActive)) add(BUTPLAYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStopActive", ButStopActive)) add(BUTSTOPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAoaAvail", TxtAoaAvail)) add(TXTAOAAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAstActive", ButAstActive)) add(BUTASTACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskLiv3DView::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (compareDouble(SldTreHMin, comp->SldTreHMin) < 1.0e-4) insert(items, SLDTREHMIN);
	if (compareDouble(SldTreHMax, comp->SldTreHMax) < 1.0e-4) insert(items, SLDTREHMAX);
	if (compareDouble(SldTreVMin, comp->SldTreVMin) < 1.0e-4) insert(items, SLDTREVMIN);
	if (compareDouble(SldTreVMax, comp->SldTreVMax) < 1.0e-4) insert(items, SLDTREVMAX);
	if (ButPlayActive == comp->ButPlayActive) insert(items, BUTPLAYACTIVE);
	if (ButStopActive == comp->ButStopActive) insert(items, BUTSTOPACTIVE);
	if (TxtAoaAvail == comp->TxtAoaAvail) insert(items, TXTAOAAVAIL);
	if (ButAstActive == comp->ButAstActive) insert(items, BUTASTACTIVE);

	return(items);
};

set<uint> PnlWzskLiv3DView::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTREHMIN, SLDTREHMAX, SLDTREVMIN, SLDTREVMAX, BUTPLAYACTIVE, BUTSTOPACTIVE, TXTAOAAVAIL, BUTASTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv3DView::Tag
 ******************************************************************************/

PnlWzskLiv3DView::Tag::Tag(
			const string& Cpt
			, const string& HdgAcq
			, const string& CptAst
			, const string& CptAoa
			, const string& ButAst
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->HdgAcq = HdgAcq;
	this->CptAst = CptAst;
	this->CptAoa = CptAoa;
	this->ButAst = ButAst;

	mask = {CPT, HDGACQ, CPTAST, CPTAOA, BUTAST};
};

bool PnlWzskLiv3DView::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLiv3DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLiv3DView";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgAcq", HdgAcq)) add(HDGACQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAst", CptAst)) add(CPTAST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAoa", CptAoa)) add(CPTAOA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButAst", ButAst)) add(BUTAST);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLiv3DView::DpchAppDo
 ******************************************************************************/

PnlWzskLiv3DView::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskLiv3DView::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv3DView::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLiv3DViewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv3DView::DpchEngData
 ******************************************************************************/

PnlWzskLiv3DView::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV3DVIEWDATA)
		{
};

string PnlWzskLiv3DView::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv3DView::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLiv3DViewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};

/******************************************************************************
 class PnlWzskLiv3DView::DpchEngLive
 ******************************************************************************/

PnlWzskLiv3DView::DpchEngLive::DpchEngLive() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV3DVIEWLIVE)
		{
};

string PnlWzskLiv3DView::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(RNOTL)) ss.push_back("rNotL");
	if (has(X)) ss.push_back("x");
	if (has(Y)) ss.push_back("y");
	if (has(Z)) ss.push_back("z");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv3DView::DpchEngLive::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLiv3DViewLive");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractBoolvecUclc(docctx, basexpath, "rNotL", "", rNotL)) add(RNOTL);
		if (extractFloatvecUclc(docctx, basexpath, "x", "", x)) add(X);
		if (extractFloatvecUclc(docctx, basexpath, "y", "", y)) add(Y);
		if (extractFloatvecUclc(docctx, basexpath, "z", "", z)) add(Z);
	} else {
	};
};

