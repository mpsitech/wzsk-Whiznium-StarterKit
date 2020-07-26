/**
  * \file PnlWzskLlvTtable.java
  * Java API code for job PnlWzskLlvTtable
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskLlvTtable {
	/**
		* VecVDo (full: VecVWzskLlvTtableDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;
		public static final int BUTCLAIMCLICK = 3;
		public static final int BUTMVECLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butclaimclick")) return BUTCLAIMCLICK;
			if (s.equals("butmveclick")) return BUTMVECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTCLAIMCLICK) return("ButClaimClick");
			if (ix == BUTMVECLICK) return("ButMveClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskLlvTtable)
	  */
	public class ContIac extends Block {

		public static final int SLDTRG = 1;

		public ContIac(
					double SldTrg
				) {
			this.SldTrg = SldTrg;

			mask = new HashSet<Integer>(Arrays.asList(SLDTRG));
		};

		public double SldTrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskLlvTtable");

			String itemtag = "ContitemIacWzskLlvTtable";

			if (Xmlio.checkXPath(doc, basexpath)) {
				SldTrg = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldTrg", mask, SLDTRG);

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
			if (difftag.isEmpty()) difftag = "ContIacWzskLlvTtable";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskLlvTtable";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldTrg", SldTrg);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareDouble(SldTrg, comp.SldTrg) < 1.0e-4) items.add(SLDTRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SLDTRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWzskLlvTtable)
	  */
	public class ContInf extends Block {

		public static final int BUTCLAIMON = 1;
		public static final int TXTSTE = 2;

		public ContInf(
					boolean ButClaimOn
					, String TxtSte
				) {
			this.ButClaimOn = ButClaimOn;
			this.TxtSte = TxtSte;

			mask = new HashSet<Integer>(Arrays.asList(BUTCLAIMON, TXTSTE));
		};

		public boolean ButClaimOn;
		public String TxtSte;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskLlvTtable");

			String itemtag = "ContitemInfWzskLlvTtable";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButClaimOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButClaimOn", mask, BUTCLAIMON);
				TxtSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSte", mask, TXTSTE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButClaimOn == comp.ButClaimOn) items.add(BUTCLAIMON);
			if (TxtSte.equals(comp.TxtSte)) items.add(TXTSTE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCLAIMON, TXTSTE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskLlvTtable)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int BUTCLAIMACTIVE = 2;
		public static final int SLDTRGMIN = 3;
		public static final int SLDTRGMAX = 4;
		public static final int BUTMVEACTIVE = 5;

		public StatShr(
					int ixWzskVExpstate
					, boolean ButClaimActive
					, double SldTrgMin
					, double SldTrgMax
					, boolean ButMveActive
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.ButClaimActive = ButClaimActive;
			this.SldTrgMin = SldTrgMin;
			this.SldTrgMax = SldTrgMax;
			this.ButMveActive = ButMveActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTRGMIN, SLDTRGMAX, BUTMVEACTIVE));
		};

		public int ixWzskVExpstate;
		public boolean ButClaimActive;
		public double SldTrgMin;
		public double SldTrgMax;
		public boolean ButMveActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLlvTtable");

			String itemtag = "StatitemShrWzskLlvTtable";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				ButClaimActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClaimActive", mask, BUTCLAIMACTIVE);
				SldTrgMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTrgMin", mask, SLDTRGMIN);
				SldTrgMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTrgMax", mask, SLDTRGMAX);
				ButMveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMveActive", mask, BUTMVEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVExpstate == comp.ixWzskVExpstate) items.add(IXWZSKVEXPSTATE);
			if (ButClaimActive == comp.ButClaimActive) items.add(BUTCLAIMACTIVE);
			if (Xmlio.compareDouble(SldTrgMin, comp.SldTrgMin) < 1.0e-4) items.add(SLDTRGMIN);
			if (Xmlio.compareDouble(SldTrgMax, comp.SldTrgMax) < 1.0e-4) items.add(SLDTRGMAX);
			if (ButMveActive == comp.ButMveActive) items.add(BUTMVEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTRGMIN, SLDTRGMAX, BUTMVEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskLlvTtable)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTTRG = 2;
		public static final int CPTSTE = 3;
		public static final int BUTMVE = 4;

		public Tag(
					String Cpt
					, String CptTrg
					, String CptSte
					, String ButMve
				) {
			this.Cpt = Cpt;
			this.CptTrg = CptTrg;
			this.CptSte = CptSte;
			this.ButMve = ButMve;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTTRG, CPTSTE, BUTMVE));
		};

		public String Cpt;
		public String CptTrg;
		public String CptSte;
		public String ButMve;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskLlvTtable");

			String itemtag = "TagitemWzskLlvTtable";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptTrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTrg", mask, CPTTRG);
				CptSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSte", mask, CPTSTE);
				ButMve = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButMve", mask, BUTMVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptTrg.equals(comp.CptTrg)) items.add(CPTTRG);
			if (CptSte.equals(comp.CptSte)) items.add(CPTSTE);
			if (ButMve.equals(comp.ButMve)) items.add(BUTMVE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTTRG, CPTSTE, BUTMVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskLlvTtableData)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVTTABLEDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvTtableData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvTtableDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVTTABLEDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvTtableDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskLlvTtableData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKLLVTTABLEDATA);

			contiac = new ContIac(0.0);
			continf = new ContInf(false, "");
			statshr = new StatShr(0, false, 0.0, 0.0, false);
			tag = new Tag("", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLlvTtableData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0.0);
				continf = new ContInf(false, "");
				statshr = new StatShr(0, false, 0.0, 0.0, false);
				tag = new Tag("", "", "", "");
			};
		};

	};

};
