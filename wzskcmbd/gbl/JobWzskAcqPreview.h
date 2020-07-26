/**
	* \file JobWzskAcqPreview.h
	* job handler for job JobWzskAcqPreview (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef JOBWZSKACQPREVIEW_H
#define JOBWZSKACQPREVIEW_H

// IP include.spec --- INSERT

#include <arm_neon.h> // IP include.cust --- ILINE

#include "JobWzskSrcV4l2.h"
#include "JobWzskAcqFpgapvw.h"

#define VecVJobWzskAcqPreviewSge JobWzskAcqPreview::VecVSge
#define VecVJobWzskAcqPreviewVar JobWzskAcqPreview::VecVVar

#define ShrdatJobWzskAcqPreview JobWzskAcqPreview::Shrdat

/**
	* JobWzskAcqPreview
	*/
class JobWzskAcqPreview : public CsjobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskAcqPreviewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint READY = 2;
		static const Sbecore::uint PRCIDLE = 3;
		static const Sbecore::uint PROCESS = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobWzskAcqPreviewVar)
		*/
	class VecVVar {

	public:
		static const Sbecore::uint GRAY = 1;
		static const Sbecore::uint REDGREENBLUE = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Shrdat (full: ShrdatJobWzskAcqPreview)
		*/
	class Shrdat : public ShrdatWzsk {

	public:
		// IP Shrdat.subs --- IBEGIN
		// using a result is not absolutely required in this case; only straight copies to UI so far
		/**
			* ResultitemGray
			*/
		class ResultitemGray : public Sbecore::Resultitem {

		public:
			ResultitemGray();
			~ResultitemGray();

		public:
			uint8_t* gr8; // 256 x 192 (4x4 bin)
			uint16_t* gr16;
			size_t sizeBuf;

			double tIn;
			double tOut;
		};

		/**
			* ResultitemRgb
			*/
		class ResultitemRgb : public Sbecore::Resultitem {

		public:
			ResultitemRgb();
			~ResultitemRgb();

		public:
			uint8_t* r8; // 160 x 120 (8x8 bin)
			uint8_t* g8;
			uint8_t* b8;

			uint16_t* r16;
			uint16_t* g16;
			uint16_t* b16;

			size_t sizeBuf;

			double tIn;
			double tOut;
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:
		std::vector<Sbecore::utinyint> gray;

		std::vector<Sbecore::utinyint> red;
		std::vector<Sbecore::utinyint> green;
		std::vector<Sbecore::utinyint> blue;

		// IP Shrdat.vars.cust --- IBEGIN
		bool bingray;
		bool binreddom;
		bool binrgb;
		bool rawgray;
		bool rawrgb;

		Sbecore::Result resultBingray;
		Sbecore::Result resultBinreddom;
		Sbecore::Result resultBinrgb;

		Sbecore::Result resultRawgray;
		Sbecore::Result resultRawrgb;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	JobWzskAcqPreview(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskAcqPreview();

public:
	static Shrdat shrdat;

	JobWzskSrcV4l2* srcv4l2;
	JobWzskAcqFpgapvw* acqfpgapvw;

	// IP vars.spec --- INSERT

	// IP vars.cust --- IBEGIN
	Sbecore::uint ixRiSrc;

	Sbecore::uint ixRiBingray;
	Sbecore::uint ixRiBinreddom;
	Sbecore::uint ixRiBinrgb;
	Sbecore::uint ixRiRawgray;
	Sbecore::uint ixRiRawrgb;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	/**
		* Claim (full: ClaimJobWzskAcqPreview)
		*/
	class Claim : public Sbecore::Claim {

	public:
		Claim(const bool retractable = true, const bool run = false, const Sbecore::uint ixWzskVPvwmode = VecWzskVPvwmode::BINGRAY);

	public:
		Sbecore::uint ixWzskVPvwmode;
	};

	void binRgb(uint16_t* r16, uint16_t* g16, uint16_t* b16, uint16_t* pvwr16, uint16_t* pvwg16, uint16_t* pvwb16);
	void binRgb_component(uint16_t* src, uint16_t* dest);

	void binGrrd(uint16_t* grrd16, uint16_t* pvwgrrd16);

	void uint16ToUint8(uint16_t* in16, uint8_t* out8, size_t sizeBuf);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleTest(DbsWzsk* dbswzsk);

	void handleTimerInSgePrcidle(DbsWzsk* dbswzsk, const std::string& sref);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskResultNewFromSrcv4l2InSgeReady(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskResultNewFromAcqfpgapvwInSgeReady(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeReady(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeReady(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgePrcidle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgePrcidle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeProcess(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeProcess(DbsWzsk* dbswzsk);

public:
	bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif


