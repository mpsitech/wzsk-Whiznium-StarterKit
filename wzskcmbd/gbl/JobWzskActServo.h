/**
	* \file JobWzskActServo.h
	* job handler for job JobWzskActServo (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACTSERVO_H
#define JOBWZSKACTSERVO_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcFpga.h"

#define VecVJobWzskActServoMethod JobWzskActServo::VecVMethod
#define VecVJobWzskActServoSge JobWzskActServo::VecVSge
#define VecVJobWzskActServoVar JobWzskActServo::VecVVar

#define StgJobWzskActServo JobWzskActServo::Stg

#define ShrdatJobWzskActServo JobWzskActServo::Shrdat

/**
	* JobWzskActServo
	*/
class JobWzskActServo : public CsjobWzsk {

public:
	/**
		* VecVMethod (full: VecVJobWzskActServoMethod)
		*/
	class VecVMethod {

	public:
		static const Sbecore::uint MOVETO = 1;
		static const Sbecore::uint STOP = 2;
		static const Sbecore::uint TURN = 3;
		static const Sbecore::uint ZERO = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVSge (full: VecVJobWzskActServoSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint MOVE = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskActServoVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint ANGLETARGET = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskActServo)
		*/
	class Stg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint PATHROOT = 1;
		static const Sbecore::uint HALFSTEPNOTTORQUE = 2;
		static const Sbecore::uint OMEGA = 3;

	public:
		Stg(const std::string& pathroot = "/sys/class/pwm/pwmchip", const bool halfstepNotTorque = false, const float omega = 0.025);

	public:
		std::string pathroot;
		bool halfstepNotTorque;
		float omega;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskActServo)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		float angle;
		float target;

		// IP Shrdat.vars.cust --- IBEGIN
		bool ccwNotCw;
		float start;

		double t0;
		double t1;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskActServo(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskActServo();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobWzskSrcFpga* srcfpga;

	// IP vars.spec --- INSERT

	// IP vars.cust --- IBEGIN
	static constexpr int Npwm = 4;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void updateAngle(DbsWzsk* dbswzsk);
	static void stopGpio();
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
	bool handleTest(DbsWzsk* dbswzsk);

	void handleTimerWithSrefCallbackInSgeMove(DbsWzsk* dbswzsk);
	void handleTimerWithSrefMonInSgeMove(DbsWzsk* dbswzsk);

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







