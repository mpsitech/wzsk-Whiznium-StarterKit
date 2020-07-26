/**
	* \file WzskQUsr1NSession.h
	* API code for table TblWzskQUsr1NSession (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef WZSKQUSR1NSESSION_H
#define WZSKQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

/**
	* WzskQUsr1NSession
	*/
class WzskQUsr1NSession {

public:
	WzskQUsr1NSession(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQUsr1NSession
	*/
class ListWzskQUsr1NSession {

public:
	ListWzskQUsr1NSession();
	ListWzskQUsr1NSession(const ListWzskQUsr1NSession& src);
	ListWzskQUsr1NSession& operator=(const ListWzskQUsr1NSession& src);
	~ListWzskQUsr1NSession();

	void clear();

public:
	std::vector<WzskQUsr1NSession*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

