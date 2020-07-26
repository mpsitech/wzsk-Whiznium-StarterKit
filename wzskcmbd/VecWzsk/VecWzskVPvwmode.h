/**
	* \file VecWzskVPvwmode.h
	* vector VecWzskVPvwmode (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef VECWZSKVPVWMODE_H
#define VECWZSKVPVWMODE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVPvwmode
	*/
namespace VecWzskVPvwmode {
	const Sbecore::uint BINGRAY = 1;
	const Sbecore::uint BINREDDOM = 2;
	const Sbecore::uint BINRGB = 3;
	const Sbecore::uint RAWGRAY = 4;
	const Sbecore::uint RAWRGB = 5;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
	void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif
