/**
	* \file WzskQOgrList.h
	* Java API code for record of table TblWzskQOgrList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQOgrList {
	
	public WzskQOgrList(
				int jnum
				, String sref
				, String Title
				, String stubSupRefWzskMObjgroup
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubSupRefWzskMObjgroup = stubSupRefWzskMObjgroup;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubSupRefWzskMObjgroup;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQOgrList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubSupRefWzskMObjgroup = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWzskMObjgroup", "sup", null, 0);
			
			return true;
		};

		return false;
	};
};

