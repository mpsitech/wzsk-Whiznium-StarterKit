/**
	* \file VecWzskVOppack.h
	* vector VecWzskVOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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

