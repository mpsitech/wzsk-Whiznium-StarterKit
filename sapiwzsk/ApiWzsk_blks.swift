/**
	* \file ApiWzsk_blks.swift
	* Wzsk Swift API package global data blocks
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* ContInfWzskAlert
	*/
public class ContInfWzskAlert: Block {
	public static let TXTCPT: Int = 1
	public static let TXTMSG1: Int = 2
	public static let TXTMSG2: Int = 3
	public static let TXTMSG3: Int = 4
	public static let TXTMSG4: Int = 5
	public static let TXTMSG5: Int = 6
	public static let TXTMSG6: Int = 7
	public static let TXTMSG7: Int = 8
	public static let TXTMSG8: Int = 9
	public static let TXTMSG9: Int = 10
	public static let TXTMSG10: Int = 11
	public static let TXTMSG11: Int = 12
	public static let TXTMSG12: Int = 13
	
	public var TxtCpt: String = ""
	public var TxtMsg1: String = ""
	public var TxtMsg2: String = ""
	public var TxtMsg3: String = ""
	public var TxtMsg4: String = ""
	public var TxtMsg5: String = ""
	public var TxtMsg6: String = ""
	public var TxtMsg7: String = ""
	public var TxtMsg8: String = ""
	public var TxtMsg9: String = ""
	public var TxtMsg10: String = ""
	public var TxtMsg11: String = ""
	public var TxtMsg12: String = ""

	public func all(
				items: Set<Int>
			) -> Bool {
		if !items.contains(ContInfWzskAlert.TXTCPT) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG1) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG2) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG3) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG4) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG5) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG6) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG7) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG8) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG9) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG10) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG11) {return false}
		if !items.contains(ContInfWzskAlert.TXTMSG12) {return false}
		
		return true
	}
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var basexpath: String? = _basexpath

		clear()

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ContInfWzskAlert")}
		valid = basexpath != nil

		let itemtag: String = "ContitemInfWzskAlert"

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			TxtCpt = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtCpt", &mask, ContInfWzskAlert.TXTCPT)
			TxtMsg1 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg1", &mask, ContInfWzskAlert.TXTMSG1)
			TxtMsg2 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg2", &mask, ContInfWzskAlert.TXTMSG2)
			TxtMsg3 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg3", &mask, ContInfWzskAlert.TXTMSG3)
			TxtMsg4 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg4", &mask, ContInfWzskAlert.TXTMSG4)
			TxtMsg5 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg5", &mask, ContInfWzskAlert.TXTMSG5)
			TxtMsg6 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg6", &mask, ContInfWzskAlert.TXTMSG6)
			TxtMsg7 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg7", &mask, ContInfWzskAlert.TXTMSG7)
			TxtMsg8 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg8", &mask, ContInfWzskAlert.TXTMSG8)
			TxtMsg9 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg9", &mask, ContInfWzskAlert.TXTMSG9)
			TxtMsg10 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg10", &mask, ContInfWzskAlert.TXTMSG10)
			TxtMsg11 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg11", &mask, ContInfWzskAlert.TXTMSG11)
			TxtMsg12 = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Ci", "sref", "TxtMsg12", &mask, ContInfWzskAlert.TXTMSG12)
		}

		return valid
	}
	
	public func compare(
				comp: ContInfWzskAlert
			) -> Set<Int> {
		var items: Set<Int> = []

		if TxtCpt == comp.TxtCpt {items.insert(ContInfWzskAlert.TXTCPT)}
		if TxtMsg1 == comp.TxtMsg1 {items.insert(ContInfWzskAlert.TXTMSG1)}
		if TxtMsg2 == comp.TxtMsg2 {items.insert(ContInfWzskAlert.TXTMSG2)}
		if TxtMsg3 == comp.TxtMsg3 {items.insert(ContInfWzskAlert.TXTMSG3)}
		if TxtMsg4 == comp.TxtMsg4 {items.insert(ContInfWzskAlert.TXTMSG4)}
		if TxtMsg5 == comp.TxtMsg5 {items.insert(ContInfWzskAlert.TXTMSG5)}
		if TxtMsg6 == comp.TxtMsg6 {items.insert(ContInfWzskAlert.TXTMSG6)}
		if TxtMsg7 == comp.TxtMsg7 {items.insert(ContInfWzskAlert.TXTMSG7)}
		if TxtMsg8 == comp.TxtMsg8 {items.insert(ContInfWzskAlert.TXTMSG8)}
		if TxtMsg9 == comp.TxtMsg9 {items.insert(ContInfWzskAlert.TXTMSG9)}
		if TxtMsg10 == comp.TxtMsg10 {items.insert(ContInfWzskAlert.TXTMSG10)}
		if TxtMsg11 == comp.TxtMsg11 {items.insert(ContInfWzskAlert.TXTMSG11)}
		if TxtMsg12 == comp.TxtMsg12 {items.insert(ContInfWzskAlert.TXTMSG12)}

		return items
	}
}

