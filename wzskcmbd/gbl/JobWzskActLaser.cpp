/**
	* \file JobWzskActLaser.cpp
	* job handler for job JobWzskActLaser (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskActLaser.h"

#include "JobWzskActLaser_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskActLaser::Shrdat
 ******************************************************************************/

JobWzskActLaser::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskActLaser", "Shrdat")
		{
};

void JobWzskActLaser::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	left = 0.0;
	right = 0.0;

	int fd;

	int res;

	string path;

	gpiohandle_data data;

	if (!xchg->stgwzskglobal.fpgaNotV4l2gpio) {
		// configure GPIO
		path = stg.pathGpio;

		fd = open(path.c_str(), 0);
		if (fd < 0) throw WzskException(WzskException::GPIO, {{"msg","error opening device at " + path}});

		memset(&reqGpio, 0, sizeof(reqGpio));

		reqGpio.lines = 2;
		reqGpio.lineoffsets[0] = stg.lineoffsetLeft; // skixora v1.1: GPIO6_IO10 ; old system: (6-1)*32 + 10 = 170
		reqGpio.lineoffsets[1] = stg.lineoffsetRight; // skixora v1.1: GPIO6_IO9 ; old system: (6-1)*32 + 9 = 169
		reqGpio.default_values[0] = 1;
		reqGpio.default_values[1] = 1;
		reqGpio.flags = GPIOHANDLE_REQUEST_OUTPUT;
		strcpy(reqGpio.consumer_label, "Wzsk");

		res = ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &reqGpio);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error getting lines handle"}});

		data.values[0] = 1;
		data.values[1] = 1;

		res = ioctl(reqGpio.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error setting initial lines state"}});

	/*
		// debug
		gpiochip_info info;
		gpioline_info linfo;
		
		res = ioctl(fd, GPIO_GET_CHIPINFO_IOCTL, &info);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error getting device info"}});
		
		cout << "name: " << info.name << ", label: " << info.label << ", lines: " << info.lines << endl;

		for (int i = 0; i < info.lines; i++) {
			memset(&linfo, 0, sizeof(linfo));

			linfo.line_offset = i;

			res = ioctl(fd, GPIO_GET_CHIPINFO_IOCTL, &info);
			if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error getting line info for line " + to_string(i)}});

			cout << "\t" << i << ": ";
			if (linfo.name) cout << linfo.name << ", ";
			if (linfo.consumer) cout << linfo.consumer << ", ";
			cout << linfo.flags << endl;
		};
	*/

		close(fd);

		// open and configure spidev
		const unsigned char mode = SPI_MODE_1; // CPOL=0, CPHA=1
		const unsigned char bits = 8;
		const unsigned int bps = 8000000;

		path = stg.pathSpi;

		fdSpi = open(path.c_str(), O_RDWR);
		if (fdSpi < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error opening device at " + path}});

		res = ioctl(fdSpi, SPI_IOC_WR_MODE, &mode);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting device mode"}});

		res = ioctl(fdSpi, SPI_IOC_RD_MODE, &mode);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting device mode"}});

		res = ioctl(fdSpi, SPI_IOC_WR_BITS_PER_WORD, &bits);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting bits per word"}});

		res = ioctl(fdSpi, SPI_IOC_RD_BITS_PER_WORD, &bits);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting bits per word"}});

		res = ioctl(fdSpi, SPI_IOC_WR_MAX_SPEED_HZ, &bps);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting speed"}});

		res = ioctl(fdSpi, SPI_IOC_RD_MAX_SPEED_HZ, &bps);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting speed"}});

		memset(&xferSpi, 0, sizeof(xferSpi));

		xferSpi.len = lenSpi;
		xferSpi.rx_buf = (unsigned long) rxbufSpi;
		xferSpi.tx_buf = (unsigned long) txbufSpi;
		xferSpi.bits_per_word = bits;
		xferSpi.speed_hz = bps;
		xferSpi.delay_usecs = 0;
		xferSpi.cs_change = 0;
		xferSpi.pad = 0;
		
		// DAC initialization (L&R at the same time)
		data.values[0] = 0;
		data.values[1] = 0;

		res = ioctl(reqGpio.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error setting lines state"}});

		txbufSpi[0] = 0xF0;
		txbufSpi[1] = 0x00;

		res = ioctl(fdSpi, SPI_IOC_MESSAGE(1), &xferSpi);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting DAC output configuration"}});

		data.values[0] = 1;
		data.values[1] = 1;
		
		res = ioctl(reqGpio.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error setting lines state"}});

		// wait for 8µs
		timespec deltat;
		deltat.tv_sec = 0;
		deltat.tv_nsec = 8000;

		nanosleep(&deltat, NULL);

	} else {
		reqGpio.fd = 0;
		fdSpi = 0;
	};
	// IP Shrdat.init --- IEND
};

void JobWzskActLaser::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	// close GPIO
	if (reqGpio.fd) close(reqGpio.fd);

	// close spidev
	if (fdSpi) close(fdSpi);
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskActLaser
 ******************************************************************************/

JobWzskActLaser::JobWzskActLaser(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACTLASER, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcfpga = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- IBEGIN
	if (srvNotCli) if (xchg->stgwzskglobal.fpgaNotV4l2gpio) srcfpga = new JobWzskSrcFpga(xchg, dbswzsk, jref, ixWzskVLocale);
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskActLaser::~JobWzskActLaser() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
usmallint JobWzskActLaser::pToAbs(
			const bool rightNotLeft
			, const float p
		) {
	if (p == 0.0) return 0;

	if (!rightNotLeft) return(stg.leftMin + lround(p * ((float) (stg.leftMax - stg.leftMin))));
	else return(stg.rightMin + lround(p * ((float) (stg.rightMax - stg.rightMin))));
};

// IP cust --- IEND

// IP spec --- INSERT

bool JobWzskActLaser::setLeft(
			DbsWzsk* dbswzsk
			, const float left
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActLaser*) srv)->setLeft(dbswzsk, left);

		} else retval = false;

		return retval;
	};

	lockAccess("setLeft");

	// IP setLeft --- IBEGIN
	int res;

	gpiohandle_data data;

	usmallint i = pToAbs(false, left);

	if (!srcfpga) {
		retval = false;

		data.values[0] = 0;
		data.values[1] = 1;

		res = ioctl(shrdat.reqGpio.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error setting lines state"}});

		shrdat.txbufSpi[0] = 0x0F & (i >> 6);
		shrdat.txbufSpi[1] = 0xFC & (i << 2);

		res = ioctl(shrdat.fdSpi, SPI_IOC_MESSAGE(1), &shrdat.xferSpi);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting left laser intensity"}});

		data.values[0] = 1;
		data.values[1] = 1;

		res = ioctl(shrdat.reqGpio.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error setting lines state"}});

		retval = true;

	} else retval = srcfpga->laser_set(i, pToAbs(true, shrdat.right));

	if (retval) {
		shrdat.wlockAccess(jref, "setLeft");

		shrdat.left = left;

		shrdat.wunlockAccess(jref, "setLeft");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "leftRight");
	};
	// IP setLeft --- IEND

	unlockAccess("setLeft");

	return retval;
};

