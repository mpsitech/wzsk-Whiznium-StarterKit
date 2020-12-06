/**
	* \file JobWzskIprAngle.h
	* job handler for job JobWzskIprAngle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKIPRANGLE_H
#define JOBWZSKIPRANGLE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskIprCorner.h"

#define ShrdatJobWzskIprAngle JobWzskIprAngle::Shrdat

/**
	* JobWzskIprAngle
	*/
class JobWzskIprAngle : public CsjobWzsk {

public:
	/**
		* Shrdat (full: ShrdatJobWzskIprAngle)
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
	JobWzskIprAngle(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskIprAngle();

public:
	static Shrdat shrdat;

	JobWzskIprCorner* iprcorner;

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
	bool handleTest(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
