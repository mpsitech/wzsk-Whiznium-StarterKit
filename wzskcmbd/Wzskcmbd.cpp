/**
	* \file Wzskcmbd.cpp
	* inter-thread exchange object for Wzsk combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "Wzskcmbd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchAppWzsk
 ******************************************************************************/

DpchAppWzsk::DpchAppWzsk(
			const uint ixWzskVDpch
		) :
			DpchWzsk(ixWzskVDpch)
		{
	jref = 0;
};

DpchAppWzsk::~DpchAppWzsk() {
};

bool DpchAppWzsk::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchAppWzsk::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchAppWzsk::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup[VecWzskVDpch::getSref(ixWzskVDpch)];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
	};
};

void DpchAppWzsk::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecWzskVDpch::getSref(ixWzskVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppWzskAlert
 ******************************************************************************/

DpchAppWzskAlert::DpchAppWzskAlert() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKALERT)
		{
};

bool DpchAppWzskAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppWzskAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppWzskAlert::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzskAlert"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
		if (me.isMember("numFMcb")) {numFMcb = me["numFMcb"].asInt(); add(NUMFMCB);};
	};
};

void DpchAppWzskAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppWzskInit
 ******************************************************************************/

DpchAppWzskInit::DpchAppWzskInit() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKINIT)
		{
};

/******************************************************************************
 class DpchAppWzskResume
 ******************************************************************************/

DpchAppWzskResume::DpchAppWzskResume() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKRESUME)
		{
};

/******************************************************************************
 class DpchEngWzsk
 ******************************************************************************/

DpchEngWzsk::DpchEngWzsk(
			const uint ixWzskVDpch
			, const ubigint jref
		) :
			DpchWzsk(ixWzskVDpch)
		{
	this->jref = jref;

	mask = {JREF};
};

DpchEngWzsk::~DpchEngWzsk() {
};

bool DpchEngWzsk::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchEngWzsk::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchEngWzsk::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngWzsk* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngWzsk::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup[VecWzskVDpch::getSref(ixWzskVDpch)] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
};

void DpchEngWzsk::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	string tag = VecWzskVDpch::getSref(ixWzskVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWzskAck
 ******************************************************************************/

DpchEngWzskAck::DpchEngWzskAck(
			const ubigint jref
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKACK, jref)
		{
};

/******************************************************************************
 class DpchEngWzskAlert
 ******************************************************************************/

DpchEngWzskAlert::DpchEngWzskAlert(
			const ubigint jref
			, ContInfWzskAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKALERT, jref)
		{
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngWzskAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngWzskAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWzskAlert::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngWzskAlert* src = (DpchEngWzskAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngWzskAlert::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskAlert"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFMCB)) feedFMcb.writeJSON(me);
};

void DpchEngWzskAlert::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWzskConfirm
 ******************************************************************************/

DpchEngWzskConfirm::DpchEngWzskConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKCONFIRM, jref)
		{
	this->accepted = accepted;
	this->jref = jref;
	this->sref = sref;

	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngWzskConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngWzskConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(JREF)) ss.push_back("jref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWzskConfirm::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngWzskConfirm* src = (DpchEngWzskConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngWzskConfirm::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskConfirm"] = Json::Value(Json::objectValue);

	if (has(ACCEPTED)) me["accepted"] = accepted;
	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(SREF)) me["sref"] = sref;
};

void DpchEngWzskConfirm::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWzskSuspend
 ******************************************************************************/

DpchEngWzskSuspend::DpchEngWzskSuspend(
			const ubigint jref
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSUSPEND, jref)
		{
};

/******************************************************************************
 class StgWzskAppearance
 ******************************************************************************/

StgWzskAppearance::StgWzskAppearance(
			const usmallint histlength
			, const bool suspsess
			, const uint sesstterm
			, const uint sesstwarn
			, const uint roottterm
		) :
			Block()
		{
	this->histlength = histlength;
	this->suspsess = suspsess;
	this->sesstterm = sesstterm;
	this->sesstwarn = sesstwarn;
	this->roottterm = roottterm;
	mask = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
};

bool StgWzskAppearance::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskAppearance");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskAppearance";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "suspsess", suspsess)) add(SUSPSESS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstterm", sesstterm)) add(SESSTTERM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstwarn", sesstwarn)) add(SESSTWARN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "roottterm", roottterm)) add(ROOTTTERM);
	};

	return basefound;
};

void StgWzskAppearance::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskAppearance";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskAppearance";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
		writeBoolAttr(wr, itemtag, "sref", "suspsess", suspsess);
		writeUintAttr(wr, itemtag, "sref", "sesstterm", sesstterm);
		writeUintAttr(wr, itemtag, "sref", "sesstwarn", sesstwarn);
		writeUintAttr(wr, itemtag, "sref", "roottterm", roottterm);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskAppearance::comm(
			const StgWzskAppearance* comp
		) {
	set<uint> items;

	if (histlength == comp->histlength) insert(items, HISTLENGTH);
	if (suspsess == comp->suspsess) insert(items, SUSPSESS);
	if (sesstterm == comp->sesstterm) insert(items, SESSTTERM);
	if (sesstwarn == comp->sesstwarn) insert(items, SESSTWARN);
	if (roottterm == comp->roottterm) insert(items, ROOTTTERM);

	return(items);
};

set<uint> StgWzskAppearance::diff(
			const StgWzskAppearance* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskAppsrv
 ******************************************************************************/

StgWzskAppsrv::StgWzskAppsrv(
			const usmallint port
			, const bool https
		) :
			Block()
		{
	this->port = port;
	this->https = https;
	mask = {PORT, HTTPS};
};

bool StgWzskAppsrv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskAppsrv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskAppsrv";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "https", https)) add(HTTPS);
	};

	return basefound;
};

void StgWzskAppsrv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskAppsrv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskAppsrv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeBoolAttr(wr, itemtag, "sref", "https", https);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskAppsrv::comm(
			const StgWzskAppsrv* comp
		) {
	set<uint> items;

	if (port == comp->port) insert(items, PORT);
	if (https == comp->https) insert(items, HTTPS);

	return(items);
};

set<uint> StgWzskAppsrv::diff(
			const StgWzskAppsrv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PORT, HTTPS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskCamera
 ******************************************************************************/

StgWzskCamera::StgWzskCamera(
			const float hpix
			, const float f
			, const float fn
		) :
			Block()
		{
	this->hpix = hpix;
	this->f = f;
	this->fn = fn;
	mask = {HPIX, F, FN};
};

bool StgWzskCamera::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskCamera");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskCamera";

	if (basefound) {
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "hpix", hpix)) add(HPIX);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "f", f)) add(F);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "fn", fn)) add(FN);
	};

	return basefound;
};

void StgWzskCamera::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskCamera";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskCamera";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeFloatAttr(wr, itemtag, "sref", "hpix", hpix);
		writeFloatAttr(wr, itemtag, "sref", "f", f);
		writeFloatAttr(wr, itemtag, "sref", "fn", fn);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskCamera::comm(
			const StgWzskCamera* comp
		) {
	set<uint> items;

	if (compareFloat(hpix, comp->hpix) < 1.0e-4) insert(items, HPIX);
	if (compareFloat(f, comp->f) < 1.0e-4) insert(items, F);
	if (compareFloat(fn, comp->fn) < 1.0e-4) insert(items, FN);

	return(items);
};

set<uint> StgWzskCamera::diff(
			const StgWzskCamera* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {HPIX, F, FN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskcmbd
 ******************************************************************************/

StgWzskcmbd::StgWzskcmbd(
			const usmallint jobprcn
			, const usmallint opprcn
			, const bool appsrv
			, const bool ddspub
			, const bool uasrv
		) :
			Block()
		{
	this->jobprcn = jobprcn;
	this->opprcn = opprcn;
	this->appsrv = appsrv;
	this->ddspub = ddspub;
	this->uasrv = uasrv;
	mask = {JOBPRCN, OPPRCN, APPSRV, DDSPUB, UASRV};
};

bool StgWzskcmbd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskcmbd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskcmbd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrv", appsrv)) add(APPSRV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ddspub", ddspub)) add(DDSPUB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "uasrv", uasrv)) add(UASRV);
	};

	return basefound;
};

void StgWzskcmbd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskcmbd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskcmbd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
		writeBoolAttr(wr, itemtag, "sref", "appsrv", appsrv);
		writeBoolAttr(wr, itemtag, "sref", "ddspub", ddspub);
		writeBoolAttr(wr, itemtag, "sref", "uasrv", uasrv);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskcmbd::comm(
			const StgWzskcmbd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);
	if (appsrv == comp->appsrv) insert(items, APPSRV);
	if (ddspub == comp->ddspub) insert(items, DDSPUB);
	if (uasrv == comp->uasrv) insert(items, UASRV);

	return(items);
};

