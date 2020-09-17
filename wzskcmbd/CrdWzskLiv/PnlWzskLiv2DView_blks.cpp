/**
	* \file PnlWzskLiv2DView_blks.cpp
	* job handler for job PnlWzskLiv2DView (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLiv2DView::VecVDo
 ******************************************************************************/

uint PnlWzskLiv2DView::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butclaimclick") return BUTCLAIMCLICK;
	if (s == "butplayclick") return BUTPLAYCLICK;
	if (s == "butstopclick") return BUTSTOPCLICK;
	if (s == "butstsclick") return BUTSTSCLICK;
	if (s == "buttccclick") return BUTTCCCLICK;
	if (s == "buttcwclick") return BUTTCWCLICK;
	if (s == "butlleclick") return BUTLLECLICK;
	if (s == "butlriclick") return BUTLRICLICK;
	if (s == "butltrclick") return BUTLTRCLICK;
	if (s == "butpicclick") return BUTPICCLICK;

	return(0);
};

string PnlWzskLiv2DView::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTCLAIMCLICK) return("ButClaimClick");
	if (ix == BUTPLAYCLICK) return("ButPlayClick");
	if (ix == BUTSTOPCLICK) return("ButStopClick");
	if (ix == BUTSTSCLICK) return("ButStsClick");
	if (ix == BUTTCCCLICK) return("ButTccClick");
	if (ix == BUTTCWCLICK) return("ButTcwClick");
	if (ix == BUTLLECLICK) return("ButLleClick");
	if (ix == BUTLRICLICK) return("ButLriClick");
	if (ix == BUTLTRCLICK) return("ButLtrClick");
	if (ix == BUTPICCLICK) return("ButPicClick");

	return("");
};

/******************************************************************************
 class PnlWzskLiv2DView::ContIac
 ******************************************************************************/

PnlWzskLiv2DView::ContIac::ContIac(
			const uint numFPupPvm
			, const bool ChkAex
			, const double SldExt
			, const double SldFcs
			, const int UpdLlo
			, const int UpdLuo
			, const int UpdLmd
			, const bool ChkLro
			, const int UpdPnt
			, const bool ChkPro
		) :
			Block()
		{
	this->numFPupPvm = numFPupPvm;
	this->ChkAex = ChkAex;
	this->SldExt = SldExt;
	this->SldFcs = SldFcs;
	this->UpdLlo = UpdLlo;
	this->UpdLuo = UpdLuo;
	this->UpdLmd = UpdLmd;
	this->ChkLro = ChkLro;
	this->UpdPnt = UpdPnt;
	this->ChkPro = ChkPro;

	mask = {NUMFPUPPVM, CHKAEX, SLDEXT, SLDFCS, UPDLLO, UPDLUO, UPDLMD, CHKLRO, UPDPNT, CHKPRO};
};

bool PnlWzskLiv2DView::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLiv2DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLiv2DView";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPvm", numFPupPvm)) add(NUMFPUPPVM);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkAex", ChkAex)) add(CHKAEX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldExt", SldExt)) add(SLDEXT);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFcs", SldFcs)) add(SLDFCS);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdLlo", UpdLlo)) add(UPDLLO);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdLuo", UpdLuo)) add(UPDLUO);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdLmd", UpdLmd)) add(UPDLMD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkLro", ChkLro)) add(CHKLRO);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdPnt", UpdPnt)) add(UPDPNT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkPro", ChkPro)) add(CHKPRO);
	};

	return basefound;
};

