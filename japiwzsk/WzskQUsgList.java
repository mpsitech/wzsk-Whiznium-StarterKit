/**
  * \file WzskQUsgList.h
  * Java API code for record of table TblWzskQUsgList
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQUsgList {
	
	public WzskQUsgList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String sref
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.sref = sref;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String sref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQUsgList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			
			return true;
		};

		return false;
	};
};