/**
	* DpchWzsk
	*/
public class DpchWzsk: Block {
	public var ixWzskVDpch: Int
	
	public init(
				_ ixWzskVDpch: Int
			) {
		self.ixWzskVDpch = ixWzskVDpch
	}
}

/**
	* DpchAppWzsk
	*/
public class DpchAppWzsk: DpchWzsk {
	public static let _SCRJREF: Int = 1

	public init(
				_ ixWzskVDpch: Int
				, _ scrJref: String
			) {
		self.scrJref = scrJref
		super.init(ixWzskVDpch)

		mask = [DpchAppWzsk._SCRJREF]
	}

	public var scrJref: String

	public func all(
				_ items: Set<Int>
			) -> Bool {
		if !items.contains(DpchAppWzsk._SCRJREF) {return false}
		
		return true
	}
	
	public func getSrefsMask() -> String {
		if has(DpchAppWzsk._SCRJREF) {return "scrJref"}

		return ""
	}

	public func writeXML(
				_ doc: XMLDocument
				, _ sup: XMLElement?
			) {
		let el = XMLElement(name: VecWzskVDpch.getSref(ixWzskVDpch))

		if sup == nil {doc.setRootElement(el)}
		else {sup!.addChild(el)}
		
		el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

		if has(DpchAppWzsk._SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
	}
}

/**
	* DpchAppWzskAlert
	*/
public class DpchAppWzskAlert: DpchAppWzsk {
	public static let SCRJREF: Int = 1
	public static let NUMFMCB: Int = 2
	public static let ALL: Int = 3

	public init(
				scrJref: String = ""
				, numFMcb: Int = 0
				, mask: Set<Int>
			) {
		self.numFMcb = numFMcb

		super.init(VecWzskVDpch.DPCHAPPWZSKALERT, scrJref)

		if mask.contains(DpchAppWzskAlert.ALL) {self.mask = [DpchAppWzskAlert.SCRJREF, DpchAppWzskAlert.NUMFMCB]}
		else {self.mask = mask}
	}

	public var numFMcb: Int

	public override func all(
				_ items: Set<Int>
			) -> Bool {
		if !items.contains(DpchAppWzskAlert.SCRJREF) {return false}
		if !items.contains(DpchAppWzskAlert.NUMFMCB) {return false}

		return true
	}

	public override func getSrefsMask() -> String {
		var ss: [String] = []

		if has(DpchAppWzskAlert.SCRJREF) {ss.append("scrJref")}
		if has(DpchAppWzskAlert.NUMFMCB) {ss.append("numFMcb")}

		return StrMod.vectorToString(ss)
	}

	public override func writeXML(
				_ doc: XMLDocument
				, _ sup: XMLElement?
			) {
		let el = XMLElement(name: VecWzskVDpch.getSref(ixWzskVDpch))

		if sup == nil {doc.setRootElement(el)}
		else {sup!.addChild(el)}
		
		el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

		if has(DpchAppWzskAlert.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
		if has(DpchAppWzskAlert.NUMFMCB) {el.addChild(XMLElement(name: "numFMcb", stringValue: String(numFMcb)))}
	}
}

/**
	* DpchAppWzskInit
	*/
public class DpchAppWzskInit: DpchAppWzsk {

	public init(
				scrJref: String
			) {
		super.init(VecWzskVDpch.DPCHAPPWZSKINIT, scrJref)
	}
}

/**
	* DpchAppWzskResume
	*/
public class DpchAppWzskResume: DpchAppWzsk {

	public init(
				scrJref: String
			) {
		super.init(VecWzskVDpch.DPCHAPPWZSKRESUME, scrJref)
	}
}

/**
	* DpchEngWzsk
	*/
public class DpchEngWzsk: DpchWzsk {
	public static let _SCRJREF: Int = 1