void PnlWzskLiv2DView::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLiv2DView";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLiv2DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupPvm", numFPupPvm);
		writeBoolAttr(wr, itemtag, "sref", "ChkAex", ChkAex);
		writeDoubleAttr(wr, itemtag, "sref", "SldExt", SldExt);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcs", SldFcs);
		writeIntAttr(wr, itemtag, "sref", "UpdLlo", UpdLlo);
		writeIntAttr(wr, itemtag, "sref", "UpdLuo", UpdLuo);
		writeIntAttr(wr, itemtag, "sref", "UpdLmd", UpdLmd);
		writeBoolAttr(wr, itemtag, "sref", "ChkLro", ChkLro);
		writeIntAttr(wr, itemtag, "sref", "UpdPnt", UpdPnt);
		writeBoolAttr(wr, itemtag, "sref", "ChkPro", ChkPro);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLiv2DView::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupPvm == comp->numFPupPvm) insert(items, NUMFPUPPVM);
	if (ChkAex == comp->ChkAex) insert(items, CHKAEX);
	if (compareDouble(SldExt, comp->SldExt) < 1.0e-4) insert(items, SLDEXT);
	if (compareDouble(SldFcs, comp->SldFcs) < 1.0e-4) insert(items, SLDFCS);
	if (UpdLlo == comp->UpdLlo) insert(items, UPDLLO);
	if (UpdLuo == comp->UpdLuo) insert(items, UPDLUO);
	if (UpdLmd == comp->UpdLmd) insert(items, UPDLMD);
	if (ChkLro == comp->ChkLro) insert(items, CHKLRO);
	if (UpdPnt == comp->UpdPnt) insert(items, UPDPNT);
	if (ChkPro == comp->ChkPro) insert(items, CHKPRO);

	return(items);
};

set<uint> PnlWzskLiv2DView::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPPVM, CHKAEX, SLDEXT, SLDFCS, UPDLLO, UPDLUO, UPDLMD, CHKLRO, UPDPNT, CHKPRO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv2DView::ContIacCorner
 ******************************************************************************/

PnlWzskLiv2DView::ContIacCorner::ContIacCorner(
			const int roiAx
			, const int roiAy
			, const int roiBx
			, const int roiBy
			, const int roiCx
			, const int roiCy
			, const int roiDx
			, const int roiDy
		) :
			Block()
		{
	this->roiAx = roiAx;
	this->roiAy = roiAy;
	this->roiBx = roiBx;
	this->roiBy = roiBy;
	this->roiCx = roiCx;
	this->roiCy = roiCy;
	this->roiDx = roiDx;
	this->roiDy = roiDy;

	mask = {ROIAX, ROIAY, ROIBX, ROIBY, ROICX, ROICY, ROIDX, ROIDY};
};

bool PnlWzskLiv2DView::ContIacCorner::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLiv2DViewCorner");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLiv2DViewCorner";

	if (basefound) {
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiAx", roiAx)) add(ROIAX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiAy", roiAy)) add(ROIAY);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiBx", roiBx)) add(ROIBX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiBy", roiBy)) add(ROIBY);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiCx", roiCx)) add(ROICX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiCy", roiCy)) add(ROICY);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiDx", roiDx)) add(ROIDX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiDy", roiDy)) add(ROIDY);
	};

	return basefound;
};

void PnlWzskLiv2DView::ContIacCorner::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLiv2DViewCorner";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLiv2DViewCorner";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeIntAttr(wr, itemtag, "sref", "roiAx", roiAx);
		writeIntAttr(wr, itemtag, "sref", "roiAy", roiAy);
		writeIntAttr(wr, itemtag, "sref", "roiBx", roiBx);
		writeIntAttr(wr, itemtag, "sref", "roiBy", roiBy);
		writeIntAttr(wr, itemtag, "sref", "roiCx", roiCx);
		writeIntAttr(wr, itemtag, "sref", "roiCy", roiCy);
		writeIntAttr(wr, itemtag, "sref", "roiDx", roiDx);
		writeIntAttr(wr, itemtag, "sref", "roiDy", roiDy);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLiv2DView::ContIacCorner::comm(
			const ContIacCorner* comp
		) {
	set<uint> items;

	if (roiAx == comp->roiAx) insert(items, ROIAX);
	if (roiAy == comp->roiAy) insert(items, ROIAY);
	if (roiBx == comp->roiBx) insert(items, ROIBX);
	if (roiBy == comp->roiBy) insert(items, ROIBY);
	if (roiCx == comp->roiCx) insert(items, ROICX);
	if (roiCy == comp->roiCy) insert(items, ROICY);
	if (roiDx == comp->roiDx) insert(items, ROIDX);
	if (roiDy == comp->roiDy) insert(items, ROIDY);

	return(items);
};

