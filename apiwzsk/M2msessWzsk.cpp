/**
	* \file M2msessWzsk.cpp
	* API code for job M2msessWzsk (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "M2msessWzsk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class M2msessWzsk::StatShr
 ******************************************************************************/

M2msessWzsk::StatShr::StatShr(
			const string& scrJrefAcqpreview
			, const string& scrJrefAcqptcloud
			, const string& scrJrefActexposure
			, const string& scrJrefActlaser
			, const string& scrJrefActservo
			, const string& scrJrefIprcorner
			, const string& scrJrefIprtrace
			, const string& scrJrefSrcsysinfo
		) :
			Block()
		{
	this->scrJrefAcqpreview = scrJrefAcqpreview;
	this->scrJrefAcqptcloud = scrJrefAcqptcloud;
	this->scrJrefActexposure = scrJrefActexposure;
	this->scrJrefActlaser = scrJrefActlaser;
	this->scrJrefActservo = scrJrefActservo;
	this->scrJrefIprcorner = scrJrefIprcorner;
	this->scrJrefIprtrace = scrJrefIprtrace;
	this->scrJrefSrcsysinfo = scrJrefSrcsysinfo;

	mask = {SCRJREFACQPREVIEW, SCRJREFACQPTCLOUD, SCRJREFACTEXPOSURE, SCRJREFACTLASER, SCRJREFACTSERVO, SCRJREFIPRCORNER, SCRJREFIPRTRACE, SCRJREFSRCSYSINFO};
};

bool M2msessWzsk::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrM2msessWzsk");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrM2msessWzsk";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqpreview", scrJrefAcqpreview)) add(SCRJREFACQPREVIEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqptcloud", scrJrefAcqptcloud)) add(SCRJREFACQPTCLOUD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActexposure", scrJrefActexposure)) add(SCRJREFACTEXPOSURE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActlaser", scrJrefActlaser)) add(SCRJREFACTLASER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActservo", scrJrefActservo)) add(SCRJREFACTSERVO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefIprcorner", scrJrefIprcorner)) add(SCRJREFIPRCORNER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefIprtrace", scrJrefIprtrace)) add(SCRJREFIPRTRACE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrcsysinfo", scrJrefSrcsysinfo)) add(SCRJREFSRCSYSINFO);
	};

	return basefound;
};

set<uint> M2msessWzsk::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefAcqpreview == comp->scrJrefAcqpreview) insert(items, SCRJREFACQPREVIEW);
	if (scrJrefAcqptcloud == comp->scrJrefAcqptcloud) insert(items, SCRJREFACQPTCLOUD);
	if (scrJrefActexposure == comp->scrJrefActexposure) insert(items, SCRJREFACTEXPOSURE);
	if (scrJrefActlaser == comp->scrJrefActlaser) insert(items, SCRJREFACTLASER);
	if (scrJrefActservo == comp->scrJrefActservo) insert(items, SCRJREFACTSERVO);
	if (scrJrefIprcorner == comp->scrJrefIprcorner) insert(items, SCRJREFIPRCORNER);
	if (scrJrefIprtrace == comp->scrJrefIprtrace) insert(items, SCRJREFIPRTRACE);
	if (scrJrefSrcsysinfo == comp->scrJrefSrcsysinfo) insert(items, SCRJREFSRCSYSINFO);

	return(items);
};

set<uint> M2msessWzsk::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFACQPREVIEW, SCRJREFACQPTCLOUD, SCRJREFACTEXPOSURE, SCRJREFACTLASER, SCRJREFACTSERVO, SCRJREFIPRCORNER, SCRJREFIPRTRACE, SCRJREFSRCSYSINFO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class M2msessWzsk::DpchEngData
 ******************************************************************************/

M2msessWzsk::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGM2MSESSWZSKDATA)
		{
};

string M2msessWzsk::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void M2msessWzsk::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngM2msessWzskData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
	} else {
		statshr = StatShr();
	};
};
