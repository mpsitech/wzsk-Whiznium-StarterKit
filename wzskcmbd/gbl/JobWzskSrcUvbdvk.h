/**
	* \file JobWzskSrcUvbdvk.h
	* job handler for job JobWzskSrcUvbdvk (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
	*/
// IP header --- ABOVE

#ifndef JOBWZSKSRCUVBDVK_H
#define JOBWZSKSRCUVBDVK_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVJobWzskSrcUvbdvkSge JobWzskSrcUvbdvk::VecVSge

#define StgJobWzskSrcUvbdvk JobWzskSrcUvbdvk::Stg

#define ShrdatJobWzskSrcUvbdvk JobWzskSrcUvbdvk::Shrdat

/**
	* JobWzskSrcUvbdvk
	*/
class JobWzskSrcUvbdvk : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskSrcUvbdvkSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint NC = 1;
		static const Sbecore::uint READY = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskSrcUvbdvk)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint PATH = 1;

	public:
		Stg(const std::string& path = "/dev/ttyUSB0");

	public:
		std::string path;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskSrcUvbdvk)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		UntWskdUbdk hw;

		bool excdump;
		bool verbose;

		// 100Hz clock source offset
		double t0;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskSrcUvbdvk(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskSrcUvbdvk();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskSrcUvbdvk)
		*/
	class Claim : public Sbecore::Claim {

	public:
		Claim(const bool retractable = true, const bool all = false, const bool laser = false, const bool step = false);

	public:
		bool all;
		bool laser; // uses laser_set
		bool step; // uses step_*
	};

	// - high-level methods

	// stepper motor
	bool getAngle(float& angle);
	bool moveto(float& _angle, const float omega);
	bool setStep(const bool rng, const bool ccwNotCw, const float omega);

	// 100Hz clock source
	double hhstToT(const uint32_t hhst);

	// - EzdevWskd methods available to the outside

	// chrono
	bool chrono_getHhst(uint32_t& hhst);

	// laser
	bool laser_set(const uint16_t l, const uint16_t r);

	// step
	bool step_zero();

	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleStartRxtxdump(DbsWzsk* dbswzsk);
	bool handleStopRxtxdump(DbsWzsk* dbswzsk);
	bool handleTest(DbsWzsk* dbswzsk);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeNc(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeNc(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeReady(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeReady(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
