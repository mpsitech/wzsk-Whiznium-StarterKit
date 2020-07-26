/**
	* \file VecWzskVStub.h
	* vector VecWzskVStub (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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
	const Sbecore::uint STUBWZSKFILSTD = 5;
	const Sbecore::uint STUBWZSKPRSSTD = 6;
	const Sbecore::uint STUBWZSKSESMENU = 7;
	const Sbecore::uint STUBWZSKSESSTD = 8;
	const Sbecore::uint STUBWZSKOWNER = 9;
	const Sbecore::uint STUBWZSKUSRSTD = 10;
	const Sbecore::uint STUBWZSKGROUP = 11;
	const Sbecore::uint STUBWZSKUSGSTD = 12;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

