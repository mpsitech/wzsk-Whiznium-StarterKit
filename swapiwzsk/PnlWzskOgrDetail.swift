/**
  * \file PnlWzskOgrDetail.swift
  * Swift API code for job PnlWzskOgrDetail
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskOgrDetail
	*/
public class PnlWzskOgrDetail {
	/**
		* VecVDo (full: VecVWzskOgrDetailDo)
		*/
	public class VecVDo {

		public static let BUTSAVECLICK: Int = 1
		public static let BUTJEDITCLICK: Int = 2
		public static let BUTSUPVIEWCLICK: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butsaveclick" {return BUTSAVECLICK}
			if s == "butjeditclick" {return BUTJEDITCLICK}
			if s == "butsupviewclick" {return BUTSUPVIEWCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTSAVECLICK {return "ButSaveClick"}
			if ix == BUTJEDITCLICK {return "ButJEditClick"}
			if ix == BUTSUPVIEWCLICK {return "ButSupViewClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskOgrDetail)
	  */
	public class ContIac: Block {

		public static let NUMFPUPJ: Int = 1
		public static let TXFCMT: Int = 2

		public init(
					_ numFPupJ: Int = 0
					, _ TxfCmt: String = ""
				) {
			self.numFPupJ = numFPupJ
			self.TxfCmt = TxfCmt

			super.init()

			mask = [ContIac.NUMFPUPJ, ContIac.TXFCMT]
		}

		public var numFPupJ: Int
		public var TxfCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskOgrDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskOgrDetail"

			if valid {
				numFPupJ = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupJ", &mask, ContIac.NUMFPUPJ)
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
			if tag == nil {tag = "ContIacWzskOgrDetail"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskOgrDetail"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupJ", numFPupJ)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFPupJ == comp.numFPupJ {items.insert(ContIac.NUMFPUPJ)}
			if TxfCmt == comp.TxfCmt {items.insert(ContIac.TXFCMT)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFPUPJ, ContIac.TXFCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskOgrDetail)
	  */
	public class ContInf: Block {

		public static let TXTSRF: Int = 1
		public static let TXTTIT: Int = 2
		public static let TXTSUP: Int = 3

		public init(
					_ TxtSrf: String = ""
					, _ TxtTit: String = ""
					, _ TxtSup: String = ""
				) {
			self.TxtSrf = TxtSrf
			self.TxtTit = TxtTit
			self.TxtSup = TxtSup

			super.init()

			mask = [ContInf.TXTSRF, ContInf.TXTTIT, ContInf.TXTSUP]
		}

		public var TxtSrf: String
		public var TxtTit: String
		public var TxtSup: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskOgrDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskOgrDetail"

			if valid {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtSrf", &mask, ContInf.TXTSRF)
				TxtTit = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtTit", &mask, ContInf.TXTTIT)
				TxtSup = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtSup", &mask, ContInf.TXTSUP)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtSrf == comp.TxtSrf {items.insert(ContInf.TXTSRF)}
			if TxtTit == comp.TxtTit {items.insert(ContInf.TXTTIT)}
			if TxtSup == comp.TxtSup {items.insert(ContInf.TXTSUP)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTSRF, ContInf.TXTTIT, ContInf.TXTSUP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskOgrDetail)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskOgrDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskOgrDetail"

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
	  * StatShr (full: StatShrWzskOgrDetail)
	  */
	public class StatShr: Block {

		public static let BUTSAVEAVAIL: Int = 1
		public static let BUTSAVEACTIVE: Int = 2
		public static let TXTSRFACTIVE: Int = 3
		public static let PUPJACTIVE: Int = 4
		public static let BUTJEDITAVAIL: Int = 5
		public static let TXTTITACTIVE: Int = 6
		public static let TXTSUPACTIVE: Int = 7
		public static let BUTSUPVIEWAVAIL: Int = 8
		public static let BUTSUPVIEWACTIVE: Int = 9
		public static let TXFCMTACTIVE: Int = 10

		public init(
					_ ButSaveAvail: Bool = false
					, _ ButSaveActive: Bool = false
					, _ TxtSrfActive: Bool = false
					, _ PupJActive: Bool = false
					, _ ButJEditAvail: Bool = false
					, _ TxtTitActive: Bool = false
					, _ TxtSupActive: Bool = false
					, _ ButSupViewAvail: Bool = false
					, _ ButSupViewActive: Bool = false
					, _ TxfCmtActive: Bool = false
				) {
			self.ButSaveAvail = ButSaveAvail
			self.ButSaveActive = ButSaveActive
			self.TxtSrfActive = TxtSrfActive
			self.PupJActive = PupJActive
			self.ButJEditAvail = ButJEditAvail
			self.TxtTitActive = TxtTitActive
			self.TxtSupActive = TxtSupActive
			self.ButSupViewAvail = ButSupViewAvail
			self.ButSupViewActive = ButSupViewActive
			self.TxfCmtActive = TxfCmtActive

			super.init()

			mask = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXTSRFACTIVE, StatShr.PUPJACTIVE, StatShr.BUTJEDITAVAIL, StatShr.TXTTITACTIVE, StatShr.TXTSUPACTIVE, StatShr.BUTSUPVIEWAVAIL, StatShr.BUTSUPVIEWACTIVE, StatShr.TXFCMTACTIVE]
		}

		public var ButSaveAvail: Bool
		public var ButSaveActive: Bool
		public var TxtSrfActive: Bool
		public var PupJActive: Bool
		public var ButJEditAvail: Bool
		public var TxtTitActive: Bool
		public var TxtSupActive: Bool
		public var ButSupViewAvail: Bool
		public var ButSupViewActive: Bool
		public var TxfCmtActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskOgrDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskOgrDetail"

			if valid {
				ButSaveAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveAvail", &mask, StatShr.BUTSAVEAVAIL)
				ButSaveActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveActive", &mask, StatShr.BUTSAVEACTIVE)
				TxtSrfActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtSrfActive", &mask, StatShr.TXTSRFACTIVE)
				PupJActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupJActive", &mask, StatShr.PUPJACTIVE)
				ButJEditAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButJEditAvail", &mask, StatShr.BUTJEDITAVAIL)
				TxtTitActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtTitActive", &mask, StatShr.TXTTITACTIVE)
				TxtSupActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtSupActive", &mask, StatShr.TXTSUPACTIVE)
				ButSupViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSupViewAvail", &mask, StatShr.BUTSUPVIEWAVAIL)
				ButSupViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSupViewActive", &mask, StatShr.BUTSUPVIEWACTIVE)
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
			if TxtSrfActive == comp.TxtSrfActive {items.insert(StatShr.TXTSRFACTIVE)}
			if PupJActive == comp.PupJActive {items.insert(StatShr.PUPJACTIVE)}
			if ButJEditAvail == comp.ButJEditAvail {items.insert(StatShr.BUTJEDITAVAIL)}
			if TxtTitActive == comp.TxtTitActive {items.insert(StatShr.TXTTITACTIVE)}
			if TxtSupActive == comp.TxtSupActive {items.insert(StatShr.TXTSUPACTIVE)}
			if ButSupViewAvail == comp.ButSupViewAvail {items.insert(StatShr.BUTSUPVIEWAVAIL)}
			if ButSupViewActive == comp.ButSupViewActive {items.insert(StatShr.BUTSUPVIEWACTIVE)}
			if TxfCmtActive == comp.TxfCmtActive {items.insert(StatShr.TXFCMTACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXTSRFACTIVE, StatShr.PUPJACTIVE, StatShr.BUTJEDITAVAIL, StatShr.TXTTITACTIVE, StatShr.TXTSUPACTIVE, StatShr.BUTSUPVIEWAVAIL, StatShr.BUTSUPVIEWACTIVE, StatShr.TXFCMTACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskOgrDetail)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTSRF: Int = 2
		public static let CPTTIT: Int = 3
		public static let CPTSUP: Int = 4
		public static let CPTCMT: Int = 5

		public init(
					_ Cpt: String = ""
					, _ CptSrf: String = ""
					, _ CptTit: String = ""
					, _ CptSup: String = ""
					, _ CptCmt: String = ""
				) {
			self.Cpt = Cpt
			self.CptSrf = CptSrf
			self.CptTit = CptTit
			self.CptSup = CptSup
			self.CptCmt = CptCmt

			super.init()

			mask = [Tag.CPT, Tag.CPTSRF, Tag.CPTTIT, Tag.CPTSUP, Tag.CPTCMT]
		}

		public var Cpt: String
		public var CptSrf: String
		public var CptTit: String
		public var CptSup: String
		public var CptCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskOgrDetail")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskOgrDetail"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSrf", &mask, Tag.CPTSRF)
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptTit", &mask, Tag.CPTTIT)
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSup", &mask, Tag.CPTSUP)
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCmt", &mask, Tag.CPTCMT)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptSrf == comp.CptSrf {items.insert(Tag.CPTSRF)}
			if CptTit == comp.CptTit {items.insert(Tag.CPTTIT)}
			if CptSup == comp.CptSup {items.insert(Tag.CPTSUP)}
			if CptCmt == comp.CptCmt {items.insert(Tag.CPTCMT)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTSRF, Tag.CPTTIT, Tag.CPTSUP, Tag.CPTCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskOgrDetailData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKOGRDETAILDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskOgrDetailData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskOgrDetailDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKOGRDETAILDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskOgrDetailDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskOgrDetailData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFPUPJ: Int = 4
		public static let STATAPP: Int = 5
		public static let STATSHR: Int = 6
		public static let TAG: Int = 7

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKOGRDETAILDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFPupJ: Feed = Feed("FeedFPupJ")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFPUPJ) {ss.append("feedFPupJ")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskOgrDetailData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFPupJ.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPJ)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFPupJ = Feed("FeedFPupJ")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
