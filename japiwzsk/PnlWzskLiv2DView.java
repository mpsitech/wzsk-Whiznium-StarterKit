/**
  * \file PnlWzskLiv2DView.java
  * Java API code for job PnlWzskLiv2DView
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWzskLiv2DView {
	/**
		* VecVDo (full: VecVWzskLiv2DViewDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;
		public static final int BUTCLAIMCLICK = 3;
		public static final int BUTPLAYCLICK = 4;
		public static final int BUTSTOPCLICK = 5;
		public static final int BUTSTSCLICK = 6;
		public static final int BUTTTBCLICK = 7;
		public static final int BUTLTRCLICK = 8;
		public static final int BUTPICCLICK = 9;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butclaimclick")) return BUTCLAIMCLICK;
			if (s.equals("butplayclick")) return BUTPLAYCLICK;
			if (s.equals("butstopclick")) return BUTSTOPCLICK;
			if (s.equals("butstsclick")) return BUTSTSCLICK;
			if (s.equals("butttbclick")) return BUTTTBCLICK;
			if (s.equals("butltrclick")) return BUTLTRCLICK;
			if (s.equals("butpicclick")) return BUTPICCLICK;

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
			if (ix == BUTSTSCLICK) return("ButStsClick");
			if (ix == BUTTTBCLICK) return("ButTtbClick");
			if (ix == BUTLTRCLICK) return("ButLtrClick");
			if (ix == BUTPICCLICK) return("ButPicClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWzskLiv2DView)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPPVM = 1;
		public static final int SLDFCS = 2;
		public static final int SLDEXT = 3;
		public static final int SLDLLE = 4;
		public static final int SLDLRI = 5;
		public static final int UPDLLO = 6;
		public static final int UPDLUO = 7;
		public static final int UPDLMD = 8;
		public static final int CHKLRO = 9;
		public static final int UPDPNT = 10;
		public static final int CHKPRO = 11;

		public ContIac(
					int numFPupPvm
					, double SldFcs
					, double SldExt
					, double SldLle
					, double SldLri
					, int UpdLlo
					, int UpdLuo
					, int UpdLmd
					, boolean ChkLro
					, int UpdPnt
					, boolean ChkPro
				) {
			this.numFPupPvm = numFPupPvm;
			this.SldFcs = SldFcs;
			this.SldExt = SldExt;
			this.SldLle = SldLle;
			this.SldLri = SldLri;
			this.UpdLlo = UpdLlo;
			this.UpdLuo = UpdLuo;
			this.UpdLmd = UpdLmd;
			this.ChkLro = ChkLro;
			this.UpdPnt = UpdPnt;
			this.ChkPro = ChkPro;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPPVM, SLDFCS, SLDEXT, SLDLLE, SLDLRI, UPDLLO, UPDLUO, UPDLMD, CHKLRO, UPDPNT, CHKPRO));
		};

		public int numFPupPvm;
		public double SldFcs;
		public double SldExt;
		public double SldLle;
		public double SldLri;
		public int UpdLlo;
		public int UpdLuo;
		public int UpdLmd;
		public boolean ChkLro;
		public int UpdPnt;
		public boolean ChkPro;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWzskLiv2DView");

			String itemtag = "ContitemIacWzskLiv2DView";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupPvm = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupPvm", mask, NUMFPUPPVM);
				SldFcs = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFcs", mask, SLDFCS);
				SldExt = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldExt", mask, SLDEXT);
				SldLle = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldLle", mask, SLDLLE);
				SldLri = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldLri", mask, SLDLRI);
				UpdLlo = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "UpdLlo", mask, UPDLLO);
				UpdLuo = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "UpdLuo", mask, UPDLUO);
				UpdLmd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "UpdLmd", mask, UPDLMD);
				ChkLro = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkLro", mask, CHKLRO);
				UpdPnt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "UpdPnt", mask, UPDPNT);
				ChkPro = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkPro", mask, CHKPRO);

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
			if (difftag.isEmpty()) difftag = "ContIacWzskLiv2DView";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWzskLiv2DView";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPvm", numFPupPvm);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFcs", SldFcs);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldExt", SldExt);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldLle", SldLle);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldLri", SldLri);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "UpdLlo", UpdLlo);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "UpdLuo", UpdLuo);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "UpdLmd", UpdLmd);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkLro", ChkLro);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "UpdPnt", UpdPnt);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkPro", ChkPro);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupPvm == comp.numFPupPvm) items.add(NUMFPUPPVM);
			if (Xmlio.compareDouble(SldFcs, comp.SldFcs) < 1.0e-4) items.add(SLDFCS);
			if (Xmlio.compareDouble(SldExt, comp.SldExt) < 1.0e-4) items.add(SLDEXT);
			if (Xmlio.compareDouble(SldLle, comp.SldLle) < 1.0e-4) items.add(SLDLLE);
			if (Xmlio.compareDouble(SldLri, comp.SldLri) < 1.0e-4) items.add(SLDLRI);
			if (UpdLlo == comp.UpdLlo) items.add(UPDLLO);
			if (UpdLuo == comp.UpdLuo) items.add(UPDLUO);
			if (UpdLmd == comp.UpdLmd) items.add(UPDLMD);
			if (ChkLro == comp.ChkLro) items.add(CHKLRO);
			if (UpdPnt == comp.UpdPnt) items.add(UPDPNT);
			if (ChkPro == comp.ChkPro) items.add(CHKPRO);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPPVM, SLDFCS, SLDEXT, SLDLLE, SLDLRI, UPDLLO, UPDLUO, UPDLMD, CHKLRO, UPDPNT, CHKPRO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWzskLiv2DView)
	  */
	public class ContInf extends Block {

		public static final int BUTCLAIMON = 1;
		public static final int TXTOAF = 2;
		public static final int BUTTTBON = 3;
		public static final int BUTLTRON = 4;
		public static final int BUTPICON = 5;

		public ContInf(
					boolean ButClaimOn
					, String TxtOaf
					, boolean ButTtbOn
					, boolean ButLtrOn
					, boolean ButPicOn
				) {
			this.ButClaimOn = ButClaimOn;
			this.TxtOaf = TxtOaf;
			this.ButTtbOn = ButTtbOn;
			this.ButLtrOn = ButLtrOn;
			this.ButPicOn = ButPicOn;

			mask = new HashSet<Integer>(Arrays.asList(BUTCLAIMON, TXTOAF, BUTTTBON, BUTLTRON, BUTPICON));
		};

		public boolean ButClaimOn;
		public String TxtOaf;
		public boolean ButTtbOn;
		public boolean ButLtrOn;
		public boolean ButPicOn;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWzskLiv2DView");

			String itemtag = "ContitemInfWzskLiv2DView";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButClaimOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButClaimOn", mask, BUTCLAIMON);
				TxtOaf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtOaf", mask, TXTOAF);
				ButTtbOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButTtbOn", mask, BUTTTBON);
				ButLtrOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButLtrOn", mask, BUTLTRON);
				ButPicOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButPicOn", mask, BUTPICON);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButClaimOn == comp.ButClaimOn) items.add(BUTCLAIMON);
			if (TxtOaf.equals(comp.TxtOaf)) items.add(TXTOAF);
			if (ButTtbOn == comp.ButTtbOn) items.add(BUTTTBON);
			if (ButLtrOn == comp.ButLtrOn) items.add(BUTLTRON);
			if (ButPicOn == comp.ButPicOn) items.add(BUTPICON);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCLAIMON, TXTOAF, BUTTTBON, BUTLTRON, BUTPICON));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWzskLiv2DView)
	  */
	public class StatShr extends Block {

		public static final int IXWZSKVEXPSTATE = 1;
		public static final int BUTCLAIMACTIVE = 2;
		public static final int SLDFCSAVAIL = 3;
		public static final int SLDFCSACTIVE = 4;
		public static final int SLDFCSMIN = 5;
		public static final int SLDFCSMAX = 6;
		public static final int SLDEXTAVAIL = 7;
		public static final int SLDEXTACTIVE = 8;
		public static final int SLDEXTMIN = 9;
		public static final int SLDEXTMAX = 10;
		public static final int SLDEXTRAST = 11;
		public static final int BUTPLAYACTIVE = 12;
		public static final int BUTSTOPACTIVE = 13;
		public static final int TXTOAFAVAIL = 14;
		public static final int BUTSTSACTIVE = 15;
		public static final int BUTTTBACTIVE = 16;
		public static final int SLDLLEMIN = 17;
		public static final int SLDLLEMAX = 18;
		public static final int SLDLRIMIN = 19;
		public static final int SLDLRIMAX = 20;
		public static final int UPDLLOAVAIL = 21;
		public static final int UPDLLOMIN = 22;
		public static final int UPDLLOMAX = 23;
		public static final int UPDLUOAVAIL = 24;
		public static final int UPDLUOMIN = 25;
		public static final int UPDLUOMAX = 26;
		public static final int UPDLMDAVAIL = 27;
		public static final int UPDLMDMIN = 28;
		public static final int UPDLMDMAX = 29;
		public static final int UPDPNTMIN = 30;
		public static final int UPDPNTMAX = 31;

		public StatShr(
					int ixWzskVExpstate
					, boolean ButClaimActive
					, boolean SldFcsAvail
					, boolean SldFcsActive
					, double SldFcsMin
					, double SldFcsMax
					, boolean SldExtAvail
					, boolean SldExtActive
					, double SldExtMin
					, double SldExtMax
					, double SldExtRast
					, boolean ButPlayActive
					, boolean ButStopActive
					, boolean TxtOafAvail
					, boolean ButStsActive
					, boolean ButTtbActive
					, double SldLleMin
					, double SldLleMax
					, double SldLriMin
					, double SldLriMax
					, boolean UpdLloAvail
					, int UpdLloMin
					, int UpdLloMax
					, boolean UpdLuoAvail
					, int UpdLuoMin
					, int UpdLuoMax
					, boolean UpdLmdAvail
					, int UpdLmdMin
					, int UpdLmdMax
					, int UpdPntMin
					, int UpdPntMax
				) {
			this.ixWzskVExpstate = ixWzskVExpstate;
			this.ButClaimActive = ButClaimActive;
			this.SldFcsAvail = SldFcsAvail;
			this.SldFcsActive = SldFcsActive;
			this.SldFcsMin = SldFcsMin;
			this.SldFcsMax = SldFcsMax;
			this.SldExtAvail = SldExtAvail;
			this.SldExtActive = SldExtActive;
			this.SldExtMin = SldExtMin;
			this.SldExtMax = SldExtMax;
			this.SldExtRast = SldExtRast;
			this.ButPlayActive = ButPlayActive;
			this.ButStopActive = ButStopActive;
			this.TxtOafAvail = TxtOafAvail;
			this.ButStsActive = ButStsActive;
			this.ButTtbActive = ButTtbActive;
			this.SldLleMin = SldLleMin;
			this.SldLleMax = SldLleMax;
			this.SldLriMin = SldLriMin;
			this.SldLriMax = SldLriMax;
			this.UpdLloAvail = UpdLloAvail;
			this.UpdLloMin = UpdLloMin;
			this.UpdLloMax = UpdLloMax;
			this.UpdLuoAvail = UpdLuoAvail;
			this.UpdLuoMin = UpdLuoMin;
			this.UpdLuoMax = UpdLuoMax;
			this.UpdLmdAvail = UpdLmdAvail;
			this.UpdLmdMin = UpdLmdMin;
			this.UpdLmdMax = UpdLmdMax;
			this.UpdPntMin = UpdPntMin;
			this.UpdPntMax = UpdPntMax;

			mask = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, BUTPLAYACTIVE, BUTSTOPACTIVE, TXTOAFAVAIL, BUTSTSACTIVE, BUTTTBACTIVE, SLDLLEMIN, SLDLLEMAX, SLDLRIMIN, SLDLRIMAX, UPDLLOAVAIL, UPDLLOMIN, UPDLLOMAX, UPDLUOAVAIL, UPDLUOMIN, UPDLUOMAX, UPDLMDAVAIL, UPDLMDMIN, UPDLMDMAX, UPDPNTMIN, UPDPNTMAX));
		};

		public int ixWzskVExpstate;
		public boolean ButClaimActive;
		public boolean SldFcsAvail;
		public boolean SldFcsActive;
		public double SldFcsMin;
		public double SldFcsMax;
		public boolean SldExtAvail;
		public boolean SldExtActive;
		public double SldExtMin;
		public double SldExtMax;
		public double SldExtRast;
		public boolean ButPlayActive;
		public boolean ButStopActive;
		public boolean TxtOafAvail;
		public boolean ButStsActive;
		public boolean ButTtbActive;
		public double SldLleMin;
		public double SldLleMax;
		public double SldLriMin;
		public double SldLriMax;
		public boolean UpdLloAvail;
		public int UpdLloMin;
		public int UpdLloMax;
		public boolean UpdLuoAvail;
		public int UpdLuoMin;
		public int UpdLuoMax;
		public boolean UpdLmdAvail;
		public int UpdLmdMin;
		public int UpdLmdMax;
		public int UpdPntMin;
		public int UpdPntMax;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWzskVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWzskLiv2DView");

			String itemtag = "StatitemShrWzskLiv2DView";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", mask, IXWZSKVEXPSTATE);
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate);
				ButClaimActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClaimActive", mask, BUTCLAIMACTIVE);
				SldFcsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsAvail", mask, SLDFCSAVAIL);
				SldFcsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsActive", mask, SLDFCSACTIVE);
				SldFcsMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsMin", mask, SLDFCSMIN);
				SldFcsMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsMax", mask, SLDFCSMAX);
				SldExtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtAvail", mask, SLDEXTAVAIL);
				SldExtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtActive", mask, SLDEXTACTIVE);
				SldExtMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtMin", mask, SLDEXTMIN);
				SldExtMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtMax", mask, SLDEXTMAX);
				SldExtRast = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtRast", mask, SLDEXTRAST);
				ButPlayActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPlayActive", mask, BUTPLAYACTIVE);
				ButStopActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStopActive", mask, BUTSTOPACTIVE);
				TxtOafAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtOafAvail", mask, TXTOAFAVAIL);
				ButStsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStsActive", mask, BUTSTSACTIVE);
				ButTtbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTtbActive", mask, BUTTTBACTIVE);
				SldLleMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLleMin", mask, SLDLLEMIN);
				SldLleMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLleMax", mask, SLDLLEMAX);
				SldLriMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLriMin", mask, SLDLRIMIN);
				SldLriMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldLriMax", mask, SLDLRIMAX);
				UpdLloAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLloAvail", mask, UPDLLOAVAIL);
				UpdLloMin = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLloMin", mask, UPDLLOMIN);
				UpdLloMax = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLloMax", mask, UPDLLOMAX);
				UpdLuoAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLuoAvail", mask, UPDLUOAVAIL);
				UpdLuoMin = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLuoMin", mask, UPDLUOMIN);
				UpdLuoMax = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLuoMax", mask, UPDLUOMAX);
				UpdLmdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLmdAvail", mask, UPDLMDAVAIL);
				UpdLmdMin = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLmdMin", mask, UPDLMDMIN);
				UpdLmdMax = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdLmdMax", mask, UPDLMDMAX);
				UpdPntMin = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdPntMin", mask, UPDPNTMIN);
				UpdPntMax = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdPntMax", mask, UPDPNTMAX);

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
			if (SldFcsAvail == comp.SldFcsAvail) items.add(SLDFCSAVAIL);
			if (SldFcsActive == comp.SldFcsActive) items.add(SLDFCSACTIVE);
			if (Xmlio.compareDouble(SldFcsMin, comp.SldFcsMin) < 1.0e-4) items.add(SLDFCSMIN);
			if (Xmlio.compareDouble(SldFcsMax, comp.SldFcsMax) < 1.0e-4) items.add(SLDFCSMAX);
			if (SldExtAvail == comp.SldExtAvail) items.add(SLDEXTAVAIL);
			if (SldExtActive == comp.SldExtActive) items.add(SLDEXTACTIVE);
			if (Xmlio.compareDouble(SldExtMin, comp.SldExtMin) < 1.0e-4) items.add(SLDEXTMIN);
			if (Xmlio.compareDouble(SldExtMax, comp.SldExtMax) < 1.0e-4) items.add(SLDEXTMAX);
			if (Xmlio.compareDouble(SldExtRast, comp.SldExtRast) < 1.0e-4) items.add(SLDEXTRAST);
			if (ButPlayActive == comp.ButPlayActive) items.add(BUTPLAYACTIVE);
			if (ButStopActive == comp.ButStopActive) items.add(BUTSTOPACTIVE);
			if (TxtOafAvail == comp.TxtOafAvail) items.add(TXTOAFAVAIL);
			if (ButStsActive == comp.ButStsActive) items.add(BUTSTSACTIVE);
			if (ButTtbActive == comp.ButTtbActive) items.add(BUTTTBACTIVE);
			if (Xmlio.compareDouble(SldLleMin, comp.SldLleMin) < 1.0e-4) items.add(SLDLLEMIN);
			if (Xmlio.compareDouble(SldLleMax, comp.SldLleMax) < 1.0e-4) items.add(SLDLLEMAX);
			if (Xmlio.compareDouble(SldLriMin, comp.SldLriMin) < 1.0e-4) items.add(SLDLRIMIN);
			if (Xmlio.compareDouble(SldLriMax, comp.SldLriMax) < 1.0e-4) items.add(SLDLRIMAX);
			if (UpdLloAvail == comp.UpdLloAvail) items.add(UPDLLOAVAIL);
			if (UpdLloMin == comp.UpdLloMin) items.add(UPDLLOMIN);
			if (UpdLloMax == comp.UpdLloMax) items.add(UPDLLOMAX);
			if (UpdLuoAvail == comp.UpdLuoAvail) items.add(UPDLUOAVAIL);
			if (UpdLuoMin == comp.UpdLuoMin) items.add(UPDLUOMIN);
			if (UpdLuoMax == comp.UpdLuoMax) items.add(UPDLUOMAX);
			if (UpdLmdAvail == comp.UpdLmdAvail) items.add(UPDLMDAVAIL);
			if (UpdLmdMin == comp.UpdLmdMin) items.add(UPDLMDMIN);
			if (UpdLmdMax == comp.UpdLmdMax) items.add(UPDLMDMAX);
			if (UpdPntMin == comp.UpdPntMin) items.add(UPDPNTMIN);
			if (UpdPntMax == comp.UpdPntMax) items.add(UPDPNTMAX);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZSKVEXPSTATE, BUTCLAIMACTIVE, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, BUTPLAYACTIVE, BUTSTOPACTIVE, TXTOAFAVAIL, BUTSTSACTIVE, BUTTTBACTIVE, SLDLLEMIN, SLDLLEMAX, SLDLRIMIN, SLDLRIMAX, UPDLLOAVAIL, UPDLLOMIN, UPDLLOMAX, UPDLUOAVAIL, UPDLUOMIN, UPDLUOMAX, UPDLMDAVAIL, UPDLMDMIN, UPDLMDMAX, UPDPNTMIN, UPDPNTMAX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWzskLiv2DView)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPVM = 2;
		public static final int CPTFCS = 3;
		public static final int CPTEXT = 4;
		public static final int CPTOAF = 5;
		public static final int BUTSTS = 6;
		public static final int BUTTTB = 7;
		public static final int HDGLOR = 8;
		public static final int CPTLGL = 9;
		public static final int CPTLLE = 10;
		public static final int CPTLRI = 11;
		public static final int CPTLLO = 12;
		public static final int CPTLUO = 13;
		public static final int CPTLMD = 14;
		public static final int CPTLRO = 15;
		public static final int BUTLTR = 16;
		public static final int BUTLCL = 17;
		public static final int HDGPOS = 18;
		public static final int CPTPNT = 19;
		public static final int CPTPRO = 20;
		public static final int BUTPIC = 21;
		public static final int BUTPCL = 22;

		public Tag(
					String Cpt
					, String CptPvm
					, String CptFcs
					, String CptExt
					, String CptOaf
					, String ButSts
					, String ButTtb
					, String HdgLor
					, String CptLgl
					, String CptLle
					, String CptLri
					, String CptLlo
					, String CptLuo
					, String CptLmd
					, String CptLro
					, String ButLtr
					, String ButLcl
					, String HdgPos
					, String CptPnt
					, String CptPro
					, String ButPic
					, String ButPcl
				) {
			this.Cpt = Cpt;
			this.CptPvm = CptPvm;
			this.CptFcs = CptFcs;
			this.CptExt = CptExt;
			this.CptOaf = CptOaf;
			this.ButSts = ButSts;
			this.ButTtb = ButTtb;
			this.HdgLor = HdgLor;
			this.CptLgl = CptLgl;
			this.CptLle = CptLle;
			this.CptLri = CptLri;
			this.CptLlo = CptLlo;
			this.CptLuo = CptLuo;
			this.CptLmd = CptLmd;
			this.CptLro = CptLro;
			this.ButLtr = ButLtr;
			this.ButLcl = ButLcl;
			this.HdgPos = HdgPos;
			this.CptPnt = CptPnt;
			this.CptPro = CptPro;
			this.ButPic = ButPic;
			this.ButPcl = ButPcl;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPVM, CPTFCS, CPTEXT, CPTOAF, BUTSTS, BUTTTB, HDGLOR, CPTLGL, CPTLLE, CPTLRI, CPTLLO, CPTLUO, CPTLMD, CPTLRO, BUTLTR, BUTLCL, HDGPOS, CPTPNT, CPTPRO, BUTPIC, BUTPCL));
		};

		public String Cpt;
		public String CptPvm;
		public String CptFcs;
		public String CptExt;
		public String CptOaf;
		public String ButSts;
		public String ButTtb;
		public String HdgLor;
		public String CptLgl;
		public String CptLle;
		public String CptLri;
		public String CptLlo;
		public String CptLuo;
		public String CptLmd;
		public String CptLro;
		public String ButLtr;
		public String ButLcl;
		public String HdgPos;
		public String CptPnt;
		public String CptPro;
		public String ButPic;
		public String ButPcl;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWzskLiv2DView");

			String itemtag = "TagitemWzskLiv2DView";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPvm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPvm", mask, CPTPVM);
				CptFcs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFcs", mask, CPTFCS);
				CptExt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptExt", mask, CPTEXT);
				CptOaf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOaf", mask, CPTOAF);
				ButSts = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSts", mask, BUTSTS);
				ButTtb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButTtb", mask, BUTTTB);
				HdgLor = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgLor", mask, HDGLOR);
				CptLgl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLgl", mask, CPTLGL);
				CptLle = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLle", mask, CPTLLE);
				CptLri = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLri", mask, CPTLRI);
				CptLlo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLlo", mask, CPTLLO);
				CptLuo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLuo", mask, CPTLUO);
				CptLmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLmd", mask, CPTLMD);
				CptLro = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLro", mask, CPTLRO);
				ButLtr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButLtr", mask, BUTLTR);
				ButLcl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButLcl", mask, BUTLCL);
				HdgPos = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgPos", mask, HDGPOS);
				CptPnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPnt", mask, CPTPNT);
				CptPro = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPro", mask, CPTPRO);
				ButPic = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButPic", mask, BUTPIC);
				ButPcl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButPcl", mask, BUTPCL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptPvm.equals(comp.CptPvm)) items.add(CPTPVM);
			if (CptFcs.equals(comp.CptFcs)) items.add(CPTFCS);
			if (CptExt.equals(comp.CptExt)) items.add(CPTEXT);
			if (CptOaf.equals(comp.CptOaf)) items.add(CPTOAF);
			if (ButSts.equals(comp.ButSts)) items.add(BUTSTS);
			if (ButTtb.equals(comp.ButTtb)) items.add(BUTTTB);
			if (HdgLor.equals(comp.HdgLor)) items.add(HDGLOR);
			if (CptLgl.equals(comp.CptLgl)) items.add(CPTLGL);
			if (CptLle.equals(comp.CptLle)) items.add(CPTLLE);
			if (CptLri.equals(comp.CptLri)) items.add(CPTLRI);
			if (CptLlo.equals(comp.CptLlo)) items.add(CPTLLO);
			if (CptLuo.equals(comp.CptLuo)) items.add(CPTLUO);
			if (CptLmd.equals(comp.CptLmd)) items.add(CPTLMD);
			if (CptLro.equals(comp.CptLro)) items.add(CPTLRO);
			if (ButLtr.equals(comp.ButLtr)) items.add(BUTLTR);
			if (ButLcl.equals(comp.ButLcl)) items.add(BUTLCL);
			if (HdgPos.equals(comp.HdgPos)) items.add(HDGPOS);
			if (CptPnt.equals(comp.CptPnt)) items.add(CPTPNT);
			if (CptPro.equals(comp.CptPro)) items.add(CPTPRO);
			if (ButPic.equals(comp.ButPic)) items.add(BUTPIC);
			if (ButPcl.equals(comp.ButPcl)) items.add(BUTPCL);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPVM, CPTFCS, CPTEXT, CPTOAF, BUTSTS, BUTTTB, HDGLOR, CPTLGL, CPTLLE, CPTLRI, CPTLLO, CPTLUO, CPTLMD, CPTLRO, BUTLTR, BUTLCL, HDGPOS, CPTPNT, CPTPRO, BUTPIC, BUTPCL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppAlign (full: DpchAppWzskLiv2DViewAlign)
		*/
	public class DpchAppAlign extends DpchAppWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIACCORNER = 2;
		public static final int CONTIACTRACE = 3;
		public static final int ALL = 4;

		public DpchAppAlign(
					String scrJref
					, ContIacCorner contiaccorner
					, ContIacTrace contiactrace
					, Integer[] mask
				) {
			super(VecWzskVDpch.DPCHAPPWZSKLIV2DVIEWALIGN, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIACCORNER, CONTIACTRACE));
					break;
				};

			if (has(CONTIACCORNER)) this.contiaccorner = contiaccorner;
			if (has(CONTIACTRACE)) this.contiactrace = contiactrace;
		};

		public ContIacCorner contiaccorner;
		public ContIacTrace contiactrace;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIACCORNER)) ss.add("contiaccorner");
			if (has(CONTIACTRACE)) ss.add("contiactrace");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWzskLiv2DViewAlign");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIACCORNER)) contiaccorner.writeXML(doc, el, "", true);
			if (has(CONTIACTRACE)) contiactrace.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppData (full: DpchAppWzskLiv2DViewData)
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
			super(VecWzskVDpch.DPCHAPPWZSKLIV2DVIEWDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLiv2DViewData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWzskLiv2DViewDo)
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
			super(VecWzskVDpch.DPCHAPPWZSKLIV2DVIEWDO, scrJref);

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
			Element el = doc.createElement("DpchAppWzskLiv2DViewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngAlign (full: DpchEngWzskLiv2DViewAlign)
		*/
	public class DpchEngAlign extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIACCORNER = 2;
		public static final int CONTIACTRACE = 3;

		public DpchEngAlign() {
			super(VecWzskVDpch.DPCHENGWZSKLIV2DVIEWALIGN);

			contiaccorner = new ContIacCorner(0, 0, 0, 0, 0, 0, 0, 0);
			contiactrace = new ContIacTrace(0, 0, 0, 0, 0, 0, 0, 0);
		};

		public ContIacCorner contiaccorner;
		public ContIacTrace contiactrace;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIACCORNER)) ss.add("contiaccorner");
			if (has(CONTIACTRACE)) ss.add("contiactrace");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLiv2DViewAlign");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiaccorner.readXML(doc, basexpath, true)) add(CONTIACCORNER);
				if (contiactrace.readXML(doc, basexpath, true)) add(CONTIACTRACE);
			} else {
				scrJref = "";
				contiaccorner = new ContIacCorner(0, 0, 0, 0, 0, 0, 0, 0);
				contiactrace = new ContIacTrace(0, 0, 0, 0, 0, 0, 0, 0);
			};
		};

	};

	/**
		* DpchEngData (full: DpchEngWzskLiv2DViewData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPPVM = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGWZSKLIV2DVIEWDATA);

			contiac = new ContIac(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, false, 0, false);
			continf = new ContInf(false, "", false, false, false);
			feedFPupPvm = new Feed("FeedFPupPvm");
			statshr = new StatShr(0, false, false, false, 0.0, 0.0, false, false, 0.0, 0.0, 0.0, false, false, false, false, false, 0.0, 0.0, 0.0, 0.0, false, 0, 0, false, 0, 0, false, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupPvm;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPPVM)) ss.add("feedFPupPvm");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLiv2DViewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupPvm.readXML(doc, basexpath, true)) add(FEEDFPUPPVM);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, false, 0, false);
				continf = new ContInf(false, "", false, false, false);
				feedFPupPvm = new Feed("FeedFPupPvm");
				statshr = new StatShr(0, false, false, false, 0.0, 0.0, false, false, 0.0, 0.0, 0.0, false, false, false, false, false, 0.0, 0.0, 0.0, 0.0, false, 0, 0, false, 0, 0, false, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

	/**
		* DpchEngLive (full: DpchEngWzskLiv2DViewLive)
		*/
	public class DpchEngLive extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int GRAY = 2;
		public static final int RED = 3;
		public static final int GREEN = 4;
		public static final int BLUE = 5;
		public static final int XCORNER = 6;
		public static final int YCORNER = 7;
		public static final int XTRACEL = 8;
		public static final int YTRACEL = 9;
		public static final int XTRACER = 10;
		public static final int YTRACER = 11;

		public DpchEngLive() {
			super(VecWzskVDpch.DPCHENGWZSKLIV2DVIEWLIVE);

		};

		public ArrayList<Integer> gray;

		public ArrayList<Integer> red;
		public ArrayList<Integer> green;
		public ArrayList<Integer> blue;

		public ArrayList<Integer> xCorner;
		public ArrayList<Integer> yCorner;

		public ArrayList<Integer> xTraceL;
		public ArrayList<Integer> yTraceL;

		public ArrayList<Integer> xTraceR;
		public ArrayList<Integer> yTraceR;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(GRAY)) ss.add("gray");
			if (has(RED)) ss.add("red");
			if (has(GREEN)) ss.add("green");
			if (has(BLUE)) ss.add("blue");
			if (has(XCORNER)) ss.add("xCorner");
			if (has(YCORNER)) ss.add("yCorner");
			if (has(XTRACEL)) ss.add("xTraceL");
			if (has(YTRACEL)) ss.add("yTraceL");
			if (has(XTRACER)) ss.add("xTraceR");
			if (has(YTRACER)) ss.add("yTraceR");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWzskLiv2DViewLive");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				gray = Xmlio.extractUtinyintvecUclc(doc, basexpath, "gray", "", mask, GRAY);
				red = Xmlio.extractUtinyintvecUclc(doc, basexpath, "red", "", mask, RED);
				green = Xmlio.extractUtinyintvecUclc(doc, basexpath, "green", "", mask, GREEN);
				blue = Xmlio.extractUtinyintvecUclc(doc, basexpath, "blue", "", mask, BLUE);
				xCorner = Xmlio.extractIntvecUclc(doc, basexpath, "xCorner", "", mask, XCORNER);
				yCorner = Xmlio.extractIntvecUclc(doc, basexpath, "yCorner", "", mask, YCORNER);
				xTraceL = Xmlio.extractIntvecUclc(doc, basexpath, "xTraceL", "", mask, XTRACEL);
				yTraceL = Xmlio.extractIntvecUclc(doc, basexpath, "yTraceL", "", mask, YTRACEL);
				xTraceR = Xmlio.extractIntvecUclc(doc, basexpath, "xTraceR", "", mask, XTRACER);
				yTraceR = Xmlio.extractIntvecUclc(doc, basexpath, "yTraceR", "", mask, YTRACER);
			} else {
				scrJref = "";
				gray = new ArrayList<Integer>();
				red = new ArrayList<Integer>();
				green = new ArrayList<Integer>();
				blue = new ArrayList<Integer>();
				xCorner = new ArrayList<Integer>();
				yCorner = new ArrayList<Integer>();
				xTraceL = new ArrayList<Integer>();
				yTraceL = new ArrayList<Integer>();
				xTraceR = new ArrayList<Integer>();
				yTraceR = new ArrayList<Integer>();
			};
		};

	};

};

