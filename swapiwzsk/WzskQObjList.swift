/**
	* \file WzskQObjList.swift
	* Swift API code for table TblWzskQObjList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQObjList
	*/
public class WzskQObjList {

	public init(
				_ jnum: Int = 0
				, _ Title: String = ""
				, _ stubRefWzskMObjgroup: String = ""
			) {
		self.jnum = jnum
		self.Title = Title
		self.stubRefWzskMObjgroup = stubRefWzskMObjgroup
	}

	public var jnum: Int
	public var Title: String
	public var stubRefWzskMObjgroup: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQObjList")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			Title = Xmlio.extractStringUclc(doc, basexpath!, "Title", "tit", &dummy, 0)
			stubRefWzskMObjgroup = Xmlio.extractStringUclc(doc, basexpath!, "stubRefWzskMObjgroup", "ogr", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQObjList
	*/
public class ListWzskQObjList {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQObjList] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQObjList

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQObjList")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQObjList", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQObjList()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQObjList[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
