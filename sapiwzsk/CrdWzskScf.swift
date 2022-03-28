/**
  * \file CrdWzskScf.swift
  * Swift API code for job CrdWzskScf
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* CrdWzskScf
	*/
public class CrdWzskScf {
	/**
		* VecVDo (full: VecVWzskScfDo)
		*/
	public class VecVDo {

		public static let CLOSE: Int = 1
		public static let MITAPPABTCLICK: Int = 2
		public static let MITCRDCMMCLICK: Int = 3
		public static let MITCRDTTCCLICK: Int = 4
		public static let MITCRDLSPCLICK: Int = 5

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "close" {return CLOSE}
			if s == "mitappabtclick" {return MITAPPABTCLICK}
			if s == "mitcrdcmmclick" {return MITCRDCMMCLICK}
			if s == "mitcrdttcclick" {return MITCRDTTCCLICK}
			if s == "mitcrdlspclick" {return MITCRDLSPCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == CLOSE {return "close"}
			if ix == MITAPPABTCLICK {return "MitAppAbtClick"}
			if ix == MITCRDCMMCLICK {return "MitCrdCmmClick"}
			if ix == MITCRDTTCCLICK {return "MitCrdTtcClick"}
			if ix == MITCRDLSPCLICK {return "MitCrdLspClick"}

			return ""
		}

	}

	/**
		* VecVSge (full: VecVWzskScfSge)
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
	  * ContInf (full: ContInfWzskScf)
	  */
	public class ContInf: Block {

		public static let NUMFSGE: Int = 1
		public static let MRLAPPHLP: Int = 2

		public init(
					_ numFSge: Int = 0
					, _ MrlAppHlp: String = ""
				) {
			self.numFSge = numFSge
			self.MrlAppHlp = MrlAppHlp

			super.init()

			mask = [ContInf.NUMFSGE, ContInf.MRLAPPHLP]
		}

		public var numFSge: Int
		public var MrlAppHlp: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskScf")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskScf"

			if valid {
				numFSge = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFSge", &mask, ContInf.NUMFSGE)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MrlAppHlp", &mask, ContInf.MRLAPPHLP)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFSge == comp.numFSge {items.insert(ContInf.NUMFSGE)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(ContInf.MRLAPPHLP)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.NUMFSGE, ContInf.MRLAPPHLP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskScf)
	  */
	public class StatApp: Block {

		public static let IXWZSKVREQITMODE: Int = 1
		public static let LATENCY: Int = 2
		public static let SHORTMENU: Int = 3
		public static let WIDTHMENU: Int = 4
		public static let INITDONECONN: Int = 5
		public static let INITDONEGEOM: Int = 6
		public static let INITDONEHEADBAR: Int = 7

		public init(
					_ ixWzskVReqitmode: Int = 0
					, _ latency: Int = 0
					, _ shortMenu: String = ""
					, _ widthMenu: Int = 0
					, _ initdoneConn: Bool = false
					, _ initdoneGeom: Bool = false
					, _ initdoneHeadbar: Bool = false
				) {
			self.ixWzskVReqitmode = ixWzskVReqitmode
			self.latency = latency
			self.shortMenu = shortMenu
			self.widthMenu = widthMenu
			self.initdoneConn = initdoneConn
			self.initdoneGeom = initdoneGeom
			self.initdoneHeadbar = initdoneHeadbar

			super.init()

			mask = [StatApp.IXWZSKVREQITMODE, StatApp.LATENCY, StatApp.SHORTMENU, StatApp.WIDTHMENU, StatApp.INITDONECONN, StatApp.INITDONEGEOM, StatApp.INITDONEHEADBAR]
		}

		public var ixWzskVReqitmode: Int
		public var latency: Int
		public var shortMenu: String
		public var widthMenu: Int
		public var initdoneConn: Bool
		public var initdoneGeom: Bool
		public var initdoneHeadbar: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVReqitmode: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskScf")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskScf"