set<uint> PnlWzskLiv2DView::ContIacCorner::diff(
			const ContIacCorner* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ROIAX, ROIAY, ROIBX, ROIBY, ROICX, ROICY, ROIDX, ROIDY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv2DView::ContIacTrace
 ******************************************************************************/

PnlWzskLiv2DView::ContIacTrace::ContIacTrace(
			const int roiAx
			, const int roiAy
			, const int roiBx
			, const int roiBy
			, const int roiCx
			, const int roiCy
			, const int roiDx
			, const int roiDy
		) :
			Block()
		{
	this->roiAx = roiAx;
	this->roiAy = roiAy;
	this->roiBx = roiBx;
	this->roiBy = roiBy;
	this->roiCx = roiCx;
	this->roiCy = roiCy;
	this->roiDx = roiDx;
	this->roiDy = roiDy;

	mask = {ROIAX, ROIAY, ROIBX, ROIBY, ROICX, ROICY, ROIDX, ROIDY};
};

bool PnlWzskLiv2DView::ContIacTrace::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzskLiv2DViewTrace");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzskLiv2DViewTrace";

	if (basefound) {
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiAx", roiAx)) add(ROIAX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiAy", roiAy)) add(ROIAY);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiBx", roiBx)) add(ROIBX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiBy", roiBy)) add(ROIBY);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiCx", roiCx)) add(ROICX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiCy", roiCy)) add(ROICY);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiDx", roiDx)) add(ROIDX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "roiDy", roiDy)) add(ROIDY);
	};

	return basefound;
};

void PnlWzskLiv2DView::ContIacTrace::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzskLiv2DViewTrace";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzskLiv2DViewTrace";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeIntAttr(wr, itemtag, "sref", "roiAx", roiAx);
		writeIntAttr(wr, itemtag, "sref", "roiAy", roiAy);
		writeIntAttr(wr, itemtag, "sref", "roiBx", roiBx);
		writeIntAttr(wr, itemtag, "sref", "roiBy", roiBy);
		writeIntAttr(wr, itemtag, "sref", "roiCx", roiCx);
		writeIntAttr(wr, itemtag, "sref", "roiCy", roiCy);
		writeIntAttr(wr, itemtag, "sref", "roiDx", roiDx);
		writeIntAttr(wr, itemtag, "sref", "roiDy", roiDy);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLiv2DView::ContIacTrace::comm(
			const ContIacTrace* comp
		) {
	set<uint> items;

	if (roiAx == comp->roiAx) insert(items, ROIAX);
	if (roiAy == comp->roiAy) insert(items, ROIAY);
	if (roiBx == comp->roiBx) insert(items, ROIBX);
	if (roiBy == comp->roiBy) insert(items, ROIBY);
	if (roiCx == comp->roiCx) insert(items, ROICX);
	if (roiCy == comp->roiCy) insert(items, ROICY);
	if (roiDx == comp->roiDx) insert(items, ROIDX);
	if (roiDy == comp->roiDy) insert(items, ROIDY);

	return(items);
};

