/**
	* \file PnlWzskPrsList.h
	* API code for job PnlWzskPrsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRSLIST_H
#define PNLWZSKPRSLIST_H

#include "ApiWzsk_blks.h"

#include "WzskQPrsList.h"

#include "QryWzskPrsList.h"

#define VecVWzskPrsListDo PnlWzskPrsList::VecVDo

#define ContIacWzskPrsList PnlWzskPrsList::ContIac
#define ContInfWzskPrsList PnlWzskPrsList::ContInf
#define StatShrWzskPrsList PnlWzskPrsList::StatShr
#define StgIacWzskPrsList PnlWzskPrsList::StgIac
#define TagWzskPrsList PnlWzskPrsList::Tag

#define DpchAppWzskPrsListData PnlWzskPrsList::DpchAppData
#define DpchAppWzskPrsListDo PnlWzskPrsList::DpchAppDo
#define DpchEngWzskPrsListData PnlWzskPrsList::DpchEngData

/**
	* PnlWzskPrsList
	*/
namespace PnlWzskPrsList {
	/**
		* VecVDo (full: VecVWzskPrsListDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDELETECLICK = 4;
		static const Sbecore::uint BUTFILTERCLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrsList)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFTOS = 1;

	public:
		ContIac(const Sbecore::uint numFTos = 1);

	public:
		Sbecore::uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskPrsList)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTFILTERON = 1;
		static const Sbecore::uint NUMFCSIQST = 2;

	public:
		ContInf(const bool ButFilterOn = false, const Sbecore::uint numFCsiQst = 1);

	public:
		bool ButFilterOn;
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskPrsList)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWzskPrsList)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOGRPWIDTH = 1;
		static const Sbecore::uint TCOOWNWIDTH = 2;
		static const Sbecore::uint TCOTITWIDTH = 3;
		static const Sbecore::uint TCOFNMWIDTH = 4;
		static const Sbecore::uint TCOLNMWIDTH = 5;
		static const Sbecore::uint TCOSEXWIDTH = 6;
		static const Sbecore::uint TCOTELWIDTH = 7;
		static const Sbecore::uint TCOEMLWIDTH = 8;

	public:
		StgIac(const Sbecore::uint TcoGrpWidth = 80, const Sbecore::uint TcoOwnWidth = 80, const Sbecore::uint TcoTitWidth = 60, const Sbecore::uint TcoFnmWidth = 100, const Sbecore::uint TcoLnmWidth = 120, const Sbecore::uint TcoSexWidth = 60, const Sbecore::uint TcoTelWidth = 100, const Sbecore::uint TcoEmlWidth = 100);

	public:
		Sbecore::uint TcoGrpWidth;
		Sbecore::uint TcoOwnWidth;
		Sbecore::uint TcoTitWidth;
		Sbecore::uint TcoFnmWidth;
		Sbecore::uint TcoLnmWidth;
		Sbecore::uint TcoSexWidth;
		Sbecore::uint TcoTelWidth;
		Sbecore::uint TcoEmlWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWzskPrsList)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOGRP = 7;
		static const Sbecore::uint TCOOWN = 8;
		static const Sbecore::uint TCOTIT = 9;
		static const Sbecore::uint TCOFNM = 10;
		static const Sbecore::uint TCOLNM = 11;
		static const Sbecore::uint TCOSEX = 12;
		static const Sbecore::uint TCOTEL = 13;
		static const Sbecore::uint TCOEML = 14;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoGrp = "", const std::string& TcoOwn = "", const std::string& TcoTit = "", const std::string& TcoFnm = "", const std::string& TcoLnm = "", const std::string& TcoSex = "", const std::string& TcoTel = "", const std::string& TcoEml = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoGrp;
		std::string TcoOwn;
		std::string TcoTit;
		std::string TcoFnm;
		std::string TcoLnm;
		std::string TcoSex;
		std::string TcoTel;
		std::string TcoEml;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrsListData)
		*/
	class DpchAppData : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWzskPrsList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWzskPrsList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWzskPrsListDo)
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
		* DpchEngData (full: DpchEngWzskPrsListData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFCSIQST = 4;
		static const Sbecore::uint FEEDFTOS = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint STGIAC = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint RST = 9;
		static const Sbecore::uint STATAPPQRY = 10;
		static const Sbecore::uint STATSHRQRY = 11;
		static const Sbecore::uint STGIACQRY = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		Sbecore::Xmlio::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWzskQPrsList rst;
		QryWzskPrsList::StatApp statappqry;
		QryWzskPrsList::StatShr statshrqry;
		QryWzskPrsList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
