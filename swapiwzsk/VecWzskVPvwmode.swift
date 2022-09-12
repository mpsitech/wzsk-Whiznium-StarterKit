/**
  * \file VecWzskVPvwmode.swift
  * vector VecWzskVPvwmode
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* VecWzskVPvwmode
	*/
public struct VecWzskVPvwmode {
	public static let BINGRAY: Int = 1
	public static let BINREDDOM: Int = 2
	public static let BINRGB: Int = 3
	public static let RAWGRAY: Int = 4
	public static let RAWRGB: Int = 5

	public static func getIx(
				_ sref: String
			) -> Int {
		let s: String = sref.lowercased()

		if s == "bingray" {return BINGRAY}
		if s == "binreddom" {return BINREDDOM}
		if s == "binrgb" {return BINRGB}
		if s == "rawgray" {return RAWGRAY}
		if s == "rawrgb" {return RAWRGB}

		return 0
	}

	public static func getSref(
				_ ix: Int
			) -> String {
		if ix == BINGRAY {return "bingray"}
		if ix == BINREDDOM {return "binreddom"}
		if ix == BINRGB {return "binrgb"}
		if ix == RAWGRAY {return "rawgray"}
		if ix == RAWRGB {return "rawrgb"}

		return ""
	}

}
