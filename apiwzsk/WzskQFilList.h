/**
	* \file WzskQFilList.h
	* API code for table TblWzskQFilList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQFILLIST_H
#define WZSKQFILLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzskQFilList
	*/
class WzskQFilList {

public:
	WzskQFilList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Filename = "", const std::string srefRefIxVTbl = "", const std::string titRefIxVTbl = "", const std::string stubRefUref = "", const std::string osrefKContent = "", const std::string titOsrefKContent = "", const std::string srefKMimetype = "", const std::string titSrefKMimetype = "", const Sbecore::usmallint Size = 0);

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Filename;
	std::string srefRefIxVTbl;
	std::string titRefIxVTbl;
	std::string stubRefUref;
	std::string osrefKContent;
	std::string titOsrefKContent;
	std::string srefKMimetype;
	std::string titSrefKMimetype;
	Sbecore::usmallint Size;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQFilList
	*/
class ListWzskQFilList {

public:
	ListWzskQFilList();
	ListWzskQFilList(const ListWzskQFilList& src);
	ListWzskQFilList& operator=(const ListWzskQFilList& src);
	~ListWzskQFilList();

	void clear();

public:
	std::vector<WzskQFilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
