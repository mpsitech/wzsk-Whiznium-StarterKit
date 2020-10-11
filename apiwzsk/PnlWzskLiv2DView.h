/**
	* \file PnlWzskLiv2DView.h
	* API code for job PnlWzskLiv2DView (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef PNLWZSKLIV2DVIEW_H
#define PNLWZSKLIV2DVIEW_H

#include "ApiWzsk_blks.h"

#define VecVWzskLiv2DViewDo PnlWzskLiv2DView::VecVDo

#define ContIacWzskLiv2DView PnlWzskLiv2DView::ContIac
#define ContIacWzskLiv2DViewCorner PnlWzskLiv2DView::ContIacCorner
#define ContIacWzskLiv2DViewTrace PnlWzskLiv2DView::ContIacTrace
#define ContInfWzskLiv2DView PnlWzskLiv2DView::ContInf
#define StatShrWzskLiv2DView PnlWzskLiv2DView::StatShr
#define TagWzskLiv2DView PnlWzskLiv2DView::Tag

#define DpchAppWzskLiv2DViewAlign PnlWzskLiv2DView::DpchAppAlign
#define DpchAppWzskLiv2DViewData PnlWzskLiv2DView::DpchAppData
#define DpchAppWzskLiv2DViewDo PnlWzskLiv2DView::DpchAppDo
#define DpchEngWzskLiv2DViewAlign PnlWzskLiv2DView::DpchEngAlign
#define DpchEngWzskLiv2DViewData PnlWzskLiv2DView::DpchEngData
#define DpchEngWzskLiv2DViewLive PnlWzskLiv2DView::DpchEngLive

/**
	* PnlWzskLiv2DView
	*/
namespace PnlWzskLiv2DView {
	/**
		* VecVDo (full: VecVWzskLiv2DViewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTPLAYCLICK = 4;
		static const Sbecore::uint BUTSTOPCLICK = 5;
		static const Sbecore::uint BUTSTSCLICK = 6;
		static const Sbecore::uint BUTTCCCLICK = 7;
		static const Sbecore::uint BUTTCWCLICK = 8;
		static const Sbecore::uint BUTLLECLICK = 9;
		static const Sbecore::uint BUTLRICLICK = 10;
		static const Sbecore::uint BUTLTRCLICK = 11;
		static const Sbecore::uint BUTPICCLICK = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLiv2DView)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPPVM = 1;
		static const Sbecore::uint CHKAEX = 2;
		static const Sbecore::uint SLDEXT = 3;
		static const Sbecore::uint SLDFCS = 4;
		static const Sbecore::uint UPDLLO = 5;
		static const Sbecore::uint UPDLUO = 6;
		static const Sbecore::uint UPDLMD = 7;
		static const Sbecore::uint CHKLRO = 8;
		static const Sbecore::uint UPDPNT = 9;
		static const Sbecore::uint CHKPRO = 10;

	public:
		ContIac(const Sbecore::uint numFPupPvm = 1, const bool ChkAex = false, const double SldExt = 0.0, const double SldFcs = 0.0, const int UpdLlo = 0, const int UpdLuo = 0, const int UpdLmd = 0, const bool ChkLro = false, const int UpdPnt = 0, const bool ChkPro = false);

	public:
		Sbecore::uint numFPupPvm;
		bool ChkAex;
		double SldExt;
		double SldFcs;
		int UpdLlo;
		int UpdLuo;
		int UpdLmd;
		bool ChkLro;
		int UpdPnt;
		bool ChkPro;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacCorner (full: ContIacWzskLiv2DViewCorner)
	  */
	class ContIacCorner : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ROIAX = 1;
		static const Sbecore::uint ROIAY = 2;
		static const Sbecore::uint ROIBX = 3;
		static const Sbecore::uint ROIBY = 4;
		static const Sbecore::uint ROICX = 5;
		static const Sbecore::uint ROICY = 6;
		static const Sbecore::uint ROIDX = 7;
		static const Sbecore::uint ROIDY = 8;

	public:
		ContIacCorner(const int roiAx = 0, const int roiAy = -200, const int roiBx = 300, const int roiBy = 0, const int roiCx = 0, const int roiCy = 200, const int roiDx = -300, const int roiDy = 0);

