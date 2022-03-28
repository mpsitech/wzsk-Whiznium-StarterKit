/**
	* \file WzskQShtList.swift
	* Swift API code for table TblWzskQShtList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQShtList
	*/
public class WzskQShtList {

	public init(
				_ jnum: Int = 0
				, _ stubRefWzskMSession: String = ""
				, _ stubRefWzskMObject: String = ""
				, _ ftmStart: String = ""
			) {
		self.jnum = jnum
		self.stubRefWzskMSession = stubRefWzskMSession
		self.stubRefWzskMObject = stubRefWzskMObject
		self.ftmStart = ftmStart
	}

	public var jnum: Int = 0
	public var stubRefWzskMSession: String
	public var stubRefWzskMObject: String
	public var ftmStart: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQShtList")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubRefWzskMSession = Xmlio.extractStringUclc(doc, basexpath!, "stubRefWzskMSession", "ses", &dummy, 0)
			stubRefWzskMObject = Xmlio.extractStringUclc(doc, basexpath!, "stubRefWzskMObject", "obj", &dummy, 0)
			ftmStart = Xmlio.extractStringUclc(doc, basexpath!, "ftmStart", "sta", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQShtList
	*/
public class ListWzskQShtList {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQShtList] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQShtList

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQShtList")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQShtList", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQShtList()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQShtList[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
