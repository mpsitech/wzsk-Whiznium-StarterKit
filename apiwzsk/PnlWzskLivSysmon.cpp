/**
	* \file PnlWzskLivSysmon.cpp
	* API code for job PnlWzskLivSysmon (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "PnlWzskLivSysmon.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLivSysmon::VecVDo
 ******************************************************************************/

uint PnlWzskLivSysmon::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskLivSysmon::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskLivSysmon::ContInf
 ******************************************************************************/

PnlWzskLivSysmon::ContInf::ContInf(
			const string& TxtCtp
		) :
			Block()
		{
	this->TxtCtp = TxtCtp;

	mask = {TXTCTP};
};

bool PnlWzskLivSysmon::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLivSysmon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLivSysmon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCtp", TxtCtp)) add(TXTCTP);
	};

	return basefound;
};

set<uint> PnlWzskLivSysmon::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtCtp == comp->TxtCtp) insert(items, TXTCTP);

	return(items);
};

set<uint> PnlWzskLivSysmon::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCTP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLivSysmon::StatShr
 ******************************************************************************/

PnlWzskLivSysmon::StatShr::StatShr(
			const uint ixWzskVExpstate
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;

	mask = {IXWZSKVEXPSTATE};
};

bool PnlWzskLivSysmon::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLivSysmon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLivSysmon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWzskLivSysmon::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);

	return(items);
};

set<uint> PnlWzskLivSysmon::StatShr::diff(
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
 class PnlWzskLivSysmon::Tag
 ******************************************************************************/

PnlWzskLivSysmon::Tag::Tag(
			const string& Cpt
			, const string& CptCtp
			, const string& CptPltTme
			, const string& CptPltCld
			, const string& CptPltTot
			, const string& CptPltCor
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptCtp = CptCtp;
	this->CptPltTme = CptPltTme;
	this->CptPltCld = CptPltCld;
	this->CptPltTot = CptPltTot;
	this->CptPltCor = CptPltCor;

	mask = {CPT, CPTCTP, CPTPLTTME, CPTPLTCLD, CPTPLTTOT, CPTPLTCOR};
};

bool PnlWzskLivSysmon::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLivSysmon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLivSysmon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtp", CptCtp)) add(CPTCTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPltTme", CptPltTme)) add(CPTPLTTME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPltCld", CptPltCld)) add(CPTPLTCLD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPltTot", CptPltTot)) add(CPTPLTTOT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPltCor", CptPltCor)) add(CPTPLTCOR);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLivSysmon::DpchAppDo
 ******************************************************************************/

PnlWzskLivSysmon::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIVSYSMONDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskLivSysmon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLivSysmon::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLivSysmonDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLivSysmon::DpchEngData
 ******************************************************************************/

PnlWzskLivSysmon::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIVSYSMONDATA)
		{
};

string PnlWzskLivSysmon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLivSysmon::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLivSysmonData");
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
 class PnlWzskLivSysmon::DpchEngLive
 ******************************************************************************/

PnlWzskLivSysmon::DpchEngLive::DpchEngLive() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIVSYSMONLIVE)
		{
};

string PnlWzskLivSysmon::DpchEngLive::getSrefsMask() {
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

void PnlWzskLivSysmon::DpchEngLive::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLivSysmonLive");
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

