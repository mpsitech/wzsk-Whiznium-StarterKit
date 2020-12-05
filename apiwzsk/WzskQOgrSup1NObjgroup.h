/**
	* \file WzskQOgrSup1NObjgroup.h
	* API code for table TblWzskQOgrSup1NObjgroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQOGRSUP1NOBJGROUP_H
#define WZSKQOGRSUP1NOBJGROUP_H

#include <sbecore/Xmlio.h>

/**
	* WzskQOgrSup1NObjgroup
	*/
class WzskQOgrSup1NObjgroup {

public:
	WzskQOgrSup1NObjgroup(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQOgrSup1NObjgroup
	*/
class ListWzskQOgrSup1NObjgroup {

public:
	ListWzskQOgrSup1NObjgroup();
	ListWzskQOgrSup1NObjgroup(const ListWzskQOgrSup1NObjgroup& src);
	ListWzskQOgrSup1NObjgroup& operator=(const ListWzskQOgrSup1NObjgroup& src);
	~ListWzskQOgrSup1NObjgroup();

	void clear();

public:
	std::vector<WzskQOgrSup1NObjgroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

