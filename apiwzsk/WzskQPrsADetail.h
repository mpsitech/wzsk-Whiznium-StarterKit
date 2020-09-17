/**
	* \file WzskQPrsADetail.h
	* API code for table TblWzskQPrsADetail (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKQPRSADETAIL_H
#define WZSKQPRSADETAIL_H

#include <sbecore/Xmlio.h>

/**
	* WzskQPrsADetail
	*/
class WzskQPrsADetail {

public:
	WzskQPrsADetail(const Sbecore::uint jnum = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQPrsADetail
	*/
class ListWzskQPrsADetail {

public:
	ListWzskQPrsADetail();
	ListWzskQPrsADetail(const ListWzskQPrsADetail& src);
	ListWzskQPrsADetail& operator=(const ListWzskQPrsADetail& src);
	~ListWzskQPrsADetail();

	void clear();

public:
	std::vector<WzskQPrsADetail*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

