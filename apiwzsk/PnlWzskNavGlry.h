/**
	* \file PnlWzskNavGlry.h
	* API code for job PnlWzskNavGlry (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 11 Mar 2021
	*/
// IP header --- ABOVE

#ifndef PNLWZSKNAVGLRY_H
#define PNLWZSKNAVGLRY_H

#include "ApiWzsk_blks.h"

#define VecVWzskNavGlryDo PnlWzskNavGlry::VecVDo

#define ContIacWzskNavGlry PnlWzskNavGlry::ContIac
#define StatAppWzskNavGlry PnlWzskNavGlry::StatApp
#define StatShrWzskNavGlry PnlWzskNavGlry::StatShr
#define TagWzskNavGlry PnlWzskNavGlry::Tag

#define DpchAppWzskNavGlryData PnlWzskNavGlry::DpchAppData
#define DpchAppWzskNavGlryDo PnlWzskNavGlry::DpchAppDo
#define DpchEngWzskNavGlryData PnlWzskNavGlry::DpchEngData

/**
	* PnlWzskNavGlry
	*/
namespace PnlWzskNavGlry {
	/**
		* VecVDo (full: VecVWzskNavGlryDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTOGRVIEWCLICK = 1;
		static const Sbecore::uint BUTOGRNEWCRDCLICK = 2;
		static const Sbecore::uint BUTOBJVIEWCLICK = 3;
		static const Sbecore::uint BUTOBJNEWCRDCLICK = 4;
		static const Sbecore::uint BUTSESVIEWCLICK = 5;
		static const Sbecore::uint BUTSESNEWCRDCLICK = 6;
		static const Sbecore::uint BUTSHTVIEWCLICK = 7;
		static const Sbecore::uint BUTSHTNEWCRDCLICK = 8;
		static const Sbecore::uint BUTFILVIEWCLICK = 9;
		static const Sbecore::uint BUTFILNEWCRDCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskNavGlry)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTOGR = 1;
		static const Sbecore::uint NUMFLSTOBJ = 2;
		static const Sbecore::uint NUMFLSTSES = 3;
		static const Sbecore::uint NUMFLSTSHT = 4;
		static const Sbecore::uint NUMFLSTFIL = 5;

	public:
		ContIac(const Sbecore::uint numFLstOgr = 1, const Sbecore::uint numFLstObj = 1, const Sbecore::uint numFLstSes = 1, const Sbecore::uint numFLstSht = 1, const Sbecore::uint numFLstFil = 1);

	public:
		Sbecore::uint numFLstOgr;
		Sbecore::uint numFLstObj;
		Sbecore::uint numFLstSes;
		Sbecore::uint numFLstSht;
		Sbecore::uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWzskNavGlry)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint LSTOGRALT = 2;
		static const Sbecore::uint LSTOBJALT = 3;
		static const Sbecore::uint LSTSESALT = 4;
		static const Sbecore::uint LSTSHTALT = 5;
		static const Sbecore::uint LSTFILALT = 6;
		static const Sbecore::uint LSTOGRNUMFIRSTDISP = 7;
		static const Sbecore::uint LSTOBJNUMFIRSTDISP = 8;
		static const Sbecore::uint LSTSESNUMFIRSTDISP = 9;
		static const Sbecore::uint LSTSHTNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTFILNUMFIRSTDISP = 11;

	public:
		StatApp(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstOgrAlt = true, const bool LstObjAlt = true, const bool LstSesAlt = true, const bool LstShtAlt = true, const bool LstFilAlt = true, const Sbecore::uint LstOgrNumFirstdisp = 1, const Sbecore::uint LstObjNumFirstdisp = 1, const Sbecore::uint LstSesNumFirstdisp = 1, const Sbecore::uint LstShtNumFirstdisp = 1, const Sbecore::uint LstFilNumFirstdisp = 1);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool LstOgrAlt;
		bool LstObjAlt;
		bool LstSesAlt;
		bool LstShtAlt;
		bool LstFilAlt;
		Sbecore::uint LstOgrNumFirstdisp;
		Sbecore::uint LstObjNumFirstdisp;
		Sbecore::uint LstSesNumFirstdisp;
		Sbecore::uint LstShtNumFirstdisp;
		Sbecore::uint LstFilNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskNavGlry)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTOGRAVAIL = 1;
		static const Sbecore::uint BUTOGRVIEWACTIVE = 2;
		static const Sbecore::uint LSTOBJAVAIL = 3;
		static const Sbecore::uint BUTOBJVIEWACTIVE = 4;
		static const Sbecore::uint LSTSESAVAIL = 5;
		static const Sbecore::uint BUTSESVIEWACTIVE = 6;
		static const Sbecore::uint LSTSHTAVAIL = 7;
		static const Sbecore::uint BUTSHTVIEWACTIVE = 8;
		static const Sbecore::uint LSTFILAVAIL = 9;
		static const Sbecore::uint BUTFILVIEWACTIVE = 10;

	public:
		StatShr(const bool LstOgrAvail = true, const bool ButOgrViewActive = true, const bool LstObjAvail = true, const bool ButObjViewActive = true, const bool LstSesAvail = true, const bool ButSesViewActive = true, const bool LstShtAvail = true, const bool ButShtViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool LstOgrAvail;
		bool ButOgrViewActive;
		bool LstObjAvail;
		bool ButObjViewActive;
		bool LstSesAvail;
		bool ButSesViewActive;
		bool LstShtAvail;
		bool ButShtViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskNavGlry)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTOGR = 2;
		static const Sbecore::uint CPTOBJ = 3;
		static const Sbecore::uint CPTSES = 4;
		static const Sbecore::uint CPTSHT = 5;
		static const Sbecore::uint CPTFIL = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptOgr = "", const std::string& CptObj = "", const std::string& CptSes = "", const std::string& CptSht = "", const std::string& CptFil = "");

	public:
		std::string Cpt;
		std::string CptOgr;
		std::string CptObj;
		std::string CptSes;
		std::string CptSht;
		std::string CptFil;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskNavGlryData)
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
		* DpchAppDo (full: DpchAppWzskNavGlryDo)
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
		* DpchEngData (full: DpchEngWzskNavGlryData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFIL = 3;
		static const Sbecore::uint FEEDFLSTOBJ = 4;
		static const Sbecore::uint FEEDFLSTOGR = 5;
		static const Sbecore::uint FEEDFLSTSES = 6;
		static const Sbecore::uint FEEDFLSTSHT = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstFil;
		Sbecore::Feed feedFLstObj;
		Sbecore::Feed feedFLstOgr;
		Sbecore::Feed feedFLstSes;
		Sbecore::Feed feedFLstSht;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
