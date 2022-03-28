/**
  * \file PnlWzskUsgAAccess.swift
  * Swift API code for job PnlWzskUsgAAccess
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskUsgAAccess
	*/
public class PnlWzskUsgAAccess {
	/**
		* VecVDo (full: VecVWzskUsgAAccessDo)
		*/
	public class VecVDo {

		public static let BUTNEWCLICK: Int = 1
		public static let BUTDUPLICATECLICK: Int = 2
		public static let BUTDELETECLICK: Int = 3
		public static let BUTREFRESHCLICK: Int = 4

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butnewclick" {return BUTNEWCLICK}
			if s == "butduplicateclick" {return BUTDUPLICATECLICK}
			if s == "butdeleteclick" {return BUTDELETECLICK}
			if s == "butrefreshclick" {return BUTREFRESHCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTNEWCLICK {return "ButNewClick"}
			if ix == BUTDUPLICATECLICK {return "ButDuplicateClick"}
			if ix == BUTDELETECLICK {return "ButDeleteClick"}
			if ix == BUTREFRESHCLICK {return "ButRefreshClick"}

			return ""
		}

	}

	/**
	  * ContInf (full: ContInfWzskUsgAAccess)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskUsgAAccess")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskUsgAAccess"

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
	  * StatApp (full: StatAppWzskUsgAAccess)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskUsgAAccess")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskUsgAAccess"

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
	  * StatShr (full: StatShrWzskUsgAAccess)
	  */
	public class StatShr: Block {

		public static let BUTNEWAVAIL: Int = 1
		public static let BUTDUPLICATEAVAIL: Int = 2
		public static let BUTDUPLICATEACTIVE: Int = 3
		public static let BUTDELETEAVAIL: Int = 4
		public static let BUTDELETEACTIVE: Int = 5

		public init(
					_ ButNewAvail: Bool = false
					, _ ButDuplicateAvail: Bool = false
					, _ ButDuplicateActive: Bool = false
					, _ ButDeleteAvail: Bool = false
					, _ ButDeleteActive: Bool = false
				) {
			self.ButNewAvail = ButNewAvail
			self.ButDuplicateAvail = ButDuplicateAvail
			self.ButDuplicateActive = ButDuplicateActive
			self.ButDeleteAvail = ButDeleteAvail
			self.ButDeleteActive = ButDeleteActive

			super.init()

			mask = [StatShr.BUTNEWAVAIL, StatShr.BUTDUPLICATEAVAIL, StatShr.BUTDUPLICATEACTIVE, StatShr.BUTDELETEAVAIL, StatShr.BUTDELETEACTIVE]
		}

		public var ButNewAvail: Bool
		public var ButDuplicateAvail: Bool
		public var ButDuplicateActive: Bool
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskUsgAAccess")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskUsgAAccess"

