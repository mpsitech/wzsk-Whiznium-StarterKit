/**
	* \file WzskQSes1NShot.swift
	* Swift API code for table TblWzskQSes1NShot
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQSes1NShot
	*/
public class WzskQSes1NShot {

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

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQSes1NShot")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubRef = Xmlio.extractStringUclc(doc, basexpath!, "stubRef", "ref", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQSes1NShot
	*/
public class ListWzskQSes1NShot {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQSes1NShot] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQSes1NShot

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQSes1NShot")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQSes1NShot", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQSes1NShot()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQSes1NShot[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
