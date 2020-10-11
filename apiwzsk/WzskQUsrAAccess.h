/**
	* \file WzskQUsrAAccess.h
	* API code for table TblWzskQUsrAAccess (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef WZSKQUSRAACCESS_H
#define WZSKQUSRAACCESS_H

#include <sbecore/Xmlio.h>

/**
	* WzskQUsrAAccess
	*/
class WzskQUsrAAccess {

public:
	WzskQUsrAAccess(const Sbecore::uint jnum = 0, const std::string srefX1IxWzskVFeatgroup = "", const std::string titX1IxWzskVFeatgroup = "", const std::string x2FeaSrefUix = "", const std::string srefsIxWzskWAccess = "", const std::string titsIxWzskWAccess = "");

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
	* ListWzskQUsrAAccess
	*/
class ListWzskQUsrAAccess {

public:
	ListWzskQUsrAAccess();
	ListWzskQUsrAAccess(const ListWzskQUsrAAccess& src);
	ListWzskQUsrAAccess& operator=(const ListWzskQUsrAAccess& src);
	~ListWzskQUsrAAccess();

	void clear();

public:
	std::vector<WzskQUsrAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

