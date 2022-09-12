/**
  * \file PnlWzskUsrDetail.swift
  * Swift API code for job PnlWzskUsrDetail
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskUsrDetail
	*/
public class PnlWzskUsrDetail {
	/**
		* VecVDo (full: VecVWzskUsrDetailDo)
		*/
	public class VecVDo {

		public static let BUTSAVECLICK: Int = 1
		public static let BUTPRSVIEWCLICK: Int = 2
		public static let BUTUSGVIEWCLICK: Int = 3
		public static let BUTJEDITCLICK: Int = 4

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butsaveclick" {return BUTSAVECLICK}
			if s == "butprsviewclick" {return BUTPRSVIEWCLICK}
			if s == "butusgviewclick" {return BUTUSGVIEWCLICK}
			if s == "butjeditclick" {return BUTJEDITCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTSAVECLICK {return "ButSaveClick"}
			if ix == BUTPRSVIEWCLICK {return "ButPrsViewClick"}
			if ix == BUTUSGVIEWCLICK {return "ButUsgViewClick"}
			if ix == BUTJEDITCLICK {return "ButJEditClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskUsrDetail)
	  */
	public class ContIac: Block {

		public static let NUMFPUPJ: Int = 1
		public static let NUMFPUPSTE: Int = 2
		public static let NUMFPUPLCL: Int = 3
		public static let NUMFPUPULV: Int = 4
		public static let TXFPWD: Int = 5
		public static let TXFFKY: Int = 6
		public static let TXFCMT: Int = 7

		public init(
					_ numFPupJ: Int = 0
					, _ numFPupSte: Int = 0
					, _ numFPupLcl: Int = 0
					, _ numFPupUlv: Int = 0
					, _ TxfPwd: String = ""
					, _ TxfFky: String = ""
					, _ TxfCmt: String = ""
				) {
			self.numFPupJ = numFPupJ
			self.numFPupSte = numFPupSte
			self.numFPupLcl = numFPupLcl
			self.numFPupUlv = numFPupUlv
			self.TxfPwd = TxfPwd
			self.TxfFky = TxfFky
			self.TxfCmt = TxfCmt

			super.init()

			mask = [ContIac.NUMFPUPJ, ContIac.NUMFPUPSTE, ContIac.NUMFPUPLCL, ContIac.NUMFPUPULV, ContIac.TXFPWD, ContIac.TXFFKY, ContIac.TXFCMT]
		}

		public var numFPupJ: Int
		public var numFPupSte: Int
		public var numFPupLcl: Int
		public var numFPupUlv: Int
		public var TxfPwd: String
		public var TxfFky: String
		public var TxfCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskUsrDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskUsrDetail"

			if valid {
				numFPupJ = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupJ", &mask, ContIac.NUMFPUPJ)
				numFPupSte = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupSte", &mask, ContIac.NUMFPUPSTE)
				numFPupLcl = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupLcl", &mask, ContIac.NUMFPUPLCL)
				numFPupUlv = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupUlv", &mask, ContIac.NUMFPUPULV)
				TxfPwd = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfPwd", &mask, ContIac.TXFPWD)
				TxfFky = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfFky", &mask, ContIac.TXFFKY)
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfCmt", &mask, ContIac.TXFCMT)
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
			if tag == nil {tag = "ContIacWzskUsrDetail"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskUsrDetail"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupJ", numFPupJ)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupSte", numFPupSte)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupLcl", numFPupLcl)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupUlv", numFPupUlv)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfPwd", TxfPwd)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFky", TxfFky)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFPupJ == comp.numFPupJ {items.insert(ContIac.NUMFPUPJ)}
			if numFPupSte == comp.numFPupSte {items.insert(ContIac.NUMFPUPSTE)}
			if numFPupLcl == comp.numFPupLcl {items.insert(ContIac.NUMFPUPLCL)}
			if numFPupUlv == comp.numFPupUlv {items.insert(ContIac.NUMFPUPULV)}
			if TxfPwd == comp.TxfPwd {items.insert(ContIac.TXFPWD)}
			if TxfFky == comp.TxfFky {items.insert(ContIac.TXFFKY)}
			if TxfCmt == comp.TxfCmt {items.insert(ContIac.TXFCMT)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFPUPJ, ContIac.NUMFPUPSTE, ContIac.NUMFPUPLCL, ContIac.NUMFPUPULV, ContIac.TXFPWD, ContIac.TXFFKY, ContIac.TXFCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskUsrDetail)
	  */
	public class ContInf: Block {

		public static let TXTPRS: Int = 1
		public static let TXTSRF: Int = 2
		public static let TXTUSG: Int = 3

		public init(
					_ TxtPrs: String = ""
					, _ TxtSrf: String = ""
					, _ TxtUsg: String = ""
				) {
			self.TxtPrs = TxtPrs
			self.TxtSrf = TxtSrf
			self.TxtUsg = TxtUsg

			super.init()

			mask = [ContInf.TXTPRS, ContInf.TXTSRF, ContInf.TXTUSG]
		}

		public var TxtPrs: String
		public var TxtSrf: String
		public var TxtUsg: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskUsrDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskUsrDetail"

			if valid {
				TxtPrs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtPrs", &mask, ContInf.TXTPRS)
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtSrf", &mask, ContInf.TXTSRF)
				TxtUsg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtUsg", &mask, ContInf.TXTUSG)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtPrs == comp.TxtPrs {items.insert(ContInf.TXTPRS)}
			if TxtSrf == comp.TxtSrf {items.insert(ContInf.TXTSRF)}
			if TxtUsg == comp.TxtUsg {items.insert(ContInf.TXTUSG)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTPRS, ContInf.TXTSRF, ContInf.TXTUSG]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskUsrDetail)
	  */
	public class StatApp: Block {

		public static let IXWZSKVEXPSTATE: Int = 1

		public init(
					_ ixWzskVExpstate: Int = 0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate

			super.init()

			mask = [StatApp.IXWZSKVEXPSTATE]
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskUsrDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskUsrDetail"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatApp.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatApp.IXWZSKVEXPSTATE)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVEXPSTATE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskUsrDetail)
	  */
	public class StatShr: Block {

		public static let BUTSAVEAVAIL: Int = 1
		public static let BUTSAVEACTIVE: Int = 2
		public static let TXTPRSACTIVE: Int = 3
		public static let BUTPRSVIEWAVAIL: Int = 4
		public static let BUTPRSVIEWACTIVE: Int = 5
		public static let TXTSRFACTIVE: Int = 6
		public static let TXTUSGACTIVE: Int = 7
		public static let BUTUSGVIEWAVAIL: Int = 8
		public static let BUTUSGVIEWACTIVE: Int = 9
		public static let PUPJACTIVE: Int = 10
		public static let BUTJEDITAVAIL: Int = 11
		public static let PUPSTEACTIVE: Int = 12
		public static let PUPLCLACTIVE: Int = 13
		public static let PUPULVACTIVE: Int = 14
		public static let TXFPWDACTIVE: Int = 15
		public static let TXFFKYACTIVE: Int = 16
		public static let TXFCMTACTIVE: Int = 17

		public init(
					_ ButSaveAvail: Bool = false
					, _ ButSaveActive: Bool = false
					, _ TxtPrsActive: Bool = false
					, _ ButPrsViewAvail: Bool = false
					, _ ButPrsViewActive: Bool = false
					, _ TxtSrfActive: Bool = false
					, _ TxtUsgActive: Bool = false
					, _ ButUsgViewAvail: Bool = false
					, _ ButUsgViewActive: Bool = false
					, _ PupJActive: Bool = false
					, _ ButJEditAvail: Bool = false
					, _ PupSteActive: Bool = false
					, _ PupLclActive: Bool = false
					, _ PupUlvActive: Bool = false
					, _ TxfPwdActive: Bool = false
					, _ TxfFkyActive: Bool = false
					, _ TxfCmtActive: Bool = false
				) {
			self.ButSaveAvail = ButSaveAvail
			self.ButSaveActive = ButSaveActive
			self.TxtPrsActive = TxtPrsActive
			self.ButPrsViewAvail = ButPrsViewAvail
			self.ButPrsViewActive = ButPrsViewActive
			self.TxtSrfActive = TxtSrfActive
			self.TxtUsgActive = TxtUsgActive
			self.ButUsgViewAvail = ButUsgViewAvail
			self.ButUsgViewActive = ButUsgViewActive
			self.PupJActive = PupJActive
			self.ButJEditAvail = ButJEditAvail
			self.PupSteActive = PupSteActive
			self.PupLclActive = PupLclActive
			self.PupUlvActive = PupUlvActive
			self.TxfPwdActive = TxfPwdActive
			self.TxfFkyActive = TxfFkyActive
			self.TxfCmtActive = TxfCmtActive

			super.init()

			mask = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXTPRSACTIVE, StatShr.BUTPRSVIEWAVAIL, StatShr.BUTPRSVIEWACTIVE, StatShr.TXTSRFACTIVE, StatShr.TXTUSGACTIVE, StatShr.BUTUSGVIEWAVAIL, StatShr.BUTUSGVIEWACTIVE, StatShr.PUPJACTIVE, StatShr.BUTJEDITAVAIL, StatShr.PUPSTEACTIVE, StatShr.PUPLCLACTIVE, StatShr.PUPULVACTIVE, StatShr.TXFPWDACTIVE, StatShr.TXFFKYACTIVE, StatShr.TXFCMTACTIVE]
		}

		public var ButSaveAvail: Bool
		public var ButSaveActive: Bool
		public var TxtPrsActive: Bool
		public var ButPrsViewAvail: Bool
		public var ButPrsViewActive: Bool
		public var TxtSrfActive: Bool
		public var TxtUsgActive: Bool
		public var ButUsgViewAvail: Bool
		public var ButUsgViewActive: Bool
		public var PupJActive: Bool
		public var ButJEditAvail: Bool
		public var PupSteActive: Bool
		public var PupLclActive: Bool
		public var PupUlvActive: Bool
		public var TxfPwdActive: Bool
		public var TxfFkyActive: Bool
		public var TxfCmtActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskUsrDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskUsrDetail"

			if valid {
				ButSaveAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveAvail", &mask, StatShr.BUTSAVEAVAIL)
				ButSaveActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveActive", &mask, StatShr.BUTSAVEACTIVE)
				TxtPrsActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtPrsActive", &mask, StatShr.TXTPRSACTIVE)
				ButPrsViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButPrsViewAvail", &mask, StatShr.BUTPRSVIEWAVAIL)
				ButPrsViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButPrsViewActive", &mask, StatShr.BUTPRSVIEWACTIVE)
				TxtSrfActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtSrfActive", &mask, StatShr.TXTSRFACTIVE)
				TxtUsgActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtUsgActive", &mask, StatShr.TXTUSGACTIVE)
				ButUsgViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButUsgViewAvail", &mask, StatShr.BUTUSGVIEWAVAIL)
				ButUsgViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButUsgViewActive", &mask, StatShr.BUTUSGVIEWACTIVE)
				PupJActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupJActive", &mask, StatShr.PUPJACTIVE)
				ButJEditAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButJEditAvail", &mask, StatShr.BUTJEDITAVAIL)
				PupSteActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupSteActive", &mask, StatShr.PUPSTEACTIVE)
				PupLclActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupLclActive", &mask, StatShr.PUPLCLACTIVE)
				PupUlvActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupUlvActive", &mask, StatShr.PUPULVACTIVE)
				TxfPwdActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfPwdActive", &mask, StatShr.TXFPWDACTIVE)
				TxfFkyActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfFkyActive", &mask, StatShr.TXFFKYACTIVE)
				TxfCmtActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfCmtActive", &mask, StatShr.TXFCMTACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButSaveAvail == comp.ButSaveAvail {items.insert(StatShr.BUTSAVEAVAIL)}
			if ButSaveActive == comp.ButSaveActive {items.insert(StatShr.BUTSAVEACTIVE)}
			if TxtPrsActive == comp.TxtPrsActive {items.insert(StatShr.TXTPRSACTIVE)}
			if ButPrsViewAvail == comp.ButPrsViewAvail {items.insert(StatShr.BUTPRSVIEWAVAIL)}
			if ButPrsViewActive == comp.ButPrsViewActive {items.insert(StatShr.BUTPRSVIEWACTIVE)}
			if TxtSrfActive == comp.TxtSrfActive {items.insert(StatShr.TXTSRFACTIVE)}
			if TxtUsgActive == comp.TxtUsgActive {items.insert(StatShr.TXTUSGACTIVE)}
			if ButUsgViewAvail == comp.ButUsgViewAvail {items.insert(StatShr.BUTUSGVIEWAVAIL)}
			if ButUsgViewActive == comp.ButUsgViewActive {items.insert(StatShr.BUTUSGVIEWACTIVE)}
			if PupJActive == comp.PupJActive {items.insert(StatShr.PUPJACTIVE)}
			if ButJEditAvail == comp.ButJEditAvail {items.insert(StatShr.BUTJEDITAVAIL)}
			if PupSteActive == comp.PupSteActive {items.insert(StatShr.PUPSTEACTIVE)}
			if PupLclActive == comp.PupLclActive {items.insert(StatShr.PUPLCLACTIVE)}
			if PupUlvActive == comp.PupUlvActive {items.insert(StatShr.PUPULVACTIVE)}
			if TxfPwdActive == comp.TxfPwdActive {items.insert(StatShr.TXFPWDACTIVE)}
			if TxfFkyActive == comp.TxfFkyActive {items.insert(StatShr.TXFFKYACTIVE)}
			if TxfCmtActive == comp.TxfCmtActive {items.insert(StatShr.TXFCMTACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXTPRSACTIVE, StatShr.BUTPRSVIEWAVAIL, StatShr.BUTPRSVIEWACTIVE, StatShr.TXTSRFACTIVE, StatShr.TXTUSGACTIVE, StatShr.BUTUSGVIEWAVAIL, StatShr.BUTUSGVIEWACTIVE, StatShr.PUPJACTIVE, StatShr.BUTJEDITAVAIL, StatShr.PUPSTEACTIVE, StatShr.PUPLCLACTIVE, StatShr.PUPULVACTIVE, StatShr.TXFPWDACTIVE, StatShr.TXFFKYACTIVE, StatShr.TXFCMTACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskUsrDetail)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTPRS: Int = 2
		public static let CPTSRF: Int = 3
		public static let CPTUSG: Int = 4
		public static let CPTSTE: Int = 5
		public static let CPTLCL: Int = 6
		public static let CPTULV: Int = 7
		public static let CPTPWD: Int = 8
		public static let CPTFKY: Int = 9
		public static let CPTCMT: Int = 10

		public init(
					_ Cpt: String = ""
					, _ CptPrs: String = ""
					, _ CptSrf: String = ""
					, _ CptUsg: String = ""
					, _ CptSte: String = ""
					, _ CptLcl: String = ""
					, _ CptUlv: String = ""
					, _ CptPwd: String = ""
					, _ CptFky: String = ""
					, _ CptCmt: String = ""
				) {
			self.Cpt = Cpt
			self.CptPrs = CptPrs
			self.CptSrf = CptSrf
			self.CptUsg = CptUsg
			self.CptSte = CptSte
			self.CptLcl = CptLcl
			self.CptUlv = CptUlv
			self.CptPwd = CptPwd
			self.CptFky = CptFky
			self.CptCmt = CptCmt

			super.init()

			mask = [Tag.CPT, Tag.CPTPRS, Tag.CPTSRF, Tag.CPTUSG, Tag.CPTSTE, Tag.CPTLCL, Tag.CPTULV, Tag.CPTPWD, Tag.CPTFKY, Tag.CPTCMT]
		}

		public var Cpt: String
		public var CptPrs: String
		public var CptSrf: String
		public var CptUsg: String
		public var CptSte: String
		public var CptLcl: String
		public var CptUlv: String
		public var CptPwd: String
		public var CptFky: String
		public var CptCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskUsrDetail")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskUsrDetail"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptPrs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPrs", &mask, Tag.CPTPRS)
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSrf", &mask, Tag.CPTSRF)
				CptUsg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptUsg", &mask, Tag.CPTUSG)
				CptSte = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSte", &mask, Tag.CPTSTE)
				CptLcl = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLcl", &mask, Tag.CPTLCL)
				CptUlv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptUlv", &mask, Tag.CPTULV)
				CptPwd = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPwd", &mask, Tag.CPTPWD)
				CptFky = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptFky", &mask, Tag.CPTFKY)
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCmt", &mask, Tag.CPTCMT)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptPrs == comp.CptPrs {items.insert(Tag.CPTPRS)}
			if CptSrf == comp.CptSrf {items.insert(Tag.CPTSRF)}
			if CptUsg == comp.CptUsg {items.insert(Tag.CPTUSG)}
			if CptSte == comp.CptSte {items.insert(Tag.CPTSTE)}
			if CptLcl == comp.CptLcl {items.insert(Tag.CPTLCL)}
			if CptUlv == comp.CptUlv {items.insert(Tag.CPTULV)}
			if CptPwd == comp.CptPwd {items.insert(Tag.CPTPWD)}
			if CptFky == comp.CptFky {items.insert(Tag.CPTFKY)}
			if CptCmt == comp.CptCmt {items.insert(Tag.CPTCMT)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTPRS, Tag.CPTSRF, Tag.CPTUSG, Tag.CPTSTE, Tag.CPTLCL, Tag.CPTULV, Tag.CPTPWD, Tag.CPTFKY, Tag.CPTCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskUsrDetailData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKUSRDETAILDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskUsrDetailData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskUsrDetailDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKUSRDETAILDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskUsrDetailDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskUsrDetailData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFPUPJ: Int = 4
		public static let FEEDFPUPLCL: Int = 5
		public static let FEEDFPUPSTE: Int = 6
		public static let FEEDFPUPULV: Int = 7
		public static let STATAPP: Int = 8
		public static let STATSHR: Int = 9
		public static let TAG: Int = 10

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKUSRDETAILDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFPupJ: Feed = Feed("FeedFPupJ")
		public var feedFPupLcl: Feed = Feed("FeedFPupLcl")
		public var feedFPupSte: Feed = Feed("FeedFPupSte")
		public var feedFPupUlv: Feed = Feed("FeedFPupUlv")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFPUPJ) {ss.append("feedFPupJ")}
			if has(DpchEngData.FEEDFPUPLCL) {ss.append("feedFPupLcl")}
			if has(DpchEngData.FEEDFPUPSTE) {ss.append("feedFPupSte")}
			if has(DpchEngData.FEEDFPUPULV) {ss.append("feedFPupUlv")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskUsrDetailData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFPupJ.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPJ)}
				if feedFPupLcl.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPLCL)}
				if feedFPupSte.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPSTE)}
				if feedFPupUlv.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPULV)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFPupJ = Feed("FeedFPupJ")
				feedFPupLcl = Feed("FeedFPupLcl")
				feedFPupSte = Feed("FeedFPupSte")
				feedFPupUlv = Feed("FeedFPupUlv")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
