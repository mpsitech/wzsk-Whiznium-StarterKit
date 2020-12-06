/**
	* \file WzskQShtRef1NFile.h
	* API code for table TblWzskQShtRef1NFile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKQSHTREF1NFILE_H
#define WZSKQSHTREF1NFILE_H

#include <sbecore/Xmlio.h>

/**
	* WzskQShtRef1NFile
	*/
class WzskQShtRef1NFile {

public:
	WzskQShtRef1NFile(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQShtRef1NFile
	*/
class ListWzskQShtRef1NFile {

public:
	ListWzskQShtRef1NFile();
	ListWzskQShtRef1NFile(const ListWzskQShtRef1NFile& src);
	ListWzskQShtRef1NFile& operator=(const ListWzskQShtRef1NFile& src);
	~ListWzskQShtRef1NFile();

	void clear();

public:
	std::vector<WzskQShtRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
