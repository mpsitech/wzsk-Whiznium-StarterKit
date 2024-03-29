/**
	* \file PnlWzskLlvCamera_blks.cpp
	* job handler for job PnlWzskLlvCamera (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvCamera::VecVDo
 ******************************************************************************/

uint PnlWzskLlvCamera::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;
	if (s == "butplayclick") return BUTPLAYCLICK;
	if (s == "butstopclick") return BUTSTOPCLICK;

	return(0);
};

string PnlWzskLlvCamera::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTPLAYCLICK) return("ButPlayClick");
	if (ix == BUTSTOPCLICK) return("ButStopClick");

	return("");
};

/******************************************************************************
 class PnlWzskLlvCamera::ContIac
 ******************************************************************************/

PnlWzskLlvCamera::ContIac::ContIac(
			const uint numFPupMde
			, const bool ChkAex
			, const double SldExt
			, const double SldFcs
		) :
			Block()
		{
	this->numFPupMde = numFPupMde;
	this->ChkAex = ChkAex;
	this->SldExt = SldExt;
	this->SldFcs = SldFcs;

	mask = {NUMFPUPMDE, CHKAEX, SLDEXT, SLDFCS};
};

bool PnlWzskLlvCamera::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskLlvCamera"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupMde")) {numFPupMde = me["numFPupMde"].asUInt(); add(NUMFPUPMDE);};
		if (me.isMember("ChkAex")) {ChkAex = me["ChkAex"].asBool(); add(CHKAEX);};
		if (me.isMember("SldExt")) {SldExt = me["SldExt"].asDouble(); add(SLDEXT);};
		if (me.isMember("SldFcs")) {SldFcs = me["SldFcs"].asDouble(); add(SLDFCS);};
	};

	return basefound;
};

bool PnlWzskLlvCamera::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLlvCamera");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLlvCamera";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMde", numFPupMde)) add(NUMFPUPMDE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkAex", ChkAex)) add(CHKAEX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldExt", SldExt)) add(SLDEXT);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFcs", SldFcs)) add(SLDFCS);
	};

	return basefound;
};

void PnlWzskLlvCamera::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLlvCamera";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupMde"] = numFPupMde;
	me["ChkAex"] = ChkAex;
	me["SldExt"] = SldExt;
	me["SldFcs"] = SldFcs;
};

void PnlWzskLlvCamera::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLlvCamera";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLlvCamera";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupMde", numFPupMde);
		writeBoolAttr(wr, itemtag, "sref", "ChkAex", ChkAex);
		writeDoubleAttr(wr, itemtag, "sref", "SldExt", SldExt);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcs", SldFcs);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvCamera::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupMde == comp->numFPupMde) insert(items, NUMFPUPMDE);
	if (ChkAex == comp->ChkAex) insert(items, CHKAEX);
	if (compareDouble(SldExt, comp->SldExt) < 1.0e-4) insert(items, SLDEXT);
	if (compareDouble(SldFcs, comp->SldFcs) < 1.0e-4) insert(items, SLDFCS);

	return(items);
};

set<uint> PnlWzskLlvCamera::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPMDE, CHKAEX, SLDEXT, SLDFCS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvCamera::ContInf
 ******************************************************************************/

PnlWzskLlvCamera::ContInf::ContInf(
			const bool ButClaimOn
		) :
			Block()
		{
	this->ButClaimOn = ButClaimOn;

	mask = {BUTCLAIMON};
};

void PnlWzskLlvCamera::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLlvCamera";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButClaimOn"] = ButClaimOn;
};

void PnlWzskLlvCamera::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLlvCamera";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskLlvCamera";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButClaimOn", ButClaimOn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvCamera::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);

	return(items);
};