	public override init(
				_ ixWzskVDpch: Int
			) {
		super.init(ixWzskVDpch)

		mask = [DpchEngWzsk._SCRJREF]
	}

	public var scrJref: String = ""

	public func all(
				_ items: Set<Int>
			) -> Bool {
		if !items.contains(DpchEngWzsk._SCRJREF) {return false}
		
		return true
	}
	
	public func getSrefsMask() -> String {
		if has(DpchEngWzsk._SCRJREF) {return "scrJref"}

		return ""
	}
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) {
		var valid: Bool
		var basexpath: String? = _basexpath

		clear()

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, VecWzskVDpch.getSref(ixWzskVDpch))}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngWzsk._SCRJREF)
		}
	}
}

/**
	* DpchEngWzskAck
	*/
public class DpchEngWzskAck: DpchEngWzsk {

	public init() {
		super.init(VecWzskVDpch.DPCHENGWZSKACK)
	}
}

/**
	* DpchEngWzskAlert
	*/
public class DpchEngWzskAlert: DpchEngWzsk {
	public static let SCRJREF: Int = 1
	public static let CONTINF: Int = 2
	public static let FEEDFMCB: Int = 3
	
	public init() {
		super.init(VecWzskVDpch.DPCHENGWZSKALERT)
	}

	public var continf: ContInfWzskAlert = ContInfWzskAlert()
	public var feedFMcb: Feed = Feed("FeedFMcb")

	public override func all(
				_ items: Set<Int>
			) -> Bool {
		if !items.contains(DpchEngWzskAlert.SCRJREF) {return false}
		if !items.contains(DpchEngWzskAlert.CONTINF) {return false}
		if !items.contains(DpchEngWzskAlert.FEEDFMCB) {return false}

		return true
	}
	
	public override func getSrefsMask() -> String {
		var ss: [String] = []

		if has(DpchEngWzskAlert.SCRJREF) {ss.append("scrJref")}
		if has(DpchEngWzskAlert.CONTINF) {ss.append("continf")}
		if has(DpchEngWzskAlert.FEEDFMCB) {ss.append("feedFMcb")}

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

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, VecWzskVDpch.getSref(ixWzskVDpch))}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngWzskAlert.SCRJREF)
			if continf.readXML(doc, basexpath!, true) {add(DpchEngWzskAlert.CONTINF)};
			if feedFMcb.readXML(doc, basexpath!, true) {add(DpchEngWzskAlert.FEEDFMCB)};
		} else {
			continf = ContInfWzskAlert()
			feedFMcb.clear()
		}
	}
}

/**
	* DpchEngWzskConfirm
	*/
public class DpchEngWzskConfirm: DpchEngWzsk {
	public static let ACCEPTED: Int = 1
	public static let SCRJREF: Int = 2
	public static let SREF: Int = 3

	public init() {
		super.init(VecWzskVDpch.DPCHENGWZSKCONFIRM)
	}

	public var accepted: Bool = false
	public var sref: String = ""

	public override func all(
				_ items: Set<Int>
			) -> Bool {
		if !items.contains(DpchEngWzskConfirm.ACCEPTED) {return false}
		if !items.contains(DpchEngWzskConfirm.SCRJREF) {return false}
		if !items.contains(DpchEngWzskConfirm.SREF) {return false}

		return true
	}
	
	public override func getSrefsMask() -> String {
		var ss: [String] = []

		if has(DpchEngWzskConfirm.ACCEPTED) {ss.append("accepted")}
		if has(DpchEngWzskConfirm.SCRJREF) {ss.append("scrJref")}
		if has(DpchEngWzskConfirm.SREF) {ss.append("sref")}

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

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, VecWzskVDpch.getSref(ixWzskVDpch))}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			accepted = Xmlio.extractBoolUclc(doc, basexpath!, "accepted", "", &mask, DpchEngWzskConfirm.ACCEPTED)
			scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngWzskConfirm.SCRJREF)
			sref = Xmlio.extractStringUclc(doc, basexpath!, "sref", "", &mask, DpchEngWzskConfirm.SREF)
		}
	}
}

/**
	* DpchEngWzskSuspend
	*/
public class DpchEngWzskSuspend: DpchEngWzsk {

	public init() {
		super.init(VecWzskVDpch.DPCHENGWZSKSUSPEND)
	}
}
