/**
	* \file VecWzskVSqrgrp.h
	* vector VecWzskVSqrgrp (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef VECWZSKVSQRGRP_H
#define VECWZSKVSQRGRP_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVSqrgrp
	*/
namespace VecWzskVSqrgrp {
	const Sbecore::uint R0 = 1;
	const Sbecore::uint R1 = 2;
	const Sbecore::uint R2 = 3;
	const Sbecore::uint R3 = 4;
	const Sbecore::uint S0 = 5;
	const Sbecore::uint S1 = 6;
	const Sbecore::uint S2 = 7;
	const Sbecore::uint S3 = 8;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

