// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWzskNavOp", "srefIxWzskVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzskNavOp", "srefIxWzskVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Op", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Op_side").setAttribute("height", "30");
	doc.getElementById("Op_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Op_side").src = "./PnlWzskNavOp_aside.html";
	doc.getElementById("Op_cont").src = "./PnlWzskNavOp_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzskNavOp", "srefIxWzskVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzskNavOp", "srefIxWzskVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Op_side").src = "./PnlWzskNavOp_bside.html";
	doc.getElementById("Op_cont").src = "./PnlWzskNavOp_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Op_side").contentDocument;
	contdoc = doc.getElementById("Op_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskNavOp", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Op_side").contentDocument;
	contdoc = doc.getElementById("Op_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Op_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Op_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskNavOp", "Cpt"));
	initCpt(contcontdoc, "CptLlv", retrieveTi(srcdoc, "TagWzskNavOp", "CptLlv"));
	initCpt(contcontdoc, "CptVtr", retrieveTi(srcdoc, "TagWzskNavOp", "CptVtr"));
	initCpt(contcontdoc, "CptHwc", retrieveTi(srcdoc, "TagWzskNavOp", "CptHwc"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskNavOp", "srefIxWzskVExpstate");

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

	var height = 181; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButLlvNewcrdAvail = (retrieveSi(srcdoc, "StatShrWzskNavOp", "ButLlvNewcrdAvail") == "true");

	var ButVtrNewcrdAvail = (retrieveSi(srcdoc, "StatShrWzskNavOp", "ButVtrNewcrdAvail") == "true");

	var ButHwcNewcrdAvail = (retrieveSi(srcdoc, "StatShrWzskNavOp", "ButHwcNewcrdAvail") == "true");

	var LstFilAlt = (retrieveSi(srcdoc, "StatAppWzskNavOp", "LstFilAlt") == "true");
	var LstFilAvail = (retrieveSi(srcdoc, "StatShrWzskNavOp", "LstFilAvail") == "true");
	var ButFilViewAvail = !LstFilAlt;
	var ButFilViewActive = (retrieveSi(srcdoc, "StatShrWzskNavOp", "ButFilViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Llv", ButLlvNewcrdAvail, 25);
	if (ButLlvNewcrdAvail) {
		if ((ButLlvNewcrdAvail == !contcontdoc.getElementById("ButLlvNewcrd"))) {
			mytd = contcontdoc.getElementById("dynLlv");
			clearElem(mytd);

			first = true;

			if (ButLlvNewcrdAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLlvNewcrd", "icon/newcrd"));
			};
		};

	};

	height -= setCtlAvail(contcontdoc, "Vtr", ButVtrNewcrdAvail, 25);
	if (ButVtrNewcrdAvail) {
		if ((ButVtrNewcrdAvail == !contcontdoc.getElementById("ButVtrNewcrd"))) {
			mytd = contcontdoc.getElementById("dynVtr");
			clearElem(mytd);

			first = true;

			if (ButVtrNewcrdAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVtrNewcrd", "icon/newcrd"));
			};
		};

	};

	height -= setCtlAvail(contcontdoc, "Hwc", ButHwcNewcrdAvail, 25);
	if (ButHwcNewcrdAvail) {
		if ((ButHwcNewcrdAvail == !contcontdoc.getElementById("ButHwcNewcrd"))) {
			mytd = contcontdoc.getElementById("dynHwc");
			clearElem(mytd);

			first = true;

			if (ButHwcNewcrdAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButHwcNewcrd", "icon/newcrd"));
			};
		};

	};

	height -= setCtlAvail(contcontdoc, "Fil", LstFilAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fil2", LstFilAvail && !LstFilAlt, (LstFilAvail) ? 71 : 0);
	if (LstFilAvail) {
		if ( (LstFilAlt == !contcontdoc.getElementById("ButFilExpand")) || (!LstFilAlt == !contcontdoc.getElementById("ButFilCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFil");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFil", retrieveTi(srcdoc, "TagWzskNavOp", "CptFil")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFil", "./PnlWzskNavOp_LstFil.xml", true));
			};

		} else {
			if (!LstFilAlt) refreshLst(contcontdoc.getElementById("LstFil").contentWindow.document, srcdoc, 1, true, false, "FeedFLstFil",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavOp", "LstFilNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavOp", "numFLstFil"))]);
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

	getCrdwnd().changeHeight("Op", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Op_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Op_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Op_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskNavOp", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Op_src").contentDocument;

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
	setSi(srcdoc, "StatAppWzskNavOp", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWzskNavOp", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavOpDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavOpDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzskNavOp", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavOp", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzskNavOp", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWzskNavOp", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavOp", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWzskNavOp", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWzskNavOp", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWzskNavOp", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskNavOpData", scrJref, "ContIacWzskNavOp");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWzskNavOp", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWzskNavOp", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavOp", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWzskNavOp", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskNavOpData", "ContIacWzskNavOp", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskNavOpData", "FeedFLstFil", srcdoc)) mask.push("feedFLstFil");
	if (updateSrcblock(dom, "DpchEngWzskNavOpData", "StatAppWzskNavOp", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskNavOpData", "StatShrWzskNavOp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskNavOpData", "TagWzskNavOp", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskNavOpData") {
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
			if (blk.nodeName == "DpchEngWzskNavOpData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Op");
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

			} else if (blk.nodeName == "DpchEngWzskNavOpData") {
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
