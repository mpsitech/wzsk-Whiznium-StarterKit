/**
  * \file PnlWzskShtDetail.swift
  * Swift API code for job PnlWzskShtDetail
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskShtDetail
	*/
public class PnlWzskShtDetail {
	/**
		* VecVDo (full: VecVWzskShtDetailDo)
		*/
	public class VecVDo {

		public static let BUTSAVECLICK: Int = 1
		public static let BUTSESVIEWCLICK: Int = 2
		public static let BUTOBJVIEWCLICK: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butsaveclick" {return BUTSAVECLICK}
			if s == "butsesviewclick" {return BUTSESVIEWCLICK}
			if s == "butobjviewclick" {return BUTOBJVIEWCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTSAVECLICK {return "ButSaveClick"}
			if ix == BUTSESVIEWCLICK {return "ButSesViewClick"}
			if ix == BUTOBJVIEWCLICK {return "ButObjViewClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskShtDetail)
	  */
	public class ContIac: Block {

		public static let TXFSTA: Int = 1
		public static let TXFCMT: Int = 2

		public init(
					_ TxfSta: String = ""
					, _ TxfCmt: String = ""
				) {
			self.TxfSta = TxfSta
			self.TxfCmt = TxfCmt

			super.init()

			mask = [ContIac.TXFSTA, ContIac.TXFCMT]
		}

		public var TxfSta: String
		public var TxfCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskShtDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskShtDetail"

			if valid {
				TxfSta = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfSta", &mask, ContIac.TXFSTA)
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
			if tag == nil {tag = "ContIacWzskShtDetail"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskShtDetail"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSta", TxfSta)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxfSta == comp.TxfSta {items.insert(ContIac.TXFSTA)}
			if TxfCmt == comp.TxfCmt {items.insert(ContIac.TXFCMT)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.TXFSTA, ContIac.TXFCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskShtDetail)
	  */
	public class ContInf: Block {

		public static let TXTSES: Int = 1
		public static let TXTOBJ: Int = 2

		public init(
					_ TxtSes: String = ""
					, _ TxtObj: String = ""
				) {
			self.TxtSes = TxtSes
			self.TxtObj = TxtObj

			super.init()

			mask = [ContInf.TXTSES, ContInf.TXTOBJ]
		}

		public var TxtSes: String
		public var TxtObj: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskShtDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskShtDetail"

			if valid {
				TxtSes = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtSes", &mask, ContInf.TXTSES)
				TxtObj = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtObj", &mask, ContInf.TXTOBJ)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtSes == comp.TxtSes {items.insert(ContInf.TXTSES)}
			if TxtObj == comp.TxtObj {items.insert(ContInf.TXTOBJ)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTSES, ContInf.TXTOBJ]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskShtDetail)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskShtDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskShtDetail"

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
	  * StatShr (full: StatShrWzskShtDetail)
	  */
	public class StatShr: Block {

		public static let BUTSAVEAVAIL: Int = 1
		public static let BUTSAVEACTIVE: Int = 2
		public static let TXTSESACTIVE: Int = 3
		public static let BUTSESVIEWAVAIL: Int = 4
		public static let BUTSESVIEWACTIVE: Int = 5
		public static let TXTOBJACTIVE: Int = 6
		public static let BUTOBJVIEWAVAIL: Int = 7
		public static let BUTOBJVIEWACTIVE: Int = 8
		public static let TXFSTAACTIVE: Int = 9
		public static let TXFCMTACTIVE: Int = 10

		public init(
					_ ButSaveAvail: Bool = false
					, _ ButSaveActive: Bool = false
					, _ TxtSesActive: Bool = false
					, _ ButSesViewAvail: Bool = false
					, _ ButSesViewActive: Bool = false
					, _ TxtObjActive: Bool = false
					, _ ButObjViewAvail: Bool = false
					, _ ButObjViewActive: Bool = false
					, _ TxfStaActive: Bool = false
					, _ TxfCmtActive: Bool = false
				) {
			self.ButSaveAvail = ButSaveAvail
			self.ButSaveActive = ButSaveActive
			self.TxtSesActive = TxtSesActive
			self.ButSesViewAvail = ButSesViewAvail
			self.ButSesViewActive = ButSesViewActive
			self.TxtObjActive = TxtObjActive
			self.ButObjViewAvail = ButObjViewAvail
			self.ButObjViewActive = ButObjViewActive
			self.TxfStaActive = TxfStaActive
			self.TxfCmtActive = TxfCmtActive

			super.init()

			mask = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXTSESACTIVE, StatShr.BUTSESVIEWAVAIL, StatShr.BUTSESVIEWACTIVE, StatShr.TXTOBJACTIVE, StatShr.BUTOBJVIEWAVAIL, StatShr.BUTOBJVIEWACTIVE, StatShr.TXFSTAACTIVE, StatShr.TXFCMTACTIVE]
		}

		public var ButSaveAvail: Bool
		public var ButSaveActive: Bool
		public var TxtSesActive: Bool
		public var ButSesViewAvail: Bool
		public var ButSesViewActive: Bool
		public var TxtObjActive: Bool
		public var ButObjViewAvail: Bool
		public var ButObjViewActive: Bool
		public var TxfStaActive: Bool
		public var TxfCmtActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskShtDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskShtDetail"

			if valid {
				ButSaveAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveAvail", &mask, StatShr.BUTSAVEAVAIL)
				ButSaveActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveActive", &mask, StatShr.BUTSAVEACTIVE)
				TxtSesActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtSesActive", &mask, StatShr.TXTSESACTIVE)
				ButSesViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSesViewAvail", &mask, StatShr.BUTSESVIEWAVAIL)
				ButSesViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSesViewActive", &mask, StatShr.BUTSESVIEWACTIVE)
				TxtObjActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtObjActive", &mask, StatShr.TXTOBJACTIVE)
				ButObjViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButObjViewAvail", &mask, StatShr.BUTOBJVIEWAVAIL)
				ButObjViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButObjViewActive", &mask, StatShr.BUTOBJVIEWACTIVE)
				TxfStaActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfStaActive", &mask, StatShr.TXFSTAACTIVE)
				TxfCmtActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfCmtActive", &mask, StatShr.TXFCMTACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButSaveAvail == comp.ButSaveAvail {items.insert(StatShr.BUTSAVEAVAIL)}
			if ButSaveActive == comp.ButSaveActive {items.insert(StatShr.BUTSAVEACTIVE)}
			if TxtSesActive == comp.TxtSesActive {items.insert(StatShr.TXTSESACTIVE)}
			if ButSesViewAvail == comp.ButSesViewAvail {items.insert(StatShr.BUTSESVIEWAVAIL)}
			if ButSesViewActive == comp.ButSesViewActive {items.insert(StatShr.BUTSESVIEWACTIVE)}
			if TxtObjActive == comp.TxtObjActive {items.insert(StatShr.TXTOBJACTIVE)}
			if ButObjViewAvail == comp.ButObjViewAvail {items.insert(StatShr.BUTOBJVIEWAVAIL)}
			if ButObjViewActive == comp.ButObjViewActive {items.insert(StatShr.BUTOBJVIEWACTIVE)}
			if TxfStaActive == comp.TxfStaActive {items.insert(StatShr.TXFSTAACTIVE)}
			if TxfCmtActive == comp.TxfCmtActive {items.insert(StatShr.TXFCMTACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXTSESACTIVE, StatShr.BUTSESVIEWAVAIL, StatShr.BUTSESVIEWACTIVE, StatShr.TXTOBJACTIVE, StatShr.BUTOBJVIEWAVAIL, StatShr.BUTOBJVIEWACTIVE, StatShr.TXFSTAACTIVE, StatShr.TXFCMTACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskShtDetail)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTSES: Int = 2
		public static let CPTOBJ: Int = 3
		public static let CPTSTA: Int = 4
		public static let CPTCMT: Int = 5

		public init(
					_ Cpt: String = ""
					, _ CptSes: String = ""
					, _ CptObj: String = ""
					, _ CptSta: String = ""
					, _ CptCmt: String = ""
				) {
			self.Cpt = Cpt
			self.CptSes = CptSes
			self.CptObj = CptObj
			self.CptSta = CptSta
			self.CptCmt = CptCmt

			super.init()

			mask = [Tag.CPT, Tag.CPTSES, Tag.CPTOBJ, Tag.CPTSTA, Tag.CPTCMT]
		}

		public var Cpt: String
		public var CptSes: String
		public var CptObj: String
		public var CptSta: String
		public var CptCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskShtDetail")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskShtDetail"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptSes = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSes", &mask, Tag.CPTSES)
				CptObj = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptObj", &mask, Tag.CPTOBJ)
				CptSta = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSta", &mask, Tag.CPTSTA)
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCmt", &mask, Tag.CPTCMT)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptSes == comp.CptSes {items.insert(Tag.CPTSES)}
			if CptObj == comp.CptObj {items.insert(Tag.CPTOBJ)}
			if CptSta == comp.CptSta {items.insert(Tag.CPTSTA)}
			if CptCmt == comp.CptCmt {items.insert(Tag.CPTCMT)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTSES, Tag.CPTOBJ, Tag.CPTSTA, Tag.CPTCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskShtDetailData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKSHTDETAILDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskShtDetailData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskShtDetailDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKSHTDETAILDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskShtDetailDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskShtDetailData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKSHTDETAILDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskShtDetailData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
