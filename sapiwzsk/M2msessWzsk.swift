/**
  * \file M2msessWzsk.swift
  * Swift API code for job M2msessWzsk
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* M2msessWzsk
	*/
public class M2msessWzsk {
	/**
	  * StatShr (full: StatShrM2msessWzsk)
	  */
	public class StatShr: Block {

		public static let SCRJREFACQPREVIEW: Int = 1
		public static let SCRJREFACQPTCLOUD: Int = 2
		public static let SCRJREFACTEXPOSURE: Int = 3
		public static let SCRJREFACTLASER: Int = 4
		public static let SCRJREFACTSERVO: Int = 5
		public static let SCRJREFIPRCORNER: Int = 6
		public static let SCRJREFIPRTRACE: Int = 7
		public static let SCRJREFSRCSYSINFO: Int = 8

		public init(
					_ scrJrefAcqpreview: String = ""
					, _ scrJrefAcqptcloud: String = ""
					, _ scrJrefActexposure: String = ""
					, _ scrJrefActlaser: String = ""
					, _ scrJrefActservo: String = ""
					, _ scrJrefIprcorner: String = ""
					, _ scrJrefIprtrace: String = ""
					, _ scrJrefSrcsysinfo: String = ""
				) {
			self.scrJrefAcqpreview = scrJrefAcqpreview
			self.scrJrefAcqptcloud = scrJrefAcqptcloud
			self.scrJrefActexposure = scrJrefActexposure
			self.scrJrefActlaser = scrJrefActlaser
			self.scrJrefActservo = scrJrefActservo
			self.scrJrefIprcorner = scrJrefIprcorner
			self.scrJrefIprtrace = scrJrefIprtrace
			self.scrJrefSrcsysinfo = scrJrefSrcsysinfo

			super.init()

			mask = [StatShr.SCRJREFACQPREVIEW, StatShr.SCRJREFACQPTCLOUD, StatShr.SCRJREFACTEXPOSURE, StatShr.SCRJREFACTLASER, StatShr.SCRJREFACTSERVO, StatShr.SCRJREFIPRCORNER, StatShr.SCRJREFIPRTRACE, StatShr.SCRJREFSRCSYSINFO]
		}

		public var scrJrefAcqpreview: String
		public var scrJrefAcqptcloud: String
		public var scrJrefActexposure: String
		public var scrJrefActlaser: String
		public var scrJrefActservo: String
		public var scrJrefIprcorner: String
		public var scrJrefIprtrace: String
		public var scrJrefSrcsysinfo: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrM2msessWzsk")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrM2msessWzsk"

			if valid {
				scrJrefAcqpreview = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefAcqpreview", &mask, StatShr.SCRJREFACQPREVIEW)
				scrJrefAcqptcloud = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefAcqptcloud", &mask, StatShr.SCRJREFACQPTCLOUD)
				scrJrefActexposure = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefActexposure", &mask, StatShr.SCRJREFACTEXPOSURE)
				scrJrefActlaser = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefActlaser", &mask, StatShr.SCRJREFACTLASER)
				scrJrefActservo = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefActservo", &mask, StatShr.SCRJREFACTSERVO)
				scrJrefIprcorner = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefIprcorner", &mask, StatShr.SCRJREFIPRCORNER)
				scrJrefIprtrace = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefIprtrace", &mask, StatShr.SCRJREFIPRTRACE)
				scrJrefSrcsysinfo = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "scrJrefSrcsysinfo", &mask, StatShr.SCRJREFSRCSYSINFO)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if scrJrefAcqpreview == comp.scrJrefAcqpreview {items.insert(StatShr.SCRJREFACQPREVIEW)}
			if scrJrefAcqptcloud == comp.scrJrefAcqptcloud {items.insert(StatShr.SCRJREFACQPTCLOUD)}
			if scrJrefActexposure == comp.scrJrefActexposure {items.insert(StatShr.SCRJREFACTEXPOSURE)}
			if scrJrefActlaser == comp.scrJrefActlaser {items.insert(StatShr.SCRJREFACTLASER)}
			if scrJrefActservo == comp.scrJrefActservo {items.insert(StatShr.SCRJREFACTSERVO)}
			if scrJrefIprcorner == comp.scrJrefIprcorner {items.insert(StatShr.SCRJREFIPRCORNER)}
			if scrJrefIprtrace == comp.scrJrefIprtrace {items.insert(StatShr.SCRJREFIPRTRACE)}
			if scrJrefSrcsysinfo == comp.scrJrefSrcsysinfo {items.insert(StatShr.SCRJREFSRCSYSINFO)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.SCRJREFACQPREVIEW, StatShr.SCRJREFACQPTCLOUD, StatShr.SCRJREFACTEXPOSURE, StatShr.SCRJREFACTLASER, StatShr.SCRJREFACTSERVO, StatShr.SCRJREFIPRCORNER, StatShr.SCRJREFIPRTRACE, StatShr.SCRJREFSRCSYSINFO]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchEngData (full: DpchEngM2msessWzskData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let STATSHR: Int = 2

		public init() {
			super.init(VecWzskVDpch.DPCHENGM2MSESSWZSKDATA)
		}

		public var statshr: StatShr = StatShr()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.STATSHR) {ss.append("statshr")}

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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngM2msessWzskData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
			} else {
				scrJref = ""
				statshr = StatShr()
			}
		}

	}

}
