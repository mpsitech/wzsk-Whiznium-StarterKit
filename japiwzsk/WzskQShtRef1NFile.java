/**
  * \file WzskQShtRef1NFile.h
  * Java API code for record of table TblWzskQShtRef1NFile
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQShtRef1NFile {
	
	public WzskQShtRef1NFile(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQShtRef1NFile");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRef = Xmlio.extractStringUclc(doc, basexpath, "stubRef", "ref", null, 0);
			
			return true;
		};

		return false;
	};
};
