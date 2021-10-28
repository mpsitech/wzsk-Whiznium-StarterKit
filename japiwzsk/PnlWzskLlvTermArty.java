/**
  * \file PnlWzskLlvTermArty.java
  * Java API code for job PnlWzskLlvTermArty
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
	*/
// IP header --- ABOVE

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskLlvTermArty {
	/**
		* VecVDo (full: VecVWzskLlvTermArtyDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;
		public static final int BUTCLAIMCLICK = 3;
		public static final int BUTAPDCLICK = 4;
		public static final int BUTSMTCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butclaimclick")) return BUTCLAIMCLICK;
			if (s.equals("butapdclick")) return BUTAPDCLICK;
			if (s.equals("butsmtclick")) return BUTSMTCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTCLAIMCLICK) return("ButClaimClick");
			if (ix == BUTAPDCLICK) return("ButApdClick");
			if (ix == BUTSMTCLICK) return("ButSmtClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskLlvTermArty)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPCMD = 1;
		public static final int TXFCSQ = 2;

		public ContIac(
					int numFPupCmd
					, String TxfCsq
				) {
			this.numFPupCmd = numFPupCmd;
			this.TxfCsq = TxfCsq;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPCMD, TXFCSQ));
		};

		public int numFPupCmd;
		public String TxfCsq;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskLlvTermArty");

			String itemtag = "ContitemIacWzskLlvTermArty";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupCmd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupCmd", mask, NUMFPUPCMD);
				TxfCsq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCsq", mask, TXFCSQ);

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
			if (difftag.isEmpty()) difftag = "ContIacWzskLlvTermArty";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskLlvTermArty";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupCmd", numFPupCmd);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCsq", TxfCsq);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupCmd == comp.numFPupCmd) items.add(NUMFPUPCMD);
			if (TxfCsq.equals(comp.TxfCsq)) items.add(TXFCSQ);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPCMD, TXFCSQ));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWzskLlvTermArty)
	  */
	public class ContInf extends Block {

		public static final int BUTCLAIMON = 1;
		public static final int TXTCST = 2;
		public static final int TXTDATLOG = 3;

		public ContInf(
					boolean ButClaimOn
					, String TxtCst
					, String TxtDatLog
				) {
			this.ButClaimOn = ButClaimOn;
			this.TxtCst = TxtCst;
			this.TxtDatLog = TxtDatLog;

			mask = new HashSet<Integer>(Arrays.asList(BUTCLAIMON, TXTCST, TXTDATLOG));
		};

		public boolean ButClaimOn;
		public String TxtCst;
		public String TxtDatLog;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskLlvTermArty");

			String itemtag = "ContitemInfWzskLlvTermArty";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButClaimOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButClaimOn", mask, BUTCLAIMON);
				TxtCst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCst", mask, TXTCST);
				TxtDatLog = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtDatLog", mask, TXTDATLOG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButClaimOn == comp.ButClaimOn) items.add(BUTCLAIMON);
			if (TxtCst.equals(comp.TxtCst)) items.add(TXTCST);
			if (TxtDatLog.equals(comp.TxtDatLog)) items.add(TXTDATLOG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCLAIMON, TXTCST, TXTDATLOG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskLlvTermArty)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int BUTCLAIMACTIVE = 2;
		public static final int BUTSMTACTIVE = 3;

		public StatShr(
					int ixWzskVExpstate
					, boolean ButClaimActive
					, boolean ButSmtActive
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.ButClaimActive = ButClaimActive;
			this.ButSmtActive = ButSmtActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTSMTACTIVE));
		};

		public int ixWzskVExpstate;
		public boolean ButClaimActive;
		public boolean ButSmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLlvTermArty");

			String itemtag = "StatitemShrWzskLlvTermArty";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				ButClaimActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClaimActive", mask, BUTCLAIMACTIVE);
				ButSmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSmtActive", mask, BUTSMTACTIVE);

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
			if (ButSmtActive == comp.ButSmtActive) items.add(BUTSMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, BUTSMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskLlvTermArty)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTCST = 2;
		public static final int HDGDIO = 3;
		public static final int HDGCEX = 4;
		public static final int CPTCMD = 5;
		public static final int BUTAPD = 6;
		public static final int CPTCSQ = 7;
		public static final int BUTSMT = 8;

		public Tag(
					String Cpt
					, String CptCst
					, String HdgDio
					, String HdgCex
					, String CptCmd
					, String ButApd
					, String CptCsq
					, String ButSmt
				) {
			this.Cpt = Cpt;
			this.CptCst = CptCst;
			this.HdgDio = HdgDio;
			this.HdgCex = HdgCex;
			this.CptCmd = CptCmd;
			this.ButApd = ButApd;
			this.CptCsq = CptCsq;
			this.ButSmt = ButSmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTCST, HDGDIO, HDGCEX, CPTCMD, BUTAPD, CPTCSQ, BUTSMT));
		};

		public String Cpt;
		public String CptCst;
		public String HdgDio;
		public String HdgCex;
		public String CptCmd;
		public String ButApd;
		public String CptCsq;
		public String ButSmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskLlvTermArty");

			String itemtag = "TagitemWzskLlvTermArty";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptCst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCst", mask, CPTCST);
				HdgDio = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgDio", mask, HDGDIO);
				HdgCex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgCex", mask, HDGCEX);
				CptCmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmd", mask, CPTCMD);
				ButApd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButApd", mask, BUTAPD);
				CptCsq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCsq", mask, CPTCSQ);
				ButSmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSmt", mask, BUTSMT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptCst.equals(comp.CptCst)) items.add(CPTCST);
			if (HdgDio.equals(comp.HdgDio)) items.add(HDGDIO);
			if (HdgCex.equals(comp.HdgCex)) items.add(HDGCEX);
			if (CptCmd.equals(comp.CptCmd)) items.add(CPTCMD);
			if (ButApd.equals(comp.ButApd)) items.add(BUTAPD);
			if (CptCsq.equals(comp.CptCsq)) items.add(CPTCSQ);
			if (ButSmt.equals(comp.ButSmt)) items.add(BUTSMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTCST, HDGDIO, HDGCEX, CPTCMD, BUTAPD, CPTCSQ, BUTSMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskLlvTermArtyData)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVTERMARTYDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvTermArtyData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvTermArtyDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVTERMARTYDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvTermArtyDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskLlvTermArtyData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPCMD = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKLLVTERMARTYDATA);

			contiac = new ContIac(0, "");
			continf = new ContInf(false, "", "");
			feedFPupCmd = new Feed("FeedFPupCmd");
			statshr = new StatShr(0, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupCmd;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPCMD)) ss.add("feedFPupCmd");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLlvTermArtyData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupCmd.readXML(doc, basexpath, true)) add(FEEDFPUPCMD);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "");
				continf = new ContInf(false, "", "");
				feedFPupCmd = new Feed("FeedFPupCmd");
				statshr = new StatShr(0, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};
