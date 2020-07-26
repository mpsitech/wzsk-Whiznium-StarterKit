/**
	* \file WzskQUsgMNUser.h
	* API code for table TblWzskQUsgMNUser (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQUSGMNUSER_H
#define WZSKQUSGMNUSER_H

#include <sbecore/Xmlio.h>

/**
	* WzskQUsgMNUser
	*/
class WzskQUsgMNUser {

public:
	WzskQUsgMNUser(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxWzskVUserlevel;
	std::string titIxWzskVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQUsgMNUser
	*/
class ListWzskQUsgMNUser {

public:
	ListWzskQUsgMNUser();
	ListWzskQUsgMNUser(const ListWzskQUsgMNUser& src);
	ListWzskQUsgMNUser& operator=(const ListWzskQUsgMNUser& src);
	~ListWzskQUsgMNUser();

	void clear();

public:
	std::vector<WzskQUsgMNUser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