set<uint> PnlWzskLiv2DView::ContIacTrace::diff(
			const ContIacTrace* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ROIAX, ROIAY, ROIBX, ROIBY, ROICX, ROICY, ROIDX, ROIDY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv2DView::ContInf
 ******************************************************************************/

PnlWzskLiv2DView::ContInf::ContInf(
			const bool ButClaimOn
			, const string& TxtOaf
			, const bool ButTccOn
			, const bool ButTcwOn
			, const bool ButLleOn
			, const bool ButLriOn
			, const bool ButLtrOn
			, const bool ButPicOn
		) :
			Block()
		{
	this->ButClaimOn = ButClaimOn;
	this->TxtOaf = TxtOaf;
	this->ButTccOn = ButTccOn;
	this->ButTcwOn = ButTcwOn;
	this->ButLleOn = ButLleOn;
	this->ButLriOn = ButLriOn;
	this->ButLtrOn = ButLtrOn;
	this->ButPicOn = ButPicOn;

	mask = {BUTCLAIMON, TXTOAF, BUTTCCON, BUTTCWON, BUTLLEON, BUTLRION, BUTLTRON, BUTPICON};
};

void PnlWzskLiv2DView::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskLiv2DView";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzskLiv2DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButClaimOn", ButClaimOn);
		writeStringAttr(wr, itemtag, "sref", "TxtOaf", TxtOaf);
		writeBoolAttr(wr, itemtag, "sref", "ButTccOn", ButTccOn);
		writeBoolAttr(wr, itemtag, "sref", "ButTcwOn", ButTcwOn);
		writeBoolAttr(wr, itemtag, "sref", "ButLleOn", ButLleOn);
		writeBoolAttr(wr, itemtag, "sref", "ButLriOn", ButLriOn);
		writeBoolAttr(wr, itemtag, "sref", "ButLtrOn", ButLtrOn);
		writeBoolAttr(wr, itemtag, "sref", "ButPicOn", ButPicOn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLiv2DView::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButClaimOn == comp->ButClaimOn) insert(items, BUTCLAIMON);
	if (TxtOaf == comp->TxtOaf) insert(items, TXTOAF);
	if (ButTccOn == comp->ButTccOn) insert(items, BUTTCCON);
	if (ButTcwOn == comp->ButTcwOn) insert(items, BUTTCWON);
	if (ButLleOn == comp->ButLleOn) insert(items, BUTLLEON);
	if (ButLriOn == comp->ButLriOn) insert(items, BUTLRION);
	if (ButLtrOn == comp->ButLtrOn) insert(items, BUTLTRON);
	if (ButPicOn == comp->ButPicOn) insert(items, BUTPICON);

	return(items);
};

set<uint> PnlWzskLiv2DView::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCLAIMON, TXTOAF, BUTTCCON, BUTTCWON, BUTLLEON, BUTLRION, BUTLTRON, BUTPICON};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv2DView::StatShr
 ******************************************************************************/

PnlWzskLiv2DView::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const bool ButClaimActive
			, const bool ButPlayActive
			, const bool ButStopActive
			, const bool ChkAexActive
			, const bool SldExtAvail
			, const bool SldExtActive
			, const double SldExtMin
			, const double SldExtMax
			, const double SldExtRast
			, const bool SldFcsActive
			, const double SldFcsMin
			, const double SldFcsMax
			, const bool TxtOafAvail
			, const bool ButStsActive
			, const bool UpdLloAvail
			, const int UpdLloMin
			, const int UpdLloMax
			, const bool UpdLuoAvail
			, const int UpdLuoMin
			, const int UpdLuoMax
			, const bool UpdLmdAvail
			, const int UpdLmdMin
			, const int UpdLmdMax
			, const int UpdPntMin
			, const int UpdPntMax
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->ButClaimActive = ButClaimActive;
	this->ButPlayActive = ButPlayActive;
	this->ButStopActive = ButStopActive;
	this->ChkAexActive = ChkAexActive;
	this->SldExtAvail = SldExtAvail;
	this->SldExtActive = SldExtActive;
	this->SldExtMin = SldExtMin;
	this->SldExtMax = SldExtMax;
	this->SldExtRast = SldExtRast;
	this->SldFcsActive = SldFcsActive;
	this->SldFcsMin = SldFcsMin;
	this->SldFcsMax = SldFcsMax;
	this->TxtOafAvail = TxtOafAvail;
	this->ButStsActive = ButStsActive;
	this->UpdLloAvail = UpdLloAvail;
	this->UpdLloMin = UpdLloMin;
	this->UpdLloMax = UpdLloMax;
	this->UpdLuoAvail = UpdLuoAvail;
	this->UpdLuoMin = UpdLuoMin;
	this->UpdLuoMax = UpdLuoMax;
	this->UpdLmdAvail = UpdLmdAvail;
	this->UpdLmdMin = UpdLmdMin;
	this->UpdLmdMax = UpdLmdMax;
	this->UpdPntMin = UpdPntMin;
	this->UpdPntMax = UpdPntMax;

	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTPLAYACTIVE, BUTSTOPACTIVE, CHKAEXACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX, TXTOAFAVAIL, BUTSTSACTIVE, UPDLLOAVAIL, UPDLLOMIN, UPDLLOMAX, UPDLUOAVAIL, UPDLUOMIN, UPDLUOMAX, UPDLMDAVAIL, UPDLMDMIN, UPDLMDMAX, UPDPNTMIN, UPDPNTMAX};
};

