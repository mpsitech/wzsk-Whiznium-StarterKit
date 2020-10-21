/**
  * \file PnlWzskOgrRec.java
  * Java API code for job PnlWzskOgrRec
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskOgrRec {
	/**
		* VecVDo (full: VecVWzskOgrRecDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWzskOgrRec)
	  */
	public class ContInf extends Block {

		public static final int TXTREF = 1;

		public ContInf(
					String TxtRef
				) {
			this.TxtRef = TxtRef;

			mask = new HashSet<Integer>(Arrays.asList(TXTREF));
		};

		public String TxtRef;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskOgrRec");

			String itemtag = "ContitemInfWzskOgrRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtRef = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtRef", mask, TXTREF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtRef.equals(comp.TxtRef)) items.add(TXTREF);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTREF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWzskOgrRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONE1NOBJECT = 2;
		public static final int INITDONESUP1NOBJGROUP = 3;

		public StatApp(
					boolean initdoneDetail
					, boolean initdone1NObject
					, boolean initdoneSup1NObjgroup
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdone1NObject = initdone1NObject;
			this.initdoneSup1NObjgroup = initdoneSup1NObjgroup;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONE1NOBJECT, INITDONESUP1NOBJGROUP));
		};

		public boolean initdoneDetail;
		public boolean initdone1NObject;
		public boolean initdoneSup1NObjgroup;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskOgrRec");

			String itemtag = "StatitemAppWzskOgrRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdone1NObject = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NObject", mask, INITDONE1NOBJECT);
				initdoneSup1NObjgroup = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSup1NObjgroup", mask, INITDONESUP1NOBJGROUP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdone1NObject == comp.initdone1NObject) items.add(INITDONE1NOBJECT);
			if (initdoneSup1NObjgroup == comp.initdoneSup1NObjgroup) items.add(INITDONESUP1NOBJGROUP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONE1NOBJECT, INITDONESUP1NOBJGROUP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskOgrRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREF1NOBJECT = 3;
		public static final int SCRJREFSUP1NOBJGROUP = 4;
		public static final int BUTREGULARIZEACTIVE = 5;

		public StatShr(
					int ixWzskVExpstate
					, String scrJrefDetail
					, String scrJref1NObject
					, String scrJrefSup1NObjgroup
					, boolean ButRegularizeActive
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJref1NObject = scrJref1NObject;
			this.scrJrefSup1NObjgroup = scrJrefSup1NObjgroup;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, SCRJREFDETAIL, SCRJREF1NOBJECT, SCRJREFSUP1NOBJGROUP, BUTREGULARIZEACTIVE));
		};

		public int ixWzskVExpstate;
		public String scrJrefDetail;
		public String scrJref1NObject;
		public String scrJrefSup1NObjgroup;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskOgrRec");

			String itemtag = "StatitemShrWzskOgrRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJref1NObject = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NObject", mask, SCRJREF1NOBJECT);
				scrJrefSup1NObjgroup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSup1NObjgroup", mask, SCRJREFSUP1NOBJGROUP);
				ButRegularizeActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", mask, BUTREGULARIZEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVExpstate == comp.ixWzskVExpstate) items.add(IXWZSKVEXPSTATE);
			if (scrJrefDetail.equals(comp.scrJrefDetail)) items.add(SCRJREFDETAIL);
			if (scrJref1NObject.equals(comp.scrJref1NObject)) items.add(SCRJREF1NOBJECT);
			if (scrJrefSup1NObjgroup.equals(comp.scrJrefSup1NObjgroup)) items.add(SCRJREFSUP1NOBJGROUP);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, SCRJREFDETAIL, SCRJREF1NOBJECT, SCRJREFSUP1NOBJGROUP, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskOgrRec)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;

		public Tag(
					String Cpt
				) {
			this.Cpt = Cpt;

			mask = new HashSet<Integer>(Arrays.asList(CPT));
		};

		public String Cpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskOgrRec");

			String itemtag = "TagitemWzskOgrRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskOgrRecDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKOGRRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskOgrRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskOgrRecData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKOGRRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false);
			statshr = new StatShr(0, "", "", "", false);
			tag = new Tag("");
		};

		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskOgrRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false);
				statshr = new StatShr(0, "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};

