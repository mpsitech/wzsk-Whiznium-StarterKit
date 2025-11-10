/**
	* \file PnlWzskVtrMonitor.cpp
	* API code for job PnlWzskVtrMonitor (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskVtrMonitor.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskVtrMonitor::VecVDo
 ******************************************************************************/

uint PnlWzskVtrMonitor::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskVtrMonitor::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskVtrMonitor::StatShr
 ******************************************************************************/

PnlWzskVtrMonitor::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const uint CusAplHeight
			, const uint CusVplHeight
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, CusAplHeight(CusAplHeight)
			, CusVplHeight(CusVplHeight)
		{
	mask = {IXWZSKVEXPSTATE, CUSAPLHEIGHT, CUSVPLHEIGHT};
};

bool PnlWzskVtrMonitor::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskVtrMonitor");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskVtrMonitor";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "CusAplHeight", CusAplHeight)) add(CUSAPLHEIGHT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "CusVplHeight", CusVplHeight)) add(CUSVPLHEIGHT);
	};

	return basefound;
};

set<uint> PnlWzskVtrMonitor::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (CusAplHeight == comp->CusAplHeight) insert(items, CUSAPLHEIGHT);
	if (CusVplHeight == comp->CusVplHeight) insert(items, CUSVPLHEIGHT);

	return(items);
};

set<uint> PnlWzskVtrMonitor::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, CUSAPLHEIGHT, CUSVPLHEIGHT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskVtrMonitor::Tag
 ******************************************************************************/

PnlWzskVtrMonitor::Tag::Tag(
			const string& Cpt
			, const string& CptAplTme
			, const string& CptAplAng
			, const string& CptVplTme
			, const string& CptVplAng
		) :
			Block()
			, Cpt(Cpt)
			, CptAplTme(CptAplTme)
			, CptAplAng(CptAplAng)
			, CptVplTme(CptVplTme)
			, CptVplAng(CptVplAng)
		{
	mask = {CPT, CPTAPLTME, CPTAPLANG, CPTVPLTME, CPTVPLANG};
};

bool PnlWzskVtrMonitor::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskVtrMonitor");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskVtrMonitor";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAplTme", CptAplTme)) add(CPTAPLTME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAplAng", CptAplAng)) add(CPTAPLANG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVplTme", CptVplTme)) add(CPTVPLTME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVplAng", CptVplAng)) add(CPTVPLANG);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskVtrMonitor::DpchAppDo
 ******************************************************************************/

PnlWzskVtrMonitor::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKVTRMONITORDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskVtrMonitor::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrMonitor::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskVtrMonitorDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskVtrMonitor::DpchEngData
 ******************************************************************************/

PnlWzskVtrMonitor::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRMONITORDATA)
		{
};

string PnlWzskVtrMonitor::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrMonitor::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskVtrMonitorData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		statshr = StatShr();
		tag = Tag();
	};
};

/******************************************************************************
 class PnlWzskVtrMonitor::DpchEngLive
 ******************************************************************************/

PnlWzskVtrMonitor::DpchEngLive::DpchEngLive() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKVTRMONITORLIVE)
		{
	phiMin = 0.0;
	phiMax = 0.0;
	omegaMin = 0.0;
	omegaMax = 0.0;
};

string PnlWzskVtrMonitor::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(TS)) ss.push_back("ts");
	if (has(PHIS)) ss.push_back("phis");
	if (has(PHIMIN)) ss.push_back("phiMin");
	if (has(PHIMAX)) ss.push_back("phiMax");
	if (has(OMEGAS)) ss.push_back("omegas");
	if (has(OMEGAMIN)) ss.push_back("omegaMin");
	if (has(OMEGAMAX)) ss.push_back("omegaMax");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskVtrMonitor::DpchEngLive::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskVtrMonitorLive");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractFloatvecUclc(docctx, basexpath, "ts", "", ts)) add(TS);
		if (extractFloatvecUclc(docctx, basexpath, "phis", "", phis)) add(PHIS);
		if (extractFloatUclc(docctx, basexpath, "phiMin", "", phiMin)) add(PHIMIN);
		if (extractFloatUclc(docctx, basexpath, "phiMax", "", phiMax)) add(PHIMAX);
		if (extractFloatvecUclc(docctx, basexpath, "omegas", "", omegas)) add(OMEGAS);
		if (extractFloatUclc(docctx, basexpath, "omegaMin", "", omegaMin)) add(OMEGAMIN);
		if (extractFloatUclc(docctx, basexpath, "omegaMax", "", omegaMax)) add(OMEGAMAX);
	} else {
	};
};
