/**
	* \file WzskQUsgMNUser.h
	* Java API code for record of table TblWzskQUsgMNUser
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQUsgMNUser {
	
	public WzskQUsgMNUser(
				int jnum
				, String stubMref
				, String srefIxWzskVUserlevel
				, String titIxWzskVUserlevel
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.srefIxWzskVUserlevel = srefIxWzskVUserlevel;
		this.titIxWzskVUserlevel = titIxWzskVUserlevel;
	};

	public int jnum;
	public String stubMref;
	public String srefIxWzskVUserlevel;
	public String titIxWzskVUserlevel;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQUsgMNUser");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxWzskVUserlevel", "ulv", null, 0);
			titIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxWzskVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};
