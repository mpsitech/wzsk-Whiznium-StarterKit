/**
	* \file PnlWzskPrfGlobal.h
	* API code for job PnlWzskPrfGlobal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFGLOBAL_H
#define PNLWZSKPRFGLOBAL_H

#include "ApiWzsk_blks.h"

#define VecVWzskPrfGlobalDo PnlWzskPrfGlobal::VecVDo

#define ContIacWzskPrfGlobal PnlWzskPrfGlobal::ContIac
#define StatShrWzskPrfGlobal PnlWzskPrfGlobal::StatShr
#define TagWzskPrfGlobal PnlWzskPrfGlobal::Tag

#define DpchAppWzskPrfGlobalData PnlWzskPrfGlobal::DpchAppData
#define DpchAppWzskPrfGlobalDo PnlWzskPrfGlobal::DpchAppDo
#define DpchEngWzskPrfGlobalData PnlWzskPrfGlobal::DpchEngData

/**
	* PnlWzskPrfGlobal
	*/
namespace PnlWzskPrfGlobal {
	/**
		* VecVDo (full: VecVWzskPrfGlobalDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfGlobal)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF2 = 1;
		static const Sbecore::uint TXF3 = 2;
		static const Sbecore::uint TXF4 = 3;
		static const Sbecore::uint TXF5 = 4;
		static const Sbecore::uint TXF6 = 5;
		static const Sbecore::uint NUMFPUP102 = 6;

	public:
		ContIac(const std::string& Txf2 = "", const std::string& Txf3 = "", const std::string& Txf4 = "", const std::string& Txf5 = "", const std::string& Txf6 = "", const Sbecore::uint numFPup102 = 1);

	public:
		std::string Txf2;
		std::string Txf3;
		std::string Txf4;
		std::string Txf5;
		std::string Txf6;
		Sbecore::uint numFPup102;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatShr (full: StatShrWzskPrfGlobal)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint TXF2CLEAN = 2;
		static const Sbecore::uint TXF3CLEAN = 3;
		static const Sbecore::uint TXF4CLEAN = 4;
		static const Sbecore::uint TXF5CLEAN = 5;
		static const Sbecore::uint TXF6CLEAN = 6;
		static const Sbecore::uint PUP102CLEAN = 7;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Txf2Clean = false, const bool Txf3Clean = false, const bool Txf4Clean = false, const bool Txf5Clean = false, const bool Txf6Clean = false, const bool Pup102Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Txf2Clean;
		bool Txf3Clean;
		bool Txf4Clean;
		bool Txf5Clean;
		bool Txf6Clean;
		bool Pup102Clean;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskPrfGlobal)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint HDG1 = 2;
		static const Sbecore::uint CPT2 = 3;
		static const Sbecore::uint CPT3 = 4;
		static const Sbecore::uint CPT4 = 5;
		static const Sbecore::uint CPT5 = 6;
		static const Sbecore::uint CPT6 = 7;
		static const Sbecore::uint HDG101 = 8;
		static const Sbecore::uint CPT102 = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& Hdg1 = "", const std::string& Cpt2 = "", const std::string& Cpt3 = "", const std::string& Cpt4 = "", const std::string& Cpt5 = "", const std::string& Cpt6 = "", const std::string& Hdg101 = "", const std::string& Cpt102 = "");

	public:
		std::string Cpt;
		std::string Hdg1;
		std::string Cpt2;
		std::string Cpt3;
		std::string Cpt4;
		std::string Cpt5;
		std::string Cpt6;
		std::string Hdg101;
		std::string Cpt102;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfGlobalData)
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
		* DpchAppDo (full: DpchAppWzskPrfGlobalDo)
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
		* DpchEngData (full: DpchEngWzskPrfGlobalData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFPUP102 = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFPup102;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
