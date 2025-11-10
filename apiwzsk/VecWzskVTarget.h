/**
	* \file VecWzskVTarget.h
	* vector VecWzskVTarget (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef VECWZSKVTARGET_H
#define VECWZSKVTARGET_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVTarget
	*/
namespace VecWzskVTarget {
	const Sbecore::uint DISCO = 1;
	const Sbecore::uint TITDVK = 2;
	const Sbecore::uint ZUDVK = 3;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
