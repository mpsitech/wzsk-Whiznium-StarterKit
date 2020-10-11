/**
  * \file DpchEngWzskAlert.java
  * Wzsk Java API package alert engine dispatch block
  * \author Catherine Johnson
  * \date created: 6 Oct 2020
  * \date modified: 6 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchEngWzskAlert extends DpchEngWzsk {

	public static final int SCRJREF = 1;
	public static final int CONTINF = 2;
	public static final int FEEDFMCB = 3;

	public DpchEngWzskAlert() {
		super(VecWzskVDpch.DPCHENGWZSKALERT);
		
		continf = new ContInfWzskAlert("", "", "", "", "", "", "", "", "", "", "", "", "");
		feedFMcb = new Feed("FeedFMcb");
	};

	public ContInfWzskAlert continf;
	public Feed feedFMcb;

	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(SCRJREF)) return false;
		if (!items.contains(CONTINF)) return false;
		if (!items.contains(FEEDFMCB)) return false;
	
		return true;
	};

	public String getSrefsMask() {
		ArrayList<String> ss = new ArrayList<String>();

		if (has(SCRJREF)) ss.add("scrJref");
		if (has(CONTINF)) ss.add("continf");
		if (has(FEEDFMCB)) ss.add("feedFMcb");

		return StrMod.vectorToString(ss, ';');
	};

	public void readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		clear();
		
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, VecWzskVDpch.getSref(ixWzskVDpch));
	
		if (Xmlio.checkXPath(doc, basexpath)) {
			scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
			if (continf.readXML(doc, basexpath, true)) add(CONTINF);
			if (feedFMcb.readXML(doc, basexpath, true)) add(FEEDFMCB);
		} else {
			continf = new ContInfWzskAlert("", "", "", "", "", "", "", "", "", "", "", "", "");
			feedFMcb.clear();
		};
	};
};

