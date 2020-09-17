/**
  * \file PnlWzskNavAdmin.java
  * Java API code for job PnlWzskNavAdmin
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskNavAdmin {
	/**
		* VecVDo (full: VecVWzskNavAdminDo)
		*/
	public static class VecVDo {

		public static final int BUTUSGVIEWCLICK = 1;
		public static final int BUTUSGNEWCRDCLICK = 2;
		public static final int BUTUSRVIEWCLICK = 3;
		public static final int BUTUSRNEWCRDCLICK = 4;
		public static final int BUTPRSVIEWCLICK = 5;
		public static final int BUTPRSNEWCRDCLICK = 6;
		public static final int BUTSCFNEWCRDCLICK = 7;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butusgviewclick")) return BUTUSGVIEWCLICK;
			if (s.equals("butusgnewcrdclick")) return BUTUSGNEWCRDCLICK;
			if (s.equals("butusrviewclick")) return BUTUSRVIEWCLICK;
			if (s.equals("butusrnewcrdclick")) return BUTUSRNEWCRDCLICK;
			if (s.equals("butprsviewclick")) return BUTPRSVIEWCLICK;
			if (s.equals("butprsnewcrdclick")) return BUTPRSNEWCRDCLICK;
			if (s.equals("butscfnewcrdclick")) return BUTSCFNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
			if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
			if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
			if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
			if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
			if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");
			if (ix == BUTSCFNEWCRDCLICK) return("ButScfNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskNavAdmin)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTUSG = 1;
		public static final int NUMFLSTUSR = 2;
		public static final int NUMFLSTPRS = 3;

		public ContIac(
					int numFLstUsg
					, int numFLstUsr
					, int numFLstPrs
				) {
			this.numFLstUsg = numFLstUsg;
			this.numFLstUsr = numFLstUsr;
			this.numFLstPrs = numFLstPrs;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS));
		};

		public int numFLstUsg;
		public int numFLstUsr;
		public int numFLstPrs;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskNavAdmin");

			String itemtag = "ContitemIacWzskNavAdmin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstUsg = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstUsg", mask, NUMFLSTUSG);
				numFLstUsr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstUsr", mask, NUMFLSTUSR);
				numFLstPrs = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrs", mask, NUMFLSTPRS);

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
			if (difftag.isEmpty()) difftag = "ContIacWzskNavAdmin";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskNavAdmin";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstUsg", numFLstUsg);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstUsr", numFLstUsr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrs", numFLstPrs);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstUsg == comp.numFLstUsg) items.add(NUMFLSTUSG);
			if (numFLstUsr == comp.numFLstUsr) items.add(NUMFLSTUSR);
			if (numFLstPrs == comp.numFLstPrs) items.add(NUMFLSTPRS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWzskNavAdmin)
	  */
	public class StatApp extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int LSTUSGALT = 2;
		public static final int LSTUSRALT = 3;
		public static final int LSTPRSALT = 4;
		public static final int LSTUSGNUMFIRSTDISP = 5;
		public static final int LSTUSRNUMFIRSTDISP = 6;
		public static final int LSTPRSNUMFIRSTDISP = 7;

		public StatApp(
					int ixWzskVExpstate
					, boolean LstUsgAlt
					, boolean LstUsrAlt
					, boolean LstPrsAlt
					, int LstUsgNumFirstdisp
					, int LstUsrNumFirstdisp
					, int LstPrsNumFirstdisp
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.LstUsgAlt = LstUsgAlt;
			this.LstUsrAlt = LstUsrAlt;
			this.LstPrsAlt = LstPrsAlt;
			this.LstUsgNumFirstdisp = LstUsgNumFirstdisp;
			this.LstUsrNumFirstdisp = LstUsrNumFirstdisp;
			this.LstPrsNumFirstdisp = LstPrsNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP));
		};

		public int ixWzskVExpstate;
		public boolean LstUsgAlt;
		public boolean LstUsrAlt;
		public boolean LstPrsAlt;
		public int LstUsgNumFirstdisp;
		public int LstUsrNumFirstdisp;
		public int LstPrsNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskNavAdmin");

			String itemtag = "StatitemAppWzskNavAdmin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				LstUsgAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsgAlt", mask, LSTUSGALT);
				LstUsrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsrAlt", mask, LSTUSRALT);
				LstPrsAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrsAlt", mask, LSTPRSALT);
				LstUsgNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsgNumFirstdisp", mask, LSTUSGNUMFIRSTDISP);
				LstUsrNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsrNumFirstdisp", mask, LSTUSRNUMFIRSTDISP);
				LstPrsNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrsNumFirstdisp", mask, LSTPRSNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVExpstate == comp.ixWzskVExpstate) items.add(IXWZSKVEXPSTATE);
			if (LstUsgAlt == comp.LstUsgAlt) items.add(LSTUSGALT);
			if (LstUsrAlt == comp.LstUsrAlt) items.add(LSTUSRALT);
			if (LstPrsAlt == comp.LstPrsAlt) items.add(LSTPRSALT);
			if (LstUsgNumFirstdisp == comp.LstUsgNumFirstdisp) items.add(LSTUSGNUMFIRSTDISP);
			if (LstUsrNumFirstdisp == comp.LstUsrNumFirstdisp) items.add(LSTUSRNUMFIRSTDISP);
			if (LstPrsNumFirstdisp == comp.LstPrsNumFirstdisp) items.add(LSTPRSNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskNavAdmin)
	  */
	public class StatShr extends Block {

		public static final int LSTUSGAVAIL = 1;
		public static final int BUTUSGVIEWACTIVE = 2;
		public static final int LSTUSRAVAIL = 3;
		public static final int BUTUSRVIEWACTIVE = 4;
		public static final int LSTPRSAVAIL = 5;
		public static final int BUTPRSVIEWACTIVE = 6;
		public static final int BUTSCFNEWCRDAVAIL = 7;

		public StatShr(
					boolean LstUsgAvail
					, boolean ButUsgViewActive
					, boolean LstUsrAvail
					, boolean ButUsrViewActive
					, boolean LstPrsAvail
					, boolean ButPrsViewActive
					, boolean ButScfNewcrdAvail
				) {
			this.LstUsgAvail = LstUsgAvail;
			this.ButUsgViewActive = ButUsgViewActive;
			this.LstUsrAvail = LstUsrAvail;
			this.ButUsrViewActive = ButUsrViewActive;
			this.LstPrsAvail = LstPrsAvail;
			this.ButPrsViewActive = ButPrsViewActive;
			this.ButScfNewcrdAvail = ButScfNewcrdAvail;

			mask = new HashSet<Integer>(Arrays.asList(LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, BUTSCFNEWCRDAVAIL));
		};

		public boolean LstUsgAvail;
		public boolean ButUsgViewActive;
		public boolean LstUsrAvail;
		public boolean ButUsrViewActive;
		public boolean LstPrsAvail;
		public boolean ButPrsViewActive;
		public boolean ButScfNewcrdAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskNavAdmin");

			String itemtag = "StatitemShrWzskNavAdmin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstUsgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsgAvail", mask, LSTUSGAVAIL);
				ButUsgViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUsgViewActive", mask, BUTUSGVIEWACTIVE);
				LstUsrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsrAvail", mask, LSTUSRAVAIL);
				ButUsrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUsrViewActive", mask, BUTUSRVIEWACTIVE);
				LstPrsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrsAvail", mask, LSTPRSAVAIL);
				ButPrsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrsViewActive", mask, BUTPRSVIEWACTIVE);
				ButScfNewcrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButScfNewcrdAvail", mask, BUTSCFNEWCRDAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstUsgAvail == comp.LstUsgAvail) items.add(LSTUSGAVAIL);
			if (ButUsgViewActive == comp.ButUsgViewActive) items.add(BUTUSGVIEWACTIVE);
			if (LstUsrAvail == comp.LstUsrAvail) items.add(LSTUSRAVAIL);
			if (ButUsrViewActive == comp.ButUsrViewActive) items.add(BUTUSRVIEWACTIVE);
			if (LstPrsAvail == comp.LstPrsAvail) items.add(LSTPRSAVAIL);
			if (ButPrsViewActive == comp.ButPrsViewActive) items.add(BUTPRSVIEWACTIVE);
			if (ButScfNewcrdAvail == comp.ButScfNewcrdAvail) items.add(BUTSCFNEWCRDAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, BUTSCFNEWCRDAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskNavAdmin)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTUSG = 2;
		public static final int CPTUSR = 3;
		public static final int CPTPRS = 4;
		public static final int CPTSCF = 5;

		public Tag(
					String Cpt
					, String CptUsg
					, String CptUsr
					, String CptPrs
					, String CptScf
				) {
			this.Cpt = Cpt;
			this.CptUsg = CptUsg;
			this.CptUsr = CptUsr;
			this.CptPrs = CptPrs;
			this.CptScf = CptScf;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTUSG, CPTUSR, CPTPRS, CPTSCF));
		};

		public String Cpt;
		public String CptUsg;
		public String CptUsr;
		public String CptPrs;
		public String CptScf;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskNavAdmin");

			String itemtag = "TagitemWzskNavAdmin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptUsg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUsg", mask, CPTUSG);
				CptUsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUsr", mask, CPTUSR);
				CptPrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrs", mask, CPTPRS);
				CptScf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptScf", mask, CPTSCF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptUsg.equals(comp.CptUsg)) items.add(CPTUSG);
			if (CptUsr.equals(comp.CptUsr)) items.add(CPTUSR);
			if (CptPrs.equals(comp.CptPrs)) items.add(CPTPRS);
			if (CptScf.equals(comp.CptScf)) items.add(CPTSCF);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTUSG, CPTUSR, CPTPRS, CPTSCF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskNavAdminData)
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
			super(VecWzskVDpch.DPCHAPPWZSKNAVADMINDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWzskNavAdminData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskNavAdminDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKNAVADMINDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskNavAdminDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskNavAdminData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTPRS = 3;
		public static final int FEEDFLSTUSG = 4;
		public static final int FEEDFLSTUSR = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKNAVADMINDATA);

			contiac = new ContIac(0, 0, 0);
			feedFLstPrs = new Feed("FeedFLstPrs");
			feedFLstUsg = new Feed("FeedFLstUsg");
			feedFLstUsr = new Feed("FeedFLstUsr");
			statapp = new StatApp(0, false, false, false, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstPrs;
		public Feed feedFLstUsg;
		public Feed feedFLstUsr;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTPRS)) ss.add("feedFLstPrs");
			if (has(FEEDFLSTUSG)) ss.add("feedFLstUsg");
			if (has(FEEDFLSTUSR)) ss.add("feedFLstUsr");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskNavAdminData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstPrs.readXML(doc, basexpath, true)) add(FEEDFLSTPRS);
				if (feedFLstUsg.readXML(doc, basexpath, true)) add(FEEDFLSTUSG);
				if (feedFLstUsr.readXML(doc, basexpath, true)) add(FEEDFLSTUSR);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0);
				feedFLstPrs = new Feed("FeedFLstPrs");
				feedFLstUsg = new Feed("FeedFLstUsg");
				feedFLstUsr = new Feed("FeedFLstUsr");
				statapp = new StatApp(0, false, false, false, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};

