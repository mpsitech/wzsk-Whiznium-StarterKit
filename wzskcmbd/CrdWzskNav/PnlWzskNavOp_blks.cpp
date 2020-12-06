/**
	* \file PnlWzskNavOp_blks.cpp
	* job handler for job PnlWzskNavOp (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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
	if (s == "butlivnewcrdclick") return BUTLIVNEWCRDCLICK;

	return(0);
};

string PnlWzskNavOp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTLLVNEWCRDCLICK) return("ButLlvNewcrdClick");
	if (ix == BUTLIVNEWCRDCLICK) return("ButLivNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzskNavOp::StatApp
 ******************************************************************************/

void PnlWzskNavOp::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskNavOp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskNavOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavOp::StatShr
 ******************************************************************************/

PnlWzskNavOp::StatShr::StatShr(
			const bool ButLlvNewcrdAvail
			, const bool ButLivNewcrdAvail
		) :
			Block()
		{
	this->ButLlvNewcrdAvail = ButLlvNewcrdAvail;
	this->ButLivNewcrdAvail = ButLivNewcrdAvail;

	mask = {BUTLLVNEWCRDAVAIL, BUTLIVNEWCRDAVAIL};
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
		writeBoolAttr(wr, itemtag, "sref", "ButLivNewcrdAvail", ButLivNewcrdAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskNavOp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButLlvNewcrdAvail == comp->ButLlvNewcrdAvail) insert(items, BUTLLVNEWCRDAVAIL);
	if (ButLivNewcrdAvail == comp->ButLivNewcrdAvail) insert(items, BUTLIVNEWCRDAVAIL);

	return(items);
};

set<uint> PnlWzskNavOp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTLLVNEWCRDAVAIL, BUTLIVNEWCRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavOp::Tag
 ******************************************************************************/

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
			writeStringAttr(wr, itemtag, "sref", "CptLiv", "live data");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Betrieb");
			writeStringAttr(wr, itemtag, "sref", "CptLlv", "Low-level Zugriff");
			writeStringAttr(wr, itemtag, "sref", "CptLiv", "Livedaten");
		};
	xmlTextWriterEndElement(wr);
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
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVOPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskNavOp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskNavOp::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskNavOpData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
