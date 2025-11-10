/**
	* \file PnlWzskVtrConfig.h
	* API code for job PnlWzskVtrConfig (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKVTRCONFIG_H
#define PNLWZSKVTRCONFIG_H

#include "ApiWzsk_blks.h"

#define VecVWzskVtrConfigDo PnlWzskVtrConfig::VecVDo
#define VecVWzskVtrConfigMode PnlWzskVtrConfig::VecVMode

#define ContIacWzskVtrConfig PnlWzskVtrConfig::ContIac
#define ContIacWzskVtrConfigAlign PnlWzskVtrConfig::ContIacAlign
#define ContInfWzskVtrConfig PnlWzskVtrConfig::ContInf
#define StatShrWzskVtrConfig PnlWzskVtrConfig::StatShr
#define TagWzskVtrConfig PnlWzskVtrConfig::Tag

#define DpchAppWzskVtrConfigAlign PnlWzskVtrConfig::DpchAppAlign
#define DpchAppWzskVtrConfigData PnlWzskVtrConfig::DpchAppData
#define DpchAppWzskVtrConfigDo PnlWzskVtrConfig::DpchAppDo
#define DpchEngWzskVtrConfigAlign PnlWzskVtrConfig::DpchEngAlign
#define DpchEngWzskVtrConfigData PnlWzskVtrConfig::DpchEngData
#define DpchEngWzskVtrConfigLive PnlWzskVtrConfig::DpchEngLive

/**
	* PnlWzskVtrConfig
	*/
namespace PnlWzskVtrConfig {
	/**
		* VecVDo (full: VecVWzskVtrConfigDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTSTACLICK = 4;
		static const Sbecore::uint BUTSTOCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVMode (full: VecVWzskVtrConfigMode)
		*/
	class VecVMode {

	public:
		static const Sbecore::uint GRAY = 1;
		static const Sbecore::uint RGB = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskVtrConfig)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFRBUMDE = 1;
		static const Sbecore::uint SLDASP = 2;

	public:
		ContIac(const Sbecore::uint numFRbuMde = 1, const double SldAsp = 0.0);

	public:
		Sbecore::uint numFRbuMde;
		double SldAsp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacAlign (full: ContIacWzskVtrConfigAlign)
	  */
	class ContIacAlign : public Sbecore::Block {

	public:
		static const Sbecore::uint ROIX0 = 1;
		static const Sbecore::uint ROIY0 = 2;
		static const Sbecore::uint ROIX1 = 3;
		static const Sbecore::uint ROIY1 = 4;

	public:
		ContIacAlign(const int roiX0 = -300, const int roiY0 = -200, const int roiX1 = 300, const int roiY1 = 200);

	public:
		int roiX0;
		int roiY0;
		int roiX1;
		int roiY1;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacAlign* comp);
		std::set<Sbecore::uint> diff(const ContIacAlign* comp);
	};

	/**
	  * ContInf (full: ContInfWzskVtrConfig)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTSTE = 2;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtSte = "");

	public:
		bool ButClaimOn;
		std::string TxtSte;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskVtrConfig)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint RBUMDEACTIVE = 3;
		static const Sbecore::uint CUSIMGHEIGHT = 4;
		static const Sbecore::uint SLDASPACTIVE = 5;
		static const Sbecore::uint SLDASPMIN = 6;
		static const Sbecore::uint SLDASPMAX = 7;
		static const Sbecore::uint BUTSTAACTIVE = 8;
		static const Sbecore::uint BUTSTOACTIVE = 9;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool RbuMdeActive = true, const Sbecore::uint CusImgHeight = 384, const bool SldAspActive = true, const double SldAspMin = -180.0, const double SldAspMax = 180.0, const bool ButStaActive = true, const bool ButStoActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool RbuMdeActive;
		Sbecore::uint CusImgHeight;
		bool SldAspActive;
		double SldAspMin;
		double SldAspMax;
		bool ButStaActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskVtrConfig)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint HDGPVW = 2;
		static const Sbecore::uint CPTMDE = 3;
		static const Sbecore::uint CPTASP = 4;
		static const Sbecore::uint CPTSTE = 5;
		static const Sbecore::uint BUTSTA = 6;
		static const Sbecore::uint BUTSTO = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& HdgPvw = "", const std::string& CptMde = "", const std::string& CptAsp = "", const std::string& CptSte = "", const std::string& ButSta = "", const std::string& ButSto = "");

	public:
		std::string Cpt;
		std::string HdgPvw;
		std::string CptMde;
		std::string CptAsp;
		std::string CptSte;
		std::string ButSta;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppAlign (full: DpchAppWzskVtrConfigAlign)
		*/
	class DpchAppAlign : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIACALIGN = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppAlign(const std::string& scrJref = "", ContIacAlign* contiacalign = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIacAlign contiacalign;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppData (full: DpchAppWzskVtrConfigData)
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
		* DpchAppDo (full: DpchAppWzskVtrConfigDo)
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
		* DpchEngAlign (full: DpchEngWzskVtrConfigAlign)
		*/
	class DpchEngAlign : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIACALIGN = 2;

	public:
		DpchEngAlign();

	public:
		ContIacAlign contiacalign;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskVtrConfigData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFRBUMDE = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFRbuMde;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngLive (full: DpchEngWzskVtrConfigLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint GRAY = 2;
		static const Sbecore::uint RED = 3;
		static const Sbecore::uint GREEN = 4;
		static const Sbecore::uint BLUE = 5;

	public:
		DpchEngLive();

	public:
		std::vector<Sbecore::utinyint> gray;

		std::vector<Sbecore::utinyint> red;
		std::vector<Sbecore::utinyint> green;
		std::vector<Sbecore::utinyint> blue;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
