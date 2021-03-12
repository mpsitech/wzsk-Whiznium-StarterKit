/**
	* \file JobWzskIexIni.h
	* job handler for job JobWzskIexIni (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZSKIEXINI_H
#define JOBWZSKIEXINI_H

#include "IexWzskIni.h"

// IP include.cust --- INSERT

#define VecVJobWzskIexIniSge JobWzskIexIni::VecVSge

/**
	* JobWzskIexIni
	*/
class JobWzskIexIni : public JobWzsk {

public:
	/**
		* VecVSge (full: VecVJobWzskIexIniSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PARSE = 2;
		static const Sbecore::uint PRSERR = 3;
		static const Sbecore::uint PRSDONE = 4;
		static const Sbecore::uint IMPORT = 5;
		static const Sbecore::uint IMPERR = 6;
		static const Sbecore::uint REVERSE = 7;
		static const Sbecore::uint COLLECT = 8;
		static const Sbecore::uint CLTDONE = 9;
		static const Sbecore::uint EXPORT = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

public:
	JobWzskIexIni(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~JobWzskIexIni();

public:

	std::string fullpath;
	bool xmlNotTxt;
	std::string rectpath;

	Sbecore::uint lineno;
	Sbecore::uint impcnt;

	std::map<Sbecore::uint,Sbecore::uint> icsWzskVIop;

	bool shorttags;

	IexWzskIni::ImeIAVControlPar imeiavcontrolpar;
	IexWzskIni::ImeIAVKeylistKey imeiavkeylistkey;
	IexWzskIni::ImeIAVValuelistVal imeiavvaluelistval;
	IexWzskIni::ImeIMFile imeimfile;
	IexWzskIni::ImeIMUsergroup imeimusergroup;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void reset(DbsWzsk* dbswzsk);

	void parseFromFile(DbsWzsk* dbswzsk, const std::string& _fullpath, const bool _xmlNotTxt, const std::string& _rectpath = "");
	void import(DbsWzsk* dbswzsk);
	void reverse(DbsWzsk* dbswzsk);
	void collect(DbsWzsk* dbswzsk, const std::map<Sbecore::uint,Sbecore::uint>& _icsWzskVIop = IexWzskIni::icsWzskVIopInsAll());
	void exportToFile(DbsWzsk* dbswzsk, const std::string& _fullpath, const bool _xmlNotTxt, const bool _shorttags = true);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeParse(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeParse(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgePrserr(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgePrserr(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgePrsdone(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgePrsdone(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeImport(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeImport(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeImperr(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeImperr(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeReverse(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeReverse(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeCollect(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeCollect(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeCltdone(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeCltdone(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeExport(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeExport(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeDone(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeDone(DbsWzsk* dbswzsk);

};

#endif
