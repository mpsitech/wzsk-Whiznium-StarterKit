/**
  * \file PnlWzskSesDetail.swift
  * Swift API code for job PnlWzskSesDetail
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskSesDetail
	*/
public class PnlWzskSesDetail {
	/**
		* VecVDo (full: VecVWzskSesDetailDo)
		*/
	public class VecVDo {

		public static let BUTSAVECLICK: Int = 1
		public static let BUTUSRVIEWCLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butsaveclick" {return BUTSAVECLICK}
			if s == "butusrviewclick" {return BUTUSRVIEWCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTSAVECLICK {return "ButSaveClick"}
			if ix == BUTUSRVIEWCLICK {return "ButUsrViewClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskSesDetail)
	  */
	public class ContIac: Block {

		public static let TXFSTA: Int = 1
		public static let TXFSTO: Int = 2
		public static let TXFIP: Int = 3

		public init(
					_ TxfSta: String = ""
					, _ TxfSto: String = ""
					, _ TxfIp: String = ""
				) {
			self.TxfSta = TxfSta
			self.TxfSto = TxfSto
			self.TxfIp = TxfIp

			super.init()

			mask = [ContIac.TXFSTA, ContIac.TXFSTO, ContIac.TXFIP]
		}

		public var TxfSta: String
		public var TxfSto: String
		public var TxfIp: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskSesDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskSesDetail"

			if valid {
				TxfSta = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfSta", &mask, ContIac.TXFSTA)
				TxfSto = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfSto", &mask, ContIac.TXFSTO)
				TxfIp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfIp", &mask, ContIac.TXFIP)
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
			if tag == nil {tag = "ContIacWzskSesDetail"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskSesDetail"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSta", TxfSta)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSto", TxfSto)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfIp", TxfIp)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxfSta == comp.TxfSta {items.insert(ContIac.TXFSTA)}
			if TxfSto == comp.TxfSto {items.insert(ContIac.TXFSTO)}
			if TxfIp == comp.TxfIp {items.insert(ContIac.TXFIP)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.TXFSTA, ContIac.TXFSTO, ContIac.TXFIP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskSesDetail)
	  */
	public class ContInf: Block {

		public static let TXTUSR: Int = 1

		public init(
					_ TxtUsr: String = ""
				) {
			self.TxtUsr = TxtUsr

			super.init()

			mask = [ContInf.TXTUSR]
		}

		public var TxtUsr: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskSesDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskSesDetail"

			if valid {
				TxtUsr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtUsr", &mask, ContInf.TXTUSR)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtUsr == comp.TxtUsr {items.insert(ContInf.TXTUSR)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTUSR]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskSesDetail)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskSesDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskSesDetail"

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
	  * StatShr (full: StatShrWzskSesDetail)
	  */
	public class StatShr: Block {

		public static let BUTSAVEAVAIL: Int = 1
		public static let BUTSAVEACTIVE: Int = 2
		public static let TXTUSRACTIVE: Int = 3
		public static let BUTUSRVIEWAVAIL: Int = 4
		public static let BUTUSRVIEWACTIVE: Int = 5
		public static let TXFSTAACTIVE: Int = 6
		public static let TXFSTOACTIVE: Int = 7
		public static let TXFIPACTIVE: Int = 8

		public init(
					_ ButSaveAvail: Bool = false
					, _ ButSaveActive: Bool = false
					, _ TxtUsrActive: Bool = false
					, _ ButUsrViewAvail: Bool = false
					, _ ButUsrViewActive: Bool = false
					, _ TxfStaActive: Bool = false
					, _ TxfStoActive: Bool = false
					, _ TxfIpActive: Bool = false
				) {
			self.ButSaveAvail = ButSaveAvail
			self.ButSaveActive = ButSaveActive
			self.TxtUsrActive = TxtUsrActive
			self.ButUsrViewAvail = ButUsrViewAvail
			self.ButUsrViewActive = ButUsrViewActive
			self.TxfStaActive = TxfStaActive
			self.TxfStoActive = TxfStoActive
			self.TxfIpActive = TxfIpActive

			super.init()

			mask = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXTUSRACTIVE, StatShr.BUTUSRVIEWAVAIL, StatShr.BUTUSRVIEWACTIVE, StatShr.TXFSTAACTIVE, StatShr.TXFSTOACTIVE, StatShr.TXFIPACTIVE]
		}

		public var ButSaveAvail: Bool
		public var ButSaveActive: Bool
		public var TxtUsrActive: Bool
		public var ButUsrViewAvail: Bool
		public var ButUsrViewActive: Bool
		public var TxfStaActive: Bool
		public var TxfStoActive: Bool
		public var TxfIpActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskSesDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskSesDetail"

			if valid {
				ButSaveAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveAvail", &mask, StatShr.BUTSAVEAVAIL)
				ButSaveActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveActive", &mask, StatShr.BUTSAVEACTIVE)
				TxtUsrActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtUsrActive", &mask, StatShr.TXTUSRACTIVE)
				ButUsrViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButUsrViewAvail", &mask, StatShr.BUTUSRVIEWAVAIL)
				ButUsrViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButUsrViewActive", &mask, StatShr.BUTUSRVIEWACTIVE)
				TxfStaActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfStaActive", &mask, StatShr.TXFSTAACTIVE)
				TxfStoActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfStoActive", &mask, StatShr.TXFSTOACTIVE)
				TxfIpActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfIpActive", &mask, StatShr.TXFIPACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButSaveAvail == comp.ButSaveAvail {items.insert(StatShr.BUTSAVEAVAIL)}
			if ButSaveActive == comp.ButSaveActive {items.insert(StatShr.BUTSAVEACTIVE)}
			if TxtUsrActive == comp.TxtUsrActive {items.insert(StatShr.TXTUSRACTIVE)}
			if ButUsrViewAvail == comp.ButUsrViewAvail {items.insert(StatShr.BUTUSRVIEWAVAIL)}
			if ButUsrViewActive == comp.ButUsrViewActive {items.insert(StatShr.BUTUSRVIEWACTIVE)}
			if TxfStaActive == comp.TxfStaActive {items.insert(StatShr.TXFSTAACTIVE)}
			if TxfStoActive == comp.TxfStoActive {items.insert(StatShr.TXFSTOACTIVE)}
			if TxfIpActive == comp.TxfIpActive {items.insert(StatShr.TXFIPACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXTUSRACTIVE, StatShr.BUTUSRVIEWAVAIL, StatShr.BUTUSRVIEWACTIVE, StatShr.TXFSTAACTIVE, StatShr.TXFSTOACTIVE, StatShr.TXFIPACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskSesDetail)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTUSR: Int = 2
		public static let CPTSTA: Int = 3
		public static let CPTSTO: Int = 4
		public static let CPTIP: Int = 5

		public init(
					_ Cpt: String = ""
					, _ CptUsr: String = ""
					, _ CptSta: String = ""
					, _ CptSto: String = ""
					, _ CptIp: String = ""
				) {
			self.Cpt = Cpt
			self.CptUsr = CptUsr
			self.CptSta = CptSta
			self.CptSto = CptSto
			self.CptIp = CptIp

			super.init()

			mask = [Tag.CPT, Tag.CPTUSR, Tag.CPTSTA, Tag.CPTSTO, Tag.CPTIP]
		}

		public var Cpt: String
		public var CptUsr: String
		public var CptSta: String
		public var CptSto: String
		public var CptIp: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskSesDetail")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskSesDetail"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptUsr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptUsr", &mask, Tag.CPTUSR)
				CptSta = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSta", &mask, Tag.CPTSTA)
				CptSto = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSto", &mask, Tag.CPTSTO)
				CptIp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptIp", &mask, Tag.CPTIP)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptUsr == comp.CptUsr {items.insert(Tag.CPTUSR)}
			if CptSta == comp.CptSta {items.insert(Tag.CPTSTA)}
			if CptSto == comp.CptSto {items.insert(Tag.CPTSTO)}
			if CptIp == comp.CptIp {items.insert(Tag.CPTIP)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTUSR, Tag.CPTSTA, Tag.CPTSTO, Tag.CPTIP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskSesDetailData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKSESDETAILDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskSesDetailData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskSesDetailDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKSESDETAILDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskSesDetailDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskSesDetailData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKSESDETAILDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskSesDetailData")}
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