void PnlWzskLiv2DView::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzskLiv2DView";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzskLiv2DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzskVExpstate", VecWzskVExpstate::getSref(ixWzskVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButClaimActive", ButClaimActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPlayActive", ButPlayActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStopActive", ButStopActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkAexActive", ChkAexActive);
		writeBoolAttr(wr, itemtag, "sref", "SldExtAvail", SldExtAvail);
		writeBoolAttr(wr, itemtag, "sref", "SldExtActive", SldExtActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtMin", SldExtMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtMax", SldExtMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtRast", SldExtRast);
		writeBoolAttr(wr, itemtag, "sref", "SldFcsActive", SldFcsActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcsMin", SldFcsMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcsMax", SldFcsMax);
		writeBoolAttr(wr, itemtag, "sref", "TxtOafAvail", TxtOafAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStsActive", ButStsActive);
		writeBoolAttr(wr, itemtag, "sref", "UpdLloAvail", UpdLloAvail);
		writeIntAttr(wr, itemtag, "sref", "UpdLloMin", UpdLloMin);
		writeIntAttr(wr, itemtag, "sref", "UpdLloMax", UpdLloMax);
		writeBoolAttr(wr, itemtag, "sref", "UpdLuoAvail", UpdLuoAvail);
		writeIntAttr(wr, itemtag, "sref", "UpdLuoMin", UpdLuoMin);
		writeIntAttr(wr, itemtag, "sref", "UpdLuoMax", UpdLuoMax);
		writeBoolAttr(wr, itemtag, "sref", "UpdLmdAvail", UpdLmdAvail);
		writeIntAttr(wr, itemtag, "sref", "UpdLmdMin", UpdLmdMin);
		writeIntAttr(wr, itemtag, "sref", "UpdLmdMax", UpdLmdMax);
		writeIntAttr(wr, itemtag, "sref", "UpdPntMin", UpdPntMin);
		writeIntAttr(wr, itemtag, "sref", "UpdPntMax", UpdPntMax);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzskLiv2DView::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (ButClaimActive == comp->ButClaimActive) insert(items, BUTCLAIMACTIVE);
	if (ButPlayActive == comp->ButPlayActive) insert(items, BUTPLAYACTIVE);
	if (ButStopActive == comp->ButStopActive) insert(items, BUTSTOPACTIVE);
	if (ChkAexActive == comp->ChkAexActive) insert(items, CHKAEXACTIVE);
	if (SldExtAvail == comp->SldExtAvail) insert(items, SLDEXTAVAIL);
	if (SldExtActive == comp->SldExtActive) insert(items, SLDEXTACTIVE);
	if (compareDouble(SldExtMin, comp->SldExtMin) < 1.0e-4) insert(items, SLDEXTMIN);
	if (compareDouble(SldExtMax, comp->SldExtMax) < 1.0e-4) insert(items, SLDEXTMAX);
	if (compareDouble(SldExtRast, comp->SldExtRast) < 1.0e-4) insert(items, SLDEXTRAST);
	if (SldFcsActive == comp->SldFcsActive) insert(items, SLDFCSACTIVE);
	if (compareDouble(SldFcsMin, comp->SldFcsMin) < 1.0e-4) insert(items, SLDFCSMIN);
	if (compareDouble(SldFcsMax, comp->SldFcsMax) < 1.0e-4) insert(items, SLDFCSMAX);
	if (TxtOafAvail == comp->TxtOafAvail) insert(items, TXTOAFAVAIL);
	if (ButStsActive == comp->ButStsActive) insert(items, BUTSTSACTIVE);
	if (UpdLloAvail == comp->UpdLloAvail) insert(items, UPDLLOAVAIL);
	if (UpdLloMin == comp->UpdLloMin) insert(items, UPDLLOMIN);
	if (UpdLloMax == comp->UpdLloMax) insert(items, UPDLLOMAX);
	if (UpdLuoAvail == comp->UpdLuoAvail) insert(items, UPDLUOAVAIL);
	if (UpdLuoMin == comp->UpdLuoMin) insert(items, UPDLUOMIN);
	if (UpdLuoMax == comp->UpdLuoMax) insert(items, UPDLUOMAX);
	if (UpdLmdAvail == comp->UpdLmdAvail) insert(items, UPDLMDAVAIL);
	if (UpdLmdMin == comp->UpdLmdMin) insert(items, UPDLMDMIN);
	if (UpdLmdMax == comp->UpdLmdMax) insert(items, UPDLMDMAX);
	if (UpdPntMin == comp->UpdPntMin) insert(items, UPDPNTMIN);
	if (UpdPntMax == comp->UpdPntMax) insert(items, UPDPNTMAX);

	return(items);
};

set<uint> PnlWzskLiv2DView::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTPLAYACTIVE, BUTSTOPACTIVE, CHKAEXACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX, TXTOAFAVAIL, BUTSTSACTIVE, UPDLLOAVAIL, UPDLLOMIN, UPDLLOMAX, UPDLUOAVAIL, UPDLUOMIN, UPDLUOMAX, UPDLMDAVAIL, UPDLMDMIN, UPDLMDMAX, UPDPNTMIN, UPDPNTMAX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv2DView::Tag
 ******************************************************************************/

void PnlWzskLiv2DView::Tag::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzskLiv2DView";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzskLiv2DView";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Calibration");
			writeStringAttr(wr, itemtag, "sref", "CptPvm", "preview mode");
			writeStringAttr(wr, itemtag, "sref", "CptAex", "auto-exposure");
			writeStringAttr(wr, itemtag, "sref", "CptExt", "exposure time [ms]");
			writeStringAttr(wr, itemtag, "sref", "CptFcs", "focus (near -\\u003e far)");
			writeStringAttr(wr, itemtag, "sref", "CptOaf", "object affiliation");
			writeStringAttr(wr, itemtag, "sref", "ButSts", "Store snapshot");
			writeStringAttr(wr, itemtag, "sref", "HdgTtb", "Turntable");
			writeStringAttr(wr, itemtag, "sref", "ButTcc", "Turn counter-clockwise");
			writeStringAttr(wr, itemtag, "sref", "ButTcw", "Turn clockwise");
			writeStringAttr(wr, itemtag, "sref", "HdgLor", "Laser orientation");
			writeStringAttr(wr, itemtag, "sref", "ButLle", "Left on");
			writeStringAttr(wr, itemtag, "sref", "ButLri", "Right on");
			writeStringAttr(wr, itemtag, "sref", "CptLlo", "lower 'on' threshold level");
			writeStringAttr(wr, itemtag, "sref", "CptLuo", "upper 'off' threshold level");
			writeStringAttr(wr, itemtag, "sref", "CptLmd", "minimum 'on'-'off' difference");
			writeStringAttr(wr, itemtag, "sref", "CptLgl", "show guidelines");
			writeStringAttr(wr, itemtag, "sref", "CptLro", "ROI trapezoid");
			writeStringAttr(wr, itemtag, "sref", "ButLtr", "Trace");
			writeStringAttr(wr, itemtag, "sref", "ButLcl", "Clear");
			writeStringAttr(wr, itemtag, "sref", "HdgPos", "Pose estimation");
			writeStringAttr(wr, itemtag, "sref", "CptPnt", "target count");
			writeStringAttr(wr, itemtag, "sref", "CptPro", "ROI trapezoid");
			writeStringAttr(wr, itemtag, "sref", "ButPic", "Identify corners");
			writeStringAttr(wr, itemtag, "sref", "ButPcl", "Clear");
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Kalibrierung");
			writeStringAttr(wr, itemtag, "sref", "CptPvm", "Vorschaumodus");
			writeStringAttr(wr, itemtag, "sref", "CptAex", "automatische Belichtung");
			writeStringAttr(wr, itemtag, "sref", "CptExt", "Belichtungszeit [ms]");
			writeStringAttr(wr, itemtag, "sref", "CptFcs", "Fokus (nah -\\u003e fern)");
			writeStringAttr(wr, itemtag, "sref", "CptOaf", "Objekt-Zuordnung");
			writeStringAttr(wr, itemtag, "sref", "ButSts", "Schnappschuss machen");
			writeStringAttr(wr, itemtag, "sref", "HdgTtb", "Drehteller");
			writeStringAttr(wr, itemtag, "sref", "ButTcc", "Gegen Uhrzeigersinn drehen");
			writeStringAttr(wr, itemtag, "sref", "ButTcw", "Im Uhrzeigersinn drehen");
			writeStringAttr(wr, itemtag, "sref", "HdgLor", "Laser-Orientierung");
			writeStringAttr(wr, itemtag, "sref", "ButLle", "Links ein");
			writeStringAttr(wr, itemtag, "sref", "ButLri", "Rechts ein");
			writeStringAttr(wr, itemtag, "sref", "CptLlo", "unterer 'ein'-Schwellwert");
			writeStringAttr(wr, itemtag, "sref", "CptLuo", "oberer 'aus'-Schwellwert");
			writeStringAttr(wr, itemtag, "sref", "CptLmd", "minimale 'ein'-'aus' Differenz");
			writeStringAttr(wr, itemtag, "sref", "CptLgl", "Hilfslinien anzeigen");
			writeStringAttr(wr, itemtag, "sref", "CptLro", "ROI-Trapez");
			writeStringAttr(wr, itemtag, "sref", "ButLtr", "Spur nachzeichnen");
			writeStringAttr(wr, itemtag, "sref", "ButLcl", "Zur\\u00fccksetzen");
			writeStringAttr(wr, itemtag, "sref", "HdgPos", "Lagebestimmung");
			writeStringAttr(wr, itemtag, "sref", "CptPnt", "Anzahl-Vorgabe");
			writeStringAttr(wr, itemtag, "sref", "CptPro", "ROI-Trapez");
			writeStringAttr(wr, itemtag, "sref", "ButPic", "Ecken identifizieren");
			writeStringAttr(wr, itemtag, "sref", "ButPcl", "Zur\\u00fccksetzen");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchAppAlign
 ******************************************************************************/

PnlWzskLiv2DView::DpchAppAlign::DpchAppAlign() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWALIGN)
		{
};

