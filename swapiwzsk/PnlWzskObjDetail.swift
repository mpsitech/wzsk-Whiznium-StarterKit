/**
  * \file PnlWzskObjDetail.swift
  * Swift API code for job PnlWzskObjDetail
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskObjDetail
	*/
public class PnlWzskObjDetail {
	/**
		* VecVDo (full: VecVWzskObjDetailDo)
		*/
	public class VecVDo {

		public static let BUTSAVECLICK: Int = 1
		public static let BUTOGRVIEWCLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butsaveclick" {return BUTSAVECLICK}
			if s == "butogrviewclick" {return BUTOGRVIEWCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTSAVECLICK {return "ButSaveClick"}
			if ix == BUTOGRVIEWCLICK {return "ButOgrViewClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskObjDetail)
	  */
	public class ContIac: Block {

		public static let TXFTIT: Int = 1
		public static let TXFCMT: Int = 2

		public init(
					_ TxfTit: String = ""
					, _ TxfCmt: String = ""
				) {
			self.TxfTit = TxfTit
			self.TxfCmt = TxfCmt

			super.init()

			mask = [ContIac.TXFTIT, ContIac.TXFCMT]
		}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskObjDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskObjDetail"

			if valid {
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
			if tag == nil {tag = "ContIacWzskObjDetail"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskObjDetail"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxfTit == comp.TxfTit {items.insert(ContIac.TXFTIT)}
			if TxfCmt == comp.TxfCmt {items.insert(ContIac.TXFCMT)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.TXFTIT, ContIac.TXFCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskObjDetail)
	  */
	public class ContInf: Block {

		public static let TXTOGR: Int = 1

		public init(
					_ TxtOgr: String = ""
				) {
			self.TxtOgr = TxtOgr

			super.init()

			mask = [ContInf.TXTOGR]
		}

		public var TxtOgr: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskObjDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskObjDetail"

			if valid {
				TxtOgr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtOgr", &mask, ContInf.TXTOGR)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtOgr == comp.TxtOgr {items.insert(ContInf.TXTOGR)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTOGR]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskObjDetail)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskObjDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskObjDetail"

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
	  * StatShr (full: StatShrWzskObjDetail)
	  */
	public class StatShr: Block {

		public static let BUTSAVEAVAIL: Int = 1
		public static let BUTSAVEACTIVE: Int = 2
		public static let TXFTITACTIVE: Int = 3
		public static let TXTOGRACTIVE: Int = 4
		public static let BUTOGRVIEWAVAIL: Int = 5
		public static let BUTOGRVIEWACTIVE: Int = 6
		public static let TXFCMTACTIVE: Int = 7

		public init(
					_ ButSaveAvail: Bool = false
					, _ ButSaveActive: Bool = false
					, _ TxfTitActive: Bool = false
					, _ TxtOgrActive: Bool = false
					, _ ButOgrViewAvail: Bool = false
					, _ ButOgrViewActive: Bool = false
					, _ TxfCmtActive: Bool = false
				) {
			self.ButSaveAvail = ButSaveAvail
			self.ButSaveActive = ButSaveActive
			self.TxfTitActive = TxfTitActive
			self.TxtOgrActive = TxtOgrActive
			self.ButOgrViewAvail = ButOgrViewAvail
			self.ButOgrViewActive = ButOgrViewActive
			self.TxfCmtActive = TxfCmtActive

			super.init()

			mask = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXFTITACTIVE, StatShr.TXTOGRACTIVE, StatShr.BUTOGRVIEWAVAIL, StatShr.BUTOGRVIEWACTIVE, StatShr.TXFCMTACTIVE]
		}

		public var ButSaveAvail: Bool
		public var ButSaveActive: Bool
		public var TxfTitActive: Bool
		public var TxtOgrActive: Bool
		public var ButOgrViewAvail: Bool
		public var ButOgrViewActive: Bool
		public var TxfCmtActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskObjDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskObjDetail"

			if valid {
				ButSaveAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveAvail", &mask, StatShr.BUTSAVEAVAIL)
				ButSaveActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveActive", &mask, StatShr.BUTSAVEACTIVE)
				TxfTitActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfTitActive", &mask, StatShr.TXFTITACTIVE)
				TxtOgrActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtOgrActive", &mask, StatShr.TXTOGRACTIVE)
				ButOgrViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButOgrViewAvail", &mask, StatShr.BUTOGRVIEWAVAIL)
				ButOgrViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButOgrViewActive", &mask, StatShr.BUTOGRVIEWACTIVE)
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
			if TxfTitActive == comp.TxfTitActive {items.insert(StatShr.TXFTITACTIVE)}
			if TxtOgrActive == comp.TxtOgrActive {items.insert(StatShr.TXTOGRACTIVE)}
			if ButOgrViewAvail == comp.ButOgrViewAvail {items.insert(StatShr.BUTOGRVIEWAVAIL)}
			if ButOgrViewActive == comp.ButOgrViewActive {items.insert(StatShr.BUTOGRVIEWACTIVE)}
			if TxfCmtActive == comp.TxfCmtActive {items.insert(StatShr.TXFCMTACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXFTITACTIVE, StatShr.TXTOGRACTIVE, StatShr.BUTOGRVIEWAVAIL, StatShr.BUTOGRVIEWACTIVE, StatShr.TXFCMTACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskObjDetail)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTTIT: Int = 2
		public static let CPTOGR: Int = 3
		public static let CPTCMT: Int = 4

		public init(
					_ Cpt: String = ""
					, _ CptTit: String = ""
					, _ CptOgr: String = ""
					, _ CptCmt: String = ""
				) {
			self.Cpt = Cpt
			self.CptTit = CptTit
			self.CptOgr = CptOgr
			self.CptCmt = CptCmt

			super.init()

			mask = [Tag.CPT, Tag.CPTTIT, Tag.CPTOGR, Tag.CPTCMT]
		}

		public var Cpt: String
		public var CptTit: String
		public var CptOgr: String
		public var CptCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskObjDetail")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskObjDetail"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptTit", &mask, Tag.CPTTIT)
				CptOgr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptOgr", &mask, Tag.CPTOGR)
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCmt", &mask, Tag.CPTCMT)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptTit == comp.CptTit {items.insert(Tag.CPTTIT)}
			if CptOgr == comp.CptOgr {items.insert(Tag.CPTOGR)}
			if CptCmt == comp.CptCmt {items.insert(Tag.CPTCMT)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTTIT, Tag.CPTOGR, Tag.CPTCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskObjDetailData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKOBJDETAILDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskObjDetailData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskObjDetailDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKOBJDETAILDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskObjDetailDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskObjDetailData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKOBJDETAILDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskObjDetailData")}
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
