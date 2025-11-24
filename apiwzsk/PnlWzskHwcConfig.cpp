/**
	* \file PnlWzskHwcConfig.cpp
	* API code for job PnlWzskHwcConfig (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskHwcConfig.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskHwcConfig::VecVDo
 ******************************************************************************/

uint PnlWzskHwcConfig::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;
	if (s == "butplayclick") return BUTPLAYCLICK;
	if (s == "butstopclick") return BUTSTOPCLICK;
	if (s == "butsnapclick") return BUTSNAPCLICK;
	if (s == "butpfiviewclick") return BUTPFIVIEWCLICK;
	if (s == "butstaclick") return BUTSTACLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string PnlWzskHwcConfig::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTPLAYCLICK) return("ButPlayClick");
	if (ix == BUTSTOPCLICK) return("ButStopClick");
	if (ix == BUTSNAPCLICK) return("ButSnapClick");
	if (ix == BUTPFIVIEWCLICK) return("ButPfiViewClick");
	if (ix == BUTSTACLICK) return("ButStaClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class PnlWzskHwcConfig::VecVMode
 ******************************************************************************/

uint PnlWzskHwcConfig::VecVMode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "gray") return GRAY;
	if (s == "rgb") return RGB;

	return(0);
};

string PnlWzskHwcConfig::VecVMode::getSref(
			const uint ix
		) {
	if (ix == GRAY) return("gray");
	if (ix == RGB) return("rgb");

	return("");
};

/******************************************************************************
 class PnlWzskHwcConfig::VecVSge
 ******************************************************************************/

uint PnlWzskHwcConfig::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "capture") return CAPTURE;
	if (s == "stoidle") return STOIDLE;
	if (s == "store") return STORE;

	return(0);
};

string PnlWzskHwcConfig::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CAPTURE) return("capture");
	if (ix == STOIDLE) return("stoidle");
	if (ix == STORE) return("store");

	return("");
};

/******************************************************************************
 class PnlWzskHwcConfig::ContIac
 ******************************************************************************/

PnlWzskHwcConfig::ContIac::ContIac(
			const uint numFRbuMde
			, const int UpdNfr
			, const double SldFst
			, const double SldFsp
		) :
			Block()
			, numFRbuMde(numFRbuMde)
			, UpdNfr(UpdNfr)
			, SldFst(SldFst)
			, SldFsp(SldFsp)
		{
	mask = {NUMFRBUMDE, UPDNFR, SLDFST, SLDFSP};
};

bool PnlWzskHwcConfig::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskHwcConfig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskHwcConfig";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuMde", numFRbuMde)) add(NUMFRBUMDE);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdNfr", UpdNfr)) add(UPDNFR);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFst", SldFst)) add(SLDFST);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFsp", SldFsp)) add(SLDFSP);
	};

	return basefound;
};

void PnlWzskHwcConfig::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskHwcConfig";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskHwcConfig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFRbuMde", numFRbuMde);
		writeIntAttr(wr, itemtag, "sref", "UpdNfr", UpdNfr);
		writeDoubleAttr(wr, itemtag, "sref", "SldFst", SldFst);
		writeDoubleAttr(wr, itemtag, "sref", "SldFsp", SldFsp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskHwcConfig::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFRbuMde == comp->numFRbuMde) insert(items, NUMFRBUMDE);
	if (UpdNfr == comp->UpdNfr) insert(items, UPDNFR);
	if (compareDouble(SldFst, comp->SldFst) < 1.0e-4) insert(items, SLDFST);
	if (compareDouble(SldFsp, comp->SldFsp) < 1.0e-4) insert(items, SLDFSP);

	return(items);
};

set<uint> PnlWzskHwcConfig::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFRBUMDE, UPDNFR, SLDFST, SLDFSP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskHwcConfig::ContIacAlign
 ******************************************************************************/

