/**
	* \file ListWzskQUsrList.java
	* Java API code for record set of table TblWzskQUsrList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWzskQUsrList {

	public ListWzskQUsrList() {
		nodes = new ArrayList<WzskQUsrList>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WzskQUsrList> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WzskQUsrList rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWzskQUsrList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WzskQUsrList", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WzskQUsrList(i+1, "", "", "", "", "", "", "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WzskQUsrList[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
