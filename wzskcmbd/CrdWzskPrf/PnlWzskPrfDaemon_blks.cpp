/**
	* \file PnlWzskPrfDaemon_blks.cpp
	* job handler for job PnlWzskPrfDaemon (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskPrfDaemon::VecVDo
 ******************************************************************************/

uint PnlWzskPrfDaemon::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWzskPrfDaemon::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskPrfDaemon::ContIac
 ******************************************************************************/

PnlWzskPrfDaemon::ContIac::ContIac(
			const string& Txf2
			, const bool Chk3
			, const string& Txf4
			, const string& Txf5
			, const string& Txf6
			, const string& Txf102
			, const bool Chk103
			, const string& Txf104
			, const string& Txf202
			, const string& Txf203
			, const bool Chk204
			, const bool Chk205
			, const bool Chk206
			, const uint numFPup302
			, const string& Txf303
			, const string& Txf304
			, const string& Txf305
			, const string& Txf306
			, const string& Txf307
			, const string& Txf308
			, const string& Txf402
			, const string& Txf403
			, const string& Txf404
			, const string& Txf405
			, const string& Txf406
			, const string& Txf407
			, const string& Txf502
			, const string& Txf503
			, const string& Txf602
			, const string& Txf603
			, const string& Txf604
			, const string& Txf605
			, const string& Txf606
		) :
			Block()
			, Txf2(Txf2)
			, Chk3(Chk3)
			, Txf4(Txf4)
			, Txf5(Txf5)
			, Txf6(Txf6)
			, Txf102(Txf102)
			, Chk103(Chk103)
			, Txf104(Txf104)
			, Txf202(Txf202)
			, Txf203(Txf203)
			, Chk204(Chk204)
			, Chk205(Chk205)
			, Chk206(Chk206)
			, numFPup302(numFPup302)
			, Txf303(Txf303)
			, Txf304(Txf304)
			, Txf305(Txf305)
			, Txf306(Txf306)
			, Txf307(Txf307)
			, Txf308(Txf308)
			, Txf402(Txf402)
			, Txf403(Txf403)
			, Txf404(Txf404)
			, Txf405(Txf405)
			, Txf406(Txf406)
			, Txf407(Txf407)
			, Txf502(Txf502)
			, Txf503(Txf503)
			, Txf602(Txf602)
			, Txf603(Txf603)
			, Txf604(Txf604)
			, Txf605(Txf605)
			, Txf606(Txf606)
		{
	mask = {TXF2, CHK3, TXF4, TXF5, TXF6, TXF102, CHK103, TXF104, TXF202, TXF203, CHK204, CHK205, CHK206, NUMFPUP302, TXF303, TXF304, TXF305, TXF306, TXF307, TXF308, TXF402, TXF403, TXF404, TXF405, TXF406, TXF407, TXF502, TXF503, TXF602, TXF603, TXF604, TXF605, TXF606};
};

