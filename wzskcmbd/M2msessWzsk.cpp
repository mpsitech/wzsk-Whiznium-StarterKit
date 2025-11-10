/**
	* \file M2msessWzsk.cpp
	* job handler for job M2msessWzsk (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "M2msessWzsk.h"

#include "M2msessWzsk_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class M2msessWzsk
 ******************************************************************************/

M2msessWzsk::M2msessWzsk(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const ubigint refWzskMUser
			, const string& ip
		) :
			JobWzsk(xchg, VecWzskVJob::M2MSESSWZSK, jrefSup)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	acqcorner = NULL;
	acqtrace = NULL;
	actlaser = NULL;
	actrotary = NULL;
	srcfpgainfo = NULL;
	srcsysinfo = NULL;

	// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	WzskMUser* usr = NULL;

	bool adm;

	ListWzskRMUserMUsergroup urus;

	uint ixWzskWAccessBase;

	// create new session with start time
	time_t rawtime;
	time(&rawtime);

	refSes = dbswzsk->tblwzskmsession->insertNewRec(NULL, refWzskMUser, (uint) rawtime, 0, ip);

	xchg->addRefPreset(VecWzskVPreset::PREWZSKSESS, jref, refSes);
	xchg->addTxtvalPreset(VecWzskVPreset::PREWZSKIP, jref, ip);

	// set locale and presetings corresponding to user
	dbswzsk->tblwzskmuser->loadRecByRef(refWzskMUser, &usr);

	ixWzskVLocale = usr->ixWzskVLocale;
	adm = (usr->ixWzskVUserlevel == VecWzskVUserlevel::ADM);

	delete usr;

	if (!adm) dbswzsk->tblwzskrmusermusergroup->loadRstByUsr(refWzskMUser, false, urus);

	// determine access rights for each feature group and feature
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD, "setRoi", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "roiX0RoiY0RoiX1RoiY1", urus, refWzskMUser, ixWzskWAccessBase);
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "shiftScoreMinScoreMax", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD, "setRoi", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR, "roiX0RoiY0RoiX1RoiY1", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setLeft", urus, refWzskMUser, ixWzskWAccessBase);
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setRight", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR, "leftRight", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "moveto", urus, refWzskMUser, ixWzskWAccessBase);
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "stop", urus, refWzskMUser, ixWzskWAccessBase);
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "turn", urus, refWzskMUser, ixWzskWAccessBase);
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "zero", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR, "angleTarget", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "hdrDRdHdrDWr", urus, refWzskMUser, ixWzskWAccessBase);
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "rndDRdRndDWr", urus, refWzskMUser, ixWzskWAccessBase);
	};
	ixWzskWAccessBase = addAccBase(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, adm, urus, refWzskMUser);
	if (!adm) {
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "loadAllLoadCore0LoadCore1LoadCore2LoadCore3", urus, refWzskMUser, ixWzskWAccessBase);
		addAcc(dbswzsk, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "temp", urus, refWzskMUser, ixWzskWAccessBase);
	};

	// create jobs according to access rights
	if ( (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "")) != accs.end()) ) {
		acqcorner = new JobWzskAcqCorner(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefAcqcorner = acqcorner->jref;
	};
	if ( (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR, "")) != accs.end()) ) {
		acqtrace = new JobWzskAcqTrace(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefAcqtrace = acqtrace->jref;
	};
	if ( (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR, "")) != accs.end()) ) {
		actlaser = new JobWzskActLaser(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefActlaser = actlaser->jref;
	};
	if ( (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR, "")) != accs.end()) ) {
		actrotary = new JobWzskActRotary(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefActrotary = actrotary->jref;
	};
	if (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "")) != accs.end()) {
		srcfpgainfo = new JobWzskSrcFpgainfo(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefSrcfpgainfo = srcfpgainfo->jref;
	};
	if (accs.find(featix_t(VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "")) != accs.end()) {
		srcsysinfo = new JobWzskSrcSysinfo(xchg, dbswzsk, jref, ixWzskVLocale);
		statshr.jrefSrcsysinfo = srcsysinfo->jref;
	};

// IP constructor.subs2 --- BEGIN
	// if (CUSTOM) acqcorner = new JobWzskAcqCorner(xchg, dbswzsk, jref, ixWzskVLocale);
	// if (CUSTOM) acqtrace = new JobWzskAcqTrace(xchg, dbswzsk, jref, ixWzskVLocale);
	// if (CUSTOM) actlaser = new JobWzskActLaser(xchg, dbswzsk, jref, ixWzskVLocale);
	// if (CUSTOM) actrotary = new JobWzskActRotary(xchg, dbswzsk, jref, ixWzskVLocale);
	// if (CUSTOM) srcfpgainfo = new JobWzskSrcFpgainfo(xchg, dbswzsk, jref, ixWzskVLocale);
	// if (CUSTOM) srcsysinfo = new JobWzskSrcSysinfo(xchg, dbswzsk, jref, ixWzskVLocale);
// IP constructor.subs2 --- END

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

M2msessWzsk::~M2msessWzsk() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void M2msessWzsk::term(
			DbsWzsk* dbswzsk
		) {
	WzskMSession* ses = NULL;

	time_t rawtime;

	// update session with stop time
	time(&rawtime);

	dbswzsk->tblwzskmsession->loadRecByRef(xchg->getRefPreset(VecWzskVPreset::PREWZSKSESS, jref), &ses);
	ses->stop = rawtime;
	dbswzsk->tblwzskmsession->updateRec(ses);

	delete ses;
};

uint M2msessWzsk::addAccBase(
			DbsWzsk* dbswzsk
			, const uint ixWzskVFeatgroup
			, const bool adm
			, ListWzskRMUserMUsergroup& urus
			, const ubigint refWzskMUser
		) {
	uint ixWzskWAccess = 0;

	getIxAcc(dbswzsk, ixWzskVFeatgroup, "", adm, urus, refWzskMUser, ixWzskWAccess);
	if (ixWzskWAccess != 0) accs.insert(pair<featix_t,uint>(featix_t(ixWzskVFeatgroup, ""), ixWzskWAccess));

	return ixWzskWAccess;
};

void M2msessWzsk::addAcc(
			DbsWzsk* dbswzsk
			, const uint ixWzskVFeatgroup
			, const string& srefIxVFeature
			, ListWzskRMUserMUsergroup& urus
			, const ubigint refWzskMUser
			, const uint ixWzskWAccessBase
		) {
	uint ixWzskWAccess = ixWzskWAccessBase;

	getIxAcc(dbswzsk, ixWzskVFeatgroup, srefIxVFeature, false, urus, refWzskMUser, ixWzskWAccess);
	if (ixWzskWAccess != ixWzskWAccessBase) accs.insert(pair<featix_t,uint>(featix_t(ixWzskVFeatgroup, srefIxVFeature), ixWzskWAccess));
};

void M2msessWzsk::getIxAcc(
			DbsWzsk* dbswzsk
			, const uint ixWzskVFeatgroup
			, const string& srefIxVFeature
			, const bool adm
			, ListWzskRMUserMUsergroup& urus
			, const ubigint refWzskMUser
			, uint& ixWzskWAccess
		) {
	WzskRMUserMUsergroup* uru = NULL;
	WzskAMUsergroupAccess* usgAacc = NULL;
	WzskAMUserAccess* usrAacc = NULL;

	uint ixAcc = 0;

	bool first = true;

	if (adm) {
		ixWzskWAccess = VecWzskWAccess::EDIT + VecWzskWAccess::EXEC + VecWzskWAccess::VIEW;
		return;
	};

	// check for access rights override by any of the applicable user groups
	for (unsigned int i = 0; i < urus.nodes.size(); i++) {
		uru = urus.nodes[i];

		if (dbswzsk->tblwzskamusergroupaccess->loadRecBySQL("SELECT * FROM TblWzskAMUsergroupAccess WHERE refWzskMUsergroup = " + to_string(uru->refWzskMUsergroup) + " AND x1IxWzskVFeatgroup = " + to_string(ixWzskVFeatgroup) + " AND x2FeaSrefUix = '" + srefIxVFeature + "'", &usgAacc)) {
			ixAcc |= usgAacc->ixWzskWAccess;
			first = false;

			delete usgAacc;
		};

		if (ixAcc == (VecWzskWAccess::EDIT + VecWzskWAccess::EXEC + VecWzskWAccess::VIEW)) break;
	};

	if (!first) ixWzskWAccess = ixAcc;

	// user access rights override user group access rights
	if (dbswzsk->tblwzskamuseraccess->loadRecBySQL("SELECT * FROM TblWzskAMUserAccess WHERE refWzskMUser = " + to_string(refWzskMUser) + " AND x1IxWzskVFeatgroup = " + to_string(ixWzskVFeatgroup) + " AND x2FeaSrefUix = '" + srefIxVFeature + "'", &usrAacc)) {
		ixWzskWAccess = usrAacc->ixWzskWAccess;
		delete usrAacc;
	};
};

void M2msessWzsk::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKINIT) {
			handleDpchAppWzskInit(dbswzsk, (DpchAppWzskInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void M2msessWzsk::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = new DpchEngData(jref, &statshr, {DpchEngData::ALL});
};

void M2msessWzsk::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKACCESS) {
		call->abort = handleCallWzskAccess(dbswzsk, call->jref, call->argInv.ix, call->argInv.sref, call->argRet.ix);
	};
};

bool M2msessWzsk::handleCallWzskAccess(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = 0;

	auto it = accs.find(featix_t(ixInv, srefInv));
	if (it != accs.end()) ixRet = it->second;
	else {
		it = accs.find(featix_t(ixInv, ""));
		if (it != accs.end()) ixRet = it->second;
	};
	return retval;
};