PnlWzskHwcConfig::ContIacAlign::ContIacAlign(
			const int roiX0
			, const int roiY0
			, const int roiX1
			, const int roiY1
		) :
			Block()
			, roiX0(roiX0)
			, roiY0(roiY0)
			, roiX1(roiX1)
			, roiY1(roiY1)
		{
	mask = {ROIX0, ROIY0, ROIX1, ROIY1};
};

bool PnlWzskHwcConfig::ContIacAlign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskHwcConfigAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskHwcConfigAlign";

	if (basefound) {
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiX0", roiX0)) add(ROIX0);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiY0", roiY0)) add(ROIY0);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiX1", roiX1)) add(ROIX1);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiY1", roiY1)) add(ROIY1);
	};

	return basefound;
};

void PnlWzskHwcConfig::ContIacAlign::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskHwcConfigAlign";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskHwcConfigAlign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeIntAttr(wr, itemtag, "sref", "roiX0", roiX0);
		writeIntAttr(wr, itemtag, "sref", "roiY0", roiY0);
		writeIntAttr(wr, itemtag, "sref", "roiX1", roiX1);
		writeIntAttr(wr, itemtag, "sref", "roiY1", roiY1);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskHwcConfig::ContIacAlign::comm(
			const ContIacAlign* comp
		) {
	set<uint> items;

	if (roiX0 == comp->roiX0) insert(items, ROIX0);
	if (roiY0 == comp->roiY0) insert(items, ROIY0);
	if (roiX1 == comp->roiX1) insert(items, ROIX1);
	if (roiY1 == comp->roiY1) insert(items, ROIY1);

	return(items);
};

set<uint> PnlWzskHwcConfig::ContIacAlign::diff(
			const ContIacAlign* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ROIX0, ROIY0, ROIX1, ROIY1};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskHwcConfig::ContInf
 ******************************************************************************/

PnlWzskHwcConfig::ContInf::ContInf(
			const bool ButClaimOn
			, const string& TxtPfi
			, const string& TxtSte
		) :
			Block()
			, ButClaimOn(ButClaimOn)
			, TxtPfi(TxtPfi)
			, TxtSte(TxtSte)
		{
	mask = {BUTCLAIMON, TXTPFI, TXTSTE};
};

bool PnlWzskHwcConfig::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskHwcConfig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskHwcConfig";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButClaimOn", ButClaimOn)) add(BUTCLAIMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPfi", TxtPfi)) add(TXTPFI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSte", TxtSte)) add(TXTSTE);
	};

	return basefound;
};

set<uint> PnlWzskHwcConfig::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtPfi == comp->TxtPfi) insert(items, TXTPFI);
	if (TxtSte == comp->TxtSte) insert(items, TXTSTE);

	return(items);
};

set<uint> PnlWzskHwcConfig::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCLAIMON, TXTPFI, TXTSTE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskHwcConfig::StatShr
 ******************************************************************************/

PnlWzskHwcConfig::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const uint CusImgHeight
			, const bool ButPlayActive
			, const bool ButStopActive
			, const bool ButSnapActive
			, const bool ButPfiViewActive
			, const bool UpdNfrActive
			, const int UpdNfrMin
			, const int UpdNfrMax
			, const bool SldFstActive
			, const double SldFstMin
			, const double SldFstMax
			, const bool SldFspActive
			, const double SldFspMin
			, const double SldFspMax
			, const bool ButStaActive
			, const bool ButStoActive
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, ButClaimActive(ButClaimActive)
			, CusImgHeight(CusImgHeight)
			, ButPlayActive(ButPlayActive)
			, ButStopActive(ButStopActive)
			, ButSnapActive(ButSnapActive)
			, ButPfiViewActive(ButPfiViewActive)
			, UpdNfrActive(UpdNfrActive)
			, UpdNfrMin(UpdNfrMin)
			, UpdNfrMax(UpdNfrMax)
			, SldFstActive(SldFstActive)
			, SldFstMin(SldFstMin)
			, SldFstMax(SldFstMax)
			, SldFspActive(SldFspActive)
			, SldFspMin(SldFspMin)
			, SldFspMax(SldFspMax)
			, ButStaActive(ButStaActive)
			, ButStoActive(ButStoActive)
		{
	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, CUSIMGHEIGHT, BUTPLAYACTIVE, BUTSTOPACTIVE, BUTSNAPACTIVE, BUTPFIVIEWACTIVE, UPDNFRACTIVE, UPDNFRMIN, UPDNFRMAX, SLDFSTACTIVE, SLDFSTMIN, SLDFSTMAX, SLDFSPACTIVE, SLDFSPMIN, SLDFSPMAX, BUTSTAACTIVE, BUTSTOACTIVE};
};

