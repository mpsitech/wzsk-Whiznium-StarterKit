/**
	* \file PnlWzskLiv3DView.h
	* API code for job PnlWzskLiv3DView (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef PNLWZSKLIV3DVIEW_H
#define PNLWZSKLIV3DVIEW_H

#include "ApiWzsk_blks.h"

#define VecVWzskLiv3DViewDo PnlWzskLiv3DView::VecVDo

#define ContIacWzskLiv3DView PnlWzskLiv3DView::ContIac
#define ContInfWzskLiv3DView PnlWzskLiv3DView::ContInf
#define StatAppWzskLiv3DView PnlWzskLiv3DView::StatApp
#define StatShrWzskLiv3DView PnlWzskLiv3DView::StatShr
#define TagWzskLiv3DView PnlWzskLiv3DView::Tag

#define DpchAppWzskLiv3DViewData PnlWzskLiv3DView::DpchAppData
#define DpchAppWzskLiv3DViewDo PnlWzskLiv3DView::DpchAppDo
#define DpchEngWzskLiv3DViewData PnlWzskLiv3DView::DpchEngData
#define DpchEngWzskLiv3DViewLive PnlWzskLiv3DView::DpchEngLive

/**
	* PnlWzskLiv3DView
	*/
namespace PnlWzskLiv3DView {
	/**
		* VecVDo (full: VecVWzskLiv3DViewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTASRCLICK = 4;
		static const Sbecore::uint BUTAIRCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLiv3DView)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SLDAIN = 1;

	public:
		ContIac(const double SldAin = 0.0);

	public:
		double SldAin;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLiv3DView)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTAST = 2;
		static const Sbecore::uint TXTAOA = 3;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtAst = "", const std::string& TxtAoa = "");

	public:
		bool ButClaimOn;
		std::string TxtAst;
		std::string TxtAoa;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskLiv3DView)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTPLAYACTIVE = 1;
		static const Sbecore::uint BUTSTOPACTIVE = 2;

	public:
		StatApp(const bool ButPlayActive = true, const bool ButStopActive = true);

	public:
		bool ButPlayActive;
		bool ButStopActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskLiv3DView)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint SLDTREHMIN = 3;
		static const Sbecore::uint SLDTREHMAX = 4;
		static const Sbecore::uint SLDTREVMIN = 5;
		static const Sbecore::uint SLDTREVMAX = 6;
		static const Sbecore::uint SLDAINACTIVE = 7;
		static const Sbecore::uint SLDAINMIN = 8;
		static const Sbecore::uint SLDAINMAX = 9;
		static const Sbecore::uint SLDAINRAST = 10;
		static const Sbecore::uint TXTAOAAVAIL = 11;
		static const Sbecore::uint BUTASRACTIVE = 12;
		static const Sbecore::uint BUTAIRACTIVE = 13;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const double SldTreHMin = 0.0, const double SldTreHMax = 1.0, const double SldTreVMin = 0.0, const double SldTreVMax = 1.0, const bool SldAinActive = true, const double SldAinMin = 3.0, const double SldAinMax = 60.0, const double SldAinRast = 0.5, const bool TxtAoaAvail = true, const bool ButAsrActive = true, const bool ButAirActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		double SldTreHMin;
		double SldTreHMax;
		double SldTreVMin;
		double SldTreVMax;
		bool SldAinActive;
		double SldAinMin;
		double SldAinMax;
		double SldAinRast;
		bool TxtAoaAvail;
		bool ButAsrActive;
		bool ButAirActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskLiv3DView)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint HDGACQ = 2;
		static const Sbecore::uint CPTAIN = 3;
		static const Sbecore::uint CPTAST = 4;
		static const Sbecore::uint CPTAOA = 5;
		static const Sbecore::uint BUTASR = 6;
		static const Sbecore::uint BUTAIR = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& HdgAcq = "", const std::string& CptAin = "", const std::string& CptAst = "", const std::string& CptAoa = "", const std::string& ButAsr = "", const std::string& ButAir = "");

	public:
		std::string Cpt;
		std::string HdgAcq;
		std::string CptAin;
		std::string CptAst;
		std::string CptAoa;
		std::string ButAsr;
		std::string ButAir;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskLiv3DViewData)
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
		* DpchAppDo (full: DpchAppWzskLiv3DViewDo)
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
		* DpchEngData (full: DpchEngWzskLiv3DViewData)
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

	/**
		* DpchEngLive (full: DpchEngWzskLiv3DViewLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint RNOTL = 2;
		static const Sbecore::uint X = 3;
		static const Sbecore::uint Y = 4;
		static const Sbecore::uint Z = 5;

	public:
		DpchEngLive();

	public:
		std::vector<bool> rNotL;
		std::vector<float> x;
		std::vector<float> y;
		std::vector<float> z;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

