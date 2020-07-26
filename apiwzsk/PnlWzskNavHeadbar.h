/**
	* \file PnlWzskNavHeadbar.h
	* API code for job PnlWzskNavHeadbar (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef PNLWZSKNAVHEADBAR_H
#define PNLWZSKNAVHEADBAR_H

#include "ApiWzsk_blks.h"

#define StatShrWzskNavHeadbar PnlWzskNavHeadbar::StatShr
#define StgInfWzskNavHeadbar PnlWzskNavHeadbar::StgInf
#define TagWzskNavHeadbar PnlWzskNavHeadbar::Tag

#define DpchEngWzskNavHeadbarData PnlWzskNavHeadbar::DpchEngData

/**
	* PnlWzskNavHeadbar
	*/
namespace PnlWzskNavHeadbar {
	/**
	  * StatShr (full: StatShrWzskNavHeadbar)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgInf (full: StgInfWzskNavHeadbar)
	  */
	class StgInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENAPPCPTWIDTH = 1;
		static const Sbecore::uint MENAPPWIDTH = 2;
		static const Sbecore::uint MENSESCPTWIDTH = 3;
		static const Sbecore::uint MENSESWIDTH = 4;
		static const Sbecore::uint MENCRDCPTWIDTH = 5;
		static const Sbecore::uint MENCRDWIDTH = 6;

	public:
		StgInf(const Sbecore::uint MenAppCptwidth = 100, const Sbecore::uint MenAppWidth = 100, const Sbecore::uint MenSesCptwidth = 100, const Sbecore::uint MenSesWidth = 100, const Sbecore::uint MenCrdCptwidth = 100, const Sbecore::uint MenCrdWidth = 100);

	public:
		Sbecore::uint MenAppCptwidth;
		Sbecore::uint MenAppWidth;
		Sbecore::uint MenSesCptwidth;
		Sbecore::uint MenSesWidth;
		Sbecore::uint MenCrdCptwidth;
		Sbecore::uint MenCrdWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StgInf* comp);
		std::set<Sbecore::uint> diff(const StgInf* comp);
	};

	/**
	  * Tag (full: TagWzskNavHeadbar)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENAPP = 1;
		static const Sbecore::uint MENSES = 2;
		static const Sbecore::uint MENCRD = 3;

	public:
		Tag(const std::string& MenApp = "", const std::string& MenSes = "", const std::string& MenCrd = "");

	public:
		std::string MenApp;
		std::string MenSes;
		std::string MenCrd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskNavHeadbarData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint STGINF = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		StatShr statshr;
		StgInf stginf;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
