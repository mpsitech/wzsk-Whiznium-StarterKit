/**
	* \file VecWzskVDpch.h
	* vector VecWzskVDpch (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "VecWzskVDpch.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 namespace VecWzskVDpch
 ******************************************************************************/

uint VecWzskVDpch::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dpchengdlgwzskfildownloaddata") return DPCHENGDLGWZSKFILDOWNLOADDATA;
	if (s == "dpchengdlgwzsknavloainidata") return DPCHENGDLGWZSKNAVLOAINIDATA;
	if (s == "dpchengdlgwzskobjnewdata") return DPCHENGDLGWZSKOBJNEWDATA;
	if (s == "dpchengdlgwzskogrnewdata") return DPCHENGDLGWZSKOGRNEWDATA;
	if (s == "dpchengdlgwzskscfcameramatdata") return DPCHENGDLGWZSKSCFCAMERAMATDATA;
	if (s == "dpchengdlgwzskscflaserposdata") return DPCHENGDLGWZSKSCFLASERPOSDATA;
	if (s == "dpchengdlgwzskscfttablecoorddata") return DPCHENGDLGWZSKSCFTTABLECOORDDATA;
	if (s == "dpchengm2msesswzskdata") return DPCHENGM2MSESSWZSKDATA;
	if (s == "dpchengrootwzskdata") return DPCHENGROOTWZSKDATA;
	if (s == "dpchengsesswzskdata") return DPCHENGSESSWZSKDATA;
	if (s == "dpchengwzskack") return DPCHENGWZSKACK;
	if (s == "dpchengwzskalert") return DPCHENGWZSKALERT;
	if (s == "dpchengwzskconfirm") return DPCHENGWZSKCONFIRM;
	if (s == "dpchengwzskfildata") return DPCHENGWZSKFILDATA;
	if (s == "dpchengwzskfildetaildata") return DPCHENGWZSKFILDETAILDATA;
	if (s == "dpchengwzskfilheadbardata") return DPCHENGWZSKFILHEADBARDATA;
	if (s == "dpchengwzskfillistdata") return DPCHENGWZSKFILLISTDATA;
	if (s == "dpchengwzskfilrecdata") return DPCHENGWZSKFILRECDATA;
	if (s == "dpchengwzskliv2dviewalign") return DPCHENGWZSKLIV2DVIEWALIGN;
	if (s == "dpchengwzskliv2dviewdata") return DPCHENGWZSKLIV2DVIEWDATA;
	if (s == "dpchengwzskliv2dviewlive") return DPCHENGWZSKLIV2DVIEWLIVE;
	if (s == "dpchengwzskliv3dviewdata") return DPCHENGWZSKLIV3DVIEWDATA;
	if (s == "dpchengwzskliv3dviewlive") return DPCHENGWZSKLIV3DVIEWLIVE;
	if (s == "dpchengwzsklivdata") return DPCHENGWZSKLIVDATA;
	if (s == "dpchengwzsklivheadbardata") return DPCHENGWZSKLIVHEADBARDATA;
	if (s == "dpchengwzsklivsysmondata") return DPCHENGWZSKLIVSYSMONDATA;
	if (s == "dpchengwzsklivsysmonlive") return DPCHENGWZSKLIVSYSMONLIVE;
	if (s == "dpchengwzskllvcameradata") return DPCHENGWZSKLLVCAMERADATA;
	if (s == "dpchengwzskllvcameralive") return DPCHENGWZSKLLVCAMERALIVE;
	if (s == "dpchengwzskllvdata") return DPCHENGWZSKLLVDATA;
	if (s == "dpchengwzskllvheadbardata") return DPCHENGWZSKLLVHEADBARDATA;
	if (s == "dpchengwzskllvlaserdata") return DPCHENGWZSKLLVLASERDATA;
	if (s == "dpchengwzskllvtermartydata") return DPCHENGWZSKLLVTERMARTYDATA;
	if (s == "dpchengwzskllvtermclnxevbdata") return DPCHENGWZSKLLVTERMCLNXEVBDATA;
	if (s == "dpchengwzskllvtermicicledata") return DPCHENGWZSKLLVTERMICICLEDATA;
	if (s == "dpchengwzskllvtermmcvevpdata") return DPCHENGWZSKLLVTERMMCVEVPDATA;
	if (s == "dpchengwzskllvtermuvbdvkdata") return DPCHENGWZSKLLVTERMUVBDVKDATA;
	if (s == "dpchengwzskllvttabledata") return DPCHENGWZSKLLVTTABLEDATA;
	if (s == "dpchengwzsknavadmindata") return DPCHENGWZSKNAVADMINDATA;
	if (s == "dpchengwzsknavdata") return DPCHENGWZSKNAVDATA;
	if (s == "dpchengwzsknavglrydata") return DPCHENGWZSKNAVGLRYDATA;
	if (s == "dpchengwzsknavheadbardata") return DPCHENGWZSKNAVHEADBARDATA;
	if (s == "dpchengwzsknavopdata") return DPCHENGWZSKNAVOPDATA;
	if (s == "dpchengwzsknavpredata") return DPCHENGWZSKNAVPREDATA;
	if (s == "dpchengwzskobj1nshotdata") return DPCHENGWZSKOBJ1NSHOTDATA;
	if (s == "dpchengwzskobjdata") return DPCHENGWZSKOBJDATA;
	if (s == "dpchengwzskobjdetaildata") return DPCHENGWZSKOBJDETAILDATA;
	if (s == "dpchengwzskobjheadbardata") return DPCHENGWZSKOBJHEADBARDATA;
	if (s == "dpchengwzskobjlistdata") return DPCHENGWZSKOBJLISTDATA;
	if (s == "dpchengwzskobjrecdata") return DPCHENGWZSKOBJRECDATA;
	if (s == "dpchengwzskobjref1nfiledata") return DPCHENGWZSKOBJREF1NFILEDATA;
	if (s == "dpchengwzskogr1nobjectdata") return DPCHENGWZSKOGR1NOBJECTDATA;
	if (s == "dpchengwzskogrdata") return DPCHENGWZSKOGRDATA;
	if (s == "dpchengwzskogrdetaildata") return DPCHENGWZSKOGRDETAILDATA;
	if (s == "dpchengwzskogrheadbardata") return DPCHENGWZSKOGRHEADBARDATA;
	if (s == "dpchengwzskogrlistdata") return DPCHENGWZSKOGRLISTDATA;
	if (s == "dpchengwzskogrrecdata") return DPCHENGWZSKOGRRECDATA;
	if (s == "dpchengwzskogrsup1nobjgroupdata") return DPCHENGWZSKOGRSUP1NOBJGROUPDATA;
	if (s == "dpchengwzskprsadetaildata") return DPCHENGWZSKPRSADETAILDATA;
	if (s == "dpchengwzskprsdata") return DPCHENGWZSKPRSDATA;
	if (s == "dpchengwzskprsdetaildata") return DPCHENGWZSKPRSDETAILDATA;
	if (s == "dpchengwzskprsheadbardata") return DPCHENGWZSKPRSHEADBARDATA;
	if (s == "dpchengwzskprslistdata") return DPCHENGWZSKPRSLISTDATA;
	if (s == "dpchengwzskprsrecdata") return DPCHENGWZSKPRSRECDATA;
	if (s == "dpchengwzskscfconndata") return DPCHENGWZSKSCFCONNDATA;
	if (s == "dpchengwzskscfdata") return DPCHENGWZSKSCFDATA;
	if (s == "dpchengwzskscfgeomdata") return DPCHENGWZSKSCFGEOMDATA;
	if (s == "dpchengwzskscfheadbardata") return DPCHENGWZSKSCFHEADBARDATA;
	if (s == "dpchengwzskses1nshotdata") return DPCHENGWZSKSES1NSHOTDATA;
	if (s == "dpchengwzsksesdata") return DPCHENGWZSKSESDATA;
	if (s == "dpchengwzsksesdetaildata") return DPCHENGWZSKSESDETAILDATA;
	if (s == "dpchengwzsksesheadbardata") return DPCHENGWZSKSESHEADBARDATA;
	if (s == "dpchengwzskseslistdata") return DPCHENGWZSKSESLISTDATA;
	if (s == "dpchengwzsksesrecdata") return DPCHENGWZSKSESRECDATA;
	if (s == "dpchengwzskshtapardata") return DPCHENGWZSKSHTAPARDATA;
	if (s == "dpchengwzskshtdata") return DPCHENGWZSKSHTDATA;
	if (s == "dpchengwzskshtdetaildata") return DPCHENGWZSKSHTDETAILDATA;
	if (s == "dpchengwzskshtheadbardata") return DPCHENGWZSKSHTHEADBARDATA;
	if (s == "dpchengwzskshtlistdata") return DPCHENGWZSKSHTLISTDATA;
	if (s == "dpchengwzskshtrecdata") return DPCHENGWZSKSHTRECDATA;
	if (s == "dpchengwzskshtref1nfiledata") return DPCHENGWZSKSHTREF1NFILEDATA;
	if (s == "dpchengwzsksuspend") return DPCHENGWZSKSUSPEND;
	if (s == "dpchengwzskusgaaccessdata") return DPCHENGWZSKUSGAACCESSDATA;
	if (s == "dpchengwzskusgdata") return DPCHENGWZSKUSGDATA;
	if (s == "dpchengwzskusgdetaildata") return DPCHENGWZSKUSGDETAILDATA;
	if (s == "dpchengwzskusgheadbardata") return DPCHENGWZSKUSGHEADBARDATA;
	if (s == "dpchengwzskusglistdata") return DPCHENGWZSKUSGLISTDATA;
	if (s == "dpchengwzskusgmnuserdata") return DPCHENGWZSKUSGMNUSERDATA;
	if (s == "dpchengwzskusgrecdata") return DPCHENGWZSKUSGRECDATA;
	if (s == "dpchengwzskusr1nsessiondata") return DPCHENGWZSKUSR1NSESSIONDATA;
	if (s == "dpchengwzskusraaccessdata") return DPCHENGWZSKUSRAACCESSDATA;
	if (s == "dpchengwzskusrdata") return DPCHENGWZSKUSRDATA;
	if (s == "dpchengwzskusrdetaildata") return DPCHENGWZSKUSRDETAILDATA;
	if (s == "dpchengwzskusrheadbardata") return DPCHENGWZSKUSRHEADBARDATA;
	if (s == "dpchengwzskusrlistdata") return DPCHENGWZSKUSRLISTDATA;
	if (s == "dpchengwzskusrmnusergroupdata") return DPCHENGWZSKUSRMNUSERGROUPDATA;
	if (s == "dpchengwzskusrrecdata") return DPCHENGWZSKUSRRECDATA;
	if (s == "dpchappdlgwzskfildownloaddo") return DPCHAPPDLGWZSKFILDOWNLOADDO;
	if (s == "dpchappdlgwzsknavloainidata") return DPCHAPPDLGWZSKNAVLOAINIDATA;
	if (s == "dpchappdlgwzsknavloainido") return DPCHAPPDLGWZSKNAVLOAINIDO;
	if (s == "dpchappdlgwzskobjnewdata") return DPCHAPPDLGWZSKOBJNEWDATA;
	if (s == "dpchappdlgwzskobjnewdo") return DPCHAPPDLGWZSKOBJNEWDO;
	if (s == "dpchappdlgwzskogrnewdata") return DPCHAPPDLGWZSKOGRNEWDATA;
	if (s == "dpchappdlgwzskogrnewdo") return DPCHAPPDLGWZSKOGRNEWDO;
	if (s == "dpchappdlgwzskscfcameramatdata") return DPCHAPPDLGWZSKSCFCAMERAMATDATA;
	if (s == "dpchappdlgwzskscfcameramatdo") return DPCHAPPDLGWZSKSCFCAMERAMATDO;
	if (s == "dpchappdlgwzskscflaserposdata") return DPCHAPPDLGWZSKSCFLASERPOSDATA;
	if (s == "dpchappdlgwzskscflaserposdo") return DPCHAPPDLGWZSKSCFLASERPOSDO;
	if (s == "dpchappdlgwzskscfttablecoorddata") return DPCHAPPDLGWZSKSCFTTABLECOORDDATA;
	if (s == "dpchappdlgwzskscfttablecoorddo") return DPCHAPPDLGWZSKSCFTTABLECOORDDO;
	if (s == "dpchapprootwzsklogin") return DPCHAPPROOTWZSKLOGIN;
	if (s == "dpchappwzskalert") return DPCHAPPWZSKALERT;
	if (s == "dpchappwzskfildetaildata") return DPCHAPPWZSKFILDETAILDATA;
	if (s == "dpchappwzskfildetaildo") return DPCHAPPWZSKFILDETAILDO;
	if (s == "dpchappwzskfildo") return DPCHAPPWZSKFILDO;
	if (s == "dpchappwzskfillistdata") return DPCHAPPWZSKFILLISTDATA;
	if (s == "dpchappwzskfillistdo") return DPCHAPPWZSKFILLISTDO;
	if (s == "dpchappwzskfilrecdo") return DPCHAPPWZSKFILRECDO;
	if (s == "dpchappwzskinit") return DPCHAPPWZSKINIT;
	if (s == "dpchappwzskliv2dviewalign") return DPCHAPPWZSKLIV2DVIEWALIGN;
	if (s == "dpchappwzskliv2dviewdata") return DPCHAPPWZSKLIV2DVIEWDATA;
	if (s == "dpchappwzskliv2dviewdo") return DPCHAPPWZSKLIV2DVIEWDO;
	if (s == "dpchappwzskliv3dviewdata") return DPCHAPPWZSKLIV3DVIEWDATA;
	if (s == "dpchappwzskliv3dviewdo") return DPCHAPPWZSKLIV3DVIEWDO;
	if (s == "dpchappwzsklivdo") return DPCHAPPWZSKLIVDO;
	if (s == "dpchappwzsklivsysmondo") return DPCHAPPWZSKLIVSYSMONDO;
	if (s == "dpchappwzskllvcameradata") return DPCHAPPWZSKLLVCAMERADATA;
	if (s == "dpchappwzskllvcamerado") return DPCHAPPWZSKLLVCAMERADO;
	if (s == "dpchappwzskllvdo") return DPCHAPPWZSKLLVDO;
	if (s == "dpchappwzskllvlaserdata") return DPCHAPPWZSKLLVLASERDATA;
	if (s == "dpchappwzskllvlaserdo") return DPCHAPPWZSKLLVLASERDO;
	if (s == "dpchappwzskllvtermartydata") return DPCHAPPWZSKLLVTERMARTYDATA;
	if (s == "dpchappwzskllvtermartydo") return DPCHAPPWZSKLLVTERMARTYDO;
	if (s == "dpchappwzskllvtermclnxevbdata") return DPCHAPPWZSKLLVTERMCLNXEVBDATA;
	if (s == "dpchappwzskllvtermclnxevbdo") return DPCHAPPWZSKLLVTERMCLNXEVBDO;
	if (s == "dpchappwzskllvtermicicledata") return DPCHAPPWZSKLLVTERMICICLEDATA;
	if (s == "dpchappwzskllvtermicicledo") return DPCHAPPWZSKLLVTERMICICLEDO;
	if (s == "dpchappwzskllvtermmcvevpdata") return DPCHAPPWZSKLLVTERMMCVEVPDATA;
	if (s == "dpchappwzskllvtermmcvevpdo") return DPCHAPPWZSKLLVTERMMCVEVPDO;
	if (s == "dpchappwzskllvtermuvbdvkdata") return DPCHAPPWZSKLLVTERMUVBDVKDATA;
	if (s == "dpchappwzskllvtermuvbdvkdo") return DPCHAPPWZSKLLVTERMUVBDVKDO;
	if (s == "dpchappwzskllvttabledata") return DPCHAPPWZSKLLVTTABLEDATA;
	if (s == "dpchappwzskllvttabledo") return DPCHAPPWZSKLLVTTABLEDO;
	if (s == "dpchappwzsknavadmindata") return DPCHAPPWZSKNAVADMINDATA;
	if (s == "dpchappwzsknavadmindo") return DPCHAPPWZSKNAVADMINDO;
	if (s == "dpchappwzsknavdo") return DPCHAPPWZSKNAVDO;
	if (s == "dpchappwzsknavglrydata") return DPCHAPPWZSKNAVGLRYDATA;
	if (s == "dpchappwzsknavglrydo") return DPCHAPPWZSKNAVGLRYDO;
	if (s == "dpchappwzsknavopdo") return DPCHAPPWZSKNAVOPDO;
	if (s == "dpchappwzsknavpredo") return DPCHAPPWZSKNAVPREDO;
	if (s == "dpchappwzskobj1nshotdata") return DPCHAPPWZSKOBJ1NSHOTDATA;
	if (s == "dpchappwzskobj1nshotdo") return DPCHAPPWZSKOBJ1NSHOTDO;
	if (s == "dpchappwzskobjdetaildata") return DPCHAPPWZSKOBJDETAILDATA;
	if (s == "dpchappwzskobjdetaildo") return DPCHAPPWZSKOBJDETAILDO;
	if (s == "dpchappwzskobjdo") return DPCHAPPWZSKOBJDO;
	if (s == "dpchappwzskobjlistdata") return DPCHAPPWZSKOBJLISTDATA;
	if (s == "dpchappwzskobjlistdo") return DPCHAPPWZSKOBJLISTDO;
	if (s == "dpchappwzskobjrecdo") return DPCHAPPWZSKOBJRECDO;
	if (s == "dpchappwzskobjref1nfiledata") return DPCHAPPWZSKOBJREF1NFILEDATA;
	if (s == "dpchappwzskobjref1nfiledo") return DPCHAPPWZSKOBJREF1NFILEDO;
	if (s == "dpchappwzskogr1nobjectdata") return DPCHAPPWZSKOGR1NOBJECTDATA;
	if (s == "dpchappwzskogr1nobjectdo") return DPCHAPPWZSKOGR1NOBJECTDO;
	if (s == "dpchappwzskogrdetaildata") return DPCHAPPWZSKOGRDETAILDATA;
	if (s == "dpchappwzskogrdetaildo") return DPCHAPPWZSKOGRDETAILDO;
	if (s == "dpchappwzskogrdo") return DPCHAPPWZSKOGRDO;
	if (s == "dpchappwzskogrlistdata") return DPCHAPPWZSKOGRLISTDATA;
	if (s == "dpchappwzskogrlistdo") return DPCHAPPWZSKOGRLISTDO;
	if (s == "dpchappwzskogrrecdo") return DPCHAPPWZSKOGRRECDO;
	if (s == "dpchappwzskogrsup1nobjgroupdata") return DPCHAPPWZSKOGRSUP1NOBJGROUPDATA;
	if (s == "dpchappwzskogrsup1nobjgroupdo") return DPCHAPPWZSKOGRSUP1NOBJGROUPDO;
	if (s == "dpchappwzskprsadetaildata") return DPCHAPPWZSKPRSADETAILDATA;
	if (s == "dpchappwzskprsadetaildo") return DPCHAPPWZSKPRSADETAILDO;
	if (s == "dpchappwzskprsdetaildata") return DPCHAPPWZSKPRSDETAILDATA;
	if (s == "dpchappwzskprsdetaildo") return DPCHAPPWZSKPRSDETAILDO;
	if (s == "dpchappwzskprsdo") return DPCHAPPWZSKPRSDO;
	if (s == "dpchappwzskprslistdata") return DPCHAPPWZSKPRSLISTDATA;
	if (s == "dpchappwzskprslistdo") return DPCHAPPWZSKPRSLISTDO;
	if (s == "dpchappwzskprsrecdo") return DPCHAPPWZSKPRSRECDO;
	if (s == "dpchappwzskresume") return DPCHAPPWZSKRESUME;
	if (s == "dpchappwzskscfconndo") return DPCHAPPWZSKSCFCONNDO;
	if (s == "dpchappwzskscfdo") return DPCHAPPWZSKSCFDO;
	if (s == "dpchappwzskscfgeomdo") return DPCHAPPWZSKSCFGEOMDO;
	if (s == "dpchappwzskses1nshotdata") return DPCHAPPWZSKSES1NSHOTDATA;
	if (s == "dpchappwzskses1nshotdo") return DPCHAPPWZSKSES1NSHOTDO;
	if (s == "dpchappwzsksesdetaildata") return DPCHAPPWZSKSESDETAILDATA;
	if (s == "dpchappwzsksesdetaildo") return DPCHAPPWZSKSESDETAILDO;
	if (s == "dpchappwzsksesdo") return DPCHAPPWZSKSESDO;
	if (s == "dpchappwzskseslistdata") return DPCHAPPWZSKSESLISTDATA;
	if (s == "dpchappwzskseslistdo") return DPCHAPPWZSKSESLISTDO;
	if (s == "dpchappwzsksesrecdo") return DPCHAPPWZSKSESRECDO;
	if (s == "dpchappwzskshtapardata") return DPCHAPPWZSKSHTAPARDATA;
	if (s == "dpchappwzskshtapardo") return DPCHAPPWZSKSHTAPARDO;
	if (s == "dpchappwzskshtdetaildata") return DPCHAPPWZSKSHTDETAILDATA;
	if (s == "dpchappwzskshtdetaildo") return DPCHAPPWZSKSHTDETAILDO;
	if (s == "dpchappwzskshtdo") return DPCHAPPWZSKSHTDO;
	if (s == "dpchappwzskshtlistdata") return DPCHAPPWZSKSHTLISTDATA;
	if (s == "dpchappwzskshtlistdo") return DPCHAPPWZSKSHTLISTDO;
	if (s == "dpchappwzskshtrecdo") return DPCHAPPWZSKSHTRECDO;
	if (s == "dpchappwzskshtref1nfiledata") return DPCHAPPWZSKSHTREF1NFILEDATA;
	if (s == "dpchappwzskshtref1nfiledo") return DPCHAPPWZSKSHTREF1NFILEDO;
	if (s == "dpchappwzskusgaaccessdata") return DPCHAPPWZSKUSGAACCESSDATA;
	if (s == "dpchappwzskusgaaccessdo") return DPCHAPPWZSKUSGAACCESSDO;
	if (s == "dpchappwzskusgdetaildata") return DPCHAPPWZSKUSGDETAILDATA;
	if (s == "dpchappwzskusgdetaildo") return DPCHAPPWZSKUSGDETAILDO;
	if (s == "dpchappwzskusgdo") return DPCHAPPWZSKUSGDO;
	if (s == "dpchappwzskusglistdata") return DPCHAPPWZSKUSGLISTDATA;
	if (s == "dpchappwzskusglistdo") return DPCHAPPWZSKUSGLISTDO;
	if (s == "dpchappwzskusgmnuserdata") return DPCHAPPWZSKUSGMNUSERDATA;
	if (s == "dpchappwzskusgmnuserdo") return DPCHAPPWZSKUSGMNUSERDO;
	if (s == "dpchappwzskusgrecdo") return DPCHAPPWZSKUSGRECDO;
	if (s == "dpchappwzskusr1nsessiondata") return DPCHAPPWZSKUSR1NSESSIONDATA;
	if (s == "dpchappwzskusr1nsessiondo") return DPCHAPPWZSKUSR1NSESSIONDO;
	if (s == "dpchappwzskusraaccessdata") return DPCHAPPWZSKUSRAACCESSDATA;
	if (s == "dpchappwzskusraaccessdo") return DPCHAPPWZSKUSRAACCESSDO;
	if (s == "dpchappwzskusrdetaildata") return DPCHAPPWZSKUSRDETAILDATA;
	if (s == "dpchappwzskusrdetaildo") return DPCHAPPWZSKUSRDETAILDO;
	if (s == "dpchappwzskusrdo") return DPCHAPPWZSKUSRDO;
	if (s == "dpchappwzskusrlistdata") return DPCHAPPWZSKUSRLISTDATA;
	if (s == "dpchappwzskusrlistdo") return DPCHAPPWZSKUSRLISTDO;
	if (s == "dpchappwzskusrmnusergroupdata") return DPCHAPPWZSKUSRMNUSERGROUPDATA;
	if (s == "dpchappwzskusrmnusergroupdo") return DPCHAPPWZSKUSRMNUSERGROUPDO;
	if (s == "dpchappwzskusrrecdo") return DPCHAPPWZSKUSRRECDO;

	return(0);
};

