/**
  * \file PnlWzskNavHeadbar.swift
  * Swift API code for job PnlWzskNavHeadbar
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskNavHeadbar
	*/
public class PnlWzskNavHeadbar {
	/**
	  * StatShr (full: StatShrWzskNavHeadbar)
	  */
	public class StatShr: Block {

		public static let MENCRDAVAIL: Int = 1

		public init(
					_ MenCrdAvail: Bool = false
				) {
			self.MenCrdAvail = MenCrdAvail

			super.init()

			mask = [StatShr.MENCRDAVAIL]
		}

		public var MenCrdAvail: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskNavHeadbar")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskNavHeadbar"

			if valid {
				MenCrdAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MenCrdAvail", &mask, StatShr.MENCRDAVAIL)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if MenCrdAvail == comp.MenCrdAvail {items.insert(StatShr.MENCRDAVAIL)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.MENCRDAVAIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StgInf (full: StgInfWzskNavHeadbar)
	  */
	public class StgInf: Block {

		public static let MENAPPCPTWIDTH: Int = 1
		public static let MENAPPWIDTH: Int = 2
		public static let MENSESCPTWIDTH: Int = 3
		public static let MENSESWIDTH: Int = 4
		public static let MENCRDCPTWIDTH: Int = 5
		public static let MENCRDWIDTH: Int = 6

		public init(
					_ MenAppCptwidth: Int = 0
					, _ MenAppWidth: Int = 0
					, _ MenSesCptwidth: Int = 0
					, _ MenSesWidth: Int = 0
					, _ MenCrdCptwidth: Int = 0
					, _ MenCrdWidth: Int = 0
				) {
			self.MenAppCptwidth = MenAppCptwidth
			self.MenAppWidth = MenAppWidth
			self.MenSesCptwidth = MenSesCptwidth
			self.MenSesWidth = MenSesWidth
			self.MenCrdCptwidth = MenCrdCptwidth
			self.MenCrdWidth = MenCrdWidth

			super.init()

			mask = [StgInf.MENAPPCPTWIDTH, StgInf.MENAPPWIDTH, StgInf.MENSESCPTWIDTH, StgInf.MENSESWIDTH, StgInf.MENCRDCPTWIDTH, StgInf.MENCRDWIDTH]
		}

		public var MenAppCptwidth: Int
		public var MenAppWidth: Int
		public var MenSesCptwidth: Int
		public var MenSesWidth: Int
		public var MenCrdCptwidth: Int
		public var MenCrdWidth: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StgInfWzskNavHeadbar")}
			valid = basexpath != nil

			let itemtag: String = "StgitemnfWzskNavHeadbar"

			if valid {
				MenAppCptwidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "MenAppCptwidth", &mask, StgInf.MENAPPCPTWIDTH)
				MenAppWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "MenAppWidth", &mask, StgInf.MENAPPWIDTH)
				MenSesCptwidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "MenSesCptwidth", &mask, StgInf.MENSESCPTWIDTH)
				MenSesWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "MenSesWidth", &mask, StgInf.MENSESWIDTH)
				MenCrdCptwidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "MenCrdCptwidth", &mask, StgInf.MENCRDCPTWIDTH)
				MenCrdWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "MenCrdWidth", &mask, StgInf.MENCRDWIDTH)
			}

			return valid
		}

		public func comm(
					_ comp: StgInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if MenAppCptwidth == comp.MenAppCptwidth {items.insert(StgInf.MENAPPCPTWIDTH)}
			if MenAppWidth == comp.MenAppWidth {items.insert(StgInf.MENAPPWIDTH)}
			if MenSesCptwidth == comp.MenSesCptwidth {items.insert(StgInf.MENSESCPTWIDTH)}
			if MenSesWidth == comp.MenSesWidth {items.insert(StgInf.MENSESWIDTH)}
			if MenCrdCptwidth == comp.MenCrdCptwidth {items.insert(StgInf.MENCRDCPTWIDTH)}
			if MenCrdWidth == comp.MenCrdWidth {items.insert(StgInf.MENCRDWIDTH)}

			return items
		}

		public func diff(
					_ comp: StgInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StgInf.MENAPPCPTWIDTH, StgInf.MENAPPWIDTH, StgInf.MENSESCPTWIDTH, StgInf.MENSESWIDTH, StgInf.MENCRDCPTWIDTH, StgInf.MENCRDWIDTH]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskNavHeadbar)
	  */
	public class Tag: Block {

		public static let MENAPP: Int = 1
		public static let MENSES: Int = 2
		public static let MENCRD: Int = 3

		public init(
					_ MenApp: String = ""
					, _ MenSes: String = ""
					, _ MenCrd: String = ""
				) {
			self.MenApp = MenApp
			self.MenSes = MenSes
			self.MenCrd = MenCrd

			super.init()

			mask = [Tag.MENAPP, Tag.MENSES, Tag.MENCRD]
		}

		public var MenApp: String
		public var MenSes: String
		public var MenCrd: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskNavHeadbar")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskNavHeadbar"

			if valid {
				MenApp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MenApp", &mask, Tag.MENAPP)
				MenSes = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MenSes", &mask, Tag.MENSES)
				MenCrd = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MenCrd", &mask, Tag.MENCRD)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if MenApp == comp.MenApp {items.insert(Tag.MENAPP)}
			if MenSes == comp.MenSes {items.insert(Tag.MENSES)}
			if MenCrd == comp.MenCrd {items.insert(Tag.MENCRD)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.MENAPP, Tag.MENSES, Tag.MENCRD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskNavHeadbarData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let STATSHR: Int = 2
		public static let STGINF: Int = 3
		public static let TAG: Int = 4

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKNAVHEADBARDATA)
		}

		public var statshr: StatShr = StatShr()
		public var stginf: StgInf = StgInf()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.STATSHR) {ss.append("statshr")}
			if has(DpchEngData.STGINF) {ss.append("stginf")}
			if has(DpchEngData.TAG) {ss.append("tag")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskNavHeadbarData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if stginf.readXML(doc, basexpath!, true) {add(DpchEngData.STGINF)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				statshr = StatShr()
				stginf = StgInf()
				tag = Tag()
			}
		}

	}

}
