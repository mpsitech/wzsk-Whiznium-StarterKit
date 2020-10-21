/**
	* \file WzskQShtList.h
	* API code for table TblWzskQShtList (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKQSHTLIST_H
#define WZSKQSHTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzskQShtList
	*/
class WzskQShtList {

public:
	WzskQShtList(const Sbecore::uint jnum = 0, const std::string stubRefWzskMSession = "", const std::string stubRefWzskMObject = "", const std::string ftmStart = "");

public:
	Sbecore::uint jnum;
	std::string stubRefWzskMSession;
	std::string stubRefWzskMObject;
	std::string ftmStart;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQShtList
	*/
class ListWzskQShtList {

public:
	ListWzskQShtList();
	ListWzskQShtList(const ListWzskQShtList& src);
	ListWzskQShtList& operator=(const ListWzskQShtList& src);
	~ListWzskQShtList();

	void clear();

public:
	std::vector<WzskQShtList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

