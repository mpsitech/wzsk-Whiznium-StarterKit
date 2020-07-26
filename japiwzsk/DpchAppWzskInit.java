/**
  * \file DpchAppWzskInit.java
  * Wzsk Java API package init app dispatch block
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

package apiwzsk;

public class DpchAppWzskInit extends DpchAppWzsk {

	public DpchAppWzskInit(
				String scrJref
			) {
		super(VecWzskVDpch.DPCHAPPWZSKINIT, scrJref);
	};
};

