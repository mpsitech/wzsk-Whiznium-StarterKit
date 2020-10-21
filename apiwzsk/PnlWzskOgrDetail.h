/**
	* \file PnlWzskOgrDetail.h
	* API code for job PnlWzskOgrDetail (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef PNLWZSKOGRDETAIL_H
#define PNLWZSKOGRDETAIL_H

#include "ApiWzsk_blks.h"

#define VecVWzskOgrDetailDo PnlWzskOgrDetail::VecVDo

#define ContIacWzskOgrDetail PnlWzskOgrDetail::ContIac
#define ContInfWzskOgrDetail PnlWzskOgrDetail::ContInf
#define StatAppWzskOgrDetail PnlWzskOgrDetail::StatApp
#define StatShrWzskOgrDetail PnlWzskOgrDetail::StatShr
#define TagWzskOgrDetail PnlWzskOgrDetail::Tag

#define DpchAppWzskOgrDetailData PnlWzskOgrDetail::DpchAppData
#define DpchAppWzskOgrDetailDo PnlWzskOgrDetail::DpchAppDo
#define DpchEngWzskOgrDetailData PnlWzskOgrDetail::DpchEngData

/**
	* PnlWzskOgrDetail
	*/
namespace PnlWzskOgrDetail {
	/**
		* VecVDo (full: VecVWzskOgrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJEDITCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskOgrDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJ = 1;
		static const Sbecore::uint TXFCMT = 2;

	public:
		ContIac(const Sbecore::uint numFPupJ = 1, const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupJ;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskOgrDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTSUP = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtSup = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtSup;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskOgrDetail)
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
	  * StatShr (full: StatShrWzskOgrDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPJACTIVE = 4;
		static const Sbecore::uint BUTJEDITAVAIL = 5;
		static const Sbecore::uint TXTTITACTIVE = 6;
		static const Sbecore::uint TXTSUPACTIVE = 7;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 8;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtTitActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtTitActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskOgrDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSRF = 2;
		static const Sbecore::uint CPTTIT = 3;
		static const Sbecore::uint CPTSUP = 4;
		static const Sbecore::uint CPTCMT = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSrf = "", const std::string& CptTit = "", const std::string& CptSup = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptSrf;
		std::string CptTit;
		std::string CptSup;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskOgrDetailData)
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
		* DpchAppDo (full: DpchAppWzskOgrDetailDo)
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
		* DpchEngData (full: DpchEngWzskOgrDetailData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJ = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJ;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

