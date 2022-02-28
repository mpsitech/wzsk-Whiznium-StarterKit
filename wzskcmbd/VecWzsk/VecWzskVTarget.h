/**
	* \file VecWzskVTarget.h
	* vector VecWzskVTarget (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
  */
// IP header --- ABOVE

#ifndef VECWZSKVTARGET_H
#define VECWZSKVTARGET_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVTarget
	*/
namespace VecWzskVTarget {
	const Sbecore::uint APALIS = 1;
	const Sbecore::uint ARTY = 2;
	const Sbecore::uint CLNXEVB = 3;
	const Sbecore::uint ICICLE = 4;
	const Sbecore::uint MCVEVP = 5;
	const Sbecore::uint UZEDIOCC = 6;
	const Sbecore::uint WS = 7;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
};

#endif
