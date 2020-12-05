/**
	* \file WzskQOgr1NObject.h
	* API code for table TblWzskQOgr1NObject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQOGR1NOBJECT_H
#define WZSKQOGR1NOBJECT_H

#include <sbecore/Xmlio.h>

/**
	* WzskQOgr1NObject
	*/
class WzskQOgr1NObject {

public:
	WzskQOgr1NObject(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQOgr1NObject
	*/
class ListWzskQOgr1NObject {

public:
	ListWzskQOgr1NObject();
	ListWzskQOgr1NObject(const ListWzskQOgr1NObject& src);
	ListWzskQOgr1NObject& operator=(const ListWzskQOgr1NObject& src);
	~ListWzskQOgr1NObject();

	void clear();

public:
	std::vector<WzskQOgr1NObject*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

