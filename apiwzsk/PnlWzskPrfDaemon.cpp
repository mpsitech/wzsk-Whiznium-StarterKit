/**
	* \file PnlWzskPrfDaemon.cpp
	* API code for job PnlWzskPrfDaemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskPrfDaemon.h"

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

bool PnlWzskPrfDaemon::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskPrfDaemon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskPrfDaemon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf2Clean", Txf2Clean)) add(TXF2CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk3Clean", Chk3Clean)) add(CHK3CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf4Clean", Txf4Clean)) add(TXF4CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf5Clean", Txf5Clean)) add(TXF5CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf6Clean", Txf6Clean)) add(TXF6CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf102Clean", Txf102Clean)) add(TXF102CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk103Clean", Chk103Clean)) add(CHK103CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf104Clean", Txf104Clean)) add(TXF104CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Sep2Avail", Sep2Avail)) add(SEP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Hdg201Avail", Hdg201Avail)) add(HDG201AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf202Avail", Txf202Avail)) add(TXF202AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf202Clean", Txf202Clean)) add(TXF202CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf203Avail", Txf203Avail)) add(TXF203AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf203Clean", Txf203Clean)) add(TXF203CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk204Avail", Chk204Avail)) add(CHK204AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk204Clean", Chk204Clean)) add(CHK204CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk205Avail", Chk205Avail)) add(CHK205AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk205Clean", Chk205Clean)) add(CHK205CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk206Avail", Chk206Avail)) add(CHK206AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk206Clean", Chk206Clean)) add(CHK206CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Pup302Clean", Pup302Clean)) add(PUP302CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf303Clean", Txf303Clean)) add(TXF303CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf304Clean", Txf304Clean)) add(TXF304CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf305Clean", Txf305Clean)) add(TXF305CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf306Clean", Txf306Clean)) add(TXF306CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf307Clean", Txf307Clean)) add(TXF307CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf308Clean", Txf308Clean)) add(TXF308CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf402Clean", Txf402Clean)) add(TXF402CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf403Clean", Txf403Clean)) add(TXF403CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf404Clean", Txf404Clean)) add(TXF404CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf405Clean", Txf405Clean)) add(TXF405CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf406Clean", Txf406Clean)) add(TXF406CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf407Clean", Txf407Clean)) add(TXF407CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf502Clean", Txf502Clean)) add(TXF502CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf503Clean", Txf503Clean)) add(TXF503CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf602Clean", Txf602Clean)) add(TXF602CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf603Clean", Txf603Clean)) add(TXF603CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf604Clean", Txf604Clean)) add(TXF604CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf605Clean", Txf605Clean)) add(TXF605CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf606Clean", Txf606Clean)) add(TXF606CLEAN);
	};

	return basefound;
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

PnlWzskPrfDaemon::Tag::Tag(
			const string& Cpt
			, const string& Hdg1
			, const string& Cpt2
			, const string& Cpt3
			, const string& Cpt4
			, const string& Cpt5
			, const string& Cpt6
			, const string& Hdg101
			, const string& Cpt102
			, const string& Cpt103
			, const string& Cpt104
			, const string& Hdg201
			, const string& Cpt202
			, const string& Cpt203
			, const string& Cpt204
			, const string& Cpt205
			, const string& Cpt206
			, const string& Hdg301
			, const string& Cpt302
			, const string& Cpt303
			, const string& Cpt304
			, const string& Cpt305
			, const string& Cpt306
			, const string& Cpt307
			, const string& Cpt308
			, const string& Hdg401
			, const string& Cpt402
			, const string& Cpt403
			, const string& Cpt404
			, const string& Cpt405
			, const string& Cpt406
			, const string& Cpt407
			, const string& Hdg501
			, const string& Cpt502
			, const string& Cpt503
			, const string& Hdg601
			, const string& Cpt602
			, const string& Cpt603
			, const string& Cpt604
			, const string& Cpt605
			, const string& Cpt606
		) :
			Block()
			, Cpt(Cpt)
			, Hdg1(Hdg1)
			, Cpt2(Cpt2)
			, Cpt3(Cpt3)
			, Cpt4(Cpt4)
			, Cpt5(Cpt5)
			, Cpt6(Cpt6)
			, Hdg101(Hdg101)
			, Cpt102(Cpt102)
			, Cpt103(Cpt103)
			, Cpt104(Cpt104)
			, Hdg201(Hdg201)
			, Cpt202(Cpt202)
			, Cpt203(Cpt203)
			, Cpt204(Cpt204)
			, Cpt205(Cpt205)
			, Cpt206(Cpt206)
			, Hdg301(Hdg301)
			, Cpt302(Cpt302)
			, Cpt303(Cpt303)
			, Cpt304(Cpt304)
			, Cpt305(Cpt305)
			, Cpt306(Cpt306)
			, Cpt307(Cpt307)
			, Cpt308(Cpt308)
			, Hdg401(Hdg401)
			, Cpt402(Cpt402)
			, Cpt403(Cpt403)
			, Cpt404(Cpt404)
			, Cpt405(Cpt405)
			, Cpt406(Cpt406)
			, Cpt407(Cpt407)
			, Hdg501(Hdg501)
			, Cpt502(Cpt502)
			, Cpt503(Cpt503)
			, Hdg601(Hdg601)
			, Cpt602(Cpt602)
			, Cpt603(Cpt603)
			, Cpt604(Cpt604)
			, Cpt605(Cpt605)
			, Cpt606(Cpt606)
		{
	mask = {CPT, HDG1, CPT2, CPT3, CPT4, CPT5, CPT6, HDG101, CPT102, CPT103, CPT104, HDG201, CPT202, CPT203, CPT204, CPT205, CPT206, HDG301, CPT302, CPT303, CPT304, CPT305, CPT306, CPT307, CPT308, HDG401, CPT402, CPT403, CPT404, CPT405, CPT406, CPT407, HDG501, CPT502, CPT503, HDG601, CPT602, CPT603, CPT604, CPT605, CPT606};
};

bool PnlWzskPrfDaemon::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskPrfDaemon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskPrfDaemon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg1", Hdg1)) add(HDG1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt2", Cpt2)) add(CPT2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt3", Cpt3)) add(CPT3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt4", Cpt4)) add(CPT4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt5", Cpt5)) add(CPT5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt6", Cpt6)) add(CPT6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg101", Hdg101)) add(HDG101);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt102", Cpt102)) add(CPT102);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt103", Cpt103)) add(CPT103);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt104", Cpt104)) add(CPT104);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg201", Hdg201)) add(HDG201);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt202", Cpt202)) add(CPT202);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt203", Cpt203)) add(CPT203);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt204", Cpt204)) add(CPT204);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt205", Cpt205)) add(CPT205);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt206", Cpt206)) add(CPT206);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg301", Hdg301)) add(HDG301);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt302", Cpt302)) add(CPT302);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt303", Cpt303)) add(CPT303);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt304", Cpt304)) add(CPT304);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt305", Cpt305)) add(CPT305);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt306", Cpt306)) add(CPT306);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt307", Cpt307)) add(CPT307);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt308", Cpt308)) add(CPT308);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg401", Hdg401)) add(HDG401);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt402", Cpt402)) add(CPT402);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt403", Cpt403)) add(CPT403);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt404", Cpt404)) add(CPT404);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt405", Cpt405)) add(CPT405);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt406", Cpt406)) add(CPT406);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt407", Cpt407)) add(CPT407);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg501", Hdg501)) add(HDG501);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt502", Cpt502)) add(CPT502);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt503", Cpt503)) add(CPT503);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg601", Hdg601)) add(HDG601);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt602", Cpt602)) add(CPT602);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt603", Cpt603)) add(CPT603);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt604", Cpt604)) add(CPT604);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt605", Cpt605)) add(CPT605);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt606", Cpt606)) add(CPT606);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskPrfDaemon::DpchAppData
 ******************************************************************************/

PnlWzskPrfDaemon::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFDAEMONDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskPrfDaemon::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfDaemon::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfDaemonData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfDaemon::DpchAppDo
 ******************************************************************************/

PnlWzskPrfDaemon::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKPRFDAEMONDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWzskPrfDaemon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfDaemon::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskPrfDaemonDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskPrfDaemon::DpchEngData
 ******************************************************************************/

PnlWzskPrfDaemon::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKPRFDAEMONDATA)
		{
	feedFPup302.tag = "FeedFPup302";
};

string PnlWzskPrfDaemon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFPUP302)) ss.push_back("feedFPup302");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskPrfDaemon::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskPrfDaemonData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFPup302.readXML(docctx, basexpath, true)) add(FEEDFPUP302);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFPup302.clear();
		statshr = StatShr();
		tag = Tag();
	};
};
