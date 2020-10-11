/**
  * \file PnlWzskNavOp.java
  * Java API code for job PnlWzskNavOp
  * \author Catherine Johnson
  * \date created: 6 Oct 2020
  * \date modified: 6 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskNavOp {
	/**
		* VecVDo (full: VecVWzskNavOpDo)
		*/
	public static class VecVDo {

		public static final int BUTLLVNEWCRDCLICK = 1;
		public static final int BUTLIVNEWCRDCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butllvnewcrdclick")) return BUTLLVNEWCRDCLICK;
			if (s.equals("butlivnewcrdclick")) return BUTLIVNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTLLVNEWCRDCLICK) return("ButLlvNewcrdClick");
			if (ix == BUTLIVNEWCRDCLICK) return("ButLivNewcrdClick");

			return "";
		};

	};

	/**
	  * StatApp (full: StatAppWzskNavOp)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskNavOp");

			String itemtag = "StatitemAppWzskNavOp";

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
	  * StatShr (full: StatShrWzskNavOp)
	  */
	public class StatShr extends Block {

		public static final int BUTLLVNEWCRDAVAIL = 1;
		public static final int BUTLIVNEWCRDAVAIL = 2;

		public StatShr(
					boolean ButLlvNewcrdAvail
					, boolean ButLivNewcrdAvail
				) {
			this.ButLlvNewcrdAvail = ButLlvNewcrdAvail;
			this.ButLivNewcrdAvail = ButLivNewcrdAvail;

			mask = new HashSet<Integer>(Arrays.asList(BUTLLVNEWCRDAVAIL, BUTLIVNEWCRDAVAIL));
		};

		public boolean ButLlvNewcrdAvail;
		public boolean ButLivNewcrdAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskNavOp");

			String itemtag = "StatitemShrWzskNavOp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButLlvNewcrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLlvNewcrdAvail", mask, BUTLLVNEWCRDAVAIL);
				ButLivNewcrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLivNewcrdAvail", mask, BUTLIVNEWCRDAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButLlvNewcrdAvail == comp.ButLlvNewcrdAvail) items.add(BUTLLVNEWCRDAVAIL);
			if (ButLivNewcrdAvail == comp.ButLivNewcrdAvail) items.add(BUTLIVNEWCRDAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTLLVNEWCRDAVAIL, BUTLIVNEWCRDAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskNavOp)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTLLV = 2;
		public static final int CPTLIV = 3;

		public Tag(
					String Cpt
					, String CptLlv
					, String CptLiv
				) {
			this.Cpt = Cpt;
			this.CptLlv = CptLlv;
			this.CptLiv = CptLiv;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTLLV, CPTLIV));
		};

		public String Cpt;
		public String CptLlv;
		public String CptLiv;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskNavOp");

			String itemtag = "TagitemWzskNavOp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptLlv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLlv", mask, CPTLLV);
				CptLiv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLiv", mask, CPTLIV);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptLlv.equals(comp.CptLlv)) items.add(CPTLLV);
			if (CptLiv.equals(comp.CptLiv)) items.add(CPTLIV);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTLLV, CPTLIV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskNavOpDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKNAVOPDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskNavOpDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskNavOpData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int STATAPP = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKNAVOPDATA);

			statapp = new StatApp(0);
			statshr = new StatShr(false, false);
			tag = new Tag("", "", "");
		};

		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskNavOpData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				statapp = new StatApp(0);
				statshr = new StatShr(false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};

