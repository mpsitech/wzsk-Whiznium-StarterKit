/**
	* \file JobWzskActLaser.h
	* job handler for job JobWzskActLaser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACTLASER_H
#define JOBWZSKACTLASER_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcDcvsp.h"
#include "JobWzskSrcTivsp.h"
#include "JobWzskSrcZuvsp.h"

#define VecVJobWzskActLaserMethod JobWzskActLaser::VecVMethod
#define VecVJobWzskActLaserVar JobWzskActLaser::VecVVar

#define StgJobWzskActLaser JobWzskActLaser::Stg

#define ShrdatJobWzskActLaser JobWzskActLaser::Shrdat

/**
	* JobWzskActLaser
	*/
class JobWzskActLaser : public CsjobWzsk {

public:
	/**
		* VecVMethod (full: VecVJobWzskActLaserMethod)
		*/
	class VecVMethod {

	public:
		static const Sbecore::uint SETLEFT = 1;
		static const Sbecore::uint SETRIGHT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskActLaserVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint LEFTRIGHT = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskActLaser)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint LEFTMIN = 1;
		static const Sbecore::uint LEFTMAX = 2;
		static const Sbecore::uint RIGHTMIN = 3;
		static const Sbecore::uint RIGHTMAX = 4;

	public:
		Stg(const Sbecore::usmallint leftMin = 256, const Sbecore::usmallint leftMax = 512, const Sbecore::usmallint rightMin = 256, const Sbecore::usmallint rightMax = 512);

	public:
		Sbecore::usmallint leftMin; // experimentally, full range corresponds to 25% .. 50%
		Sbecore::usmallint leftMax;

		Sbecore::usmallint rightMin;
		Sbecore::usmallint rightMax;

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
		* Shrdat (full: ShrdatJobWzskActLaser)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		float left;
		float right;

		// IP Shrdat.vars.cust --- INSERT

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskActLaser(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskActLaser();

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
	static Sbecore::usmallint pToAbs(const bool rightNotLeft, const float p);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:
	bool setLeft(DbsWzsk* dbswzsk, const float left);
	bool setRight(DbsWzsk* dbswzsk, const float right);

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
