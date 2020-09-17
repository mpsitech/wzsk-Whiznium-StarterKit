/**
	* \file VecWzskVStub.h
	* vector VecWzskVStub (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
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
	const Sbecore::uint STUBWZSKGROUP = 5;
	const Sbecore::uint STUBWZSKUSGSTD = 6;
	const Sbecore::uint STUBWZSKOWNER = 7;
	const Sbecore::uint STUBWZSKUSRSTD = 8;
	const Sbecore::uint STUBWZSKPRSSTD = 9;
	const Sbecore::uint STUBWZSKSESMENU = 10;
	const Sbecore::uint STUBWZSKSESSTD = 11;
	const Sbecore::uint STUBWZSKFILSTD = 12;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

