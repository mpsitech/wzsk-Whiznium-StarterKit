/**
  * \file VecWzskVReqitmode.java
  * vector VecWzskVReqitmode
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwzsk;

public class VecWzskVReqitmode {
	public static final int IDLE = 1;
	public static final int NOTIFY = 2;
	public static final int POLL = 3;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("idle")) return IDLE;
		if (s.equals("notify")) return NOTIFY;
		if (s.equals("poll")) return POLL;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == IDLE) return("idle");
		if (ix == NOTIFY) return("notify");
		if (ix == POLL) return("poll");

		return "";
	};

};

