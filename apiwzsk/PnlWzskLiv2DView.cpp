/**
	* \file PnlWzskLiv2DView.cpp
	* API code for job PnlWzskLiv2DView (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzskLiv2DView.h"

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
			, const double SldCwd
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
	this->SldCwd = SldCwd;

	mask = {NUMFPUPPVM, CHKAEX, SLDEXT, SLDFCS, UPDLLO, UPDLUO, UPDLMD, CHKLRO, UPDPNT, CHKPRO, SLDCWD};
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
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldCwd", SldCwd)) add(SLDCWD);
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
		writeDoubleAttr(wr, itemtag, "sref", "SldCwd", SldCwd);
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
	if (compareDouble(SldCwd, comp->SldCwd) < 1.0e-4) insert(items, SLDCWD);

	return(items);
};

set<uint> PnlWzskLiv2DView::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPPVM, CHKAEX, SLDEXT, SLDFCS, UPDLLO, UPDLUO, UPDLMD, CHKLRO, UPDPNT, CHKPRO, SLDCWD};
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

bool PnlWzskLiv2DView::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskLiv2DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskLiv2DView";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButClaimOn", ButClaimOn)) add(BUTCLAIMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtOaf", TxtOaf)) add(TXTOAF);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButTccOn", ButTccOn)) add(BUTTCCON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButTcwOn", ButTcwOn)) add(BUTTCWON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButLleOn", ButLleOn)) add(BUTLLEON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButLriOn", ButLriOn)) add(BUTLRION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButLtrOn", ButLtrOn)) add(BUTLTRON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButPicOn", ButPicOn)) add(BUTPICON);
	};

	return basefound;
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
			, const double SldCwdMin
			, const double SldCwdMax
			, const double SldCwdRast
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
	this->SldCwdMin = SldCwdMin;
	this->SldCwdMax = SldCwdMax;
	this->SldCwdRast = SldCwdRast;

	mask = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTPLAYACTIVE, BUTSTOPACTIVE, CHKAEXACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX, TXTOAFAVAIL, BUTSTSACTIVE, UPDLLOAVAIL, UPDLLOMIN, UPDLLOMAX, UPDLUOAVAIL, UPDLUOMIN, UPDLUOMAX, UPDLMDAVAIL, UPDLMDMIN, UPDLMDMAX, UPDPNTMIN, UPDPNTMAX, SLDCWDMIN, SLDCWDMAX, SLDCWDRAST};
};

bool PnlWzskLiv2DView::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskLiv2DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskLiv2DView";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClaimActive", ButClaimActive)) add(BUTCLAIMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPlayActive", ButPlayActive)) add(BUTPLAYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStopActive", ButStopActive)) add(BUTSTOPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkAexActive", ChkAexActive)) add(CHKAEXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtAvail", SldExtAvail)) add(SLDEXTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtActive", SldExtActive)) add(SLDEXTACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtMin", SldExtMin)) add(SLDEXTMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtMax", SldExtMax)) add(SLDEXTMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtRast", SldExtRast)) add(SLDEXTRAST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFcsActive", SldFcsActive)) add(SLDFCSACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFcsMin", SldFcsMin)) add(SLDFCSMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFcsMax", SldFcsMax)) add(SLDFCSMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtOafAvail", TxtOafAvail)) add(TXTOAFAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStsActive", ButStsActive)) add(BUTSTSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLloAvail", UpdLloAvail)) add(UPDLLOAVAIL);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLloMin", UpdLloMin)) add(UPDLLOMIN);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLloMax", UpdLloMax)) add(UPDLLOMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLuoAvail", UpdLuoAvail)) add(UPDLUOAVAIL);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLuoMin", UpdLuoMin)) add(UPDLUOMIN);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLuoMax", UpdLuoMax)) add(UPDLUOMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLmdAvail", UpdLmdAvail)) add(UPDLMDAVAIL);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLmdMin", UpdLmdMin)) add(UPDLMDMIN);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdLmdMax", UpdLmdMax)) add(UPDLMDMAX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdPntMin", UpdPntMin)) add(UPDPNTMIN);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdPntMax", UpdPntMax)) add(UPDPNTMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldCwdMin", SldCwdMin)) add(SLDCWDMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldCwdMax", SldCwdMax)) add(SLDCWDMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldCwdRast", SldCwdRast)) add(SLDCWDRAST);
	};

	return basefound;
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
	if (compareDouble(SldCwdMin, comp->SldCwdMin) < 1.0e-4) insert(items, SLDCWDMIN);
	if (compareDouble(SldCwdMax, comp->SldCwdMax) < 1.0e-4) insert(items, SLDCWDMAX);
	if (compareDouble(SldCwdRast, comp->SldCwdRast) < 1.0e-4) insert(items, SLDCWDRAST);

	return(items);
};

set<uint> PnlWzskLiv2DView::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTPLAYACTIVE, BUTSTOPACTIVE, CHKAEXACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX, TXTOAFAVAIL, BUTSTSACTIVE, UPDLLOAVAIL, UPDLLOMIN, UPDLLOMAX, UPDLUOAVAIL, UPDLUOMIN, UPDLUOMAX, UPDLMDAVAIL, UPDLMDMIN, UPDLMDMAX, UPDPNTMIN, UPDPNTMAX, SLDCWDMIN, SLDCWDMAX, SLDCWDRAST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLiv2DView::Tag
 ******************************************************************************/

