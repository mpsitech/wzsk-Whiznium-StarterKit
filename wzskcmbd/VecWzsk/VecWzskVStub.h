/**
	* \file VecWzskVStub.h
	* vector VecWzskVStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef VECWZSKVSTUB_H
#define VECWZSKVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVStub
	*/
namespace VecWzskVStub {
	const Sbecore::uint STUBWZSKFILSTD = 1;
	const Sbecore::uint STUBWZSKPRSSTD = 2;
	const Sbecore::uint STUBWZSKSESMENU = 3;
	const Sbecore::uint STUBWZSKSESSTD = 4;
	const Sbecore::uint STUBWZSKOWNER = 5;
	const Sbecore::uint STUBWZSKUSRSTD = 6;
	const Sbecore::uint STUBWZSKGROUP = 7;
	const Sbecore::uint STUBWZSKUSGSTD = 8;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
