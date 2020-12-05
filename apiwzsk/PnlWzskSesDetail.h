/**
	* \file PnlWzskSesDetail.h
	* API code for job PnlWzskSesDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKSESDETAIL_H
#define PNLWZSKSESDETAIL_H

#include "ApiWzsk_blks.h"

#define VecVWzskSesDetailDo PnlWzskSesDetail::VecVDo

#define ContIacWzskSesDetail PnlWzskSesDetail::ContIac
#define ContInfWzskSesDetail PnlWzskSesDetail::ContInf
#define StatAppWzskSesDetail PnlWzskSesDetail::StatApp
#define StatShrWzskSesDetail PnlWzskSesDetail::StatShr
#define TagWzskSesDetail PnlWzskSesDetail::Tag

#define DpchAppWzskSesDetailData PnlWzskSesDetail::DpchAppData
#define DpchAppWzskSesDetailDo PnlWzskSesDetail::DpchAppDo
#define DpchEngWzskSesDetailData PnlWzskSesDetail::DpchEngData

/**
	* PnlWzskSesDetail
	*/
namespace PnlWzskSesDetail {
	/**
		* VecVDo (full: VecVWzskSesDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTUSRVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskSesDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSTA = 1;
		static const Sbecore::uint TXFSTO = 2;
		static const Sbecore::uint TXFIP = 3;

	public:
		ContIac(const std::string& TxfSta = "", const std::string& TxfSto = "", const std::string& TxfIp = "");

	public:
		std::string TxfSta;
		std::string TxfSto;
		std::string TxfIp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskSesDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTUSR = 1;

	public:
		ContInf(const std::string& TxtUsr = "");

	public:
		std::string TxtUsr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskSesDetail)
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
	  * StatShr (full: StatShrWzskSesDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTUSRACTIVE = 3;
		static const Sbecore::uint BUTUSRVIEWAVAIL = 4;
		static const Sbecore::uint BUTUSRVIEWACTIVE = 5;
		static const Sbecore::uint TXFSTAACTIVE = 6;
		static const Sbecore::uint TXFSTOACTIVE = 7;
		static const Sbecore::uint TXFIPACTIVE = 8;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtUsrActive = true, const bool ButUsrViewAvail = true, const bool ButUsrViewActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfIpActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtUsrActive;
		bool ButUsrViewAvail;
		bool ButUsrViewActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfIpActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskSesDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTUSR = 2;
		static const Sbecore::uint CPTSTA = 3;
		static const Sbecore::uint CPTSTO = 4;
		static const Sbecore::uint CPTIP = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptUsr = "", const std::string& CptSta = "", const std::string& CptSto = "", const std::string& CptIp = "");

	public:
		std::string Cpt;
		std::string CptUsr;
		std::string CptSta;
		std::string CptSto;
		std::string CptIp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskSesDetailData)
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
		* DpchAppDo (full: DpchAppWzskSesDetailDo)
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
		* DpchEngData (full: DpchEngWzskSesDetailData)
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

