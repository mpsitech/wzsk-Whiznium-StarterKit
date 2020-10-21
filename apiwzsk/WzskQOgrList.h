/**
	* \file WzskQOgrList.h
	* API code for table TblWzskQOgrList (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

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

