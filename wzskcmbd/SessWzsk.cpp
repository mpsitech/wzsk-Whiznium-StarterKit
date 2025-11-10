/**
	* \file SessWzsk.cpp
	* job handler for job SessWzsk (implementation)
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

#include "SessWzsk.h"

#include "SessWzsk_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class SessWzsk
 ******************************************************************************/

SessWzsk::SessWzsk(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const ubigint refWzskMUser
			, const string& ip
		) :
			JobWzsk(xchg, VecWzskVJob::SESSWZSK, jrefSup)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	crdnav = NULL;

	// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	WzskMUser* usr = NULL;

	bool adm;

	ListWzskRMUserMUsergroup urus;
	WzskRMUserMUsergroup* uru = NULL;

	uint ixWzskWAccessBase, ixWzskWAccess;

	uint jnum;

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

	xchg->addBoolvalPreset(VecWzskVPreset::PREWZSKADMIN, jref, adm);
	xchg->addBoolvalPreset(VecWzskVPreset::PREWZSKNOADM, jref, (usr->ixWzskVUserlevel == VecWzskVUserlevel::REG));

	xchg->addRefPreset(VecWzskVPreset::PREWZSKGROUP, jref, usr->refWzskMUsergroup);
	xchg->addRefPreset(VecWzskVPreset::PREWZSKOWNER, jref, refWzskMUser);

	delete usr;

	// set jrefSess (for access to WzskQSelect from rst-type panel queries)
	xchg->addRefPreset(VecWzskVPreset::PREWZSKJREFSESS, jref, jref);

	// fill query in WzskQSelect with all applicable user groups
	jnum = 1;

	dbswzsk->tblwzskqselect->insertNewRec(NULL, jref, jnum++, 0, 0);

	if (adm) {
		dbswzsk->loadRefsBySQL("SELECT ref FROM TblWzskMUsergroup ORDER BY ref ASC", false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) dbswzsk->tblwzskqselect->insertNewRec(NULL, jref, jnum++, 0, refs[i]);

	} else {
		dbswzsk->tblwzskrmusermusergroup->loadRstByUsr(refWzskMUser, false, urus);

		for (unsigned int i = 0; i < urus.nodes.size(); i++) {
			uru = urus.nodes[i];

			usgaccs[uru->refWzskMUsergroup] = uru->ixWzskVUserlevel;
			dbswzsk->tblwzskqselect->insertNewRec(NULL, jref, jnum++, 0, uru->refWzskMUsergroup);
		};
	};

	// determine access rights for each card
	ixWzskWAccessBase = 0;
	getIxCrdacc(dbswzsk, 0, adm, urus, refWzskMUser, ixWzskWAccessBase);

	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKUSG, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKUSR, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKPRS, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKPRF, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRF, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKLLV, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKVTR, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCVTR, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKHWC, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCHWC, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKFIL, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref, ixWzskWAccess);

	crdnav = new CrdWzskNav(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecWzskVCall::CALLWZSKCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKLOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

SessWzsk::~SessWzsk() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void SessWzsk::warnTerm(
			DbsWzsk* dbswzsk
		) {
	crdnav->warnTerm(dbswzsk);
};

void SessWzsk::term(
			DbsWzsk* dbswzsk
		) {
	WzskMSession* ses = NULL;

	time_t rawtime;

	// update session with stop time
	time(&rawtime);

	if (dbswzsk->tblwzskmsession->loadRecByRef(xchg->getRefPreset(VecWzskVPreset::PREWZSKSESS, jref), &ses)) {
		ses->stop = rawtime;
		dbswzsk->tblwzskmsession->updateRec(ses);

		delete ses;
	};
};

void SessWzsk::eraseCrd(
			map<ubigint, JobWzsk*>& subjobs
		) {
	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoll(input.c_str());

	if (!eraseSubjobByJref(subjobs, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tcard erased." << endl;
};

uint SessWzsk::checkCrdActive(
			const uint ixWzskVCard
		) {

	return 0;
};

uint SessWzsk::checkCrdaccess(
			const uint ixWzskVCard
		) {
	if (ixWzskVCard == VecWzskVCard::CRDWZSKUSG) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref);
	if (ixWzskVCard == VecWzskVCard::CRDWZSKUSR) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref);
	if (ixWzskVCard == VecWzskVCard::CRDWZSKPRS) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref);
	if (ixWzskVCard == VecWzskVCard::CRDWZSKPRF) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRF, jref);
	if (ixWzskVCard == VecWzskVCard::CRDWZSKLLV) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref);
	if (ixWzskVCard == VecWzskVCard::CRDWZSKVTR) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCVTR, jref);
	if (ixWzskVCard == VecWzskVCard::CRDWZSKHWC) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCHWC, jref);
	if (ixWzskVCard == VecWzskVCard::CRDWZSKFIL) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref);

	return 0;
};

