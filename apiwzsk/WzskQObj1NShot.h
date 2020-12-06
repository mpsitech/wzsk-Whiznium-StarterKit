/**
	* \file WzskQObj1NShot.h
	* API code for table TblWzskQObj1NShot (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQOBJ1NSHOT_H
#define WZSKQOBJ1NSHOT_H

#include <sbecore/Xmlio.h>

/**
	* WzskQObj1NShot
	*/
class WzskQObj1NShot {

public:
	WzskQObj1NShot(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQObj1NShot
	*/
class ListWzskQObj1NShot {

public:
	ListWzskQObj1NShot();
	ListWzskQObj1NShot(const ListWzskQObj1NShot& src);
	ListWzskQObj1NShot& operator=(const ListWzskQObj1NShot& src);
	~ListWzskQObj1NShot();

	void clear();

public:
	std::vector<WzskQObj1NShot*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
