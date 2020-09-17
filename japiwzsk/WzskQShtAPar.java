/**
  * \file WzskQShtAPar.h
  * Java API code for record of table TblWzskQShtAPar
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import org.w3c.dom.*;
import sbecore.*;

public class WzskQShtAPar {
	
	public WzskQShtAPar(
				int jnum
				, String x1SrefKKey
				, String titX1SrefKKey
				, String Val
			) {
		this.jnum = jnum;
		this.x1SrefKKey = x1SrefKKey;
		this.titX1SrefKKey = titX1SrefKKey;
		this.Val = Val;
	};

	public int jnum;
	public String x1SrefKKey;
	public String titX1SrefKKey;
	public String Val;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WzskQShtAPar");

		if (Xmlio.checkXPath(doc, basexpath)) {
			x1SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "x1SrefKKey", "key", null, 0);
			titX1SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "titX1SrefKKey", "key2", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			
			return true;
		};

		return false;
	};
};

