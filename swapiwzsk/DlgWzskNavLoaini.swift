/**
  * \file DlgWzskNavLoaini.swift
  * Swift API code for job DlgWzskNavLoaini
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* DlgWzskNavLoaini
	*/
public class DlgWzskNavLoaini {
	/**
		* VecVDit (full: VecVDlgWzskNavLoainiDit)
		*/
	public class VecVDit {

		public static let IFI: Int = 1
		public static let IMP: Int = 2
		public static let LFI: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "ifi" {return IFI}
			if s == "imp" {return IMP}
			if s == "lfi" {return LFI}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == IFI {return "Ifi"}
			if ix == IMP {return "Imp"}
			if ix == LFI {return "Lfi"}

			return ""
		}

	}

	/**
		* VecVDo (full: VecVDlgWzskNavLoainiDo)
		*/
	public class VecVDo {

		public static let BUTDNECLICK: Int = 1

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butdneclick" {return BUTDNECLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTDNECLICK {return "ButDneClick"}

			return ""
		}

	}

	/**
		* VecVDoImp (full: VecVDlgWzskNavLoainiDoImp)
		*/
	public class VecVDoImp {

		public static let BUTRUNCLICK: Int = 1
		public static let BUTSTOCLICK: Int = 2

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butrunclick" {return BUTRUNCLICK}
			if s == "butstoclick" {return BUTSTOCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTRUNCLICK {return "ButRunClick"}
			if ix == BUTSTOCLICK {return "ButStoClick"}

			return ""
		}

	}

	/**
		* VecVSge (full: VecVDlgWzskNavLoainiSge)
		*/
	public class VecVSge {

		public static let IDLE: Int = 1
		public static let PRSIDLE: Int = 2
		public static let PARSE: Int = 3
		public static let ALRWZSKPER: Int = 4
		public static let PRSDONE: Int = 5
		public static let IMPIDLE: Int = 6
		public static let IMPORT: Int = 7
		public static let ALRWZSKIER: Int = 8
		public static let DONE: Int = 9

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "idle" {return IDLE}
			if s == "prsidle" {return PRSIDLE}
			if s == "parse" {return PARSE}
			if s == "alrwzskper" {return ALRWZSKPER}
			if s == "prsdone" {return PRSDONE}
			if s == "impidle" {return IMPIDLE}
			if s == "import" {return IMPORT}
			if s == "alrwzskier" {return ALRWZSKIER}
			if s == "done" {return DONE}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == IDLE {return "idle"}
			if ix == PRSIDLE {return "prsidle"}
			if ix == PARSE {return "parse"}
			if ix == ALRWZSKPER {return "alrwzskper"}
			if ix == PRSDONE {return "prsdone"}
			if ix == IMPIDLE {return "impidle"}
			if ix == IMPORT {return "import"}
			if ix == ALRWZSKIER {return "alrwzskier"}
			if ix == DONE {return "done"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacDlgWzskNavLoaini)
	  */
	public class ContIac: Block {

		public static let NUMFDSE: Int = 1

		public init(
					_ numFDse: Int = 0
				) {
			self.numFDse = numFDse

			super.init()

			mask = [ContIac.NUMFDSE]
		}

		public var numFDse: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacDlgWzskNavLoaini")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacDlgWzskNavLoaini"

			if valid {
				numFDse = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFDse", &mask, ContIac.NUMFDSE)
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
			if tag == nil {tag = "ContIacDlgWzskNavLoaini"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacDlgWzskNavLoaini"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFDse", numFDse)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFDse == comp.numFDse {items.insert(ContIac.NUMFDSE)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFDSE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfDlgWzskNavLoaini)
	  */
	public class ContInf: Block {

		public static let NUMFSGE: Int = 1

		public init(
					_ numFSge: Int = 0
				) {
			self.numFSge = numFSge

			super.init()

			mask = [ContInf.NUMFSGE]
		}

		public var numFSge: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfDlgWzskNavLoaini")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfDlgWzskNavLoaini"

			if valid {
				numFSge = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFSge", &mask, ContInf.NUMFSGE)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFSge == comp.numFSge {items.insert(ContInf.NUMFSGE)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.NUMFSGE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInfImp (full: ContInfDlgWzskNavLoainiImp)
	  */
	public class ContInfImp: Block {

		public static let TXTPRG: Int = 1

		public init(
					_ TxtPrg: String = ""
				) {
			self.TxtPrg = TxtPrg

			super.init()

			mask = [ContInfImp.TXTPRG]
		}

		public var TxtPrg: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfDlgWzskNavLoainiImp")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfDlgWzskNavLoainiImp"

			if valid {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtPrg", &mask, ContInfImp.TXTPRG)
			}

			return valid
		}

		public func comm(
					_ comp: ContInfImp
				) -> Set<Int> {
			var items: Set<Int> = []

			if TxtPrg == comp.TxtPrg {items.insert(ContInfImp.TXTPRG)}

			return items
		}

		public func diff(
					_ comp: ContInfImp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInfImp.TXTPRG]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInfLfi (full: ContInfDlgWzskNavLoainiLfi)
	  */
	public class ContInfLfi: Block {

		public static let DLD: Int = 1

		public init(
					_ Dld: String = ""
				) {
			self.Dld = Dld

			super.init()

			mask = [ContInfLfi.DLD]
		}

		public var Dld: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfDlgWzskNavLoainiLfi")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfDlgWzskNavLoainiLfi"

			if valid {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "Dld", &mask, ContInfLfi.DLD)
			}

			return valid
		}

		public func comm(
					_ comp: ContInfLfi
				) -> Set<Int> {
			var items: Set<Int> = []

			if Dld == comp.Dld {items.insert(ContInfLfi.DLD)}

			return items
		}

		public func diff(
					_ comp: ContInfLfi
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInfLfi.DLD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppDlgWzskNavLoaini)
	  */
	public class StatApp: Block {

		public static let INITDONE: Int = 1
		public static let SHORTMENU: Int = 2

		public init(
					_ initdone: Bool = false
					, _ shortMenu: String = ""
				) {
			self.initdone = initdone
			self.shortMenu = shortMenu

			super.init()

			mask = [StatApp.INITDONE, StatApp.SHORTMENU]
		}

		public var initdone: Bool
		public var shortMenu: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppDlgWzskNavLoaini")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppDlgWzskNavLoaini"

			if valid {
				initdone = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "initdone", &mask, StatApp.INITDONE)
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "shortMenu", &mask, StatApp.SHORTMENU)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if initdone == comp.initdone {items.insert(StatApp.INITDONE)}
			if shortMenu == comp.shortMenu {items.insert(StatApp.SHORTMENU)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.INITDONE, StatApp.SHORTMENU]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrDlgWzskNavLoaini)
	  */
	public class StatShr: Block {

		public static let BUTDNEACTIVE: Int = 1

		public init(
					_ ButDneActive: Bool = false
				) {
			self.ButDneActive = ButDneActive

			super.init()

			mask = [StatShr.BUTDNEACTIVE]
		}

		public var ButDneActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrDlgWzskNavLoaini")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrDlgWzskNavLoaini"

			if valid {
				ButDneActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButDneActive", &mask, StatShr.BUTDNEACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButDneActive == comp.ButDneActive {items.insert(StatShr.BUTDNEACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.BUTDNEACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShrIfi (full: StatShrDlgWzskNavLoainiIfi)
	  */
	public class StatShrIfi: Block {

		public static let ULDACTIVE: Int = 1

		public init(
					_ UldActive: Bool = false
				) {
			self.UldActive = UldActive

			super.init()

			mask = [StatShrIfi.ULDACTIVE]
		}

		public var UldActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrDlgWzskNavLoainiIfi")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrDlgWzskNavLoainiIfi"

			if valid {
				UldActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UldActive", &mask, StatShrIfi.ULDACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShrIfi
				) -> Set<Int> {
			var items: Set<Int> = []

			if UldActive == comp.UldActive {items.insert(StatShrIfi.ULDACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShrIfi
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShrIfi.ULDACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShrImp (full: StatShrDlgWzskNavLoainiImp)
	  */
	public class StatShrImp: Block {

		public static let BUTRUNACTIVE: Int = 1
		public static let BUTSTOACTIVE: Int = 2

		public init(
					_ ButRunActive: Bool = false
					, _ ButStoActive: Bool = false
				) {
			self.ButRunActive = ButRunActive
			self.ButStoActive = ButStoActive

			super.init()

			mask = [StatShrImp.BUTRUNACTIVE, StatShrImp.BUTSTOACTIVE]
		}

		public var ButRunActive: Bool
		public var ButStoActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrDlgWzskNavLoainiImp")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrDlgWzskNavLoainiImp"

			if valid {
				ButRunActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButRunActive", &mask, StatShrImp.BUTRUNACTIVE)
				ButStoActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButStoActive", &mask, StatShrImp.BUTSTOACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShrImp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButRunActive == comp.ButRunActive {items.insert(StatShrImp.BUTRUNACTIVE)}
			if ButStoActive == comp.ButStoActive {items.insert(StatShrImp.BUTSTOACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShrImp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShrImp.BUTRUNACTIVE, StatShrImp.BUTSTOACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShrLfi (full: StatShrDlgWzskNavLoainiLfi)
	  */
	public class StatShrLfi: Block {

		public static let DLDACTIVE: Int = 1

		public init(
					_ DldActive: Bool = false
				) {
			self.DldActive = DldActive

			super.init()

			mask = [StatShrLfi.DLDACTIVE]
		}

		public var DldActive: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrDlgWzskNavLoainiLfi")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrDlgWzskNavLoainiLfi"

			if valid {
				DldActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "DldActive", &mask, StatShrLfi.DLDACTIVE)
			}

			return valid
		}

		public func comm(
					_ comp: StatShrLfi
				) -> Set<Int> {
			var items: Set<Int> = []

			if DldActive == comp.DldActive {items.insert(StatShrLfi.DLDACTIVE)}

			return items
		}

		public func diff(
					_ comp: StatShrLfi
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShrLfi.DLDACTIVE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagDlgWzskNavLoaini)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let BUTDNE: Int = 2

		public init(
					_ Cpt: String = ""
					, _ ButDne: String = ""
				) {
			self.Cpt = Cpt
			self.ButDne = ButDne

			super.init()

			mask = [Tag.CPT, Tag.BUTDNE]
		}

		public var Cpt: String
		public var ButDne: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagDlgWzskNavLoaini")}
			valid = basexpath != nil

			let itemtag: String = "TagitemlgWzskNavLoaini"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				ButDne = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButDne", &mask, Tag.BUTDNE)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if ButDne == comp.ButDne {items.insert(Tag.BUTDNE)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.BUTDNE]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * TagIfi (full: TagDlgWzskNavLoainiIfi)
	  */
	public class TagIfi: Block {

		public static let ULD: Int = 1
		public static let CPT: Int = 2

		public init(
					_ Uld: String = ""
					, _ Cpt: String = ""
				) {
			self.Uld = Uld
			self.Cpt = Cpt

			super.init()

			mask = [TagIfi.ULD, TagIfi.CPT]
		}

		public var Uld: String
		public var Cpt: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagDlgWzskNavLoainiIfi")}
			valid = basexpath != nil

			let itemtag: String = "TagitemlgWzskNavLoainiIfi"

			if valid {
				Uld = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Uld", &mask, TagIfi.ULD)
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, TagIfi.CPT)
			}

			return valid
		}

		public func comm(
					_ comp: TagIfi
				) -> Set<Int> {
			var items: Set<Int> = []

			if Uld == comp.Uld {items.insert(TagIfi.ULD)}
			if Cpt == comp.Cpt {items.insert(TagIfi.CPT)}

			return items
		}

		public func diff(
					_ comp: TagIfi
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [TagIfi.ULD, TagIfi.CPT]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * TagImp (full: TagDlgWzskNavLoainiImp)
	  */
	public class TagImp: Block {

		public static let CPTPRG: Int = 1
		public static let BUTRUN: Int = 2
		public static let BUTSTO: Int = 3

		public init(
					_ CptPrg: String = ""
					, _ ButRun: String = ""
					, _ ButSto: String = ""
				) {
			self.CptPrg = CptPrg
			self.ButRun = ButRun
			self.ButSto = ButSto

			super.init()

			mask = [TagImp.CPTPRG, TagImp.BUTRUN, TagImp.BUTSTO]
		}

		public var CptPrg: String
		public var ButRun: String
		public var ButSto: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagDlgWzskNavLoainiImp")}
			valid = basexpath != nil

			let itemtag: String = "TagitemlgWzskNavLoainiImp"

			if valid {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPrg", &mask, TagImp.CPTPRG)
				ButRun = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButRun", &mask, TagImp.BUTRUN)
				ButSto = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButSto", &mask, TagImp.BUTSTO)
			}

			return valid
		}

		public func comm(
					_ comp: TagImp
				) -> Set<Int> {
			var items: Set<Int> = []

			if CptPrg == comp.CptPrg {items.insert(TagImp.CPTPRG)}
			if ButRun == comp.ButRun {items.insert(TagImp.BUTRUN)}
			if ButSto == comp.ButSto {items.insert(TagImp.BUTSTO)}

			return items
		}

		public func diff(
					_ comp: TagImp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [TagImp.CPTPRG, TagImp.BUTRUN, TagImp.BUTSTO]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * TagLfi (full: TagDlgWzskNavLoainiLfi)
	  */
	public class TagLfi: Block {

		public static let DLD: Int = 1

		public init(
					_ Dld: String = ""
				) {
			self.Dld = Dld

			super.init()

			mask = [TagLfi.DLD]
		}

		public var Dld: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagDlgWzskNavLoainiLfi")}
			valid = basexpath != nil

			let itemtag: String = "TagitemlgWzskNavLoainiLfi"

			if valid {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Dld", &mask, TagLfi.DLD)
			}

			return valid
		}

		public func comm(
					_ comp: TagLfi
				) -> Set<Int> {
			var items: Set<Int> = []

			if Dld == comp.Dld {items.insert(TagLfi.DLD)}

			return items
		}

		public func diff(
					_ comp: TagLfi
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [TagLfi.DLD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppDlgWzskNavLoainiData)
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
			super.init(VecWzskVDpch.DPCHAPPDLGWZSKNAVLOAINIDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppDlgWzskNavLoainiData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppDlgWzskNavLoainiDo)
		*/
	public class DpchAppDo: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let IXVDO: Int = 2
		public static let IXVDOIMP: Int = 3
		public static let ALL: Int  = 4

		public init(
					_ scrJref: String = ""
					, _ ixVDo: Int = 0
					, _ ixVDoImp: Int = 0
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPDLGWZSKNAVLOAINIDO, scrJref)

			if mask.contains(DpchAppDo.ALL) {self.mask = [DpchAppDo.SCRJREF, DpchAppDo.IXVDO, DpchAppDo.IXVDOIMP]}
			else {self.mask = mask}

			self.ixVDo = ixVDo
			self.ixVDoImp = ixVDoImp
		}

		public var ixVDo: Int = 0
		public var ixVDoImp: Int = 0

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchAppDo.SCRJREF) {ss.append("scrJref")}
			if has(DpchAppDo.IXVDO) {ss.append("ixVDo")}
			if has(DpchAppDo.IXVDOIMP) {ss.append("ixVDoImp")}

			return StrMod.vectorToString(ss)
		}

		public override func writeXML(
					_ doc: XMLDocument
					, _ sup: XMLElement?
				) {
			let el = XMLElement(name: "DpchAppDlgWzskNavLoainiDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
			if has(DpchAppDo.IXVDOIMP) {el.addChild(XMLElement(name: "srefIxVDoImp", stringValue: VecVDoImp.getSref(ixVDoImp)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngDlgWzskNavLoainiData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let CONTINFIMP: Int = 4
		public static let CONTINFLFI: Int = 5
		public static let FEEDFDSE: Int = 6
		public static let FEEDFSGE: Int = 7
		public static let STATAPP: Int = 8
		public static let STATSHR: Int = 9
		public static let STATSHRIFI: Int = 10
		public static let STATSHRIMP: Int = 11
		public static let STATSHRLFI: Int = 12
		public static let TAG: Int = 13
		public static let TAGIFI: Int = 14
		public static let TAGIMP: Int = 15
		public static let TAGLFI: Int = 16

		public init() {
			super.init(VecWzskVDpch.DPCHENGDLGWZSKNAVLOAINIDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var continfimp: ContInfImp = ContInfImp()
		public var continflfi: ContInfLfi = ContInfLfi()
		public var feedFDse: Feed = Feed("FeedFDse")
		public var feedFSge: Feed = Feed("FeedFSge")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var statshrifi: StatShrIfi = StatShrIfi()
		public var statshrimp: StatShrImp = StatShrImp()
		public var statshrlfi: StatShrLfi = StatShrLfi()
		public var tag: Tag = Tag()
		public var tagifi: TagIfi = TagIfi()
		public var tagimp: TagImp = TagImp()
		public var taglfi: TagLfi = TagLfi()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.CONTINFIMP) {ss.append("continfimp")}
			if has(DpchEngData.CONTINFLFI) {ss.append("continflfi")}
			if has(DpchEngData.FEEDFDSE) {ss.append("feedFDse")}
			if has(DpchEngData.FEEDFSGE) {ss.append("feedFSge")}
			if has(DpchEngData.STATAPP) {ss.append("statapp")}
			if has(DpchEngData.STATSHR) {ss.append("statshr")}
			if has(DpchEngData.STATSHRIFI) {ss.append("statshrifi")}
			if has(DpchEngData.STATSHRIMP) {ss.append("statshrimp")}
			if has(DpchEngData.STATSHRLFI) {ss.append("statshrlfi")}
			if has(DpchEngData.TAG) {ss.append("tag")}
			if has(DpchEngData.TAGIFI) {ss.append("tagifi")}
			if has(DpchEngData.TAGIMP) {ss.append("tagimp")}
			if has(DpchEngData.TAGLFI) {ss.append("taglfi")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngDlgWzskNavLoainiData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if continfimp.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINFIMP)}
				if continflfi.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINFLFI)}
				if feedFDse.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFDSE)}
				if feedFSge.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFSGE)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if statshrifi.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHRIFI)}
				if statshrimp.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHRIMP)}
				if statshrlfi.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHRLFI)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
				if tagifi.readXML(doc, basexpath!, true) {add(DpchEngData.TAGIFI)}
				if tagimp.readXML(doc, basexpath!, true) {add(DpchEngData.TAGIMP)}
				if taglfi.readXML(doc, basexpath!, true) {add(DpchEngData.TAGLFI)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				continfimp = ContInfImp()
				continflfi = ContInfLfi()
				feedFDse = Feed("FeedFDse")
				feedFSge = Feed("FeedFSge")
				statapp = StatApp()
				statshr = StatShr()
				statshrifi = StatShrIfi()
				statshrimp = StatShrImp()
				statshrlfi = StatShrLfi()
				tag = Tag()
				tagifi = TagIfi()
				tagimp = TagImp()
				taglfi = TagLfi()
			}
		}

	}

}
