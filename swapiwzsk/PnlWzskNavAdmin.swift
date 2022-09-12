/**
  * \file PnlWzskNavAdmin.swift
  * Swift API code for job PnlWzskNavAdmin
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* PnlWzskNavAdmin
	*/
public class PnlWzskNavAdmin {
	/**
		* VecVDo (full: VecVWzskNavAdminDo)
		*/
	public class VecVDo {

		public static let BUTUSGVIEWCLICK: Int = 1
		public static let BUTUSGNEWCRDCLICK: Int = 2
		public static let BUTUSRVIEWCLICK: Int = 3
		public static let BUTUSRNEWCRDCLICK: Int = 4
		public static let BUTPRSVIEWCLICK: Int = 5
		public static let BUTPRSNEWCRDCLICK: Int = 6
		public static let BUTSCFNEWCRDCLICK: Int = 7

		public static func getIx(
					_ sref: String
				) -> Int {
			let s: String = sref.lowercased()

			if s == "butusgviewclick" {return BUTUSGVIEWCLICK}
			if s == "butusgnewcrdclick" {return BUTUSGNEWCRDCLICK}
			if s == "butusrviewclick" {return BUTUSRVIEWCLICK}
			if s == "butusrnewcrdclick" {return BUTUSRNEWCRDCLICK}
			if s == "butprsviewclick" {return BUTPRSVIEWCLICK}
			if s == "butprsnewcrdclick" {return BUTPRSNEWCRDCLICK}
			if s == "butscfnewcrdclick" {return BUTSCFNEWCRDCLICK}

			return 0
		}

		public static func getSref(
					_ ix: Int
				) -> String {
			if ix == BUTUSGVIEWCLICK {return "ButUsgViewClick"}
			if ix == BUTUSGNEWCRDCLICK {return "ButUsgNewcrdClick"}
			if ix == BUTUSRVIEWCLICK {return "ButUsrViewClick"}
			if ix == BUTUSRNEWCRDCLICK {return "ButUsrNewcrdClick"}
			if ix == BUTPRSVIEWCLICK {return "ButPrsViewClick"}
			if ix == BUTPRSNEWCRDCLICK {return "ButPrsNewcrdClick"}
			if ix == BUTSCFNEWCRDCLICK {return "ButScfNewcrdClick"}

			return ""
		}

	}

	/**
	  * ContIac (full: ContIacWzskNavAdmin)
	  */
	public class ContIac: Block {

		public static let NUMFLSTUSG: Int = 1
		public static let NUMFLSTUSR: Int = 2
		public static let NUMFLSTPRS: Int = 3

		public init(
					_ numFLstUsg: Int = 0
					, _ numFLstUsr: Int = 0
					, _ numFLstPrs: Int = 0
				) {
			self.numFLstUsg = numFLstUsg
			self.numFLstUsr = numFLstUsr
			self.numFLstPrs = numFLstPrs

			super.init()

			mask = [ContIac.NUMFLSTUSG, ContIac.NUMFLSTUSR, ContIac.NUMFLSTPRS]
		}

		public var numFLstUsg: Int
		public var numFLstUsr: Int
		public var numFLstPrs: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContIacWzskNavAdmin")}
			valid = basexpath != nil

			let itemtag: String = "ContitemIacWzskNavAdmin"

			if valid {
				numFLstUsg = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstUsg", &mask, ContIac.NUMFLSTUSG)
				numFLstUsr = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstUsr", &mask, ContIac.NUMFLSTUSR)
				numFLstPrs = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "numFLstPrs", &mask, ContIac.NUMFLSTPRS)
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
			if tag == nil {tag = "ContIacWzskNavAdmin"}

			let itemtag: String = shorttags ? "Ci" : "ContitemIacWzskNavAdmin"