			if valid {
				ButNewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButNewAvail", &mask, StatShr.BUTNEWAVAIL)
				ButDuplicateAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDuplicateAvail", &mask, StatShr.BUTDUPLICATEAVAIL)
				ButDuplicateActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDuplicateActive", &mask, StatShr.BUTDUPLICATEACTIVE)
				ButDeleteAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDeleteAvail", &mask, StatShr.BUTDELETEAVAIL)
				ButDeleteActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDeleteActive", &mask, StatShr.BUTDELETEACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButNewAvail == comp.ButNewAvail {items.insert(StatShr.BUTNEWAVAIL)}
			if ButDuplicateAvail == comp.ButDuplicateAvail {items.insert(StatShr.BUTDUPLICATEAVAIL)}
			if ButDuplicateActive == comp.ButDuplicateActive {items.insert(StatShr.BUTDUPLICATEACTIVE)}
			if ButDeleteAvail == comp.ButDeleteAvail {items.insert(StatShr.BUTDELETEAVAIL)}
			if ButDeleteActive == comp.ButDeleteActive {items.insert(StatShr.BUTDELETEACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTNEWAVAIL, StatShr.BUTDUPLICATEAVAIL, StatShr.BUTDUPLICATEACTIVE, StatShr.BUTDELETEAVAIL, StatShr.BUTDELETEACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StgIac (full: StgIacWzskUsgAAccess)
	  */
	public class StgIac: Block {

		public static let TCOFEGWIDTH: Int = 1
		public static let TCOFEAWIDTH: Int = 2
		public static let TCOACCWIDTH: Int = 3

		public init(
					_ TcoFegWidth: Int = 0
					, _ TcoFeaWidth: Int = 0
					, _ TcoAccWidth: Int = 0
				) {
			self.TcoFegWidth = TcoFegWidth
			self.TcoFeaWidth = TcoFeaWidth
			self.TcoAccWidth = TcoAccWidth

			super.init()

			mask = [StgIac.TCOFEGWIDTH, StgIac.TCOFEAWIDTH, StgIac.TCOACCWIDTH]
		}

		public var TcoFegWidth: Int
		public var TcoFeaWidth: Int
		public var TcoAccWidth: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StgIacWzskUsgAAccess")}
			valid = basexpath != nil

			let itemtag: String = "StgitemacWzskUsgAAccess"

			if valid {
				TcoFegWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoFegWidth", &mask, StgIac.TCOFEGWIDTH)
				TcoFeaWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoFeaWidth", &mask, StgIac.TCOFEAWIDTH)
				TcoAccWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoAccWidth", &mask, StgIac.TCOACCWIDTH)
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
			if tag == nil {tag = "StgIacWzskUsgAAccess"}

			let itemtag: String = shorttags ? "Si" : "StgitemacWzskUsgAAccess"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoFegWidth", TcoFegWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoFeaWidth", TcoFeaWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoAccWidth", TcoAccWidth)
		}

		public func comm(
					_ comp: StgIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TcoFegWidth == comp.TcoFegWidth {items.insert(StgIac.TCOFEGWIDTH)}
			if TcoFeaWidth == comp.TcoFeaWidth {items.insert(StgIac.TCOFEAWIDTH)}
			if TcoAccWidth == comp.TcoAccWidth {items.insert(StgIac.TCOACCWIDTH)}

			return items
		}

		public func diff(
					_ comp: StgIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StgIac.TCOFEGWIDTH, StgIac.TCOFEAWIDTH, StgIac.TCOACCWIDTH]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskUsgAAccess)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let TXTRECORD1: Int = 2
		public static let TXTRECORD2: Int = 3
		public static let TRS: Int = 4
		public static let TXTSHOWING1: Int = 5
		public static let TXTSHOWING2: Int = 6
		public static let TCOFEG: Int = 7
		public static let TCOFEA: Int = 8
		public static let TCOACC: Int = 9

		public init(
					_ Cpt: String = ""
					, _ TxtRecord1: String = ""
					, _ TxtRecord2: String = ""
					, _ Trs: String = ""
					, _ TxtShowing1: String = ""
					, _ TxtShowing2: String = ""
					, _ TcoFeg: String = ""
					, _ TcoFea: String = ""
					, _ TcoAcc: String = ""
				) {
			self.Cpt = Cpt
			self.TxtRecord1 = TxtRecord1
			self.TxtRecord2 = TxtRecord2
			self.Trs = Trs
			self.TxtShowing1 = TxtShowing1
			self.TxtShowing2 = TxtShowing2
			self.TcoFeg = TcoFeg
			self.TcoFea = TcoFea
			self.TcoAcc = TcoAcc

			super.init()

			mask = [Tag.CPT, Tag.TXTRECORD1, Tag.TXTRECORD2, Tag.TRS, Tag.TXTSHOWING1, Tag.TXTSHOWING2, Tag.TCOFEG, Tag.TCOFEA, Tag.TCOACC]
		}

		public var Cpt: String
		public var TxtRecord1: String
		public var TxtRecord2: String
		public var Trs: String
		public var TxtShowing1: String
		public var TxtShowing2: String
		public var TcoFeg: String
		public var TcoFea: String
		public var TcoAcc: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskUsgAAccess")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskUsgAAccess"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtRecord1", &mask, Tag.TXTRECORD1)
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtRecord2", &mask, Tag.TXTRECORD2)
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Trs", &mask, Tag.TRS)
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtShowing1", &mask, Tag.TXTSHOWING1)
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtShowing2", &mask, Tag.TXTSHOWING2)
				TcoFeg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoFeg", &mask, Tag.TCOFEG)
				TcoFea = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoFea", &mask, Tag.TCOFEA)
				TcoAcc = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoAcc", &mask, Tag.TCOACC)
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
			if TcoFeg == comp.TcoFeg {items.insert(Tag.TCOFEG)}
			if TcoFea == comp.TcoFea {items.insert(Tag.TCOFEA)}
			if TcoAcc == comp.TcoAcc {items.insert(Tag.TCOACC)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.TXTRECORD1, Tag.TXTRECORD2, Tag.TRS, Tag.TXTSHOWING1, Tag.TXTSHOWING2, Tag.TCOFEG, Tag.TCOFEA, Tag.TCOACC]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskUsgAAccessData)
		*/
	public class DpchAppData: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let STGIAC: Int = 2
		public static let STGIACQRY: Int = 3
		public static let ALL: Int  = 4

		public init(
					_ scrJref: String = ""
					, _ stgiac: StgIac? = nil
					, _ stgiacqry: QryWzskUsgAAccess.StgIac? = nil
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPWZSKUSGAACCESSDATA, scrJref)

			if mask.contains(DpchAppData.ALL) {self.mask = [DpchAppData.SCRJREF, DpchAppData.STGIAC, DpchAppData.STGIACQRY]}
			else {self.mask = mask}

			if has(DpchAppData.STGIAC) {if stgiac != nil {self.stgiac = stgiac!}}
			if has(DpchAppData.STGIACQRY) {if stgiacqry != nil {self.stgiacqry = stgiacqry!}}
		}

		public var stgiac: StgIac = StgIac()
		public var stgiacqry: QryWzskUsgAAccess.StgIac = QryWzskUsgAAccess.StgIac()

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
			let el = XMLElement(name: "DpchAppWzskUsgAAccessData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.STGIAC) {stgiac.writeXML(doc, el, "", true)}
			if has(DpchAppData.STGIACQRY) {stgiacqry.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskUsgAAccessDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKUSGAACCESSDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskUsgAAccessDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskUsgAAccessData)
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
			super.init(VecWzskVDpch.DPCHENGWZSKUSGAACCESSDATA)
		}

		public var continf: ContInf = ContInf()
		public var feedFCsiQst: Feed = Feed("FeedFCsiQst")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var stgiac: StgIac = StgIac()
		public var tag: Tag = Tag()
		public var rst: ListWzskQUsgAAccess = ListWzskQUsgAAccess()
		public var statappqry: QryWzskUsgAAccess.StatApp = QryWzskUsgAAccess.StatApp()
		public var statshrqry: QryWzskUsgAAccess.StatShr = QryWzskUsgAAccess.StatShr()
		public var stgiacqry: QryWzskUsgAAccess.StgIac = QryWzskUsgAAccess.StgIac()

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskUsgAAccessData")}
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
				statappqry = QryWzskUsgAAccess.StatApp()
				statshrqry = QryWzskUsgAAccess.StatShr()
				stgiacqry = QryWzskUsgAAccess.StgIac()
			}
		}

	}

}
