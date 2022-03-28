/**
	* \file WzskQSesList.swift
	* Swift API code for table TblWzskQSesList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQSesList
	*/
public class WzskQSesList {

	public init(
				_ jnum: Int = 0
				, _ stubRefWzskMUser: String = ""
				, _ ftmStart: String = ""
				, _ ftmStop: String = ""
				, _ Ip: String = ""
			) {
		self.jnum = jnum
		self.stubRefWzskMUser = stubRefWzskMUser
		self.ftmStart = ftmStart
		self.ftmStop = ftmStop
		self.Ip = Ip
	}

	public var jnum: Int = 0
	public var stubRefWzskMUser: String
	public var ftmStart: String
	public var ftmStop: String
	public var Ip: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQSesList")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubRefWzskMUser = Xmlio.extractStringUclc(doc, basexpath!, "stubRefWzskMUser", "usr", &dummy, 0)
			ftmStart = Xmlio.extractStringUclc(doc, basexpath!, "ftmStart", "sta", &dummy, 0)
			ftmStop = Xmlio.extractStringUclc(doc, basexpath!, "ftmStop", "sto", &dummy, 0)
			Ip = Xmlio.extractStringUclc(doc, basexpath!, "Ip", "ip", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQSesList
	*/
public class ListWzskQSesList {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQSesList] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQSesList

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQSesList")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQSesList", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQSesList()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQSesList[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
