/**
	* \file PnlWzskFilDetail.cpp
	* API code for job PnlWzskFilDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzskFilDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskFilDetail::VecVDo
 ******************************************************************************/

uint PnlWzskFilDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "butcnteditclick") return BUTCNTEDITCLICK;
	if (s == "butmimeditclick") return BUTMIMEDITCLICK;

	return(0);
};

string PnlWzskFilDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTCNTEDITCLICK) return("ButCntEditClick");
	if (ix == BUTMIMEDITCLICK) return("ButMimEditClick");

	return("");
};

/******************************************************************************
 class PnlWzskFilDetail::ContIac
 ******************************************************************************/

PnlWzskFilDetail::ContIac::ContIac(
			const string& TxfFnm
			, const uint numFLstClu
			, const uint numFPupRet
			, const uint numFPupCnt
			, const string& TxfCnt
			, const string& TxfAcv
			, const string& TxfAnm
			, const uint numFPupMim
			, const string& TxfMim
			, const string& TxfSiz
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfFnm = TxfFnm;
	this->numFLstClu = numFLstClu;
	this->numFPupRet = numFPupRet;
	this->numFPupCnt = numFPupCnt;
	this->TxfCnt = TxfCnt;
	this->TxfAcv = TxfAcv;
	this->TxfAnm = TxfAnm;
	this->numFPupMim = numFPupMim;
	this->TxfMim = TxfMim;
	this->TxfSiz = TxfSiz;
	this->TxfCmt = TxfCmt;

	mask = {TXFFNM, NUMFLSTCLU, NUMFPUPRET, NUMFPUPCNT, TXFCNT, TXFACV, TXFANM, NUMFPUPMIM, TXFMIM, TXFSIZ, TXFCMT};
};

bool PnlWzskFilDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskFilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCnt", numFPupCnt)) add(NUMFPUPCNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCnt", TxfCnt)) add(TXFCNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAcv", TxfAcv)) add(TXFACV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAnm", TxfAnm)) add(TXFANM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMim", numFPupMim)) add(NUMFPUPMIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMim", TxfMim)) add(TXFMIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSiz", TxfSiz)) add(TXFSIZ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWzskFilDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskFilDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskFilDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFPupCnt", numFPupCnt);
		writeStringAttr(wr, itemtag, "sref", "TxfCnt", TxfCnt);
		writeStringAttr(wr, itemtag, "sref", "TxfAcv", TxfAcv);
		writeStringAttr(wr, itemtag, "sref", "TxfAnm", TxfAnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupMim", numFPupMim);
		writeStringAttr(wr, itemtag, "sref", "TxfMim", TxfMim);
		writeStringAttr(wr, itemtag, "sref", "TxfSiz", TxfSiz);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskFilDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfFnm == comp->TxfFnm) insert(items, TXFFNM);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFPupCnt == comp->numFPupCnt) insert(items, NUMFPUPCNT);
	if (TxfCnt == comp->TxfCnt) insert(items, TXFCNT);
	if (TxfAcv == comp->TxfAcv) insert(items, TXFACV);
	if (TxfAnm == comp->TxfAnm) insert(items, TXFANM);
	if (numFPupMim == comp->numFPupMim) insert(items, NUMFPUPMIM);
	if (TxfMim == comp->TxfMim) insert(items, TXFMIM);
	if (TxfSiz == comp->TxfSiz) insert(items, TXFSIZ);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWzskFilDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFNM, NUMFLSTCLU, NUMFPUPRET, NUMFPUPCNT, TXFCNT, TXFACV, TXFANM, NUMFPUPMIM, TXFMIM, TXFSIZ, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskFilDetail::ContInf
 ******************************************************************************/

PnlWzskFilDetail::ContInf::ContInf(
			const string& TxtClu
			, const string& TxtReu
		) :
			Block()
		{
	this->TxtClu = TxtClu;
	this->TxtReu = TxtReu;

	mask = {TXTCLU, TXTREU};
};

bool PnlWzskFilDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskFilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
	};

	return basefound;
};

set<uint> PnlWzskFilDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);

	return(items);
};

set<uint> PnlWzskFilDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCLU, TXTREU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskFilDetail::StatApp
 ******************************************************************************/

PnlWzskFilDetail::StatApp::StatApp(
			const uint ixWzskVExpstate
			, const bool LstCluAlt
			, const bool PupCntAlt
			, const bool PupMimAlt
			, const uint LstCluNumFirstdisp
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->PupCntAlt = PupCntAlt;
	this->PupMimAlt = PupMimAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;

	mask = {IXWZSKVEXPSTATE, LSTCLUALT, PUPCNTALT, PUPMIMALT, LSTCLUNUMFIRSTDISP};
};

