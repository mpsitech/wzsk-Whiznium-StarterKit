// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzskFilDetail", "srefIxWzskVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzskFilDetail", "srefIxWzskVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWzskFilDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzskFilDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzskFilDetail", "srefIxWzskVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzskFilDetail", "srefIxWzskVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWzskFilDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzskFilDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskFilDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptFnm", retrieveTi(srcdoc, "TagWzskFilDetail", "CptFnm"));
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWzskFilDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWzskFilDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptCnt", retrieveTi(srcdoc, "TagWzskFilDetail", "CptCnt"));
	initCpt(contcontdoc, "CptAcv", retrieveTi(srcdoc, "TagWzskFilDetail", "CptAcv"));
	initCpt(contcontdoc, "CptAnm", retrieveTi(srcdoc, "TagWzskFilDetail", "CptAnm"));
	initCpt(contcontdoc, "CptMim", retrieveTi(srcdoc, "TagWzskFilDetail", "CptMim"));
	initCpt(contcontdoc, "CptSiz", retrieveTi(srcdoc, "TagWzskFilDetail", "CptSiz"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWzskFilDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskFilDetail", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		initA();
	} else if (srefIxWzskVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWzskVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 363; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxfFnmActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "TxfFnmActive") == "true");

	var LstCluAlt = (retrieveSi(srcdoc, "StatAppWzskFilDetail", "LstCluAlt") == "true");
	var LstCluActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "LstCluActive") == "true");
	var ButCluViewAvail = !LstCluAlt;
	var ButCluViewActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "ButCluViewActive") == "true");
	var ButCluClusterAvail = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "ButCluClusterAvail") == "true");
	var ButCluUnclusterAvail = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "ButCluUnclusterAvail") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "ButReuViewActive") == "true");

	var PupCntAlt = (retrieveSi(srcdoc, "StatAppWzskFilDetail", "PupCntAlt") == "true");
	var TxfCntValid = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "TxfCntValid") == "true");
	var PupCntActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "PupCntActive") == "true");
	var ButCntEditAvail = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "ButCntEditAvail") == "true");

	var TxfAcvActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "TxfAcvActive") == "true");

	var TxfAnmActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "TxfAnmActive") == "true");

	var PupMimAlt = (retrieveSi(srcdoc, "StatAppWzskFilDetail", "PupMimAlt") == "true");
	var TxfMimValid = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "TxfMimValid") == "true");
	var PupMimActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "PupMimActive") == "true");
	var ButMimEditAvail = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "ButMimEditAvail") == "true");

	var TxfSizActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "TxfSizActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWzskFilDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "TxfFnm", "", retrieveCi(srcdoc, "ContIacWzskFilDetail", "TxfFnm"), TxfFnmActive, false, true);

	height -= setCtlAvail(contcontdoc, "Clu2", !LstCluAlt, 71);
	if ( (LstCluAlt == !contcontdoc.getElementById("ButCluExpand")) || (!LstCluAlt == !contcontdoc.getElementById("ButCluCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynClu");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptClu", retrieveTi(srcdoc, "TagWzskFilDetail", "CptClu")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstCluAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCluExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButCluCollapse", "icon/collapse"));
	};

	if ( (LstCluAlt == !contcontdoc.getElementById("TxtClu")) || (!LstCluAlt == !contcontdoc.getElementById("LstClu")) ) {
		mytd = contcontdoc.getElementById("dynClu");
		clearElem(mytd);

		if (LstCluAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtClu", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstClu", "./PnlWzskFilDetail_LstClu.xml", false));
		};

	} else {
		if (!LstCluAlt) refreshLst(contcontdoc.getElementById("LstClu").contentWindow.document, srcdoc, 1, false, false, "FeedFLstClu",
					parseInt(retrieveSi(srcdoc, "StatAppWzskFilDetail", "LstCluNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskFilDetail", "numFLstClu"))]);
	};

	if (LstCluAlt) refreshTxt(contcontdoc, "TxtClu", retrieveCi(srcdoc, "ContInfWzskFilDetail", "TxtClu"));

	if ((ButCluViewAvail == !contcontdoc.getElementById("ButCluView")) || (ButCluClusterAvail == !contcontdoc.getElementById("ButCluCluster")) || (ButCluUnclusterAvail == !contcontdoc.getElementById("ButCluUncluster"))) {
		mytd = contcontdoc.getElementById("rdynClu");
		clearElem(mytd);

		first = true;

		if (ButCluViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluView", "icon/view"));
		};

		if (ButCluClusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluCluster", "icon/cluster"));
		};

		if (ButCluUnclusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluUncluster", "icon/uncluster"));
		};
	};

	if (ButCluViewAvail) refreshButicon(contcontdoc, "ButCluView", "icon/view", ButCluViewActive, false);

	if ((ButReuViewAvail == !contcontdoc.getElementById("ButReuView"))) {
		mytd = contcontdoc.getElementById("rdynReu");
		clearElem(mytd);

		first = true;

		if (ButReuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButReuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWzskFilDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWzskFilDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	if ( (PupCntAlt == !contcontdoc.getElementById("TxfCnt")) || (!PupCntAlt == !contcontdoc.getElementById("PupCnt")) ) {
		mytd = contcontdoc.getElementById("dynCnt");
		clearElem(mytd);

		if (PupCntAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfCnt", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupCnt", ""));
	};

	if (PupCntAlt) refreshTxf(contcontdoc, "TxfCnt", "", retrieveCi(srcdoc, "ContIacWzskFilDetail", "TxfCnt"), PupCntActive, false, TxfCntValid);
	else refreshPup(contcontdoc, srcdoc, "PupCnt", "", "FeedFPupCnt", retrieveCi(srcdoc, "ContIacWzskFilDetail", "numFPupCnt"), true, false);

	if ((ButCntEditAvail == !contcontdoc.getElementById("ButCntEdit"))) {
		mytd = contcontdoc.getElementById("rdynCnt");
		clearElem(mytd);

		first = true;

		if (ButCntEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCntEdit", "icon/edit"));
		};
	};

	refreshTxf(contcontdoc, "TxfAcv", "", retrieveCi(srcdoc, "ContIacWzskFilDetail", "TxfAcv"), TxfAcvActive, false, true);

	refreshTxf(contcontdoc, "TxfAnm", "s", retrieveCi(srcdoc, "ContIacWzskFilDetail", "TxfAnm"), TxfAnmActive, false, true);

	if ( (PupMimAlt == !contcontdoc.getElementById("TxfMim")) || (!PupMimAlt == !contcontdoc.getElementById("PupMim")) ) {
		mytd = contcontdoc.getElementById("dynMim");
		clearElem(mytd);

		if (PupMimAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfMim", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupMim", ""));
	};

	if (PupMimAlt) refreshTxf(contcontdoc, "TxfMim", "", retrieveCi(srcdoc, "ContIacWzskFilDetail", "TxfMim"), PupMimActive, false, TxfMimValid);
	else refreshPup(contcontdoc, srcdoc, "PupMim", "", "FeedFPupMim", retrieveCi(srcdoc, "ContIacWzskFilDetail", "numFPupMim"), true, false);

	if ((ButMimEditAvail == !contcontdoc.getElementById("ButMimEdit"))) {
		mytd = contcontdoc.getElementById("rdynMim");
		clearElem(mytd);

		first = true;

		if (ButMimEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMimEdit", "icon/edit"));
		};
	};

	refreshTxf(contcontdoc, "TxfSiz", "s", retrieveCi(srcdoc, "ContIacWzskFilDetail", "TxfSiz"), TxfSizActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWzskFilDetail", "TxfCmt"), TxfCmtActive, false, true);

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskFilDetail", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		refreshA();
	} else if (srefIxWzskVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWzskVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWzskFilDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWzskFilDetail", basectlsref + "Alt", "false");
	refresh();
};

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppWzskFilDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWzskFilDetail", basectlsref + "Alt", alt);

	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskFilDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskFilDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskFilDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzskFilDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWzskFilDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzskFilDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWzskFilDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWzskFilDetail", "numsF" + ctlsref));

		found = false;

		for (var i = 0; i < oldNumsFLst.length; i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j = 0; j < oldNumsFLst.length; j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i = 0; i < oldNumsFLst.length; i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacWzskFilDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWzskFilDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWzskFilDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskFilDetailData", scrJref, "ContIacWzskFilDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWzskFilDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWzskFilDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWzskFilDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWzskFilDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskFilDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskFilDetailData", scrJref, "ContIacWzskFilDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskFilDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskFilDetailData", scrJref, "ContIacWzskFilDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskFilDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskFilDetailData", scrJref, "ContIacWzskFilDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWzskFilDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskFilDetailData", scrJref, "ContIacWzskFilDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "ContIacWzskFilDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "ContInfWzskFilDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "FeedFLstClu", srcdoc)) mask.push("feedFLstClu");
	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "FeedFPupCnt", srcdoc)) mask.push("feedFPupCnt");
	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "FeedFPupMim", srcdoc)) mask.push("feedFPupMim");
	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "StatAppWzskFilDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "StatShrWzskFilDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskFilDetailData", "TagWzskFilDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskFilDetailData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskFilDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzskConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzskFilDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
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
				getCrdwnd().showAlr(retrieveValue(dom, "//wzsk:DpchEngWzskAlert/wzsk:scrJref"),
						retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:ContInfWzskAlert"),
						retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:FeedFMcbAlert"));
			};
		};
	};
};

function handleDpchAppDoDlgopenReply() {
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

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};
