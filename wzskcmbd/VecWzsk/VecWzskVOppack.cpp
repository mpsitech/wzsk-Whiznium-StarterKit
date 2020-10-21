/**
	* \file VecWzskVOppack.cpp
	* vector VecWzskVOppack (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "VecWzskVOppack.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVOppack
 ******************************************************************************/

uint VecWzskVOppack::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	return(0);
};

string VecWzskVOppack::getSref(
			const uint ix
		) {

	return("");
};

string VecWzskVOppack::getTitle(
			const uint ix
		) {
	return(getSref(ix));

	return("");
};

string VecWzskVOppack::getComment(
			const uint ix
		) {

	return("");
};

void VecWzskVOppack::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix));
};

void VecWzskVOppack::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 0; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

