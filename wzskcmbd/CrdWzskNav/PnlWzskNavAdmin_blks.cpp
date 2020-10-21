/**
	* \file PnlWzskNavAdmin_blks.cpp
	* job handler for job PnlWzskNavAdmin (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskNavAdmin::VecVDo
 ******************************************************************************/

uint PnlWzskNavAdmin::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;
	if (s == "butusgnewcrdclick") return BUTUSGNEWCRDCLICK;
	if (s == "butusrviewclick") return BUTUSRVIEWCLICK;
	if (s == "butusrnewcrdclick") return BUTUSRNEWCRDCLICK;
	if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	if (s == "butprsnewcrdclick") return BUTPRSNEWCRDCLICK;
	if (s == "butscfnewcrdclick") return BUTSCFNEWCRDCLICK;

	return(0);
};

string PnlWzskNavAdmin::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
	if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
	if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
	if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");
	if (ix == BUTSCFNEWCRDCLICK) return("ButScfNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzskNavAdmin::ContIac
 ******************************************************************************/

PnlWzskNavAdmin::ContIac::ContIac(
			const uint numFLstUsg
			, const uint numFLstUsr
			, const uint numFLstPrs
		) :
			Block()
		{
	this->numFLstUsg = numFLstUsg;
	this->numFLstUsr = numFLstUsr;
	this->numFLstPrs = numFLstPrs;

	mask = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS};
};

bool PnlWzskNavAdmin::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskNavAdmin";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsg", numFLstUsg)) add(NUMFLSTUSG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsr", numFLstUsr)) add(NUMFLSTUSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrs", numFLstPrs)) add(NUMFLSTPRS);
	};

	return basefound;
};

void PnlWzskNavAdmin::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstUsg", numFLstUsg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUsr", numFLstUsr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrs", numFLstPrs);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavAdmin::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstUsg == comp->numFLstUsg) insert(items, NUMFLSTUSG);
	if (numFLstUsr == comp->numFLstUsr) insert(items, NUMFLSTUSR);
	if (numFLstPrs == comp->numFLstPrs) insert(items, NUMFLSTPRS);

	return(items);
};

set<uint> PnlWzskNavAdmin::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavAdmin::StatApp
 ******************************************************************************/

void PnlWzskNavAdmin::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
			, const bool LstUsgAlt
			, const bool LstUsrAlt
			, const bool LstPrsAlt
			, const uint LstUsgNumFirstdisp
			, const uint LstUsrNumFirstdisp
			, const uint LstPrsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstUsgAlt", LstUsgAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstUsrAlt", LstUsrAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPrsAlt", LstPrsAlt);
		writeUintAttr(wr, itemtag, "sref", "LstUsgNumFirstdisp", LstUsgNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstUsrNumFirstdisp", LstUsrNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPrsNumFirstdisp", LstPrsNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavAdmin::StatShr
 ******************************************************************************/

PnlWzskNavAdmin::StatShr::StatShr(
			const bool LstUsgAvail
			, const bool ButUsgViewActive
			, const bool LstUsrAvail
			, const bool ButUsrViewActive
			, const bool LstPrsAvail
			, const bool ButPrsViewActive
			, const bool ButScfNewcrdAvail
		) :
			Block()
		{
	this->LstUsgAvail = LstUsgAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->LstUsrAvail = LstUsrAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->LstPrsAvail = LstPrsAvail;
	this->ButPrsViewActive = ButPrsViewActive;
	this->ButScfNewcrdAvail = ButScfNewcrdAvail;

	mask = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, BUTSCFNEWCRDAVAIL};
};

void PnlWzskNavAdmin::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstUsgAvail", LstUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUsgViewActive", ButUsgViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstUsrAvail", LstUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUsrViewActive", ButUsrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPrsAvail", LstPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrsViewActive", ButPrsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButScfNewcrdAvail", ButScfNewcrdAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavAdmin::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstUsgAvail == comp->LstUsgAvail) insert(items, LSTUSGAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (LstUsrAvail == comp->LstUsrAvail) insert(items, LSTUSRAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (LstPrsAvail == comp->LstPrsAvail) insert(items, LSTPRSAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);
	if (ButScfNewcrdAvail == comp->ButScfNewcrdAvail) insert(items, BUTSCFNEWCRDAVAIL);

	return(items);
};

set<uint> PnlWzskNavAdmin::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, BUTSCFNEWCRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavAdmin::Tag
 ******************************************************************************/

void PnlWzskNavAdmin::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Administration module");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "user groups");
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "users");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "persons");
			writeStringAttr(wr, itemtag, "sref", "CptScf", "system configuration");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Verwaltung");
			writeStringAttr(wr, itemtag, "sref", "CptUsg", "Benutzergruppen");
			writeStringAttr(wr, itemtag, "sref", "CptUsr", "Benutzer");
			writeStringAttr(wr, itemtag, "sref", "CptPrs", "Personen");
			writeStringAttr(wr, itemtag, "sref", "CptScf", "Systemkonfiguration");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavAdmin::DpchAppData
 ******************************************************************************/

PnlWzskNavAdmin::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVADMINDATA)
		{
};

string PnlWzskNavAdmin::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavAdmin::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskNavAdminData");
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
 class PnlWzskNavAdmin::DpchAppDo
 ******************************************************************************/

PnlWzskNavAdmin::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVADMINDO)
		{
	ixVDo = 0;
};

string PnlWzskNavAdmin::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavAdmin::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskNavAdminDo");
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
 class PnlWzskNavAdmin::DpchEngData
 ******************************************************************************/

PnlWzskNavAdmin::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstPrs
			, Feed* feedFLstUsg
			, Feed* feedFLstUsr
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVADMINDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTPRS, FEEDFLSTUSG, FEEDFLSTUSR, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTPRS) && feedFLstPrs) this->feedFLstPrs = *feedFLstPrs;
	if (find(this->mask, FEEDFLSTUSG) && feedFLstUsg) this->feedFLstUsg = *feedFLstUsg;
	if (find(this->mask, FEEDFLSTUSR) && feedFLstUsr) this->feedFLstUsr = *feedFLstUsr;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskNavAdmin::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTPRS)) ss.push_back("feedFLstPrs");
	if (has(FEEDFLSTUSG)) ss.push_back("feedFLstUsg");
	if (has(FEEDFLSTUSR)) ss.push_back("feedFLstUsr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavAdmin::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTPRS)) {feedFLstPrs = src->feedFLstPrs; add(FEEDFLSTPRS);};
	if (src->has(FEEDFLSTUSG)) {feedFLstUsg = src->feedFLstUsg; add(FEEDFLSTUSG);};
	if (src->has(FEEDFLSTUSR)) {feedFLstUsr = src->feedFLstUsr; add(FEEDFLSTUSR);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskNavAdmin::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskNavAdminData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTPRS)) feedFLstPrs.writeXML(wr);
		if (has(FEEDFLSTUSG)) feedFLstUsg.writeXML(wr);
		if (has(FEEDFLSTUSR)) feedFLstUsr.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

