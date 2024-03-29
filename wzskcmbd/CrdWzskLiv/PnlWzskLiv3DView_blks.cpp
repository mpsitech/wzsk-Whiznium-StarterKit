/**
	* \file PnlWzskLiv3DView_blks.cpp
	* job handler for job PnlWzskLiv3DView (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

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

bool PnlWzskLiv3DView::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskLiv3DView"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("SldAin")) {SldAin = me["SldAin"].asDouble(); add(SLDAIN);};
	};

	return basefound;
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

void PnlWzskLiv3DView::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLiv3DView";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["SldAin"] = SldAin;
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

void PnlWzskLiv3DView::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLiv3DView";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButClaimOn"] = ButClaimOn;
	me["TxtAst"] = TxtAst;
	me["TxtAoa"] = TxtAoa;
};

void PnlWzskLiv3DView::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLiv3DView";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskLiv3DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButClaimOn", ButClaimOn);
		writeStringAttr(wr, itemtag, "sref", "TxtAst", TxtAst);
		writeStringAttr(wr, itemtag, "sref", "TxtAoa", TxtAoa);
	xmlTextWriterEndElement(wr);
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

void PnlWzskLiv3DView::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool ButPlayActive
			, const bool ButStopActive
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskLiv3DView";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButPlayActive"] = ButPlayActive;
	me["ButStopActive"] = ButStopActive;
};

void PnlWzskLiv3DView::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool ButPlayActive
			, const bool ButStopActive
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskLiv3DView";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskLiv3DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButPlayActive", ButPlayActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStopActive", ButStopActive);
	xmlTextWriterEndElement(wr);
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

void PnlWzskLiv3DView::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLiv3DView";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["ButClaimActive"] = ButClaimActive;
	me["SldTreHMin"] = SldTreHMin;
	me["SldTreHMax"] = SldTreHMax;
	me["SldTreVMin"] = SldTreVMin;
	me["SldTreVMax"] = SldTreVMax;
	me["SldAinActive"] = SldAinActive;
	me["SldAinMin"] = SldAinMin;
	me["SldAinMax"] = SldAinMax;
	me["SldAinRast"] = SldAinRast;
	me["TxtAoaAvail"] = TxtAoaAvail;
	me["ButAsrActive"] = ButAsrActive;
	me["ButAirActive"] = ButAirActive;
};

void PnlWzskLiv3DView::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLiv3DView";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskLiv3DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButClaimActive", ButClaimActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldTreHMin", SldTreHMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldTreHMax", SldTreHMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldTreVMin", SldTreVMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldTreVMax", SldTreVMax);
		writeBoolAttr(wr, itemtag, "sref", "SldAinActive", SldAinActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldAinMin", SldAinMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldAinMax", SldAinMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldAinRast", SldAinRast);
		writeBoolAttr(wr, itemtag, "sref", "TxtAoaAvail", TxtAoaAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButAsrActive", ButAsrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButAirActive", ButAirActive);
	xmlTextWriterEndElement(wr);
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

void PnlWzskLiv3DView::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskLiv3DView";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "3D Reconstruction";
		me["HdgAcq"] = "Shot acquisition";
		me["CptAin"] = "angle increment [\\u00b0]";
		me["CptAst"] = "state";
		me["CptAoa"] = "object affiliation";
		me["ButAsr"] = "Start";
		me["ButAir"] = "Interrupt";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["Cpt"] = "3D-Rekonstruktion";
		me["HdgAcq"] = "Aufnahme";
		me["CptAin"] = "Winkel-Schrittweite [\\u00b0]";
		me["CptAst"] = "Status";
		me["CptAoa"] = "Objekt-Zuordnung";
		me["ButAsr"] = "Start";
		me["ButAir"] = "Unterbrechen";
	};
};

void PnlWzskLiv3DView::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskLiv3DView";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskLiv3DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "3D Reconstruction");
			writeStringAttr(wr, itemtag, "sref", "HdgAcq", "Shot acquisition");
			writeStringAttr(wr, itemtag, "sref", "CptAin", "angle increment [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptAst", "state");
			writeStringAttr(wr, itemtag, "sref", "CptAoa", "object affiliation");
			writeStringAttr(wr, itemtag, "sref", "ButAsr", "Start");
			writeStringAttr(wr, itemtag, "sref", "ButAir", "Interrupt");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "3D-Rekonstruktion");
			writeStringAttr(wr, itemtag, "sref", "HdgAcq", "Aufnahme");
			writeStringAttr(wr, itemtag, "sref", "CptAin", "Winkel-Schrittweite [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptAst", "Status");
			writeStringAttr(wr, itemtag, "sref", "CptAoa", "Objekt-Zuordnung");
			writeStringAttr(wr, itemtag, "sref", "ButAsr", "Start");
			writeStringAttr(wr, itemtag, "sref", "ButAir", "Unterbrechen");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv3DView::DpchAppData
 ******************************************************************************/

PnlWzskLiv3DView::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDATA)
		{
};

string PnlWzskLiv3DView::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv3DView::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskLiv3DViewData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskLiv3DView::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLiv3DViewData");
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
 class PnlWzskLiv3DView::DpchAppDo
 ******************************************************************************/

PnlWzskLiv3DView::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDO)
		{
	ixVDo = 0;
};

string PnlWzskLiv3DView::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv3DView::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskLiv3DViewDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskLiv3DView::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLiv3DViewDo");
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
 class PnlWzskLiv3DView::DpchEngData
 ******************************************************************************/

PnlWzskLiv3DView::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV3DVIEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskLiv3DView::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv3DView::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskLiv3DView::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskLiv3DViewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskLiv3DView::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLiv3DViewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv3DView::DpchEngLive
 ******************************************************************************/

PnlWzskLiv3DView::DpchEngLive::DpchEngLive(
			const ubigint jref
			, const vector<bool>& rNotL
			, const vector<float>& x
			, const vector<float>& y
			, const vector<float>& z
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV3DVIEWLIVE, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, RNOTL, X, Y, Z};
	else this->mask = mask;

	this->rNotL = rNotL;
	this->x = x;
	this->y = y;
	this->z = z;
};

string PnlWzskLiv3DView::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(RNOTL)) ss.push_back("rNotL");
	if (has(X)) ss.push_back("x");
	if (has(Y)) ss.push_back("y");
	if (has(Z)) ss.push_back("z");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv3DView::DpchEngLive::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(RNOTL)) {rNotL = src->rNotL; add(RNOTL);};
	if (src->has(X)) {x = src->x; add(X);};
	if (src->has(Y)) {y = src->y; add(Y);};
	if (src->has(Z)) {z = src->z; add(Z);};
};

void PnlWzskLiv3DView::DpchEngLive::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskLiv3DViewLive"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(RNOTL)) Jsonio::writeBoolvec(me, "rNotL", rNotL);
	if (has(X)) Jsonio::writeFloatvec(me, "x", x);
	if (has(Y)) Jsonio::writeFloatvec(me, "y", y);
	if (has(Z)) Jsonio::writeFloatvec(me, "z", z);
};

void PnlWzskLiv3DView::DpchEngLive::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLiv3DViewLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(RNOTL)) writeBoolvec(wr, "rNotL",rNotL);
		if (has(X)) writeFloatvec(wr, "x", x);
		if (has(Y)) writeFloatvec(wr, "y", y);
		if (has(Z)) writeFloatvec(wr, "z", z);
	xmlTextWriterEndElement(wr);
};
