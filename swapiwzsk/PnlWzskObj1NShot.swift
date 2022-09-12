/**
  * \file PnlWzskObj1NShot.swift
  * Swift API code for job PnlWzskObj1NShot
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskObj1NShot
	*/
public class PnlWzskObj1NShot {
	/**
		* VecVDo (full: VecVWzskObj1NShotDo)
		*/
	public class VecVDo {

		public static let BUTVIEWCLICK: Int = 1
		public static let BUTNEWCLICK: Int = 2
		public static let BUTDELETECLICK: Int = 3
		public static let BUTREFRESHCLICK: Int = 4

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butviewclick" {return BUTVIEWCLICK}
			if s == "butnewclick" {return BUTNEWCLICK}
			if s == "butdeleteclick" {return BUTDELETECLICK}
			if s == "butrefreshclick" {return BUTREFRESHCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTVIEWCLICK {return "ButViewClick"}
			if ix == BUTNEWCLICK {return "ButNewClick"}
			if ix == BUTDELETECLICK {return "ButDeleteClick"}
			if ix == BUTREFRESHCLICK {return "ButRefreshClick"}

			return ""
		}

	}

	/**
	  * ContInf (full: ContInfWzskObj1NShot)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskObj1NShot")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskObj1NShot"

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
	  * StatApp (full: StatAppWzskObj1NShot)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskObj1NShot")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskObj1NShot"

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
	  * StatShr (full: StatShrWzskObj1NShot)
	  */
	public class StatShr: Block {

		public static let BUTVIEWAVAIL: Int = 1
		public static let BUTVIEWACTIVE: Int = 2
		public static let BUTNEWAVAIL: Int = 3
		public static let BUTDELETEAVAIL: Int = 4
		public static let BUTDELETEACTIVE: Int = 5

		public init(
					_ ButViewAvail: Bool = false
					, _ ButViewActive: Bool = false
					, _ ButNewAvail: Bool = false
					, _ ButDeleteAvail: Bool = false
					, _ ButDeleteActive: Bool = false
				) {
			self.ButViewAvail = ButViewAvail
			self.ButViewActive = ButViewActive
			self.ButNewAvail = ButNewAvail
			self.ButDeleteAvail = ButDeleteAvail
			self.ButDeleteActive = ButDeleteActive

			super.init()

			mask = [StatShr.BUTVIEWAVAIL, StatShr.BUTVIEWACTIVE, StatShr.BUTNEWAVAIL, StatShr.BUTDELETEAVAIL, StatShr.BUTDELETEACTIVE]
		}

		public var ButViewAvail: Bool
		public var ButViewActive: Bool
		public var ButNewAvail: Bool
		public var ButDeleteAvail: Bool
		public var ButDeleteActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskObj1NShot")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskObj1NShot"

