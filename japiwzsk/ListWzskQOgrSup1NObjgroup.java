/**
  * \file ListWzskQOgrSup1NObjgroup.java
  * Java API code for record set of table TblWzskQOgrSup1NObjgroup
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWzskQOgrSup1NObjgroup {

	public ListWzskQOgrSup1NObjgroup() {
		nodes = new ArrayList<WzskQOgrSup1NObjgroup>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WzskQOgrSup1NObjgroup> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WzskQOgrSup1NObjgroup rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWzskQOgrSup1NObjgroup");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WzskQOgrSup1NObjgroup", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WzskQOgrSup1NObjgroup(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WzskQOgrSup1NObjgroup[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

