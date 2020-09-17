/**
	* \file PnlWzskLivSysmon_blks.cpp
	* job handler for job PnlWzskLivSysmon (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

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

void PnlWzskLivSysmon::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLivSysmon";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskLivSysmon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCtp", TxtCtp);
	xmlTextWriterEndElement(wr);
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

void PnlWzskLivSysmon::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLivSysmon";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskLivSysmon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
	xmlTextWriterEndElement(wr);
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

void PnlWzskLivSysmon::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskLivSysmon";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskLivSysmon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "System monitor");
			writeStringAttr(wr, itemtag, "sref", "CptCtp", "CPU temperature [\\u00b0C]");
			writeStringAttr(wr, itemtag, "sref", "CptPltTme", "time [s]");
			writeStringAttr(wr, itemtag, "sref", "CptPltCld", "CPU load [\\u0025]");
			writeStringAttr(wr, itemtag, "sref", "CptPltTot", "total");
			writeStringAttr(wr, itemtag, "sref", "CptPltCor", "core");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "System\\u00fcberwachung");
			writeStringAttr(wr, itemtag, "sref", "CptCtp", "CPU-Temperatur [\\u00b0C]");
			writeStringAttr(wr, itemtag, "sref", "CptPltTme", "Zeit [s]");
			writeStringAttr(wr, itemtag, "sref", "CptPltCld", "CPU-Last [\\u0025]");
			writeStringAttr(wr, itemtag, "sref", "CptPltTot", "gesamt");
			writeStringAttr(wr, itemtag, "sref", "CptPltCor", "Kern");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLivSysmon::DpchAppDo
 ******************************************************************************/

PnlWzskLivSysmon::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIVSYSMONDO)
		{
	ixVDo = 0;
};

string PnlWzskLivSysmon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLivSysmon::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLivSysmonDo");
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
 class PnlWzskLivSysmon::DpchEngData
 ******************************************************************************/

PnlWzskLivSysmon::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIVSYSMONDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskLivSysmon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLivSysmon::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskLivSysmon::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLivSysmonData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLivSysmon::DpchEngLive
 ******************************************************************************/

PnlWzskLivSysmon::DpchEngLive::DpchEngLive(
			const ubigint jref
			, const vector<float>& ts
			, const vector<float>& cldtots
			, const vector<float>& cld1s
			, const vector<float>& cld2s
			, const vector<float>& cld3s
			, const vector<float>& cld4s
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIVSYSMONLIVE, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, TS, CLDTOTS, CLD1S, CLD2S, CLD3S, CLD4S};
	else this->mask = mask;

	this->ts = ts;
	this->cldtots = cldtots;
	this->cld1s = cld1s;
	this->cld2s = cld2s;
	this->cld3s = cld3s;
	this->cld4s = cld4s;
};

string PnlWzskLivSysmon::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(TS)) ss.push_back("ts");
	if (has(CLDTOTS)) ss.push_back("cldtots");
	if (has(CLD1S)) ss.push_back("cld1s");
	if (has(CLD2S)) ss.push_back("cld2s");
	if (has(CLD3S)) ss.push_back("cld3s");
	if (has(CLD4S)) ss.push_back("cld4s");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLivSysmon::DpchEngLive::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(TS)) {ts = src->ts; add(TS);};
	if (src->has(CLDTOTS)) {cldtots = src->cldtots; add(CLDTOTS);};
	if (src->has(CLD1S)) {cld1s = src->cld1s; add(CLD1S);};
	if (src->has(CLD2S)) {cld2s = src->cld2s; add(CLD2S);};
	if (src->has(CLD3S)) {cld3s = src->cld3s; add(CLD3S);};
	if (src->has(CLD4S)) {cld4s = src->cld4s; add(CLD4S);};
};

void PnlWzskLivSysmon::DpchEngLive::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLivSysmonLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(TS)) writeFloatvec(wr, "ts", ts);
		if (has(CLDTOTS)) writeFloatvec(wr, "cldtots", cldtots);
		if (has(CLD1S)) writeFloatvec(wr, "cld1s", cld1s);
		if (has(CLD2S)) writeFloatvec(wr, "cld2s", cld2s);
		if (has(CLD3S)) writeFloatvec(wr, "cld3s", cld3s);
		if (has(CLD4S)) writeFloatvec(wr, "cld4s", cld4s);
	xmlTextWriterEndElement(wr);
};