PnlWzskLiv2DView::Tag::Tag(
			const string& Cpt
			, const string& CptPvm
			, const string& CptAex
			, const string& CptExt
			, const string& CptFcs
			, const string& CptOaf
			, const string& ButSts
			, const string& HdgTtb
			, const string& ButTcc
			, const string& ButTcw
			, const string& HdgLor
			, const string& ButLle
			, const string& ButLri
			, const string& CptLlo
			, const string& CptLuo
			, const string& CptLmd
			, const string& CptLgl
			, const string& CptLro
			, const string& ButLtr
			, const string& ButLcl
			, const string& HdgPos
			, const string& CptPnt
			, const string& CptPro
			, const string& ButPic
			, const string& ButPcl
			, const string& HdgCld
			, const string& CptCwd
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPvm = CptPvm;
	this->CptAex = CptAex;
	this->CptExt = CptExt;
	this->CptFcs = CptFcs;
	this->CptOaf = CptOaf;
	this->ButSts = ButSts;
	this->HdgTtb = HdgTtb;
	this->ButTcc = ButTcc;
	this->ButTcw = ButTcw;
	this->HdgLor = HdgLor;
	this->ButLle = ButLle;
	this->ButLri = ButLri;
	this->CptLlo = CptLlo;
	this->CptLuo = CptLuo;
	this->CptLmd = CptLmd;
	this->CptLgl = CptLgl;
	this->CptLro = CptLro;
	this->ButLtr = ButLtr;
	this->ButLcl = ButLcl;
	this->HdgPos = HdgPos;
	this->CptPnt = CptPnt;
	this->CptPro = CptPro;
	this->ButPic = ButPic;
	this->ButPcl = ButPcl;
	this->HdgCld = HdgCld;
	this->CptCwd = CptCwd;

	mask = {CPT, CPTPVM, CPTAEX, CPTEXT, CPTFCS, CPTOAF, BUTSTS, HDGTTB, BUTTCC, BUTTCW, HDGLOR, BUTLLE, BUTLRI, CPTLLO, CPTLUO, CPTLMD, CPTLGL, CPTLRO, BUTLTR, BUTLCL, HDGPOS, CPTPNT, CPTPRO, BUTPIC, BUTPCL, HDGCLD, CPTCWD};
};

bool PnlWzskLiv2DView::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLiv2DView");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLiv2DView";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPvm", CptPvm)) add(CPTPVM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAex", CptAex)) add(CPTAEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptExt", CptExt)) add(CPTEXT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFcs", CptFcs)) add(CPTFCS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOaf", CptOaf)) add(CPTOAF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSts", ButSts)) add(BUTSTS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgTtb", HdgTtb)) add(HDGTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButTcc", ButTcc)) add(BUTTCC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButTcw", ButTcw)) add(BUTTCW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgLor", HdgLor)) add(HDGLOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButLle", ButLle)) add(BUTLLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButLri", ButLri)) add(BUTLRI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLlo", CptLlo)) add(CPTLLO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLuo", CptLuo)) add(CPTLUO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLmd", CptLmd)) add(CPTLMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLgl", CptLgl)) add(CPTLGL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLro", CptLro)) add(CPTLRO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButLtr", ButLtr)) add(BUTLTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButLcl", ButLcl)) add(BUTLCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgPos", HdgPos)) add(HDGPOS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPnt", CptPnt)) add(CPTPNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPro", CptPro)) add(CPTPRO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButPic", ButPic)) add(BUTPIC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButPcl", ButPcl)) add(BUTPCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgCld", HdgCld)) add(HDGCLD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCwd", CptCwd)) add(CPTCWD);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchAppAlign
 ******************************************************************************/

