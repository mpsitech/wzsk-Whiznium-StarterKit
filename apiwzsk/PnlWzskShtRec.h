/**
	* \file PnlWzskShtRec.h
	* API code for job PnlWzskShtRec (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef PNLWZSKSHTREC_H
#define PNLWZSKSHTREC_H

#include "ApiWzsk_blks.h"

#define VecVWzskShtRecDo PnlWzskShtRec::VecVDo

#define ContInfWzskShtRec PnlWzskShtRec::ContInf
#define StatAppWzskShtRec PnlWzskShtRec::StatApp
#define StatShrWzskShtRec PnlWzskShtRec::StatShr
#define TagWzskShtRec PnlWzskShtRec::Tag

#define DpchAppWzskShtRecDo PnlWzskShtRec::DpchAppDo
#define DpchEngWzskShtRecData PnlWzskShtRec::DpchEngData

/**
	* PnlWzskShtRec
	*/
namespace PnlWzskShtRec {
	/**
		* VecVDo (full: VecVWzskShtRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskShtRec)
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
	  * StatApp (full: StatAppWzskShtRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONEAPAR = 2;
		static const Sbecore::uint INITDONEREF1NFILE = 3;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAPar = false, const bool initdoneRef1NFile = false);

	public:
		bool initdoneDetail;
		bool initdoneAPar;
		bool initdoneRef1NFile;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskShtRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREFAPAR = 3;
		static const Sbecore::uint SCRJREFREF1NFILE = 4;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 5;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJrefAPar = "", const std::string& scrJrefRef1NFile = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		std::string scrJrefDetail;
		std::string scrJrefAPar;
		std::string scrJrefRef1NFile;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskShtRec)
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
		* DpchAppDo (full: DpchAppWzskShtRecDo)
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
		* DpchEngData (full: DpchEngWzskShtRecData)
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

