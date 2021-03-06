/**
  * \file SessWzsk.java
  * Java API code for job SessWzsk
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class SessWzsk {
	/**
	  * StatShr (full: StatShrSessWzsk)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFCRDNAV = 1;

		public StatShr(
					String scrJrefCrdnav
				) {
			this.scrJrefCrdnav = scrJrefCrdnav;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFCRDNAV));
		};

		public String scrJrefCrdnav;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrSessWzsk");

			String itemtag = "StatitemShrSessWzsk";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefCrdnav = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCrdnav", mask, SCRJREFCRDNAV);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefCrdnav.equals(comp.scrJrefCrdnav)) items.add(SCRJREFCRDNAV);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFCRDNAV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchEngData (full: DpchEngSessWzskData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int FEEDFENSSEC = 2;
		public static final int STATSHR = 3;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGSESSWZSKDATA);

			feedFEnsSec = new Feed("FeedFEnsSec");
			statshr = new StatShr("");
		};

		public Feed feedFEnsSec;
		public StatShr statshr;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(FEEDFENSSEC)) ss.add("feedFEnsSec");
			if (has(STATSHR)) ss.add("statshr");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngSessWzskData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (feedFEnsSec.readXML(doc, basexpath, true)) add(FEEDFENSSEC);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
			} else {
				scrJref = "";
				feedFEnsSec = new Feed("FeedFEnsSec");
				statshr = new StatShr("");
			};
		};

	};

};
