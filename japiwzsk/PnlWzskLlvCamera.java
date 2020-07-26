/**
  * \file PnlWzskLlvCamera.java
  * Java API code for job PnlWzskLlvCamera
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskLlvCamera {
	/**
		* VecVDo (full: VecVWzskLlvCameraDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;
		public static final int BUTCLAIMCLICK = 3;
		public static final int BUTPLAYCLICK = 4;
		public static final int BUTSTOPCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butclaimclick")) return BUTCLAIMCLICK;
			if (s.equals("butplayclick")) return BUTPLAYCLICK;
			if (s.equals("butstopclick")) return BUTSTOPCLICK;

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

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskLlvCamera)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPMDE = 1;
		public static final int SLDFCS = 2;
		public static final int SLDEXT = 3;

		public ContIac(
					int numFPupMde
					, double SldFcs
					, double SldExt
				) {
			this.numFPupMde = numFPupMde;
			this.SldFcs = SldFcs;
			this.SldExt = SldExt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPMDE, SLDFCS, SLDEXT));
		};

		public int numFPupMde;
		public double SldFcs;
		public double SldExt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskLlvCamera");

			String itemtag = "ContitemIacWzskLlvCamera";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupMde = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupMde", mask, NUMFPUPMDE);
				SldFcs = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFcs", mask, SLDFCS);
				SldExt = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldExt", mask, SLDEXT);

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
			if (difftag.isEmpty()) difftag = "ContIacWzskLlvCamera";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskLlvCamera";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupMde", numFPupMde);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFcs", SldFcs);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldExt", SldExt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupMde == comp.numFPupMde) items.add(NUMFPUPMDE);
			if (Xmlio.compareDouble(SldFcs, comp.SldFcs) < 1.0e-4) items.add(SLDFCS);
			if (Xmlio.compareDouble(SldExt, comp.SldExt) < 1.0e-4) items.add(SLDEXT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPMDE, SLDFCS, SLDEXT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWzskLlvCamera)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskLlvCamera");

			String itemtag = "ContitemInfWzskLlvCamera";

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
	  * StatShr (full: StatShrWzskLlvCamera)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int BUTCLAIMACTIVE = 2;
		public static final int BUTPLAYACTIVE = 3;
		public static final int BUTSTOPACTIVE = 4;
		public static final int SLDFCSAVAIL = 5;
		public static final int SLDFCSACTIVE = 6;
		public static final int SLDFCSMIN = 7;
		public static final int SLDFCSMAX = 8;
		public static final int SLDEXTAVAIL = 9;
		public static final int SLDEXTACTIVE = 10;
		public static final int SLDEXTMIN = 11;
		public static final int SLDEXTMAX = 12;
		public static final int SLDEXTRAST = 13;

		public StatShr(
					int ixWzskVExpstate
					, boolean ButClaimActive
					, boolean ButPlayActive
					, boolean ButStopActive
					, boolean SldFcsAvail
					, boolean SldFcsActive
					, double SldFcsMin
					, double SldFcsMax
					, boolean SldExtAvail
					, boolean SldExtActive
					, double SldExtMin
					, double SldExtMax
					, double SldExtRast
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.ButClaimActive = ButClaimActive;
			this.ButPlayActive = ButPlayActive;
			this.ButStopActive = ButStopActive;
			this.SldFcsAvail = SldFcsAvail;
			this.SldFcsActive = SldFcsActive;
			this.SldFcsMin = SldFcsMin;
			this.SldFcsMax = SldFcsMax;
			this.SldExtAvail = SldExtAvail;
			this.SldExtActive = SldExtActive;
			this.SldExtMin = SldExtMin;
			this.SldExtMax = SldExtMax;
			this.SldExtRast = SldExtRast;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST));
		};

		public int ixWzskVExpstate;
		public boolean ButClaimActive;
		public boolean ButPlayActive;
		public boolean ButStopActive;
		public boolean SldFcsAvail;
		public boolean SldFcsActive;
		public double SldFcsMin;
		public double SldFcsMax;
		public boolean SldExtAvail;
		public boolean SldExtActive;
		public double SldExtMin;
		public double SldExtMax;
		public double SldExtRast;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLlvCamera");

			String itemtag = "StatitemShrWzskLlvCamera";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				ButClaimActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClaimActive", mask, BUTCLAIMACTIVE);
				ButPlayActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPlayActive", mask, BUTPLAYACTIVE);
				ButStopActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStopActive", mask, BUTSTOPACTIVE);
				SldFcsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsAvail", mask, SLDFCSAVAIL);
				SldFcsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsActive", mask, SLDFCSACTIVE);
				SldFcsMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsMin", mask, SLDFCSMIN);
				SldFcsMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsMax", mask, SLDFCSMAX);
				SldExtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtAvail", mask, SLDEXTAVAIL);
				SldExtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtActive", mask, SLDEXTACTIVE);
				SldExtMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtMin", mask, SLDEXTMIN);
				SldExtMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtMax", mask, SLDEXTMAX);
				SldExtRast = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtRast", mask, SLDEXTRAST);

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
			if (ButPlayActive == comp.ButPlayActive) items.add(BUTPLAYACTIVE);
			if (ButStopActive == comp.ButStopActive) items.add(BUTSTOPACTIVE);
			if (SldFcsAvail == comp.SldFcsAvail) items.add(SLDFCSAVAIL);
			if (SldFcsActive == comp.SldFcsActive) items.add(SLDFCSACTIVE);
			if (Xmlio.compareDouble(SldFcsMin, comp.SldFcsMin) < 1.0e-4) items.add(SLDFCSMIN);
			if (Xmlio.compareDouble(SldFcsMax, comp.SldFcsMax) < 1.0e-4) items.add(SLDFCSMAX);
			if (SldExtAvail == comp.SldExtAvail) items.add(SLDEXTAVAIL);
			if (SldExtActive == comp.SldExtActive) items.add(SLDEXTACTIVE);
			if (Xmlio.compareDouble(SldExtMin, comp.SldExtMin) < 1.0e-4) items.add(SLDEXTMIN);
			if (Xmlio.compareDouble(SldExtMax, comp.SldExtMax) < 1.0e-4) items.add(SLDEXTMAX);
			if (Xmlio.compareDouble(SldExtRast, comp.SldExtRast) < 1.0e-4) items.add(SLDEXTRAST);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskLlvCamera)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTMDE = 2;
		public static final int CPTFCS = 3;
		public static final int CPTEXT = 4;

		public Tag(
					String Cpt
					, String CptMde
					, String CptFcs
					, String CptExt
				) {
			this.Cpt = Cpt;
			this.CptMde = CptMde;
			this.CptFcs = CptFcs;
			this.CptExt = CptExt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTMDE, CPTFCS, CPTEXT));
		};

		public String Cpt;
		public String CptMde;
		public String CptFcs;
		public String CptExt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskLlvCamera");

			String itemtag = "TagitemWzskLlvCamera";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptMde = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMde", mask, CPTMDE);
				CptFcs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFcs", mask, CPTFCS);
				CptExt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptExt", mask, CPTEXT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptMde.equals(comp.CptMde)) items.add(CPTMDE);
			if (CptFcs.equals(comp.CptFcs)) items.add(CPTFCS);
			if (CptExt.equals(comp.CptExt)) items.add(CPTEXT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTMDE, CPTFCS, CPTEXT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskLlvCameraData)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVCAMERADATA, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvCameraData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvCameraDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVCAMERADO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvCameraDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskLlvCameraData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPMDE = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKLLVCAMERADATA);

			contiac = new ContIac(0, 0.0, 0.0);
			continf = new ContInf(false);
			feedFPupMde = new Feed("FeedFPupMde");
			statshr = new StatShr(0, false, false, false, false, false, 0.0, 0.0, false, false, 0.0, 0.0, 0.0);
			tag = new Tag("", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupMde;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPMDE)) ss.add("feedFPupMde");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLlvCameraData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupMde.readXML(doc, basexpath, true)) add(FEEDFPUPMDE);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0.0, 0.0);
				continf = new ContInf(false);
				feedFPupMde = new Feed("FeedFPupMde");
				statshr = new StatShr(0, false, false, false, false, false, 0.0, 0.0, false, false, 0.0, 0.0, 0.0);
				tag = new Tag("", "", "", "");
			};
		};

	};

	/**
		* DpchEngLive (full: DpchEngWzskLlvCameraLive)
		*/
	public class DpchEngLive extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int GRAY = 2;
		public static final int RED = 3;
		public static final int GREEN = 4;
		public static final int BLUE = 5;

		public DpchEngLive() {
			super(VecWzskVDpch.DPCHENGWZSKLLVCAMERALIVE);

		};

		public ArrayList<Integer> gray;

		public ArrayList<Integer> red;
		public ArrayList<Integer> green;
		public ArrayList<Integer> blue;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(GRAY)) ss.add("gray");
			if (has(RED)) ss.add("red");
			if (has(GREEN)) ss.add("green");
			if (has(BLUE)) ss.add("blue");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLlvCameraLive");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				gray = Xmlio.extractUtinyintvecUclc(doc, basexpath, "gray", "", mask, GRAY);
				red = Xmlio.extractUtinyintvecUclc(doc, basexpath, "red", "", mask, RED);
				green = Xmlio.extractUtinyintvecUclc(doc, basexpath, "green", "", mask, GREEN);
				blue = Xmlio.extractUtinyintvecUclc(doc, basexpath, "blue", "", mask, BLUE);
			} else {
				scrJref = "";
				gray = new ArrayList<Integer>();
				red = new ArrayList<Integer>();
				green = new ArrayList<Integer>();
				blue = new ArrayList<Integer>();
			};
		};

	};

};

