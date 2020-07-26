/**
	* \file M2msessWzsk.cpp
	* API code for job M2msessWzsk (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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
			, const string& scrJrefActlaser
			, const string& scrJrefActservo
			, const string& scrJrefIprcorner
			, const string& scrJrefIprtrace
		) :
			Block()
		{
	this->scrJrefAcqpreview = scrJrefAcqpreview;
	this->scrJrefAcqptcloud = scrJrefAcqptcloud;
	this->scrJrefActlaser = scrJrefActlaser;
	this->scrJrefActservo = scrJrefActservo;
	this->scrJrefIprcorner = scrJrefIprcorner;
	this->scrJrefIprtrace = scrJrefIprtrace;

	mask = {SCRJREFACQPREVIEW, SCRJREFACQPTCLOUD, SCRJREFACTLASER, SCRJREFACTSERVO, SCRJREFIPRCORNER, SCRJREFIPRTRACE};
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
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActlaser", scrJrefActlaser)) add(SCRJREFACTLASER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActservo", scrJrefActservo)) add(SCRJREFACTSERVO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefIprcorner", scrJrefIprcorner)) add(SCRJREFIPRCORNER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefIprtrace", scrJrefIprtrace)) add(SCRJREFIPRTRACE);
	};

	return basefound;
};

set<uint> M2msessWzsk::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefAcqpreview == comp->scrJrefAcqpreview) insert(items, SCRJREFACQPREVIEW);
	if (scrJrefAcqptcloud == comp->scrJrefAcqptcloud) insert(items, SCRJREFACQPTCLOUD);
	if (scrJrefActlaser == comp->scrJrefActlaser) insert(items, SCRJREFACTLASER);
	if (scrJrefActservo == comp->scrJrefActservo) insert(items, SCRJREFACTSERVO);
	if (scrJrefIprcorner == comp->scrJrefIprcorner) insert(items, SCRJREFIPRCORNER);
	if (scrJrefIprtrace == comp->scrJrefIprtrace) insert(items, SCRJREFIPRTRACE);

	return(items);
};

set<uint> M2msessWzsk::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFACQPREVIEW, SCRJREFACQPTCLOUD, SCRJREFACTLASER, SCRJREFACTSERVO, SCRJREFIPRCORNER, SCRJREFIPRTRACE};
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

