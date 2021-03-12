/**
	* \file RootWzsk.h
	* API code for job RootWzsk (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef ROOTWZSK_H
#define ROOTWZSK_H

#include "ApiWzsk_blks.h"

#define DpchAppRootWzskLogin RootWzsk::DpchAppLogin
#define DpchEngRootWzskData RootWzsk::DpchEngData

/**
	* RootWzsk
	*/
namespace RootWzsk {
	/**
		* DpchAppLogin (full: DpchAppRootWzskLogin)
		*/
	class DpchAppLogin : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchAppLogin(const std::string& scrJref = "", const std::string& username = "", const std::string& password = "", const bool m2mNotReg = false, const bool chksuspsess = false, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngRootWzskData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;

	public:
		DpchEngData();

	public:
		Sbecore::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
