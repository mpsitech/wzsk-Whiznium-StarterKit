/**
	* \file WzskQShtAPar.h
	* API code for table TblWzskQShtAPar (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKQSHTAPAR_H
#define WZSKQSHTAPAR_H

#include <sbecore/Xmlio.h>

/**
	* WzskQShtAPar
	*/
class WzskQShtAPar {

public:
	WzskQShtAPar(const Sbecore::uint jnum = 0, const std::string x1SrefKKey = "", const std::string titX1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKKey;
	std::string titX1SrefKKey;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQShtAPar
	*/
class ListWzskQShtAPar {

public:
	ListWzskQShtAPar();
	ListWzskQShtAPar(const ListWzskQShtAPar& src);
	ListWzskQShtAPar& operator=(const ListWzskQShtAPar& src);
	~ListWzskQShtAPar();

	void clear();

public:
	std::vector<WzskQShtAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

