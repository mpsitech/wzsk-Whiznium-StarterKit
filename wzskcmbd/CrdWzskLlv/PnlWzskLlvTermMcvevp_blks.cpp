/**
	* \file PnlWzskLlvTermMcvevp_blks.cpp
	* job handler for job PnlWzskLlvTermMcvevp (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvTermMcvevp::VecVDo
 ******************************************************************************/

uint PnlWzskLlvTermMcvevp::VecVDo::getIx(
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

string PnlWzskLlvTermMcvevp::VecVDo::getSref(
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
 class PnlWzskLlvTermMcvevp::ContIac
 ******************************************************************************/

PnlWzskLlvTermMcvevp::ContIac::ContIac(
			const uint numFPupCmd
			, const string& TxfCsq
		) :
			Block()
		{
	this->numFPupCmd = numFPupCmd;
	this->TxfCsq = TxfCsq;

	mask = {NUMFPUPCMD, TXFCSQ};
};

bool PnlWzskLlvTermMcvevp::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWzskLlvTermMcvevp"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupCmd")) {numFPupCmd = me["numFPupCmd"].asUInt(); add(NUMFPUPCMD);};
		if (me.isMember("TxfCsq")) {TxfCsq = me["TxfCsq"].asString(); add(TXFCSQ);};
	};

	return basefound;
};

bool PnlWzskLlvTermMcvevp::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLlvTermMcvevp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLlvTermMcvevp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCmd", numFPupCmd)) add(NUMFPUPCMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCsq", TxfCsq)) add(TXFCSQ);
	};

	return basefound;
};

void PnlWzskLlvTermMcvevp::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLlvTermMcvevp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupCmd"] = numFPupCmd;
	me["TxfCsq"] = TxfCsq;
};

void PnlWzskLlvTermMcvevp::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLlvTermMcvevp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLlvTermMcvevp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupCmd", numFPupCmd);
		writeStringAttr(wr, itemtag, "sref", "TxfCsq", TxfCsq);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvTermMcvevp::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupCmd == comp->numFPupCmd) insert(items, NUMFPUPCMD);
	if (TxfCsq == comp->TxfCsq) insert(items, TXFCSQ);

	return(items);
};

set<uint> PnlWzskLlvTermMcvevp::ContIac::diff(
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
 class PnlWzskLlvTermMcvevp::ContInf
 ******************************************************************************/

PnlWzskLlvTermMcvevp::ContInf::ContInf(
			const bool ButClaimOn
			, const string& TxtCst
			, const string& TxtDatLog
		) :
			Block()
		{
	this->ButClaimOn = ButClaimOn;
	this->TxtCst = TxtCst;
	this->TxtDatLog = TxtDatLog;

	mask = {BUTCLAIMON, TXTCST, TXTDATLOG};
};

void PnlWzskLlvTermMcvevp::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLlvTermMcvevp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButClaimOn"] = ButClaimOn;
	me["TxtCst"] = TxtCst;
	me["TxtDatLog"] = TxtDatLog;
};

void PnlWzskLlvTermMcvevp::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLlvTermMcvevp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskLlvTermMcvevp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButClaimOn", ButClaimOn);
		writeStringAttr(wr, itemtag, "sref", "TxtCst", TxtCst);
		writeStringAttr(wr, itemtag, "sref", "TxtDatLog", TxtDatLog);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvTermMcvevp::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtCst == comp->TxtCst) insert(items, TXTCST);
	if (TxtDatLog == comp->TxtDatLog) insert(items, TXTDATLOG);

	return(items);
};

set<uint> PnlWzskLlvTermMcvevp::ContInf::diff(
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
 class PnlWzskLlvTermMcvevp::StatShr
 ******************************************************************************/

PnlWzskLlvTermMcvevp::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool ButSmtActive
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->ButClaimActive = ButClaimActive;
	this->ButSmtActive = ButSmtActive;

	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTSMTACTIVE};
};

void PnlWzskLlvTermMcvevp::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLlvTermMcvevp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["ButClaimActive"] = ButClaimActive;
	me["ButSmtActive"] = ButSmtActive;
};

