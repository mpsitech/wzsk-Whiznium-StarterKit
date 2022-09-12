/**
  * \file PnlWzskUsgMNUser.swift
  * Swift API code for job PnlWzskUsgMNUser
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskUsgMNUser
	*/
public class PnlWzskUsgMNUser {
	/**
		* VecVDo (full: VecVWzskUsgMNUserDo)
		*/
	public class VecVDo {

		public static let BUTVIEWCLICK: Int = 1
		public static let BUTADDCLICK: Int = 2
		public static let BUTSUBCLICK: Int = 3
		public static let BUTREFRESHCLICK: Int = 4

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butviewclick" {return BUTVIEWCLICK}
			if s == "butaddclick" {return BUTADDCLICK}
			if s == "butsubclick" {return BUTSUBCLICK}
			if s == "butrefreshclick" {return BUTREFRESHCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTVIEWCLICK {return "ButViewClick"}
			if ix == BUTADDCLICK {return "ButAddClick"}
			if ix == BUTSUBCLICK {return "ButSubClick"}
			if ix == BUTREFRESHCLICK {return "ButRefreshClick"}

			return ""
		}

	}

	/**
	  * ContInf (full: ContInfWzskUsgMNUser)
	  */
	public class ContInf: Block {

		public static let NUMFCSIQST: Int = 1

		public init(
					_ numFCsiQst: Int = 0
				) {
			self.numFCsiQst = numFCsiQst

			super.init()

			mask = [ContInf.NUMFCSIQST]
		}

		public var numFCsiQst: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskUsgMNUser")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskUsgMNUser"

			if valid {
				numFCsiQst = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFCsiQst", &mask, ContInf.NUMFCSIQST)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFCsiQst == comp.numFCsiQst {items.insert(ContInf.NUMFCSIQST)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.NUMFCSIQST]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskUsgMNUser)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskUsgMNUser")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskUsgMNUser"

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
	  * StatShr (full: StatShrWzskUsgMNUser)
	  */
	public class StatShr: Block {

		public static let BUTVIEWAVAIL: Int = 1
		public static let BUTVIEWACTIVE: Int = 2
		public static let BUTADDAVAIL: Int = 3
		public static let BUTSUBAVAIL: Int = 4
		public static let BUTSUBACTIVE: Int = 5

		public init(
					_ ButViewAvail: Bool = false
					, _ ButViewActive: Bool = false
					, _ ButAddAvail: Bool = false
					, _ ButSubAvail: Bool = false
					, _ ButSubActive: Bool = false
				) {
			self.ButViewAvail = ButViewAvail
			self.ButViewActive = ButViewActive
			self.ButAddAvail = ButAddAvail
			self.ButSubAvail = ButSubAvail
			self.ButSubActive = ButSubActive

			super.init()

			mask = [StatShr.BUTVIEWAVAIL, StatShr.BUTVIEWACTIVE, StatShr.BUTADDAVAIL, StatShr.BUTSUBAVAIL, StatShr.BUTSUBACTIVE]
		}

		public var ButViewAvail: Bool
		public var ButViewActive: Bool
		public var ButAddAvail: Bool
		public var ButSubAvail: Bool
		public var ButSubActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskUsgMNUser")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskUsgMNUser"

