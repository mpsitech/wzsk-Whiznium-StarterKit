/**
	* \file JobWzskActExposure.h
	* job handler for job JobWzskActExposure (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACTEXPOSURE_H
#define JOBWZSKACTEXPOSURE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcV4l2.h"
#include "JobWzskSrcFpga.h"

#define VecVJobWzskActExposureMethod JobWzskActExposure::VecVMethod
#define VecVJobWzskActExposureVar JobWzskActExposure::VecVVar

#define ShrdatJobWzskActExposure JobWzskActExposure::Shrdat

/**
	* JobWzskActExposure
	*/
class JobWzskActExposure : public CsjobWzsk {

public:
	/**
		* VecVMethod (full: VecVJobWzskActExposureMethod)
		*/
	class VecVMethod {

	public:
		static const Sbecore::uint SETEXPOSURE = 1;
		static const Sbecore::uint SETFOCUS = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskActExposureVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint AUTONOTMANUALTEXP = 1;
		static const Sbecore::uint FOCUS = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Shrdat (full: ShrdatJobWzskActExposure)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		bool autoNotManual;
		float Texp;

		float focus;

		// IP Shrdat.vars.cust --- INSERT

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskActExposure(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskActExposure();

public:
	static Shrdat shrdat;

	JobWzskSrcV4l2* srcv4l2;
	JobWzskSrcFpga* srcfpga;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	// IP spec --- INSERT

public:
	bool setExposure(DbsWzsk* dbswzsk, const bool autoNotManual, const float Texp);
	bool setFocus(DbsWzsk* dbswzsk, const float focus);

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
