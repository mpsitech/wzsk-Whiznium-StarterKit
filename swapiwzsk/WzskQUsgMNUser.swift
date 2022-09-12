/**
	* \file WzskQUsgMNUser.swift
	* Swift API code for table TblWzskQUsgMNUser
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQUsgMNUser
	*/
public class WzskQUsgMNUser {

	public init(
				_ jnum: Int = 0
				, _ stubMref: String = ""
				, _ srefIxWzskVUserlevel: String = ""
				, _ titIxWzskVUserlevel: String = ""
			) {
		self.jnum = jnum
		self.stubMref = stubMref
		self.srefIxWzskVUserlevel = srefIxWzskVUserlevel
		self.titIxWzskVUserlevel = titIxWzskVUserlevel
	}

	public var jnum: Int
	public var stubMref: String
	public var srefIxWzskVUserlevel: String
	public var titIxWzskVUserlevel: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQUsgMNUser")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubMref = Xmlio.extractStringUclc(doc, basexpath!, "stubMref", "mref", &dummy, 0)
			srefIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath!, "srefIxWzskVUserlevel", "ulv", &dummy, 0)
			titIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath!, "titIxWzskVUserlevel", "ulv2", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQUsgMNUser
	*/
public class ListWzskQUsgMNUser {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQUsgMNUser] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQUsgMNUser

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQUsgMNUser")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQUsgMNUser", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQUsgMNUser()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQUsgMNUser[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
