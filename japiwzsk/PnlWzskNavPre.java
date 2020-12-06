/**
  * \file PnlWzskNavPre.java
  * Java API code for job PnlWzskNavPre
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskNavPre {
	/**
		* VecVDo (full: VecVWzskNavPreDo)
		*/
	public static class VecVDo {

		public static final int BUTOBJREMOVECLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butobjremoveclick")) return BUTOBJREMOVECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTOBJREMOVECLICK) return("ButObjRemoveClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWzskNavPre)
	  */
	public class ContInf extends Block {

		public static final int TXTOBJ = 1;

		public ContInf(
					String TxtObj
				) {
			this.TxtObj = TxtObj;

			mask = new HashSet<Integer>(Arrays.asList(TXTOBJ));
		};

		public String TxtObj;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskNavPre");

			String itemtag = "ContitemInfWzskNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtObj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtObj", mask, TXTOBJ);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtObj.equals(comp.TxtObj)) items.add(TXTOBJ);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTOBJ));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskNavPre)
	  */
	public class StatShr extends Block {

		public static final int TXTOBJAVAIL = 1;

		public StatShr(
					boolean TxtObjAvail
				) {
			this.TxtObjAvail = TxtObjAvail;

			mask = new HashSet<Integer>(Arrays.asList(TXTOBJAVAIL));
		};

		public boolean TxtObjAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskNavPre");

			String itemtag = "StatitemShrWzskNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtObjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtObjAvail", mask, TXTOBJAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtObjAvail == comp.TxtObjAvail) items.add(TXTOBJAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTOBJAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskNavPre)
	  */
	public class Tag extends Block {

		public static final int CPTOBJ = 1;

		public Tag(
					String CptObj
				) {
			this.CptObj = CptObj;

			mask = new HashSet<Integer>(Arrays.asList(CPTOBJ));
		};

		public String CptObj;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskNavPre");

			String itemtag = "TagitemWzskNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptObj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptObj", mask, CPTOBJ);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptObj.equals(comp.CptObj)) items.add(CPTOBJ);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTOBJ));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskNavPreDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKNAVPREDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskNavPreDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskNavPreData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKNAVPREDATA);

			continf = new ContInf("");
			statshr = new StatShr(false);
			tag = new Tag("");
		};

		public ContInf continf;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskNavPreData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statshr = new StatShr(false);
				tag = new Tag("");
			};
		};

	};

};
