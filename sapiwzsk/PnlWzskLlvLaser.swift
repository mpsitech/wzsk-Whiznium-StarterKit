/**
  * \file PnlWzskLlvLaser.swift
  * Swift API code for job PnlWzskLlvLaser
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskLlvLaser
	*/
public class PnlWzskLlvLaser {
	/**
		* VecVDo (full: VecVWzskLlvLaserDo)
		*/
	public class VecVDo {

		public static let BUTREGULARIZECLICK: Int = 1
		public static let BUTMINIMIZECLICK: Int = 2
		public static let BUTCLAIMCLICK: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butregularizeclick" {return BUTREGULARIZECLICK}
			if s == "butminimizeclick" {return BUTMINIMIZECLICK}
			if s == "butclaimclick" {return BUTCLAIMCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTREGULARIZECLICK {return "ButRegularizeClick"}
			if ix == BUTMINIMIZECLICK {return "ButMinimizeClick"}
			if ix == BUTCLAIMCLICK {return "ButClaimClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskLlvLaser)
	  */
	public class ContIac: Block {

		public static let CHKERG: Int = 1
		public static let SLDLLE: Int = 2
		public static let SLDLRI: Int = 3

		public init(
					_ ChkErg: Bool = false
					, _ SldLle: Double = 0.0
					, _ SldLri: Double = 0.0
				) {
			self.ChkErg = ChkErg
			self.SldLle = SldLle
			self.SldLri = SldLri

			super.init()

			mask = [ContIac.CHKERG, ContIac.SLDLLE, ContIac.SLDLRI]
		}

		public var ChkErg: Bool
		public var SldLle: Double
		public var SldLri: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskLlvLaser")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskLlvLaser"

			if valid {
				ChkErg = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ChkErg", &mask, ContIac.CHKERG)
				SldLle = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldLle", &mask, ContIac.SLDLLE)
				SldLri = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldLri", &mask, ContIac.SLDLRI)
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
			if tag == nil {tag = "ContIacWzskLlvLaser"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskLlvLaser"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeBoolAttr(doc, el, itemtag, "sref", "ChkErg", ChkErg)
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldLle", SldLle)
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldLri", SldLri)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if ChkErg == comp.ChkErg {items.insert(ContIac.CHKERG)}
			if Xmlio.compareDouble(SldLle, comp.SldLle) < 1.0e-4 {items.insert(ContIac.SLDLLE)}
			if Xmlio.compareDouble(SldLri, comp.SldLri) < 1.0e-4 {items.insert(ContIac.SLDLRI)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.CHKERG, ContIac.SLDLLE, ContIac.SLDLRI]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskLlvLaser)
	  */
	public class ContInf: Block {

		public static let BUTCLAIMON: Int = 1

		public init(
					_ ButClaimOn: Bool = false
				) {
			self.ButClaimOn = ButClaimOn

			super.init()

			mask = [ContInf.BUTCLAIMON]
		}

		public var ButClaimOn: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskLlvLaser")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskLlvLaser"

			if valid {
				ButClaimOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimOn", &mask, ContInf.BUTCLAIMON)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButClaimOn == comp.ButClaimOn {items.insert(ContInf.BUTCLAIMON)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.BUTCLAIMON]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskLlvLaser)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let BUTCLAIMACTIVE: Int = 2
		public static let SLDLLEACTIVE: Int = 3
		public static let SLDLLEMIN: Int = 4
		public static let SLDLLEMAX: Int = 5
		public static let SLDLRIACTIVE: Int = 6
		public static let SLDLRIMIN: Int = 7
		public static let SLDLRIMAX: Int = 8

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ ButClaimActive: Bool = false
					, _ SldLleActive: Bool = false
					, _ SldLleMin: Double = 0.0
					, _ SldLleMax: Double = 0.0
					, _ SldLriActive: Bool = false
					, _ SldLriMin: Double = 0.0
					, _ SldLriMax: Double = 0.0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.ButClaimActive = ButClaimActive
			self.SldLleActive = SldLleActive
			self.SldLleMin = SldLleMin
			self.SldLleMax = SldLleMax
			self.SldLriActive = SldLriActive
			self.SldLriMin = SldLriMin
			self.SldLriMax = SldLriMax

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.SLDLLEACTIVE, StatShr.SLDLLEMIN, StatShr.SLDLLEMAX, StatShr.SLDLRIACTIVE, StatShr.SLDLRIMIN, StatShr.SLDLRIMAX]
		}

		public var ixWzskVExpstate: Int
		public var ButClaimActive: Bool
		public var SldLleActive: Bool
		public var SldLleMin: Double
		public var SldLleMax: Double
		public var SldLriActive: Bool
		public var SldLriMin: Double
		public var SldLriMax: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskLlvLaser")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskLlvLaser"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				ButClaimActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimActive", &mask, StatShr.BUTCLAIMACTIVE)
				SldLleActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldLleActive", &mask, StatShr.SLDLLEACTIVE)
				SldLleMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldLleMin", &mask, StatShr.SLDLLEMIN)
				SldLleMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldLleMax", &mask, StatShr.SLDLLEMAX)
				SldLriActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldLriActive", &mask, StatShr.SLDLRIACTIVE)
				SldLriMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldLriMin", &mask, StatShr.SLDLRIMIN)
				SldLriMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldLriMax", &mask, StatShr.SLDLRIMAX)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}
			if ButClaimActive == comp.ButClaimActive {items.insert(StatShr.BUTCLAIMACTIVE)}
			if SldLleActive == comp.SldLleActive {items.insert(StatShr.SLDLLEACTIVE)}
			if Xmlio.compareDouble(SldLleMin, comp.SldLleMin) < 1.0e-4 {items.insert(StatShr.SLDLLEMIN)}
			if Xmlio.compareDouble(SldLleMax, comp.SldLleMax) < 1.0e-4 {items.insert(StatShr.SLDLLEMAX)}
			if SldLriActive == comp.SldLriActive {items.insert(StatShr.SLDLRIACTIVE)}
			if Xmlio.compareDouble(SldLriMin, comp.SldLriMin) < 1.0e-4 {items.insert(StatShr.SLDLRIMIN)}
			if Xmlio.compareDouble(SldLriMax, comp.SldLriMax) < 1.0e-4 {items.insert(StatShr.SLDLRIMAX)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.SLDLLEACTIVE, StatShr.SLDLLEMIN, StatShr.SLDLLEMAX, StatShr.SLDLRIACTIVE, StatShr.SLDLRIMIN, StatShr.SLDLRIMAX]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskLlvLaser)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTERG: Int = 2
		public static let CPTLLE: Int = 3
		public static let CPTLRI: Int = 4

		public init(
					_ Cpt: String = ""
					, _ CptErg: String = ""
					, _ CptLle: String = ""
					, _ CptLri: String = ""
				) {
			self.Cpt = Cpt
			self.CptErg = CptErg
			self.CptLle = CptLle
			self.CptLri = CptLri

			super.init()

			mask = [Tag.CPT, Tag.CPTERG, Tag.CPTLLE, Tag.CPTLRI]
		}

		public var Cpt: String
		public var CptErg: String
		public var CptLle: String
		public var CptLri: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskLlvLaser")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskLlvLaser"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptErg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptErg", &mask, Tag.CPTERG)
				CptLle = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLle", &mask, Tag.CPTLLE)
				CptLri = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLri", &mask, Tag.CPTLRI)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptErg == comp.CptErg {items.insert(Tag.CPTERG)}
			if CptLle == comp.CptLle {items.insert(Tag.CPTLLE)}
			if CptLri == comp.CptLri {items.insert(Tag.CPTLRI)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTERG, Tag.CPTLLE, Tag.CPTLRI]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskLlvLaserData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVLASERDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvLaserData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskLlvLaserDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVLASERDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvLaserDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskLlvLaserData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let STATSHR: Int = 4
		public static let TAG: Int = 5

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLLVLASERDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLlvLaserData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
