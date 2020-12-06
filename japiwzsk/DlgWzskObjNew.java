/**
  * \file DlgWzskObjNew.java
  * Java API code for job DlgWzskObjNew
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWzskObjNew {
	/**
		* VecVDo (full: VecVDlgWzskObjNewDo)
		*/
	public static class VecVDo {

		public static final int BUTCNCCLICK = 1;
		public static final int BUTCRECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butcncclick")) return BUTCNCCLICK;
			if (s.equals("butcreclick")) return BUTCRECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTCNCCLICK) return("ButCncClick");
			if (ix == BUTCRECLICK) return("ButCreClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWzskObjNewSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int CREATE = 2;
		public static final int DONE = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("create")) return CREATE;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == CREATE) return("create");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWzskObjNew)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPOGR = 1;
		public static final int TXFTIT = 2;
		public static final int TXFCMT = 3;

		public ContIac(
					int numFPupOgr
					, String TxfTit
					, String TxfCmt
				) {
			this.numFPupOgr = numFPupOgr;
			this.TxfTit = TxfTit;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPOGR, TXFTIT, TXFCMT));
		};

		public int numFPupOgr;
		public String TxfTit;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWzskObjNew");

			String itemtag = "ContitemIacDlgWzskObjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupOgr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupOgr", mask, NUMFPUPOGR);
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTit", mask, TXFTIT);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWzskObjNew";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWzskObjNew";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupOgr", numFPupOgr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupOgr == comp.numFPupOgr) items.add(NUMFPUPOGR);
			if (TxfTit.equals(comp.TxfTit)) items.add(TXFTIT);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPOGR, TXFTIT, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWzskObjNew)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;

		public ContInf(
					int numFSge
				) {
			this.numFSge = numFSge;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE));
		};

		public int numFSge;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWzskObjNew");

			String itemtag = "ContitemInfDlgWzskObjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWzskObjNew)
	  */
	public class StatApp extends Block {

		public static final int SHORTMENU = 1;

		public StatApp(
					String shortMenu
				) {
			this.shortMenu = shortMenu;

			mask = new HashSet<Integer>(Arrays.asList(SHORTMENU));
		};

		public String shortMenu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWzskObjNew");

			String itemtag = "StatitemAppDlgWzskObjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SHORTMENU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWzskObjNew)
	  */
	public class StatShr extends Block {

		public static final int BUTCNCACTIVE = 1;
		public static final int BUTCREACTIVE = 2;

		public StatShr(
					boolean ButCncActive
					, boolean ButCreActive
				) {
			this.ButCncActive = ButCncActive;
			this.ButCreActive = ButCreActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTCNCACTIVE, BUTCREACTIVE));
		};

		public boolean ButCncActive;
		public boolean ButCreActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWzskObjNew");

			String itemtag = "StatitemShrDlgWzskObjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButCncActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCncActive", mask, BUTCNCACTIVE);
				ButCreActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCreActive", mask, BUTCREACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButCncActive == comp.ButCncActive) items.add(BUTCNCACTIVE);
			if (ButCreActive == comp.ButCreActive) items.add(BUTCREACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCNCACTIVE, BUTCREACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWzskObjNew)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTOGR = 2;
		public static final int CPTTIT = 3;
		public static final int CPTCMT = 4;
		public static final int BUTCNC = 5;
		public static final int BUTCRE = 6;

		public Tag(
					String Cpt
					, String CptOgr
					, String CptTit
					, String CptCmt
					, String ButCnc
					, String ButCre
				) {
			this.Cpt = Cpt;
			this.CptOgr = CptOgr;
			this.CptTit = CptTit;
			this.CptCmt = CptCmt;
			this.ButCnc = ButCnc;
			this.ButCre = ButCre;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTOGR, CPTTIT, CPTCMT, BUTCNC, BUTCRE));
		};

		public String Cpt;
		public String CptOgr;
		public String CptTit;
		public String CptCmt;
		public String ButCnc;
		public String ButCre;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWzskObjNew");

			String itemtag = "TagitemDlgWzskObjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptOgr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOgr", mask, CPTOGR);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);
				ButCnc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButCnc", mask, BUTCNC);
				ButCre = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButCre", mask, BUTCRE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptOgr.equals(comp.CptOgr)) items.add(CPTOGR);
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);
			if (ButCnc.equals(comp.ButCnc)) items.add(BUTCNC);
			if (ButCre.equals(comp.ButCre)) items.add(BUTCRE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTOGR, CPTTIT, CPTCMT, BUTCNC, BUTCRE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWzskObjNewData)
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
			super(VecWzskVDpch.DPCHAPPDLGWZSKOBJNEWDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWzskObjNewData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWzskObjNewDo)
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
			super(VecWzskVDpch.DPCHAPPDLGWZSKOBJNEWDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWzskObjNewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWzskObjNewData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPOGR = 4;
		public static final int FEEDFSGE = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGDLGWZSKOBJNEWDATA);

			contiac = new ContIac(0, "", "");
			continf = new ContInf(0);
			feedFPupOgr = new Feed("FeedFPupOgr");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("");
			statshr = new StatShr(false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupOgr;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPOGR)) ss.add("feedFPupOgr");
			if (has(FEEDFSGE)) ss.add("feedFSge");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWzskObjNewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupOgr.readXML(doc, basexpath, true)) add(FEEDFPUPOGR);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "");
				continf = new ContInf(0);
				feedFPupOgr = new Feed("FeedFPupOgr");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp("");
				statshr = new StatShr(false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};
