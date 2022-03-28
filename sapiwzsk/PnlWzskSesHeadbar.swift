/**
  * \file PnlWzskSesHeadbar.swift
  * Swift API code for job PnlWzskSesHeadbar
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskSesHeadbar
	*/
public class PnlWzskSesHeadbar {
	/**
	  * StgInf (full: StgInfWzskSesHeadbar)
	  */
	public class StgInf: Block {

		public static let MENAPPCPTWIDTH: Int = 1
		public static let MENAPPWIDTH: Int = 2
		public static let MENCRDCPTWIDTH: Int = 3
		public static let MENCRDWIDTH: Int = 4

		public init(
					_ MenAppCptwidth: Int = 0
					, _ MenAppWidth: Int = 0
					, _ MenCrdCptwidth: Int = 0
					, _ MenCrdWidth: Int = 0
				) {
			self.MenAppCptwidth = MenAppCptwidth
			self.MenAppWidth = MenAppWidth
			self.MenCrdCptwidth = MenCrdCptwidth
			self.MenCrdWidth = MenCrdWidth

			super.init()

			mask = [StgInf.MENAPPCPTWIDTH, StgInf.MENAPPWIDTH, StgInf.MENCRDCPTWIDTH, StgInf.MENCRDWIDTH]
		}

		public var MenAppCptwidth: Int
		public var MenAppWidth: Int
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StgInfWzskSesHeadbar")}
			valid = basexpath != nil

			let itemtag: String = "StgitemnfWzskSesHeadbar"

			if valid {
				MenAppCptwidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "MenAppCptwidth", &mask, StgInf.MENAPPCPTWIDTH)
				MenAppWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "MenAppWidth", &mask, StgInf.MENAPPWIDTH)
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
			if MenCrdCptwidth == comp.MenCrdCptwidth {items.insert(StgInf.MENCRDCPTWIDTH)}
			if MenCrdWidth == comp.MenCrdWidth {items.insert(StgInf.MENCRDWIDTH)}

			return items
		}

		public func diff(
					_ comp: StgInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StgInf.MENAPPCPTWIDTH, StgInf.MENAPPWIDTH, StgInf.MENCRDCPTWIDTH, StgInf.MENCRDWIDTH]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskSesHeadbar)
	  */
	public class Tag: Block {

		public static let MENAPP: Int = 1
		public static let MENCRD: Int = 2

		public init(
					_ MenApp: String = ""
					, _ MenCrd: String = ""
				) {
			self.MenApp = MenApp
			self.MenCrd = MenCrd

			super.init()

			mask = [Tag.MENAPP, Tag.MENCRD]
		}

		public var MenApp: String
		public var MenCrd: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskSesHeadbar")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskSesHeadbar"

			if valid {
				MenApp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MenApp", &mask, Tag.MENAPP)
				MenCrd = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MenCrd", &mask, Tag.MENCRD)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if MenApp == comp.MenApp {items.insert(Tag.MENAPP)}
			if MenCrd == comp.MenCrd {items.insert(Tag.MENCRD)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.MENAPP, Tag.MENCRD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskSesHeadbarData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let STGINF: Int = 2
		public static let TAG: Int = 3

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKSESHEADBARDATA)
		}

		public var stginf: StgInf = StgInf()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskSesHeadbarData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if stginf.readXML(doc, basexpath!, true) {add(DpchEngData.STGINF)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				stginf = StgInf()
				tag = Tag()
			}
		}

	}

}
