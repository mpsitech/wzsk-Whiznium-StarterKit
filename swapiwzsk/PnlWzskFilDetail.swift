/**
  * \file PnlWzskFilDetail.swift
  * Swift API code for job PnlWzskFilDetail
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskFilDetail
	*/
public class PnlWzskFilDetail {
	/**
		* VecVDo (full: VecVWzskFilDetailDo)
		*/
	public class VecVDo {

		public static let BUTSAVECLICK: Int = 1
		public static let BUTCLUVIEWCLICK: Int = 2
		public static let BUTCLUCLUSTERCLICK: Int = 3
		public static let BUTCLUUNCLUSTERCLICK: Int = 4
		public static let BUTREUVIEWCLICK: Int = 5
		public static let BUTCNTEDITCLICK: Int = 6
		public static let BUTMIMEDITCLICK: Int = 7

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butsaveclick" {return BUTSAVECLICK}
			if s == "butcluviewclick" {return BUTCLUVIEWCLICK}
			if s == "butcluclusterclick" {return BUTCLUCLUSTERCLICK}
			if s == "butcluunclusterclick" {return BUTCLUUNCLUSTERCLICK}
			if s == "butreuviewclick" {return BUTREUVIEWCLICK}
			if s == "butcnteditclick" {return BUTCNTEDITCLICK}
			if s == "butmimeditclick" {return BUTMIMEDITCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTSAVECLICK {return "ButSaveClick"}
			if ix == BUTCLUVIEWCLICK {return "ButCluViewClick"}
			if ix == BUTCLUCLUSTERCLICK {return "ButCluClusterClick"}
			if ix == BUTCLUUNCLUSTERCLICK {return "ButCluUnclusterClick"}
			if ix == BUTREUVIEWCLICK {return "ButReuViewClick"}
			if ix == BUTCNTEDITCLICK {return "ButCntEditClick"}
			if ix == BUTMIMEDITCLICK {return "ButMimEditClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskFilDetail)
	  */
	public class ContIac: Block {

		public static let TXFFNM: Int = 1
		public static let NUMFLSTCLU: Int = 2
		public static let NUMFPUPRET: Int = 3
		public static let NUMFPUPCNT: Int = 4
		public static let TXFCNT: Int = 5
		public static let TXFACV: Int = 6
		public static let TXFANM: Int = 7
		public static let NUMFPUPMIM: Int = 8
		public static let TXFMIM: Int = 9
		public static let TXFSIZ: Int = 10
		public static let TXFCMT: Int = 11

		public init(
					_ TxfFnm: String = ""
					, _ numFLstClu: Int = 0
					, _ numFPupRet: Int = 0
					, _ numFPupCnt: Int = 0
					, _ TxfCnt: String = ""
					, _ TxfAcv: String = ""
					, _ TxfAnm: String = ""
					, _ numFPupMim: Int = 0
					, _ TxfMim: String = ""
					, _ TxfSiz: String = ""
					, _ TxfCmt: String = ""
				) {
			self.TxfFnm = TxfFnm
			self.numFLstClu = numFLstClu
			self.numFPupRet = numFPupRet
			self.numFPupCnt = numFPupCnt
			self.TxfCnt = TxfCnt
			self.TxfAcv = TxfAcv
			self.TxfAnm = TxfAnm
			self.numFPupMim = numFPupMim
			self.TxfMim = TxfMim
			self.TxfSiz = TxfSiz
			self.TxfCmt = TxfCmt

			super.init()

			mask = [ContIac.TXFFNM, ContIac.NUMFLSTCLU, ContIac.NUMFPUPRET, ContIac.NUMFPUPCNT, ContIac.TXFCNT, ContIac.TXFACV, ContIac.TXFANM, ContIac.NUMFPUPMIM, ContIac.TXFMIM, ContIac.TXFSIZ, ContIac.TXFCMT]
		}

		public var TxfFnm: String
		public var numFLstClu: Int
		public var numFPupRet: Int
		public var numFPupCnt: Int
		public var TxfCnt: String
		public var TxfAcv: String
		public var TxfAnm: String
		public var numFPupMim: Int
		public var TxfMim: String
		public var TxfSiz: String
		public var TxfCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskFilDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskFilDetail"

			if valid {
				TxfFnm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfFnm", &mask, ContIac.TXFFNM)
				numFLstClu = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstClu", &mask, ContIac.NUMFLSTCLU)
				numFPupRet = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupRet", &mask, ContIac.NUMFPUPRET)
				numFPupCnt = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupCnt", &mask, ContIac.NUMFPUPCNT)
				TxfCnt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfCnt", &mask, ContIac.TXFCNT)
				TxfAcv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfAcv", &mask, ContIac.TXFACV)
				TxfAnm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfAnm", &mask, ContIac.TXFANM)
				numFPupMim = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupMim", &mask, ContIac.NUMFPUPMIM)
				TxfMim = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfMim", &mask, ContIac.TXFMIM)
				TxfSiz = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfSiz", &mask, ContIac.TXFSIZ)
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
			if tag == nil {tag = "ContIacWzskFilDetail"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskFilDetail"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFnm", TxfFnm)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupCnt", numFPupCnt)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCnt", TxfCnt)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAcv", TxfAcv)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAnm", TxfAnm)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupMim", numFPupMim)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMim", TxfMim)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSiz", TxfSiz)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxfFnm == comp.TxfFnm {items.insert(ContIac.TXFFNM)}
			if numFLstClu == comp.numFLstClu {items.insert(ContIac.NUMFLSTCLU)}
			if numFPupRet == comp.numFPupRet {items.insert(ContIac.NUMFPUPRET)}
			if numFPupCnt == comp.numFPupCnt {items.insert(ContIac.NUMFPUPCNT)}
			if TxfCnt == comp.TxfCnt {items.insert(ContIac.TXFCNT)}
			if TxfAcv == comp.TxfAcv {items.insert(ContIac.TXFACV)}
			if TxfAnm == comp.TxfAnm {items.insert(ContIac.TXFANM)}
			if numFPupMim == comp.numFPupMim {items.insert(ContIac.NUMFPUPMIM)}
			if TxfMim == comp.TxfMim {items.insert(ContIac.TXFMIM)}
			if TxfSiz == comp.TxfSiz {items.insert(ContIac.TXFSIZ)}
			if TxfCmt == comp.TxfCmt {items.insert(ContIac.TXFCMT)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.TXFFNM, ContIac.NUMFLSTCLU, ContIac.NUMFPUPRET, ContIac.NUMFPUPCNT, ContIac.TXFCNT, ContIac.TXFACV, ContIac.TXFANM, ContIac.NUMFPUPMIM, ContIac.TXFMIM, ContIac.TXFSIZ, ContIac.TXFCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskFilDetail)
	  */
	public class ContInf: Block {

		public static let TXTCLU: Int = 1
		public static let TXTREU: Int = 2

		public init(
					_ TxtClu: String = ""
					, _ TxtReu: String = ""
				) {
			self.TxtClu = TxtClu
			self.TxtReu = TxtReu

			super.init()

			mask = [ContInf.TXTCLU, ContInf.TXTREU]
		}

		public var TxtClu: String
		public var TxtReu: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskFilDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskFilDetail"

			if valid {
				TxtClu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtClu", &mask, ContInf.TXTCLU)
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtReu", &mask, ContInf.TXTREU)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtClu == comp.TxtClu {items.insert(ContInf.TXTCLU)}
			if TxtReu == comp.TxtReu {items.insert(ContInf.TXTREU)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTCLU, ContInf.TXTREU]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskFilDetail)
	  */
	public class StatApp: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let LSTCLUALT: Int = 2
		public static let PUPCNTALT: Int = 3
		public static let PUPMIMALT: Int = 4
		public static let LSTCLUNUMFIRSTDISP: Int = 5

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ LstCluAlt: Bool = false
					, _ PupCntAlt: Bool = false
					, _ PupMimAlt: Bool = false
					, _ LstCluNumFirstdisp: Int = 0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.LstCluAlt = LstCluAlt
			self.PupCntAlt = PupCntAlt
			self.PupMimAlt = PupMimAlt
			self.LstCluNumFirstdisp = LstCluNumFirstdisp

			super.init()

			mask = [StatApp.IXWZSKVEXPSTATE, StatApp.LSTCLUALT, StatApp.PUPCNTALT, StatApp.PUPMIMALT, StatApp.LSTCLUNUMFIRSTDISP]
		}

		public var ixWzskVExpstate: Int
		public var LstCluAlt: Bool
		public var PupCntAlt: Bool
		public var PupMimAlt: Bool
		public var LstCluNumFirstdisp: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskFilDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskFilDetail"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatApp.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				LstCluAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstCluAlt", &mask, StatApp.LSTCLUALT)
				PupCntAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupCntAlt", &mask, StatApp.PUPCNTALT)
				PupMimAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupMimAlt", &mask, StatApp.PUPMIMALT)
				LstCluNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstCluNumFirstdisp", &mask, StatApp.LSTCLUNUMFIRSTDISP)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatApp.IXWZSKVEXPSTATE)}
			if LstCluAlt == comp.LstCluAlt {items.insert(StatApp.LSTCLUALT)}
			if PupCntAlt == comp.PupCntAlt {items.insert(StatApp.PUPCNTALT)}
			if PupMimAlt == comp.PupMimAlt {items.insert(StatApp.PUPMIMALT)}
			if LstCluNumFirstdisp == comp.LstCluNumFirstdisp {items.insert(StatApp.LSTCLUNUMFIRSTDISP)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVEXPSTATE, StatApp.LSTCLUALT, StatApp.PUPCNTALT, StatApp.PUPMIMALT, StatApp.LSTCLUNUMFIRSTDISP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskFilDetail)
	  */
	public class StatShr: Block {

