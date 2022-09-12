/**
	* \file WzskQOgrList.swift
	* Swift API code for table TblWzskQOgrList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQOgrList
	*/
public class WzskQOgrList {

	public init(
				_ jnum: Int = 0
				, _ sref: String = ""
				, _ Title: String = ""
				, _ stubSupRefWzskMObjgroup: String = ""
			) {
		self.jnum = jnum
		self.sref = sref
		self.Title = Title
		self.stubSupRefWzskMObjgroup = stubSupRefWzskMObjgroup
	}

	public var jnum: Int
	public var sref: String
	public var Title: String
	public var stubSupRefWzskMObjgroup: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQOgrList")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			sref = Xmlio.extractStringUclc(doc, basexpath!, "sref", "srf", &dummy, 0)
			Title = Xmlio.extractStringUclc(doc, basexpath!, "Title", "tit", &dummy, 0)
			stubSupRefWzskMObjgroup = Xmlio.extractStringUclc(doc, basexpath!, "stubSupRefWzskMObjgroup", "sup", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQOgrList
	*/
public class ListWzskQOgrList {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQOgrList] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQOgrList

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQOgrList")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQOgrList", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQOgrList()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQOgrList[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
