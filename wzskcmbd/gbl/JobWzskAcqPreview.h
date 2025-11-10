/**
	* \file JobWzskAcqPreview.h
	* job handler for job JobWzskAcqPreview (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACQPREVIEW_H
#define JOBWZSKACQPREVIEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcDcvsp.h"
#include "JobWzskSrcTivsp.h"
#include "JobWzskSrcZuvsp.h"

#define VecVJobWzskAcqPreviewSge JobWzskAcqPreview::VecVSge

#define StgJobWzskAcqPreview JobWzskAcqPreview::Stg

#define ShrdatJobWzskAcqPreview JobWzskAcqPreview::Shrdat

/**
	* JobWzskAcqPreview
	*/
class JobWzskAcqPreview : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskAcqPreviewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint RNG = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskAcqPreview)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint RGBNOTGRAY = 1;
		static const Sbecore::uint DECIM = 2;

	public:
		Stg(const bool rgbNotGray = true, const Sbecore::utinyint decim = 10);

	public:
		bool rgbNotGray;
		Sbecore::utinyint decim;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	bool evalSrcdcvspConstr(DbsWzsk* dbswzsk);
	bool evalSrctivspConstr(DbsWzsk* dbswzsk);
	bool evalSrczuvspConstr(DbsWzsk* dbswzsk);
	/**
		* Shrdat (full: ShrdatJobWzskAcqPreview)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* Resultitem (full: ResultitemJobWzskAcqPreview)
			*/
		class Resultitem : public Sbecore::Resultitem {

		public:
			Resultitem(XchgWzsk* xchg);
			~Resultitem();

		public:
			unsigned int w;
			unsigned int h;

			bool rgbNotGray;
			Sbecore::utinyint edge;

			unsigned char* buf; // allocate space for max i.e. rgb and edge 6
			size_t sizeBuf;

			// converted from decim.getInfo()
			double t;

		public:
			void config(const bool _rgbNotGray, const Sbecore::utinyint _edge);
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		pthread_t pvw;
		Sbecore::Mutex mPvw;

		// info passed to pvw sub-thread
		bool rgbNotGray_next;
		Sbecore::utinyint edge_next;

		bool cancelPvw;

		Sbecore::Result resultPvw;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskAcqPreview(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskAcqPreview();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobWzskSrcDcvsp* srcdcvsp;
	JobWzskSrcTivsp* srctivsp;
	JobWzskSrcZuvsp* srczuvsp;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskAcqPreview)
		*/
	class Claim : public Sbecore::Claim {

	public:
		Claim(const bool retractable = true, const bool run = false, const bool rgbNotGray = false, const Sbecore::utinyint edge = 6);

	public:
		bool rgbNotGray;
		Sbecore::utinyint edge;
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

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskCallbackFromSelfInSgeRng(DbsWzsk* dbswzsk);

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
