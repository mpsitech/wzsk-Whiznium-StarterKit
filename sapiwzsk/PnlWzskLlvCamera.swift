/**
  * \file PnlWzskLlvCamera.swift
  * Swift API code for job PnlWzskLlvCamera
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskLlvCamera
	*/
public class PnlWzskLlvCamera {
	/**
		* VecVDo (full: VecVWzskLlvCameraDo)
		*/
	public class VecVDo {

		public static let BUTREGULARIZECLICK: Int = 1
		public static let BUTMINIMIZECLICK: Int = 2
		public static let BUTCLAIMCLICK: Int = 3
		public static let BUTPLAYCLICK: Int = 4
		public static let BUTSTOPCLICK: Int = 5

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butregularizeclick" {return BUTREGULARIZECLICK}
			if s == "butminimizeclick" {return BUTMINIMIZECLICK}
			if s == "butclaimclick" {return BUTCLAIMCLICK}
			if s == "butplayclick" {return BUTPLAYCLICK}
			if s == "butstopclick" {return BUTSTOPCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTREGULARIZECLICK {return "ButRegularizeClick"}
			if ix == BUTMINIMIZECLICK {return "ButMinimizeClick"}
			if ix == BUTCLAIMCLICK {return "ButClaimClick"}
			if ix == BUTPLAYCLICK {return "ButPlayClick"}
			if ix == BUTSTOPCLICK {return "ButStopClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskLlvCamera)
	  */
	public class ContIac: Block {

		public static let NUMFPUPMDE: Int = 1
		public static let CHKAEX: Int = 2
		public static let SLDEXT: Int = 3
		public static let SLDFCS: Int = 4

		public init(
					_ numFPupMde: Int = 0
					, _ ChkAex: Bool = false
					, _ SldExt: Double = 0.0
					, _ SldFcs: Double = 0.0
				) {
			self.numFPupMde = numFPupMde
			self.ChkAex = ChkAex
			self.SldExt = SldExt
			self.SldFcs = SldFcs

			super.init()

			mask = [ContIac.NUMFPUPMDE, ContIac.CHKAEX, ContIac.SLDEXT, ContIac.SLDFCS]
		}

		public var numFPupMde: Int
		public var ChkAex: Bool
		public var SldExt: Double
		public var SldFcs: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskLlvCamera")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskLlvCamera"

			if valid {
				numFPupMde = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupMde", &mask, ContIac.NUMFPUPMDE)
				ChkAex = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ChkAex", &mask, ContIac.CHKAEX)
				SldExt = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExt", &mask, ContIac.SLDEXT)
				SldFcs = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldFcs", &mask, ContIac.SLDFCS)
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
			if tag == nil {tag = "ContIacWzskLlvCamera"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskLlvCamera"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupMde", numFPupMde)
			Xmlio.writeBoolAttr(doc, el, itemtag, "sref", "ChkAex", ChkAex)
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldExt", SldExt)
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFcs", SldFcs)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFPupMde == comp.numFPupMde {items.insert(ContIac.NUMFPUPMDE)}
			if ChkAex == comp.ChkAex {items.insert(ContIac.CHKAEX)}
			if Xmlio.compareDouble(SldExt, comp.SldExt) < 1.0e-4 {items.insert(ContIac.SLDEXT)}
			if Xmlio.compareDouble(SldFcs, comp.SldFcs) < 1.0e-4 {items.insert(ContIac.SLDFCS)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFPUPMDE, ContIac.CHKAEX, ContIac.SLDEXT, ContIac.SLDFCS]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskLlvCamera)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskLlvCamera")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskLlvCamera"

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
	  * StatShr (full: StatShrWzskLlvCamera)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let BUTCLAIMACTIVE: Int = 2
		public static let BUTPLAYACTIVE: Int = 3
		public static let BUTSTOPACTIVE: Int = 4
		public static let CHKAEXACTIVE: Int = 5
		public static let SLDEXTAVAIL: Int = 6
		public static let SLDEXTACTIVE: Int = 7
		public static let SLDEXTMIN: Int = 8
		public static let SLDEXTMAX: Int = 9
		public static let SLDEXTRAST: Int = 10
		public static let SLDFCSACTIVE: Int = 11
		public static let SLDFCSMIN: Int = 12
		public static let SLDFCSMAX: Int = 13

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ ButClaimActive: Bool = false
					, _ ButPlayActive: Bool = false
					, _ ButStopActive: Bool = false
					, _ ChkAexActive: Bool = false
					, _ SldExtAvail: Bool = false
					, _ SldExtActive: Bool = false
					, _ SldExtMin: Double = 0.0
					, _ SldExtMax: Double = 0.0
					, _ SldExtRast: Double = 0.0
					, _ SldFcsActive: Bool = false
					, _ SldFcsMin: Double = 0.0
					, _ SldFcsMax: Double = 0.0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.ButClaimActive = ButClaimActive
			self.ButPlayActive = ButPlayActive
			self.ButStopActive = ButStopActive
			self.ChkAexActive = ChkAexActive
			self.SldExtAvail = SldExtAvail
			self.SldExtActive = SldExtActive
			self.SldExtMin = SldExtMin
			self.SldExtMax = SldExtMax
			self.SldExtRast = SldExtRast
			self.SldFcsActive = SldFcsActive
			self.SldFcsMin = SldFcsMin
			self.SldFcsMax = SldFcsMax

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.BUTPLAYACTIVE, StatShr.BUTSTOPACTIVE, StatShr.CHKAEXACTIVE, StatShr.SLDEXTAVAIL, StatShr.SLDEXTACTIVE, StatShr.SLDEXTMIN, StatShr.SLDEXTMAX, StatShr.SLDEXTRAST, StatShr.SLDFCSACTIVE, StatShr.SLDFCSMIN, StatShr.SLDFCSMAX]
		}

		public var ixWzskVExpstate: Int
		public var ButClaimActive: Bool
		public var ButPlayActive: Bool
		public var ButStopActive: Bool
		public var ChkAexActive: Bool
		public var SldExtAvail: Bool
		public var SldExtActive: Bool
		public var SldExtMin: Double
		public var SldExtMax: Double
		public var SldExtRast: Double
		public var SldFcsActive: Bool
		public var SldFcsMin: Double
		public var SldFcsMax: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskLlvCamera")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskLlvCamera"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				ButClaimActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimActive", &mask, StatShr.BUTCLAIMACTIVE)
				ButPlayActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButPlayActive", &mask, StatShr.BUTPLAYACTIVE)
				ButStopActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButStopActive", &mask, StatShr.BUTSTOPACTIVE)
				ChkAexActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ChkAexActive", &mask, StatShr.CHKAEXACTIVE)
				SldExtAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtAvail", &mask, StatShr.SLDEXTAVAIL)
				SldExtActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtActive", &mask, StatShr.SLDEXTACTIVE)
				SldExtMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtMin", &mask, StatShr.SLDEXTMIN)
				SldExtMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtMax", &mask, StatShr.SLDEXTMAX)
				SldExtRast = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtRast", &mask, StatShr.SLDEXTRAST)
				SldFcsActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldFcsActive", &mask, StatShr.SLDFCSACTIVE)
				SldFcsMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldFcsMin", &mask, StatShr.SLDFCSMIN)
				SldFcsMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldFcsMax", &mask, StatShr.SLDFCSMAX)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}
			if ButClaimActive == comp.ButClaimActive {items.insert(StatShr.BUTCLAIMACTIVE)}
			if ButPlayActive == comp.ButPlayActive {items.insert(StatShr.BUTPLAYACTIVE)}
			if ButStopActive == comp.ButStopActive {items.insert(StatShr.BUTSTOPACTIVE)}
			if ChkAexActive == comp.ChkAexActive {items.insert(StatShr.CHKAEXACTIVE)}
			if SldExtAvail == comp.SldExtAvail {items.insert(StatShr.SLDEXTAVAIL)}
			if SldExtActive == comp.SldExtActive {items.insert(StatShr.SLDEXTACTIVE)}
			if Xmlio.compareDouble(SldExtMin, comp.SldExtMin) < 1.0e-4 {items.insert(StatShr.SLDEXTMIN)}
			if Xmlio.compareDouble(SldExtMax, comp.SldExtMax) < 1.0e-4 {items.insert(StatShr.SLDEXTMAX)}
			if Xmlio.compareDouble(SldExtRast, comp.SldExtRast) < 1.0e-4 {items.insert(StatShr.SLDEXTRAST)}
			if SldFcsActive == comp.SldFcsActive {items.insert(StatShr.SLDFCSACTIVE)}
			if Xmlio.compareDouble(SldFcsMin, comp.SldFcsMin) < 1.0e-4 {items.insert(StatShr.SLDFCSMIN)}
			if Xmlio.compareDouble(SldFcsMax, comp.SldFcsMax) < 1.0e-4 {items.insert(StatShr.SLDFCSMAX)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.BUTPLAYACTIVE, StatShr.BUTSTOPACTIVE, StatShr.CHKAEXACTIVE, StatShr.SLDEXTAVAIL, StatShr.SLDEXTACTIVE, StatShr.SLDEXTMIN, StatShr.SLDEXTMAX, StatShr.SLDEXTRAST, StatShr.SLDFCSACTIVE, StatShr.SLDFCSMIN, StatShr.SLDFCSMAX]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskLlvCamera)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTMDE: Int = 2
		public static let CPTAEX: Int = 3
		public static let CPTEXT: Int = 4
		public static let CPTFCS: Int = 5