bool PnlWzskFilDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskFilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupCntAlt", PupCntAlt)) add(PUPCNTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupMimAlt", PupMimAlt)) add(PUPMIMALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWzskFilDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (PupCntAlt == comp->PupCntAlt) insert(items, PUPCNTALT);
	if (PupMimAlt == comp->PupMimAlt) insert(items, PUPMIMALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWzskFilDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, LSTCLUALT, PUPCNTALT, PUPMIMALT, LSTCLUNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskFilDetail::StatShr
 ******************************************************************************/

PnlWzskFilDetail::StatShr::StatShr(
			const bool TxfCntValid
			, const bool TxfMimValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfFnmActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool PupCntActive
			, const bool ButCntEditAvail
			, const bool TxfAcvActive
			, const bool TxfAnmActive
			, const bool PupMimActive
			, const bool ButMimEditAvail
			, const bool TxfSizActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfCntValid = TxfCntValid;
	this->TxfMimValid = TxfMimValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfFnmActive = TxfFnmActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->PupCntActive = PupCntActive;
	this->ButCntEditAvail = ButCntEditAvail;
	this->TxfAcvActive = TxfAcvActive;
	this->TxfAnmActive = TxfAnmActive;
	this->PupMimActive = PupMimActive;
	this->ButMimEditAvail = ButMimEditAvail;
	this->TxfSizActive = TxfSizActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFCNTVALID, TXFMIMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXFFNMACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPCNTACTIVE, BUTCNTEDITAVAIL, TXFACVACTIVE, TXFANMACTIVE, PUPMIMACTIVE, BUTMIMEDITAVAIL, TXFSIZACTIVE, TXFCMTACTIVE};
};

bool PnlWzskFilDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskFilDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCntValid", TxfCntValid)) add(TXFCNTVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMimValid", TxfMimValid)) add(TXFMIMVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFnmActive", TxfFnmActive)) add(TXFFNMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtReuActive", TxtReuActive)) add(TXTREUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", ButReuViewAvail)) add(BUTREUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewActive", ButReuViewActive)) add(BUTREUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupCntActive", PupCntActive)) add(PUPCNTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCntEditAvail", ButCntEditAvail)) add(BUTCNTEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAcvActive", TxfAcvActive)) add(TXFACVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAnmActive", TxfAnmActive)) add(TXFANMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupMimActive", PupMimActive)) add(PUPMIMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMimEditAvail", ButMimEditAvail)) add(BUTMIMEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSizActive", TxfSizActive)) add(TXFSIZACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskFilDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfCntValid == comp->TxfCntValid) insert(items, TXFCNTVALID);
	if (TxfMimValid == comp->TxfMimValid) insert(items, TXFMIMVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfFnmActive == comp->TxfFnmActive) insert(items, TXFFNMACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (PupCntActive == comp->PupCntActive) insert(items, PUPCNTACTIVE);
	if (ButCntEditAvail == comp->ButCntEditAvail) insert(items, BUTCNTEDITAVAIL);
	if (TxfAcvActive == comp->TxfAcvActive) insert(items, TXFACVACTIVE);
	if (TxfAnmActive == comp->TxfAnmActive) insert(items, TXFANMACTIVE);
	if (PupMimActive == comp->PupMimActive) insert(items, PUPMIMACTIVE);
	if (ButMimEditAvail == comp->ButMimEditAvail) insert(items, BUTMIMEDITAVAIL);
	if (TxfSizActive == comp->TxfSizActive) insert(items, TXFSIZACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWzskFilDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCNTVALID, TXFMIMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXFFNMACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPCNTACTIVE, BUTCNTEDITAVAIL, TXFACVACTIVE, TXFANMACTIVE, PUPMIMACTIVE, BUTMIMEDITAVAIL, TXFSIZACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskFilDetail::Tag
 ******************************************************************************/

PnlWzskFilDetail::Tag::Tag(
			const string& Cpt
			, const string& CptFnm
			, const string& CptClu
			, const string& CptReu
			, const string& CptCnt
			, const string& CptAcv
			, const string& CptAnm
			, const string& CptMim
			, const string& CptSiz
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptFnm = CptFnm;
	this->CptClu = CptClu;
	this->CptReu = CptReu;
	this->CptCnt = CptCnt;
	this->CptAcv = CptAcv;
	this->CptAnm = CptAnm;
	this->CptMim = CptMim;
	this->CptSiz = CptSiz;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTFNM, CPTCLU, CPTREU, CPTCNT, CPTACV, CPTANM, CPTMIM, CPTSIZ, CPTCMT};
};

bool PnlWzskFilDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskFilDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskFilDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFnm", CptFnm)) add(CPTFNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCnt", CptCnt)) add(CPTCNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAcv", CptAcv)) add(CPTACV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAnm", CptAnm)) add(CPTANM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMim", CptMim)) add(CPTMIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSiz", CptSiz)) add(CPTSIZ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskFilDetail::DpchAppData
 ******************************************************************************/

PnlWzskFilDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKFILDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskFilDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskFilDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskFilDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskFilDetail::DpchAppDo
 ******************************************************************************/

PnlWzskFilDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKFILDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskFilDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskFilDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskFilDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskFilDetail::DpchEngData
 ******************************************************************************/

PnlWzskFilDetail::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKFILDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
	feedFPupCnt.tag = "FeedFPupCnt";
	feedFPupMim.tag = "FeedFPupMim";
	feedFPupRet.tag = "FeedFPupRet";
};

string PnlWzskFilDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPCNT)) ss.push_back("feedFPupCnt");
	if (has(FEEDFPUPMIM)) ss.push_back("feedFPupMim");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskFilDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskFilDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFPupCnt.readXML(docctx, basexpath, true)) add(FEEDFPUPCNT);
		if (feedFPupMim.readXML(docctx, basexpath, true)) add(FEEDFPUPMIM);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFPupCnt.clear();
		feedFPupMim.clear();
		feedFPupRet.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

