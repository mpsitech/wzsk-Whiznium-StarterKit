/**
	* \file PnlWzskSesDetail.cpp
	* API code for job PnlWzskSesDetail (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "PnlWzskSesDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskSesDetail::VecVDo
 ******************************************************************************/

uint PnlWzskSesDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butusrviewclick") return BUTUSRVIEWCLICK;

	return(0);
};

string PnlWzskSesDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");

	return("");
};

/******************************************************************************
 class PnlWzskSesDetail::ContIac
 ******************************************************************************/

PnlWzskSesDetail::ContIac::ContIac(
			const string& TxfSta
			, const string& TxfSto
			, const string& TxfIp
		) :
			Block()
		{
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->TxfIp = TxfIp;

	mask = {TXFSTA, TXFSTO, TXFIP};
};

bool PnlWzskSesDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskSesDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskSesDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfIp", TxfIp)) add(TXFIP);
	};

	return basefound;
};

void PnlWzskSesDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskSesDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskSesDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeStringAttr(wr, itemtag, "sref", "TxfIp", TxfIp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskSesDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (TxfIp == comp->TxfIp) insert(items, TXFIP);

	return(items);
};

set<uint> PnlWzskSesDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSTA, TXFSTO, TXFIP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskSesDetail::ContInf
 ******************************************************************************/

PnlWzskSesDetail::ContInf::ContInf(
			const string& TxtUsr
		) :
			Block()
		{
	this->TxtUsr = TxtUsr;

	mask = {TXTUSR};
};

bool PnlWzskSesDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskSesDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskSesDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtUsr", TxtUsr)) add(TXTUSR);
	};

	return basefound;
};

set<uint> PnlWzskSesDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtUsr == comp->TxtUsr) insert(items, TXTUSR);

	return(items);
};

set<uint> PnlWzskSesDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTUSR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskSesDetail::StatApp
 ******************************************************************************/

PnlWzskSesDetail::StatApp::StatApp(
			const uint ixWzskVExpstate
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;

	mask = {IXWZSKVEXPSTATE};
};

bool PnlWzskSesDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskSesDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskSesDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWzskSesDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);

	return(items);
};

set<uint> PnlWzskSesDetail::StatApp::diff(
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
 class PnlWzskSesDetail::StatShr
 ******************************************************************************/

PnlWzskSesDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtUsrActive
			, const bool ButUsrViewAvail
			, const bool ButUsrViewActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxfIpActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtUsrActive = TxtUsrActive;
	this->ButUsrViewAvail = ButUsrViewAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxfIpActive = TxfIpActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTUSRACTIVE, BUTUSRVIEWAVAIL, BUTUSRVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFIPACTIVE};
};

bool PnlWzskSesDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskSesDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskSesDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtUsrActive", TxtUsrActive)) add(TXTUSRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsrViewAvail", ButUsrViewAvail)) add(BUTUSRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsrViewActive", ButUsrViewActive)) add(BUTUSRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfIpActive", TxfIpActive)) add(TXFIPACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskSesDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtUsrActive == comp->TxtUsrActive) insert(items, TXTUSRACTIVE);
	if (ButUsrViewAvail == comp->ButUsrViewAvail) insert(items, BUTUSRVIEWAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxfIpActive == comp->TxfIpActive) insert(items, TXFIPACTIVE);

	return(items);
};

set<uint> PnlWzskSesDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTUSRACTIVE, BUTUSRVIEWAVAIL, BUTUSRVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFIPACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskSesDetail::Tag
 ******************************************************************************/

PnlWzskSesDetail::Tag::Tag(
			const string& Cpt
			, const string& CptUsr
			, const string& CptSta
			, const string& CptSto
			, const string& CptIp
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptUsr = CptUsr;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptIp = CptIp;

	mask = {CPT, CPTUSR, CPTSTA, CPTSTO, CPTIP};
};

bool PnlWzskSesDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskSesDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskSesDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsr", CptUsr)) add(CPTUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIp", CptIp)) add(CPTIP);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskSesDetail::DpchAppData
 ******************************************************************************/

PnlWzskSesDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSESDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskSesDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskSesDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskSesDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskSesDetail::DpchAppDo
 ******************************************************************************/

PnlWzskSesDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSESDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskSesDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskSesDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskSesDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskSesDetail::DpchEngData
 ******************************************************************************/

PnlWzskSesDetail::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSESDETAILDATA)
		{
};

string PnlWzskSesDetail::DpchEngData::getSrefsMask() {
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

void PnlWzskSesDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskSesDetailData");
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

