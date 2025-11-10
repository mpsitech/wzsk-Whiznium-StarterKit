function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWzskNav", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWzskNav", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppWzskNav", "initdoneHeadbar") == "true");
	var initdoneAdmin = (retrieveSi(srcdoc, "StatAppWzskNav", "initdoneAdmin") == "true");
	var initdoneOp = (retrieveSi(srcdoc, "StatAppWzskNav", "initdoneOp") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlWzskNavHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdoneAdmin) {
		doc.getElementById("Admin").src = "./PnlWzskNavAdmin.html?scrJref=" + scrJrefAdmin;
	} else if (!initdoneOp) {
		doc.getElementById("Op").src = "./PnlWzskNavOp.html?scrJref=" + scrJrefOp;
	} else {
		doc.initdone = true;
		window.onfocus = resumeNotify;

		refresh();

		restartNotify();
	};
};

function setPnlAvail(short, avail) {
	var oldAvail = (doc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) {
			doc.getElementById("spc" + short).setAttribute("class", "show");
			doc.getElementById("tr" + short).setAttribute("class", "show");
		} else {
			doc.getElementById(short).contentWindow.minimize();
			doc.getElementById("spc" + short).setAttribute("class", "hide");
			doc.getElementById("tr" + short).setAttribute("class", "hide");
		};
	};
};

