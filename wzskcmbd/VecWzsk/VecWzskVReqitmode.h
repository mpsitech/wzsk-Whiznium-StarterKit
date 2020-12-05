/**
	* \file VecWzskVReqitmode.h
	* vector VecWzskVReqitmode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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

