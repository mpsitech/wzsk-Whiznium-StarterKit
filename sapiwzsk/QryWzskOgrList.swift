/**
  * \file QryWzskOgrList.swift
  * Swift API code for job QryWzskOgrList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* QryWzskOgrList
	*/
public class QryWzskOgrList {
	/**
		* VecVOrd (full: VecVQryWzskOgrListOrd)
		*/
	public class VecVOrd {

		public static let SUP: Int = 1
		public static let TIT: Int = 2
		public static let SRF: Int = 3

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "sup" {return SUP}
			if s == "tit" {return TIT}
			if s == "srf" {return SRF}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == SUP {return "sup"}
			if ix == TIT {return "tit"}
			if ix == SRF {return "srf"}

			return ""
		}

	}

	/**
	  * StatApp (full: StatAppQryWzskOgrList)
	  */
	public class StatApp: Block {

		public static let FIRSTCOL: Int = 1
		public static let JNUMFIRSTDISP: Int = 2
		public static let NCOL: Int = 3
		public static let NDISP: Int = 4

		public init(
					_ firstcol: Int = 0
					, _ jnumFirstdisp: Int = 0
					, _ ncol: Int = 0
					, _ ndisp: Int = 0
				) {
			self.firstcol = firstcol
			self.jnumFirstdisp = jnumFirstdisp
			self.ncol = ncol
			self.ndisp = ndisp

			super.init()

			mask = [StatApp.FIRSTCOL, StatApp.JNUMFIRSTDISP, StatApp.NCOL, StatApp.NDISP]
		}

		public var firstcol: Int
		public var jnumFirstdisp: Int
		public var ncol: Int
		public var ndisp: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppQryWzskOgrList")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppQryWzskOgrList"

			if valid {
				firstcol = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "firstcol", &mask, StatApp.FIRSTCOL)
				jnumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "jnumFirstdisp", &mask, StatApp.JNUMFIRSTDISP)
				ncol = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ncol", &mask, StatApp.NCOL)
				ndisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ndisp", &mask, StatApp.NDISP)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if firstcol == comp.firstcol {items.insert(StatApp.FIRSTCOL)}
			if jnumFirstdisp == comp.jnumFirstdisp {items.insert(StatApp.JNUMFIRSTDISP)}
			if ncol == comp.ncol {items.insert(StatApp.NCOL)}
			if ndisp == comp.ndisp {items.insert(StatApp.NDISP)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.FIRSTCOL, StatApp.JNUMFIRSTDISP, StatApp.NCOL, StatApp.NDISP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrQryWzskOgrList)
	  */
	public class StatShr: Block {

		public static let NTOT: Int = 1
		public static let JNUMFIRSTLOAD: Int = 2
		public static let NLOAD: Int = 3

		public init(
					_ ntot: Int = 0
					, _ jnumFirstload: Int = 0
					, _ nload: Int = 0
				) {
			self.ntot = ntot
			self.jnumFirstload = jnumFirstload
			self.nload = nload

			super.init()

			mask = [StatShr.NTOT, StatShr.JNUMFIRSTLOAD, StatShr.NLOAD]
		}

		public var ntot: Int
		public var jnumFirstload: Int
		public var nload: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrQryWzskOgrList")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrQryWzskOgrList"

			if valid {
				ntot = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ntot", &mask, StatShr.NTOT)
				jnumFirstload = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "jnumFirstload", &mask, StatShr.JNUMFIRSTLOAD)
				nload = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "nload", &mask, StatShr.NLOAD)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ntot == comp.ntot {items.insert(StatShr.NTOT)}
			if jnumFirstload == comp.jnumFirstload {items.insert(StatShr.JNUMFIRSTLOAD)}
			if nload == comp.nload {items.insert(StatShr.NLOAD)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.NTOT, StatShr.JNUMFIRSTLOAD, StatShr.NLOAD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StgIac (full: StgIacQryWzskOgrList)
	  */
	public class StgIac: Block {

		public static let JNUM: Int = 1
		public static let JNUMFIRSTLOAD: Int = 2
		public static let NLOAD: Int = 3

		public init(
					_ jnum: Int = 0
					, _ jnumFirstload: Int = 0
					, _ nload: Int = 0
				) {
			self.jnum = jnum
			self.jnumFirstload = jnumFirstload
			self.nload = nload

			super.init()

			mask = [StgIac.JNUM, StgIac.JNUMFIRSTLOAD, StgIac.NLOAD]
		}

		public var jnum: Int
		public var jnumFirstload: Int
		public var nload: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StgIacQryWzskOgrList")}
			valid = basexpath != nil

			let itemtag: String = "StgitemacQryWzskOgrList"

			if valid {
				jnum = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "jnum", &mask, StgIac.JNUM)
				jnumFirstload = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "jnumFirstload", &mask, StgIac.JNUMFIRSTLOAD)
				nload = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "nload", &mask, StgIac.NLOAD)
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
			if tag == nil {tag = "StgIacQryWzskOgrList"}

			let itemtag: String = shorttags ? "Si" : "StgitemacQryWzskOgrList"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "jnum", jnum)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "jnumFirstload", jnumFirstload)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "nload", nload)
		}

		public func comm(
					_ comp: StgIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if jnum == comp.jnum {items.insert(StgIac.JNUM)}
			if jnumFirstload == comp.jnumFirstload {items.insert(StgIac.JNUMFIRSTLOAD)}
			if nload == comp.nload {items.insert(StgIac.NLOAD)}

			return items
		}

		public func diff(
					_ comp: StgIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StgIac.JNUM, StgIac.JNUMFIRSTLOAD, StgIac.NLOAD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

}
