// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWzskNavGalery", "srefIxWzskVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzskNavGalery", "srefIxWzskVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Galery", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Galery_side").setAttribute("height", "30");
	doc.getElementById("Galery_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Galery_side").src = "./PnlWzskNavGalery_aside.html";
	doc.getElementById("Galery_cont").src = "./PnlWzskNavGalery_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzskNavGalery", "srefIxWzskVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzskNavGalery", "srefIxWzskVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Galery_side").src = "./PnlWzskNavGalery_bside.html";
	doc.getElementById("Galery_cont").src = "./PnlWzskNavGalery_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Galery_side").contentDocument;
	contdoc = doc.getElementById("Galery_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskNavGalery", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Galery_side").contentDocument;
	contdoc = doc.getElementById("Galery_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Galery_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Galery_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskNavGalery", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskNavGalery", "srefIxWzskVExpstate");

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

	var height = 490; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstOgrAlt = (retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstOgrAlt") == "true");
	var LstOgrAvail = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "LstOgrAvail") == "true");
	var ButOgrViewAvail = !LstOgrAlt;
	var ButOgrViewActive = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "ButOgrViewActive") == "true");

	var LstObjAlt = (retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstObjAlt") == "true");
	var LstObjAvail = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "LstObjAvail") == "true");
	var ButObjViewAvail = !LstObjAlt;
	var ButObjViewActive = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "ButObjViewActive") == "true");

	var LstSesAlt = (retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstSesAlt") == "true");
	var LstSesAvail = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "LstSesAvail") == "true");
	var ButSesViewAvail = !LstSesAlt;
	var ButSesViewActive = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "ButSesViewActive") == "true");

	var LstShtAlt = (retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstShtAlt") == "true");
	var LstShtAvail = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "LstShtAvail") == "true");
	var ButShtViewAvail = !LstShtAlt;
	var ButShtViewActive = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "ButShtViewActive") == "true");

	var LstFilAlt = (retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstFilAlt") == "true");
	var LstFilAvail = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "LstFilAvail") == "true");
	var ButFilViewAvail = !LstFilAlt;
	var ButFilViewActive = (retrieveSi(srcdoc, "StatShrWzskNavGalery", "ButFilViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Ogr", LstOgrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ogr2", LstOgrAvail && !LstOgrAlt, (LstOgrAvail) ? 71 : 0);
	if (LstOgrAvail) {
		if ( (LstOgrAlt == !contcontdoc.getElementById("ButOgrExpand")) || (!LstOgrAlt == !contcontdoc.getElementById("ButOgrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynOgr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptOgr", retrieveTi(srcdoc, "TagWzskNavGalery", "CptOgr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstOgrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOgrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButOgrCollapse", "icon/collapse"));
		};

		if (!LstOgrAlt == !contcontdoc.getElementById("LstOgr")) {
			mytd = contcontdoc.getElementById("rdynOgr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynOgr");
			clearElem(mytd);

			if (LstOgrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstOgr", "./PnlWzskNavGalery_LstOgr.xml", true));
			};

		} else {
			if (!LstOgrAlt) refreshLst(contcontdoc.getElementById("LstOgr").contentWindow.document, srcdoc, 1, true, false, "FeedFLstOgr",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstOgrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numFLstOgr"))]);
		};

		if ((ButOgrViewAvail == !contcontdoc.getElementById("ButOgrView")) || !contcontdoc.getElementById("ButOgrNewcrd")) {
			if (LstOgrAlt) mytd = contcontdoc.getElementById("dynOgr");
			else mytd = contcontdoc.getElementById("rdynOgr");
			clearElem(mytd);

			first = true;

			if (ButOgrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButOgrView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOgrNewcrd", "icon/newcrd"));
		};

		if (ButOgrViewAvail) refreshButicon(contcontdoc, "ButOgrView", "icon/view", ButOgrViewActive, false);

	} else setCtlAvail(contcontdoc, "Ogr2", false, 0);

	height -= setCtlAvail(contcontdoc, "Obj", LstObjAvail, 96);
	height -= setCtlAvail(contcontdoc, "Obj2", LstObjAvail && !LstObjAlt, (LstObjAvail) ? 71 : 0);
	if (LstObjAvail) {
		if ( (LstObjAlt == !contcontdoc.getElementById("ButObjExpand")) || (!LstObjAlt == !contcontdoc.getElementById("ButObjCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynObj");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptObj", retrieveTi(srcdoc, "TagWzskNavGalery", "CptObj")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstObjAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButObjExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButObjCollapse", "icon/collapse"));
		};

		if (!LstObjAlt == !contcontdoc.getElementById("LstObj")) {
			mytd = contcontdoc.getElementById("rdynObj");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynObj");
			clearElem(mytd);

			if (LstObjAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstObj", "./PnlWzskNavGalery_LstObj.xml", true));
			};

		} else {
			if (!LstObjAlt) refreshLst(contcontdoc.getElementById("LstObj").contentWindow.document, srcdoc, 1, true, false, "FeedFLstObj",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstObjNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numFLstObj"))]);
		};

		if ((ButObjViewAvail == !contcontdoc.getElementById("ButObjView")) || !contcontdoc.getElementById("ButObjNewcrd")) {
			if (LstObjAlt) mytd = contcontdoc.getElementById("dynObj");
			else mytd = contcontdoc.getElementById("rdynObj");
			clearElem(mytd);

			first = true;

			if (ButObjViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButObjView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButObjNewcrd", "icon/newcrd"));
		};

		if (ButObjViewAvail) refreshButicon(contcontdoc, "ButObjView", "icon/view", ButObjViewActive, false);

	} else setCtlAvail(contcontdoc, "Obj2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ses", LstSesAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ses2", LstSesAvail && !LstSesAlt, (LstSesAvail) ? 71 : 0);
	if (LstSesAvail) {
		if ( (LstSesAlt == !contcontdoc.getElementById("ButSesExpand")) || (!LstSesAlt == !contcontdoc.getElementById("ButSesCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSes");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSes", retrieveTi(srcdoc, "TagWzskNavGalery", "CptSes")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSesAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSesExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSesCollapse", "icon/collapse"));
		};

		if (!LstSesAlt == !contcontdoc.getElementById("LstSes")) {
			mytd = contcontdoc.getElementById("rdynSes");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSes");
			clearElem(mytd);

			if (LstSesAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSes", "./PnlWzskNavGalery_LstSes.xml", true));
			};

		} else {
			if (!LstSesAlt) refreshLst(contcontdoc.getElementById("LstSes").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSes",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstSesNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numFLstSes"))]);
		};

		if ((ButSesViewAvail == !contcontdoc.getElementById("ButSesView")) || !contcontdoc.getElementById("ButSesNewcrd")) {
			if (LstSesAlt) mytd = contcontdoc.getElementById("dynSes");
			else mytd = contcontdoc.getElementById("rdynSes");
			clearElem(mytd);

			first = true;

			if (ButSesViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSesView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSesNewcrd", "icon/newcrd"));
		};

		if (ButSesViewAvail) refreshButicon(contcontdoc, "ButSesView", "icon/view", ButSesViewActive, false);

	} else setCtlAvail(contcontdoc, "Ses2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sht", LstShtAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sht2", LstShtAvail && !LstShtAlt, (LstShtAvail) ? 71 : 0);
	if (LstShtAvail) {
		if ( (LstShtAlt == !contcontdoc.getElementById("ButShtExpand")) || (!LstShtAlt == !contcontdoc.getElementById("ButShtCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSht");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSht", retrieveTi(srcdoc, "TagWzskNavGalery", "CptSht")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstShtAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButShtExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButShtCollapse", "icon/collapse"));
		};

		if (!LstShtAlt == !contcontdoc.getElementById("LstSht")) {
			mytd = contcontdoc.getElementById("rdynSht");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSht");
			clearElem(mytd);

			if (LstShtAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSht", "./PnlWzskNavGalery_LstSht.xml", true));
			};

		} else {
			if (!LstShtAlt) refreshLst(contcontdoc.getElementById("LstSht").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSht",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstShtNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numFLstSht"))]);
		};

		if ((ButShtViewAvail == !contcontdoc.getElementById("ButShtView")) || !contcontdoc.getElementById("ButShtNewcrd")) {
			if (LstShtAlt) mytd = contcontdoc.getElementById("dynSht");
			else mytd = contcontdoc.getElementById("rdynSht");
			clearElem(mytd);

			first = true;

			if (ButShtViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButShtView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButShtNewcrd", "icon/newcrd"));
		};

		if (ButShtViewAvail) refreshButicon(contcontdoc, "ButShtView", "icon/view", ButShtViewActive, false);

	} else setCtlAvail(contcontdoc, "Sht2", false, 0);

	height -= setCtlAvail(contcontdoc, "Fil", LstFilAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fil2", LstFilAvail && !LstFilAlt, (LstFilAvail) ? 71 : 0);
	if (LstFilAvail) {
		if ( (LstFilAlt == !contcontdoc.getElementById("ButFilExpand")) || (!LstFilAlt == !contcontdoc.getElementById("ButFilCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFil");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFil", retrieveTi(srcdoc, "TagWzskNavGalery", "CptFil")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFilAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFilExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFilCollapse", "icon/collapse"));
		};

		if (!LstFilAlt == !contcontdoc.getElementById("LstFil")) {
			mytd = contcontdoc.getElementById("rdynFil");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFil");
			clearElem(mytd);

			if (LstFilAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFil", "./PnlWzskNavGalery_LstFil.xml", true));
			};

		} else {
			if (!LstFilAlt) refreshLst(contcontdoc.getElementById("LstFil").contentWindow.document, srcdoc, 1, true, false, "FeedFLstFil",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavGalery", "LstFilNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numFLstFil"))]);
		};

		if ((ButFilViewAvail == !contcontdoc.getElementById("ButFilView")) || !contcontdoc.getElementById("ButFilNewcrd")) {
			if (LstFilAlt) mytd = contcontdoc.getElementById("dynFil");
			else mytd = contcontdoc.getElementById("rdynFil");
			clearElem(mytd);

			first = true;

			if (ButFilViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFilView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFilNewcrd", "icon/newcrd"));
		};

		if (ButFilViewAvail) refreshButicon(contcontdoc, "ButFilView", "icon/view", ButFilViewActive, false);

	} else setCtlAvail(contcontdoc, "Fil2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Galery", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Galery_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Galery_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Galery_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskNavGalery", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Galery_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWzskNavGalery", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWzskNavGalery", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavGaleryDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavGaleryDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzskNavGalery", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzskNavGalery", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWzskNavGalery", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWzskNavGalery", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskNavGaleryData", scrJref, "ContIacWzskNavGalery");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWzskNavGalery", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWzskNavGalery", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWzskNavGalery", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "ContIacWzskNavGalery", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "FeedFLstFil", srcdoc)) mask.push("feedFLstFil");
	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "FeedFLstObj", srcdoc)) mask.push("feedFLstObj");
	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "FeedFLstOgr", srcdoc)) mask.push("feedFLstOgr");
	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "FeedFLstSes", srcdoc)) mask.push("feedFLstSes");
	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "FeedFLstSht", srcdoc)) mask.push("feedFLstSht");
	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "StatAppWzskNavGalery", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "StatShrWzskNavGalery", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskNavGaleryData", "TagWzskNavGalery", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskNavGaleryData") {
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
			if (blk.nodeName == "DpchEngWzskNavGaleryData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Galery");
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

			} else if (blk.nodeName == "DpchEngWzskNavGaleryData") {
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