set<uint> StgWzskcmbd::diff(
			const StgWzskcmbd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPPRCN, APPSRV, DDSPUB, UASRV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskDatabase
 ******************************************************************************/

StgWzskDatabase::StgWzskDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) :
			Block()
		{
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgWzskDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgWzskDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskDatabase::comm(
			const StgWzskDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgWzskDatabase::diff(
			const StgWzskDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskDdspub
 ******************************************************************************/

StgWzskDdspub::StgWzskDdspub(
			const string& username
			, const string& password
		) :
			Block()
		{
	this->username = username;
	this->password = password;
	mask = {USERNAME, PASSWORD};
};

bool StgWzskDdspub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskDdspub");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskDdspub";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgWzskDdspub::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskDdspub";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskDdspub";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskDdspub::comm(
			const StgWzskDdspub* comp
		) {
	set<uint> items;

	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);

	return(items);
};

set<uint> StgWzskDdspub::diff(
			const StgWzskDdspub* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {USERNAME, PASSWORD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskFramegeo
 ******************************************************************************/

StgWzskFramegeo::StgWzskFramegeo(
			const uint wAcq
			, const uint hAcq
			, const uint whAcq
			, const uint x0Rgb
			, const uint wRgb
			, const uint y0Rgb
			, const uint hRgb
			, const uint x0Grrd
			, const uint wGrrd
			, const uint y0Grrd
			, const uint hGrrd
		) :
			Block()
		{
	this->wAcq = wAcq;
	this->hAcq = hAcq;
	this->whAcq = whAcq;
	this->x0Rgb = x0Rgb;
	this->wRgb = wRgb;
	this->y0Rgb = y0Rgb;
	this->hRgb = hRgb;
	this->x0Grrd = x0Grrd;
	this->wGrrd = wGrrd;
	this->y0Grrd = y0Grrd;
	this->hGrrd = hGrrd;
	mask = {WACQ, HACQ, WHACQ, X0RGB, WRGB, Y0RGB, HRGB, X0GRRD, WGRRD, Y0GRRD, HGRRD};
};

bool StgWzskFramegeo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskFramegeo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskFramegeo";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "wAcq", wAcq)) add(WACQ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "hAcq", hAcq)) add(HACQ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "whAcq", whAcq)) add(WHACQ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "x0Rgb", x0Rgb)) add(X0RGB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "wRgb", wRgb)) add(WRGB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "y0Rgb", y0Rgb)) add(Y0RGB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "hRgb", hRgb)) add(HRGB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "x0Grrd", x0Grrd)) add(X0GRRD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "wGrrd", wGrrd)) add(WGRRD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "y0Grrd", y0Grrd)) add(Y0GRRD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "hGrrd", hGrrd)) add(HGRRD);
	};

	return basefound;
};

void StgWzskFramegeo::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskFramegeo";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskFramegeo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "wAcq", wAcq);
		writeUintAttr(wr, itemtag, "sref", "hAcq", hAcq);
		writeUintAttr(wr, itemtag, "sref", "whAcq", whAcq);
		writeUintAttr(wr, itemtag, "sref", "x0Rgb", x0Rgb);
		writeUintAttr(wr, itemtag, "sref", "wRgb", wRgb);
		writeUintAttr(wr, itemtag, "sref", "y0Rgb", y0Rgb);
		writeUintAttr(wr, itemtag, "sref", "hRgb", hRgb);
		writeUintAttr(wr, itemtag, "sref", "x0Grrd", x0Grrd);
		writeUintAttr(wr, itemtag, "sref", "wGrrd", wGrrd);
		writeUintAttr(wr, itemtag, "sref", "y0Grrd", y0Grrd);
		writeUintAttr(wr, itemtag, "sref", "hGrrd", hGrrd);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskFramegeo::comm(
			const StgWzskFramegeo* comp
		) {
	set<uint> items;

	if (wAcq == comp->wAcq) insert(items, WACQ);
	if (hAcq == comp->hAcq) insert(items, HACQ);
	if (whAcq == comp->whAcq) insert(items, WHACQ);
	if (x0Rgb == comp->x0Rgb) insert(items, X0RGB);
	if (wRgb == comp->wRgb) insert(items, WRGB);
	if (y0Rgb == comp->y0Rgb) insert(items, Y0RGB);
	if (hRgb == comp->hRgb) insert(items, HRGB);
	if (x0Grrd == comp->x0Grrd) insert(items, X0GRRD);
	if (wGrrd == comp->wGrrd) insert(items, WGRRD);
	if (y0Grrd == comp->y0Grrd) insert(items, Y0GRRD);
	if (hGrrd == comp->hGrrd) insert(items, HGRRD);

	return(items);
};

set<uint> StgWzskFramegeo::diff(
			const StgWzskFramegeo* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {WACQ, HACQ, WHACQ, X0RGB, WRGB, Y0RGB, HRGB, X0GRRD, WGRRD, Y0GRRD, HGRRD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskGlobal
 ******************************************************************************/

StgWzskGlobal::StgWzskGlobal(
			const uint ixWzskVTarget
		) :
			Block()
		{
	this->ixWzskVTarget = ixWzskVTarget;
	mask = {IXWZSKVTARGET};
};

bool StgWzskGlobal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVTarget;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVTarget", srefIxWzskVTarget)) {
			ixWzskVTarget = VecWzskVTarget::getIx(srefIxWzskVTarget);
			add(IXWZSKVTARGET);
		};
	};

	return basefound;
};

void StgWzskGlobal::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskGlobal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVTarget", VecWzskVTarget::getSref(ixWzskVTarget));
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskGlobal::comm(
			const StgWzskGlobal* comp
		) {
	set<uint> items;

	if (ixWzskVTarget == comp->ixWzskVTarget) insert(items, IXWZSKVTARGET);

	return(items);
};

set<uint> StgWzskGlobal::diff(
			const StgWzskGlobal* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVTARGET};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskPath
 ******************************************************************************/

StgWzskPath::StgWzskPath(
			const string& acvpath
			, const string& keypath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) :
			Block()
		{
	this->acvpath = acvpath;
	this->keypath = keypath;
	this->monpath = monpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgWzskPath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskPath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskPath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "keypath", keypath)) add(KEYPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgWzskPath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskPath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskPath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "keypath", keypath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskPath::comm(
			const StgWzskPath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (keypath == comp->keypath) insert(items, KEYPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgWzskPath::diff(
			const StgWzskPath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzskUasrv
 ******************************************************************************/

StgWzskUasrv::StgWzskUasrv(
			const string& profile
			, const usmallint port
			, const usmallint cycle
			, const uint maxbrowse
			, const uint maxmon
		) :
			Block()
		{
	this->profile = profile;
	this->port = port;
	this->cycle = cycle;
	this->maxbrowse = maxbrowse;
	this->maxmon = maxmon;
	mask = {PROFILE, PORT, CYCLE, MAXBROWSE, MAXMON};
};

bool StgWzskUasrv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskUasrv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskUasrv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "profile", profile)) add(PROFILE);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "cycle", cycle)) add(CYCLE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "maxbrowse", maxbrowse)) add(MAXBROWSE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "maxmon", maxmon)) add(MAXMON);
	};

	return basefound;
};

void StgWzskUasrv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskUasrv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzskUasrv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "profile", profile);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeUsmallintAttr(wr, itemtag, "sref", "cycle", cycle);
		writeUintAttr(wr, itemtag, "sref", "maxbrowse", maxbrowse);
		writeUintAttr(wr, itemtag, "sref", "maxmon", maxmon);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskUasrv::comm(
			const StgWzskUasrv* comp
		) {
	set<uint> items;

	if (profile == comp->profile) insert(items, PROFILE);
	if (port == comp->port) insert(items, PORT);
	if (cycle == comp->cycle) insert(items, CYCLE);
	if (maxbrowse == comp->maxbrowse) insert(items, MAXBROWSE);
	if (maxmon == comp->maxmon) insert(items, MAXMON);

	return(items);
};

set<uint> StgWzskUasrv::diff(
			const StgWzskUasrv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PROFILE, PORT, CYCLE, MAXBROWSE, MAXMON};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 namespace AlrWzsk
 ******************************************************************************/

DpchEngWzskAlert* AlrWzsk::prepareAlrAbt(
			const ubigint jref
			, const uint ixWzskVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfWzskAlert continf;
	// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		continf.TxtMsg1 = "Whiznium StarterKit version v1.0.9 released on 14-11-2021";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "contributors: -";
		continf.TxtMsg6 = "libraries: ezdevwskd 0.1.26 and png 1.6.36";
		continf.TxtMsg8 = "Whiznium StarterKit is computer vision software which powers MPSI's tabletop 3D laser scanner that represents the primary on-boarding vehicle for Whiznium.";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		continf.TxtMsg1 = "Whiznium StarterKit Version v1.0.9 ver\\u00f6ffentlicht am 14-11-2021";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "Mitwirkende: -";
		continf.TxtMsg6 = "Programmbibliotheken: ezdevwskd 0.1.26 und png 1.6.36";
		continf.TxtMsg8 = "Whiznium StarterKit ist Computer-Vision Software, welche MPSI's kompakten 3D-Laserscanner (prim\\u00e4res Onboarding-Werkzeug f\\u00fcr Whiznium) ansteuert.";
	};

	feedFMcbAlert.clear();

	VecWzskVTag::appendToFeed(VecWzskVTag::CLOSE, ixWzskVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrAbt --- END
	return(new DpchEngWzskAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzskAlert::ALL}));
};

DpchEngWzskAlert* AlrWzsk::prepareAlrIer(
			const ubigint jref
			, const uint ixWzskVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfWzskAlert continf;
	// IP prepareAlrIer --- BEGIN
	continf.TxtCpt = VecWzskVTag::getTitle(VecWzskVTag::IMPERR, ixWzskVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecWzskVTag::appendToFeed(VecWzskVTag::CANCEL, ixWzskVLocale, feedFMcbAlert);
	VecWzskVTag::appendToFeed(VecWzskVTag::REVERSE, ixWzskVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrIer --- END
	return(new DpchEngWzskAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzskAlert::ALL}));
};

DpchEngWzskAlert* AlrWzsk::prepareAlrPer(
			const ubigint jref
			, const uint ixWzskVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfWzskAlert continf;
	// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecWzskVTag::getTitle(VecWzskVTag::PRSERR, ixWzskVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecWzskVTag::appendToFeed(VecWzskVTag::OK, ixWzskVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrPer --- END
	return(new DpchEngWzskAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzskAlert::ALL}));
};

DpchEngWzskAlert* AlrWzsk::prepareAlrSav(
			const ubigint jref
			, const uint ixWzskVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfWzskAlert continf;
	// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecWzskVTag::getTitle(VecWzskVTag::QUEST, ixWzskVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		continf.TxtMsg1 = "\\u00c4nderungen speichern?";
	};

	feedFMcbAlert.clear();

	VecWzskVTag::appendToFeed(VecWzskVTag::CANCEL, ixWzskVLocale, feedFMcbAlert);
	VecWzskVTag::appendToFeed(VecWzskVTag::FLS, ixWzskVLocale, feedFMcbAlert);
	VecWzskVTag::appendToFeed(VecWzskVTag::TRU, ixWzskVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrSav --- END
	return(new DpchEngWzskAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzskAlert::ALL}));
};

DpchEngWzskAlert* AlrWzsk::prepareAlrTrm(
			const ubigint jref
			, const uint ixWzskVLocale
			, const uint sesstterm
			, const uint sesstwarn
			, Feed& feedFMcbAlert
		) {
	ContInfWzskAlert continf;
	// IP prepareAlrTrm --- BEGIN
	continf.TxtCpt = VecWzskVTag::getTitle(VecWzskVTag::ANNOUNCE, ixWzskVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		continf.TxtMsg1 = "Your session has been inactive for " + prepareAlrTrm_dtToString(ixWzskVLocale, sesstterm) + ". It will be terminated in " + prepareAlrTrm_dtToString(ixWzskVLocale, sesstwarn) + ".";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		continf.TxtMsg1 = "Ihre Sitzung ist seit " + prepareAlrTrm_dtToString(ixWzskVLocale, sesstterm) + " inaktiv. Sie wird in " + prepareAlrTrm_dtToString(ixWzskVLocale, sesstwarn) + " beendet.";
	};

	feedFMcbAlert.clear();

	VecWzskVTag::appendToFeed(VecWzskVTag::OK, ixWzskVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrTrm --- END
	return(new DpchEngWzskAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzskAlert::ALL}));
};

string AlrWzsk::prepareAlrTrm_dtToString(
			const uint ixWzskVLocale
			, const time_t dt
		) {
	string s;

	if ((dt%3600) == 0) {
		s = to_string(dt/3600);

		if (dt == 3600) s += " " + VecWzskVTag::getTitle(VecWzskVTag::HOUR, ixWzskVLocale);
		else s += " " + VecWzskVTag::getTitle(VecWzskVTag::HOURS, ixWzskVLocale);

	} else if ((dt%60) == 0) {
		s = to_string(dt/60);

		if (dt == 60) s += " " + VecWzskVTag::getTitle(VecWzskVTag::MINUTE, ixWzskVLocale);
		else s += " " + VecWzskVTag::getTitle(VecWzskVTag::MINUTES, ixWzskVLocale);

	} else {
		s = to_string(dt);

		if (dt == 1) s += " " + VecWzskVTag::getTitle(VecWzskVTag::SECOND, ixWzskVLocale);
		else s += " " + VecWzskVTag::getTitle(VecWzskVTag::SECONDS, ixWzskVLocale);
	};

	return s;
};

