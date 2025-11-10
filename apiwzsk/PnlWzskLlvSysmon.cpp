/**
	* \file PnlWzskLlvSysmon.cpp
	* API code for job PnlWzskLlvSysmon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskLlvSysmon.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvSysmon::VecVDo
 ******************************************************************************/

uint PnlWzskLlvSysmon::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskLlvSysmon::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskLlvSysmon::ContInf
 ******************************************************************************/

PnlWzskLlvSysmon::ContInf::ContInf(
			const string& TxtCtp
			, const string& TxtDhr
			, const string& TxtDhw
			, const string& TxtDrr
			, const string& TxtDrw
		) :
			Block()
			, TxtCtp(TxtCtp)
			, TxtDhr(TxtDhr)
			, TxtDhw(TxtDhw)
			, TxtDrr(TxtDrr)
			, TxtDrw(TxtDrw)
		{
	mask = {TXTCTP, TXTDHR, TXTDHW, TXTDRR, TXTDRW};
};

bool PnlWzskLlvSysmon::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLlvSysmon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLlvSysmon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCtp", TxtCtp)) add(TXTCTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDhr", TxtDhr)) add(TXTDHR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDhw", TxtDhw)) add(TXTDHW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDrr", TxtDrr)) add(TXTDRR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDrw", TxtDrw)) add(TXTDRW);
	};

	return basefound;
};

set<uint> PnlWzskLlvSysmon::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtCtp == comp->TxtCtp) insert(items, TXTCTP);
	if (TxtDhr == comp->TxtDhr) insert(items, TXTDHR);
	if (TxtDhw == comp->TxtDhw) insert(items, TXTDHW);
	if (TxtDrr == comp->TxtDrr) insert(items, TXTDRR);
	if (TxtDrw == comp->TxtDrw) insert(items, TXTDRW);

	return(items);
};

set<uint> PnlWzskLlvSysmon::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCTP, TXTDHR, TXTDHW, TXTDRR, TXTDRW};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvSysmon::StatShr
 ******************************************************************************/

PnlWzskLlvSysmon::StatShr::StatShr(
			const uint ixWzskVExpstate
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
		{
	mask = {IXWZSKVEXPSTATE};
};

bool PnlWzskLlvSysmon::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLlvSysmon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLlvSysmon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWzskLlvSysmon::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);

	return(items);
};

set<uint> PnlWzskLlvSysmon::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvSysmon::Tag
 ******************************************************************************/

PnlWzskLlvSysmon::Tag::Tag(
			const string& Cpt
			, const string& CptCtp
			, const string& CptPltTme
			, const string& CptPltCld
			, const string& CptPltTot
			, const string& CptPltCor
			, const string& CptDhr
			, const string& CptDhw
			, const string& CptDrr
			, const string& CptDrw
		) :
			Block()
			, Cpt(Cpt)
			, CptCtp(CptCtp)
			, CptPltTme(CptPltTme)
			, CptPltCld(CptPltCld)
			, CptPltTot(CptPltTot)
			, CptPltCor(CptPltCor)
			, CptDhr(CptDhr)
			, CptDhw(CptDhw)
			, CptDrr(CptDrr)
			, CptDrw(CptDrw)
		{
	mask = {CPT, CPTCTP, CPTPLTTME, CPTPLTCLD, CPTPLTTOT, CPTPLTCOR, CPTDHR, CPTDHW, CPTDRR, CPTDRW};
};

bool PnlWzskLlvSysmon::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLlvSysmon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLlvSysmon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtp", CptCtp)) add(CPTCTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPltTme", CptPltTme)) add(CPTPLTTME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPltCld", CptPltCld)) add(CPTPLTCLD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPltTot", CptPltTot)) add(CPTPLTTOT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPltCor", CptPltCor)) add(CPTPLTCOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDhr", CptDhr)) add(CPTDHR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDhw", CptDhw)) add(CPTDHW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDrr", CptDrr)) add(CPTDRR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDrw", CptDrw)) add(CPTDRW);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLlvSysmon::DpchAppDo
 ******************************************************************************/

PnlWzskLlvSysmon::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVSYSMONDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskLlvSysmon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvSysmon::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvSysmonDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvSysmon::DpchEngData
 ******************************************************************************/

PnlWzskLlvSysmon::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVSYSMONDATA)
		{
};

string PnlWzskLlvSysmon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvSysmon::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLlvSysmonData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};

/******************************************************************************
 class PnlWzskLlvSysmon::DpchEngLive
 ******************************************************************************/

PnlWzskLlvSysmon::DpchEngLive::DpchEngLive() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVSYSMONLIVE)
		{
};

string PnlWzskLlvSysmon::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(TS)) ss.push_back("ts");
	if (has(CLDTOTS)) ss.push_back("cldtots");
	if (has(CLD1S)) ss.push_back("cld1s");
	if (has(CLD2S)) ss.push_back("cld2s");
	if (has(CLD3S)) ss.push_back("cld3s");
	if (has(CLD4S)) ss.push_back("cld4s");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvSysmon::DpchEngLive::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLlvSysmonLive");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractFloatvecUclc(docctx, basexpath, "ts", "", ts)) add(TS);
		if (extractFloatvecUclc(docctx, basexpath, "cldtots", "", cldtots)) add(CLDTOTS);
		if (extractFloatvecUclc(docctx, basexpath, "cld1s", "", cld1s)) add(CLD1S);
		if (extractFloatvecUclc(docctx, basexpath, "cld2s", "", cld2s)) add(CLD2S);
		if (extractFloatvecUclc(docctx, basexpath, "cld3s", "", cld3s)) add(CLD3S);
		if (extractFloatvecUclc(docctx, basexpath, "cld4s", "", cld4s)) add(CLD4S);
	} else {
	};
};
