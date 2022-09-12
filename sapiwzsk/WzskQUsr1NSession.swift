/**
	* \file WzskQUsr1NSession.swift
	* Swift API code for table TblWzskQUsr1NSession
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQUsr1NSession
	*/
public class WzskQUsr1NSession {

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

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQUsr1NSession")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubRef = Xmlio.extractStringUclc(doc, basexpath!, "stubRef", "ref", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQUsr1NSession
	*/
public class ListWzskQUsr1NSession {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQUsr1NSession] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQUsr1NSession

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQUsr1NSession")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQUsr1NSession", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQUsr1NSession()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQUsr1NSession[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