bool PnlWzskPrfDaemon::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzskPrfDaemon"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("Txf2")) {Txf2 = me["Txf2"].asString(); add(TXF2);};
		if (me.isMember("Chk3")) {Chk3 = me["Chk3"].asBool(); add(CHK3);};
		if (me.isMember("Txf4")) {Txf4 = me["Txf4"].asString(); add(TXF4);};
		if (me.isMember("Txf5")) {Txf5 = me["Txf5"].asString(); add(TXF5);};
		if (me.isMember("Txf6")) {Txf6 = me["Txf6"].asString(); add(TXF6);};
		if (me.isMember("Txf102")) {Txf102 = me["Txf102"].asString(); add(TXF102);};
		if (me.isMember("Chk103")) {Chk103 = me["Chk103"].asBool(); add(CHK103);};
		if (me.isMember("Txf104")) {Txf104 = me["Txf104"].asString(); add(TXF104);};
		if (me.isMember("Txf202")) {Txf202 = me["Txf202"].asString(); add(TXF202);};
		if (me.isMember("Txf203")) {Txf203 = me["Txf203"].asString(); add(TXF203);};
		if (me.isMember("Chk204")) {Chk204 = me["Chk204"].asBool(); add(CHK204);};
		if (me.isMember("Chk205")) {Chk205 = me["Chk205"].asBool(); add(CHK205);};
		if (me.isMember("Chk206")) {Chk206 = me["Chk206"].asBool(); add(CHK206);};
		if (me.isMember("numFPup302")) {numFPup302 = me["numFPup302"].asUInt(); add(NUMFPUP302);};
		if (me.isMember("Txf303")) {Txf303 = me["Txf303"].asString(); add(TXF303);};
		if (me.isMember("Txf304")) {Txf304 = me["Txf304"].asString(); add(TXF304);};
		if (me.isMember("Txf305")) {Txf305 = me["Txf305"].asString(); add(TXF305);};
		if (me.isMember("Txf306")) {Txf306 = me["Txf306"].asString(); add(TXF306);};
		if (me.isMember("Txf307")) {Txf307 = me["Txf307"].asString(); add(TXF307);};
		if (me.isMember("Txf308")) {Txf308 = me["Txf308"].asString(); add(TXF308);};
		if (me.isMember("Txf402")) {Txf402 = me["Txf402"].asString(); add(TXF402);};
		if (me.isMember("Txf403")) {Txf403 = me["Txf403"].asString(); add(TXF403);};
		if (me.isMember("Txf404")) {Txf404 = me["Txf404"].asString(); add(TXF404);};
		if (me.isMember("Txf405")) {Txf405 = me["Txf405"].asString(); add(TXF405);};
		if (me.isMember("Txf406")) {Txf406 = me["Txf406"].asString(); add(TXF406);};
		if (me.isMember("Txf407")) {Txf407 = me["Txf407"].asString(); add(TXF407);};
		if (me.isMember("Txf502")) {Txf502 = me["Txf502"].asString(); add(TXF502);};
		if (me.isMember("Txf503")) {Txf503 = me["Txf503"].asString(); add(TXF503);};
		if (me.isMember("Txf602")) {Txf602 = me["Txf602"].asString(); add(TXF602);};
		if (me.isMember("Txf603")) {Txf603 = me["Txf603"].asString(); add(TXF603);};
		if (me.isMember("Txf604")) {Txf604 = me["Txf604"].asString(); add(TXF604);};
		if (me.isMember("Txf605")) {Txf605 = me["Txf605"].asString(); add(TXF605);};
		if (me.isMember("Txf606")) {Txf606 = me["Txf606"].asString(); add(TXF606);};
	};

	return basefound;
};

bool PnlWzskPrfDaemon::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskPrfDaemon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskPrfDaemon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk3", Chk3)) add(CHK3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf4", Txf4)) add(TXF4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf5", Txf5)) add(TXF5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf6", Txf6)) add(TXF6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf102", Txf102)) add(TXF102);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk103", Chk103)) add(CHK103);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf104", Txf104)) add(TXF104);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf202", Txf202)) add(TXF202);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf203", Txf203)) add(TXF203);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk204", Chk204)) add(CHK204);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk205", Chk205)) add(CHK205);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk206", Chk206)) add(CHK206);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPup302", numFPup302)) add(NUMFPUP302);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf303", Txf303)) add(TXF303);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf304", Txf304)) add(TXF304);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf305", Txf305)) add(TXF305);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf306", Txf306)) add(TXF306);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf307", Txf307)) add(TXF307);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf308", Txf308)) add(TXF308);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf402", Txf402)) add(TXF402);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf403", Txf403)) add(TXF403);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf404", Txf404)) add(TXF404);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf405", Txf405)) add(TXF405);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf406", Txf406)) add(TXF406);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf407", Txf407)) add(TXF407);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf502", Txf502)) add(TXF502);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf503", Txf503)) add(TXF503);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf602", Txf602)) add(TXF602);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf603", Txf603)) add(TXF603);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf604", Txf604)) add(TXF604);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf605", Txf605)) add(TXF605);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf606", Txf606)) add(TXF606);
	};

	return basefound;
};

void PnlWzskPrfDaemon::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfDaemon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["Txf2"] = Txf2;
	me["Chk3"] = Chk3;
	me["Txf4"] = Txf4;
	me["Txf5"] = Txf5;
	me["Txf6"] = Txf6;
	me["Txf102"] = Txf102;
	me["Chk103"] = Chk103;
	me["Txf104"] = Txf104;
	me["Txf202"] = Txf202;
	me["Txf203"] = Txf203;
	me["Chk204"] = Chk204;
	me["Chk205"] = Chk205;
	me["Chk206"] = Chk206;
	me["numFPup302"] = (Json::Value::UInt) numFPup302;
	me["Txf303"] = Txf303;
	me["Txf304"] = Txf304;
	me["Txf305"] = Txf305;
	me["Txf306"] = Txf306;
	me["Txf307"] = Txf307;
	me["Txf308"] = Txf308;
	me["Txf402"] = Txf402;
	me["Txf403"] = Txf403;
	me["Txf404"] = Txf404;
	me["Txf405"] = Txf405;
	me["Txf406"] = Txf406;
	me["Txf407"] = Txf407;
	me["Txf502"] = Txf502;
	me["Txf503"] = Txf503;
	me["Txf602"] = Txf602;
	me["Txf603"] = Txf603;
	me["Txf604"] = Txf604;
	me["Txf605"] = Txf605;
	me["Txf606"] = Txf606;
};