string PnlWzskLiv2DView::DpchAppAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIACCORNER)) ss.push_back("contiaccorner");
	if (has(CONTIACTRACE)) ss.push_back("contiactrace");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchAppAlign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLiv2DViewAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiaccorner.readXML(docctx, basexpath, true)) add(CONTIACCORNER);
		if (contiactrace.readXML(docctx, basexpath, true)) add(CONTIACTRACE);
	} else {
		contiaccorner = ContIacCorner();
		contiactrace = ContIacTrace();
	};
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchAppData
 ******************************************************************************/

PnlWzskLiv2DView::DpchAppData::DpchAppData() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDATA)
		{
};

string PnlWzskLiv2DView::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLiv2DViewData");
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
 class PnlWzskLiv2DView::DpchAppDo
 ******************************************************************************/

PnlWzskLiv2DView::DpchAppDo::DpchAppDo() :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDO)
		{
	ixVDo = 0;
};

string PnlWzskLiv2DView::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzskLiv2DViewDo");
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
 class PnlWzskLiv2DView::DpchEngAlign
 ******************************************************************************/

PnlWzskLiv2DView::DpchEngAlign::DpchEngAlign(
			const ubigint jref
			, ContIacCorner* contiaccorner
			, ContIacTrace* contiactrace
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV2DVIEWALIGN, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIACCORNER, CONTIACTRACE};
	else this->mask = mask;

	if (find(this->mask, CONTIACCORNER) && contiaccorner) this->contiaccorner = *contiaccorner;
	if (find(this->mask, CONTIACTRACE) && contiactrace) this->contiactrace = *contiactrace;
};

