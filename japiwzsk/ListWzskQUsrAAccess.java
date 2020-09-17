/**
  * \file ListWzskQUsrAAccess.java
  * Java API code for record set of table TblWzskQUsrAAccess
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWzskQUsrAAccess {

	public ListWzskQUsrAAccess() {
		nodes = new ArrayList<WzskQUsrAAccess>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WzskQUsrAAccess> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WzskQUsrAAccess rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWzskQUsrAAccess");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WzskQUsrAAccess", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WzskQUsrAAccess(i+1, "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WzskQUsrAAccess[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

