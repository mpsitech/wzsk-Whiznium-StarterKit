/**
  * \file PnlWzskUsrList.swift
  * Swift API code for job PnlWzskUsrList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskUsrList
	*/
public class PnlWzskUsrList {
	/**
		* VecVDo (full: VecVWzskUsrListDo)
		*/
	public class VecVDo {

		public static let BUTMINIMIZECLICK: Int = 1
		public static let BUTREGULARIZECLICK: Int = 2
		public static let BUTNEWCLICK: Int = 3
		public static let BUTDELETECLICK: Int = 4
		public static let BUTFILTERCLICK: Int = 5
		public static let BUTREFRESHCLICK: Int = 6

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butminimizeclick" {return BUTMINIMIZECLICK}
			if s == "butregularizeclick" {return BUTREGULARIZECLICK}
			if s == "butnewclick" {return BUTNEWCLICK}
			if s == "butdeleteclick" {return BUTDELETECLICK}
			if s == "butfilterclick" {return BUTFILTERCLICK}
			if s == "butrefreshclick" {return BUTREFRESHCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTMINIMIZECLICK {return "ButMinimizeClick"}
			if ix == BUTREGULARIZECLICK {return "ButRegularizeClick"}
			if ix == BUTNEWCLICK {return "ButNewClick"}
			if ix == BUTDELETECLICK {return "ButDeleteClick"}
			if ix == BUTFILTERCLICK {return "ButFilterClick"}
			if ix == BUTREFRESHCLICK {return "ButRefreshClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskUsrList)
	  */
	public class ContIac: Block {

		public static let NUMFTOS: Int = 1

		public init(
					_ numFTos: Int = 0
				) {
			self.numFTos = numFTos

			super.init()

			mask = [ContIac.NUMFTOS]
		}

		public var numFTos: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskUsrList")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskUsrList"

			if valid {
				numFTos = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFTos", &mask, ContIac.NUMFTOS)
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
			if tag == nil {tag = "ContIacWzskUsrList"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskUsrList"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFTos", numFTos)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFTos == comp.numFTos {items.insert(ContIac.NUMFTOS)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFTOS]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskUsrList)
	  */
	public class ContInf: Block {

		public static let BUTFILTERON: Int = 1
		public static let NUMFCSIQST: Int = 2

		public init(
					_ ButFilterOn: Bool = false
					, _ numFCsiQst: Int = 0
				) {
			self.ButFilterOn = ButFilterOn
			self.numFCsiQst = numFCsiQst

			super.init()

			mask = [ContInf.BUTFILTERON, ContInf.NUMFCSIQST]
		}

		public var ButFilterOn: Bool
		public var numFCsiQst: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskUsrList")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskUsrList"

			if valid {
				ButFilterOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButFilterOn", &mask, ContInf.BUTFILTERON)
				numFCsiQst = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFCsiQst", &mask, ContInf.NUMFCSIQST)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButFilterOn == comp.ButFilterOn {items.insert(ContInf.BUTFILTERON)}
			if numFCsiQst == comp.numFCsiQst {items.insert(ContInf.NUMFCSIQST)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.BUTFILTERON, ContInf.NUMFCSIQST]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskUsrList)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let BUTDELETEACTIVE: Int = 2

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ ButDeleteActive: Bool = false
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.ButDeleteActive = ButDeleteActive

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTDELETEACTIVE]
		}

		public var ixWzskVExpstate: Int
		public var ButDeleteActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskUsrList")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskUsrList"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				ButDeleteActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDeleteActive", &mask, StatShr.BUTDELETEACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}
			if ButDeleteActive == comp.ButDeleteActive {items.insert(StatShr.BUTDELETEACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTDELETEACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StgIac (full: StgIacWzskUsrList)
	  */
	public class StgIac: Block {

		public static let TCOGRPWIDTH: Int = 1
		public static let TCOOWNWIDTH: Int = 2
		public static let TCOPRSWIDTH: Int = 3
		public static let TCOSRFWIDTH: Int = 4
		public static let TCOUSGWIDTH: Int = 5
		public static let TCOSTEWIDTH: Int = 6
		public static let TCOLCLWIDTH: Int = 7
		public static let TCOULVWIDTH: Int = 8

		public init(
					_ TcoGrpWidth: Int = 0
					, _ TcoOwnWidth: Int = 0
					, _ TcoPrsWidth: Int = 0
					, _ TcoSrfWidth: Int = 0
					, _ TcoUsgWidth: Int = 0
					, _ TcoSteWidth: Int = 0
					, _ TcoLclWidth: Int = 0
					, _ TcoUlvWidth: Int = 0
				) {
			self.TcoGrpWidth = TcoGrpWidth
			self.TcoOwnWidth = TcoOwnWidth
			self.TcoPrsWidth = TcoPrsWidth
			self.TcoSrfWidth = TcoSrfWidth
			self.TcoUsgWidth = TcoUsgWidth
			self.TcoSteWidth = TcoSteWidth
			self.TcoLclWidth = TcoLclWidth
			self.TcoUlvWidth = TcoUlvWidth

			super.init()

			mask = [StgIac.TCOGRPWIDTH, StgIac.TCOOWNWIDTH, StgIac.TCOPRSWIDTH, StgIac.TCOSRFWIDTH, StgIac.TCOUSGWIDTH, StgIac.TCOSTEWIDTH, StgIac.TCOLCLWIDTH, StgIac.TCOULVWIDTH]
		}

		public var TcoGrpWidth: Int
		public var TcoOwnWidth: Int
		public var TcoPrsWidth: Int
		public var TcoSrfWidth: Int
		public var TcoUsgWidth: Int
		public var TcoSteWidth: Int
		public var TcoLclWidth: Int
		public var TcoUlvWidth: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StgIacWzskUsrList")}
			valid = basexpath != nil

			let itemtag: String = "StgitemacWzskUsrList"

			if valid {
				TcoGrpWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoGrpWidth", &mask, StgIac.TCOGRPWIDTH)
				TcoOwnWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoOwnWidth", &mask, StgIac.TCOOWNWIDTH)
				TcoPrsWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoPrsWidth", &mask, StgIac.TCOPRSWIDTH)
				TcoSrfWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoSrfWidth", &mask, StgIac.TCOSRFWIDTH)
				TcoUsgWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoUsgWidth", &mask, StgIac.TCOUSGWIDTH)
				TcoSteWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoSteWidth", &mask, StgIac.TCOSTEWIDTH)
				TcoLclWidth = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "TcoLclWidth", &mask, StgIac.TCOLCLWIDTH)
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
			if tag == nil {tag = "StgIacWzskUsrList"}

			let itemtag: String = shorttags ? "Si" : "StgitemacWzskUsrList"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoGrpWidth", TcoGrpWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoOwnWidth", TcoOwnWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoPrsWidth", TcoPrsWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoUsgWidth", TcoUsgWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoSteWidth", TcoSteWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoLclWidth", TcoLclWidth)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "TcoUlvWidth", TcoUlvWidth)
		}

		public func comm(
					_ comp: StgIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TcoGrpWidth == comp.TcoGrpWidth {items.insert(StgIac.TCOGRPWIDTH)}
			if TcoOwnWidth == comp.TcoOwnWidth {items.insert(StgIac.TCOOWNWIDTH)}
			if TcoPrsWidth == comp.TcoPrsWidth {items.insert(StgIac.TCOPRSWIDTH)}
			if TcoSrfWidth == comp.TcoSrfWidth {items.insert(StgIac.TCOSRFWIDTH)}
			if TcoUsgWidth == comp.TcoUsgWidth {items.insert(StgIac.TCOUSGWIDTH)}
			if TcoSteWidth == comp.TcoSteWidth {items.insert(StgIac.TCOSTEWIDTH)}
			if TcoLclWidth == comp.TcoLclWidth {items.insert(StgIac.TCOLCLWIDTH)}
			if TcoUlvWidth == comp.TcoUlvWidth {items.insert(StgIac.TCOULVWIDTH)}

			return items
		}

		public func diff(
					_ comp: StgIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StgIac.TCOGRPWIDTH, StgIac.TCOOWNWIDTH, StgIac.TCOPRSWIDTH, StgIac.TCOSRFWIDTH, StgIac.TCOUSGWIDTH, StgIac.TCOSTEWIDTH, StgIac.TCOLCLWIDTH, StgIac.TCOULVWIDTH]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskUsrList)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let TXTRECORD1: Int = 2
		public static let TXTRECORD2: Int = 3
		public static let TRS: Int = 4
		public static let TXTSHOWING1: Int = 5
		public static let TXTSHOWING2: Int = 6
		public static let TCOGRP: Int = 7
		public static let TCOOWN: Int = 8
		public static let TCOPRS: Int = 9
		public static let TCOSRF: Int = 10
		public static let TCOUSG: Int = 11
		public static let TCOSTE: Int = 12
		public static let TCOLCL: Int = 13
		public static let TCOULV: Int = 14

		public init(
					_ Cpt: String = ""
					, _ TxtRecord1: String = ""
					, _ TxtRecord2: String = ""
					, _ Trs: String = ""
					, _ TxtShowing1: String = ""
					, _ TxtShowing2: String = ""
					, _ TcoGrp: String = ""
					, _ TcoOwn: String = ""
					, _ TcoPrs: String = ""
					, _ TcoSrf: String = ""
					, _ TcoUsg: String = ""
					, _ TcoSte: String = ""
					, _ TcoLcl: String = ""
					, _ TcoUlv: String = ""
				) {
			self.Cpt = Cpt
			self.TxtRecord1 = TxtRecord1
			self.TxtRecord2 = TxtRecord2
			self.Trs = Trs
			self.TxtShowing1 = TxtShowing1
			self.TxtShowing2 = TxtShowing2
			self.TcoGrp = TcoGrp
			self.TcoOwn = TcoOwn
			self.TcoPrs = TcoPrs
			self.TcoSrf = TcoSrf
			self.TcoUsg = TcoUsg
			self.TcoSte = TcoSte
			self.TcoLcl = TcoLcl
			self.TcoUlv = TcoUlv

			super.init()

			mask = [Tag.CPT, Tag.TXTRECORD1, Tag.TXTRECORD2, Tag.TRS, Tag.TXTSHOWING1, Tag.TXTSHOWING2, Tag.TCOGRP, Tag.TCOOWN, Tag.TCOPRS, Tag.TCOSRF, Tag.TCOUSG, Tag.TCOSTE, Tag.TCOLCL, Tag.TCOULV]
		}

		public var Cpt: String
		public var TxtRecord1: String
		public var TxtRecord2: String
		public var Trs: String
		public var TxtShowing1: String
		public var TxtShowing2: String
		public var TcoGrp: String
		public var TcoOwn: String
		public var TcoPrs: String
		public var TcoSrf: String
		public var TcoUsg: String
		public var TcoSte: String
		public var TcoLcl: String
		public var TcoUlv: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskUsrList")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskUsrList"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtRecord1", &mask, Tag.TXTRECORD1)
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtRecord2", &mask, Tag.TXTRECORD2)
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Trs", &mask, Tag.TRS)
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtShowing1", &mask, Tag.TXTSHOWING1)
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TxtShowing2", &mask, Tag.TXTSHOWING2)
				TcoGrp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoGrp", &mask, Tag.TCOGRP)
				TcoOwn = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoOwn", &mask, Tag.TCOOWN)
				TcoPrs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoPrs", &mask, Tag.TCOPRS)
				TcoSrf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoSrf", &mask, Tag.TCOSRF)
				TcoUsg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoUsg", &mask, Tag.TCOUSG)
				TcoSte = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoSte", &mask, Tag.TCOSTE)
				TcoLcl = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "TcoLcl", &mask, Tag.TCOLCL)
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
			if TcoGrp == comp.TcoGrp {items.insert(Tag.TCOGRP)}
			if TcoOwn == comp.TcoOwn {items.insert(Tag.TCOOWN)}
			if TcoPrs == comp.TcoPrs {items.insert(Tag.TCOPRS)}
			if TcoSrf == comp.TcoSrf {items.insert(Tag.TCOSRF)}
			if TcoUsg == comp.TcoUsg {items.insert(Tag.TCOUSG)}
			if TcoSte == comp.TcoSte {items.insert(Tag.TCOSTE)}
			if TcoLcl == comp.TcoLcl {items.insert(Tag.TCOLCL)}
			if TcoUlv == comp.TcoUlv {items.insert(Tag.TCOULV)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.TXTRECORD1, Tag.TXTRECORD2, Tag.TRS, Tag.TXTSHOWING1, Tag.TXTSHOWING2, Tag.TCOGRP, Tag.TCOOWN, Tag.TCOPRS, Tag.TCOSRF, Tag.TCOUSG, Tag.TCOSTE, Tag.TCOLCL, Tag.TCOULV]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskUsrListData)
		*/
	public class DpchAppData: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let STGIAC: Int = 3
		public static let STGIACQRY: Int = 4
		public static let ALL: Int  = 5

