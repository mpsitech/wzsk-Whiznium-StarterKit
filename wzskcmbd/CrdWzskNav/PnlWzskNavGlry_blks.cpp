/**
	* \file PnlWzskNavGlry_blks.cpp
	* job handler for job PnlWzskNavGlry (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 11 Mar 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskNavGlry::VecVDo
 ******************************************************************************/

uint PnlWzskNavGlry::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butogrviewclick") return BUTOGRVIEWCLICK;
	if (s == "butogrnewcrdclick") return BUTOGRNEWCRDCLICK;
	if (s == "butobjviewclick") return BUTOBJVIEWCLICK;
	if (s == "butobjnewcrdclick") return BUTOBJNEWCRDCLICK;
	if (s == "butsesviewclick") return BUTSESVIEWCLICK;
	if (s == "butsesnewcrdclick") return BUTSESNEWCRDCLICK;
	if (s == "butshtviewclick") return BUTSHTVIEWCLICK;
	if (s == "butshtnewcrdclick") return BUTSHTNEWCRDCLICK;
	if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;

	return(0);
};

string PnlWzskNavGlry::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTOGRVIEWCLICK) return("ButOgrViewClick");
	if (ix == BUTOGRNEWCRDCLICK) return("ButOgrNewcrdClick");
	if (ix == BUTOBJVIEWCLICK) return("ButObjViewClick");
	if (ix == BUTOBJNEWCRDCLICK) return("ButObjNewcrdClick");
	if (ix == BUTSESVIEWCLICK) return("ButSesViewClick");
	if (ix == BUTSESNEWCRDCLICK) return("ButSesNewcrdClick");
	if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");
	if (ix == BUTSHTNEWCRDCLICK) return("ButShtNewcrdClick");
	if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzskNavGlry::ContIac
 ******************************************************************************/

PnlWzskNavGlry::ContIac::ContIac(
			const uint numFLstOgr
			, const uint numFLstObj
			, const uint numFLstSes
			, const uint numFLstSht
			, const uint numFLstFil
		) :
			Block()
		{
	this->numFLstOgr = numFLstOgr;
	this->numFLstObj = numFLstObj;
	this->numFLstSes = numFLstSes;
	this->numFLstSht = numFLstSht;
	this->numFLstFil = numFLstFil;

	mask = {NUMFLSTOGR, NUMFLSTOBJ, NUMFLSTSES, NUMFLSTSHT, NUMFLSTFIL};
};

bool PnlWzskNavGlry::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskNavGlry"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstOgr")) {numFLstOgr = me["numFLstOgr"].asUInt(); add(NUMFLSTOGR);};
		if (me.isMember("numFLstObj")) {numFLstObj = me["numFLstObj"].asUInt(); add(NUMFLSTOBJ);};
		if (me.isMember("numFLstSes")) {numFLstSes = me["numFLstSes"].asUInt(); add(NUMFLSTSES);};
		if (me.isMember("numFLstSht")) {numFLstSht = me["numFLstSht"].asUInt(); add(NUMFLSTSHT);};
		if (me.isMember("numFLstFil")) {numFLstFil = me["numFLstFil"].asUInt(); add(NUMFLSTFIL);};
	};

	return basefound;
};

bool PnlWzskNavGlry::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskNavGlry");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskNavGlry";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOgr", numFLstOgr)) add(NUMFLSTOGR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstObj", numFLstObj)) add(NUMFLSTOBJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSes", numFLstSes)) add(NUMFLSTSES);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSht", numFLstSht)) add(NUMFLSTSHT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
	};

	return basefound;
};

void PnlWzskNavGlry::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskNavGlry";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstOgr"] = numFLstOgr;
	me["numFLstObj"] = numFLstObj;
	me["numFLstSes"] = numFLstSes;
	me["numFLstSht"] = numFLstSht;
	me["numFLstFil"] = numFLstFil;
};

void PnlWzskNavGlry::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskNavGlry";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskNavGlry";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstOgr", numFLstOgr);
		writeUintAttr(wr, itemtag, "sref", "numFLstObj", numFLstObj);
		writeUintAttr(wr, itemtag, "sref", "numFLstSes", numFLstSes);
		writeUintAttr(wr, itemtag, "sref", "numFLstSht", numFLstSht);
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavGlry::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstOgr == comp->numFLstOgr) insert(items, NUMFLSTOGR);
	if (numFLstObj == comp->numFLstObj) insert(items, NUMFLSTOBJ);
	if (numFLstSes == comp->numFLstSes) insert(items, NUMFLSTSES);
	if (numFLstSht == comp->numFLstSht) insert(items, NUMFLSTSHT);
	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);

	return(items);
};

set<uint> PnlWzskNavGlry::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTOGR, NUMFLSTOBJ, NUMFLSTSES, NUMFLSTSHT, NUMFLSTFIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavGlry::StatApp
 ******************************************************************************/