			if valid {
				srefIxWzskVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVReqitmode", &mask, StatApp.IXWZSKVREQITMODE)
				ixWzskVReqitmode = VecWzskVReqitmode.getIx(srefIxWzskVReqitmode)
				latency = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "latency", &mask, StatApp.LATENCY)
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "shortMenu", &mask, StatApp.SHORTMENU)
				widthMenu = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "widthMenu", &mask, StatApp.WIDTHMENU)
				initdoneConn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneConn", &mask, StatApp.INITDONECONN)
				initdoneGeom = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneGeom", &mask, StatApp.INITDONEGEOM)
				initdoneHeadbar = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneHeadbar", &mask, StatApp.INITDONEHEADBAR)
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
			if initdoneConn == comp.initdoneConn {items.insert(StatApp.INITDONECONN)}
			if initdoneGeom == comp.initdoneGeom {items.insert(StatApp.INITDONEGEOM)}
			if initdoneHeadbar == comp.initdoneHeadbar {items.insert(StatApp.INITDONEHEADBAR)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVREQITMODE, StatApp.LATENCY, StatApp.SHORTMENU, StatApp.WIDTHMENU, StatApp.INITDONECONN, StatApp.INITDONEGEOM, StatApp.INITDONEHEADBAR]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskScf)
	  */
	public class StatShr: Block {

		public static let SCRJREFDLGCAMERAMAT: Int = 1
		public static let SCRJREFDLGLASERPOS: Int = 2
		public static let SCRJREFDLGTTABLECOORD: Int = 3
		public static let SCRJREFCONN: Int = 4
		public static let SCRJREFGEOM: Int = 5
		public static let SCRJREFHEADBAR: Int = 6

		public init(
					_ scrJrefDlgcameramat: String = ""
					, _ scrJrefDlglaserpos: String = ""
					, _ scrJrefDlgttablecoord: String = ""
					, _ scrJrefConn: String = ""
					, _ scrJrefGeom: String = ""
					, _ scrJrefHeadbar: String = ""
				) {
			self.scrJrefDlgcameramat = scrJrefDlgcameramat
			self.scrJrefDlglaserpos = scrJrefDlglaserpos
			self.scrJrefDlgttablecoord = scrJrefDlgttablecoord
			self.scrJrefConn = scrJrefConn
			self.scrJrefGeom = scrJrefGeom
			self.scrJrefHeadbar = scrJrefHeadbar

			super.init()

			mask = [StatShr.SCRJREFDLGCAMERAMAT, StatShr.SCRJREFDLGLASERPOS, StatShr.SCRJREFDLGTTABLECOORD, StatShr.SCRJREFCONN, StatShr.SCRJREFGEOM, StatShr.SCRJREFHEADBAR]
		}

		public var scrJrefDlgcameramat: String
		public var scrJrefDlglaserpos: String
		public var scrJrefDlgttablecoord: String
		public var scrJrefConn: String
		public var scrJrefGeom: String
		public var scrJrefHeadbar: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskScf")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskScf"

			if valid {
				scrJrefDlgcameramat = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefDlgcameramat", &mask, StatShr.SCRJREFDLGCAMERAMAT)
				scrJrefDlglaserpos = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefDlglaserpos", &mask, StatShr.SCRJREFDLGLASERPOS)
				scrJrefDlgttablecoord = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefDlgttablecoord", &mask, StatShr.SCRJREFDLGTTABLECOORD)
				scrJrefConn = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefConn", &mask, StatShr.SCRJREFCONN)
				scrJrefGeom = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefGeom", &mask, StatShr.SCRJREFGEOM)
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefHeadbar", &mask, StatShr.SCRJREFHEADBAR)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if scrJrefDlgcameramat == comp.scrJrefDlgcameramat {items.insert(StatShr.SCRJREFDLGCAMERAMAT)}
			if scrJrefDlglaserpos == comp.scrJrefDlglaserpos {items.insert(StatShr.SCRJREFDLGLASERPOS)}
			if scrJrefDlgttablecoord == comp.scrJrefDlgttablecoord {items.insert(StatShr.SCRJREFDLGTTABLECOORD)}
			if scrJrefConn == comp.scrJrefConn {items.insert(StatShr.SCRJREFCONN)}
			if scrJrefGeom == comp.scrJrefGeom {items.insert(StatShr.SCRJREFGEOM)}
			if scrJrefHeadbar == comp.scrJrefHeadbar {items.insert(StatShr.SCRJREFHEADBAR)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.SCRJREFDLGCAMERAMAT, StatShr.SCRJREFDLGLASERPOS, StatShr.SCRJREFDLGTTABLECOORD, StatShr.SCRJREFCONN, StatShr.SCRJREFGEOM, StatShr.SCRJREFHEADBAR]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskScf)
	  */
	public class Tag: Block {

		public static let MITAPPABT: Int = 1
		public static let MRLAPPHLP: Int = 2
		public static let MITCRDCMM: Int = 3
		public static let MITCRDTTC: Int = 4
		public static let MITCRDLSP: Int = 5

		public init(
					_ MitAppAbt: String = ""
					, _ MrlAppHlp: String = ""
					, _ MitCrdCmm: String = ""
					, _ MitCrdTtc: String = ""
					, _ MitCrdLsp: String = ""
				) {
			self.MitAppAbt = MitAppAbt
			self.MrlAppHlp = MrlAppHlp
			self.MitCrdCmm = MitCrdCmm
			self.MitCrdTtc = MitCrdTtc
			self.MitCrdLsp = MitCrdLsp

			super.init()

			mask = [Tag.MITAPPABT, Tag.MRLAPPHLP, Tag.MITCRDCMM, Tag.MITCRDTTC, Tag.MITCRDLSP]
		}

		public var MitAppAbt: String
		public var MrlAppHlp: String
		public var MitCrdCmm: String
		public var MitCrdTtc: String
		public var MitCrdLsp: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskScf")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskScf"

			if valid {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitAppAbt", &mask, Tag.MITAPPABT)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MrlAppHlp", &mask, Tag.MRLAPPHLP)
				MitCrdCmm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdCmm", &mask, Tag.MITCRDCMM)
				MitCrdTtc = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdTtc", &mask, Tag.MITCRDTTC)
				MitCrdLsp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdLsp", &mask, Tag.MITCRDLSP)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if MitAppAbt == comp.MitAppAbt {items.insert(Tag.MITAPPABT)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(Tag.MRLAPPHLP)}
			if MitCrdCmm == comp.MitCrdCmm {items.insert(Tag.MITCRDCMM)}
			if MitCrdTtc == comp.MitCrdTtc {items.insert(Tag.MITCRDTTC)}
			if MitCrdLsp == comp.MitCrdLsp {items.insert(Tag.MITCRDLSP)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.MITAPPABT, Tag.MRLAPPHLP, Tag.MITCRDCMM, Tag.MITCRDTTC, Tag.MITCRDLSP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskScfDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKSCFDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskScfDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskScfData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let FEEDFSGE: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKSCFDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskScfData")}
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