string PnlWzskLiv2DView::DpchEngAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIACCORNER)) ss.push_back("contiaccorner");
	if (has(CONTIACTRACE)) ss.push_back("contiactrace");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchEngAlign::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngAlign* src = (DpchEngAlign*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIACCORNER)) {contiaccorner = src->contiaccorner; add(CONTIACCORNER);};
	if (src->has(CONTIACTRACE)) {contiactrace = src->contiactrace; add(CONTIACTRACE);};
};

void PnlWzskLiv2DView::DpchEngAlign::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLiv2DViewAlign");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIACCORNER)) contiaccorner.writeXML(wr);
		if (has(CONTIACTRACE)) contiactrace.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchEngData
 ******************************************************************************/

PnlWzskLiv2DView::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupPvm
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV2DVIEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPPVM, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPPVM) && feedFPupPvm) this->feedFPupPvm = *feedFPupPvm;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzskLiv2DView::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPPVM)) ss.push_back("feedFPupPvm");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchEngData::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPPVM)) {feedFPupPvm = src->feedFPupPvm; add(FEEDFPUPPVM);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzskLiv2DView::DpchEngData::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLiv2DViewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPPVM)) feedFPupPvm.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzskVLocale, wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchEngLive
 ******************************************************************************/

PnlWzskLiv2DView::DpchEngLive::DpchEngLive(
			const ubigint jref
			, const vector<utinyint>& gray
			, const vector<utinyint>& red
			, const vector<utinyint>& green
			, const vector<utinyint>& blue
			, const vector<int>& xCorner
			, const vector<int>& yCorner
			, const vector<int>& xTraceL
			, const vector<int>& yTraceL
			, const vector<int>& xTraceR
			, const vector<int>& yTraceR
			, const set<uint>& mask
		) :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV2DVIEWLIVE, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, GRAY, RED, GREEN, BLUE, XCORNER, YCORNER, XTRACEL, YTRACEL, XTRACER, YTRACER};
	else this->mask = mask;

	this->gray = gray;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->xCorner = xCorner;
	this->yCorner = yCorner;
	this->xTraceL = xTraceL;
	this->yTraceL = yTraceL;
	this->xTraceR = xTraceR;
	this->yTraceR = yTraceR;
};

