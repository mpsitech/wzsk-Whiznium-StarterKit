/**
	* \file WzskMFile_vecs.cpp
	* database access for table TblWzskMFile (implementation of vectors)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

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
	if (s == "obj") return OBJ;
	if (s == "sht") return SHT;

	return(0);
};

string TblWzskMFile::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == OBJ) return("obj");
	if (ix == SHT) return("sht");

	return("");
};

string TblWzskMFile::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == OBJ) return("object");
		if (ix == SHT) return("shot");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == VOID) return("kein");
		if (ix == OBJ) return("Objekt");
		if (ix == SHT) return("Aufnahme");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblWzskMFile::VecVRefTbl::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

