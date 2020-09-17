/**
	* \file VecWzskVReqitmode.h
	* vector VecWzskVReqitmode (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef VECWZSKVREQITMODE_H
#define VECWZSKVREQITMODE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVReqitmode
	*/
namespace VecWzskVReqitmode {
	const Sbecore::uint IDLE = 1;
	const Sbecore::uint NOTIFY = 2;
	const Sbecore::uint POLL = 3;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

