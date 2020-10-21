/**
  * \file ListWzskQOgr1NObject.java
  * Java API code for record set of table TblWzskQOgr1NObject
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWzskQOgr1NObject {

	public ListWzskQOgr1NObject() {
		nodes = new ArrayList<WzskQOgr1NObject>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WzskQOgr1NObject> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WzskQOgr1NObject rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWzskQOgr1NObject");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WzskQOgr1NObject", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WzskQOgr1NObject(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WzskQOgr1NObject[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