/******************************************************************************
 class ReqWzsk
 ******************************************************************************/

ReqWzsk::ReqWzsk(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) :
			cReady("cReady", "ReqWzsk", "ReqWzsk")
		{
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	retain = !((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::DPCHAPP) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD) || (ixVBasetype == VecVBasetype::METHOD));

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jsonNotXml = false;

	jref = 0;

	wref = 0;

	call = NULL;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixWzskVLocale = VecWzskVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;

	method = NULL;
};

ReqWzsk::~ReqWzsk() {
	if (pp) MHD_destroy_post_processor(pp);

	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	if (call) delete call;

	if (request) delete[] request;

	if (dpchapp) delete dpchapp;

	if (dpcheng) delete dpcheng;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	if (method) delete method;
};

void ReqWzsk::setStateReply() {
	cReady.lockMutex("ReqWzsk", "setStateReply", "jref=" + to_string(jref));
	ixVState = VecVState::REPLY;
	cReady.unlockMutex("ReqWzsk", "setStateReply", "jref=" + to_string(jref));

	cReady.signal("ReqWzsk", "setStateReply", "jref=" + to_string(jref));
};

/******************************************************************************
 class DcolWzsk
 ******************************************************************************/

DcolWzsk::DcolWzsk(
			const ubigint jref
			, const uint ixWzskVLocale
		) :
			mAccess("dcol.mAccess", "DcolWzsk", "DcolWzsk", "jref=" + to_string(jref))
		{
	this->jref = jref;
	this->ixWzskVLocale = ixWzskVLocale;

	hot = false;

	req = NULL;
};

DcolWzsk::~DcolWzsk() {
	for (auto it = dpchs.begin(); it != dpchs.end(); it++) delete(*it);

	if (req) req->cReady.signal("DcolWzsk", "~DcolWzsk", "jref=" + to_string(jref));

	mAccess.lock("DcolWzsk", "~DcolWzsk", "jref=" + to_string(jref));
	mAccess.unlock("DcolWzsk", "~DcolWzsk", "jref=" + to_string(jref));
};

void DcolWzsk::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void DcolWzsk::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class JobWzsk
 ******************************************************************************/

JobWzsk::JobWzsk(
			XchgWzsk* xchg
			, const uint ixWzskVJob
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			mAccess("mAccess", VecWzskVJob::getSref(ixWzskVJob), VecWzskVJob::getSref(ixWzskVJob), "jrefSup=" + to_string(jrefSup))
			, mOps("mOps", VecWzskVJob::getSref(ixWzskVJob), VecWzskVJob::getSref(ixWzskVJob), "jrefSup=" + to_string(jrefSup))
		{
	this->xchg = xchg;

	jref = 0;

	this->ixWzskVJob = ixWzskVJob;

	this->ixWzskVLocale = ixWzskVLocale;

	muteRefresh = false;

	ixVSge = 1;
	nextIxVSgeSuccess = 1;
	nextIxVSgeFailure = 1;

	opN = 0;
	opNSuccess = 0;
	opNFailure = 0;

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobWzsk::~JobWzsk() {
	if (reqCmd) delete reqCmd;

	mAccess.lock(VecWzskVJob::getSref(ixWzskVJob), "~" + VecWzskVJob::getSref(ixWzskVJob), "jref=" + to_string(jref));
	mAccess.unlock(VecWzskVJob::getSref(ixWzskVJob), "~" + VecWzskVJob::getSref(ixWzskVJob), "jref=" + to_string(jref));
};

ubigint JobWzsk::insertSubjob(
			map<ubigint, JobWzsk*>& subjobs
			, JobWzsk* subjob
		) {
	subjobs[subjob->jref] = subjob;

	return subjob->jref;
};

bool JobWzsk::eraseSubjobByJref(
			map<ubigint, JobWzsk*>& subjobs
			, const ubigint _jref
		) {
	auto it = subjobs.find(_jref);

	if (it != subjobs.end()) {
		delete it->second;
		subjobs.erase(it);

		return true;
	};

	return false;
};

DpchEngWzsk* JobWzsk::getNewDpchEng(
			set<uint> items
		) {
	return new DpchEngWzskConfirm(true, jref, "");
};

void JobWzsk::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
};

void JobWzsk::refreshWithDpchEng(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
			, const bool unmute
		) {
	set<uint> moditems;

	DpchEngWzsk* _dpcheng = NULL;

	refresh(dbswzsk, moditems, unmute);
	if (muteRefresh) return;

	if (dpcheng) {
		_dpcheng = getNewDpchEng(moditems);

		if (*dpcheng) {
			if (_dpcheng->ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKCONFIRM) delete _dpcheng;
			else if (_dpcheng->ixWzskVDpch == (*dpcheng)->ixWzskVDpch) {
				(*dpcheng)->merge(_dpcheng);
				delete _dpcheng;

			} else xchg->submitDpch(_dpcheng);

		} else *dpcheng = _dpcheng;

	} else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
};

string JobWzsk::getSquawk(
			DbsWzsk* dbswzsk
		) {
	return "";
};

void JobWzsk::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
};

void JobWzsk::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
};

void JobWzsk::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

bool JobWzsk::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return mAccess.trylock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobWzsk::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobWzsk::lockAccess(
			const string& srefMember
		) {
	mAccess.lock(VecWzskVJob::getSref(ixWzskVJob), srefMember, "jref=" + to_string(jref));
};

bool JobWzsk::trylockAccess(
			const string& srefMember
		) {
	return mAccess.trylock(VecWzskVJob::getSref(ixWzskVJob), srefMember, "jref=" + to_string(jref));
};

void JobWzsk::unlockAccess(
			const string& srefMember
		) {
	mAccess.unlock(VecWzskVJob::getSref(ixWzskVJob), srefMember, "jref=" + to_string(jref));
};

void JobWzsk::setStage(
			DbsWzsk* dbswzsk
			, const uint _ixVSge
		) {
	xchg->setJobStage(dbswzsk, this, _ixVSge);
};

void JobWzsk::clearInvs() {
	for (unsigned int i = 0; i < invs.size(); i++) delete invs[i];
	invs.clear();
};

ubigint JobWzsk::addInv(
			DpchInvWzsk* inv
		) {
	inv->oref = xchg->orefseq.getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;

	return(inv->oref);
};

void JobWzsk::addInvs(
			vector<DpchInvWzsk*>& _invs
		) {
	for (unsigned int i = 0; i < _invs.size(); i++) addInv(_invs[i]);
};

void JobWzsk::submitInvs(
			DbsWzsk* dbswzsk
			, const uint nextIxVSgeEmpty
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = nextIxVSgeEmpty;

	} else {
		xchg->addInvs(dbswzsk, this, invs);
		invs.clear();
	};
};

void JobWzsk::clearOps() {
	mOps.lock(VecWzskVJob::getSref(ixWzskVJob), "clearOps", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) delete(*it);
	ops.clear();

	mOps.unlock(VecWzskVJob::getSref(ixWzskVJob), "clearOps", "jref=" + to_string(jref));
};

void JobWzsk::addOp(
			DbsWzsk* dbswzsk
			, DpchInvWzsk* inv
		) {
	string squawk;

	mOps.lock(VecWzskVJob::getSref(ixWzskVJob), "addOp", "jref=" + to_string(jref));

	// generate squawk

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixWzskVDpch, squawk));

	mOps.unlock(VecWzskVJob::getSref(ixWzskVJob), "addOp", "jref=" + to_string(jref));
};

void JobWzsk::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	mOps.lock(VecWzskVJob::getSref(ixWzskVJob), "removeOp", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	mOps.unlock(VecWzskVJob::getSref(ixWzskVJob), "removeOp", "jref=" + to_string(jref));
};

string JobWzsk::getOpsqkLast() {
	string retval;

	mOps.lock(VecWzskVJob::getSref(ixWzskVJob), "getOpsqkLast", "jref=" + to_string(jref));

	retval = opsqkLast;

	mOps.unlock(VecWzskVJob::getSref(ixWzskVJob), "getOpsqkLast", "jref=" + to_string(jref));

	return retval;
};

void JobWzsk::callback(
			const uint nextIxVSge
		) {
	nextIxVSgeSuccess = nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobWzsk::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class CsjobWzsk
 ******************************************************************************/

CsjobWzsk::CsjobWzsk(
			XchgWzsk* xchg
			, const uint ixWzskVJob
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, ixWzskVJob, jrefSup, ixWzskVLocale)
		{
	srvNotCli = false;
	srv = NULL;
};

bool CsjobWzsk::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Claim*>& claims
			, const ubigint jrefNewest
		) {
	return false;
};

/******************************************************************************
 class ShrdatWzsk
 ******************************************************************************/

ShrdatWzsk::ShrdatWzsk(
			const string& srefSupclass
			, const string& srefObject
		) :
			rwmAccess("shrdat.mAccess", srefSupclass + "::" + srefObject, srefObject)
		{
	this->srefSupclass = srefSupclass;
	this->srefObject = srefObject;
};

ShrdatWzsk::~ShrdatWzsk() {
};

void ShrdatWzsk::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
};

void ShrdatWzsk::term(
			XchgWzsk* xchg
		) {
};

void ShrdatWzsk::rlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.rlock(srefObject, srefMember, args);
};

void ShrdatWzsk::runlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.runlock(srefObject, srefMember, args);
};

void ShrdatWzsk::rlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.rlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWzsk::runlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.runlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWzsk::wlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wlock(srefObject, srefMember, args);
};

void ShrdatWzsk::wunlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wunlock(srefObject, srefMember, args);
};

void ShrdatWzsk::wlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWzsk::wunlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wunlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class StmgrWzsk
 ******************************************************************************/

StmgrWzsk::StmgrWzsk(
			XchgWzsk* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) :
			mAccess("stmgr.mAccess", "StmgrWzsk", "StmgrWzsk", "jref=" + to_string(jref))
		{
	this->xchg = xchg;

	this->jref = jref;
	this->ixVNonetype = ixVNonetype;

	stcch = new Stcch(true);
};

StmgrWzsk::~StmgrWzsk() {
	delete stcch;

	mAccess.lock("StmgrWzsk", "~StmgrWzsk", "jref=" + to_string(jref));
	mAccess.unlock("StmgrWzsk", "~StmgrWzsk", "jref=" + to_string(jref));
};

