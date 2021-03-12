/**
	* \file PnlWzskSesDetail_blks.cpp
	* job handler for job PnlWzskSesDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskSesDetail::VecVDo
 ******************************************************************************/

uint PnlWzskSesDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butusrviewclick") return BUTUSRVIEWCLICK;

	return(0);
};

string PnlWzskSesDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");

	return("");
};

/******************************************************************************
 class PnlWzskSesDetail::ContIac
 ******************************************************************************/

PnlWzskSesDetail::ContIac::ContIac(
			const string& TxfSta
			, const string& TxfSto
			, const string& TxfIp
		) :
			Block()
		{
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->TxfIp = TxfIp;

	mask = {TXFSTA, TXFSTO, TXFIP};
};

bool PnlWzskSesDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWzskSesDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfSta")) {TxfSta = me["TxfSta"].asString(); add(TXFSTA);};
		if (me.isMember("TxfSto")) {TxfSto = me["TxfSto"].asString(); add(TXFSTO);};
		if (me.isMember("TxfIp")) {TxfIp = me["TxfIp"].asString(); add(TXFIP);};
	};

	return basefound;
};

bool PnlWzskSesDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskSesDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskSesDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfIp", TxfIp)) add(TXFIP);
	};

	return basefound;
};

void PnlWzskSesDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskSesDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfSta"] = TxfSta;
	me["TxfSto"] = TxfSto;
	me["TxfIp"] = TxfIp;
};

void PnlWzskSesDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskSesDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskSesDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeStringAttr(wr, itemtag, "sref", "TxfIp", TxfIp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskSesDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (TxfIp == comp->TxfIp) insert(items, TXFIP);

	return(items);
};

set<uint> PnlWzskSesDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSTA, TXFSTO, TXFIP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskSesDetail::ContInf
 ******************************************************************************/

PnlWzskSesDetail::ContInf::ContInf(
			const string& TxtUsr
		) :
			Block()
		{
	this->TxtUsr = TxtUsr;

	mask = {TXTUSR};
};

void PnlWzskSesDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskSesDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtUsr"] = TxtUsr;
};

void PnlWzskSesDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskSesDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskSesDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtUsr", TxtUsr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskSesDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtUsr == comp->TxtUsr) insert(items, TXTUSR);

	return(items);
};

set<uint> PnlWzskSesDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTUSR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskSesDetail::StatApp
 ******************************************************************************/

void PnlWzskSesDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzskVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskSesDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
};

void PnlWzskSesDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskSesDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskSesDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskSesDetail::StatShr
 ******************************************************************************/

PnlWzskSesDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtUsrActive
			, const bool ButUsrViewAvail
			, const bool ButUsrViewActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxfIpActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtUsrActive = TxtUsrActive;
	this->ButUsrViewAvail = ButUsrViewAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxfIpActive = TxfIpActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTUSRACTIVE, BUTUSRVIEWAVAIL, BUTUSRVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFIPACTIVE};
};

void PnlWzskSesDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskSesDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtUsrActive"] = TxtUsrActive;
	me["ButUsrViewAvail"] = ButUsrViewAvail;
	me["ButUsrViewActive"] = ButUsrViewActive;
	me["TxfStaActive"] = TxfStaActive;
	me["TxfStoActive"] = TxfStoActive;
	me["TxfIpActive"] = TxfIpActive;
};

void PnlWzskSesDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskSesDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskSesDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtUsrActive", TxtUsrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButUsrViewAvail", ButUsrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUsrViewActive", ButUsrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfIpActive", TxfIpActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskSesDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtUsrActive == comp->TxtUsrActive) insert(items, TXTUSRACTIVE);
	if (ButUsrViewAvail == comp->ButUsrViewAvail) insert(items, BUTUSRVIEWAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxfIpActive == comp->TxfIpActive) insert(items, TXFIPACTIVE);

	return(items);
};

set<uint> PnlWzskSesDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTUSRACTIVE, BUTUSRVIEWAVAIL, BUTUSRVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFIPACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskSesDetail::Tag
 ******************************************************************************/

void PnlWzskSesDetail::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskSesDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["CptUsr"] = "user";
		me["CptSta"] = "login time";
		me["CptSto"] = "logout time";
		me["CptIp"] = "IP address";
	} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
		me["CptUsr"] = "Benutzer";
		me["CptSta"] = "Login-Zeitpunkt";
		me["CptSto"] = "Logout-Zeitpunkt";
		me["CptIp"] = "IP Adresse";
	};
	me["Cpt"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::DETAIL, ixWzskVLocale));
};

void PnlWzskSesDetail::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskSesDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskSesDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "user");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "login time");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "logout time");
			writeStringAttr(wr, itemtag, "sref", "CptIp", "IP address");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "Benutzer");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "Login-Zeitpunkt");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "Logout-Zeitpunkt");
			writeStringAttr(wr, itemtag, "sref", "CptIp", "IP Adresse");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::DETAIL, ixWzskVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskSesDetail::DpchAppData
 ******************************************************************************/

PnlWzskSesDetail::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSESDETAILDATA)
		{
};

string PnlWzskSesDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskSesDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzskSesDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskSesDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskSesDetailData");
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
 class PnlWzskSesDetail::DpchAppDo
 ******************************************************************************/

PnlWzskSesDetail::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKSESDETAILDO)
		{
	ixVDo = 0;
};

string PnlWzskSesDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskSesDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzskSesDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskSesDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskSesDetailDo");
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
 class PnlWzskSesDetail::DpchEngData
 ******************************************************************************/

PnlWzskSesDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKSESDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskSesDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskSesDetail::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskSesDetail::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskSesDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskSesDetail::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskSesDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
