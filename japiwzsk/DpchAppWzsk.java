/**
  * \file DpchAppWzsk.java
  * Wzsk Java API package app dispatch block
  * \author Catherine Johnson
  * \date created: 6 Oct 2020
  * \date modified: 6 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchAppWzsk extends DpchWzsk {

	public static final int SCRJREF = 1;
	
	public DpchAppWzsk(
				int ixWzskVDpch
				, String scrJref
			) {
		super(ixWzskVDpch);
		
		this.scrJref = scrJref;
		
		mask = new HashSet<Integer>(Arrays.asList(SCRJREF));
	};

	public String scrJref;
	
	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(SCRJREF)) return false;

		return true;
	};
	
	public String getSrefsMask() {
		if (has(SCRJREF)) return("scrJref");
		
		return "";
	};
	
	public void writeXML(
				Document doc
				, Element sup
			) {
		Element el = doc.createElement(VecWzskVDpch.getSref(ixWzskVDpch));

		if (sup == null) doc.appendChild(el);
		else sup.appendChild(el);

		el.setAttribute("xmlns", "http://www.mpsitech.com/wzsk");
		
		if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
	};
};

