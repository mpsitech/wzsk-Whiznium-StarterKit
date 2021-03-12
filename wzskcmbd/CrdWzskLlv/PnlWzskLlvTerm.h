/**
	* \file PnlWzskLlvTerm.h
	* job handler for job PnlWzskLlvTerm (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKLLVTERM_H
#define PNLWZSKLLVTERM_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcFpga.h"

#define VecVWzskLlvTermDo PnlWzskLlvTerm::VecVDo

#define ContIacWzskLlvTerm PnlWzskLlvTerm::ContIac
#define ContInfWzskLlvTerm PnlWzskLlvTerm::ContInf
#define StatShrWzskLlvTerm PnlWzskLlvTerm::StatShr
#define TagWzskLlvTerm PnlWzskLlvTerm::Tag

#define DpchAppWzskLlvTermData PnlWzskLlvTerm::DpchAppData
#define DpchAppWzskLlvTermDo PnlWzskLlvTerm::DpchAppDo
#define DpchEngWzskLlvTermData PnlWzskLlvTerm::DpchEngData

/**
	* PnlWzskLlvTerm
	*/
class PnlWzskLlvTerm : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskLlvTermDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTAPDCLICK = 4;
		static const Sbecore::uint BUTSMTCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLlvTerm)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPCMD = 1;
		static const Sbecore::uint TXFCSQ = 2;

	public:
		ContIac(const Sbecore::uint numFPupCmd = 1, const std::string& TxfCsq = "");

	public:
		Sbecore::uint numFPupCmd;
		std::string TxfCsq;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLlvTerm)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTCST = 2;
		static const Sbecore::uint TXTDATLOG = 3;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtCst = "", const std::string& TxtDatLog = "");

	public:
		bool ButClaimOn;
		std::string TxtCst;
		std::string TxtDatLog;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWzskLlvTerm)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint BUTSMTACTIVE = 3;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool ButSmtActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool ButSmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskLlvTerm)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskLlvTermData)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvTermDo)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskLlvTermData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPCMD = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupCmd = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupCmd;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButClaimActive(DbsWzsk* dbswzsk);
	bool evalButSmtActive(DbsWzsk* dbswzsk);

public:
	PnlWzskLlvTerm(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskLlvTerm();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupCmd;

	JobWzskSrcFpga* srcfpga;

	// IP vars.cust --- IBEGIN
	std::vector<std::string> hist;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void parseCmd(UntWskd& unt, std::string s, Dbecore::Cmd*& cmd);
	Sbecore::uint getCmdix(UntWskd& unt, const std::string& cmdsref);
	std::string getCmdsref(UntWskd& unt, const Sbecore::uint cmdix);
	// IP cust --- IEND

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
	void handleDpchAppDoButApdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButSmtClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskClaimChgFromSrcfpga(DbsWzsk* dbswzsk);

};

#endif
