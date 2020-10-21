/**
  * \file VecWzskVExpstate.java
  * vector VecWzskVExpstate
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

public class VecWzskVExpstate {
	public static final int DETD = 1;
	public static final int MAXD = 2;
	public static final int MIND = 3;
	public static final int REGD = 4;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("detd")) return DETD;
		if (s.equals("maxd")) return MAXD;
		if (s.equals("mind")) return MIND;
		if (s.equals("regd")) return REGD;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == DETD) return("detd");
		if (ix == MAXD) return("maxd");
		if (ix == MIND) return("mind");
		if (ix == REGD) return("regd");

		return "";
	};

};

