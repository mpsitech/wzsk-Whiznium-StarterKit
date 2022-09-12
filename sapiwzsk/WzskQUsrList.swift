/**
	* \file WzskQUsrList.swift
	* Swift API code for table TblWzskQUsrList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQUsrList
	*/
public class WzskQUsrList {

	public init(
				_ jnum: Int = 0
				, _ stubGrp: String = ""
				, _ stubOwn: String = ""
				, _ stubRefWzskMPerson: String = ""
				, _ sref: String = ""
				, _ stubRefWzskMUsergroup: String = ""
				, _ srefIxVState: String = ""
				, _ titIxVState: String = ""
				, _ srefIxWzskVLocale: String = ""
				, _ titIxWzskVLocale: String = ""
				, _ srefIxWzskVUserlevel: String = ""
				, _ titIxWzskVUserlevel: String = ""
			) {
		self.jnum = jnum
		self.stubGrp = stubGrp
		self.stubOwn = stubOwn
		self.stubRefWzskMPerson = stubRefWzskMPerson
		self.sref = sref
		self.stubRefWzskMUsergroup = stubRefWzskMUsergroup
		self.srefIxVState = srefIxVState
		self.titIxVState = titIxVState
		self.srefIxWzskVLocale = srefIxWzskVLocale
		self.titIxWzskVLocale = titIxWzskVLocale
		self.srefIxWzskVUserlevel = srefIxWzskVUserlevel
		self.titIxWzskVUserlevel = titIxWzskVUserlevel
	}

	public var jnum: Int
	public var stubGrp: String
	public var stubOwn: String
	public var stubRefWzskMPerson: String
	public var sref: String
	public var stubRefWzskMUsergroup: String
	public var srefIxVState: String
	public var titIxVState: String
	public var srefIxWzskVLocale: String
	public var titIxWzskVLocale: String
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

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQUsrList")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath!, "stubGrp", "grp", &dummy, 0)
			stubOwn = Xmlio.extractStringUclc(doc, basexpath!, "stubOwn", "own", &dummy, 0)
			stubRefWzskMPerson = Xmlio.extractStringUclc(doc, basexpath!, "stubRefWzskMPerson", "prs", &dummy, 0)
			sref = Xmlio.extractStringUclc(doc, basexpath!, "sref", "srf", &dummy, 0)
			stubRefWzskMUsergroup = Xmlio.extractStringUclc(doc, basexpath!, "stubRefWzskMUsergroup", "usg", &dummy, 0)
			srefIxVState = Xmlio.extractStringUclc(doc, basexpath!, "srefIxVState", "ste", &dummy, 0)
			titIxVState = Xmlio.extractStringUclc(doc, basexpath!, "titIxVState", "ste2", &dummy, 0)
			srefIxWzskVLocale = Xmlio.extractStringUclc(doc, basexpath!, "srefIxWzskVLocale", "lcl", &dummy, 0)
			titIxWzskVLocale = Xmlio.extractStringUclc(doc, basexpath!, "titIxWzskVLocale", "lcl2", &dummy, 0)
			srefIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath!, "srefIxWzskVUserlevel", "ulv", &dummy, 0)
			titIxWzskVUserlevel = Xmlio.extractStringUclc(doc, basexpath!, "titIxWzskVUserlevel", "ulv2", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQUsrList
	*/
public class ListWzskQUsrList {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQUsrList] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQUsrList

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQUsrList")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQUsrList", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQUsrList()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQUsrList[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
