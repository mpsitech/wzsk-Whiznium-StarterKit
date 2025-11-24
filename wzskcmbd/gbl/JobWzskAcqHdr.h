/**
	* \file JobWzskAcqHdr.h
	* job handler for job JobWzskAcqHdr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACQHDR_H
#define JOBWZSKACQHDR_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <sys/ioctl.h>
#include <sys/mman.h>
#undef MAP_TYPE
#include <sys/stat.h>
#include <sys/types.h>
// IP include.cust --- IEND

#include "JobWzskSrcDcvsp.h"
#include "JobWzskSrcTivsp.h"
#include "JobWzskSrcZuvsp.h"

#define VecVJobWzskAcqHdrSge JobWzskAcqHdr::VecVSge

#define StgJobWzskAcqHdr JobWzskAcqHdr::Stg

#define ShrdatJobWzskAcqHdr JobWzskAcqHdr::Shrdat

/**
	* JobWzskAcqHdr
	*/
class JobWzskAcqHdr : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskAcqHdrSge)
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
		* Stg (full: StgJobWzskAcqHdr)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint PATH = 1;
		static const Sbecore::uint NCHUNK = 2;
		static const Sbecore::uint SIZECHUNK = 3;

	public:
		Stg(const std::string& path = "/dev/dbeaxishmem0", const Sbecore::utinyint NChunk = 12, const Sbecore::utinyint sizeChunk = 12);

	public:
		std::string path;
		Sbecore::utinyint NChunk;
		Sbecore::utinyint sizeChunk; // in MB

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
		* Shrdat (full: ShrdatJobWzskAcqHdr)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* Resultitem (full: ResultitemJobWzskAcqHdr)
			*/
		class Resultitem : public Sbecore::Resultitem {

		public:
			Resultitem(Shrdat& super, XchgWzsk* xchg, const Sbecore::uint ixDma);

		public:
			unsigned int w;
			unsigned int h;

			unsigned char* buf;
			size_t lenBuf;

			// converted from hdreng.getInfo()
			double t;
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		int fd;
		void* buf;

		unsigned char* bufDummy;

		pthread_t hdr;
		Sbecore::Mutex mHdr;

		bool cancelHdr;

		Sbecore::Result resultHdr;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskAcqHdr(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskAcqHdr();

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
	static void* runHdr(void* arg);
	static void cleanupHdr(void* arg);
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
