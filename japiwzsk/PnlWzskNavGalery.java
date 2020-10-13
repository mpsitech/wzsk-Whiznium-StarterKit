/**
  * \file PnlWzskNavGalery.java
  * Java API code for job PnlWzskNavGalery
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskNavGalery {
	/**
		* VecVDo (full: VecVWzskNavGaleryDo)
		*/
	public static class VecVDo {

		public static final int BUTOGRVIEWCLICK = 1;
		public static final int BUTOGRNEWCRDCLICK = 2;
		public static final int BUTOBJVIEWCLICK = 3;
		public static final int BUTOBJNEWCRDCLICK = 4;
		public static final int BUTSESVIEWCLICK = 5;
		public static final int BUTSESNEWCRDCLICK = 6;
		public static final int BUTSHTVIEWCLICK = 7;
		public static final int BUTSHTNEWCRDCLICK = 8;
		public static final int BUTFILVIEWCLICK = 9;
		public static final int BUTFILNEWCRDCLICK = 10;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butogrviewclick")) return BUTOGRVIEWCLICK;
			if (s.equals("butogrnewcrdclick")) return BUTOGRNEWCRDCLICK;
			if (s.equals("butobjviewclick")) return BUTOBJVIEWCLICK;
			if (s.equals("butobjnewcrdclick")) return BUTOBJNEWCRDCLICK;
			if (s.equals("butsesviewclick")) return BUTSESVIEWCLICK;
			if (s.equals("butsesnewcrdclick")) return BUTSESNEWCRDCLICK;
			if (s.equals("butshtviewclick")) return BUTSHTVIEWCLICK;
			if (s.equals("butshtnewcrdclick")) return BUTSHTNEWCRDCLICK;
			if (s.equals("butfilviewclick")) return BUTFILVIEWCLICK;
			if (s.equals("butfilnewcrdclick")) return BUTFILNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTOGRVIEWCLICK) return("ButOgrViewClick");
			if (ix == BUTOGRNEWCRDCLICK) return("ButOgrNewcrdClick");
			if (ix == BUTOBJVIEWCLICK) return("ButObjViewClick");
			if (ix == BUTOBJNEWCRDCLICK) return("ButObjNewcrdClick");
			if (ix == BUTSESVIEWCLICK) return("ButSesViewClick");
			if (ix == BUTSESNEWCRDCLICK) return("ButSesNewcrdClick");
			if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");
			if (ix == BUTSHTNEWCRDCLICK) return("ButShtNewcrdClick");
			if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
			if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskNavGalery)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTOGR = 1;
		public static final int NUMFLSTOBJ = 2;
		public static final int NUMFLSTSES = 3;
		public static final int NUMFLSTSHT = 4;
		public static final int NUMFLSTFIL = 5;

		public ContIac(
					int numFLstOgr
					, int numFLstObj
					, int numFLstSes
					, int numFLstSht
					, int numFLstFil
				) {
			this.numFLstOgr = numFLstOgr;
			this.numFLstObj = numFLstObj;
			this.numFLstSes = numFLstSes;
			this.numFLstSht = numFLstSht;
			this.numFLstFil = numFLstFil;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTOGR, NUMFLSTOBJ, NUMFLSTSES, NUMFLSTSHT, NUMFLSTFIL));
		};

		public int numFLstOgr;
		public int numFLstObj;
		public int numFLstSes;
		public int numFLstSht;
		public int numFLstFil;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskNavGalery");

			String itemtag = "ContitemIacWzskNavGalery";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstOgr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstOgr", mask, NUMFLSTOGR);
				numFLstObj = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstObj", mask, NUMFLSTOBJ);
				numFLstSes = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSes", mask, NUMFLSTSES);
				numFLstSht = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSht", mask, NUMFLSTSHT);
				numFLstFil = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstFil", mask, NUMFLSTFIL);

				return true;
			};

			return false;
		};

		public void writeXML(
					Document doc
					, Element sup
					, String difftag
					, boolean shorttags
				) {
			if (difftag.isEmpty()) difftag = "ContIacWzskNavGalery";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskNavGalery";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstOgr", numFLstOgr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstObj", numFLstObj);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSes", numFLstSes);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSht", numFLstSht);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstFil", numFLstFil);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstOgr == comp.numFLstOgr) items.add(NUMFLSTOGR);
			if (numFLstObj == comp.numFLstObj) items.add(NUMFLSTOBJ);
			if (numFLstSes == comp.numFLstSes) items.add(NUMFLSTSES);
			if (numFLstSht == comp.numFLstSht) items.add(NUMFLSTSHT);
			if (numFLstFil == comp.numFLstFil) items.add(NUMFLSTFIL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTOGR, NUMFLSTOBJ, NUMFLSTSES, NUMFLSTSHT, NUMFLSTFIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWzskNavGalery)
	  */
	public class StatApp extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int LSTOGRALT = 2;
		public static final int LSTOBJALT = 3;
		public static final int LSTSESALT = 4;
		public static final int LSTSHTALT = 5;
		public static final int LSTFILALT = 6;
		public static final int LSTOGRNUMFIRSTDISP = 7;
		public static final int LSTOBJNUMFIRSTDISP = 8;
		public static final int LSTSESNUMFIRSTDISP = 9;
		public static final int LSTSHTNUMFIRSTDISP = 10;
		public static final int LSTFILNUMFIRSTDISP = 11;

		public StatApp(
					int ixWzskVExpstate
					, boolean LstOgrAlt
					, boolean LstObjAlt
					, boolean LstSesAlt
					, boolean LstShtAlt
					, boolean LstFilAlt
					, int LstOgrNumFirstdisp
					, int LstObjNumFirstdisp
					, int LstSesNumFirstdisp
					, int LstShtNumFirstdisp
					, int LstFilNumFirstdisp
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.LstOgrAlt = LstOgrAlt;
			this.LstObjAlt = LstObjAlt;
			this.LstSesAlt = LstSesAlt;
			this.LstShtAlt = LstShtAlt;
			this.LstFilAlt = LstFilAlt;
			this.LstOgrNumFirstdisp = LstOgrNumFirstdisp;
			this.LstObjNumFirstdisp = LstObjNumFirstdisp;
			this.LstSesNumFirstdisp = LstSesNumFirstdisp;
			this.LstShtNumFirstdisp = LstShtNumFirstdisp;
			this.LstFilNumFirstdisp = LstFilNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, LSTOGRALT, LSTOBJALT, LSTSESALT, LSTSHTALT, LSTFILALT, LSTOGRNUMFIRSTDISP, LSTOBJNUMFIRSTDISP, LSTSESNUMFIRSTDISP, LSTSHTNUMFIRSTDISP, LSTFILNUMFIRSTDISP));
		};

		public int ixWzskVExpstate;
		public boolean LstOgrAlt;
		public boolean LstObjAlt;
		public boolean LstSesAlt;
		public boolean LstShtAlt;
		public boolean LstFilAlt;
		public int LstOgrNumFirstdisp;
		public int LstObjNumFirstdisp;
		public int LstSesNumFirstdisp;
		public int LstShtNumFirstdisp;
		public int LstFilNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskNavGalery");

			String itemtag = "StatitemAppWzskNavGalery";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				LstOgrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOgrAlt", mask, LSTOGRALT);
				LstObjAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstObjAlt", mask, LSTOBJALT);
				LstSesAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSesAlt", mask, LSTSESALT);
				LstShtAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstShtAlt", mask, LSTSHTALT);
				LstFilAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilAlt", mask, LSTFILALT);
				LstOgrNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOgrNumFirstdisp", mask, LSTOGRNUMFIRSTDISP);
				LstObjNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstObjNumFirstdisp", mask, LSTOBJNUMFIRSTDISP);
				LstSesNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSesNumFirstdisp", mask, LSTSESNUMFIRSTDISP);
				LstShtNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstShtNumFirstdisp", mask, LSTSHTNUMFIRSTDISP);
				LstFilNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilNumFirstdisp", mask, LSTFILNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVExpstate == comp.ixWzskVExpstate) items.add(IXWZSKVEXPSTATE);
			if (LstOgrAlt == comp.LstOgrAlt) items.add(LSTOGRALT);
			if (LstObjAlt == comp.LstObjAlt) items.add(LSTOBJALT);
			if (LstSesAlt == comp.LstSesAlt) items.add(LSTSESALT);
			if (LstShtAlt == comp.LstShtAlt) items.add(LSTSHTALT);
			if (LstFilAlt == comp.LstFilAlt) items.add(LSTFILALT);
			if (LstOgrNumFirstdisp == comp.LstOgrNumFirstdisp) items.add(LSTOGRNUMFIRSTDISP);
			if (LstObjNumFirstdisp == comp.LstObjNumFirstdisp) items.add(LSTOBJNUMFIRSTDISP);
			if (LstSesNumFirstdisp == comp.LstSesNumFirstdisp) items.add(LSTSESNUMFIRSTDISP);
			if (LstShtNumFirstdisp == comp.LstShtNumFirstdisp) items.add(LSTSHTNUMFIRSTDISP);
			if (LstFilNumFirstdisp == comp.LstFilNumFirstdisp) items.add(LSTFILNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, LSTOGRALT, LSTOBJALT, LSTSESALT, LSTSHTALT, LSTFILALT, LSTOGRNUMFIRSTDISP, LSTOBJNUMFIRSTDISP, LSTSESNUMFIRSTDISP, LSTSHTNUMFIRSTDISP, LSTFILNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskNavGalery)
	  */
	public class StatShr extends Block {

		public static final int LSTOGRAVAIL = 1;
		public static final int BUTOGRVIEWACTIVE = 2;
		public static final int LSTOBJAVAIL = 3;
		public static final int BUTOBJVIEWACTIVE = 4;
		public static final int LSTSESAVAIL = 5;
		public static final int BUTSESVIEWACTIVE = 6;
		public static final int LSTSHTAVAIL = 7;
		public static final int BUTSHTVIEWACTIVE = 8;
		public static final int LSTFILAVAIL = 9;
		public static final int BUTFILVIEWACTIVE = 10;

		public StatShr(
					boolean LstOgrAvail
					, boolean ButOgrViewActive
					, boolean LstObjAvail
					, boolean ButObjViewActive
					, boolean LstSesAvail
					, boolean ButSesViewActive
					, boolean LstShtAvail
					, boolean ButShtViewActive
					, boolean LstFilAvail
					, boolean ButFilViewActive
				) {
			this.LstOgrAvail = LstOgrAvail;
			this.ButOgrViewActive = ButOgrViewActive;
			this.LstObjAvail = LstObjAvail;
			this.ButObjViewActive = ButObjViewActive;
			this.LstSesAvail = LstSesAvail;
			this.ButSesViewActive = ButSesViewActive;
			this.LstShtAvail = LstShtAvail;
			this.ButShtViewActive = ButShtViewActive;
			this.LstFilAvail = LstFilAvail;
			this.ButFilViewActive = ButFilViewActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTOGRAVAIL, BUTOGRVIEWACTIVE, LSTOBJAVAIL, BUTOBJVIEWACTIVE, LSTSESAVAIL, BUTSESVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE));
		};

		public boolean LstOgrAvail;
		public boolean ButOgrViewActive;
		public boolean LstObjAvail;
		public boolean ButObjViewActive;
		public boolean LstSesAvail;
		public boolean ButSesViewActive;
		public boolean LstShtAvail;
		public boolean ButShtViewActive;
		public boolean LstFilAvail;
		public boolean ButFilViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskNavGalery");

			String itemtag = "StatitemShrWzskNavGalery";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstOgrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOgrAvail", mask, LSTOGRAVAIL);
				ButOgrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOgrViewActive", mask, BUTOGRVIEWACTIVE);
				LstObjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstObjAvail", mask, LSTOBJAVAIL);
				ButObjViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButObjViewActive", mask, BUTOBJVIEWACTIVE);
				LstSesAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSesAvail", mask, LSTSESAVAIL);
				ButSesViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSesViewActive", mask, BUTSESVIEWACTIVE);
				LstShtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstShtAvail", mask, LSTSHTAVAIL);
				ButShtViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButShtViewActive", mask, BUTSHTVIEWACTIVE);
				LstFilAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilAvail", mask, LSTFILAVAIL);
				ButFilViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFilViewActive", mask, BUTFILVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstOgrAvail == comp.LstOgrAvail) items.add(LSTOGRAVAIL);
			if (ButOgrViewActive == comp.ButOgrViewActive) items.add(BUTOGRVIEWACTIVE);
			if (LstObjAvail == comp.LstObjAvail) items.add(LSTOBJAVAIL);
			if (ButObjViewActive == comp.ButObjViewActive) items.add(BUTOBJVIEWACTIVE);
			if (LstSesAvail == comp.LstSesAvail) items.add(LSTSESAVAIL);
			if (ButSesViewActive == comp.ButSesViewActive) items.add(BUTSESVIEWACTIVE);
			if (LstShtAvail == comp.LstShtAvail) items.add(LSTSHTAVAIL);
			if (ButShtViewActive == comp.ButShtViewActive) items.add(BUTSHTVIEWACTIVE);
			if (LstFilAvail == comp.LstFilAvail) items.add(LSTFILAVAIL);
			if (ButFilViewActive == comp.ButFilViewActive) items.add(BUTFILVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTOGRAVAIL, BUTOGRVIEWACTIVE, LSTOBJAVAIL, BUTOBJVIEWACTIVE, LSTSESAVAIL, BUTSESVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskNavGalery)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTOGR = 2;
		public static final int CPTOBJ = 3;
		public static final int CPTSES = 4;
		public static final int CPTSHT = 5;
		public static final int CPTFIL = 6;

		public Tag(
					String Cpt
					, String CptOgr
					, String CptObj
					, String CptSes
					, String CptSht
					, String CptFil
				) {
			this.Cpt = Cpt;
			this.CptOgr = CptOgr;
			this.CptObj = CptObj;
			this.CptSes = CptSes;
			this.CptSht = CptSht;
			this.CptFil = CptFil;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTOGR, CPTOBJ, CPTSES, CPTSHT, CPTFIL));
		};

		public String Cpt;
		public String CptOgr;
		public String CptObj;
		public String CptSes;
		public String CptSht;
		public String CptFil;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskNavGalery");

			String itemtag = "TagitemWzskNavGalery";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptOgr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOgr", mask, CPTOGR);
				CptObj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptObj", mask, CPTOBJ);
				CptSes = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSes", mask, CPTSES);
				CptSht = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSht", mask, CPTSHT);
				CptFil = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFil", mask, CPTFIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptOgr.equals(comp.CptOgr)) items.add(CPTOGR);
			if (CptObj.equals(comp.CptObj)) items.add(CPTOBJ);
			if (CptSes.equals(comp.CptSes)) items.add(CPTSES);
			if (CptSht.equals(comp.CptSht)) items.add(CPTSHT);
			if (CptFil.equals(comp.CptFil)) items.add(CPTFIL);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTOGR, CPTOBJ, CPTSES, CPTSHT, CPTFIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskNavGaleryData)
		*/
	public class DpchAppData extends DpchAppWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int ALL = 3;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, Integer[] mask
				) {
			super(VecWzskVDpch.DPCHAPPWZSKNAVGALERYDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
		};

		public ContIac contiac;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWzskNavGaleryData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskNavGaleryDo)
		*/
	public class DpchAppDo extends DpchAppWzsk {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int ALL = 3;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, Integer[] mask
				) {
			super(VecWzskVDpch.DPCHAPPWZSKNAVGALERYDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO));
					break;
				};

			this.ixVDo = ixVDo;
		};

		public int ixVDo;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWzskNavGaleryDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskNavGaleryData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTFIL = 3;
		public static final int FEEDFLSTOBJ = 4;
		public static final int FEEDFLSTOGR = 5;
		public static final int FEEDFLSTSES = 6;
		public static final int FEEDFLSTSHT = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKNAVGALERYDATA);

			contiac = new ContIac(0, 0, 0, 0, 0);
			feedFLstFil = new Feed("FeedFLstFil");
			feedFLstObj = new Feed("FeedFLstObj");
			feedFLstOgr = new Feed("FeedFLstOgr");
			feedFLstSes = new Feed("FeedFLstSes");
			feedFLstSht = new Feed("FeedFLstSht");
			statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstFil;
		public Feed feedFLstObj;
		public Feed feedFLstOgr;
		public Feed feedFLstSes;
		public Feed feedFLstSht;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTFIL)) ss.add("feedFLstFil");
			if (has(FEEDFLSTOBJ)) ss.add("feedFLstObj");
			if (has(FEEDFLSTOGR)) ss.add("feedFLstOgr");
			if (has(FEEDFLSTSES)) ss.add("feedFLstSes");
			if (has(FEEDFLSTSHT)) ss.add("feedFLstSht");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(TAG)) ss.add("tag");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskNavGaleryData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstFil.readXML(doc, basexpath, true)) add(FEEDFLSTFIL);
				if (feedFLstObj.readXML(doc, basexpath, true)) add(FEEDFLSTOBJ);
				if (feedFLstOgr.readXML(doc, basexpath, true)) add(FEEDFLSTOGR);
				if (feedFLstSes.readXML(doc, basexpath, true)) add(FEEDFLSTSES);
				if (feedFLstSht.readXML(doc, basexpath, true)) add(FEEDFLSTSHT);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0);
				feedFLstFil = new Feed("FeedFLstFil");
				feedFLstObj = new Feed("FeedFLstObj");
				feedFLstOgr = new Feed("FeedFLstOgr");
				feedFLstSes = new Feed("FeedFLstSes");
				feedFLstSht = new Feed("FeedFLstSht");
				statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

