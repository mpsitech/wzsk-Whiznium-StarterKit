/**
  * \file WzskQSes1NShot.h
  * Java API code for record of table TblWzskQSes1NShot
  * \author Catherine Johnson
  * \date created: 6 Oct 2020
  * \date modified: 6 Oct 2020
  */

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQSes1NShot {
	
	public WzskQSes1NShot(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQSes1NShot");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRef = Xmlio.extractStringUclc(doc, basexpath, "stubRef", "ref", null, 0);
			
			return true;
		};

		return false;
	};
};

