/**
	* \file WzskQUsgList.h
	* API code for table TblWzskQUsgList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQUSGLIST_H
#define WZSKQUSGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzskQUsgList
	*/
class WzskQUsgList {

public:
	WzskQUsgList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string sref = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string sref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQUsgList
	*/
class ListWzskQUsgList {

public:
	ListWzskQUsgList();
	ListWzskQUsgList(const ListWzskQUsgList& src);
	ListWzskQUsgList& operator=(const ListWzskQUsgList& src);
	~ListWzskQUsgList();

	void clear();

public:
	std::vector<WzskQUsgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
