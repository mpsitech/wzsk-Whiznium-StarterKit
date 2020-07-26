/**
	* \file M2msessWzsk.h
	* API code for job M2msessWzsk (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef M2MSESSWZSK_H
#define M2MSESSWZSK_H

#include "ApiWzsk_blks.h"

#define StatShrM2msessWzsk M2msessWzsk::StatShr

#define DpchEngM2msessWzskData M2msessWzsk::DpchEngData

/**
	* M2msessWzsk
	*/
namespace M2msessWzsk {
	/**
	  * StatShr (full: StatShrM2msessWzsk)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFACQPREVIEW = 1;
		static const Sbecore::uint SCRJREFACQPTCLOUD = 2;
		static const Sbecore::uint SCRJREFACTLASER = 3;
		static const Sbecore::uint SCRJREFACTSERVO = 4;
		static const Sbecore::uint SCRJREFIPRCORNER = 5;
		static const Sbecore::uint SCRJREFIPRTRACE = 6;

	public:
		StatShr(const std::string& scrJrefAcqpreview = "", const std::string& scrJrefAcqptcloud = "", const std::string& scrJrefActlaser = "", const std::string& scrJrefActservo = "", const std::string& scrJrefIprcorner = "", const std::string& scrJrefIprtrace = "");

	public:
		std::string scrJrefAcqpreview;
		std::string scrJrefAcqptcloud;
		std::string scrJrefActlaser;
		std::string scrJrefActservo;
		std::string scrJrefIprcorner;
		std::string scrJrefIprtrace;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngM2msessWzskData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STATSHR = 2;

	public:
		DpchEngData();

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

