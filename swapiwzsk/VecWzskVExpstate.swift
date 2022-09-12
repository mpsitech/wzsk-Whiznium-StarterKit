/**
  * \file VecWzskVExpstate.swift
  * vector VecWzskVExpstate
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* VecWzskVExpstate
	*/
public struct VecWzskVExpstate {
	public static let DETD: Int = 1
	public static let MAXD: Int = 2
	public static let MIND: Int = 3
	public static let REGD: Int = 4

	public static func getIx(
				_ sref: String
			) -> Int {
		let s: String = sref.lowercased()

		if s == "detd" {return DETD}
		if s == "maxd" {return MAXD}
		if s == "mind" {return MIND}
		if s == "regd" {return REGD}

		return 0
	}

	public static func getSref(
				_ ix: Int
			) -> String {
		if ix == DETD {return "detd"}
		if ix == MAXD {return "maxd"}
		if ix == MIND {return "mind"}
		if ix == REGD {return "regd"}

		return ""
	}

}
