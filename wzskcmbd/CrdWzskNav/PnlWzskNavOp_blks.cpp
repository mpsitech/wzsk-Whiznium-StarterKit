/**
	* \file PnlWzskNavOp_blks.cpp
	* job handler for job PnlWzskNavOp (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskNavOp::VecVDo
 ******************************************************************************/

uint PnlWzskNavOp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butllvnewcrdclick") return BUTLLVNEWCRDCLICK;
	if (s == "butvtrnewcrdclick") return BUTVTRNEWCRDCLICK;
	if (s == "buthwcnewcrdclick") return BUTHWCNEWCRDCLICK;
	if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;

	return(0);
};

string PnlWzskNavOp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTLLVNEWCRDCLICK) return("ButLlvNewcrdClick");
	if (ix == BUTVTRNEWCRDCLICK) return("ButVtrNewcrdClick");
	if (ix == BUTHWCNEWCRDCLICK) return("ButHwcNewcrdClick");
	if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzskNavOp::ContIac
 ******************************************************************************/

PnlWzskNavOp::ContIac::ContIac(
			const uint numFLstFil
		) :
			Block()
			, numFLstFil(numFLstFil)
		{
	mask = {NUMFLSTFIL};
};

bool PnlWzskNavOp::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskNavOp"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstFil")) {numFLstFil = me["numFLstFil"].asUInt(); add(NUMFLSTFIL);};
	};

	return basefound;
};

bool PnlWzskNavOp::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskNavOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskNavOp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
	};

	return basefound;
};

void PnlWzskNavOp::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskNavOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstFil"] = (Json::Value::UInt) numFLstFil;
};

void PnlWzskNavOp::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskNavOp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskNavOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavOp::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);

	return(items);
};

set<uint> PnlWzskNavOp::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTFIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavOp::StatApp
 ******************************************************************************/

void PnlWzskNavOp::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzskVExpstate
			, const bool LstFilAlt
			, const uint LstFilNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskNavOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["LstFilAlt"] = LstFilAlt;
	me["LstFilNumFirstdisp"] = (Json::Value::UInt) LstFilNumFirstdisp;
};

void PnlWzskNavOp::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
			, const bool LstFilAlt
			, const uint LstFilNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskNavOp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskNavOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstFilAlt", LstFilAlt);
		writeUintAttr(wr, itemtag, "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavOp::StatShr
 ******************************************************************************/

PnlWzskNavOp::StatShr::StatShr(
			const bool ButLlvNewcrdAvail
			, const bool ButVtrNewcrdAvail
			, const bool ButHwcNewcrdAvail
			, const bool LstFilAvail
			, const bool ButFilViewActive
		) :
			Block()
			, ButLlvNewcrdAvail(ButLlvNewcrdAvail)
			, ButVtrNewcrdAvail(ButVtrNewcrdAvail)
			, ButHwcNewcrdAvail(ButHwcNewcrdAvail)
			, LstFilAvail(LstFilAvail)
			, ButFilViewActive(ButFilViewActive)
		{
	mask = {BUTLLVNEWCRDAVAIL, BUTVTRNEWCRDAVAIL, BUTHWCNEWCRDAVAIL, LSTFILAVAIL, BUTFILVIEWACTIVE};
};

void PnlWzskNavOp::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskNavOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButLlvNewcrdAvail"] = ButLlvNewcrdAvail;
	me["ButVtrNewcrdAvail"] = ButVtrNewcrdAvail;
	me["ButHwcNewcrdAvail"] = ButHwcNewcrdAvail;
	me["LstFilAvail"] = LstFilAvail;
	me["ButFilViewActive"] = ButFilViewActive;
};

void PnlWzskNavOp::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskNavOp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskNavOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButLlvNewcrdAvail", ButLlvNewcrdAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVtrNewcrdAvail", ButVtrNewcrdAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButHwcNewcrdAvail", ButHwcNewcrdAvail);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAvail", LstFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewActive", ButFilViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavOp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButLlvNewcrdAvail == comp->ButLlvNewcrdAvail) insert(items, BUTLLVNEWCRDAVAIL);
	if (ButVtrNewcrdAvail == comp->ButVtrNewcrdAvail) insert(items, BUTVTRNEWCRDAVAIL);
	if (ButHwcNewcrdAvail == comp->ButHwcNewcrdAvail) insert(items, BUTHWCNEWCRDAVAIL);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);

	return(items);
};

set<uint> PnlWzskNavOp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTLLVNEWCRDAVAIL, BUTVTRNEWCRDAVAIL, BUTHWCNEWCRDAVAIL, LSTFILAVAIL, BUTFILVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavOp::Tag
 ******************************************************************************/

void PnlWzskNavOp::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskNavOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Operation";
		me["CptLlv"] = "low-level access";
		me["CptVtr"] = "vision-to-rotary";
		me["CptHwc"] = "HDR wavelet classification";
		me["CptFil"] = "files";
	};
};

void PnlWzskNavOp::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskNavOp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskNavOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Operation");
			writeStringAttr(wr, itemtag, "sref", "CptLlv", "low-level access");
			writeStringAttr(wr, itemtag, "sref", "CptVtr", "vision-to-rotary");
			writeStringAttr(wr, itemtag, "sref", "CptHwc", "HDR wavelet classification");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "files");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavOp::DpchAppData
 ******************************************************************************/

PnlWzskNavOp::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVOPDATA)
		{
};

string PnlWzskNavOp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavOp::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskNavOpData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskNavOp::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskNavOpData");
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
 class PnlWzskNavOp::DpchAppDo
 ******************************************************************************/

PnlWzskNavOp::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVOPDO)
		{
	ixVDo = 0;
};

string PnlWzskNavOp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavOp::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskNavOpDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskNavOp::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskNavOpDo");
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
 class PnlWzskNavOp::DpchEngData
 ******************************************************************************/

PnlWzskNavOp::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstFil
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVOPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTFIL, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTFIL) && feedFLstFil) this->feedFLstFil = *feedFLstFil;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskNavOp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavOp::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTFIL)) {feedFLstFil = src->feedFLstFil; add(FEEDFLSTFIL);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskNavOp::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskNavOpData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTFIL)) feedFLstFil.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskNavOp::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskNavOpData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTFIL)) feedFLstFil.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
