/**
	* \file WzskQUsgList.swift
	* Swift API code for table TblWzskQUsgList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQUsgList
	*/
public class WzskQUsgList {

	public init(
				_ jnum: Int = 0
				, _ stubGrp: String = ""
				, _ stubOwn: String = ""
				, _ sref: String = ""
			) {
		self.jnum = jnum
		self.stubGrp = stubGrp
		self.stubOwn = stubOwn
		self.sref = sref
	}

	public var jnum: Int
	public var stubGrp: String
	public var stubOwn: String
	public var sref: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQUsgList")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath!, "stubGrp", "grp", &dummy, 0)
			stubOwn = Xmlio.extractStringUclc(doc, basexpath!, "stubOwn", "own", &dummy, 0)
			sref = Xmlio.extractStringUclc(doc, basexpath!, "sref", "srf", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQUsgList
	*/
public class ListWzskQUsgList {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQUsgList] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQUsgList

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQUsgList")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQUsgList", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQUsgList()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQUsgList[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
