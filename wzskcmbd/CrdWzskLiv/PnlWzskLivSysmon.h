/**
	* \file PnlWzskLivSysmon.h
	* job handler for job PnlWzskLivSysmon (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef PNLWZSKLIVSYSMON_H
#define PNLWZSKLIVSYSMON_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcSysinfo.h"

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
class PnlWzskLivSysmon : public JobWzsk {

public:
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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskLivSysmon)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLivSysmonDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskLivSysmonData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngLive (full: DpchEngWzskLivSysmonLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint TS = 2;
		static const Sbecore::uint CLDTOTS = 3;
		static const Sbecore::uint CLD1S = 4;
		static const Sbecore::uint CLD2S = 5;
		static const Sbecore::uint CLD3S = 6;
		static const Sbecore::uint CLD4S = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngLive(const Sbecore::ubigint jref = 0, const std::vector<float>& ts = {}, const std::vector<float>& cldtots = {}, const std::vector<float>& cld1s = {}, const std::vector<float>& cld2s = {}, const std::vector<float>& cld3s = {}, const std::vector<float>& cld4s = {}, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::vector<float> ts;
		std::vector<float> cldtots;
		std::vector<float> cld1s;
		std::vector<float> cld2s;
		std::vector<float> cld3s;
		std::vector<float> cld4s;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	PnlWzskLivSysmon(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskLivSysmon();

public:
	ContInf continf;
	StatShr statshr;

	JobWzskSrcSysinfo* srcsysinfo;

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

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskShrdatChgFromSrcsysinfo(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);

};

#endif

