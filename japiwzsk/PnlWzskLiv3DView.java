/**
  * \file PnlWzskLiv3DView.java
  * Java API code for job PnlWzskLiv3DView
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskLiv3DView {
	/**
		* VecVDo (full: VecVWzskLiv3DViewDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;
		public static final int BUTCLAIMCLICK = 3;
		public static final int BUTPLAYCLICK = 4;
		public static final int BUTSTOPCLICK = 5;
		public static final int BUTASTCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butclaimclick")) return BUTCLAIMCLICK;
			if (s.equals("butplayclick")) return BUTPLAYCLICK;
			if (s.equals("butstopclick")) return BUTSTOPCLICK;
			if (s.equals("butastclick")) return BUTASTCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTCLAIMCLICK) return("ButClaimClick");
			if (ix == BUTPLAYCLICK) return("ButPlayClick");
			if (ix == BUTSTOPCLICK) return("ButStopClick");
			if (ix == BUTASTCLICK) return("ButAstClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWzskLiv3DView)
	  */
	public class ContInf extends Block {

		public static final int BUTCLAIMON = 1;
		public static final int TXTAST = 2;
		public static final int TXTAOA = 3;

		public ContInf(
					boolean ButClaimOn
					, String TxtAst
					, String TxtAoa
				) {
			this.ButClaimOn = ButClaimOn;
			this.TxtAst = TxtAst;
			this.TxtAoa = TxtAoa;

			mask = new HashSet<Integer>(Arrays.asList(BUTCLAIMON, TXTAST, TXTAOA));
		};

		public boolean ButClaimOn;
		public String TxtAst;
		public String TxtAoa;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskLiv3DView");

			String itemtag = "ContitemInfWzskLiv3DView";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButClaimOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButClaimOn", mask, BUTCLAIMON);
				TxtAst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtAst", mask, TXTAST);
				TxtAoa = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtAoa", mask, TXTAOA);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButClaimOn == comp.ButClaimOn) items.add(BUTCLAIMON);
			if (TxtAst.equals(comp.TxtAst)) items.add(TXTAST);
			if (TxtAoa.equals(comp.TxtAoa)) items.add(TXTAOA);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCLAIMON, TXTAST, TXTAOA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskLiv3DView)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int BUTCLAIMACTIVE = 2;
		public static final int SLDTREHMIN = 3;
		public static final int SLDTREHMAX = 4;
		public static final int SLDTREVMIN = 5;
		public static final int SLDTREVMAX = 6;
		public static final int BUTPLAYACTIVE = 7;
		public static final int BUTSTOPACTIVE = 8;
		public static final int TXTAOAAVAIL = 9;
		public static final int BUTASTACTIVE = 10;

		public StatShr(
					int ixWzskVExpstate
					, boolean ButClaimActive
					, double SldTreHMin
					, double SldTreHMax
					, double SldTreVMin
					, double SldTreVMax
					, boolean ButPlayActive
					, boolean ButStopActive
					, boolean TxtAoaAvail
					, boolean ButAstActive
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.ButClaimActive = ButClaimActive;
			this.SldTreHMin = SldTreHMin;
			this.SldTreHMax = SldTreHMax;
			this.SldTreVMin = SldTreVMin;
			this.SldTreVMax = SldTreVMax;
			this.ButPlayActive = ButPlayActive;
			this.ButStopActive = ButStopActive;
			this.TxtAoaAvail = TxtAoaAvail;
			this.ButAstActive = ButAstActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTREHMIN, SLDTREHMAX, SLDTREVMIN, SLDTREVMAX, BUTPLAYACTIVE, BUTSTOPACTIVE, TXTAOAAVAIL, BUTASTACTIVE));
		};

		public int ixWzskVExpstate;
		public boolean ButClaimActive;
		public double SldTreHMin;
		public double SldTreHMax;
		public double SldTreVMin;
		public double SldTreVMax;
		public boolean ButPlayActive;
		public boolean ButStopActive;
		public boolean TxtAoaAvail;
		public boolean ButAstActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLiv3DView");

			String itemtag = "StatitemShrWzskLiv3DView";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				ButClaimActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClaimActive", mask, BUTCLAIMACTIVE);
				SldTreHMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTreHMin", mask, SLDTREHMIN);
				SldTreHMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTreHMax", mask, SLDTREHMAX);
				SldTreVMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTreVMin", mask, SLDTREVMIN);
				SldTreVMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTreVMax", mask, SLDTREVMAX);
				ButPlayActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPlayActive", mask, BUTPLAYACTIVE);
				ButStopActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStopActive", mask, BUTSTOPACTIVE);
				TxtAoaAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtAoaAvail", mask, TXTAOAAVAIL);
				ButAstActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAstActive", mask, BUTASTACTIVE);

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
			if (Xmlio.compareDouble(SldTreHMin, comp.SldTreHMin) < 1.0e-4) items.add(SLDTREHMIN);
			if (Xmlio.compareDouble(SldTreHMax, comp.SldTreHMax) < 1.0e-4) items.add(SLDTREHMAX);
			if (Xmlio.compareDouble(SldTreVMin, comp.SldTreVMin) < 1.0e-4) items.add(SLDTREVMIN);
			if (Xmlio.compareDouble(SldTreVMax, comp.SldTreVMax) < 1.0e-4) items.add(SLDTREVMAX);
			if (ButPlayActive == comp.ButPlayActive) items.add(BUTPLAYACTIVE);
			if (ButStopActive == comp.ButStopActive) items.add(BUTSTOPACTIVE);
			if (TxtAoaAvail == comp.TxtAoaAvail) items.add(TXTAOAAVAIL);
			if (ButAstActive == comp.ButAstActive) items.add(BUTASTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDTREHMIN, SLDTREHMAX, SLDTREVMIN, SLDTREVMAX, BUTPLAYACTIVE, BUTSTOPACTIVE, TXTAOAAVAIL, BUTASTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskLiv3DView)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int HDGACQ = 2;
		public static final int CPTAST = 3;
		public static final int CPTAOA = 4;
		public static final int BUTAST = 5;

		public Tag(
					String Cpt
					, String HdgAcq
					, String CptAst
					, String CptAoa
					, String ButAst
				) {
			this.Cpt = Cpt;
			this.HdgAcq = HdgAcq;
			this.CptAst = CptAst;
			this.CptAoa = CptAoa;
			this.ButAst = ButAst;

			mask = new HashSet<Integer>(Arrays.asList(CPT, HDGACQ, CPTAST, CPTAOA, BUTAST));
		};

		public String Cpt;
		public String HdgAcq;
		public String CptAst;
		public String CptAoa;
		public String ButAst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskLiv3DView");

			String itemtag = "TagitemWzskLiv3DView";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				HdgAcq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgAcq", mask, HDGACQ);
				CptAst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAst", mask, CPTAST);
				CptAoa = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAoa", mask, CPTAOA);
				ButAst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButAst", mask, BUTAST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (HdgAcq.equals(comp.HdgAcq)) items.add(HDGACQ);
			if (CptAst.equals(comp.CptAst)) items.add(CPTAST);
			if (CptAoa.equals(comp.CptAoa)) items.add(CPTAOA);
			if (ButAst.equals(comp.ButAst)) items.add(BUTAST);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, HDGACQ, CPTAST, CPTAOA, BUTAST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskLiv3DViewDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKLIV3DVIEWDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLiv3DViewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskLiv3DViewData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKLIV3DVIEWDATA);

			continf = new ContInf(false, "", "");
			statshr = new StatShr(0, false, 0.0, 0.0, 0.0, 0.0, false, false, false, false);
			tag = new Tag("", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLiv3DViewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(false, "", "");
				statshr = new StatShr(0, false, 0.0, 0.0, 0.0, 0.0, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

	/**
		* DpchEngLive (full: DpchEngWzskLiv3DViewLive)
		*/
	public class DpchEngLive extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int RNOTL = 2;
		public static final int X = 3;
		public static final int Y = 4;
		public static final int Z = 5;

		public DpchEngLive() {
			super(VecWzskVDpch.DPCHENGWZSKLIV3DVIEWLIVE);

		};

		public ArrayList<Boolean> rNotL;
		public ArrayList<Float> x;
		public ArrayList<Float> y;
		public ArrayList<Float> z;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(RNOTL)) ss.add("rNotL");
			if (has(X)) ss.add("x");
			if (has(Y)) ss.add("y");
			if (has(Z)) ss.add("z");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLiv3DViewLive");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				rNotL = Xmlio.extractBooleanvecUclc(doc, basexpath, "rNotL", "", mask, RNOTL);
				x = Xmlio.extractFloatvecUclc(doc, basexpath, "x", "", mask, X);
				y = Xmlio.extractFloatvecUclc(doc, basexpath, "y", "", mask, Y);
				z = Xmlio.extractFloatvecUclc(doc, basexpath, "z", "", mask, Z);
			} else {
				scrJref = "";
				rNotL = new ArrayList<Boolean>();
				x = new ArrayList<Float>();
				y = new ArrayList<Float>();
				z = new ArrayList<Float>();
			};
		};

	};

};

