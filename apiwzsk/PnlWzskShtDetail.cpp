/**
	* \file PnlWzskShtDetail.cpp
	* API code for job PnlWzskShtDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzskShtDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskShtDetail::VecVDo
 ******************************************************************************/

uint PnlWzskShtDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butsesviewclick") return BUTSESVIEWCLICK;
	if (s == "butobjviewclick") return BUTOBJVIEWCLICK;

	return(0);
};

string PnlWzskShtDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSESVIEWCLICK) return("ButSesViewClick");
	if (ix == BUTOBJVIEWCLICK) return("ButObjViewClick");

	return("");
};

/******************************************************************************
 class PnlWzskShtDetail::ContIac
 ******************************************************************************/

PnlWzskShtDetail::ContIac::ContIac(
			const string& TxfSta
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfSta = TxfSta;
	this->TxfCmt = TxfCmt;

	mask = {TXFSTA, TXFCMT};
};

bool PnlWzskShtDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskShtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskShtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWzskShtDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskShtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskShtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskShtDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWzskShtDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSTA, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskShtDetail::ContInf
 ******************************************************************************/

PnlWzskShtDetail::ContInf::ContInf(
			const string& TxtSes
			, const string& TxtObj
		) :
			Block()
		{
	this->TxtSes = TxtSes;
	this->TxtObj = TxtObj;

	mask = {TXTSES, TXTOBJ};
};

bool PnlWzskShtDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskShtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskShtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSes", TxtSes)) add(TXTSES);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtObj", TxtObj)) add(TXTOBJ);
	};

	return basefound;
};

set<uint> PnlWzskShtDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSes == comp->TxtSes) insert(items, TXTSES);
	if (TxtObj == comp->TxtObj) insert(items, TXTOBJ);

	return(items);
};

set<uint> PnlWzskShtDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSES, TXTOBJ};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskShtDetail::StatApp
 ******************************************************************************/

PnlWzskShtDetail::StatApp::StatApp(
			const uint ixWzskVExpstate
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;

	mask = {IXWZSKVEXPSTATE};
};

bool PnlWzskShtDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskShtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskShtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWzskShtDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);

	return(items);
};

set<uint> PnlWzskShtDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskShtDetail::StatShr
 ******************************************************************************/

PnlWzskShtDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSesActive
			, const bool ButSesViewAvail
			, const bool ButSesViewActive
			, const bool TxtObjActive
			, const bool ButObjViewAvail
			, const bool ButObjViewActive
			, const bool TxfStaActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSesActive = TxtSesActive;
	this->ButSesViewAvail = ButSesViewAvail;
	this->ButSesViewActive = ButSesViewActive;
	this->TxtObjActive = TxtObjActive;
	this->ButObjViewAvail = ButObjViewAvail;
	this->ButObjViewActive = ButObjViewActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSESACTIVE, BUTSESVIEWAVAIL, BUTSESVIEWACTIVE, TXTOBJACTIVE, BUTOBJVIEWAVAIL, BUTOBJVIEWACTIVE, TXFSTAACTIVE, TXFCMTACTIVE};
};

bool PnlWzskShtDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskShtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskShtDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSesActive", TxtSesActive)) add(TXTSESACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSesViewAvail", ButSesViewAvail)) add(BUTSESVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSesViewActive", ButSesViewActive)) add(BUTSESVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtObjActive", TxtObjActive)) add(TXTOBJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButObjViewAvail", ButObjViewAvail)) add(BUTOBJVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButObjViewActive", ButObjViewActive)) add(BUTOBJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskShtDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSesActive == comp->TxtSesActive) insert(items, TXTSESACTIVE);
	if (ButSesViewAvail == comp->ButSesViewAvail) insert(items, BUTSESVIEWAVAIL);
	if (ButSesViewActive == comp->ButSesViewActive) insert(items, BUTSESVIEWACTIVE);
	if (TxtObjActive == comp->TxtObjActive) insert(items, TXTOBJACTIVE);
	if (ButObjViewAvail == comp->ButObjViewAvail) insert(items, BUTOBJVIEWAVAIL);
	if (ButObjViewActive == comp->ButObjViewActive) insert(items, BUTOBJVIEWACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWzskShtDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSESACTIVE, BUTSESVIEWAVAIL, BUTSESVIEWACTIVE, TXTOBJACTIVE, BUTOBJVIEWAVAIL, BUTOBJVIEWACTIVE, TXFSTAACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskShtDetail::Tag
 ******************************************************************************/

PnlWzskShtDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSes
			, const string& CptObj
			, const string& CptSta
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSes = CptSes;
	this->CptObj = CptObj;
	this->CptSta = CptSta;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSES, CPTOBJ, CPTSTA, CPTCMT};
};

bool PnlWzskShtDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskShtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskShtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSes", CptSes)) add(CPTSES);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptObj", CptObj)) add(CPTOBJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskShtDetail::DpchAppData
 ******************************************************************************/

PnlWzskShtDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSHTDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskShtDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskShtDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskShtDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskShtDetail::DpchAppDo
 ******************************************************************************/

PnlWzskShtDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSHTDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskShtDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskShtDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskShtDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskShtDetail::DpchEngData
 ******************************************************************************/

PnlWzskShtDetail::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSHTDETAILDATA)
		{
};

string PnlWzskShtDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskShtDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskShtDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
