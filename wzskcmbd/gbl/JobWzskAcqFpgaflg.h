/**
	* \file JobWzskAcqFpgaflg.h
	* job handler for job JobWzskAcqFpgaflg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACQFPGAFLG_H
#define JOBWZSKACQFPGAFLG_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcFpga.h"

#define VecVJobWzskAcqFpgaflgSge JobWzskAcqFpgaflg::VecVSge

#define ShrdatJobWzskAcqFpgaflg JobWzskAcqFpgaflg::Shrdat

/**
	* JobWzskAcqFpgaflg
	*/
class JobWzskAcqFpgaflg : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskAcqFpgaflgSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint RNG = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Shrdat (full: ShrdatJobWzskAcqFpgaflg)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* ResultitemFlg (full: ResultitemJobWzskAcqFpgaflg)
			*/
		class ResultitemFlg : public Sbecore::Resultitem {

		public:
			ResultitemFlg();
			~ResultitemFlg();

		public:
			bool thdNotCorner;
			bool thdDeltaNotAbs;

			unsigned char* buf;
			size_t sizeBuf;

			// (converted) from featdet.getInfo()
			Sbecore::utinyint tixVThdstate;
			double t;

			// from featdet.getCornerinfo()
			Sbecore::utinyint shift;
			Sbecore::utinyint scoreMin;
			Sbecore::utinyint scoreMax;
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		pthread_t flg;
		Sbecore::Mutex mFlg;

		Sbecore::Cond cFlg;

		// info passed to flg sub-thread
		bool thdNotCorner;
		bool thdDeltaNotAbs;

		bool cornerLinNotLog;
		Sbecore::utinyint cornerThd;

		Sbecore::utinyint thdLvlFirst;
		Sbecore::utinyint thdLvlSecond;

		bool cancelFlg;
		//

		Sbecore::Result resultFlg;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskAcqFpgaflg(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskAcqFpgaflg();

public:
	static Shrdat shrdat;

	JobWzskSrcFpga* srcfpga;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskAcqFpgaflg)
		*/
	class Claim : public Sbecore::Claim {

	public:
		Claim(const bool retractable = true, const bool run = false, const bool thdNotCorner = false, const bool thdDeltaNotAbs = false, const bool cornerLinNotLog = false, const Sbecore::utinyint cornerThd = 0, const Sbecore::utinyint thdLvlFirst = 0, const Sbecore::utinyint thdLvlSecond = 0);

	public:
		bool thdNotCorner;
		bool thdDeltaNotAbs;

		bool cornerLinNotLog;
		Sbecore::utinyint cornerThd;

		Sbecore::utinyint thdLvlFirst;
		Sbecore::utinyint thdLvlSecond;
	};

	static void* runFlg(void* arg);
	static void cleanupFlg(void* arg);

	void trigger();
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskCallbackFromSelfInSgeRng(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeRng(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeRng(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
