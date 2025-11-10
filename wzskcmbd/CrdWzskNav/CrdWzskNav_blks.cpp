/**
	* \file CrdWzskNav_blks.cpp
	* job handler for job CrdWzskNav (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzskNav::VecVDo
 ******************************************************************************/

uint CrdWzskNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitsesspsclick") return MITSESSPSCLICK;
	if (s == "mitsestrmclick") return MITSESTRMCLICK;
	if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	if (s == "mitcrdprfclick") return MITCRDPRFCLICK;
	if (s == "mitcrdllvclick") return MITCRDLLVCLICK;
	if (s == "mitcrdvtrclick") return MITCRDVTRCLICK;
	if (s == "mitcrdhwcclick") return MITCRDHWCCLICK;
	if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	if (s == "mitapploiclick") return MITAPPLOICLICK;

	return(0);
};

string CrdWzskNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
	if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	if (ix == MITCRDPRFCLICK) return("MitCrdPrfClick");
	if (ix == MITCRDLLVCLICK) return("MitCrdLlvClick");
	if (ix == MITCRDVTRCLICK) return("MitCrdVtrClick");
	if (ix == MITCRDHWCCLICK) return("MitCrdHwcClick");
	if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdWzskNav::VecVSge
 ******************************************************************************/

uint CrdWzskNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzskabt") return ALRWZSKABT;
	if (s == "alrwzsktrm") return ALRWZSKTRM;

	return(0);
};

string CrdWzskNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZSKABT) return("alrwzskabt");
	if (ix == ALRWZSKTRM) return("alrwzsktrm");

	return("");
};

void CrdWzskNav::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdWzskNav::ContInf
 ******************************************************************************/

CrdWzskNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxSesSes1(MtxSesSes1)
			, MtxSesSes2(MtxSesSes2)
			, MtxSesSes3(MtxSesSes3)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

void CrdWzskNav::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxSesSes1"] = MtxSesSes1;
	me["MtxSesSes2"] = MtxSesSes2;
	me["MtxSesSes3"] = MtxSesSes3;
};

void CrdWzskNav::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskNav";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes1", MtxSesSes1);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes2", MtxSesSes2);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes3", MtxSesSes3);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWzskNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdWzskNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskNav::StatApp
 ******************************************************************************/

void CrdWzskNav::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneAdmin
			, const bool initdoneOp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVReqitmode"] = VecWzskVReqitmode::getSref(ixWzskVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = (Json::Value::UInt) widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneAdmin"] = initdoneAdmin;
	me["initdoneOp"] = initdoneOp;
};

