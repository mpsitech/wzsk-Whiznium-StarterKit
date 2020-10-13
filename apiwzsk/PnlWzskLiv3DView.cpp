/**
	* \file PnlWzskLiv3DView.cpp
	* API code for job PnlWzskLiv3DView (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
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
	if (s == "butasrclick") return BUTASRCLICK;
	if (s == "butairclick") return BUTAIRCLICK;

	return(0);
};

string PnlWzskLiv3DView::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTASRCLICK) return("ButAsrClick");
	if (ix == BUTAIRCLICK) return("ButAirClick");

	return("");
};

/******************************************************************************
 class PnlWzskLiv3DView::ContIac
 ******************************************************************************/

PnlWzskLiv3DView::ContIac::ContIac(
			const double SldAin
		) :
			Block()
		{
	this->SldAin = SldAin;

	mask = {SLDAIN};
};

bool PnlWzskLiv3DView::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLiv3DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLiv3DView";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldAin", SldAin)) add(SLDAIN);
	};

	return basefound;
};

void PnlWzskLiv3DView::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLiv3DView";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLiv3DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldAin", SldAin);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLiv3DView::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldAin, comp->SldAin) < 1.0e-4) insert(items, SLDAIN);

	return(items);
};

set<uint> PnlWzskLiv3DView::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDAIN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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
 class PnlWzskLiv3DView::StatApp
 ******************************************************************************/

PnlWzskLiv3DView::StatApp::StatApp(
			const bool ButPlayActive
			, const bool ButStopActive
		) :
			Block()
		{
	this->ButPlayActive = ButPlayActive;
	this->ButStopActive = ButStopActive;

	mask = {BUTPLAYACTIVE, BUTSTOPACTIVE};
};

bool PnlWzskLiv3DView::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskLiv3DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskLiv3DView";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPlayActive", ButPlayActive)) add(BUTPLAYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStopActive", ButStopActive)) add(BUTSTOPACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskLiv3DView::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ButPlayActive == comp->ButPlayActive) insert(items, BUTPLAYACTIVE);
	if (ButStopActive == comp->ButStopActive) insert(items, BUTSTOPACTIVE);

	return(items);
};

set<uint> PnlWzskLiv3DView::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTPLAYACTIVE, BUTSTOPACTIVE};
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
			, const bool SldAinActive
			, const double SldAinMin
			, const double SldAinMax
			, const double SldAinRast
			, const bool TxtAoaAvail
			, const bool ButAsrActive
			, const bool ButAirActive
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->ButClaimActive = ButClaimActive;
	this->SldTreHMin = SldTreHMin;
	this->SldTreHMax = SldTreHMax;
	this->SldTreVMin = SldTreVMin;
	this->SldTreVMax = SldTreVMax;
	this->SldAinActive = SldAinActive;
	this->SldAinMin = SldAinMin;
	this->SldAinMax = SldAinMax;
	this->SldAinRast = SldAinRast;
	this->TxtAoaAvail = TxtAoaAvail;
	this->ButAsrActive = ButAsrActive;
	this->ButAirActive = ButAirActive;

	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTREHMIN, SLDTREHMAX, SLDTREVMIN, SLDTREVMAX, SLDAINACTIVE, SLDAINMIN, SLDAINMAX, SLDAINRAST, TXTAOAAVAIL, BUTASRACTIVE, BUTAIRACTIVE};
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
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldAinActive", SldAinActive)) add(SLDAINACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldAinMin", SldAinMin)) add(SLDAINMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldAinMax", SldAinMax)) add(SLDAINMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldAinRast", SldAinRast)) add(SLDAINRAST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAoaAvail", TxtAoaAvail)) add(TXTAOAAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAsrActive", ButAsrActive)) add(BUTASRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAirActive", ButAirActive)) add(BUTAIRACTIVE);
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
	if (SldAinActive == comp->SldAinActive) insert(items, SLDAINACTIVE);
	if (compareDouble(SldAinMin, comp->SldAinMin) < 1.0e-4) insert(items, SLDAINMIN);
	if (compareDouble(SldAinMax, comp->SldAinMax) < 1.0e-4) insert(items, SLDAINMAX);
	if (compareDouble(SldAinRast, comp->SldAinRast) < 1.0e-4) insert(items, SLDAINRAST);
	if (TxtAoaAvail == comp->TxtAoaAvail) insert(items, TXTAOAAVAIL);
	if (ButAsrActive == comp->ButAsrActive) insert(items, BUTASRACTIVE);
	if (ButAirActive == comp->ButAirActive) insert(items, BUTAIRACTIVE);

	return(items);
};

set<uint> PnlWzskLiv3DView::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTREHMIN, SLDTREHMAX, SLDTREVMIN, SLDTREVMAX, SLDAINACTIVE, SLDAINMIN, SLDAINMAX, SLDAINRAST, TXTAOAAVAIL, BUTASRACTIVE, BUTAIRACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv3DView::Tag
 ******************************************************************************/

PnlWzskLiv3DView::Tag::Tag(
			const string& Cpt
			, const string& HdgAcq
			, const string& CptAin
			, const string& CptAst
			, const string& CptAoa
			, const string& ButAsr
			, const string& ButAir
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->HdgAcq = HdgAcq;
	this->CptAin = CptAin;
	this->CptAst = CptAst;
	this->CptAoa = CptAoa;
	this->ButAsr = ButAsr;
	this->ButAir = ButAir;

	mask = {CPT, HDGACQ, CPTAIN, CPTAST, CPTAOA, BUTASR, BUTAIR};
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
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAin", CptAin)) add(CPTAIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAst", CptAst)) add(CPTAST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAoa", CptAoa)) add(CPTAOA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButAsr", ButAsr)) add(BUTASR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButAir", ButAir)) add(BUTAIR);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLiv3DView::DpchAppData
 ******************************************************************************/

PnlWzskLiv3DView::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskLiv3DView::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv3DView::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLiv3DViewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
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
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
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
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statapp = StatApp();
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