void PnlWzskPrfDaemon::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskPrfDaemon";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskPrfDaemon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
		writeBoolAttr(wr, itemtag, "sref", "Chk3", Chk3);
		writeStringAttr(wr, itemtag, "sref", "Txf4", Txf4);
		writeStringAttr(wr, itemtag, "sref", "Txf5", Txf5);
		writeStringAttr(wr, itemtag, "sref", "Txf6", Txf6);
		writeStringAttr(wr, itemtag, "sref", "Txf102", Txf102);
		writeBoolAttr(wr, itemtag, "sref", "Chk103", Chk103);
		writeStringAttr(wr, itemtag, "sref", "Txf104", Txf104);
		writeStringAttr(wr, itemtag, "sref", "Txf202", Txf202);
		writeStringAttr(wr, itemtag, "sref", "Txf203", Txf203);
		writeBoolAttr(wr, itemtag, "sref", "Chk204", Chk204);
		writeBoolAttr(wr, itemtag, "sref", "Chk205", Chk205);
		writeBoolAttr(wr, itemtag, "sref", "Chk206", Chk206);
		writeUintAttr(wr, itemtag, "sref", "numFPup302", numFPup302);
		writeStringAttr(wr, itemtag, "sref", "Txf303", Txf303);
		writeStringAttr(wr, itemtag, "sref", "Txf304", Txf304);
		writeStringAttr(wr, itemtag, "sref", "Txf305", Txf305);
		writeStringAttr(wr, itemtag, "sref", "Txf306", Txf306);
		writeStringAttr(wr, itemtag, "sref", "Txf307", Txf307);
		writeStringAttr(wr, itemtag, "sref", "Txf308", Txf308);
		writeStringAttr(wr, itemtag, "sref", "Txf402", Txf402);
		writeStringAttr(wr, itemtag, "sref", "Txf403", Txf403);
		writeStringAttr(wr, itemtag, "sref", "Txf404", Txf404);
		writeStringAttr(wr, itemtag, "sref", "Txf405", Txf405);
		writeStringAttr(wr, itemtag, "sref", "Txf406", Txf406);
		writeStringAttr(wr, itemtag, "sref", "Txf407", Txf407);
		writeStringAttr(wr, itemtag, "sref", "Txf502", Txf502);
		writeStringAttr(wr, itemtag, "sref", "Txf503", Txf503);
		writeStringAttr(wr, itemtag, "sref", "Txf602", Txf602);
		writeStringAttr(wr, itemtag, "sref", "Txf603", Txf603);
		writeStringAttr(wr, itemtag, "sref", "Txf604", Txf604);
		writeStringAttr(wr, itemtag, "sref", "Txf605", Txf605);
		writeStringAttr(wr, itemtag, "sref", "Txf606", Txf606);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfDaemon::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf2 == comp->Txf2) insert(items, TXF2);
	if (Chk3 == comp->Chk3) insert(items, CHK3);
	if (Txf4 == comp->Txf4) insert(items, TXF4);
	if (Txf5 == comp->Txf5) insert(items, TXF5);
	if (Txf6 == comp->Txf6) insert(items, TXF6);
	if (Txf102 == comp->Txf102) insert(items, TXF102);
	if (Chk103 == comp->Chk103) insert(items, CHK103);
	if (Txf104 == comp->Txf104) insert(items, TXF104);
	if (Txf202 == comp->Txf202) insert(items, TXF202);
	if (Txf203 == comp->Txf203) insert(items, TXF203);
	if (Chk204 == comp->Chk204) insert(items, CHK204);
	if (Chk205 == comp->Chk205) insert(items, CHK205);
	if (Chk206 == comp->Chk206) insert(items, CHK206);
	if (numFPup302 == comp->numFPup302) insert(items, NUMFPUP302);
	if (Txf303 == comp->Txf303) insert(items, TXF303);
	if (Txf304 == comp->Txf304) insert(items, TXF304);
	if (Txf305 == comp->Txf305) insert(items, TXF305);
	if (Txf306 == comp->Txf306) insert(items, TXF306);
	if (Txf307 == comp->Txf307) insert(items, TXF307);
	if (Txf308 == comp->Txf308) insert(items, TXF308);
	if (Txf402 == comp->Txf402) insert(items, TXF402);
	if (Txf403 == comp->Txf403) insert(items, TXF403);
	if (Txf404 == comp->Txf404) insert(items, TXF404);
	if (Txf405 == comp->Txf405) insert(items, TXF405);
	if (Txf406 == comp->Txf406) insert(items, TXF406);
	if (Txf407 == comp->Txf407) insert(items, TXF407);
	if (Txf502 == comp->Txf502) insert(items, TXF502);
	if (Txf503 == comp->Txf503) insert(items, TXF503);
	if (Txf602 == comp->Txf602) insert(items, TXF602);
	if (Txf603 == comp->Txf603) insert(items, TXF603);
	if (Txf604 == comp->Txf604) insert(items, TXF604);
	if (Txf605 == comp->Txf605) insert(items, TXF605);
	if (Txf606 == comp->Txf606) insert(items, TXF606);

	return(items);
};

