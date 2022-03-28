/**
  * \file DlgWzskObjNew.swift
  * Swift API code for job DlgWzskObjNew
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* DlgWzskObjNew
	*/
public class DlgWzskObjNew {
	/**
		* VecVDo (full: VecVDlgWzskObjNewDo)
		*/
	public class VecVDo {

		public static let BUTCNCCLICK: Int = 1
		public static let BUTCRECLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butcncclick" {return BUTCNCCLICK}
			if s == "butcreclick" {return BUTCRECLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTCNCCLICK {return "ButCncClick"}
			if ix == BUTCRECLICK {return "ButCreClick"}

			return ""
		}

	}

	/**
		* VecVSge (full: VecVDlgWzskObjNewSge)
		*/
	public class VecVSge {

		public static let IDLE: Int = 1
		public static let CREATE: Int = 2
		public static let DONE: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "idle" {return IDLE}
			if s == "create" {return CREATE}
			if s == "done" {return DONE}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == IDLE {return "idle"}
			if ix == CREATE {return "create"}
			if ix == DONE {return "done"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacDlgWzskObjNew)
	  */
	public class ContIac: Block {

		public static let NUMFPUPOGR: Int = 1
		public static let TXFTIT: Int = 2
		public static let TXFCMT: Int = 3

		public init(
					_ numFPupOgr: Int = 0
					, _ TxfTit: String = ""
					, _ TxfCmt: String = ""
				) {
			self.numFPupOgr = numFPupOgr
			self.TxfTit = TxfTit
			self.TxfCmt = TxfCmt

			super.init()

			mask = [ContIac.NUMFPUPOGR, ContIac.TXFTIT, ContIac.TXFCMT]
		}

		public var numFPupOgr: Int
		public var TxfTit: String
		public var TxfCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacDlgWzskObjNew")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacDlgWzskObjNew"

			if valid {
				numFPupOgr = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupOgr", &mask, ContIac.NUMFPUPOGR)
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfTit", &mask, ContIac.TXFTIT)
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfCmt", &mask, ContIac.TXFCMT)
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
			if tag == nil {tag = "ContIacDlgWzskObjNew"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacDlgWzskObjNew"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupOgr", numFPupOgr)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFPupOgr == comp.numFPupOgr {items.insert(ContIac.NUMFPUPOGR)}
			if TxfTit == comp.TxfTit {items.insert(ContIac.TXFTIT)}
			if TxfCmt == comp.TxfCmt {items.insert(ContIac.TXFCMT)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFPUPOGR, ContIac.TXFTIT, ContIac.TXFCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfDlgWzskObjNew)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfDlgWzskObjNew")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfDlgWzskObjNew"

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
	  * StatApp (full: StatAppDlgWzskObjNew)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppDlgWzskObjNew")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppDlgWzskObjNew"

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
	  * StatShr (full: StatShrDlgWzskObjNew)
	  */
	public class StatShr: Block {

		public static let BUTCNCACTIVE: Int = 1
		public static let BUTCREACTIVE: Int = 2

		public init(
					_ ButCncActive: Bool = false
					, _ ButCreActive: Bool = false
				) {
			self.ButCncActive = ButCncActive
			self.ButCreActive = ButCreActive

			super.init()

			mask = [StatShr.BUTCNCACTIVE, StatShr.BUTCREACTIVE]
		}

		public var ButCncActive: Bool
		public var ButCreActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrDlgWzskObjNew")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrDlgWzskObjNew"

			if valid {
				ButCncActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButCncActive", &mask, StatShr.BUTCNCACTIVE)
				ButCreActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButCreActive", &mask, StatShr.BUTCREACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButCncActive == comp.ButCncActive {items.insert(StatShr.BUTCNCACTIVE)}
			if ButCreActive == comp.ButCreActive {items.insert(StatShr.BUTCREACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTCNCACTIVE, StatShr.BUTCREACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagDlgWzskObjNew)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTOGR: Int = 2
		public static let CPTTIT: Int = 3
		public static let CPTCMT: Int = 4
		public static let BUTCNC: Int = 5
		public static let BUTCRE: Int = 6

		public init(
					_ Cpt: String = ""
					, _ CptOgr: String = ""
					, _ CptTit: String = ""
					, _ CptCmt: String = ""
					, _ ButCnc: String = ""
					, _ ButCre: String = ""
				) {
			self.Cpt = Cpt
			self.CptOgr = CptOgr
			self.CptTit = CptTit
			self.CptCmt = CptCmt
			self.ButCnc = ButCnc
			self.ButCre = ButCre

			super.init()

			mask = [Tag.CPT, Tag.CPTOGR, Tag.CPTTIT, Tag.CPTCMT, Tag.BUTCNC, Tag.BUTCRE]
		}

		public var Cpt: String
		public var CptOgr: String
		public var CptTit: String
		public var CptCmt: String
		public var ButCnc: String
		public var ButCre: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagDlgWzskObjNew")}
			valid = basexpath != nil

			let itemtag: String = "TagitemlgWzskObjNew"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptOgr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptOgr", &mask, Tag.CPTOGR)
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptTit", &mask, Tag.CPTTIT)
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCmt", &mask, Tag.CPTCMT)
				ButCnc = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButCnc", &mask, Tag.BUTCNC)
				ButCre = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButCre", &mask, Tag.BUTCRE)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptOgr == comp.CptOgr {items.insert(Tag.CPTOGR)}
			if CptTit == comp.CptTit {items.insert(Tag.CPTTIT)}
			if CptCmt == comp.CptCmt {items.insert(Tag.CPTCMT)}
			if ButCnc == comp.ButCnc {items.insert(Tag.BUTCNC)}
			if ButCre == comp.ButCre {items.insert(Tag.BUTCRE)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTOGR, Tag.CPTTIT, Tag.CPTCMT, Tag.BUTCNC, Tag.BUTCRE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppDlgWzskObjNewData)
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
			super.init(VecWzskVDpch.DPCHAPPDLGWZSKOBJNEWDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppDlgWzskObjNewData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppDlgWzskObjNewDo)
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
			super.init(VecWzskVDpch.DPCHAPPDLGWZSKOBJNEWDO, scrJref)

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
			let el = XMLElement(name: "DpchAppDlgWzskObjNewDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngDlgWzskObjNewData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFPUPOGR: Int = 4
		public static let FEEDFSGE: Int = 5
		public static let STATAPP: Int = 6
		public static let STATSHR: Int = 7
		public static let TAG: Int = 8

		public init() {
			super.init(VecWzskVDpch.DPCHENGDLGWZSKOBJNEWDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFPupOgr: Feed = Feed("FeedFPupOgr")
		public var feedFSge: Feed = Feed("FeedFSge")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFPUPOGR) {ss.append("feedFPupOgr")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngDlgWzskObjNewData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFPupOgr.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPOGR)}
				if feedFSge.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFSGE)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFPupOgr = Feed("FeedFPupOgr")
				feedFSge = Feed("FeedFSge")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
