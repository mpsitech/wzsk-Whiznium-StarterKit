/**
  * \file M2msessWzsk.java
  * Java API code for job M2msessWzsk
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class M2msessWzsk {
	/**
	  * StatShr (full: StatShrM2msessWzsk)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFACQPREVIEW = 1;
		public static final int SCRJREFACQPTCLOUD = 2;
		public static final int SCRJREFACTLASER = 3;
		public static final int SCRJREFACTSERVO = 4;
		public static final int SCRJREFIPRCORNER = 5;
		public static final int SCRJREFIPRTRACE = 6;

		public StatShr(
					String scrJrefAcqpreview
					, String scrJrefAcqptcloud
					, String scrJrefActlaser
					, String scrJrefActservo
					, String scrJrefIprcorner
					, String scrJrefIprtrace
				) {
			this.scrJrefAcqpreview = scrJrefAcqpreview;
			this.scrJrefAcqptcloud = scrJrefAcqptcloud;
			this.scrJrefActlaser = scrJrefActlaser;
			this.scrJrefActservo = scrJrefActservo;
			this.scrJrefIprcorner = scrJrefIprcorner;
			this.scrJrefIprtrace = scrJrefIprtrace;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFACQPREVIEW, SCRJREFACQPTCLOUD, SCRJREFACTLASER, SCRJREFACTSERVO, SCRJREFIPRCORNER, SCRJREFIPRTRACE));
		};

		public String scrJrefAcqpreview;
		public String scrJrefAcqptcloud;
		public String scrJrefActlaser;
		public String scrJrefActservo;
		public String scrJrefIprcorner;
		public String scrJrefIprtrace;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrM2msessWzsk");

			String itemtag = "StatitemShrM2msessWzsk";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefAcqpreview = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAcqpreview", mask, SCRJREFACQPREVIEW);
				scrJrefAcqptcloud = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAcqptcloud", mask, SCRJREFACQPTCLOUD);
				scrJrefActlaser = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefActlaser", mask, SCRJREFACTLASER);
				scrJrefActservo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefActservo", mask, SCRJREFACTSERVO);
				scrJrefIprcorner = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefIprcorner", mask, SCRJREFIPRCORNER);
				scrJrefIprtrace = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefIprtrace", mask, SCRJREFIPRTRACE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefAcqpreview.equals(comp.scrJrefAcqpreview)) items.add(SCRJREFACQPREVIEW);
			if (scrJrefAcqptcloud.equals(comp.scrJrefAcqptcloud)) items.add(SCRJREFACQPTCLOUD);
			if (scrJrefActlaser.equals(comp.scrJrefActlaser)) items.add(SCRJREFACTLASER);
			if (scrJrefActservo.equals(comp.scrJrefActservo)) items.add(SCRJREFACTSERVO);
			if (scrJrefIprcorner.equals(comp.scrJrefIprcorner)) items.add(SCRJREFIPRCORNER);
			if (scrJrefIprtrace.equals(comp.scrJrefIprtrace)) items.add(SCRJREFIPRTRACE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFACQPREVIEW, SCRJREFACQPTCLOUD, SCRJREFACTLASER, SCRJREFACTSERVO, SCRJREFIPRCORNER, SCRJREFIPRTRACE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchEngData (full: DpchEngM2msessWzskData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int STATSHR = 2;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGM2MSESSWZSKDATA);

			statshr = new StatShr("", "", "", "", "", "");
		};

		public StatShr statshr;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STATSHR)) ss.add("statshr");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngM2msessWzskData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
			} else {
				scrJref = "";
				statshr = new StatShr("", "", "", "", "", "");
			};
		};

	};

};

