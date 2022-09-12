/**
  * \file VecWzskVReqitmode.swift
  * vector VecWzskVReqitmode
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* VecWzskVReqitmode
	*/
public struct VecWzskVReqitmode {
	public static let IDLE: Int = 1
	public static let NOTIFY: Int = 2
	public static let POLL: Int = 3

	public static func getIx(
				_ sref: String
			) -> Int {
		let s: String = sref.lowercased()

		if s == "idle" {return IDLE}
		if s == "notify" {return NOTIFY}
		if s == "poll" {return POLL}

		return 0
	}

	public static func getSref(
				_ ix: Int
			) -> String {
		if ix == IDLE {return "idle"}
		if ix == NOTIFY {return "notify"}
		if ix == POLL {return "poll"}

		return ""
	}

}
