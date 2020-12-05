/**
	* \file WzskQPrsList.h
	* API code for table TblWzskQPrsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQPRSLIST_H
#define WZSKQPRSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzskQPrsList
	*/
class WzskQPrsList {

public:
	WzskQPrsList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQPrsList
	*/
class ListWzskQPrsList {

public:
	ListWzskQPrsList();
	ListWzskQPrsList(const ListWzskQPrsList& src);
	ListWzskQPrsList& operator=(const ListWzskQPrsList& src);
	~ListWzskQPrsList();

	void clear();

public:
	std::vector<WzskQPrsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

