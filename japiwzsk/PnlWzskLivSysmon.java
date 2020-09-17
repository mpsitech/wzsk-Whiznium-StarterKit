/**
  * \file PnlWzskLivSysmon.java
  * Java API code for job PnlWzskLivSysmon
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskLivSysmon {
	/**
		* VecVDo (full: VecVWzskLivSysmonDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWzskLivSysmon)
	  */
	public class ContInf extends Block {

		public static final int TXTCTP = 1;

		public ContInf(
					String TxtCtp
				) {
			this.TxtCtp = TxtCtp;

			mask = new HashSet<Integer>(Arrays.asList(TXTCTP));
		};

		public String TxtCtp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskLivSysmon");

			String itemtag = "ContitemInfWzskLivSysmon";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtCtp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCtp", mask, TXTCTP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtCtp.equals(comp.TxtCtp)) items.add(TXTCTP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTCTP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskLivSysmon)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;

		public StatShr(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLivSysmon");

			String itemtag = "StatitemShrWzskLivSysmon";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVExpstate == comp.ixWzskVExpstate) items.add(IXWZSKVEXPSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
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
	  * Tag (full: TagWzskLivSysmon)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTCTP = 2;
		public static final int CPTPLTTME = 3;
		public static final int CPTPLTCLD = 4;
		public static final int CPTPLTTOT = 5;
		public static final int CPTPLTCOR = 6;

		public Tag(
					String Cpt
					, String CptCtp
					, String CptPltTme
					, String CptPltCld
					, String CptPltTot
					, String CptPltCor
				) {
			this.Cpt = Cpt;
			this.CptCtp = CptCtp;
			this.CptPltTme = CptPltTme;
			this.CptPltCld = CptPltCld;
			this.CptPltTot = CptPltTot;
			this.CptPltCor = CptPltCor;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTCTP, CPTPLTTME, CPTPLTCLD, CPTPLTTOT, CPTPLTCOR));
		};

		public String Cpt;
		public String CptCtp;
		public String CptPltTme;
		public String CptPltCld;
		public String CptPltTot;
		public String CptPltCor;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskLivSysmon");

			String itemtag = "TagitemWzskLivSysmon";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptCtp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCtp", mask, CPTCTP);
				CptPltTme = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPltTme", mask, CPTPLTTME);
				CptPltCld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPltCld", mask, CPTPLTCLD);
				CptPltTot = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPltTot", mask, CPTPLTTOT);
				CptPltCor = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPltCor", mask, CPTPLTCOR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptCtp.equals(comp.CptCtp)) items.add(CPTCTP);
			if (CptPltTme.equals(comp.CptPltTme)) items.add(CPTPLTTME);
			if (CptPltCld.equals(comp.CptPltCld)) items.add(CPTPLTCLD);
			if (CptPltTot.equals(comp.CptPltTot)) items.add(CPTPLTTOT);
			if (CptPltCor.equals(comp.CptPltCor)) items.add(CPTPLTCOR);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTCTP, CPTPLTTME, CPTPLTCLD, CPTPLTTOT, CPTPLTCOR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskLivSysmonDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKLIVSYSMONDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLivSysmonDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskLivSysmonData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKLIVSYSMONDATA);

			continf = new ContInf("");
			statshr = new StatShr(0);
			tag = new Tag("", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLivSysmonData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statshr = new StatShr(0);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

	/**
		* DpchEngLive (full: DpchEngWzskLivSysmonLive)
		*/
	public class DpchEngLive extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int TS = 2;
		public static final int CLDTOTS = 3;
		public static final int CLD1S = 4;
		public static final int CLD2S = 5;
		public static final int CLD3S = 6;
		public static final int CLD4S = 7;

		public DpchEngLive() {
			super(VecWzskVDpch.DPCHENGWZSKLIVSYSMONLIVE);

		};

		public ArrayList<Float> ts;
		public ArrayList<Float> cldtots;
		public ArrayList<Float> cld1s;
		public ArrayList<Float> cld2s;
		public ArrayList<Float> cld3s;
		public ArrayList<Float> cld4s;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(TS)) ss.add("ts");
			if (has(CLDTOTS)) ss.add("cldtots");
			if (has(CLD1S)) ss.add("cld1s");
			if (has(CLD2S)) ss.add("cld2s");
			if (has(CLD3S)) ss.add("cld3s");
			if (has(CLD4S)) ss.add("cld4s");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLivSysmonLive");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				ts = Xmlio.extractFloatvecUclc(doc, basexpath, "ts", "", mask, TS);
				cldtots = Xmlio.extractFloatvecUclc(doc, basexpath, "cldtots", "", mask, CLDTOTS);
				cld1s = Xmlio.extractFloatvecUclc(doc, basexpath, "cld1s", "", mask, CLD1S);
				cld2s = Xmlio.extractFloatvecUclc(doc, basexpath, "cld2s", "", mask, CLD2S);
				cld3s = Xmlio.extractFloatvecUclc(doc, basexpath, "cld3s", "", mask, CLD3S);
				cld4s = Xmlio.extractFloatvecUclc(doc, basexpath, "cld4s", "", mask, CLD4S);
			} else {
				scrJref = "";
				ts = new ArrayList<Float>();
				cldtots = new ArrayList<Float>();
				cld1s = new ArrayList<Float>();
				cld2s = new ArrayList<Float>();
				cld3s = new ArrayList<Float>();
				cld4s = new ArrayList<Float>();
			};
		};

	};

};

