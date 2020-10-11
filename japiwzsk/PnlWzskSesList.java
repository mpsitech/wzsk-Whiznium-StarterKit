/**
  * \file PnlWzskSesList.java
  * Java API code for job PnlWzskSesList
  * \author Catherine Johnson
  * \date created: 6 Oct 2020
  * \date modified: 6 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskSesList {
	/**
		* VecVDo (full: VecVWzskSesListDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;
		public static final int BUTNEWCLICK = 3;
		public static final int BUTDELETECLICK = 4;
		public static final int BUTFILTERCLICK = 5;
		public static final int BUTREFRESHCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butfilterclick")) return BUTFILTERCLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTFILTERCLICK) return("ButFilterClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskSesList)
	  */
	public class ContIac extends Block {

		public static final int NUMFTOS = 1;

		public ContIac(
					int numFTos
				) {
			this.numFTos = numFTos;

			mask = new HashSet<Integer>(Arrays.asList(NUMFTOS));
		};

		public int numFTos;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskSesList");

			String itemtag = "ContitemIacWzskSesList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFTos = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFTos", mask, NUMFTOS);

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
			if (difftag.isEmpty()) difftag = "ContIacWzskSesList";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskSesList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFTos", numFTos);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFTos == comp.numFTos) items.add(NUMFTOS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFTOS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWzskSesList)
	  */
	public class ContInf extends Block {

		public static final int BUTFILTERON = 1;
		public static final int NUMFCSIQST = 2;

		public ContInf(
					boolean ButFilterOn
					, int numFCsiQst
				) {
			this.ButFilterOn = ButFilterOn;
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(BUTFILTERON, NUMFCSIQST));
		};

		public boolean ButFilterOn;
		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskSesList");

			String itemtag = "ContitemInfWzskSesList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButFilterOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButFilterOn", mask, BUTFILTERON);
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButFilterOn == comp.ButFilterOn) items.add(BUTFILTERON);
			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTFILTERON, NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskSesList)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int BUTDELETEACTIVE = 2;

		public StatShr(
					int ixWzskVExpstate
					, boolean ButDeleteActive
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTDELETEACTIVE));
		};

		public int ixWzskVExpstate;
		public boolean ButDeleteActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskSesList");

			String itemtag = "StatitemShrWzskSesList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				ButDeleteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteActive", mask, BUTDELETEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWzskVExpstate == comp.ixWzskVExpstate) items.add(IXWZSKVEXPSTATE);
			if (ButDeleteActive == comp.ButDeleteActive) items.add(BUTDELETEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWzskSesList)
	  */
	public class StgIac extends Block {

		public static final int TCOUSRWIDTH = 1;
		public static final int TCOSTAWIDTH = 2;
		public static final int TCOSTOWIDTH = 3;
		public static final int TCOIPWIDTH = 4;

		public StgIac(
					int TcoUsrWidth
					, int TcoStaWidth
					, int TcoStoWidth
					, int TcoIpWidth
				) {
			this.TcoUsrWidth = TcoUsrWidth;
			this.TcoStaWidth = TcoStaWidth;
			this.TcoStoWidth = TcoStoWidth;
			this.TcoIpWidth = TcoIpWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOUSRWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOIPWIDTH));
		};

		public int TcoUsrWidth;
		public int TcoStaWidth;
		public int TcoStoWidth;
		public int TcoIpWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWzskSesList");

			String itemtag = "StgitemIacWzskSesList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoUsrWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoUsrWidth", mask, TCOUSRWIDTH);
				TcoStaWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoStaWidth", mask, TCOSTAWIDTH);
				TcoStoWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoStoWidth", mask, TCOSTOWIDTH);
				TcoIpWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIpWidth", mask, TCOIPWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWzskSesList";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWzskSesList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoUsrWidth", TcoUsrWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoStaWidth", TcoStaWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoStoWidth", TcoStoWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIpWidth", TcoIpWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoUsrWidth == comp.TcoUsrWidth) items.add(TCOUSRWIDTH);
			if (TcoStaWidth == comp.TcoStaWidth) items.add(TCOSTAWIDTH);
			if (TcoStoWidth == comp.TcoStoWidth) items.add(TCOSTOWIDTH);
			if (TcoIpWidth == comp.TcoIpWidth) items.add(TCOIPWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOUSRWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOIPWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskSesList)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOUSR = 7;
		public static final int TCOSTA = 8;
		public static final int TCOSTO = 9;
		public static final int TCOIP = 10;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoUsr
					, String TcoSta
					, String TcoSto
					, String TcoIp
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoUsr = TcoUsr;
			this.TcoSta = TcoSta;
			this.TcoSto = TcoSto;
			this.TcoIp = TcoIp;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOUSR, TCOSTA, TCOSTO, TCOIP));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoUsr;
		public String TcoSta;
		public String TcoSto;
		public String TcoIp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskSesList");

			String itemtag = "TagitemWzskSesList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoUsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoUsr", mask, TCOUSR);
				TcoSta = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSta", mask, TCOSTA);
				TcoSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSto", mask, TCOSTO);
				TcoIp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp", mask, TCOIP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (TxtRecord1.equals(comp.TxtRecord1)) items.add(TXTRECORD1);
			if (TxtRecord2.equals(comp.TxtRecord2)) items.add(TXTRECORD2);
			if (Trs.equals(comp.Trs)) items.add(TRS);
			if (TxtShowing1.equals(comp.TxtShowing1)) items.add(TXTSHOWING1);
			if (TxtShowing2.equals(comp.TxtShowing2)) items.add(TXTSHOWING2);
			if (TcoUsr.equals(comp.TcoUsr)) items.add(TCOUSR);
			if (TcoSta.equals(comp.TcoSta)) items.add(TCOSTA);
			if (TcoSto.equals(comp.TcoSto)) items.add(TCOSTO);
			if (TcoIp.equals(comp.TcoIp)) items.add(TCOIP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOUSR, TCOSTA, TCOSTO, TCOIP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskSesListData)
		*/
	public class DpchAppData extends DpchAppWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int STGIAC = 3;
		public static final int STGIACQRY = 4;
		public static final int ALL = 5;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, StgIac stgiac
					, QryWzskSesList.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWzskVDpch.DPCHAPPWZSKSESLISTDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC, STGIAC, STGIACQRY));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public ContIac contiac;
		public StgIac stgiac;
		public QryWzskSesList.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWzskSesListData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskSesListDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKSESLISTDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskSesListDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskSesListData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFCSIQST = 4;
		public static final int FEEDFTOS = 5;
		public static final int STATSHR = 6;
		public static final int STGIAC = 7;
		public static final int TAG = 8;
		public static final int RST = 9;
		public static final int STATAPPQRY = 10;
		public static final int STATSHRQRY = 11;
		public static final int STGIACQRY = 12;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKSESLISTDATA);

			contiac = new ContIac(0);
			continf = new ContInf(false, 0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			feedFTos = new Feed("FeedFTos");
			statshr = new StatShr(0, false);
			stgiac = new StgIac(0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
			rst = new ListWzskQSesList();
			statappqry = (new QryWzskSesList()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWzskSesList()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWzskSesList()).new StgIac(0, 0, 0);
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFCsiQst;
		public Feed feedFTos;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWzskQSesList rst;
		public QryWzskSesList.StatApp statappqry;
		public QryWzskSesList.StatShr statshrqry;
		public QryWzskSesList.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(FEEDFTOS)) ss.add("feedFTos");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(TAG)) ss.add("tag");
			if (has(RST)) ss.add("rst");
			if (has(STATAPPQRY)) ss.add("statappqry");
			if (has(STATSHRQRY)) ss.add("statshrqry");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskSesListData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (feedFTos.readXML(doc, basexpath, true)) add(FEEDFTOS);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf(false, 0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				feedFTos = new Feed("FeedFTos");
				statshr = new StatShr(0, false);
				stgiac = new StgIac(0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWzskSesList()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWzskSesList()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWzskSesList()).new StgIac(0, 0, 0);
			};
		};

	};

};

