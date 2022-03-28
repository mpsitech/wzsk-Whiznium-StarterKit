/**
	* \file Wzsk.h
	* Wzsk global functionality (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSK_H
#define WZSK_H

#define WZSK_VERSION "1.0.13"
#define WZSK_VERSION_MAJOR 1
#define WZSK_VERSION_MINOR 0
#define WZSK_VERSION_SUB 13

#include "DevWskd.h" // IP include.cust --- ILINE

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "VecWzskVCall.h"
#include "VecWzskVDpch.h"
#include "VecWzskVError.h"
#include "VecWzskVExpstate.h"
#include "VecWzskVIop.h"
#include "VecWzskVJob.h"
#include "VecWzskVMimetype.h"
#include "VecWzskVOpengtype.h"
#include "VecWzskVOppack.h"
#include "VecWzskVPvwmode.h"
#include "VecWzskVQrystate.h"
#include "VecWzskVReqitmode.h"
#include "VecWzskVSqrgrp.h"
#include "VecWzskVStub.h"
#include "VecWzskVTag.h"
#include "VecWzskVTarget.h"

#include <DbsWzsk.h>

#include <sbecore/Engtypes.h>
#include <sbecore/Stub.h>

/**
	* Acv
	*/
namespace Acv {
	Sbecore::ubigint addfile(DbsWzsk* dbswzsk, const std::string& acvpath, const std::string& path, const Sbecore::ubigint grp, const Sbecore::ubigint own, const Sbecore::uint refIxVTbl, const Sbecore::ubigint refUref, const std::string& osrefKContent, const std::string& Filename, const std::string& srefKMimetype, const std::string& Comment);
	void alterfile(DbsWzsk* dbswzsk, const std::string& acvpath, const std::string& path, const Sbecore::ubigint ref);
	std::string getfile(DbsWzsk* dbswzsk, const Sbecore::ubigint refWzskMFile);
};

/**
	* Lop
	*/
namespace Lop {
	void apply(const Sbecore::uint ixWzskVLop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);

	void insert(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
};

/**
	* Oolop
	*/
namespace Oolop {
	void apply(const Sbecore::uint ixWzskVOolop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);

