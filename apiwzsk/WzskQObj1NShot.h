/**
	* \file WzskQObj1NShot.h
	* API code for table TblWzskQObj1NShot (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

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

