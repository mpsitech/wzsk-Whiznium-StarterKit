/**
  * \file PnlWzskLlvTtable.swift
  * Swift API code for job PnlWzskLlvTtable
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskLlvTtable
	*/
public class PnlWzskLlvTtable {
	/**
		* VecVDo (full: VecVWzskLlvTtableDo)
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
	  * ContIac (full: ContIacWzskLlvTtable)
	  */
	public class ContIac: Block {

		public static let SLDTRG: Int = 1

		public init(
					_ SldTrg: Double = 0.0
				) {
			self.SldTrg = SldTrg

			super.init()

			mask = [ContIac.SLDTRG]
		}

		public var SldTrg: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskLlvTtable")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskLlvTtable"

			if valid {
				SldTrg = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldTrg", &mask, ContIac.SLDTRG)
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
			if tag == nil {tag = "ContIacWzskLlvTtable"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskLlvTtable"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldTrg", SldTrg)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if Xmlio.compareDouble(SldTrg, comp.SldTrg) < 1.0e-4 {items.insert(ContIac.SLDTRG)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.SLDTRG]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskLlvTtable)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskLlvTtable")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskLlvTtable"

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
	  * StatShr (full: StatShrWzskLlvTtable)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let BUTCLAIMACTIVE: Int = 2
		public static let SLDTRGACTIVE: Int = 3
		public static let SLDTRGMIN: Int = 4
		public static let SLDTRGMAX: Int = 5

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ ButClaimActive: Bool = false
					, _ SldTrgActive: Bool = false
					, _ SldTrgMin: Double = 0.0
					, _ SldTrgMax: Double = 0.0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.ButClaimActive = ButClaimActive
			self.SldTrgActive = SldTrgActive
			self.SldTrgMin = SldTrgMin
			self.SldTrgMax = SldTrgMax

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.SLDTRGACTIVE, StatShr.SLDTRGMIN, StatShr.SLDTRGMAX]
		}

		public var ixWzskVExpstate: Int
		public var ButClaimActive: Bool
		public var SldTrgActive: Bool
		public var SldTrgMin: Double
		public var SldTrgMax: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskLlvTtable")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskLlvTtable"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				ButClaimActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimActive", &mask, StatShr.BUTCLAIMACTIVE)
				SldTrgActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldTrgActive", &mask, StatShr.SLDTRGACTIVE)
				SldTrgMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldTrgMin", &mask, StatShr.SLDTRGMIN)
				SldTrgMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldTrgMax", &mask, StatShr.SLDTRGMAX)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}
			if ButClaimActive == comp.ButClaimActive {items.insert(StatShr.BUTCLAIMACTIVE)}
			if SldTrgActive == comp.SldTrgActive {items.insert(StatShr.SLDTRGACTIVE)}
			if Xmlio.compareDouble(SldTrgMin, comp.SldTrgMin) < 1.0e-4 {items.insert(StatShr.SLDTRGMIN)}
			if Xmlio.compareDouble(SldTrgMax, comp.SldTrgMax) < 1.0e-4 {items.insert(StatShr.SLDTRGMAX)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.SLDTRGACTIVE, StatShr.SLDTRGMIN, StatShr.SLDTRGMAX]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskLlvTtable)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTTRG: Int = 2

		public init(
					_ Cpt: String = ""
					, _ CptTrg: String = ""
				) {
			self.Cpt = Cpt
			self.CptTrg = CptTrg

			super.init()

			mask = [Tag.CPT, Tag.CPTTRG]
		}

		public var Cpt: String
		public var CptTrg: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskLlvTtable")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskLlvTtable"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptTrg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptTrg", &mask, Tag.CPTTRG)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptTrg == comp.CptTrg {items.insert(Tag.CPTTRG)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTTRG]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskLlvTtableData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVTTABLEDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvTtableData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskLlvTtableDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVTTABLEDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvTtableDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskLlvTtableData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let STATSHR: Int = 4
		public static let TAG: Int = 5

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLLVTTABLEDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLlvTtableData")}
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
