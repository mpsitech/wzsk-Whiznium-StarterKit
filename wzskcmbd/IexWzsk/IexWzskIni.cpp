/**
	* \file IexWzskIni.cpp
	* data blocks and readers/writers for import/export complex IexWzskIni (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "IexWzskIni.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWzskIni::VecVIme
 ******************************************************************************/

uint IexWzskIni::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamuseraccess") return IMEIAMUSERACCESS;
	if (s == "imeiamusergroupaccess") return IMEIAMUSERGROUPACCESS;
	if (s == "imeiavcontrolpar") return IMEIAVCONTROLPAR;
	if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	if (s == "imeiavvaluelistval") return IMEIAVVALUELISTVAL;
	if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;
	if (s == "imeijmuserstate") return IMEIJMUSERSTATE;
	if (s == "imeimfile") return IMEIMFILE;
	if (s == "imeimperson") return IMEIMPERSON;
	if (s == "imeimuser") return IMEIMUSER;
	if (s == "imeimusergroup") return IMEIMUSERGROUP;

	return(0);
};

string IexWzskIni::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMUSERACCESS) return("ImeIAMUserAccess");
	if (ix == IMEIAMUSERGROUPACCESS) return("ImeIAMUsergroupAccess");
	if (ix == IMEIAVCONTROLPAR) return("ImeIAVControlPar");
	if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	if (ix == IMEIAVVALUELISTVAL) return("ImeIAVValuelistVal");
	if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");
	if (ix == IMEIJMUSERSTATE) return("ImeIJMUserState");
	if (ix == IMEIMFILE) return("ImeIMFile");
	if (ix == IMEIMPERSON) return("ImeIMPerson");
	if (ix == IMEIMUSER) return("ImeIMUser");
	if (ix == IMEIMUSERGROUP) return("ImeIMUsergroup");

	return("");
};

/******************************************************************************
 class IexWzskIni::ImeitemIAVControlPar
 ******************************************************************************/

IexWzskIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			const uint ixWzskVControl
			, const string& Par
			, const string& Val
		) : WzskAVControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWzskVControl = ixWzskVControl;
	this->Par = Par;
	this->Val = Val;
};

IexWzskIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIAVControlPar()
		{
	WzskAVControlPar* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskavcontrolpar->loadRecByRef(ref, &rec)) {
		ixWzskVControl = rec->ixWzskVControl;
		Par = rec->Par;
		Val = rec->Val;

		delete rec;
	};
};

void IexWzskIni::ImeitemIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWzskVControl = txtrd.fields[0]; ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXWZSKVCONTROL;};
	if (txtrd.fields.size() > 1) {Par = txtrd.fields[1]; ixWIelValid += ImeIAVControlPar::VecWIel::PAR;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVControlPar::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIAVControlPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWzskVControl", "ctl", srefIxWzskVControl)) ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXWZSKVCONTROL;
		if (extractStringUclc(docctx, basexpath, "Par", "par", Par)) ixWIelValid += ImeIAVControlPar::VecWIel::PAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVControlPar::VecWIel::VAL;
	};
};

void IexWzskIni::ImeitemIAVControlPar::writeTxt(
			fstream& outfile
		) {
	outfile << VecWzskVControl::getSref(ixWzskVControl) << "\t" << Par << "\t" << Val << endl;
};

void IexWzskIni::ImeitemIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ctl","par","val"};
	else tags = {"ImeitemIAVControlPar","srefIxWzskVControl","Par","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzskVControl::getSref(ixWzskVControl));
		writeString(wr, tags[2], Par);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIAVControlPar::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIAVControlPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwzskvcontrol") ix |= SREFIXWZSKVCONTROL;
		else if (ss[i] == "par") ix |= PAR;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWzskIni::ImeIAVControlPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIAVControlPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZSKVCONTROL) ss.push_back("srefIxWzskVControl");
	if (ix & PAR) ss.push_back("Par");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIAVControlPar
 ******************************************************************************/

IexWzskIni::ImeIAVControlPar::ImeIAVControlPar() {
};

IexWzskIni::ImeIAVControlPar::~ImeIAVControlPar() {
	clear();
};

void IexWzskIni::ImeIAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIAVControlPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzskIni::ImeitemIAVControlPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIAVControlPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIAVControlPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVControlPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVControlPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVControlPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIAVControlPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIAVControlPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVControlPar." << StrMod::replaceChar(ImeIAVControlPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVControlPar.end" << endl;
	};
};

void IexWzskIni::ImeIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVControlPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexWzskIni::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			const uint x1IxWzskVLocale
			, const string& Title
			, const string& Comment
		) : WzskJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWzskVLocale = x1IxWzskVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexWzskIni::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey()
		{
	WzskJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskjavkeylistkey->loadRecByRef(ref, &rec)) {
		refWzskAVKeylistKey = rec->refWzskAVKeylistKey;
		x1IxWzskVLocale = rec->x1IxWzskVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzskIni::ImeitemIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWzskVLocale = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::SREFX1IXWZSKVLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWzskVLocale", "lcl", srefX1IxWzskVLocale)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::SREFX1IXWZSKVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexWzskIni::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWzskVLocale::getSref(x1IxWzskVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexWzskIni::ImeitemIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey","srefX1IxWzskVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzskVLocale::getSref(x1IxWzskVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIJAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwzskvlocale") ix |= SREFX1IXWZSKVLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzskIni::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIJAVKeylistKey::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZSKVLOCALE) ss.push_back("srefX1IxWzskVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIJAVKeylistKey
 ******************************************************************************/

IexWzskIni::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexWzskIni::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexWzskIni::ImeIJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWzskIni::ImeitemIJAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIJAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJAVKeylistKey.end" << endl;
	};
};

void IexWzskIni::ImeIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIAVKeylistKey
 ******************************************************************************/

IexWzskIni::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			const uint klsIxWzskVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
			, const string& Title
			, const string& Comment
		) : WzskAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxWzskVKeylist = klsIxWzskVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

IexWzskIni::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey()
		{
	WzskAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxWzskVKeylist = rec->klsIxWzskVKeylist;
		klsNum = rec->klsNum;
		x1IxWzskVMaintable = rec->x1IxWzskVMaintable;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzskIni::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefKlsIxWzskVKeylist = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREFKLSIXWZSKVKEYLIST;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Avail = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 3) {Implied = txtrd.fields[3]; ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;};
	if (txtrd.fields.size() > 4) {Title = txtrd.fields[4]; ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY)) {
					imeijavkeylistkey.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxWzskVKeylist", "kls", srefKlsIxWzskVKeylist)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREFKLSIXWZSKVKEYLIST;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;
		imeijavkeylistkey.readXML(docctx, basexpath);
	};
};

void IexWzskIni::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << VecWzskVKeylist::getSref(klsIxWzskVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexWzskIni::ImeitemIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey","srefKlsIxWzskVKeylist","sref","Avail","Implied","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzskVKeylist::getSref(klsIxWzskVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		writeString(wr, tags[5], Title);
		writeString(wr, tags[6], Comment);
		imeijavkeylistkey.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefklsixwzskvkeylist") ix |= SREFKLSIXWZSKVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "implied") ix |= IMPLIED;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzskIni::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIAVKeylistKey::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXWZSKVKEYLIST) ss.push_back("srefKlsIxWzskVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIAVKeylistKey
 ******************************************************************************/

IexWzskIni::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexWzskIni::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexWzskIni::ImeIAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzskIni::ImeitemIAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVKeylistKey.end" << endl;
	};
};

void IexWzskIni::ImeIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIAVValuelistVal
 ******************************************************************************/

IexWzskIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			const uint vlsIxWzskVValuelist
			, const uint x1IxWzskVLocale
			, const string& Val
		) : WzskAVValuelistVal() {
	lineno = 0;
	ixWIelValid = 0;

	this->vlsIxWzskVValuelist = vlsIxWzskVValuelist;
	this->x1IxWzskVLocale = x1IxWzskVLocale;
	this->Val = Val;
};

IexWzskIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIAVValuelistVal()
		{
	WzskAVValuelistVal* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskavvaluelistval->loadRecByRef(ref, &rec)) {
		vlsIxWzskVValuelist = rec->vlsIxWzskVValuelist;
		vlsNum = rec->vlsNum;
		x1IxWzskVLocale = rec->x1IxWzskVLocale;
		Val = rec->Val;

		delete rec;
	};
};

void IexWzskIni::ImeitemIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefVlsIxWzskVValuelist = txtrd.fields[0]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXWZSKVVALUELIST;};
	if (txtrd.fields.size() > 1) {srefX1IxWzskVLocale = txtrd.fields[1]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXWZSKVLOCALE;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefVlsIxWzskVValuelist", "vls", srefVlsIxWzskVValuelist)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXWZSKVVALUELIST;
		if (extractStringUclc(docctx, basexpath, "srefX1IxWzskVLocale", "lcl", srefX1IxWzskVLocale)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXWZSKVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;
	};
};

void IexWzskIni::ImeitemIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	outfile << VecWzskVValuelist::getSref(vlsIxWzskVValuelist) << "\t" << VecWzskVLocale::getSref(x1IxWzskVLocale) << "\t" << Val << endl;
};

void IexWzskIni::ImeitemIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vls","lcl","val"};
	else tags = {"ImeitemIAVValuelistVal","srefVlsIxWzskVValuelist","srefX1IxWzskVLocale","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzskVValuelist::getSref(vlsIxWzskVValuelist));
		writeString(wr, tags[2], VecWzskVLocale::getSref(x1IxWzskVLocale));
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIAVValuelistVal::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIAVValuelistVal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefvlsixwzskvvaluelist") ix |= SREFVLSIXWZSKVVALUELIST;
		else if (ss[i] == "srefx1ixwzskvlocale") ix |= SREFX1IXWZSKVLOCALE;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWzskIni::ImeIAVValuelistVal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIAVValuelistVal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFVLSIXWZSKVVALUELIST) ss.push_back("srefVlsIxWzskVValuelist");
	if (ix & SREFX1IXWZSKVLOCALE) ss.push_back("srefX1IxWzskVLocale");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIAVValuelistVal
 ******************************************************************************/

IexWzskIni::ImeIAVValuelistVal::ImeIAVValuelistVal() {
};

IexWzskIni::ImeIAVValuelistVal::~ImeIAVValuelistVal() {
	clear();
};

void IexWzskIni::ImeIAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIAVValuelistVal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzskIni::ImeitemIAVValuelistVal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIAVValuelistVal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVValuelistVal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVValuelistVal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVValuelistVal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIAVValuelistVal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVValuelistVal." << StrMod::replaceChar(ImeIAVValuelistVal::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVValuelistVal.end" << endl;
	};
};

void IexWzskIni::ImeIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVValuelistVal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIMFile
 ******************************************************************************/

