/**
  * \file CrdWzskOgr.swift
  * Swift API code for job CrdWzskOgr
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* CrdWzskOgr
	*/
public class CrdWzskOgr {
	/**
		* VecVDo (full: VecVWzskOgrDo)
		*/
	public class VecVDo {

		public static let CLOSE: Int = 1
		public static let MITAPPABTCLICK: Int = 2
		public static let MITCRDNEWCLICK: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "close" {return CLOSE}
			if s == "mitappabtclick" {return MITAPPABTCLICK}
			if s == "mitcrdnewclick" {return MITCRDNEWCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == CLOSE {return "close"}
			if ix == MITAPPABTCLICK {return "MitAppAbtClick"}
			if ix == MITCRDNEWCLICK {return "MitCrdNewClick"}

			return ""
		}

	}

	/**
		* VecVSge (full: VecVWzskOgrSge)
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
	  * ContInf (full: ContInfWzskOgr)
	  */
	public class ContInf: Block {

		public static let NUMFSGE: Int = 1
		public static let MRLAPPHLP: Int = 2
		public static let MTXCRDOGR: Int = 3

		public init(
					_ numFSge: Int = 0
					, _ MrlAppHlp: String = ""
					, _ MtxCrdOgr: String = ""
				) {
			self.numFSge = numFSge
			self.MrlAppHlp = MrlAppHlp
			self.MtxCrdOgr = MtxCrdOgr

			super.init()

			mask = [ContInf.NUMFSGE, ContInf.MRLAPPHLP, ContInf.MTXCRDOGR]
		}

		public var numFSge: Int
		public var MrlAppHlp: String
		public var MtxCrdOgr: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskOgr")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskOgr"

			if valid {
				numFSge = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFSge", &mask, ContInf.NUMFSGE)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MrlAppHlp", &mask, ContInf.MRLAPPHLP)
				MtxCrdOgr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MtxCrdOgr", &mask, ContInf.MTXCRDOGR)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFSge == comp.numFSge {items.insert(ContInf.NUMFSGE)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(ContInf.MRLAPPHLP)}
			if MtxCrdOgr == comp.MtxCrdOgr {items.insert(ContInf.MTXCRDOGR)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.NUMFSGE, ContInf.MRLAPPHLP, ContInf.MTXCRDOGR]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskOgr)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskOgr")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskOgr"

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
	  * StatShr (full: StatShrWzskOgr)
	  */
	public class StatShr: Block {

		public static let SCRJREFDLGNEW: Int = 1
		public static let SCRJREFHEADBAR: Int = 2
		public static let SCRJREFLIST: Int = 3
		public static let SCRJREFREC: Int = 4
		public static let MSPCRD1AVAIL: Int = 5
		public static let MITCRDNEWAVAIL: Int = 6

		public init(
					_ scrJrefDlgnew: String = ""
					, _ scrJrefHeadbar: String = ""
					, _ scrJrefList: String = ""
					, _ scrJrefRec: String = ""
					, _ MspCrd1Avail: Bool = false
					, _ MitCrdNewAvail: Bool = false
				) {
			self.scrJrefDlgnew = scrJrefDlgnew
			self.scrJrefHeadbar = scrJrefHeadbar
			self.scrJrefList = scrJrefList
			self.scrJrefRec = scrJrefRec
			self.MspCrd1Avail = MspCrd1Avail
			self.MitCrdNewAvail = MitCrdNewAvail

			super.init()

			mask = [StatShr.SCRJREFDLGNEW, StatShr.SCRJREFHEADBAR, StatShr.SCRJREFLIST, StatShr.SCRJREFREC, StatShr.MSPCRD1AVAIL, StatShr.MITCRDNEWAVAIL]
		}

		public var scrJrefDlgnew: String
		public var scrJrefHeadbar: String
		public var scrJrefList: String
		public var scrJrefRec: String
		public var MspCrd1Avail: Bool
		public var MitCrdNewAvail: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskOgr")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskOgr"

			if valid {
				scrJrefDlgnew = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefDlgnew", &mask, StatShr.SCRJREFDLGNEW)
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefHeadbar", &mask, StatShr.SCRJREFHEADBAR)
				scrJrefList = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefList", &mask, StatShr.SCRJREFLIST)
				scrJrefRec = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefRec", &mask, StatShr.SCRJREFREC)
				MspCrd1Avail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MspCrd1Avail", &mask, StatShr.MSPCRD1AVAIL)
				MitCrdNewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdNewAvail", &mask, StatShr.MITCRDNEWAVAIL)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if scrJrefDlgnew == comp.scrJrefDlgnew {items.insert(StatShr.SCRJREFDLGNEW)}
			if scrJrefHeadbar == comp.scrJrefHeadbar {items.insert(StatShr.SCRJREFHEADBAR)}
			if scrJrefList == comp.scrJrefList {items.insert(StatShr.SCRJREFLIST)}
			if scrJrefRec == comp.scrJrefRec {items.insert(StatShr.SCRJREFREC)}
			if MspCrd1Avail == comp.MspCrd1Avail {items.insert(StatShr.MSPCRD1AVAIL)}
			if MitCrdNewAvail == comp.MitCrdNewAvail {items.insert(StatShr.MITCRDNEWAVAIL)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.SCRJREFDLGNEW, StatShr.SCRJREFHEADBAR, StatShr.SCRJREFLIST, StatShr.SCRJREFREC, StatShr.MSPCRD1AVAIL, StatShr.MITCRDNEWAVAIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskOgr)
	  */
	public class Tag: Block {

		public static let MITAPPABT: Int = 1
		public static let MRLAPPHLP: Int = 2
		public static let MITCRDNEW: Int = 3

		public init(
					_ MitAppAbt: String = ""
					, _ MrlAppHlp: String = ""
					, _ MitCrdNew: String = ""
				) {
			self.MitAppAbt = MitAppAbt
			self.MrlAppHlp = MrlAppHlp
			self.MitCrdNew = MitCrdNew

			super.init()

			mask = [Tag.MITAPPABT, Tag.MRLAPPHLP, Tag.MITCRDNEW]
		}

		public var MitAppAbt: String
		public var MrlAppHlp: String
		public var MitCrdNew: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskOgr")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskOgr"

			if valid {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitAppAbt", &mask, Tag.MITAPPABT)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MrlAppHlp", &mask, Tag.MRLAPPHLP)
				MitCrdNew = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdNew", &mask, Tag.MITCRDNEW)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if MitAppAbt == comp.MitAppAbt {items.insert(Tag.MITAPPABT)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(Tag.MRLAPPHLP)}
			if MitCrdNew == comp.MitCrdNew {items.insert(Tag.MITCRDNEW)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.MITAPPABT, Tag.MRLAPPHLP, Tag.MITCRDNEW]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskOgrDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKOGRDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskOgrDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskOgrData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let FEEDFSGE: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKOGRDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskOgrData")}
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
