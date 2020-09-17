/**
  * \file WzskQUsrMNUsergroup.h
  * Java API code for record of table TblWzskQUsrMNUsergroup
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQUsrMNUsergroup {
	
	public WzskQUsrMNUsergroup(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQUsrMNUsergroup");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxWzskVUserlevel", "ulv", null, 0);
			titIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxWzskVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};

