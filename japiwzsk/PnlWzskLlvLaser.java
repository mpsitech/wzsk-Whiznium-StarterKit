/**
  * \file PnlWzskLlvLaser.java
  * Java API code for job PnlWzskLlvLaser
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskLlvLaser {
	/**
		* VecVDo (full: VecVWzskLlvLaserDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;
		public static final int BUTCLAIMCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butclaimclick")) return BUTCLAIMCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTCLAIMCLICK) return("ButClaimClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskLlvLaser)
	  */
	public class ContIac extends Block {

		public static final int CHKERG = 1;
		public static final int SLDLLE = 2;
		public static final int SLDLRI = 3;

		public ContIac(
					boolean ChkErg
					, double SldLle
					, double SldLri
				) {
			this.ChkErg = ChkErg;
			this.SldLle = SldLle;
			this.SldLri = SldLri;

			mask = new HashSet<Integer>(Arrays.asList(CHKERG, SLDLLE, SLDLRI));
		};

		public boolean ChkErg;
		public double SldLle;
		public double SldLri;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskLlvLaser");

			String itemtag = "ContitemIacWzskLlvLaser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ChkErg = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkErg", mask, CHKERG);
				SldLle = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldLle", mask, SLDLLE);
				SldLri = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldLri", mask, SLDLRI);

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
			if (difftag.isEmpty()) difftag = "ContIacWzskLlvLaser";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskLlvLaser";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkErg", ChkErg);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldLle", SldLle);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldLri", SldLri);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ChkErg == comp.ChkErg) items.add(CHKERG);
			if (Xmlio.compareDouble(SldLle, comp.SldLle) < 1.0e-4) items.add(SLDLLE);
			if (Xmlio.compareDouble(SldLri, comp.SldLri) < 1.0e-4) items.add(SLDLRI);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CHKERG, SLDLLE, SLDLRI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWzskLlvLaser)
	  */
	public class ContInf extends Block {

		public static final int BUTCLAIMON = 1;

		public ContInf(
					boolean ButClaimOn
				) {
			this.ButClaimOn = ButClaimOn;

			mask = new HashSet<Integer>(Arrays.asList(BUTCLAIMON));
		};

		public boolean ButClaimOn;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskLlvLaser");

			String itemtag = "ContitemInfWzskLlvLaser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButClaimOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButClaimOn", mask, BUTCLAIMON);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButClaimOn == comp.ButClaimOn) items.add(BUTCLAIMON);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCLAIMON));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskLlvLaser)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int BUTCLAIMACTIVE = 2;
		public static final int SLDLLEACTIVE = 3;
		public static final int SLDLLEMIN = 4;
		public static final int SLDLLEMAX = 5;
		public static final int SLDLRIACTIVE = 6;
		public static final int SLDLRIMIN = 7;
		public static final int SLDLRIMAX = 8;

		public StatShr(
					int ixWzskVExpstate
					, boolean ButClaimActive
					, boolean SldLleActive
					, double SldLleMin
					, double SldLleMax
					, boolean SldLriActive
					, double SldLriMin
					, double SldLriMax
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.ButClaimActive = ButClaimActive;
			this.SldLleActive = SldLleActive;
			this.SldLleMin = SldLleMin;
			this.SldLleMax = SldLleMax;
			this.SldLriActive = SldLriActive;
			this.SldLriMin = SldLriMin;
			this.SldLriMax = SldLriMax;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDLLEACTIVE, SLDLLEMIN, SLDLLEMAX, SLDLRIACTIVE, SLDLRIMIN, SLDLRIMAX));
		};

		public int ixWzskVExpstate;
		public boolean ButClaimActive;
		public boolean SldLleActive;
		public double SldLleMin;
		public double SldLleMax;
		public boolean SldLriActive;
		public double SldLriMin;
		public double SldLriMax;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLlvLaser");

			String itemtag = "StatitemShrWzskLlvLaser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				ButClaimActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClaimActive", mask, BUTCLAIMACTIVE);
				SldLleActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLleActive", mask, SLDLLEACTIVE);
				SldLleMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLleMin", mask, SLDLLEMIN);
				SldLleMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLleMax", mask, SLDLLEMAX);
				SldLriActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLriActive", mask, SLDLRIACTIVE);
				SldLriMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLriMin", mask, SLDLRIMIN);
				SldLriMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLriMax", mask, SLDLRIMAX);

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
			if (SldLleActive == comp.SldLleActive) items.add(SLDLLEACTIVE);
			if (Xmlio.compareDouble(SldLleMin, comp.SldLleMin) < 1.0e-4) items.add(SLDLLEMIN);
			if (Xmlio.compareDouble(SldLleMax, comp.SldLleMax) < 1.0e-4) items.add(SLDLLEMAX);
			if (SldLriActive == comp.SldLriActive) items.add(SLDLRIACTIVE);
			if (Xmlio.compareDouble(SldLriMin, comp.SldLriMin) < 1.0e-4) items.add(SLDLRIMIN);
			if (Xmlio.compareDouble(SldLriMax, comp.SldLriMax) < 1.0e-4) items.add(SLDLRIMAX);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDLLEACTIVE, SLDLLEMIN, SLDLLEMAX, SLDLRIACTIVE, SLDLRIMIN, SLDLRIMAX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskLlvLaser)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTERG = 2;
		public static final int CPTLLE = 3;
		public static final int CPTLRI = 4;

		public Tag(
					String Cpt
					, String CptErg
					, String CptLle
					, String CptLri
				) {
			this.Cpt = Cpt;
			this.CptErg = CptErg;
			this.CptLle = CptLle;
			this.CptLri = CptLri;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTERG, CPTLLE, CPTLRI));
		};

		public String Cpt;
		public String CptErg;
		public String CptLle;
		public String CptLri;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskLlvLaser");

			String itemtag = "TagitemWzskLlvLaser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptErg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptErg", mask, CPTERG);
				CptLle = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLle", mask, CPTLLE);
				CptLri = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLri", mask, CPTLRI);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptErg.equals(comp.CptErg)) items.add(CPTERG);
			if (CptLle.equals(comp.CptLle)) items.add(CPTLLE);
			if (CptLri.equals(comp.CptLri)) items.add(CPTLRI);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTERG, CPTLLE, CPTLRI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskLlvLaserData)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVLASERDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvLaserData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvLaserDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVLASERDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvLaserDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskLlvLaserData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKLLVLASERDATA);

			contiac = new ContIac(false, 0.0, 0.0);
			continf = new ContInf(false);
			statshr = new StatShr(0, false, false, 0.0, 0.0, false, 0.0, 0.0);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLlvLaserData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(false, 0.0, 0.0);
				continf = new ContInf(false);
				statshr = new StatShr(0, false, false, 0.0, 0.0, false, 0.0, 0.0);
				tag = new Tag("", "", "", "");
			};
		};

	};

};