void SessWzsk::getIxCrdacc(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCard
			, const bool adm
			, ListWzskRMUserMUsergroup& urus
			, const ubigint refWzskMUser
			, uint& ixWzskWAccess
		) {
	WzskRMUserMUsergroup* uru = NULL;
	WzskAMUsergroupAccess* usgAacc = NULL;
	WzskAMUserAccess* usrAacc = NULL;

	uint ixCrdacc = 0;

	bool first = true;

	if (adm) {
		ixWzskWAccess = VecWzskWAccess::EDIT + VecWzskWAccess::EXEC + VecWzskWAccess::VIEW;
		return;
	};

	// check for access rights override by any of the applicable user groups
	for (unsigned int i = 0; i < urus.nodes.size(); i++) {
		uru = urus.nodes[i];

		if (dbswzsk->tblwzskamusergroupaccess->loadRecBySQL("SELECT * FROM TblWzskAMUsergroupAccess WHERE refWzskMUsergroup = " + to_string(uru->refWzskMUsergroup) + " AND x1IxWzskVFeatgroup = " + to_string(VecWzskVFeatgroup::VECWZSKVCARD) + " AND x2FeaSrefUix = '" + VecWzskVCard::getSref(ixWzskVCard) + "'", &usgAacc)) {
			ixCrdacc |= usgAacc->ixWzskWAccess;
			first = false;

			delete usgAacc;
			if (ixCrdacc == (VecWzskWAccess::EDIT + VecWzskWAccess::EXEC + VecWzskWAccess::VIEW)) break;
		};
	};

	if (!first) ixWzskWAccess = ixCrdacc;

	// user access rights override user group access rights
	if (dbswzsk->tblwzskamuseraccess->loadRecBySQL("SELECT * FROM TblWzskAMUserAccess WHERE refWzskMUser = " + to_string(refWzskMUser) + " AND x1IxWzskVFeatgroup = " + to_string(VecWzskVFeatgroup::VECWZSKVCARD) + " AND x2FeaSrefUix = '" + VecWzskVCard::getSref(ixWzskVCard) + "'", &usrAacc)) {
		ixWzskWAccess = usrAacc->ixWzskWAccess;
		delete usrAacc;
	};

};

