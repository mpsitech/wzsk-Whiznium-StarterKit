/**
	* \file PnlWzskPrfSrcZuvsp.h
	* API code for job PnlWzskPrfSrcZuvsp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFSRCZUVSP_H
#define PNLWZSKPRFSRCZUVSP_H

#include "ApiWzsk_blks.h"

#define VecVWzskPrfSrcZuvspDo PnlWzskPrfSrcZuvsp::VecVDo

#define ContIacWzskPrfSrcZuvsp PnlWzskPrfSrcZuvsp::ContIac
#define StatShrWzskPrfSrcZuvsp PnlWzskPrfSrcZuvsp::StatShr
#define TagWzskPrfSrcZuvsp PnlWzskPrfSrcZuvsp::Tag

#define DpchAppWzskPrfSrcZuvspData PnlWzskPrfSrcZuvsp::DpchAppData
#define DpchAppWzskPrfSrcZuvspDo PnlWzskPrfSrcZuvsp::DpchAppDo
#define DpchEngWzskPrfSrcZuvspData PnlWzskPrfSrcZuvsp::DpchEngData

/**
	* PnlWzskPrfSrcZuvsp
	*/
namespace PnlWzskPrfSrcZuvsp {
	/**
		* VecVDo (full: VecVWzskPrfSrcZuvspDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfSrcZuvsp)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF1 = 1;

	public:
		ContIac(const std::string& Txf1 = "");

	public:
		std::string Txf1;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatShr (full: StatShrWzskPrfSrcZuvsp)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint TXF1CLEAN = 2;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Txf1Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Txf1Clean;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskPrfSrcZuvsp)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPT1 = 2;

	public:
		Tag(const std::string& Cpt = "", const std::string& Cpt1 = "");

	public:
		std::string Cpt;
		std::string Cpt1;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfSrcZuvspData)
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
		* DpchAppDo (full: DpchAppWzskPrfSrcZuvspDo)
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
		* DpchEngData (full: DpchEngWzskPrfSrcZuvspData)
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