			if valid {
				ButViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButViewAvail", &mask, StatShr.BUTVIEWAVAIL)
				ButViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButViewActive", &mask, StatShr.BUTVIEWACTIVE)
				ButNewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButNewAvail", &mask, StatShr.BUTNEWAVAIL)
				ButDeleteAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDeleteAvail", &mask, StatShr.BUTDELETEAVAIL)
				ButDeleteActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDeleteActive", &mask, StatShr.BUTDELETEACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButViewAvail == comp.ButViewAvail {items.insert(StatShr.BUTVIEWAVAIL)}
			if ButViewActive == comp.ButViewActive {items.insert(StatShr.BUTVIEWACTIVE)}
			if ButNewAvail == comp.ButNewAvail {items.insert(StatShr.BUTNEWAVAIL)}
			if ButDeleteAvail == comp.ButDeleteAvail {items.insert(StatShr.BUTDELETEAVAIL)}
			if ButDeleteActive == comp.ButDeleteActive {items.insert(StatShr.BUTDELETEACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTVIEWAVAIL, StatShr.BUTVIEWACTIVE, StatShr.BUTNEWAVAIL, StatShr.BUTDELETEAVAIL, StatShr.BUTDELETEACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StgIac (full: StgIacWzskObj1NShot)
	  */
	public class StgIac: Block {

		public static let TCOREFWIDTH: Int = 1

		public init(
					_ TcoRefWidth: Int = 0
				) {
			self.TcoRefWidth = TcoRefWidth

			super.init()

			mask = [StgIac.TCOREFWIDTH]
		}

		public var TcoRefWidth: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StgIacWzskObj1NShot")}
			valid = basexpath != nil

			let itemtag: String = "StgitemacWzskObj1NShot"

			if valid {
				TcoRefWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoRefWidth", &mask, StgIac.TCOREFWIDTH)
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
			if tag == nil {tag = "StgIacWzskObj1NShot"}

			let itemtag: String = shorttags ? "Si" : "StgitemacWzskObj1NShot"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoRefWidth", TcoRefWidth)
		}

		public func comm(
					_ comp: StgIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TcoRefWidth == comp.TcoRefWidth {items.insert(StgIac.TCOREFWIDTH)}

			return items
		}

		public func diff(
					_ comp: StgIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StgIac.TCOREFWIDTH]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskObj1NShot)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let TXTRECORD1: Int = 2
		public static let TXTRECORD2: Int = 3
		public static let TRS: Int = 4
		public static let TXTSHOWING1: Int = 5
		public static let TXTSHOWING2: Int = 6
		public static let TCOREF: Int = 7

		public init(
					_ Cpt: String = ""
					, _ TxtRecord1: String = ""
					, _ TxtRecord2: String = ""
					, _ Trs: String = ""
					, _ TxtShowing1: String = ""
					, _ TxtShowing2: String = ""
					, _ TcoRef: String = ""
				) {
			self.Cpt = Cpt
			self.TxtRecord1 = TxtRecord1
			self.TxtRecord2 = TxtRecord2
			self.Trs = Trs
			self.TxtShowing1 = TxtShowing1
			self.TxtShowing2 = TxtShowing2
			self.TcoRef = TcoRef

			super.init()

			mask = [Tag.CPT, Tag.TXTRECORD1, Tag.TXTRECORD2, Tag.TRS, Tag.TXTSHOWING1, Tag.TXTSHOWING2, Tag.TCOREF]
		}

		public var Cpt: String
		public var TxtRecord1: String
		public var TxtRecord2: String
		public var Trs: String
		public var TxtShowing1: String
		public var TxtShowing2: String
		public var TcoRef: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskObj1NShot")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskObj1NShot"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtRecord1", &mask, Tag.TXTRECORD1)
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtRecord2", &mask, Tag.TXTRECORD2)
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Trs", &mask, Tag.TRS)
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtShowing1", &mask, Tag.TXTSHOWING1)
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtShowing2", &mask, Tag.TXTSHOWING2)
				TcoRef = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoRef", &mask, Tag.TCOREF)
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
			if TcoRef == comp.TcoRef {items.insert(Tag.TCOREF)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.TXTRECORD1, Tag.TXTRECORD2, Tag.TRS, Tag.TXTSHOWING1, Tag.TXTSHOWING2, Tag.TCOREF]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskObj1NShotData)
		*/
	public class DpchAppData: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let STGIAC: Int = 2
		public static let STGIACQRY: Int = 3
		public static let ALL: Int  = 4

		public init(
					_ scrJref: String = ""
					, _ stgiac: StgIac? = nil
					, _ stgiacqry: QryWzskObj1NShot.StgIac? = nil
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPWZSKOBJ1NSHOTDATA, scrJref)

			if mask.contains(DpchAppData.ALL) {self.mask = [DpchAppData.SCRJREF, DpchAppData.STGIAC, DpchAppData.STGIACQRY]}
			else {self.mask = mask}

			if has(DpchAppData.STGIAC) {if stgiac != nil {self.stgiac = stgiac!}}
			if has(DpchAppData.STGIACQRY) {if stgiacqry != nil {self.stgiacqry = stgiacqry!}}
		}

		public var stgiac: StgIac = StgIac()
		public var stgiacqry: QryWzskObj1NShot.StgIac = QryWzskObj1NShot.StgIac()

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
			let el = XMLElement(name: "DpchAppWzskObj1NShotData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.STGIAC) {stgiac.writeXML(doc, el, "", true)}
			if has(DpchAppData.STGIACQRY) {stgiacqry.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskObj1NShotDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKOBJ1NSHOTDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskObj1NShotDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskObj1NShotData)
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
			super.init(VecWzskVDpch.DPCHENGWZSKOBJ1NSHOTDATA)
		}

		public var continf: ContInf = ContInf()
		public var feedFCsiQst: Feed = Feed("FeedFCsiQst")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var stgiac: StgIac = StgIac()
		public var tag: Tag = Tag()
		public var rst: ListWzskQObj1NShot = ListWzskQObj1NShot()
		public var statappqry: QryWzskObj1NShot.StatApp = QryWzskObj1NShot.StatApp()
		public var statshrqry: QryWzskObj1NShot.StatShr = QryWzskObj1NShot.StatShr()
		public var stgiacqry: QryWzskObj1NShot.StgIac = QryWzskObj1NShot.StgIac()

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskObj1NShotData")}
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
				statappqry = QryWzskObj1NShot.StatApp()
				statshrqry = QryWzskObj1NShot.StatShr()
				stgiacqry = QryWzskObj1NShot.StgIac()
			}
		}

	}

}
