/**
	* \file JobWzskActLaser.h
	* job handler for job JobWzskActLaser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKACTLASER_H
#define JOBWZSKACTLASER_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <linux/gpio.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
// IP include.cust --- IEND

#include "JobWzskSrcArty.h"
#include "JobWzskSrcClnxevb.h"
#include "JobWzskSrcIcicle.h"
#include "JobWzskSrcMcvevp.h"
#include "JobWzskSrcUvbdvk.h"
#include "JobWzskSrcUzediocc.h"

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
		static const Sbecore::uint PATHGPIO = 1;
		static const Sbecore::uint LINEOFFSETLEFT = 2;
		static const Sbecore::uint LINEOFFSETRIGHT = 3;
		static const Sbecore::uint PATHSPI = 4;
		static const Sbecore::uint LEFTMIN = 5;
		static const Sbecore::uint LEFTMAX = 6;
		static const Sbecore::uint RIGHTMIN = 7;
		static const Sbecore::uint RIGHTMAX = 8;

	public:
		Stg(const std::string& pathGpio = "/dev/gpiochip5", const Sbecore::utinyint lineoffsetLeft = 10, const Sbecore::utinyint lineoffsetRight = 9, const std::string& pathSpi = "/dev/spidev0.0", const Sbecore::usmallint leftMin = 164, const Sbecore::usmallint leftMax = 245, const Sbecore::usmallint rightMin = 164, const Sbecore::usmallint rightMax = 245);

	public:
		std::string pathGpio; // corr. to GPIO6
		Sbecore::utinyint lineoffsetLeft; // GPIO6_IO10
		Sbecore::utinyint lineoffsetRight; // GPIO6_IO9

		std::string pathSpi;

		Sbecore::usmallint leftMin; // experimentally, full range corresponds to 16% .. 24%
		Sbecore::usmallint leftMax;

		Sbecore::usmallint rightMin;
		Sbecore::usmallint rightMax;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

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

		// IP Shrdat.vars.cust --- IBEGIN
		gpiohandle_request reqGpio;

		int fdSpi;
		spi_ioc_transfer xferSpi;

		static constexpr int lenSpi = 2;

		unsigned char rxbufSpi[lenSpi];
		unsigned char txbufSpi[lenSpi];
		// IP Shrdat.vars.cust --- IEND

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

	JobWzskSrcArty* srcarty;
	JobWzskSrcClnxevb* srcclnxevb;
	JobWzskSrcIcicle* srcicicle;
	JobWzskSrcMcvevp* srcmcvevp;
	JobWzskSrcUvbdvk* srcuvbdvk;
	JobWzskSrcUzediocc* srcuzediocc;

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
	bool handleTest(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
