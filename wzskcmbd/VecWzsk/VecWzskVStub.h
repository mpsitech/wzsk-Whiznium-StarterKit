/**
	* \file VecWzskVStub.h
	* vector VecWzskVStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef VECWZSKVSTUB_H
#define VECWZSKVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVStub
	*/
namespace VecWzskVStub {
	const Sbecore::uint STUBWZSKSHTSTD = 1;
	const Sbecore::uint STUBWZSKOGRHSREF = 2;
	const Sbecore::uint STUBWZSKOGRSTD = 3;
	const Sbecore::uint STUBWZSKOBJSTD = 4;
	const Sbecore::uint STUBWZSKGROUP = 5;
	const Sbecore::uint STUBWZSKUSGSTD = 6;
	const Sbecore::uint STUBWZSKPRSSTD = 7;
	const Sbecore::uint STUBWZSKSESMENU = 8;
	const Sbecore::uint STUBWZSKSESSTD = 9;
	const Sbecore::uint STUBWZSKOWNER = 10;
	const Sbecore::uint STUBWZSKUSRSTD = 11;
	const Sbecore::uint STUBWZSKFILSTD = 12;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
