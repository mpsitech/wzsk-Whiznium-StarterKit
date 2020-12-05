/**
	* \file PnlWzskLlvCamera.h
	* job handler for job PnlWzskLlvCamera (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKLLVCAMERA_H
#define PNLWZSKLLVCAMERA_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskActExposure.h"
#include "JobWzskAcqPreview.h"

#define VecVWzskLlvCameraDo PnlWzskLlvCamera::VecVDo

#define ContIacWzskLlvCamera PnlWzskLlvCamera::ContIac
#define ContInfWzskLlvCamera PnlWzskLlvCamera::ContInf
#define StatShrWzskLlvCamera PnlWzskLlvCamera::StatShr
#define TagWzskLlvCamera PnlWzskLlvCamera::Tag

#define DpchAppWzskLlvCameraData PnlWzskLlvCamera::DpchAppData
#define DpchAppWzskLlvCameraDo PnlWzskLlvCamera::DpchAppDo
#define DpchEngWzskLlvCameraData PnlWzskLlvCamera::DpchEngData
#define DpchEngWzskLlvCameraLive PnlWzskLlvCamera::DpchEngLive

/**
	* PnlWzskLlvCamera
	*/
class PnlWzskLlvCamera : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskLlvCameraDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTPLAYCLICK = 4;
		static const Sbecore::uint BUTSTOPCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLlvCamera)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPMDE = 1;
		static const Sbecore::uint CHKAEX = 2;
		static const Sbecore::uint SLDEXT = 3;
		static const Sbecore::uint SLDFCS = 4;

	public:
		ContIac(const Sbecore::uint numFPupMde = 1, const bool ChkAex = false, const double SldExt = 0.0, const double SldFcs = 0.0);

	public:
		Sbecore::uint numFPupMde;
		bool ChkAex;
		double SldExt;
		double SldFcs;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLlvCamera)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;

	public:
		ContInf(const bool ButClaimOn = false);

	public:
		bool ButClaimOn;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWzskLlvCamera)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint BUTPLAYACTIVE = 3;
		static const Sbecore::uint BUTSTOPACTIVE = 4;
		static const Sbecore::uint CHKAEXACTIVE = 5;
		static const Sbecore::uint SLDEXTAVAIL = 6;
		static const Sbecore::uint SLDEXTACTIVE = 7;
		static const Sbecore::uint SLDEXTMIN = 8;
		static const Sbecore::uint SLDEXTMAX = 9;
		static const Sbecore::uint SLDEXTRAST = 10;
		static const Sbecore::uint SLDFCSACTIVE = 11;
		static const Sbecore::uint SLDFCSMIN = 12;
		static const Sbecore::uint SLDFCSMAX = 13;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool ButPlayActive = true, const bool ButStopActive = true, const bool ChkAexActive = true, const bool SldExtAvail = true, const bool SldExtActive = true, const double SldExtMin = 0.001, const double SldExtMax = 100.0, const double SldExtRast = 1.77828, const bool SldFcsActive = true, const double SldFcsMin = 0.0, const double SldFcsMax = 1.0);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool ButPlayActive;
		bool ButStopActive;
		bool ChkAexActive;
		bool SldExtAvail;
		bool SldExtActive;
		double SldExtMin;
		double SldExtMax;
		double SldExtRast;
		bool SldFcsActive;
		double SldFcsMin;
		double SldFcsMax;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskLlvCamera)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskLlvCameraData)
		*/
	class DpchAppData : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvCameraDo)
		*/
	class DpchAppDo : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskLlvCameraData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPMDE = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupMde = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupMde;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngLive (full: DpchEngWzskLlvCameraLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint GRAY = 2;
		static const Sbecore::uint RED = 3;
		static const Sbecore::uint GREEN = 4;
		static const Sbecore::uint BLUE = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngLive(const Sbecore::ubigint jref = 0, const std::vector<Sbecore::utinyint>& gray = {}, const std::vector<Sbecore::utinyint>& red = {}, const std::vector<Sbecore::utinyint>& green = {}, const std::vector<Sbecore::utinyint>& blue = {}, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::vector<Sbecore::utinyint> gray;

		std::vector<Sbecore::utinyint> red;
		std::vector<Sbecore::utinyint> green;
		std::vector<Sbecore::utinyint> blue;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButClaimActive(DbsWzsk* dbswzsk);
	bool evalButPlayActive(DbsWzsk* dbswzsk);
	bool evalButStopActive(DbsWzsk* dbswzsk);
	bool evalChkAexActive(DbsWzsk* dbswzsk);
	bool evalSldExtAvail(DbsWzsk* dbswzsk);
	bool evalSldExtActive(DbsWzsk* dbswzsk);
	bool evalSldFcsActive(DbsWzsk* dbswzsk);

public:
	PnlWzskLlvCamera(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskLlvCamera();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupMde;

	JobWzskActExposure* actexposure;
	JobWzskAcqPreview* acqpreview;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButClaimClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPlayClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButStopClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskShrdatChgFromActexposure(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskResultNewFromAcqpreview(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskClaimChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);

};

#endif

