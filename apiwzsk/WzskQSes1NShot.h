/**
	* \file WzskQSes1NShot.h
	* API code for table TblWzskQSes1NShot (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQSES1NSHOT_H
#define WZSKQSES1NSHOT_H

#include <sbecore/Xmlio.h>

/**
	* WzskQSes1NShot
	*/
class WzskQSes1NShot {

public:
	WzskQSes1NShot(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQSes1NShot
	*/
class ListWzskQSes1NShot {

public:
	ListWzskQSes1NShot();
	ListWzskQSes1NShot(const ListWzskQSes1NShot& src);
	ListWzskQSes1NShot& operator=(const ListWzskQSes1NShot& src);
	~ListWzskQSes1NShot();

	void clear();

public:
	std::vector<WzskQSes1NShot*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

