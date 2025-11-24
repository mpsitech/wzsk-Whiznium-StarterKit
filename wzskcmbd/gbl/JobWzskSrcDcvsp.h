/**
	* \file JobWzskSrcDcvsp.h
	* job handler for job JobWzskSrcDcvsp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Oct 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKSRCDCVSP_H
#define JOBWZSKSRCDCVSP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVJobWzskSrcDcvspSge JobWzskSrcDcvsp::VecVSge

#define StgJobWzskSrcDcvsp JobWzskSrcDcvsp::Stg

#define ShrdatJobWzskSrcDcvsp JobWzskSrcDcvsp::Shrdat

/**
	* JobWzskSrcDcvsp
	*/
class JobWzskSrcDcvsp : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskSrcDcvspSge)
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
		* Stg (full: StgJobWzskSrcDcvsp)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint PATH = 1;

	public:
		Stg(const std::string& path = "/dev/dbeaxilite0");

	public:
		std::string path;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskSrcDcvsp)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		UntWskdDcvsp hw;

		bool excdump;
		bool verbose;

		// 10kHz clock source offset
		double t0;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskSrcDcvsp(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskSrcDcvsp();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN

	// - UntWskdDcvsp convenience methods with real-world units

	// ident
	static bool ident_get(std::string& unt, std::string& ver, std::string& hash, std::string& who);
	bool ident_getCfg(float& fMclk, float& fMemclk);

	// laser
	bool laser_set(const uint16_t l, const uint16_t r);

	// rotary
	bool rotary_getInfo(std::string& srefTixVState, float& angle);
	bool rotary_moveto(float& _angle);
	bool rotary_set(const bool rng, const bool ccwNotCw);
	bool rotary_zero();

	// - high-level methods

	// 10kHz clock source
	double tkstToT(const uint32_t tkst);

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
