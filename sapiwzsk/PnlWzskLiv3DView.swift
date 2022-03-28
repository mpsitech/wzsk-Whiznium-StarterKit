/**
  * \file PnlWzskLiv3DView.swift
  * Swift API code for job PnlWzskLiv3DView
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskLiv3DView
	*/
public class PnlWzskLiv3DView {
	/**
		* VecVDo (full: VecVWzskLiv3DViewDo)
		*/
	public class VecVDo {

		public static let BUTREGULARIZECLICK: Int = 1
		public static let BUTMINIMIZECLICK: Int = 2
		public static let BUTCLAIMCLICK: Int = 3
		public static let BUTASRCLICK: Int = 4
		public static let BUTAIRCLICK: Int = 5

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butregularizeclick" {return BUTREGULARIZECLICK}
			if s == "butminimizeclick" {return BUTMINIMIZECLICK}
			if s == "butclaimclick" {return BUTCLAIMCLICK}
			if s == "butasrclick" {return BUTASRCLICK}
			if s == "butairclick" {return BUTAIRCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTREGULARIZECLICK {return "ButRegularizeClick"}
			if ix == BUTMINIMIZECLICK {return "ButMinimizeClick"}
			if ix == BUTCLAIMCLICK {return "ButClaimClick"}
			if ix == BUTASRCLICK {return "ButAsrClick"}
			if ix == BUTAIRCLICK {return "ButAirClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskLiv3DView)
	  */
	public class ContIac: Block {

		public static let SLDAIN: Int = 1

		public init(
					_ SldAin: Double = 0.0
				) {
			self.SldAin = SldAin

			super.init()

			mask = [ContIac.SLDAIN]
		}

		public var SldAin: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskLiv3DView")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskLiv3DView"

			if valid {
				SldAin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldAin", &mask, ContIac.SLDAIN)
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
			if tag == nil {tag = "ContIacWzskLiv3DView"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskLiv3DView"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldAin", SldAin)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if Xmlio.compareDouble(SldAin, comp.SldAin) < 1.0e-4 {items.insert(ContIac.SLDAIN)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.SLDAIN]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskLiv3DView)
	  */
	public class ContInf: Block {

		public static let BUTCLAIMON: Int = 1
		public static let TXTAST: Int = 2
		public static let TXTAOA: Int = 3

		public init(
					_ ButClaimOn: Bool = false
					, _ TxtAst: String = ""
					, _ TxtAoa: String = ""
				) {
			self.ButClaimOn = ButClaimOn
			self.TxtAst = TxtAst
			self.TxtAoa = TxtAoa

			super.init()

			mask = [ContInf.BUTCLAIMON, ContInf.TXTAST, ContInf.TXTAOA]
		}

		public var ButClaimOn: Bool
		public var TxtAst: String
		public var TxtAoa: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskLiv3DView")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskLiv3DView"

			if valid {
				ButClaimOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimOn", &mask, ContInf.BUTCLAIMON)
				TxtAst = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtAst", &mask, ContInf.TXTAST)
				TxtAoa = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtAoa", &mask, ContInf.TXTAOA)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButClaimOn == comp.ButClaimOn {items.insert(ContInf.BUTCLAIMON)}
			if TxtAst == comp.TxtAst {items.insert(ContInf.TXTAST)}
			if TxtAoa == comp.TxtAoa {items.insert(ContInf.TXTAOA)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.BUTCLAIMON, ContInf.TXTAST, ContInf.TXTAOA]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskLiv3DView)
	  */
	public class StatApp: Block {

		public static let BUTPLAYACTIVE: Int = 1
		public static let BUTSTOPACTIVE: Int = 2

		public init(
					_ ButPlayActive: Bool = false
					, _ ButStopActive: Bool = false
				) {
			self.ButPlayActive = ButPlayActive
			self.ButStopActive = ButStopActive

			super.init()

			mask = [StatApp.BUTPLAYACTIVE, StatApp.BUTSTOPACTIVE]
		}

		public var ButPlayActive: Bool
		public var ButStopActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskLiv3DView")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskLiv3DView"

			if valid {
				ButPlayActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButPlayActive", &mask, StatApp.BUTPLAYACTIVE)
				ButStopActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButStopActive", &mask, StatApp.BUTSTOPACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButPlayActive == comp.ButPlayActive {items.insert(StatApp.BUTPLAYACTIVE)}
			if ButStopActive == comp.ButStopActive {items.insert(StatApp.BUTSTOPACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.BUTPLAYACTIVE, StatApp.BUTSTOPACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskLiv3DView)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let BUTCLAIMACTIVE: Int = 2
		public static let SLDTREHMIN: Int = 3
		public static let SLDTREHMAX: Int = 4
		public static let SLDTREVMIN: Int = 5
		public static let SLDTREVMAX: Int = 6
		public static let SLDAINACTIVE: Int = 7
		public static let SLDAINMIN: Int = 8
		public static let SLDAINMAX: Int = 9
		public static let SLDAINRAST: Int = 10
		public static let TXTAOAAVAIL: Int = 11
		public static let BUTASRACTIVE: Int = 12
		public static let BUTAIRACTIVE: Int = 13

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ ButClaimActive: Bool = false
					, _ SldTreHMin: Double = 0.0
					, _ SldTreHMax: Double = 0.0
					, _ SldTreVMin: Double = 0.0
					, _ SldTreVMax: Double = 0.0
					, _ SldAinActive: Bool = false
					, _ SldAinMin: Double = 0.0
					, _ SldAinMax: Double = 0.0
					, _ SldAinRast: Double = 0.0
					, _ TxtAoaAvail: Bool = false
					, _ ButAsrActive: Bool = false
					, _ ButAirActive: Bool = false
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.ButClaimActive = ButClaimActive
			self.SldTreHMin = SldTreHMin
			self.SldTreHMax = SldTreHMax
			self.SldTreVMin = SldTreVMin
			self.SldTreVMax = SldTreVMax
			self.SldAinActive = SldAinActive
			self.SldAinMin = SldAinMin
			self.SldAinMax = SldAinMax
			self.SldAinRast = SldAinRast
			self.TxtAoaAvail = TxtAoaAvail
			self.ButAsrActive = ButAsrActive
			self.ButAirActive = ButAirActive

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.SLDTREHMIN, StatShr.SLDTREHMAX, StatShr.SLDTREVMIN, StatShr.SLDTREVMAX, StatShr.SLDAINACTIVE, StatShr.SLDAINMIN, StatShr.SLDAINMAX, StatShr.SLDAINRAST, StatShr.TXTAOAAVAIL, StatShr.BUTASRACTIVE, StatShr.BUTAIRACTIVE]
		}

		public var ixWzskVExpstate: Int
		public var ButClaimActive: Bool
		public var SldTreHMin: Double
		public var SldTreHMax: Double
		public var SldTreVMin: Double
		public var SldTreVMax: Double
		public var SldAinActive: Bool
		public var SldAinMin: Double
		public var SldAinMax: Double
		public var SldAinRast: Double
		public var TxtAoaAvail: Bool
		public var ButAsrActive: Bool
		public var ButAirActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskLiv3DView")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskLiv3DView"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				ButClaimActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimActive", &mask, StatShr.BUTCLAIMACTIVE)
				SldTreHMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldTreHMin", &mask, StatShr.SLDTREHMIN)
				SldTreHMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldTreHMax", &mask, StatShr.SLDTREHMAX)
				SldTreVMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldTreVMin", &mask, StatShr.SLDTREVMIN)
				SldTreVMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldTreVMax", &mask, StatShr.SLDTREVMAX)
				SldAinActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldAinActive", &mask, StatShr.SLDAINACTIVE)
				SldAinMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldAinMin", &mask, StatShr.SLDAINMIN)
				SldAinMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldAinMax", &mask, StatShr.SLDAINMAX)
				SldAinRast = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldAinRast", &mask, StatShr.SLDAINRAST)
				TxtAoaAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtAoaAvail", &mask, StatShr.TXTAOAAVAIL)
				ButAsrActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButAsrActive", &mask, StatShr.BUTASRACTIVE)
				ButAirActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButAirActive", &mask, StatShr.BUTAIRACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}
			if ButClaimActive == comp.ButClaimActive {items.insert(StatShr.BUTCLAIMACTIVE)}
			if Xmlio.compareDouble(SldTreHMin, comp.SldTreHMin) < 1.0e-4 {items.insert(StatShr.SLDTREHMIN)}
			if Xmlio.compareDouble(SldTreHMax, comp.SldTreHMax) < 1.0e-4 {items.insert(StatShr.SLDTREHMAX)}
			if Xmlio.compareDouble(SldTreVMin, comp.SldTreVMin) < 1.0e-4 {items.insert(StatShr.SLDTREVMIN)}
			if Xmlio.compareDouble(SldTreVMax, comp.SldTreVMax) < 1.0e-4 {items.insert(StatShr.SLDTREVMAX)}
			if SldAinActive == comp.SldAinActive {items.insert(StatShr.SLDAINACTIVE)}
			if Xmlio.compareDouble(SldAinMin, comp.SldAinMin) < 1.0e-4 {items.insert(StatShr.SLDAINMIN)}
			if Xmlio.compareDouble(SldAinMax, comp.SldAinMax) < 1.0e-4 {items.insert(StatShr.SLDAINMAX)}
			if Xmlio.compareDouble(SldAinRast, comp.SldAinRast) < 1.0e-4 {items.insert(StatShr.SLDAINRAST)}
			if TxtAoaAvail == comp.TxtAoaAvail {items.insert(StatShr.TXTAOAAVAIL)}
			if ButAsrActive == comp.ButAsrActive {items.insert(StatShr.BUTASRACTIVE)}
			if ButAirActive == comp.ButAirActive {items.insert(StatShr.BUTAIRACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.SLDTREHMIN, StatShr.SLDTREHMAX, StatShr.SLDTREVMIN, StatShr.SLDTREVMAX, StatShr.SLDAINACTIVE, StatShr.SLDAINMIN, StatShr.SLDAINMAX, StatShr.SLDAINRAST, StatShr.TXTAOAAVAIL, StatShr.BUTASRACTIVE, StatShr.BUTAIRACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskLiv3DView)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let HDGACQ: Int = 2
		public static let CPTAIN: Int = 3
		public static let CPTAST: Int = 4
		public static let CPTAOA: Int = 5
		public static let BUTASR: Int = 6
		public static let BUTAIR: Int = 7

		public init(
					_ Cpt: String = ""
					, _ HdgAcq: String = ""
					, _ CptAin: String = ""
					, _ CptAst: String = ""
					, _ CptAoa: String = ""
					, _ ButAsr: String = ""
					, _ ButAir: String = ""
				) {
			self.Cpt = Cpt
			self.HdgAcq = HdgAcq
			self.CptAin = CptAin
			self.CptAst = CptAst
			self.CptAoa = CptAoa
			self.ButAsr = ButAsr
			self.ButAir = ButAir

			super.init()

			mask = [Tag.CPT, Tag.HDGACQ, Tag.CPTAIN, Tag.CPTAST, Tag.CPTAOA, Tag.BUTASR, Tag.BUTAIR]
		}

		public var Cpt: String
		public var HdgAcq: String
		public var CptAin: String
		public var CptAst: String
		public var CptAoa: String
		public var ButAsr: String
		public var ButAir: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskLiv3DView")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskLiv3DView"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				HdgAcq = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "HdgAcq", &mask, Tag.HDGACQ)
				CptAin = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptAin", &mask, Tag.CPTAIN)
				CptAst = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptAst", &mask, Tag.CPTAST)
				CptAoa = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptAoa", &mask, Tag.CPTAOA)
				ButAsr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButAsr", &mask, Tag.BUTASR)
				ButAir = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButAir", &mask, Tag.BUTAIR)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if HdgAcq == comp.HdgAcq {items.insert(Tag.HDGACQ)}
			if CptAin == comp.CptAin {items.insert(Tag.CPTAIN)}
			if CptAst == comp.CptAst {items.insert(Tag.CPTAST)}
			if CptAoa == comp.CptAoa {items.insert(Tag.CPTAOA)}
			if ButAsr == comp.ButAsr {items.insert(Tag.BUTASR)}
			if ButAir == comp.ButAir {items.insert(Tag.BUTAIR)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.HDGACQ, Tag.CPTAIN, Tag.CPTAST, Tag.CPTAOA, Tag.BUTASR, Tag.BUTAIR]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskLiv3DViewData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLIV3DVIEWDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLiv3DViewData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskLiv3DViewDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLIV3DVIEWDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLiv3DViewDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskLiv3DViewData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLIV3DVIEWDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLiv3DViewData")}
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

	/**
		* DpchEngLive (full: DpchEngWzskLiv3DViewLive)
		*/
	public class DpchEngLive: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let RNOTL: Int = 2
		public static let X: Int = 3
		public static let Y: Int = 4
		public static let Z: Int = 5

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLIV3DVIEWLIVE)
		}

		public var rNotL: [Bool] = [Bool]()
		public var x: [Float] = [Float]()
		public var y: [Float] = [Float]()
		public var z: [Float] = [Float]()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngLive.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngLive.RNOTL) {ss.append("rNotL")}
			if has(DpchEngLive.X) {ss.append("x")}
			if has(DpchEngLive.Y) {ss.append("y")}
			if has(DpchEngLive.Z) {ss.append("z")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLiv3DViewLive")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngLive.SCRJREF)
				rNotL = Xmlio.extractBoolvecUclc(doc, basexpath!, "rNotL", "", &mask, DpchEngLive.RNOTL)
				x = Xmlio.extractFloatvecUclc(doc, basexpath!, "x", "", &mask, DpchEngLive.X)
				y = Xmlio.extractFloatvecUclc(doc, basexpath!, "y", "", &mask, DpchEngLive.Y)
				z = Xmlio.extractFloatvecUclc(doc, basexpath!, "z", "", &mask, DpchEngLive.Z)
			} else {
				scrJref = ""
				rNotL = [Bool]()
				x = [Float]()
				y = [Float]()
				z = [Float]()
			}
		}

	}

}
