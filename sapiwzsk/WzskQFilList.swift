/**
	* \file WzskQFilList.swift
	* Swift API code for table TblWzskQFilList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQFilList
	*/
public class WzskQFilList {

	public init(
				_ jnum: Int = 0
				, _ stubGrp: String = ""
				, _ stubOwn: String = ""
				, _ Filename: String = ""
				, _ srefRefIxVTbl: String = ""
				, _ titRefIxVTbl: String = ""
				, _ stubRefUref: String = ""
				, _ osrefKContent: String = ""
				, _ titOsrefKContent: String = ""
				, _ srefKMimetype: String = ""
				, _ titSrefKMimetype: String = ""
				, _ Size: Int = 0
			) {
		self.jnum = jnum
		self.stubGrp = stubGrp
		self.stubOwn = stubOwn
		self.Filename = Filename
		self.srefRefIxVTbl = srefRefIxVTbl
		self.titRefIxVTbl = titRefIxVTbl
		self.stubRefUref = stubRefUref
		self.osrefKContent = osrefKContent
		self.titOsrefKContent = titOsrefKContent
		self.srefKMimetype = srefKMimetype
		self.titSrefKMimetype = titSrefKMimetype
		self.Size = Size
	}

	public var jnum: Int
	public var stubGrp: String
	public var stubOwn: String
	public var Filename: String
	public var srefRefIxVTbl: String
	public var titRefIxVTbl: String
	public var stubRefUref: String
	public var osrefKContent: String
	public var titOsrefKContent: String
	public var srefKMimetype: String
	public var titSrefKMimetype: String
	public var Size: Int

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQFilList")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath!, "stubGrp", "grp", &dummy, 0)
			stubOwn = Xmlio.extractStringUclc(doc, basexpath!, "stubOwn", "own", &dummy, 0)
			Filename = Xmlio.extractStringUclc(doc, basexpath!, "Filename", "fnm", &dummy, 0)
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath!, "srefRefIxVTbl", "ret", &dummy, 0)
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath!, "titRefIxVTbl", "ret2", &dummy, 0)
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath!, "stubRefUref", "reu", &dummy, 0)
			osrefKContent = Xmlio.extractStringUclc(doc, basexpath!, "osrefKContent", "cnt", &dummy, 0)
			titOsrefKContent = Xmlio.extractStringUclc(doc, basexpath!, "titOsrefKContent", "cnt2", &dummy, 0)
			srefKMimetype = Xmlio.extractStringUclc(doc, basexpath!, "srefKMimetype", "mim", &dummy, 0)
			titSrefKMimetype = Xmlio.extractStringUclc(doc, basexpath!, "titSrefKMimetype", "mim2", &dummy, 0)
			Size = Xmlio.extractIntUclc(doc, basexpath!, "Size", "siz", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQFilList
	*/
public class ListWzskQFilList {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQFilList] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQFilList

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQFilList")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQFilList", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQFilList()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQFilList[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
