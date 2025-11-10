/**
	* \file JobWzskActVistorot.h
	* job handler for job JobWzskActVistorot (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACTVISTOROT_H
#define JOBWZSKACTVISTOROT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskPrcAngle.h"
#include "JobWzskSrcDcvsp.h"
#include "JobWzskSrcTivsp.h"
#include "JobWzskSrcZuvsp.h"

#define StgJobWzskActVistorot JobWzskActVistorot::Stg

#define ShrdatJobWzskActVistorot JobWzskActVistorot::Shrdat

/**
	* JobWzskActVistorot
	*/
class JobWzskActVistorot : public CsjobWzsk {

public:
	/**
		* Stg (full: StgJobWzskActVistorot)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint OMEGAMAX = 1;
		static const Sbecore::uint _P = 2;
		static const Sbecore::uint _I = 3;

	public:
		Stg(const float omegaMax = 9, const float P = 0.5, const float I = 1);

	public:
		float omegaMax; // [\u00a1/s]
		float P; // [(\u00a1/s)/\u00a1]
		float I; // [(\u00a1/s)/(\u00a1s)]

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
		* Shrdat (full: ShrdatJobWzskActVistorot)
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
	JobWzskActVistorot(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskActVistorot();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobWzskPrcAngle* prcangle;
	JobWzskSrcDcvsp* srcdcvsp;
	JobWzskSrcTivsp* srctivsp;
	JobWzskSrcZuvsp* srczuvsp;

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
