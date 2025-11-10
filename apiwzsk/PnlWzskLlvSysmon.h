/**
	* \file PnlWzskLlvSysmon.h
	* API code for job PnlWzskLlvSysmon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKLLVSYSMON_H
#define PNLWZSKLLVSYSMON_H

#include "ApiWzsk_blks.h"

#define VecVWzskLlvSysmonDo PnlWzskLlvSysmon::VecVDo

#define ContInfWzskLlvSysmon PnlWzskLlvSysmon::ContInf
#define StatShrWzskLlvSysmon PnlWzskLlvSysmon::StatShr
#define TagWzskLlvSysmon PnlWzskLlvSysmon::Tag

#define DpchAppWzskLlvSysmonDo PnlWzskLlvSysmon::DpchAppDo
#define DpchEngWzskLlvSysmonData PnlWzskLlvSysmon::DpchEngData
#define DpchEngWzskLlvSysmonLive PnlWzskLlvSysmon::DpchEngLive

/**
	* PnlWzskLlvSysmon
	*/
namespace PnlWzskLlvSysmon {
	/**
		* VecVDo (full: VecVWzskLlvSysmonDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskLlvSysmon)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTCTP = 1;
		static const Sbecore::uint TXTDHR = 2;
		static const Sbecore::uint TXTDHW = 3;
		static const Sbecore::uint TXTDRR = 4;
		static const Sbecore::uint TXTDRW = 5;

	public:
		ContInf(const std::string& TxtCtp = "", const std::string& TxtDhr = "", const std::string& TxtDhw = "", const std::string& TxtDrr = "", const std::string& TxtDrw = "");

	public:
		std::string TxtCtp;
		std::string TxtDhr;
		std::string TxtDhw;
		std::string TxtDrr;
		std::string TxtDrw;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskLlvSysmon)
	  */
	class StatShr : public Sbecore::Block {

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
	  * Tag (full: TagWzskLlvSysmon)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTCTP = 2;
		static const Sbecore::uint CPTPLTTME = 3;
		static const Sbecore::uint CPTPLTCLD = 4;
		static const Sbecore::uint CPTPLTTOT = 5;
		static const Sbecore::uint CPTPLTCOR = 6;
		static const Sbecore::uint CPTDHR = 7;
		static const Sbecore::uint CPTDHW = 8;
		static const Sbecore::uint CPTDRR = 9;
		static const Sbecore::uint CPTDRW = 10;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptCtp = "", const std::string& CptPltTme = "", const std::string& CptPltCld = "", const std::string& CptPltTot = "", const std::string& CptPltCor = "", const std::string& CptDhr = "", const std::string& CptDhw = "", const std::string& CptDrr = "", const std::string& CptDrw = "");

	public:
		std::string Cpt;
		std::string CptCtp;
		std::string CptPltTme;
		std::string CptPltCld;
		std::string CptPltTot;
		std::string CptPltCor;
		std::string CptDhr;
		std::string CptDhw;
		std::string CptDrr;
		std::string CptDrw;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvSysmonDo)
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
		* DpchEngData (full: DpchEngWzskLlvSysmonData)
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
		* DpchEngLive (full: DpchEngWzskLlvSysmonLive)
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
