/**
	* \file WzskQObjList.h
	* Java API code for record of table TblWzskQObjList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQObjList {
	
	public WzskQObjList(
				int jnum
				, String Title
				, String stubRefWzskMObjgroup
			) {
		this.jnum = jnum;
		this.Title = Title;
		this.stubRefWzskMObjgroup = stubRefWzskMObjgroup;
	};

	public int jnum;
	public String Title;
	public String stubRefWzskMObjgroup;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQObjList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubRefWzskMObjgroup = Xmlio.extractStringUclc(doc, basexpath, "stubRefWzskMObjgroup", "ogr", null, 0);
			
			return true;
		};

		return false;
	};
};
