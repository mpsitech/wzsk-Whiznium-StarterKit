/**
  * \file DpchAppWzskResume.java
  * Wzsk Java API package resume app dispatch block
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

package apiwzsk;

public class DpchAppWzskResume extends DpchAppWzsk {

	public DpchAppWzskResume(
				String scrJref
			) {
		super(VecWzskVDpch.DPCHAPPWZSKRESUME, scrJref);
	};
};

