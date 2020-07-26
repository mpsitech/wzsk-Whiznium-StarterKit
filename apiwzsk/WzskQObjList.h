/**
	* \file WzskQObjList.h
	* API code for table TblWzskQObjList (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQOBJLIST_H
#define WZSKQOBJLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzskQObjList
	*/
class WzskQObjList {

public:
	WzskQObjList(const Sbecore::uint jnum = 0, const std::string Title = "", const std::string stubRefWzskMObjgroup = "");

public:
	Sbecore::uint jnum;
	std::string Title;
	std::string stubRefWzskMObjgroup;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQObjList
	*/
class ListWzskQObjList {

public:
	ListWzskQObjList();
	ListWzskQObjList(const ListWzskQObjList& src);
	ListWzskQObjList& operator=(const ListWzskQObjList& src);
	~ListWzskQObjList();

	void clear();

public:
	std::vector<WzskQObjList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

