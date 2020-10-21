/**
  * \file DpchAppWzskInit.java
  * Wzsk Java API package init app dispatch block
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

public class DpchAppWzskInit extends DpchAppWzsk {

	public DpchAppWzskInit(
				String scrJref
			) {
		super(VecWzskVDpch.DPCHAPPWZSKINIT, scrJref);
	};
};

