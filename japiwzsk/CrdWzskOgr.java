/**
  * \file CrdWzskOgr.java
  * Java API code for job CrdWzskOgr
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWzskOgr {
	/**
		* VecVDo (full: VecVWzskOgrDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITCRDNEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitcrdnewclick")) return MITCRDNEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWzskOgrSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRWZSKABT = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrwzskabt")) return ALRWZSKABT;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRWZSKABT) return("alrwzskabt");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWzskOgr)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MTXCRDOGR = 3;

		public ContInf(
					int numFSge
					, String MrlAppHlp
					, String MtxCrdOgr
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;
			this.MtxCrdOgr = MtxCrdOgr;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDOGR));
		};

		public int numFSge;
		public String MrlAppHlp;
		public String MtxCrdOgr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskOgr");

			String itemtag = "ContitemInfWzskOgr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MtxCrdOgr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxCrdOgr", mask, MTXCRDOGR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);
			if (MtxCrdOgr.equals(comp.MtxCrdOgr)) items.add(MTXCRDOGR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDOGR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWzskOgr)
	  */
	public class StatApp extends Block {

		public static final int IXWZSKVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEHEADBAR = 5;
		public static final int INITDONELIST = 6;
		public static final int INITDONEREC = 7;

		public StatApp(
					int ixWzskVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
					, boolean initdoneList
					, boolean initdoneRec
				) {
			this.ixWzskVReqitmode = ixWzskVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;
			this.initdoneList = initdoneList;
			this.initdoneRec = initdoneRec;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC));
		};

		public int ixWzskVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;
		public boolean initdoneList;
		public boolean initdoneRec;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskOgr");

			String itemtag = "StatitemAppWzskOgr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", mask, IXWZSKVREQITMODE);
				ixWzskVReqitmode = VecWzskVReqitmode.getIx(srefIxWzskVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);
				initdoneList = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneList", mask, INITDONELIST);
				initdoneRec = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRec", mask, INITDONEREC);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVReqitmode == comp.ixWzskVReqitmode) items.add(IXWZSKVREQITMODE);
			if (latency == comp.latency) items.add(LATENCY);
			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);
			if (widthMenu == comp.widthMenu) items.add(WIDTHMENU);
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);
			if (initdoneList == comp.initdoneList) items.add(INITDONELIST);
			if (initdoneRec == comp.initdoneRec) items.add(INITDONEREC);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskOgr)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGNEW = 1;
		public static final int SCRJREFHEADBAR = 2;
		public static final int SCRJREFLIST = 3;
		public static final int SCRJREFREC = 4;
		public static final int MSPCRD1AVAIL = 5;
		public static final int MITCRDNEWAVAIL = 6;

		public StatShr(
					String scrJrefDlgnew
					, String scrJrefHeadbar
					, String scrJrefList
					, String scrJrefRec
					, boolean MspCrd1Avail
					, boolean MitCrdNewAvail
				) {
			this.scrJrefDlgnew = scrJrefDlgnew;
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefList = scrJrefList;
			this.scrJrefRec = scrJrefRec;
			this.MspCrd1Avail = MspCrd1Avail;
			this.MitCrdNewAvail = MitCrdNewAvail;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGNEW, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL));
		};

		public String scrJrefDlgnew;
		public String scrJrefHeadbar;
		public String scrJrefList;
		public String scrJrefRec;
		public boolean MspCrd1Avail;
		public boolean MitCrdNewAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskOgr");

			String itemtag = "StatitemShrWzskOgr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgnew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", mask, SCRJREFDLGNEW);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefList = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefList", mask, SCRJREFLIST);
				scrJrefRec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRec", mask, SCRJREFREC);
				MspCrd1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", mask, MSPCRD1AVAIL);
				MitCrdNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", mask, MITCRDNEWAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgnew.equals(comp.scrJrefDlgnew)) items.add(SCRJREFDLGNEW);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefList.equals(comp.scrJrefList)) items.add(SCRJREFLIST);
			if (scrJrefRec.equals(comp.scrJrefRec)) items.add(SCRJREFREC);
			if (MspCrd1Avail == comp.MspCrd1Avail) items.add(MSPCRD1AVAIL);
			if (MitCrdNewAvail == comp.MitCrdNewAvail) items.add(MITCRDNEWAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGNEW, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskOgr)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITCRDNEW = 3;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitCrdNew
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitCrdNew = MitCrdNew;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitCrdNew;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskOgr");

			String itemtag = "TagitemWzskOgr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitCrdNew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdNew", mask, MITCRDNEW);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MitAppAbt.equals(comp.MitAppAbt)) items.add(MITAPPABT);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);
			if (MitCrdNew.equals(comp.MitCrdNew)) items.add(MITCRDNEW);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskOgrDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKOGRDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskOgrDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskOgrData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKOGRDATA);

			continf = new ContInf(0, "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false);
			statshr = new StatShr("", "", "", "", false, false);
			tag = new Tag("", "", "");
		};

		public ContInf continf;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskOgrData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "", "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false);
				statshr = new StatShr("", "", "", "", false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};