set<uint> PnlWzskPrfDaemon::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF2, CHK3, TXF4, TXF5, TXF6, TXF102, CHK103, TXF104, TXF202, TXF203, CHK204, CHK205, CHK206, NUMFPUP302, TXF303, TXF304, TXF305, TXF306, TXF307, TXF308, TXF402, TXF403, TXF404, TXF405, TXF406, TXF407, TXF502, TXF503, TXF602, TXF603, TXF604, TXF605, TXF606};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfDaemon::StatShr
 ******************************************************************************/

PnlWzskPrfDaemon::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool Txf2Clean
			, const bool Chk3Clean
			, const bool Txf4Clean
			, const bool Txf5Clean
			, const bool Txf6Clean
			, const bool Txf102Clean
			, const bool Chk103Clean
			, const bool Txf104Clean
			, const bool Sep2Avail
			, const bool Hdg201Avail
			, const bool Txf202Avail
			, const bool Txf202Clean
			, const bool Txf203Avail
			, const bool Txf203Clean
			, const bool Chk204Avail
			, const bool Chk204Clean
			, const bool Chk205Avail
			, const bool Chk205Clean
			, const bool Chk206Avail
			, const bool Chk206Clean
			, const bool Pup302Clean
			, const bool Txf303Clean
			, const bool Txf304Clean
			, const bool Txf305Clean
			, const bool Txf306Clean
			, const bool Txf307Clean
			, const bool Txf308Clean
			, const bool Txf402Clean
			, const bool Txf403Clean
			, const bool Txf404Clean
			, const bool Txf405Clean
			, const bool Txf406Clean
			, const bool Txf407Clean
			, const bool Txf502Clean
			, const bool Txf503Clean
			, const bool Txf602Clean
			, const bool Txf603Clean
			, const bool Txf604Clean
			, const bool Txf605Clean
			, const bool Txf606Clean
		) :
			Block()
			, ixWzskVExpstate(ixWzskVExpstate)
			, Txf2Clean(Txf2Clean)
			, Chk3Clean(Chk3Clean)
			, Txf4Clean(Txf4Clean)
			, Txf5Clean(Txf5Clean)
			, Txf6Clean(Txf6Clean)
			, Txf102Clean(Txf102Clean)
			, Chk103Clean(Chk103Clean)
			, Txf104Clean(Txf104Clean)
			, Sep2Avail(Sep2Avail)
			, Hdg201Avail(Hdg201Avail)
			, Txf202Avail(Txf202Avail)
			, Txf202Clean(Txf202Clean)
			, Txf203Avail(Txf203Avail)
			, Txf203Clean(Txf203Clean)
			, Chk204Avail(Chk204Avail)
			, Chk204Clean(Chk204Clean)
			, Chk205Avail(Chk205Avail)
			, Chk205Clean(Chk205Clean)
			, Chk206Avail(Chk206Avail)
			, Chk206Clean(Chk206Clean)
			, Pup302Clean(Pup302Clean)
			, Txf303Clean(Txf303Clean)
			, Txf304Clean(Txf304Clean)
			, Txf305Clean(Txf305Clean)
			, Txf306Clean(Txf306Clean)
			, Txf307Clean(Txf307Clean)
			, Txf308Clean(Txf308Clean)
			, Txf402Clean(Txf402Clean)
			, Txf403Clean(Txf403Clean)
			, Txf404Clean(Txf404Clean)
			, Txf405Clean(Txf405Clean)
			, Txf406Clean(Txf406Clean)
			, Txf407Clean(Txf407Clean)
			, Txf502Clean(Txf502Clean)
			, Txf503Clean(Txf503Clean)
			, Txf602Clean(Txf602Clean)
			, Txf603Clean(Txf603Clean)
			, Txf604Clean(Txf604Clean)
			, Txf605Clean(Txf605Clean)
			, Txf606Clean(Txf606Clean)
		{
	mask = {IXWZSKVEXPSTATE, TXF2CLEAN, CHK3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF102CLEAN, CHK103CLEAN, TXF104CLEAN, SEP2AVAIL, HDG201AVAIL, TXF202AVAIL, TXF202CLEAN, TXF203AVAIL, TXF203CLEAN, CHK204AVAIL, CHK204CLEAN, CHK205AVAIL, CHK205CLEAN, CHK206AVAIL, CHK206CLEAN, PUP302CLEAN, TXF303CLEAN, TXF304CLEAN, TXF305CLEAN, TXF306CLEAN, TXF307CLEAN, TXF308CLEAN, TXF402CLEAN, TXF403CLEAN, TXF404CLEAN, TXF405CLEAN, TXF406CLEAN, TXF407CLEAN, TXF502CLEAN, TXF503CLEAN, TXF602CLEAN, TXF603CLEAN, TXF604CLEAN, TXF605CLEAN, TXF606CLEAN};
};

