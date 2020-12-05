/**
	* \file PnlWzskSesRec.h
	* API code for job PnlWzskSesRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKSESREC_H
#define PNLWZSKSESREC_H

#include "ApiWzsk_blks.h"

#define VecVWzskSesRecDo PnlWzskSesRec::VecVDo

#define ContInfWzskSesRec PnlWzskSesRec::ContInf
#define StatAppWzskSesRec PnlWzskSesRec::StatApp
#define StatShrWzskSesRec PnlWzskSesRec::StatShr
#define TagWzskSesRec PnlWzskSesRec::Tag

#define DpchAppWzskSesRecDo PnlWzskSesRec::DpchAppDo
#define DpchEngWzskSesRecData PnlWzskSesRec::DpchEngData

/**
	* PnlWzskSesRec
	*/
namespace PnlWzskSesRec {
	/**
		* VecVDo (full: VecVWzskSesRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskSesRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskSesRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NSHOT = 2;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NShot = false);

	public:
		bool initdoneDetail;
		bool initdone1NShot;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskSesRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NSHOT = 3;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 4;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NShot = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NShot;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskSesRec)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;

	public:
		Tag(const std::string& Cpt = "");

	public:
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskSesRecDo)
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
		* DpchEngData (full: DpchEngWzskSesRecData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;

	public:
		DpchEngData();

	public:
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

