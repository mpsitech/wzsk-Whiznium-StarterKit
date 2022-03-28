/**
  * \file PnlWzskPrsDetail.swift
  * Swift API code for job PnlWzskPrsDetail
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskPrsDetail
	*/
public class PnlWzskPrsDetail {
	/**
		* VecVDo (full: VecVWzskPrsDetailDo)
		*/
	public class VecVDo {

		public static let BUTSAVECLICK: Int = 1
		public static let BUTJEDITCLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butsaveclick" {return BUTSAVECLICK}
			if s == "butjeditclick" {return BUTJEDITCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTSAVECLICK {return "ButSaveClick"}
			if ix == BUTJEDITCLICK {return "ButJEditClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskPrsDetail)
	  */
	public class ContIac: Block {

		public static let TXFTIT: Int = 1
		public static let TXFFNM: Int = 2
		public static let NUMFPUPJ: Int = 3
		public static let NUMSFLSTDRV: Int = 4
		public static let NUMFPUPSEX: Int = 5
		public static let TXFTEL: Int = 6
		public static let TXFEML: Int = 7
		public static let TXFSAL: Int = 8

		public init(
					_ TxfTit: String = ""
					, _ TxfFnm: String = ""
					, _ numFPupJ: Int = 0
					, _ numsFLstDrv: [UInt32] = [UInt32]()
					, _ numFPupSex: Int = 0
					, _ TxfTel: String = ""
					, _ TxfEml: String = ""
					, _ TxfSal: String = ""
				) {
			self.TxfTit = TxfTit
			self.TxfFnm = TxfFnm
			self.numFPupJ = numFPupJ
			self.numsFLstDrv = numsFLstDrv
			self.numFPupSex = numFPupSex
			self.TxfTel = TxfTel
			self.TxfEml = TxfEml
			self.TxfSal = TxfSal

			super.init()

			mask = [ContIac.TXFTIT, ContIac.TXFFNM, ContIac.NUMFPUPJ, ContIac.NUMSFLSTDRV, ContIac.NUMFPUPSEX, ContIac.TXFTEL, ContIac.TXFEML, ContIac.TXFSAL]
		}

		public var TxfTit: String
		public var TxfFnm: String
		public var numFPupJ: Int
		public var numsFLstDrv: [UInt32]
		public var numFPupSex: Int
		public var TxfTel: String
		public var TxfEml: String
		public var TxfSal: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskPrsDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskPrsDetail"

			if valid {
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfTit", &mask, ContIac.TXFTIT)
				TxfFnm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfFnm", &mask, ContIac.TXFFNM)
				numFPupJ = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupJ", &mask, ContIac.NUMFPUPJ)
				numsFLstDrv = Xmlio.extractUintvecAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numsFLstDrv", &mask, ContIac.NUMSFLSTDRV)
				numFPupSex = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupSex", &mask, ContIac.NUMFPUPSEX)
				TxfTel = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfTel", &mask, ContIac.TXFTEL)
				TxfEml = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfEml", &mask, ContIac.TXFEML)
				TxfSal = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfSal", &mask, ContIac.TXFSAL)
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
			if tag == nil {tag = "ContIacWzskPrsDetail"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskPrsDetail"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFnm", TxfFnm)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupJ", numFPupJ)
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstDrv", numsFLstDrv)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupSex", numFPupSex)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTel", TxfTel)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfEml", TxfEml)
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSal", TxfSal)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxfTit == comp.TxfTit {items.insert(ContIac.TXFTIT)}
			if TxfFnm == comp.TxfFnm {items.insert(ContIac.TXFFNM)}
			if numFPupJ == comp.numFPupJ {items.insert(ContIac.NUMFPUPJ)}
			if Xmlio.compareUintvec(numsFLstDrv, comp.numsFLstDrv) {items.insert(ContIac.NUMSFLSTDRV)}
			if numFPupSex == comp.numFPupSex {items.insert(ContIac.NUMFPUPSEX)}
			if TxfTel == comp.TxfTel {items.insert(ContIac.TXFTEL)}
			if TxfEml == comp.TxfEml {items.insert(ContIac.TXFEML)}
			if TxfSal == comp.TxfSal {items.insert(ContIac.TXFSAL)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.TXFTIT, ContIac.TXFFNM, ContIac.NUMFPUPJ, ContIac.NUMSFLSTDRV, ContIac.NUMFPUPSEX, ContIac.TXFTEL, ContIac.TXFEML, ContIac.TXFSAL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskPrsDetail)
	  */
	public class ContInf: Block {

		public static let TXTLNM: Int = 1
		public static let TXTDRV: Int = 2

		public init(
					_ TxtLnm: String = ""
					, _ TxtDrv: String = ""
				) {
			self.TxtLnm = TxtLnm
			self.TxtDrv = TxtDrv

			super.init()

			mask = [ContInf.TXTLNM, ContInf.TXTDRV]
		}

		public var TxtLnm: String
		public var TxtDrv: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskPrsDetail")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskPrsDetail"

			if valid {
				TxtLnm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtLnm", &mask, ContInf.TXTLNM)
				TxtDrv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtDrv", &mask, ContInf.TXTDRV)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtLnm == comp.TxtLnm {items.insert(ContInf.TXTLNM)}
			if TxtDrv == comp.TxtDrv {items.insert(ContInf.TXTDRV)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.TXTLNM, ContInf.TXTDRV]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskPrsDetail)
	  */
	public class StatApp: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let LSTDRVALT: Int = 2
		public static let LSTDRVNUMFIRSTDISP: Int = 3

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ LstDrvAlt: Bool = false
					, _ LstDrvNumFirstdisp: Int = 0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.LstDrvAlt = LstDrvAlt
			self.LstDrvNumFirstdisp = LstDrvNumFirstdisp

			super.init()

			mask = [StatApp.IXWZSKVEXPSTATE, StatApp.LSTDRVALT, StatApp.LSTDRVNUMFIRSTDISP]
		}

		public var ixWzskVExpstate: Int
		public var LstDrvAlt: Bool
		public var LstDrvNumFirstdisp: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskPrsDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskPrsDetail"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatApp.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				LstDrvAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstDrvAlt", &mask, StatApp.LSTDRVALT)
				LstDrvNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstDrvNumFirstdisp", &mask, StatApp.LSTDRVNUMFIRSTDISP)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatApp.IXWZSKVEXPSTATE)}
			if LstDrvAlt == comp.LstDrvAlt {items.insert(StatApp.LSTDRVALT)}
			if LstDrvNumFirstdisp == comp.LstDrvNumFirstdisp {items.insert(StatApp.LSTDRVNUMFIRSTDISP)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVEXPSTATE, StatApp.LSTDRVALT, StatApp.LSTDRVNUMFIRSTDISP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskPrsDetail)
	  */
	public class StatShr: Block {

		public static let BUTSAVEAVAIL: Int = 1
		public static let BUTSAVEACTIVE: Int = 2
		public static let TXFTITACTIVE: Int = 3
		public static let TXFFNMACTIVE: Int = 4
		public static let PUPJACTIVE: Int = 5
		public static let BUTJEDITAVAIL: Int = 6
		public static let TXTLNMACTIVE: Int = 7
		public static let LSTDRVACTIVE: Int = 8
		public static let PUPSEXACTIVE: Int = 9
		public static let TXFTELACTIVE: Int = 10
		public static let TXFEMLACTIVE: Int = 11
		public static let TXFSALACTIVE: Int = 12

		public init(
					_ ButSaveAvail: Bool = false
					, _ ButSaveActive: Bool = false
					, _ TxfTitActive: Bool = false
					, _ TxfFnmActive: Bool = false
					, _ PupJActive: Bool = false
					, _ ButJEditAvail: Bool = false
					, _ TxtLnmActive: Bool = false
					, _ LstDrvActive: Bool = false
					, _ PupSexActive: Bool = false
					, _ TxfTelActive: Bool = false
					, _ TxfEmlActive: Bool = false
					, _ TxfSalActive: Bool = false
				) {
			self.ButSaveAvail = ButSaveAvail
			self.ButSaveActive = ButSaveActive
			self.TxfTitActive = TxfTitActive
			self.TxfFnmActive = TxfFnmActive
			self.PupJActive = PupJActive
			self.ButJEditAvail = ButJEditAvail
			self.TxtLnmActive = TxtLnmActive
			self.LstDrvActive = LstDrvActive
			self.PupSexActive = PupSexActive
			self.TxfTelActive = TxfTelActive
			self.TxfEmlActive = TxfEmlActive
			self.TxfSalActive = TxfSalActive

			super.init()

			mask = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXFTITACTIVE, StatShr.TXFFNMACTIVE, StatShr.PUPJACTIVE, StatShr.BUTJEDITAVAIL, StatShr.TXTLNMACTIVE, StatShr.LSTDRVACTIVE, StatShr.PUPSEXACTIVE, StatShr.TXFTELACTIVE, StatShr.TXFEMLACTIVE, StatShr.TXFSALACTIVE]
		}

		public var ButSaveAvail: Bool
		public var ButSaveActive: Bool
		public var TxfTitActive: Bool
		public var TxfFnmActive: Bool
		public var PupJActive: Bool
		public var ButJEditAvail: Bool
		public var TxtLnmActive: Bool
		public var LstDrvActive: Bool
		public var PupSexActive: Bool
		public var TxfTelActive: Bool
		public var TxfEmlActive: Bool
		public var TxfSalActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskPrsDetail")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskPrsDetail"

			if valid {
				ButSaveAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveAvail", &mask, StatShr.BUTSAVEAVAIL)
				ButSaveActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSaveActive", &mask, StatShr.BUTSAVEACTIVE)
				TxfTitActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfTitActive", &mask, StatShr.TXFTITACTIVE)
				TxfFnmActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfFnmActive", &mask, StatShr.TXFFNMACTIVE)
				PupJActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupJActive", &mask, StatShr.PUPJACTIVE)
				ButJEditAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButJEditAvail", &mask, StatShr.BUTJEDITAVAIL)
				TxtLnmActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtLnmActive", &mask, StatShr.TXTLNMACTIVE)
				LstDrvActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstDrvActive", &mask, StatShr.LSTDRVACTIVE)
				PupSexActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "PupSexActive", &mask, StatShr.PUPSEXACTIVE)
				TxfTelActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfTelActive", &mask, StatShr.TXFTELACTIVE)
				TxfEmlActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfEmlActive", &mask, StatShr.TXFEMLACTIVE)
				TxfSalActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxfSalActive", &mask, StatShr.TXFSALACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButSaveAvail == comp.ButSaveAvail {items.insert(StatShr.BUTSAVEAVAIL)}
			if ButSaveActive == comp.ButSaveActive {items.insert(StatShr.BUTSAVEACTIVE)}
			if TxfTitActive == comp.TxfTitActive {items.insert(StatShr.TXFTITACTIVE)}
			if TxfFnmActive == comp.TxfFnmActive {items.insert(StatShr.TXFFNMACTIVE)}
			if PupJActive == comp.PupJActive {items.insert(StatShr.PUPJACTIVE)}
			if ButJEditAvail == comp.ButJEditAvail {items.insert(StatShr.BUTJEDITAVAIL)}
			if TxtLnmActive == comp.TxtLnmActive {items.insert(StatShr.TXTLNMACTIVE)}
			if LstDrvActive == comp.LstDrvActive {items.insert(StatShr.LSTDRVACTIVE)}
			if PupSexActive == comp.PupSexActive {items.insert(StatShr.PUPSEXACTIVE)}
			if TxfTelActive == comp.TxfTelActive {items.insert(StatShr.TXFTELACTIVE)}
			if TxfEmlActive == comp.TxfEmlActive {items.insert(StatShr.TXFEMLACTIVE)}
			if TxfSalActive == comp.TxfSalActive {items.insert(StatShr.TXFSALACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTSAVEAVAIL, StatShr.BUTSAVEACTIVE, StatShr.TXFTITACTIVE, StatShr.TXFFNMACTIVE, StatShr.PUPJACTIVE, StatShr.BUTJEDITAVAIL, StatShr.TXTLNMACTIVE, StatShr.LSTDRVACTIVE, StatShr.PUPSEXACTIVE, StatShr.TXFTELACTIVE, StatShr.TXFEMLACTIVE, StatShr.TXFSALACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskPrsDetail)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTTIT: Int = 2
		public static let CPTFNM: Int = 3
		public static let CPTLNM: Int = 4
		public static let CPTDRV: Int = 5
		public static let CPTSEX: Int = 6
		public static let CPTTEL: Int = 7
		public static let CPTEML: Int = 8
		public static let CPTSAL: Int = 9

		public init(
					_ Cpt: String = ""
					, _ CptTit: String = ""
					, _ CptFnm: String = ""
					, _ CptLnm: String = ""
					, _ CptDrv: String = ""
					, _ CptSex: String = ""
					, _ CptTel: String = ""
					, _ CptEml: String = ""
					, _ CptSal: String = ""
				) {
			self.Cpt = Cpt
			self.CptTit = CptTit
			self.CptFnm = CptFnm
			self.CptLnm = CptLnm
			self.CptDrv = CptDrv
			self.CptSex = CptSex
			self.CptTel = CptTel
			self.CptEml = CptEml
			self.CptSal = CptSal

			super.init()

			mask = [Tag.CPT, Tag.CPTTIT, Tag.CPTFNM, Tag.CPTLNM, Tag.CPTDRV, Tag.CPTSEX, Tag.CPTTEL, Tag.CPTEML, Tag.CPTSAL]
		}

		public var Cpt: String
		public var CptTit: String
		public var CptFnm: String
		public var CptLnm: String
		public var CptDrv: String
		public var CptSex: String
		public var CptTel: String
		public var CptEml: String
		public var CptSal: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskPrsDetail")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskPrsDetail"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptTit", &mask, Tag.CPTTIT)
				CptFnm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptFnm", &mask, Tag.CPTFNM)
				CptLnm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLnm", &mask, Tag.CPTLNM)
				CptDrv = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptDrv", &mask, Tag.CPTDRV)
				CptSex = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSex", &mask, Tag.CPTSEX)
				CptTel = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptTel", &mask, Tag.CPTTEL)
				CptEml = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptEml", &mask, Tag.CPTEML)
				CptSal = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSal", &mask, Tag.CPTSAL)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptTit == comp.CptTit {items.insert(Tag.CPTTIT)}
			if CptFnm == comp.CptFnm {items.insert(Tag.CPTFNM)}
			if CptLnm == comp.CptLnm {items.insert(Tag.CPTLNM)}
			if CptDrv == comp.CptDrv {items.insert(Tag.CPTDRV)}
			if CptSex == comp.CptSex {items.insert(Tag.CPTSEX)}
			if CptTel == comp.CptTel {items.insert(Tag.CPTTEL)}
			if CptEml == comp.CptEml {items.insert(Tag.CPTEML)}
			if CptSal == comp.CptSal {items.insert(Tag.CPTSAL)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTTIT, Tag.CPTFNM, Tag.CPTLNM, Tag.CPTDRV, Tag.CPTSEX, Tag.CPTTEL, Tag.CPTEML, Tag.CPTSAL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskPrsDetailData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKPRSDETAILDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskPrsDetailData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskPrsDetailDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKPRSDETAILDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskPrsDetailDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskPrsDetailData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFLSTDRV: Int = 4
		public static let FEEDFPUPJ: Int = 5
		public static let FEEDFPUPSEX: Int = 6
		public static let STATAPP: Int = 7
		public static let STATSHR: Int = 8
		public static let TAG: Int = 9

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKPRSDETAILDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFLstDrv: Feed = Feed("FeedFLstDrv")
		public var feedFPupJ: Feed = Feed("FeedFPupJ")
		public var feedFPupSex: Feed = Feed("FeedFPupSex")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFLSTDRV) {ss.append("feedFLstDrv")}
			if has(DpchEngData.FEEDFPUPJ) {ss.append("feedFPupJ")}
			if has(DpchEngData.FEEDFPUPSEX) {ss.append("feedFPupSex")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskPrsDetailData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFLstDrv.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTDRV)}
				if feedFPupJ.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPJ)}
				if feedFPupSex.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPSEX)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFLstDrv = Feed("FeedFLstDrv")
				feedFPupJ = Feed("FeedFPupJ")
				feedFPupSex = Feed("FeedFPupSex")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
