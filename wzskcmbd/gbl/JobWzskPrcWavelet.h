/**
	* \file JobWzskPrcWavelet.h
	* job handler for job JobWzskPrcWavelet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKPRCWAVELET_H
#define JOBWZSKPRCWAVELET_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskAcqHdr.h"

#define ShrdatJobWzskPrcWavelet JobWzskPrcWavelet::Shrdat

/**
	* JobWzskPrcWavelet
	*/
class JobWzskPrcWavelet : public CsjobWzsk {

public:

	/**
		* Shrdat (full: ShrdatJobWzskPrcWavelet)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- INSERT

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskPrcWavelet(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskPrcWavelet();

public:
	static Shrdat shrdat;

	JobWzskAcqHdr* acqhdr;

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

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
