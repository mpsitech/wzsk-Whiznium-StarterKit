/**
	* \file PnlWzskLlvTermZuvsp.cpp
	* API code for job PnlWzskLlvTermZuvsp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskLlvTermZuvsp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvTermZuvsp::VecVDo
 ******************************************************************************/

uint PnlWzskLlvTermZuvsp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;
	if (s == "butapdclick") return BUTAPDCLICK;
	if (s == "butsmtclick") return BUTSMTCLICK;

	return(0);
};

string PnlWzskLlvTermZuvsp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTAPDCLICK) return("ButApdClick");
	if (ix == BUTSMTCLICK) return("ButSmtClick");

	return("");
};

/******************************************************************************
 class PnlWzskLlvTermZuvsp::ContIac
 ******************************************************************************/

PnlWzskLlvTermZuvsp::ContIac::ContIac(
			const uint numFPupCmd
			, const string& TxfCsq
		) :
			Block()
			, numFPupCmd(numFPupCmd)
			, TxfCsq(TxfCsq)
		{
	mask = {NUMFPUPCMD, TXFCSQ};
};

bool PnlWzskLlvTermZuvsp::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLlvTermZuvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLlvTermZuvsp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCmd", numFPupCmd)) add(NUMFPUPCMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCsq", TxfCsq)) add(TXFCSQ);
	};

	return basefound;
};

void PnlWzskLlvTermZuvsp::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLlvTermZuvsp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLlvTermZuvsp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupCmd", numFPupCmd);
		writeStringAttr(wr, itemtag, "sref", "TxfCsq", TxfCsq);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvTermZuvsp::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupCmd == comp->numFPupCmd) insert(items, NUMFPUPCMD);
	if (TxfCsq == comp->TxfCsq) insert(items, TXFCSQ);

	return(items);
};

set<uint> PnlWzskLlvTermZuvsp::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPCMD, TXFCSQ};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvTermZuvsp::ContInf
 ******************************************************************************/

PnlWzskLlvTermZuvsp::ContInf::ContInf(
			const bool ButClaimOn
			, const string& TxtCst
			, const string& TxtDatLog
		) :
			Block()
			, ButClaimOn(ButClaimOn)
			, TxtCst(TxtCst)
			, TxtDatLog(TxtDatLog)
		{
	mask = {BUTCLAIMON, TXTCST, TXTDATLOG};
};

bool PnlWzskLlvTermZuvsp::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLlvTermZuvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLlvTermZuvsp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButClaimOn", ButClaimOn)) add(BUTCLAIMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCst", TxtCst)) add(TXTCST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDatLog", TxtDatLog)) add(TXTDATLOG);
	};

	return basefound;
};

set<uint> PnlWzskLlvTermZuvsp::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtCst == comp->TxtCst) insert(items, TXTCST);
	if (TxtDatLog == comp->TxtDatLog) insert(items, TXTDATLOG);

	return(items);
};

set<uint> PnlWzskLlvTermZuvsp::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCLAIMON, TXTCST, TXTDATLOG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvTermZuvsp::StatShr
 ******************************************************************************/

PnlWzskLlvTermZuvsp::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool ButSmtActive
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, ButClaimActive(ButClaimActive)
			, ButSmtActive(ButSmtActive)
		{
	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTSMTACTIVE};
};

bool PnlWzskLlvTermZuvsp::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLlvTermZuvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLlvTermZuvsp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClaimActive", ButClaimActive)) add(BUTCLAIMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSmtActive", ButSmtActive)) add(BUTSMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskLlvTermZuvsp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (ButSmtActive == comp->ButSmtActive) insert(items, BUTSMTACTIVE);

	return(items);
};

set<uint> PnlWzskLlvTermZuvsp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTSMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvTermZuvsp::Tag
 ******************************************************************************/

PnlWzskLlvTermZuvsp::Tag::Tag(
			const string& Cpt
			, const string& CptCst
			, const string& HdgDio
			, const string& HdgCex
			, const string& CptCmd
			, const string& ButApd
			, const string& CptCsq
			, const string& ButSmt
		) :
			Block()
			, Cpt(Cpt)
			, CptCst(CptCst)
			, HdgDio(HdgDio)
			, HdgCex(HdgCex)
			, CptCmd(CptCmd)
			, ButApd(ButApd)
			, CptCsq(CptCsq)
			, ButSmt(ButSmt)
		{
	mask = {CPT, CPTCST, HDGDIO, HDGCEX, CPTCMD, BUTAPD, CPTCSQ, BUTSMT};
};

bool PnlWzskLlvTermZuvsp::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLlvTermZuvsp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLlvTermZuvsp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCst", CptCst)) add(CPTCST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgDio", HdgDio)) add(HDGDIO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgCex", HdgCex)) add(HDGCEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmd", CptCmd)) add(CPTCMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButApd", ButApd)) add(BUTAPD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCsq", CptCsq)) add(CPTCSQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSmt", ButSmt)) add(BUTSMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLlvTermZuvsp::DpchAppData
 ******************************************************************************/

PnlWzskLlvTermZuvsp::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVTERMZUVSPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskLlvTermZuvsp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvTermZuvsp::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvTermZuvspData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvTermZuvsp::DpchAppDo
 ******************************************************************************/

PnlWzskLlvTermZuvsp::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVTERMZUVSPDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskLlvTermZuvsp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvTermZuvsp::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvTermZuvspDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvTermZuvsp::DpchEngData
 ******************************************************************************/

PnlWzskLlvTermZuvsp::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVTERMZUVSPDATA)
		{
	feedFPupCmd.tag = "FeedFPupCmd";
};

string PnlWzskLlvTermZuvsp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPCMD)) ss.push_back("feedFPupCmd");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvTermZuvsp::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLlvTermZuvspData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupCmd.readXML(docctx, basexpath, true)) add(FEEDFPUPCMD);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupCmd.clear();
		statshr = StatShr();
		tag = Tag();
	};
};
