/**
	* \file JobWzskActRotary.h
	* job handler for job JobWzskActRotary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACTROTARY_H
#define JOBWZSKACTROTARY_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcDcvsp.h"
#include "JobWzskSrcTivsp.h"
#include "JobWzskSrcZuvsp.h"

#define VecVJobWzskActRotaryMethod JobWzskActRotary::VecVMethod
#define VecVJobWzskActRotarySge JobWzskActRotary::VecVSge
#define VecVJobWzskActRotaryVar JobWzskActRotary::VecVVar

#define ShrdatJobWzskActRotary JobWzskActRotary::Shrdat

/**
	* JobWzskActRotary
	*/
class JobWzskActRotary : public CsjobWzsk {

public:
	/**
		* VecVMethod (full: VecVJobWzskActRotaryMethod)
		*/
	class VecVMethod {

	public:
		static const Sbecore::uint MOVETO = 1;
		static const Sbecore::uint STOP = 2;
		static const Sbecore::uint TURN = 3;
		static const Sbecore::uint ZERO = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVSge (full: VecVJobWzskActRotarySge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint MOVE = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskActRotaryVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint ANGLETARGET = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	bool evalSrcdcvspConstr(DbsWzsk* dbswzsk);
	bool evalSrctivspConstr(DbsWzsk* dbswzsk);
	bool evalSrczuvspConstr(DbsWzsk* dbswzsk);
	/**
		* Shrdat (full: ShrdatJobWzskActRotary)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		float angle; // in deg
		float target; // in deg

		// IP Shrdat.vars.cust --- INSERT

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskActRotary(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskActRotary();

public:
	static Shrdat shrdat;

	JobWzskSrcDcvsp* srcdcvsp;
	JobWzskSrcTivsp* srctivsp;
	JobWzskSrcZuvsp* srczuvsp;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	void updateAngle(DbsWzsk* dbswzsk);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:
	bool moveto(DbsWzsk* dbswzsk, const float target);
	bool stop(DbsWzsk* dbswzsk);
	bool turn(DbsWzsk* dbswzsk, const bool ccwNotCw);
	bool zero(DbsWzsk* dbswzsk);

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleTimerWithSrefMonInSgeMove(DbsWzsk* dbswzsk);
	void handleTimerWithSrefCallbackInSgeMove(DbsWzsk* dbswzsk);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeMove(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeMove(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
