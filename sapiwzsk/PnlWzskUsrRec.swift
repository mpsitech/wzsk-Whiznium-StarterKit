/**
  * \file PnlWzskUsrRec.swift
  * Swift API code for job PnlWzskUsrRec
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskUsrRec
	*/
public class PnlWzskUsrRec {
	/**
		* VecVDo (full: VecVWzskUsrRecDo)
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
	  * ContInf (full: ContInfWzskUsrRec)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskUsrRec")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskUsrRec"

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
	  * StatApp (full: StatAppWzskUsrRec)
	  */
	public class StatApp: Block {

		public static let INITDONEDETAIL: Int = 1
		public static let INITDONEAACCESS: Int = 2
		public static let INITDONE1NSESSION: Int = 3
		public static let INITDONEMNUSERGROUP: Int = 4

		public init(
					_ initdoneDetail: Bool = false
					, _ initdoneAAccess: Bool = false
					, _ initdone1NSession: Bool = false
					, _ initdoneMNUsergroup: Bool = false
				) {
			self.initdoneDetail = initdoneDetail
			self.initdoneAAccess = initdoneAAccess
			self.initdone1NSession = initdone1NSession
			self.initdoneMNUsergroup = initdoneMNUsergroup

			super.init()

			mask = [StatApp.INITDONEDETAIL, StatApp.INITDONEAACCESS, StatApp.INITDONE1NSESSION, StatApp.INITDONEMNUSERGROUP]
		}

		public var initdoneDetail: Bool
		public var initdoneAAccess: Bool
		public var initdone1NSession: Bool
		public var initdoneMNUsergroup: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskUsrRec")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskUsrRec"

			if valid {
				initdoneDetail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneDetail", &mask, StatApp.INITDONEDETAIL)
				initdoneAAccess = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneAAccess", &mask, StatApp.INITDONEAACCESS)
				initdone1NSession = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdone1NSession", &mask, StatApp.INITDONE1NSESSION)
				initdoneMNUsergroup = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneMNUsergroup", &mask, StatApp.INITDONEMNUSERGROUP)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if initdoneDetail == comp.initdoneDetail {items.insert(StatApp.INITDONEDETAIL)}
			if initdoneAAccess == comp.initdoneAAccess {items.insert(StatApp.INITDONEAACCESS)}
			if initdone1NSession == comp.initdone1NSession {items.insert(StatApp.INITDONE1NSESSION)}
			if initdoneMNUsergroup == comp.initdoneMNUsergroup {items.insert(StatApp.INITDONEMNUSERGROUP)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.INITDONEDETAIL, StatApp.INITDONEAACCESS, StatApp.INITDONE1NSESSION, StatApp.INITDONEMNUSERGROUP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskUsrRec)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let SCRJREFDETAIL: Int = 2
		public static let SCRJREFAACCESS: Int = 3
		public static let SCRJREF1NSESSION: Int = 4
		public static let SCRJREFMNUSERGROUP: Int = 5
		public static let BUTREGULARIZEACTIVE: Int = 6

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ scrJrefDetail: String = ""
					, _ scrJrefAAccess: String = ""
					, _ scrJref1NSession: String = ""
					, _ scrJrefMNUsergroup: String = ""
					, _ ButRegularizeActive: Bool = false
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.scrJrefDetail = scrJrefDetail
			self.scrJrefAAccess = scrJrefAAccess
			self.scrJref1NSession = scrJref1NSession
			self.scrJrefMNUsergroup = scrJrefMNUsergroup
			self.ButRegularizeActive = ButRegularizeActive

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.SCRJREFDETAIL, StatShr.SCRJREFAACCESS, StatShr.SCRJREF1NSESSION, StatShr.SCRJREFMNUSERGROUP, StatShr.BUTREGULARIZEACTIVE]
		}

		public var ixWzskVExpstate: Int
		public var scrJrefDetail: String
		public var scrJrefAAccess: String
		public var scrJref1NSession: String
		public var scrJrefMNUsergroup: String
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskUsrRec")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskUsrRec"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefDetail", &mask, StatShr.SCRJREFDETAIL)
				scrJrefAAccess = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefAAccess", &mask, StatShr.SCRJREFAACCESS)
				scrJref1NSession = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJref1NSession", &mask, StatShr.SCRJREF1NSESSION)
				scrJrefMNUsergroup = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefMNUsergroup", &mask, StatShr.SCRJREFMNUSERGROUP)
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
			if scrJrefAAccess == comp.scrJrefAAccess {items.insert(StatShr.SCRJREFAACCESS)}
			if scrJref1NSession == comp.scrJref1NSession {items.insert(StatShr.SCRJREF1NSESSION)}
			if scrJrefMNUsergroup == comp.scrJrefMNUsergroup {items.insert(StatShr.SCRJREFMNUSERGROUP)}
			if ButRegularizeActive == comp.ButRegularizeActive {items.insert(StatShr.BUTREGULARIZEACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.SCRJREFDETAIL, StatShr.SCRJREFAACCESS, StatShr.SCRJREF1NSESSION, StatShr.SCRJREFMNUSERGROUP, StatShr.BUTREGULARIZEACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskUsrRec)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskUsrRec")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskUsrRec"

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
		* DpchAppDo (full: DpchAppWzskUsrRecDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKUSRRECDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskUsrRecDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskUsrRecData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let STATAPP: Int = 3
		public static let STATSHR: Int = 4
		public static let TAG: Int = 5

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKUSRRECDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskUsrRecData")}
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