bool PnlWzskHwcConfig::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskHwcConfig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskHwcConfig";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClaimActive", ButClaimActive)) add(BUTCLAIMACTIVE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "CusImgHeight", CusImgHeight)) add(CUSIMGHEIGHT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPlayActive", ButPlayActive)) add(BUTPLAYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStopActive", ButStopActive)) add(BUTSTOPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSnapActive", ButSnapActive)) add(BUTSNAPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPfiViewActive", ButPfiViewActive)) add(BUTPFIVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdNfrActive", UpdNfrActive)) add(UPDNFRACTIVE);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdNfrMin", UpdNfrMin)) add(UPDNFRMIN);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdNfrMax", UpdNfrMax)) add(UPDNFRMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFstActive", SldFstActive)) add(SLDFSTACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFstMin", SldFstMin)) add(SLDFSTMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFstMax", SldFstMax)) add(SLDFSTMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFspActive", SldFspActive)) add(SLDFSPACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFspMin", SldFspMin)) add(SLDFSPMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFspMax", SldFspMax)) add(SLDFSPMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStaActive", ButStaActive)) add(BUTSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskHwcConfig::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (CusImgHeight == comp->CusImgHeight) insert(items, CUSIMGHEIGHT);
	if (ButPlayActive == comp->ButPlayActive) insert(items, BUTPLAYACTIVE);
	if (ButStopActive == comp->ButStopActive) insert(items, BUTSTOPACTIVE);
	if (ButSnapActive == comp->ButSnapActive) insert(items, BUTSNAPACTIVE);
	if (ButPfiViewActive == comp->ButPfiViewActive) insert(items, BUTPFIVIEWACTIVE);
	if (UpdNfrActive == comp->UpdNfrActive) insert(items, UPDNFRACTIVE);
	if (UpdNfrMin == comp->UpdNfrMin) insert(items, UPDNFRMIN);
	if (UpdNfrMax == comp->UpdNfrMax) insert(items, UPDNFRMAX);
	if (SldFstActive == comp->SldFstActive) insert(items, SLDFSTACTIVE);
	if (compareDouble(SldFstMin, comp->SldFstMin) < 1.0e-4) insert(items, SLDFSTMIN);
	if (compareDouble(SldFstMax, comp->SldFstMax) < 1.0e-4) insert(items, SLDFSTMAX);
	if (SldFspActive == comp->SldFspActive) insert(items, SLDFSPACTIVE);
	if (compareDouble(SldFspMin, comp->SldFspMin) < 1.0e-4) insert(items, SLDFSPMIN);
	if (compareDouble(SldFspMax, comp->SldFspMax) < 1.0e-4) insert(items, SLDFSPMAX);
	if (ButStaActive == comp->ButStaActive) insert(items, BUTSTAACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> PnlWzskHwcConfig::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, CUSIMGHEIGHT, BUTPLAYACTIVE, BUTSTOPACTIVE, BUTSNAPACTIVE, BUTPFIVIEWACTIVE, UPDNFRACTIVE, UPDNFRMIN, UPDNFRMAX, SLDFSTACTIVE, SLDFSTMIN, SLDFSTMAX, SLDFSPACTIVE, SLDFSPMIN, SLDFSPMAX, BUTSTAACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskHwcConfig::Tag
 ******************************************************************************/

PnlWzskHwcConfig::Tag::Tag(
			const string& Cpt
			, const string& HdgPvw
			, const string& CptMde
			, const string& CptPfi
			, const string& CptNfr
			, const string& CptFst
			, const string& CptFsp
			, const string& CptSte
			, const string& ButSta
			, const string& ButSto
		) :
			Block()
			, Cpt(Cpt)
			, HdgPvw(HdgPvw)
			, CptMde(CptMde)
			, CptPfi(CptPfi)
			, CptNfr(CptNfr)
			, CptFst(CptFst)
			, CptFsp(CptFsp)
			, CptSte(CptSte)
			, ButSta(ButSta)
			, ButSto(ButSto)
		{
	mask = {CPT, HDGPVW, CPTMDE, CPTPFI, CPTNFR, CPTFST, CPTFSP, CPTSTE, BUTSTA, BUTSTO};
};

bool PnlWzskHwcConfig::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskHwcConfig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskHwcConfig";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgPvw", HdgPvw)) add(HDGPVW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMde", CptMde)) add(CPTMDE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPfi", CptPfi)) add(CPTPFI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptNfr", CptNfr)) add(CPTNFR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFst", CptFst)) add(CPTFST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFsp", CptFsp)) add(CPTFSP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSta", ButSta)) add(BUTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchAppAlign
 ******************************************************************************/

PnlWzskHwcConfig::DpchAppAlign::DpchAppAlign(
			const string& scrJref
			, ContIacAlign* contiacalign
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCCONFIGALIGN, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIACALIGN};
	else this->mask = mask;

		if (find(this->mask, CONTIACALIGN) && contiacalign) this->contiacalign = *contiacalign;
};