		public init(
					_ scrJref: String = ""
					, _ contiac: ContIac? = nil
					, _ stgiac: StgIac? = nil
					, _ stgiacqry: QryWzskUsrList.StgIac? = nil
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPWZSKUSRLISTDATA, scrJref)

			if mask.contains(DpchAppData.ALL) {self.mask = [DpchAppData.SCRJREF, DpchAppData.CONTIAC, DpchAppData.STGIAC, DpchAppData.STGIACQRY]}
			else {self.mask = mask}

			if has(DpchAppData.CONTIAC) {if contiac != nil {self.contiac = contiac!}}
			if has(DpchAppData.STGIAC) {if stgiac != nil {self.stgiac = stgiac!}}
			if has(DpchAppData.STGIACQRY) {if stgiacqry != nil {self.stgiacqry = stgiacqry!}}
		}

		public var contiac: ContIac = ContIac()
		public var stgiac: StgIac = StgIac()
		public var stgiacqry: QryWzskUsrList.StgIac = QryWzskUsrList.StgIac()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchAppData.SCRJREF) {ss.append("scrJref")}
			if has(DpchAppData.CONTIAC) {ss.append("contiac")}
			if has(DpchAppData.STGIAC) {ss.append("stgiac")}
			if has(DpchAppData.STGIACQRY) {ss.append("stgiacqry")}

			return StrMod.vectorToString(ss)
		}

		public override func writeXML(
					_ doc: XMLDocument
					, _ sup: XMLElement?
				) {
			let el = XMLElement(name: "DpchAppWzskUsrListData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
			if has(DpchAppData.STGIAC) {stgiac.writeXML(doc, el, "", true)}
			if has(DpchAppData.STGIACQRY) {stgiacqry.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskUsrListDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKUSRLISTDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskUsrListDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskUsrListData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFCSIQST: Int = 4
		public static let FEEDFTOS: Int = 5
		public static let STATSHR: Int = 6
		public static let STGIAC: Int = 7
		public static let TAG: Int = 8
		public static let RST: Int = 9
		public static let STATAPPQRY: Int = 10
		public static let STATSHRQRY: Int = 11
		public static let STGIACQRY: Int = 12

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKUSRLISTDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFCsiQst: Feed = Feed("FeedFCsiQst")
		public var feedFTos: Feed = Feed("FeedFTos")
		public var statshr: StatShr = StatShr()
		public var stgiac: StgIac = StgIac()
		public var tag: Tag = Tag()
		public var rst: ListWzskQUsrList = ListWzskQUsrList()
		public var statappqry: QryWzskUsrList.StatApp = QryWzskUsrList.StatApp()
		public var statshrqry: QryWzskUsrList.StatShr = QryWzskUsrList.StatShr()
		public var stgiacqry: QryWzskUsrList.StgIac = QryWzskUsrList.StgIac()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFCSIQST) {ss.append("feedFCsiQst")}
			if has(DpchEngData.FEEDFTOS) {ss.append("feedFTos")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskUsrListData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFCsiQst.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFCSIQST)}
				if feedFTos.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFTOS)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if stgiac.readXML(doc, basexpath!, true) {add(DpchEngData.STGIAC)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
				if rst.readXML(doc, basexpath!, true) {add(DpchEngData.RST)}
				if statappqry.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPPQRY)}
				if statshrqry.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHRQRY)}
				if stgiacqry.readXML(doc, basexpath!, true) {add(DpchEngData.STGIACQRY)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFCsiQst = Feed("FeedFCsiQst")
				feedFTos = Feed("FeedFTos")
				statshr = StatShr()
				stgiac = StgIac()
				tag = Tag()
				statappqry = QryWzskUsrList.StatApp()
				statshrqry = QryWzskUsrList.StatShr()
				stgiacqry = QryWzskUsrList.StgIac()
			}
		}

	}

}