PnlWzskLiv2DView::DpchAppAlign::DpchAppAlign(
			const string& scrJref
			, ContIacCorner* contiaccorner
			, ContIacTrace* contiactrace
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWALIGN, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIACCORNER, CONTIACTRACE};
	else this->mask = mask;

		if (find(this->mask, CONTIACCORNER) && contiaccorner) this->contiaccorner = *contiaccorner;
		if (find(this->mask, CONTIACTRACE) && contiactrace) this->contiactrace = *contiactrace;
};

string PnlWzskLiv2DView::DpchAppAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIACCORNER)) ss.push_back("contiaccorner");
	if (has(CONTIACTRACE)) ss.push_back("contiactrace");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchAppAlign::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLiv2DViewAlign");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIACCORNER)) contiaccorner.writeXML(wr);
		if (has(CONTIACTRACE)) contiactrace.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchAppData
 ******************************************************************************/

PnlWzskLiv2DView::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzskLiv2DView::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLiv2DViewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchAppDo
 ******************************************************************************/

PnlWzskLiv2DView::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskLiv2DView::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskLiv2DViewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchEngAlign
 ******************************************************************************/

PnlWzskLiv2DView::DpchEngAlign::DpchEngAlign() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV2DVIEWALIGN)
		{
};

string PnlWzskLiv2DView::DpchEngAlign::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIACCORNER)) ss.push_back("contiaccorner");
	if (has(CONTIACTRACE)) ss.push_back("contiactrace");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchEngAlign::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLiv2DViewAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiaccorner.readXML(docctx, basexpath, true)) add(CONTIACCORNER);
		if (contiactrace.readXML(docctx, basexpath, true)) add(CONTIACTRACE);
	} else {
		contiaccorner = ContIacCorner();
		contiactrace = ContIacTrace();
	};
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchEngData
 ******************************************************************************/

PnlWzskLiv2DView::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV2DVIEWDATA)
		{
	feedFPupPvm.tag = "FeedFPupPvm";
};

string PnlWzskLiv2DView::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPPVM)) ss.push_back("feedFPupPvm");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLiv2DView::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLiv2DViewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupPvm.readXML(docctx, basexpath, true)) add(FEEDFPUPPVM);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupPvm.clear();
		statshr = StatShr();
		tag = Tag();
	};
};

/******************************************************************************
 class PnlWzskLiv2DView::DpchEngLive
 ******************************************************************************/

PnlWzskLiv2DView::DpchEngLive::DpchEngLive() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLIV2DVIEWLIVE)
		{
};

string PnlWzskLiv2DView::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWzskLiv2DView::DpchEngLive::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLiv2DViewLive");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUtinyintvecUclc(docctx, basexpath, "gray", "", gray)) add(GRAY);
		if (extractUtinyintvecUclc(docctx, basexpath, "red", "", red)) add(RED);
		if (extractUtinyintvecUclc(docctx, basexpath, "green", "", green)) add(GREEN);
		if (extractUtinyintvecUclc(docctx, basexpath, "blue", "", blue)) add(BLUE);
		if (extractIntvecUclc(docctx, basexpath, "xCorner", "", xCorner)) add(XCORNER);
		if (extractIntvecUclc(docctx, basexpath, "yCorner", "", yCorner)) add(YCORNER);
		if (extractIntvecUclc(docctx, basexpath, "xTraceL", "", xTraceL)) add(XTRACEL);
		if (extractIntvecUclc(docctx, basexpath, "yTraceL", "", yTraceL)) add(YTRACEL);
		if (extractIntvecUclc(docctx, basexpath, "xTraceR", "", xTraceR)) add(XTRACER);
		if (extractIntvecUclc(docctx, basexpath, "yTraceR", "", yTraceR)) add(YTRACER);
	} else {
	};
};