IexWzskIni::ImeitemIMFile::ImeitemIMFile(
			const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : WzskMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexWzskIni::ImeitemIMFile::ImeitemIMFile(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIMFile()
		{
	WzskMFile* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskmfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzskIni::ImeitemIMFile::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {osrefKContent = txtrd.fields[0]; ixWIelValid += ImeIMFile::VecWIel::OSREFKCONTENT;};
	if (txtrd.fields.size() > 1) {Filename = txtrd.fields[1]; ixWIelValid += ImeIMFile::VecWIel::FILENAME;};
	if (txtrd.fields.size() > 2) {srefKMimetype = txtrd.fields[2]; ixWIelValid += ImeIMFile::VecWIel::SREFKMIMETYPE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMFile::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIMFile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile::VecWIel::COMMENT;
	};
};

void IexWzskIni::ImeitemIMFile::writeTxt(
			fstream& outfile
		) {
	outfile << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexWzskIni::ImeitemIMFile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIMFile::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIMFile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "osrefkcontent") ix |= OSREFKCONTENT;
		else if (ss[i] == "filename") ix |= FILENAME;
		else if (ss[i] == "srefkmimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzskIni::ImeIMFile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIMFile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIMFile
 ******************************************************************************/

IexWzskIni::ImeIMFile::ImeIMFile() {
};

IexWzskIni::ImeIMFile::~ImeIMFile() {
	clear();
};

void IexWzskIni::ImeIMFile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIMFile::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIMFile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzskIni::ImeitemIMFile();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFILE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIMFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIMFile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIMFile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIMFile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFile." << StrMod::replaceChar(ImeIMFile::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMFile.end" << endl;
	};
};

void IexWzskIni::ImeIMFile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIAMUsergroupAccess
 ******************************************************************************/

IexWzskIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			const uint x1IxWzskVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixWzskWAccess
		) : WzskAMUsergroupAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWzskVFeatgroup = x1IxWzskVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzskWAccess = ixWzskWAccess;
};

IexWzskIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIAMUsergroupAccess()
		{
	WzskAMUsergroupAccess* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskamusergroupaccess->loadRecByRef(ref, &rec)) {
		refWzskMUsergroup = rec->refWzskMUsergroup;
		x1IxWzskVFeatgroup = rec->x1IxWzskVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixWzskWAccess = rec->ixWzskWAccess;

		delete rec;
	};
};

void IexWzskIni::ImeitemIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWzskVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXWZSKVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxWzskWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXWZSKWACCESS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWzskVFeatgroup", "feg", srefX1IxWzskVFeatgroup)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXWZSKVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxWzskWAccess", "acc", srefsIxWzskWAccess)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXWZSKWACCESS;
	};
};

void IexWzskIni::ImeitemIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWzskVFeatgroup::getSref(x1IxWzskVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecWzskWAccess::getSrefs(ixWzskWAccess) << endl;
};

void IexWzskIni::ImeitemIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUsergroupAccess","srefX1IxWzskVFeatgroup","x2FeaSrefUix","srefsIxWzskWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzskVFeatgroup::getSref(x1IxWzskVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecWzskWAccess::getSrefs(ixWzskWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIAMUsergroupAccess::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIAMUsergroupAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwzskvfeatgroup") ix |= SREFX1IXWZSKVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixwzskwaccess") ix |= SREFSIXWZSKWACCESS;
	};

	return(ix);
};

void IexWzskIni::ImeIAMUsergroupAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWZSKWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIAMUsergroupAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZSKVFEATGROUP) ss.push_back("srefX1IxWzskVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXWZSKWACCESS) ss.push_back("srefsIxWzskWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIAMUsergroupAccess
 ******************************************************************************/

IexWzskIni::ImeIAMUsergroupAccess::ImeIAMUsergroupAccess() {
};

IexWzskIni::ImeIAMUsergroupAccess::~ImeIAMUsergroupAccess() {
	clear();
};

void IexWzskIni::ImeIAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIAMUsergroupAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWzskIni::ImeitemIAMUsergroupAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIAMUsergroupAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUsergroupAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUsergroupAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUsergroupAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIAMUsergroupAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMUsergroupAccess." << StrMod::replaceChar(ImeIAMUsergroupAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMUsergroupAccess.end" << endl;
	};
};

void IexWzskIni::ImeIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUsergroupAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIAMUserAccess
 ******************************************************************************/

IexWzskIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			const uint x1IxWzskVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixWzskWAccess
		) : WzskAMUserAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWzskVFeatgroup = x1IxWzskVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzskWAccess = ixWzskWAccess;
};

IexWzskIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIAMUserAccess()
		{
	WzskAMUserAccess* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskamuseraccess->loadRecByRef(ref, &rec)) {
		refWzskMUser = rec->refWzskMUser;
		x1IxWzskVFeatgroup = rec->x1IxWzskVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixWzskWAccess = rec->ixWzskWAccess;

		delete rec;
	};
};

void IexWzskIni::ImeitemIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWzskVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXWZSKVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxWzskWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXWZSKWACCESS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWzskVFeatgroup", "feg", srefX1IxWzskVFeatgroup)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXWZSKVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxWzskWAccess", "acc", srefsIxWzskWAccess)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXWZSKWACCESS;
	};
};

void IexWzskIni::ImeitemIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWzskVFeatgroup::getSref(x1IxWzskVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecWzskWAccess::getSrefs(ixWzskWAccess) << endl;
};

void IexWzskIni::ImeitemIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUserAccess","srefX1IxWzskVFeatgroup","x2FeaSrefUix","srefsIxWzskWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzskVFeatgroup::getSref(x1IxWzskVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecWzskWAccess::getSrefs(ixWzskWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIAMUserAccess::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIAMUserAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwzskvfeatgroup") ix |= SREFX1IXWZSKVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixwzskwaccess") ix |= SREFSIXWZSKWACCESS;
	};

	return(ix);
};

void IexWzskIni::ImeIAMUserAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWZSKWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIAMUserAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZSKVFEATGROUP) ss.push_back("srefX1IxWzskVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXWZSKWACCESS) ss.push_back("srefsIxWzskWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIAMUserAccess
 ******************************************************************************/

IexWzskIni::ImeIAMUserAccess::ImeIAMUserAccess() {
};

IexWzskIni::ImeIAMUserAccess::~ImeIAMUserAccess() {
	clear();
};

void IexWzskIni::ImeIAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIAMUserAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWzskIni::ImeitemIAMUserAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIAMUserAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUserAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUserAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUserAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIAMUserAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMUserAccess." << StrMod::replaceChar(ImeIAMUserAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMUserAccess.end" << endl;
	};
};

void IexWzskIni::ImeIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUserAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIJMUserState
 ******************************************************************************/

IexWzskIni::ImeitemIJMUserState::ImeitemIJMUserState(
			const uint ixVState
		) : WzskJMUserState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexWzskIni::ImeitemIJMUserState::ImeitemIJMUserState(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIJMUserState()
		{
	WzskJMUserState* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskjmuserstate->loadRecByRef(ref, &rec)) {
		refWzskMUser = rec->refWzskMUser;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

void IexWzskIni::ImeitemIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVState = txtrd.fields[0]; ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIJMUserState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;
	};
};

void IexWzskIni::ImeitemIJMUserState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWzskVMUserState::getSref(ixVState) << endl;
};

void IexWzskIni::ImeitemIJMUserState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMUserState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzskVMUserState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIJMUserState::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIJMUserState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexWzskIni::ImeIJMUserState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVSTATE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIJMUserState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIJMUserState
 ******************************************************************************/

IexWzskIni::ImeIJMUserState::ImeIJMUserState() {
};

IexWzskIni::ImeIJMUserState::~ImeIJMUserState() {
	clear();
};

void IexWzskIni::ImeIJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIJMUserState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWzskIni::ImeitemIJMUserState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIJMUserState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIJMUserState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMUserState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMUserState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMUserState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIJMUserState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIJMUserState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMUserState." << StrMod::replaceChar(ImeIJMUserState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMUserState.end" << endl;
	};
};

void IexWzskIni::ImeIJMUserState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMUserState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIJMPersonLastname
 ******************************************************************************/

IexWzskIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : WzskJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexWzskIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIJMPersonLastname()
		{
	WzskJMPersonLastname* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskjmpersonlastname->loadRecByRef(ref, &rec)) {
		refWzskMPerson = rec->refWzskMPerson;
		x1Startd = rec->x1Startd;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexWzskIni::ImeitemIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Lastname = txtrd.fields[0]; ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexWzskIni::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Lastname << endl;
};

void IexWzskIni::ImeitemIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lnm"};
	else tags = {"ImeitemIJMPersonLastname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Lastname);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIJMPersonLastname::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexWzskIni::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIJMPersonLastname
 ******************************************************************************/

IexWzskIni::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexWzskIni::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexWzskIni::ImeIJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWzskIni::ImeitemIJMPersonLastname();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIJMPersonLastname* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPersonLastname");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPersonLastname", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPersonLastname";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMPersonLastname.end" << endl;
	};
};

void IexWzskIni::ImeIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPersonLastname");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIMPerson
 ******************************************************************************/

IexWzskIni::ImeitemIMPerson::ImeitemIMPerson(
			const uint ixVSex
			, const string& Title
			, const string& Firstname
			, const string& Lastname
		) : WzskMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
};

IexWzskIni::ImeitemIMPerson::ImeitemIMPerson(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIMPerson()
		{
	WzskMPerson* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskmperson->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexWzskIni::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVSex = txtrd.fields[0]; ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMPerson::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Firstname = txtrd.fields[2]; ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;};
	if (txtrd.fields.size() > 3) {Lastname = txtrd.fields[3]; ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
					imeijmpersonlastname.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;
		imeijmpersonlastname.readXML(docctx, basexpath);
	};
};

void IexWzskIni::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWzskVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << "\t" << Lastname << endl;
	imeijmpersonlastname.writeTxt(outfile);
};

void IexWzskIni::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sex","tit","fnm","lnm"};
	else tags = {"ImeitemIMPerson","srefIxVSex","Title","Firstname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzskVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Firstname);
		writeString(wr, tags[4], Lastname);
		imeijmpersonlastname.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvsex") ix |= SREFIXVSEX;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "firstname") ix |= FIRSTNAME;
		else if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexWzskIni::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");
	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIMPerson
 ******************************************************************************/

IexWzskIni::ImeIMPerson::ImeIMPerson() {
};

IexWzskIni::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexWzskIni::ImeIMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWzskIni::ImeitemIMPerson();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPERSON) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPerson.end" << endl;
	};
};

void IexWzskIni::ImeIMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPerson");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIMUser
 ******************************************************************************/

IexWzskIni::ImeitemIMUser::ImeitemIMUser(
			const string& sref
			, const uint ixVState
			, const uint ixWzskVLocale
			, const uint ixWzskVUserlevel
			, const string& Password
			, const string& Comment
		) : WzskMUser() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixVState = ixVState;
	this->ixWzskVLocale = ixWzskVLocale;
	this->ixWzskVUserlevel = ixWzskVUserlevel;
	this->Password = Password;
	this->Comment = Comment;
};

