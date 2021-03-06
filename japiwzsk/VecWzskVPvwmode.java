/**
  * \file VecWzskVPvwmode.java
  * vector VecWzskVPvwmode
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwzsk;

public class VecWzskVPvwmode {
	public static final int BINGRAY = 1;
	public static final int BINREDDOM = 2;
	public static final int BINRGB = 3;
	public static final int RAWGRAY = 4;
	public static final int RAWRGB = 5;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("bingray")) return BINGRAY;
		if (s.equals("binreddom")) return BINREDDOM;
		if (s.equals("binrgb")) return BINRGB;
		if (s.equals("rawgray")) return RAWGRAY;
		if (s.equals("rawrgb")) return RAWRGB;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == BINGRAY) return("bingray");
		if (ix == BINREDDOM) return("binreddom");
		if (ix == BINRGB) return("binrgb");
		if (ix == RAWGRAY) return("rawgray");
		if (ix == RAWRGB) return("rawrgb");

		return "";
	};

};
