/**
	* \file JobWzskIexIni.cpp
	* job handler for job JobWzskIexIni (implementation)
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

#include "JobWzskIexIni.h"

#include "JobWzskIexIni_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWzskIni;

/******************************************************************************
 class JobWzskIexIni
 ******************************************************************************/

JobWzskIexIni::JobWzskIexIni(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::JOBWZSKIEXINI, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswzsk, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWzskIexIni::~JobWzskIexIni() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWzskIexIni::reset(
			DbsWzsk* dbswzsk
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswzsk, VecVSge::IDLE);
};

void JobWzskIexIni::parseFromFile(
			DbsWzsk* dbswzsk
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const string& _rectpath
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		rectpath = _rectpath;

		changeStage(dbswzsk, VecVSge::PARSE);
	};
};

void JobWzskIexIni::import(
			DbsWzsk* dbswzsk
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswzsk, VecVSge::IMPORT);
};

void JobWzskIexIni::reverse(
			DbsWzsk* dbswzsk
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswzsk, VecVSge::REVERSE);
};

void JobWzskIexIni::collect(
			DbsWzsk* dbswzsk
			, const map<uint,uint>& _icsWzskVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWzskVIop = _icsWzskVIop;
		changeStage(dbswzsk, VecVSge::COLLECT);
	};
};

void JobWzskIexIni::exportToFile(
			DbsWzsk* dbswzsk
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const bool _shorttags
		) {
	if ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CLTDONE)) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		shorttags = _shorttags;

		changeStage(dbswzsk, VecVSge::EXPORT);
	};
};

void JobWzskIexIni::handleRequest(
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

	};
};

void JobWzskIexIni::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::PARSE: leaveSgeParse(dbswzsk); break;
				case VecVSge::PRSERR: leaveSgePrserr(dbswzsk); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswzsk); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswzsk); break;
				case VecVSge::IMPERR: leaveSgeImperr(dbswzsk); break;
				case VecVSge::REVERSE: leaveSgeReverse(dbswzsk); break;
				case VecVSge::COLLECT: leaveSgeCollect(dbswzsk); break;
				case VecVSge::CLTDONE: leaveSgeCltdone(dbswzsk); break;
				case VecVSge::EXPORT: leaveSgeExport(dbswzsk); break;
				case VecVSge::DONE: leaveSgeDone(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswzsk, reenter); break;
			case VecVSge::PRSERR: _ixVSge = enterSgePrserr(dbswzsk, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswzsk, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswzsk, reenter); break;
			case VecVSge::IMPERR: _ixVSge = enterSgeImperr(dbswzsk, reenter); break;
			case VecVSge::REVERSE: _ixVSge = enterSgeReverse(dbswzsk, reenter); break;
			case VecVSge::COLLECT: _ixVSge = enterSgeCollect(dbswzsk, reenter); break;
			case VecVSge::CLTDONE: _ixVSge = enterSgeCltdone(dbswzsk, reenter); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbswzsk, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskIexIni::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing Initialisierungsdaten";
			else if (ixVSge == VecVSge::PRSDONE) retval = "Initialisierungsdaten parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing Initialisierungsdaten (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing Initialisierungsdaten import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting Initialisierungsdaten for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "Initialisierungsdaten collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting Initialisierungsdaten";
		} else if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing Initialisierungsdaten";
			else if (ixVSge == VecVSge::PRSDONE) retval = "Initialisierungsdaten parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing Initialisierungsdaten (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing Initialisierungsdaten import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting Initialisierungsdaten for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "Initialisierungsdaten collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting Initialisierungsdaten";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWzskIexIni::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;
	rectpath = "";

	lineno = 0;
	impcnt = 0;

	icsWzskVIop.clear();

	imeiavcontrolpar.clear();
	imeiavkeylistkey.clear();
	imeiavvaluelistval.clear();
	imeimfile.clear();
	imeimusergroup.clear();

	return retval;
};