	public:
		int roiAx;
		int roiAy;
		int roiBx;
		int roiBy;
		int roiCx;
		int roiCy;
		int roiDx;
		int roiDy;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacCorner* comp);
		std::set<Sbecore::uint> diff(const ContIacCorner* comp);
	};

	/**
	  * ContIacTrace (full: ContIacWzskLiv2DViewTrace)
	  */
	class ContIacTrace : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ROIAX = 1;
		static const Sbecore::uint ROIAY = 2;
		static const Sbecore::uint ROIBX = 3;
		static const Sbecore::uint ROIBY = 4;
		static const Sbecore::uint ROICX = 5;
		static const Sbecore::uint ROICY = 6;
		static const Sbecore::uint ROIDX = 7;
		static const Sbecore::uint ROIDY = 8;

	public:
		ContIacTrace(const int roiAx = -300, const int roiAy = -200, const int roiBx = 300, const int roiBy = -200, const int roiCx = 300, const int roiCy = 400, const int roiDx = -300, const int roiDy = 400);

	public:
		int roiAx;
		int roiAy;
		int roiBx;
		int roiBy;
		int roiCx;
		int roiCy;
		int roiDx;
		int roiDy;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacTrace* comp);
		std::set<Sbecore::uint> diff(const ContIacTrace* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLiv2DView)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTOAF = 2;
		static const Sbecore::uint BUTTCCON = 3;
		static const Sbecore::uint BUTTCWON = 4;
		static const Sbecore::uint BUTLLEON = 5;
		static const Sbecore::uint BUTLRION = 6;
		static const Sbecore::uint BUTLTRON = 7;
		static const Sbecore::uint BUTPICON = 8;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtOaf = "", const bool ButTccOn = false, const bool ButTcwOn = false, const bool ButLleOn = false, const bool ButLriOn = false, const bool ButLtrOn = false, const bool ButPicOn = false);

	public:
		bool ButClaimOn;
		std::string TxtOaf;
		bool ButTccOn;
		bool ButTcwOn;
		bool ButLleOn;
		bool ButLriOn;
		bool ButLtrOn;
		bool ButPicOn;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskLiv2DView)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint BUTPLAYACTIVE = 3;
		static const Sbecore::uint BUTSTOPACTIVE = 4;
		static const Sbecore::uint CHKAEXACTIVE = 5;
		static const Sbecore::uint SLDEXTAVAIL = 6;
		static const Sbecore::uint SLDEXTACTIVE = 7;
		static const Sbecore::uint SLDEXTMIN = 8;
		static const Sbecore::uint SLDEXTMAX = 9;
		static const Sbecore::uint SLDEXTRAST = 10;
		static const Sbecore::uint SLDFCSACTIVE = 11;
		static const Sbecore::uint SLDFCSMIN = 12;
		static const Sbecore::uint SLDFCSMAX = 13;
		static const Sbecore::uint TXTOAFAVAIL = 14;
		static const Sbecore::uint BUTSTSACTIVE = 15;
		static const Sbecore::uint UPDLLOAVAIL = 16;
		static const Sbecore::uint UPDLLOMIN = 17;
		static const Sbecore::uint UPDLLOMAX = 18;
		static const Sbecore::uint UPDLUOAVAIL = 19;
		static const Sbecore::uint UPDLUOMIN = 20;
		static const Sbecore::uint UPDLUOMAX = 21;
		static const Sbecore::uint UPDLMDAVAIL = 22;
		static const Sbecore::uint UPDLMDMIN = 23;
		static const Sbecore::uint UPDLMDMAX = 24;
		static const Sbecore::uint UPDPNTMIN = 25;
		static const Sbecore::uint UPDPNTMAX = 26;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool ButPlayActive = true, const bool ButStopActive = true, const bool ChkAexActive = true, const bool SldExtAvail = true, const bool SldExtActive = true, const double SldExtMin = 0.001, const double SldExtMax = 100.0, const double SldExtRast = 1.77828, const bool SldFcsActive = true, const double SldFcsMin = 0.0, const double SldFcsMax = 1.0, const bool TxtOafAvail = true, const bool ButStsActive = true, const bool UpdLloAvail = true, const int UpdLloMin = 0, const int UpdLloMax = 255, const bool UpdLuoAvail = true, const int UpdLuoMin = 0, const int UpdLuoMax = 255, const bool UpdLmdAvail = true, const int UpdLmdMin = 0, const int UpdLmdMax = 255, const int UpdPntMin = 0, const int UpdPntMax = 1000);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool ButPlayActive;
		bool ButStopActive;
		bool ChkAexActive;
		bool SldExtAvail;
		bool SldExtActive;
		double SldExtMin;
		double SldExtMax;
		double SldExtRast;
		bool SldFcsActive;
		double SldFcsMin;
		double SldFcsMax;
		bool TxtOafAvail;
		bool ButStsActive;
		bool UpdLloAvail;
		int UpdLloMin;
		int UpdLloMax;
		bool UpdLuoAvail;
		int UpdLuoMin;
		int UpdLuoMax;
		bool UpdLmdAvail;
		int UpdLmdMin;
		int UpdLmdMax;
		int UpdPntMin;
		int UpdPntMax;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskLiv2DView)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPVM = 2;
		static const Sbecore::uint CPTAEX = 3;
		static const Sbecore::uint CPTEXT = 4;
		static const Sbecore::uint CPTFCS = 5;
		static const Sbecore::uint CPTOAF = 6;
		static const Sbecore::uint BUTSTS = 7;
		static const Sbecore::uint HDGTTB = 8;
		static const Sbecore::uint BUTTCC = 9;
		static const Sbecore::uint BUTTCW = 10;
		static const Sbecore::uint HDGLOR = 11;
		static const Sbecore::uint BUTLLE = 12;
		static const Sbecore::uint BUTLRI = 13;
		static const Sbecore::uint CPTLLO = 14;
		static const Sbecore::uint CPTLUO = 15;
		static const Sbecore::uint CPTLMD = 16;
		static const Sbecore::uint CPTLGL = 17;
		static const Sbecore::uint CPTLRO = 18;
		static const Sbecore::uint BUTLTR = 19;
		static const Sbecore::uint BUTLCL = 20;
		static const Sbecore::uint HDGPOS = 21;
		static const Sbecore::uint CPTPNT = 22;
		static const Sbecore::uint CPTPRO = 23;
		static const Sbecore::uint BUTPIC = 24;
		static const Sbecore::uint BUTPCL = 25;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPvm = "", const std::string& CptAex = "", const std::string& CptExt = "", const std::string& CptFcs = "", const std::string& CptOaf = "", const std::string& ButSts = "", const std::string& HdgTtb = "", const std::string& ButTcc = "", const std::string& ButTcw = "", const std::string& HdgLor = "", const std::string& ButLle = "", const std::string& ButLri = "", const std::string& CptLlo = "", const std::string& CptLuo = "", const std::string& CptLmd = "", const std::string& CptLgl = "", const std::string& CptLro = "", const std::string& ButLtr = "", const std::string& ButLcl = "", const std::string& HdgPos = "", const std::string& CptPnt = "", const std::string& CptPro = "", const std::string& ButPic = "", const std::string& ButPcl = "");

	public:
		std::string Cpt;
		std::string CptPvm;
		std::string CptAex;
		std::string CptExt;
		std::string CptFcs;
		std::string CptOaf;
		std::string ButSts;
		std::string HdgTtb;
		std::string ButTcc;
		std::string ButTcw;
		std::string HdgLor;
		std::string ButLle;
		std::string ButLri;
		std::string CptLlo;
		std::string CptLuo;
		std::string CptLmd;
		std::string CptLgl;
		std::string CptLro;
		std::string ButLtr;
		std::string ButLcl;
		std::string HdgPos;
		std::string CptPnt;
		std::string CptPro;
		std::string ButPic;
		std::string ButPcl;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppAlign (full: DpchAppWzskLiv2DViewAlign)
		*/
	class DpchAppAlign : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIACCORNER = 2;
		static const Sbecore::uint CONTIACTRACE = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppAlign(const std::string& scrJref = "", ContIacCorner* contiaccorner = NULL, ContIacTrace* contiactrace = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIacCorner contiaccorner;
		ContIacTrace contiactrace;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppData (full: DpchAppWzskLiv2DViewData)
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
		* DpchAppDo (full: DpchAppWzskLiv2DViewDo)
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
		* DpchEngAlign (full: DpchEngWzskLiv2DViewAlign)
		*/
	class DpchEngAlign : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIACCORNER = 2;
		static const Sbecore::uint CONTIACTRACE = 3;

	public:
		DpchEngAlign();

	public:
		ContIacCorner contiaccorner;
		ContIacTrace contiactrace;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskLiv2DViewData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPVM = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupPvm;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngLive (full: DpchEngWzskLiv2DViewLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint GRAY = 2;
		static const Sbecore::uint RED = 3;
		static const Sbecore::uint GREEN = 4;
		static const Sbecore::uint BLUE = 5;
		static const Sbecore::uint XCORNER = 6;
		static const Sbecore::uint YCORNER = 7;
		static const Sbecore::uint XTRACEL = 8;
		static const Sbecore::uint YTRACEL = 9;
		static const Sbecore::uint XTRACER = 10;
		static const Sbecore::uint YTRACER = 11;

	public:
		DpchEngLive();

	public:
		std::vector<Sbecore::utinyint> gray;

		std::vector<Sbecore::utinyint> red;
		std::vector<Sbecore::utinyint> green;
		std::vector<Sbecore::utinyint> blue;

		std::vector<int> xCorner;
		std::vector<int> yCorner;

		std::vector<int> xTraceL;
		std::vector<int> yTraceL;

		std::vector<int> xTraceR;
		std::vector<int> yTraceR;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

