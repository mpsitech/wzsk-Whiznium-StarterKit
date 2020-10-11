/**
	* \file PnlWzskShtDetail_blks.cpp
	* job handler for job PnlWzskShtDetail (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

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

void PnlWzskShtDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskShtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskShtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSes", TxtSes);
		writeStringAttr(wr, itemtag, "sref", "TxtObj", TxtObj);
	xmlTextWriterEndElement(wr);
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

void PnlWzskShtDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskShtDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskShtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
	xmlTextWriterEndElement(wr);
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

void PnlWzskShtDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskShtDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskShtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSesActive", TxtSesActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSesViewAvail", ButSesViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSesViewActive", ButSesViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtObjActive", TxtObjActive);
		writeBoolAttr(wr, itemtag, "sref", "ButObjViewAvail", ButObjViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButObjViewActive", ButObjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
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

void PnlWzskShtDetail::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskShtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskShtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSes", "session");
			writeStringAttr(wr, itemtag, "sref", "CptObj", "object");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "start");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSes", "Sitzung");
			writeStringAttr(wr, itemtag, "sref", "CptObj", "Objekt");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "Start");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Notiz");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::DETAIL, ixWzskVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskShtDetail::DpchAppData
 ******************************************************************************/

PnlWzskShtDetail::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSHTDETAILDATA)
		{
};

string PnlWzskShtDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskShtDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskShtDetailData");
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
 class PnlWzskShtDetail::DpchAppDo
 ******************************************************************************/

PnlWzskShtDetail::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSHTDETAILDO)
		{
	ixVDo = 0;
};

string PnlWzskShtDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskShtDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskShtDetailDo");
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
 class PnlWzskShtDetail::DpchEngData
 ******************************************************************************/

PnlWzskShtDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSHTDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskShtDetail::DpchEngData::getSrefsMask() {
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

void PnlWzskShtDetail::DpchEngData::merge(
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

void PnlWzskShtDetail::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskShtDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