void StmgrWzsk::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	set<uint> icsWzskVStub;
	pair<multimap<stcchitemref_t,Stcchitem*>::iterator,multimap<stcchitemref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecWzskVCall::CALLWZSKFILUPD_REFEQ) {
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKFILSTD);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKOBJUPD_REFEQ) {
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKOBJSTD);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKOGRUPD_REFEQ) {
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKOGRSTD);
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKOGRHSREF);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKPRSUPD_REFEQ) {
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKPRSSTD);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSESUPD_REFEQ) {
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKSESMENU);
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKSESSTD);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKSHTUPD_REFEQ) {
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKSHTSTD);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKUSGUPD_REFEQ) {
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKUSGSTD);
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKGROUP);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKUSRUPD_REFEQ) {
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKUSRSTD);
		insert(icsWzskVStub, VecWzskVStub::STUBWZSKOWNER);
	};

	for (auto it = icsWzskVStub.begin(); it != icsWzskVStub.end(); it++) {
		rng = stcch->nodes.equal_range(stcchitemref_t(*it, call->argInv.ref, 0));
		for (auto it2 = rng.first; it2 != rng.second; it2++) if (refresh(dbswzsk, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTUBCHG, jref);
};

bool StmgrWzsk::refresh(
			DbsWzsk* dbswzsk
			, Stcchitem* stit
		) {
	set<stcchitemref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubWzsk::getStub(dbswzsk, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it = strefsSub_backup.begin(); it != strefsSub_backup.end(); it++) refresh(dbswzsk, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrWzsk::begin() {
	stcch->begin();
};

void StmgrWzsk::commit() {
	for (auto it = stcch->icsVStubNew.begin(); it != stcch->icsVStubNew.end(); it++) {
		if (*it == VecWzskVStub::STUBWZSKFILSTD) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKFILUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKGROUP) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKUSGUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKOBJSTD) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKOBJUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKOGRHSREF) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKOGRUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKOGRSTD) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKOGRUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKOWNER) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKUSRUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKPRSSTD) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKPRSUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKSESMENU) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKSESUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKSESSTD) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKSESUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKSHTSTD) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKSHTUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKUSGSTD) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKUSGUPD_REFEQ, jref);
		} else if (*it == VecWzskVStub::STUBWZSKUSRSTD) {
			xchg->addClstnStmgr(VecWzskVCall::CALLWZSKUSRUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

void StmgrWzsk::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void StmgrWzsk::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class WakeupWzsk
 ******************************************************************************/

WakeupWzsk::WakeupWzsk(
			XchgWzsk* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	this->xchg = xchg;
	this->wref = wref;
	this->jref = jref;
	this->sref = sref;
	this->deltat = deltat;
	this->weak = weak;
};

/******************************************************************************
 class ExtcallWzsk
 ******************************************************************************/

ExtcallWzsk::ExtcallWzsk(
			XchgWzsk* xchg
			, Call* call
		) {
	this->xchg = xchg;
	this->call = call;
};

// IP ShrdatJobprc.subs --- INSERT

/******************************************************************************
 class XchgWzskcmbd::ShrdatJobprc
 ******************************************************************************/

XchgWzskcmbd::ShrdatJobprc::ShrdatJobprc() :
			ShrdatWzsk("XchgWzsk", "ShrdatJobprc")
		{
};

void XchgWzskcmbd::ShrdatJobprc::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP ShrdatJobprc.init --- INSERT
};

void XchgWzskcmbd::ShrdatJobprc::term(
			XchgWzsk* xchg
		) {
	// IP ShrdatJobprc.term --- INSERT
};

// IP ShrdatOpprc.subs --- INSERT

/******************************************************************************
 class XchgWzskcmbd::ShrdatOpprc
 ******************************************************************************/

XchgWzskcmbd::ShrdatOpprc::ShrdatOpprc() :
			ShrdatWzsk("XchgWzsk", "ShrdatOpprc")
		{
};

void XchgWzskcmbd::ShrdatOpprc::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP ShrdatOpprc.init --- INSERT
};

void XchgWzskcmbd::ShrdatOpprc::term(
			XchgWzsk* xchg
		) {
	// IP ShrdatOpprc.term --- INSERT
};

/******************************************************************************
 class XchgWzskcmbd
 ******************************************************************************/

XchgWzskcmbd::XchgWzskcmbd() :
			cStable("cStable", "XchgWzskcmbd", "XchgWzskcmbd")
			, mLogfile("mLogfile", "XchgWzskcmbd", "XchgWzskcmbd")
			, cJobprcs("cJobprcs", "XchgWzskcmbd", "XchgWzskcmbd")
			, cOpprcs("cOpprcs", "XchgWzskcmbd", "XchgWzskcmbd")
#if defined(SBECORE_DDS)
			, cDdspub("cDdspub", "XchgWzskcmbd", "XchgWzskcmbd")
#endif
#if defined(SBECORE_UA)
			, cUasrv("cUasrv", "XchgWzskcmbd", "XchgWzskcmbd")
#endif
			, mReqs("mReqs", "XchgWzskcmbd", "XchgWzskcmbd")
			, orefseq("orefseq")
			, mInvs("mInvs", "XchgWzskcmbd", "XchgWzskcmbd")
			, rwmPresets("rwmPresets", "XchgWzskcmbd", "XchgWzskcmbd")
			, rwmStmgrs("rwmStmgrs", "XchgWzskcmbd", "XchgWzskcmbd")
			, rwmClstns("rwmClstns", "XchgWzskcmbd", "XchgWzskcmbd")
			, rwmDcols("rwmDcols", "XchgWzskcmbd", "XchgWzskcmbd")
			, jrefseq("jrefseq")
			, rwmJobs("rwmJobs", "XchgWzskcmbd", "XchgWzskcmbd")
			, rwmCsjobinfos("rwmCsjobinfos", "XchgWzskcmbd", "XchgWzskcmbd")
#if defined(SBECORE_DDS)
			, mDdspubcall("mDdspubcall", "XchgWzskcmbd", "XchgWzskcmbd")
#endif
#if defined(SBECORE_UA)
			, mUasrvcall("mUasrvcall", "XchgWzskcmbd", "XchgWzskcmbd")
#endif
			, wrefseq("wrefseq")
		{
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	// client-server job information
	csjobinfos[VecWzskVJob::JOBWZSKACQFPGAFLG] = new Csjobinfo(VecWzskVJob::JOBWZSKACQFPGAFLG);
	csjobinfos[VecWzskVJob::JOBWZSKACQFPGAPVW] = new Csjobinfo(VecWzskVJob::JOBWZSKACQFPGAPVW);
	csjobinfos[VecWzskVJob::JOBWZSKACQPREVIEW] = new Csjobinfo(VecWzskVJob::JOBWZSKACQPREVIEW);
	csjobinfos[VecWzskVJob::JOBWZSKACQPTCLOUD] = new Csjobinfo(VecWzskVJob::JOBWZSKACQPTCLOUD);
	csjobinfos[VecWzskVJob::JOBWZSKACTEXPOSURE] = new Csjobinfo(VecWzskVJob::JOBWZSKACTEXPOSURE);
	csjobinfos[VecWzskVJob::JOBWZSKACTLASER] = new Csjobinfo(VecWzskVJob::JOBWZSKACTLASER);
	csjobinfos[VecWzskVJob::JOBWZSKACTSERVO] = new Csjobinfo(VecWzskVJob::JOBWZSKACTSERVO);
	csjobinfos[VecWzskVJob::JOBWZSKIPRANGLE] = new Csjobinfo(VecWzskVJob::JOBWZSKIPRANGLE);
	csjobinfos[VecWzskVJob::JOBWZSKIPRCORNER] = new Csjobinfo(VecWzskVJob::JOBWZSKIPRCORNER);
	csjobinfos[VecWzskVJob::JOBWZSKIPRTRACE] = new Csjobinfo(VecWzskVJob::JOBWZSKIPRTRACE);
	csjobinfos[VecWzskVJob::JOBWZSKSRCARTY] = new Csjobinfo(VecWzskVJob::JOBWZSKSRCARTY);
	csjobinfos[VecWzskVJob::JOBWZSKSRCCLNXEVB] = new Csjobinfo(VecWzskVJob::JOBWZSKSRCCLNXEVB);
	csjobinfos[VecWzskVJob::JOBWZSKSRCICICLE] = new Csjobinfo(VecWzskVJob::JOBWZSKSRCICICLE);
	csjobinfos[VecWzskVJob::JOBWZSKSRCMCVEVP] = new Csjobinfo(VecWzskVJob::JOBWZSKSRCMCVEVP);
	csjobinfos[VecWzskVJob::JOBWZSKSRCSYSINFO] = new Csjobinfo(VecWzskVJob::JOBWZSKSRCSYSINFO);
	csjobinfos[VecWzskVJob::JOBWZSKSRCUVBDVK] = new Csjobinfo(VecWzskVJob::JOBWZSKSRCUVBDVK);
	csjobinfos[VecWzskVJob::JOBWZSKSRCV4L2] = new Csjobinfo(VecWzskVJob::JOBWZSKSRCV4L2);

#if defined(SBECORE_DDS)
	// DDS publisher call
	ddspubcall = NULL;
#endif

#if defined(SBECORE_UA)
	// OPC UA server call
	uasrvcall = NULL;
#endif
};

XchgWzskcmbd::~XchgWzskcmbd() {
	// empty out lists
	for (auto it = reqs.begin(); it != reqs.end(); it++) delete(*it);
	for (auto it = invs.begin(); it != invs.end(); it++) delete(*it);
	for (auto it = presets.begin(); it != presets.end(); it++) delete(it->second);
	for (auto it = stmgrs.begin(); it != stmgrs.end(); it++) delete(it->second);
	for (auto it = clstns.begin(); it != clstns.end(); it++) delete(it->second);
	for (auto it = dcols.begin(); it != dcols.end(); it++) delete(it->second);
	for (auto it = jobs.begin(); it != jobs.end(); it++) delete(it->second);
	for (auto it = jobinfos.begin(); it != jobinfos.end(); it++) delete(it->second);
	for (auto it = csjobinfos.begin(); it != csjobinfos.end(); it++) delete(it->second);
};

// IP cust --- INSERT

