/**
	* \file WzskQSesList.h
	* API code for table TblWzskQSesList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQSESLIST_H
#define WZSKQSESLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzskQSesList
	*/
class WzskQSesList {

public:
	WzskQSesList(const Sbecore::uint jnum = 0, const std::string stubRefWzskMUser = "", const std::string ftmStart = "", const std::string ftmStop = "", const std::string Ip = "");

public:
	Sbecore::uint jnum;
	std::string stubRefWzskMUser;
	std::string ftmStart;
	std::string ftmStop;
	std::string Ip;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQSesList
	*/
class ListWzskQSesList {

public:
	ListWzskQSesList();
	ListWzskQSesList(const ListWzskQSesList& src);
	ListWzskQSesList& operator=(const ListWzskQSesList& src);
	~ListWzskQSesList();

	void clear();

public:
	std::vector<WzskQSesList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

