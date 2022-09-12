/**
	* \file WzskQShtAPar.swift
	* Swift API code for table TblWzskQShtAPar
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQShtAPar
	*/
public class WzskQShtAPar {

	public init(
				_ jnum: Int = 0
				, _ x1SrefKKey: String = ""
				, _ titX1SrefKKey: String = ""
				, _ Val: String = ""
			) {
		self.jnum = jnum
		self.x1SrefKKey = x1SrefKKey
		self.titX1SrefKKey = titX1SrefKKey
		self.Val = Val
	}

	public var jnum: Int
	public var x1SrefKKey: String
	public var titX1SrefKKey: String
	public var Val: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQShtAPar")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			x1SrefKKey = Xmlio.extractStringUclc(doc, basexpath!, "x1SrefKKey", "key", &dummy, 0)
			titX1SrefKKey = Xmlio.extractStringUclc(doc, basexpath!, "titX1SrefKKey", "key2", &dummy, 0)
			Val = Xmlio.extractStringUclc(doc, basexpath!, "Val", "val", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQShtAPar
	*/
public class ListWzskQShtAPar {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQShtAPar] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQShtAPar

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQShtAPar")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQShtAPar", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQShtAPar()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQShtAPar[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
