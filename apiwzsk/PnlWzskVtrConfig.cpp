/**
	* \file PnlWzskVtrConfig.cpp
	* API code for job PnlWzskVtrConfig (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskVtrConfig.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskVtrConfig::VecVDo
 ******************************************************************************/

uint PnlWzskVtrConfig::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;
	if (s == "butplayclick") return BUTPLAYCLICK;
	if (s == "butstopclick") return BUTSTOPCLICK;
	if (s == "butstaclick") return BUTSTACLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string PnlWzskVtrConfig::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTPLAYCLICK) return("ButPlayClick");
	if (ix == BUTSTOPCLICK) return("ButStopClick");
	if (ix == BUTSTACLICK) return("ButStaClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class PnlWzskVtrConfig::VecVMode
 ******************************************************************************/

uint PnlWzskVtrConfig::VecVMode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "gray") return GRAY;
	if (s == "rgb") return RGB;

	return(0);
};

string PnlWzskVtrConfig::VecVMode::getSref(
			const uint ix
		) {
	if (ix == GRAY) return("gray");
	if (ix == RGB) return("rgb");

	return("");
};

/******************************************************************************
 class PnlWzskVtrConfig::ContIac
 ******************************************************************************/

PnlWzskVtrConfig::ContIac::ContIac(
			const uint numFRbuMde
			, const double SldAsp
		) :
			Block()
			, numFRbuMde(numFRbuMde)
			, SldAsp(SldAsp)
		{
	mask = {NUMFRBUMDE, SLDASP};
};

bool PnlWzskVtrConfig::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskVtrConfig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskVtrConfig";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuMde", numFRbuMde)) add(NUMFRBUMDE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldAsp", SldAsp)) add(SLDASP);
	};

	return basefound;
};

void PnlWzskVtrConfig::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskVtrConfig";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskVtrConfig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFRbuMde", numFRbuMde);
		writeDoubleAttr(wr, itemtag, "sref", "SldAsp", SldAsp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskVtrConfig::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFRbuMde == comp->numFRbuMde) insert(items, NUMFRBUMDE);
	if (compareDouble(SldAsp, comp->SldAsp) < 1.0e-4) insert(items, SLDASP);

	return(items);
};

set<uint> PnlWzskVtrConfig::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFRBUMDE, SLDASP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskVtrConfig::ContIacAlign
 ******************************************************************************/

PnlWzskVtrConfig::ContIacAlign::ContIacAlign(
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

bool PnlWzskVtrConfig::ContIacAlign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskVtrConfigAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskVtrConfigAlign";

	if (basefound) {
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiX0", roiX0)) add(ROIX0);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiY0", roiY0)) add(ROIY0);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiX1", roiX1)) add(ROIX1);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiY1", roiY1)) add(ROIY1);
	};

	return basefound;
};

void PnlWzskVtrConfig::ContIacAlign::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskVtrConfigAlign";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskVtrConfigAlign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeIntAttr(wr, itemtag, "sref", "roiX0", roiX0);
		writeIntAttr(wr, itemtag, "sref", "roiY0", roiY0);
		writeIntAttr(wr, itemtag, "sref", "roiX1", roiX1);
		writeIntAttr(wr, itemtag, "sref", "roiY1", roiY1);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskVtrConfig::ContIacAlign::comm(
			const ContIacAlign* comp
		) {
	set<uint> items;

	if (roiX0 == comp->roiX0) insert(items, ROIX0);
	if (roiY0 == comp->roiY0) insert(items, ROIY0);
	if (roiX1 == comp->roiX1) insert(items, ROIX1);
	if (roiY1 == comp->roiY1) insert(items, ROIY1);

	return(items);
};

set<uint> PnlWzskVtrConfig::ContIacAlign::diff(
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
 class PnlWzskVtrConfig::ContInf
 ******************************************************************************/

PnlWzskVtrConfig::ContInf::ContInf(
			const bool ButClaimOn
			, const string& TxtSte
		) :
			Block()
			, ButClaimOn(ButClaimOn)
			, TxtSte(TxtSte)
		{
	mask = {BUTCLAIMON, TXTSTE};
};

bool PnlWzskVtrConfig::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskVtrConfig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskVtrConfig";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButClaimOn", ButClaimOn)) add(BUTCLAIMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSte", TxtSte)) add(TXTSTE);
	};

	return basefound;
};

set<uint> PnlWzskVtrConfig::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtSte == comp->TxtSte) insert(items, TXTSTE);

	return(items);
};

set<uint> PnlWzskVtrConfig::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCLAIMON, TXTSTE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskVtrConfig::StatShr
 ******************************************************************************/

PnlWzskVtrConfig::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const uint CusImgHeight
			, const bool ButPlayActive
			, const bool ButStopActive
			, const bool SldAspActive
			, const double SldAspMin
			, const double SldAspMax
			, const bool ButStaActive
			, const bool ButStoActive
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, ButClaimActive(ButClaimActive)
			, CusImgHeight(CusImgHeight)
			, ButPlayActive(ButPlayActive)
			, ButStopActive(ButStopActive)
			, SldAspActive(SldAspActive)
			, SldAspMin(SldAspMin)
			, SldAspMax(SldAspMax)
			, ButStaActive(ButStaActive)
			, ButStoActive(ButStoActive)
		{
	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, CUSIMGHEIGHT, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDASPACTIVE, SLDASPMIN, SLDASPMAX, BUTSTAACTIVE, BUTSTOACTIVE};
};

