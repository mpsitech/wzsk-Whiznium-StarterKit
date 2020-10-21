/**
  * \file ListWzskQUsgAAccess.java
  * Java API code for record set of table TblWzskQUsgAAccess
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWzskQUsgAAccess {

	public ListWzskQUsgAAccess() {
		nodes = new ArrayList<WzskQUsgAAccess>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WzskQUsgAAccess> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WzskQUsgAAccess rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWzskQUsgAAccess");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WzskQUsgAAccess", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WzskQUsgAAccess(i+1, "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WzskQUsgAAccess[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