string PnlWzskHwcConfig::DpchAppAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIACALIGN)) ss.push_back("contiacalign");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchAppAlign::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskHwcConfigAlign");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIACALIGN)) contiacalign.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchAppData
 ******************************************************************************/

PnlWzskHwcConfig::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCCONFIGDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskHwcConfig::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskHwcConfigData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchAppDo
 ******************************************************************************/

PnlWzskHwcConfig::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCCONFIGDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskHwcConfig::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskHwcConfigDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchEngAlign
 ******************************************************************************/

PnlWzskHwcConfig::DpchEngAlign::DpchEngAlign() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKHWCCONFIGALIGN)
		{
};

string PnlWzskHwcConfig::DpchEngAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIACALIGN)) ss.push_back("contiacalign");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchEngAlign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskHwcConfigAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiacalign.readXML(docctx, basexpath, true)) add(CONTIACALIGN);
	} else {
		contiacalign = ContIacAlign();
	};
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchEngData
 ******************************************************************************/

PnlWzskHwcConfig::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKHWCCONFIGDATA)
		{
	feedFRbuMde.tag = "FeedFRbuMde";
};

string PnlWzskHwcConfig::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFRBUMDE)) ss.push_back("feedFRbuMde");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskHwcConfigData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFRbuMde.readXML(docctx, basexpath, true)) add(FEEDFRBUMDE);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFRbuMde.clear();
		statshr = StatShr();
		tag = Tag();
	};
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchEngLive
 ******************************************************************************/

PnlWzskHwcConfig::DpchEngLive::DpchEngLive() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKHWCCONFIGLIVE)
		{
};

string PnlWzskHwcConfig::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(GRAY)) ss.push_back("gray");
	if (has(RGB)) ss.push_back("rgb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchEngLive::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskHwcConfigLive");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUtinyintvecUclc(docctx, basexpath, "gray", "", gray)) add(GRAY);
		if (extractUtinyintvecUclc(docctx, basexpath, "rgb", "", rgb)) add(RGB);
	} else {
	};
};
