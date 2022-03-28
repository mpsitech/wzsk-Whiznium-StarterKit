/**
  * \file PnlWzskLivSysmon.swift
  * Swift API code for job PnlWzskLivSysmon
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskLivSysmon
	*/
public class PnlWzskLivSysmon {
	/**
		* VecVDo (full: VecVWzskLivSysmonDo)
		*/
	public class VecVDo {

		public static let BUTREGULARIZECLICK: Int = 1
		public static let BUTMINIMIZECLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butregularizeclick" {return BUTREGULARIZECLICK}
			if s == "butminimizeclick" {return BUTMINIMIZECLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTREGULARIZECLICK {return "ButRegularizeClick"}
			if ix == BUTMINIMIZECLICK {return "ButMinimizeClick"}

			return ""
		}

	}

	/**
	  * ContInf (full: ContInfWzskLivSysmon)
	  */
	public class ContInf: Block {

		public static let TXTCTP: Int = 1

		public init(
					_ TxtCtp: String = ""
				) {
			self.TxtCtp = TxtCtp

			super.init()

			mask = [ContInf.TXTCTP]
		}

		public var TxtCtp: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskLivSysmon")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskLivSysmon"

			if valid {
				TxtCtp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtCtp", &mask, ContInf.TXTCTP)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtCtp == comp.TxtCtp {items.insert(ContInf.TXTCTP)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTCTP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskLivSysmon)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1

		public init(
					_ ixWzskVExpstate: Int = 0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE]
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskLivSysmon")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskLivSysmon"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskLivSysmon)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTCTP: Int = 2
		public static let CPTPLTTME: Int = 3
		public static let CPTPLTCLD: Int = 4
		public static let CPTPLTTOT: Int = 5
		public static let CPTPLTCOR: Int = 6

		public init(
					_ Cpt: String = ""
					, _ CptCtp: String = ""
					, _ CptPltTme: String = ""
					, _ CptPltCld: String = ""
					, _ CptPltTot: String = ""
					, _ CptPltCor: String = ""
				) {
			self.Cpt = Cpt
			self.CptCtp = CptCtp
			self.CptPltTme = CptPltTme
			self.CptPltCld = CptPltCld
			self.CptPltTot = CptPltTot
			self.CptPltCor = CptPltCor

			super.init()

			mask = [Tag.CPT, Tag.CPTCTP, Tag.CPTPLTTME, Tag.CPTPLTCLD, Tag.CPTPLTTOT, Tag.CPTPLTCOR]
		}

		public var Cpt: String
		public var CptCtp: String
		public var CptPltTme: String
		public var CptPltCld: String
		public var CptPltTot: String
		public var CptPltCor: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskLivSysmon")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskLivSysmon"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptCtp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCtp", &mask, Tag.CPTCTP)
				CptPltTme = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPltTme", &mask, Tag.CPTPLTTME)
				CptPltCld = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPltCld", &mask, Tag.CPTPLTCLD)
				CptPltTot = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPltTot", &mask, Tag.CPTPLTTOT)
				CptPltCor = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPltCor", &mask, Tag.CPTPLTCOR)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptCtp == comp.CptCtp {items.insert(Tag.CPTCTP)}
			if CptPltTme == comp.CptPltTme {items.insert(Tag.CPTPLTTME)}
			if CptPltCld == comp.CptPltCld {items.insert(Tag.CPTPLTCLD)}
			if CptPltTot == comp.CptPltTot {items.insert(Tag.CPTPLTTOT)}
			if CptPltCor == comp.CptPltCor {items.insert(Tag.CPTPLTCOR)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTCTP, Tag.CPTPLTTME, Tag.CPTPLTCLD, Tag.CPTPLTTOT, Tag.CPTPLTCOR]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskLivSysmonDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLIVSYSMONDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLivSysmonDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskLivSysmonData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let STATSHR: Int = 3
		public static let TAG: Int = 4

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLIVSYSMONDATA)
		}

		public var continf: ContInf = ContInf()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLivSysmonData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				continf = ContInf()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

	/**
		* DpchEngLive (full: DpchEngWzskLivSysmonLive)
		*/
	public class DpchEngLive: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let TS: Int = 2
		public static let CLDTOTS: Int = 3
		public static let CLD1S: Int = 4
		public static let CLD2S: Int = 5
		public static let CLD3S: Int = 6
		public static let CLD4S: Int = 7

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLIVSYSMONLIVE)
		}

		public var ts: [Float] = [Float]()
		public var cldtots: [Float] = [Float]()
		public var cld1s: [Float] = [Float]()
		public var cld2s: [Float] = [Float]()
		public var cld3s: [Float] = [Float]()
		public var cld4s: [Float] = [Float]()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngLive.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngLive.TS) {ss.append("ts")}
			if has(DpchEngLive.CLDTOTS) {ss.append("cldtots")}
			if has(DpchEngLive.CLD1S) {ss.append("cld1s")}
			if has(DpchEngLive.CLD2S) {ss.append("cld2s")}
			if has(DpchEngLive.CLD3S) {ss.append("cld3s")}
			if has(DpchEngLive.CLD4S) {ss.append("cld4s")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLivSysmonLive")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngLive.SCRJREF)
				ts = Xmlio.extractFloatvecUclc(doc, basexpath!, "ts", "", &mask, DpchEngLive.TS)
				cldtots = Xmlio.extractFloatvecUclc(doc, basexpath!, "cldtots", "", &mask, DpchEngLive.CLDTOTS)
				cld1s = Xmlio.extractFloatvecUclc(doc, basexpath!, "cld1s", "", &mask, DpchEngLive.CLD1S)
				cld2s = Xmlio.extractFloatvecUclc(doc, basexpath!, "cld2s", "", &mask, DpchEngLive.CLD2S)
				cld3s = Xmlio.extractFloatvecUclc(doc, basexpath!, "cld3s", "", &mask, DpchEngLive.CLD3S)
				cld4s = Xmlio.extractFloatvecUclc(doc, basexpath!, "cld4s", "", &mask, DpchEngLive.CLD4S)
			} else {
				scrJref = ""
				ts = [Float]()
				cldtots = [Float]()
				cld1s = [Float]()
				cld2s = [Float]()
				cld3s = [Float]()
				cld4s = [Float]()
			}
		}

	}

}
