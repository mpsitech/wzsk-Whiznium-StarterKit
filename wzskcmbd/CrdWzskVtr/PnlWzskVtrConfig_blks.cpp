/**
	* \file PnlWzskVtrConfig_blks.cpp
	* job handler for job PnlWzskVtrConfig (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

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

string PnlWzskVtrConfig::VecVMode::getTitle(
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

void PnlWzskVtrConfig::VecVMode::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
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

bool PnlWzskVtrConfig::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskVtrConfig"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFRbuMde")) {numFRbuMde = me["numFRbuMde"].asUInt(); add(NUMFRBUMDE);};
		if (me.isMember("SldAsp")) {SldAsp = me["SldAsp"].asDouble(); add(SLDASP);};
	};

	return basefound;
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

void PnlWzskVtrConfig::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskVtrConfig";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFRbuMde"] = (Json::Value::UInt) numFRbuMde;
	me["SldAsp"] = SldAsp;
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

bool PnlWzskVtrConfig::ContIacAlign::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskVtrConfigAlign"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("roiX0")) {roiX0 = me["roiX0"].asInt(); add(ROIX0);};
		if (me.isMember("roiY0")) {roiY0 = me["roiY0"].asInt(); add(ROIY0);};
		if (me.isMember("roiX1")) {roiX1 = me["roiX1"].asInt(); add(ROIX1);};
		if (me.isMember("roiY1")) {roiY1 = me["roiY1"].asInt(); add(ROIY1);};
	};

	return basefound;
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

void PnlWzskVtrConfig::ContIacAlign::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskVtrConfigAlign";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["roiX0"] = (Json::Value::Int) roiX0;
	me["roiY0"] = (Json::Value::Int) roiY0;
	me["roiX1"] = (Json::Value::Int) roiX1;
	me["roiY1"] = (Json::Value::Int) roiY1;
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

void PnlWzskVtrConfig::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskVtrConfig";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButClaimOn"] = ButClaimOn;
	me["TxtSte"] = TxtSte;
};

void PnlWzskVtrConfig::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskVtrConfig";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskVtrConfig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButClaimOn", ButClaimOn);
		writeStringAttr(wr, itemtag, "sref", "TxtSte", TxtSte);
	xmlTextWriterEndElement(wr);
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

void PnlWzskVtrConfig::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskVtrConfig";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["ButClaimActive"] = ButClaimActive;
	me["CusImgHeight"] = (Json::Value::UInt) CusImgHeight;
	me["ButPlayActive"] = ButPlayActive;
	me["ButStopActive"] = ButStopActive;
	me["SldAspActive"] = SldAspActive;
	me["SldAspMin"] = SldAspMin;
	me["SldAspMax"] = SldAspMax;
	me["ButStaActive"] = ButStaActive;
	me["ButStoActive"] = ButStoActive;
};

void PnlWzskVtrConfig::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskVtrConfig";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskVtrConfig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButClaimActive", ButClaimActive);
		writeUintAttr(wr, itemtag, "sref", "CusImgHeight", CusImgHeight);
		writeBoolAttr(wr, itemtag, "sref", "ButPlayActive", ButPlayActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStopActive", ButStopActive);
		writeBoolAttr(wr, itemtag, "sref", "SldAspActive", SldAspActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldAspMin", SldAspMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldAspMax", SldAspMax);
		writeBoolAttr(wr, itemtag, "sref", "ButStaActive", ButStaActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
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

void PnlWzskVtrConfig::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskVtrConfig";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Configuration";
		me["HdgPvw"] = "Preview and ROI";
		me["CptMde"] = "mode";
		me["CptAsp"] = "angle setpoint [\\u00b0]";
		me["CptSte"] = "state";
		me["ButSta"] = "Start";
		me["ButSto"] = "Stop";
	};
};

void PnlWzskVtrConfig::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskVtrConfig";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskVtrConfig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Configuration");
			writeStringAttr(wr, itemtag, "sref", "HdgPvw", "Preview and ROI");
			writeStringAttr(wr, itemtag, "sref", "CptMde", "mode");
			writeStringAttr(wr, itemtag, "sref", "CptAsp", "angle setpoint [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "ButSta", "Start");
			writeStringAttr(wr, itemtag, "sref", "ButSto", "Stop");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrConfig::DpchAppAlign
 ******************************************************************************/