void PnlWzskLlvTermMcvevp::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLlvTermMcvevp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskLlvTermMcvevp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButClaimActive", ButClaimActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSmtActive", ButSmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLlvTermMcvevp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (ButSmtActive == comp->ButSmtActive) insert(items, BUTSMTACTIVE);

	return(items);
};

set<uint> PnlWzskLlvTermMcvevp::StatShr::diff(
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
 class PnlWzskLlvTermMcvevp::Tag
 ******************************************************************************/

void PnlWzskLlvTermMcvevp::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskLlvTermMcvevp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Terminal";
		me["CptCst"] = "Connection state";
		me["HdgDio"] = "Data in/out";
		me["HdgCex"] = "Command execution";
		me["CptCmd"] = "Command";
		me["ButApd"] = "Append";
		me["CptCsq"] = "Command sequence";
		me["ButSmt"] = "Submit";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["Cpt"] = "Terminal";
		me["CptCst"] = "Verbindungsstatus";
		me["HdgDio"] = "Ein-/ausgehende Daten";
		me["HdgCex"] = "Befehlsausf\\\\u00fchrung";
		me["CptCmd"] = "Befehl";
		me["ButApd"] = "Hinzuf\\\\u00fcgen";
		me["CptCsq"] = "Befehlsfolge";
		me["ButSmt"] = "Absenden";
	};
};

void PnlWzskLlvTermMcvevp::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskLlvTermMcvevp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskLlvTermMcvevp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Terminal");
			writeStringAttr(wr, itemtag, "sref", "CptCst", "Connection state");
			writeStringAttr(wr, itemtag, "sref", "HdgDio", "Data in/out");
			writeStringAttr(wr, itemtag, "sref", "HdgCex", "Command execution");
			writeStringAttr(wr, itemtag, "sref", "CptCmd", "Command");
			writeStringAttr(wr, itemtag, "sref", "ButApd", "Append");
			writeStringAttr(wr, itemtag, "sref", "CptCsq", "Command sequence");
			writeStringAttr(wr, itemtag, "sref", "ButSmt", "Submit");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Terminal");
			writeStringAttr(wr, itemtag, "sref", "CptCst", "Verbindungsstatus");
			writeStringAttr(wr, itemtag, "sref", "HdgDio", "Ein-/ausgehende Daten");
			writeStringAttr(wr, itemtag, "sref", "HdgCex", "Befehlsausf\\\\u00fchrung");
			writeStringAttr(wr, itemtag, "sref", "CptCmd", "Befehl");
			writeStringAttr(wr, itemtag, "sref", "ButApd", "Hinzuf\\\\u00fcgen");
			writeStringAttr(wr, itemtag, "sref", "CptCsq", "Befehlsfolge");
			writeStringAttr(wr, itemtag, "sref", "ButSmt", "Absenden");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLlvTermMcvevp::DpchAppData
 ******************************************************************************/

PnlWzskLlvTermMcvevp::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVTERMMCVEVPDATA)
		{
};

string PnlWzskLlvTermMcvevp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvTermMcvevp::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzskLlvTermMcvevpData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskLlvTermMcvevp::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLlvTermMcvevpData");
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
 class PnlWzskLlvTermMcvevp::DpchAppDo
 ******************************************************************************/

PnlWzskLlvTermMcvevp::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLLVTERMMCVEVPDO)
		{
	ixVDo = 0;
};

string PnlWzskLlvTermMcvevp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvTermMcvevp::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzskLlvTermMcvevpDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskLlvTermMcvevp::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLlvTermMcvevpDo");
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
 class PnlWzskLlvTermMcvevp::DpchEngData
 ******************************************************************************/

PnlWzskLlvTermMcvevp::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupCmd
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVTERMMCVEVPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPCMD, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPCMD) && feedFPupCmd) this->feedFPupCmd = *feedFPupCmd;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskLlvTermMcvevp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPCMD)) ss.push_back("feedFPupCmd");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvTermMcvevp::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPCMD)) {feedFPupCmd = src->feedFPupCmd; add(FEEDFPUPCMD);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskLlvTermMcvevp::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskLlvTermMcvevpData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPCMD)) feedFPupCmd.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskLlvTermMcvevp::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLlvTermMcvevpData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPCMD)) feedFPupCmd.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
