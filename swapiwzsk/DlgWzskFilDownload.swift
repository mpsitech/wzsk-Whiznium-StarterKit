/**
  * \file DlgWzskFilDownload.swift
  * Swift API code for job DlgWzskFilDownload
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* DlgWzskFilDownload
	*/
public class DlgWzskFilDownload {
	/**
		* VecVDo (full: VecVDlgWzskFilDownloadDo)
		*/
	public class VecVDo {

		public static let BUTDNECLICK: Int = 1

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butdneclick" {return BUTDNECLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTDNECLICK {return "ButDneClick"}

			return ""
		}

	}

	/**
	  * ContInf (full: ContInfDlgWzskFilDownload)
	  */
	public class ContInf: Block {

		public static let DLD: Int = 1

		public init(
					_ Dld: String = ""
				) {
			self.Dld = Dld

			super.init()

			mask = [ContInf.DLD]
		}

		public var Dld: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfDlgWzskFilDownload")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfDlgWzskFilDownload"

			if valid {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "Dld", &mask, ContInf.DLD)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if Dld == comp.Dld {items.insert(ContInf.DLD)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.DLD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppDlgWzskFilDownload)
	  */
	public class StatApp: Block {

		public static let SHORTMENU: Int = 1

		public init(
					_ shortMenu: String = ""
				) {
			self.shortMenu = shortMenu

			super.init()

			mask = [StatApp.SHORTMENU]
		}

		public var shortMenu: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppDlgWzskFilDownload")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppDlgWzskFilDownload"

			if valid {
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "shortMenu", &mask, StatApp.SHORTMENU)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if shortMenu == comp.shortMenu {items.insert(StatApp.SHORTMENU)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.SHORTMENU]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagDlgWzskFilDownload)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let DLD: Int = 2
		public static let BUTDNE: Int = 3

		public init(
					_ Cpt: String = ""
					, _ Dld: String = ""
					, _ ButDne: String = ""
				) {
			self.Cpt = Cpt
			self.Dld = Dld
			self.ButDne = ButDne

			super.init()

			mask = [Tag.CPT, Tag.DLD, Tag.BUTDNE]
		}

		public var Cpt: String
		public var Dld: String
		public var ButDne: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagDlgWzskFilDownload")}
			valid = basexpath != nil

			let itemtag: String = "TagitemlgWzskFilDownload"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Dld", &mask, Tag.DLD)
				ButDne = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButDne", &mask, Tag.BUTDNE)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if Dld == comp.Dld {items.insert(Tag.DLD)}
			if ButDne == comp.ButDne {items.insert(Tag.BUTDNE)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.DLD, Tag.BUTDNE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppDlgWzskFilDownloadDo)
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
			super.init(VecWzskVDpch.DPCHAPPDLGWZSKFILDOWNLOADDO, scrJref)

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
			let el = XMLElement(name: "DpchAppDlgWzskFilDownloadDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngDlgWzskFilDownloadData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let STATAPP: Int = 3
		public static let TAG: Int = 4

		public init() {
			super.init(VecWzskVDpch.DPCHENGDLGWZSKFILDOWNLOADDATA)
		}

		public var continf: ContInf = ContInf()
		public var statapp: StatApp = StatApp()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.STATAPP) {ss.append("statapp")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngDlgWzskFilDownloadData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				continf = ContInf()
				statapp = StatApp()
				tag = Tag()
			}
		}

	}

}
