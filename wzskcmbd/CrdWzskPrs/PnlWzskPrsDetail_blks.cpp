/**
	* \file PnlWzskPrsDetail_blks.cpp
	* job handler for job PnlWzskPrsDetail (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrsDetail::VecVDo
 ******************************************************************************/

uint PnlWzskPrsDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjeditclick") return BUTJEDITCLICK;

	return(0);
};

string PnlWzskPrsDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJEDITCLICK) return("ButJEditClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrsDetail::ContIac
 ******************************************************************************/

PnlWzskPrsDetail::ContIac::ContIac(
			const string& TxfTit
			, const string& TxfFnm
			, const uint numFPupJ
			, const vector<uint>& numsFLstDrv
			, const uint numFPupSex
			, const string& TxfTel
			, const string& TxfEml
			, const string& TxfSal
		) :
			Block()
		{
	this->TxfTit = TxfTit;
	this->TxfFnm = TxfFnm;
	this->numFPupJ = numFPupJ;
	this->numsFLstDrv = numsFLstDrv;
	this->numFPupSex = numFPupSex;
	this->TxfTel = TxfTel;
	this->TxfEml = TxfEml;
	this->TxfSal = TxfSal;

	mask = {TXFTIT, TXFFNM, NUMFPUPJ, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
};

bool PnlWzskPrsDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstDrv", numsFLstDrv)) add(NUMSFLSTDRV);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSex", numFPupSex)) add(NUMFPUPSEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTel", TxfTel)) add(TXFTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEml", TxfEml)) add(TXFEML);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSal", TxfSal)) add(TXFSAL);
	};

	return basefound;
};

void PnlWzskPrsDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstDrv", numsFLstDrv);
		writeUintAttr(wr, itemtag, "sref", "numFPupSex", numFPupSex);
		writeStringAttr(wr, itemtag, "sref", "TxfTel", TxfTel);
		writeStringAttr(wr, itemtag, "sref", "TxfEml", TxfEml);
		writeStringAttr(wr, itemtag, "sref", "TxfSal", TxfSal);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrsDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (TxfFnm == comp->TxfFnm) insert(items, TXFFNM);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (compareUintvec(numsFLstDrv, comp->numsFLstDrv)) insert(items, NUMSFLSTDRV);
	if (numFPupSex == comp->numFPupSex) insert(items, NUMFPUPSEX);
	if (TxfTel == comp->TxfTel) insert(items, TXFTEL);
	if (TxfEml == comp->TxfEml) insert(items, TXFEML);
	if (TxfSal == comp->TxfSal) insert(items, TXFSAL);

	return(items);
};

set<uint> PnlWzskPrsDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, TXFFNM, NUMFPUPJ, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrsDetail::ContInf
 ******************************************************************************/

PnlWzskPrsDetail::ContInf::ContInf(
			const string& TxtLnm
			, const string& TxtDrv
		) :
			Block()
		{
	this->TxtLnm = TxtLnm;
	this->TxtDrv = TxtDrv;

	mask = {TXTLNM, TXTDRV};
};

void PnlWzskPrsDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtLnm", TxtLnm);
		writeStringAttr(wr, itemtag, "sref", "TxtDrv", TxtDrv);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrsDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtLnm == comp->TxtLnm) insert(items, TXTLNM);
	if (TxtDrv == comp->TxtDrv) insert(items, TXTDRV);

	return(items);
};

set<uint> PnlWzskPrsDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTLNM, TXTDRV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrsDetail::StatApp
 ******************************************************************************/

void PnlWzskPrsDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
			, const bool LstDrvAlt
			, const uint LstDrvNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstDrvAlt", LstDrvAlt);
		writeUintAttr(wr, itemtag, "sref", "LstDrvNumFirstdisp", LstDrvNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrsDetail::StatShr
 ******************************************************************************/

PnlWzskPrsDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfTitActive
			, const bool TxfFnmActive
			, const bool PupJActive
			, const bool ButJEditAvail
			, const bool TxtLnmActive
			, const bool LstDrvActive
			, const bool PupSexActive
			, const bool TxfTelActive
			, const bool TxfEmlActive
			, const bool TxfSalActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfTitActive = TxfTitActive;
	this->TxfFnmActive = TxfFnmActive;
	this->PupJActive = PupJActive;
	this->ButJEditAvail = ButJEditAvail;
	this->TxtLnmActive = TxtLnmActive;
	this->LstDrvActive = LstDrvActive;
	this->PupSexActive = PupSexActive;
	this->TxfTelActive = TxfTelActive;
	this->TxfEmlActive = TxfEmlActive;
	this->TxfSalActive = TxfSalActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE};
};

void PnlWzskPrsDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTitActive", TxfTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFnmActive", TxfFnmActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJActive", PupJActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJEditAvail", ButJEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtLnmActive", TxtLnmActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDrvActive", LstDrvActive);
		writeBoolAttr(wr, itemtag, "sref", "PupSexActive", PupSexActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTelActive", TxfTelActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfEmlActive", TxfEmlActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSalActive", TxfSalActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrsDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxfFnmActive == comp->TxfFnmActive) insert(items, TXFFNMACTIVE);
	if (PupJActive == comp->PupJActive) insert(items, PUPJACTIVE);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (TxtLnmActive == comp->TxtLnmActive) insert(items, TXTLNMACTIVE);
	if (LstDrvActive == comp->LstDrvActive) insert(items, LSTDRVACTIVE);
	if (PupSexActive == comp->PupSexActive) insert(items, PUPSEXACTIVE);
	if (TxfTelActive == comp->TxfTelActive) insert(items, TXFTELACTIVE);
	if (TxfEmlActive == comp->TxfEmlActive) insert(items, TXFEMLACTIVE);
	if (TxfSalActive == comp->TxfSalActive) insert(items, TXFSALACTIVE);

	return(items);
};

set<uint> PnlWzskPrsDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrsDetail::Tag
 ******************************************************************************/

void PnlWzskPrsDetail::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Title");
			writeStringAttr(wr, itemtag, "sref", "CptFnm", "first name");
			writeStringAttr(wr, itemtag, "sref", "CptLnm", "last name");
			writeStringAttr(wr, itemtag, "sref", "CptDrv", "");
			writeStringAttr(wr, itemtag, "sref", "CptSex", "sex");
			writeStringAttr(wr, itemtag, "sref", "CptTel", "phone");
			writeStringAttr(wr, itemtag, "sref", "CptEml", "e-mail");
			writeStringAttr(wr, itemtag, "sref", "CptSal", "salutation");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Title");
			writeStringAttr(wr, itemtag, "sref", "CptFnm", "Vorname");
			writeStringAttr(wr, itemtag, "sref", "CptLnm", "Nachname");
			writeStringAttr(wr, itemtag, "sref", "CptDrv", "");
			writeStringAttr(wr, itemtag, "sref", "CptSex", "sex");
			writeStringAttr(wr, itemtag, "sref", "CptTel", "Telefon");
			writeStringAttr(wr, itemtag, "sref", "CptEml", "E-Mail");
			writeStringAttr(wr, itemtag, "sref", "CptSal", "Briefanrede");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::DETAIL, ixWzskVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrsDetail::DpchAppData
 ******************************************************************************/

PnlWzskPrsDetail::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRSDETAILDATA)
		{
};

string PnlWzskPrsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrsDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrsDetailData");
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
 class PnlWzskPrsDetail::DpchAppDo
 ******************************************************************************/

PnlWzskPrsDetail::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRSDETAILDO)
		{
	ixVDo = 0;
};

string PnlWzskPrsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrsDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrsDetailDo");
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
 class PnlWzskPrsDetail::DpchEngData
 ******************************************************************************/

PnlWzskPrsDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstDrv
			, Feed* feedFPupJ
			, Feed* feedFPupSex
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRSDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTDRV, FEEDFPUPJ, FEEDFPUPSEX, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTDRV) && feedFLstDrv) this->feedFLstDrv = *feedFLstDrv;
	if (find(this->mask, FEEDFPUPJ) && feedFPupJ) this->feedFPupJ = *feedFPupJ;
	if (find(this->mask, FEEDFPUPSEX) && feedFPupSex) this->feedFPupSex = *feedFPupSex;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskPrsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDRV)) ss.push_back("feedFLstDrv");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(FEEDFPUPSEX)) ss.push_back("feedFPupSex");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrsDetail::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTDRV)) {feedFLstDrv = src->feedFLstDrv; add(FEEDFLSTDRV);};
	if (src->has(FEEDFPUPJ)) {feedFPupJ = src->feedFPupJ; add(FEEDFPUPJ);};
	if (src->has(FEEDFPUPSEX)) {feedFPupSex = src->feedFPupSex; add(FEEDFPUPSEX);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskPrsDetail::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskPrsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTDRV)) feedFLstDrv.writeXML(wr);
		if (has(FEEDFPUPJ)) feedFPupJ.writeXML(wr);
		if (has(FEEDFPUPSEX)) feedFPupSex.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
