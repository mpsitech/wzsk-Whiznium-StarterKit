/**
	* \file VecWzskVExpstate.h
	* vector VecWzskVExpstate (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

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

