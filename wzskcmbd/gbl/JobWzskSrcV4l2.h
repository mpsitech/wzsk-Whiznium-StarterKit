/**
	* \file JobWzskSrcV4l2.h
	* job handler for job JobWzskSrcV4l2 (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKSRCV4L2_H
#define JOBWZSKSRCV4L2_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <sys/mman.h>
#undef MAP_TYPE
#include <sys/stat.h>
#include <sys/types.h>
//#include <imx/linux/mxc_v4l2.h>
#include <arm_neon.h>
// IP include.cust --- IEND

#define VecVJobWzskSrcV4l2Sge JobWzskSrcV4l2::VecVSge

#define StgJobWzskSrcV4l2 JobWzskSrcV4l2::Stg

#define ShrdatJobWzskSrcV4l2 JobWzskSrcV4l2::Shrdat

/**
	* JobWzskSrcV4l2
	*/
class JobWzskSrcV4l2 : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskSrcV4l2Sge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint READY = 2;
		static const Sbecore::uint CNVIDLE = 3;
		static const Sbecore::uint CONVERT = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Stg (full: StgJobWzskSrcV4l2)
		*/
	class Stg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint PATH = 1;
		static const Sbecore::uint YUV422NOTYUV420 = 2;

	public:
		Stg(const std::string& path = "/dev/video1", const bool YUV422NotYUV420 = false);

	public:
		std::string path;
		bool YUV422NotYUV420;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWzskSrcV4l2)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		/**
			* ResultitemAcq (full: ResultitemJobWzskSrcV4l2Acq)
			*/
		class ResultitemAcq : public Sbecore::Resultitem {

		public:
			ResultitemAcq(XchgWzsk* xchg, int fd, const Sbecore::uint ix);
			~ResultitemAcq();

		public:
			void* buf; // v4l2 mmap
			size_t sizeBuf;

			double t;

			uint16_t* r16;
			uint16_t* g16;
			uint16_t* b16;
			size_t rgb16len;

			uint16_t* gr16;
			uint16_t* rd16;
			size_t grrd16len;

		public:
			void updateT(int fd, const Sbecore::uint ix);
		};

		/**
			* ResultAcq (full: ResultJobWzskSrcV4l2Acq)
			*/
		class ResultAcq : public Sbecore::Result {

		public:
			ResultAcq();
			~ResultAcq();

		public:
			void queue(const Sbecore::uint ix);
			bool dequeue(Sbecore::uint& ix);

			void requeueAllV4l2();

		public:
			int fd;
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		int fd;

		pthread_t acq;
		Sbecore::Mutex mAcq;

		bool cancelAcq;

		ResultAcq resultAcq;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskSrcV4l2(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskSrcV4l2();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP vars.spec --- INSERT

	// IP vars.cust --- IBEGIN
	unsigned int ixRi;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	static void* runAcq(void* arg);
	static void cleanupAcq(void* arg);

	bool setCtrl(const int id, const std::string& sref, const bool boolvalNotIntval, const int intval, const bool boolval);

	void convertYUV420toRGBGrrdInt16(unsigned char* src, uint16_t* r16, uint16_t* g16, uint16_t* b16, uint16_t* gr16, uint16_t* rd16);
	void convertYUV420toRGBGrrdNEON(unsigned char* src, uint16_t* r16, uint16_t* g16, uint16_t* b16, uint16_t* gr16, uint16_t* rd16);

	void convertYUV422toRGBGrrdInt8(unsigned char* src, uint8_t* r8, uint8_t* g8, uint8_t* b8, uint8_t* gr8, uint8_t* rd8);
	void convertYUV422toRGBGrrdInt16(unsigned char* src, uint16_t* r16, uint16_t* g16, uint16_t* b16, uint16_t* gr16, uint16_t* rd16);

	bool setExposure(const bool autoNotManual, const float _Texp);
	bool setFocus(const float _focus);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

	void handleTimerInSgeCnvidle(DbsWzsk* dbswzsk, const std::string& sref);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskCallbackFromSelf(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeReady(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeReady(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeCnvidle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeCnvidle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeConvert(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeConvert(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif
