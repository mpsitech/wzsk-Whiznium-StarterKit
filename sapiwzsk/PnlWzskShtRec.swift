/**
  * \file PnlWzskShtRec.swift
  * Swift API code for job PnlWzskShtRec
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskShtRec
	*/
public class PnlWzskShtRec {
	/**
		* VecVDo (full: VecVWzskShtRecDo)
		*/
	public class VecVDo {

		public static let BUTMINIMIZECLICK: Int = 1
		public static let BUTREGULARIZECLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butminimizeclick" {return BUTMINIMIZECLICK}
			if s == "butregularizeclick" {return BUTREGULARIZECLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTMINIMIZECLICK {return "ButMinimizeClick"}
			if ix == BUTREGULARIZECLICK {return "ButRegularizeClick"}

			return ""
		}

	}

	/**
	  * ContInf (full: ContInfWzskShtRec)
	  */
	public class ContInf: Block {

		public static let TXTREF: Int = 1

		public init(
					_ TxtRef: String = ""
				) {
			self.TxtRef = TxtRef

			super.init()

			mask = [ContInf.TXTREF]
		}

		public var TxtRef: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskShtRec")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskShtRec"

			if valid {
				TxtRef = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtRef", &mask, ContInf.TXTREF)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtRef == comp.TxtRef {items.insert(ContInf.TXTREF)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTREF]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskShtRec)
	  */
	public class StatApp: Block {

		public static let INITDONEDETAIL: Int = 1
		public static let INITDONEAPAR: Int = 2
		public static let INITDONEREF1NFILE: Int = 3

		public init(
					_ initdoneDetail: Bool = false
					, _ initdoneAPar: Bool = false
					, _ initdoneRef1NFile: Bool = false
				) {
			self.initdoneDetail = initdoneDetail
			self.initdoneAPar = initdoneAPar
			self.initdoneRef1NFile = initdoneRef1NFile

			super.init()

			mask = [StatApp.INITDONEDETAIL, StatApp.INITDONEAPAR, StatApp.INITDONEREF1NFILE]
		}

		public var initdoneDetail: Bool
		public var initdoneAPar: Bool
		public var initdoneRef1NFile: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskShtRec")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskShtRec"

			if valid {
				initdoneDetail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneDetail", &mask, StatApp.INITDONEDETAIL)
				initdoneAPar = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneAPar", &mask, StatApp.INITDONEAPAR)
				initdoneRef1NFile = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneRef1NFile", &mask, StatApp.INITDONEREF1NFILE)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if initdoneDetail == comp.initdoneDetail {items.insert(StatApp.INITDONEDETAIL)}
			if initdoneAPar == comp.initdoneAPar {items.insert(StatApp.INITDONEAPAR)}
			if initdoneRef1NFile == comp.initdoneRef1NFile {items.insert(StatApp.INITDONEREF1NFILE)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.INITDONEDETAIL, StatApp.INITDONEAPAR, StatApp.INITDONEREF1NFILE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskShtRec)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let SCRJREFDETAIL: Int = 2
		public static let SCRJREFAPAR: Int = 3
		public static let SCRJREFREF1NFILE: Int = 4
		public static let BUTREGULARIZEACTIVE: Int = 5

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ scrJrefDetail: String = ""
					, _ scrJrefAPar: String = ""
					, _ scrJrefRef1NFile: String = ""
					, _ ButRegularizeActive: Bool = false
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.scrJrefDetail = scrJrefDetail
			self.scrJrefAPar = scrJrefAPar
			self.scrJrefRef1NFile = scrJrefRef1NFile
			self.ButRegularizeActive = ButRegularizeActive

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.SCRJREFDETAIL, StatShr.SCRJREFAPAR, StatShr.SCRJREFREF1NFILE, StatShr.BUTREGULARIZEACTIVE]
		}

		public var ixWzskVExpstate: Int
		public var scrJrefDetail: String
		public var scrJrefAPar: String
		public var scrJrefRef1NFile: String
		public var ButRegularizeActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskShtRec")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskShtRec"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefDetail", &mask, StatShr.SCRJREFDETAIL)
				scrJrefAPar = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefAPar", &mask, StatShr.SCRJREFAPAR)
				scrJrefRef1NFile = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefRef1NFile", &mask, StatShr.SCRJREFREF1NFILE)
				ButRegularizeActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButRegularizeActive", &mask, StatShr.BUTREGULARIZEACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}
			if scrJrefDetail == comp.scrJrefDetail {items.insert(StatShr.SCRJREFDETAIL)}
			if scrJrefAPar == comp.scrJrefAPar {items.insert(StatShr.SCRJREFAPAR)}
			if scrJrefRef1NFile == comp.scrJrefRef1NFile {items.insert(StatShr.SCRJREFREF1NFILE)}
			if ButRegularizeActive == comp.ButRegularizeActive {items.insert(StatShr.BUTREGULARIZEACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.SCRJREFDETAIL, StatShr.SCRJREFAPAR, StatShr.SCRJREFREF1NFILE, StatShr.BUTREGULARIZEACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskShtRec)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1

		public init(
					_ Cpt: String = ""
				) {
			self.Cpt = Cpt

			super.init()

			mask = [Tag.CPT]
		}

		public var Cpt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskShtRec")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskShtRec"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskShtRecDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKSHTRECDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskShtRecDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskShtRecData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let STATAPP: Int = 3
		public static let STATSHR: Int = 4
		public static let TAG: Int = 5

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKSHTRECDATA)
		}

		public var continf: ContInf = ContInf()
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskShtRecData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				continf = ContInf()
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
