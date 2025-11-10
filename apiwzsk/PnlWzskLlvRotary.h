/**
	* \file PnlWzskLlvRotary.h
	* API code for job PnlWzskLlvRotary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKLLVROTARY_H
#define PNLWZSKLLVROTARY_H

#include "ApiWzsk_blks.h"

#define VecVWzskLlvRotaryDo PnlWzskLlvRotary::VecVDo

#define ContIacWzskLlvRotary PnlWzskLlvRotary::ContIac
#define ContInfWzskLlvRotary PnlWzskLlvRotary::ContInf
#define StatShrWzskLlvRotary PnlWzskLlvRotary::StatShr
#define TagWzskLlvRotary PnlWzskLlvRotary::Tag

#define DpchAppWzskLlvRotaryData PnlWzskLlvRotary::DpchAppData
#define DpchAppWzskLlvRotaryDo PnlWzskLlvRotary::DpchAppDo
#define DpchEngWzskLlvRotaryData PnlWzskLlvRotary::DpchEngData

/**
	* PnlWzskLlvRotary
	*/
namespace PnlWzskLlvRotary {
	/**
		* VecVDo (full: VecVWzskLlvRotaryDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLlvRotary)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint SLDTRG = 1;

	public:
		ContIac(const double SldTrg = 0.0);

	public:
		double SldTrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLlvRotary)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;

	public:
		ContInf(const bool ButClaimOn = false);

	public:
		bool ButClaimOn;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskLlvRotary)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint SLDTRGACTIVE = 3;
		static const Sbecore::uint SLDTRGMIN = 4;
		static const Sbecore::uint SLDTRGMAX = 5;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool SldTrgActive = true, const double SldTrgMin = 0, const double SldTrgMax = 360);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool SldTrgActive;
		double SldTrgMin;
		double SldTrgMax;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskLlvRotary)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTTRG = 2;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptTrg = "");

	public:
		std::string Cpt;
		std::string CptTrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskLlvRotaryData)
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
		* DpchAppDo (full: DpchAppWzskLlvRotaryDo)
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
		* DpchEngData (full: DpchEngWzskLlvRotaryData)
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