set<uint> PnlWzskLlvCamera::ContInf::diff(
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
 class PnlWzskLlvCamera::StatShr
 ******************************************************************************/

PnlWzskLlvCamera::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool ButPlayActive
			, const bool ButStopActive
			, const bool ChkAexActive
			, const bool SldExtAvail
			, const bool SldExtActive
			, const double SldExtMin
			, const double SldExtMax
			, const double SldExtRast
			, const bool SldFcsActive
			, const double SldFcsMin
			, const double SldFcsMax
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->ButClaimActive = ButClaimActive;
	this->ButPlayActive = ButPlayActive;
	this->ButStopActive = ButStopActive;
	this->ChkAexActive = ChkAexActive;
	this->SldExtAvail = SldExtAvail;
	this->SldExtActive = SldExtActive;
	this->SldExtMin = SldExtMin;
	this->SldExtMax = SldExtMax;
	this->SldExtRast = SldExtRast;
	this->SldFcsActive = SldFcsActive;
	this->SldFcsMin = SldFcsMin;
	this->SldFcsMax = SldFcsMax;

	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTPLAYACTIVE, BUTSTOPACTIVE, CHKAEXACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX};
};

void PnlWzskLlvCamera::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLlvCamera";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["ButClaimActive"] = ButClaimActive;
	me["ButPlayActive"] = ButPlayActive;
	me["ButStopActive"] = ButStopActive;
	me["ChkAexActive"] = ChkAexActive;
	me["SldExtAvail"] = SldExtAvail;
	me["SldExtActive"] = SldExtActive;
	me["SldExtMin"] = SldExtMin;
	me["SldExtMax"] = SldExtMax;
	me["SldExtRast"] = SldExtRast;
	me["SldFcsActive"] = SldFcsActive;
	me["SldFcsMin"] = SldFcsMin;
	me["SldFcsMax"] = SldFcsMax;
};

void PnlWzskLlvCamera::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLlvCamera";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskLlvCamera";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButClaimActive", ButClaimActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPlayActive", ButPlayActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStopActive", ButStopActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkAexActive", ChkAexActive);
		writeBoolAttr(wr, itemtag, "sref", "SldExtAvail", SldExtAvail);
		writeBoolAttr(wr, itemtag, "sref", "SldExtActive", SldExtActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtMin", SldExtMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtMax", SldExtMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtRast", SldExtRast);
		writeBoolAttr(wr, itemtag, "sref", "SldFcsActive", SldFcsActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcsMin", SldFcsMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcsMax", SldFcsMax);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvCamera::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (ButPlayActive == comp->ButPlayActive) insert(items, BUTPLAYACTIVE);
	if (ButStopActive == comp->ButStopActive) insert(items, BUTSTOPACTIVE);
	if (ChkAexActive == comp->ChkAexActive) insert(items, CHKAEXACTIVE);
	if (SldExtAvail == comp->SldExtAvail) insert(items, SLDEXTAVAIL);
	if (SldExtActive == comp->SldExtActive) insert(items, SLDEXTACTIVE);
	if (compareDouble(SldExtMin, comp->SldExtMin) < 1.0e-4) insert(items, SLDEXTMIN);
	if (compareDouble(SldExtMax, comp->SldExtMax) < 1.0e-4) insert(items, SLDEXTMAX);
	if (compareDouble(SldExtRast, comp->SldExtRast) < 1.0e-4) insert(items, SLDEXTRAST);
	if (SldFcsActive == comp->SldFcsActive) insert(items, SLDFCSACTIVE);
	if (compareDouble(SldFcsMin, comp->SldFcsMin) < 1.0e-4) insert(items, SLDFCSMIN);
	if (compareDouble(SldFcsMax, comp->SldFcsMax) < 1.0e-4) insert(items, SLDFCSMAX);

	return(items);
};

set<uint> PnlWzskLlvCamera::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTPLAYACTIVE, BUTSTOPACTIVE, CHKAEXACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvCamera::Tag
 ******************************************************************************/

void PnlWzskLlvCamera::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskLlvCamera";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Camera";
		me["CptMde"] = "mode";
		me["CptAex"] = "auto-exposure";
		me["CptExt"] = "exposure time [ms]";
		me["CptFcs"] = "focus (near -\\u003e far)";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["Cpt"] = "Kamera";
		me["CptMde"] = "Modus";
		me["CptAex"] = "automatische Belichtung";
		me["CptExt"] = "Belichtungszeit [ms]";
		me["CptFcs"] = "Fokus (nah -\\u003e fern)";
	};
};

