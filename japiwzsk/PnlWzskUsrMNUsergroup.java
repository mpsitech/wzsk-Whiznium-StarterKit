/**
  * \file PnlWzskUsrMNUsergroup.java
  * Java API code for job PnlWzskUsrMNUsergroup
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskUsrMNUsergroup {
	/**
		* VecVDo (full: VecVWzskUsrMNUsergroupDo)
		*/
	public static class VecVDo {

		public static final int BUTVIEWCLICK = 1;
		public static final int BUTADDCLICK = 2;
		public static final int BUTSUBCLICK = 3;
		public static final int BUTREFRESHCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butviewclick")) return BUTVIEWCLICK;
			if (s.equals("butaddclick")) return BUTADDCLICK;
			if (s.equals("butsubclick")) return BUTSUBCLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTVIEWCLICK) return("ButViewClick");
			if (ix == BUTADDCLICK) return("ButAddClick");
			if (ix == BUTSUBCLICK) return("ButSubClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWzskUsrMNUsergroup)
	  */
	public class ContInf extends Block {

		public static final int NUMFCSIQST = 1;

		public ContInf(
					int numFCsiQst
				) {
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
		};

		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskUsrMNUsergroup");

			String itemtag = "ContitemInfWzskUsrMNUsergroup";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWzskUsrMNUsergroup)
	  */
	public class StatApp extends Block {

		public static final int IXWZSKVEXPSTATE = 1;

		public StatApp(
					int ixWzskVExpstate
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE));
		};

		public int ixWzskVExpstate;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskUsrMNUsergroup");

			String itemtag = "StatitemAppWzskUsrMNUsergroup";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVExpstate == comp.ixWzskVExpstate) items.add(IXWZSKVEXPSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskUsrMNUsergroup)
	  */
	public class StatShr extends Block {

		public static final int BUTVIEWAVAIL = 1;
		public static final int BUTVIEWACTIVE = 2;
		public static final int BUTADDAVAIL = 3;
		public static final int BUTSUBAVAIL = 4;
		public static final int BUTSUBACTIVE = 5;

		public StatShr(
					boolean ButViewAvail
					, boolean ButViewActive
					, boolean ButAddAvail
					, boolean ButSubAvail
					, boolean ButSubActive
				) {
			this.ButViewAvail = ButViewAvail;
			this.ButViewActive = ButViewActive;
			this.ButAddAvail = ButAddAvail;
			this.ButSubAvail = ButSubAvail;
			this.ButSubActive = ButSubActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE));
		};

		public boolean ButViewAvail;
		public boolean ButViewActive;
		public boolean ButAddAvail;
		public boolean ButSubAvail;
		public boolean ButSubActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskUsrMNUsergroup");

			String itemtag = "StatitemShrWzskUsrMNUsergroup";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButViewAvail", mask, BUTVIEWAVAIL);
				ButViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButViewActive", mask, BUTVIEWACTIVE);
				ButAddAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAddAvail", mask, BUTADDAVAIL);
				ButSubAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSubAvail", mask, BUTSUBAVAIL);
				ButSubActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSubActive", mask, BUTSUBACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButViewAvail == comp.ButViewAvail) items.add(BUTVIEWAVAIL);
			if (ButViewActive == comp.ButViewActive) items.add(BUTVIEWACTIVE);
			if (ButAddAvail == comp.ButAddAvail) items.add(BUTADDAVAIL);
			if (ButSubAvail == comp.ButSubAvail) items.add(BUTSUBAVAIL);
			if (ButSubActive == comp.ButSubActive) items.add(BUTSUBACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWzskUsrMNUsergroup)
	  */
	public class StgIac extends Block {

		public static final int TCOMREFWIDTH = 1;
		public static final int TCOULVWIDTH = 2;

		public StgIac(
					int TcoMrefWidth
					, int TcoUlvWidth
				) {
			this.TcoMrefWidth = TcoMrefWidth;
			this.TcoUlvWidth = TcoUlvWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOMREFWIDTH, TCOULVWIDTH));
		};

		public int TcoMrefWidth;
		public int TcoUlvWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWzskUsrMNUsergroup");

			String itemtag = "StgitemIacWzskUsrMNUsergroup";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoMrefWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", mask, TCOMREFWIDTH);
				TcoUlvWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoUlvWidth", mask, TCOULVWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWzskUsrMNUsergroup";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWzskUsrMNUsergroup";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoUlvWidth", TcoUlvWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoMrefWidth == comp.TcoMrefWidth) items.add(TCOMREFWIDTH);
			if (TcoUlvWidth == comp.TcoUlvWidth) items.add(TCOULVWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOMREFWIDTH, TCOULVWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskUsrMNUsergroup)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOMREF = 7;
		public static final int TCOULV = 8;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoMref
					, String TcoUlv
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoMref = TcoMref;
			this.TcoUlv = TcoUlv;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOULV));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoMref;
		public String TcoUlv;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskUsrMNUsergroup");

			String itemtag = "TagitemWzskUsrMNUsergroup";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoMref = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoMref", mask, TCOMREF);
				TcoUlv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoUlv", mask, TCOULV);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (TxtRecord1.equals(comp.TxtRecord1)) items.add(TXTRECORD1);
			if (TxtRecord2.equals(comp.TxtRecord2)) items.add(TXTRECORD2);
			if (Trs.equals(comp.Trs)) items.add(TRS);
			if (TxtShowing1.equals(comp.TxtShowing1)) items.add(TXTSHOWING1);
			if (TxtShowing2.equals(comp.TxtShowing2)) items.add(TXTSHOWING2);
			if (TcoMref.equals(comp.TcoMref)) items.add(TCOMREF);
			if (TcoUlv.equals(comp.TcoUlv)) items.add(TCOULV);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOULV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskUsrMNUsergroupData)
		*/
	public class DpchAppData extends DpchAppWzsk {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWzskUsrMNUsergroup.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWzskVDpch.DPCHAPPWZSKUSRMNUSERGROUPDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, STGIAC, STGIACQRY));
					break;
				};

			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public StgIac stgiac;
		public QryWzskUsrMNUsergroup.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWzskUsrMNUsergroupData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskUsrMNUsergroupDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKUSRMNUSERGROUPDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskUsrMNUsergroupDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskUsrMNUsergroupData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFCSIQST = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int STGIAC = 6;
		public static final int TAG = 7;
		public static final int RST = 8;
		public static final int STATAPPQRY = 9;
		public static final int STATSHRQRY = 10;
		public static final int STGIACQRY = 11;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKUSRMNUSERGROUPDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false);
			stgiac = new StgIac(0, 0);
			tag = new Tag("", "", "", "", "", "", "", "");
			rst = new ListWzskQUsrMNUsergroup();
			statappqry = (new QryWzskUsrMNUsergroup()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWzskUsrMNUsergroup()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWzskUsrMNUsergroup()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWzskQUsrMNUsergroup rst;
		public QryWzskUsrMNUsergroup.StatApp statappqry;
		public QryWzskUsrMNUsergroup.StatShr statshrqry;
		public QryWzskUsrMNUsergroup.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(TAG)) ss.add("tag");
			if (has(RST)) ss.add("rst");
			if (has(STATAPPQRY)) ss.add("statappqry");
			if (has(STATSHRQRY)) ss.add("statshrqry");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskUsrMNUsergroupData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				continf = new ContInf(0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false);
				stgiac = new StgIac(0, 0);
				tag = new Tag("", "", "", "", "", "", "", "");
				statappqry = (new QryWzskUsrMNUsergroup()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWzskUsrMNUsergroup()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWzskUsrMNUsergroup()).new StgIac(0, 0, 0);
			};
		};

	};

};