			let el = XMLElement(name: tag!)

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstUsg", numFLstUsg)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstUsr", numFLstUsr)
			Xmlio.writeIntAttr(doc, el, itemtag, "sref", "numFLstPrs", numFLstPrs)
		}

		public func comm(
					_ comp: ContIac
				) -> Set<Int> {
			var items: Set<Int> = []

			if numFLstUsg == comp.numFLstUsg {items.insert(ContIac.NUMFLSTUSG)}
			if numFLstUsr == comp.numFLstUsr {items.insert(ContIac.NUMFLSTUSR)}
			if numFLstPrs == comp.numFLstPrs {items.insert(ContIac.NUMFLSTPRS)}

			return items
		}

		public func diff(
					_ comp: ContIac
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [ContIac.NUMFLSTUSG, ContIac.NUMFLSTUSR, ContIac.NUMFLSTPRS]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatApp (full: StatAppWzskNavAdmin)
	  */
	public class StatApp: Block {

		public static let IXWZSKVEXPSTATE: Int = 1
		public static let LSTUSGALT: Int = 2
		public static let LSTUSRALT: Int = 3
		public static let LSTPRSALT: Int = 4
		public static let LSTUSGNUMFIRSTDISP: Int = 5
		public static let LSTUSRNUMFIRSTDISP: Int = 6
		public static let LSTPRSNUMFIRSTDISP: Int = 7

		public init(
					_ ixWzskVExpstate: Int = 0
					, _ LstUsgAlt: Bool = false
					, _ LstUsrAlt: Bool = false
					, _ LstPrsAlt: Bool = false
					, _ LstUsgNumFirstdisp: Int = 0
					, _ LstUsrNumFirstdisp: Int = 0
					, _ LstPrsNumFirstdisp: Int = 0
				) {
			self.ixWzskVExpstate = ixWzskVExpstate
			self.LstUsgAlt = LstUsgAlt
			self.LstUsrAlt = LstUsrAlt
			self.LstPrsAlt = LstPrsAlt
			self.LstUsgNumFirstdisp = LstUsgNumFirstdisp
			self.LstUsrNumFirstdisp = LstUsrNumFirstdisp
			self.LstPrsNumFirstdisp = LstPrsNumFirstdisp

			super.init()

			mask = [StatApp.IXWZSKVEXPSTATE, StatApp.LSTUSGALT, StatApp.LSTUSRALT, StatApp.LSTPRSALT, StatApp.LSTUSGNUMFIRSTDISP, StatApp.LSTUSRNUMFIRSTDISP, StatApp.LSTPRSNUMFIRSTDISP]
		}

		public var ixWzskVExpstate: Int
		public var LstUsgAlt: Bool
		public var LstUsrAlt: Bool
		public var LstPrsAlt: Bool
		public var LstUsgNumFirstdisp: Int
		public var LstUsrNumFirstdisp: Int
		public var LstPrsNumFirstdisp: Int

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			var srefIxWzskVExpstate: String

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatAppWzskNavAdmin")}
			valid = basexpath != nil

			let itemtag: String = "StatitemAppWzskNavAdmin"

			if valid {
				srefIxWzskVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "srefIxWzskVExpstate", &mask, StatApp.IXWZSKVEXPSTATE)
				ixWzskVExpstate = VecWzskVExpstate.getIx(srefIxWzskVExpstate)
				LstUsgAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstUsgAlt", &mask, StatApp.LSTUSGALT)
				LstUsrAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstUsrAlt", &mask, StatApp.LSTUSRALT)
				LstPrsAlt = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstPrsAlt", &mask, StatApp.LSTPRSALT)
				LstUsgNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstUsgNumFirstdisp", &mask, StatApp.LSTUSGNUMFIRSTDISP)
				LstUsrNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstUsrNumFirstdisp", &mask, StatApp.LSTUSRNUMFIRSTDISP)
				LstPrsNumFirstdisp = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstPrsNumFirstdisp", &mask, StatApp.LSTPRSNUMFIRSTDISP)
			}

			return valid
		}

		public func comm(
					_ comp: StatApp
				) -> Set<Int> {
			var items: Set<Int> = []

			if ixWzskVExpstate == comp.ixWzskVExpstate {items.insert(StatApp.IXWZSKVEXPSTATE)}
			if LstUsgAlt == comp.LstUsgAlt {items.insert(StatApp.LSTUSGALT)}
			if LstUsrAlt == comp.LstUsrAlt {items.insert(StatApp.LSTUSRALT)}
			if LstPrsAlt == comp.LstPrsAlt {items.insert(StatApp.LSTPRSALT)}
			if LstUsgNumFirstdisp == comp.LstUsgNumFirstdisp {items.insert(StatApp.LSTUSGNUMFIRSTDISP)}
			if LstUsrNumFirstdisp == comp.LstUsrNumFirstdisp {items.insert(StatApp.LSTUSRNUMFIRSTDISP)}
			if LstPrsNumFirstdisp == comp.LstPrsNumFirstdisp {items.insert(StatApp.LSTPRSNUMFIRSTDISP)}

			return items
		}

		public func diff(
					_ comp: StatApp
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatApp.IXWZSKVEXPSTATE, StatApp.LSTUSGALT, StatApp.LSTUSRALT, StatApp.LSTPRSALT, StatApp.LSTUSGNUMFIRSTDISP, StatApp.LSTUSRNUMFIRSTDISP, StatApp.LSTPRSNUMFIRSTDISP]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * StatShr (full: StatShrWzskNavAdmin)
	  */
	public class StatShr: Block {

		public static let LSTUSGAVAIL: Int = 1
		public static let BUTUSGVIEWACTIVE: Int = 2
		public static let LSTUSRAVAIL: Int = 3
		public static let BUTUSRVIEWACTIVE: Int = 4
		public static let LSTPRSAVAIL: Int = 5
		public static let BUTPRSVIEWACTIVE: Int = 6
		public static let BUTSCFNEWCRDAVAIL: Int = 7

		public init(
					_ LstUsgAvail: Bool = false
					, _ ButUsgViewActive: Bool = false
					, _ LstUsrAvail: Bool = false
					, _ ButUsrViewActive: Bool = false
					, _ LstPrsAvail: Bool = false
					, _ ButPrsViewActive: Bool = false
					, _ ButScfNewcrdAvail: Bool = false
				) {
			self.LstUsgAvail = LstUsgAvail
			self.ButUsgViewActive = ButUsgViewActive
			self.LstUsrAvail = LstUsrAvail
			self.ButUsrViewActive = ButUsrViewActive
			self.LstPrsAvail = LstPrsAvail
			self.ButPrsViewActive = ButPrsViewActive
			self.ButScfNewcrdAvail = ButScfNewcrdAvail

			super.init()

			mask = [StatShr.LSTUSGAVAIL, StatShr.BUTUSGVIEWACTIVE, StatShr.LSTUSRAVAIL, StatShr.BUTUSRVIEWACTIVE, StatShr.LSTPRSAVAIL, StatShr.BUTPRSVIEWACTIVE, StatShr.BUTSCFNEWCRDAVAIL]
		}

		public var LstUsgAvail: Bool
		public var ButUsgViewActive: Bool
		public var LstUsrAvail: Bool
		public var ButUsrViewActive: Bool
		public var LstPrsAvail: Bool
		public var ButPrsViewActive: Bool
		public var ButScfNewcrdAvail: Bool

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StatShrWzskNavAdmin")}
			valid = basexpath != nil

			let itemtag: String = "StatitemShrWzskNavAdmin"

			if valid {
				LstUsgAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstUsgAvail", &mask, StatShr.LSTUSGAVAIL)
				ButUsgViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButUsgViewActive", &mask, StatShr.BUTUSGVIEWACTIVE)
				LstUsrAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstUsrAvail", &mask, StatShr.LSTUSRAVAIL)
				ButUsrViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButUsrViewActive", &mask, StatShr.BUTUSRVIEWACTIVE)
				LstPrsAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "LstPrsAvail", &mask, StatShr.LSTPRSAVAIL)
				ButPrsViewActive = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButPrsViewActive", &mask, StatShr.BUTPRSVIEWACTIVE)
				ButScfNewcrdAvail = Xmlio.extractBoolAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "ButScfNewcrdAvail", &mask, StatShr.BUTSCFNEWCRDAVAIL)
			}

			return valid
		}

		public func comm(
					_ comp: StatShr
				) -> Set<Int> {
			var items: Set<Int> = []

			if LstUsgAvail == comp.LstUsgAvail {items.insert(StatShr.LSTUSGAVAIL)}
			if ButUsgViewActive == comp.ButUsgViewActive {items.insert(StatShr.BUTUSGVIEWACTIVE)}
			if LstUsrAvail == comp.LstUsrAvail {items.insert(StatShr.LSTUSRAVAIL)}
			if ButUsrViewActive == comp.ButUsrViewActive {items.insert(StatShr.BUTUSRVIEWACTIVE)}
			if LstPrsAvail == comp.LstPrsAvail {items.insert(StatShr.LSTPRSAVAIL)}
			if ButPrsViewActive == comp.ButPrsViewActive {items.insert(StatShr.BUTPRSVIEWACTIVE)}
			if ButScfNewcrdAvail == comp.ButScfNewcrdAvail {items.insert(StatShr.BUTSCFNEWCRDAVAIL)}

			return items
		}

		public func diff(
					_ comp: StatShr
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [StatShr.LSTUSGAVAIL, StatShr.BUTUSGVIEWACTIVE, StatShr.LSTUSRAVAIL, StatShr.BUTUSRVIEWACTIVE, StatShr.LSTPRSAVAIL, StatShr.BUTPRSVIEWACTIVE, StatShr.BUTSCFNEWCRDAVAIL]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
	  * Tag (full: TagWzskNavAdmin)
	  */
	public class Tag: Block {

		public static let CPT: Int = 1
		public static let CPTUSG: Int = 2
		public static let CPTUSR: Int = 3
		public static let CPTPRS: Int = 4
		public static let CPTSCF: Int = 5

		public init(
					_ Cpt: String = ""
					, _ CptUsg: String = ""
					, _ CptUsr: String = ""
					, _ CptPrs: String = ""
					, _ CptScf: String = ""
				) {
			self.Cpt = Cpt
			self.CptUsg = CptUsg
			self.CptUsr = CptUsr
			self.CptPrs = CptPrs
			self.CptScf = CptScf

			super.init()

			mask = [Tag.CPT, Tag.CPTUSG, Tag.CPTUSR, Tag.CPTPRS, Tag.CPTSCF]
		}

		public var Cpt: String
		public var CptUsg: String
		public var CptUsr: String
		public var CptPrs: String
		public var CptScf: String

		public func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) -> Bool {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "TagWzskNavAdmin")}
			valid = basexpath != nil

			let itemtag: String = "TagitemzskNavAdmin"

			if valid {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "Cpt", &mask, Tag.CPT)
				CptUsg = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptUsg", &mask, Tag.CPTUSG)
				CptUsr = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptUsr", &mask, Tag.CPTUSR)
				CptPrs = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptPrs", &mask, Tag.CPTPRS)
				CptScf = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ti", "sref", "CptScf", &mask, Tag.CPTSCF)
			}

			return valid
		}

		public func comm(
					_ comp: Tag
				) -> Set<Int> {
			var items: Set<Int> = []

			if Cpt == comp.Cpt {items.insert(Tag.CPT)}
			if CptUsg == comp.CptUsg {items.insert(Tag.CPTUSG)}
			if CptUsr == comp.CptUsr {items.insert(Tag.CPTUSR)}
			if CptPrs == comp.CptPrs {items.insert(Tag.CPTPRS)}
			if CptScf == comp.CptScf {items.insert(Tag.CPTSCF)}

			return items
		}

		public func diff(
					_ comp: Tag
				) -> Set<Int> {
			let commitems: Set<Int> = comm(comp)
			var diffitems: Set<Int> = [Tag.CPT, Tag.CPTUSG, Tag.CPTUSR, Tag.CPTPRS, Tag.CPTSCF]

			for ci in commitems {diffitems.remove(ci)}

			return diffitems
		}

	}

	/**
		* DpchAppData (full: DpchAppWzskNavAdminData)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKNAVADMINDATA, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskNavAdminData")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppData.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppData.CONTIAC) {contiac.writeXML(doc, el, "", true)}
		}

	}

	/**
		* DpchAppDo (full: DpchAppWzskNavAdminDo)
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
			super.init(VecWzskVDpch.DPCHAPPWZSKNAVADMINDO, scrJref)

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
			let el = XMLElement(name: "DpchAppWzskNavAdminDo")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppDo.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppDo.IXVDO) {el.addChild(XMLElement(name: "srefIxVDo", stringValue: VecVDo.getSref(ixVDo)))}
		}

	}

	/**
		* DpchEngData (full: DpchEngWzskNavAdminData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let CONTIAC: Int = 2
		public static let FEEDFLSTPRS: Int = 3
		public static let FEEDFLSTUSG: Int = 4
		public static let FEEDFLSTUSR: Int = 5
		public static let STATAPP: Int = 6
		public static let STATSHR: Int = 7
		public static let TAG: Int = 8

		public init() {
			super.init(VecWzskVDpch.DPCHENGWZSKNAVADMINDATA)
		}

		public var contiac: ContIac = ContIac()
		public var feedFLstPrs: Feed = Feed("FeedFLstPrs")
		public var feedFLstUsg: Feed = Feed("FeedFLstUsg")
		public var feedFLstUsr: Feed = Feed("FeedFLstUsr")
		public var statapp: StatApp = StatApp()
		public var statshr: StatShr = StatShr()
		public var tag: Tag = Tag()

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.CONTIAC) {ss.append("contiac")}
			if has(DpchEngData.FEEDFLSTPRS) {ss.append("feedFLstPrs")}
			if has(DpchEngData.FEEDFLSTUSG) {ss.append("feedFLstUsg")}
			if has(DpchEngData.FEEDFLSTUSR) {ss.append("feedFLstUsr")}
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

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngWzskNavAdminData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if contiac.readXML(doc, basexpath!, true) {add(DpchEngData.CONTIAC)}
				if feedFLstPrs.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTPRS)}
				if feedFLstUsg.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTUSG)}
				if feedFLstUsr.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFLSTUSR)}
				if statapp.readXML(doc, basexpath!, true) {add(DpchEngData.STATAPP)}
				if statshr.readXML(doc, basexpath!, true) {add(DpchEngData.STATSHR)}
				if tag.readXML(doc, basexpath!, true) {add(DpchEngData.TAG)}
			} else {
				scrJref = ""
				contiac = ContIac()
				feedFLstPrs = Feed("FeedFLstPrs")
				feedFLstUsg = Feed("FeedFLstUsg")
				feedFLstUsr = Feed("FeedFLstUsr")
				statapp = StatApp()
				statshr = StatShr()
				tag = Tag()
			}
		}

	}

}