void JobWzskIexIni::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskIexIni::enterSgeParse(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWzskIni::parseFromFile(fullpath, xmlNotTxt, rectpath, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimusergroup);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, ixWzskVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWzskIexIni::leaveSgeParse(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWzskIexIni::enterSgePrserr(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWzskIexIni::leaveSgePrserr(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWzskIexIni::enterSgePrsdone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWzskIexIni::leaveSgePrsdone(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWzskIexIni::enterSgeImport(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint num0;

	// IP enterSgeImport.prep --- IBEGIN
	WzskRMUserMUsergroup uru;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIAVKeylistKey
		for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
			klsAkey = imeiavkeylistkey.nodes[ix0];

			klsAkey->klsIxWzskVKeylist = VecWzskVKeylist::getIx(klsAkey->srefKlsIxWzskVKeylist);
			if (klsAkey->klsIxWzskVKeylist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klsAkey->srefKlsIxWzskVKeylist}, {"iel","srefKlsIxWzskVKeylist"}, {"lineno",to_string(klsAkey->lineno)}});
			//klsAkey->klsNum: CUST
			klsAkey->klsNum = num0++; // TBD
			klsAkey->x1IxWzskVMaintable = VecWzskVMaintable::VOID;
			klsAkey->Fixed = true;
			//klsAkey->sref: TBL
			//klsAkey->Avail: TBL
			//klsAkey->Implied: TBL
			//klsAkey->refJ: SUB
			//klsAkey->Title: TBL
			//klsAkey->Comment: TBL

			dbswzsk->tblwzskavkeylistkey->insertRec(klsAkey);
			impcnt++;

			if (((klsAkey->Title != "") || (klsAkey->Comment != "")) && klsAkey->imeijavkeylistkey.nodes.empty()) {
				kakJkey = new ImeitemIJAVKeylistKey();
				kakJkey->lineno = klsAkey->lineno;
				klsAkey->imeijavkeylistkey.nodes.push_back(kakJkey);

				kakJkey->refWzskAVKeylistKey = klsAkey->ref;
				kakJkey->Title = klsAkey->Title;
				kakJkey->Comment = klsAkey->Comment;
			};

			for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

				kakJkey->refWzskAVKeylistKey = klsAkey->ref;
				if (kakJkey->srefX1IxWzskVLocale == "") kakJkey->srefX1IxWzskVLocale = "enus";
				kakJkey->x1IxWzskVLocale = VecWzskVLocale::getIx(kakJkey->srefX1IxWzskVLocale);
				if (kakJkey->x1IxWzskVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",kakJkey->srefX1IxWzskVLocale}, {"iel","srefX1IxWzskVLocale"}, {"lineno",to_string(kakJkey->lineno)}});
				//kakJkey->Title: TBL
				//kakJkey->Comment: TBL

				dbswzsk->tblwzskjavkeylistkey->insertRec(kakJkey);
				impcnt++;

				if (ix1 == 0) {
					klsAkey->refJ = kakJkey->ref;
					klsAkey->Title = kakJkey->Title;
					klsAkey->Comment = kakJkey->Comment;
					dbswzsk->tblwzskavkeylistkey->updateRec(klsAkey);
				};
			};
		};

		// -- ImeIAVValuelistVal
		for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
			vlsAval = imeiavvaluelistval.nodes[ix0];

			vlsAval->vlsIxWzskVValuelist = VecWzskVValuelist::getIx(vlsAval->srefVlsIxWzskVValuelist);
			if (vlsAval->vlsIxWzskVValuelist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefVlsIxWzskVValuelist}, {"iel","srefVlsIxWzskVValuelist"}, {"lineno",to_string(vlsAval->lineno)}});
			//vlsAval->vlsNum: CUST
			vlsAval->vlsNum = num0++; // TBD
			vlsAval->x1IxWzskVLocale = VecWzskVLocale::getIx(vlsAval->srefX1IxWzskVLocale);
			if (vlsAval->x1IxWzskVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefX1IxWzskVLocale}, {"iel","srefX1IxWzskVLocale"}, {"lineno",to_string(vlsAval->lineno)}});
			//vlsAval->Val: TBL

			dbswzsk->tblwzskavvaluelistval->insertRec(vlsAval);
			impcnt++;
		};

		// -- ImeIAVControlPar
		for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
			ctlApar = imeiavcontrolpar.nodes[ix0];

			ctlApar->ixWzskVControl = VecWzskVControl::getIx(ctlApar->srefIxWzskVControl);
			if (ctlApar->ixWzskVControl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ctlApar->srefIxWzskVControl}, {"iel","srefIxWzskVControl"}, {"lineno",to_string(ctlApar->lineno)}});
			//ctlApar->Par: TBL
			//ctlApar->Val: TBL

			dbswzsk->tblwzskavcontrolpar->insertRec(ctlApar);
			impcnt++;
		};

		// -- ImeIMFile
		for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
			fil = imeimfile.nodes[ix0];

			fil->refIxVTbl = VecWzskVMFileRefTbl::VOID;
			//fil->osrefKContent: TBL
			//fil->Filename: TBL
			//fil->srefKMimetype: TBL
			//fil->Comment: TBL

			dbswzsk->tblwzskmfile->insertRec(fil);
			impcnt++;
		};

		// -- ImeIMUsergroup
		for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
			usg = imeimusergroup.nodes[ix0];

			//usg->sref: TBL
			//usg->Comment: TBL

			dbswzsk->tblwzskmusergroup->insertRec(usg);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
				usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

				usgAacc->refWzskMUsergroup = usg->ref;
				usgAacc->x1IxWzskVFeatgroup = VecWzskVFeatgroup::getIx(usgAacc->srefX1IxWzskVFeatgroup);
				if (usgAacc->x1IxWzskVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usgAacc->srefX1IxWzskVFeatgroup}, {"iel","srefX1IxWzskVFeatgroup"}, {"lineno",to_string(usgAacc->lineno)}});
				//usgAacc->x2FeaSrefUix: TBL
				usgAacc->ixWzskWAccess = VecWzskWAccess::getIx(usgAacc->srefsIxWzskWAccess);

				dbswzsk->tblwzskamusergroupaccess->insertRec(usgAacc);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
				usr = usg->imeimuser.nodes[ix1];

				//usr->refRUsergroup: IMPPP
				usr->refWzskMUsergroup = usg->ref;
				//usr->refWzskMPerson: SUB
				//usr->sref: TBL
				//usr->refJState: SUB
				if (usr->srefIxVState != "") {
					usr->ixVState = VecWzskVMUserState::getIx(usr->srefIxVState);
					if (usr->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usr->lineno)}});
				};
				usr->ixWzskVLocale = VecWzskVLocale::getIx(usr->srefIxWzskVLocale);
				if (usr->ixWzskVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxWzskVLocale}, {"iel","srefIxWzskVLocale"}, {"lineno",to_string(usr->lineno)}});
				usr->ixWzskVUserlevel = VecWzskVUserlevel::getIx(usr->srefIxWzskVUserlevel);
				if (usr->ixWzskVUserlevel == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxWzskVUserlevel}, {"iel","srefIxWzskVUserlevel"}, {"lineno",to_string(usr->lineno)}});
				//usr->Password: TBL
				//usr->Comment: TBL

				dbswzsk->tblwzskmuser->insertRec(usr);
				impcnt++;

				if (((usr->srefIxVState != "")) && usr->imeijmuserstate.nodes.empty()) {
					usrJste = new ImeitemIJMUserState();
					usrJste->lineno = usr->lineno;
					usr->imeijmuserstate.nodes.push_back(usrJste);

					usrJste->refWzskMUser = usr->ref;
					usrJste->srefIxVState = usr->srefIxVState;
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
					usrJste = usr->imeijmuserstate.nodes[ix2];

					usrJste->refWzskMUser = usr->ref;
					usrJste->x1Start = Ftm::invstamp("&now;");
					usrJste->ixVState = VecWzskVMUserState::getIx(usrJste->srefIxVState);
					if (usrJste->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrJste->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usrJste->lineno)}});

					dbswzsk->tblwzskjmuserstate->insertRec(usrJste);
					impcnt++;

					if (ix2 == 0) {
						usr->refJState = usrJste->ref;
						usr->ixVState = usrJste->ixVState;
						dbswzsk->tblwzskmuser->updateRec(usr);
					};
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
					prs = usr->imeimperson.nodes[ix2];

					prs->ixWDerivate = VecWzskWMPersonDerivate::USR;
					prs->ixVSex = VecWzskVMPersonSex::getIx(prs->srefIxVSex);
					if (prs->ixVSex == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prs->srefIxVSex}, {"iel","srefIxVSex"}, {"lineno",to_string(prs->lineno)}});
					//prs->Title: TBL
					//prs->Firstname: TBL
					//prs->refJLastname: SUB
					//prs->Lastname: TBL

					dbswzsk->tblwzskmperson->insertRec(prs);
					impcnt++;

					if (((prs->Lastname != "")) && prs->imeijmpersonlastname.nodes.empty()) {
						prsJlnm = new ImeitemIJMPersonLastname();
						prsJlnm->lineno = prs->lineno;
						prs->imeijmpersonlastname.nodes.push_back(prsJlnm);

						prsJlnm->refWzskMPerson = prs->ref;
						prsJlnm->Lastname = prs->Lastname;
					};

					if (ix2 == 0) {
						usr->refWzskMPerson = prs->ref;
						dbswzsk->tblwzskmuser->updateRec(usr);
					};

					for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
						prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

						prsJlnm->refWzskMPerson = prs->ref;
						prsJlnm->x1Startd = Ftm::invdate("&today;");
						//prsJlnm->Lastname: TBL

						dbswzsk->tblwzskjmpersonlastname->insertRec(prsJlnm);
						impcnt++;

						if (ix3 == 0) {
							prs->refJLastname = prsJlnm->ref;
							prs->Lastname = prsJlnm->Lastname;
							dbswzsk->tblwzskmperson->updateRec(prs);
						};
					};
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
					usrAacc = usr->imeiamuseraccess.nodes[ix2];

					usrAacc->refWzskMUser = usr->ref;
					usrAacc->x1IxWzskVFeatgroup = VecWzskVFeatgroup::getIx(usrAacc->srefX1IxWzskVFeatgroup);
					if (usrAacc->x1IxWzskVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrAacc->srefX1IxWzskVFeatgroup}, {"iel","srefX1IxWzskVFeatgroup"}, {"lineno",to_string(usrAacc->lineno)}});
					//usrAacc->x2FeaSrefUix: TBL
					usrAacc->ixWzskWAccess = VecWzskWAccess::getIx(usrAacc->srefsIxWzskWAccess);

					dbswzsk->tblwzskamuseraccess->insertRec(usrAacc);
					impcnt++;
				};

				uru.refWzskMUser = usr->ref;
				uru.refWzskMUsergroup = usg->ref;
				uru.ixWzskVUserlevel = usr->ixWzskVUserlevel;
				dbswzsk->tblwzskrmusermusergroup->insertRec(&uru);

				usr->refRUsergroup = uru.ref;
				usr->refWzskMUsergroup = usg->ref;
				dbswzsk->tblwzskmuser->updateRec(usr);
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- INSERT
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, ixWzskVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWzskIexIni::leaveSgeImport(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWzskIexIni::enterSgeImperr(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWzskIexIni::leaveSgeImperr(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWzskIexIni::enterSgeReverse(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];
		if (ctlApar->ref != 0) dbswzsk->tblwzskavcontrolpar->removeRecByRef(ctlApar->ref);
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];
		if (klsAkey->ref != 0) dbswzsk->tblwzskavkeylistkey->removeRecByRef(klsAkey->ref);

		for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
			kakJkey = klsAkey->imeijavkeylistkey.nodes[ix1];
			if (kakJkey->ref != 0) dbswzsk->tblwzskjavkeylistkey->removeRecByRef(kakJkey->ref);
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];
		if (vlsAval->ref != 0) dbswzsk->tblwzskavvaluelistval->removeRecByRef(vlsAval->ref);
	};

	// -- ImeIMFile
	for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
		fil = imeimfile.nodes[ix0];
		if (fil->ref != 0) dbswzsk->tblwzskmfile->removeRecByRef(fil->ref);
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];
		if (usg->ref != 0) dbswzsk->tblwzskmusergroup->removeRecByRef(usg->ref);

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];
			if (usgAacc->ref != 0) dbswzsk->tblwzskamusergroupaccess->removeRecByRef(usgAacc->ref);
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];
			if (usr->ref != 0) dbswzsk->tblwzskmuser->removeRecByRef(usr->ref);

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];
				if (usrAacc->ref != 0) dbswzsk->tblwzskamuseraccess->removeRecByRef(usrAacc->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];
				if (usrJste->ref != 0) dbswzsk->tblwzskjmuserstate->removeRecByRef(usrJste->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];
				if (prs->ref != 0) dbswzsk->tblwzskmperson->removeRecByRef(prs->ref);

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];
					if (prsJlnm->ref != 0) dbswzsk->tblwzskjmpersonlastname->removeRecByRef(prsJlnm->ref);
				};
			};
		};
	};

	return retval;
};

