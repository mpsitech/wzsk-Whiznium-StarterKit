/**
	* \file WzskQUsgAAccess.h
	* API code for table TblWzskQUsgAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQUSGAACCESS_H
#define WZSKQUSGAACCESS_H

#include <sbecore/Xmlio.h>

/**
	* WzskQUsgAAccess
	*/
class WzskQUsgAAccess {

public:
	WzskQUsgAAccess(const Sbecore::uint jnum = 0, const std::string srefX1IxWzskVFeatgroup = "", const std::string titX1IxWzskVFeatgroup = "", const std::string x2FeaSrefUix = "", const std::string srefsIxWzskWAccess = "", const std::string titsIxWzskWAccess = "");

public:
	Sbecore::uint jnum;
	std::string srefX1IxWzskVFeatgroup;
	std::string titX1IxWzskVFeatgroup;
	std::string x2FeaSrefUix;
	std::string srefsIxWzskWAccess;
	std::string titsIxWzskWAccess;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQUsgAAccess
	*/
class ListWzskQUsgAAccess {

public:
	ListWzskQUsgAAccess();
	ListWzskQUsgAAccess(const ListWzskQUsgAAccess& src);
	ListWzskQUsgAAccess& operator=(const ListWzskQUsgAAccess& src);
	~ListWzskQUsgAAccess();

	void clear();

public:
	std::vector<WzskQUsgAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
