/**
  * \file WzskQSesList.h
  * Java API code for record of table TblWzskQSesList
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQSesList {
	
	public WzskQSesList(
				int jnum
				, String stubRefWzskMUser
				, String ftmStart
				, String ftmStop
				, String Ip
			) {
		this.jnum = jnum;
		this.stubRefWzskMUser = stubRefWzskMUser;
		this.ftmStart = ftmStart;
		this.ftmStop = ftmStop;
		this.Ip = Ip;
	};

	public int jnum;
	public String stubRefWzskMUser;
	public String ftmStart;
	public String ftmStop;
	public String Ip;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQSesList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRefWzskMUser = Xmlio.extractStringUclc(doc, basexpath, "stubRefWzskMUser", "usr", null, 0);
			ftmStart = Xmlio.extractStringUclc(doc, basexpath, "ftmStart", "sta", null, 0);
			ftmStop = Xmlio.extractStringUclc(doc, basexpath, "ftmStop", "sto", null, 0);
			Ip = Xmlio.extractStringUclc(doc, basexpath, "Ip", "ip", null, 0);
			
			return true;
		};

		return false;
	};
};

