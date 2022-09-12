/**
	* \file WzskQPrsList.swift
	* Swift API code for table TblWzskQPrsList
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
  */
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* WzskQPrsList
	*/
public class WzskQPrsList {

	public init(
				_ jnum: Int = 0
				, _ stubGrp: String = ""
				, _ stubOwn: String = ""
				, _ Title: String = ""
				, _ Firstname: String = ""
				, _ Lastname: String = ""
				, _ srefIxVSex: String = ""
				, _ titIxVSex: String = ""
				, _ telVal: String = ""
				, _ emlVal: String = ""
			) {
		self.jnum = jnum
		self.stubGrp = stubGrp
		self.stubOwn = stubOwn
		self.Title = Title
		self.Firstname = Firstname
		self.Lastname = Lastname
		self.srefIxVSex = srefIxVSex
		self.titIxVSex = titIxVSex
		self.telVal = telVal
		self.emlVal = emlVal
	}

	public var jnum: Int
	public var stubGrp: String
	public var stubOwn: String
	public var Title: String
	public var Firstname: String
	public var Lastname: String
	public var srefIxVSex: String
	public var titIxVSex: String
	public var telVal: String
	public var emlVal: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var dummy: Set<Int> = []
		var basexpath: String? = _basexpath

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "WzskQPrsList")}
		valid = basexpath != nil

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath!, "stubGrp", "grp", &dummy, 0)
			stubOwn = Xmlio.extractStringUclc(doc, basexpath!, "stubOwn", "own", &dummy, 0)
			Title = Xmlio.extractStringUclc(doc, basexpath!, "Title", "tit", &dummy, 0)
			Firstname = Xmlio.extractStringUclc(doc, basexpath!, "Firstname", "fnm", &dummy, 0)
			Lastname = Xmlio.extractStringUclc(doc, basexpath!, "Lastname", "lnm", &dummy, 0)
			srefIxVSex = Xmlio.extractStringUclc(doc, basexpath!, "srefIxVSex", "sex", &dummy, 0)
			titIxVSex = Xmlio.extractStringUclc(doc, basexpath!, "titIxVSex", "sex2", &dummy, 0)
			telVal = Xmlio.extractStringUclc(doc, basexpath!, "telVal", "tel", &dummy, 0)
			emlVal = Xmlio.extractStringUclc(doc, basexpath!, "emlVal", "eml", &dummy, 0)
		}
		
		return valid
	}
}

/**
	* ListWzskQPrsList
	*/
public class ListWzskQPrsList {
	public func clear() {
		nodes.removeAll()
	}

	public var nodes: [WzskQPrsList] = []
	
	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var basexpath: String? = _basexpath

		var ics: [Int] = []
		var shorttags: [Bool] = []

		var rec: WzskQPrsList

		var s: String

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "ListWzskQPrsList")}

		if basexpath != nil {
			if (Xmlio.checkXPath(doc, basexpath!)) {
				Xmlio.extractList(doc, basexpath!, "WzskQPrsList", "row", "jnum", &ics, &shorttags)

				clear()
				
				for i in 0 ... ics.count - 1 {
					rec = WzskQPrsList()

					if shorttags[i] {s = basexpath! + "/row[@jnum='" + String(ics[i]) + "']"}
					else {s = basexpath! + "/WzskQPrsList[@jnum='" + String(ics[i]) + "']"}
					
					if rec.readXML(doc, s, false) {nodes.append(rec)}
				}
			}
			
			return true
		}

		return false
	}
}
