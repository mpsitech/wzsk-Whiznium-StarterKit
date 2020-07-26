/**
	* \file JobWzskAcqPtcloud.h
	* job handler for job JobWzskAcqPtcloud (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef JOBWZSKACQPTCLOUD_H
#define JOBWZSKACQPTCLOUD_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskIprTrace.h"
#include "JobWzskActServo.h"

#define VecVJobWzskAcqPtcloudSge JobWzskAcqPtcloud::VecVSge
#define VecVJobWzskAcqPtcloudVar JobWzskAcqPtcloud::VecVVar

#define StgJobWzskAcqPtcloud JobWzskAcqPtcloud::Stg

#define ShrdatJobWzskAcqPtcloud JobWzskAcqPtcloud::Shrdat

/**
	* JobWzskAcqPtcloud
	*/
class JobWzskAcqPtcloud : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskAcqPtcloudSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint READY = 2;
		static const Sbecore::uint ACQUIRE = 3;
		static const Sbecore::uint PRCIDLE = 4;
		static const Sbecore::uint PROCESS = 5;
		static const Sbecore::uint TURN = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskAcqPtcloudVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint XYZ = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskAcqPtcloud)
		*/
	class Stg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLEFT = 1;
		static const Sbecore::uint DRIGHT = 2;
		static const Sbecore::uint DWORK = 3;
		static const Sbecore::uint DELTATHETA = 4;

	public:
		Stg(const float dLeft = 0.2, const float dRight = 0.2, const float dWork = 0.2, const float deltaTheta = 5);

	public:
		float dLeft;
		float dRight;

		float dWork;
		float deltaTheta;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskAcqPtcloud)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* ResultitemBody
			*/
		class ResultitemBody : public Sbecore::Resultitem {

		public:
			ResultitemBody();
			~ResultitemBody();

		public:
			double tStart;
			double tStop;

			std::vector<bool> rNotL;

			// probably use x.reserve(72000) before pushing back
			std::vector<float> x;
			std::vector<float> y;
			std::vector<float> z;
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:
		std::vector<float> x;
		std::vector<float> y;
		std::vector<float> z;

		// IP Shrdat.vars.cust --- IBEGIN
		Sbecore::Result resultBody;

		float theta;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskAcqPtcloud(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskAcqPtcloud();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobWzskIprTrace* iprtrace;
	JobWzskActServo* actservo;

	// IP vars.spec --- INSERT

	// IP vars.cust --- IBEGIN
	uint ixRiSrc;

	uint ixRi;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

	void handleTimerInSgePrcidle(DbsWzsk* dbswzsk, const std::string& sref);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSgeChgFromActservoInSgeTurn(DbsWzsk* dbswzsk);
	bool handleCallWzskResultNewFromIprtraceInSgeAcquire(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeReady(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeReady(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeAcquire(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeAcquire(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgePrcidle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgePrcidle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeProcess(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeProcess(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeTurn(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeTurn(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif



