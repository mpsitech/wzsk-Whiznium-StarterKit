/**
  * \file CrdWzskNav.swift
  * Swift API code for job CrdWzskNav
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* CrdWzskNav
	*/
public class CrdWzskNav {
	/**
		* VecVDo (full: VecVWzskNavDo)
		*/
	public class VecVDo {

		public static let CLOSE: Int = 1
		public static let MITAPPABTCLICK: Int = 2
		public static let MITSESSPSCLICK: Int = 3
		public static let MITSESTRMCLICK: Int = 4
		public static let MITCRDUSGCLICK: Int = 5
		public static let MITCRDUSRCLICK: Int = 6
		public static let MITCRDPRSCLICK: Int = 7
		public static let MITCRDSCFCLICK: Int = 8
		public static let MITCRDLLVCLICK: Int = 9
		public static let MITCRDLIVCLICK: Int = 10
		public static let MITCRDOGRCLICK: Int = 11
		public static let MITCRDOBJCLICK: Int = 12
		public static let MITCRDSESCLICK: Int = 13
		public static let MITCRDSHTCLICK: Int = 14
		public static let MITCRDFILCLICK: Int = 15
		public static let MITAPPLOICLICK: Int = 16

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "close" {return CLOSE}
			if s == "mitappabtclick" {return MITAPPABTCLICK}
			if s == "mitsesspsclick" {return MITSESSPSCLICK}
			if s == "mitsestrmclick" {return MITSESTRMCLICK}
			if s == "mitcrdusgclick" {return MITCRDUSGCLICK}
			if s == "mitcrdusrclick" {return MITCRDUSRCLICK}
			if s == "mitcrdprsclick" {return MITCRDPRSCLICK}
			if s == "mitcrdscfclick" {return MITCRDSCFCLICK}
			if s == "mitcrdllvclick" {return MITCRDLLVCLICK}
			if s == "mitcrdlivclick" {return MITCRDLIVCLICK}
			if s == "mitcrdogrclick" {return MITCRDOGRCLICK}
			if s == "mitcrdobjclick" {return MITCRDOBJCLICK}
			if s == "mitcrdsesclick" {return MITCRDSESCLICK}
			if s == "mitcrdshtclick" {return MITCRDSHTCLICK}
			if s == "mitcrdfilclick" {return MITCRDFILCLICK}
			if s == "mitapploiclick" {return MITAPPLOICLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == CLOSE {return "close"}
			if ix == MITAPPABTCLICK {return "MitAppAbtClick"}
			if ix == MITSESSPSCLICK {return "MitSesSpsClick"}
			if ix == MITSESTRMCLICK {return "MitSesTrmClick"}
			if ix == MITCRDUSGCLICK {return "MitCrdUsgClick"}
			if ix == MITCRDUSRCLICK {return "MitCrdUsrClick"}
			if ix == MITCRDPRSCLICK {return "MitCrdPrsClick"}
			if ix == MITCRDSCFCLICK {return "MitCrdScfClick"}
			if ix == MITCRDLLVCLICK {return "MitCrdLlvClick"}
			if ix == MITCRDLIVCLICK {return "MitCrdLivClick"}
			if ix == MITCRDOGRCLICK {return "MitCrdOgrClick"}
			if ix == MITCRDOBJCLICK {return "MitCrdObjClick"}
			if ix == MITCRDSESCLICK {return "MitCrdSesClick"}
			if ix == MITCRDSHTCLICK {return "MitCrdShtClick"}
			if ix == MITCRDFILCLICK {return "MitCrdFilClick"}
			if ix == MITAPPLOICLICK {return "MitAppLoiClick"}

			return ""
		}

	}

	/**
		* VecVSge (full: VecVWzskNavSge)
		*/
	public class VecVSge {

