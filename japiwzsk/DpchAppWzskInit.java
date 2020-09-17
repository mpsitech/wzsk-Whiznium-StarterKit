/**
  * \file DpchAppWzskInit.java
  * Wzsk Java API package init app dispatch block
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

public class DpchAppWzskInit extends DpchAppWzsk {

	public DpchAppWzskInit(
				String scrJref
			) {
		super(VecWzskVDpch.DPCHAPPWZSKINIT, scrJref);
	};
};

