/**
	* \file VecWzskVError.cpp
	* vector VecWzskVError (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "VecWzskVError.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVError
 ******************************************************************************/

uint VecWzskVError::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dbs.conn") return DBS_CONN;
	if (s == "dbs.query") return DBS_QUERY;
	if (s == "dbs.stmtexec") return DBS_STMTEXEC;
	if (s == "dbs.stmtprep") return DBS_STMTPREP;
	if (s == "engconn") return ENGCONN;
	if (s == "iex.filetype") return IEX_FILETYPE;
	if (s == "iex.ftm") return IEX_FTM;
	if (s == "iex.iarg") return IEX_IARG;
	if (s == "iex.idiref") return IEX_IDIREF;
	if (s == "iex.iop") return IEX_IOP;
	if (s == "iex.iref") return IEX_IREF;
	if (s == "iex.retr") return IEX_RETR;
	if (s == "iex.thint") return IEX_THINT;
	if (s == "iex.thsref") return IEX_THSREF;
	if (s == "iex.tsref") return IEX_TSREF;
	if (s == "iex.version") return IEX_VERSION;
	if (s == "iex.vsref") return IEX_VSREF;
	if (s == "pathnf") return PATHNF;
	if (s == "txtrd.content") return TXTRD_CONTENT;
	if (s == "txtrd.endtkn") return TXTRD_ENDTKN;
	if (s == "txtrd.tknmispl") return TXTRD_TKNMISPL;
	if (s == "txtrd.tknunid") return TXTRD_TKNUNID;
	if (s == "xmlio.bufparse") return XMLIO_BUFPARSE;
	if (s == "xmlio.fileparse") return XMLIO_FILEPARSE;
	if (s == "gpio") return GPIO;
	if (s == "pwm") return PWM;
	if (s == "spidev") return SPIDEV;
	if (s == "v4l2") return V4L2;

	return(0);
};

string VecWzskVError::getSref(
			const uint ix
		) {
	if (ix == DBS_CONN) return("dbs.conn");
	if (ix == DBS_QUERY) return("dbs.query");
	if (ix == DBS_STMTEXEC) return("dbs.stmtexec");
	if (ix == DBS_STMTPREP) return("dbs.stmtprep");
	if (ix == ENGCONN) return("engconn");
	if (ix == IEX_FILETYPE) return("iex.filetype");
	if (ix == IEX_FTM) return("iex.ftm");
	if (ix == IEX_IARG) return("iex.iarg");
	if (ix == IEX_IDIREF) return("iex.idiref");
	if (ix == IEX_IOP) return("iex.iop");
	if (ix == IEX_IREF) return("iex.iref");
	if (ix == IEX_RETR) return("iex.retr");
	if (ix == IEX_THINT) return("iex.thint");
	if (ix == IEX_THSREF) return("iex.thsref");
	if (ix == IEX_TSREF) return("iex.tsref");
	if (ix == IEX_VERSION) return("iex.version");
	if (ix == IEX_VSREF) return("iex.vsref");
	if (ix == PATHNF) return("pathnf");
	if (ix == TXTRD_CONTENT) return("txtrd.content");
	if (ix == TXTRD_ENDTKN) return("txtrd.endtkn");
	if (ix == TXTRD_TKNMISPL) return("txtrd.tknmispl");
	if (ix == TXTRD_TKNUNID) return("txtrd.tknunid");
	if (ix == XMLIO_BUFPARSE) return("xmlio.bufparse");
	if (ix == XMLIO_FILEPARSE) return("xmlio.fileparse");
	if (ix == GPIO) return("gpio");
	if (ix == PWM) return("pwm");
	if (ix == SPIDEV) return("spidev");
	if (ix == V4L2) return("v4l2");

	return("");
};

