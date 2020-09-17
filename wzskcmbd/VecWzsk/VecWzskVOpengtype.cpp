/**
	* \file VecWzskVOpengtype.cpp
	* vector VecWzskVOpengtype (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "VecWzskVOpengtype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVOpengtype
 ******************************************************************************/

uint VecWzskVOpengtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	return(0);
};

string VecWzskVOpengtype::getSref(
			const uint ix
		) {

	return("");
};

string VecWzskVOpengtype::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		return(getTitle(ix, 1));
	};

	return("");
};

void VecWzskVOpengtype::appendToFeed(
			const uint ix
			, const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixWzskVLocale));
};

void VecWzskVOpengtype::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 0; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

