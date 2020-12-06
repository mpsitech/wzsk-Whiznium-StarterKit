/**
	* \file PnlWzskShtDetail.h
	* API code for job PnlWzskShtDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKSHTDETAIL_H
#define PNLWZSKSHTDETAIL_H

#include "ApiWzsk_blks.h"

#define VecVWzskShtDetailDo PnlWzskShtDetail::VecVDo

#define ContIacWzskShtDetail PnlWzskShtDetail::ContIac
#define ContInfWzskShtDetail PnlWzskShtDetail::ContInf
#define StatAppWzskShtDetail PnlWzskShtDetail::StatApp
#define StatShrWzskShtDetail PnlWzskShtDetail::StatShr
#define TagWzskShtDetail PnlWzskShtDetail::Tag

#define DpchAppWzskShtDetailData PnlWzskShtDetail::DpchAppData
#define DpchAppWzskShtDetailDo PnlWzskShtDetail::DpchAppDo
#define DpchEngWzskShtDetailData PnlWzskShtDetail::DpchEngData

/**
	* PnlWzskShtDetail
	*/
namespace PnlWzskShtDetail {
	/**
		* VecVDo (full: VecVWzskShtDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTSESVIEWCLICK = 2;
		static const Sbecore::uint BUTOBJVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskShtDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSTA = 1;
		static const Sbecore::uint TXFCMT = 2;

	public:
		ContIac(const std::string& TxfSta = "", const std::string& TxfCmt = "");

	public:
		std::string TxfSta;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskShtDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSES = 1;
		static const Sbecore::uint TXTOBJ = 2;

	public:
		ContInf(const std::string& TxtSes = "", const std::string& TxtObj = "");

	public:
		std::string TxtSes;
		std::string TxtObj;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskShtDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND);

	public:
		Sbecore::uint ixWzskVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskShtDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSESACTIVE = 3;
		static const Sbecore::uint BUTSESVIEWAVAIL = 4;
		static const Sbecore::uint BUTSESVIEWACTIVE = 5;
		static const Sbecore::uint TXTOBJACTIVE = 6;
		static const Sbecore::uint BUTOBJVIEWAVAIL = 7;
		static const Sbecore::uint BUTOBJVIEWACTIVE = 8;
		static const Sbecore::uint TXFSTAACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSesActive = true, const bool ButSesViewAvail = true, const bool ButSesViewActive = true, const bool TxtObjActive = true, const bool ButObjViewAvail = true, const bool ButObjViewActive = true, const bool TxfStaActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSesActive;
		bool ButSesViewAvail;
		bool ButSesViewActive;
		bool TxtObjActive;
		bool ButObjViewAvail;
		bool ButObjViewActive;
		bool TxfStaActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskShtDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSES = 2;
		static const Sbecore::uint CPTOBJ = 3;
		static const Sbecore::uint CPTSTA = 4;
		static const Sbecore::uint CPTCMT = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSes = "", const std::string& CptObj = "", const std::string& CptSta = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSes;
		std::string CptObj;
		std::string CptSta;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskShtDetailData)
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
		* DpchAppDo (full: DpchAppWzskShtDetailDo)
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
		* DpchEngData (full: DpchEngWzskShtDetailData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