function getHeight() {
	var height = 25;

	if (doc.getElementById("trAdmin").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAdmin").getAttribute("height")) + 8;
	if (doc.getElementById("trOp").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdOp").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppWzskNav", "shortMenu");

	if (doc.getElementById("divMenu")) {
		if (shortMenu == short)
			hideMenu(shortMenu);
		else {
			hideMenu(shortMenu);
			showMenu(short, left, width, height);
		};

	} else {
		showMenu(short, left, width, height);
	};
};

function showMenu(short, left, width, height) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppWzskNav", "shortMenu", short);
	setSi(srcdoc, "StatAppWzskNav", "widthMenu", "" + (width-3));

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuappact");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menuact");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menulineact");

	var body = doc.getElementById("body");
	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "menu");
	mydiv.setAttribute("id", "divMenu");
	mydiv.setAttribute("style", "left:" + left + "px;");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Menu");
	myif.setAttribute("src", "./Men" + short + ".html");
	myif.setAttribute("width", "" + width);
	myif.setAttribute("height", "" + height);
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideMenu(short) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppWzskNav", "shortMenu", "");

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspApp2Avail = (retrieveSi(srcdoc, "StatShrWzskNav", "MspApp2Avail") == "true");
	MitAppLoiAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitAppLoiAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWzskNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagWzskNav", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagWzskNav", "MrlAppHlp"));
	setTextContent(mendoc, mendoc.getElementById("MitAppLoi"), retrieveTi(srcdoc, "TagWzskNav", "MitAppLoi"));

	height -= setMitMspAvail("MspApp2", MspApp2Avail, 1);
	height -= setMitMspAvail("MitAppLoi", MitAppLoiAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenSes() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MitSesSpsAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitSesSpsAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWzskNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxSesSes1"), retrieveCi(srcdoc, "ContInfWzskNav", "MtxSesSes1"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes2"), retrieveCi(srcdoc, "ContInfWzskNav", "MtxSesSes2"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes3"), retrieveCi(srcdoc, "ContInfWzskNav", "MtxSesSes3"));
	setTextContent(mendoc, mendoc.getElementById("MitSesSps"), retrieveTi(srcdoc, "TagWzskNav", "MitSesSps"));
	setTextContent(mendoc, mendoc.getElementById("MitSesTrm"), retrieveTi(srcdoc, "TagWzskNav", "MitSesTrm"));

	height -= setMitMspAvail("MitSesSps", MitSesSpsAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrWzskNav", "MspCrd1Avail") == "true");
	MitCrdUsgAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitCrdUsgAvail") == "true");
	MitCrdUsrAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitCrdUsrAvail") == "true");
	MitCrdPrsAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitCrdPrsAvail") == "true");
	MitCrdPrfAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitCrdPrfAvail") == "true");
	MspCrd2Avail = (retrieveSi(srcdoc, "StatShrWzskNav", "MspCrd2Avail") == "true");
	MitCrdLlvAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitCrdLlvAvail") == "true");
	MitCrdVtrAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitCrdVtrAvail") == "true");
	MitCrdHwcAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitCrdHwcAvail") == "true");
	MitCrdFilAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "MitCrdFilAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWzskNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitCrdUsg"), retrieveTi(srcdoc, "TagWzskNav", "MitCrdUsg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdUsr"), retrieveTi(srcdoc, "TagWzskNav", "MitCrdUsr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrs"), retrieveTi(srcdoc, "TagWzskNav", "MitCrdPrs"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrf"), retrieveTi(srcdoc, "TagWzskNav", "MitCrdPrf"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdLlv"), retrieveTi(srcdoc, "TagWzskNav", "MitCrdLlv"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdVtr"), retrieveTi(srcdoc, "TagWzskNav", "MitCrdVtr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdHwc"), retrieveTi(srcdoc, "TagWzskNav", "MitCrdHwc"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFil"), retrieveTi(srcdoc, "TagWzskNav", "MitCrdFil"));

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdUsg", MitCrdUsgAvail, 20);
	height -= setMitMspAvail("MitCrdUsr", MitCrdUsrAvail, 20);
	height -= setMitMspAvail("MitCrdPrs", MitCrdPrsAvail, 20);
	height -= setMitMspAvail("MitCrdPrf", MitCrdPrfAvail, 20);
	height -= setMitMspAvail("MspCrd2", MspCrd2Avail, 1);
	height -= setMitMspAvail("MitCrdLlv", MitCrdLlvAvail, 20);
	height -= setMitMspAvail("MitCrdVtr", MitCrdVtrAvail, 20);
	height -= setMitMspAvail("MitCrdHwc", MitCrdHwcAvail, 20);
	height -= setMitMspAvail("MitCrdFil", MitCrdFilAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function setMitMspAvail(short, avail, dh) {
	var mendoc = doc.getElementById("Menu").contentDocument;

	if (!avail) mendoc.getElementById("tr" + short).setAttribute("class", "hide");

	if (avail) return 0;
	else return dh;
};

function setMitActive(short, active) {
	var mendoc = doc.getElementById("Menu").contentDocument;
	var mit = mendoc.getElementById(short);

	if (active) {
		mit.setAttribute("class", "item");
		mit.setAttribute("onclick", "handle" + short + "Click()");
	} else {
		mit.setAttribute("class", "itemdis");
		mit.setAttribute("onclick", "");
	};
};

// --- detached panel functionality
function detachPnl(sref, _scrJref) {
	if ((scrJrefPnld != "") && (scrJrefPnld != _scrJref)) attachPnl();

	scrJrefPnld = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divPnldshld");
	mydiv.setAttribute("class", "pnldshld");
	mydiv.setAttribute("style", "height:" + (getHeight()-35) + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "pnld");
	mydiv.setAttribute("id", "divPnld");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Pnld");
	myif.setAttribute("src", "./" + sref + "_d.html?scrJref=" + _scrJref);
	myif.setAttribute("width", "891"); /// PRELIMINARY
	myif.setAttribute("height", "586");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function maximizePnl() {
	/// TBD
};

function attachPnl() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divPnldshld"));
	body.removeChild(doc.getElementById("divPnld"));

	scrJrefPnld = "";
};

// --- dialog functionality
function showDlg(sref, _scrJref)  {
	if ((scrJrefDlg != "") && (scrJrefDlg != _scrJref)) hideDlg();

	scrJrefDlg = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divDlgshld");
	mydiv.setAttribute("class", "dlgshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "dlg");
	mydiv.setAttribute("id", "divDlg");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Dlg");
	myif.setAttribute("src", "./" + sref + ".html?scrJref=" + _scrJref);
	myif.setAttribute("width", "691");
	if ((sref == "DlgWzskNavLoaini")) myif.setAttribute("height", "585");
	else myif.setAttribute("height", "555");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideDlg() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divDlgshld"));
	body.removeChild(doc.getElementById("divDlg"));

	scrJrefDlg = "";
};

// --- alert functionality
function showAlr(_scrJref, blkcontinf, blkfeedfmcb)  {
	// update information
	scrJrefAlr = _scrJref;

	replaceSrcblock(blkcontinf, "ContInfWzskAlert", srcdoc);
	replaceSrcblock(blkfeedfmcb, "FeedFMcbAlert", srcdoc);

	// show alert
	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divAlrshld");
	mydiv.setAttribute("class", "alrshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "alr");
	mydiv.setAttribute("id", "divAlr");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Alr");
	myif.setAttribute("src", "../iframe/alr.xml");
	myif.setAttribute("width", "501");
	myif.setAttribute("height", "60");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideAlr(numFMcb) {
	var str = serializeDpchAppAlert(scrJrefAlr, numFMcb);
	sendReq(str, doc, handleDpchAppDoReply);

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divAlrshld"));
	body.removeChild(doc.getElementById("divAlr"));

	scrJrefAlr = "";
};

function initAlr() {
	var alrdoc = doc.getElementById("Alr").contentDocument;

	var height = 30+2+3+25;

	setTextContent(alrdoc, alrdoc.getElementById("TxtCpt"), retrieveCi(srcdoc, "ContInfWzskAlert", "TxtCpt"));

	height += fillAlrTxtMsgFromCont(alrdoc, srcdoc, "ContInfWzskAlert");

	doc.getElementById("Alr").setAttribute("height", "" + height);

	fillAlrMcbFromFeed(alrdoc, srcdoc, "FeedFMcbAlert");
};

// --- expand state management
function changeHeight(pnlshort, height) {
	var divPnldshld = doc.getElementById("divPnldshld");
	var divDlgshld = doc.getElementById("divDlgshld");
	var divAlrshld = doc.getElementById("divAlrshld");

	if (pnlshort == "Admin") {
		doc.getElementById("tdAdmin").setAttribute("height", "" + height);
		doc.getElementById("Admin").setAttribute("height", "" + height);
	} else if (pnlshort == "Op") {
		doc.getElementById("tdOp").setAttribute("height", "" + height);
		doc.getElementById("Op").setAttribute("height", "" + height);
	};

	if (divPnldshld) divPnldshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divDlgshld) divDlgshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divAlrshld) divAlrshld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgloaini = retrieveSi(srcdoc, "StatShrWzskNav", "scrJrefDlgloaini");
	var pnladminAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "pnladminAvail") == "true");
	var pnlopAvail = (retrieveSi(srcdoc, "StatShrWzskNav", "pnlopAvail") == "true");

	if (scrJrefDlgloaini != "") {
		if (scrJrefDlg != scrJrefDlgloaini) showDlg("DlgWzskNavLoaini", scrJrefDlgloaini);
	} else if (scrJrefDlg != "") hideDlg();

	setPnlAvail("Admin", pnladminAvail);
	setPnlAvail("Op", pnlopAvail);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleUnload() {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavDo", scrJref, "close");
	sendReq(str, doc, null, true);
};

function handleMitClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMitCrdopenClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, consref) {
	window.open(retrieveCi(srcdoc, "ContInfWzskNav", consref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskNavData", "ContInfWzskNav", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskNavData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngWzskNavData", "StatAppWzskNav", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskNavData", "StatShrWzskNav", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskNavData", "TagWzskNav", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEngSub(_scrJref, dom, dpch) {
	if (_scrJref == scrJrefPnld) {
		doc.getElementById("Pnld").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefDlg) {
		doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefAdmin) {
		doc.getElementById("Admin").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefOp) {
		doc.getElementById("Op").contentWindow.handleDpchEng(dom, dpch);

	} else {
		// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskNavData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrWzskNav", "scrJrefHeadbar");
				scrJrefAdmin = retrieveSi(srcdoc, "StatShrWzskNav", "scrJrefAdmin");
				scrJrefOp = retrieveSi(srcdoc, "StatShrWzskNav", "scrJrefOp");

				scrJrefPnld = "";

				scrJrefDlg = "";

				scrJrefAlr = "";

				// load sub-panels one by one
				checkInitdone();
			};
		};
	};
};

function handleDpchAppDoReply() {
	var _scrJref;

	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) {
			_scrJref = retrieveValue(dom, "//wzsk:*/wzsk:scrJref");

			if (_scrJref != "") {
				if (_scrJref == scrJref) {
					if (blk.nodeName == "DpchEngWzskConfirm") {
						// do nothing

					} else if (blk.nodeName == "DpchEngWzskAlert") {
						// show alert with new content
						showAlr(retrieveValue(dom, "//wzsk:DpchEngWzskAlert/wzsk:scrJref"),
								retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:ContInfWzskAlert"),
								retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:FeedFMcbAlert"));

					} else if (blk.nodeName == "DpchEngWzskNavData") {
						mergeDpchEngData(dom);
						refresh();
					};

				} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
			};

			restartNotify();
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzskConfirm") {
				accepted = retrieveValue(dom, "//wzsk:DpchEngWzskConfirm/wzsk:accepted");
				_scrJref = retrieveValue(dom, "//wzsk:DpchEngWzskConfirm/wzsk:scrJref");
				sref = retrieveValue(dom, "//wzsk:DpchEngWzskConfirm/wzsk:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngWzskAlert") {
				showAlr(retrieveValue(dom, "//wzsk:DpchEngWzskAlert/wzsk:scrJref"),
						retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:ContInfWzskAlert"),
						retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:FeedFMcbAlert"));
			};

			restartNotify();
		};
	};
};

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

	window.open("../CrdWzskStart/CrdWzskStart.html?do=Logout", "_self");
};

