/**
	* \file VecWzskVQrystate.h
	* vector VecWzskVQrystate (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef VECWZSKVQRYSTATE_H
#define VECWZSKVQRYSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVQrystate
	*/
namespace VecWzskVQrystate {
	const Sbecore::uint MNR = 1;
	const Sbecore::uint OOD = 2;
	const Sbecore::uint SLM = 3;
	const Sbecore::uint UTD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

	void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

