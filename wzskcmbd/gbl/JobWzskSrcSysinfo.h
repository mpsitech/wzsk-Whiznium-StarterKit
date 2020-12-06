/**
	* \file JobWzskSrcSysinfo.h
	* job handler for job JobWzskSrcSysinfo (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKSRCSYSINFO_H
#define JOBWZSKSRCSYSINFO_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVJobWzskSrcSysinfoSge JobWzskSrcSysinfo::VecVSge
#define VecVJobWzskSrcSysinfoVar JobWzskSrcSysinfo::VecVVar

#define StgJobWzskSrcSysinfo JobWzskSrcSysinfo::Stg

#define ShrdatJobWzskSrcSysinfo JobWzskSrcSysinfo::Shrdat

/**
	* JobWzskSrcSysinfo
	*/
class JobWzskSrcSysinfo : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskSrcSysinfoSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint RUN = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskSrcSysinfoVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint LOADALLLOADCORE0LOADCORE1LOADCORE2LOADCORE3 = 1;
		static const Sbecore::uint TEMP = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskSrcSysinfo)
		*/
	class Stg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint PATHSTAT = 1;
		static const Sbecore::uint PATHTHERMAL = 2;
		static const Sbecore::uint PATHROOTXADC = 3;

	public:
		Stg(const std::string& pathStat = "/proc/stat", const std::string& pathThermal = "/sys/class/thermal/thermal_zone0/temp", const std::string& pathrootXadc = "/sys/bus/platform/drivers/xadc/f8007100.adc/iio:device0/in_temp0");

	public:
		std::string pathStat;

		std::string pathThermal;
		std::string pathrootXadc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskSrcSysinfo)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		std::vector<float> loadAll;
		std::vector<float> loadCore0;
		std::vector<float> loadCore1;
		std::vector<float> loadCore2;
		std::vector<float> loadCore3;

		std::vector<float> temp;

		// IP Shrdat.vars.cust --- IBEGIN
		unsigned int NCore;

		int unkAll, idleAll;
		int unkCore0, idleCore0;
		int unkCore1, idleCore1;
		int unkCore2, idleCore2;
		int unkCore3, idleCore3;

		float tempOffset;
		float tempScale;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskSrcSysinfo(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskSrcSysinfo();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	void getLoad();

	void getTempThermal();
	void getTempXadc();

	float getValFromFile(const std::string& path);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

	void handleTimerWithSrefMonInSgeRun(DbsWzsk* dbswzsk);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeRun(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeRun(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
