/**
  * \file CrdWzskScf.java
  * Java API code for job CrdWzskScf
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWzskScf {
	/**
		* VecVDo (full: VecVWzskScfDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITCRDCMMCLICK = 3;
		public static final int MITCRDTTCCLICK = 4;
		public static final int MITCRDLSPCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitcrdcmmclick")) return MITCRDCMMCLICK;
			if (s.equals("mitcrdttcclick")) return MITCRDTTCCLICK;
			if (s.equals("mitcrdlspclick")) return MITCRDLSPCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITCRDCMMCLICK) return("MitCrdCmmClick");
			if (ix == MITCRDTTCCLICK) return("MitCrdTtcClick");
			if (ix == MITCRDLSPCLICK) return("MitCrdLspClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWzskScfSge)
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
	  * ContInf (full: ContInfWzskScf)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;

		public ContInf(
					int numFSge
					, String MrlAppHlp
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP));
		};

		public int numFSge;
		public String MrlAppHlp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskScf");

			String itemtag = "ContitemInfWzskScf";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);

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

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWzskScf)
	  */
	public class StatApp extends Block {

		public static final int IXWZSKVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONECONN = 5;
		public static final int INITDONEGEOM = 6;
		public static final int INITDONEHEADBAR = 7;

		public StatApp(
					int ixWzskVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneConn
					, boolean initdoneGeom
					, boolean initdoneHeadbar
				) {
			this.ixWzskVReqitmode = ixWzskVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneConn = initdoneConn;
			this.initdoneGeom = initdoneGeom;
			this.initdoneHeadbar = initdoneHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONECONN, INITDONEGEOM, INITDONEHEADBAR));
		};

		public int ixWzskVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneConn;
		public boolean initdoneGeom;
		public boolean initdoneHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskScf");

			String itemtag = "StatitemAppWzskScf";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", mask, IXWZSKVREQITMODE);
				ixWzskVReqitmode = VecWzskVReqitmode.getIx(srefIxWzskVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneConn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneConn", mask, INITDONECONN);
				initdoneGeom = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneGeom", mask, INITDONEGEOM);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);

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
			if (initdoneConn == comp.initdoneConn) items.add(INITDONECONN);
			if (initdoneGeom == comp.initdoneGeom) items.add(INITDONEGEOM);
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONECONN, INITDONEGEOM, INITDONEHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskScf)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGCAMERAMAT = 1;
		public static final int SCRJREFDLGLASERPOS = 2;
		public static final int SCRJREFDLGTTABLECOORD = 3;
		public static final int SCRJREFCONN = 4;
		public static final int SCRJREFGEOM = 5;
		public static final int SCRJREFHEADBAR = 6;

		public StatShr(
					String scrJrefDlgcameramat
					, String scrJrefDlglaserpos
					, String scrJrefDlgttablecoord
					, String scrJrefConn
					, String scrJrefGeom
					, String scrJrefHeadbar
				) {
			this.scrJrefDlgcameramat = scrJrefDlgcameramat;
			this.scrJrefDlglaserpos = scrJrefDlglaserpos;
			this.scrJrefDlgttablecoord = scrJrefDlgttablecoord;
			this.scrJrefConn = scrJrefConn;
			this.scrJrefGeom = scrJrefGeom;
			this.scrJrefHeadbar = scrJrefHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGCAMERAMAT, SCRJREFDLGLASERPOS, SCRJREFDLGTTABLECOORD, SCRJREFCONN, SCRJREFGEOM, SCRJREFHEADBAR));
		};

		public String scrJrefDlgcameramat;
		public String scrJrefDlglaserpos;
		public String scrJrefDlgttablecoord;
		public String scrJrefConn;
		public String scrJrefGeom;
		public String scrJrefHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskScf");

			String itemtag = "StatitemShrWzskScf";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgcameramat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgcameramat", mask, SCRJREFDLGCAMERAMAT);
				scrJrefDlglaserpos = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlglaserpos", mask, SCRJREFDLGLASERPOS);
				scrJrefDlgttablecoord = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgttablecoord", mask, SCRJREFDLGTTABLECOORD);
				scrJrefConn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefConn", mask, SCRJREFCONN);
				scrJrefGeom = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefGeom", mask, SCRJREFGEOM);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgcameramat.equals(comp.scrJrefDlgcameramat)) items.add(SCRJREFDLGCAMERAMAT);
			if (scrJrefDlglaserpos.equals(comp.scrJrefDlglaserpos)) items.add(SCRJREFDLGLASERPOS);
			if (scrJrefDlgttablecoord.equals(comp.scrJrefDlgttablecoord)) items.add(SCRJREFDLGTTABLECOORD);
			if (scrJrefConn.equals(comp.scrJrefConn)) items.add(SCRJREFCONN);
			if (scrJrefGeom.equals(comp.scrJrefGeom)) items.add(SCRJREFGEOM);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGCAMERAMAT, SCRJREFDLGLASERPOS, SCRJREFDLGTTABLECOORD, SCRJREFCONN, SCRJREFGEOM, SCRJREFHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskScf)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITCRDCMM = 3;
		public static final int MITCRDTTC = 4;
		public static final int MITCRDLSP = 5;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitCrdCmm
					, String MitCrdTtc
					, String MitCrdLsp
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitCrdCmm = MitCrdCmm;
			this.MitCrdTtc = MitCrdTtc;
			this.MitCrdLsp = MitCrdLsp;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDCMM, MITCRDTTC, MITCRDLSP));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitCrdCmm;
		public String MitCrdTtc;
		public String MitCrdLsp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskScf");

			String itemtag = "TagitemWzskScf";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitCrdCmm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCmm", mask, MITCRDCMM);
				MitCrdTtc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdTtc", mask, MITCRDTTC);
				MitCrdLsp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdLsp", mask, MITCRDLSP);

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
			if (MitCrdCmm.equals(comp.MitCrdCmm)) items.add(MITCRDCMM);
			if (MitCrdTtc.equals(comp.MitCrdTtc)) items.add(MITCRDTTC);
			if (MitCrdLsp.equals(comp.MitCrdLsp)) items.add(MITCRDLSP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDCMM, MITCRDTTC, MITCRDLSP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskScfDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKSCFDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskScfDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskScfData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKSCFDATA);

			continf = new ContInf(0, "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false);
			statshr = new StatShr("", "", "", "", "", "");
			tag = new Tag("", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskScfData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false);
				statshr = new StatShr("", "", "", "", "", "");
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};

