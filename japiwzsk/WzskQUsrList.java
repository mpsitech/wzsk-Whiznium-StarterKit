/**
	* \file WzskQUsrList.h
	* Java API code for record of table TblWzskQUsrList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQUsrList {
	
	public WzskQUsrList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String stubRefWzskMPerson
				, String sref
				, String stubRefWzskMUsergroup
				, String srefIxVState
				, String titIxVState
				, String srefIxWzskVLocale
				, String titIxWzskVLocale
				, String srefIxWzskVUserlevel
				, String titIxWzskVUserlevel
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.stubRefWzskMPerson = stubRefWzskMPerson;
		this.sref = sref;
		this.stubRefWzskMUsergroup = stubRefWzskMUsergroup;
		this.srefIxVState = srefIxVState;
		this.titIxVState = titIxVState;
		this.srefIxWzskVLocale = srefIxWzskVLocale;
		this.titIxWzskVLocale = titIxWzskVLocale;
		this.srefIxWzskVUserlevel = srefIxWzskVUserlevel;
		this.titIxWzskVUserlevel = titIxWzskVUserlevel;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String stubRefWzskMPerson;
	public String sref;
	public String stubRefWzskMUsergroup;
	public String srefIxVState;
	public String titIxVState;
	public String srefIxWzskVLocale;
	public String titIxWzskVLocale;
	public String srefIxWzskVUserlevel;
	public String titIxWzskVUserlevel;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQUsrList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			stubRefWzskMPerson = Xmlio.extractStringUclc(doc, basexpath, "stubRefWzskMPerson", "prs", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWzskMUsergroup = Xmlio.extractStringUclc(doc, basexpath, "stubRefWzskMUsergroup", "usg", null, 0);
			srefIxVState = Xmlio.extractStringUclc(doc, basexpath, "srefIxVState", "ste", null, 0);
			titIxVState = Xmlio.extractStringUclc(doc, basexpath, "titIxVState", "ste2", null, 0);
			srefIxWzskVLocale = Xmlio.extractStringUclc(doc, basexpath, "srefIxWzskVLocale", "lcl", null, 0);
			titIxWzskVLocale = Xmlio.extractStringUclc(doc, basexpath, "titIxWzskVLocale", "lcl2", null, 0);
			srefIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxWzskVUserlevel", "ulv", null, 0);
			titIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxWzskVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};