uint SessWzsk::checkRecaccess(
			DbsWzsk* dbswzsk
			, const uint ixWzskVCard
			, const ubigint ref
		) {
	uint retval = VecWzskVRecaccess::NONE;

	ubigint grp;
	ubigint own;

	map<ubigint,uint>::iterator it;

	ubigint refWzskMUser;
	uint ixWzskVMaintable;

	WzskAccRMUserUniversal* ausrRunv = NULL;
	WzskRMUsergroupUniversal* usgRunv = NULL;

	ixWzskVMaintable = crdToMtb(ixWzskVCard);

	if (ixWzskVMaintable == VecWzskVMaintable::VOID) {
		retval = VecWzskVRecaccess::FULL;

	} else if (hasGrpown(ixWzskVMaintable) && (ref != 0)) {
		// find record's group and owner
		dbswzsk->loadRefBySQL("SELECT grp FROM " + VecWzskVMaintable::getSref(ixWzskVMaintable) + " WHERE ref = " + to_string(ref), grp);
		dbswzsk->loadRefBySQL("SELECT own FROM " + VecWzskVMaintable::getSref(ixWzskVMaintable) + " WHERE ref = " + to_string(ref), own);

		// administrators can edit any record
		if (xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKADMIN, jref)) retval = VecWzskVRecaccess::FULL;

		if (retval == VecWzskVRecaccess::NONE) {
			refWzskMUser = xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref);

			// a record's owner has full rights on his records
			if (refWzskMUser == own) retval = VecWzskVRecaccess::FULL;

			if (retval != VecWzskVRecaccess::FULL) {
				// individual record access right
				if (dbswzsk->tblwzskaccrmuseruniversal->loadRecByUsrMtbUnv(refWzskMUser, ixWzskVMaintable, ref, &ausrRunv)) {
					retval = ausrRunv->ixWzskVRecaccess;
					delete ausrRunv;
				};
			};

			if (retval != VecWzskVRecaccess::FULL) {
				it = usgaccs.find(grp);
				if (it != usgaccs.end()) {
					if (it->second == VecWzskVUserlevel::GADM) {
						// group admins have full access to all of the group's records
						retval = VecWzskVRecaccess::FULL;
					};
				};
			};

			if (retval != VecWzskVRecaccess::FULL) {
				// individual record access right due to group membership
				for (it = usgaccs.begin(); it != usgaccs.end(); it++) {

					if (it->second == VecWzskVUserlevel::GADM) {
						if (dbswzsk->tblwzskrmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ixWzskVMaintable, ref, &usgRunv)) {
							if (usgRunv->ixWzskVRecaccess == VecWzskVRecaccess::FULL) retval = VecWzskVRecaccess::FULL;
							else retval = VecWzskVRecaccess::VIEW;

							delete usgRunv;
						};
					};

					if (retval == VecWzskVRecaccess::FULL) break;
				};
			};
		};

	} else {
		if (xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKADMIN, jref)) retval = VecWzskVRecaccess::FULL;
		else retval = VecWzskVRecaccess::VIEW;
	};

	return retval;
};

void SessWzsk::logRecaccess(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPreset
			, const ubigint preUref
			, const uint ixWzskVCard
			, const ubigint unvUref
		) {
	vector<ubigint> refs;

	ubigint refWzskMUser;
	uint unvIxWzskVMaintable;
	uint preIxWzskVMaintable;

	WzskHistRMUserUniversal* husrRunv = NULL;

	if (xchg->stgwzskbehavior.histlength > 0) {
		refWzskMUser = xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref);
		unvIxWzskVMaintable = crdToMtb(ixWzskVCard);
		preIxWzskVMaintable = preToMtb(ixWzskVPreset);

		if (!dbswzsk->tblwzskhistrmuseruniversal->loadRecByUsrMtbUnvCrd(refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, &husrRunv)) {
			husrRunv = new WzskHistRMUserUniversal(0, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, 0);
		};

		husrRunv->start = time(NULL);

		if (husrRunv->ref == 0) {
			dbswzsk->tblwzskhistrmuseruniversal->insertRec(husrRunv);

			dbswzsk->tblwzskhistrmuseruniversal->loadRefsByUsrMtbCrd(refWzskMUser, unvIxWzskVMaintable, ixWzskVCard, false, refs, 4294967296, xchg->stgwzskbehavior.histlength);
			for (unsigned int i = 0; i < refs.size(); i++) dbswzsk->tblwzskhistrmuseruniversal->removeRecByRef(refs[i]);

		} else dbswzsk->tblwzskhistrmuseruniversal->updateRec(husrRunv);

		xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKHUSRRUNVMOD_CRDUSREQ, jref, ixWzskVCard, refWzskMUser);
	};

	delete husrRunv;
};

