/**
	* \file PnlWzskNavGlry.cpp
	* API code for job PnlWzskNavGlry (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 11 Mar 2021
	*/
// IP header --- ABOVE

#include "PnlWzskNavGlry.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskNavGlry::VecVDo
 ******************************************************************************/

uint PnlWzskNavGlry::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butogrviewclick") return BUTOGRVIEWCLICK;
	if (s == "butogrnewcrdclick") return BUTOGRNEWCRDCLICK;
	if (s == "butobjviewclick") return BUTOBJVIEWCLICK;
	if (s == "butobjnewcrdclick") return BUTOBJNEWCRDCLICK;
	if (s == "butsesviewclick") return BUTSESVIEWCLICK;
	if (s == "butsesnewcrdclick") return BUTSESNEWCRDCLICK;
	if (s == "butshtviewclick") return BUTSHTVIEWCLICK;
	if (s == "butshtnewcrdclick") return BUTSHTNEWCRDCLICK;
	if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;

	return(0);
};

string PnlWzskNavGlry::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTOGRVIEWCLICK) return("ButOgrViewClick");
	if (ix == BUTOGRNEWCRDCLICK) return("ButOgrNewcrdClick");
	if (ix == BUTOBJVIEWCLICK) return("ButObjViewClick");
	if (ix == BUTOBJNEWCRDCLICK) return("ButObjNewcrdClick");
	if (ix == BUTSESVIEWCLICK) return("ButSesViewClick");
	if (ix == BUTSESNEWCRDCLICK) return("ButSesNewcrdClick");
	if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");
	if (ix == BUTSHTNEWCRDCLICK) return("ButShtNewcrdClick");
	if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzskNavGlry::ContIac
 ******************************************************************************/

PnlWzskNavGlry::ContIac::ContIac(
			const uint numFLstOgr
			, const uint numFLstObj
			, const uint numFLstSes
			, const uint numFLstSht
			, const uint numFLstFil
		) :
			Block()
		{
	this->numFLstOgr = numFLstOgr;
	this->numFLstObj = numFLstObj;
	this->numFLstSes = numFLstSes;
	this->numFLstSht = numFLstSht;
	this->numFLstFil = numFLstFil;

	mask = {NUMFLSTOGR, NUMFLSTOBJ, NUMFLSTSES, NUMFLSTSHT, NUMFLSTFIL};
};

bool PnlWzskNavGlry::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskNavGlry");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskNavGlry";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOgr", numFLstOgr)) add(NUMFLSTOGR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstObj", numFLstObj)) add(NUMFLSTOBJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSes", numFLstSes)) add(NUMFLSTSES);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSht", numFLstSht)) add(NUMFLSTSHT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
	};

	return basefound;
};

void PnlWzskNavGlry::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskNavGlry";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskNavGlry";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstOgr", numFLstOgr);
		writeUintAttr(wr, itemtag, "sref", "numFLstObj", numFLstObj);
		writeUintAttr(wr, itemtag, "sref", "numFLstSes", numFLstSes);
		writeUintAttr(wr, itemtag, "sref", "numFLstSht", numFLstSht);
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavGlry::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstOgr == comp->numFLstOgr) insert(items, NUMFLSTOGR);
	if (numFLstObj == comp->numFLstObj) insert(items, NUMFLSTOBJ);
	if (numFLstSes == comp->numFLstSes) insert(items, NUMFLSTSES);
	if (numFLstSht == comp->numFLstSht) insert(items, NUMFLSTSHT);
	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);

	return(items);
};

set<uint> PnlWzskNavGlry::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTOGR, NUMFLSTOBJ, NUMFLSTSES, NUMFLSTSHT, NUMFLSTFIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavGlry::StatApp
 ******************************************************************************/