string VecWzskVError::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == DBS_CONN) return("database connection failure: &dbms;");
		if (ix == DBS_QUERY) return("error executing SQL query '&sql;': &dbms;");
		if (ix == DBS_STMTEXEC) return("error executing statement: &dbms;");
		if (ix == DBS_STMTPREP) return("error preparing SQL statement '&sql;': &dbms;");
		if (ix == ENGCONN) return("error connecting to engine");
		if (ix == IEX_FILETYPE) return("not a &iexsref; file");
		if (ix == IEX_FTM) return("time stamp/date/time format '&ftm;' invalid for import column &iel; in line &lineno;");
		if (ix == IEX_IARG) return("argument '&iarg;' for custom import invalid for import column &iel; in line &lineno;");
		if (ix == IEX_IDIREF) return("duplicate identifying integer reference &idiref; for import &ime; in line &lineno;");
		if (ix == IEX_IOP) return("invalid import operation &iop; for import &ime; in line &lineno;");
		if (ix == IEX_IREF) return("integer reference &iref; not resolved for import column &iel; in line &lineno;");
		if (ix == IEX_RETR) return("record can't be retrieved for import &ime; based on information in line &lineno;");
		if (ix == IEX_THINT) return("textual hint '&thint;' for table reference not resolved for import column &iel; in line &lineno;");
		if (ix == IEX_THSREF) return("hierarchical string reference '&thsref;' to table not resolved for import column &iel; in line &lineno;");
		if (ix == IEX_TSREF) return("string reference '&tsref;' to table not resolved for import column &iel; in line &lineno;");
		if (ix == IEX_VERSION) return("version &version; incompatible, minimum is &minversion;");
		if (ix == IEX_VSREF) return("string reference '&vsref;' to vector item not resolved for import column &iel; in line &lineno;");
		if (ix == PATHNF) return("path '&path;' not found");
		if (ix == TXTRD_CONTENT) return("misplaced content in line &lineno;");
		if (ix == TXTRD_ENDTKN) return("missing &ime;.end token in line &lineno;");
		if (ix == TXTRD_TKNMISPL) return("misplaced token '&tkn;' in line &lineno;");
		if (ix == TXTRD_TKNUNID) return("unidentified token '&tkn;' in line &lineno;");
		if (ix == XMLIO_BUFPARSE) return("error parsing XML buffer");
		if (ix == XMLIO_FILEPARSE) return("error parsing XML file");
		if (ix == GPIO) return("GPIO subsystem: &msg;");
		if (ix == PWM) return("PWM subsystem: &msg;");
		if (ix == SPIDEV) return("SPI subsystem: &msg;");
		if (ix == V4L2) return("V4L2 subsystem: &msg;");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == DBS_CONN) return("database connection failure: &dbms;");
		if (ix == DBS_QUERY) return("error executing SQL query '&sql;': &dbms;");
		if (ix == DBS_STMTEXEC) return("error executing statement: &dbms;");
		if (ix == DBS_STMTPREP) return("error preparing SQL statement '&sql;': &dbms;");
		if (ix == ENGCONN) return("Fehler beim Verbinden zur Engine");
		if (ix == IEX_FILETYPE) return("keine &iexsref; Datei");
		if (ix == IEX_FTM) return("Zeitstempel/Datum/Uhrzeit-Format '&ftm;' ung\\u00fcltig f\\u00fcr Importspalte &iel; in Zeile &lineno;");
		if (ix == IEX_IARG) return("Argument '&iarg;' zum spezifischen Import ung\\u00fcltig f\\u00fcr Importspalte &iel; in Zeile &lineno;");
		if (ix == IEX_IDIREF) return("doppelte Integer-ID-Referenz &idiref; f\\u00fcr Import &ime; in Zeile &lineno;");
		if (ix == IEX_IOP) return("ung\\u00fcltige Import-Operation &iop; f\\u00fcr Import &ime; in Zeile &lineno;");
		if (ix == IEX_IREF) return("Integer-Referenz &iref; nicht aufgel\\u00f6st f\\u00fcr Importspalte &iel; in Zeile &lineno;");
		if (ix == IEX_RETR) return("Datensatz nicht auffindbar f\\u00fcr Import &ime; und Informationen in Zeile &lineno;");
		if (ix == IEX_THINT) return("Text-Hinweis '&thint;' f\\u00fcr Tabellen-Referenz nicht aufgel\\u00f6st f\\u00fcr Importspalte &iel; in Zeile &lineno;");
		if (ix == IEX_THSREF) return("hierarchische String-Referenz '&thsref;' auf Tabelle nicht aufgel\\u00f6st f\\u00fcr Importspalte &iel; in Zeile &lineno;");
		if (ix == IEX_TSREF) return("String-Referenz '&tsref;' auf Tabelle nicht aufgel\\u00f6st f\\u00fcr Importspalte &iel; in Zeile &lineno;");
		if (ix == IEX_VERSION) return("Version &version; inkompatibel, Minimum ist &minversion;");
		if (ix == IEX_VSREF) return("String-Referenz '&vsref;' auf Vektoreintrag nicht aufgel\\u00f6st f\\u00fcr Importspalte &iel; in Zeile &lineno;");
		if (ix == PATHNF) return("Pfad '&path;' nicht gefunden");
		if (ix == TXTRD_CONTENT) return("fehlplatzierter Inhalt in Zeile &lineno;");
		if (ix == TXTRD_ENDTKN) return("fehlendes &ime;.end-Token in Zeile &lineno;");
		if (ix == TXTRD_TKNMISPL) return("fehlplatziertes Token '&tkn;' in Zeile &lineno;");
		if (ix == TXTRD_TKNUNID) return("unbekanntes Token '&tkn;' in Zeile &lineno;");
		if (ix == XMLIO_BUFPARSE) return("Fehler beim Parsen von XML-Buffer");
		if (ix == XMLIO_FILEPARSE) return("Fehler beim Parsen von XML-Datei");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecWzskVError::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 28; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

