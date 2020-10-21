/**
	* \file JobWzskAcqFpgaflg_blks.cpp
	* job handler for job JobWzskAcqFpgaflg (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

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

