/**
  * \file SessWzsk.swift
  * Swift API code for job SessWzsk
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* SessWzsk
	*/
public class SessWzsk {
	/**
	  * StatShr (full: StatShrSessWzsk)
	  */
	public class StatShr: Block {

		public static let SCRJREFCRDNAV: Int = 1

		public init(
					_ scrJrefCrdnav: String = ""
				) {
			self.scrJrefCrdnav = scrJrefCrdnav

			super.init()

			mask = [StatShr.SCRJREFCRDNAV]
		}

		public var scrJrefCrdnav: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrSessWzsk")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrSessWzsk"

			if valid {
				scrJrefCrdnav = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefCrdnav", &mask, StatShr.SCRJREFCRDNAV)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if scrJrefCrdnav == comp.scrJrefCrdnav {items.insert(StatShr.SCRJREFCRDNAV)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.SCRJREFCRDNAV]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchEngData (full: DpchEngSessWzskData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let FEEDFENSSEC: Int = 2
		public static let STATSHR: Int = 3

		public init() {
			super.init(VecWzskVDpch.DPCHENGSESSWZSKDATA)
		}

		public var feedFEnsSec: Feed = Feed("FeedFEnsSec")
		public var statshr: StatShr = StatShr()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.FEEDFENSSEC) {ss.append("feedFEnsSec")}
			if has(DpchEngData.STATSHR) {ss.append("statshr")}

			return StrMod.vectorToString(ss)
		}

		public override func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngSessWzskData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if feedFEnsSec.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFENSSEC)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
			} else {
				scrJref = ""
				feedFEnsSec = Feed("FeedFEnsSec")
				statshr = StatShr()
			}
		}

	}

}