PnlWzskNavGlry::StatApp::StatApp(
			const uint ixWzskVExpstate
			, const bool LstOgrAlt
			, const bool LstObjAlt
			, const bool LstSesAlt
			, const bool LstShtAlt
			, const bool LstFilAlt
			, const uint LstOgrNumFirstdisp
			, const uint LstObjNumFirstdisp
			, const uint LstSesNumFirstdisp
			, const uint LstShtNumFirstdisp
			, const uint LstFilNumFirstdisp
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->LstOgrAlt = LstOgrAlt;
	this->LstObjAlt = LstObjAlt;
	this->LstSesAlt = LstSesAlt;
	this->LstShtAlt = LstShtAlt;
	this->LstFilAlt = LstFilAlt;
	this->LstOgrNumFirstdisp = LstOgrNumFirstdisp;
	this->LstObjNumFirstdisp = LstObjNumFirstdisp;
	this->LstSesNumFirstdisp = LstSesNumFirstdisp;
	this->LstShtNumFirstdisp = LstShtNumFirstdisp;
	this->LstFilNumFirstdisp = LstFilNumFirstdisp;

	mask = {IXWZSKVEXPSTATE, LSTOGRALT, LSTOBJALT, LSTSESALT, LSTSHTALT, LSTFILALT, LSTOGRNUMFIRSTDISP, LSTOBJNUMFIRSTDISP, LSTSESNUMFIRSTDISP, LSTSHTNUMFIRSTDISP, LSTFILNUMFIRSTDISP};
};

bool PnlWzskNavGlry::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskNavGlry");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskNavGlry";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOgrAlt", LstOgrAlt)) add(LSTOGRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstObjAlt", LstObjAlt)) add(LSTOBJALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSesAlt", LstSesAlt)) add(LSTSESALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstShtAlt", LstShtAlt)) add(LSTSHTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAlt", LstFilAlt)) add(LSTFILALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOgrNumFirstdisp", LstOgrNumFirstdisp)) add(LSTOGRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstObjNumFirstdisp", LstObjNumFirstdisp)) add(LSTOBJNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSesNumFirstdisp", LstSesNumFirstdisp)) add(LSTSESNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstShtNumFirstdisp", LstShtNumFirstdisp)) add(LSTSHTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp)) add(LSTFILNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWzskNavGlry::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (LstOgrAlt == comp->LstOgrAlt) insert(items, LSTOGRALT);
	if (LstObjAlt == comp->LstObjAlt) insert(items, LSTOBJALT);
	if (LstSesAlt == comp->LstSesAlt) insert(items, LSTSESALT);
	if (LstShtAlt == comp->LstShtAlt) insert(items, LSTSHTALT);
	if (LstFilAlt == comp->LstFilAlt) insert(items, LSTFILALT);
	if (LstOgrNumFirstdisp == comp->LstOgrNumFirstdisp) insert(items, LSTOGRNUMFIRSTDISP);
	if (LstObjNumFirstdisp == comp->LstObjNumFirstdisp) insert(items, LSTOBJNUMFIRSTDISP);
	if (LstSesNumFirstdisp == comp->LstSesNumFirstdisp) insert(items, LSTSESNUMFIRSTDISP);
	if (LstShtNumFirstdisp == comp->LstShtNumFirstdisp) insert(items, LSTSHTNUMFIRSTDISP);
	if (LstFilNumFirstdisp == comp->LstFilNumFirstdisp) insert(items, LSTFILNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWzskNavGlry::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, LSTOGRALT, LSTOBJALT, LSTSESALT, LSTSHTALT, LSTFILALT, LSTOGRNUMFIRSTDISP, LSTOBJNUMFIRSTDISP, LSTSESNUMFIRSTDISP, LSTSHTNUMFIRSTDISP, LSTFILNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavGlry::StatShr
 ******************************************************************************/

PnlWzskNavGlry::StatShr::StatShr(
			const bool LstOgrAvail
			, const bool ButOgrViewActive
			, const bool LstObjAvail
			, const bool ButObjViewActive
			, const bool LstSesAvail
			, const bool ButSesViewActive
			, const bool LstShtAvail
			, const bool ButShtViewActive
			, const bool LstFilAvail
			, const bool ButFilViewActive
		) :
			Block()
		{
	this->LstOgrAvail = LstOgrAvail;
	this->ButOgrViewActive = ButOgrViewActive;
	this->LstObjAvail = LstObjAvail;
	this->ButObjViewActive = ButObjViewActive;
	this->LstSesAvail = LstSesAvail;
	this->ButSesViewActive = ButSesViewActive;
	this->LstShtAvail = LstShtAvail;
	this->ButShtViewActive = ButShtViewActive;
	this->LstFilAvail = LstFilAvail;
	this->ButFilViewActive = ButFilViewActive;

	mask = {LSTOGRAVAIL, BUTOGRVIEWACTIVE, LSTOBJAVAIL, BUTOBJVIEWACTIVE, LSTSESAVAIL, BUTSESVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE};
};

bool PnlWzskNavGlry::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskNavGlry");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskNavGlry";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOgrAvail", LstOgrAvail)) add(LSTOGRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOgrViewActive", ButOgrViewActive)) add(BUTOGRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstObjAvail", LstObjAvail)) add(LSTOBJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButObjViewActive", ButObjViewActive)) add(BUTOBJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSesAvail", LstSesAvail)) add(LSTSESAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSesViewActive", ButSesViewActive)) add(BUTSESVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstShtAvail", LstShtAvail)) add(LSTSHTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButShtViewActive", ButShtViewActive)) add(BUTSHTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAvail", LstFilAvail)) add(LSTFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewActive", ButFilViewActive)) add(BUTFILVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskNavGlry::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstOgrAvail == comp->LstOgrAvail) insert(items, LSTOGRAVAIL);
	if (ButOgrViewActive == comp->ButOgrViewActive) insert(items, BUTOGRVIEWACTIVE);
	if (LstObjAvail == comp->LstObjAvail) insert(items, LSTOBJAVAIL);
	if (ButObjViewActive == comp->ButObjViewActive) insert(items, BUTOBJVIEWACTIVE);
	if (LstSesAvail == comp->LstSesAvail) insert(items, LSTSESAVAIL);
	if (ButSesViewActive == comp->ButSesViewActive) insert(items, BUTSESVIEWACTIVE);
	if (LstShtAvail == comp->LstShtAvail) insert(items, LSTSHTAVAIL);
	if (ButShtViewActive == comp->ButShtViewActive) insert(items, BUTSHTVIEWACTIVE);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);

	return(items);
};

