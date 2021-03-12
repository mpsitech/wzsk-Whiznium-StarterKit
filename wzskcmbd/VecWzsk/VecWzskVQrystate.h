/**
	* \file VecWzskVQrystate.h
	* vector VecWzskVQrystate (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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

	void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
};

#endif
