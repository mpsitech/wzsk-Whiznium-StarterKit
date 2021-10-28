/**
	* \file VecWzskVTarget.cpp
	* vector VecWzskVTarget (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
  */
// IP header --- ABOVE

#include "VecWzskVTarget.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVTarget
 ******************************************************************************/

uint VecWzskVTarget::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "apalis") return APALIS;
	if (s == "arty") return ARTY;
	if (s == "clnxevb") return CLNXEVB;
	if (s == "icicle") return ICICLE;
	if (s == "mcvevp") return MCVEVP;
	if (s == "ws") return WS;

	return(0);
};

string VecWzskVTarget::getSref(
			const uint ix
		) {
	if (ix == APALIS) return("apalis");
	if (ix == ARTY) return("arty");
	if (ix == CLNXEVB) return("clnxevb");
	if (ix == ICICLE) return("icicle");
	if (ix == MCVEVP) return("mcvevp");
	if (ix == WS) return("ws");

	return("");
};

string VecWzskVTarget::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == APALIS) return("Toradex Apalis on Ixora carrier board ");
		if (ix == ARTY) return("Digilent Cora Z7");
		if (ix == CLNXEVB) return("Lattice CrossLink-NX evaluation board");
		if (ix == ICICLE) return("Microchip PolarFire Soc Icicle kit");
		if (ix == MCVEVP) return("Aries Cyclone V evaluation platform");
		if (ix == WS) return("Generic Intel x64 workstation");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		return(getTitle(ix, 1));
	};

	return("");
};

void VecWzskVTarget::appendToFeed(
			const uint ix
			, const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixWzskVLocale));
};

void VecWzskVTarget::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};
