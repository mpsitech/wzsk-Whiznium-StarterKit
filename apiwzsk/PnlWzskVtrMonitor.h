/**
	* \file PnlWzskVtrMonitor.h
	* API code for job PnlWzskVtrMonitor (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKVTRMONITOR_H
#define PNLWZSKVTRMONITOR_H

#include "ApiWzsk_blks.h"

#define VecVWzskVtrMonitorDo PnlWzskVtrMonitor::VecVDo

#define StatShrWzskVtrMonitor PnlWzskVtrMonitor::StatShr
#define TagWzskVtrMonitor PnlWzskVtrMonitor::Tag

#define DpchAppWzskVtrMonitorDo PnlWzskVtrMonitor::DpchAppDo
#define DpchEngWzskVtrMonitorData PnlWzskVtrMonitor::DpchEngData
#define DpchEngWzskVtrMonitorLive PnlWzskVtrMonitor::DpchEngLive

/**
	* PnlWzskVtrMonitor
	*/
namespace PnlWzskVtrMonitor {
	/**
		* VecVDo (full: VecVWzskVtrMonitorDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * StatShr (full: StatShrWzskVtrMonitor)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint CUSAPLHEIGHT = 2;
		static const Sbecore::uint CUSVPLHEIGHT = 3;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const Sbecore::uint CusAplHeight = 250, const Sbecore::uint CusVplHeight = 250);

	public:
		Sbecore::uint ixWzskVExpstate;
		Sbecore::uint CusAplHeight;
		Sbecore::uint CusVplHeight;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskVtrMonitor)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTAPLTME = 2;
		static const Sbecore::uint CPTAPLANG = 3;
		static const Sbecore::uint CPTVPLTME = 4;
		static const Sbecore::uint CPTVPLANG = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptAplTme = "", const std::string& CptAplAng = "", const std::string& CptVplTme = "", const std::string& CptVplAng = "");

	public:
		std::string Cpt;
		std::string CptAplTme;
		std::string CptAplAng;
		std::string CptVplTme;
		std::string CptVplAng;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskVtrMonitorDo)
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
		* DpchEngData (full: DpchEngWzskVtrMonitorData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint TAG = 3;

	public:
		DpchEngData();

	public:
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngLive (full: DpchEngWzskVtrMonitorLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint TS = 2;
		static const Sbecore::uint PHIS = 3;
		static const Sbecore::uint PHIMIN = 4;
		static const Sbecore::uint PHIMAX = 5;
		static const Sbecore::uint OMEGAS = 6;
		static const Sbecore::uint OMEGAMIN = 7;
		static const Sbecore::uint OMEGAMAX = 8;

	public:
		DpchEngLive();

	public:
		std::vector<float> ts;

		std::vector<float> phis;

		float phiMin;
		float phiMax;

		std::vector<float> omegas;

		float omegaMin;
		float omegaMax;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