void PnlWzskNavGlry::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzskVExpstate
			, const bool LstOgrAlt
			, const bool LstObjAlt
			, const bool LstSesAlt
			, const bool LstShtAlt
			, const bool LstFilAlt
			, const uint LstOgrNumFirstdisp
			, const uint LstObjNumFirstdisp
			, const uint LstSesNumFirstdisp
			, const uint LstShtNumFirstdisp
			, const uint LstFilNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskNavGlry";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["LstOgrAlt"] = LstOgrAlt;
	me["LstObjAlt"] = LstObjAlt;
	me["LstSesAlt"] = LstSesAlt;
	me["LstShtAlt"] = LstShtAlt;
	me["LstFilAlt"] = LstFilAlt;
	me["LstOgrNumFirstdisp"] = LstOgrNumFirstdisp;
	me["LstObjNumFirstdisp"] = LstObjNumFirstdisp;
	me["LstSesNumFirstdisp"] = LstSesNumFirstdisp;
	me["LstShtNumFirstdisp"] = LstShtNumFirstdisp;
	me["LstFilNumFirstdisp"] = LstFilNumFirstdisp;
};

void PnlWzskNavGlry::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
			, const bool LstOgrAlt
			, const bool LstObjAlt
			, const bool LstSesAlt
			, const bool LstShtAlt
			, const bool LstFilAlt
			, const uint LstOgrNumFirstdisp
			, const uint LstObjNumFirstdisp
			, const uint LstSesNumFirstdisp
			, const uint LstShtNumFirstdisp
			, const uint LstFilNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskNavGlry";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskNavGlry";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstOgrAlt", LstOgrAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstObjAlt", LstObjAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSesAlt", LstSesAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstShtAlt", LstShtAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAlt", LstFilAlt);
		writeUintAttr(wr, itemtag, "sref", "LstOgrNumFirstdisp", LstOgrNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstObjNumFirstdisp", LstObjNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSesNumFirstdisp", LstSesNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstShtNumFirstdisp", LstShtNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavGlry::StatShr
 ******************************************************************************/

PnlWzskNavGlry::StatShr::StatShr(
			const bool LstOgrAvail
			, const bool ButOgrViewActive
			, const bool LstObjAvail
			, const bool ButObjViewActive
			, const bool LstSesAvail
			, const bool ButSesViewActive
			, const bool LstShtAvail
			, const bool ButShtViewActive
			, const bool LstFilAvail
			, const bool ButFilViewActive
		) :
			Block()
		{
	this->LstOgrAvail = LstOgrAvail;
	this->ButOgrViewActive = ButOgrViewActive;
	this->LstObjAvail = LstObjAvail;
	this->ButObjViewActive = ButObjViewActive;
	this->LstSesAvail = LstSesAvail;
	this->ButSesViewActive = ButSesViewActive;
	this->LstShtAvail = LstShtAvail;
	this->ButShtViewActive = ButShtViewActive;
	this->LstFilAvail = LstFilAvail;
	this->ButFilViewActive = ButFilViewActive;

	mask = {LSTOGRAVAIL, BUTOGRVIEWACTIVE, LSTOBJAVAIL, BUTOBJVIEWACTIVE, LSTSESAVAIL, BUTSESVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE};
};

void PnlWzskNavGlry::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskNavGlry";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstOgrAvail"] = LstOgrAvail;
	me["ButOgrViewActive"] = ButOgrViewActive;
	me["LstObjAvail"] = LstObjAvail;
	me["ButObjViewActive"] = ButObjViewActive;
	me["LstSesAvail"] = LstSesAvail;
	me["ButSesViewActive"] = ButSesViewActive;
	me["LstShtAvail"] = LstShtAvail;
	me["ButShtViewActive"] = ButShtViewActive;
	me["LstFilAvail"] = LstFilAvail;
	me["ButFilViewActive"] = ButFilViewActive;
};

void PnlWzskNavGlry::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskNavGlry";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskNavGlry";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstOgrAvail", LstOgrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButOgrViewActive", ButOgrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstObjAvail", LstObjAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButObjViewActive", ButObjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSesAvail", LstSesAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSesViewActive", ButSesViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstShtAvail", LstShtAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButShtViewActive", ButShtViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAvail", LstFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewActive", ButFilViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavGlry::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstOgrAvail == comp->LstOgrAvail) insert(items, LSTOGRAVAIL);
	if (ButOgrViewActive == comp->ButOgrViewActive) insert(items, BUTOGRVIEWACTIVE);
	if (LstObjAvail == comp->LstObjAvail) insert(items, LSTOBJAVAIL);
	if (ButObjViewActive == comp->ButObjViewActive) insert(items, BUTOBJVIEWACTIVE);
	if (LstSesAvail == comp->LstSesAvail) insert(items, LSTSESAVAIL);
	if (ButSesViewActive == comp->ButSesViewActive) insert(items, BUTSESVIEWACTIVE);
	if (LstShtAvail == comp->LstShtAvail) insert(items, LSTSHTAVAIL);
	if (ButShtViewActive == comp->ButShtViewActive) insert(items, BUTSHTVIEWACTIVE);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);

	return(items);
};

