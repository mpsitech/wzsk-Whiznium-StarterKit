/**
  * \file WzskQOgrSup1NObjgroup.h
  * Java API code for record of table TblWzskQOgrSup1NObjgroup
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQOgrSup1NObjgroup {
	
	public WzskQOgrSup1NObjgroup(
				int jnum
				, String stubRef
			) {
		this.jnum = jnum;
		this.stubRef = stubRef;
	};

	public int jnum;
	public String stubRef;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQOgrSup1NObjgroup");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRef = Xmlio.extractStringUclc(doc, basexpath, "stubRef", "ref", null, 0);
			
			return true;
		};

		return false;
	};
};

