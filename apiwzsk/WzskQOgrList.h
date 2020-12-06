/**
	* \file WzskQOgrList.h
	* API code for table TblWzskQOgrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQOGRLIST_H
#define WZSKQOGRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzskQOgrList
	*/
class WzskQOgrList {

public:
	WzskQOgrList(const Sbecore::uint jnum = 0, const std::string sref = "", const std::string Title = "", const std::string stubSupRefWzskMObjgroup = "");

public:
	Sbecore::uint jnum;
	std::string sref;
	std::string Title;
	std::string stubSupRefWzskMObjgroup;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQOgrList
	*/
class ListWzskQOgrList {

public:
	ListWzskQOgrList();
	ListWzskQOgrList(const ListWzskQOgrList& src);
	ListWzskQOgrList& operator=(const ListWzskQOgrList& src);
	~ListWzskQOgrList();

	void clear();

public:
	std::vector<WzskQOgrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