set<uint> PnlWzskNavGlry::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTOGRAVAIL, BUTOGRVIEWACTIVE, LSTOBJAVAIL, BUTOBJVIEWACTIVE, LSTSESAVAIL, BUTSESVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavGlry::Tag
 ******************************************************************************/

void PnlWzskNavGlry::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskNavGlry";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Gallery";
		me["CptOgr"] = "object groups";
		me["CptObj"] = "objects";
		me["CptSes"] = "sessions";
		me["CptSht"] = "shots";
		me["CptFil"] = "files";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["Cpt"] = "Galerie";
		me["CptOgr"] = "Objektgruppen";
		me["CptObj"] = "Objekte";
		me["CptSes"] = "Sitzungen";
		me["CptSht"] = "Aufnahmen";
		me["CptFil"] = "Dateien";
	};
};

void PnlWzskNavGlry::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskNavGlry";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskNavGlry";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Gallery");
			writeStringAttr(wr, itemtag, "sref", "CptOgr", "object groups");
			writeStringAttr(wr, itemtag, "sref", "CptObj", "objects");
			writeStringAttr(wr, itemtag, "sref", "CptSes", "sessions");
			writeStringAttr(wr, itemtag, "sref", "CptSht", "shots");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "files");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Galerie");
			writeStringAttr(wr, itemtag, "sref", "CptOgr", "Objektgruppen");
			writeStringAttr(wr, itemtag, "sref", "CptObj", "Objekte");
			writeStringAttr(wr, itemtag, "sref", "CptSes", "Sitzungen");
			writeStringAttr(wr, itemtag, "sref", "CptSht", "Aufnahmen");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Dateien");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavGlry::DpchAppData
 ******************************************************************************/

PnlWzskNavGlry::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVGLRYDATA)
		{
};

string PnlWzskNavGlry::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavGlry::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskNavGlryData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskNavGlry::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskNavGlryData");
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
 class PnlWzskNavGlry::DpchAppDo
 ******************************************************************************/

PnlWzskNavGlry::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVGLRYDO)
		{
	ixVDo = 0;
};

string PnlWzskNavGlry::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavGlry::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskNavGlryDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskNavGlry::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskNavGlryDo");
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
 class PnlWzskNavGlry::DpchEngData
 ******************************************************************************/

PnlWzskNavGlry::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstFil
			, Feed* feedFLstObj
			, Feed* feedFLstOgr
			, Feed* feedFLstSes
			, Feed* feedFLstSht
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVGLRYDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTFIL, FEEDFLSTOBJ, FEEDFLSTOGR, FEEDFLSTSES, FEEDFLSTSHT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTFIL) && feedFLstFil) this->feedFLstFil = *feedFLstFil;
	if (find(this->mask, FEEDFLSTOBJ) && feedFLstObj) this->feedFLstObj = *feedFLstObj;
	if (find(this->mask, FEEDFLSTOGR) && feedFLstOgr) this->feedFLstOgr = *feedFLstOgr;
	if (find(this->mask, FEEDFLSTSES) && feedFLstSes) this->feedFLstSes = *feedFLstSes;
	if (find(this->mask, FEEDFLSTSHT) && feedFLstSht) this->feedFLstSht = *feedFLstSht;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskNavGlry::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(FEEDFLSTOBJ)) ss.push_back("feedFLstObj");
	if (has(FEEDFLSTOGR)) ss.push_back("feedFLstOgr");
	if (has(FEEDFLSTSES)) ss.push_back("feedFLstSes");
	if (has(FEEDFLSTSHT)) ss.push_back("feedFLstSht");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavGlry::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTFIL)) {feedFLstFil = src->feedFLstFil; add(FEEDFLSTFIL);};
	if (src->has(FEEDFLSTOBJ)) {feedFLstObj = src->feedFLstObj; add(FEEDFLSTOBJ);};
	if (src->has(FEEDFLSTOGR)) {feedFLstOgr = src->feedFLstOgr; add(FEEDFLSTOGR);};
	if (src->has(FEEDFLSTSES)) {feedFLstSes = src->feedFLstSes; add(FEEDFLSTSES);};
	if (src->has(FEEDFLSTSHT)) {feedFLstSht = src->feedFLstSht; add(FEEDFLSTSHT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskNavGlry::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskNavGlryData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTFIL)) feedFLstFil.writeJSON(me);
	if (has(FEEDFLSTOBJ)) feedFLstObj.writeJSON(me);
	if (has(FEEDFLSTOGR)) feedFLstOgr.writeJSON(me);
	if (has(FEEDFLSTSES)) feedFLstSes.writeJSON(me);
	if (has(FEEDFLSTSHT)) feedFLstSht.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskNavGlry::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskNavGlryData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTFIL)) feedFLstFil.writeXML(wr);
		if (has(FEEDFLSTOBJ)) feedFLstObj.writeXML(wr);
		if (has(FEEDFLSTOGR)) feedFLstOgr.writeXML(wr);
		if (has(FEEDFLSTSES)) feedFLstSes.writeXML(wr);
		if (has(FEEDFLSTSHT)) feedFLstSht.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
