/**
  * \file DpchAppWzskInit.java
  * Wzsk Java API package init app dispatch block
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

package apiwzsk;

public class DpchAppWzskInit extends DpchAppWzsk {

	public DpchAppWzskInit(
				String scrJref
			) {
		super(VecWzskVDpch.DPCHAPPWZSKINIT, scrJref);
	};
};

