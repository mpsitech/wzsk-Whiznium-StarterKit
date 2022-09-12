/**
  * \file CrdWzskFil.swift
  * Swift API code for job CrdWzskFil
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* CrdWzskFil
	*/
public class CrdWzskFil {
	/**
		* VecVDo (full: VecVWzskFilDo)
		*/
	public class VecVDo {

		public static let CLOSE: Int = 1
		public static let MITAPPABTCLICK: Int = 2
		public static let MITCRDDLDCLICK: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "close" {return CLOSE}
			if s == "mitappabtclick" {return MITAPPABTCLICK}
			if s == "mitcrddldclick" {return MITCRDDLDCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == CLOSE {return "close"}
			if ix == MITAPPABTCLICK {return "MitAppAbtClick"}
			if ix == MITCRDDLDCLICK {return "MitCrdDldClick"}

			return ""
		}

	}

	/**
		* VecVSge (full: VecVWzskFilSge)
		*/
	public class VecVSge {

		public static let IDLE: Int = 1
		public static let ALRWZSKABT: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "idle" {return IDLE}
			if s == "alrwzskabt" {return ALRWZSKABT}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == IDLE {return "idle"}
			if ix == ALRWZSKABT {return "alrwzskabt"}

			return ""
		}

	}

	/**
	  * ContInf (full: ContInfWzskFil)
	  */
	public class ContInf: Block {

		public static let NUMFSGE: Int = 1
		public static let MRLAPPHLP: Int = 2
		public static let MTXCRDFIL: Int = 3

		public init(
					_ numFSge: Int = 0
					, _ MrlAppHlp: String = ""
					, _ MtxCrdFil: String = ""
				) {
			self.numFSge = numFSge
			self.MrlAppHlp = MrlAppHlp
			self.MtxCrdFil = MtxCrdFil

			super.init()

			mask = [ContInf.NUMFSGE, ContInf.MRLAPPHLP, ContInf.MTXCRDFIL]
		}

		public var numFSge: Int
		public var MrlAppHlp: String
		public var MtxCrdFil: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskFil")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskFil"

			if valid {
				numFSge = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFSge", &mask, ContInf.NUMFSGE)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MrlAppHlp", &mask, ContInf.MRLAPPHLP)
				MtxCrdFil = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MtxCrdFil", &mask, ContInf.MTXCRDFIL)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFSge == comp.numFSge {items.insert(ContInf.NUMFSGE)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(ContInf.MRLAPPHLP)}
			if MtxCrdFil == comp.MtxCrdFil {items.insert(ContInf.MTXCRDFIL)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.NUMFSGE, ContInf.MRLAPPHLP, ContInf.MTXCRDFIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskFil)
	  */
	public class StatApp: Block {

		public static let IXWZSKVREQITMODE: Int = 1
		public static let LATENCY: Int = 2
		public static let SHORTMENU: Int = 3
		public static let WIDTHMENU: Int = 4
		public static let INITDONEHEADBAR: Int = 5
		public static let INITDONELIST: Int = 6
		public static let INITDONEREC: Int = 7

		public init(
					_ ixWzskVReqitmode: Int = 0
					, _ latency: Int = 0
					, _ shortMenu: String = ""
					, _ widthMenu: Int = 0
					, _ initdoneHeadbar: Bool = false
					, _ initdoneList: Bool = false
					, _ initdoneRec: Bool = false
				) {
			self.ixWzskVReqitmode = ixWzskVReqitmode
			self.latency = latency
			self.shortMenu = shortMenu
			self.widthMenu = widthMenu
			self.initdoneHeadbar = initdoneHeadbar
			self.initdoneList = initdoneList
			self.initdoneRec = initdoneRec

			super.init()

			mask = [StatApp.IXWZSKVREQITMODE, StatApp.LATENCY, StatApp.SHORTMENU, StatApp.WIDTHMENU, StatApp.INITDONEHEADBAR, StatApp.INITDONELIST, StatApp.INITDONEREC]
		}

		public var ixWzskVReqitmode: Int
		public var latency: Int
		public var shortMenu: String
		public var widthMenu: Int
		public var initdoneHeadbar: Bool
		public var initdoneList: Bool
		public var initdoneRec: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVReqitmode: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskFil")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskFil"

			if valid {
				srefIxWzskVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVReqitmode", &mask, StatApp.IXWZSKVREQITMODE)
				ixWzskVReqitmode = VecWzskVReqitmode.getIx(srefIxWzskVReqitmode)
				latency = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "latency", &mask, StatApp.LATENCY)
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "shortMenu", &mask, StatApp.SHORTMENU)
				widthMenu = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "widthMenu", &mask, StatApp.WIDTHMENU)
				initdoneHeadbar = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneHeadbar", &mask, StatApp.INITDONEHEADBAR)
				initdoneList = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneList", &mask, StatApp.INITDONELIST)
				initdoneRec = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneRec", &mask, StatApp.INITDONEREC)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVReqitmode == comp.ixWzskVReqitmode {items.insert(StatApp.IXWZSKVREQITMODE)}
			if latency == comp.latency {items.insert(StatApp.LATENCY)}
			if shortMenu == comp.shortMenu {items.insert(StatApp.SHORTMENU)}
			if widthMenu == comp.widthMenu {items.insert(StatApp.WIDTHMENU)}
			if initdoneHeadbar == comp.initdoneHeadbar {items.insert(StatApp.INITDONEHEADBAR)}
			if initdoneList == comp.initdoneList {items.insert(StatApp.INITDONELIST)}
			if initdoneRec == comp.initdoneRec {items.insert(StatApp.INITDONEREC)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVREQITMODE, StatApp.LATENCY, StatApp.SHORTMENU, StatApp.WIDTHMENU, StatApp.INITDONEHEADBAR, StatApp.INITDONELIST, StatApp.INITDONEREC]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskFil)
	  */
	public class StatShr: Block {

		public static let SCRJREFDLGDOWNLOAD: Int = 1
		public static let SCRJREFHEADBAR: Int = 2
		public static let SCRJREFLIST: Int = 3
		public static let SCRJREFREC: Int = 4
		public static let MITCRDDLDAVAIL: Int = 5
		public static let MITCRDDLDACTIVE: Int = 6

		public init(
					_ scrJrefDlgdownload: String = ""
					, _ scrJrefHeadbar: String = ""
					, _ scrJrefList: String = ""
					, _ scrJrefRec: String = ""
					, _ MitCrdDldAvail: Bool = false
					, _ MitCrdDldActive: Bool = false
				) {
			self.scrJrefDlgdownload = scrJrefDlgdownload
			self.scrJrefHeadbar = scrJrefHeadbar
			self.scrJrefList = scrJrefList
			self.scrJrefRec = scrJrefRec
			self.MitCrdDldAvail = MitCrdDldAvail
			self.MitCrdDldActive = MitCrdDldActive

			super.init()

			mask = [StatShr.SCRJREFDLGDOWNLOAD, StatShr.SCRJREFHEADBAR, StatShr.SCRJREFLIST, StatShr.SCRJREFREC, StatShr.MITCRDDLDAVAIL, StatShr.MITCRDDLDACTIVE]
		}

		public var scrJrefDlgdownload: String
		public var scrJrefHeadbar: String
		public var scrJrefList: String
		public var scrJrefRec: String
		public var MitCrdDldAvail: Bool
		public var MitCrdDldActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskFil")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskFil"

			if valid {
				scrJrefDlgdownload = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefDlgdownload", &mask, StatShr.SCRJREFDLGDOWNLOAD)
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefHeadbar", &mask, StatShr.SCRJREFHEADBAR)
				scrJrefList = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefList", &mask, StatShr.SCRJREFLIST)
				scrJrefRec = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefRec", &mask, StatShr.SCRJREFREC)
				MitCrdDldAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdDldAvail", &mask, StatShr.MITCRDDLDAVAIL)
				MitCrdDldActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdDldActive", &mask, StatShr.MITCRDDLDACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if scrJrefDlgdownload == comp.scrJrefDlgdownload {items.insert(StatShr.SCRJREFDLGDOWNLOAD)}
			if scrJrefHeadbar == comp.scrJrefHeadbar {items.insert(StatShr.SCRJREFHEADBAR)}
			if scrJrefList == comp.scrJrefList {items.insert(StatShr.SCRJREFLIST)}
			if scrJrefRec == comp.scrJrefRec {items.insert(StatShr.SCRJREFREC)}
			if MitCrdDldAvail == comp.MitCrdDldAvail {items.insert(StatShr.MITCRDDLDAVAIL)}
			if MitCrdDldActive == comp.MitCrdDldActive {items.insert(StatShr.MITCRDDLDACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.SCRJREFDLGDOWNLOAD, StatShr.SCRJREFHEADBAR, StatShr.SCRJREFLIST, StatShr.SCRJREFREC, StatShr.MITCRDDLDAVAIL, StatShr.MITCRDDLDACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskFil)
	  */
	public class Tag: Block {

		public static let MITAPPABT: Int = 1
		public static let MRLAPPHLP: Int = 2
		public static let MITCRDDLD: Int = 3

		public init(
					_ MitAppAbt: String = ""
					, _ MrlAppHlp: String = ""
					, _ MitCrdDld: String = ""
				) {
			self.MitAppAbt = MitAppAbt
			self.MrlAppHlp = MrlAppHlp
			self.MitCrdDld = MitCrdDld

			super.init()

			mask = [Tag.MITAPPABT, Tag.MRLAPPHLP, Tag.MITCRDDLD]
		}

		public var MitAppAbt: String
		public var MrlAppHlp: String
		public var MitCrdDld: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskFil")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskFil"

			if valid {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitAppAbt", &mask, Tag.MITAPPABT)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MrlAppHlp", &mask, Tag.MRLAPPHLP)
				MitCrdDld = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdDld", &mask, Tag.MITCRDDLD)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if MitAppAbt == comp.MitAppAbt {items.insert(Tag.MITAPPABT)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(Tag.MRLAPPHLP)}
			if MitCrdDld == comp.MitCrdDld {items.insert(Tag.MITCRDDLD)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.MITAPPABT, Tag.MRLAPPHLP, Tag.MITCRDDLD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskFilDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKFILDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskFilDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskFilData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let FEEDFSGE: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKFILDATA)
		}

		public var continf: ContInf = ContInf()
		public var feedFSge: Feed = Feed("FeedFSge")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFSGE) {ss.append("feedFSge")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskFilData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFSge.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFSGE)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				continf = ContInf()
				feedFSge = Feed("FeedFSge")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
