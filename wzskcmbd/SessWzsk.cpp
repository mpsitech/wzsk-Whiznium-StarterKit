/**
	* \file SessWzsk.cpp
	* job handler for job SessWzsk (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKSCF, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSCF, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKLLV, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKLIV, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLIV, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKOGR, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKOBJ, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKSES, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKSHT, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref, ixWzskWAccess);
	ixWzskWAccess = ixWzskWAccessBase; if (!adm) getIxCrdacc(dbswzsk, VecWzskVCard::CRDWZSKFIL, adm, urus, refWzskMUser, ixWzskWAccess); xchg->addIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref, ixWzskWAccess);

	crdnav = new CrdWzskNav(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecWzskVCall::CALLWZSKREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKLOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

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
	if (ixWzskVCard == VecWzskVCard::CRDWZSKSHT) return evalCrdshtActive();
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKFIL) return evalCrdfilActive();

	return 0;
};

uint SessWzsk::evalCrdshtActive() {
	// pre.refObj() > pre.void()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref)) ? VecWzskVPreset::PREWZSKREFOBJ : 0);
	args.push_back([](){uint preVoid = VecWzskVPreset::VOID; return preVoid;}());
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWzsk::evalCrdfilActive() {
	// pre.refObj() > pre.void()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref)) ? VecWzskVPreset::PREWZSKREFOBJ : 0);
	args.push_back([](){uint preVoid = VecWzskVPreset::VOID; return preVoid;}());
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWzsk::checkCrdaccess(
			const uint ixWzskVCard
		) {
	if (ixWzskVCard == VecWzskVCard::CRDWZSKUSG) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKUSR) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKPRS) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKSCF) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSCF, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKLLV) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKLIV) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLIV, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKOGR) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKOBJ) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKSES) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKSHT) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref);
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKFIL) return xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref);

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

	if (xchg->stgwzskappearance.histlength > 0) {
		refWzskMUser = xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref);
		unvIxWzskVMaintable = crdToMtb(ixWzskVCard);
		preIxWzskVMaintable = preToMtb(ixWzskVPreset);

		if (!dbswzsk->tblwzskhistrmuseruniversal->loadRecByUsrMtbUnvCrd(refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, &husrRunv)) {
			husrRunv = new WzskHistRMUserUniversal(0, refWzskMUser, unvIxWzskVMaintable, unvUref, ixWzskVCard, ixWzskVPreset, preIxWzskVMaintable, preUref, 0);
		};

		husrRunv->start = time(NULL);

		if (husrRunv->ref == 0) {
			dbswzsk->tblwzskhistrmuseruniversal->insertRec(husrRunv);

			dbswzsk->tblwzskhistrmuseruniversal->loadRefsByUsrMtbCrd(refWzskMUser, unvIxWzskVMaintable, ixWzskVCard, false, refs, 4294967296, xchg->stgwzskappearance.histlength);
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
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKUSR) return VecWzskVMaintable::TBLWZSKMUSER;
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKPRS) return VecWzskVMaintable::TBLWZSKMPERSON;
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKOGR) return VecWzskVMaintable::TBLWZSKMOBJGROUP;
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKOBJ) return VecWzskVMaintable::TBLWZSKMOBJECT;
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKSES) return VecWzskVMaintable::TBLWZSKMSESSION;
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKSHT) return VecWzskVMaintable::TBLWZSKMSHOT;
	else if (ixWzskVCard == VecWzskVCard::CRDWZSKFIL) return VecWzskVMaintable::TBLWZSKMFILE;

	return VecWzskVMaintable::VOID;
};

uint SessWzsk::preToMtb(
			const uint ixWzskVPreset
		) {
	if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFFIL) return VecWzskVMaintable::TBLWZSKMFILE;
	else if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFOBJ) return VecWzskVMaintable::TBLWZSKMOBJECT;
	else if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFOGR) return VecWzskVMaintable::TBLWZSKMOBJGROUP;
	else if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFPRS) return VecWzskVMaintable::TBLWZSKMPERSON;
	else if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFSES) return VecWzskVMaintable::TBLWZSKMSESSION;
	else if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFSHT) return VecWzskVMaintable::TBLWZSKMSHOT;
	else if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFUSG) return VecWzskVMaintable::TBLWZSKMUSERGROUP;
	else if (ixWzskVPreset == VecWzskVPreset::PREWZSKREFUSR) return VecWzskVMaintable::TBLWZSKMUSER;

	return VecWzskVMaintable::VOID;
};

bool SessWzsk::hasActive(
			const uint ixWzskVCard
		) {
	return((ixWzskVCard == VecWzskVCard::CRDWZSKSHT) || (ixWzskVCard == VecWzskVCard::CRDWZSKFIL));
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
			cout << "\tcreateCrdliv" << endl;
			cout << "\tcreateCrdllv" << endl;
			cout << "\tcreateCrdobj" << endl;
			cout << "\tcreateCrdogr" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdscf" << endl;
			cout << "\tcreateCrdses" << endl;
			cout << "\tcreateCrdsht" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\teraseCrdfil" << endl;
			cout << "\teraseCrdliv" << endl;
			cout << "\teraseCrdllv" << endl;
			cout << "\teraseCrdobj" << endl;
			cout << "\teraseCrdogr" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdscf" << endl;
			cout << "\teraseCrdses" << endl;
			cout << "\teraseCrdsht" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
		} else if (req->cmd == "createCrdfil") {
			req->retain = handleCreateCrdfil(dbswzsk);

		} else if (req->cmd == "createCrdliv") {
			req->retain = handleCreateCrdliv(dbswzsk);

		} else if (req->cmd == "createCrdllv") {
			req->retain = handleCreateCrdllv(dbswzsk);

		} else if (req->cmd == "createCrdobj") {
			req->retain = handleCreateCrdobj(dbswzsk);

		} else if (req->cmd == "createCrdogr") {
			req->retain = handleCreateCrdogr(dbswzsk);

		} else if (req->cmd == "createCrdprs") {
			req->retain = handleCreateCrdprs(dbswzsk);

		} else if (req->cmd == "createCrdscf") {
			req->retain = handleCreateCrdscf(dbswzsk);

		} else if (req->cmd == "createCrdses") {
			req->retain = handleCreateCrdses(dbswzsk);

		} else if (req->cmd == "createCrdsht") {
			req->retain = handleCreateCrdsht(dbswzsk);

		} else if (req->cmd == "createCrdusg") {
			req->retain = handleCreateCrdusg(dbswzsk);

		} else if (req->cmd == "createCrdusr") {
			req->retain = handleCreateCrdusr(dbswzsk);

		} else if (req->cmd == "eraseCrdfil") {
			req->retain = handleEraseCrdfil(dbswzsk);

		} else if (req->cmd == "eraseCrdliv") {
			req->retain = handleEraseCrdliv(dbswzsk);

		} else if (req->cmd == "eraseCrdllv") {
			req->retain = handleEraseCrdllv(dbswzsk);

		} else if (req->cmd == "eraseCrdobj") {
			req->retain = handleEraseCrdobj(dbswzsk);

		} else if (req->cmd == "eraseCrdogr") {
			req->retain = handleEraseCrdogr(dbswzsk);

		} else if (req->cmd == "eraseCrdprs") {
			req->retain = handleEraseCrdprs(dbswzsk);

		} else if (req->cmd == "eraseCrdscf") {
			req->retain = handleEraseCrdscf(dbswzsk);

		} else if (req->cmd == "eraseCrdses") {
			req->retain = handleEraseCrdses(dbswzsk);

		} else if (req->cmd == "eraseCrdsht") {
			req->retain = handleEraseCrdsht(dbswzsk);

		} else if (req->cmd == "eraseCrdusg") {
			req->retain = handleEraseCrdusg(dbswzsk);

		} else if (req->cmd == "eraseCrdusr") {
			req->retain = handleEraseCrdusr(dbswzsk);

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

	uint ixWzskVPreset = evalCrdfilActive();

	if (ixWzskVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdfils, new CrdWzskFil(xchg, dbswzsk, jref, ixWzskVLocale, 0, ixWzskVPreset, xchg->getRefPreset(ixWzskVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWzsk::handleCreateCrdliv(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdlivs, new CrdWzskLiv(xchg, dbswzsk, jref, ixWzskVLocale));
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

bool SessWzsk::handleCreateCrdobj(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdobjs, new CrdWzskObj(xchg, dbswzsk, jref, ixWzskVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdogr(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdogrs, new CrdWzskOgr(xchg, dbswzsk, jref, ixWzskVLocale, 0));
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

bool SessWzsk::handleCreateCrdscf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdscfs, new CrdWzskScf(xchg, dbswzsk, jref, ixWzskVLocale));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdses(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdsess, new CrdWzskSes(xchg, dbswzsk, jref, ixWzskVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzsk::handleCreateCrdsht(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	uint ixWzskVPreset = evalCrdshtActive();

	if (ixWzskVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdshts, new CrdWzskSht(xchg, dbswzsk, jref, ixWzskVLocale, 0, ixWzskVPreset, xchg->getRefPreset(ixWzskVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

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

bool SessWzsk::handleEraseCrdfil(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdfils);
	return retval;
};

bool SessWzsk::handleEraseCrdliv(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdlivs);
	return retval;
};

bool SessWzsk::handleEraseCrdllv(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdllvs);
	return retval;
};

bool SessWzsk::handleEraseCrdobj(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdobjs);
	return retval;
};

bool SessWzsk::handleEraseCrdogr(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdogrs);
	return retval;
};

bool SessWzsk::handleEraseCrdprs(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdprss);
	return retval;
};

bool SessWzsk::handleEraseCrdscf(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdscfs);
	return retval;
};

bool SessWzsk::handleEraseCrdses(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdsess);
	return retval;
};

bool SessWzsk::handleEraseCrdsht(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	eraseCrd(crdshts);
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
	for (auto it = crdscfs.begin(); it != crdscfs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskScf");
	for (auto it = crdllvs.begin(); it != crdllvs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskLlv");
	for (auto it = crdlivs.begin(); it != crdlivs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskLiv");
	for (auto it = crdogrs.begin(); it != crdogrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskOgr");
	for (auto it = crdobjs.begin(); it != crdobjs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskObj");
	for (auto it = crdsess.begin(); it != crdsess.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskSes");
	for (auto it = crdshts.begin(); it != crdshts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskSht");
	for (auto it = crdfils.begin(); it != crdfils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzskFil");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessWzsk::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKREFPRESET) {
		call->abort = handleCallWzskRefPreSet(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKRECACCESS) {
		call->abort = handleCallWzskRecaccess(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKLOG) {
		call->abort = handleCallWzskLog(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCRDOPEN) {
		call->abort = handleCallWzskCrdOpen(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCRDCLOSE) {
		call->abort = handleCallWzskCrdClose(dbswzsk, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCRDACTIVE) {
		call->abort = handleCallWzskCrdActive(dbswzsk, call->jref, call->argInv.ix, call->argRet.ix);
	};
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
		if (xchg->stgwzskappearance.sesstterm != 0) xchg->addRefPreset(ixInv, jref, refInv);

	} else if ((ixInv == VecWzskVPreset::PREWZSKREFOBJ)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbswzsk, ixInv, jrefTrig, true);
	};
// IP handleCallWzskRefPreSet --- END
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
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKSCF) refRet = insertSubjob(crdscfs, new CrdWzskScf(xchg, dbswzsk, jref, ixWzskVLocale));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKLLV) refRet = insertSubjob(crdllvs, new CrdWzskLlv(xchg, dbswzsk, jref, ixWzskVLocale));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKLIV) refRet = insertSubjob(crdlivs, new CrdWzskLiv(xchg, dbswzsk, jref, ixWzskVLocale));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKOGR) refRet = insertSubjob(crdogrs, new CrdWzskOgr(xchg, dbswzsk, jref, ixWzskVLocale, ref));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKOBJ) refRet = insertSubjob(crdobjs, new CrdWzskObj(xchg, dbswzsk, jref, ixWzskVLocale, ref));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKSES) refRet = insertSubjob(crdsess, new CrdWzskSes(xchg, dbswzsk, jref, ixWzskVLocale, ref));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKSHT) refRet = insertSubjob(crdshts, new CrdWzskSht(xchg, dbswzsk, jref, ixWzskVLocale, ref, ixWzskVPreset, preUref));
		else if (ixWzskVCard == VecWzskVCard::CRDWZSKFIL) refRet = insertSubjob(crdfils, new CrdWzskFil(xchg, dbswzsk, jref, ixWzskVLocale, ref, ixWzskVPreset, preUref));
	};

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
	else if (ixInv == VecWzskVCard::CRDWZSKSCF) eraseSubjobByJref(crdscfs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKLLV) eraseSubjobByJref(crdllvs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKLIV) eraseSubjobByJref(crdlivs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKOGR) eraseSubjobByJref(crdogrs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKOBJ) eraseSubjobByJref(crdobjs, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKSES) eraseSubjobByJref(crdsess, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKSHT) eraseSubjobByJref(crdshts, jrefTrig);
	else if (ixInv == VecWzskVCard::CRDWZSKFIL) eraseSubjobByJref(crdfils, jrefTrig);
	return retval;
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
