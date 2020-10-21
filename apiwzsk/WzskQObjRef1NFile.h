/**
	* \file WzskQObjRef1NFile.h
	* API code for table TblWzskQObjRef1NFile (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef WZSKQOBJREF1NFILE_H
#define WZSKQOBJREF1NFILE_H

#include <sbecore/Xmlio.h>

/**
	* WzskQObjRef1NFile
	*/
class WzskQObjRef1NFile {

public:
	WzskQObjRef1NFile(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzskQObjRef1NFile
	*/
class ListWzskQObjRef1NFile {

public:
	ListWzskQObjRef1NFile();
	ListWzskQObjRef1NFile(const ListWzskQObjRef1NFile& src);
	ListWzskQObjRef1NFile& operator=(const ListWzskQObjRef1NFile& src);
	~ListWzskQObjRef1NFile();

	void clear();

public:
	std::vector<WzskQObjRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