void XchgWzskcmbd::startMon() {
	JobWzsk* job = NULL;
	Jobinfo* jobinfo = NULL;

	DcolWzsk* dcol = NULL;
	bool Dcol;

	StmgrWzsk* stmgr = NULL;
	bool Stmgr;

	Clstn* clstn = NULL;
	Preset* preset = NULL;

	mon.start("Whiznium StarterKit v1.0.9", stgwzskpath.monpath);

	rwmJobs.rlock("XchgWzskcmbd", "startMon");
	for (auto it = jobs.begin(); it != jobs.end(); it++) {
		job = it->second;
		jobinfo = jobinfos[job->jref];

		dcol = getDcolByJref(job->jref, false);
		if (dcol) {
			Dcol = true;
			dcol->unlockAccess("XchgWzskcmbd", "startMon");
		} else Dcol = false;

		stmgr = getStmgrByJref(job->jref);
		if (stmgr) {
			Stmgr = true;
			stmgr->unlockAccess("XchgWzskcmbd", "startMon");
		} else Stmgr = false;

		if (getCsjobNotJob(job->ixWzskVJob)) mon.insertJob(jobinfo->jrefSup, VecWzskVJob::getSref(job->ixWzskVJob), job->jref, true, ((CsjobWzsk*) job)->srvNotCli, Dcol, Stmgr);
		else mon.insertJob(jobinfo->jrefSup, VecWzskVJob::getSref(job->ixWzskVJob), job->jref, false, false, Dcol, Stmgr);
	};
	rwmJobs.runlock("XchgWzskcmbd", "startMon");

	rwmClstns.rlock("XchgWzskcmbd", "startMon");
	for (auto it = clstns.begin(); it != clstns.end(); it++) {
		clstn = it->second;
		mon.insertClstn(clstn->cref.jref, Clstn::VecVTarget::getSref(clstn->cref.ixVTarget), VecWzskVCall::getSref(clstn->cref.ixVCall), Clstn::VecVJobmask::getSref(clstn->cref.ixVJobmask), clstn->cref.jrefTrig, clstn->cref.arg, clstn->cref.ixVSge, Clstn::VecVJactype::getSref(clstn->ixVJactype));
	};
	rwmClstns.runlock("XchgWzskcmbd", "startMon");

	rwmPresets.rlock("XchgWzskcmbd", "startMon");
	for (auto it = presets.begin(); it != presets.end(); it++) {
		preset = it->second;
		mon.insertPreset(preset->pref.jref, VecWzskVPreset::getSref(preset->pref.ixVPreset), preset->arg);
	};
	rwmPresets.runlock("XchgWzskcmbd", "startMon");

	triggerCall(NULL, VecWzskVCall::CALLWZSKMONSTATCHG, jrefRoot);
};

void XchgWzskcmbd::stopMon() {
	mon.stop();

	triggerCall(NULL, VecWzskVCall::CALLWZSKMONSTATCHG, jrefRoot);
};

void XchgWzskcmbd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	mLogfile.lock("XchgWzskcmbd", "appendToLogfile");

	time(&rawtime);

	logfile.open(exedir + "/log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	mLogfile.unlock("XchgWzskcmbd", "appendToLogfile");
};

void XchgWzskcmbd::addReq(
			ReqWzsk* req
		) {
	if (jrefRoot == 0) return;

	mReqs.lock("XchgWzskcmbd", "addReq", "jref=" + to_string(req->jref));

	req->ixVState = ReqWzsk::VecVState::WAITPRC;
	reqs.push_back(req);

	mReqs.unlock("XchgWzskcmbd", "addReq", "jref=" + to_string(req->jref));

	cJobprcs.signal("XchgWzskcmbd", "addReq", "jref=" + to_string(req->jref));
};

ReqWzsk* XchgWzskcmbd::pullFirstReq() {
	ReqWzsk* req;

	// get first element from list
	mReqs.lock("XchgWzskcmbd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqWzsk::VecVState::PRC;
		reqs.pop_front();
	};

	mReqs.unlock("XchgWzskcmbd", "pullFirstReq");

	return req;
};

void XchgWzskcmbd::addInvs(
			DbsWzsk* dbswzsk
			, JobWzsk* job
			, vector<DpchInvWzsk*>& dpchinvs
		) {
	// append to inv list and signal the news (note the double-lock)
	mInvs.lock("XchgWzskcmbd", "addInvs", "jref=" + to_string(job->jref));
	job->mOps.lock("XchgWzskcmbd", "addInvs", "jref=" + to_string(job->jref));

	for (unsigned int i = 0; i < dpchinvs.size(); i++) {
		job->addOp(dbswzsk, dpchinvs[i]);

		invs.push_back(dpchinvs[i]);

		mon.eventAddInv(job->jref, VecWzskVDpch::getSref(dpchinvs[i]->ixWzskVDpch), "", dpchinvs[i]->oref);
	};

	job->mOps.unlock("XchgWzskcmbd", "addInvs", "jref=" + to_string(job->jref));
	mInvs.unlock("XchgWzskcmbd", "addInvs", "jref=" + to_string(job->jref));

	cOpprcs.broadcast("XchgWzskcmbd", "addInvs", "jref=" + to_string(job->jref));
};

DpchInvWzsk* XchgWzskcmbd::pullFirstInv() {
	DpchInvWzsk* inv;

	// get first element from list
	mInvs.lock("XchgWzskcmbd", "pullFirstInv");

	inv = NULL;

	if (!invs.empty()) {
		inv = *(invs.begin());
		invs.pop_front();
	};

	mInvs.unlock("XchgWzskcmbd", "pullFirstInv");

	return inv;
};

Preset* XchgWzskcmbd::addPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	presetref_t pref(jref, ixWzskVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	preset = getPresetByPref(pref);

	rwmPresets.wlock("XchgWzskcmbd", "addPreset", "jref=" + to_string(jref));

	if (preset) {
		preset->arg = arg;

		mon.eventChangePreset(jref, VecWzskVPreset::getSref(ixWzskVPreset), arg);

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<presetref_t,Preset*>(pref, preset));

		mon.eventAddPreset(jref, VecWzskVPreset::getSref(ixWzskVPreset), arg);
	};

	rwmPresets.wunlock("XchgWzskcmbd", "addPreset", "jref=" + to_string(jref));

	return(preset);
};

Preset* XchgWzskcmbd::addIxPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixWzskVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgWzskcmbd::addRefPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixWzskVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgWzskcmbd::addRefsPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixWzskVPreset, jref, arg));
};

Preset* XchgWzskcmbd::addSrefPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixWzskVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgWzskcmbd::addIntvalPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixWzskVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgWzskcmbd::addDblvalPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixWzskVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgWzskcmbd::addBoolvalPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixWzskVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgWzskcmbd::addTxtvalPreset(
			const uint ixWzskVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixWzskVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgWzskcmbd::getPresetByPref(
			const presetref_t& pref
		) {
	Preset* preset = NULL;

	rwmPresets.rlock("XchgWzskcmbd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	rwmPresets.runlock("XchgWzskcmbd", "getPresetByPref");

	return preset;
};

Arg XchgWzskcmbd::getPreset(
			const uint ixWzskVPreset
			, ubigint jref
		) {
	Arg arg;

	Jobinfo* jobinfo = NULL;
	Preset* preset = NULL;

	if ( (ixWzskVPreset == VecWzskVPreset::PREWZSKSYSDATE) || (ixWzskVPreset == VecWzskVPreset::PREWZSKSYSTIME) || (ixWzskVPreset == VecWzskVPreset::PREWZSKSYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		if (ixWzskVPreset == VecWzskVPreset::PREWZSKSYSSTAMP) {
			arg.mask = Arg::REF;
			arg.ref = rawtime;

		} else {
			arg.mask = Arg::INTVAL;

			if (ixWzskVPreset == VecWzskVPreset::PREWZSKSYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
			else arg.intval = rawtime%(3600*24);
		};

	} else {
		rwmJobs.rlock("XchgWzskcmbd", "getPreset", "jref=" + to_string(jref));
		rwmPresets.rlock("XchgWzskcmbd", "getPreset", "jref=" + to_string(jref));

		jobinfo = getJobinfoByJref(jref);

		if (jobinfo && (ixWzskVPreset == VecWzskVPreset::PREWZSKIXLCL)) {
			arg.mask = Arg::IX;
			arg.ix = jobs[jref]->ixWzskVLocale;

		} else {
			while (jobinfo && !preset) {
				preset = getPresetByPref(presetref_t(jref, ixWzskVPreset));

				if (preset) arg = preset->arg;
				else {
					jref = jobinfo->jrefSup;
					jobinfo = getJobinfoByJref(jref);
				};
			};
		};

		rwmPresets.runlock("XchgWzskcmbd", "getPreset", "jref=" + to_string(jref));
		rwmJobs.runlock("XchgWzskcmbd", "getPreset", "jref=" + to_string(jref));
	};

	return(arg);
};

uint XchgWzskcmbd::getIxPreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzskVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgWzskcmbd::getRefPreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzskVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgWzskcmbd::getRefsPreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzskVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgWzskcmbd::getSrefPreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzskVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgWzskcmbd::getIntvalPreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzskVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgWzskcmbd::getDblvalPreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzskVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgWzskcmbd::getBoolvalPreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzskVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgWzskcmbd::getTxtvalPreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzskVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgWzskcmbd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsWzskVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsWzskVPreset.clear();
	args.clear();

	rwmPresets.rlock("XchgWzskcmbd", "getPresetsByJref", "jref=" + to_string(jref));

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		preset = it->second;

		icsWzskVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	rwmPresets.runlock("XchgWzskcmbd", "getPresetsByJref", "jref=" + to_string(jref));
};

void XchgWzskcmbd::removePreset(
			const uint ixWzskVPreset
			, const ubigint jref
		) {
	rwmPresets.wlock("XchgWzskcmbd", "removePreset", "jref=" + to_string(jref) + ",srefIxWzskVPreset=" + VecWzskVPreset::getSref(ixWzskVPreset));

	auto it = presets.find(presetref_t(jref, ixWzskVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);

		mon.eventRemovePreset(jref, VecWzskVPreset::getSref(ixWzskVPreset));
	};

	rwmPresets.wunlock("XchgWzskcmbd", "removePreset", "jref=" + to_string(jref) + ",srefIxWzskVPreset=" + VecWzskVPreset::getSref(ixWzskVPreset));
};

void XchgWzskcmbd::removePresetsByJref(
			const ubigint jref
		) {
	rwmPresets.wlock("XchgWzskcmbd", "removePresetsByJref", "jref=" + to_string(jref));

	uint ixVPreset;

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVPreset = it->second->pref.ixVPreset;
		delete it->second;

		mon.eventRemovePreset(jref, VecWzskVPreset::getSref(ixVPreset));
	};
	presets.erase(rng.first, rng.second);

	rwmPresets.wunlock("XchgWzskcmbd", "removePresetsByJref", "jref=" + to_string(jref));
};

StmgrWzsk* XchgWzskcmbd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrWzsk* stmgr = NULL;

	// create new stmgr and append to stmgr list
	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		rwmStmgrs.wlock("XchgWzskcmbd", "addStmgr", "jref=" + to_string(jref));

		stmgr = new StmgrWzsk(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;

		rwmStmgrs.wunlock("XchgWzskcmbd", "addStmgr", "jref=" + to_string(jref));

		mon.eventAddStmgr(jref);
	};

	return(stmgr);
};

StmgrWzsk* XchgWzskcmbd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrWzsk* stmgr = NULL;

	rwmStmgrs.rlock("XchgWzskcmbd", "getStmgrByJref", "jref=" + to_string(jref));

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgWzskcmbd", "getStmgrByJref");
	};

	rwmStmgrs.runlock("XchgWzskcmbd", "getStmgrByJref", "jref=" + to_string(jref));

	return(stmgr);
};

