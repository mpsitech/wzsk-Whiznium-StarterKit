/**
	* \file VecWzskVStub.h
	* vector VecWzskVStub (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef VECWZSKVSTUB_H
#define VECWZSKVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVStub
	*/
namespace VecWzskVStub {
	const Sbecore::uint STUBWZSKPRSSTD = 1;
	const Sbecore::uint STUBWZSKSESMENU = 2;
	const Sbecore::uint STUBWZSKSESSTD = 3;
	const Sbecore::uint STUBWZSKOWNER = 4;
	const Sbecore::uint STUBWZSKUSRSTD = 5;
	const Sbecore::uint STUBWZSKGROUP = 6;
	const Sbecore::uint STUBWZSKUSGSTD = 7;
	const Sbecore::uint STUBWZSKOGRHSREF = 8;
	const Sbecore::uint STUBWZSKOGRSTD = 9;
	const Sbecore::uint STUBWZSKSHTSTD = 10;
	const Sbecore::uint STUBWZSKOBJSTD = 11;
	const Sbecore::uint STUBWZSKFILSTD = 12;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