PnlWzskVtrConfig::DpchAppAlign::DpchAppAlign() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRCONFIGALIGN)
		{
};

string PnlWzskVtrConfig::DpchAppAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIACALIGN)) ss.push_back("contiacalign");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchAppAlign::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskVtrConfigAlign"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiacalign.readJSON(me, true)) add(CONTIACALIGN);
	} else {
		contiacalign = ContIacAlign();
	};
};

void PnlWzskVtrConfig::DpchAppAlign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskVtrConfigAlign");
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
 class PnlWzskVtrConfig::DpchAppData
 ******************************************************************************/

PnlWzskVtrConfig::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRCONFIGDATA)
		{
};

string PnlWzskVtrConfig::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskVtrConfigData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskVtrConfig::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskVtrConfigData");
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
 class PnlWzskVtrConfig::DpchAppDo
 ******************************************************************************/

PnlWzskVtrConfig::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRCONFIGDO)
		{
	ixVDo = 0;
};

string PnlWzskVtrConfig::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskVtrConfigDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskVtrConfig::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskVtrConfigDo");
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
 class PnlWzskVtrConfig::DpchEngAlign
 ******************************************************************************/

PnlWzskVtrConfig::DpchEngAlign::DpchEngAlign(
			const ubigint jref
			, ContIacAlign* contiacalign
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRCONFIGALIGN, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIACALIGN};
	else this->mask = mask;

	if (find(this->mask, CONTIACALIGN) && contiacalign) this->contiacalign = *contiacalign;
};

string PnlWzskVtrConfig::DpchEngAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIACALIGN)) ss.push_back("contiacalign");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchEngAlign::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngAlign* src = (DpchEngAlign*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIACALIGN)) {contiacalign = src->contiacalign; add(CONTIACALIGN);};
};

void PnlWzskVtrConfig::DpchEngAlign::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskVtrConfigAlign"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIACALIGN)) contiacalign.writeJSON(me);
};

void PnlWzskVtrConfig::DpchEngAlign::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskVtrConfigAlign");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIACALIGN)) contiacalign.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrConfig::DpchEngData
 ******************************************************************************/

PnlWzskVtrConfig::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFRbuMde
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRCONFIGDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFRBUMDE, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFRBUMDE) && feedFRbuMde) this->feedFRbuMde = *feedFRbuMde;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskVtrConfig::DpchEngData::getSrefsMask() {
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

void PnlWzskVtrConfig::DpchEngData::merge(
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

void PnlWzskVtrConfig::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskVtrConfigData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFRBUMDE)) feedFRbuMde.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskVtrConfig::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskVtrConfigData");
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
 class PnlWzskVtrConfig::DpchEngLive
 ******************************************************************************/

PnlWzskVtrConfig::DpchEngLive::DpchEngLive(
			const ubigint jref
			, const vector<utinyint>& gray
			, const vector<utinyint>& rgb
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRCONFIGLIVE, jref)
			, gray(gray)
			, rgb(rgb)
		{
	if (find(mask, ALL)) this->mask = {JREF, GRAY, RGB};
	else this->mask = mask;

};

string PnlWzskVtrConfig::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(GRAY)) ss.push_back("gray");
	if (has(RGB)) ss.push_back("rgb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrConfig::DpchEngLive::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(GRAY)) {gray = src->gray; add(GRAY);};
	if (src->has(RGB)) {rgb = src->rgb; add(RGB);};
};

void PnlWzskVtrConfig::DpchEngLive::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskVtrConfigLive"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(GRAY)) Jsonio::writeUtinyintvec(me, "gray", gray);
	if (has(RGB)) Jsonio::writeUtinyintvec(me, "rgb", rgb);
};

void PnlWzskVtrConfig::DpchEngLive::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskVtrConfigLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(GRAY)) writeUtinyintvec(wr, "gray", gray);
		if (has(RGB)) writeUtinyintvec(wr, "rgb", rgb);
	xmlTextWriterEndElement(wr);
};
