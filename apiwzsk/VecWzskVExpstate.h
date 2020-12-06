/**
	* \file VecWzskVExpstate.h
	* vector VecWzskVExpstate (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef VECWZSKVEXPSTATE_H
#define VECWZSKVEXPSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVExpstate
	*/
namespace VecWzskVExpstate {
	const Sbecore::uint DETD = 1;
	const Sbecore::uint MAXD = 2;
	const Sbecore::uint MIND = 3;
	const Sbecore::uint REGD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
