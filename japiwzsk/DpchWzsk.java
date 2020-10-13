/**
  * \file DpchWzsk.java
  * Wzsk Java API package dispatch block
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
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

