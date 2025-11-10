/**
	* \file PnlWzskPrfAcqCorner.h
	* API code for job PnlWzskPrfAcqCorner (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFACQCORNER_H
#define PNLWZSKPRFACQCORNER_H

#include "ApiWzsk_blks.h"

#define VecVWzskPrfAcqCornerDo PnlWzskPrfAcqCorner::VecVDo

#define ContIacWzskPrfAcqCorner PnlWzskPrfAcqCorner::ContIac
#define StatShrWzskPrfAcqCorner PnlWzskPrfAcqCorner::StatShr
#define TagWzskPrfAcqCorner PnlWzskPrfAcqCorner::Tag

#define DpchAppWzskPrfAcqCornerData PnlWzskPrfAcqCorner::DpchAppData
#define DpchAppWzskPrfAcqCornerDo PnlWzskPrfAcqCorner::DpchAppDo
#define DpchEngWzskPrfAcqCornerData PnlWzskPrfAcqCorner::DpchEngData

/**
	* PnlWzskPrfAcqCorner
	*/
namespace PnlWzskPrfAcqCorner {
	/**
		* VecVDo (full: VecVWzskPrfAcqCornerDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfAcqCorner)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF1 = 1;
		static const Sbecore::uint TXF2 = 2;
		static const Sbecore::uint TXF3 = 3;
		static const Sbecore::uint TXF4 = 4;

	public:
		ContIac(const std::string& Txf1 = "", const std::string& Txf2 = "", const std::string& Txf3 = "", const std::string& Txf4 = "");

	public:
		std::string Txf1;
		std::string Txf2;
		std::string Txf3;
		std::string Txf4;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatShr (full: StatShrWzskPrfAcqCorner)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint TXF1CLEAN = 2;
		static const Sbecore::uint TXF2CLEAN = 3;
		static const Sbecore::uint TXF3CLEAN = 4;
		static const Sbecore::uint TXF4CLEAN = 5;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Txf1Clean = false, const bool Txf2Clean = false, const bool Txf3Clean = false, const bool Txf4Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Txf1Clean;
		bool Txf2Clean;
		bool Txf3Clean;
		bool Txf4Clean;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskPrfAcqCorner)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPT1 = 2;
		static const Sbecore::uint CPT2 = 3;
		static const Sbecore::uint CPT3 = 4;
		static const Sbecore::uint CPT4 = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& Cpt1 = "", const std::string& Cpt2 = "", const std::string& Cpt3 = "", const std::string& Cpt4 = "");

	public:
		std::string Cpt;
		std::string Cpt1;
		std::string Cpt2;
		std::string Cpt3;
		std::string Cpt4;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfAcqCornerData)
		*/
	class DpchAppData : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWzskPrfAcqCornerDo)
		*/
	class DpchAppDo : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWzskPrfAcqCornerData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