bool JobWzskActLaser::setRight(
			DbsWzsk* dbswzsk
			, const float right
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskActLaser*) srv)->setRight(dbswzsk, right);

		} else retval = false;

		return retval;
	};

	lockAccess("setRight");

	// IP setRight --- IBEGIN
	int res;

	gpiohandle_data data;

	usmallint i = pToAbs(true, right);

	if (!srcfpga) {
		retval = false;

		data.values[0] = 1;
		data.values[1] = 0;

		res = ioctl(shrdat.reqGpio.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error setting lines state"}});

		shrdat.txbufSpi[0] = 0x0F & (i >> 6);
		shrdat.txbufSpi[1] = 0xFC & (i << 2);

		res = ioctl(shrdat.fdSpi, SPI_IOC_MESSAGE(1), &shrdat.xferSpi);
		if (res < 0) throw WzskException(WzskException::SPIDEV, {{"msg","error setting right laser intensity"}});

		data.values[0] = 1;
		data.values[1] = 1;

		res = ioctl(shrdat.reqGpio.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);
		if (res < 0) throw WzskException(WzskException::GPIO, {{"msg","error setting lines state"}});

		retval = true;

	} else retval = srcfpga->laser_set(pToAbs(false, shrdat.left), i);

	if (retval) {
		shrdat.wlockAccess(jref, "setRight");

		shrdat.right = right;

		shrdat.wunlockAccess(jref, "setRight");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "leftRight");
	};
	// IP setRight --- IEND

	unlockAccess("setRight");

	return retval;
};

void JobWzskActLaser::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\ttest" << endl;
		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswzsk);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETLEFT) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setLeft(dbswzsk, *((const float*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::SETRIGHT) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setRight(dbswzsk, *((const float*) (req->method->parsInv[0])));
		};
	};
};

bool JobWzskActLaser::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

bool JobWzskActLaser::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if srcfpga "laser" claim can be fulfilled

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;

	bool available;
	bool reattributed;

	bool laserTakenNotAvailable, laserFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
		};
	};

	if (srcfpga) {
		// add or remove "laser" claim with srcfpga
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcfpga);
		else xchg->addCsjobClaim(dbswzsk, srcfpga, new JobWzskSrcFpga::Claim(false, false, false, false, true, false));

		xchg->getCsjobClaim(srcfpga, laserTakenNotAvailable, laserFulfilled);

	} else laserFulfilled = true;

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && laserFulfilled;

			if (!available) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim
				if (it->first != jrefFulfilled) {
					if (jrefFulfilled != 0) claims[jrefFulfilled]->fulfilled = false;

					claim->fulfilled = true;
					retractable = claim->retractable;
					reattributed = true;
				};

				if (reattributed) break;
			};
		};

		if (!available) break;
		if (reattributed) break;
	};

	// update taken status
	available = retractable;

	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		claim->takenNotAvailable = !available;
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};



