/**
	* \file JobWzskPrcAngle.h
	* job handler for job JobWzskPrcAngle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKPRCANGLE_H
#define JOBWZSKPRCANGLE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskAcqCorner.h"

#define ShrdatJobWzskPrcAngle JobWzskPrcAngle::Shrdat

/**
	* JobWzskPrcAngle
	*/
class JobWzskPrcAngle : public CsjobWzsk {

public:
	/**
		* Shrdat (full: ShrdatJobWzskPrcAngle)
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
	JobWzskPrcAngle(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskPrcAngle();

public:
	static Shrdat shrdat;

	JobWzskAcqCorner* acqcorner;

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