void PnlWzskPrfDaemon::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrfDaemon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzskVExpstate"] = VecWzskVExpstate::getSref(ixWzskVExpstate);
	me["Txf2Clean"] = Txf2Clean;
	me["Chk3Clean"] = Chk3Clean;
	me["Txf4Clean"] = Txf4Clean;
	me["Txf5Clean"] = Txf5Clean;
	me["Txf6Clean"] = Txf6Clean;
	me["Txf102Clean"] = Txf102Clean;
	me["Chk103Clean"] = Chk103Clean;
	me["Txf104Clean"] = Txf104Clean;
	me["Sep2Avail"] = Sep2Avail;
	me["Hdg201Avail"] = Hdg201Avail;
	me["Txf202Avail"] = Txf202Avail;
	me["Txf202Clean"] = Txf202Clean;
	me["Txf203Avail"] = Txf203Avail;
	me["Txf203Clean"] = Txf203Clean;
	me["Chk204Avail"] = Chk204Avail;
	me["Chk204Clean"] = Chk204Clean;
	me["Chk205Avail"] = Chk205Avail;
	me["Chk205Clean"] = Chk205Clean;
	me["Chk206Avail"] = Chk206Avail;
	me["Chk206Clean"] = Chk206Clean;
	me["Pup302Clean"] = Pup302Clean;
	me["Txf303Clean"] = Txf303Clean;
	me["Txf304Clean"] = Txf304Clean;
	me["Txf305Clean"] = Txf305Clean;
	me["Txf306Clean"] = Txf306Clean;
	me["Txf307Clean"] = Txf307Clean;
	me["Txf308Clean"] = Txf308Clean;
	me["Txf402Clean"] = Txf402Clean;
	me["Txf403Clean"] = Txf403Clean;
	me["Txf404Clean"] = Txf404Clean;
	me["Txf405Clean"] = Txf405Clean;
	me["Txf406Clean"] = Txf406Clean;
	me["Txf407Clean"] = Txf407Clean;
	me["Txf502Clean"] = Txf502Clean;
	me["Txf503Clean"] = Txf503Clean;
	me["Txf602Clean"] = Txf602Clean;
	me["Txf603Clean"] = Txf603Clean;
	me["Txf604Clean"] = Txf604Clean;
	me["Txf605Clean"] = Txf605Clean;
	me["Txf606Clean"] = Txf606Clean;
};

