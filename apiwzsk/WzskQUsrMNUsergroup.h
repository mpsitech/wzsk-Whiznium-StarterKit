/**
	* \file WzskQUsrMNUsergroup.h
	* API code for table TblWzskQUsrMNUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef WZSKQUSRMNUSERGROUP_H
#define WZSKQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

/**
	* WzskQUsrMNUsergroup
	*/
class WzskQUsrMNUsergroup {

public:
	WzskQUsrMNUsergroup(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxWzskVUserlevel;
	std::string titIxWzskVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQUsrMNUsergroup
	*/
class ListWzskQUsrMNUsergroup {

public:
	ListWzskQUsrMNUsergroup();
	ListWzskQUsrMNUsergroup(const ListWzskQUsrMNUsergroup& src);
	ListWzskQUsrMNUsergroup& operator=(const ListWzskQUsrMNUsergroup& src);
	~ListWzskQUsrMNUsergroup();

	void clear();

public:
	std::vector<WzskQUsrMNUsergroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
