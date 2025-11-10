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

#define ShrdatJobWzskAcqHdr JobWzskAcqHdr::Shrdat

/**
	* JobWzskAcqHdr
	*/
class JobWzskAcqHdr : public CsjobWzsk {

public:
	bool evalSrcdcvspConstr(DbsWzsk* dbswzsk);
	bool evalSrctivspConstr(DbsWzsk* dbswzsk);
	bool evalSrczuvspConstr(DbsWzsk* dbswzsk);

	/// newline before subs!

	/**
		* Shrdat (full: ShrdatJobWzskAcqHdr)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* Resultitem (full: ResultitemJobFrdpAcqFpgacube)
			*/
		class Resultitem : public Frdp::ResultitemCube {

		public:
			Resultitem(Shrdat& super, const Frdp::Cubeinfo& ci, const Sbecore::uint ixDma);
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		int fd;
		void* buf;

		unsigned char* bufDummy;

		pthread_t cube;
		Sbecore::Mutex mCube;

		bool cancelCube;

		Sbecore::Result resultCube;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskAcqHdr(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskAcqHdr();

public:
	static Shrdat shrdat;

	JobWzskSrcDcvsp* srcdcvsp;
	JobWzskSrcTivsp* srctivsp;
	JobWzskSrcZuvsp* srczuvsp;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	static void* runCube(void* arg);
	static void cleanupCube(void* arg);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

	/// and changeStage
private:
	bool handleCallFrdpCallbackFromSelfInSgeRng(DbsFrdp* dbsfrdp, const Sbecore::uint ixInv, const std::string& srefInv);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
