/**
	* \file WzskQUsrMNUsergroup.h
	* API code for table TblWzskQUsrMNUsergroup (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

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

