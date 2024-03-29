/**
	* \file ApiWzsk_blks.h
	* Wzsk API library global data blocks (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef APIWZSK_BLKS_H
#define APIWZSK_BLKS_H

#include "VecWzskVExpstate.h"
#include "VecWzskVPvwmode.h"
#include "VecWzskVReqitmode.h"
#include "VecWzskVSqrgrp.h"
#include "VecWzskVTarget.h"

#include "VecWzskVDpch.h"

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
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
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
	* DpchAppWzsk
	*/
class DpchAppWzsk : public DpchWzsk {

public:
	static const Sbecore::uint SCRJREF = 1;

public:
	DpchAppWzsk(const Sbecore::uint ixWzskVDpch = 0, const std::string& scrJref = "");
	virtual ~DpchAppWzsk();

public:
	std::string scrJref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppWzskAlert
	*/
class DpchAppWzskAlert : public DpchAppWzsk {

public:
	static const Sbecore::uint SCRJREF = 1;
	static const Sbecore::uint NUMFMCB = 2;
	static const Sbecore::uint ALL = 3;

public:
	DpchAppWzskAlert(const std::string& scrJref = "", const Sbecore::uint numFMcb = 0, const std::set<Sbecore::uint>& mask = {NONE});

public:
	Sbecore::uint numFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppWzskInit
	*/
class DpchAppWzskInit : public DpchAppWzsk {

public:
	DpchAppWzskInit(const std::string& scrJref = "");
};

/**
	* DpchAppWzskResume
	*/
class DpchAppWzskResume : public DpchAppWzsk {

public:
	DpchAppWzskResume(const std::string& scrJref = "");
};

/**
	* DpchEngWzsk
	*/
class DpchEngWzsk : public DpchWzsk {

public:
	static const Sbecore::uint SCRJREF = 1;

public:
	DpchEngWzsk(const Sbecore::uint ixWzskVDpch = 0);
	virtual ~DpchEngWzsk();

public:
	std::string scrJref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWzskAck
	*/
class DpchEngWzskAck : public DpchEngWzsk {

public:
	DpchEngWzskAck();
};

/**
	* DpchEngWzskAlert
	*/
class DpchEngWzskAlert : public DpchEngWzsk {

public:
	static const Sbecore::uint SCRJREF = 1;
	static const Sbecore::uint CONTINF = 2;
	static const Sbecore::uint FEEDFMCB = 3;

public:
	DpchEngWzskAlert();

public:
	ContInfWzskAlert continf;
	Sbecore::Feed feedFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWzskConfirm
	*/
class DpchEngWzskConfirm : public DpchEngWzsk {

public:
	static const Sbecore::uint ACCEPTED = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint SREF = 3;

public:
	DpchEngWzskConfirm();

public:
	bool accepted;
	std::string sref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWzskSuspend
	*/
class DpchEngWzskSuspend : public DpchEngWzsk {

public:
	DpchEngWzskSuspend();
};

#endif
