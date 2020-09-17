/**
	* \file PnlWzskLlvLaser.h
	* API code for job PnlWzskLlvLaser (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef PNLWZSKLLVLASER_H
#define PNLWZSKLLVLASER_H

#include "ApiWzsk_blks.h"

#define VecVWzskLlvLaserDo PnlWzskLlvLaser::VecVDo

#define ContIacWzskLlvLaser PnlWzskLlvLaser::ContIac
#define ContInfWzskLlvLaser PnlWzskLlvLaser::ContInf
#define StatShrWzskLlvLaser PnlWzskLlvLaser::StatShr
#define TagWzskLlvLaser PnlWzskLlvLaser::Tag

#define DpchAppWzskLlvLaserData PnlWzskLlvLaser::DpchAppData
#define DpchAppWzskLlvLaserDo PnlWzskLlvLaser::DpchAppDo
#define DpchEngWzskLlvLaserData PnlWzskLlvLaser::DpchEngData

/**
	* PnlWzskLlvLaser
	*/
namespace PnlWzskLlvLaser {
	/**
		* VecVDo (full: VecVWzskLlvLaserDo)
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
	  * ContIac (full: ContIacWzskLlvLaser)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CHKERG = 1;
		static const Sbecore::uint SLDLLE = 2;
		static const Sbecore::uint SLDLRI = 3;

	public:
		ContIac(const bool ChkErg = false, const double SldLle = 0.0, const double SldLri = 0.0);

	public:
		bool ChkErg;
		double SldLle;
		double SldLri;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLlvLaser)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrWzskLlvLaser)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint SLDLLEACTIVE = 3;
		static const Sbecore::uint SLDLLEMIN = 4;
		static const Sbecore::uint SLDLLEMAX = 5;
		static const Sbecore::uint SLDLRIACTIVE = 6;
		static const Sbecore::uint SLDLRIMIN = 7;
		static const Sbecore::uint SLDLRIMAX = 8;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool SldLleActive = true, const double SldLleMin = 0, const double SldLleMax = 100, const bool SldLriActive = true, const double SldLriMin = 0, const double SldLriMax = 100);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool SldLleActive;
		double SldLleMin;
		double SldLleMax;
		bool SldLriActive;
		double SldLriMin;
		double SldLriMax;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskLlvLaser)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTERG = 2;
		static const Sbecore::uint CPTLLE = 3;
		static const Sbecore::uint CPTLRI = 4;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptErg = "", const std::string& CptLle = "", const std::string& CptLri = "");

	public:
		std::string Cpt;
		std::string CptErg;
		std::string CptLle;
		std::string CptLri;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskLlvLaserData)
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
		* DpchAppDo (full: DpchAppWzskLlvLaserDo)
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
		* DpchEngData (full: DpchEngWzskLlvLaserData)
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

