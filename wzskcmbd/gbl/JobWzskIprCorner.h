/**
	* \file JobWzskIprCorner.h
	* job handler for job JobWzskIprCorner (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKIPRCORNER_H
#define JOBWZSKIPRCORNER_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcV4l2.h"
#include "JobWzskAcqFpgaflg.h"

#define VecVJobWzskIprCornerMethod JobWzskIprCorner::VecVMethod
#define VecVJobWzskIprCornerSge JobWzskIprCorner::VecVSge
#define VecVJobWzskIprCornerVar JobWzskIprCorner::VecVVar

#define StgJobWzskIprCorner JobWzskIprCorner::Stg

#define ShrdatJobWzskIprCorner JobWzskIprCorner::Shrdat

/**
	* JobWzskIprCorner
	*/
class JobWzskIprCorner : public CsjobWzsk {

public:
	/**
		* VecVMethod (full: VecVJobWzskIprCornerMethod)
		*/
	class VecVMethod {

	public:
		static const Sbecore::uint SETNTARGET = 1;
		static const Sbecore::uint SETROI = 2;
		static const Sbecore::uint SETROINOTFULL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVSge (full: VecVJobWzskIprCornerSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint READY = 2;
		static const Sbecore::uint PRCIDLE = 3;
		static const Sbecore::uint PROCESS = 4;
		static const Sbecore::uint DONE = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskIprCornerVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint NTARGET = 1;
		static const Sbecore::uint ROIAXROIAYROIBXROIBYROICXROICYROIDXROIDY = 2;
		static const Sbecore::uint FLGSHIFTSCOREMINSCOREMAX = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskIprCorner)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint LINNOTLOG = 1;
		static const Sbecore::uint ROINOTFULL = 2;
		static const Sbecore::uint FLGPERROWMAX = 3;

	public:
		Stg(const bool linNotLog = false, const bool roiNotFull = false, const Sbecore::utinyint flgPerRowMax = 50);

	public:
		bool linNotLog;
		bool roiNotFull;
		Sbecore::utinyint flgPerRowMax;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskIprCorner)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* ResultitemCorner (full: ResultitemJobWzskIprCornerCorner)
			*/
		class ResultitemCorner : public Sbecore::Resultitem {

		public:
			ResultitemCorner();
			~ResultitemCorner();

		public:
			Sbecore::uint NCorner;
			Sbecore::utinyint thd;

			double tIn;
			double tOut;

			std::vector<int> x;
			std::vector<int> y;
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:
		Sbecore::usmallint NTarget;

		int roiAx;
		int roiAy;
		int roiBx;
		int roiBy;
		int roiCx;
		int roiCy;
		int roiDx;
		int roiDy;

		std::vector<bool> flg;
		Sbecore::utinyint shift;
		Sbecore::utinyint scoreMin;
		Sbecore::utinyint scoreMax;

		// IP Shrdat.vars.cust --- IBEGIN
		bool loopNotSngshot;

		Sbecore::Result result;

		Sbecore::utinyint thd; // constantly adapted, enforced using srcfpga->featdet_setThd();
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskIprCorner(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskIprCorner();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobWzskSrcV4l2* srcv4l2;
	JobWzskAcqFpgaflg* acqfpgaflg;

	// IP vars.spec --- INSERT

	// IP vars.cust --- IBEGIN
	unsigned int ixRiSrc;

	unsigned int ixRi;

	Sbecore::utinyint shift_last;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskIprCorner)
		*/
	class Claim : public Sbecore::Claim {

	public:
		Claim(const bool retractable = true, const bool run = false, const bool loopNotSngshot = false);

	public:
		bool loopNotSngshot;
	};

	void scoreV4l2(uint16_t* gr16, uint16_t* score16, const bool linNotLog, Sbecore::utinyint& shift, Sbecore::utinyint& _scoreMin, Sbecore::utinyint& _scoreMax);
	void scoreV4l2Fp(uint16_t* gr16, uint16_t* score16, const bool linNotLog, Sbecore::utinyint& shift, Sbecore::utinyint& _scoreMin, Sbecore::utinyint& _scoreMax);

	void maxselV4l2(uint16_t* score16, uint16_t* corner16, Sbecore::uint& NCorner);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:
	bool setNTarget(DbsWzsk* dbswzsk, const Sbecore::usmallint NTarget);
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
	bool handleCallWzskResultNewFromAcqfpgaflgWithSrefCornerInSgeReady(DbsWzsk* dbswzsk, const Sbecore::uint ixInv);
	bool handleCallWzskResultNewFromSrcv4l2InSgeReady(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);

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
	Sbecore::uint enterSgeDone(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeDone(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
