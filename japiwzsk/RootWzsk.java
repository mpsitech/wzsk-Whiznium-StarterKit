/**
  * \file RootWzsk.java
  * Java API code for job RootWzsk
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class RootWzsk {
	/**
		* DpchAppLogin (full: DpchAppRootWzskLogin)
		*/
	public class DpchAppLogin extends DpchAppWzsk {

		public static final int SCRJREF = 1;
		public static final int USERNAME = 2;
		public static final int PASSWORD = 3;
		public static final int M2MNOTREG = 4;
		public static final int CHKSUSPSESS = 5;
		public static final int ALL = 6;

		public DpchAppLogin(
					String scrJref
					, String username
					, String password
					, boolean m2mNotReg
					, boolean chksuspsess
					, Integer[] mask
				) {
			super(VecWzskVDpch.DPCHAPPROOTWZSKLOGIN, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, USERNAME, PASSWORD, M2MNOTREG, CHKSUSPSESS));
					break;
				};

			this.username = username;
			this.password = password;
			this.m2mNotReg = m2mNotReg;
			this.chksuspsess = chksuspsess;
		};

		public String username;
		public String password;
		public boolean m2mNotReg;
		public boolean chksuspsess;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(USERNAME)) ss.add("username");
			if (has(PASSWORD)) ss.add("password");
			if (has(M2MNOTREG)) ss.add("m2mNotReg");
			if (has(CHKSUSPSESS)) ss.add("chksuspsess");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppRootWzskLogin");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(USERNAME)) Xmlio.writeString(doc, el, "username", username);
			if (has(PASSWORD)) Xmlio.writeString(doc, el, "password", password);
			if (has(M2MNOTREG)) Xmlio.writeBoolean(doc, el, "m2mNotReg", m2mNotReg);
			if (has(CHKSUSPSESS)) Xmlio.writeBoolean(doc, el, "chksuspsess", chksuspsess);
		};

	};

	/**
		* DpchEngData (full: DpchEngRootWzskData)
		*/
	public class DpchEngData extends DpchEngWzsk {

		public static final int SCRJREF = 1;
		public static final int FEEDFENSSPS = 2;

		public DpchEngData() {
			super(VecWzskVDpch.DPCHENGROOTWZSKDATA);

			feedFEnsSps = new Feed("FeedFEnsSps");
		};

		public Feed feedFEnsSps;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(FEEDFENSSPS)) ss.add("feedFEnsSps");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngRootWzskData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (feedFEnsSps.readXML(doc, basexpath, true)) add(FEEDFENSSPS);
			} else {
				scrJref = "";
				feedFEnsSps = new Feed("FeedFEnsSps");
			};
		};

	};

};

