/**
	* \file JobWzskSrcIcicle.h
	* job handler for job JobWzskSrcIcicle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
	*/
// IP header --- ABOVE

#ifndef JOBWZSKSRCICICLE_H
#define JOBWZSKSRCICICLE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVJobWzskSrcIcicleSge JobWzskSrcIcicle::VecVSge

#define StgJobWzskSrcIcicle JobWzskSrcIcicle::Stg

#define ShrdatJobWzskSrcIcicle JobWzskSrcIcicle::Shrdat

/**
	* JobWzskSrcIcicle
	*/
class JobWzskSrcIcicle : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskSrcIcicleSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint NC = 1;
		static const Sbecore::uint READY = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskSrcIcicle)
		*/
	class Stg : public Sbecore::Block {

	public:
		static const Sbecore::uint PATH = 1;

	public:
		Stg(const std::string& path = "/dev/icicle");

	public:
		std::string path;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskSrcIcicle)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		UntWskdIccl hw;

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
	JobWzskSrcIcicle(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskSrcIcicle();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskSrcIcicle)
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
	double tkstToT(const uint32_t tkst);

	// - EzdevWskd methods available to the outside

	// camacq
	bool camacq_setGrrd(const bool rng, const bool redNotGray);
	bool camacq_setPvw(const bool rng, const bool rawNotBin, const bool grayNotRgb);
	bool camacq_getPvwinfo(uint8_t& tixVPvwbufstate, uint32_t& tkst);

	// camif
	bool camif_setRng(const bool rng);
	bool camif_setReg(const uint16_t regaddr, const uint8_t val);
	bool camif_getReg(const uint16_t regaddr, uint8_t& val); // includes setRegaddr
	bool camif_modReg(const uint16_t regaddr, const uint8_t mask, const uint8_t val);

	// featdet
	bool featdet_set(const bool rng, const bool thdNotCorner, const bool thdDeltaNotAbs);
	bool featdet_getInfo(uint8_t& tixVFlgbufstate, uint8_t& tixVThdstate, uint32_t& tkst);
	bool featdet_getCornerinfo(uint8_t& shift, uint8_t& scoreMin, uint8_t& scoreMax);

	bool featdet_setCorner(const bool linNotLog, const uint32_t Ntrg);
	bool featdet_setThd(const uint8_t lvlFirst, const uint8_t lvlSecond);
	bool featdet_triggerThd();

	// laser
	bool laser_set(const uint16_t l, const uint16_t r);

	// step
	bool step_zero();

	// tkclksrc
	bool tkclksrc_getTkst(uint32_t& tkst);

	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleStartRxtxdump(DbsWzsk* dbswzsk);
	bool handleStopRxtxdump(DbsWzsk* dbswzsk);
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
