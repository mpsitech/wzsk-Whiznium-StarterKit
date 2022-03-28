/**
	* \file WzskQPrsADetail.swift
	* Swift API code for table TblWzskQPrsADetail
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQPrsADetail
	*/
public class WzskQPrsADetail {

	public init(
				_ jnum: Int = 0
				, _ x1SrefKType: String = ""
				, _ titX1SrefKType: String = ""
				, _ Val: String = ""
			) {
		self.jnum = jnum
		self.x1SrefKType = x1SrefKType
		self.titX1SrefKType = titX1SrefKType
		self.Val = Val
	}

	public var jnum: Int = 0
	public var x1SrefKType: String
	public var titX1SrefKType: String
	public var Val: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQPrsADetail")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			x1SrefKType = Xmlio.extractStringUclc(doc, basexpath!, "x1SrefKType", "typ", &dummy, 0)
			titX1SrefKType = Xmlio.extractStringUclc(doc, basexpath!, "titX1SrefKType", "typ2", &dummy, 0)
			Val = Xmlio.extractStringUclc(doc, basexpath!, "Val", "val", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQPrsADetail
	*/
public class ListWzskQPrsADetail {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQPrsADetail] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQPrsADetail

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQPrsADetail")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQPrsADetail", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQPrsADetail()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQPrsADetail[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
