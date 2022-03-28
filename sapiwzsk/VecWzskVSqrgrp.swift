/**
  * \file VecWzskVSqrgrp.swift
  * vector VecWzskVSqrgrp
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* VecWzskVSqrgrp
	*/
public struct VecWzskVSqrgrp {
	public static let R0: Int = 1
	public static let R1: Int = 2
	public static let R2: Int = 3
	public static let R3: Int = 4
	public static let S0: Int = 5
	public static let S1: Int = 6
	public static let S2: Int = 7
	public static let S3: Int = 8

	public static func getIx(
				_ sref: String
			) -> Int {
		let s: String = sref.lowercased()

		if s == "r0" {return R0}
		if s == "r1" {return R1}
		if s == "r2" {return R2}
		if s == "r3" {return R3}
		if s == "s0" {return S0}
		if s == "s1" {return S1}
		if s == "s2" {return S2}
		if s == "s3" {return S3}

		return 0
	}

	public static func getSref(
				_ ix: Int
			) -> String {
		if ix == R0 {return "r0"}
		if ix == R1 {return "r1"}
		if ix == R2 {return "r2"}
		if ix == R3 {return "r3"}
		if ix == S0 {return "s0"}
		if ix == S1 {return "s1"}
		if ix == S2 {return "s2"}
		if ix == S3 {return "s3"}

		return ""
	}

}
