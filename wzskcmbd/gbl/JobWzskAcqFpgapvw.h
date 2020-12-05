/**
	* \file JobWzskAcqFpgapvw.h
	* job handler for job JobWzskAcqFpgapvw (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACQFPGAPVW_H
#define JOBWZSKACQFPGAPVW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcFpga.h"

#define VecVJobWzskAcqFpgapvwSge JobWzskAcqFpgapvw::VecVSge

#define ShrdatJobWzskAcqFpgapvw JobWzskAcqFpgapvw::Shrdat

/**
	* JobWzskAcqFpgapvw
	*/
class JobWzskAcqFpgapvw : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskAcqFpgapvwSge)
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
		* Shrdat (full: ShrdatJobWzskAcqFpgapvw)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* ResultitemPvw (full: ResultitemJobWzskSrcFpgaPvw)
			*/
		class ResultitemPvw : public Sbecore::Resultitem {

		public:
			ResultitemPvw();
			~ResultitemPvw();

		public:
			Sbecore::uint ixWzskVPvwmode;

			unsigned char* buf;
			size_t sizeBuf;

			// converted from camacq.getPvwinfo()
			double t;

		public:
			void setPvwmode(const Sbecore::uint ixWzskVPvwmode);
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		pthread_t pvw;
		Sbecore::Mutex mPvw;

		// info passed to pvw sub-thread
		Sbecore::uint ixWzskVPvwmode;

		bool cancelPvw;
		//

		Sbecore::Result resultPvw;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskAcqFpgapvw(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskAcqFpgapvw();

public:
	static Shrdat shrdat;

	JobWzskSrcFpga* srcfpga;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskAcqFpgapvw)
		*/
	class Claim : public Sbecore::Claim {

	public:
		Claim(const bool retractable = true, const bool run = false, const Sbecore::uint ixWzskVPvwmode = VecWzskVPvwmode::BINGRAY);

	public:
		Sbecore::uint ixWzskVPvwmode;
	};

	static void* runPvw(void* arg);
	static void cleanupPvw(void* arg);
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