void PnlWzskPrfDaemon::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskPrfDaemon";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskPrfDaemon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "Txf2Clean", Txf2Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk3Clean", Chk3Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf4Clean", Txf4Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf5Clean", Txf5Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf6Clean", Txf6Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf102Clean", Txf102Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk103Clean", Chk103Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf104Clean", Txf104Clean);
		writeBoolAttr(wr, itemtag, "sref", "Sep2Avail", Sep2Avail);
		writeBoolAttr(wr, itemtag, "sref", "Hdg201Avail", Hdg201Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf202Avail", Txf202Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf202Clean", Txf202Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf203Avail", Txf203Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf203Clean", Txf203Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk204Avail", Chk204Avail);
		writeBoolAttr(wr, itemtag, "sref", "Chk204Clean", Chk204Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk205Avail", Chk205Avail);
		writeBoolAttr(wr, itemtag, "sref", "Chk205Clean", Chk205Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk206Avail", Chk206Avail);
		writeBoolAttr(wr, itemtag, "sref", "Chk206Clean", Chk206Clean);
		writeBoolAttr(wr, itemtag, "sref", "Pup302Clean", Pup302Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf303Clean", Txf303Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf304Clean", Txf304Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf305Clean", Txf305Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf306Clean", Txf306Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf307Clean", Txf307Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf308Clean", Txf308Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf402Clean", Txf402Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf403Clean", Txf403Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf404Clean", Txf404Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf405Clean", Txf405Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf406Clean", Txf406Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf407Clean", Txf407Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf502Clean", Txf502Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf503Clean", Txf503Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf602Clean", Txf602Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf603Clean", Txf603Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf604Clean", Txf604Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf605Clean", Txf605Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf606Clean", Txf606Clean);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskPrfDaemon::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);
	if (Chk3Clean == comp->Chk3Clean) insert(items, CHK3CLEAN);
	if (Txf4Clean == comp->Txf4Clean) insert(items, TXF4CLEAN);
	if (Txf5Clean == comp->Txf5Clean) insert(items, TXF5CLEAN);
	if (Txf6Clean == comp->Txf6Clean) insert(items, TXF6CLEAN);
	if (Txf102Clean == comp->Txf102Clean) insert(items, TXF102CLEAN);
	if (Chk103Clean == comp->Chk103Clean) insert(items, CHK103CLEAN);
	if (Txf104Clean == comp->Txf104Clean) insert(items, TXF104CLEAN);
	if (Sep2Avail == comp->Sep2Avail) insert(items, SEP2AVAIL);
	if (Hdg201Avail == comp->Hdg201Avail) insert(items, HDG201AVAIL);
	if (Txf202Avail == comp->Txf202Avail) insert(items, TXF202AVAIL);
	if (Txf202Clean == comp->Txf202Clean) insert(items, TXF202CLEAN);
	if (Txf203Avail == comp->Txf203Avail) insert(items, TXF203AVAIL);
	if (Txf203Clean == comp->Txf203Clean) insert(items, TXF203CLEAN);
	if (Chk204Avail == comp->Chk204Avail) insert(items, CHK204AVAIL);
	if (Chk204Clean == comp->Chk204Clean) insert(items, CHK204CLEAN);
	if (Chk205Avail == comp->Chk205Avail) insert(items, CHK205AVAIL);
	if (Chk205Clean == comp->Chk205Clean) insert(items, CHK205CLEAN);
	if (Chk206Avail == comp->Chk206Avail) insert(items, CHK206AVAIL);
	if (Chk206Clean == comp->Chk206Clean) insert(items, CHK206CLEAN);
	if (Pup302Clean == comp->Pup302Clean) insert(items, PUP302CLEAN);
	if (Txf303Clean == comp->Txf303Clean) insert(items, TXF303CLEAN);
	if (Txf304Clean == comp->Txf304Clean) insert(items, TXF304CLEAN);
	if (Txf305Clean == comp->Txf305Clean) insert(items, TXF305CLEAN);
	if (Txf306Clean == comp->Txf306Clean) insert(items, TXF306CLEAN);
	if (Txf307Clean == comp->Txf307Clean) insert(items, TXF307CLEAN);
	if (Txf308Clean == comp->Txf308Clean) insert(items, TXF308CLEAN);
	if (Txf402Clean == comp->Txf402Clean) insert(items, TXF402CLEAN);
	if (Txf403Clean == comp->Txf403Clean) insert(items, TXF403CLEAN);
	if (Txf404Clean == comp->Txf404Clean) insert(items, TXF404CLEAN);
	if (Txf405Clean == comp->Txf405Clean) insert(items, TXF405CLEAN);
	if (Txf406Clean == comp->Txf406Clean) insert(items, TXF406CLEAN);
	if (Txf407Clean == comp->Txf407Clean) insert(items, TXF407CLEAN);
	if (Txf502Clean == comp->Txf502Clean) insert(items, TXF502CLEAN);
	if (Txf503Clean == comp->Txf503Clean) insert(items, TXF503CLEAN);
	if (Txf602Clean == comp->Txf602Clean) insert(items, TXF602CLEAN);
	if (Txf603Clean == comp->Txf603Clean) insert(items, TXF603CLEAN);
	if (Txf604Clean == comp->Txf604Clean) insert(items, TXF604CLEAN);
	if (Txf605Clean == comp->Txf605Clean) insert(items, TXF605CLEAN);
	if (Txf606Clean == comp->Txf606Clean) insert(items, TXF606CLEAN);

	return(items);
};

set<uint> PnlWzskPrfDaemon::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, TXF2CLEAN, CHK3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF102CLEAN, CHK103CLEAN, TXF104CLEAN, SEP2AVAIL, HDG201AVAIL, TXF202AVAIL, TXF202CLEAN, TXF203AVAIL, TXF203CLEAN, CHK204AVAIL, CHK204CLEAN, CHK205AVAIL, CHK205CLEAN, CHK206AVAIL, CHK206CLEAN, PUP302CLEAN, TXF303CLEAN, TXF304CLEAN, TXF305CLEAN, TXF306CLEAN, TXF307CLEAN, TXF308CLEAN, TXF402CLEAN, TXF403CLEAN, TXF404CLEAN, TXF405CLEAN, TXF406CLEAN, TXF407CLEAN, TXF502CLEAN, TXF503CLEAN, TXF602CLEAN, TXF603CLEAN, TXF604CLEAN, TXF605CLEAN, TXF606CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskPrfDaemon::Tag
 ******************************************************************************/

void PnlWzskPrfDaemon::Tag::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrfDaemon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzskVLocale == VecWzskVLocale::ENUS) {
		me["Cpt"] = "Daemon settings";
		me["Hdg1"] = "Behavior";
		me["Cpt2"] = "histlength";
		me["Cpt3"] = "suspsess";
		me["Cpt4"] = "sesstterm";
		me["Cpt5"] = "sesstwarn";
		me["Cpt6"] = "roottterm";
		me["Hdg101"] = "Application server";
		me["Cpt102"] = "port";
		me["Cpt103"] = "https";
		me["Cpt104"] = "cors";
		me["Hdg201"] = "Combined daemon";
		me["Cpt202"] = "jobprcn";
		me["Cpt203"] = "opprcn";
		me["Cpt204"] = "appsrv";
		me["Cpt205"] = "ddspub";
		me["Cpt206"] = "uasrv";
		me["Hdg301"] = "Database";
		me["Cpt302"] = "ixDbsVDbstype";
		me["Cpt303"] = "dbspath";
		me["Cpt304"] = "dbsname";
		me["Cpt305"] = "username";
		me["Cpt306"] = "password";
		me["Cpt307"] = "ip";
		me["Cpt308"] = "port";
		me["Hdg401"] = "Paths";
		me["Cpt402"] = "acvpath";
		me["Cpt403"] = "keypath";
		me["Cpt404"] = "monpath";
		me["Cpt405"] = "tmppath";
		me["Cpt406"] = "webpath";
		me["Cpt407"] = "helpurl";
		me["Hdg501"] = "DDS publisher";
		me["Cpt502"] = "username";
		me["Cpt503"] = "password";
		me["Hdg601"] = "OPC UA server";
		me["Cpt602"] = "profile";
		me["Cpt603"] = "port";
		me["Cpt604"] = "cycle";
		me["Cpt605"] = "maxbrowse";
		me["Cpt606"] = "maxmon";
	};
};

void PnlWzskPrfDaemon::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskPrfDaemon";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskPrfDaemon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Daemon settings");
			writeStringAttr(wr, itemtag, "sref", "Hdg1", "Behavior");
			writeStringAttr(wr, itemtag, "sref", "Cpt2", "histlength");
			writeStringAttr(wr, itemtag, "sref", "Cpt3", "suspsess");
			writeStringAttr(wr, itemtag, "sref", "Cpt4", "sesstterm");
			writeStringAttr(wr, itemtag, "sref", "Cpt5", "sesstwarn");
			writeStringAttr(wr, itemtag, "sref", "Cpt6", "roottterm");
			writeStringAttr(wr, itemtag, "sref", "Hdg101", "Application server");
			writeStringAttr(wr, itemtag, "sref", "Cpt102", "port");
			writeStringAttr(wr, itemtag, "sref", "Cpt103", "https");
			writeStringAttr(wr, itemtag, "sref", "Cpt104", "cors");
			writeStringAttr(wr, itemtag, "sref", "Hdg201", "Combined daemon");
			writeStringAttr(wr, itemtag, "sref", "Cpt202", "jobprcn");
			writeStringAttr(wr, itemtag, "sref", "Cpt203", "opprcn");
			writeStringAttr(wr, itemtag, "sref", "Cpt204", "appsrv");
			writeStringAttr(wr, itemtag, "sref", "Cpt205", "ddspub");
			writeStringAttr(wr, itemtag, "sref", "Cpt206", "uasrv");
			writeStringAttr(wr, itemtag, "sref", "Hdg301", "Database");
			writeStringAttr(wr, itemtag, "sref", "Cpt302", "ixDbsVDbstype");
			writeStringAttr(wr, itemtag, "sref", "Cpt303", "dbspath");
			writeStringAttr(wr, itemtag, "sref", "Cpt304", "dbsname");
			writeStringAttr(wr, itemtag, "sref", "Cpt305", "username");
			writeStringAttr(wr, itemtag, "sref", "Cpt306", "password");
			writeStringAttr(wr, itemtag, "sref", "Cpt307", "ip");
			writeStringAttr(wr, itemtag, "sref", "Cpt308", "port");
			writeStringAttr(wr, itemtag, "sref", "Hdg401", "Paths");
			writeStringAttr(wr, itemtag, "sref", "Cpt402", "acvpath");
			writeStringAttr(wr, itemtag, "sref", "Cpt403", "keypath");
			writeStringAttr(wr, itemtag, "sref", "Cpt404", "monpath");
			writeStringAttr(wr, itemtag, "sref", "Cpt405", "tmppath");
			writeStringAttr(wr, itemtag, "sref", "Cpt406", "webpath");
			writeStringAttr(wr, itemtag, "sref", "Cpt407", "helpurl");
			writeStringAttr(wr, itemtag, "sref", "Hdg501", "DDS publisher");
			writeStringAttr(wr, itemtag, "sref", "Cpt502", "username");
			writeStringAttr(wr, itemtag, "sref", "Cpt503", "password");
			writeStringAttr(wr, itemtag, "sref", "Hdg601", "OPC UA server");
			writeStringAttr(wr, itemtag, "sref", "Cpt602", "profile");
			writeStringAttr(wr, itemtag, "sref", "Cpt603", "port");
			writeStringAttr(wr, itemtag, "sref", "Cpt604", "cycle");
			writeStringAttr(wr, itemtag, "sref", "Cpt605", "maxbrowse");
			writeStringAttr(wr, itemtag, "sref", "Cpt606", "maxmon");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfDaemon::DpchAppData
 ******************************************************************************/

