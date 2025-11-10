/**
	* \file PnlWzskPrfAcqPreview.h
	* API code for job PnlWzskPrfAcqPreview (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFACQPREVIEW_H
#define PNLWZSKPRFACQPREVIEW_H

#include "ApiWzsk_blks.h"

#define VecVWzskPrfAcqPreviewDo PnlWzskPrfAcqPreview::VecVDo

#define ContIacWzskPrfAcqPreview PnlWzskPrfAcqPreview::ContIac
#define StatShrWzskPrfAcqPreview PnlWzskPrfAcqPreview::StatShr
#define TagWzskPrfAcqPreview PnlWzskPrfAcqPreview::Tag

#define DpchAppWzskPrfAcqPreviewData PnlWzskPrfAcqPreview::DpchAppData
#define DpchAppWzskPrfAcqPreviewDo PnlWzskPrfAcqPreview::DpchAppDo
#define DpchEngWzskPrfAcqPreviewData PnlWzskPrfAcqPreview::DpchEngData

/**
	* PnlWzskPrfAcqPreview
	*/
namespace PnlWzskPrfAcqPreview {
	/**
		* VecVDo (full: VecVWzskPrfAcqPreviewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfAcqPreview)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint CHK1 = 1;
		static const Sbecore::uint TXF2 = 2;

	public:
		ContIac(const bool Chk1 = false, const std::string& Txf2 = "");

	public:
		bool Chk1;
		std::string Txf2;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatShr (full: StatShrWzskPrfAcqPreview)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint CHK1CLEAN = 2;
		static const Sbecore::uint TXF2CLEAN = 3;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Chk1Clean = false, const bool Txf2Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Chk1Clean;
		bool Txf2Clean;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskPrfAcqPreview)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPT1 = 2;
		static const Sbecore::uint CPT2 = 3;

	public:
		Tag(const std::string& Cpt = "", const std::string& Cpt1 = "", const std::string& Cpt2 = "");

	public:
		std::string Cpt;
		std::string Cpt1;
		std::string Cpt2;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfAcqPreviewData)
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
		* DpchAppDo (full: DpchAppWzskPrfAcqPreviewDo)
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
		* DpchEngData (full: DpchEngWzskPrfAcqPreviewData)
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