void PnlWzskLlvCamera::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskLlvCamera";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskLlvCamera";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Camera");
			writeStringAttr(wr, itemtag, "sref", "CptMde", "mode");
			writeStringAttr(wr, itemtag, "sref", "CptAex", "auto-exposure");
			writeStringAttr(wr, itemtag, "sref", "CptExt", "exposure time [ms]");
			writeStringAttr(wr, itemtag, "sref", "CptFcs", "focus (near -\\u003e far)");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Kamera");
			writeStringAttr(wr, itemtag, "sref", "CptMde", "Modus");
			writeStringAttr(wr, itemtag, "sref", "CptAex", "automatische Belichtung");
			writeStringAttr(wr, itemtag, "sref", "CptExt", "Belichtungszeit [ms]");
			writeStringAttr(wr, itemtag, "sref", "CptFcs", "Fokus (nah -\\u003e fern)");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvCamera::DpchAppData
 ******************************************************************************/

PnlWzskLlvCamera::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVCAMERADATA)
		{
};

string PnlWzskLlvCamera::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvCamera::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskLlvCameraData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskLlvCamera::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLlvCameraData");
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
 class PnlWzskLlvCamera::DpchAppDo
 ******************************************************************************/

PnlWzskLlvCamera::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVCAMERADO)
		{
	ixVDo = 0;
};

string PnlWzskLlvCamera::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvCamera::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskLlvCameraDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskLlvCamera::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLlvCameraDo");
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
 class PnlWzskLlvCamera::DpchEngData
 ******************************************************************************/

PnlWzskLlvCamera::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupMde
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVCAMERADATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPMDE, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPMDE) && feedFPupMde) this->feedFPupMde = *feedFPupMde;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskLlvCamera::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPMDE)) ss.push_back("feedFPupMde");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvCamera::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPMDE)) {feedFPupMde = src->feedFPupMde; add(FEEDFPUPMDE);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskLlvCamera::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskLlvCameraData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPMDE)) feedFPupMde.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskLlvCamera::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLlvCameraData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPMDE)) feedFPupMde.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvCamera::DpchEngLive
 ******************************************************************************/

PnlWzskLlvCamera::DpchEngLive::DpchEngLive(
			const ubigint jref
			, const vector<utinyint>& gray
			, const vector<utinyint>& red
			, const vector<utinyint>& green
			, const vector<utinyint>& blue
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVCAMERALIVE, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, GRAY, RED, GREEN, BLUE};
	else this->mask = mask;

	this->gray = gray;
	this->red = red;
	this->green = green;
	this->blue = blue;
};

string PnlWzskLlvCamera::DpchEngLive::getSrefsMask() {
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

void PnlWzskLlvCamera::DpchEngLive::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(GRAY)) {gray = src->gray; add(GRAY);};
	if (src->has(RED)) {red = src->red; add(RED);};
	if (src->has(GREEN)) {green = src->green; add(GREEN);};
	if (src->has(BLUE)) {blue = src->blue; add(BLUE);};
};

void PnlWzskLlvCamera::DpchEngLive::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskLlvCameraLive"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(GRAY)) Jsonio::writeUtinyintvec(me, "gray", gray);
	if (has(RED)) Jsonio::writeUtinyintvec(me, "red", red);
	if (has(GREEN)) Jsonio::writeUtinyintvec(me, "green", green);
	if (has(BLUE)) Jsonio::writeUtinyintvec(me, "blue", blue);
};

void PnlWzskLlvCamera::DpchEngLive::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLlvCameraLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(GRAY)) writeUtinyintvec(wr, "gray", gray);
		if (has(RED)) writeUtinyintvec(wr, "red", red);
		if (has(GREEN)) writeUtinyintvec(wr, "green", green);
		if (has(BLUE)) writeUtinyintvec(wr, "blue", blue);
	xmlTextWriterEndElement(wr);
};
