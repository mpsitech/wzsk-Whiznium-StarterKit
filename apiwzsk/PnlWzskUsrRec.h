/**
	* \file PnlWzskUsrRec.h
	* API code for job PnlWzskUsrRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKUSRREC_H
#define PNLWZSKUSRREC_H

#include "ApiWzsk_blks.h"

#define VecVWzskUsrRecDo PnlWzskUsrRec::VecVDo

#define ContInfWzskUsrRec PnlWzskUsrRec::ContInf
#define StatAppWzskUsrRec PnlWzskUsrRec::StatApp
#define StatShrWzskUsrRec PnlWzskUsrRec::StatShr
#define TagWzskUsrRec PnlWzskUsrRec::Tag

#define DpchAppWzskUsrRecDo PnlWzskUsrRec::DpchAppDo
#define DpchEngWzskUsrRecData PnlWzskUsrRec::DpchEngData

/**
	* PnlWzskUsrRec
	*/
namespace PnlWzskUsrRec {
	/**
		* VecVDo (full: VecVWzskUsrRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskUsrRec)
	  */
	class ContInf : public Sbecore::Block {

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
	  * StatApp (full: StatAppWzskUsrRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAACCESS = 2;
		static const Sbecore::uint INITDONE1NSESSION = 3;
		static const Sbecore::uint INITDONEMNUSERGROUP = 4;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAAccess = false, const bool initdone1NSession = false, const bool initdoneMNUsergroup = false);

	public:
		bool initdoneDetail;
		bool initdoneAAccess;
		bool initdone1NSession;
		bool initdoneMNUsergroup;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskUsrRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAACCESS = 3;
		static const Sbecore::uint SCRJREF1NSESSION = 4;
		static const Sbecore::uint SCRJREFMNUSERGROUP = 5;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 6;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAAccess = "", const std::string& scrJref1NSession = "", const std::string& scrJrefMNUsergroup = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAAccess;
		std::string scrJref1NSession;
		std::string scrJrefMNUsergroup;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskUsrRec)
	  */
	class Tag : public Sbecore::Block {

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
		* DpchAppDo (full: DpchAppWzskUsrRecDo)
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
		* DpchEngData (full: DpchEngWzskUsrRecData)
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
