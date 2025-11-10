/**
	* \file VecWzskVTag.h
	* vector VecWzskVTag (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef VECWZSKVTAG_H
#define VECWZSKVTAG_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVTag
	*/
namespace VecWzskVTag {
	const Sbecore::uint ABOUT = 1;
	const Sbecore::uint ALWAYS = 2;
	const Sbecore::uint ANNOUNCE = 3;
	const Sbecore::uint CANCEL = 4;
	const Sbecore::uint CLOSE = 5;
	const Sbecore::uint CLSESS = 6;
	const Sbecore::uint CLUST = 7;
	const Sbecore::uint DETAIL = 8;
	const Sbecore::uint DONE = 9;
	const Sbecore::uint DOWNLOAD = 10;
	const Sbecore::uint EMPLONG = 11;
	const Sbecore::uint EMPSHORT = 12;
	const Sbecore::uint ERROR = 13;
	const Sbecore::uint FILENAME = 14;
	const Sbecore::uint FLS = 15;
	const Sbecore::uint GENERAL = 16;
	const Sbecore::uint GOTO = 17;
	const Sbecore::uint GRP = 18;
	const Sbecore::uint HELP = 19;
	const Sbecore::uint HOUR = 20;
	const Sbecore::uint HOURS = 21;
	const Sbecore::uint IMPERR = 22;
	const Sbecore::uint IMPORT = 23;
	const Sbecore::uint LOAINI = 24;
	const Sbecore::uint MINUTE = 25;
	const Sbecore::uint MINUTES = 26;
	const Sbecore::uint NAV = 27;
	const Sbecore::uint NO = 28;
	const Sbecore::uint OK = 29;
	const Sbecore::uint OPSCPLLAST = 30;
	const Sbecore::uint OPSPREP = 31;
	const Sbecore::uint OWN = 32;
	const Sbecore::uint PROGRESS = 33;
	const Sbecore::uint PRSERR = 34;
	const Sbecore::uint QUEST = 35;
	const Sbecore::uint REC = 36;
	const Sbecore::uint REVERSE = 37;
	const Sbecore::uint RUN = 38;
	const Sbecore::uint SECOND = 39;
	const Sbecore::uint SECONDS = 40;
	const Sbecore::uint SESS = 41;
	const Sbecore::uint SHOWLONG = 42;
	const Sbecore::uint SHOWSHORT = 43;
	const Sbecore::uint STOP = 44;
	const Sbecore::uint SUSPSESS = 45;
	const Sbecore::uint TRU = 46;
	const Sbecore::uint UPLOAD = 47;
	const Sbecore::uint YES = 48;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
};

#endif
