/**
  * \file ListWzskQShtRef1NFile.java
  * Java API code for record set of table TblWzskQShtRef1NFile
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWzskQShtRef1NFile {

	public ListWzskQShtRef1NFile() {
		nodes = new ArrayList<WzskQShtRef1NFile>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WzskQShtRef1NFile> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WzskQShtRef1NFile rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWzskQShtRef1NFile");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WzskQShtRef1NFile", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WzskQShtRef1NFile(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WzskQShtRef1NFile[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

