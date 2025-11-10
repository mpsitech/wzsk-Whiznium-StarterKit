/**
	* \file PnlWzskHwcConfig_blks.cpp
	* job handler for job PnlWzskHwcConfig (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

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

string PnlWzskHwcConfig::VecVMode::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == GRAY) return("grayscale");
		if (ix == RGB) return("RGB");
		return(getSref(ix));
	};

	return("");
};

void PnlWzskHwcConfig::VecVMode::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
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

bool PnlWzskHwcConfig::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskHwcConfig"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFRbuMde")) {numFRbuMde = me["numFRbuMde"].asUInt(); add(NUMFRBUMDE);};
		if (me.isMember("UpdNfr")) {UpdNfr = me["UpdNfr"].asInt(); add(UPDNFR);};
		if (me.isMember("SldFst")) {SldFst = me["SldFst"].asDouble(); add(SLDFST);};
		if (me.isMember("SldFsp")) {SldFsp = me["SldFsp"].asDouble(); add(SLDFSP);};
	};

	return basefound;
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

void PnlWzskHwcConfig::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskHwcConfig";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFRbuMde"] = (Json::Value::UInt) numFRbuMde;
	me["UpdNfr"] = (Json::Value::Int) UpdNfr;
	me["SldFst"] = SldFst;
	me["SldFsp"] = SldFsp;
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

bool PnlWzskHwcConfig::ContIacAlign::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskHwcConfigAlign"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("roiX0")) {roiX0 = me["roiX0"].asInt(); add(ROIX0);};
		if (me.isMember("roiY0")) {roiY0 = me["roiY0"].asInt(); add(ROIY0);};
		if (me.isMember("roiX1")) {roiX1 = me["roiX1"].asInt(); add(ROIX1);};
		if (me.isMember("roiY1")) {roiY1 = me["roiY1"].asInt(); add(ROIY1);};
	};

	return basefound;
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

void PnlWzskHwcConfig::ContIacAlign::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskHwcConfigAlign";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["roiX0"] = (Json::Value::Int) roiX0;
	me["roiY0"] = (Json::Value::Int) roiY0;
	me["roiX1"] = (Json::Value::Int) roiX1;
	me["roiY1"] = (Json::Value::Int) roiY1;
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
			, const string& TxtSte
		) :
			Block()
			, ButClaimOn(ButClaimOn)
			, TxtSte(TxtSte)
		{
	mask = {BUTCLAIMON, TXTSTE};
};

void PnlWzskHwcConfig::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskHwcConfig";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButClaimOn"] = ButClaimOn;
	me["TxtSte"] = TxtSte;
};

void PnlWzskHwcConfig::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskHwcConfig";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskHwcConfig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButClaimOn", ButClaimOn);
		writeStringAttr(wr, itemtag, "sref", "TxtSte", TxtSte);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskHwcConfig::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtSte == comp->TxtSte) insert(items, TXTSTE);

	return(items);
};

set<uint> PnlWzskHwcConfig::ContInf::diff(
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
 class PnlWzskHwcConfig::StatShr
 ******************************************************************************/

PnlWzskHwcConfig::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool RbuMdeActive
			, const uint CusImgHeight
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
			, RbuMdeActive(RbuMdeActive)
			, CusImgHeight(CusImgHeight)
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
	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, RBUMDEACTIVE, CUSIMGHEIGHT, UPDNFRACTIVE, UPDNFRMIN, UPDNFRMAX, SLDFSTACTIVE, SLDFSTMIN, SLDFSTMAX, SLDFSPACTIVE, SLDFSPMIN, SLDFSPMAX, BUTSTAACTIVE, BUTSTOACTIVE};
};

