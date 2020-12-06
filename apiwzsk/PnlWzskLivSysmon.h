/**
	* \file PnlWzskLivSysmon.h
	* API code for job PnlWzskLivSysmon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKLIVSYSMON_H
#define PNLWZSKLIVSYSMON_H

#include "ApiWzsk_blks.h"

#define VecVWzskLivSysmonDo PnlWzskLivSysmon::VecVDo

#define ContInfWzskLivSysmon PnlWzskLivSysmon::ContInf
#define StatShrWzskLivSysmon PnlWzskLivSysmon::StatShr
#define TagWzskLivSysmon PnlWzskLivSysmon::Tag

#define DpchAppWzskLivSysmonDo PnlWzskLivSysmon::DpchAppDo
#define DpchEngWzskLivSysmonData PnlWzskLivSysmon::DpchEngData
#define DpchEngWzskLivSysmonLive PnlWzskLivSysmon::DpchEngLive

/**
	* PnlWzskLivSysmon
	*/
namespace PnlWzskLivSysmon {
	/**
		* VecVDo (full: VecVWzskLivSysmonDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskLivSysmon)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTCTP = 1;

	public:
		ContInf(const std::string& TxtCtp = "");

	public:
		std::string TxtCtp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskLivSysmon)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND);

	public:
		Sbecore::uint ixWzskVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskLivSysmon)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTCTP = 2;
		static const Sbecore::uint CPTPLTTME = 3;
		static const Sbecore::uint CPTPLTCLD = 4;
		static const Sbecore::uint CPTPLTTOT = 5;
		static const Sbecore::uint CPTPLTCOR = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptCtp = "", const std::string& CptPltTme = "", const std::string& CptPltCld = "", const std::string& CptPltTot = "", const std::string& CptPltCor = "");

	public:
		std::string Cpt;
		std::string CptCtp;
		std::string CptPltTme;
		std::string CptPltCld;
		std::string CptPltTot;
		std::string CptPltCor;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLivSysmonDo)
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
		* DpchEngData (full: DpchEngWzskLivSysmonData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngLive (full: DpchEngWzskLivSysmonLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint TS = 2;
		static const Sbecore::uint CLDTOTS = 3;
		static const Sbecore::uint CLD1S = 4;
		static const Sbecore::uint CLD2S = 5;
		static const Sbecore::uint CLD3S = 6;
		static const Sbecore::uint CLD4S = 7;

	public:
		DpchEngLive();

	public:
		std::vector<float> ts;
		std::vector<float> cldtots;
		std::vector<float> cld1s;
		std::vector<float> cld2s;
		std::vector<float> cld3s;
		std::vector<float> cld4s;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