uint SessWzsk::crdToMtb(
			const uint ixWzskVCard
		) {
	if (ixWzskVCard == VecWzskVCard::CRDWZSKUSG) return VecWzskVMaintable::TBLWZSKMUSERGROUP;
	if (ixWzskVCard == VecWzskVCard::CRDWZSKUSR) return VecWzskVMaintable::TBLWZSKMUSER;
	if (ixWzskVCard == VecWzskVCard::CRDWZSKPRS) return VecWzskVMaintable::TBLWZSKMPERSON;
	if (ixWzskVCard == VecWzskVCard::CRDWZSKFIL) return VecWzskVMaintable::TBLWZSKMFILE;

	return VecWzskVMaintable::VOID;
};

uint SessWzsk::preToMtb(
			const uint ixWzskVPreset
		) {
	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFFIL) return VecWzskVMaintable::TBLWZSKMFILE;
	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFPRS) return VecWzskVMaintable::TBLWZSKMPERSON;
	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFSES) return VecWzskVMaintable::TBLWZSKMSESSION;
	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFUSG) return VecWzskVMaintable::TBLWZSKMUSERGROUP;
	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFUSR) return VecWzskVMaintable::TBLWZSKMUSER;

	return VecWzskVMaintable::VOID;
};

bool SessWzsk::hasActive(
			const uint ixWzskVCard
		) {
	return(false);
};

bool SessWzsk::hasGrpown(
			const uint ixWzskVMaintable
		) {
	return((ixWzskVMaintable == VecWzskVMaintable::TBLWZSKMFILE) || (ixWzskVMaintable == VecWzskVMaintable::TBLWZSKMPERSON) || (ixWzskVMaintable == VecWzskVMaintable::TBLWZSKMUSER) || (ixWzskVMaintable == VecWzskVMaintable::TBLWZSKMUSERGROUP));
};

void SessWzsk::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tcreateCrdfil" << endl;
			cout << "\tcreateCrdhwc" << endl;
			cout << "\tcreateCrdllv" << endl;
			cout << "\tcreateCrdprf" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\tcreateCrdvtr" << endl;
			cout << "\teraseCrdfil" << endl;
			cout << "\teraseCrdhwc" << endl;
			cout << "\teraseCrdllv" << endl;
			cout << "\teraseCrdprf" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
			cout << "\teraseCrdvtr" << endl;
		} else if (req->cmd == "createCrdfil") {
			req->retain = handleCreateCrdfil(dbswzsk);

		} else if (req->cmd == "createCrdhwc") {
			req->retain = handleCreateCrdhwc(dbswzsk);

		} else if (req->cmd == "createCrdllv") {
			req->retain = handleCreateCrdllv(dbswzsk);

		} else if (req->cmd == "createCrdprf") {
			req->retain = handleCreateCrdprf(dbswzsk);

		} else if (req->cmd == "createCrdprs") {
			req->retain = handleCreateCrdprs(dbswzsk);

		} else if (req->cmd == "createCrdusg") {
			req->retain = handleCreateCrdusg(dbswzsk);

		} else if (req->cmd == "createCrdusr") {
			req->retain = handleCreateCrdusr(dbswzsk);

		} else if (req->cmd == "createCrdvtr") {
			req->retain = handleCreateCrdvtr(dbswzsk);

		} else if (req->cmd == "eraseCrdfil") {
			req->retain = handleEraseCrdfil(dbswzsk);

		} else if (req->cmd == "eraseCrdhwc") {
			req->retain = handleEraseCrdhwc(dbswzsk);

		} else if (req->cmd == "eraseCrdllv") {
			req->retain = handleEraseCrdllv(dbswzsk);

		} else if (req->cmd == "eraseCrdprf") {
			req->retain = handleEraseCrdprf(dbswzsk);

		} else if (req->cmd == "eraseCrdprs") {
			req->retain = handleEraseCrdprs(dbswzsk);

		} else if (req->cmd == "eraseCrdusg") {
			req->retain = handleEraseCrdusg(dbswzsk);

		} else if (req->cmd == "eraseCrdusr") {
			req->retain = handleEraseCrdusr(dbswzsk);

		} else if (req->cmd == "eraseCrdvtr") {
			req->retain = handleEraseCrdvtr(dbswzsk);

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

bool SessWzsk::handleCreateCrdfil(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdfils, new CrdWzskFil(xchg, dbswzsk, jref, ixWzskVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdhwc(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdhwcs, new CrdWzskHwc(xchg, dbswzsk, jref, ixWzskVLocale));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdllv(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdllvs, new CrdWzskLlv(xchg, dbswzsk, jref, ixWzskVLocale));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdprf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprfs, new CrdWzskPrf(xchg, dbswzsk, jref, ixWzskVLocale));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdprs(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprss, new CrdWzskPrs(xchg, dbswzsk, jref, ixWzskVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdusg(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusgs, new CrdWzskUsg(xchg, dbswzsk, jref, ixWzskVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdusr(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusrs, new CrdWzskUsr(xchg, dbswzsk, jref, ixWzskVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdvtr(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdvtrs, new CrdWzskVtr(xchg, dbswzsk, jref, ixWzskVLocale));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleEraseCrdfil(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdfils);
	return retval;
};

bool SessWzsk::handleEraseCrdhwc(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdhwcs);
	return retval;
};

bool SessWzsk::handleEraseCrdllv(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdllvs);
	return retval;
};

bool SessWzsk::handleEraseCrdprf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdprfs);
	return retval;
};

bool SessWzsk::handleEraseCrdprs(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdprss);
	return retval;
};

bool SessWzsk::handleEraseCrdusg(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdusgs);
	return retval;
};

bool SessWzsk::handleEraseCrdusr(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdusrs);
	return retval;
};