void PnlWzskHwcConfig::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskHwcConfig";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["ButClaimActive"] = ButClaimActive;
	me["RbuMdeActive"] = RbuMdeActive;
	me["CusImgHeight"] = (Json::Value::UInt) CusImgHeight;
	me["UpdNfrActive"] = UpdNfrActive;
	me["UpdNfrMin"] = (Json::Value::Int) UpdNfrMin;
	me["UpdNfrMax"] = (Json::Value::Int) UpdNfrMax;
	me["SldFstActive"] = SldFstActive;
	me["SldFstMin"] = SldFstMin;
	me["SldFstMax"] = SldFstMax;
	me["SldFspActive"] = SldFspActive;
	me["SldFspMin"] = SldFspMin;
	me["SldFspMax"] = SldFspMax;
	me["ButStaActive"] = ButStaActive;
	me["ButStoActive"] = ButStoActive;
};

void PnlWzskHwcConfig::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskHwcConfig";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskHwcConfig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButClaimActive", ButClaimActive);
		writeBoolAttr(wr, itemtag, "sref", "RbuMdeActive", RbuMdeActive);
		writeUintAttr(wr, itemtag, "sref", "CusImgHeight", CusImgHeight);
		writeBoolAttr(wr, itemtag, "sref", "UpdNfrActive", UpdNfrActive);
		writeIntAttr(wr, itemtag, "sref", "UpdNfrMin", UpdNfrMin);
		writeIntAttr(wr, itemtag, "sref", "UpdNfrMax", UpdNfrMax);
		writeBoolAttr(wr, itemtag, "sref", "SldFstActive", SldFstActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldFstMin", SldFstMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldFstMax", SldFstMax);
		writeBoolAttr(wr, itemtag, "sref", "SldFspActive", SldFspActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldFspMin", SldFspMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldFspMax", SldFspMax);
		writeBoolAttr(wr, itemtag, "sref", "ButStaActive", ButStaActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskHwcConfig::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (RbuMdeActive == comp->RbuMdeActive) insert(items, RBUMDEACTIVE);
	if (CusImgHeight == comp->CusImgHeight) insert(items, CUSIMGHEIGHT);
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

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, RBUMDEACTIVE, CUSIMGHEIGHT, UPDNFRACTIVE, UPDNFRMIN, UPDNFRMAX, SLDFSTACTIVE, SLDFSTMIN, SLDFSTMAX, SLDFSPACTIVE, SLDFSPMIN, SLDFSPMAX, BUTSTAACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskHwcConfig::Tag
 ******************************************************************************/

void PnlWzskHwcConfig::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskHwcConfig";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Configuration";
		me["HdgPvw"] = "Preview and ROI";
		me["CptMde"] = "mode";
		me["CptNfr"] = "frequencies";
		me["CptFst"] = "start frequency";
		me["CptFsp"] = "stop frequency";
		me["CptSte"] = "state";
		me["ButSta"] = "Start";
		me["ButSto"] = "Stop";
	};
};

void PnlWzskHwcConfig::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskHwcConfig";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskHwcConfig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Configuration");
			writeStringAttr(wr, itemtag, "sref", "HdgPvw", "Preview and ROI");
			writeStringAttr(wr, itemtag, "sref", "CptMde", "mode");
			writeStringAttr(wr, itemtag, "sref", "CptNfr", "frequencies");
			writeStringAttr(wr, itemtag, "sref", "CptFst", "start frequency");
			writeStringAttr(wr, itemtag, "sref", "CptFsp", "stop frequency");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "ButSta", "Start");
			writeStringAttr(wr, itemtag, "sref", "ButSto", "Stop");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchAppAlign
 ******************************************************************************/

PnlWzskHwcConfig::DpchAppAlign::DpchAppAlign() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCCONFIGALIGN)
		{
};

string PnlWzskHwcConfig::DpchAppAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIACALIGN)) ss.push_back("contiacalign");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchAppAlign::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskHwcConfigAlign"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiacalign.readJSON(me, true)) add(CONTIACALIGN);
	} else {
		contiacalign = ContIacAlign();
	};
};

void PnlWzskHwcConfig::DpchAppAlign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskHwcConfigAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiacalign.readXML(docctx, basexpath, true)) add(CONTIACALIGN);
	} else {
		contiacalign = ContIacAlign();
	};
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchAppData
 ******************************************************************************/

