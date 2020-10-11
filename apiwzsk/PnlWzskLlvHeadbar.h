/**
	* \file PnlWzskLlvHeadbar.h
	* API code for job PnlWzskLlvHeadbar (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef PNLWZSKLLVHEADBAR_H
#define PNLWZSKLLVHEADBAR_H

#include "ApiWzsk_blks.h"

#define StgInfWzskLlvHeadbar PnlWzskLlvHeadbar::StgInf
#define TagWzskLlvHeadbar PnlWzskLlvHeadbar::Tag

#define DpchEngWzskLlvHeadbarData PnlWzskLlvHeadbar::DpchEngData

/**
	* PnlWzskLlvHeadbar
	*/
namespace PnlWzskLlvHeadbar {
	/**
	  * StgInf (full: StgInfWzskLlvHeadbar)
	  */
	class StgInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENAPPCPTWIDTH = 1;
		static const Sbecore::uint MENAPPWIDTH = 2;
		static const Sbecore::uint MENCRDCPTWIDTH = 3;
		static const Sbecore::uint MENCRDWIDTH = 4;

	public:
		StgInf(const Sbecore::uint MenAppCptwidth = 100, const Sbecore::uint MenAppWidth = 100, const Sbecore::uint MenCrdCptwidth = 100, const Sbecore::uint MenCrdWidth = 100);

	public:
		Sbecore::uint MenAppCptwidth;
		Sbecore::uint MenAppWidth;
		Sbecore::uint MenCrdCptwidth;
		Sbecore::uint MenCrdWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StgInf* comp);
		std::set<Sbecore::uint> diff(const StgInf* comp);
	};

	/**
	  * Tag (full: TagWzskLlvHeadbar)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENAPP = 1;
		static const Sbecore::uint MENCRD = 2;

	public:
		Tag(const std::string& MenApp = "", const std::string& MenCrd = "");

	public:
		std::string MenApp;
		std::string MenCrd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskLlvHeadbarData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGINF = 2;
		static const Sbecore::uint TAG = 3;

	public:
		DpchEngData();

	public:
		StgInf stginf;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