set<uint> PnlWzskNavGlry::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTOGRAVAIL, BUTOGRVIEWACTIVE, LSTOBJAVAIL, BUTOBJVIEWACTIVE, LSTSESAVAIL, BUTSESVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavGlry::Tag
 ******************************************************************************/

PnlWzskNavGlry::Tag::Tag(
			const string& Cpt
			, const string& CptOgr
			, const string& CptObj
			, const string& CptSes
			, const string& CptSht
			, const string& CptFil
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptOgr = CptOgr;
	this->CptObj = CptObj;
	this->CptSes = CptSes;
	this->CptSht = CptSht;
	this->CptFil = CptFil;

	mask = {CPT, CPTOGR, CPTOBJ, CPTSES, CPTSHT, CPTFIL};
};

bool PnlWzskNavGlry::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskNavGlry");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskNavGlry";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOgr", CptOgr)) add(CPTOGR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptObj", CptObj)) add(CPTOBJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSes", CptSes)) add(CPTSES);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSht", CptSht)) add(CPTSHT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskNavGlry::DpchAppData
 ******************************************************************************/

PnlWzskNavGlry::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVGLRYDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskNavGlry::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavGlry::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskNavGlryData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavGlry::DpchAppDo
 ******************************************************************************/

PnlWzskNavGlry::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVGLRYDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskNavGlry::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavGlry::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskNavGlryDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavGlry::DpchEngData
 ******************************************************************************/

PnlWzskNavGlry::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVGLRYDATA)
		{
	feedFLstFil.tag = "FeedFLstFil";
	feedFLstObj.tag = "FeedFLstObj";
	feedFLstOgr.tag = "FeedFLstOgr";
	feedFLstSes.tag = "FeedFLstSes";
	feedFLstSht.tag = "FeedFLstSht";
};

string PnlWzskNavGlry::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(FEEDFLSTOBJ)) ss.push_back("feedFLstObj");
	if (has(FEEDFLSTOGR)) ss.push_back("feedFLstOgr");
	if (has(FEEDFLSTSES)) ss.push_back("feedFLstSes");
	if (has(FEEDFLSTSHT)) ss.push_back("feedFLstSht");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavGlry::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskNavGlryData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstFil.readXML(docctx, basexpath, true)) add(FEEDFLSTFIL);
		if (feedFLstObj.readXML(docctx, basexpath, true)) add(FEEDFLSTOBJ);
		if (feedFLstOgr.readXML(docctx, basexpath, true)) add(FEEDFLSTOGR);
		if (feedFLstSes.readXML(docctx, basexpath, true)) add(FEEDFLSTSES);
		if (feedFLstSht.readXML(docctx, basexpath, true)) add(FEEDFLSTSHT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstFil.clear();
		feedFLstObj.clear();
		feedFLstOgr.clear();
		feedFLstSes.clear();
		feedFLstSht.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
