/**
  * \file RootWzsk.swift
  * Swift API code for job RootWzsk
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Mar 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* RootWzsk
	*/
public class RootWzsk {
	/**
		* DpchAppLogin (full: DpchAppRootWzskLogin)
		*/
	public class DpchAppLogin: DpchAppWzsk {

		public static let SCRJREF: Int = 1
		public static let USERNAME: Int = 2
		public static let PASSWORD: Int = 3
		public static let M2MNOTREG: Int = 4
		public static let CHKSUSPSESS: Int = 5
		public static let ALL: Int  = 6

		public init(
					_ scrJref: String = ""
					, _ username: String = ""
					, _ password: String = ""
					, _ m2mNotReg: Bool = false
					, _ chksuspsess: Bool = false
					, mask: Set<Int> = []
				) {
			super.init(VecWzskVDpch.DPCHAPPROOTWZSKLOGIN, scrJref)

			if mask.contains(DpchAppLogin.ALL) {self.mask = [DpchAppLogin.SCRJREF, DpchAppLogin.USERNAME, DpchAppLogin.PASSWORD, DpchAppLogin.M2MNOTREG, DpchAppLogin.CHKSUSPSESS]}
			else {self.mask = mask}

			self.username = username
			self.password = password
			self.m2mNotReg = m2mNotReg
			self.chksuspsess = chksuspsess
		}

		public var username: String = ""
		public var password: String = ""
		public var m2mNotReg: Bool = false
		public var chksuspsess: Bool = false

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchAppLogin.SCRJREF) {ss.append("scrJref")}
			if has(DpchAppLogin.USERNAME) {ss.append("username")}
			if has(DpchAppLogin.PASSWORD) {ss.append("password")}
			if has(DpchAppLogin.M2MNOTREG) {ss.append("m2mNotReg")}
			if has(DpchAppLogin.CHKSUSPSESS) {ss.append("chksuspsess")}

			return StrMod.vectorToString(ss)
		}

		public override func writeXML(
					_ doc: XMLDocument
					, _ sup: XMLElement?
				) {
			let el = XMLElement(name: "DpchAppRootWzskLogin")

			if sup == nil {doc.setRootElement(el)}
			else {sup!.addChild(el)}

			el.addAttribute(XMLNode.attribute(withName: "xmlns", stringValue: "http://www.mpsitech.com") as! XMLNode)

			if has(DpchAppLogin.SCRJREF) {el.addChild(XMLElement(name: "scrJref", stringValue: scrJref))}
			if has(DpchAppLogin.USERNAME) {el.addChild(XMLElement(name: "scrUsername", stringValue: username))}
			if has(DpchAppLogin.PASSWORD) {el.addChild(XMLElement(name: "scrPassword", stringValue: password))}
			if has(DpchAppLogin.M2MNOTREG) {el.addChild(XMLElement(name: "scrM2mNotReg", stringValue: (m2mNotReg ? "true" : "false")))}
			if has(DpchAppLogin.CHKSUSPSESS) {el.addChild(XMLElement(name: "scrChksuspsess", stringValue: (chksuspsess ? "true" : "false")))}
		}

	}

	/**
		* DpchEngData (full: DpchEngRootWzskData)
		*/
	public class DpchEngData: DpchEngWzsk {

		public static let SCRJREF: Int = 1
		public static let FEEDFENSSPS: Int = 2

		public init() {
			super.init(VecWzskVDpch.DPCHENGROOTWZSKDATA)
		}

		public var feedFEnsSps: Feed = Feed("FeedFEnsSps")

		public override func getSrefsMask() -> String {
			var ss: Array<String> = []

			if has(DpchEngData.SCRJREF) {ss.append("scrJref")}
			if has(DpchEngData.FEEDFENSSPS) {ss.append("feedFEnsSps")}

			return StrMod.vectorToString(ss)
		}

		public override func readXML(
					_ doc: XMLDocument
					, _ _basexpath: String
					, _ addbasetag: Bool
				) {
			var valid: Bool
			var basexpath: String? = _basexpath

			clear()

			if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "DpchEngRootWzskData")}
			valid = basexpath != nil

			if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

			if valid {
				scrJref = Xmlio.extractStringUclc(doc, basexpath!, "scrJref", "", &mask, DpchEngData.SCRJREF)
				if feedFEnsSps.readXML(doc, basexpath!, true) {add(DpchEngData.FEEDFENSSPS)}
			} else {
				scrJref = ""
				feedFEnsSps = Feed("FeedFEnsSps")
			}
		}

	}

}
