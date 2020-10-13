/**
	* \file WzskQUsrList.h
	* API code for table TblWzskQUsrList (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef WZSKQUSRLIST_H
#define WZSKQUSRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzskQUsrList
	*/
class WzskQUsrList {

public:
	WzskQUsrList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string stubRefWzskMPerson = "", const std::string sref = "", const std::string stubRefWzskMUsergroup = "", const std::string srefIxVState = "", const std::string titIxVState = "", const std::string srefIxWzskVLocale = "", const std::string titIxWzskVLocale = "", const std::string srefIxWzskVUserlevel = "", const std::string titIxWzskVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string stubRefWzskMPerson;
	std::string sref;
	std::string stubRefWzskMUsergroup;
	std::string srefIxVState;
	std::string titIxVState;
	std::string srefIxWzskVLocale;
	std::string titIxWzskVLocale;
	std::string srefIxWzskVUserlevel;
	std::string titIxWzskVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQUsrList
	*/
class ListWzskQUsrList {

public:
	ListWzskQUsrList();
	ListWzskQUsrList(const ListWzskQUsrList& src);
	ListWzskQUsrList& operator=(const ListWzskQUsrList& src);
	~ListWzskQUsrList();

	void clear();

public:
	std::vector<WzskQUsrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

