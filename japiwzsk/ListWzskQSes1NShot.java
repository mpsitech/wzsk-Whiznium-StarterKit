/**
  * \file ListWzskQSes1NShot.java
  * Java API code for record set of table TblWzskQSes1NShot
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWzskQSes1NShot {

	public ListWzskQSes1NShot() {
		nodes = new ArrayList<WzskQSes1NShot>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WzskQSes1NShot> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WzskQSes1NShot rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWzskQSes1NShot");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WzskQSes1NShot", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WzskQSes1NShot(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WzskQSes1NShot[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

