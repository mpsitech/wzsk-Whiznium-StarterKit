/**
	* \file WzskQOgr1NShot.h
	* API code for table TblWzskQOgr1NShot (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQOGR1NSHOT_H
#define WZSKQOGR1NSHOT_H

#include <sbecore/Xmlio.h>

/**
	* WzskQOgr1NShot
	*/
class WzskQOgr1NShot {

public:
	WzskQOgr1NShot(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQOgr1NShot
	*/
class ListWzskQOgr1NShot {

public:
	ListWzskQOgr1NShot();
	ListWzskQOgr1NShot(const ListWzskQOgr1NShot& src);
	ListWzskQOgr1NShot& operator=(const ListWzskQOgr1NShot& src);
	~ListWzskQOgr1NShot();

	void clear();

public:
	std::vector<WzskQOgr1NShot*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