		public static let IDLE: Int = 1
		public static let ALRWZSKABT: Int = 2
		public static let ALRWZSKTRM: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "idle" {return IDLE}
			if s == "alrwzskabt" {return ALRWZSKABT}
			if s == "alrwzsktrm" {return ALRWZSKTRM}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == IDLE {return "idle"}
			if ix == ALRWZSKABT {return "alrwzskabt"}
			if ix == ALRWZSKTRM {return "alrwzsktrm"}

			return ""
		}

	}

	/**
	  * ContInf (full: ContInfWzskNav)
	  */
	public class ContInf: Block {

		public static let NUMFSGE: Int = 1
		public static let MRLAPPHLP: Int = 2
		public static let MTXSESSES1: Int = 3
		public static let MTXSESSES2: Int = 4
		public static let MTXSESSES3: Int = 5

		public init(
					_ numFSge: Int = 0
					, _ MrlAppHlp: String = ""
					, _ MtxSesSes1: String = ""
					, _ MtxSesSes2: String = ""
					, _ MtxSesSes3: String = ""
				) {
			self.numFSge = numFSge
			self.MrlAppHlp = MrlAppHlp
			self.MtxSesSes1 = MtxSesSes1
			self.MtxSesSes2 = MtxSesSes2
			self.MtxSesSes3 = MtxSesSes3

			super.init()

			mask = [ContInf.NUMFSGE, ContInf.MRLAPPHLP, ContInf.MTXSESSES1, ContInf.MTXSESSES2, ContInf.MTXSESSES3]
		}

		public var numFSge: Int
		public var MrlAppHlp: String
		public var MtxSesSes1: String
		public var MtxSesSes2: String
		public var MtxSesSes3: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskNav")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskNav"

			if valid {
				numFSge = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFSge", &mask, ContInf.NUMFSGE)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MrlAppHlp", &mask, ContInf.MRLAPPHLP)
				MtxSesSes1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MtxSesSes1", &mask, ContInf.MTXSESSES1)
				MtxSesSes2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MtxSesSes2", &mask, ContInf.MTXSESSES2)
				MtxSesSes3 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MtxSesSes3", &mask, ContInf.MTXSESSES3)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFSge == comp.numFSge {items.insert(ContInf.NUMFSGE)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(ContInf.MRLAPPHLP)}
			if MtxSesSes1 == comp.MtxSesSes1 {items.insert(ContInf.MTXSESSES1)}
			if MtxSesSes2 == comp.MtxSesSes2 {items.insert(ContInf.MTXSESSES2)}
			if MtxSesSes3 == comp.MtxSesSes3 {items.insert(ContInf.MTXSESSES3)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.NUMFSGE, ContInf.MRLAPPHLP, ContInf.MTXSESSES1, ContInf.MTXSESSES2, ContInf.MTXSESSES3]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskNav)
	  */
	public class StatApp: Block {

		public static let IXWZSKVREQITMODE: Int = 1
		public static let LATENCY: Int = 2
		public static let SHORTMENU: Int = 3
		public static let WIDTHMENU: Int = 4
		public static let INITDONEHEADBAR: Int = 5
		public static let INITDONEPRE: Int = 6
		public static let INITDONEADMIN: Int = 7
		public static let INITDONEOP: Int = 8
		public static let INITDONEGLRY: Int = 9

		public init(
					_ ixWzskVReqitmode: Int = 0
					, _ latency: Int = 0
					, _ shortMenu: String = ""
					, _ widthMenu: Int = 0
					, _ initdoneHeadbar: Bool = false
					, _ initdonePre: Bool = false
					, _ initdoneAdmin: Bool = false
					, _ initdoneOp: Bool = false
					, _ initdoneGlry: Bool = false
				) {
			self.ixWzskVReqitmode = ixWzskVReqitmode
			self.latency = latency
			self.shortMenu = shortMenu
			self.widthMenu = widthMenu
			self.initdoneHeadbar = initdoneHeadbar
			self.initdonePre = initdonePre
			self.initdoneAdmin = initdoneAdmin
			self.initdoneOp = initdoneOp
			self.initdoneGlry = initdoneGlry

			super.init()

			mask = [StatApp.IXWZSKVREQITMODE, StatApp.LATENCY, StatApp.SHORTMENU, StatApp.WIDTHMENU, StatApp.INITDONEHEADBAR, StatApp.INITDONEPRE, StatApp.INITDONEADMIN, StatApp.INITDONEOP, StatApp.INITDONEGLRY]
		}

		public var ixWzskVReqitmode: Int
		public var latency: Int
		public var shortMenu: String
		public var widthMenu: Int
		public var initdoneHeadbar: Bool
		public var initdonePre: Bool
		public var initdoneAdmin: Bool
		public var initdoneOp: Bool
		public var initdoneGlry: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVReqitmode: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskNav")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskNav"

			if valid {
				srefIxWzskVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVReqitmode", &mask, StatApp.IXWZSKVREQITMODE)
				ixWzskVReqitmode = VecWzskVReqitmode.getIx(srefIxWzskVReqitmode)
				latency = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "latency", &mask, StatApp.LATENCY)
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "shortMenu", &mask, StatApp.SHORTMENU)
				widthMenu = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "widthMenu", &mask, StatApp.WIDTHMENU)
				initdoneHeadbar = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneHeadbar", &mask, StatApp.INITDONEHEADBAR)
				initdonePre = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdonePre", &mask, StatApp.INITDONEPRE)
				initdoneAdmin = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneAdmin", &mask, StatApp.INITDONEADMIN)
				initdoneOp = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneOp", &mask, StatApp.INITDONEOP)
				initdoneGlry = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdoneGlry", &mask, StatApp.INITDONEGLRY)
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
			if initdonePre == comp.initdonePre {items.insert(StatApp.INITDONEPRE)}
			if initdoneAdmin == comp.initdoneAdmin {items.insert(StatApp.INITDONEADMIN)}
			if initdoneOp == comp.initdoneOp {items.insert(StatApp.INITDONEOP)}
			if initdoneGlry == comp.initdoneGlry {items.insert(StatApp.INITDONEGLRY)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVREQITMODE, StatApp.LATENCY, StatApp.SHORTMENU, StatApp.WIDTHMENU, StatApp.INITDONEHEADBAR, StatApp.INITDONEPRE, StatApp.INITDONEADMIN, StatApp.INITDONEOP, StatApp.INITDONEGLRY]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskNav)
	  */
	public class StatShr: Block {

		public static let SCRJREFDLGLOAINI: Int = 1
		public static let SCRJREFHEADBAR: Int = 2
		public static let SCRJREFPRE: Int = 3
		public static let PNLPREAVAIL: Int = 4
		public static let SCRJREFADMIN: Int = 5
		public static let PNLADMINAVAIL: Int = 6
		public static let SCRJREFOP: Int = 7
		public static let PNLOPAVAIL: Int = 8
		public static let SCRJREFGLRY: Int = 9
		public static let PNLGLRYAVAIL: Int = 10
		public static let MITSESSPSAVAIL: Int = 11
		public static let MSPCRD1AVAIL: Int = 12
		public static let MITCRDUSGAVAIL: Int = 13
		public static let MITCRDUSRAVAIL: Int = 14
		public static let MITCRDPRSAVAIL: Int = 15
		public static let MITCRDSCFAVAIL: Int = 16
		public static let MSPCRD2AVAIL: Int = 17
		public static let MITCRDLLVAVAIL: Int = 18
		public static let MITCRDLIVAVAIL: Int = 19
		public static let MSPCRD3AVAIL: Int = 20
		public static let MITCRDOGRAVAIL: Int = 21
		public static let MITCRDOBJAVAIL: Int = 22
		public static let MITCRDSESAVAIL: Int = 23
		public static let MITCRDSHTAVAIL: Int = 24
		public static let MITCRDFILAVAIL: Int = 25
		public static let MSPAPP2AVAIL: Int = 26
		public static let MITAPPLOIAVAIL: Int = 27

		public init(
					_ scrJrefDlgloaini: String = ""
					, _ scrJrefHeadbar: String = ""
					, _ scrJrefPre: String = ""
					, _ pnlpreAvail: Bool = false
					, _ scrJrefAdmin: String = ""
					, _ pnladminAvail: Bool = false
					, _ scrJrefOp: String = ""
					, _ pnlopAvail: Bool = false
					, _ scrJrefGlry: String = ""
					, _ pnlglryAvail: Bool = false
					, _ MitSesSpsAvail: Bool = false
					, _ MspCrd1Avail: Bool = false
					, _ MitCrdUsgAvail: Bool = false
					, _ MitCrdUsrAvail: Bool = false
					, _ MitCrdPrsAvail: Bool = false
					, _ MitCrdScfAvail: Bool = false
					, _ MspCrd2Avail: Bool = false
					, _ MitCrdLlvAvail: Bool = false
					, _ MitCrdLivAvail: Bool = false
					, _ MspCrd3Avail: Bool = false
					, _ MitCrdOgrAvail: Bool = false
					, _ MitCrdObjAvail: Bool = false
					, _ MitCrdSesAvail: Bool = false
					, _ MitCrdShtAvail: Bool = false
					, _ MitCrdFilAvail: Bool = false
					, _ MspApp2Avail: Bool = false
					, _ MitAppLoiAvail: Bool = false
				) {
			self.scrJrefDlgloaini = scrJrefDlgloaini
			self.scrJrefHeadbar = scrJrefHeadbar
			self.scrJrefPre = scrJrefPre
			self.pnlpreAvail = pnlpreAvail
			self.scrJrefAdmin = scrJrefAdmin
			self.pnladminAvail = pnladminAvail
			self.scrJrefOp = scrJrefOp
			self.pnlopAvail = pnlopAvail
			self.scrJrefGlry = scrJrefGlry
			self.pnlglryAvail = pnlglryAvail
			self.MitSesSpsAvail = MitSesSpsAvail
			self.MspCrd1Avail = MspCrd1Avail
			self.MitCrdUsgAvail = MitCrdUsgAvail
			self.MitCrdUsrAvail = MitCrdUsrAvail
			self.MitCrdPrsAvail = MitCrdPrsAvail
			self.MitCrdScfAvail = MitCrdScfAvail
			self.MspCrd2Avail = MspCrd2Avail
			self.MitCrdLlvAvail = MitCrdLlvAvail
			self.MitCrdLivAvail = MitCrdLivAvail
			self.MspCrd3Avail = MspCrd3Avail
			self.MitCrdOgrAvail = MitCrdOgrAvail
			self.MitCrdObjAvail = MitCrdObjAvail
			self.MitCrdSesAvail = MitCrdSesAvail
			self.MitCrdShtAvail = MitCrdShtAvail
			self.MitCrdFilAvail = MitCrdFilAvail
			self.MspApp2Avail = MspApp2Avail
			self.MitAppLoiAvail = MitAppLoiAvail

			super.init()

			mask = [StatShr.SCRJREFDLGLOAINI, StatShr.SCRJREFHEADBAR, StatShr.SCRJREFPRE, StatShr.PNLPREAVAIL, StatShr.SCRJREFADMIN, StatShr.PNLADMINAVAIL, StatShr.SCRJREFOP, StatShr.PNLOPAVAIL, StatShr.SCRJREFGLRY, StatShr.PNLGLRYAVAIL, StatShr.MITSESSPSAVAIL, StatShr.MSPCRD1AVAIL, StatShr.MITCRDUSGAVAIL, StatShr.MITCRDUSRAVAIL, StatShr.MITCRDPRSAVAIL, StatShr.MITCRDSCFAVAIL, StatShr.MSPCRD2AVAIL, StatShr.MITCRDLLVAVAIL, StatShr.MITCRDLIVAVAIL, StatShr.MSPCRD3AVAIL, StatShr.MITCRDOGRAVAIL, StatShr.MITCRDOBJAVAIL, StatShr.MITCRDSESAVAIL, StatShr.MITCRDSHTAVAIL, StatShr.MITCRDFILAVAIL, StatShr.MSPAPP2AVAIL, StatShr.MITAPPLOIAVAIL]
		}

		public var scrJrefDlgloaini: String
		public var scrJrefHeadbar: String
		public var scrJrefPre: String
		public var pnlpreAvail: Bool
		public var scrJrefAdmin: String
		public var pnladminAvail: Bool
		public var scrJrefOp: String
		public var pnlopAvail: Bool
		public var scrJrefGlry: String
		public var pnlglryAvail: Bool
		public var MitSesSpsAvail: Bool
		public var MspCrd1Avail: Bool
		public var MitCrdUsgAvail: Bool
		public var MitCrdUsrAvail: Bool
		public var MitCrdPrsAvail: Bool
		public var MitCrdScfAvail: Bool
		public var MspCrd2Avail: Bool
		public var MitCrdLlvAvail: Bool
		public var MitCrdLivAvail: Bool
		public var MspCrd3Avail: Bool
		public var MitCrdOgrAvail: Bool
		public var MitCrdObjAvail: Bool
		public var MitCrdSesAvail: Bool
		public var MitCrdShtAvail: Bool
		public var MitCrdFilAvail: Bool
		public var MspApp2Avail: Bool
		public var MitAppLoiAvail: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskNav")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskNav"

			if valid {
				scrJrefDlgloaini = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefDlgloaini", &mask, StatShr.SCRJREFDLGLOAINI)
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefHeadbar", &mask, StatShr.SCRJREFHEADBAR)
				scrJrefPre = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefPre", &mask, StatShr.SCRJREFPRE)
				pnlpreAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnlpreAvail", &mask, StatShr.PNLPREAVAIL)
				scrJrefAdmin = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefAdmin", &mask, StatShr.SCRJREFADMIN)
				pnladminAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnladminAvail", &mask, StatShr.PNLADMINAVAIL)
				scrJrefOp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefOp", &mask, StatShr.SCRJREFOP)
				pnlopAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnlopAvail", &mask, StatShr.PNLOPAVAIL)
				scrJrefGlry = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefGlry", &mask, StatShr.SCRJREFGLRY)
				pnlglryAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "pnlglryAvail", &mask, StatShr.PNLGLRYAVAIL)
				MitSesSpsAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitSesSpsAvail", &mask, StatShr.MITSESSPSAVAIL)
				MspCrd1Avail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MspCrd1Avail", &mask, StatShr.MSPCRD1AVAIL)
				MitCrdUsgAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdUsgAvail", &mask, StatShr.MITCRDUSGAVAIL)
				MitCrdUsrAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdUsrAvail", &mask, StatShr.MITCRDUSRAVAIL)
				MitCrdPrsAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdPrsAvail", &mask, StatShr.MITCRDPRSAVAIL)
				MitCrdScfAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdScfAvail", &mask, StatShr.MITCRDSCFAVAIL)
				MspCrd2Avail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MspCrd2Avail", &mask, StatShr.MSPCRD2AVAIL)
				MitCrdLlvAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdLlvAvail", &mask, StatShr.MITCRDLLVAVAIL)
				MitCrdLivAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdLivAvail", &mask, StatShr.MITCRDLIVAVAIL)
				MspCrd3Avail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MspCrd3Avail", &mask, StatShr.MSPCRD3AVAIL)
				MitCrdOgrAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdOgrAvail", &mask, StatShr.MITCRDOGRAVAIL)
				MitCrdObjAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdObjAvail", &mask, StatShr.MITCRDOBJAVAIL)
				MitCrdSesAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdSesAvail", &mask, StatShr.MITCRDSESAVAIL)
				MitCrdShtAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdShtAvail", &mask, StatShr.MITCRDSHTAVAIL)
				MitCrdFilAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitCrdFilAvail", &mask, StatShr.MITCRDFILAVAIL)
				MspApp2Avail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MspApp2Avail", &mask, StatShr.MSPAPP2AVAIL)
				MitAppLoiAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "MitAppLoiAvail", &mask, StatShr.MITAPPLOIAVAIL)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if scrJrefDlgloaini == comp.scrJrefDlgloaini {items.insert(StatShr.SCRJREFDLGLOAINI)}
			if scrJrefHeadbar == comp.scrJrefHeadbar {items.insert(StatShr.SCRJREFHEADBAR)}
			if scrJrefPre == comp.scrJrefPre {items.insert(StatShr.SCRJREFPRE)}
			if pnlpreAvail == comp.pnlpreAvail {items.insert(StatShr.PNLPREAVAIL)}
			if scrJrefAdmin == comp.scrJrefAdmin {items.insert(StatShr.SCRJREFADMIN)}
			if pnladminAvail == comp.pnladminAvail {items.insert(StatShr.PNLADMINAVAIL)}
			if scrJrefOp == comp.scrJrefOp {items.insert(StatShr.SCRJREFOP)}
			if pnlopAvail == comp.pnlopAvail {items.insert(StatShr.PNLOPAVAIL)}
			if scrJrefGlry == comp.scrJrefGlry {items.insert(StatShr.SCRJREFGLRY)}
			if pnlglryAvail == comp.pnlglryAvail {items.insert(StatShr.PNLGLRYAVAIL)}
			if MitSesSpsAvail == comp.MitSesSpsAvail {items.insert(StatShr.MITSESSPSAVAIL)}
			if MspCrd1Avail == comp.MspCrd1Avail {items.insert(StatShr.MSPCRD1AVAIL)}
			if MitCrdUsgAvail == comp.MitCrdUsgAvail {items.insert(StatShr.MITCRDUSGAVAIL)}
			if MitCrdUsrAvail == comp.MitCrdUsrAvail {items.insert(StatShr.MITCRDUSRAVAIL)}
			if MitCrdPrsAvail == comp.MitCrdPrsAvail {items.insert(StatShr.MITCRDPRSAVAIL)}
			if MitCrdScfAvail == comp.MitCrdScfAvail {items.insert(StatShr.MITCRDSCFAVAIL)}
			if MspCrd2Avail == comp.MspCrd2Avail {items.insert(StatShr.MSPCRD2AVAIL)}
			if MitCrdLlvAvail == comp.MitCrdLlvAvail {items.insert(StatShr.MITCRDLLVAVAIL)}
			if MitCrdLivAvail == comp.MitCrdLivAvail {items.insert(StatShr.MITCRDLIVAVAIL)}
			if MspCrd3Avail == comp.MspCrd3Avail {items.insert(StatShr.MSPCRD3AVAIL)}
			if MitCrdOgrAvail == comp.MitCrdOgrAvail {items.insert(StatShr.MITCRDOGRAVAIL)}
			if MitCrdObjAvail == comp.MitCrdObjAvail {items.insert(StatShr.MITCRDOBJAVAIL)}
			if MitCrdSesAvail == comp.MitCrdSesAvail {items.insert(StatShr.MITCRDSESAVAIL)}
			if MitCrdShtAvail == comp.MitCrdShtAvail {items.insert(StatShr.MITCRDSHTAVAIL)}
			if MitCrdFilAvail == comp.MitCrdFilAvail {items.insert(StatShr.MITCRDFILAVAIL)}
			if MspApp2Avail == comp.MspApp2Avail {items.insert(StatShr.MSPAPP2AVAIL)}
			if MitAppLoiAvail == comp.MitAppLoiAvail {items.insert(StatShr.MITAPPLOIAVAIL)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.SCRJREFDLGLOAINI, StatShr.SCRJREFHEADBAR, StatShr.SCRJREFPRE, StatShr.PNLPREAVAIL, StatShr.SCRJREFADMIN, StatShr.PNLADMINAVAIL, StatShr.SCRJREFOP, StatShr.PNLOPAVAIL, StatShr.SCRJREFGLRY, StatShr.PNLGLRYAVAIL, StatShr.MITSESSPSAVAIL, StatShr.MSPCRD1AVAIL, StatShr.MITCRDUSGAVAIL, StatShr.MITCRDUSRAVAIL, StatShr.MITCRDPRSAVAIL, StatShr.MITCRDSCFAVAIL, StatShr.MSPCRD2AVAIL, StatShr.MITCRDLLVAVAIL, StatShr.MITCRDLIVAVAIL, StatShr.MSPCRD3AVAIL, StatShr.MITCRDOGRAVAIL, StatShr.MITCRDOBJAVAIL, StatShr.MITCRDSESAVAIL, StatShr.MITCRDSHTAVAIL, StatShr.MITCRDFILAVAIL, StatShr.MSPAPP2AVAIL, StatShr.MITAPPLOIAVAIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskNav)
	  */
	public class Tag: Block {

		public static let MITAPPABT: Int = 1
		public static let MRLAPPHLP: Int = 2
		public static let MITSESSPS: Int = 3
		public static let MITSESTRM: Int = 4
		public static let MITCRDUSG: Int = 5
		public static let MITCRDUSR: Int = 6
		public static let MITCRDPRS: Int = 7
		public static let MITCRDSCF: Int = 8
		public static let MITCRDLLV: Int = 9
		public static let MITCRDLIV: Int = 10
		public static let MITCRDOGR: Int = 11
		public static let MITCRDOBJ: Int = 12
		public static let MITCRDSES: Int = 13
		public static let MITCRDSHT: Int = 14
		public static let MITCRDFIL: Int = 15
		public static let MITAPPLOI: Int = 16

		public init(
					_ MitAppAbt: String = ""
					, _ MrlAppHlp: String = ""
					, _ MitSesSps: String = ""
					, _ MitSesTrm: String = ""
					, _ MitCrdUsg: String = ""
					, _ MitCrdUsr: String = ""
					, _ MitCrdPrs: String = ""
					, _ MitCrdScf: String = ""
					, _ MitCrdLlv: String = ""
					, _ MitCrdLiv: String = ""
					, _ MitCrdOgr: String = ""
					, _ MitCrdObj: String = ""
					, _ MitCrdSes: String = ""
					, _ MitCrdSht: String = ""
					, _ MitCrdFil: String = ""
					, _ MitAppLoi: String = ""
				) {
			self.MitAppAbt = MitAppAbt
			self.MrlAppHlp = MrlAppHlp
			self.MitSesSps = MitSesSps
			self.MitSesTrm = MitSesTrm
			self.MitCrdUsg = MitCrdUsg
			self.MitCrdUsr = MitCrdUsr
			self.MitCrdPrs = MitCrdPrs
			self.MitCrdScf = MitCrdScf
			self.MitCrdLlv = MitCrdLlv
			self.MitCrdLiv = MitCrdLiv
			self.MitCrdOgr = MitCrdOgr
			self.MitCrdObj = MitCrdObj
			self.MitCrdSes = MitCrdSes
			self.MitCrdSht = MitCrdSht
			self.MitCrdFil = MitCrdFil
			self.MitAppLoi = MitAppLoi

			super.init()

			mask = [Tag.MITAPPABT, Tag.MRLAPPHLP, Tag.MITSESSPS, Tag.MITSESTRM, Tag.MITCRDUSG, Tag.MITCRDUSR, Tag.MITCRDPRS, Tag.MITCRDSCF, Tag.MITCRDLLV, Tag.MITCRDLIV, Tag.MITCRDOGR, Tag.MITCRDOBJ, Tag.MITCRDSES, Tag.MITCRDSHT, Tag.MITCRDFIL, Tag.MITAPPLOI]
		}

		public var MitAppAbt: String
		public var MrlAppHlp: String
		public var MitSesSps: String
		public var MitSesTrm: String
		public var MitCrdUsg: String
		public var MitCrdUsr: String
		public var MitCrdPrs: String
		public var MitCrdScf: String
		public var MitCrdLlv: String
		public var MitCrdLiv: String
		public var MitCrdOgr: String
		public var MitCrdObj: String
		public var MitCrdSes: String
		public var MitCrdSht: String
		public var MitCrdFil: String
		public var MitAppLoi: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskNav")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskNav"

			if valid {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitAppAbt", &mask, Tag.MITAPPABT)
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MrlAppHlp", &mask, Tag.MRLAPPHLP)
				MitSesSps = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitSesSps", &mask, Tag.MITSESSPS)
				MitSesTrm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitSesTrm", &mask, Tag.MITSESTRM)
				MitCrdUsg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdUsg", &mask, Tag.MITCRDUSG)
				MitCrdUsr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdUsr", &mask, Tag.MITCRDUSR)
				MitCrdPrs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdPrs", &mask, Tag.MITCRDPRS)
				MitCrdScf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdScf", &mask, Tag.MITCRDSCF)
				MitCrdLlv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdLlv", &mask, Tag.MITCRDLLV)
				MitCrdLiv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdLiv", &mask, Tag.MITCRDLIV)
				MitCrdOgr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdOgr", &mask, Tag.MITCRDOGR)
				MitCrdObj = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdObj", &mask, Tag.MITCRDOBJ)
				MitCrdSes = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdSes", &mask, Tag.MITCRDSES)
				MitCrdSht = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdSht", &mask, Tag.MITCRDSHT)
				MitCrdFil = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitCrdFil", &mask, Tag.MITCRDFIL)
				MitAppLoi = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "MitAppLoi", &mask, Tag.MITAPPLOI)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if MitAppAbt == comp.MitAppAbt {items.insert(Tag.MITAPPABT)}
			if MrlAppHlp == comp.MrlAppHlp {items.insert(Tag.MRLAPPHLP)}
			if MitSesSps == comp.MitSesSps {items.insert(Tag.MITSESSPS)}
			if MitSesTrm == comp.MitSesTrm {items.insert(Tag.MITSESTRM)}
			if MitCrdUsg == comp.MitCrdUsg {items.insert(Tag.MITCRDUSG)}
			if MitCrdUsr == comp.MitCrdUsr {items.insert(Tag.MITCRDUSR)}
			if MitCrdPrs == comp.MitCrdPrs {items.insert(Tag.MITCRDPRS)}
			if MitCrdScf == comp.MitCrdScf {items.insert(Tag.MITCRDSCF)}
			if MitCrdLlv == comp.MitCrdLlv {items.insert(Tag.MITCRDLLV)}
			if MitCrdLiv == comp.MitCrdLiv {items.insert(Tag.MITCRDLIV)}
			if MitCrdOgr == comp.MitCrdOgr {items.insert(Tag.MITCRDOGR)}
			if MitCrdObj == comp.MitCrdObj {items.insert(Tag.MITCRDOBJ)}
			if MitCrdSes == comp.MitCrdSes {items.insert(Tag.MITCRDSES)}
			if MitCrdSht == comp.MitCrdSht {items.insert(Tag.MITCRDSHT)}
			if MitCrdFil == comp.MitCrdFil {items.insert(Tag.MITCRDFIL)}
			if MitAppLoi == comp.MitAppLoi {items.insert(Tag.MITAPPLOI)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.MITAPPABT, Tag.MRLAPPHLP, Tag.MITSESSPS, Tag.MITSESTRM, Tag.MITCRDUSG, Tag.MITCRDUSR, Tag.MITCRDPRS, Tag.MITCRDSCF, Tag.MITCRDLLV, Tag.MITCRDLIV, Tag.MITCRDOGR, Tag.MITCRDOBJ, Tag.MITCRDSES, Tag.MITCRDSHT, Tag.MITCRDFIL, Tag.MITAPPLOI]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskNavDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKNAVDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskNavDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskNavData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTINF: Int = 2
		public static let FEEDFSGE: Int = 3
		public static let STATAPP: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKNAVDATA)
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskNavData")}
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
