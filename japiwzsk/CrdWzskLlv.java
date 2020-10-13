/**
  * \file CrdWzskLlv.java
  * Java API code for job CrdWzskLlv
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWzskLlv {
	/**
		* VecVDo (full: VecVWzskLlvDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWzskLlvSge)
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
	  * ContInf (full: ContInfWzskLlv)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskLlv");

			String itemtag = "ContitemInfWzskLlv";

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
	  * StatApp (full: StatAppWzskLlv)
	  */
	public class StatApp extends Block {

		public static final int IXWZSKVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONETERM = 5;
		public static final int INITDONECAMERA = 6;
		public static final int INITDONETTABLE = 7;
		public static final int INITDONELASER = 8;
		public static final int INITDONEHEADBAR = 9;

		public StatApp(
					int ixWzskVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneTerm
					, boolean initdoneCamera
					, boolean initdoneTtable
					, boolean initdoneLaser
					, boolean initdoneHeadbar
				) {
			this.ixWzskVReqitmode = ixWzskVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneTerm = initdoneTerm;
			this.initdoneCamera = initdoneCamera;
			this.initdoneTtable = initdoneTtable;
			this.initdoneLaser = initdoneLaser;
			this.initdoneHeadbar = initdoneHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONETERM, INITDONECAMERA, INITDONETTABLE, INITDONELASER, INITDONEHEADBAR));
		};

		public int ixWzskVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneTerm;
		public boolean initdoneCamera;
		public boolean initdoneTtable;
		public boolean initdoneLaser;
		public boolean initdoneHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskLlv");

			String itemtag = "StatitemAppWzskLlv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVReqitmode", mask, IXWZSKVREQITMODE);
				ixWzskVReqitmode = VecWzskVReqitmode.getIx(srefIxWzskVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneTerm = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTerm", mask, INITDONETERM);
				initdoneCamera = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCamera", mask, INITDONECAMERA);
				initdoneTtable = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTtable", mask, INITDONETTABLE);
				initdoneLaser = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneLaser", mask, INITDONELASER);
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
			if (initdoneTerm == comp.initdoneTerm) items.add(INITDONETERM);
			if (initdoneCamera == comp.initdoneCamera) items.add(INITDONECAMERA);
			if (initdoneTtable == comp.initdoneTtable) items.add(INITDONETTABLE);
			if (initdoneLaser == comp.initdoneLaser) items.add(INITDONELASER);
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONETERM, INITDONECAMERA, INITDONETTABLE, INITDONELASER, INITDONEHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskLlv)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFTERM = 1;
		public static final int PNLTERMAVAIL = 2;
		public static final int SCRJREFCAMERA = 3;
		public static final int SCRJREFTTABLE = 4;
		public static final int SCRJREFLASER = 5;
		public static final int SCRJREFHEADBAR = 6;

		public StatShr(
					String scrJrefTerm
					, boolean pnltermAvail
					, String scrJrefCamera
					, String scrJrefTtable
					, String scrJrefLaser
					, String scrJrefHeadbar
				) {
			this.scrJrefTerm = scrJrefTerm;
			this.pnltermAvail = pnltermAvail;
			this.scrJrefCamera = scrJrefCamera;
			this.scrJrefTtable = scrJrefTtable;
			this.scrJrefLaser = scrJrefLaser;
			this.scrJrefHeadbar = scrJrefHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFTERM, PNLTERMAVAIL, SCRJREFCAMERA, SCRJREFTTABLE, SCRJREFLASER, SCRJREFHEADBAR));
		};

		public String scrJrefTerm;
		public boolean pnltermAvail;
		public String scrJrefCamera;
		public String scrJrefTtable;
		public String scrJrefLaser;
		public String scrJrefHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLlv");

			String itemtag = "StatitemShrWzskLlv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefTerm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTerm", mask, SCRJREFTERM);
				pnltermAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnltermAvail", mask, PNLTERMAVAIL);
				scrJrefCamera = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCamera", mask, SCRJREFCAMERA);
				scrJrefTtable = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTtable", mask, SCRJREFTTABLE);
				scrJrefLaser = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefLaser", mask, SCRJREFLASER);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefTerm.equals(comp.scrJrefTerm)) items.add(SCRJREFTERM);
			if (pnltermAvail == comp.pnltermAvail) items.add(PNLTERMAVAIL);
			if (scrJrefCamera.equals(comp.scrJrefCamera)) items.add(SCRJREFCAMERA);
			if (scrJrefTtable.equals(comp.scrJrefTtable)) items.add(SCRJREFTTABLE);
			if (scrJrefLaser.equals(comp.scrJrefLaser)) items.add(SCRJREFLASER);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFTERM, PNLTERMAVAIL, SCRJREFCAMERA, SCRJREFTTABLE, SCRJREFLASER, SCRJREFHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskLlv)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP));
		};

		public String MitAppAbt;
		public String MrlAppHlp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskLlv");

			String itemtag = "TagitemWzskLlv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);

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

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKLLVDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLlvDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskLlvData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKLLVDATA);

			continf = new ContInf(0, "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false, false, false);
			statshr = new StatShr("", false, "", "", "", "");
			tag = new Tag("", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLlvData");

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
				statapp = new StatApp(0, 0, "", 0, false, false, false, false, false);
				statshr = new StatShr("", false, "", "", "", "");
				tag = new Tag("", "");
			};
		};

	};

};

