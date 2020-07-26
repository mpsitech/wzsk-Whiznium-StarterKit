/**
	* \file PnlWzskLiv3DView_blks.cpp
	* job handler for job PnlWzskLiv3DView (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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
		writeBoolAttr(wr, itemtag, "sref", "ButPlayActive", ButPlayActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStopActive", ButStopActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtAoaAvail", TxtAoaAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButAstActive", ButAstActive);
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
			writeStringAttr(wr, itemtag, "sref", "CptAst", "state");
			writeStringAttr(wr, itemtag, "sref", "CptAoa", "object affiliation");
			writeStringAttr(wr, itemtag, "sref", "ButAst", "Start");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "3D-Rekonstruktion");
			writeStringAttr(wr, itemtag, "sref", "HdgAcq", "Aufnahme");
			writeStringAttr(wr, itemtag, "sref", "CptAst", "Status");
			writeStringAttr(wr, itemtag, "sref", "CptAoa", "Objekt-Zuordnung");
			writeStringAttr(wr, itemtag, "sref", "ButAst", "Start");
		};
	xmlTextWriterEndElement(wr);
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
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV3DVIEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskLiv3DView::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
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
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskLiv3DView::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLiv3DViewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
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

