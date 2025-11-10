/**
	* \file JobWzskActRotary_blks.cpp
	* job handler for job JobWzskActRotary (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskActRotary::VecVMethod
 ******************************************************************************/

uint JobWzskActRotary::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "moveto") return MOVETO;
	if (s == "stop") return STOP;
	if (s == "turn") return TURN;
	if (s == "zero") return ZERO;

	return(0);
};

string JobWzskActRotary::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == MOVETO) return("moveto");
	if (ix == STOP) return("stop");
	if (ix == TURN) return("turn");
	if (ix == ZERO) return("zero");

	return("");
};

void JobWzskActRotary::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActRotary::VecVSge
 ******************************************************************************/

uint JobWzskActRotary::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "move") return MOVE;

	return(0);
};

string JobWzskActRotary::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == MOVE) return("move");

	return("");
};

void JobWzskActRotary::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActRotary::VecVVar
 ******************************************************************************/

uint JobWzskActRotary::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "angletarget") return ANGLETARGET;

	return(0);
};

string JobWzskActRotary::VecVVar::getSref(
			const uint ix
		) {
	if (ix == ANGLETARGET) return("angleTarget");

	return("");
};

void JobWzskActRotary::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};