string VecWzskVDpch::getSref(
			const uint ix
		) {
	if (ix == DPCHENGDLGWZSKFILDOWNLOADDATA) return("DpchEngDlgWzskFilDownloadData");
	if (ix == DPCHENGDLGWZSKNAVLOAINIDATA) return("DpchEngDlgWzskNavLoainiData");
	if (ix == DPCHENGDLGWZSKOBJNEWDATA) return("DpchEngDlgWzskObjNewData");
	if (ix == DPCHENGDLGWZSKOGRNEWDATA) return("DpchEngDlgWzskOgrNewData");
	if (ix == DPCHENGDLGWZSKSCFCAMERAMATDATA) return("DpchEngDlgWzskScfCameramatData");
	if (ix == DPCHENGDLGWZSKSCFLASERPOSDATA) return("DpchEngDlgWzskScfLaserposData");
	if (ix == DPCHENGDLGWZSKSCFTTABLECOORDDATA) return("DpchEngDlgWzskScfTtablecoordData");
	if (ix == DPCHENGM2MSESSWZSKDATA) return("DpchEngM2msessWzskData");
	if (ix == DPCHENGROOTWZSKDATA) return("DpchEngRootWzskData");
	if (ix == DPCHENGSESSWZSKDATA) return("DpchEngSessWzskData");
	if (ix == DPCHENGWZSKACK) return("DpchEngWzskAck");
	if (ix == DPCHENGWZSKALERT) return("DpchEngWzskAlert");
	if (ix == DPCHENGWZSKCONFIRM) return("DpchEngWzskConfirm");
	if (ix == DPCHENGWZSKFILDATA) return("DpchEngWzskFilData");
	if (ix == DPCHENGWZSKFILDETAILDATA) return("DpchEngWzskFilDetailData");
	if (ix == DPCHENGWZSKFILHEADBARDATA) return("DpchEngWzskFilHeadbarData");
	if (ix == DPCHENGWZSKFILLISTDATA) return("DpchEngWzskFilListData");
	if (ix == DPCHENGWZSKFILRECDATA) return("DpchEngWzskFilRecData");
	if (ix == DPCHENGWZSKLIV2DVIEWALIGN) return("DpchEngWzskLiv2DViewAlign");
	if (ix == DPCHENGWZSKLIV2DVIEWDATA) return("DpchEngWzskLiv2DViewData");
	if (ix == DPCHENGWZSKLIV2DVIEWLIVE) return("DpchEngWzskLiv2DViewLive");
	if (ix == DPCHENGWZSKLIV3DVIEWDATA) return("DpchEngWzskLiv3DViewData");
	if (ix == DPCHENGWZSKLIV3DVIEWLIVE) return("DpchEngWzskLiv3DViewLive");
	if (ix == DPCHENGWZSKLIVDATA) return("DpchEngWzskLivData");
	if (ix == DPCHENGWZSKLIVHEADBARDATA) return("DpchEngWzskLivHeadbarData");
	if (ix == DPCHENGWZSKLIVSYSMONDATA) return("DpchEngWzskLivSysmonData");
	if (ix == DPCHENGWZSKLIVSYSMONLIVE) return("DpchEngWzskLivSysmonLive");
	if (ix == DPCHENGWZSKLLVCAMERADATA) return("DpchEngWzskLlvCameraData");
	if (ix == DPCHENGWZSKLLVCAMERALIVE) return("DpchEngWzskLlvCameraLive");
	if (ix == DPCHENGWZSKLLVDATA) return("DpchEngWzskLlvData");
	if (ix == DPCHENGWZSKLLVHEADBARDATA) return("DpchEngWzskLlvHeadbarData");
	if (ix == DPCHENGWZSKLLVLASERDATA) return("DpchEngWzskLlvLaserData");
	if (ix == DPCHENGWZSKLLVTERMARTYDATA) return("DpchEngWzskLlvTermArtyData");
	if (ix == DPCHENGWZSKLLVTERMCLNXEVBDATA) return("DpchEngWzskLlvTermClnxevbData");
	if (ix == DPCHENGWZSKLLVTERMICICLEDATA) return("DpchEngWzskLlvTermIcicleData");
	if (ix == DPCHENGWZSKLLVTERMMCVEVPDATA) return("DpchEngWzskLlvTermMcvevpData");
	if (ix == DPCHENGWZSKLLVTERMUVBDVKDATA) return("DpchEngWzskLlvTermUvbdvkData");
	if (ix == DPCHENGWZSKLLVTTABLEDATA) return("DpchEngWzskLlvTtableData");
	if (ix == DPCHENGWZSKNAVADMINDATA) return("DpchEngWzskNavAdminData");
	if (ix == DPCHENGWZSKNAVDATA) return("DpchEngWzskNavData");
	if (ix == DPCHENGWZSKNAVGLRYDATA) return("DpchEngWzskNavGlryData");
	if (ix == DPCHENGWZSKNAVHEADBARDATA) return("DpchEngWzskNavHeadbarData");
	if (ix == DPCHENGWZSKNAVOPDATA) return("DpchEngWzskNavOpData");
	if (ix == DPCHENGWZSKNAVPREDATA) return("DpchEngWzskNavPreData");
	if (ix == DPCHENGWZSKOBJ1NSHOTDATA) return("DpchEngWzskObj1NShotData");
	if (ix == DPCHENGWZSKOBJDATA) return("DpchEngWzskObjData");
	if (ix == DPCHENGWZSKOBJDETAILDATA) return("DpchEngWzskObjDetailData");
	if (ix == DPCHENGWZSKOBJHEADBARDATA) return("DpchEngWzskObjHeadbarData");
	if (ix == DPCHENGWZSKOBJLISTDATA) return("DpchEngWzskObjListData");
	if (ix == DPCHENGWZSKOBJRECDATA) return("DpchEngWzskObjRecData");
	if (ix == DPCHENGWZSKOBJREF1NFILEDATA) return("DpchEngWzskObjRef1NFileData");
	if (ix == DPCHENGWZSKOGR1NOBJECTDATA) return("DpchEngWzskOgr1NObjectData");
	if (ix == DPCHENGWZSKOGRDATA) return("DpchEngWzskOgrData");
	if (ix == DPCHENGWZSKOGRDETAILDATA) return("DpchEngWzskOgrDetailData");
	if (ix == DPCHENGWZSKOGRHEADBARDATA) return("DpchEngWzskOgrHeadbarData");
	if (ix == DPCHENGWZSKOGRLISTDATA) return("DpchEngWzskOgrListData");
	if (ix == DPCHENGWZSKOGRRECDATA) return("DpchEngWzskOgrRecData");
	if (ix == DPCHENGWZSKOGRSUP1NOBJGROUPDATA) return("DpchEngWzskOgrSup1NObjgroupData");
	if (ix == DPCHENGWZSKPRSADETAILDATA) return("DpchEngWzskPrsADetailData");
	if (ix == DPCHENGWZSKPRSDATA) return("DpchEngWzskPrsData");
	if (ix == DPCHENGWZSKPRSDETAILDATA) return("DpchEngWzskPrsDetailData");
	if (ix == DPCHENGWZSKPRSHEADBARDATA) return("DpchEngWzskPrsHeadbarData");
	if (ix == DPCHENGWZSKPRSLISTDATA) return("DpchEngWzskPrsListData");
	if (ix == DPCHENGWZSKPRSRECDATA) return("DpchEngWzskPrsRecData");
	if (ix == DPCHENGWZSKSCFCONNDATA) return("DpchEngWzskScfConnData");
	if (ix == DPCHENGWZSKSCFDATA) return("DpchEngWzskScfData");
	if (ix == DPCHENGWZSKSCFGEOMDATA) return("DpchEngWzskScfGeomData");
	if (ix == DPCHENGWZSKSCFHEADBARDATA) return("DpchEngWzskScfHeadbarData");
	if (ix == DPCHENGWZSKSES1NSHOTDATA) return("DpchEngWzskSes1NShotData");
	if (ix == DPCHENGWZSKSESDATA) return("DpchEngWzskSesData");
	if (ix == DPCHENGWZSKSESDETAILDATA) return("DpchEngWzskSesDetailData");
	if (ix == DPCHENGWZSKSESHEADBARDATA) return("DpchEngWzskSesHeadbarData");
	if (ix == DPCHENGWZSKSESLISTDATA) return("DpchEngWzskSesListData");
	if (ix == DPCHENGWZSKSESRECDATA) return("DpchEngWzskSesRecData");
	if (ix == DPCHENGWZSKSHTAPARDATA) return("DpchEngWzskShtAParData");
	if (ix == DPCHENGWZSKSHTDATA) return("DpchEngWzskShtData");
	if (ix == DPCHENGWZSKSHTDETAILDATA) return("DpchEngWzskShtDetailData");
	if (ix == DPCHENGWZSKSHTHEADBARDATA) return("DpchEngWzskShtHeadbarData");
	if (ix == DPCHENGWZSKSHTLISTDATA) return("DpchEngWzskShtListData");
	if (ix == DPCHENGWZSKSHTRECDATA) return("DpchEngWzskShtRecData");
	if (ix == DPCHENGWZSKSHTREF1NFILEDATA) return("DpchEngWzskShtRef1NFileData");
	if (ix == DPCHENGWZSKSUSPEND) return("DpchEngWzskSuspend");
	if (ix == DPCHENGWZSKUSGAACCESSDATA) return("DpchEngWzskUsgAAccessData");
	if (ix == DPCHENGWZSKUSGDATA) return("DpchEngWzskUsgData");
	if (ix == DPCHENGWZSKUSGDETAILDATA) return("DpchEngWzskUsgDetailData");
	if (ix == DPCHENGWZSKUSGHEADBARDATA) return("DpchEngWzskUsgHeadbarData");
	if (ix == DPCHENGWZSKUSGLISTDATA) return("DpchEngWzskUsgListData");
	if (ix == DPCHENGWZSKUSGMNUSERDATA) return("DpchEngWzskUsgMNUserData");
	if (ix == DPCHENGWZSKUSGRECDATA) return("DpchEngWzskUsgRecData");
	if (ix == DPCHENGWZSKUSR1NSESSIONDATA) return("DpchEngWzskUsr1NSessionData");
	if (ix == DPCHENGWZSKUSRAACCESSDATA) return("DpchEngWzskUsrAAccessData");
	if (ix == DPCHENGWZSKUSRDATA) return("DpchEngWzskUsrData");
	if (ix == DPCHENGWZSKUSRDETAILDATA) return("DpchEngWzskUsrDetailData");
	if (ix == DPCHENGWZSKUSRHEADBARDATA) return("DpchEngWzskUsrHeadbarData");
	if (ix == DPCHENGWZSKUSRLISTDATA) return("DpchEngWzskUsrListData");
	if (ix == DPCHENGWZSKUSRMNUSERGROUPDATA) return("DpchEngWzskUsrMNUsergroupData");
	if (ix == DPCHENGWZSKUSRRECDATA) return("DpchEngWzskUsrRecData");
	if (ix == DPCHAPPDLGWZSKFILDOWNLOADDO) return("DpchAppDlgWzskFilDownloadDo");
	if (ix == DPCHAPPDLGWZSKNAVLOAINIDATA) return("DpchAppDlgWzskNavLoainiData");
	if (ix == DPCHAPPDLGWZSKNAVLOAINIDO) return("DpchAppDlgWzskNavLoainiDo");
	if (ix == DPCHAPPDLGWZSKOBJNEWDATA) return("DpchAppDlgWzskObjNewData");
	if (ix == DPCHAPPDLGWZSKOBJNEWDO) return("DpchAppDlgWzskObjNewDo");
	if (ix == DPCHAPPDLGWZSKOGRNEWDATA) return("DpchAppDlgWzskOgrNewData");
	if (ix == DPCHAPPDLGWZSKOGRNEWDO) return("DpchAppDlgWzskOgrNewDo");
	if (ix == DPCHAPPDLGWZSKSCFCAMERAMATDATA) return("DpchAppDlgWzskScfCameramatData");
	if (ix == DPCHAPPDLGWZSKSCFCAMERAMATDO) return("DpchAppDlgWzskScfCameramatDo");
	if (ix == DPCHAPPDLGWZSKSCFLASERPOSDATA) return("DpchAppDlgWzskScfLaserposData");
	if (ix == DPCHAPPDLGWZSKSCFLASERPOSDO) return("DpchAppDlgWzskScfLaserposDo");
	if (ix == DPCHAPPDLGWZSKSCFTTABLECOORDDATA) return("DpchAppDlgWzskScfTtablecoordData");
	if (ix == DPCHAPPDLGWZSKSCFTTABLECOORDDO) return("DpchAppDlgWzskScfTtablecoordDo");
	if (ix == DPCHAPPROOTWZSKLOGIN) return("DpchAppRootWzskLogin");
	if (ix == DPCHAPPWZSKALERT) return("DpchAppWzskAlert");
	if (ix == DPCHAPPWZSKFILDETAILDATA) return("DpchAppWzskFilDetailData");
	if (ix == DPCHAPPWZSKFILDETAILDO) return("DpchAppWzskFilDetailDo");
	if (ix == DPCHAPPWZSKFILDO) return("DpchAppWzskFilDo");
	if (ix == DPCHAPPWZSKFILLISTDATA) return("DpchAppWzskFilListData");
	if (ix == DPCHAPPWZSKFILLISTDO) return("DpchAppWzskFilListDo");
	if (ix == DPCHAPPWZSKFILRECDO) return("DpchAppWzskFilRecDo");
	if (ix == DPCHAPPWZSKINIT) return("DpchAppWzskInit");
	if (ix == DPCHAPPWZSKLIV2DVIEWALIGN) return("DpchAppWzskLiv2DViewAlign");
	if (ix == DPCHAPPWZSKLIV2DVIEWDATA) return("DpchAppWzskLiv2DViewData");
	if (ix == DPCHAPPWZSKLIV2DVIEWDO) return("DpchAppWzskLiv2DViewDo");
	if (ix == DPCHAPPWZSKLIV3DVIEWDATA) return("DpchAppWzskLiv3DViewData");
	if (ix == DPCHAPPWZSKLIV3DVIEWDO) return("DpchAppWzskLiv3DViewDo");
	if (ix == DPCHAPPWZSKLIVDO) return("DpchAppWzskLivDo");
	if (ix == DPCHAPPWZSKLIVSYSMONDO) return("DpchAppWzskLivSysmonDo");
	if (ix == DPCHAPPWZSKLLVCAMERADATA) return("DpchAppWzskLlvCameraData");
	if (ix == DPCHAPPWZSKLLVCAMERADO) return("DpchAppWzskLlvCameraDo");
	if (ix == DPCHAPPWZSKLLVDO) return("DpchAppWzskLlvDo");
	if (ix == DPCHAPPWZSKLLVLASERDATA) return("DpchAppWzskLlvLaserData");
	if (ix == DPCHAPPWZSKLLVLASERDO) return("DpchAppWzskLlvLaserDo");
	if (ix == DPCHAPPWZSKLLVTERMARTYDATA) return("DpchAppWzskLlvTermArtyData");
	if (ix == DPCHAPPWZSKLLVTERMARTYDO) return("DpchAppWzskLlvTermArtyDo");
	if (ix == DPCHAPPWZSKLLVTERMCLNXEVBDATA) return("DpchAppWzskLlvTermClnxevbData");
	if (ix == DPCHAPPWZSKLLVTERMCLNXEVBDO) return("DpchAppWzskLlvTermClnxevbDo");
	if (ix == DPCHAPPWZSKLLVTERMICICLEDATA) return("DpchAppWzskLlvTermIcicleData");
	if (ix == DPCHAPPWZSKLLVTERMICICLEDO) return("DpchAppWzskLlvTermIcicleDo");
	if (ix == DPCHAPPWZSKLLVTERMMCVEVPDATA) return("DpchAppWzskLlvTermMcvevpData");
	if (ix == DPCHAPPWZSKLLVTERMMCVEVPDO) return("DpchAppWzskLlvTermMcvevpDo");
	if (ix == DPCHAPPWZSKLLVTERMUVBDVKDATA) return("DpchAppWzskLlvTermUvbdvkData");
	if (ix == DPCHAPPWZSKLLVTERMUVBDVKDO) return("DpchAppWzskLlvTermUvbdvkDo");
	if (ix == DPCHAPPWZSKLLVTTABLEDATA) return("DpchAppWzskLlvTtableData");
	if (ix == DPCHAPPWZSKLLVTTABLEDO) return("DpchAppWzskLlvTtableDo");
	if (ix == DPCHAPPWZSKNAVADMINDATA) return("DpchAppWzskNavAdminData");
	if (ix == DPCHAPPWZSKNAVADMINDO) return("DpchAppWzskNavAdminDo");
	if (ix == DPCHAPPWZSKNAVDO) return("DpchAppWzskNavDo");
	if (ix == DPCHAPPWZSKNAVGLRYDATA) return("DpchAppWzskNavGlryData");
	if (ix == DPCHAPPWZSKNAVGLRYDO) return("DpchAppWzskNavGlryDo");
	if (ix == DPCHAPPWZSKNAVOPDO) return("DpchAppWzskNavOpDo");
	if (ix == DPCHAPPWZSKNAVPREDO) return("DpchAppWzskNavPreDo");
	if (ix == DPCHAPPWZSKOBJ1NSHOTDATA) return("DpchAppWzskObj1NShotData");
	if (ix == DPCHAPPWZSKOBJ1NSHOTDO) return("DpchAppWzskObj1NShotDo");
	if (ix == DPCHAPPWZSKOBJDETAILDATA) return("DpchAppWzskObjDetailData");
	if (ix == DPCHAPPWZSKOBJDETAILDO) return("DpchAppWzskObjDetailDo");
	if (ix == DPCHAPPWZSKOBJDO) return("DpchAppWzskObjDo");
	if (ix == DPCHAPPWZSKOBJLISTDATA) return("DpchAppWzskObjListData");
	if (ix == DPCHAPPWZSKOBJLISTDO) return("DpchAppWzskObjListDo");
	if (ix == DPCHAPPWZSKOBJRECDO) return("DpchAppWzskObjRecDo");
	if (ix == DPCHAPPWZSKOBJREF1NFILEDATA) return("DpchAppWzskObjRef1NFileData");
	if (ix == DPCHAPPWZSKOBJREF1NFILEDO) return("DpchAppWzskObjRef1NFileDo");
	if (ix == DPCHAPPWZSKOGR1NOBJECTDATA) return("DpchAppWzskOgr1NObjectData");
	if (ix == DPCHAPPWZSKOGR1NOBJECTDO) return("DpchAppWzskOgr1NObjectDo");
	if (ix == DPCHAPPWZSKOGRDETAILDATA) return("DpchAppWzskOgrDetailData");
	if (ix == DPCHAPPWZSKOGRDETAILDO) return("DpchAppWzskOgrDetailDo");
	if (ix == DPCHAPPWZSKOGRDO) return("DpchAppWzskOgrDo");
	if (ix == DPCHAPPWZSKOGRLISTDATA) return("DpchAppWzskOgrListData");
	if (ix == DPCHAPPWZSKOGRLISTDO) return("DpchAppWzskOgrListDo");
	if (ix == DPCHAPPWZSKOGRRECDO) return("DpchAppWzskOgrRecDo");
	if (ix == DPCHAPPWZSKOGRSUP1NOBJGROUPDATA) return("DpchAppWzskOgrSup1NObjgroupData");
	if (ix == DPCHAPPWZSKOGRSUP1NOBJGROUPDO) return("DpchAppWzskOgrSup1NObjgroupDo");
	if (ix == DPCHAPPWZSKPRSADETAILDATA) return("DpchAppWzskPrsADetailData");
	if (ix == DPCHAPPWZSKPRSADETAILDO) return("DpchAppWzskPrsADetailDo");
	if (ix == DPCHAPPWZSKPRSDETAILDATA) return("DpchAppWzskPrsDetailData");
	if (ix == DPCHAPPWZSKPRSDETAILDO) return("DpchAppWzskPrsDetailDo");
	if (ix == DPCHAPPWZSKPRSDO) return("DpchAppWzskPrsDo");
	if (ix == DPCHAPPWZSKPRSLISTDATA) return("DpchAppWzskPrsListData");
	if (ix == DPCHAPPWZSKPRSLISTDO) return("DpchAppWzskPrsListDo");
	if (ix == DPCHAPPWZSKPRSRECDO) return("DpchAppWzskPrsRecDo");
	if (ix == DPCHAPPWZSKRESUME) return("DpchAppWzskResume");
	if (ix == DPCHAPPWZSKSCFCONNDO) return("DpchAppWzskScfConnDo");
	if (ix == DPCHAPPWZSKSCFDO) return("DpchAppWzskScfDo");
	if (ix == DPCHAPPWZSKSCFGEOMDO) return("DpchAppWzskScfGeomDo");
	if (ix == DPCHAPPWZSKSES1NSHOTDATA) return("DpchAppWzskSes1NShotData");
	if (ix == DPCHAPPWZSKSES1NSHOTDO) return("DpchAppWzskSes1NShotDo");
	if (ix == DPCHAPPWZSKSESDETAILDATA) return("DpchAppWzskSesDetailData");
	if (ix == DPCHAPPWZSKSESDETAILDO) return("DpchAppWzskSesDetailDo");
	if (ix == DPCHAPPWZSKSESDO) return("DpchAppWzskSesDo");
	if (ix == DPCHAPPWZSKSESLISTDATA) return("DpchAppWzskSesListData");
	if (ix == DPCHAPPWZSKSESLISTDO) return("DpchAppWzskSesListDo");
	if (ix == DPCHAPPWZSKSESRECDO) return("DpchAppWzskSesRecDo");
	if (ix == DPCHAPPWZSKSHTAPARDATA) return("DpchAppWzskShtAParData");
	if (ix == DPCHAPPWZSKSHTAPARDO) return("DpchAppWzskShtAParDo");
	if (ix == DPCHAPPWZSKSHTDETAILDATA) return("DpchAppWzskShtDetailData");
	if (ix == DPCHAPPWZSKSHTDETAILDO) return("DpchAppWzskShtDetailDo");
	if (ix == DPCHAPPWZSKSHTDO) return("DpchAppWzskShtDo");
	if (ix == DPCHAPPWZSKSHTLISTDATA) return("DpchAppWzskShtListData");
	if (ix == DPCHAPPWZSKSHTLISTDO) return("DpchAppWzskShtListDo");
	if (ix == DPCHAPPWZSKSHTRECDO) return("DpchAppWzskShtRecDo");
	if (ix == DPCHAPPWZSKSHTREF1NFILEDATA) return("DpchAppWzskShtRef1NFileData");
	if (ix == DPCHAPPWZSKSHTREF1NFILEDO) return("DpchAppWzskShtRef1NFileDo");
	if (ix == DPCHAPPWZSKUSGAACCESSDATA) return("DpchAppWzskUsgAAccessData");
	if (ix == DPCHAPPWZSKUSGAACCESSDO) return("DpchAppWzskUsgAAccessDo");
	if (ix == DPCHAPPWZSKUSGDETAILDATA) return("DpchAppWzskUsgDetailData");
	if (ix == DPCHAPPWZSKUSGDETAILDO) return("DpchAppWzskUsgDetailDo");
	if (ix == DPCHAPPWZSKUSGDO) return("DpchAppWzskUsgDo");
	if (ix == DPCHAPPWZSKUSGLISTDATA) return("DpchAppWzskUsgListData");
	if (ix == DPCHAPPWZSKUSGLISTDO) return("DpchAppWzskUsgListDo");
	if (ix == DPCHAPPWZSKUSGMNUSERDATA) return("DpchAppWzskUsgMNUserData");
	if (ix == DPCHAPPWZSKUSGMNUSERDO) return("DpchAppWzskUsgMNUserDo");
	if (ix == DPCHAPPWZSKUSGRECDO) return("DpchAppWzskUsgRecDo");
	if (ix == DPCHAPPWZSKUSR1NSESSIONDATA) return("DpchAppWzskUsr1NSessionData");
	if (ix == DPCHAPPWZSKUSR1NSESSIONDO) return("DpchAppWzskUsr1NSessionDo");
	if (ix == DPCHAPPWZSKUSRAACCESSDATA) return("DpchAppWzskUsrAAccessData");
	if (ix == DPCHAPPWZSKUSRAACCESSDO) return("DpchAppWzskUsrAAccessDo");
	if (ix == DPCHAPPWZSKUSRDETAILDATA) return("DpchAppWzskUsrDetailData");
	if (ix == DPCHAPPWZSKUSRDETAILDO) return("DpchAppWzskUsrDetailDo");
	if (ix == DPCHAPPWZSKUSRDO) return("DpchAppWzskUsrDo");
	if (ix == DPCHAPPWZSKUSRLISTDATA) return("DpchAppWzskUsrListData");
	if (ix == DPCHAPPWZSKUSRLISTDO) return("DpchAppWzskUsrListDo");
	if (ix == DPCHAPPWZSKUSRMNUSERGROUPDATA) return("DpchAppWzskUsrMNUsergroupData");
	if (ix == DPCHAPPWZSKUSRMNUSERGROUPDO) return("DpchAppWzskUsrMNUsergroupDo");
	if (ix == DPCHAPPWZSKUSRRECDO) return("DpchAppWzskUsrRecDo");

	return("");
};
