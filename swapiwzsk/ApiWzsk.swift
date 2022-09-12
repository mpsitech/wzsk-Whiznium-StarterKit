/**
	* \file ApiWzsk.swift
	* Wzsk Swift API package global functionality
	* \copyright (C) 2022 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2022
	*/
// IP header --- ABOVE

import Foundation
import sbecore

/**
	* StgWzskapi
	*/
public class StgWzskapi: Block {
	public static let ENGIP: Int = 1
	public static let ENGPORT: Int = 2
	public static let USERNAME: Int = 3
	public static let PASSWORD: Int = 4
	
	public init(
				engip: String = ""
				, engport: Int = 0
				, username: String = ""
				, password: String = ""
			) {
		self.engip = engip
		self.engport = engport
		self.username = username
		self.password = password

		super.init()

		mask = [StgWzskapi.ENGIP, StgWzskapi.ENGPORT, StgWzskapi.USERNAME, StgWzskapi.PASSWORD]
	}

	public var engip: String
	public var engport: Int
	public var username: String
	public var password: String

	public func readXML(
				_ doc: XMLDocument
				, _ _basexpath: String
				, _ addbasetag: Bool
			) -> Bool {
		var valid: Bool
		var basexpath: String? = _basexpath

		clear()

		if addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, "StgWzskapi")}
		valid = basexpath != nil

		let itemtag: String = "StgitemWzskapi"

		if valid {valid = Xmlio.checkXPath(doc, basexpath!)}

		if valid {
			engip = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "engip", &mask, StgWzskapi.ENGIP)
			engport = Xmlio.extractIntAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "engport", &mask, StgWzskapi.ENGPORT)
			username = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "username", &mask, StgWzskapi.USERNAME)
			password = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, "Si", "sref", "password", &mask, StgWzskapi.PASSWORD)
		}

		return valid
	}

	public func writeXML(
				_ doc: XMLDocument
				, _ sup: XMLElement?
				, _ difftag: String
				, _ shorttags: Bool
			) {
		var tag: String? = difftag
		if tag == nil {tag = "StgWzskapi"}

		let itemtag: String = shorttags ? "Si" : "StgitemWzskapi"

		let el = XMLElement(name: tag!)

		if sup == nil {doc.setRootElement(el)}
		else {sup!.addChild(el)}

		Xmlio.writeStringAttr(doc, el, itemtag, "sref", "engip", engip)
		Xmlio.writeIntAttr(doc, el, itemtag, "sref", "engport", engport)
		Xmlio.writeStringAttr(doc, el, itemtag, "sref", "username", username)
		Xmlio.writeStringAttr(doc, el, itemtag, "sref", "password", password)
	}

	public func all(
				_ items: Set<Int>
			) -> Bool {
		if !items.contains(StgWzskapi.ENGIP) {return false}
		if !items.contains(StgWzskapi.ENGPORT) {return false}
		if !items.contains(StgWzskapi.USERNAME) {return false}
		if !items.contains(StgWzskapi.PASSWORD) {return false}

		return true
	}
}

/**
	* ApiWzsk
	*/
public struct ApiWzsk {
	public let WZSK_VERSION: String = "1.0.17"
	public let WZSK_VERSION_MAJOR: Int = 1
	public let WZSK_VERSION_MINOR: Int = 0
	public let WZSK_VERSION_SUB: Int = 17

	public init() {}

