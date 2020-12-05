/**
	* \file VecWzskVPvwmode.cpp
	* vector VecWzskVPvwmode (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "VecWzskVPvwmode.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVPvwmode
 ******************************************************************************/

uint VecWzskVPvwmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bingray") return BINGRAY;
	if (s == "binreddom") return BINREDDOM;
	if (s == "binrgb") return BINRGB;
	if (s == "rawgray") return RAWGRAY;
	if (s == "rawrgb") return RAWRGB;

	return(0);
};

string VecWzskVPvwmode::getSref(
			const uint ix
		) {
	if (ix == BINGRAY) return("bingray");
	if (ix == BINREDDOM) return("binreddom");
	if (ix == BINRGB) return("binrgb");
	if (ix == RAWGRAY) return("rawgray");
	if (ix == RAWRGB) return("rawrgb");

	return("");
};

string VecWzskVPvwmode::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == BINGRAY) return("4x4 pixel binning grayscale");
		if (ix == BINREDDOM) return("4x4 pixel binning red dominance");
		if (ix == BINRGB) return("8x8 pixel binning RGB");
		if (ix == RAWGRAY) return("full-res grayscale");
		if (ix == RAWRGB) return("full-res RGB");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == BINGRAY) return("4x4 Pixel Mittelung Graustufen");
		if (ix == BINREDDOM) return("4x4 Pixel Mittelung Rot-Dominanz");
		if (ix == BINRGB) return("8x8 Pixel Mittelung RGB");
		if (ix == RAWGRAY) return("Graustufen volle Aufl\\u00f6sung");
		if (ix == RAWRGB) return("RGB volle Aufl\\u00f6sung");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecWzskVPvwmode::appendToFeed(
			const uint ix
			, const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixWzskVLocale));
};

void VecWzskVPvwmode::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

