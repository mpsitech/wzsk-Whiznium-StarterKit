/**
	* \file PnlWzskLlvIdent.cpp
	* API code for job PnlWzskLlvIdent (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskLlvIdent.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvIdent::VecVDo
 ******************************************************************************/

uint PnlWzskLlvIdent::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskLlvIdent::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskLlvIdent::ContInf
 ******************************************************************************/

PnlWzskLlvIdent::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtVve
			, const string& TxtVgh
			, const string& TxtVau
			, const string& TxtVfm
			, const string& TxtVfd
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtVve(TxtVve)
			, TxtVgh(TxtVgh)
			, TxtVau(TxtVau)
			, TxtVfm(TxtVfm)
			, TxtVfd(TxtVfd)
		{
	mask = {TXTSRF, TXTVVE, TXTVGH, TXTVAU, TXTVFM, TXTVFD};
};

bool PnlWzskLlvIdent::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLlvIdent");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLlvIdent";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVve", TxtVve)) add(TXTVVE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVgh", TxtVgh)) add(TXTVGH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVau", TxtVau)) add(TXTVAU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVfm", TxtVfm)) add(TXTVFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVfd", TxtVfd)) add(TXTVFD);
	};

	return basefound;
};

set<uint> PnlWzskLlvIdent::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtVve == comp->TxtVve) insert(items, TXTVVE);
	if (TxtVgh == comp->TxtVgh) insert(items, TXTVGH);
	if (TxtVau == comp->TxtVau) insert(items, TXTVAU);
	if (TxtVfm == comp->TxtVfm) insert(items, TXTVFM);
	if (TxtVfd == comp->TxtVfd) insert(items, TXTVFD);

	return(items);
};

set<uint> PnlWzskLlvIdent::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTVVE, TXTVGH, TXTVAU, TXTVFM, TXTVFD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvIdent::StatShr
 ******************************************************************************/

PnlWzskLlvIdent::StatShr::StatShr(
			const uint ixWzskVExpstate
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
		{
	mask = {IXWZSKVEXPSTATE};
};

bool PnlWzskLlvIdent::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLlvIdent");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLlvIdent";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWzskLlvIdent::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);

	return(items);
};

set<uint> PnlWzskLlvIdent::StatShr::diff(
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
 class PnlWzskLlvIdent::Tag
 ******************************************************************************/

PnlWzskLlvIdent::Tag::Tag(
			const string& Cpt
			, const string& HdgVsp
			, const string& CptSrf
			, const string& CptVve
			, const string& CptVgh
			, const string& CptVau
			, const string& CptVfm
			, const string& CptVfd
		) :
			Block()
			, Cpt(Cpt)
			, HdgVsp(HdgVsp)
			, CptSrf(CptSrf)
			, CptVve(CptVve)
			, CptVgh(CptVgh)
			, CptVau(CptVau)
			, CptVfm(CptVfm)
			, CptVfd(CptVfd)
		{
	mask = {CPT, HDGVSP, CPTSRF, CPTVVE, CPTVGH, CPTVAU, CPTVFM, CPTVFD};
};

bool PnlWzskLlvIdent::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLlvIdent");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLlvIdent";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgVsp", HdgVsp)) add(HDGVSP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVve", CptVve)) add(CPTVVE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVgh", CptVgh)) add(CPTVGH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVau", CptVau)) add(CPTVAU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVfm", CptVfm)) add(CPTVFM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVfd", CptVfd)) add(CPTVFD);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLlvIdent::DpchAppDo
 ******************************************************************************/

PnlWzskLlvIdent::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVIDENTDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskLlvIdent::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvIdent::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLlvIdentDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvIdent::DpchEngData
 ******************************************************************************/

PnlWzskLlvIdent::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVIDENTDATA)
		{
};

string PnlWzskLlvIdent::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvIdent::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLlvIdentData");
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
