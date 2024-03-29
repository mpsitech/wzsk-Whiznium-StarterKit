/**
  * \file CrdWzskLlv.java
  * Java API code for job CrdWzskLlv
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

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
		public static final int INITDONEHEADBAR = 5;
		public static final int INITDONETERMARTY = 6;
		public static final int INITDONETERMCLNXEVB = 7;
		public static final int INITDONETERMICICLE = 8;
		public static final int INITDONETERMMCVEVP = 9;
		public static final int INITDONETERMUVBDVK = 10;
		public static final int INITDONECAMERA = 11;
		public static final int INITDONETTABLE = 12;
		public static final int INITDONELASER = 13;
		public static final int INITDONETERMPWMONUART = 14;
		public static final int INITDONETERMPWMONUSB = 15;

		public StatApp(
					int ixWzskVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
					, boolean initdoneTermArty
					, boolean initdoneTermClnxevb
					, boolean initdoneTermIcicle
					, boolean initdoneTermMcvevp
					, boolean initdoneTermUvbdvk
					, boolean initdoneCamera
					, boolean initdoneTtable
					, boolean initdoneLaser
					, boolean initdoneTermPwmonuart
					, boolean initdoneTermPwmonusb
				) {
			this.ixWzskVReqitmode = ixWzskVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;
			this.initdoneTermArty = initdoneTermArty;
			this.initdoneTermClnxevb = initdoneTermClnxevb;
			this.initdoneTermIcicle = initdoneTermIcicle;
			this.initdoneTermMcvevp = initdoneTermMcvevp;
			this.initdoneTermUvbdvk = initdoneTermUvbdvk;
			this.initdoneCamera = initdoneCamera;
			this.initdoneTtable = initdoneTtable;
			this.initdoneLaser = initdoneLaser;
			this.initdoneTermPwmonuart = initdoneTermPwmonuart;
			this.initdoneTermPwmonusb = initdoneTermPwmonusb;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONETERMARTY, INITDONETERMCLNXEVB, INITDONETERMICICLE, INITDONETERMMCVEVP, INITDONETERMUVBDVK, INITDONECAMERA, INITDONETTABLE, INITDONELASER, INITDONETERMPWMONUART, INITDONETERMPWMONUSB));
		};

		public int ixWzskVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;
		public boolean initdoneTermArty;
		public boolean initdoneTermClnxevb;
		public boolean initdoneTermIcicle;
		public boolean initdoneTermMcvevp;
		public boolean initdoneTermUvbdvk;
		public boolean initdoneCamera;
		public boolean initdoneTtable;
		public boolean initdoneLaser;
		public boolean initdoneTermPwmonuart;
		public boolean initdoneTermPwmonusb;

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
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);
				initdoneTermArty = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTermArty", mask, INITDONETERMARTY);
				initdoneTermClnxevb = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTermClnxevb", mask, INITDONETERMCLNXEVB);
				initdoneTermIcicle = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTermIcicle", mask, INITDONETERMICICLE);
				initdoneTermMcvevp = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTermMcvevp", mask, INITDONETERMMCVEVP);
				initdoneTermUvbdvk = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTermUvbdvk", mask, INITDONETERMUVBDVK);
				initdoneCamera = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCamera", mask, INITDONECAMERA);
				initdoneTtable = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTtable", mask, INITDONETTABLE);
				initdoneLaser = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneLaser", mask, INITDONELASER);
				initdoneTermPwmonuart = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTermPwmonuart", mask, INITDONETERMPWMONUART);
				initdoneTermPwmonusb = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTermPwmonusb", mask, INITDONETERMPWMONUSB);

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
			if (initdoneTermArty == comp.initdoneTermArty) items.add(INITDONETERMARTY);
			if (initdoneTermClnxevb == comp.initdoneTermClnxevb) items.add(INITDONETERMCLNXEVB);
			if (initdoneTermIcicle == comp.initdoneTermIcicle) items.add(INITDONETERMICICLE);
			if (initdoneTermMcvevp == comp.initdoneTermMcvevp) items.add(INITDONETERMMCVEVP);
			if (initdoneTermUvbdvk == comp.initdoneTermUvbdvk) items.add(INITDONETERMUVBDVK);
			if (initdoneCamera == comp.initdoneCamera) items.add(INITDONECAMERA);
			if (initdoneTtable == comp.initdoneTtable) items.add(INITDONETTABLE);
			if (initdoneLaser == comp.initdoneLaser) items.add(INITDONELASER);
			if (initdoneTermPwmonuart == comp.initdoneTermPwmonuart) items.add(INITDONETERMPWMONUART);
			if (initdoneTermPwmonusb == comp.initdoneTermPwmonusb) items.add(INITDONETERMPWMONUSB);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONETERMARTY, INITDONETERMCLNXEVB, INITDONETERMICICLE, INITDONETERMMCVEVP, INITDONETERMUVBDVK, INITDONECAMERA, INITDONETTABLE, INITDONELASER, INITDONETERMPWMONUART, INITDONETERMPWMONUSB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskLlv)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFHEADBAR = 1;
		public static final int SCRJREFTERMARTY = 2;
		public static final int PNLTERMARTYAVAIL = 3;
		public static final int SCRJREFTERMCLNXEVB = 4;
		public static final int PNLTERMCLNXEVBAVAIL = 5;
		public static final int SCRJREFTERMICICLE = 6;
		public static final int PNLTERMICICLEAVAIL = 7;
		public static final int SCRJREFTERMMCVEVP = 8;
		public static final int PNLTERMMCVEVPAVAIL = 9;
		public static final int SCRJREFTERMUVBDVK = 10;
		public static final int PNLTERMUVBDVKAVAIL = 11;
		public static final int SCRJREFCAMERA = 12;
		public static final int SCRJREFTTABLE = 13;
		public static final int SCRJREFLASER = 14;
		public static final int SCRJREFTERMPWMONUART = 15;
		public static final int PNLTERMPWMONUARTAVAIL = 16;
		public static final int SCRJREFTERMPWMONUSB = 17;
		public static final int PNLTERMPWMONUSBAVAIL = 18;

		public StatShr(
					String scrJrefHeadbar
					, String scrJrefTermArty
					, boolean pnltermartyAvail
					, String scrJrefTermClnxevb
					, boolean pnltermclnxevbAvail
					, String scrJrefTermIcicle
					, boolean pnltermicicleAvail
					, String scrJrefTermMcvevp
					, boolean pnltermmcvevpAvail
					, String scrJrefTermUvbdvk
					, boolean pnltermuvbdvkAvail
					, String scrJrefCamera
					, String scrJrefTtable
					, String scrJrefLaser
					, String scrJrefTermPwmonuart
					, boolean pnltermpwmonuartAvail
					, String scrJrefTermPwmonusb
					, boolean pnltermpwmonusbAvail
				) {
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefTermArty = scrJrefTermArty;
			this.pnltermartyAvail = pnltermartyAvail;
			this.scrJrefTermClnxevb = scrJrefTermClnxevb;
			this.pnltermclnxevbAvail = pnltermclnxevbAvail;
			this.scrJrefTermIcicle = scrJrefTermIcicle;
			this.pnltermicicleAvail = pnltermicicleAvail;
			this.scrJrefTermMcvevp = scrJrefTermMcvevp;
			this.pnltermmcvevpAvail = pnltermmcvevpAvail;
			this.scrJrefTermUvbdvk = scrJrefTermUvbdvk;
			this.pnltermuvbdvkAvail = pnltermuvbdvkAvail;
			this.scrJrefCamera = scrJrefCamera;
			this.scrJrefTtable = scrJrefTtable;
			this.scrJrefLaser = scrJrefLaser;
			this.scrJrefTermPwmonuart = scrJrefTermPwmonuart;
			this.pnltermpwmonuartAvail = pnltermpwmonuartAvail;
			this.scrJrefTermPwmonusb = scrJrefTermPwmonusb;
			this.pnltermpwmonusbAvail = pnltermpwmonusbAvail;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFHEADBAR, SCRJREFTERMARTY, PNLTERMARTYAVAIL, SCRJREFTERMCLNXEVB, PNLTERMCLNXEVBAVAIL, SCRJREFTERMICICLE, PNLTERMICICLEAVAIL, SCRJREFTERMMCVEVP, PNLTERMMCVEVPAVAIL, SCRJREFTERMUVBDVK, PNLTERMUVBDVKAVAIL, SCRJREFCAMERA, SCRJREFTTABLE, SCRJREFLASER, SCRJREFTERMPWMONUART, PNLTERMPWMONUARTAVAIL, SCRJREFTERMPWMONUSB, PNLTERMPWMONUSBAVAIL));
		};

		public String scrJrefHeadbar;
		public String scrJrefTermArty;
		public boolean pnltermartyAvail;
		public String scrJrefTermClnxevb;
		public boolean pnltermclnxevbAvail;
		public String scrJrefTermIcicle;
		public boolean pnltermicicleAvail;
		public String scrJrefTermMcvevp;
		public boolean pnltermmcvevpAvail;
		public String scrJrefTermUvbdvk;
		public boolean pnltermuvbdvkAvail;
		public String scrJrefCamera;
		public String scrJrefTtable;
		public String scrJrefLaser;
		public String scrJrefTermPwmonuart;
		public boolean pnltermpwmonuartAvail;
		public String scrJrefTermPwmonusb;
		public boolean pnltermpwmonusbAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLlv");

			String itemtag = "StatitemShrWzskLlv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefTermArty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTermArty", mask, SCRJREFTERMARTY);
				pnltermartyAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnltermartyAvail", mask, PNLTERMARTYAVAIL);
				scrJrefTermClnxevb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTermClnxevb", mask, SCRJREFTERMCLNXEVB);
				pnltermclnxevbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnltermclnxevbAvail", mask, PNLTERMCLNXEVBAVAIL);
				scrJrefTermIcicle = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTermIcicle", mask, SCRJREFTERMICICLE);
				pnltermicicleAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnltermicicleAvail", mask, PNLTERMICICLEAVAIL);
				scrJrefTermMcvevp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTermMcvevp", mask, SCRJREFTERMMCVEVP);
				pnltermmcvevpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnltermmcvevpAvail", mask, PNLTERMMCVEVPAVAIL);
				scrJrefTermUvbdvk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTermUvbdvk", mask, SCRJREFTERMUVBDVK);
				pnltermuvbdvkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnltermuvbdvkAvail", mask, PNLTERMUVBDVKAVAIL);
				scrJrefCamera = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCamera", mask, SCRJREFCAMERA);
				scrJrefTtable = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTtable", mask, SCRJREFTTABLE);
				scrJrefLaser = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefLaser", mask, SCRJREFLASER);
				scrJrefTermPwmonuart = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTermPwmonuart", mask, SCRJREFTERMPWMONUART);
				pnltermpwmonuartAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnltermpwmonuartAvail", mask, PNLTERMPWMONUARTAVAIL);
				scrJrefTermPwmonusb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTermPwmonusb", mask, SCRJREFTERMPWMONUSB);
				pnltermpwmonusbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnltermpwmonusbAvail", mask, PNLTERMPWMONUSBAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefTermArty.equals(comp.scrJrefTermArty)) items.add(SCRJREFTERMARTY);
			if (pnltermartyAvail == comp.pnltermartyAvail) items.add(PNLTERMARTYAVAIL);
			if (scrJrefTermClnxevb.equals(comp.scrJrefTermClnxevb)) items.add(SCRJREFTERMCLNXEVB);
			if (pnltermclnxevbAvail == comp.pnltermclnxevbAvail) items.add(PNLTERMCLNXEVBAVAIL);
			if (scrJrefTermIcicle.equals(comp.scrJrefTermIcicle)) items.add(SCRJREFTERMICICLE);
			if (pnltermicicleAvail == comp.pnltermicicleAvail) items.add(PNLTERMICICLEAVAIL);
			if (scrJrefTermMcvevp.equals(comp.scrJrefTermMcvevp)) items.add(SCRJREFTERMMCVEVP);
			if (pnltermmcvevpAvail == comp.pnltermmcvevpAvail) items.add(PNLTERMMCVEVPAVAIL);
			if (scrJrefTermUvbdvk.equals(comp.scrJrefTermUvbdvk)) items.add(SCRJREFTERMUVBDVK);
			if (pnltermuvbdvkAvail == comp.pnltermuvbdvkAvail) items.add(PNLTERMUVBDVKAVAIL);
			if (scrJrefCamera.equals(comp.scrJrefCamera)) items.add(SCRJREFCAMERA);
			if (scrJrefTtable.equals(comp.scrJrefTtable)) items.add(SCRJREFTTABLE);
			if (scrJrefLaser.equals(comp.scrJrefLaser)) items.add(SCRJREFLASER);
			if (scrJrefTermPwmonuart.equals(comp.scrJrefTermPwmonuart)) items.add(SCRJREFTERMPWMONUART);
			if (pnltermpwmonuartAvail == comp.pnltermpwmonuartAvail) items.add(PNLTERMPWMONUARTAVAIL);
			if (scrJrefTermPwmonusb.equals(comp.scrJrefTermPwmonusb)) items.add(SCRJREFTERMPWMONUSB);
			if (pnltermpwmonusbAvail == comp.pnltermpwmonusbAvail) items.add(PNLTERMPWMONUSBAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFHEADBAR, SCRJREFTERMARTY, PNLTERMARTYAVAIL, SCRJREFTERMCLNXEVB, PNLTERMCLNXEVBAVAIL, SCRJREFTERMICICLE, PNLTERMICICLEAVAIL, SCRJREFTERMMCVEVP, PNLTERMMCVEVPAVAIL, SCRJREFTERMUVBDVK, PNLTERMUVBDVKAVAIL, SCRJREFCAMERA, SCRJREFTTABLE, SCRJREFLASER, SCRJREFTERMPWMONUART, PNLTERMPWMONUARTAVAIL, SCRJREFTERMPWMONUSB, PNLTERMPWMONUSBAVAIL));
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
			statapp = new StatApp(0, 0, "", 0, false, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr("", "", false, "", false, "", false, "", false, "", false, "", "", "", "", false, "", false);
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
				statapp = new StatApp(0, 0, "", 0, false, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr("", "", false, "", false, "", false, "", false, "", false, "", "", "", "", false, "", false);
				tag = new Tag("", "");
			};
		};

	};

};
