/**
	* \file SessWzsk.h
	* API code for job SessWzsk (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef SESSWZSK_H
#define SESSWZSK_H

#include "ApiWzsk_blks.h"

#define StatShrSessWzsk SessWzsk::StatShr

#define DpchEngSessWzskData SessWzsk::DpchEngData

/**
	* SessWzsk
	*/
namespace SessWzsk {
	/**
	  * StatShr (full: StatShrSessWzsk)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFCRDNAV = 1;

	public:
		StatShr(const std::string& scrJrefCrdnav = "");

	public:
		std::string scrJrefCrdnav;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessWzskData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint FEEDFENSSEC = 2;
		static const Sbecore::uint STATSHR = 3;

	public:
		DpchEngData();

	public:
		Sbecore::Xmlio::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

