/**
	* \file VecWzskVIop.h
	* vector VecWzskVIop (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef VECWZSKVIOP_H
#define VECWZSKVIOP_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVIop
	*/
namespace VecWzskVIop {
	const Sbecore::uint INS = 1;
	const Sbecore::uint RETR = 2;
	const Sbecore::uint RETRINS = 3;
	const Sbecore::uint RETRUPD = 4;
	const Sbecore::uint RETRUPDINS = 5;
	const Sbecore::uint RMV = 6;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

	void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
};

#endif
