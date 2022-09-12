/**
	* \file WzskQObj1NShot.swift
	* Swift API code for table TblWzskQObj1NShot
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQObj1NShot
	*/
public class WzskQObj1NShot {

	public init(
				_ jnum: Int = 0
				, _ stubRef: String = ""
			) {
		self.jnum = jnum
		self.stubRef = stubRef
	}

	public var jnum: Int
	public var stubRef: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQObj1NShot")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubRef = Xmlio.extractStringUclc(doc, basexpath!, "stubRef", "ref", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQObj1NShot
	*/
public class ListWzskQObj1NShot {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQObj1NShot] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQObj1NShot

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQObj1NShot")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQObj1NShot", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQObj1NShot()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQObj1NShot[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