string PnlWzskLiv2DView::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(GRAY)) ss.push_back("gray");
	if (has(RED)) ss.push_back("red");
	if (has(GREEN)) ss.push_back("green");
	if (has(BLUE)) ss.push_back("blue");
	if (has(XCORNER)) ss.push_back("xCorner");
	if (has(YCORNER)) ss.push_back("yCorner");
	if (has(XTRACEL)) ss.push_back("xTraceL");
	if (has(YTRACEL)) ss.push_back("yTraceL");
	if (has(XTRACER)) ss.push_back("xTraceR");
	if (has(YTRACER)) ss.push_back("yTraceR");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchEngLive::merge(
			DpchEngWzsk* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(GRAY)) {gray = src->gray; add(GRAY);};
	if (src->has(RED)) {red = src->red; add(RED);};
	if (src->has(GREEN)) {green = src->green; add(GREEN);};
	if (src->has(BLUE)) {blue = src->blue; add(BLUE);};
	if (src->has(XCORNER)) {xCorner = src->xCorner; add(XCORNER);};
	if (src->has(YCORNER)) {yCorner = src->yCorner; add(YCORNER);};
	if (src->has(XTRACEL)) {xTraceL = src->xTraceL; add(XTRACEL);};
	if (src->has(YTRACEL)) {yTraceL = src->yTraceL; add(YTRACEL);};
	if (src->has(XTRACER)) {xTraceR = src->xTraceR; add(XTRACER);};
	if (src->has(YTRACER)) {yTraceR = src->yTraceR; add(YTRACER);};
};

void PnlWzskLiv2DView::DpchEngLive::writeXML(
			const uint ixWzskVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzskLiv2DViewLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(GRAY)) writeUtinyintvec(wr, "gray", gray);
		if (has(RED)) writeUtinyintvec(wr, "red", red);
		if (has(GREEN)) writeUtinyintvec(wr, "green", green);
		if (has(BLUE)) writeUtinyintvec(wr, "blue", blue);
		if (has(XCORNER)) writeIntvec(wr, "xCorner", xCorner);
		if (has(YCORNER)) writeIntvec(wr, "yCorner", yCorner);
		if (has(XTRACEL)) writeIntvec(wr, "xTraceL", xTraceL);
		if (has(YTRACEL)) writeIntvec(wr, "yTraceL", yTraceL);
		if (has(XTRACER)) writeIntvec(wr, "xTraceR", xTraceR);
		if (has(YTRACER)) writeIntvec(wr, "yTraceR", yTraceR);
	xmlTextWriterEndElement(wr);
};

