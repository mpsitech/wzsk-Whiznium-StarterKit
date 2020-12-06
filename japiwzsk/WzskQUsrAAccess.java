/**
	* \file WzskQUsrAAccess.h
	* Java API code for record of table TblWzskQUsrAAccess
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQUsrAAccess {
	
	public WzskQUsrAAccess(
				int jnum
				, String srefX1IxWzskVFeatgroup
				, String titX1IxWzskVFeatgroup
				, String x2FeaSrefUix
				, String srefsIxWzskWAccess
				, String titsIxWzskWAccess
			) {
		this.jnum = jnum;
		this.srefX1IxWzskVFeatgroup = srefX1IxWzskVFeatgroup;
		this.titX1IxWzskVFeatgroup = titX1IxWzskVFeatgroup;
		this.x2FeaSrefUix = x2FeaSrefUix;
		this.srefsIxWzskWAccess = srefsIxWzskWAccess;
		this.titsIxWzskWAccess = titsIxWzskWAccess;
	};

	public int jnum;
	public String srefX1IxWzskVFeatgroup;
	public String titX1IxWzskVFeatgroup;
	public String x2FeaSrefUix;
	public String srefsIxWzskWAccess;
	public String titsIxWzskWAccess;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQUsrAAccess");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefX1IxWzskVFeatgroup = Xmlio.extractStringUclc(doc, basexpath, "srefX1IxWzskVFeatgroup", "feg", null, 0);
			titX1IxWzskVFeatgroup = Xmlio.extractStringUclc(doc, basexpath, "titX1IxWzskVFeatgroup", "feg2", null, 0);
			x2FeaSrefUix = Xmlio.extractStringUclc(doc, basexpath, "x2FeaSrefUix", "fea", null, 0);
			srefsIxWzskWAccess = Xmlio.extractStringUclc(doc, basexpath, "srefsIxWzskWAccess", "acc", null, 0);
			titsIxWzskWAccess = Xmlio.extractStringUclc(doc, basexpath, "titsIxWzskWAccess", "acc2", null, 0);
			
			return true;
		};

		return false;
	};
};
