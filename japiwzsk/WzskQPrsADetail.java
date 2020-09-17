/**
  * \file WzskQPrsADetail.h
  * Java API code for record of table TblWzskQPrsADetail
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQPrsADetail {
	
	public WzskQPrsADetail(
				int jnum
				, String x1SrefKType
				, String titX1SrefKType
				, String Val
			) {
		this.jnum = jnum;
		this.x1SrefKType = x1SrefKType;
		this.titX1SrefKType = titX1SrefKType;
		this.Val = Val;
	};

	public int jnum;
	public String x1SrefKType;
	public String titX1SrefKType;
	public String Val;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQPrsADetail");

		if (Xmlio.checkXPath(doc, basexpath)) {
			x1SrefKType = Xmlio.extractStringUclc(doc, basexpath, "x1SrefKType", "typ", null, 0);
			titX1SrefKType = Xmlio.extractStringUclc(doc, basexpath, "titX1SrefKType", "typ2", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			
			return true;
		};

		return false;
	};
};

