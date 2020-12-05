/**
	* \file PnlWzskNavOp.h
	* API code for job PnlWzskNavOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKNAVOP_H
#define PNLWZSKNAVOP_H

#include "ApiWzsk_blks.h"

#define VecVWzskNavOpDo PnlWzskNavOp::VecVDo

#define StatAppWzskNavOp PnlWzskNavOp::StatApp
#define StatShrWzskNavOp PnlWzskNavOp::StatShr
#define TagWzskNavOp PnlWzskNavOp::Tag

#define DpchAppWzskNavOpDo PnlWzskNavOp::DpchAppDo
#define DpchEngWzskNavOpData PnlWzskNavOp::DpchEngData

/**
	* PnlWzskNavOp
	*/
namespace PnlWzskNavOp {
	/**
		* VecVDo (full: VecVWzskNavOpDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTLLVNEWCRDCLICK = 1;
		static const Sbecore::uint BUTLIVNEWCRDCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * StatApp (full: StatAppWzskNavOp)
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
	  * StatShr (full: StatShrWzskNavOp)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTLLVNEWCRDAVAIL = 1;
		static const Sbecore::uint BUTLIVNEWCRDAVAIL = 2;

	public:
		StatShr(const bool ButLlvNewcrdAvail = true, const bool ButLivNewcrdAvail = true);

	public:
		bool ButLlvNewcrdAvail;
		bool ButLivNewcrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskNavOp)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTLLV = 2;
		static const Sbecore::uint CPTLIV = 3;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptLlv = "", const std::string& CptLiv = "");

	public:
		std::string Cpt;
		std::string CptLlv;
		std::string CptLiv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskNavOpDo)
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
		* DpchEngData (full: DpchEngWzskNavOpData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STATAPP = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