		public static let TXFCNTVALID: Int = 1
		public static let TXFMIMVALID: Int = 2
		public static let BUTSAVEAVAIL: Int = 3
		public static let BUTSAVEACTIVE: Int = 4
		public static let TXFFNMACTIVE: Int = 5
		public static let LSTCLUACTIVE: Int = 6
		public static let BUTCLUVIEWACTIVE: Int = 7
		public static let BUTCLUCLUSTERAVAIL: Int = 8
		public static let BUTCLUUNCLUSTERAVAIL: Int = 9
		public static let TXTREUACTIVE: Int = 10
		public static let BUTREUVIEWAVAIL: Int = 11
		public static let BUTREUVIEWACTIVE: Int = 12
		public static let PUPCNTACTIVE: Int = 13
		public static let BUTCNTEDITAVAIL: Int = 14
		public static let TXFACVACTIVE: Int = 15
		public static let TXFANMACTIVE: Int = 16
		public static let PUPMIMACTIVE: Int = 17
		public static let BUTMIMEDITAVAIL: Int = 18
		public static let TXFSIZACTIVE: Int = 19
		public static let TXFCMTACTIVE: Int = 20

		public init(
					_ TxfCntValid: Bool = false
					, _ TxfMimValid: Bool = false
					, _ ButSaveAvail: Bool = false
					, _ ButSaveActive: Bool = false
					, _ TxfFnmActive: Bool = false
					, _ LstCluActive: Bool = false
					, _ ButCluViewActive: Bool = false
					, _ ButCluClusterAvail: Bool = false
					, _ ButCluUnclusterAvail: Bool = false
					, _ TxtReuActive: Bool = false
					, _ ButReuViewAvail: Bool = false
					, _ ButReuViewActive: Bool = false
					, _ PupCntActive: Bool = false
					, _ ButCntEditAvail: Bool = false
					, _ TxfAcvActive: Bool = false
					, _ TxfAnmActive: Bool = false
					, _ PupMimActive: Bool = false
					, _ ButMimEditAvail: Bool = false
					, _ TxfSizActive: Bool = false
					, _ TxfCmtActive: Bool = false
				) {
			self.TxfCntValid = TxfCntValid
			self.TxfMimValid = TxfMimValid
			self.ButSaveAvail = ButSaveAvail
			self.ButSaveActive = ButSaveActive
			self.TxfFnmActive = TxfFnmActive
			self.LstCluActive = LstCluActive
			self.ButCluViewActive = ButCluViewActive
			self.ButCluClusterAvail = ButCluClusterAvail
			self.ButCluUnclusterAvail = ButCluUnclusterAvail
			self.TxtReuActive = TxtReuActive
			self.ButReuViewAvail = ButReuViewAvail
			self.ButReuViewActive = ButReuViewActive
			self.PupCntActive = PupCntActive
			self.ButCntEditAvail = ButCntEditAvail
			self.TxfAcvActive = TxfAcvActive
			self.TxfAnmActive = TxfAnmActive
			self.PupMimActive = PupMimActive
			self.ButMimEditAvail = ButMimEditAvail
			self.TxfSizActive = TxfSizActive
			self.TxfCmtActive = TxfCmtActive

			super.init()

			mask = [StatShr.TXFCNTVALID, StatShr.TXFMIMVALID, StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXFFNMACTIVE, StatShr.LSTCLUACTIVE, StatShr.BUTCLUVIEWACTIVE, StatShr.BUTCLUCLUSTERAVAIL, StatShr.BUTCLUUNCLUSTERAVAIL, StatShr.TXTREUACTIVE, StatShr.BUTREUVIEWAVAIL, StatShr.BUTREUVIEWACTIVE, StatShr.PUPCNTACTIVE, StatShr.BUTCNTEDITAVAIL, StatShr.TXFACVACTIVE, StatShr.TXFANMACTIVE, StatShr.PUPMIMACTIVE, StatShr.BUTMIMEDITAVAIL, StatShr.TXFSIZACTIVE, StatShr.TXFCMTACTIVE]
		}