PnlWzskPrfDaemon::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFDAEMONDATA)
		{
};

string PnlWzskPrfDaemon::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfDaemon::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskPrfDaemonData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzskPrfDaemon::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrfDaemonData");
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
 class PnlWzskPrfDaemon::DpchAppDo
 ******************************************************************************/

PnlWzskPrfDaemon::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFDAEMONDO)
		{
	ixVDo = 0;
};

string PnlWzskPrfDaemon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfDaemon::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzskPrfDaemonDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzskPrfDaemon::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskPrfDaemonDo");
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
 class PnlWzskPrfDaemon::DpchEngData
 ******************************************************************************/

PnlWzskPrfDaemon::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFPup302
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFDAEMONDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFPUP302, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFPUP302) && feedFPup302) this->feedFPup302 = *feedFPup302;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskPrfDaemon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFPUP302)) ss.push_back("feedFPup302");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfDaemon::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFPUP302)) {feedFPup302 = src->feedFPup302; add(FEEDFPUP302);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskPrfDaemon::DpchEngData::writeJSON(
			const uint ixWzskVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzskPrfDaemonData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFPUP302)) feedFPup302.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzskVLocale, me);
};

void PnlWzskPrfDaemon::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskPrfDaemonData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFPUP302)) feedFPup302.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};