void XchgWzskcmbd::removeStmgrByJref(
			const ubigint jref
		) {
	rwmStmgrs.wlock("XchgWzskcmbd", "removeStmgrByJref", "jref=" + to_string(jref));

	removeClstnsByJref(jref, Clstn::VecVTarget::STMGR);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);

		mon.eventRemoveStmgr(jref);
	};

	rwmStmgrs.wunlock("XchgWzskcmbd", "removeStmgrByJref", "jref=" + to_string(jref));
};

Clstn* XchgWzskcmbd::addClstn(
			const uint ixWzskVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const Arg& arg
			, const uint ixVSge
			, const uint ixVJactype
		) {
	clstnref_t cref(ixWzskVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, arg, ixVSge);
	clstnref2_t cref2(cref);

	multimap<clstnref_t,Clstn*>::iterator it;
	Clstn* clstn = NULL;

	rwmClstns.wlock("XchgWzskcmbd", "addClstn", "jref=" + to_string(jref) + ",srefIxWzskVCall=" + VecWzskVCall::getSref(ixWzskVCall));

	if (!chgarg) it = clstns.end();
	else {
		Arg argFind = arg;
		argFind.clearContent();

		clstnref_t crefFind(ixWzskVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, argFind, ixVSge);

		it = clstns.find(crefFind);
	};

	if (it == clstns.end()) {
		// create new clstn and append to clstn list
		clstn = new Clstn(cref, ixVJactype);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, "job", VecWzskVCall::getSref(ixWzskVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));

	} else {
		// change clstn argument
		clstn = it->second;
		clstn->cref = cref;

		cref2sClstns.erase(clstnref2_t(it->first));
		clstns.erase(it->first);

		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));
		
		mon.eventChangeClstnArg(jref, "job", VecWzskVCall::getSref(ixWzskVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));
	};

	rwmClstns.wunlock("XchgWzskcmbd", "addClstn", "jref=" + to_string(jref) + ",srefIxWzskVCall=" + VecWzskVCall::getSref(ixWzskVCall));

	return(clstn);
};

Clstn* XchgWzskcmbd::addIxClstn(
			const uint ixWzskVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixWzskVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWzskcmbd::addRefClstn(
			const uint ixWzskVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixWzskVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWzskcmbd::addIxRefClstn(
			const uint ixWzskVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixWzskVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
		};

Clstn* XchgWzskcmbd::addIxRefSrefClstn(
			const uint ixWzskVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const string& sref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, sref, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixWzskVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWzskcmbd::addClstnStmgr(
			const uint ixWzskVCall
			, const ubigint jref
		) {
	clstnref_t cref(ixWzskVCall, jref, Clstn::VecVTarget::STMGR, Clstn::VecVJobmask::ALL);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	clstn = getClstnByCref(cref);

	if (!clstn) {
		rwmClstns.wlock("XchgWzskcmbd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxWzskVCall=" + VecWzskVCall::getSref(ixWzskVCall));

		clstn = new Clstn(cref, Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		rwmClstns.wunlock("XchgWzskcmbd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxWzskVCall=" + VecWzskVCall::getSref(ixWzskVCall));

		mon.eventAddClstn(jref, "stmgr", VecWzskVCall::getSref(ixWzskVCall), Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::ALL), 0, Arg(), 0, Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	return(clstn);
};

#if defined(SBECORE_DDS)
Clstn* XchgWzskcmbd::addClstnDdspub(
			const ubigint jrefTrig
			, const string& sref
			, const bool shrdatNotDat
		) {
	uint ixWzskVCall = ((shrdatNotDat) ? VecWzskVCall::CALLWZSKSHRDATCHG : VecWzskVCall::CALLWZSKDATCHG);

	clstnref_t cref(ixWzskVCall, 1, Clstn::VecVTarget::DDSPUB, Clstn::VecVJobmask::SPEC, jrefTrig, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF));
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	clstn = getClstnByCref(cref);

	if (!clstn) {
		rwmClstns.wlock("XchgWzskcmbd", "addClstnDdspub", "jrefTrig=" + to_string(jrefTrig));

		clstn = new Clstn(cref, Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		rwmClstns.wunlock("XchgWzskcmbd", "addClstnDdspub", "jrefTrig=" + to_string(jrefTrig));

		mon.eventAddClstn(0, "CallWzskShrdatChg", "ddspub", Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::SPEC), jrefTrig, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF), 0, Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	return(clstn);
};
#endif

#if defined(SBECORE_UA)
Clstn* XchgWzskcmbd::addClstnUasrv(
			const ubigint jrefTrig
			, const string& sref
			, const bool shrdatNotDat
		) {
	uint ixWzskVCall = ((shrdatNotDat) ? VecWzskVCall::CALLWZSKSHRDATCHG : VecWzskVCall::CALLWZSKDATCHG);

	clstnref_t cref(ixWzskVCall, 1, Clstn::VecVTarget::UASRV, Clstn::VecVJobmask::SPEC, jrefTrig, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF));
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	clstn = getClstnByCref(cref);

	if (!clstn) {
		rwmClstns.wlock("XchgWzskcmbd", "addClstnUasrv", "jrefTrig=" + to_string(jrefTrig));

		clstn = new Clstn(cref, Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		rwmClstns.wunlock("XchgWzskcmbd", "addClstnUasrv", "jrefTrig=" + to_string(jrefTrig));

		mon.eventAddClstn(0, "uasrv", "CallWzskShrdatChg", Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::SPEC), jrefTrig, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF), 0, Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	return(clstn);
};
#endif

Clstn* XchgWzskcmbd::getClstnByCref(
			const clstnref_t& cref
		) {
	Clstn* clstn = NULL;

	rwmClstns.rlock("XchgWzskcmbd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	rwmClstns.runlock("XchgWzskcmbd", "getClstnByCref");

	return clstn;
};

void XchgWzskcmbd::getClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
			, vector<uint>& icsWzskVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsWzskVCall.clear();
	icsVJobmask.clear();

	rwmClstns.rlock("XchgWzskcmbd", "getClstnsByJref", "jref=" + to_string(jref));

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsWzskVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	rwmClstns.runlock("XchgWzskcmbd", "getClstnsByJref", "jref=" + to_string(jref));
};

void XchgWzskcmbd::removeClstns(
			const uint ixWzskVCall
			, const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgWzskcmbd", "removeClstns", "jref=" + to_string(jref));

	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = clstns.equal_range(clstnref_t(ixWzskVCall, jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVJobmask = it->second->cref.ixVJobmask;
		jrefTrig = it->second->cref.jrefTrig;
		arg = it->second->cref.arg;
		ixVSge = it->second->cref.ixVSge;
		ixVJactype = it->second->ixVJactype;

		cref2sClstns.erase(clstnref2_t(it->first));
		delete it->second;

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecWzskVCall::getSref(ixWzskVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	clstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgWzskcmbd", "removeClstns", "jref=" + to_string(jref));
};

void XchgWzskcmbd::removeClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgWzskcmbd", "removeClstnsByJref", "jref=" + to_string(jref));

	uint ixVCall;
	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		auto it2 = clstns.find(it->second);

		ixVCall = it2->second->cref.ixVCall;
		ixVJobmask = it2->second->cref.ixVJobmask;
		jrefTrig = it2->second->cref.jrefTrig;
		arg = it2->second->cref.arg;
		ixVSge = it2->second->cref.ixVSge;
		ixVJactype = it2->second->ixVJactype;

		delete it2->second;
		clstns.erase(it2);

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecWzskVCall::getSref(ixVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	cref2sClstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgWzskcmbd", "removeClstnsByJref", "jref=" + to_string(jref));
};

void XchgWzskcmbd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefTrigs
			, vector<ubigint>& jrefs
			, vector<uint>& icsVTarget
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	set<ubigint> jrefsClissrv;

	ubigint jrefTrig;
	bool match;

	rwmJobs.rlock("XchgWzskcmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmClstns.rlock("XchgWzskcmbd", "findJrefsByCall", "jref=" + to_string(call->jref));

	jrefsClissrv = getCsjobClisByJref(call->jref);
	jrefsClissrv.insert(call->jref);

	auto rng = clstns.equal_range(clstnref_t(call->ixVCall, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = it->second;

		jrefTrig = call->jref;

		if (clstn->cref.ixVTarget == Clstn::VecVTarget::JOB) {
			match = true;

			if (clstn->cref.arg.mask & Arg::IX) if (clstn->cref.arg.ix != call->argInv.ix) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::REF) if (clstn->cref.arg.ref != call->argInv.ref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::INTVAL) if (clstn->cref.arg.intval != call->argInv.intval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::DBLVAL) if (clstn->cref.arg.dblval != call->argInv.dblval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::BOOLVAL) if (clstn->cref.arg.boolval != call->argInv.boolval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::TXTVAL) if (clstn->cref.arg.txtval != call->argInv.txtval) match = false;

			if (match) if (clstn->cref.ixVSge != 0) if (clstn->cref.ixVSge != jobinfos[clstn->cref.jref]->ixVSge) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about jrefsClissrv
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// check if trigger job is immediate sub-job to listener job
						if (clstn->cref.jref == jobinfos[*it]->jrefSup) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SELF) {
					// check if trigger job is equivalent to listener job
					if (clstn->cref.jref == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// require specific jref
						if (clstn->cref.jrefTrig == (*it)) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					if (clstn->cref.jref == call->jref) match = true;
					else {
						for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
							// check if trigger job is down the tree from listener job
							if (getJobSup(clstn->cref.jref, *it)) {
								jrefTrig = *it;
								match = true;
								break;
							};
						};
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(clstn->ixVJactype);
			};

		} else if (clstn->cref.ixVTarget == Clstn::VecVTarget::STMGR) {
			jrefTrigs.push_back(jrefTrig);
			jrefs.push_back(clstn->cref.jref);
			icsVTarget.push_back(clstn->cref.ixVTarget);
			icsVJactype.push_back(0);

		} else {
			// targets DDSPUB and UASRV
			match = true;

			if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;

			if (match) if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
				match = false;

				for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
					// require specific jref
					if (clstn->cref.jrefTrig == (*it)) {
						jrefTrig = *it;
						match = true;
						break;
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(0);
			};
		};
	};

	rwmClstns.runlock("XchgWzskcmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmJobs.runlock("XchgWzskcmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
};

void XchgWzskcmbd::triggerCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	vector<ubigint> jrefTrigs;
	vector<ubigint> jrefs;
	vector<uint> icsVTarget;
	vector<uint> icsVJactype;

	uint ixVTarget;
	ubigint jref;
	uint ixVJactype;

	JobWzsk* job = NULL;

	StmgrWzsk* stmgr = NULL;

	ubigint eref;

	Arg argRet_old;

	eref = mon.eventTriggerCall(call->jref, VecWzskVCall::getSref(call->ixVCall), call->argInv);

	findJrefsByCall(call, jrefTrigs, jrefs, icsVTarget, icsVJactype);

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		call->jref = jrefTrigs[i];
		jref = jrefs[i];
		ixVTarget = icsVTarget[i];
		ixVJactype = icsVJactype[i];

		if (ixVTarget == Clstn::VecVTarget::JOB) {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgWzskcmbd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (!job->trylockAccess("XchgWzskcmbd", "triggerCall")) continue;
					};
				};

				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				job->handleCall(dbswzsk, call);

				if (call->argRet != argRet_old) mon.eventRetCall(eref, jref, call->argRet);
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgWzskcmbd", "triggerCall");
			};

		} else if (ixVTarget == Clstn::VecVTarget::STMGR) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				stmgr->handleCall(dbswzsk, call);

				if (!(call->argRet == argRet_old)) mon.eventRetCall(eref, jref, call->argRet);

				stmgr->unlockAccess("XchgWzskcmbd", "triggerCall");
			};

#if defined(SBECORE_DDS)
		} else if (ixVTarget == Clstn::VecVTarget::DDSPUB) {
			if (mDdspubcall.trylock("XchgWzskcmbd", "triggerCall", "jref=" + to_string(call->jref))) {
				cDdspub.lockMutex("XchgWzskcmbd", "triggerCall[1]", "jref=" + to_string(call->jref));
				ddspubcall = call;
				cDdspub.unlockMutex("XchgWzskcmbd", "triggerCall[1]", "jref=" + to_string(call->jref));

				mon.eventHandleCall(eref, jref);
				cDdspub.signal("XchgWzskcmbd", "triggerCall", "jref=" + to_string(call->jref));

				cDdspub.lockMutex("XchgWzskcmbd", "triggerCall[2]", "jref=" + to_string(call->jref));
				if (ddspubcall) cDdspub.wait("XchgWzskcmbd", "triggerCall", "jref=" + to_string(call->jref));
				cDdspub.unlockMutex("XchgWzskcmbd", "triggerCall[2]", "jref=" + to_string(call->jref));

				mDdspubcall.unlock("XchgWzskcmbd", "triggerCall", "jref=" + to_string(call->jref));
			};
#endif

#if defined(SBECORE_UA)
		} else if (ixVTarget == Clstn::VecVTarget::UASRV) {
			if (mUasrvcall.trylock("XchgWzskcmbd", "triggerCall", "jref=" + to_string(call->jref))) {
				cUasrv.lockMutex("XchgWzskcmbd", "triggerCall[1]", "jref=" + to_string(call->jref));
				uasrvcall = call;
				cUasrv.unlockMutex("XchgWzskcmbd", "triggerCall[1]", "jref=" + to_string(call->jref));

				mon.eventHandleCall(eref, jref);
			
				cUasrv.lockMutex("XchgWzskcmbd", "triggerCall[2]", "jref=" + to_string(call->jref));
				if (uasrvcall) cUasrv.wait("XchgWzskcmbd", "triggerCall", "jref=" + to_string(call->jref));
				cUasrv.unlockMutex("XchgWzskcmbd", "triggerCall[2]", "jref=" + to_string(call->jref));

				mUasrvcall.unlock("XchgWzskcmbd", "triggerCall", "jref=" + to_string(call->jref));
			};
#endif
		};

		if (call->abort) break;
	};

	mon.eventFinalizeCall(eref);
};

bool XchgWzskcmbd::triggerArgToArgCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

	call = new Call(ixWzskVCall, jref, argInv);
	triggerCall(dbswzsk, call);

	argRet = call->argRet;
	retval = call->abort;

	delete call;
	return retval;
};

bool XchgWzskcmbd::triggerCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerIxCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerRefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerIntvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerBoolvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerIxRefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerIxSrefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerIxSrefToIxCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;
	
	return retval;
};

