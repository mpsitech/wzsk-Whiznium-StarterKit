/**
	* \file WzskQShtRef1NFile.swift
	* Swift API code for table TblWzskQShtRef1NFile
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQShtRef1NFile
	*/
public class WzskQShtRef1NFile {

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

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQShtRef1NFile")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubRef = Xmlio.extractStringUclc(doc, basexpath!, "stubRef", "ref", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQShtRef1NFile
	*/
public class ListWzskQShtRef1NFile {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQShtRef1NFile] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQShtRef1NFile

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQShtRef1NFile")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQShtRef1NFile", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQShtRef1NFile()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQShtRef1NFile[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
