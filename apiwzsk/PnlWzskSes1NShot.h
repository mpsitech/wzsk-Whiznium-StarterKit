/**
	* \file PnlWzskSes1NShot.h
	* API code for job PnlWzskSes1NShot (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKSES1NSHOT_H
#define PNLWZSKSES1NSHOT_H

#include "ApiWzsk_blks.h"

#include "WzskQSes1NShot.h"

#include "QryWzskSes1NShot.h"

#define VecVWzskSes1NShotDo PnlWzskSes1NShot::VecVDo

#define ContInfWzskSes1NShot PnlWzskSes1NShot::ContInf
#define StatAppWzskSes1NShot PnlWzskSes1NShot::StatApp
#define StatShrWzskSes1NShot PnlWzskSes1NShot::StatShr
#define StgIacWzskSes1NShot PnlWzskSes1NShot::StgIac
#define TagWzskSes1NShot PnlWzskSes1NShot::Tag

#define DpchAppWzskSes1NShotData PnlWzskSes1NShot::DpchAppData
#define DpchAppWzskSes1NShotDo PnlWzskSes1NShot::DpchAppDo
#define DpchEngWzskSes1NShotData PnlWzskSes1NShot::DpchEngData

/**
	* PnlWzskSes1NShot
	*/
namespace PnlWzskSes1NShot {
	/**
		* VecVDo (full: VecVWzskSes1NShotDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTVIEWCLICK = 1;
		static const Sbecore::uint BUTNEWCLICK = 2;
		static const Sbecore::uint BUTDELETECLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskSes1NShot)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskSes1NShot)
	  */
	class StatApp : public Sbecore::Block {

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
	  * StatShr (full: StatShrWzskSes1NShot)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTVIEWAVAIL = 1;
		static const Sbecore::uint BUTVIEWACTIVE = 2;
		static const Sbecore::uint BUTNEWAVAIL = 3;
		static const Sbecore::uint BUTDELETEAVAIL = 4;
		static const Sbecore::uint BUTDELETEACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButNewAvail = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButNewAvail;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWzskSes1NShot)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOREFWIDTH = 1;

	public:
		StgIac(const Sbecore::uint TcoRefWidth = 100);

	public:
		Sbecore::uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWzskSes1NShot)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOREF = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoRef = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoRef;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskSes1NShotData)
		*/
	class DpchAppData : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWzskSes1NShot::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWzskSes1NShot::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWzskSes1NShotDo)
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
		* DpchEngData (full: DpchEngWzskSes1NShotData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint STGIAC = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint RST = 8;
		static const Sbecore::uint STATAPPQRY = 9;
		static const Sbecore::uint STATSHRQRY = 10;
		static const Sbecore::uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWzskQSes1NShot rst;
		QryWzskSes1NShot::StatApp statappqry;
		QryWzskSes1NShot::StatShr statshrqry;
		QryWzskSes1NShot::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