IexWzskIni::ImeitemIMUser::ImeitemIMUser(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIMUser()
		{
	WzskMUser* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskmuser->loadRecByRef(ref, &rec)) {
		refRUsergroup = rec->refRUsergroup;
		refWzskMUsergroup = rec->refWzskMUsergroup;
		refWzskMPerson = rec->refWzskMPerson;
		sref = rec->sref;
		refJState = rec->refJState;
		ixVState = rec->ixVState;
		ixWzskVLocale = rec->ixWzskVLocale;
		ixWzskVUserlevel = rec->ixWzskVUserlevel;
		Password = rec->Password;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzskIni::ImeitemIMUser::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUser::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxVState = txtrd.fields[1]; ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;};
	if (txtrd.fields.size() > 2) {srefIxWzskVLocale = txtrd.fields[2]; ixWIelValid += ImeIMUser::VecWIel::SREFIXWZSKVLOCALE;};
	if (txtrd.fields.size() > 3) {srefIxWzskVUserlevel = txtrd.fields[3]; ixWIelValid += ImeIMUser::VecWIel::SREFIXWZSKVUSERLEVEL;};
	if (txtrd.fields.size() > 4) {Password = txtrd.fields[4]; ixWIelValid += ImeIMUser::VecWIel::PASSWORD;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMUser::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS)) {
					imeiamuseraccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE)) {
					imeijmuserstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPERSON)) {
					imeimperson.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIMUser::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUser::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;
		if (extractStringUclc(docctx, basexpath, "srefIxWzskVLocale", "lcl", srefIxWzskVLocale)) ixWIelValid += ImeIMUser::VecWIel::SREFIXWZSKVLOCALE;
		if (extractStringUclc(docctx, basexpath, "srefIxWzskVUserlevel", "ulv", srefIxWzskVUserlevel)) ixWIelValid += ImeIMUser::VecWIel::SREFIXWZSKVUSERLEVEL;
		if (extractStringUclc(docctx, basexpath, "Password", "pwd", Password)) ixWIelValid += ImeIMUser::VecWIel::PASSWORD;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUser::VecWIel::COMMENT;
		imeiamuseraccess.readXML(docctx, basexpath);
		imeijmuserstate.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
	};
};

void IexWzskIni::ImeitemIMUser::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecWzskVMUserState::getSref(ixVState) << "\t" << VecWzskVLocale::getSref(ixWzskVLocale) << "\t" << VecWzskVUserlevel::getSref(ixWzskVUserlevel) << "\t" << Password << "\t" << Comment << endl;
	imeiamuseraccess.writeTxt(outfile);
	imeijmuserstate.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
};

void IexWzskIni::ImeitemIMUser::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","ste","lcl","ulv","pwd","cmt"};
	else tags = {"ImeitemIMUser","sref","srefIxVState","srefIxWzskVLocale","srefIxWzskVUserlevel","Password","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWzskVMUserState::getSref(ixVState));
		writeString(wr, tags[3], VecWzskVLocale::getSref(ixWzskVLocale));
		writeString(wr, tags[4], VecWzskVUserlevel::getSref(ixWzskVUserlevel));
		writeString(wr, tags[5], Password);
		writeString(wr, tags[6], Comment);
		imeiamuseraccess.writeXML(wr, shorttags);
		imeijmuserstate.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIMUser::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIMUser::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
		else if (ss[i] == "srefixwzskvlocale") ix |= SREFIXWZSKVLOCALE;
		else if (ss[i] == "srefixwzskvuserlevel") ix |= SREFIXWZSKVUSERLEVEL;
		else if (ss[i] == "password") ix |= PASSWORD;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzskIni::ImeIMUser::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIMUser::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");
	if (ix & SREFIXWZSKVLOCALE) ss.push_back("srefIxWzskVLocale");
	if (ix & SREFIXWZSKVUSERLEVEL) ss.push_back("srefIxWzskVUserlevel");
	if (ix & PASSWORD) ss.push_back("Password");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIMUser
 ******************************************************************************/

IexWzskIni::ImeIMUser::ImeIMUser() {
};

IexWzskIni::ImeIMUser::~ImeIMUser() {
	clear();
};

void IexWzskIni::ImeIMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIMUser::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIMUser* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWzskIni::ImeitemIMUser();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSER) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIMUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIMUser* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUser");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUser", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUser";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIMUser();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIMUser::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMUser." << StrMod::replaceChar(ImeIMUser::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMUser.end" << endl;
	};
};

void IexWzskIni::ImeIMUser::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUser");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzskIni::ImeitemIMUsergroup
 ******************************************************************************/

IexWzskIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			const string& sref
			, const string& Comment
		) : WzskMUsergroup() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWzskIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			DbsWzsk* dbswzsk
			, const ubigint ref
		) :
			ImeitemIMUsergroup()
		{
	WzskMUsergroup* rec = NULL;

	this->ref = ref;

	if (dbswzsk->tblwzskmusergroup->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzskIni::ImeitemIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUsergroup::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS)) {
					imeiamusergroupaccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMUSER)) {
					imeimuser.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzskIni::ImeitemIMUsergroup::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUsergroup::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;
		imeiamusergroupaccess.readXML(docctx, basexpath);
		imeimuser.readXML(docctx, basexpath);
	};
};

void IexWzskIni::ImeitemIMUsergroup::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
	imeiamusergroupaccess.writeTxt(outfile);
	imeimuser.writeTxt(outfile);
};

void IexWzskIni::ImeitemIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMUsergroup","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamusergroupaccess.writeXML(wr, shorttags);
		imeimuser.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzskIni::ImeIMUsergroup::VecWIel
 ******************************************************************************/

uint IexWzskIni::ImeIMUsergroup::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzskIni::ImeIMUsergroup::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzskIni::ImeIMUsergroup::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzskIni::ImeIMUsergroup
 ******************************************************************************/

IexWzskIni::ImeIMUsergroup::ImeIMUsergroup() {
};

IexWzskIni::ImeIMUsergroup::~ImeIMUsergroup() {
	clear();
};

void IexWzskIni::ImeIMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzskIni::ImeIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	IexWzskIni::ImeitemIMUsergroup* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzskIni::ImeitemIMUsergroup();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzskIni::ImeIMUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzskIni::ImeitemIMUsergroup* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUsergroup");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUsergroup", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUsergroup";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzskIni::ImeitemIMUsergroup();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzskIni::ImeIMUsergroup::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUsergroup." << StrMod::replaceChar(ImeIMUsergroup::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUsergroup.end" << endl;
	};
};

void IexWzskIni::ImeIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUsergroup");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWzskIni
 ******************************************************************************/

void IexWzskIni::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimusergroup);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWzskIni", Version(""), VecVIme::getIx);
			readTxt(rd, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimusergroup);
	};
};

void IexWzskIni::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimusergroup);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimfile, imeimusergroup);
		txtfile.close();
	};
};

void IexWzskIni::readTxt(
			Txtrd& txtrd
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMUsergroup& imeimusergroup
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR)) imeiavcontrolpar.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY)) imeiavkeylistkey.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL)) imeiavvaluelistval.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMFILE)) imeimfile.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP)) imeimusergroup.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWzskIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMUsergroup& imeimusergroup
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWzskIni")) {

		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimfile.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);

	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey = ImeIAVKeylistKey();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimfile = ImeIMFile();
		imeimusergroup = ImeIMUsergroup();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWzskIni"}});
	};
};

void IexWzskIni::writeTxt(
			fstream& outfile
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMUsergroup& imeimusergroup
		) {
	outfile << "IexWzskIni v" WZSK_VERSION << endl;

	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimfile.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexWzskIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMFile& imeimfile
			, ImeIMUsergroup& imeimusergroup
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWzskIni");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZSK_VERSION);

		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimfile.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWzskIni::icsWzskVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMUSERACCESS,VecWzskVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecWzskVIop::INS},{(uint)VecVIme::IMEIAVCONTROLPAR,VecWzskVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecWzskVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecWzskVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecWzskVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecWzskVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecWzskVIop::INS},{(uint)VecVIme::IMEIMFILE,VecWzskVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecWzskVIop::INS},{(uint)VecVIme::IMEIMUSER,VecWzskVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecWzskVIop::INS}};
};

uint IexWzskIni::getIxWzskVIop(
			const map<uint,uint>& icsWzskVIop
			, const uint ixVIme
			, uint& ixWzskVIop
		) {
	ixWzskVIop = 0;

	auto it = icsWzskVIop.find(ixVIme);
	if (it != icsWzskVIop.end()) ixWzskVIop = it->second;

	return ixWzskVIop;
};

