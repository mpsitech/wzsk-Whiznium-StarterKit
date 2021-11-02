/**
	* \file JobWzskIprTrace.h
	* job handler for job JobWzskIprTrace (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKIPRTRACE_H
#define JOBWZSKIPRTRACE_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#ifdef __arm__
	#include <arm_neon.h>
#elif __x86_64__
	#include <emmintrin.h>
#endif
// IP include.cust --- IEND

#include "JobWzskSrcV4l2.h"
#include "JobWzskActLaser.h"
#include "JobWzskAcqFpgaflg.h"

#define VecVJobWzskIprTraceMethod JobWzskIprTrace::VecVMethod
#define VecVJobWzskIprTraceSge JobWzskIprTrace::VecVSge
#define VecVJobWzskIprTraceVar JobWzskIprTrace::VecVVar

#define StgJobWzskIprTrace JobWzskIprTrace::Stg

#define ShrdatJobWzskIprTrace JobWzskIprTrace::Shrdat

/**
	* JobWzskIprTrace
	*/
class JobWzskIprTrace : public CsjobWzsk {

public:
	/**
		* VecVMethod (full: VecVJobWzskIprTraceMethod)
		*/
	class VecVMethod {

	public:
		static const Sbecore::uint SETLEVEL = 1;
		static const Sbecore::uint SETROI = 2;
		static const Sbecore::uint SETROINOTFULL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVSge (full: VecVJobWzskIprTraceSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint READY = 2;
		static const Sbecore::uint PRCIDLE = 3;
		static const Sbecore::uint PROCESS = 4;
		static const Sbecore::uint LEFTON = 5;
		static const Sbecore::uint LEFTOFF = 6;
		static const Sbecore::uint RIGHTON = 7;
		static const Sbecore::uint RIGHTOFF = 8;
		static const Sbecore::uint DONE = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskIprTraceVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint PONLEFTPONRIGHT = 1;
		static const Sbecore::uint LEVELONLEVELOFF = 2;
		static const Sbecore::uint ROIAXROIAYROIBXROIBYROICXROICYROIDXROIDY = 3;
		static const Sbecore::uint LEFTRIGHT = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskIprTrace)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint V4L2RDNOTDELTA = 1;
		static const Sbecore::uint ROINOTFULL = 2;
		static const Sbecore::uint FLGPERROWMAX = 3;
		static const Sbecore::uint LEFTONNOTOFF = 4;
		static const Sbecore::uint RIGHTONNOTOFF = 5;

	public:
		Stg(const bool v4l2RdNotDelta = false, const bool roiNotFull = false, const Sbecore::utinyint flgPerRowMax = 10, const bool leftOnNotOff = true, const bool rightOnNotOff = true);

	public:
		bool v4l2RdNotDelta;
		bool roiNotFull;
		Sbecore::utinyint flgPerRowMax;

		bool leftOnNotOff;
		bool rightOnNotOff;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskIprTrace)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* ResultitemTrace (full: ResultitemJobWzskIprTraceTrace)
			*/
		class ResultitemTrace : public Sbecore::Resultitem {

		public:
			ResultitemTrace();
			~ResultitemTrace();

		public:
			double tIn;
			double tOut;

			unsigned int Nleft;
			unsigned int Nright;

			std::vector<int> x;
			std::vector<int> y;
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:
		float pOnLeft; // left line laser intensity in 'on' state
		float pOnRight; // right line laser intensity in 'on' state

		Sbecore::utinyint levelOn; // lower threshold level for 'on' state
		Sbecore::utinyint levelOff; // upper threshold level for 'off' state

		int roiAx;
		int roiAy;
		int roiBx;
		int roiBy;
		int roiCx;
		int roiCy;
		int roiDx;
		int roiDy;

		std::vector<bool> left; // wGrrd * hGrrd
		std::vector<bool> right; // wGrrd * hGrrd

		// IP Shrdat.vars.cust --- IBEGIN
		bool loopNotSngshot;

		Sbecore::Result result;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskIprTrace(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskIprTrace();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobWzskSrcV4l2* srcv4l2;
	JobWzskActLaser* actlaser;
	JobWzskAcqFpgaflg* acqfpgaflg;

	// IP vars.spec --- INSERT

	// IP vars.cust --- IBEGIN
	unsigned int ixRiSrcOn;
	unsigned int ixRiSrc;

	unsigned int ixRi;

	// intermediate results
	uint16_t* flg16; // 64 x 768

	double tMin;

	bool rightNotLeft;
	bool onNotOff;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskIprTrace)
		*/
	class Claim : public Sbecore::Claim {

	public:
		Claim(const bool retractable = true, const bool run = false, const bool loopNotSngshot = false);

	public:
		bool loopNotSngshot;
	};

	void flagV4l2(uint16_t* rd16, uint16_t* flg16, const uint16_t thd16, const bool deltaNotAbs);
	void deltaV4l2(uint16_t* on16, uint16_t* off16, uint16_t* flg16, const uint16_t thd16);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:
	bool setLevel(DbsWzsk* dbswzsk, const Sbecore::utinyint levelOn, const Sbecore::utinyint levelOff);
	bool setRoi(DbsWzsk* dbswzsk, const int roiAx, const int roiAy, const int roiBx, const int roiBy, const int roiCx, const int roiCy, const int roiDx, const int roiDy);
	bool setRoiNotFull(DbsWzsk* dbswzsk, const bool roiNotFull);

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

	void handleTimerInSgePrcidle(DbsWzsk* dbswzsk, const std::string& sref);
	void handleTimerWithSrefSrcstopInSgeDone(DbsWzsk* dbswzsk);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskResultNewFromAcqfpgaflgWithSrefThddelta(DbsWzsk* dbswzsk, const Sbecore::uint ixInv);
	bool handleCallWzskResultNewFromSrcv4l2(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskWaitsecondFromAcqfpgaflgInSgeLefton(DbsWzsk* dbswzsk);
	bool handleCallWzskWaitsecondFromAcqfpgaflgInSgeRighton(DbsWzsk* dbswzsk);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeReady(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeReady(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgePrcidle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgePrcidle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeProcess(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeProcess(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeLefton(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeLefton(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeLeftoff(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeLeftoff(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeRighton(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeRighton(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeRightoff(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeRightoff(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeDone(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeDone(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
