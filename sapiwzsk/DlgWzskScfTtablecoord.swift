/**
  * \file DlgWzskScfTtablecoord.swift
  * Swift API code for job DlgWzskScfTtablecoord
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* DlgWzskScfTtablecoord
	*/
public class DlgWzskScfTtablecoord {
	/**
		* VecVDit (full: VecVDlgWzskScfTtablecoordDit)
		*/
	public class VecVDit {

		public static let PLH: Int = 1

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "plh" {return PLH}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == PLH {return "Plh"}

			return ""
		}

	}

	/**
		* VecVDo (full: VecVDlgWzskScfTtablecoordDo)
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
		* VecVSge (full: VecVDlgWzskScfTtablecoordSge)
		*/
	public class VecVSge {

		public static let IDLE: Int = 1
		public static let DONE: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "idle" {return IDLE}
			if s == "done" {return DONE}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == IDLE {return "idle"}
			if ix == DONE {return "done"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacDlgWzskScfTtablecoord)
	  */
	public class ContIac: Block {

		public static let NUMFDSE: Int = 1

		public init(
					_ numFDse: Int = 0
				) {
			self.numFDse = numFDse

			super.init()

			mask = [ContIac.NUMFDSE]
		}

		public var numFDse: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacDlgWzskScfTtablecoord")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacDlgWzskScfTtablecoord"

			if valid {
				numFDse = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFDse", &mask, ContIac.NUMFDSE)
			}

			return valid
		}

		public func writeXML(
					_ doc: XMLDocument
					, _ sup: XMLElement?
					, _ difftag: String
					, _ shorttags: Bool
				) {
			var tag: String? = difftag
			if tag == nil {tag = "ContIacDlgWzskScfTtablecoord"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacDlgWzskScfTtablecoord"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFDse", numFDse)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFDse == comp.numFDse {items.insert(ContIac.NUMFDSE)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFDSE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfDlgWzskScfTtablecoord)
	  */
	public class ContInf: Block {

		public static let NUMFSGE: Int = 1

		public init(
					_ numFSge: Int = 0
				) {
			self.numFSge = numFSge

			super.init()

			mask = [ContInf.NUMFSGE]
		}

		public var numFSge: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfDlgWzskScfTtablecoord")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfDlgWzskScfTtablecoord"

			if valid {
				numFSge = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFSge", &mask, ContInf.NUMFSGE)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFSge == comp.numFSge {items.insert(ContInf.NUMFSGE)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.NUMFSGE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppDlgWzskScfTtablecoord)
	  */
	public class StatApp: Block {

		public static let INITDONE: Int = 1
		public static let SHORTMENU: Int = 2

		public init(
					_ initdone: Bool = false
					, _ shortMenu: String = ""
				) {
			self.initdone = initdone
			self.shortMenu = shortMenu

			super.init()

			mask = [StatApp.INITDONE, StatApp.SHORTMENU]
		}

		public var initdone: Bool
		public var shortMenu: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppDlgWzskScfTtablecoord")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppDlgWzskScfTtablecoord"

			if valid {
				initdone = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdone", &mask, StatApp.INITDONE)
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "shortMenu", &mask, StatApp.SHORTMENU)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if initdone == comp.initdone {items.insert(StatApp.INITDONE)}
			if shortMenu == comp.shortMenu {items.insert(StatApp.SHORTMENU)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.INITDONE, StatApp.SHORTMENU]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrDlgWzskScfTtablecoord)
	  */
	public class StatShr: Block {

		public static let BUTDNEACTIVE: Int = 1

		public init(
					_ ButDneActive: Bool = false
				) {
			self.ButDneActive = ButDneActive

			super.init()

			mask = [StatShr.BUTDNEACTIVE]
		}

		public var ButDneActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrDlgWzskScfTtablecoord")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrDlgWzskScfTtablecoord"

			if valid {
				ButDneActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDneActive", &mask, StatShr.BUTDNEACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButDneActive == comp.ButDneActive {items.insert(StatShr.BUTDNEACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTDNEACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagDlgWzskScfTtablecoord)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let BUTDNE: Int = 2

		public init(
					_ Cpt: String = ""
					, _ ButDne: String = ""
				) {
			self.Cpt = Cpt
			self.ButDne = ButDne

			super.init()

			mask = [Tag.CPT, Tag.BUTDNE]
		}

		public var Cpt: String
		public var ButDne: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagDlgWzskScfTtablecoord")}
			valid = basexpath != nil

			let itemtag: String = "TagitemlgWzskScfTtablecoord"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				ButDne = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButDne", &mask, Tag.BUTDNE)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if ButDne == comp.ButDne {items.insert(Tag.BUTDNE)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.BUTDNE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppDlgWzskScfTtablecoordData)
		*/
	public class DpchAppData: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let ALL: Int  = 3

		public init(
					_ scrJref: String = ""
					, _ contiac: ContIac? = nil
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPDLGWZSKSCFTTABLECOORDDATA, scrJref)

			if mask.contains(DpchAppData.ALL) {self.mask = [DpchAppData.SCRJREF, DpchAppData.CONTIAC]}
			else {self.mask = mask}

			if has(DpchAppData.CONTIAC) {if contiac != nil {self.contiac = contiac!}}
		}

		public var contiac: ContIac = ContIac()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchAppData.SCRJREF) {ss.append("scrJref")}
			if has(DpchAppData.CONTIAC) {ss.append("contiac")}

			return StrMod.vectorToString(ss)
		}

		public override func writeXML(
					_ doc: XMLDocument
					, _ sup: XMLElement?
				) {
			let el = XMLElement(name: "DpchAppDlgWzskScfTtablecoordData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppDlgWzskScfTtablecoordDo)
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
			super.init(VecWzskVDpch.DPCHAPPDLGWZSKSCFTTABLECOORDDO, scrJref)

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
			let el = XMLElement(name: "DpchAppDlgWzskScfTtablecoordDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngDlgWzskScfTtablecoordData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFDSE: Int = 4
		public static let FEEDFSGE: Int = 5
		public static let STATAPP: Int = 6
		public static let STATSHR: Int = 7
		public static let TAG: Int = 8

		public init() {
			super.init(VecWzskVDpch.DPCHENGDLGWZSKSCFTTABLECOORDDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFDse: Feed = Feed("FeedFDse")
		public var feedFSge: Feed = Feed("FeedFSge")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFDSE) {ss.append("feedFDse")}
			if has(DpchEngData.FEEDFSGE) {ss.append("feedFSge")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngDlgWzskScfTtablecoordData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFDse.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFDSE)}
				if feedFSge.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFSGE)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFDse = Feed("FeedFDse")
				feedFSge = Feed("FeedFSge")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