void CrdWzskNav::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzskVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneAdmin
			, const bool initdoneOp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzskNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzskNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVReqitmode", VecWzskVReqitmode::getSref(ixWzskVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAdmin", initdoneAdmin);
		writeBoolAttr(wr, itemtag, "sref", "initdoneOp", initdoneOp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskNav::StatShr
 ******************************************************************************/

CrdWzskNav::StatShr::StatShr(
			const ubigint jrefDlgloaini
			, const ubigint jrefHeadbar
			, const ubigint jrefAdmin
			, const bool pnladminAvail
			, const ubigint jrefOp
			, const bool pnlopAvail
			, const bool MitSesSpsAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdPrfAvail
			, const bool MspCrd2Avail
			, const bool MitCrdLlvAvail
			, const bool MitCrdVtrAvail
			, const bool MitCrdHwcAvail
			, const bool MitCrdFilAvail
			, const bool MspApp2Avail
			, const bool MitAppLoiAvail
		) :
			Block()
			, jrefDlgloaini(jrefDlgloaini)
			, jrefHeadbar(jrefHeadbar)
			, jrefAdmin(jrefAdmin)
			, pnladminAvail(pnladminAvail)
			, jrefOp(jrefOp)
			, pnlopAvail(pnlopAvail)
			, MitSesSpsAvail(MitSesSpsAvail)
			, MspCrd1Avail(MspCrd1Avail)
			, MitCrdUsgAvail(MitCrdUsgAvail)
			, MitCrdUsrAvail(MitCrdUsrAvail)
			, MitCrdPrsAvail(MitCrdPrsAvail)
			, MitCrdPrfAvail(MitCrdPrfAvail)
			, MspCrd2Avail(MspCrd2Avail)
			, MitCrdLlvAvail(MitCrdLlvAvail)
			, MitCrdVtrAvail(MitCrdVtrAvail)
			, MitCrdHwcAvail(MitCrdHwcAvail)
			, MitCrdFilAvail(MitCrdFilAvail)
			, MspApp2Avail(MspApp2Avail)
			, MitAppLoiAvail(MitAppLoiAvail)
		{
	mask = {JREFDLGLOAINI, JREFHEADBAR, JREFADMIN, PNLADMINAVAIL, JREFOP, PNLOPAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDPRFAVAIL, MSPCRD2AVAIL, MITCRDLLVAVAIL, MITCRDVTRAVAIL, MITCRDHWCAVAIL, MITCRDFILAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

void CrdWzskNav::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgloaini"] = Scr::scramble(jrefDlgloaini);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefAdmin"] = Scr::scramble(jrefAdmin);
	me["pnladminAvail"] = pnladminAvail;
	me["scrJrefOp"] = Scr::scramble(jrefOp);
	me["pnlopAvail"] = pnlopAvail;
	me["MitSesSpsAvail"] = MitSesSpsAvail;
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdUsgAvail"] = MitCrdUsgAvail;
	me["MitCrdUsrAvail"] = MitCrdUsrAvail;
	me["MitCrdPrsAvail"] = MitCrdPrsAvail;
	me["MitCrdPrfAvail"] = MitCrdPrfAvail;
	me["MspCrd2Avail"] = MspCrd2Avail;
	me["MitCrdLlvAvail"] = MitCrdLlvAvail;
	me["MitCrdVtrAvail"] = MitCrdVtrAvail;
	me["MitCrdHwcAvail"] = MitCrdHwcAvail;
	me["MitCrdFilAvail"] = MitCrdFilAvail;
	me["MspApp2Avail"] = MspApp2Avail;
	me["MitAppLoiAvail"] = MitAppLoiAvail;
};

void CrdWzskNav::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgloaini", Scr::scramble(jrefDlgloaini));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAdmin", Scr::scramble(jrefAdmin));
		writeBoolAttr(wr, itemtag, "sref", "pnladminAvail", pnladminAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefOp", Scr::scramble(jrefOp));
		writeBoolAttr(wr, itemtag, "sref", "pnlopAvail", pnlopAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitSesSpsAvail", MitSesSpsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsgAvail", MitCrdUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsrAvail", MitCrdUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrsAvail", MitCrdPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrfAvail", MitCrdPrfAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd2Avail", MspCrd2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLlvAvail", MitCrdLlvAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVtrAvail", MitCrdVtrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdHwcAvail", MitCrdHwcAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFilAvail", MitCrdFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspApp2Avail", MspApp2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppLoiAvail", MitAppLoiAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWzskNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgloaini == comp->jrefDlgloaini) insert(items, JREFDLGLOAINI);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefAdmin == comp->jrefAdmin) insert(items, JREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (jrefOp == comp->jrefOp) insert(items, JREFOP);
	if (pnlopAvail == comp->pnlopAvail) insert(items, PNLOPAVAIL);
	if (MitSesSpsAvail == comp->MitSesSpsAvail) insert(items, MITSESSPSAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdPrfAvail == comp->MitCrdPrfAvail) insert(items, MITCRDPRFAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdLlvAvail == comp->MitCrdLlvAvail) insert(items, MITCRDLLVAVAIL);
	if (MitCrdVtrAvail == comp->MitCrdVtrAvail) insert(items, MITCRDVTRAVAIL);
	if (MitCrdHwcAvail == comp->MitCrdHwcAvail) insert(items, MITCRDHWCAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdWzskNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGLOAINI, JREFHEADBAR, JREFADMIN, PNLADMINAVAIL, JREFOP, PNLOPAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDPRFAVAIL, MSPCRD2AVAIL, MITCRDLLVAVAIL, MITCRDVTRAVAIL, MITCRDHWCAVAIL, MITCRDFILAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzskNav::Tag
 ******************************************************************************/

void CrdWzskNav::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["MitCrdUsg"] = "User groups ...";
		me["MitCrdUsr"] = "Users ...";
		me["MitCrdPrs"] = "Persons ...";
		me["MitCrdPrf"] = "Preferences ...";
		me["MitCrdLlv"] = "Low-level access ...";
		me["MitCrdVtr"] = "Vision-to-rotary ...";
		me["MitCrdHwc"] = "HDR wavelet classification ...";
		me["MitCrdFil"] = "Files ...";
	};
	me["MitAppAbt"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::HELP, ixWzskVLocale)) + " ...";
	me["MitSesSps"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::SUSPSESS, ixWzskVLocale));
	me["MitSesTrm"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::CLSESS, ixWzskVLocale));
	me["MitAppLoi"] = StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::LOAINI, ixWzskVLocale)) + " ...";
};

void CrdWzskNav::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskNav";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "User groups ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Persons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrf", "Preferences ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLlv", "Low-level access ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdVtr", "Vision-to-rotary ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdHwc", "HDR wavelet classification ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Files ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::ABOUT, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::HELP, ixWzskVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitSesSps", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::SUSPSESS, ixWzskVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitSesTrm", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::CLSESS, ixWzskVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitAppLoi", StrMod::cap(VecWzskVTag::getTitle(VecWzskVTag::LOAINI, ixWzskVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzskNav::DpchAppDo
 ******************************************************************************/

CrdWzskNav::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVDO)
		{
	ixVDo = 0;
};

string CrdWzskNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskNav::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskNavDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWzskNav::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskNavDo");
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
 class CrdWzskNav::DpchEngData
 ******************************************************************************/

CrdWzskNav::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWzskNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzskNav::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdWzskNav::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskNavData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void CrdWzskNav::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskNavData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
