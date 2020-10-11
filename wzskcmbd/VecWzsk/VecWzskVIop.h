/**
	* \file VecWzskVIop.h
	* vector VecWzskVIop (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

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

	void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

