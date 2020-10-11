/**
	* \file JobWzskSrcFpga.h
	* job handler for job JobWzskSrcFpga (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef JOBWZSKSRCFPGA_H
#define JOBWZSKSRCFPGA_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include "DevWskd.h"
// IP include.cust --- IEND

#define VecVJobWzskSrcFpgaSge JobWzskSrcFpga::VecVSge

#define StgJobWzskSrcFpga JobWzskSrcFpga::Stg

#define ShrdatJobWzskSrcFpga JobWzskSrcFpga::Shrdat

/**
	* JobWzskSrcFpga
	*/
class JobWzskSrcFpga : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskSrcFpgaSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint NC = 1;
		static const Sbecore::uint READY = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskSrcFpga)
		*/
	class Stg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint PATH = 1;

	public:
		Stg(const std::string& path = "/dev/arty");

	public:
		std::string path;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskSrcFpga)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		UntWskdArty hw;

		bool excdump;
		bool verbose;

		// 10kHz clock source offset
		double t0;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskSrcFpga(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskSrcFpga();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskSrcFpga)
		*/
	class Claim : public Sbecore::Claim {

	public:
		Claim(const bool retractable = true, const bool all = false, const bool flg = false, const bool pvw = false, const bool laser = false, const bool step = false);

	public:
		bool all;
		bool flg;  // uses camif_setRng, camacq_setGrrd, featdet_*
		bool pvw; // uses camif_setRng, camacq_setPvw, camacq_getPvwinfo
		bool laser; // uses laser_set
		bool step; // uses step_*
	};

	// - high-level methods

	// camera interface
	bool setExposure(const bool autoNotManual, const float _Texp);
	bool setFocus(const float _focus);

	// stepper motor
	bool getAngle(float& angle);
	bool moveto(float& _angle, const float omega);
	bool setStep(const bool rng, const bool ccwNotCw, const float omega);

	// 10kHz clock source
	double tkstToT(const Sbecore::uint tkst);

	// - EzdevWskd methods available to the outside

	// camacq
	bool camacq_setGrrd(const bool rng, const bool redNotGray);
	bool camacq_setPvw(const bool rng, const bool rawNotBin, const bool grayNotRgb);
	bool camacq_getPvwinfo(Sbecore::utinyint& tixVPvwbufstate, Sbecore::uint& tkst);

	// camif
	bool camif_setRng(const bool rng);
	bool camif_setReg(const Sbecore::usmallint regaddr, const Sbecore::utinyint val);
	bool camif_getReg(const Sbecore::usmallint regaddr, Sbecore::utinyint& val); // includes setRegaddr
	bool camif_modReg(const Sbecore::usmallint regaddr, const Sbecore::utinyint mask, const Sbecore::utinyint val);

	// featdet
	bool featdet_set(const bool rng, const bool thdNotCorner, const bool thdDeltaNotAbs);
	bool featdet_getInfo(Sbecore::utinyint& tixVFlgbufstate, Sbecore::utinyint& tixVThdstate, Sbecore::uint& tkst);
	bool featdet_getCornerinfo(Sbecore::utinyint& shift, Sbecore::utinyint& scoreMin, Sbecore::utinyint& scoreMax);

	bool featdet_setCorner(const bool linNotLog, const Sbecore::uint Ntrg);
	bool featdet_setThd(const Sbecore::utinyint lvlFirst, const Sbecore::utinyint lvlSecond);
	bool featdet_triggerThd();

	// laser
	bool laser_set(const Sbecore::usmallint l, const Sbecore::usmallint r);

	// step
	bool step_zero();

	// tkclksrc
	bool tkclksrc_getTkst(Sbecore::uint& tkst);

	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
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