			if valid {
				ButViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButViewAvail", &mask, StatShr.BUTVIEWAVAIL)
				ButViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButViewActive", &mask, StatShr.BUTVIEWACTIVE)
				ButAddAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButAddAvail", &mask, StatShr.BUTADDAVAIL)
				ButSubAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSubAvail", &mask, StatShr.BUTSUBAVAIL)
				ButSubActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSubActive", &mask, StatShr.BUTSUBACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButViewAvail == comp.ButViewAvail {items.insert(StatShr.BUTVIEWAVAIL)}
			if ButViewActive == comp.ButViewActive {items.insert(StatShr.BUTVIEWACTIVE)}
			if ButAddAvail == comp.ButAddAvail {items.insert(StatShr.BUTADDAVAIL)}
			if ButSubAvail == comp.ButSubAvail {items.insert(StatShr.BUTSUBAVAIL)}
			if ButSubActive == comp.ButSubActive {items.insert(StatShr.BUTSUBACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTVIEWAVAIL, StatShr.BUTVIEWACTIVE, StatShr.BUTADDAVAIL, StatShr.BUTSUBAVAIL, StatShr.BUTSUBACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StgIac (full: StgIacWzskUsgMNUser)
	  */
	public class StgIac: Block {

		public static let TCOMREFWIDTH: Int = 1
		public static let TCOULVWIDTH: Int = 2

		public init(
					_ TcoMrefWidth: Int = 0
					, _ TcoUlvWidth: Int = 0
				) {
			self.TcoMrefWidth = TcoMrefWidth
			self.TcoUlvWidth = TcoUlvWidth

			super.init()

			mask = [StgIac.TCOMREFWIDTH, StgIac.TCOULVWIDTH]
		}

		public var TcoMrefWidth: Int
		public var TcoUlvWidth: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StgIacWzskUsgMNUser")}
			valid = basexpath != nil

			let itemtag: String = "StgitemacWzskUsgMNUser"

			if valid {
				TcoMrefWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoMrefWidth", &mask, StgIac.TCOMREFWIDTH)
				TcoUlvWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoUlvWidth", &mask, StgIac.TCOULVWIDTH)
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
			if tag == nil {tag = "StgIacWzskUsgMNUser"}

			let itemtag: String = shorttags ? "Si" : "StgitemacWzskUsgMNUser"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoUlvWidth", TcoUlvWidth)
		}

		public func comm(
					_ comp: StgIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TcoMrefWidth == comp.TcoMrefWidth {items.insert(StgIac.TCOMREFWIDTH)}
			if TcoUlvWidth == comp.TcoUlvWidth {items.insert(StgIac.TCOULVWIDTH)}

			return items
		}

		public func diff(
					_ comp: StgIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StgIac.TCOMREFWIDTH, StgIac.TCOULVWIDTH]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskUsgMNUser)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let TXTRECORD1: Int = 2
		public static let TXTRECORD2: Int = 3
		public static let TRS: Int = 4
		public static let TXTSHOWING1: Int = 5
		public static let TXTSHOWING2: Int = 6
		public static let TCOMREF: Int = 7
		public static let TCOULV: Int = 8

		public init(
					_ Cpt: String = ""
					, _ TxtRecord1: String = ""
					, _ TxtRecord2: String = ""
					, _ Trs: String = ""
					, _ TxtShowing1: String = ""
					, _ TxtShowing2: String = ""
					, _ TcoMref: String = ""
					, _ TcoUlv: String = ""
				) {
			self.Cpt = Cpt
			self.TxtRecord1 = TxtRecord1
			self.TxtRecord2 = TxtRecord2
			self.Trs = Trs
			self.TxtShowing1 = TxtShowing1
			self.TxtShowing2 = TxtShowing2
			self.TcoMref = TcoMref
			self.TcoUlv = TcoUlv

			super.init()

			mask = [Tag.CPT, Tag.TXTRECORD1, Tag.TXTRECORD2, Tag.TRS, Tag.TXTSHOWING1, Tag.TXTSHOWING2, Tag.TCOMREF, Tag.TCOULV]
		}

		public var Cpt: String
		public var TxtRecord1: String
		public var TxtRecord2: String
		public var Trs: String
		public var TxtShowing1: String
		public var TxtShowing2: String
		public var TcoMref: String
		public var TcoUlv: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskUsgMNUser")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskUsgMNUser"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtRecord1", &mask, Tag.TXTRECORD1)
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtRecord2", &mask, Tag.TXTRECORD2)
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Trs", &mask, Tag.TRS)
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtShowing1", &mask, Tag.TXTSHOWING1)
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtShowing2", &mask, Tag.TXTSHOWING2)
				TcoMref = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoMref", &mask, Tag.TCOMREF)
				TcoUlv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoUlv", &mask, Tag.TCOULV)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if TxtRecord1 == comp.TxtRecord1 {items.insert(Tag.TXTRECORD1)}
			if TxtRecord2 == comp.TxtRecord2 {items.insert(Tag.TXTRECORD2)}
			if Trs == comp.Trs {items.insert(Tag.TRS)}
			if TxtShowing1 == comp.TxtShowing1 {items.insert(Tag.TXTSHOWING1)}
			if TxtShowing2 == comp.TxtShowing2 {items.insert(Tag.TXTSHOWING2)}
			if TcoMref == comp.TcoMref {items.insert(Tag.TCOMREF)}
			if TcoUlv == comp.TcoUlv {items.insert(Tag.TCOULV)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.TXTRECORD1, Tag.TXTRECORD2, Tag.TRS, Tag.TXTSHOWING1, Tag.TXTSHOWING2, Tag.TCOMREF, Tag.TCOULV]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskUsgMNUserData)
		*/
	public class DpchAppData: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let STGIAC: Int = 2
		public static let STGIACQRY: Int = 3
		public static let ALL: Int  = 4

		public init(
					_ scrJref: String = ""
					, _ stgiac: StgIac? = nil
					, _ stgiacqry: QryWzskUsgMNUser.StgIac? = nil
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPWZSKUSGMNUSERDATA, scrJref)

			if mask.contains(DpchAppData.ALL) {self.mask = [DpchAppData.SCRJREF, DpchAppData.STGIAC, DpchAppData.STGIACQRY]}
			else {self.mask = mask}

			if has(DpchAppData.STGIAC) {if stgiac != nil {self.stgiac = stgiac!}}
			if has(DpchAppData.STGIACQRY) {if stgiacqry != nil {self.stgiacqry = stgiacqry!}}
		}

		public var stgiac: StgIac = StgIac()
		public var stgiacqry: QryWzskUsgMNUser.StgIac = QryWzskUsgMNUser.StgIac()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchAppData.SCRJREF) {ss.append("scrJref")}
			if has(DpchAppData.STGIAC) {ss.append("stgiac")}
			if has(DpchAppData.STGIACQRY) {ss.append("stgiacqry")}

