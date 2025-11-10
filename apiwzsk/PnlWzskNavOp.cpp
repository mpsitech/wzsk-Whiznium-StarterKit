/**
	* \file PnlWzskNavOp.cpp
	* API code for job PnlWzskNavOp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskNavOp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskNavOp::VecVDo
 ******************************************************************************/

uint PnlWzskNavOp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butllvnewcrdclick") return BUTLLVNEWCRDCLICK;
	if (s == "butvtrnewcrdclick") return BUTVTRNEWCRDCLICK;
	if (s == "buthwcnewcrdclick") return BUTHWCNEWCRDCLICK;
	if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;

	return(0);
};

string PnlWzskNavOp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTLLVNEWCRDCLICK) return("ButLlvNewcrdClick");
	if (ix == BUTVTRNEWCRDCLICK) return("ButVtrNewcrdClick");
	if (ix == BUTHWCNEWCRDCLICK) return("ButHwcNewcrdClick");
	if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzskNavOp::ContIac
 ******************************************************************************/

PnlWzskNavOp::ContIac::ContIac(
			const uint numFLstFil
		) :
			Block()
			, numFLstFil(numFLstFil)
		{
	mask = {NUMFLSTFIL};
};

bool PnlWzskNavOp::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskNavOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskNavOp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
	};

	return basefound;
};

void PnlWzskNavOp::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskNavOp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskNavOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavOp::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);

	return(items);
};

set<uint> PnlWzskNavOp::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTFIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavOp::StatApp
 ******************************************************************************/

PnlWzskNavOp::StatApp::StatApp(
			const uint ixWzskVExpstate
			, const bool LstFilAlt
			, const uint LstFilNumFirstdisp
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, LstFilAlt(LstFilAlt)
			, LstFilNumFirstdisp(LstFilNumFirstdisp)
		{
	mask = {IXWZSKVEXPSTATE, LSTFILALT, LSTFILNUMFIRSTDISP};
};

bool PnlWzskNavOp::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskNavOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskNavOp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAlt", LstFilAlt)) add(LSTFILALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp)) add(LSTFILNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWzskNavOp::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (LstFilAlt == comp->LstFilAlt) insert(items, LSTFILALT);
	if (LstFilNumFirstdisp == comp->LstFilNumFirstdisp) insert(items, LSTFILNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWzskNavOp::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, LSTFILALT, LSTFILNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavOp::StatShr
 ******************************************************************************/

PnlWzskNavOp::StatShr::StatShr(
			const bool ButLlvNewcrdAvail
			, const bool ButVtrNewcrdAvail
			, const bool ButHwcNewcrdAvail
			, const bool LstFilAvail
			, const bool ButFilViewActive
		) :
			Block()
			, ButLlvNewcrdAvail(ButLlvNewcrdAvail)
			, ButVtrNewcrdAvail(ButVtrNewcrdAvail)
			, ButHwcNewcrdAvail(ButHwcNewcrdAvail)
			, LstFilAvail(LstFilAvail)
			, ButFilViewActive(ButFilViewActive)
		{
	mask = {BUTLLVNEWCRDAVAIL, BUTVTRNEWCRDAVAIL, BUTHWCNEWCRDAVAIL, LSTFILAVAIL, BUTFILVIEWACTIVE};
};

bool PnlWzskNavOp::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskNavOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskNavOp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLlvNewcrdAvail", ButLlvNewcrdAvail)) add(BUTLLVNEWCRDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVtrNewcrdAvail", ButVtrNewcrdAvail)) add(BUTVTRNEWCRDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHwcNewcrdAvail", ButHwcNewcrdAvail)) add(BUTHWCNEWCRDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAvail", LstFilAvail)) add(LSTFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewActive", ButFilViewActive)) add(BUTFILVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskNavOp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButLlvNewcrdAvail == comp->ButLlvNewcrdAvail) insert(items, BUTLLVNEWCRDAVAIL);
	if (ButVtrNewcrdAvail == comp->ButVtrNewcrdAvail) insert(items, BUTVTRNEWCRDAVAIL);
	if (ButHwcNewcrdAvail == comp->ButHwcNewcrdAvail) insert(items, BUTHWCNEWCRDAVAIL);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);

	return(items);
};

set<uint> PnlWzskNavOp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTLLVNEWCRDAVAIL, BUTVTRNEWCRDAVAIL, BUTHWCNEWCRDAVAIL, LSTFILAVAIL, BUTFILVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavOp::Tag
 ******************************************************************************/

PnlWzskNavOp::Tag::Tag(
			const string& Cpt
			, const string& CptLlv
			, const string& CptVtr
			, const string& CptHwc
			, const string& CptFil
		) :
			Block()
			, Cpt(Cpt)
			, CptLlv(CptLlv)
			, CptVtr(CptVtr)
			, CptHwc(CptHwc)
			, CptFil(CptFil)
		{
	mask = {CPT, CPTLLV, CPTVTR, CPTHWC, CPTFIL};
};

bool PnlWzskNavOp::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskNavOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskNavOp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLlv", CptLlv)) add(CPTLLV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVtr", CptVtr)) add(CPTVTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHwc", CptHwc)) add(CPTHWC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskNavOp::DpchAppData
 ******************************************************************************/

PnlWzskNavOp::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVOPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskNavOp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavOp::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskNavOpData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavOp::DpchAppDo
 ******************************************************************************/

PnlWzskNavOp::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVOPDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskNavOp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavOp::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskNavOpDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavOp::DpchEngData
 ******************************************************************************/

PnlWzskNavOp::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVOPDATA)
		{
	feedFLstFil.tag = "FeedFLstFil";
};

string PnlWzskNavOp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavOp::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskNavOpData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstFil.readXML(docctx, basexpath, true)) add(FEEDFLSTFIL);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstFil.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
