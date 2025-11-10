/**
	* \file PnlWzskVtrMonitor.h
	* job handler for job PnlWzskVtrMonitor (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKVTRMONITOR_H
#define PNLWZSKVTRMONITOR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskActVistorot.h"

#define VecVWzskVtrMonitorDo PnlWzskVtrMonitor::VecVDo

#define StatShrWzskVtrMonitor PnlWzskVtrMonitor::StatShr
#define TagWzskVtrMonitor PnlWzskVtrMonitor::Tag

#define DpchAppWzskVtrMonitorDo PnlWzskVtrMonitor::DpchAppDo
#define DpchEngWzskVtrMonitorData PnlWzskVtrMonitor::DpchEngData
#define DpchEngWzskVtrMonitorLive PnlWzskVtrMonitor::DpchEngLive

/**
	* PnlWzskVtrMonitor
	*/
class PnlWzskVtrMonitor : public JobWzsk {

public:
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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskVtrMonitor)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskVtrMonitorDo)
		*/
	class DpchAppDo : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskVtrMonitorData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint TAG = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngLive (full: DpchEngWzskVtrMonitorLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint TS = 2;
		static const Sbecore::uint PHIS = 3;
		static const Sbecore::uint PHIMIN = 4;
		static const Sbecore::uint PHIMAX = 5;
		static const Sbecore::uint OMEGAS = 6;
		static const Sbecore::uint OMEGAMIN = 7;
		static const Sbecore::uint OMEGAMAX = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngLive(const Sbecore::ubigint jref = 0, const std::vector<float>& ts = {}, const std::vector<float>& phis = {}, const float phiMin = -180.0, const float phiMax = 180.0, const std::vector<float>& omegas = {}, const float omegaMin = -9.0, const float omegaMax = 9.0, const std::set<Sbecore::uint>& mask = {NONE});

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
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	PnlWzskVtrMonitor(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskVtrMonitor();

public:
	StatShr statshr;

	JobWzskActVistorot* actvistorot;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

};

#endif
