/**
  * \file PnlWzskLlvTermIcicle.swift
  * Swift API code for job PnlWzskLlvTermIcicle
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskLlvTermIcicle
	*/
public class PnlWzskLlvTermIcicle {
	/**
		* VecVDo (full: VecVWzskLlvTermIcicleDo)
		*/
	public class VecVDo {

		public static let BUTREGULARIZECLICK: Int = 1
		public static let BUTMINIMIZECLICK: Int = 2
		public static let BUTCLAIMCLICK: Int = 3
		public static let BUTAPDCLICK: Int = 4
		public static let BUTSMTCLICK: Int = 5

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butregularizeclick" {return BUTREGULARIZECLICK}
			if s == "butminimizeclick" {return BUTMINIMIZECLICK}
			if s == "butclaimclick" {return BUTCLAIMCLICK}
			if s == "butapdclick" {return BUTAPDCLICK}
			if s == "butsmtclick" {return BUTSMTCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTREGULARIZECLICK {return "ButRegularizeClick"}
			if ix == BUTMINIMIZECLICK {return "ButMinimizeClick"}
			if ix == BUTCLAIMCLICK {return "ButClaimClick"}
			if ix == BUTAPDCLICK {return "ButApdClick"}
			if ix == BUTSMTCLICK {return "ButSmtClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskLlvTermIcicle)
	  */
	public class ContIac: Block {

		public static let NUMFPUPCMD: Int = 1
		public static let TXFCSQ: Int = 2

		public init(
					_ numFPupCmd: Int = 0
					, _ TxfCsq: String = ""
				) {
			self.numFPupCmd = numFPupCmd
			self.TxfCsq = TxfCsq

			super.init()

			mask = [ContIac.NUMFPUPCMD, ContIac.TXFCSQ]
		}

		public var numFPupCmd: Int
		public var TxfCsq: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskLlvTermIcicle")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskLlvTermIcicle"

			if valid {
				numFPupCmd = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupCmd", &mask, ContIac.NUMFPUPCMD)
				TxfCsq = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfCsq", &mask, ContIac.TXFCSQ)
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
			if tag == nil {tag = "ContIacWzskLlvTermIcicle"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskLlvTermIcicle"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupCmd", numFPupCmd)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCsq", TxfCsq)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFPupCmd == comp.numFPupCmd {items.insert(ContIac.NUMFPUPCMD)}
			if TxfCsq == comp.TxfCsq {items.insert(ContIac.TXFCSQ)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFPUPCMD, ContIac.TXFCSQ]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskLlvTermIcicle)
	  */
	public class ContInf: Block {

		public static let BUTCLAIMON: Int = 1
		public static let TXTCST: Int = 2
		public static let TXTDATLOG: Int = 3

		public init(
					_ ButClaimOn: Bool = false
					, _ TxtCst: String = ""
					, _ TxtDatLog: String = ""
				) {
			self.ButClaimOn = ButClaimOn
			self.TxtCst = TxtCst
			self.TxtDatLog = TxtDatLog

			super.init()

			mask = [ContInf.BUTCLAIMON, ContInf.TXTCST, ContInf.TXTDATLOG]
		}

		public var ButClaimOn: Bool
		public var TxtCst: String
		public var TxtDatLog: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskLlvTermIcicle")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskLlvTermIcicle"

			if valid {
				ButClaimOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimOn", &mask, ContInf.BUTCLAIMON)
				TxtCst = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtCst", &mask, ContInf.TXTCST)
				TxtDatLog = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtDatLog", &mask, ContInf.TXTDATLOG)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButClaimOn == comp.ButClaimOn {items.insert(ContInf.BUTCLAIMON)}
			if TxtCst == comp.TxtCst {items.insert(ContInf.TXTCST)}
			if TxtDatLog == comp.TxtDatLog {items.insert(ContInf.TXTDATLOG)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.BUTCLAIMON, ContInf.TXTCST, ContInf.TXTDATLOG]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskLlvTermIcicle)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let BUTCLAIMACTIVE: Int = 2
		public static let BUTSMTACTIVE: Int = 3

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ ButClaimActive: Bool = false
					, _ ButSmtActive: Bool = false
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.ButClaimActive = ButClaimActive
			self.ButSmtActive = ButSmtActive

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.BUTSMTACTIVE]
		}

		public var ixWzskVExpstate: Int
		public var ButClaimActive: Bool
		public var ButSmtActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskLlvTermIcicle")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskLlvTermIcicle"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				ButClaimActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimActive", &mask, StatShr.BUTCLAIMACTIVE)
				ButSmtActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSmtActive", &mask, StatShr.BUTSMTACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}
			if ButClaimActive == comp.ButClaimActive {items.insert(StatShr.BUTCLAIMACTIVE)}
			if ButSmtActive == comp.ButSmtActive {items.insert(StatShr.BUTSMTACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.BUTSMTACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskLlvTermIcicle)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTCST: Int = 2
		public static let HDGDIO: Int = 3
		public static let HDGCEX: Int = 4
		public static let CPTCMD: Int = 5
		public static let BUTAPD: Int = 6
		public static let CPTCSQ: Int = 7
		public static let BUTSMT: Int = 8

		public init(
					_ Cpt: String = ""
					, _ CptCst: String = ""
					, _ HdgDio: String = ""
					, _ HdgCex: String = ""
					, _ CptCmd: String = ""
					, _ ButApd: String = ""
					, _ CptCsq: String = ""
					, _ ButSmt: String = ""
				) {
			self.Cpt = Cpt
			self.CptCst = CptCst
			self.HdgDio = HdgDio
			self.HdgCex = HdgCex
			self.CptCmd = CptCmd
			self.ButApd = ButApd
			self.CptCsq = CptCsq
			self.ButSmt = ButSmt

			super.init()

			mask = [Tag.CPT, Tag.CPTCST, Tag.HDGDIO, Tag.HDGCEX, Tag.CPTCMD, Tag.BUTAPD, Tag.CPTCSQ, Tag.BUTSMT]
		}

		public var Cpt: String
		public var CptCst: String
		public var HdgDio: String
		public var HdgCex: String
		public var CptCmd: String
		public var ButApd: String
		public var CptCsq: String
		public var ButSmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskLlvTermIcicle")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskLlvTermIcicle"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptCst = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCst", &mask, Tag.CPTCST)
				HdgDio = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "HdgDio", &mask, Tag.HDGDIO)
				HdgCex = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "HdgCex", &mask, Tag.HDGCEX)
				CptCmd = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCmd", &mask, Tag.CPTCMD)
				ButApd = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButApd", &mask, Tag.BUTAPD)
				CptCsq = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCsq", &mask, Tag.CPTCSQ)
				ButSmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButSmt", &mask, Tag.BUTSMT)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptCst == comp.CptCst {items.insert(Tag.CPTCST)}
			if HdgDio == comp.HdgDio {items.insert(Tag.HDGDIO)}
			if HdgCex == comp.HdgCex {items.insert(Tag.HDGCEX)}
			if CptCmd == comp.CptCmd {items.insert(Tag.CPTCMD)}
			if ButApd == comp.ButApd {items.insert(Tag.BUTAPD)}
			if CptCsq == comp.CptCsq {items.insert(Tag.CPTCSQ)}
			if ButSmt == comp.ButSmt {items.insert(Tag.BUTSMT)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTCST, Tag.HDGDIO, Tag.HDGCEX, Tag.CPTCMD, Tag.BUTAPD, Tag.CPTCSQ, Tag.BUTSMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskLlvTermIcicleData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVTERMICICLEDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvTermIcicleData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskLlvTermIcicleDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVTERMICICLEDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvTermIcicleDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskLlvTermIcicleData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFPUPCMD: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLLVTERMICICLEDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFPupCmd: Feed = Feed("FeedFPupCmd")
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFPUPCMD) {ss.append("feedFPupCmd")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLlvTermIcicleData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFPupCmd.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPCMD)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFPupCmd = Feed("FeedFPupCmd")
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