		public init(
					_ Cpt: String = ""
					, _ CptMde: String = ""
					, _ CptAex: String = ""
					, _ CptExt: String = ""
					, _ CptFcs: String = ""
				) {
			self.Cpt = Cpt
			self.CptMde = CptMde
			self.CptAex = CptAex
			self.CptExt = CptExt
			self.CptFcs = CptFcs

			super.init()

			mask = [Tag.CPT, Tag.CPTMDE, Tag.CPTAEX, Tag.CPTEXT, Tag.CPTFCS]
		}

		public var Cpt: String
		public var CptMde: String
		public var CptAex: String
		public var CptExt: String
		public var CptFcs: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskLlvCamera")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskLlvCamera"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptMde = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptMde", &mask, Tag.CPTMDE)
				CptAex = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptAex", &mask, Tag.CPTAEX)
				CptExt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptExt", &mask, Tag.CPTEXT)
				CptFcs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptFcs", &mask, Tag.CPTFCS)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptMde == comp.CptMde {items.insert(Tag.CPTMDE)}
			if CptAex == comp.CptAex {items.insert(Tag.CPTAEX)}
			if CptExt == comp.CptExt {items.insert(Tag.CPTEXT)}
			if CptFcs == comp.CptFcs {items.insert(Tag.CPTFCS)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTMDE, Tag.CPTAEX, Tag.CPTEXT, Tag.CPTFCS]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskLlvCameraData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVCAMERADATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvCameraData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskLlvCameraDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVCAMERADO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvCameraDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskLlvCameraData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFPUPMDE: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLLVCAMERADATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFPupMde: Feed = Feed("FeedFPupMde")
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFPUPMDE) {ss.append("feedFPupMde")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLlvCameraData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFPupMde.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPMDE)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFPupMde = Feed("FeedFPupMde")
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

