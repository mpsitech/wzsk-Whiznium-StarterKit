/**
  * \file DpchWzsk.java
  * Wzsk Java API package dispatch block
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

package apiwzsk;

import sbecore.*;

public class DpchWzsk extends Block {

	public DpchWzsk(
				int ixWzskVDpch
			) {
		this.ixWzskVDpch = ixWzskVDpch;
	};

	public int ixWzskVDpch;
};

