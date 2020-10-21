/**
	* \file DlgWzskFilDownload_blks.cpp
	* job handler for job DlgWzskFilDownload (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWzskFilDownload::VecVDo
 ******************************************************************************/

uint DlgWzskFilDownload::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWzskFilDownload::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWzskFilDownload::ContInf
 ******************************************************************************/

DlgWzskFilDownload::ContInf::ContInf(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

void DlgWzskFilDownload::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWzskFilDownload";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWzskFilDownload";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWzskFilDownload::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWzskFilDownload::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWzskFilDownload::StatApp
 ******************************************************************************/

void DlgWzskFilDownload::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWzskFilDownload";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWzskFilDownload";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWzskFilDownload::Tag
 ******************************************************************************/

void DlgWzskFilDownload::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWzskFilDownload";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWzskFilDownload";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Download file");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Datei herunterladen");
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::DOWNLOAD, ixWzskVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::DONE, ixWzskVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWzskFilDownload::DpchAppDo
 ******************************************************************************/

DlgWzskFilDownload::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPDLGWZSKFILDOWNLOADDO)
		{
	ixVDo = 0;
};

string DlgWzskFilDownload::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWzskFilDownload::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWzskFilDownloadDo");
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
 class DlgWzskFilDownload::DpchEngData
 ******************************************************************************/

DlgWzskFilDownload::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGDLGWZSKFILDOWNLOADDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
};

string DlgWzskFilDownload::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWzskFilDownload::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(TAG)) add(TAG);
};

void DlgWzskFilDownload::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWzskFilDownloadData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

