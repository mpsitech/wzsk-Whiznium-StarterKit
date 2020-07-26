/**
	* \file VecWzskVOpengtype.h
	* vector VecWzskVOpengtype (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
	void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif
