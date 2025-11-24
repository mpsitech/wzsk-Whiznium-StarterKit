/**
	* \file JobWzskAcqCorner.h
	* job handler for job JobWzskAcqCorner (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACQCORNER_H
#define JOBWZSKACQCORNER_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcDcvsp.h"
#include "JobWzskSrcTivsp.h"
#include "JobWzskSrcZuvsp.h"

#define VecVJobWzskAcqCornerMethod JobWzskAcqCorner::VecVMethod
#define VecVJobWzskAcqCornerSge JobWzskAcqCorner::VecVSge
#define VecVJobWzskAcqCornerVar JobWzskAcqCorner::VecVVar

#define StgJobWzskAcqCorner JobWzskAcqCorner::Stg

#define ShrdatJobWzskAcqCorner JobWzskAcqCorner::Shrdat

/**
	* JobWzskAcqCorner
	*/
class JobWzskAcqCorner : public CsjobWzsk {

public:
	/**
		* VecVMethod (full: VecVJobWzskAcqCornerMethod)
		*/
	class VecVMethod {

	public:
		static const Sbecore::uint SETROI = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVSge (full: VecVJobWzskAcqCornerSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ACQ = 2;
		static const Sbecore::uint CALCIDLE = 3;
		static const Sbecore::uint CALC = 4;
		static const Sbecore::uint DONE = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskAcqCornerVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint ROIX0ROIY0ROIX1ROIY1 = 1;
		static const Sbecore::uint SHIFTSCOREMINSCOREMAX = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskAcqCorner)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint ROW0 = 1;
		static const Sbecore::uint COL0 = 2;
		static const Sbecore::uint W = 3;
		static const Sbecore::uint H = 4;

	public:
		Stg(const Sbecore::usmallint row0 = 100, const Sbecore::usmallint col0 = 100, const Sbecore::usmallint w = 640, const Sbecore::usmallint h = 480);

	public:
		Sbecore::usmallint row0;
		Sbecore::usmallint col0;

		Sbecore::usmallint w;
		Sbecore::usmallint h;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	bool evalSrcdcvspConstr(DbsWzsk* dbswzsk);
	bool evalSrctivspConstr(DbsWzsk* dbswzsk);
	bool evalSrczuvspConstr(DbsWzsk* dbswzsk);

	/**
		* Shrdat (full: ShrdatJobWzskAcqCorner)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		int roiX0;
		int roiY0;
		int roiX1;
		int roiY1;

		Sbecore::utinyint shift;
		Sbecore::utinyint scoreMin;
		Sbecore::utinyint scoreMax;

		// IP Shrdat.vars.cust --- INSERT

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskAcqCorner(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskAcqCorner();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobWzskSrcDcvsp* srcdcvsp;
	JobWzskSrcTivsp* srctivsp;
	JobWzskSrcZuvsp* srczuvsp;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	// IP spec --- INSERT

public:
	bool setRoi(DbsWzsk* dbswzsk, const int roiX0, const int roiY0, const int roiX1, const int roiY1);

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

	void handleTimerInSgeCalcidle(DbsWzsk* dbswzsk, const std::string& sref);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskCallbackFromSelfInSgeAcq(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeAcq(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeAcq(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeCalcidle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeCalcidle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeCalc(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeCalc(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeDone(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeDone(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
