/**
	* \file JobWzskSrcPwmonusb.h
	* job handler for job JobWzskSrcPwmonusb (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Jun 2022
	*/
// IP header --- ABOVE

#ifndef JOBWZSKSRCPWMONUSB_H
#define JOBWZSKSRCPWMONUSB_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVJobWzskSrcPwmonusbSge JobWzskSrcPwmonusb::VecVSge

#define StgJobWzskSrcPwmonusb JobWzskSrcPwmonusb::Stg

#define ShrdatJobWzskSrcPwmonusb JobWzskSrcPwmonusb::Shrdat

/**
	* JobWzskSrcPwmonusb
	*/
class JobWzskSrcPwmonusb : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskSrcPwmonusbSge)
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
		* Stg (full: StgJobWzskSrcPwmonusb)
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
		* Shrdat (full: ShrdatJobWzskSrcPwmonusb)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		UntPmndUbdk hw;

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
	JobWzskSrcPwmonusb(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskSrcPwmonusb();

public:
	static Stg stg;
	static Shrdat shrdat;

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
