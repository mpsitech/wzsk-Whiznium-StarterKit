/**
	* \file PnlWzskNavOp.h
	* API code for job PnlWzskNavOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKNAVOP_H
#define PNLWZSKNAVOP_H

#include "ApiWzsk_blks.h"

#define VecVWzskNavOpDo PnlWzskNavOp::VecVDo

#define ContIacWzskNavOp PnlWzskNavOp::ContIac
#define StatAppWzskNavOp PnlWzskNavOp::StatApp
#define StatShrWzskNavOp PnlWzskNavOp::StatShr
#define TagWzskNavOp PnlWzskNavOp::Tag

#define DpchAppWzskNavOpData PnlWzskNavOp::DpchAppData
#define DpchAppWzskNavOpDo PnlWzskNavOp::DpchAppDo
#define DpchEngWzskNavOpData PnlWzskNavOp::DpchEngData

/**
	* PnlWzskNavOp
	*/
namespace PnlWzskNavOp {
	/**
		* VecVDo (full: VecVWzskNavOpDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTLLVNEWCRDCLICK = 1;
		static const Sbecore::uint BUTVTRNEWCRDCLICK = 2;
		static const Sbecore::uint BUTHWCNEWCRDCLICK = 3;
		static const Sbecore::uint BUTFILVIEWCLICK = 4;
		static const Sbecore::uint BUTFILNEWCRDCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskNavOp)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTFIL = 1;

	public:
		ContIac(const Sbecore::uint numFLstFil = 1);

	public:
		Sbecore::uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWzskNavOp)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint LSTFILALT = 2;
		static const Sbecore::uint LSTFILNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstFilAlt = true, const Sbecore::uint LstFilNumFirstdisp = 1);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool LstFilAlt;
		Sbecore::uint LstFilNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskNavOp)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTLLVNEWCRDAVAIL = 1;
		static const Sbecore::uint BUTVTRNEWCRDAVAIL = 2;
		static const Sbecore::uint BUTHWCNEWCRDAVAIL = 3;
		static const Sbecore::uint LSTFILAVAIL = 4;
		static const Sbecore::uint BUTFILVIEWACTIVE = 5;

	public:
		StatShr(const bool ButLlvNewcrdAvail = true, const bool ButVtrNewcrdAvail = true, const bool ButHwcNewcrdAvail = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool ButLlvNewcrdAvail;
		bool ButVtrNewcrdAvail;
		bool ButHwcNewcrdAvail;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskNavOp)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTLLV = 2;
		static const Sbecore::uint CPTVTR = 3;
		static const Sbecore::uint CPTHWC = 4;
		static const Sbecore::uint CPTFIL = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptLlv = "", const std::string& CptVtr = "", const std::string& CptHwc = "", const std::string& CptFil = "");

	public:
		std::string Cpt;
		std::string CptLlv;
		std::string CptVtr;
		std::string CptHwc;
		std::string CptFil;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskNavOpData)
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
		* DpchAppDo (full: DpchAppWzskNavOpDo)
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
		* DpchEngData (full: DpchEngWzskNavOpData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFIL = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstFil;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