bool XchgWzskcmbd::triggerIxIntvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerIxDblvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerIxTxtvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const string& txtvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, txtvalInv, Arg::IX + Arg::TXTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerSrefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const string& srefInv
		) {
	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet));
};

bool XchgWzskcmbd::triggerToBoolvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWzskcmbd::triggerIxToBoolvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWzskcmbd::triggerRefToSrefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) srefRet = argRet.sref;

	return(retval);
};

bool XchgWzskcmbd::triggerRefToBoolvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWzskcmbd::triggerIxRefToIxCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgWzskcmbd::triggerIxRefToRefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgWzskcmbd::triggerIxRefSrefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgWzskcmbd::triggerIxRefSrefIntvalCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgWzskcmbd::triggerIxRefSrefIntvalToRefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgWzskcmbd::triggerRefToIxCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgWzskcmbd::triggerSrefToRefCall(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCall
			, const ubigint jref
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzsk, ixWzskVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

DcolWzsk* XchgWzskcmbd::addDcol(
			const ubigint jref
		) {
	JobWzsk* job = NULL;

	DcolWzsk* dcol = NULL;

	// create new dcol and append to dcol list
	rwmJobs.rlock("XchgWzskcmbd", "addDcol", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			rwmDcols.wlock("XchgWzskcmbd", "addDcol", "jref=" + to_string(jref));

			dcol = new DcolWzsk(jref, job->ixWzskVLocale);
			dcols[jref] = dcol;

			dcol->lockAccess("XchgWzskcmbd", "addDcol");

			rwmDcols.wunlock("XchgWzskcmbd", "addDcol", "jref=" + to_string(jref));

			mon.eventAddDcol(jref);
		};
	};

	rwmJobs.runlock("XchgWzskcmbd", "addDcol", "jref=" + to_string(jref));

	// make dcol the session's active notify dcol
	triggerIxRefCall(NULL, VecWzskVCall::CALLWZSKREFPRESET, jref, VecWzskVPreset::PREWZSKJREFNOTIFY, jref);

	return(dcol);
};

DcolWzsk* XchgWzskcmbd::getDcolByJref(
			ubigint jref
			, const bool tree
		) {
	Jobinfo* jobinfo = NULL;

	DcolWzsk* dcol = NULL;

	rwmJobs.rlock("XchgWzskcmbd", "getDcolByJref", "jref=" + to_string(jref));
	rwmDcols.rlock("XchgWzskcmbd", "getDcolByJref", "jref=" + to_string(jref));

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo != NULL) {
		auto it = dcols.find(jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgWzskcmbd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	rwmDcols.runlock("XchgWzskcmbd", "getDcolByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgWzskcmbd", "getDcolByJref", "jref=" + to_string(jref));

	return(dcol);
};

void XchgWzskcmbd::removeDcolByJref(
			const ubigint jref
		) {
	rwmDcols.wlock("XchgWzskcmbd", "removeDcolByJref", "jref=" + to_string(jref));

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);

		mon.eventRemoveDcol(jref);
	};

	rwmDcols.wunlock("XchgWzskcmbd", "removeDcolByJref", "jref=" + to_string(jref));
};

void XchgWzskcmbd::removeDcolsByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	vector<ubigint> jrefs;

	rwmJobs.rlock("XchgWzskcmbd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmDcols.wlock("XchgWzskcmbd", "removeDcolsByJref", "jref=" + to_string(jref));

	jrefs.push_back(jref);

	// sub-tree without recursion
	for (unsigned int i = 0; i < jrefs.size(); i++) {
		jobinfo = getJobinfoByJref(jrefs[i]);

		if (jobinfo) for (auto it = jobinfo->jrefsSub.begin(); it != jobinfo->jrefsSub.end(); it++) jrefs.push_back(*it);
	};

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		auto it = dcols.find(jrefs[i]);
		if (it != dcols.end()) {
			delete it->second;
			dcols.erase(it);

			mon.eventRemoveDcol(jrefs[i]);
		};
	};

	rwmDcols.wunlock("XchgWzskcmbd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgWzskcmbd", "removeDcolsByJref", "jref=" + to_string(jref));
};

void XchgWzskcmbd::submitDpch(
			DpchEngWzsk* dpcheng
		) {
	DcolWzsk* dcol = NULL;

	Cond* cReady_backup;

	DpchEngWzsk* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		mon.eventSubmitDpch(dpcheng->jref, VecWzskVDpch::getSref(dpcheng->ixWzskVDpch), dpcheng->getSrefsMask(), "");

		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);

			dcol->req = NULL;
			//cout << "XchgWzskcmbd::submitDpch() waiting request for ixWzskVDpch = " << dpcheng->ixWzskVDpch << ", jref = " << dpcheng->jref << endl;

			cReady_backup->signal("XchgWzskcmbd", "submitDpch", "jref=" + to_string(dcol->jref));

			dcol->unlockAccess("XchgWzskcmbd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it = dcol->dpchs.begin(); it != dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixWzskVDpch == dpcheng->ixWzskVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgWzskcmbd::submitDpch() merge for ixWzskVDpch = " << dpcheng->ixWzskVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgWzskcmbd::submitDpch() append for ixWzskVDpch = " << dpcheng->ixWzskVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgWzskcmbd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngWzsk* XchgWzskcmbd::pullFirstDpch(
			DcolWzsk* dcol
		) {
	DpchEngWzsk* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgWzskcmbd::addJob(
			DbsWzsk* dbswzsk
			, JobWzsk* job
			, const ubigint jrefSup
		) {
	CsjobWzsk* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob = getCsjobNotJob(job->ixWzskVJob);
	bool srvNotCli = false;

	// get new jref and append to job list
	rwmJobs.wlock("XchgWzskcmbd", "addJob", "jrefSup=" + to_string(jrefSup));

	job->jref = jrefseq.getNewRef();
	jobs[job->jref] = job;

	if (jobs.size() == 1) {
		// root job
		jrefRoot = job->jref;
		jrefCmd = job->jref;
	};

	ixWzskVJobs[job->jref] = job->ixWzskVJob;
	jobinfos[job->jref] = new Jobinfo(jrefSup);

	if (jrefSup != 0) jobinfos[jrefSup]->jrefsSub.insert(job->jref);

	if (csjobNotJob) {
		rwmCsjobinfos.wlock("XchgWzskcmbd", "addJob", "jref=" + to_string(job->jref));

		csjob = (CsjobWzsk*) job;
		csjobinfo = csjobinfos[job->ixWzskVJob];

		if (jrefSup == jrefRoot) {
			csjob->srvNotCli = true;
			srvNotCli = true;
			
			csjobinfo->jrefSrv = job->jref;
			for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) {
				jobs[*it]->ixVSge = job->ixVSge;
				((CsjobWzsk*) (jobs[*it]))->srv = csjob;
			};

		} else {
			csjob->srvNotCli = false;
			
			if (csjobinfo->jrefSrv != 0) {
				job->ixVSge = jobs[csjobinfo->jrefSrv]->ixVSge;
				csjob->srv = (CsjobWzsk*) jobs[csjobinfo->jrefSrv];
			};
			csjobinfo->jrefsCli.insert(job->jref);
		};

		rwmCsjobinfos.wunlock("XchgWzskcmbd", "addJob", "jref=" + to_string(job->jref));
	};

	rwmJobs.wunlock("XchgWzskcmbd", "addJob", "jref=" + to_string(job->jref));

	mon.eventAddJob(jrefSup, VecWzskVJob::getSref(job->ixWzskVJob), job->jref, csjobNotJob, srvNotCli);

	return(job->jref);
};

