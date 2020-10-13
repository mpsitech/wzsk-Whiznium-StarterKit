/**
  * \file PnlWzskSesDetail.java
  * Java API code for job PnlWzskSesDetail
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskSesDetail {
	/**
		* VecVDo (full: VecVWzskSesDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTUSRVIEWCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butusrviewclick")) return BUTUSRVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskSesDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFSTA = 1;
		public static final int TXFSTO = 2;
		public static final int TXFIP = 3;

		public ContIac(
					String TxfSta
					, String TxfSto
					, String TxfIp
				) {
			this.TxfSta = TxfSta;
			this.TxfSto = TxfSto;
			this.TxfIp = TxfIp;

			mask = new HashSet<Integer>(Arrays.asList(TXFSTA, TXFSTO, TXFIP));
		};

		public String TxfSta;
		public String TxfSto;
		public String TxfIp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskSesDetail");

			String itemtag = "ContitemIacWzskSesDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfSta = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSta", mask, TXFSTA);
				TxfSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSto", mask, TXFSTO);
				TxfIp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfIp", mask, TXFIP);

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
			if (difftag.isEmpty()) difftag = "ContIacWzskSesDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskSesDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSta", TxfSta);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSto", TxfSto);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfIp", TxfIp);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfSta.equals(comp.TxfSta)) items.add(TXFSTA);
			if (TxfSto.equals(comp.TxfSto)) items.add(TXFSTO);
			if (TxfIp.equals(comp.TxfIp)) items.add(TXFIP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFSTA, TXFSTO, TXFIP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWzskSesDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTUSR = 1;

		public ContInf(
					String TxtUsr
				) {
			this.TxtUsr = TxtUsr;

			mask = new HashSet<Integer>(Arrays.asList(TXTUSR));
		};

		public String TxtUsr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskSesDetail");

			String itemtag = "ContitemInfWzskSesDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtUsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtUsr", mask, TXTUSR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtUsr.equals(comp.TxtUsr)) items.add(TXTUSR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTUSR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWzskSesDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZSKVEXPSTATE = 1;

		public StatApp(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWzskSesDetail");

			String itemtag = "StatitemAppWzskSesDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVExpstate == comp.ixWzskVExpstate) items.add(IXWZSKVEXPSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
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
	  * StatShr (full: StatShrWzskSesDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTUSRACTIVE = 3;
		public static final int BUTUSRVIEWAVAIL = 4;
		public static final int BUTUSRVIEWACTIVE = 5;
		public static final int TXFSTAACTIVE = 6;
		public static final int TXFSTOACTIVE = 7;
		public static final int TXFIPACTIVE = 8;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtUsrActive
					, boolean ButUsrViewAvail
					, boolean ButUsrViewActive
					, boolean TxfStaActive
					, boolean TxfStoActive
					, boolean TxfIpActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtUsrActive = TxtUsrActive;
			this.ButUsrViewAvail = ButUsrViewAvail;
			this.ButUsrViewActive = ButUsrViewActive;
			this.TxfStaActive = TxfStaActive;
			this.TxfStoActive = TxfStoActive;
			this.TxfIpActive = TxfIpActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTUSRACTIVE, BUTUSRVIEWAVAIL, BUTUSRVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFIPACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtUsrActive;
		public boolean ButUsrViewAvail;
		public boolean ButUsrViewActive;
		public boolean TxfStaActive;
		public boolean TxfStoActive;
		public boolean TxfIpActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskSesDetail");

			String itemtag = "StatitemShrWzskSesDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtUsrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtUsrActive", mask, TXTUSRACTIVE);
				ButUsrViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUsrViewAvail", mask, BUTUSRVIEWAVAIL);
				ButUsrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUsrViewActive", mask, BUTUSRVIEWACTIVE);
				TxfStaActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfStaActive", mask, TXFSTAACTIVE);
				TxfStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfStoActive", mask, TXFSTOACTIVE);
				TxfIpActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfIpActive", mask, TXFIPACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtUsrActive == comp.TxtUsrActive) items.add(TXTUSRACTIVE);
			if (ButUsrViewAvail == comp.ButUsrViewAvail) items.add(BUTUSRVIEWAVAIL);
			if (ButUsrViewActive == comp.ButUsrViewActive) items.add(BUTUSRVIEWACTIVE);
			if (TxfStaActive == comp.TxfStaActive) items.add(TXFSTAACTIVE);
			if (TxfStoActive == comp.TxfStoActive) items.add(TXFSTOACTIVE);
			if (TxfIpActive == comp.TxfIpActive) items.add(TXFIPACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTUSRACTIVE, BUTUSRVIEWAVAIL, BUTUSRVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFIPACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskSesDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTUSR = 2;
		public static final int CPTSTA = 3;
		public static final int CPTSTO = 4;
		public static final int CPTIP = 5;

		public Tag(
					String Cpt
					, String CptUsr
					, String CptSta
					, String CptSto
					, String CptIp
				) {
			this.Cpt = Cpt;
			this.CptUsr = CptUsr;
			this.CptSta = CptSta;
			this.CptSto = CptSto;
			this.CptIp = CptIp;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTUSR, CPTSTA, CPTSTO, CPTIP));
		};

		public String Cpt;
		public String CptUsr;
		public String CptSta;
		public String CptSto;
		public String CptIp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskSesDetail");

			String itemtag = "TagitemWzskSesDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptUsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUsr", mask, CPTUSR);
				CptSta = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSta", mask, CPTSTA);
				CptSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSto", mask, CPTSTO);
				CptIp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIp", mask, CPTIP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptUsr.equals(comp.CptUsr)) items.add(CPTUSR);
			if (CptSta.equals(comp.CptSta)) items.add(CPTSTA);
			if (CptSto.equals(comp.CptSto)) items.add(CPTSTO);
			if (CptIp.equals(comp.CptIp)) items.add(CPTIP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTUSR, CPTSTA, CPTSTO, CPTIP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskSesDetailData)
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
			super(VecWzskVDpch.DPCHAPPWZSKSESDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWzskSesDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskSesDetailDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKSESDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskSesDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskSesDetailData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKSESDETAILDATA);

			contiac = new ContIac("", "", "");
			continf = new ContInf("");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskSesDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "");
				continf = new ContInf("");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};

