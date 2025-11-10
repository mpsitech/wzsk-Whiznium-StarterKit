/**
	* \file JobWzskSrcFpgainfo.h
	* job handler for job JobWzskSrcFpgainfo (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 2 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKSRCFPGAINFO_H
#define JOBWZSKSRCFPGAINFO_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcDcvsp.h"
#include "JobWzskSrcTivsp.h"
#include "JobWzskSrcZuvsp.h"

#define VecVJobWzskSrcFpgainfoSge JobWzskSrcFpgainfo::VecVSge
#define VecVJobWzskSrcFpgainfoVar JobWzskSrcFpgainfo::VecVVar

#define ShrdatJobWzskSrcFpgainfo JobWzskSrcFpgainfo::Shrdat

/**
	* JobWzskSrcFpgainfo
	*/
class JobWzskSrcFpgainfo : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskSrcFpgainfoSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint RUN = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskSrcFpgainfoVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint HDRDRDHDRDWR = 1;
		static const Sbecore::uint RNDDRDRNDDWR = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	bool evalSrcdcvspConstr(DbsWzsk* dbswzsk);
	bool evalSrctivspConstr(DbsWzsk* dbswzsk);
	bool evalSrczuvspConstr(DbsWzsk* dbswzsk);
	/**
		* Shrdat (full: ShrdatJobWzskSrcFpgainfo)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		float hdrDRd;
		float hdrDWr;

		float rndDRd;
		float rndDWr;

		// IP Shrdat.vars.cust --- INSERT

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskSrcFpgainfo(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskSrcFpgainfo();

public:
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

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

	void handleTimerWithSrefMonInSgeRun(DbsWzsk* dbswzsk);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeRun(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeRun(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
