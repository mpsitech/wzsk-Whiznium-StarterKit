/**
	* \file WzskMFile_vecs.cpp
	* database access for table TblWzskMFile (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWzskMFile::VecVRefTbl
 ******************************************************************************/

uint TblWzskMFile::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;

	return(0);
};

string TblWzskMFile::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");

	return("");
};

string TblWzskMFile::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == VOID) return("none");
		return(getSref(ix));
	};

	return("");
};

void TblWzskMFile::VecVRefTbl::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};
