/**
	* \file PnlWzskLlvLaser_blks.cpp
	* job handler for job PnlWzskLlvLaser (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

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

void PnlWzskLlvLaser::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLlvLaser";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskLlvLaser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButClaimOn", ButClaimOn);
	xmlTextWriterEndElement(wr);
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

void PnlWzskLlvLaser::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLlvLaser";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskLlvLaser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButClaimActive", ButClaimActive);
		writeBoolAttr(wr, itemtag, "sref", "SldLleActive", SldLleActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldLleMin", SldLleMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldLleMax", SldLleMax);
		writeBoolAttr(wr, itemtag, "sref", "SldLriActive", SldLriActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldLriMin", SldLriMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldLriMax", SldLriMax);
	xmlTextWriterEndElement(wr);
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

void PnlWzskLlvLaser::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskLlvLaser";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskLlvLaser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Line lasers");
			writeStringAttr(wr, itemtag, "sref", "CptErg", "entire range");
			writeStringAttr(wr, itemtag, "sref", "CptLle", "left [\\u0025]");
			writeStringAttr(wr, itemtag, "sref", "CptLri", "right [\\u0025]");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Linienlaser");
			writeStringAttr(wr, itemtag, "sref", "CptErg", "vollst\\u00e4ndige Spanne");
			writeStringAttr(wr, itemtag, "sref", "CptLle", "links [\\u0025]");
			writeStringAttr(wr, itemtag, "sref", "CptLri", "rechts [\\u0025]");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvLaser::DpchAppData
 ******************************************************************************/

PnlWzskLlvLaser::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVLASERDATA)
		{
};

string PnlWzskLlvLaser::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvLaser::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLlvLaserData");
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
 class PnlWzskLlvLaser::DpchAppDo
 ******************************************************************************/

PnlWzskLlvLaser::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVLASERDO)
		{
	ixVDo = 0;
};

string PnlWzskLlvLaser::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvLaser::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLlvLaserDo");
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
 class PnlWzskLlvLaser::DpchEngData
 ******************************************************************************/

PnlWzskLlvLaser::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVLASERDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskLlvLaser::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvLaser::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskLlvLaser::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLlvLaserData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

