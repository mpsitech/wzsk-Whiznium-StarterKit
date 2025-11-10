/**
	* \file PnlWzskVtrDebug.h
	* API code for job PnlWzskVtrDebug (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKVTRDEBUG_H
#define PNLWZSKVTRDEBUG_H

#include "ApiWzsk_blks.h"

#define VecVWzskVtrDebugDo PnlWzskVtrDebug::VecVDo

#define ContIacWzskVtrDebug PnlWzskVtrDebug::ContIac
#define ContInfWzskVtrDebug PnlWzskVtrDebug::ContInf
#define StatShrWzskVtrDebug PnlWzskVtrDebug::StatShr
#define TagWzskVtrDebug PnlWzskVtrDebug::Tag

#define DpchAppWzskVtrDebugData PnlWzskVtrDebug::DpchAppData
#define DpchAppWzskVtrDebugDo PnlWzskVtrDebug::DpchAppDo
#define DpchEngWzskVtrDebugData PnlWzskVtrDebug::DpchEngData

/**
	* PnlWzskVtrDebug
	*/
namespace PnlWzskVtrDebug {
	/**
		* VecVDo (full: VecVWzskVtrDebugDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTTSRCLICK = 4;
		static const Sbecore::uint BUTTSPCLICK = 5;
		static const Sbecore::uint BUTTTFVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskVtrDebug)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFTFR = 1;

	public:
		ContIac(const std::string& TxfTfr = "");

	public:
		std::string TxfTfr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskVtrDebug)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTTST = 2;
		static const Sbecore::uint TXTTTF = 3;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtTst = "", const std::string& TxtTtf = "");

	public:
		bool ButClaimOn;
		std::string TxtTst;
		std::string TxtTtf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskVtrDebug)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint TXFTFRACTIVE = 3;
		static const Sbecore::uint BUTTSRACTIVE = 4;
		static const Sbecore::uint BUTTSPACTIVE = 5;
		static const Sbecore::uint BUTTTFVIEWACTIVE = 6;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool TxfTfrActive = true, const bool ButTsrActive = true, const bool ButTspActive = true, const bool ButTtfViewActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool TxfTfrActive;
		bool ButTsrActive;
		bool ButTspActive;
		bool ButTtfViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskVtrDebug)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint HDGTRK = 2;
		static const Sbecore::uint CPTTFR = 3;
		static const Sbecore::uint CPTTST = 4;
		static const Sbecore::uint BUTTSR = 5;
		static const Sbecore::uint BUTTSP = 6;
		static const Sbecore::uint CPTTTF = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& HdgTrk = "", const std::string& CptTfr = "", const std::string& CptTst = "", const std::string& ButTsr = "", const std::string& ButTsp = "", const std::string& CptTtf = "");

	public:
		std::string Cpt;
		std::string HdgTrk;
		std::string CptTfr;
		std::string CptTst;
		std::string ButTsr;
		std::string ButTsp;
		std::string CptTtf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskVtrDebugData)
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
		* DpchAppDo (full: DpchAppWzskVtrDebugDo)
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
		* DpchEngData (full: DpchEngWzskVtrDebugData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
