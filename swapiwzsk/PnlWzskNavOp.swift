/**
  * \file PnlWzskNavOp.swift
  * Swift API code for job PnlWzskNavOp
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskNavOp
	*/
public class PnlWzskNavOp {
	/**
		* VecVDo (full: VecVWzskNavOpDo)
		*/
	public class VecVDo {

		public static let BUTLLVNEWCRDCLICK: Int = 1
		public static let BUTLIVNEWCRDCLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butllvnewcrdclick" {return BUTLLVNEWCRDCLICK}
			if s == "butlivnewcrdclick" {return BUTLIVNEWCRDCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTLLVNEWCRDCLICK {return "ButLlvNewcrdClick"}
			if ix == BUTLIVNEWCRDCLICK {return "ButLivNewcrdClick"}

			return ""
		}

	}

	/**
	  * StatApp (full: StatAppWzskNavOp)
	  */
	public class StatApp: Block {

		public static let IXWZSKVEXPSTATE: Int = 1

		public init(
					_ ixWzskVExpstate: Int = 0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate

			super.init()

			mask = [StatApp.IXWZSKVEXPSTATE]
		}

		public var ixWzskVExpstate: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskNavOp")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskNavOp"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatApp.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatApp.IXWZSKVEXPSTATE)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVEXPSTATE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskNavOp)
	  */
	public class StatShr: Block {

		public static let BUTLLVNEWCRDAVAIL: Int = 1
		public static let BUTLIVNEWCRDAVAIL: Int = 2

		public init(
					_ ButLlvNewcrdAvail: Bool = false
					, _ ButLivNewcrdAvail: Bool = false
				) {
			self.ButLlvNewcrdAvail = ButLlvNewcrdAvail
			self.ButLivNewcrdAvail = ButLivNewcrdAvail

			super.init()

			mask = [StatShr.BUTLLVNEWCRDAVAIL, StatShr.BUTLIVNEWCRDAVAIL]
		}

		public var ButLlvNewcrdAvail: Bool
		public var ButLivNewcrdAvail: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskNavOp")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskNavOp"

			if valid {
				ButLlvNewcrdAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButLlvNewcrdAvail", &mask, StatShr.BUTLLVNEWCRDAVAIL)
				ButLivNewcrdAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButLivNewcrdAvail", &mask, StatShr.BUTLIVNEWCRDAVAIL)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButLlvNewcrdAvail == comp.ButLlvNewcrdAvail {items.insert(StatShr.BUTLLVNEWCRDAVAIL)}
			if ButLivNewcrdAvail == comp.ButLivNewcrdAvail {items.insert(StatShr.BUTLIVNEWCRDAVAIL)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTLLVNEWCRDAVAIL, StatShr.BUTLIVNEWCRDAVAIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskNavOp)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTLLV: Int = 2
		public static let CPTLIV: Int = 3

		public init(
					_ Cpt: String = ""
					, _ CptLlv: String = ""
					, _ CptLiv: String = ""
				) {
			self.Cpt = Cpt
			self.CptLlv = CptLlv
			self.CptLiv = CptLiv

			super.init()

			mask = [Tag.CPT, Tag.CPTLLV, Tag.CPTLIV]
		}

		public var Cpt: String
		public var CptLlv: String
		public var CptLiv: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskNavOp")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskNavOp"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptLlv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLlv", &mask, Tag.CPTLLV)
				CptLiv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLiv", &mask, Tag.CPTLIV)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptLlv == comp.CptLlv {items.insert(Tag.CPTLLV)}
			if CptLiv == comp.CptLiv {items.insert(Tag.CPTLIV)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTLLV, Tag.CPTLIV]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskNavOpDo)
		*/
	public class DpchAppDo: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let IXVDO: Int = 2
		public static let ALL: Int  = 3

		public init(
					_ scrJref: String = ""
					, _ ixVDo: Int = 0
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPWZSKNAVOPDO, scrJref)

			if mask.contains(DpchAppDo.ALL) {self.mask = [DpchAppDo.SCRJREF, DpchAppDo.IXVDO]}
			else {self.mask = mask}

			self.ixVDo = ixVDo
		}

		public var ixVDo: Int = 0

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchAppDo.SCRJREF) {ss.append("scrJref")}
			if has(DpchAppDo.IXVDO) {ss.append("ixVDo")}

			return StrMod.vectorToString(ss)
		}

		public override func writeXML(
					_ doc: XMLDocument
					, _ sup: XMLElement?
				) {
			let el = XMLElement(name: "DpchAppWzskNavOpDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskNavOpData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let STATAPP: Int = 2
		public static let STATSHR: Int = 3
		public static let TAG: Int = 4

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKNAVOPDATA)
		}

		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.STATAPP) {ss.append("statapp")}
			if has(DpchEngData.STATSHR) {ss.append("statshr")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskNavOpData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
