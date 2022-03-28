/**
  * \file PnlWzskNavGlry.swift
  * Swift API code for job PnlWzskNavGlry
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskNavGlry
	*/
public class PnlWzskNavGlry {
	/**
		* VecVDo (full: VecVWzskNavGlryDo)
		*/
	public class VecVDo {

		public static let BUTOGRVIEWCLICK: Int = 1
		public static let BUTOGRNEWCRDCLICK: Int = 2
		public static let BUTOBJVIEWCLICK: Int = 3
		public static let BUTOBJNEWCRDCLICK: Int = 4
		public static let BUTSESVIEWCLICK: Int = 5
		public static let BUTSESNEWCRDCLICK: Int = 6
		public static let BUTSHTVIEWCLICK: Int = 7
		public static let BUTSHTNEWCRDCLICK: Int = 8
		public static let BUTFILVIEWCLICK: Int = 9
		public static let BUTFILNEWCRDCLICK: Int = 10

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butogrviewclick" {return BUTOGRVIEWCLICK}
			if s == "butogrnewcrdclick" {return BUTOGRNEWCRDCLICK}
			if s == "butobjviewclick" {return BUTOBJVIEWCLICK}
			if s == "butobjnewcrdclick" {return BUTOBJNEWCRDCLICK}
			if s == "butsesviewclick" {return BUTSESVIEWCLICK}
			if s == "butsesnewcrdclick" {return BUTSESNEWCRDCLICK}
			if s == "butshtviewclick" {return BUTSHTVIEWCLICK}
			if s == "butshtnewcrdclick" {return BUTSHTNEWCRDCLICK}
			if s == "butfilviewclick" {return BUTFILVIEWCLICK}
			if s == "butfilnewcrdclick" {return BUTFILNEWCRDCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTOGRVIEWCLICK {return "ButOgrViewClick"}
			if ix == BUTOGRNEWCRDCLICK {return "ButOgrNewcrdClick"}
			if ix == BUTOBJVIEWCLICK {return "ButObjViewClick"}
			if ix == BUTOBJNEWCRDCLICK {return "ButObjNewcrdClick"}
			if ix == BUTSESVIEWCLICK {return "ButSesViewClick"}
			if ix == BUTSESNEWCRDCLICK {return "ButSesNewcrdClick"}
			if ix == BUTSHTVIEWCLICK {return "ButShtViewClick"}
			if ix == BUTSHTNEWCRDCLICK {return "ButShtNewcrdClick"}
			if ix == BUTFILVIEWCLICK {return "ButFilViewClick"}
			if ix == BUTFILNEWCRDCLICK {return "ButFilNewcrdClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskNavGlry)
	  */
	public class ContIac: Block {

		public static let NUMFLSTOGR: Int = 1
		public static let NUMFLSTOBJ: Int = 2
		public static let NUMFLSTSES: Int = 3
		public static let NUMFLSTSHT: Int = 4
		public static let NUMFLSTFIL: Int = 5

		public init(
					_ numFLstOgr: Int = 0
					, _ numFLstObj: Int = 0
					, _ numFLstSes: Int = 0
					, _ numFLstSht: Int = 0
					, _ numFLstFil: Int = 0
				) {
			self.numFLstOgr = numFLstOgr
			self.numFLstObj = numFLstObj
			self.numFLstSes = numFLstSes
			self.numFLstSht = numFLstSht
			self.numFLstFil = numFLstFil

			super.init()

			mask = [ContIac.NUMFLSTOGR, ContIac.NUMFLSTOBJ, ContIac.NUMFLSTSES, ContIac.NUMFLSTSHT, ContIac.NUMFLSTFIL]
		}

		public var numFLstOgr: Int
		public var numFLstObj: Int
		public var numFLstSes: Int
		public var numFLstSht: Int
		public var numFLstFil: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskNavGlry")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskNavGlry"

			if valid {
				numFLstOgr = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstOgr", &mask, ContIac.NUMFLSTOGR)
				numFLstObj = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstObj", &mask, ContIac.NUMFLSTOBJ)
				numFLstSes = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstSes", &mask, ContIac.NUMFLSTSES)
				numFLstSht = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstSht", &mask, ContIac.NUMFLSTSHT)
				numFLstFil = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstFil", &mask, ContIac.NUMFLSTFIL)
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
			if tag == nil {tag = "ContIacWzskNavGlry"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskNavGlry"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstOgr", numFLstOgr)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstObj", numFLstObj)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstSes", numFLstSes)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstSht", numFLstSht)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstFil", numFLstFil)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFLstOgr == comp.numFLstOgr {items.insert(ContIac.NUMFLSTOGR)}
			if numFLstObj == comp.numFLstObj {items.insert(ContIac.NUMFLSTOBJ)}
			if numFLstSes == comp.numFLstSes {items.insert(ContIac.NUMFLSTSES)}
			if numFLstSht == comp.numFLstSht {items.insert(ContIac.NUMFLSTSHT)}
			if numFLstFil == comp.numFLstFil {items.insert(ContIac.NUMFLSTFIL)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFLSTOGR, ContIac.NUMFLSTOBJ, ContIac.NUMFLSTSES, ContIac.NUMFLSTSHT, ContIac.NUMFLSTFIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskNavGlry)
	  */
	public class StatApp: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let LSTOGRALT: Int = 2
		public static let LSTOBJALT: Int = 3
		public static let LSTSESALT: Int = 4
		public static let LSTSHTALT: Int = 5
		public static let LSTFILALT: Int = 6
		public static let LSTOGRNUMFIRSTDISP: Int = 7
		public static let LSTOBJNUMFIRSTDISP: Int = 8
		public static let LSTSESNUMFIRSTDISP: Int = 9
		public static let LSTSHTNUMFIRSTDISP: Int = 10
		public static let LSTFILNUMFIRSTDISP: Int = 11

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ LstOgrAlt: Bool = false
					, _ LstObjAlt: Bool = false
					, _ LstSesAlt: Bool = false
					, _ LstShtAlt: Bool = false
					, _ LstFilAlt: Bool = false
					, _ LstOgrNumFirstdisp: Int = 0
					, _ LstObjNumFirstdisp: Int = 0
					, _ LstSesNumFirstdisp: Int = 0
					, _ LstShtNumFirstdisp: Int = 0
					, _ LstFilNumFirstdisp: Int = 0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.LstOgrAlt = LstOgrAlt
			self.LstObjAlt = LstObjAlt
			self.LstSesAlt = LstSesAlt
			self.LstShtAlt = LstShtAlt
			self.LstFilAlt = LstFilAlt
			self.LstOgrNumFirstdisp = LstOgrNumFirstdisp
			self.LstObjNumFirstdisp = LstObjNumFirstdisp
			self.LstSesNumFirstdisp = LstSesNumFirstdisp
			self.LstShtNumFirstdisp = LstShtNumFirstdisp
			self.LstFilNumFirstdisp = LstFilNumFirstdisp

			super.init()

			mask = [StatApp.IXWZSKVEXPSTATE, StatApp.LSTOGRALT, StatApp.LSTOBJALT, StatApp.LSTSESALT, StatApp.LSTSHTALT, StatApp.LSTFILALT, StatApp.LSTOGRNUMFIRSTDISP, StatApp.LSTOBJNUMFIRSTDISP, StatApp.LSTSESNUMFIRSTDISP, StatApp.LSTSHTNUMFIRSTDISP, StatApp.LSTFILNUMFIRSTDISP]
		}

		public var ixWzskVExpstate: Int
		public var LstOgrAlt: Bool
		public var LstObjAlt: Bool
		public var LstSesAlt: Bool
		public var LstShtAlt: Bool
		public var LstFilAlt: Bool
		public var LstOgrNumFirstdisp: Int
		public var LstObjNumFirstdisp: Int
		public var LstSesNumFirstdisp: Int
		public var LstShtNumFirstdisp: Int
		public var LstFilNumFirstdisp: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskNavGlry")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskNavGlry"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatApp.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				LstOgrAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstOgrAlt", &mask, StatApp.LSTOGRALT)
				LstObjAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstObjAlt", &mask, StatApp.LSTOBJALT)
				LstSesAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstSesAlt", &mask, StatApp.LSTSESALT)
				LstShtAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstShtAlt", &mask, StatApp.LSTSHTALT)
				LstFilAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstFilAlt", &mask, StatApp.LSTFILALT)
				LstOgrNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstOgrNumFirstdisp", &mask, StatApp.LSTOGRNUMFIRSTDISP)
				LstObjNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstObjNumFirstdisp", &mask, StatApp.LSTOBJNUMFIRSTDISP)
				LstSesNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstSesNumFirstdisp", &mask, StatApp.LSTSESNUMFIRSTDISP)
				LstShtNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstShtNumFirstdisp", &mask, StatApp.LSTSHTNUMFIRSTDISP)
				LstFilNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstFilNumFirstdisp", &mask, StatApp.LSTFILNUMFIRSTDISP)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatApp.IXWZSKVEXPSTATE)}
			if LstOgrAlt == comp.LstOgrAlt {items.insert(StatApp.LSTOGRALT)}
			if LstObjAlt == comp.LstObjAlt {items.insert(StatApp.LSTOBJALT)}
			if LstSesAlt == comp.LstSesAlt {items.insert(StatApp.LSTSESALT)}
			if LstShtAlt == comp.LstShtAlt {items.insert(StatApp.LSTSHTALT)}
			if LstFilAlt == comp.LstFilAlt {items.insert(StatApp.LSTFILALT)}
			if LstOgrNumFirstdisp == comp.LstOgrNumFirstdisp {items.insert(StatApp.LSTOGRNUMFIRSTDISP)}
			if LstObjNumFirstdisp == comp.LstObjNumFirstdisp {items.insert(StatApp.LSTOBJNUMFIRSTDISP)}
			if LstSesNumFirstdisp == comp.LstSesNumFirstdisp {items.insert(StatApp.LSTSESNUMFIRSTDISP)}
			if LstShtNumFirstdisp == comp.LstShtNumFirstdisp {items.insert(StatApp.LSTSHTNUMFIRSTDISP)}
			if LstFilNumFirstdisp == comp.LstFilNumFirstdisp {items.insert(StatApp.LSTFILNUMFIRSTDISP)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVEXPSTATE, StatApp.LSTOGRALT, StatApp.LSTOBJALT, StatApp.LSTSESALT, StatApp.LSTSHTALT, StatApp.LSTFILALT, StatApp.LSTOGRNUMFIRSTDISP, StatApp.LSTOBJNUMFIRSTDISP, StatApp.LSTSESNUMFIRSTDISP, StatApp.LSTSHTNUMFIRSTDISP, StatApp.LSTFILNUMFIRSTDISP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskNavGlry)
	  */
	public class StatShr: Block {

		public static let LSTOGRAVAIL: Int = 1
		public static let BUTOGRVIEWACTIVE: Int = 2
		public static let LSTOBJAVAIL: Int = 3
		public static let BUTOBJVIEWACTIVE: Int = 4
		public static let LSTSESAVAIL: Int = 5
		public static let BUTSESVIEWACTIVE: Int = 6
		public static let LSTSHTAVAIL: Int = 7
		public static let BUTSHTVIEWACTIVE: Int = 8
		public static let LSTFILAVAIL: Int = 9
		public static let BUTFILVIEWACTIVE: Int = 10

		public init(
					_ LstOgrAvail: Bool = false
					, _ ButOgrViewActive: Bool = false
					, _ LstObjAvail: Bool = false
					, _ ButObjViewActive: Bool = false
					, _ LstSesAvail: Bool = false
					, _ ButSesViewActive: Bool = false
					, _ LstShtAvail: Bool = false
					, _ ButShtViewActive: Bool = false
					, _ LstFilAvail: Bool = false
					, _ ButFilViewActive: Bool = false
				) {
			self.LstOgrAvail = LstOgrAvail
			self.ButOgrViewActive = ButOgrViewActive
			self.LstObjAvail = LstObjAvail
			self.ButObjViewActive = ButObjViewActive
			self.LstSesAvail = LstSesAvail
			self.ButSesViewActive = ButSesViewActive
			self.LstShtAvail = LstShtAvail
			self.ButShtViewActive = ButShtViewActive
			self.LstFilAvail = LstFilAvail
			self.ButFilViewActive = ButFilViewActive

			super.init()

			mask = [StatShr.LSTOGRAVAIL, StatShr.BUTOGRVIEWACTIVE, StatShr.LSTOBJAVAIL, StatShr.BUTOBJVIEWACTIVE, StatShr.LSTSESAVAIL, StatShr.BUTSESVIEWACTIVE, StatShr.LSTSHTAVAIL, StatShr.BUTSHTVIEWACTIVE, StatShr.LSTFILAVAIL, StatShr.BUTFILVIEWACTIVE]
		}

		public var LstOgrAvail: Bool
		public var ButOgrViewActive: Bool
		public var LstObjAvail: Bool
		public var ButObjViewActive: Bool
		public var LstSesAvail: Bool
		public var ButSesViewActive: Bool
		public var LstShtAvail: Bool
		public var ButShtViewActive: Bool
		public var LstFilAvail: Bool
		public var ButFilViewActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskNavGlry")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskNavGlry"

			if valid {
				LstOgrAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstOgrAvail", &mask, StatShr.LSTOGRAVAIL)
				ButOgrViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButOgrViewActive", &mask, StatShr.BUTOGRVIEWACTIVE)
				LstObjAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstObjAvail", &mask, StatShr.LSTOBJAVAIL)
				ButObjViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButObjViewActive", &mask, StatShr.BUTOBJVIEWACTIVE)
				LstSesAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstSesAvail", &mask, StatShr.LSTSESAVAIL)
				ButSesViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButSesViewActive", &mask, StatShr.BUTSESVIEWACTIVE)
				LstShtAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstShtAvail", &mask, StatShr.LSTSHTAVAIL)
				ButShtViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButShtViewActive", &mask, StatShr.BUTSHTVIEWACTIVE)
				LstFilAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstFilAvail", &mask, StatShr.LSTFILAVAIL)
				ButFilViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButFilViewActive", &mask, StatShr.BUTFILVIEWACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if LstOgrAvail == comp.LstOgrAvail {items.insert(StatShr.LSTOGRAVAIL)}
			if ButOgrViewActive == comp.ButOgrViewActive {items.insert(StatShr.BUTOGRVIEWACTIVE)}
			if LstObjAvail == comp.LstObjAvail {items.insert(StatShr.LSTOBJAVAIL)}
			if ButObjViewActive == comp.ButObjViewActive {items.insert(StatShr.BUTOBJVIEWACTIVE)}
			if LstSesAvail == comp.LstSesAvail {items.insert(StatShr.LSTSESAVAIL)}
			if ButSesViewActive == comp.ButSesViewActive {items.insert(StatShr.BUTSESVIEWACTIVE)}
			if LstShtAvail == comp.LstShtAvail {items.insert(StatShr.LSTSHTAVAIL)}
			if ButShtViewActive == comp.ButShtViewActive {items.insert(StatShr.BUTSHTVIEWACTIVE)}
			if LstFilAvail == comp.LstFilAvail {items.insert(StatShr.LSTFILAVAIL)}
			if ButFilViewActive == comp.ButFilViewActive {items.insert(StatShr.BUTFILVIEWACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.LSTOGRAVAIL, StatShr.BUTOGRVIEWACTIVE, StatShr.LSTOBJAVAIL, StatShr.BUTOBJVIEWACTIVE, StatShr.LSTSESAVAIL, StatShr.BUTSESVIEWACTIVE, StatShr.LSTSHTAVAIL, StatShr.BUTSHTVIEWACTIVE, StatShr.LSTFILAVAIL, StatShr.BUTFILVIEWACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskNavGlry)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTOGR: Int = 2
		public static let CPTOBJ: Int = 3
		public static let CPTSES: Int = 4
		public static let CPTSHT: Int = 5
		public static let CPTFIL: Int = 6

		public init(
					_ Cpt: String = ""
					, _ CptOgr: String = ""
					, _ CptObj: String = ""
					, _ CptSes: String = ""
					, _ CptSht: String = ""
					, _ CptFil: String = ""
				) {
			self.Cpt = Cpt
			self.CptOgr = CptOgr
			self.CptObj = CptObj
			self.CptSes = CptSes
			self.CptSht = CptSht
			self.CptFil = CptFil

			super.init()

			mask = [Tag.CPT, Tag.CPTOGR, Tag.CPTOBJ, Tag.CPTSES, Tag.CPTSHT, Tag.CPTFIL]
		}

		public var Cpt: String
		public var CptOgr: String
		public var CptObj: String
		public var CptSes: String
		public var CptSht: String
		public var CptFil: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskNavGlry")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskNavGlry"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptOgr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptOgr", &mask, Tag.CPTOGR)
				CptObj = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptObj", &mask, Tag.CPTOBJ)
				CptSes = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSes", &mask, Tag.CPTSES)
				CptSht = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptSht", &mask, Tag.CPTSHT)
				CptFil = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptFil", &mask, Tag.CPTFIL)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptOgr == comp.CptOgr {items.insert(Tag.CPTOGR)}
			if CptObj == comp.CptObj {items.insert(Tag.CPTOBJ)}
			if CptSes == comp.CptSes {items.insert(Tag.CPTSES)}
			if CptSht == comp.CptSht {items.insert(Tag.CPTSHT)}
			if CptFil == comp.CptFil {items.insert(Tag.CPTFIL)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTOGR, Tag.CPTOBJ, Tag.CPTSES, Tag.CPTSHT, Tag.CPTFIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskNavGlryData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKNAVGLRYDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskNavGlryData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskNavGlryDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKNAVGLRYDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskNavGlryDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskNavGlryData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let FEEDFLSTFIL: Int = 3
		public static let FEEDFLSTOBJ: Int = 4
		public static let FEEDFLSTOGR: Int = 5
		public static let FEEDFLSTSES: Int = 6
		public static let FEEDFLSTSHT: Int = 7
		public static let STATAPP: Int = 8
		public static let STATSHR: Int = 9
		public static let TAG: Int = 10

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKNAVGLRYDATA)
		}

		public var contiac: ContIac = ContIac()
		public var feedFLstFil: Feed = Feed("FeedFLstFil")
		public var feedFLstObj: Feed = Feed("FeedFLstObj")
		public var feedFLstOgr: Feed = Feed("FeedFLstOgr")
		public var feedFLstSes: Feed = Feed("FeedFLstSes")
		public var feedFLstSht: Feed = Feed("FeedFLstSht")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.FEEDFLSTFIL) {ss.append("feedFLstFil")}
			if has(DpchEngData.FEEDFLSTOBJ) {ss.append("feedFLstObj")}
			if has(DpchEngData.FEEDFLSTOGR) {ss.append("feedFLstOgr")}
			if has(DpchEngData.FEEDFLSTSES) {ss.append("feedFLstSes")}
			if has(DpchEngData.FEEDFLSTSHT) {ss.append("feedFLstSht")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskNavGlryData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if feedFLstFil.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTFIL)}
				if feedFLstObj.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTOBJ)}
				if feedFLstOgr.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTOGR)}
				if feedFLstSes.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTSES)}
				if feedFLstSht.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTSHT)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				feedFLstFil = Feed("FeedFLstFil")
				feedFLstObj = Feed("FeedFLstObj")
				feedFLstOgr = Feed("FeedFLstOgr")
				feedFLstSes = Feed("FeedFLstSes")
				feedFLstSht = Feed("FeedFLstSht")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