	/**
		* DpchEngLive (full: DpchEngWzskLlvCameraLive)
		*/
	public class DpchEngLive: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let GRAY: Int = 2
		public static let RED: Int = 3
		public static let GREEN: Int = 4
		public static let BLUE: Int = 5

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLLVCAMERALIVE)
		}

		public var gray: [UInt8] = [UInt8]()

		public var red: [UInt8] = [UInt8]()
		public var green: [UInt8] = [UInt8]()
		public var blue: [UInt8] = [UInt8]()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngLive.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngLive.GRAY) {ss.append("gray")}
			if has(DpchEngLive.RED) {ss.append("red")}
			if has(DpchEngLive.GREEN) {ss.append("green")}
			if has(DpchEngLive.BLUE) {ss.append("blue")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLlvCameraLive")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngLive.SCRJREF)
				gray = Xmlio.extractUtinyintvecUclc(doc, basexpath!, "gray", "", &mask, DpchEngLive.GRAY)
				red = Xmlio.extractUtinyintvecUclc(doc, basexpath!, "red", "", &mask, DpchEngLive.RED)
				green = Xmlio.extractUtinyintvecUclc(doc, basexpath!, "green", "", &mask, DpchEngLive.GREEN)
				blue = Xmlio.extractUtinyintvecUclc(doc, basexpath!, "blue", "", &mask, DpchEngLive.BLUE)
			} else {
				scrJref = ""
				gray = [UInt8]()
				red = [UInt8]()
				green = [UInt8]()
				blue = [UInt8]()
			}
		}

	}

}