function restartNotify() {
	var srefIxWzskVReqitmode = retrieveSi(srcdoc, "StatAppWzskNav", "srefIxWzskVReqitmode");

	if (srefIxWzskVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxWzskVReqitmode = "notify";
		setSi(srcdoc, "StatAppWzskNav", "srefIxWzskVReqitmode", srefIxWzskVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxWzskVReqitmode = retrieveSi(srcdoc, "StatAppWzskNav", "srefIxWzskVReqitmode");

	if (srefIxWzskVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		var str = serializeDpchApp("DpchAppWzskResume", scrJref);
		sendReq(str, doc, handleDpchAppResumeReply);
	};
};

function handleDpchAppResumeReply() {
	var dom, blk;

	if ((doc.req.readyState == 4) && (doc.req.status == 404)) {
		terminate();

	} else if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		if (dom) blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) if (blk.nodeName == "DpchEngWzskAck") restartNotify();
	};
};

function iteratePoll() {
	iterateReqit();
};

function iterateReqit(ev) {
	var dom, blk;

	var accepted, _scrJref, mask;

	var news = false;
	var iterate = true;

	var srefIxWzskVReqitmode = retrieveSi(srcdoc, "StatAppWzskNav", "srefIxWzskVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppWzskNav", "latency"));

	if (doc.reqit && ev) {
		if (doc.reqit.readyState != 4) {
			iterate = false;

		} else if ((doc.reqit.readyState == 4) && (doc.reqit.status == 404)) {
			iterate = false;

			terminate();

		} else if (doc.reqit.readyState == 4) {
			dom = doc.reqit.responseXML;

			// check dispatch type
			if (dom) blk = retrieveBlock(dom, "//wzsk:*");

			if (blk) {
				if (blk.nodeName == "DpchEngWzskAck") {
					// no news
					// alert("no news");

				} else if (blk.nodeName == "DpchEngWzskSuspend") {
					// change to "poll" mode
					news = true;

					srefIxWzskVReqitmode = "poll";
					setSi(srcdoc, "StatAppWzskNav", "srefIxWzskVReqitmode", srefIxWzskVReqitmode);

				} else {
					// request with content
					news = true;

					_scrJref = retrieveValue(dom, "//wzsk:*/wzsk:scrJref");

					if (blk.nodeName == "DpchEngWzskAlert") {
						// card-based treatment even for scrJref corresponding to panel / dialog
						showAlr(retrieveValue(dom, "//wzsk:DpchEngWzskAlert/wzsk:scrJref"),
								retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:ContInfWzskAlert"),
								retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:FeedFMcbAlert"));

					} else if (_scrJref != "") {
						if (_scrJref == scrJref) {
							if (blk.nodeName == "DpchEngWzskConfirm") {
								accepted = retrieveValue(dom, "//wzsk:DpchEngWzskConfirm/wzsk:accepted");

								if (accepted == "false") {
									// arrives on card close
									iterate = false;
									terminate();
								};

							} else if (blk.nodeName == "DpchEngWzskNavData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
					};
				};
			};
		};
	};

	if ((srefIxWzskVReqitmode == "notify") && iterate) {
		// send notify request
		if (!doc.reqit) doc.reqit = new XMLHttpRequest();
		doc.reqit.onreadystatechange = iterateReqit;
		doc.reqit.open("GET", "/notify/" + scrJref, true);
		doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		doc.reqit.send("");

	} else if ((srefIxWzskVReqitmode == "poll") && iterate) {
		if (!ev || (news && ev)) {
			// send poll request
			if (!doc.reqit) doc.reqit = new XMLHttpRequest();
			doc.reqit.onreadystatechange = iterateReqit;
			doc.reqit.open("GET", "/poll/" + scrJref, true);
			doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			doc.reqit.send("");

		} else {
			// wait
			doc.timeout = setTimeout(iteratePoll, latency*1000);
		};
	};
};
