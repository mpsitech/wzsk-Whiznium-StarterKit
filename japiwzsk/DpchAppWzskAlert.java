/**
	* \file DpchAppWzskAlert.java
	* Wzsk Java API package alert app dispatch block
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchAppWzskAlert extends DpchAppWzsk {

	public static final int SCRJREF = 1;
	public static final int NUMFMCB = 2;
	public static final int ALL = 3;

	public DpchAppWzskAlert(
				String scrJref
				, int numFMcb
				, Integer[] mask
			) {
		super(VecWzskVDpch.DPCHAPPWZSKALERT, scrJref);

		this.numFMcb = numFMcb;

		for (Integer i: mask)
			if (i == ALL) {
				this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, NUMFMCB));
				return;
			};

		this.mask = new HashSet<Integer>(Arrays.asList(mask));
	};
	
	public int numFMcb;

	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(SCRJREF)) return false;
		if (!items.contains(NUMFMCB)) return false;
	
		return true;
	};
	
	public String getSrefsMask() {
		ArrayList<String> ss = new ArrayList<String>();
		
		if (has(SCRJREF)) ss.add("scrJref");
		if (has(NUMFMCB)) ss.add("numFMcb");
	
		return StrMod.vectorToString(ss, ';');
	};

	public void writeXML(
				Document doc
				, Element sup
			) {
		Element el = doc.createElement("DpchAppWzskAlert");
	
		if (sup == null) doc.appendChild(el);
		else sup.appendChild(el);
	
		el.setAttribute("xmlns", "http://www.mpsitech.com/wzsk");
		
		if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
		if (has(NUMFMCB)) Xmlio.writeInteger(doc, el, "numFMcb", numFMcb);
	};
};
