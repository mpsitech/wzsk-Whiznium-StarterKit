/**
  * \file ApiWzsk.java
  * Wzsk Java API package global functionality
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

package apiwzsk;

import java.io.*;

import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;

import org.w3c.dom.*;
import org.xml.sax.*;

import sbecore.*;

public class ApiWzsk {

	public static final String WZSK_VERSION = "0.1.33";
	public static final int WZSK_VERSION_MAJOR = 0;
	public static final int WZSK_VERSION_MINOR = 1;
	public static final int WZSK_VERSION_SUB = 33;

	public static DpchEngWzsk readDpchEng(
				String s
			) {
		DpchEngWzsk dpcheng = null;

		try {
			InputSource is = new InputSource();
			is.setCharacterStream(new StringReader(s));

			Document doc = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(is);

			int ixWzskVDpch = VecWzskVDpch.getIx(Xmlio.extractRoot(doc));
			
			if (ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKFILDOWNLOADDATA) dpcheng = (new DlgWzskFilDownload()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKNAVLOAINIDATA) dpcheng = (new DlgWzskNavLoaini()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKOBJNEWDATA) dpcheng = (new DlgWzskObjNew()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKOGRNEWDATA) dpcheng = (new DlgWzskOgrNew()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKSCFCAMERAMATDATA) dpcheng = (new DlgWzskScfCameramat()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKSCFLASERPOSDATA) dpcheng = (new DlgWzskScfLaserpos()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGDLGWZSKSCFTTABLECOORDDATA) dpcheng = (new DlgWzskScfTtablecoord()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGM2MSESSWZSKDATA) dpcheng = (new M2msessWzsk()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGROOTWZSKDATA) dpcheng = (new RootWzsk()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGSESSWZSKDATA) dpcheng = (new SessWzsk()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKACK) dpcheng = new DpchEngWzskAck();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKALERT) dpcheng = new DpchEngWzskAlert();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKCONFIRM) dpcheng = new DpchEngWzskConfirm();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILDATA) dpcheng = (new CrdWzskFil()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILDETAILDATA) dpcheng = (new PnlWzskFilDetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILHEADBARDATA) dpcheng = (new PnlWzskFilHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILLISTDATA) dpcheng = (new PnlWzskFilList()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKFILRECDATA) dpcheng = (new PnlWzskFilRec()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV2DVIEWALIGN) dpcheng = (new PnlWzskLiv2DView()).new DpchEngAlign();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV2DVIEWDATA) dpcheng = (new PnlWzskLiv2DView()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV2DVIEWLIVE) dpcheng = (new PnlWzskLiv2DView()).new DpchEngLive();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV3DVIEWDATA) dpcheng = (new PnlWzskLiv3DView()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIV3DVIEWLIVE) dpcheng = (new PnlWzskLiv3DView()).new DpchEngLive();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIVDATA) dpcheng = (new CrdWzskLiv()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIVHEADBARDATA) dpcheng = (new PnlWzskLivHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIVSYSMONDATA) dpcheng = (new PnlWzskLivSysmon()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLIVSYSMONLIVE) dpcheng = (new PnlWzskLivSysmon()).new DpchEngLive();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVCAMERADATA) dpcheng = (new PnlWzskLlvCamera()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVCAMERALIVE) dpcheng = (new PnlWzskLlvCamera()).new DpchEngLive();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVDATA) dpcheng = (new CrdWzskLlv()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVHEADBARDATA) dpcheng = (new PnlWzskLlvHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVLASERDATA) dpcheng = (new PnlWzskLlvLaser()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTERMDATA) dpcheng = (new PnlWzskLlvTerm()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKLLVTTABLEDATA) dpcheng = (new PnlWzskLlvTtable()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVADMINDATA) dpcheng = (new PnlWzskNavAdmin()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVDATA) dpcheng = (new CrdWzskNav()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVGALERYDATA) dpcheng = (new PnlWzskNavGalery()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVHEADBARDATA) dpcheng = (new PnlWzskNavHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVOPDATA) dpcheng = (new PnlWzskNavOp()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKNAVPREDATA) dpcheng = (new PnlWzskNavPre()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJ1NSHOTDATA) dpcheng = (new PnlWzskObj1NShot()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJDATA) dpcheng = (new CrdWzskObj()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJDETAILDATA) dpcheng = (new PnlWzskObjDetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJHEADBARDATA) dpcheng = (new PnlWzskObjHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJLISTDATA) dpcheng = (new PnlWzskObjList()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJRECDATA) dpcheng = (new PnlWzskObjRec()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOBJREF1NFILEDATA) dpcheng = (new PnlWzskObjRef1NFile()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGR1NOBJECTDATA) dpcheng = (new PnlWzskOgr1NObject()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRDATA) dpcheng = (new CrdWzskOgr()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRDETAILDATA) dpcheng = (new PnlWzskOgrDetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRHEADBARDATA) dpcheng = (new PnlWzskOgrHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRLISTDATA) dpcheng = (new PnlWzskOgrList()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRRECDATA) dpcheng = (new PnlWzskOgrRec()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKOGRSUP1NOBJGROUPDATA) dpcheng = (new PnlWzskOgrSup1NObjgroup()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSADETAILDATA) dpcheng = (new PnlWzskPrsADetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSDATA) dpcheng = (new CrdWzskPrs()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSDETAILDATA) dpcheng = (new PnlWzskPrsDetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSHEADBARDATA) dpcheng = (new PnlWzskPrsHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSLISTDATA) dpcheng = (new PnlWzskPrsList()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKPRSRECDATA) dpcheng = (new PnlWzskPrsRec()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSCFCONNDATA) dpcheng = (new PnlWzskScfConn()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSCFDATA) dpcheng = (new CrdWzskScf()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSCFGEOMDATA) dpcheng = (new PnlWzskScfGeom()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSCFHEADBARDATA) dpcheng = (new PnlWzskScfHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSES1NSHOTDATA) dpcheng = (new PnlWzskSes1NShot()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESDATA) dpcheng = (new CrdWzskSes()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESDETAILDATA) dpcheng = (new PnlWzskSesDetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESHEADBARDATA) dpcheng = (new PnlWzskSesHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESLISTDATA) dpcheng = (new PnlWzskSesList()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSESRECDATA) dpcheng = (new PnlWzskSesRec()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTAPARDATA) dpcheng = (new PnlWzskShtAPar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTDATA) dpcheng = (new CrdWzskSht()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTDETAILDATA) dpcheng = (new PnlWzskShtDetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTHEADBARDATA) dpcheng = (new PnlWzskShtHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTLISTDATA) dpcheng = (new PnlWzskShtList()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTRECDATA) dpcheng = (new PnlWzskShtRec()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSHTREF1NFILEDATA) dpcheng = (new PnlWzskShtRef1NFile()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKSUSPEND) dpcheng = new DpchEngWzskSuspend();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGAACCESSDATA) dpcheng = (new PnlWzskUsgAAccess()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGDATA) dpcheng = (new CrdWzskUsg()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGDETAILDATA) dpcheng = (new PnlWzskUsgDetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGHEADBARDATA) dpcheng = (new PnlWzskUsgHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGLISTDATA) dpcheng = (new PnlWzskUsgList()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGMNUSERDATA) dpcheng = (new PnlWzskUsgMNUser()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSGRECDATA) dpcheng = (new PnlWzskUsgRec()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSR1NSESSIONDATA) dpcheng = (new PnlWzskUsr1NSession()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRAACCESSDATA) dpcheng = (new PnlWzskUsrAAccess()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRDATA) dpcheng = (new CrdWzskUsr()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRDETAILDATA) dpcheng = (new PnlWzskUsrDetail()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRHEADBARDATA) dpcheng = (new PnlWzskUsrHeadbar()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRLISTDATA) dpcheng = (new PnlWzskUsrList()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRMNUSERGROUPDATA) dpcheng = (new PnlWzskUsrMNUsergroup()).new DpchEngData();
			else if (ixWzskVDpch == VecWzskVDpch.DPCHENGWZSKUSRRECDATA) dpcheng = (new PnlWzskUsrRec()).new DpchEngData();

			if (dpcheng != null) dpcheng.readXML(doc,  "",  true);

		} catch (IOException e) {
			System.out.println(e.toString());
		} catch (ParserConfigurationException e) {
			System.out.println(e.toString());
		} catch (SAXException e) {
			System.out.println(e.toString());
		};

		return dpcheng;
	};

	public static String writeDpchApp(
				DpchAppWzsk dpchapp
			) {
		Document doc;
		StringWriter str = new StringWriter();

		try {
			doc = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
	
			dpchapp.writeXML(doc, null);
	
			Transformer tr = TransformerFactory.newInstance().newTransformer();
	
			tr.transform(new DOMSource(doc), new StreamResult(str));
	
			return(str.toString());

		} catch (ParserConfigurationException e) {
			System.out.println(e.toString());
		} catch (TransformerConfigurationException e) {
			System.out.println(e.toString());
		} catch (TransformerException e) {
			System.out.println(e.toString());
		};
		
		return "";
	};
};

