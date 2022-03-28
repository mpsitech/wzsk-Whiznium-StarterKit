/**
  * \file PnlWzskLiv2DView.swift
  * Swift API code for job PnlWzskLiv2DView
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskLiv2DView
	*/
public class PnlWzskLiv2DView {
	/**
		* VecVDo (full: VecVWzskLiv2DViewDo)
		*/
	public class VecVDo {

		public static let BUTREGULARIZECLICK: Int = 1
		public static let BUTMINIMIZECLICK: Int = 2
		public static let BUTCLAIMCLICK: Int = 3
		public static let BUTPLAYCLICK: Int = 4
		public static let BUTSTOPCLICK: Int = 5
		public static let BUTSTSCLICK: Int = 6
		public static let BUTTCCCLICK: Int = 7
		public static let BUTTCWCLICK: Int = 8
		public static let BUTLLECLICK: Int = 9
		public static let BUTLRICLICK: Int = 10
		public static let BUTLTRCLICK: Int = 11
		public static let BUTPICCLICK: Int = 12

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butregularizeclick" {return BUTREGULARIZECLICK}
			if s == "butminimizeclick" {return BUTMINIMIZECLICK}
			if s == "butclaimclick" {return BUTCLAIMCLICK}
			if s == "butplayclick" {return BUTPLAYCLICK}
			if s == "butstopclick" {return BUTSTOPCLICK}
			if s == "butstsclick" {return BUTSTSCLICK}
			if s == "buttccclick" {return BUTTCCCLICK}
			if s == "buttcwclick" {return BUTTCWCLICK}
			if s == "butlleclick" {return BUTLLECLICK}
			if s == "butlriclick" {return BUTLRICLICK}
			if s == "butltrclick" {return BUTLTRCLICK}
			if s == "butpicclick" {return BUTPICCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTREGULARIZECLICK {return "ButRegularizeClick"}
			if ix == BUTMINIMIZECLICK {return "ButMinimizeClick"}
			if ix == BUTCLAIMCLICK {return "ButClaimClick"}
			if ix == BUTPLAYCLICK {return "ButPlayClick"}
			if ix == BUTSTOPCLICK {return "ButStopClick"}
			if ix == BUTSTSCLICK {return "ButStsClick"}
			if ix == BUTTCCCLICK {return "ButTccClick"}
			if ix == BUTTCWCLICK {return "ButTcwClick"}
			if ix == BUTLLECLICK {return "ButLleClick"}
			if ix == BUTLRICLICK {return "ButLriClick"}
			if ix == BUTLTRCLICK {return "ButLtrClick"}
			if ix == BUTPICCLICK {return "ButPicClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskLiv2DView)
	  */
	public class ContIac: Block {

		public static let NUMFPUPPVM: Int = 1
		public static let CHKAEX: Int = 2
		public static let SLDEXT: Int = 3
		public static let SLDFCS: Int = 4
		public static let UPDLLO: Int = 5
		public static let UPDLUO: Int = 6
		public static let UPDLMD: Int = 7
		public static let CHKLRO: Int = 8
		public static let UPDPNT: Int = 9
		public static let CHKPRO: Int = 10
		public static let SLDCWD: Int = 11

		public init(
					_ numFPupPvm: Int = 0
					, _ ChkAex: Bool = false
					, _ SldExt: Double = 0.0
					, _ SldFcs: Double = 0.0
					, _ UpdLlo: Int = 0
					, _ UpdLuo: Int = 0
					, _ UpdLmd: Int = 0
					, _ ChkLro: Bool = false
					, _ UpdPnt: Int = 0
					, _ ChkPro: Bool = false
					, _ SldCwd: Double = 0.0
				) {
			self.numFPupPvm = numFPupPvm
			self.ChkAex = ChkAex
			self.SldExt = SldExt
			self.SldFcs = SldFcs
			self.UpdLlo = UpdLlo
			self.UpdLuo = UpdLuo
			self.UpdLmd = UpdLmd
			self.ChkLro = ChkLro
			self.UpdPnt = UpdPnt
			self.ChkPro = ChkPro
			self.SldCwd = SldCwd

			super.init()

			mask = [ContIac.NUMFPUPPVM, ContIac.CHKAEX, ContIac.SLDEXT, ContIac.SLDFCS, ContIac.UPDLLO, ContIac.UPDLUO, ContIac.UPDLMD, ContIac.CHKLRO, ContIac.UPDPNT, ContIac.CHKPRO, ContIac.SLDCWD]
		}

		public var numFPupPvm: Int
		public var ChkAex: Bool
		public var SldExt: Double
		public var SldFcs: Double
		public var UpdLlo: Int
		public var UpdLuo: Int
		public var UpdLmd: Int
		public var ChkLro: Bool
		public var UpdPnt: Int
		public var ChkPro: Bool
		public var SldCwd: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskLiv2DView")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskLiv2DView"

			if valid {
				numFPupPvm = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFPupPvm", &mask, ContIac.NUMFPUPPVM)
				ChkAex = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ChkAex", &mask, ContIac.CHKAEX)
				SldExt = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExt", &mask, ContIac.SLDEXT)
				SldFcs = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldFcs", &mask, ContIac.SLDFCS)
				UpdLlo = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLlo", &mask, ContIac.UPDLLO)
				UpdLuo = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLuo", &mask, ContIac.UPDLUO)
				UpdLmd = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLmd", &mask, ContIac.UPDLMD)
				ChkLro = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ChkLro", &mask, ContIac.CHKLRO)
				UpdPnt = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdPnt", &mask, ContIac.UPDPNT)
				ChkPro = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ChkPro", &mask, ContIac.CHKPRO)
				SldCwd = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldCwd", &mask, ContIac.SLDCWD)
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
			if tag == nil {tag = "ContIacWzskLiv2DView"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskLiv2DView"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFPupPvm", numFPupPvm)
			Xmlio.writeBoolAttr(doc, el, itemtag, "sref", "ChkAex", ChkAex)
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldExt", SldExt)
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFcs", SldFcs)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "UpdLlo", UpdLlo)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "UpdLuo", UpdLuo)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "UpdLmd", UpdLmd)
			Xmlio.writeBoolAttr(doc, el, itemtag, "sref", "ChkLro", ChkLro)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "UpdPnt", UpdPnt)
			Xmlio.writeBoolAttr(doc, el, itemtag, "sref", "ChkPro", ChkPro)
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldCwd", SldCwd)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFPupPvm == comp.numFPupPvm {items.insert(ContIac.NUMFPUPPVM)}
			if ChkAex == comp.ChkAex {items.insert(ContIac.CHKAEX)}
			if Xmlio.compareDouble(SldExt, comp.SldExt) < 1.0e-4 {items.insert(ContIac.SLDEXT)}
			if Xmlio.compareDouble(SldFcs, comp.SldFcs) < 1.0e-4 {items.insert(ContIac.SLDFCS)}
			if UpdLlo == comp.UpdLlo {items.insert(ContIac.UPDLLO)}
			if UpdLuo == comp.UpdLuo {items.insert(ContIac.UPDLUO)}
			if UpdLmd == comp.UpdLmd {items.insert(ContIac.UPDLMD)}
			if ChkLro == comp.ChkLro {items.insert(ContIac.CHKLRO)}
			if UpdPnt == comp.UpdPnt {items.insert(ContIac.UPDPNT)}
			if ChkPro == comp.ChkPro {items.insert(ContIac.CHKPRO)}
			if Xmlio.compareDouble(SldCwd, comp.SldCwd) < 1.0e-4 {items.insert(ContIac.SLDCWD)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFPUPPVM, ContIac.CHKAEX, ContIac.SLDEXT, ContIac.SLDFCS, ContIac.UPDLLO, ContIac.UPDLUO, ContIac.UPDLMD, ContIac.CHKLRO, ContIac.UPDPNT, ContIac.CHKPRO, ContIac.SLDCWD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContIacCorner (full: ContIacWzskLiv2DViewCorner)
	  */
	public class ContIacCorner: Block {

		public static let ROIAX: Int = 1
		public static let ROIAY: Int = 2
		public static let ROIBX: Int = 3
		public static let ROIBY: Int = 4
		public static let ROICX: Int = 5
		public static let ROICY: Int = 6
		public static let ROIDX: Int = 7
		public static let ROIDY: Int = 8

		public init(
					_ roiAx: Int = 0
					, _ roiAy: Int = 0
					, _ roiBx: Int = 0
					, _ roiBy: Int = 0
					, _ roiCx: Int = 0
					, _ roiCy: Int = 0
					, _ roiDx: Int = 0
					, _ roiDy: Int = 0
				) {
			self.roiAx = roiAx
			self.roiAy = roiAy
			self.roiBx = roiBx
			self.roiBy = roiBy
			self.roiCx = roiCx
			self.roiCy = roiCy
			self.roiDx = roiDx
			self.roiDy = roiDy

			super.init()

			mask = [ContIacCorner.ROIAX, ContIacCorner.ROIAY, ContIacCorner.ROIBX, ContIacCorner.ROIBY, ContIacCorner.ROICX, ContIacCorner.ROICY, ContIacCorner.ROIDX, ContIacCorner.ROIDY]
		}

		public var roiAx: Int
		public var roiAy: Int
		public var roiBx: Int
		public var roiBy: Int
		public var roiCx: Int
		public var roiCy: Int
		public var roiDx: Int
		public var roiDy: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskLiv2DViewCorner")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskLiv2DViewCorner"

			if valid {
				roiAx = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiAx", &mask, ContIacCorner.ROIAX)
				roiAy = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiAy", &mask, ContIacCorner.ROIAY)
				roiBx = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiBx", &mask, ContIacCorner.ROIBX)
				roiBy = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiBy", &mask, ContIacCorner.ROIBY)
				roiCx = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiCx", &mask, ContIacCorner.ROICX)
				roiCy = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiCy", &mask, ContIacCorner.ROICY)
				roiDx = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiDx", &mask, ContIacCorner.ROIDX)
				roiDy = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiDy", &mask, ContIacCorner.ROIDY)
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
			if tag == nil {tag = "ContIacWzskLiv2DViewCorner"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskLiv2DViewCorner"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiAx", roiAx)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiAy", roiAy)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiBx", roiBx)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiBy", roiBy)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiCx", roiCx)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiCy", roiCy)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiDx", roiDx)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiDy", roiDy)
		}

		public func comm(
					_ comp: ContIacCorner
				) -> Set<Int> {
			var items: Set<Int> = []

			if roiAx == comp.roiAx {items.insert(ContIacCorner.ROIAX)}
			if roiAy == comp.roiAy {items.insert(ContIacCorner.ROIAY)}
			if roiBx == comp.roiBx {items.insert(ContIacCorner.ROIBX)}
			if roiBy == comp.roiBy {items.insert(ContIacCorner.ROIBY)}
			if roiCx == comp.roiCx {items.insert(ContIacCorner.ROICX)}
			if roiCy == comp.roiCy {items.insert(ContIacCorner.ROICY)}
			if roiDx == comp.roiDx {items.insert(ContIacCorner.ROIDX)}
			if roiDy == comp.roiDy {items.insert(ContIacCorner.ROIDY)}

			return items
		}

		public func diff(
					_ comp: ContIacCorner
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIacCorner.ROIAX, ContIacCorner.ROIAY, ContIacCorner.ROIBX, ContIacCorner.ROIBY, ContIacCorner.ROICX, ContIacCorner.ROICY, ContIacCorner.ROIDX, ContIacCorner.ROIDY]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContIacTrace (full: ContIacWzskLiv2DViewTrace)
	  */
	public class ContIacTrace: Block {

		public static let ROIAX: Int = 1
		public static let ROIAY: Int = 2
		public static let ROIBX: Int = 3
		public static let ROIBY: Int = 4
		public static let ROICX: Int = 5
		public static let ROICY: Int = 6
		public static let ROIDX: Int = 7
		public static let ROIDY: Int = 8

		public init(
					_ roiAx: Int = 0
					, _ roiAy: Int = 0
					, _ roiBx: Int = 0
					, _ roiBy: Int = 0
					, _ roiCx: Int = 0
					, _ roiCy: Int = 0
					, _ roiDx: Int = 0
					, _ roiDy: Int = 0
				) {
			self.roiAx = roiAx
			self.roiAy = roiAy
			self.roiBx = roiBx
			self.roiBy = roiBy
			self.roiCx = roiCx
			self.roiCy = roiCy
			self.roiDx = roiDx
			self.roiDy = roiDy

			super.init()

			mask = [ContIacTrace.ROIAX, ContIacTrace.ROIAY, ContIacTrace.ROIBX, ContIacTrace.ROIBY, ContIacTrace.ROICX, ContIacTrace.ROICY, ContIacTrace.ROIDX, ContIacTrace.ROIDY]
		}

		public var roiAx: Int
		public var roiAy: Int
		public var roiBx: Int
		public var roiBy: Int
		public var roiCx: Int
		public var roiCy: Int
		public var roiDx: Int
		public var roiDy: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskLiv2DViewTrace")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskLiv2DViewTrace"

			if valid {
				roiAx = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiAx", &mask, ContIacTrace.ROIAX)
				roiAy = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiAy", &mask, ContIacTrace.ROIAY)
				roiBx = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiBx", &mask, ContIacTrace.ROIBX)
				roiBy = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiBy", &mask, ContIacTrace.ROIBY)
				roiCx = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiCx", &mask, ContIacTrace.ROICX)
				roiCy = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiCy", &mask, ContIacTrace.ROICY)
				roiDx = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiDx", &mask, ContIacTrace.ROIDX)
				roiDy = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "roiDy", &mask, ContIacTrace.ROIDY)
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
			if tag == nil {tag = "ContIacWzskLiv2DViewTrace"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskLiv2DViewTrace"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiAx", roiAx)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiAy", roiAy)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiBx", roiBx)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiBy", roiBy)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiCx", roiCx)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiCy", roiCy)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiDx", roiDx)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "roiDy", roiDy)
		}

		public func comm(
					_ comp: ContIacTrace
				) -> Set<Int> {
			var items: Set<Int> = []

			if roiAx == comp.roiAx {items.insert(ContIacTrace.ROIAX)}
			if roiAy == comp.roiAy {items.insert(ContIacTrace.ROIAY)}
			if roiBx == comp.roiBx {items.insert(ContIacTrace.ROIBX)}
			if roiBy == comp.roiBy {items.insert(ContIacTrace.ROIBY)}
			if roiCx == comp.roiCx {items.insert(ContIacTrace.ROICX)}
			if roiCy == comp.roiCy {items.insert(ContIacTrace.ROICY)}
			if roiDx == comp.roiDx {items.insert(ContIacTrace.ROIDX)}
			if roiDy == comp.roiDy {items.insert(ContIacTrace.ROIDY)}

			return items
		}

		public func diff(
					_ comp: ContIacTrace
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIacTrace.ROIAX, ContIacTrace.ROIAY, ContIacTrace.ROIBX, ContIacTrace.ROIBY, ContIacTrace.ROICX, ContIacTrace.ROICY, ContIacTrace.ROIDX, ContIacTrace.ROIDY]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * ContInf (full: ContInfWzskLiv2DView)
	  */
	public class ContInf: Block {

		public static let BUTCLAIMON: Int = 1
		public static let TXTOAF: Int = 2
		public static let BUTTCCON: Int = 3
		public static let BUTTCWON: Int = 4
		public static let BUTLLEON: Int = 5
		public static let BUTLRION: Int = 6
		public static let BUTLTRON: Int = 7
		public static let BUTPICON: Int = 8

		public init(
					_ ButClaimOn: Bool = false
					, _ TxtOaf: String = ""
					, _ ButTccOn: Bool = false
					, _ ButTcwOn: Bool = false
					, _ ButLleOn: Bool = false
					, _ ButLriOn: Bool = false
					, _ ButLtrOn: Bool = false
					, _ ButPicOn: Bool = false
				) {
			self.ButClaimOn = ButClaimOn
			self.TxtOaf = TxtOaf
			self.ButTccOn = ButTccOn
			self.ButTcwOn = ButTcwOn
			self.ButLleOn = ButLleOn
			self.ButLriOn = ButLriOn
			self.ButLtrOn = ButLtrOn
			self.ButPicOn = ButPicOn

			super.init()

			mask = [ContInf.BUTCLAIMON, ContInf.TXTOAF, ContInf.BUTTCCON, ContInf.BUTTCWON, ContInf.BUTLLEON, ContInf.BUTLRION, ContInf.BUTLTRON, ContInf.BUTPICON]
		}

		public var ButClaimOn: Bool
		public var TxtOaf: String
		public var ButTccOn: Bool
		public var ButTcwOn: Bool
		public var ButLleOn: Bool
		public var ButLriOn: Bool
		public var ButLtrOn: Bool
		public var ButPicOn: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskLiv2DView")}
			valid = basexpath != nil

			let itemtag: String = "ContitemInfWzskLiv2DView"

			if valid {
				ButClaimOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimOn", &mask, ContInf.BUTCLAIMON)
				TxtOaf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtOaf", &mask, ContInf.TXTOAF)
				ButTccOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButTccOn", &mask, ContInf.BUTTCCON)
				ButTcwOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButTcwOn", &mask, ContInf.BUTTCWON)
				ButLleOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButLleOn", &mask, ContInf.BUTLLEON)
				ButLriOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButLriOn", &mask, ContInf.BUTLRION)
				ButLtrOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButLtrOn", &mask, ContInf.BUTLTRON)
				ButPicOn = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButPicOn", &mask, ContInf.BUTPICON)
			}

			return valid
		}

		public func comm(
					_ comp: ContInf
				) -> Set<Int> {
			var items: Set<Int> = []

			if ButClaimOn == comp.ButClaimOn {items.insert(ContInf.BUTCLAIMON)}
			if TxtOaf == comp.TxtOaf {items.insert(ContInf.TXTOAF)}
			if ButTccOn == comp.ButTccOn {items.insert(ContInf.BUTTCCON)}
			if ButTcwOn == comp.ButTcwOn {items.insert(ContInf.BUTTCWON)}
			if ButLleOn == comp.ButLleOn {items.insert(ContInf.BUTLLEON)}
			if ButLriOn == comp.ButLriOn {items.insert(ContInf.BUTLRION)}
			if ButLtrOn == comp.ButLtrOn {items.insert(ContInf.BUTLTRON)}
			if ButPicOn == comp.ButPicOn {items.insert(ContInf.BUTPICON)}

			return items
		}

		public func diff(
					_ comp: ContInf
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContInf.BUTCLAIMON, ContInf.TXTOAF, ContInf.BUTTCCON, ContInf.BUTTCWON, ContInf.BUTLLEON, ContInf.BUTLRION, ContInf.BUTLTRON, ContInf.BUTPICON]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskLiv2DView)
	  */
	public class StatShr: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let BUTCLAIMACTIVE: Int = 2
		public static let BUTPLAYACTIVE: Int = 3
		public static let BUTSTOPACTIVE: Int = 4
		public static let CHKAEXACTIVE: Int = 5
		public static let SLDEXTAVAIL: Int = 6
		public static let SLDEXTACTIVE: Int = 7
		public static let SLDEXTMIN: Int = 8
		public static let SLDEXTMAX: Int = 9
		public static let SLDEXTRAST: Int = 10
		public static let SLDFCSACTIVE: Int = 11
		public static let SLDFCSMIN: Int = 12
		public static let SLDFCSMAX: Int = 13
		public static let TXTOAFAVAIL: Int = 14
		public static let BUTSTSACTIVE: Int = 15
		public static let UPDLLOAVAIL: Int = 16
		public static let UPDLLOMIN: Int = 17
		public static let UPDLLOMAX: Int = 18
		public static let UPDLUOAVAIL: Int = 19
		public static let UPDLUOMIN: Int = 20
		public static let UPDLUOMAX: Int = 21
		public static let UPDLMDAVAIL: Int = 22
		public static let UPDLMDMIN: Int = 23
		public static let UPDLMDMAX: Int = 24
		public static let UPDPNTMIN: Int = 25
		public static let UPDPNTMAX: Int = 26
		public static let SLDCWDMIN: Int = 27
		public static let SLDCWDMAX: Int = 28
		public static let SLDCWDRAST: Int = 29

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ ButClaimActive: Bool = false
					, _ ButPlayActive: Bool = false
					, _ ButStopActive: Bool = false
					, _ ChkAexActive: Bool = false
					, _ SldExtAvail: Bool = false
					, _ SldExtActive: Bool = false
					, _ SldExtMin: Double = 0.0
					, _ SldExtMax: Double = 0.0
					, _ SldExtRast: Double = 0.0
					, _ SldFcsActive: Bool = false
					, _ SldFcsMin: Double = 0.0
					, _ SldFcsMax: Double = 0.0
					, _ TxtOafAvail: Bool = false
					, _ ButStsActive: Bool = false
					, _ UpdLloAvail: Bool = false
					, _ UpdLloMin: Int = 0
					, _ UpdLloMax: Int = 0
					, _ UpdLuoAvail: Bool = false
					, _ UpdLuoMin: Int = 0
					, _ UpdLuoMax: Int = 0
					, _ UpdLmdAvail: Bool = false
					, _ UpdLmdMin: Int = 0
					, _ UpdLmdMax: Int = 0
					, _ UpdPntMin: Int = 0
					, _ UpdPntMax: Int = 0
					, _ SldCwdMin: Double = 0.0
					, _ SldCwdMax: Double = 0.0
					, _ SldCwdRast: Double = 0.0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.ButClaimActive = ButClaimActive
			self.ButPlayActive = ButPlayActive
			self.ButStopActive = ButStopActive
			self.ChkAexActive = ChkAexActive
			self.SldExtAvail = SldExtAvail
			self.SldExtActive = SldExtActive
			self.SldExtMin = SldExtMin
			self.SldExtMax = SldExtMax
			self.SldExtRast = SldExtRast
			self.SldFcsActive = SldFcsActive
			self.SldFcsMin = SldFcsMin
			self.SldFcsMax = SldFcsMax
			self.TxtOafAvail = TxtOafAvail
			self.ButStsActive = ButStsActive
			self.UpdLloAvail = UpdLloAvail
			self.UpdLloMin = UpdLloMin
			self.UpdLloMax = UpdLloMax
			self.UpdLuoAvail = UpdLuoAvail
			self.UpdLuoMin = UpdLuoMin
			self.UpdLuoMax = UpdLuoMax
			self.UpdLmdAvail = UpdLmdAvail
			self.UpdLmdMin = UpdLmdMin
			self.UpdLmdMax = UpdLmdMax
			self.UpdPntMin = UpdPntMin
			self.UpdPntMax = UpdPntMax
			self.SldCwdMin = SldCwdMin
			self.SldCwdMax = SldCwdMax
			self.SldCwdRast = SldCwdRast

			super.init()

			mask = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.BUTPLAYACTIVE, StatShr.BUTSTOPACTIVE, StatShr.CHKAEXACTIVE, StatShr.SLDEXTAVAIL, StatShr.SLDEXTACTIVE, StatShr.SLDEXTMIN, StatShr.SLDEXTMAX, StatShr.SLDEXTRAST, StatShr.SLDFCSACTIVE, StatShr.SLDFCSMIN, StatShr.SLDFCSMAX, StatShr.TXTOAFAVAIL, StatShr.BUTSTSACTIVE, StatShr.UPDLLOAVAIL, StatShr.UPDLLOMIN, StatShr.UPDLLOMAX, StatShr.UPDLUOAVAIL, StatShr.UPDLUOMIN, StatShr.UPDLUOMAX, StatShr.UPDLMDAVAIL, StatShr.UPDLMDMIN, StatShr.UPDLMDMAX, StatShr.UPDPNTMIN, StatShr.UPDPNTMAX, StatShr.SLDCWDMIN, StatShr.SLDCWDMAX, StatShr.SLDCWDRAST]
		}

		public var ixWzskVExpstate: Int
		public var ButClaimActive: Bool
		public var ButPlayActive: Bool
		public var ButStopActive: Bool
		public var ChkAexActive: Bool
		public var SldExtAvail: Bool
		public var SldExtActive: Bool
		public var SldExtMin: Double
		public var SldExtMax: Double
		public var SldExtRast: Double
		public var SldFcsActive: Bool
		public var SldFcsMin: Double
		public var SldFcsMax: Double
		public var TxtOafAvail: Bool
		public var ButStsActive: Bool
		public var UpdLloAvail: Bool
		public var UpdLloMin: Int
		public var UpdLloMax: Int
		public var UpdLuoAvail: Bool
		public var UpdLuoMin: Int
		public var UpdLuoMax: Int
		public var UpdLmdAvail: Bool
		public var UpdLmdMin: Int
		public var UpdLmdMax: Int
		public var UpdPntMin: Int
		public var UpdPntMax: Int
		public var SldCwdMin: Double
		public var SldCwdMax: Double
		public var SldCwdRast: Double

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskLiv2DView")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskLiv2DView"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatShr.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				ButClaimActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButClaimActive", &mask, StatShr.BUTCLAIMACTIVE)
				ButPlayActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButPlayActive", &mask, StatShr.BUTPLAYACTIVE)
				ButStopActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButStopActive", &mask, StatShr.BUTSTOPACTIVE)
				ChkAexActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ChkAexActive", &mask, StatShr.CHKAEXACTIVE)
				SldExtAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtAvail", &mask, StatShr.SLDEXTAVAIL)
				SldExtActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtActive", &mask, StatShr.SLDEXTACTIVE)
				SldExtMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtMin", &mask, StatShr.SLDEXTMIN)
				SldExtMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtMax", &mask, StatShr.SLDEXTMAX)
				SldExtRast = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldExtRast", &mask, StatShr.SLDEXTRAST)
				SldFcsActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldFcsActive", &mask, StatShr.SLDFCSACTIVE)
				SldFcsMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldFcsMin", &mask, StatShr.SLDFCSMIN)
				SldFcsMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldFcsMax", &mask, StatShr.SLDFCSMAX)
				TxtOafAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtOafAvail", &mask, StatShr.TXTOAFAVAIL)
				ButStsActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButStsActive", &mask, StatShr.BUTSTSACTIVE)
				UpdLloAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLloAvail", &mask, StatShr.UPDLLOAVAIL)
				UpdLloMin = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLloMin", &mask, StatShr.UPDLLOMIN)
				UpdLloMax = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLloMax", &mask, StatShr.UPDLLOMAX)
				UpdLuoAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLuoAvail", &mask, StatShr.UPDLUOAVAIL)
				UpdLuoMin = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLuoMin", &mask, StatShr.UPDLUOMIN)
				UpdLuoMax = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLuoMax", &mask, StatShr.UPDLUOMAX)
				UpdLmdAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLmdAvail", &mask, StatShr.UPDLMDAVAIL)
				UpdLmdMin = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLmdMin", &mask, StatShr.UPDLMDMIN)
				UpdLmdMax = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdLmdMax", &mask, StatShr.UPDLMDMAX)
				UpdPntMin = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdPntMin", &mask, StatShr.UPDPNTMIN)
				UpdPntMax = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "UpdPntMax", &mask, StatShr.UPDPNTMAX)
				SldCwdMin = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldCwdMin", &mask, StatShr.SLDCWDMIN)
				SldCwdMax = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldCwdMax", &mask, StatShr.SLDCWDMAX)
				SldCwdRast = Xmlio.extractDoubleAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "SldCwdRast", &mask, StatShr.SLDCWDRAST)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatShr.IXWZSKVEXPSTATE)}
			if ButClaimActive == comp.ButClaimActive {items.insert(StatShr.BUTCLAIMACTIVE)}
			if ButPlayActive == comp.ButPlayActive {items.insert(StatShr.BUTPLAYACTIVE)}
			if ButStopActive == comp.ButStopActive {items.insert(StatShr.BUTSTOPACTIVE)}
			if ChkAexActive == comp.ChkAexActive {items.insert(StatShr.CHKAEXACTIVE)}
			if SldExtAvail == comp.SldExtAvail {items.insert(StatShr.SLDEXTAVAIL)}
			if SldExtActive == comp.SldExtActive {items.insert(StatShr.SLDEXTACTIVE)}
			if Xmlio.compareDouble(SldExtMin, comp.SldExtMin) < 1.0e-4 {items.insert(StatShr.SLDEXTMIN)}
			if Xmlio.compareDouble(SldExtMax, comp.SldExtMax) < 1.0e-4 {items.insert(StatShr.SLDEXTMAX)}
			if Xmlio.compareDouble(SldExtRast, comp.SldExtRast) < 1.0e-4 {items.insert(StatShr.SLDEXTRAST)}
			if SldFcsActive == comp.SldFcsActive {items.insert(StatShr.SLDFCSACTIVE)}
			if Xmlio.compareDouble(SldFcsMin, comp.SldFcsMin) < 1.0e-4 {items.insert(StatShr.SLDFCSMIN)}
			if Xmlio.compareDouble(SldFcsMax, comp.SldFcsMax) < 1.0e-4 {items.insert(StatShr.SLDFCSMAX)}
			if TxtOafAvail == comp.TxtOafAvail {items.insert(StatShr.TXTOAFAVAIL)}
			if ButStsActive == comp.ButStsActive {items.insert(StatShr.BUTSTSACTIVE)}
			if UpdLloAvail == comp.UpdLloAvail {items.insert(StatShr.UPDLLOAVAIL)}
			if UpdLloMin == comp.UpdLloMin {items.insert(StatShr.UPDLLOMIN)}
			if UpdLloMax == comp.UpdLloMax {items.insert(StatShr.UPDLLOMAX)}
			if UpdLuoAvail == comp.UpdLuoAvail {items.insert(StatShr.UPDLUOAVAIL)}
			if UpdLuoMin == comp.UpdLuoMin {items.insert(StatShr.UPDLUOMIN)}
			if UpdLuoMax == comp.UpdLuoMax {items.insert(StatShr.UPDLUOMAX)}
			if UpdLmdAvail == comp.UpdLmdAvail {items.insert(StatShr.UPDLMDAVAIL)}
			if UpdLmdMin == comp.UpdLmdMin {items.insert(StatShr.UPDLMDMIN)}
			if UpdLmdMax == comp.UpdLmdMax {items.insert(StatShr.UPDLMDMAX)}
			if UpdPntMin == comp.UpdPntMin {items.insert(StatShr.UPDPNTMIN)}
			if UpdPntMax == comp.UpdPntMax {items.insert(StatShr.UPDPNTMAX)}
			if Xmlio.compareDouble(SldCwdMin, comp.SldCwdMin) < 1.0e-4 {items.insert(StatShr.SLDCWDMIN)}
			if Xmlio.compareDouble(SldCwdMax, comp.SldCwdMax) < 1.0e-4 {items.insert(StatShr.SLDCWDMAX)}
			if Xmlio.compareDouble(SldCwdRast, comp.SldCwdRast) < 1.0e-4 {items.insert(StatShr.SLDCWDRAST)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.IXWZSKVEXPSTATE, StatShr.BUTCLAIMACTIVE, StatShr.BUTPLAYACTIVE, StatShr.BUTSTOPACTIVE, StatShr.CHKAEXACTIVE, StatShr.SLDEXTAVAIL, StatShr.SLDEXTACTIVE, StatShr.SLDEXTMIN, StatShr.SLDEXTMAX, StatShr.SLDEXTRAST, StatShr.SLDFCSACTIVE, StatShr.SLDFCSMIN, StatShr.SLDFCSMAX, StatShr.TXTOAFAVAIL, StatShr.BUTSTSACTIVE, StatShr.UPDLLOAVAIL, StatShr.UPDLLOMIN, StatShr.UPDLLOMAX, StatShr.UPDLUOAVAIL, StatShr.UPDLUOMIN, StatShr.UPDLUOMAX, StatShr.UPDLMDAVAIL, StatShr.UPDLMDMIN, StatShr.UPDLMDMAX, StatShr.UPDPNTMIN, StatShr.UPDPNTMAX, StatShr.SLDCWDMIN, StatShr.SLDCWDMAX, StatShr.SLDCWDRAST]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskLiv2DView)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTPVM: Int = 2
		public static let CPTAEX: Int = 3
		public static let CPTEXT: Int = 4
		public static let CPTFCS: Int = 5
		public static let CPTOAF: Int = 6
		public static let BUTSTS: Int = 7
		public static let HDGTTB: Int = 8
		public static let BUTTCC: Int = 9
		public static let BUTTCW: Int = 10
		public static let HDGLOR: Int = 11
		public static let BUTLLE: Int = 12
		public static let BUTLRI: Int = 13
		public static let CPTLLO: Int = 14
		public static let CPTLUO: Int = 15
		public static let CPTLMD: Int = 16
		public static let CPTLGL: Int = 17
		public static let CPTLRO: Int = 18
		public static let BUTLTR: Int = 19
		public static let BUTLCL: Int = 20
		public static let HDGPOS: Int = 21
		public static let CPTPNT: Int = 22
		public static let CPTPRO: Int = 23
		public static let BUTPIC: Int = 24
		public static let BUTPCL: Int = 25
		public static let HDGCLD: Int = 26
		public static let CPTCWD: Int = 27

		public init(
					_ Cpt: String = ""
					, _ CptPvm: String = ""
					, _ CptAex: String = ""
					, _ CptExt: String = ""
					, _ CptFcs: String = ""
					, _ CptOaf: String = ""
					, _ ButSts: String = ""
					, _ HdgTtb: String = ""
					, _ ButTcc: String = ""
					, _ ButTcw: String = ""
					, _ HdgLor: String = ""
					, _ ButLle: String = ""
					, _ ButLri: String = ""
					, _ CptLlo: String = ""
					, _ CptLuo: String = ""
					, _ CptLmd: String = ""
					, _ CptLgl: String = ""
					, _ CptLro: String = ""
					, _ ButLtr: String = ""
					, _ ButLcl: String = ""
					, _ HdgPos: String = ""
					, _ CptPnt: String = ""
					, _ CptPro: String = ""
					, _ ButPic: String = ""
					, _ ButPcl: String = ""
					, _ HdgCld: String = ""
					, _ CptCwd: String = ""
				) {
			self.Cpt = Cpt
			self.CptPvm = CptPvm
			self.CptAex = CptAex
			self.CptExt = CptExt
			self.CptFcs = CptFcs
			self.CptOaf = CptOaf
			self.ButSts = ButSts
			self.HdgTtb = HdgTtb
			self.ButTcc = ButTcc
			self.ButTcw = ButTcw
			self.HdgLor = HdgLor
			self.ButLle = ButLle
			self.ButLri = ButLri
			self.CptLlo = CptLlo
			self.CptLuo = CptLuo
			self.CptLmd = CptLmd
			self.CptLgl = CptLgl
			self.CptLro = CptLro
			self.ButLtr = ButLtr
			self.ButLcl = ButLcl
			self.HdgPos = HdgPos
			self.CptPnt = CptPnt
			self.CptPro = CptPro
			self.ButPic = ButPic
			self.ButPcl = ButPcl
			self.HdgCld = HdgCld
			self.CptCwd = CptCwd

			super.init()

			mask = [Tag.CPT, Tag.CPTPVM, Tag.CPTAEX, Tag.CPTEXT, Tag.CPTFCS, Tag.CPTOAF, Tag.BUTSTS, Tag.HDGTTB, Tag.BUTTCC, Tag.BUTTCW, Tag.HDGLOR, Tag.BUTLLE, Tag.BUTLRI, Tag.CPTLLO, Tag.CPTLUO, Tag.CPTLMD, Tag.CPTLGL, Tag.CPTLRO, Tag.BUTLTR, Tag.BUTLCL, Tag.HDGPOS, Tag.CPTPNT, Tag.CPTPRO, Tag.BUTPIC, Tag.BUTPCL, Tag.HDGCLD, Tag.CPTCWD]
		}

		public var Cpt: String
		public var CptPvm: String
		public var CptAex: String
		public var CptExt: String
		public var CptFcs: String
		public var CptOaf: String
		public var ButSts: String
		public var HdgTtb: String
		public var ButTcc: String
		public var ButTcw: String
		public var HdgLor: String
		public var ButLle: String
		public var ButLri: String
		public var CptLlo: String
		public var CptLuo: String
		public var CptLmd: String
		public var CptLgl: String
		public var CptLro: String
		public var ButLtr: String
		public var ButLcl: String
		public var HdgPos: String
		public var CptPnt: String
		public var CptPro: String
		public var ButPic: String
		public var ButPcl: String
		public var HdgCld: String
		public var CptCwd: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskLiv2DView")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskLiv2DView"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptPvm = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPvm", &mask, Tag.CPTPVM)
				CptAex = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptAex", &mask, Tag.CPTAEX)
				CptExt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptExt", &mask, Tag.CPTEXT)
				CptFcs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptFcs", &mask, Tag.CPTFCS)
				CptOaf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptOaf", &mask, Tag.CPTOAF)
				ButSts = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButSts", &mask, Tag.BUTSTS)
				HdgTtb = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "HdgTtb", &mask, Tag.HDGTTB)
				ButTcc = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButTcc", &mask, Tag.BUTTCC)
				ButTcw = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButTcw", &mask, Tag.BUTTCW)
				HdgLor = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "HdgLor", &mask, Tag.HDGLOR)
				ButLle = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButLle", &mask, Tag.BUTLLE)
				ButLri = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButLri", &mask, Tag.BUTLRI)
				CptLlo = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLlo", &mask, Tag.CPTLLO)
				CptLuo = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLuo", &mask, Tag.CPTLUO)
				CptLmd = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLmd", &mask, Tag.CPTLMD)
				CptLgl = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLgl", &mask, Tag.CPTLGL)
				CptLro = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptLro", &mask, Tag.CPTLRO)
				ButLtr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButLtr", &mask, Tag.BUTLTR)
				ButLcl = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButLcl", &mask, Tag.BUTLCL)
				HdgPos = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "HdgPos", &mask, Tag.HDGPOS)
				CptPnt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPnt", &mask, Tag.CPTPNT)
				CptPro = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPro", &mask, Tag.CPTPRO)
				ButPic = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButPic", &mask, Tag.BUTPIC)
				ButPcl = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "ButPcl", &mask, Tag.BUTPCL)
				HdgCld = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "HdgCld", &mask, Tag.HDGCLD)
				CptCwd = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptCwd", &mask, Tag.CPTCWD)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptPvm == comp.CptPvm {items.insert(Tag.CPTPVM)}
			if CptAex == comp.CptAex {items.insert(Tag.CPTAEX)}
			if CptExt == comp.CptExt {items.insert(Tag.CPTEXT)}
			if CptFcs == comp.CptFcs {items.insert(Tag.CPTFCS)}
			if CptOaf == comp.CptOaf {items.insert(Tag.CPTOAF)}
			if ButSts == comp.ButSts {items.insert(Tag.BUTSTS)}
			if HdgTtb == comp.HdgTtb {items.insert(Tag.HDGTTB)}
			if ButTcc == comp.ButTcc {items.insert(Tag.BUTTCC)}
			if ButTcw == comp.ButTcw {items.insert(Tag.BUTTCW)}
			if HdgLor == comp.HdgLor {items.insert(Tag.HDGLOR)}
			if ButLle == comp.ButLle {items.insert(Tag.BUTLLE)}
			if ButLri == comp.ButLri {items.insert(Tag.BUTLRI)}
			if CptLlo == comp.CptLlo {items.insert(Tag.CPTLLO)}
			if CptLuo == comp.CptLuo {items.insert(Tag.CPTLUO)}
			if CptLmd == comp.CptLmd {items.insert(Tag.CPTLMD)}
			if CptLgl == comp.CptLgl {items.insert(Tag.CPTLGL)}
			if CptLro == comp.CptLro {items.insert(Tag.CPTLRO)}
			if ButLtr == comp.ButLtr {items.insert(Tag.BUTLTR)}
			if ButLcl == comp.ButLcl {items.insert(Tag.BUTLCL)}
			if HdgPos == comp.HdgPos {items.insert(Tag.HDGPOS)}
			if CptPnt == comp.CptPnt {items.insert(Tag.CPTPNT)}
			if CptPro == comp.CptPro {items.insert(Tag.CPTPRO)}
			if ButPic == comp.ButPic {items.insert(Tag.BUTPIC)}
			if ButPcl == comp.ButPcl {items.insert(Tag.BUTPCL)}
			if HdgCld == comp.HdgCld {items.insert(Tag.HDGCLD)}
			if CptCwd == comp.CptCwd {items.insert(Tag.CPTCWD)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTPVM, Tag.CPTAEX, Tag.CPTEXT, Tag.CPTFCS, Tag.CPTOAF, Tag.BUTSTS, Tag.HDGTTB, Tag.BUTTCC, Tag.BUTTCW, Tag.HDGLOR, Tag.BUTLLE, Tag.BUTLRI, Tag.CPTLLO, Tag.CPTLUO, Tag.CPTLMD, Tag.CPTLGL, Tag.CPTLRO, Tag.BUTLTR, Tag.BUTLCL, Tag.HDGPOS, Tag.CPTPNT, Tag.CPTPRO, Tag.BUTPIC, Tag.BUTPCL, Tag.HDGCLD, Tag.CPTCWD]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppAlign (full: DpchAppWzskLiv2DViewAlign)
		*/
	public class DpchAppAlign: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIACCORNER: Int = 2
		public static let CONTIACTRACE: Int = 3
		public static let ALL: Int  = 4

		public init(
					_ scrJref: String = ""
					, _ contiaccorner: ContIacCorner? = nil
					, _ contiactrace: ContIacTrace? = nil
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPWZSKLIV2DVIEWALIGN, scrJref)

			if mask.contains(DpchAppAlign.ALL) {self.mask = [DpchAppAlign.SCRJREF, DpchAppAlign.CONTIACCORNER, DpchAppAlign.CONTIACTRACE]}
			else {self.mask = mask}

			if has(DpchAppAlign.CONTIACCORNER) {if contiaccorner != nil {self.contiaccorner = contiaccorner!}}
			if has(DpchAppAlign.CONTIACTRACE) {if contiactrace != nil {self.contiactrace = contiactrace!}}
		}

		public var contiaccorner: ContIacCorner = ContIacCorner()
		public var contiactrace: ContIacTrace = ContIacTrace()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchAppAlign.SCRJREF) {ss.append("scrJref")}
			if has(DpchAppAlign.CONTIACCORNER) {ss.append("contiaccorner")}
			if has(DpchAppAlign.CONTIACTRACE) {ss.append("contiactrace")}

			return StrMod.vectorToString(ss)
		}

		public override func writeXML(
					_ doc: XMLDocument
					, _ sup: XMLElement?
				) {
			let el = XMLElement(name: "DpchAppWzskLiv2DViewAlign")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppAlign.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppAlign.CONTIACCORNER) {contiaccorner.writeXML(doc, el, "", true)}
			if has(DpchAppAlign.CONTIACTRACE) {contiactrace.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskLiv2DViewData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLIV2DVIEWDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLiv2DViewData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskLiv2DViewDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKLIV2DVIEWDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskLiv2DViewDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngAlign (full: DpchEngWzskLiv2DViewAlign)
		*/
	public class DpchEngAlign: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIACCORNER: Int = 2
		public static let CONTIACTRACE: Int = 3

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLIV2DVIEWALIGN)
		}

		public var contiaccorner: ContIacCorner = ContIacCorner()
		public var contiactrace: ContIacTrace = ContIacTrace()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngAlign.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngAlign.CONTIACCORNER) {ss.append("contiaccorner")}
			if has(DpchEngAlign.CONTIACTRACE) {ss.append("contiactrace")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLiv2DViewAlign")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngAlign.SCRJREF)
				if contiaccorner.readXML(doc, basexpath!, true) {add(DpchEngAlign.CONTIACCORNER)}
				if contiactrace.readXML(doc, basexpath!, true) {add(DpchEngAlign.CONTIACTRACE)}
			} else {
				scrJref = ""
				contiaccorner = ContIacCorner()
				contiactrace = ContIacTrace()
			}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskLiv2DViewData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let CONTINF: Int = 3
		public static let FEEDFPUPPVM: Int = 4
		public static let STATSHR: Int = 5
		public static let TAG: Int = 6

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLIV2DVIEWDATA)
		}

		public var contiac: ContIac = ContIac()
		public var continf: ContInf = ContInf()
		public var feedFPupPvm: Feed = Feed("FeedFPupPvm")
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.CONTINF) {ss.append("continf")}
			if has(DpchEngData.FEEDFPUPPVM) {ss.append("feedFPupPvm")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLiv2DViewData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if continf.readXML(doc, basexpath!, true) {add(DpchEngData.CONTINF)}
				if feedFPupPvm.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFPUPPVM)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				continf = ContInf()
				feedFPupPvm = Feed("FeedFPupPvm")
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

	/**
		* DpchEngLive (full: DpchEngWzskLiv2DViewLive)
		*/
	public class DpchEngLive: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let GRAY: Int = 2
		public static let RED: Int = 3
		public static let GREEN: Int = 4
		public static let BLUE: Int = 5
		public static let XCORNER: Int = 6
		public static let YCORNER: Int = 7
		public static let XTRACEL: Int = 8
		public static let YTRACEL: Int = 9
		public static let XTRACER: Int = 10
		public static let YTRACER: Int = 11

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKLIV2DVIEWLIVE)
		}

		public var gray: [UInt8] = [UInt8]()

		public var red: [UInt8] = [UInt8]()
		public var green: [UInt8] = [UInt8]()
		public var blue: [UInt8] = [UInt8]()

		public var xCorner: [Int32] = [Int32]()
		public var yCorner: [Int32] = [Int32]()

		public var xTraceL: [Int32] = [Int32]()
		public var yTraceL: [Int32] = [Int32]()

		public var xTraceR: [Int32] = [Int32]()
		public var yTraceR: [Int32] = [Int32]()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngLive.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngLive.GRAY) {ss.append("gray")}
			if has(DpchEngLive.RED) {ss.append("red")}
			if has(DpchEngLive.GREEN) {ss.append("green")}
			if has(DpchEngLive.BLUE) {ss.append("blue")}
			if has(DpchEngLive.XCORNER) {ss.append("xCorner")}
			if has(DpchEngLive.YCORNER) {ss.append("yCorner")}
			if has(DpchEngLive.XTRACEL) {ss.append("xTraceL")}
			if has(DpchEngLive.YTRACEL) {ss.append("yTraceL")}
			if has(DpchEngLive.XTRACER) {ss.append("xTraceR")}
			if has(DpchEngLive.YTRACER) {ss.append("yTraceR")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskLiv2DViewLive")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngLive.SCRJREF)
				gray = Xmlio.extractUtinyintvecUclc(doc, basexpath!, "gray", "", &mask, DpchEngLive.GRAY)
				red = Xmlio.extractUtinyintvecUclc(doc, basexpath!, "red", "", &mask, DpchEngLive.RED)
				green = Xmlio.extractUtinyintvecUclc(doc, basexpath!, "green", "", &mask, DpchEngLive.GREEN)
				blue = Xmlio.extractUtinyintvecUclc(doc, basexpath!, "blue", "", &mask, DpchEngLive.BLUE)
				xCorner = Xmlio.extractIntvecUclc(doc, basexpath!, "xCorner", "", &mask, DpchEngLive.XCORNER)
				yCorner = Xmlio.extractIntvecUclc(doc, basexpath!, "yCorner", "", &mask, DpchEngLive.YCORNER)
				xTraceL = Xmlio.extractIntvecUclc(doc, basexpath!, "xTraceL", "", &mask, DpchEngLive.XTRACEL)
				yTraceL = Xmlio.extractIntvecUclc(doc, basexpath!, "yTraceL", "", &mask, DpchEngLive.YTRACEL)
				xTraceR = Xmlio.extractIntvecUclc(doc, basexpath!, "xTraceR", "", &mask, DpchEngLive.XTRACER)
				yTraceR = Xmlio.extractIntvecUclc(doc, basexpath!, "yTraceR", "", &mask, DpchEngLive.YTRACER)
			} else {
				scrJref = ""
				gray = [UInt8]()
				red = [UInt8]()
				green = [UInt8]()
				blue = [UInt8]()
				xCorner = [Int32]()
				yCorner = [Int32]()
				xTraceL = [Int32]()
				yTraceL = [Int32]()
				xTraceR = [Int32]()
				yTraceR = [Int32]()
			}
		}

	}

}
