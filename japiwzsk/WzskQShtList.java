/**
	* \file WzskQShtList.h
	* Java API code for record of table TblWzskQShtList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQShtList {
	
	public WzskQShtList(
				int jnum
				, String stubRefWzskMSession
				, String stubRefWzskMObject
				, String ftmStart
			) {
		this.jnum = jnum;
		this.stubRefWzskMSession = stubRefWzskMSession;
		this.stubRefWzskMObject = stubRefWzskMObject;
		this.ftmStart = ftmStart;
	};

	public int jnum;
	public String stubRefWzskMSession;
	public String stubRefWzskMObject;
	public String ftmStart;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQShtList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRefWzskMSession = Xmlio.extractStringUclc(doc, basexpath, "stubRefWzskMSession", "ses", null, 0);
			stubRefWzskMObject = Xmlio.extractStringUclc(doc, basexpath, "stubRefWzskMObject", "obj", null, 0);
			ftmStart = Xmlio.extractStringUclc(doc, basexpath, "ftmStart", "sta", null, 0);
			
			return true;
		};

		return false;
	};
};