		public var TxfCntValid: Bool
		public var TxfMimValid: Bool
		public var ButSaveAvail: Bool
		public var ButSaveActive: Bool
		public var TxfFnmActive: Bool
		public var LstCluActive: Bool
		public var ButCluViewActive: Bool
		public var ButCluClusterAvail: Bool
		public var ButCluUnclusterAvail: Bool
		public var TxtReuActive: Bool
		public var ButReuViewAvail: Bool
		public var ButReuViewActive: Bool
		public var PupCntActive: Bool
		public var ButCntEditAvail: Bool
		public var TxfAcvActive: Bool
		public var TxfAnmActive: Bool
		public var PupMimActive: Bool
		public var ButMimEditAvail: Bool
		public var TxfSizActive: Bool
		public var TxfCmtActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskFilDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskFilDetail"

			if valid {
				TxfCntValid = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfCntValid", &mask, StatShr.TXFCNTVALID)
				TxfMimValid = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfMimValid", &mask, StatShr.TXFMIMVALID)
				ButSaveAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveAvail", &mask, StatShr.BUTSAVEAVAIL)
				ButSaveActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveActive", &mask, StatShr.BUTSAVEACTIVE)
				TxfFnmActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfFnmActive", &mask, StatShr.TXFFNMACTIVE)
				LstCluActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstCluActive", &mask, StatShr.LSTCLUACTIVE)
				ButCluViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButCluViewActive", &mask, StatShr.BUTCLUVIEWACTIVE)
				ButCluClusterAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButCluClusterAvail", &mask, StatShr.BUTCLUCLUSTERAVAIL)
				ButCluUnclusterAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButCluUnclusterAvail", &mask, StatShr.BUTCLUUNCLUSTERAVAIL)
				TxtReuActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtReuActive", &mask, StatShr.TXTREUACTIVE)
				ButReuViewAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButReuViewAvail", &mask, StatShr.BUTREUVIEWAVAIL)
				ButReuViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButReuViewActive", &mask, StatShr.BUTREUVIEWACTIVE)
				PupCntActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupCntActive", &mask, StatShr.PUPCNTACTIVE)
				ButCntEditAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButCntEditAvail", &mask, StatShr.BUTCNTEDITAVAIL)
				TxfAcvActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfAcvActive", &mask, StatShr.TXFACVACTIVE)
				TxfAnmActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfAnmActive", &mask, StatShr.TXFANMACTIVE)
				PupMimActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupMimActive", &mask, StatShr.PUPMIMACTIVE)
				ButMimEditAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButMimEditAvail", &mask, StatShr.BUTMIMEDITAVAIL)
				TxfSizActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfSizActive", &mask, StatShr.TXFSIZACTIVE)
				TxfCmtActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfCmtActive", &mask, StatShr.TXFCMTACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxfCntValid == comp.TxfCntValid {items.insert(StatShr.TXFCNTVALID)}
			if TxfMimValid == comp.TxfMimValid {items.insert(StatShr.TXFMIMVALID)}
			if ButSaveAvail == comp.ButSaveAvail {items.insert(StatShr.BUTSAVEAVAIL)}
			if ButSaveActive == comp.ButSaveActive {items.insert(StatShr.BUTSAVEACTIVE)}
			if TxfFnmActive == comp.TxfFnmActive {items.insert(StatShr.TXFFNMACTIVE)}
			if LstCluActive == comp.LstCluActive {items.insert(StatShr.LSTCLUACTIVE)}
			if ButCluViewActive == comp.ButCluViewActive {items.insert(StatShr.BUTCLUVIEWACTIVE)}
			if ButCluClusterAvail == comp.ButCluClusterAvail {items.insert(StatShr.BUTCLUCLUSTERAVAIL)}
			if ButCluUnclusterAvail == comp.ButCluUnclusterAvail {items.insert(StatShr.BUTCLUUNCLUSTERAVAIL)}
			if TxtReuActive == comp.TxtReuActive {items.insert(StatShr.TXTREUACTIVE)}
			if ButReuViewAvail == comp.ButReuViewAvail {items.insert(StatShr.BUTREUVIEWAVAIL)}
			if ButReuViewActive == comp.ButReuViewActive {items.insert(StatShr.BUTREUVIEWACTIVE)}
			if PupCntActive == comp.PupCntActive {items.insert(StatShr.PUPCNTACTIVE)}
			if ButCntEditAvail == comp.ButCntEditAvail {items.insert(StatShr.BUTCNTEDITAVAIL)}
			if TxfAcvActive == comp.TxfAcvActive {items.insert(StatShr.TXFACVACTIVE)}
			if TxfAnmActive == comp.TxfAnmActive {items.insert(StatShr.TXFANMACTIVE)}
			if PupMimActive == comp.PupMimActive {items.insert(StatShr.PUPMIMACTIVE)}
			if ButMimEditAvail == comp.ButMimEditAvail {items.insert(StatShr.BUTMIMEDITAVAIL)}
			if TxfSizActive == comp.TxfSizActive {items.insert(StatShr.TXFSIZACTIVE)}
			if TxfCmtActive == comp.TxfCmtActive {items.insert(StatShr.TXFCMTACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.TXFCNTVALID, StatShr.TXFMIMVALID, StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXFFNMACTIVE, StatShr.LSTCLUACTIVE, StatShr.BUTCLUVIEWACTIVE, StatShr.BUTCLUCLUSTERAVAIL, StatShr.BUTCLUUNCLUSTERAVAIL, StatShr.TXTREUACTIVE, StatShr.BUTREUVIEWAVAIL, StatShr.BUTREUVIEWACTIVE, StatShr.PUPCNTACTIVE, StatShr.BUTCNTEDITAVAIL, StatShr.TXFACVACTIVE, StatShr.TXFANMACTIVE, StatShr.PUPMIMACTIVE, StatShr.BUTMIMEDITAVAIL, StatShr.TXFSIZACTIVE, StatShr.TXFCMTACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskFilDetail)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTFNM: Int = 2
		public static let CPTCLU: Int = 3
		public static let CPTREU: Int = 4
		public static let CPTCNT: Int = 5
		public static let CPTACV: Int = 6
		public static let CPTANM: Int = 7
		public static let CPTMIM: Int = 8
		public static let CPTSIZ: Int = 9
		public static let CPTCMT: Int = 10

		public init(
					_ Cpt: String = ""
					, _ CptFnm: String = ""
					, _ CptClu: String = ""
					, _ CptReu: String = ""
					, _ CptCnt: String = ""
					, _ CptAcv: String = ""
					, _ CptAnm: String = ""
					, _ CptMim: String = ""
					, _ CptSiz: String = ""
					, _ CptCmt: String = ""
				) {
			self.Cpt = Cpt
			self.CptFnm = CptFnm
			self.CptClu = CptClu
			self.CptReu = CptReu
			self.CptCnt = CptCnt
			self.CptAcv = CptAcv
			self.CptAnm = CptAnm
			self.CptMim = CptMim
			self.CptSiz = CptSiz
			self.CptCmt = CptCmt

			super.init()

			mask = [Tag.CPT, Tag.CPTFNM, Tag.CPTCLU, Tag.CPTREU, Tag.CPTCNT, Tag.CPTACV, Tag.CPTANM, Tag.CPTMIM, Tag.CPTSIZ, Tag.CPTCMT]
		}

		public var Cpt: String
		public var CptFnm: String
		public var CptClu: String
		public var CptReu: String
		public var CptCnt: String
		public var CptAcv: String
		public var CptAnm: String
		public var CptMim: String
		public var CptSiz: String
		public var CptCmt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskFilDetail")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskFilDetail"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptFnm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptFnm", &mask, Tag.CPTFNM)
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptClu", &mask, Tag.CPTCLU)
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptReu", &mask, Tag.CPTREU)
				CptCnt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCnt", &mask, Tag.CPTCNT)
				CptAcv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptAcv", &mask, Tag.CPTACV)
				CptAnm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptAnm", &mask, Tag.CPTANM)
				CptMim = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptMim", &mask, Tag.CPTMIM)
				CptSiz = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSiz", &mask, Tag.CPTSIZ)
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCmt", &mask, Tag.CPTCMT)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptFnm == comp.CptFnm {items.insert(Tag.CPTFNM)}
			if CptClu == comp.CptClu {items.insert(Tag.CPTCLU)}
			if CptReu == comp.CptReu {items.insert(Tag.CPTREU)}
			if CptCnt == comp.CptCnt {items.insert(Tag.CPTCNT)}
			if CptAcv == comp.CptAcv {items.insert(Tag.CPTACV)}
			if CptAnm == comp.CptAnm {items.insert(Tag.CPTANM)}
			if CptMim == comp.CptMim {items.insert(Tag.CPTMIM)}
			if CptSiz == comp.CptSiz {items.insert(Tag.CPTSIZ)}
			if CptCmt == comp.CptCmt {items.insert(Tag.CPTCMT)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTFNM, Tag.CPTCLU, Tag.CPTREU, Tag.CPTCNT, Tag.CPTACV, Tag.CPTANM, Tag.CPTMIM, Tag.CPTSIZ, Tag.CPTCMT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskFilDetailData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKFILDETAILDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskFilDetailData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskFilDetailDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKFILDETAILDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskFilDetailDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskFilDetailData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFLSTCLU: Int = 4
		public static let FEEDFPUPCNT: Int = 5
		public static let FEEDFPUPMIM: Int = 6
		public static let FEEDFPUPRET: Int = 7
		public static let STATAPP: Int = 8
		public static let STATSHR: Int = 9
		public static let TAG: Int = 10

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKFILDETAILDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFLstClu: Feed = Feed("FeedFLstClu")
		public var feedFPupCnt: Feed = Feed("FeedFPupCnt")
		public var feedFPupMim: Feed = Feed("FeedFPupMim")
		public var feedFPupRet: Feed = Feed("FeedFPupRet")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFLSTCLU) {ss.append("feedFLstClu")}
			if has(DpchEngData.FEEDFPUPCNT) {ss.append("feedFPupCnt")}
			if has(DpchEngData.FEEDFPUPMIM) {ss.append("feedFPupMim")}
			if has(DpchEngData.FEEDFPUPRET) {ss.append("feedFPupRet")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskFilDetailData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFLstClu.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTCLU)}
				if feedFPupCnt.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPCNT)}
				if feedFPupMim.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPMIM)}
				if feedFPupRet.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPRET)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFLstClu = Feed("FeedFLstClu")
				feedFPupCnt = Feed("FeedFPupCnt")
				feedFPupMim = Feed("FeedFPupMim")
				feedFPupRet = Feed("FeedFPupRet")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
