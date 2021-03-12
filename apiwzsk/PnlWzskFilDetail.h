/**
	* \file PnlWzskFilDetail.h
	* API code for job PnlWzskFilDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKFILDETAIL_H
#define PNLWZSKFILDETAIL_H

#include "ApiWzsk_blks.h"

#define VecVWzskFilDetailDo PnlWzskFilDetail::VecVDo

#define ContIacWzskFilDetail PnlWzskFilDetail::ContIac
#define ContInfWzskFilDetail PnlWzskFilDetail::ContInf
#define StatAppWzskFilDetail PnlWzskFilDetail::StatApp
#define StatShrWzskFilDetail PnlWzskFilDetail::StatShr
#define TagWzskFilDetail PnlWzskFilDetail::Tag

#define DpchAppWzskFilDetailData PnlWzskFilDetail::DpchAppData
#define DpchAppWzskFilDetailDo PnlWzskFilDetail::DpchAppDo
#define DpchEngWzskFilDetailData PnlWzskFilDetail::DpchEngData

/**
	* PnlWzskFilDetail
	*/
namespace PnlWzskFilDetail {
	/**
		* VecVDo (full: VecVWzskFilDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTREUVIEWCLICK = 5;
		static const Sbecore::uint BUTCNTEDITCLICK = 6;
		static const Sbecore::uint BUTMIMEDITCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskFilDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFFNM = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint NUMFPUPRET = 3;
		static const Sbecore::uint NUMFPUPCNT = 4;
		static const Sbecore::uint TXFCNT = 5;
		static const Sbecore::uint TXFACV = 6;
		static const Sbecore::uint TXFANM = 7;
		static const Sbecore::uint NUMFPUPMIM = 8;
		static const Sbecore::uint TXFMIM = 9;
		static const Sbecore::uint TXFSIZ = 10;
		static const Sbecore::uint TXFCMT = 11;

	public:
		ContIac(const std::string& TxfFnm = "", const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupCnt = 1, const std::string& TxfCnt = "", const std::string& TxfAcv = "", const std::string& TxfAnm = "", const Sbecore::uint numFPupMim = 1, const std::string& TxfMim = "", const std::string& TxfSiz = "", const std::string& TxfCmt = "");

	public:
		std::string TxfFnm;
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupCnt;
		std::string TxfCnt;
		std::string TxfAcv;
		std::string TxfAnm;
		Sbecore::uint numFPupMim;
		std::string TxfMim;
		std::string TxfSiz;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskFilDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTCLU = 1;
		static const Sbecore::uint TXTREU = 2;

	public:
		ContInf(const std::string& TxtClu = "", const std::string& TxtReu = "");

	public:
		std::string TxtClu;
		std::string TxtReu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskFilDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint PUPCNTALT = 3;
		static const Sbecore::uint PUPMIMALT = 4;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 5;

	public:
		StatApp(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool LstCluAlt;
		bool PupCntAlt;
		bool PupMimAlt;
		Sbecore::uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskFilDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCNTVALID = 1;
		static const Sbecore::uint TXFMIMVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXFFNMACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint PUPCNTACTIVE = 13;
		static const Sbecore::uint BUTCNTEDITAVAIL = 14;
		static const Sbecore::uint TXFACVACTIVE = 15;
		static const Sbecore::uint TXFANMACTIVE = 16;
		static const Sbecore::uint PUPMIMACTIVE = 17;
		static const Sbecore::uint BUTMIMEDITAVAIL = 18;
		static const Sbecore::uint TXFSIZACTIVE = 19;
		static const Sbecore::uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool TxfCntValid = false, const bool TxfMimValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfFnmActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupCntActive = true, const bool ButCntEditAvail = true, const bool TxfAcvActive = true, const bool TxfAnmActive = true, const bool PupMimActive = true, const bool ButMimEditAvail = true, const bool TxfSizActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfCntValid;
		bool TxfMimValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfFnmActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupCntActive;
		bool ButCntEditAvail;
		bool TxfAcvActive;
		bool TxfAnmActive;
		bool PupMimActive;
		bool ButMimEditAvail;
		bool TxfSizActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskFilDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTFNM = 2;
		static const Sbecore::uint CPTCLU = 3;
		static const Sbecore::uint CPTREU = 4;
		static const Sbecore::uint CPTCNT = 5;
		static const Sbecore::uint CPTACV = 6;
		static const Sbecore::uint CPTANM = 7;
		static const Sbecore::uint CPTMIM = 8;
		static const Sbecore::uint CPTSIZ = 9;
		static const Sbecore::uint CPTCMT = 10;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptFnm = "", const std::string& CptClu = "", const std::string& CptReu = "", const std::string& CptCnt = "", const std::string& CptAcv = "", const std::string& CptAnm = "", const std::string& CptMim = "", const std::string& CptSiz = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptFnm;
		std::string CptClu;
		std::string CptReu;
		std::string CptCnt;
		std::string CptAcv;
		std::string CptAnm;
		std::string CptMim;
		std::string CptSiz;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskFilDetailData)
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
		* DpchAppDo (full: DpchAppWzskFilDetailDo)
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
		* DpchEngData (full: DpchEngWzskFilDetailData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPCNT = 5;
		static const Sbecore::uint FEEDFPUPMIM = 6;
		static const Sbecore::uint FEEDFPUPRET = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFPupCnt;
		Sbecore::Feed feedFPupMim;
		Sbecore::Feed feedFPupRet;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