PnlWzskHwcConfig::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCCONFIGDATA)
		{
};

string PnlWzskHwcConfig::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskHwcConfigData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskHwcConfig::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskHwcConfigData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchAppDo
 ******************************************************************************/

PnlWzskHwcConfig::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKHWCCONFIGDO)
		{
	ixVDo = 0;
};

string PnlWzskHwcConfig::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskHwcConfigDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskHwcConfig::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskHwcConfigDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchEngAlign
 ******************************************************************************/

PnlWzskHwcConfig::DpchEngAlign::DpchEngAlign(
			const ubigint jref
			, ContIacAlign* contiacalign
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKHWCCONFIGALIGN, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIACALIGN};
	else this->mask = mask;

	if (find(this->mask, CONTIACALIGN) && contiacalign) this->contiacalign = *contiacalign;
};

string PnlWzskHwcConfig::DpchEngAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIACALIGN)) ss.push_back("contiacalign");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchEngAlign::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngAlign* src = (DpchEngAlign*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIACALIGN)) {contiacalign = src->contiacalign; add(CONTIACALIGN);};
};

void PnlWzskHwcConfig::DpchEngAlign::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskHwcConfigAlign"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIACALIGN)) contiacalign.writeJSON(me);
};

void PnlWzskHwcConfig::DpchEngAlign::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskHwcConfigAlign");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIACALIGN)) contiacalign.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchEngData
 ******************************************************************************/

PnlWzskHwcConfig::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFRbuMde
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKHWCCONFIGDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFRBUMDE, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFRBUMDE) && feedFRbuMde) this->feedFRbuMde = *feedFRbuMde;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskHwcConfig::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFRBUMDE)) ss.push_back("feedFRbuMde");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFRBUMDE)) {feedFRbuMde = src->feedFRbuMde; add(FEEDFRBUMDE);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskHwcConfig::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskHwcConfigData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFRBUMDE)) feedFRbuMde.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskHwcConfig::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskHwcConfigData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFRBUMDE)) feedFRbuMde.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskHwcConfig::DpchEngLive
 ******************************************************************************/

PnlWzskHwcConfig::DpchEngLive::DpchEngLive(
			const ubigint jref
			, const vector<utinyint>& gray
			, const vector<utinyint>& red
			, const vector<utinyint>& green
			, const vector<utinyint>& blue
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKHWCCONFIGLIVE, jref)
			, gray(gray)
			, red(red)
			, green(green)
			, blue(blue)
		{
	if (find(mask, ALL)) this->mask = {JREF, GRAY, RED, GREEN, BLUE};
	else this->mask = mask;

};

string PnlWzskHwcConfig::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(GRAY)) ss.push_back("gray");
	if (has(RED)) ss.push_back("red");
	if (has(GREEN)) ss.push_back("green");
	if (has(BLUE)) ss.push_back("blue");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskHwcConfig::DpchEngLive::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(GRAY)) {gray = src->gray; add(GRAY);};
	if (src->has(RED)) {red = src->red; add(RED);};
	if (src->has(GREEN)) {green = src->green; add(GREEN);};
	if (src->has(BLUE)) {blue = src->blue; add(BLUE);};
};

void PnlWzskHwcConfig::DpchEngLive::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskHwcConfigLive"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(GRAY)) Jsonio::writeUtinyintvec(me, "gray", gray);
	if (has(RED)) Jsonio::writeUtinyintvec(me, "red", red);
	if (has(GREEN)) Jsonio::writeUtinyintvec(me, "green", green);
	if (has(BLUE)) Jsonio::writeUtinyintvec(me, "blue", blue);
};

void PnlWzskHwcConfig::DpchEngLive::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskHwcConfigLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(GRAY)) writeUtinyintvec(wr, "gray", gray);
		if (has(RED)) writeUtinyintvec(wr, "red", red);
		if (has(GREEN)) writeUtinyintvec(wr, "green", green);
		if (has(BLUE)) writeUtinyintvec(wr, "blue", blue);
	xmlTextWriterEndElement(wr);
};
