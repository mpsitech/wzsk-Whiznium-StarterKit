/**
	* \file WzskQPrsADetail.h
	* API code for table TblWzskQPrsADetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

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