JobWzsk* XchgWzskcmbd::getJobByJref(
			const ubigint jref
		) {
	JobWzsk* job = NULL;

	rwmJobs.rlock("XchgWzskcmbd", "getJobByJref", "jref=" + to_string(jref));

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	rwmJobs.runlock("XchgWzskcmbd", "getJobByJref", "jref=" + to_string(jref));

	return job;
};

Jobinfo* XchgWzskcmbd::getJobinfoByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	rwmJobs.rlock("XchgWzskcmbd", "getJobinfoByJref", "jref=" + to_string(jref));

	auto it = jobinfos.find(jref);
	if (it != jobinfos.end()) jobinfo = it->second;

	rwmJobs.runlock("XchgWzskcmbd", "getJobinfoByJref", "jref=" + to_string(jref));

	return jobinfo;
};

void XchgWzskcmbd::removeJobByJref(
			const ubigint jref
		) {
	JobWzsk* job = NULL;
	Jobinfo* jobinfo = NULL;

	CsjobWzsk* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob;

	rwmJobs.rlock("XchgWzskcmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
 		csjobNotJob = getCsjobNotJob(job->ixWzskVJob);

		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		if (csjobNotJob) {
			rwmCsjobinfos.rlock("XchgWzskcmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

			csjob = (CsjobWzsk*) job;
			csjobinfo = csjobinfos[job->ixWzskVJob];

			removeCsjobClaim(NULL, csjob);

			rwmCsjobinfos.runlock("XchgWzskcmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

			rwmCsjobinfos.wlock("XchgWzskcmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

			if (csjob->srvNotCli) {
				csjobinfo->jrefSrv = 0;
				for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) ((CsjobWzsk*) (jobs[*it]))->srv = NULL;

			} else csjobinfo->jrefsCli.erase(jref);

			rwmCsjobinfos.wunlock("XchgWzskcmbd", "removeJobByJref[2]", "jref=" + to_string(jref));
		};

		jobinfo = jobinfos[jref];

		rwmJobs.runlock("XchgWzskcmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

		rwmJobs.wlock("XchgWzskcmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

		if (jobinfo->jrefSup != 0) jobinfos[jobinfo->jrefSup]->jrefsSub.erase(jref);

		rwmJobs.wunlock("XchgWzskcmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

		while (jobinfo->jrefsSub.size() > 0) delete jobs[*(jobinfo->jrefsSub.begin())];

		rwmJobs.wlock("XchgWzskcmbd", "removeJobByJref[3]", "jref=" + to_string(jref));

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		delete jobinfo;
		jobinfos.erase(jref);

		ixWzskVJobs.erase(jref);

		if (jobs.empty()) {
			// root job
			jrefRoot = 0;
			jrefCmd = 0;
		};

		rwmJobs.wunlock("XchgWzskcmbd", "removeJobByJref[3]", "jref=" + to_string(jref));

		mon.eventRemoveJob(jref);

	} else rwmJobs.wunlock("XchgWzskcmbd", "removeJobByJref[4]", "jref=" + to_string(jref));
};

bool XchgWzskcmbd::getJobSup(
			const ubigint jrefSup
			, ubigint jref
		) {
	bool retval = false;

	Jobinfo* jobinfo = NULL;

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo) {
		if (jobinfo->jrefSup == jrefSup) {
			retval = true;
			break;
		};

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	return retval;
};

void XchgWzskcmbd::setJobStage(
			DbsWzsk* dbswzsk
			, JobWzsk* job
			, const uint ixVSge
		) {
	set<ubigint> jrefsCli;

	bool csjobNotJob = getCsjobNotJob(job->ixWzskVJob);

	rwmJobs.rlock("XchgWzskcmbd", "setJobStage", "jref=" + to_string(job->jref));
	if (csjobNotJob) rwmCsjobinfos.rlock("XchgWzskcmbd", "setJobStage", "jref=" + to_string(job->jref));

	jobinfos[job->jref]->ixVSge = ixVSge;
	job->ixVSge = ixVSge;
	
	if (csjobNotJob) {
		jrefsCli = getCsjobClisByJref(job->jref);
		
		for (auto it = jrefsCli.begin(); it != jrefsCli.end(); it++) {
			jobinfos[*it]->ixVSge = ixVSge;
			jobs[*it]->ixVSge = ixVSge;
		};
	};

	if (csjobNotJob) rwmCsjobinfos.runlock("XchgWzskcmbd", "setJobStage", "jref=" + to_string(job->jref));
	rwmJobs.runlock("XchgWzskcmbd", "setJobStage", "jref=" + to_string(job->jref));

	triggerIxCall(dbswzsk, VecWzskVCall::CALLWZSKSGECHG, job->jref, ixVSge);
};

void XchgWzskcmbd::addCsjobClaim(
			DbsWzsk* dbswzsk
			, CsjobWzsk* csjob
			, Claim* claim
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWzskcmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWzskVJob];

		rwmCsjobinfos.runlock("XchgWzskcmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgWzskcmbd", "addCsjobClaim");

		csjobinfo->mClaims.wlock("XchgWzskcmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) delete it->second;

		csjobinfo->claims[csjob->jref] = claim;

		mod = csjob->srv->handleClaim(dbswzsk, csjobinfo->claims, csjob->jref);

		csjobinfo->mClaims.wunlock("XchgWzskcmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgWzskcmbd", "addCsjobClaim");

		if (mod) triggerCall(dbswzsk, VecWzskVCall::CALLWZSKCLAIMCHG, csjob->jref);
	};
};

bool XchgWzskcmbd::getCsjobClaim(
			CsjobWzsk* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
			, bool& run
		) {
	bool retval = false;

	Csjobinfo* csjobinfo = NULL;;

	takenNotAvailable = false;
	fulfilled = false;
	run = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWzskcmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWzskVJob];

		csjobinfo->mClaims.rlock("XchgWzskcmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		retval = (it != csjobinfo->claims.end());

		if (retval) {
			takenNotAvailable = it->second->takenNotAvailable;
			fulfilled = it->second->fulfilled;
			run = it->second->run;
		};

		csjobinfo->mClaims.runlock("XchgWzskcmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		rwmCsjobinfos.runlock("XchgWzskcmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));
	};

	return retval;
};

bool XchgWzskcmbd::getCsjobClaim(
			CsjobWzsk* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
		) {
	bool run;

	return getCsjobClaim(csjob, takenNotAvailable, fulfilled, run);
};

void XchgWzskcmbd::clearCsjobRun(
			DbsWzsk* dbswzsk
			, const uint ixWzskVJob
		) {
	Csjobinfo* csjobinfo = NULL;
	Claim* claim = NULL;

	bool mod = false;

	rwmCsjobinfos.rlock("XchgWzskcmbd", "clearCsjobRun", "srefIxWzskVJob=" + VecWzskVJob::getSref(ixWzskVJob));

	auto it = csjobinfos.find(ixWzskVJob);
	if (it != csjobinfos.end()) csjobinfo = it->second;

	rwmCsjobinfos.runlock("XchgWzskcmbd", "clearCsjobRun", "srefIxWzskVJob=" + VecWzskVJob::getSref(ixWzskVJob));

	if (csjobinfo) {
		csjobinfo->mClaims.wlock("XchgWzskcmbd", "clearCsjobRun", "srefIxWzskVJob=" + VecWzskVJob::getSref(ixWzskVJob));

		for (auto it2 = csjobinfo->claims.begin(); it2 != csjobinfo->claims.end(); it2++) {
			claim = it2->second;

			if (claim->run) {
				claim->run = false;
				mod = true;
			};
		};

		csjobinfo->mClaims.wunlock("XchgWzskcmbd", "clearCsjobRun", "srefIxWzskVJob=" + VecWzskVJob::getSref(ixWzskVJob));

		if (mod) triggerCall(dbswzsk, VecWzskVCall::CALLWZSKCLAIMCHG, csjobinfo->jrefSrv);
	};
};

void XchgWzskcmbd::removeCsjobClaim(
			DbsWzsk* dbswzsk
			, CsjobWzsk* csjob
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWzskcmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWzskVJob];

		rwmCsjobinfos.runlock("XchgWzskcmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgWzskcmbd", "removeCsjobClaim");

		csjobinfo->mClaims.wlock("XchgWzskcmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) {
			delete it->second;
			csjobinfo->claims.erase(it);

			mod = csjob->srv->handleClaim(dbswzsk, csjobinfo->claims, 0);
		};

		csjobinfo->mClaims.wunlock("XchgWzskcmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgWzskcmbd", "removeCsjobClaim");

		if (mod) triggerCall(dbswzsk, VecWzskVCall::CALLWZSKCLAIMCHG, csjobinfo->jrefSrv);
	};
};

bool XchgWzskcmbd::getCsjobNotJob(
			const uint ixWzskVJob
		) {
	bool retval;

	rwmCsjobinfos.rlock("XchgWzskcmbd", "getCsjobNotJob", "srefIxWzskVJob=" + VecWzskVJob::getSref(ixWzskVJob));

	retval = (csjobinfos.find(ixWzskVJob) != csjobinfos.end());

	rwmCsjobinfos.runlock("XchgWzskcmbd", "getCsjobNotJob", "srefIxWzskVJob=" + VecWzskVJob::getSref(ixWzskVJob));

	return retval;
};

set<ubigint> XchgWzskcmbd::getCsjobClisByJref(
			const ubigint jref
		) {
	set<ubigint> retval;

	rwmCsjobinfos.rlock("XchgWzskcmbd", "getCsjobClis", "jref=" + to_string(jref));

	auto it = csjobinfos.find(ixWzskVJobs[jref]);
	
	if (it != csjobinfos.end()) retval = it->second->jrefsCli;

	rwmCsjobinfos.runlock("XchgWzskcmbd", "getCsjobClis", "jref=" + to_string(jref));

	return retval;
};

ubigint XchgWzskcmbd::addWakeup(
			const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq.getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqWzsk* req = new ReqWzsk(ReqWzsk::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupWzsk* wakeup = new WakeupWzsk(this, wref, jref, sref, deltat, weak);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "XchgWzskcmbd::addWakeup() error creating timer thread (" << res << ")" << endl;
		else {
			res = pthread_detach(timer);
			if (res != 0) cout << "XchgWzskcmbd::addWakeup() error detaching timer thread (" << res << ")" << endl;
		};
	};

	return(wref);
};

void* XchgWzskcmbd::runWakeup(
			void* arg
		) {
	WakeupWzsk* wakeup = (WakeupWzsk*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqWzsk* req = new ReqWzsk(ReqWzsk::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

void XchgWzskcmbd::runExtcall(
			void* arg
		) {
	ExtcallWzsk* extcall = (ExtcallWzsk*) arg;

	// generate request to be treated by job processor
	ReqWzsk* req = new ReqWzsk(ReqWzsk::VecVBasetype::EXTCALL);
	req->call = new Call(*(extcall->call));

	extcall->xchg->addReq(req);
};
