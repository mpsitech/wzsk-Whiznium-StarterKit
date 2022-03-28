/**
	* \file WzskQUsrAAccess.swift
	* Swift API code for table TblWzskQUsrAAccess
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQUsrAAccess
	*/
public class WzskQUsrAAccess {

	public init(
				_ jnum: Int = 0
				, _ srefX1IxWzskVFeatgroup: String = ""
				, _ titX1IxWzskVFeatgroup: String = ""
				, _ x2FeaSrefUix: String = ""
				, _ srefsIxWzskWAccess: String = ""
				, _ titsIxWzskWAccess: String = ""
			) {
		self.jnum = jnum
		self.srefX1IxWzskVFeatgroup = srefX1IxWzskVFeatgroup
		self.titX1IxWzskVFeatgroup = titX1IxWzskVFeatgroup
		self.x2FeaSrefUix = x2FeaSrefUix
		self.srefsIxWzskWAccess = srefsIxWzskWAccess
		self.titsIxWzskWAccess = titsIxWzskWAccess
	}

	public var jnum: Int = 0
	public var srefX1IxWzskVFeatgroup: String
	public var titX1IxWzskVFeatgroup: String
	public var x2FeaSrefUix: String
	public var srefsIxWzskWAccess: String
	public var titsIxWzskWAccess: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQUsrAAccess")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			srefX1IxWzskVFeatgroup = Xmlio.extractStringUclc(doc, basexpath!, "srefX1IxWzskVFeatgroup", "feg", &dummy, 0)
			titX1IxWzskVFeatgroup = Xmlio.extractStringUclc(doc, basexpath!, "titX1IxWzskVFeatgroup", "feg2", &dummy, 0)
			x2FeaSrefUix = Xmlio.extractStringUclc(doc, basexpath!, "x2FeaSrefUix", "fea", &dummy, 0)
			srefsIxWzskWAccess = Xmlio.extractStringUclc(doc, basexpath!, "srefsIxWzskWAccess", "acc", &dummy, 0)
			titsIxWzskWAccess = Xmlio.extractStringUclc(doc, basexpath!, "titsIxWzskWAccess", "acc2", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQUsrAAccess
	*/
public class ListWzskQUsrAAccess {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQUsrAAccess] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQUsrAAccess

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQUsrAAccess")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQUsrAAccess", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQUsrAAccess()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQUsrAAccess[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
