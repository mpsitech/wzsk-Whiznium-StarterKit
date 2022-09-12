/**
  * \file VecWzskVTarget.java
  * vector VecWzskVTarget
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
  */
// IP header --- ABOVE

package apiwzsk;

public class VecWzskVTarget {
	public static final int APALIS = 1;
	public static final int ARTY = 2;
	public static final int CLNXEVB = 3;
	public static final int ICICLE = 4;
	public static final int MCVEVP = 5;
	public static final int MERCBB = 6;
	public static final int WS = 7;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("apalis")) return APALIS;
		if (s.equals("arty")) return ARTY;
		if (s.equals("clnxevb")) return CLNXEVB;
		if (s.equals("icicle")) return ICICLE;
		if (s.equals("mcvevp")) return MCVEVP;
		if (s.equals("mercbb")) return MERCBB;
		if (s.equals("ws")) return WS;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == APALIS) return("apalis");
		if (ix == ARTY) return("arty");
		if (ix == CLNXEVB) return("clnxevb");
		if (ix == ICICLE) return("icicle");
		if (ix == MCVEVP) return("mcvevp");
		if (ix == MERCBB) return("mercbb");
		if (ix == WS) return("ws");

		return "";
	};

};