	void insertBefore(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void insertAfter(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void toBefore(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void toAfter(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void swap(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
};

/**
	* Tmp
	*/
namespace Tmp {
	std::string newfile(const std::string& tmppath, const std::string& ext);
	std::string newfolder(const std::string& tmppath);
	std::string random();
};

// IP cust --- INSERT

/**
	* Wzsk
	*/
namespace Wzsk {
	// IP gbl --- IBEGIN
	void parseCmd(UntWskd& unt, std::string s, Dbecore::Cmd*& cmd);
	Sbecore::uint getCmdix(UntWskd& unt, const std::string& cmdsref);
	std::string getCmdsref(UntWskd& unt, const Sbecore::uint cmdix);

	void getFlgWh(unsigned int& w, unsigned int& h);

	void bitmapToXy(unsigned char* src, const bool src16Not8, const unsigned int width, const unsigned int height, std::vector<int>& xs, std::vector<int>& ys, const unsigned int cntPerRowMax, const bool roi, const std::vector<int>& xsRoi, const std::vector<int>& ysRoi, const bool rot180, const bool append);

	void getPvwWh(const Sbecore::uint ixWzskVTarget, const Sbecore::uint ixWzskVPvwmode, unsigned int& w, unsigned int& h);
	bool getPvwRawNotBin(const Sbecore::uint ixWzskVPvwmode);
	bool getPvwGrayNotRgb(const Sbecore::uint ixWzskVPvwmode);
	uint getIxWzskVPvwmode(const bool rawNotBin, const bool grayNotRgb);

	double getNow();
	// IP gbl --- IEND
};

/**
	* OpengWzsk
	*/
namespace OpengWzsk {
	void getIcsWzskVOppackByIxWzskVOpengtype(const Sbecore::uint ixWzskVOpengtype, std::vector<Sbecore::uint>& icsWzskVOppack);
	void getIcsWzskVDpchByIxWzskVOppack(const Sbecore::uint ixWzskVOppack, std::set<Sbecore::uint>& icsWzskVDpch);
};

/**
	* StubWzsk
	*/
namespace StubWzsk {
	std::string getStub(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVStub, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);

	std::string getStubFilStd(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubGroup(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubObjStd(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOgrHsref(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOgrStd(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOwner(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrsStd(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesMenu(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesStd(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubShtStd(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsgStd(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsrStd(DbsWzsk* dbswzsk, const Sbecore::ubigint ref, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
};

/**
	* WzskException
	*/
class WzskException : public Sbecore::SbeException {

public:
	static const Sbecore::uint GPIO = 1001;
	static const Sbecore::uint PWM = 1002;
	static const Sbecore::uint SPIDEV = 1003;
	static const Sbecore::uint V4L2 = 1004;

public:
	WzskException(const Sbecore::uint ix, const std::map<std::string,std::string>& vals);

public:
	std::string getSref();
};

/**
	* ContInfWzskAlert
	*/
class ContInfWzskAlert : public Sbecore::Block {

public:
	static const Sbecore::uint TXTCPT = 1;
	static const Sbecore::uint TXTMSG1 = 2;
	static const Sbecore::uint TXTMSG2 = 3;
	static const Sbecore::uint TXTMSG3 = 4;
	static const Sbecore::uint TXTMSG4 = 5;
	static const Sbecore::uint TXTMSG5 = 6;
	static const Sbecore::uint TXTMSG6 = 7;
	static const Sbecore::uint TXTMSG7 = 8;
	static const Sbecore::uint TXTMSG8 = 9;
	static const Sbecore::uint TXTMSG9 = 10;
	static const Sbecore::uint TXTMSG10 = 11;
	static const Sbecore::uint TXTMSG11 = 12;
	static const Sbecore::uint TXTMSG12 = 13;

public:
	ContInfWzskAlert(const std::string& TxtCpt = "", const std::string& TxtMsg1 = "", const std::string& TxtMsg2 = "", const std::string& TxtMsg3 = "", const std::string& TxtMsg4 = "", const std::string& TxtMsg5 = "", const std::string& TxtMsg6 = "", const std::string& TxtMsg7 = "", const std::string& TxtMsg8 = "", const std::string& TxtMsg9 = "", const std::string& TxtMsg10 = "", const std::string& TxtMsg11 = "", const std::string& TxtMsg12 = "");

public:
	std::string TxtCpt;
	std::string TxtMsg1;
	std::string TxtMsg2;
	std::string TxtMsg3;
	std::string TxtMsg4;
	std::string TxtMsg5;
	std::string TxtMsg6;
	std::string TxtMsg7;
	std::string TxtMsg8;
	std::string TxtMsg9;
	std::string TxtMsg10;
	std::string TxtMsg11;
	std::string TxtMsg12;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> compare(const ContInfWzskAlert* comp);
};

/**
	* DpchWzsk
	*/
class DpchWzsk : public Sbecore::Block {

public:
	DpchWzsk(const Sbecore::uint ixWzskVDpch = 0);
	virtual ~DpchWzsk();

public:
	Sbecore::uint ixWzskVDpch;
};

/**
	* DpchInvWzsk
	*/
class DpchInvWzsk : public DpchWzsk {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint ALL = 3;

public:
	DpchInvWzsk(const Sbecore::uint ixWzskVDpch = VecWzskVDpch::DPCHINVWZSK, const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchInvWzsk();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWzsk
	*/
class DpchRetWzsk : public DpchWzsk {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;

public:
	DpchRetWzsk(const Sbecore::uint ixWzskVDpch = VecWzskVDpch::DPCHRETWZSK, const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::utinyint ixOpVOpres = Sbecore::VecOpVOpres::PROGRESS, const Sbecore::utinyint pdone = 0);
	virtual ~DpchRetWzsk();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;
	Sbecore::utinyint ixOpVOpres;
	Sbecore::utinyint pdone;

public:
	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif
