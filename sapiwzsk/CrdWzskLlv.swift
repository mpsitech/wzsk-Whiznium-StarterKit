/**
  * \file CrdWzskLlv.swift
  * Swift API code for job CrdWzskLlv
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* CrdWzskLlv
	*/
public class CrdWzskLlv {
	/**
		* VecVDo (full: VecVWzskLlvDo)
		*/
	public class VecVDo {

		public static let CLOSE: Int = 1
		public static let MITAPPABTCLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "close" {return CLOSE}
			if s == "mitappabtclick" {return MITAPPABTCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == CLOSE {return "close"}
			if ix == MITAPPABTCLICK {return "MitAppAbtClick"}

			return ""
		}

	}

	/**
		* VecVSge (full: VecVWzskLlvSge)
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
	  * ContInf (full: ContInfWzskLlv)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskLlv")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskLlv"

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
	  * StatApp (full: StatAppWzskLlv)
	  */
	public class StatApp: Block {

		public static let IXWZSKVREQITMODE: Int = 1
		public static let LATENCY: Int = 2
		public static let SHORTMENU: Int = 3
		public static let WIDTHMENU: Int = 4
		public static let INITDONEHEADBAR: Int = 5
		public static let INITDONETERMARTY: Int = 6
		public static let INITDONETERMCLNXEVB: Int = 7
		public static let INITDONETERMICICLE: Int = 8
		public static let INITDONETERMMCVEVP: Int = 9
		public static let INITDONETERMUVBDVK: Int = 10
		public static let INITDONECAMERA: Int = 11
		public static let INITDONETTABLE: Int = 12
		public static let INITDONELASER: Int = 13
		public static let INITDONETERMPWMONUART: Int = 14
		public static let INITDONETERMPWMONUSB: Int = 15

		public init(
					_ ixWzskVReqitmode: Int = 0
					, _ latency: Int = 0
					, _ shortMenu: String = ""
					, _ widthMenu: Int = 0
					, _ initdoneHeadbar: Bool = false
					, _ initdoneTermArty: Bool = false
					, _ initdoneTermClnxevb: Bool = false
					, _ initdoneTermIcicle: Bool = false
					, _ initdoneTermMcvevp: Bool = false
					, _ initdoneTermUvbdvk: Bool = false
					, _ initdoneCamera: Bool = false
					, _ initdoneTtable: Bool = false
					, _ initdoneLaser: Bool = false
					, _ initdoneTermPwmonuart: Bool = false
					, _ initdoneTermPwmonusb: Bool = false
				) {
			self.ixWzskVReqitmode = ixWzskVReqitmode
			self.latency = latency
			self.shortMenu = shortMenu
			self.widthMenu = widthMenu
			self.initdoneHeadbar = initdoneHeadbar
			self.initdoneTermArty = initdoneTermArty
			self.initdoneTermClnxevb = initdoneTermClnxevb
			self.initdoneTermIcicle = initdoneTermIcicle
			self.initdoneTermMcvevp = initdoneTermMcvevp
			self.initdoneTermUvbdvk = initdoneTermUvbdvk
			self.initdoneCamera = initdoneCamera
			self.initdoneTtable = initdoneTtable
			self.initdoneLaser = initdoneLaser
			self.initdoneTermPwmonuart = initdoneTermPwmonuart
			self.initdoneTermPwmonusb = initdoneTermPwmonusb

			super.init()

			mask = [StatApp.IXWZSKVREQITMODE, StatApp.LATENCY, StatApp.SHORTMENU, StatApp.WIDTHMENU, StatApp.INITDONEHEADBAR, StatApp.INITDONETERMARTY, StatApp.INITDONETERMCLNXEVB, StatApp.INITDONETERMICICLE, StatApp.INITDONETERMMCVEVP, StatApp.INITDONETERMUVBDVK, StatApp.INITDONECAMERA, StatApp.INITDONETTABLE, StatApp.INITDONELASER, StatApp.INITDONETERMPWMONUART, StatApp.INITDONETERMPWMONUSB]
		}

		public var ixWzskVReqitmode: Int
		public var latency: Int
		public var shortMenu: String
		public var widthMenu: Int
		public var initdoneHeadbar: Bool
		public var initdoneTermArty: Bool
		public var initdoneTermClnxevb: Bool
		public var initdoneTermIcicle: Bool
		public var initdoneTermMcvevp: Bool
		public var initdoneTermUvbdvk: Bool
		public var initdoneCamera: Bool
		public var initdoneTtable: Bool
		public var initdoneLaser: Bool
		public var initdoneTermPwmonuart: Bool
		public var initdoneTermPwmonusb: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVReqitmode: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskLlv")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskLlv"

			if valid {
				srefIxWzskVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVReqitmode", &mask, StatApp.IXWZSKVREQITMODE)
				ixWzskVReqitmode = VecWzskVReqitmode.getIx(srefIxWzskVReqitmode)
				latency = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "latency", &mask, StatApp.LATENCY)
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "shortMenu", &mask, StatApp.SHORTMENU)
				widthMenu = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "widthMenu", &mask, StatApp.WIDTHMENU)
				initdoneHeadbar = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneHeadbar", &mask, StatApp.INITDONEHEADBAR)
				initdoneTermArty = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneTermArty", &mask, StatApp.INITDONETERMARTY)
				initdoneTermClnxevb = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneTermClnxevb", &mask, StatApp.INITDONETERMCLNXEVB)
				initdoneTermIcicle = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneTermIcicle", &mask, StatApp.INITDONETERMICICLE)
				initdoneTermMcvevp = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneTermMcvevp", &mask, StatApp.INITDONETERMMCVEVP)
				initdoneTermUvbdvk = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneTermUvbdvk", &mask, StatApp.INITDONETERMUVBDVK)
				initdoneCamera = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneCamera", &mask, StatApp.INITDONECAMERA)
				initdoneTtable = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneTtable", &mask, StatApp.INITDONETTABLE)
				initdoneLaser = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneLaser", &mask, StatApp.INITDONELASER)
				initdoneTermPwmonuart = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneTermPwmonuart", &mask, StatApp.INITDONETERMPWMONUART)
				initdoneTermPwmonusb = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneTermPwmonusb", &mask, StatApp.INITDONETERMPWMONUSB)
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
			if initdoneTermArty == comp.initdoneTermArty {items.insert(StatApp.INITDONETERMARTY)}
			if initdoneTermClnxevb == comp.initdoneTermClnxevb {items.insert(StatApp.INITDONETERMCLNXEVB)}
			if initdoneTermIcicle == comp.initdoneTermIcicle {items.insert(StatApp.INITDONETERMICICLE)}
			if initdoneTermMcvevp == comp.initdoneTermMcvevp {items.insert(StatApp.INITDONETERMMCVEVP)}
			if initdoneTermUvbdvk == comp.initdoneTermUvbdvk {items.insert(StatApp.INITDONETERMUVBDVK)}
			if initdoneCamera == comp.initdoneCamera {items.insert(StatApp.INITDONECAMERA)}
			if initdoneTtable == comp.initdoneTtable {items.insert(StatApp.INITDONETTABLE)}
			if initdoneLaser == comp.initdoneLaser {items.insert(StatApp.INITDONELASER)}
			if initdoneTermPwmonuart == comp.initdoneTermPwmonuart {items.insert(StatApp.INITDONETERMPWMONUART)}
			if initdoneTermPwmonusb == comp.initdoneTermPwmonusb {items.insert(StatApp.INITDONETERMPWMONUSB)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVREQITMODE, StatApp.LATENCY, StatApp.SHORTMENU, StatApp.WIDTHMENU, StatApp.INITDONEHEADBAR, StatApp.INITDONETERMARTY, StatApp.INITDONETERMCLNXEVB, StatApp.INITDONETERMICICLE, StatApp.INITDONETERMMCVEVP, StatApp.INITDONETERMUVBDVK, StatApp.INITDONECAMERA, StatApp.INITDONETTABLE, StatApp.INITDONELASER, StatApp.INITDONETERMPWMONUART, StatApp.INITDONETERMPWMONUSB]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskLlv)
	  */
	public class StatShr: Block {

		public static let SCRJREFHEADBAR: Int = 1
		public static let SCRJREFTERMARTY: Int = 2
		public static let PNLTERMARTYAVAIL: Int = 3
		public static let SCRJREFTERMCLNXEVB: Int = 4
		public static let PNLTERMCLNXEVBAVAIL: Int = 5
		public static let SCRJREFTERMICICLE: Int = 6
		public static let PNLTERMICICLEAVAIL: Int = 7
		public static let SCRJREFTERMMCVEVP: Int = 8
		public static let PNLTERMMCVEVPAVAIL: Int = 9
		public static let SCRJREFTERMUVBDVK: Int = 10
		public static let PNLTERMUVBDVKAVAIL: Int = 11
		public static let SCRJREFCAMERA: Int = 12
		public static let SCRJREFTTABLE: Int = 13
		public static let SCRJREFLASER: Int = 14
		public static let SCRJREFTERMPWMONUART: Int = 15
		public static let PNLTERMPWMONUARTAVAIL: Int = 16
		public static let SCRJREFTERMPWMONUSB: Int = 17
		public static let PNLTERMPWMONUSBAVAIL: Int = 18

		public init(
					_ scrJrefHeadbar: String = ""
					, _ scrJrefTermArty: String = ""
					, _ pnltermartyAvail: Bool = false
					, _ scrJrefTermClnxevb: String = ""
					, _ pnltermclnxevbAvail: Bool = false
					, _ scrJrefTermIcicle: String = ""
					, _ pnltermicicleAvail: Bool = false
					, _ scrJrefTermMcvevp: String = ""
					, _ pnltermmcvevpAvail: Bool = false
					, _ scrJrefTermUvbdvk: String = ""
					, _ pnltermuvbdvkAvail: Bool = false
					, _ scrJrefCamera: String = ""
					, _ scrJrefTtable: String = ""
					, _ scrJrefLaser: String = ""
					, _ scrJrefTermPwmonuart: String = ""
					, _ pnltermpwmonuartAvail: Bool = false
					, _ scrJrefTermPwmonusb: String = ""
					, _ pnltermpwmonusbAvail: Bool = false
				) {
			self.scrJrefHeadbar = scrJrefHeadbar
			self.scrJrefTermArty = scrJrefTermArty
			self.pnltermartyAvail = pnltermartyAvail
			self.scrJrefTermClnxevb = scrJrefTermClnxevb
			self.pnltermclnxevbAvail = pnltermclnxevbAvail
			self.scrJrefTermIcicle = scrJrefTermIcicle
			self.pnltermicicleAvail = pnltermicicleAvail
			self.scrJrefTermMcvevp = scrJrefTermMcvevp
			self.pnltermmcvevpAvail = pnltermmcvevpAvail
			self.scrJrefTermUvbdvk = scrJrefTermUvbdvk
			self.pnltermuvbdvkAvail = pnltermuvbdvkAvail
			self.scrJrefCamera = scrJrefCamera
			self.scrJrefTtable = scrJrefTtable
			self.scrJrefLaser = scrJrefLaser
			self.scrJrefTermPwmonuart = scrJrefTermPwmonuart
			self.pnltermpwmonuartAvail = pnltermpwmonuartAvail
			self.scrJrefTermPwmonusb = scrJrefTermPwmonusb
			self.pnltermpwmonusbAvail = pnltermpwmonusbAvail

			super.init()

			mask = [StatShr.SCRJREFHEADBAR, StatShr.SCRJREFTERMARTY, StatShr.PNLTERMARTYAVAIL, StatShr.SCRJREFTERMCLNXEVB, StatShr.PNLTERMCLNXEVBAVAIL, StatShr.SCRJREFTERMICICLE, StatShr.PNLTERMICICLEAVAIL, StatShr.SCRJREFTERMMCVEVP, StatShr.PNLTERMMCVEVPAVAIL, StatShr.SCRJREFTERMUVBDVK, StatShr.PNLTERMUVBDVKAVAIL, StatShr.SCRJREFCAMERA, StatShr.SCRJREFTTABLE, StatShr.SCRJREFLASER, StatShr.SCRJREFTERMPWMONUART, StatShr.PNLTERMPWMONUARTAVAIL, StatShr.SCRJREFTERMPWMONUSB, StatShr.PNLTERMPWMONUSBAVAIL]
		}

		public var scrJrefHeadbar: String
		public var scrJrefTermArty: String
		public var pnltermartyAvail: Bool
		public var scrJrefTermClnxevb: String
		public var pnltermclnxevbAvail: Bool
		public var scrJrefTermIcicle: String
		public var pnltermicicleAvail: Bool
		public var scrJrefTermMcvevp: String
		public var pnltermmcvevpAvail: Bool
		public var scrJrefTermUvbdvk: String
		public var pnltermuvbdvkAvail: Bool
		public var scrJrefCamera: String
		public var scrJrefTtable: String
		public var scrJrefLaser: String
		public var scrJrefTermPwmonuart: String
		public var pnltermpwmonuartAvail: Bool
		public var scrJrefTermPwmonusb: String
		public var pnltermpwmonusbAvail: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskLlv")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskLlv"

			if valid {
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefHeadbar", &mask, StatShr.SCRJREFHEADBAR)
				scrJrefTermArty = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefTermArty", &mask, StatShr.SCRJREFTERMARTY)
				pnltermartyAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnltermartyAvail", &mask, StatShr.PNLTERMARTYAVAIL)
				scrJrefTermClnxevb = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefTermClnxevb", &mask, StatShr.SCRJREFTERMCLNXEVB)
				pnltermclnxevbAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnltermclnxevbAvail", &mask, StatShr.PNLTERMCLNXEVBAVAIL)
				scrJrefTermIcicle = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefTermIcicle", &mask, StatShr.SCRJREFTERMICICLE)
				pnltermicicleAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnltermicicleAvail", &mask, StatShr.PNLTERMICICLEAVAIL)
				scrJrefTermMcvevp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefTermMcvevp", &mask, StatShr.SCRJREFTERMMCVEVP)
				pnltermmcvevpAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnltermmcvevpAvail", &mask, StatShr.PNLTERMMCVEVPAVAIL)
				scrJrefTermUvbdvk = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefTermUvbdvk", &mask, StatShr.SCRJREFTERMUVBDVK)
				pnltermuvbdvkAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnltermuvbdvkAvail", &mask, StatShr.PNLTERMUVBDVKAVAIL)
				scrJrefCamera = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefCamera", &mask, StatShr.SCRJREFCAMERA)
				scrJrefTtable = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefTtable", &mask, StatShr.SCRJREFTTABLE)
				scrJrefLaser = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefLaser", &mask, StatShr.SCRJREFLASER)
				scrJrefTermPwmonuart = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefTermPwmonuart", &mask, StatShr.SCRJREFTERMPWMONUART)
				pnltermpwmonuartAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnltermpwmonuartAvail", &mask, StatShr.PNLTERMPWMONUARTAVAIL)
				scrJrefTermPwmonusb = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefTermPwmonusb", &mask, StatShr.SCRJREFTERMPWMONUSB)
				pnltermpwmonusbAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnltermpwmonusbAvail", &mask, StatShr.PNLTERMPWMONUSBAVAIL)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if scrJrefHeadbar == comp.scrJrefHeadbar {items.insert(StatShr.SCRJREFHEADBAR)}
			if scrJrefTermArty == comp.scrJrefTermArty {items.insert(StatShr.SCRJREFTERMARTY)}
			if pnltermartyAvail == comp.pnltermartyAvail {items.insert(StatShr.PNLTERMARTYAVAIL)}
			if scrJrefTermClnxevb == comp.scrJrefTermClnxevb {items.insert(StatShr.SCRJREFTERMCLNXEVB)}
			if pnltermclnxevbAvail == comp.pnltermclnxevbAvail {items.insert(StatShr.PNLTERMCLNXEVBAVAIL)}
			if scrJrefTermIcicle == comp.scrJrefTermIcicle {items.insert(StatShr.SCRJREFTERMICICLE)}
			if pnltermicicleAvail == comp.pnltermicicleAvail {items.insert(StatShr.PNLTERMICICLEAVAIL)}
			if scrJrefTermMcvevp == comp.scrJrefTermMcvevp {items.insert(StatShr.SCRJREFTERMMCVEVP)}
			if pnltermmcvevpAvail == comp.pnltermmcvevpAvail {items.insert(StatShr.PNLTERMMCVEVPAVAIL)}
			if scrJrefTermUvbdvk == comp.scrJrefTermUvbdvk {items.insert(StatShr.SCRJREFTERMUVBDVK)}
			if pnltermuvbdvkAvail == comp.pnltermuvbdvkAvail {items.insert(StatShr.PNLTERMUVBDVKAVAIL)}
			if scrJrefCamera == comp.scrJrefCamera {items.insert(StatShr.SCRJREFCAMERA)}
			if scrJrefTtable == comp.scrJrefTtable {items.insert(StatShr.SCRJREFTTABLE)}
			if scrJrefLaser == comp.scrJrefLaser {items.insert(StatShr.SCRJREFLASER)}
			if scrJrefTermPwmonuart == comp.scrJrefTermPwmonuart {items.insert(StatShr.SCRJREFTERMPWMONUART)}
			if pnltermpwmonuartAvail == comp.pnltermpwmonuartAvail {items.insert(StatShr.PNLTERMPWMONUARTAVAIL)}
			if scrJrefTermPwmonusb == comp.scrJrefTermPwmonusb {items.insert(StatShr.SCRJREFTERMPWMONUSB)}
			if pnltermpwmonusbAvail == comp.pnltermpwmonusbAvail {items.insert(StatShr.PNLTERMPWMONUSBAVAIL)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.SCRJREFHEADBAR, StatShr.SCRJREFTERMARTY, StatShr.PNLTERMARTYAVAIL, StatShr.SCRJREFTERMCLNXEVB, StatShr.PNLTERMCLNXEVBAVAIL, StatShr.SCRJREFTERMICICLE, StatShr.PNLTERMICICLEAVAIL, StatShr.SCRJREFTERMMCVEVP, StatShr.PNLTERMMCVEVPAVAIL, StatShr.SCRJREFTERMUVBDVK, StatShr.PNLTERMUVBDVKAVAIL, StatShr.SCRJREFCAMERA, StatShr.SCRJREFTTABLE, StatShr.SCRJREFLASER, StatShr.SCRJREFTERMPWMONUART, StatShr.PNLTERMPWMONUARTAVAIL, StatShr.SCRJREFTERMPWMONUSB, StatShr.PNLTERMPWMONUSBAVAIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskLlv)
	  */
	public class Tag: Block {

		public static let MITAPPABT: Int = 1
		public static let MRLAPPHLP: Int = 2

		public init(
					_ MitAppAbt: String = ""
					, _ MrlAppHlp: String = ""
				) {
			self.MitAppAbt = MitAppAbt
			self.MrlAppHlp = MrlAppHlp

			super.init()

			mask = [Tag.MITAPPABT, Tag.MRLAPPHLP]
		}

		public var MitAppAbt: String
		public var MrlAppHlp: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskLlv")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskLlv"

			if valid {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitAppAbt", &mask, Tag.MITAPPABT)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MrlAppHlp", &mask, Tag.MRLAPPHLP)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if MitAppAbt == comp.MitAppAbt {items.insert(Tag.MITAPPABT)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(Tag.MRLAPPHLP)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.MITAPPABT, Tag.MRLAPPHLP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskLlvDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLLVDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLlvDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskLlvData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let FEEDFSGE: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLLVDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLlvData")}
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
