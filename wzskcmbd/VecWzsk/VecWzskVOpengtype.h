/**
	* \file VecWzskVOpengtype.h
	* vector VecWzskVOpengtype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef VECWZSKVOPENGTYPE_H
#define VECWZSKVOPENGTYPE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzskVOpengtype
	*/
namespace VecWzskVOpengtype {

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
};

#endif
