/**
	* \file VecWzskVOppack.h
	* vector VecWzskVOppack (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef VECWZSKVOPPACK_H
#define VECWZSKVOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVOppack
	*/
namespace VecWzskVOppack {

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix);
	std::string getComment(const Sbecore::uint ix);

	void appendToFeed(const Sbecore::uint ix, Sbecore::Xmlio::Feed& feed);
	void fillFeed(Sbecore::Xmlio::Feed& feed);
};

#endif

