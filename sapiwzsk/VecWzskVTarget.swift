/**
  * \file VecWzskVTarget.swift
  * vector VecWzskVTarget
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* VecWzskVTarget
	*/
public struct VecWzskVTarget {
	public static let APALIS: Int = 1
	public static let ARTY: Int = 2
	public static let CLNXEVB: Int = 3
	public static let ICICLE: Int = 4
	public static let MCVEVP: Int = 5
	public static let WS: Int = 6

	public static func getIx(
				_ sref: String
			) -> Int {
		let s: String = sref.lowercased()

		if s == "apalis" {return APALIS}
		if s == "arty" {return ARTY}
		if s == "clnxevb" {return CLNXEVB}
		if s == "icicle" {return ICICLE}
		if s == "mcvevp" {return MCVEVP}
		if s == "ws" {return WS}

		return 0
	}

	public static func getSref(
				_ ix: Int
			) -> String {
		if ix == APALIS {return "apalis"}
		if ix == ARTY {return "arty"}
		if ix == CLNXEVB {return "clnxevb"}
		if ix == ICICLE {return "icicle"}
		if ix == MCVEVP {return "mcvevp"}
		if ix == WS {return "ws"}

		return ""
	}

}