bool SessWzsk::handleEraseCrdvtr(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdvtrs);
	return retval;
};

void SessWzsk::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	Feed feedFEnsSec("FeedFEnsSec");

	// resume session
	xchg->removePreset(VecWzskVPreset::PREWZSKSUSPSESS, jref);

	for (auto it = crdusgs.begin(); it != crdusgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskUsg");
	for (auto it = crdusrs.begin(); it != crdusrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskUsr");
	for (auto it = crdprss.begin(); it != crdprss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskPrs");
	for (auto it = crdprfs.begin(); it != crdprfs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskPrf");
	for (auto it = crdllvs.begin(); it != crdllvs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskLlv");
	for (auto it = crdvtrs.begin(); it != crdvtrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskVtr");
	for (auto it = crdhwcs.begin(); it != crdhwcs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskHwc");
	for (auto it = crdfils.begin(); it != crdfils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskFil");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessWzsk::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKCRDACTIVE) {
		call->abort = handleCallWzskCrdActive(dbswzsk, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCRDCLOSE) {
		call->abort = handleCallWzskCrdClose(dbswzsk, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCRDOPEN) {
		call->abort = handleCallWzskCrdOpen(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKLOG) {
		call->abort = handleCallWzskLog(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKRECACCESS) {
		call->abort = handleCallWzskRecaccess(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKREFPRESET) {
		call->abort = handleCallWzskRefPreSet(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool SessWzsk::handleCallWzskCrdActive(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkCrdActive(ixInv);
	return retval;
};

bool SessWzsk::handleCallWzskCrdClose(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// delete only if card is not part of a suspended session
	if (xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKSUSPSESS, jrefTrig)) return retval;

	ubigint jrefNotif = xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFNOTIFY, jref);
	if (jrefNotif == jrefTrig) xchg->removePreset(VecWzskVPreset::PREWZSKJREFNOTIFY, jref);

	if (ixInv == VecWzskVCard::CRDWZSKNAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} 
else if (ixInv == VecWzskVCard::CRDWZSKUSG) eraseSubjobByJref(crdusgs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKUSR) eraseSubjobByJref(crdusrs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKPRS) eraseSubjobByJref(crdprss, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKPRF) eraseSubjobByJref(crdprfs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKLLV) eraseSubjobByJref(crdllvs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKVTR) eraseSubjobByJref(crdvtrs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKHWC) eraseSubjobByJref(crdhwcs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKFIL) eraseSubjobByJref(crdfils, jrefTrig);
	return retval;
};

bool SessWzsk::handleCallWzskCrdOpen(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval = false;
	bool denied = false;

	uint ixWzskVCard = VecWzskVCard::getIx(srefInv);

	ubigint ref = (ubigint) intvalInv;
	if (intvalInv == -1) {
		ref = 0;
		ref--;
	};

	uint ixWzskVPreset;
	ubigint preUref = 0;

	uint ixWzskWAccess;
	uint ixWzskVRecaccess;

	if (hasActive(ixWzskVCard)) {
		if (ixInv == 0) {
			ixWzskVPreset = checkCrdActive(ixWzskVCard);
			if (ixWzskVPreset == 0) {
				denied = true;
			} else {
				preUref = xchg->getRefPreset(ixWzskVPreset, jref);
			};

		} else {
			ixWzskVPreset = ixInv;
			preUref = refInv;
		};
	};

	if (!denied) {
		ixWzskWAccess = checkCrdaccess(ixWzskVCard);
		denied = (ixWzskWAccess == 0);
	};

	if (!denied) {
		if (intvalInv == -1) {
			denied = (((ixWzskWAccess & VecWzskWAccess::EDIT) == 0) || ((ixWzskWAccess & VecWzskWAccess::EXEC) == 0));
		} else if (intvalInv > 0) {
			ixWzskVRecaccess = checkRecaccess(dbswzsk, ixWzskVCard, intvalInv);
			denied = (ixWzskVRecaccess == VecWzskVRecaccess::NONE);
		};
	};

	if (denied) {
		refRet = 0;

	} else {
		if (ixWzskVCard == VecWzskVCard::CRDWZSKUSG) refRet = insertSubjob(crdusgs, new CrdWzskUsg(xchg, dbswzsk, jref, ixWzskVLocale, ref));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKUSR) refRet = insertSubjob(crdusrs, new CrdWzskUsr(xchg, dbswzsk, jref, ixWzskVLocale, ref));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKPRS) refRet = insertSubjob(crdprss, new CrdWzskPrs(xchg, dbswzsk, jref, ixWzskVLocale, ref));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKPRF) refRet = insertSubjob(crdprfs, new CrdWzskPrf(xchg, dbswzsk, jref, ixWzskVLocale));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKLLV) refRet = insertSubjob(crdllvs, new CrdWzskLlv(xchg, dbswzsk, jref, ixWzskVLocale));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKVTR) refRet = insertSubjob(crdvtrs, new CrdWzskVtr(xchg, dbswzsk, jref, ixWzskVLocale));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKHWC) refRet = insertSubjob(crdhwcs, new CrdWzskHwc(xchg, dbswzsk, jref, ixWzskVLocale));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKFIL) refRet = insertSubjob(crdfils, new CrdWzskFil(xchg, dbswzsk, jref, ixWzskVLocale, ref));
	};

	return retval;
};

bool SessWzsk::handleCallWzskLog(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval = false;
	logRecaccess(dbswzsk, ixInv, refInv, VecWzskVCard::getIx(srefInv), intvalInv);
	return retval;
};

bool SessWzsk::handleCallWzskRecaccess(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkRecaccess(dbswzsk, ixInv, refInv);
	return retval;
};

bool SessWzsk::handleCallWzskRefPreSet(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallWzskRefPreSet --- BEGIN
	if (ixInv == VecWzskVPreset::PREWZSKJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngWzskSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if (ixInv == VecWzskVPreset::PREWZSKTLAST) {
		if (xchg->stgwzskbehavior.sesstterm != 0) xchg->addRefPreset(ixInv, jref, refInv);

	};
// IP handleCallWzskRefPreSet --- END
	return retval;
};