void JobWzskIexIni::leaveSgeReverse(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWzskIexIni::enterSgeCollect(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint ixWzskVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		if (ctlApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];

		if (klsAkey->ref != 0) {
		};

		if (getIxWzskVIop(icsWzskVIop, VecVIme::IMEIJAVKEYLISTKEY, ixWzskVIop)) {
			dbswzsk->tblwzskjavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
			for (unsigned int i = 0; i < refs.size(); i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbswzsk, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
			kakJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

			if (kakJkey->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMFile
	for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
		fil = imeimfile.nodes[ix0];

		if (fil->ref != 0) {
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxWzskVIop(icsWzskVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixWzskVIop)) {
			dbswzsk->tblwzskamusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbswzsk, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		if (getIxWzskVIop(icsWzskVIop, VecVIme::IMEIMUSER, ixWzskVIop)) {
			dbswzsk->tblwzskmuser->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeimuser.nodes.push_back(new ImeitemIMUser(dbswzsk, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxWzskVIop(icsWzskVIop, VecVIme::IMEIAMUSERACCESS, ixWzskVIop)) {
				dbswzsk->tblwzskamuseraccess->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeiamuseraccess.nodes.push_back(new ImeitemIAMUserAccess(dbswzsk, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];

				if (usrAacc->ref != 0) {
				};
			};

			if (getIxWzskVIop(icsWzskVIop, VecVIme::IMEIJMUSERSTATE, ixWzskVIop)) {
				dbswzsk->tblwzskjmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbswzsk, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxWzskVIop(icsWzskVIop, VecVIme::IMEIJMPERSONLASTNAME, ixWzskVIop)) {
					dbswzsk->tblwzskjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i = 0; i < refs.size(); i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbswzsk, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
					};
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWzskIexIni::leaveSgeCollect(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWzskIexIni::enterSgeCltdone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWzskIexIni::leaveSgeCltdone(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWzskIexIni::enterSgeExport(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWzskIni::exportToFile(fullpath, xmlNotTxt, shorttags, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimusergroup);

	return retval;
};

void JobWzskIexIni::leaveSgeExport(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWzskIexIni::enterSgeDone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWzskIexIni::leaveSgeDone(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeDone --- INSERT
};