bool PnlWzskVtrConfig::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskVtrConfig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskVtrConfig";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClaimActive", ButClaimActive)) add(BUTCLAIMACTIVE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "CusImgHeight", CusImgHeight)) add(CUSIMGHEIGHT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPlayActive", ButPlayActive)) add(BUTPLAYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStopActive", ButStopActive)) add(BUTSTOPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldAspActive", SldAspActive)) add(SLDASPACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldAspMin", SldAspMin)) add(SLDASPMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldAspMax", SldAspMax)) add(SLDASPMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStaActive", ButStaActive)) add(BUTSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskVtrConfig::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (CusImgHeight == comp->CusImgHeight) insert(items, CUSIMGHEIGHT);
	if (ButPlayActive == comp->ButPlayActive) insert(items, BUTPLAYACTIVE);
	if (ButStopActive == comp->ButStopActive) insert(items, BUTSTOPACTIVE);
	if (SldAspActive == comp->SldAspActive) insert(items, SLDASPACTIVE);
	if (compareDouble(SldAspMin, comp->SldAspMin) < 1.0e-4) insert(items, SLDASPMIN);
	if (compareDouble(SldAspMax, comp->SldAspMax) < 1.0e-4) insert(items, SLDASPMAX);
	if (ButStaActive == comp->ButStaActive) insert(items, BUTSTAACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> PnlWzskVtrConfig::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, CUSIMGHEIGHT, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDASPACTIVE, SLDASPMIN, SLDASPMAX, BUTSTAACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskVtrConfig::Tag
 ******************************************************************************/

PnlWzskVtrConfig::Tag::Tag(
			const string& Cpt
			, const string& HdgPvw
			, const string& CptMde
			, const string& CptAsp
			, const string& CptSte
			, const string& ButSta
			, const string& ButSto
		) :
			Block()
			, Cpt(Cpt)
			, HdgPvw(HdgPvw)
			, CptMde(CptMde)
			, CptAsp(CptAsp)
			, CptSte(CptSte)
			, ButSta(ButSta)
			, ButSto(ButSto)
		{
	mask = {CPT, HDGPVW, CPTMDE, CPTASP, CPTSTE, BUTSTA, BUTSTO};
};

bool PnlWzskVtrConfig::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskVtrConfig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskVtrConfig";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgPvw", HdgPvw)) add(HDGPVW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMde", CptMde)) add(CPTMDE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAsp", CptAsp)) add(CPTASP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSta", ButSta)) add(BUTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskVtrConfig::DpchAppAlign
 ******************************************************************************/

PnlWzskVtrConfig::DpchAppAlign::DpchAppAlign(
			const string& scrJref
			, ContIacAlign* contiacalign
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRCONFIGALIGN, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIACALIGN};
	else this->mask = mask;

		if (find(this->mask, CONTIACALIGN) && contiacalign) this->contiacalign = *contiacalign;
};

string PnlWzskVtrConfig::DpchAppAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIACALIGN)) ss.push_back("contiacalign");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchAppAlign::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskVtrConfigAlign");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIACALIGN)) contiacalign.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrConfig::DpchAppData
 ******************************************************************************/

PnlWzskVtrConfig::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRCONFIGDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskVtrConfig::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskVtrConfigData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrConfig::DpchAppDo
 ******************************************************************************/

PnlWzskVtrConfig::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRCONFIGDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskVtrConfig::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskVtrConfigDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrConfig::DpchEngAlign
 ******************************************************************************/

PnlWzskVtrConfig::DpchEngAlign::DpchEngAlign() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRCONFIGALIGN)
		{
};

string PnlWzskVtrConfig::DpchEngAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIACALIGN)) ss.push_back("contiacalign");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchEngAlign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskVtrConfigAlign");
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
 class PnlWzskVtrConfig::DpchEngData
 ******************************************************************************/

PnlWzskVtrConfig::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRCONFIGDATA)
		{
	feedFRbuMde.tag = "FeedFRbuMde";
};

string PnlWzskVtrConfig::DpchEngData::getSrefsMask() {
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

void PnlWzskVtrConfig::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskVtrConfigData");
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
 class PnlWzskVtrConfig::DpchEngLive
 ******************************************************************************/

PnlWzskVtrConfig::DpchEngLive::DpchEngLive() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRCONFIGLIVE)
		{
};

string PnlWzskVtrConfig::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(GRAY)) ss.push_back("gray");
	if (has(RGB)) ss.push_back("rgb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchEngLive::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskVtrConfigLive");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUtinyintvecUclc(docctx, basexpath, "gray", "", gray)) add(GRAY);
		if (extractUtinyintvecUclc(docctx, basexpath, "rgb", "", rgb)) add(RGB);
	} else {
	};
};