	public func readDpchEng(
				_ s: String
			) -> DpchEngWzsk? {
		var dpcheng: DpchEngWzsk? = nil

		let doc: XMLDocument? = try? XMLDocument(xmlString: s)

		let ixWzskVDpch: Int = VecWzskVDpch.getIx(Xmlio.extractRoot(doc!))

		if ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKFILDOWNLOADDATA {dpcheng = DlgWzskFilDownload.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKNAVLOAINIDATA {dpcheng = DlgWzskNavLoaini.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKOBJNEWDATA {dpcheng = DlgWzskObjNew.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKOGRNEWDATA {dpcheng = DlgWzskOgrNew.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKSCFCAMERAMATDATA {dpcheng = DlgWzskScfCameramat.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKSCFLASERPOSDATA {dpcheng = DlgWzskScfLaserpos.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKSCFTTABLECOORDDATA {dpcheng = DlgWzskScfTtablecoord.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGM2MSESSWZSKDATA {dpcheng = M2msessWzsk.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGROOTWZSKDATA {dpcheng = RootWzsk.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGSESSWZSKDATA {dpcheng = SessWzsk.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKACK {dpcheng = DpchEngWzskAck()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKALERT {dpcheng = DpchEngWzskAlert()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKCONFIRM {dpcheng = DpchEngWzskConfirm()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILDATA {dpcheng = CrdWzskFil.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILDETAILDATA {dpcheng = PnlWzskFilDetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILHEADBARDATA {dpcheng = PnlWzskFilHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILLISTDATA {dpcheng = PnlWzskFilList.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILRECDATA {dpcheng = PnlWzskFilRec.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV2DVIEWALIGN {dpcheng = PnlWzskLiv2DView.DpchEngAlign()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV2DVIEWDATA {dpcheng = PnlWzskLiv2DView.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV2DVIEWLIVE {dpcheng = PnlWzskLiv2DView.DpchEngLive()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV3DVIEWDATA {dpcheng = PnlWzskLiv3DView.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV3DVIEWLIVE {dpcheng = PnlWzskLiv3DView.DpchEngLive()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIVDATA {dpcheng = CrdWzskLiv.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIVHEADBARDATA {dpcheng = PnlWzskLivHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIVSYSMONDATA {dpcheng = PnlWzskLivSysmon.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIVSYSMONLIVE {dpcheng = PnlWzskLivSysmon.DpchEngLive()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVCAMERADATA {dpcheng = PnlWzskLlvCamera.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVCAMERALIVE {dpcheng = PnlWzskLlvCamera.DpchEngLive()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVDATA {dpcheng = CrdWzskLlv.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVHEADBARDATA {dpcheng = PnlWzskLlvHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVLASERDATA {dpcheng = PnlWzskLlvLaser.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTERMARTYDATA {dpcheng = PnlWzskLlvTermArty.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTERMCLNXEVBDATA {dpcheng = PnlWzskLlvTermClnxevb.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTERMICICLEDATA {dpcheng = PnlWzskLlvTermIcicle.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTERMMCVEVPDATA {dpcheng = PnlWzskLlvTermMcvevp.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTERMPWMONUARTDATA {dpcheng = PnlWzskLlvTermPwmonuart.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTERMPWMONUSBDATA {dpcheng = PnlWzskLlvTermPwmonusb.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTERMUVBDVKDATA {dpcheng = PnlWzskLlvTermUvbdvk.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTTABLEDATA {dpcheng = PnlWzskLlvTtable.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVADMINDATA {dpcheng = PnlWzskNavAdmin.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVDATA {dpcheng = CrdWzskNav.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVGLRYDATA {dpcheng = PnlWzskNavGlry.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVHEADBARDATA {dpcheng = PnlWzskNavHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVOPDATA {dpcheng = PnlWzskNavOp.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVPREDATA {dpcheng = PnlWzskNavPre.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJ1NSHOTDATA {dpcheng = PnlWzskObj1NShot.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJDATA {dpcheng = CrdWzskObj.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJDETAILDATA {dpcheng = PnlWzskObjDetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJHEADBARDATA {dpcheng = PnlWzskObjHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJLISTDATA {dpcheng = PnlWzskObjList.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJRECDATA {dpcheng = PnlWzskObjRec.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJREF1NFILEDATA {dpcheng = PnlWzskObjRef1NFile.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGR1NOBJECTDATA {dpcheng = PnlWzskOgr1NObject.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRDATA {dpcheng = CrdWzskOgr.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRDETAILDATA {dpcheng = PnlWzskOgrDetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRHEADBARDATA {dpcheng = PnlWzskOgrHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRLISTDATA {dpcheng = PnlWzskOgrList.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRRECDATA {dpcheng = PnlWzskOgrRec.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRSUP1NOBJGROUPDATA {dpcheng = PnlWzskOgrSup1NObjgroup.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSADETAILDATA {dpcheng = PnlWzskPrsADetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSDATA {dpcheng = CrdWzskPrs.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSDETAILDATA {dpcheng = PnlWzskPrsDetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSHEADBARDATA {dpcheng = PnlWzskPrsHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSLISTDATA {dpcheng = PnlWzskPrsList.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSRECDATA {dpcheng = PnlWzskPrsRec.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSCFCONNDATA {dpcheng = PnlWzskScfConn.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSCFDATA {dpcheng = CrdWzskScf.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSCFGEOMDATA {dpcheng = PnlWzskScfGeom.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSCFHEADBARDATA {dpcheng = PnlWzskScfHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSES1NSHOTDATA {dpcheng = PnlWzskSes1NShot.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESDATA {dpcheng = CrdWzskSes.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESDETAILDATA {dpcheng = PnlWzskSesDetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESHEADBARDATA {dpcheng = PnlWzskSesHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESLISTDATA {dpcheng = PnlWzskSesList.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESRECDATA {dpcheng = PnlWzskSesRec.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTAPARDATA {dpcheng = PnlWzskShtAPar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTDATA {dpcheng = CrdWzskSht.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTDETAILDATA {dpcheng = PnlWzskShtDetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTHEADBARDATA {dpcheng = PnlWzskShtHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTLISTDATA {dpcheng = PnlWzskShtList.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTRECDATA {dpcheng = PnlWzskShtRec.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTREF1NFILEDATA {dpcheng = PnlWzskShtRef1NFile.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSUSPEND {dpcheng = DpchEngWzskSuspend()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGAACCESSDATA {dpcheng = PnlWzskUsgAAccess.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGDATA {dpcheng = CrdWzskUsg.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGDETAILDATA {dpcheng = PnlWzskUsgDetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGHEADBARDATA {dpcheng = PnlWzskUsgHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGLISTDATA {dpcheng = PnlWzskUsgList.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGMNUSERDATA {dpcheng = PnlWzskUsgMNUser.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGRECDATA {dpcheng = PnlWzskUsgRec.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSR1NSESSIONDATA {dpcheng = PnlWzskUsr1NSession.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRAACCESSDATA {dpcheng = PnlWzskUsrAAccess.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRDATA {dpcheng = CrdWzskUsr.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRDETAILDATA {dpcheng = PnlWzskUsrDetail.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRHEADBARDATA {dpcheng = PnlWzskUsrHeadbar.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRLISTDATA {dpcheng = PnlWzskUsrList.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRMNUSERGROUPDATA {dpcheng = PnlWzskUsrMNUsergroup.DpchEngData()}
		else if ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRRECDATA {dpcheng = PnlWzskUsrRec.DpchEngData()}

		if dpcheng != nil {dpcheng!.readXML(doc!, "", true)}

		return dpcheng
	}
	
	public func writeDpchApp(
				_ dpchapp: DpchAppWzsk
			) -> String? {
		let doc: XMLDocument = XMLDocument()

		dpchapp.writeXML(doc, nil)

		return doc.xmlString
	}
}
