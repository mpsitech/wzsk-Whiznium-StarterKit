/**
	* \file JobWzskAcqFpgaflg_blks.cpp
	* job handler for job JobWzskAcqFpgaflg (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskAcqFpgaflg::VecVSge
 ******************************************************************************/

uint JobWzskAcqFpgaflg::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "rng") return RNG;

	return(0);
};

string JobWzskAcqFpgaflg::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RNG) return("rng");

	return("");
};

void JobWzskAcqFpgaflg::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};