			return StrMod.vectorToString(ss)
		}

		public override func writeXML(
					_ doc: XMLDocument
					, _ sup: XMLElement?
				) {
			let el = XMLElement(name: "DpchAppWzskUsgMNUserData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.STGIAC) {stgiac.writeXML(doc, el, "", true)}
			if has(DpchAppData.STGIACQRY) {stgiacqry.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskUsgMNUserDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKUSGMNUSERDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskUsgMNUserDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskUsgMNUserData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let FEEDFCSIQST: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let STGIAC: Int = 6
		public static let TAG: Int = 7
		public static let RST: Int = 8
		public static let STATAPPQRY: Int = 9
		public static let STATSHRQRY: Int = 10
		public static let STGIACQRY: Int = 11

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKUSGMNUSERDATA)
		}

		public var continf: ContInf = ContInf()
		public var feedFCsiQst: Feed = Feed("FeedFCsiQst")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var stgiac: StgIac = StgIac()
		public var tag: Tag = Tag()
		public var rst: ListWzskQUsgMNUser = ListWzskQUsgMNUser()
		public var statappqry: QryWzskUsgMNUser.StatApp = QryWzskUsgMNUser.StatApp()
		public var statshrqry: QryWzskUsgMNUser.StatShr = QryWzskUsgMNUser.StatShr()
		public var stgiacqry: QryWzskUsgMNUser.StgIac = QryWzskUsgMNUser.StgIac()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFCSIQST) {ss.append("feedFCsiQst")}
			if has(DpchEngData.STATAPP) {ss.append("statapp")}
			if has(DpchEngData.STATSHR) {ss.append("statshr")}
			if has(DpchEngData.STGIAC) {ss.append("stgiac")}
			if has(DpchEngData.TAG) {ss.append("tag")}
			if has(DpchEngData.RST) {ss.append("rst")}
			if has(DpchEngData.STATAPPQRY) {ss.append("statappqry")}
			if has(DpchEngData.STATSHRQRY) {ss.append("statshrqry")}
			if has(DpchEngData.STGIACQRY) {ss.append("stgiacqry")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskUsgMNUserData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFCsiQst.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFCSIQST)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if stgiac.readXML(doc, basexpath!, true) {add(DpchEngData.STGIAC)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
				if rst.readXML(doc, basexpath!, true) {add(DpchEngData.RST)}
				if statappqry.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPPQRY)}
				if statshrqry.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHRQRY)}
				if stgiacqry.readXML(doc, basexpath!, true) {add(DpchEngData.STGIACQRY)}
			} else {
				scrJref = ""
				continf = ContInf()
				feedFCsiQst = Feed("FeedFCsiQst")
				statapp = StatApp()
				statshr = StatShr()
				stgiac = StgIac()
				tag = Tag()
				statappqry = QryWzskUsgMNUser.StatApp()
				statshrqry = QryWzskUsgMNUser.StatShr()
				stgiacqry = QryWzskUsgMNUser.StgIac()
			}
		}

	}

}
