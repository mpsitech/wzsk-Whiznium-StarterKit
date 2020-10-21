/**
  * \file PnlWzskNavAdmin.js
  * web client functionality for panel PnlWzskNavAdmin
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWzskNavAdmin", "srefIxWzskVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzskNavAdmin", "srefIxWzskVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Admin", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Admin_side").setAttribute("height", "30");
	doc.getElementById("Admin_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Admin_side").src = "./PnlWzskNavAdmin_aside.html";
	doc.getElementById("Admin_cont").src = "./PnlWzskNavAdmin_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzskNavAdmin", "srefIxWzskVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzskNavAdmin", "srefIxWzskVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Admin_side").src = "./PnlWzskNavAdmin_bside.html";
	doc.getElementById("Admin_cont").src = "./PnlWzskNavAdmin_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Admin_side").contentDocument;
	contdoc = doc.getElementById("Admin_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskNavAdmin", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Admin_side").contentDocument;
	contdoc = doc.getElementById("Admin_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Admin_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Admin_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskNavAdmin", "Cpt"));
	initCpt(contcontdoc, "CptScf", retrieveTi(srcdoc, "TagWzskNavAdmin", "CptScf"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskNavAdmin", "srefIxWzskVExpstate");

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

	var height = 323; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstUsgAlt = (retrieveSi(srcdoc, "StatAppWzskNavAdmin", "LstUsgAlt") == "true");
	var LstUsgAvail = (retrieveSi(srcdoc, "StatShrWzskNavAdmin", "LstUsgAvail") == "true");
	var ButUsgViewAvail = !LstUsgAlt;
	var ButUsgViewActive = (retrieveSi(srcdoc, "StatShrWzskNavAdmin", "ButUsgViewActive") == "true");

	var LstUsrAlt = (retrieveSi(srcdoc, "StatAppWzskNavAdmin", "LstUsrAlt") == "true");
	var LstUsrAvail = (retrieveSi(srcdoc, "StatShrWzskNavAdmin", "LstUsrAvail") == "true");
	var ButUsrViewAvail = !LstUsrAlt;
	var ButUsrViewActive = (retrieveSi(srcdoc, "StatShrWzskNavAdmin", "ButUsrViewActive") == "true");

	var LstPrsAlt = (retrieveSi(srcdoc, "StatAppWzskNavAdmin", "LstPrsAlt") == "true");
	var LstPrsAvail = (retrieveSi(srcdoc, "StatShrWzskNavAdmin", "LstPrsAvail") == "true");
	var ButPrsViewAvail = !LstPrsAlt;
	var ButPrsViewActive = (retrieveSi(srcdoc, "StatShrWzskNavAdmin", "ButPrsViewActive") == "true");

	var ButScfNewcrdAvail = (retrieveSi(srcdoc, "StatShrWzskNavAdmin", "ButScfNewcrdAvail") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Usg", LstUsgAvail, 96);
	height -= setCtlAvail(contcontdoc, "Usg2", LstUsgAvail && !LstUsgAlt, (LstUsgAvail) ? 71 : 0);
	if (LstUsgAvail) {
		if ( (LstUsgAlt == !contcontdoc.getElementById("ButUsgExpand")) || (!LstUsgAlt == !contcontdoc.getElementById("ButUsgCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynUsg");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptUsg", retrieveTi(srcdoc, "TagWzskNavAdmin", "CptUsg")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstUsgAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButUsgExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButUsgCollapse", "icon/collapse"));
		};

		if (!LstUsgAlt == !contcontdoc.getElementById("LstUsg")) {
			mytd = contcontdoc.getElementById("rdynUsg");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynUsg");
			clearElem(mytd);

			if (LstUsgAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstUsg", "./PnlWzskNavAdmin_LstUsg.xml", true));
			};

		} else {
			if (!LstUsgAlt) refreshLst(contcontdoc.getElementById("LstUsg").contentWindow.document, srcdoc, 1, true, false, "FeedFLstUsg",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavAdmin", "LstUsgNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numFLstUsg"))]);
		};

		if ((ButUsgViewAvail == !contcontdoc.getElementById("ButUsgView")) || !contcontdoc.getElementById("ButUsgNewcrd")) {
			if (LstUsgAlt) mytd = contcontdoc.getElementById("dynUsg");
			else mytd = contcontdoc.getElementById("rdynUsg");
			clearElem(mytd);

			first = true;

			if (ButUsgViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButUsgView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUsgNewcrd", "icon/newcrd"));
		};

		if (ButUsgViewAvail) refreshButicon(contcontdoc, "ButUsgView", "icon/view", ButUsgViewActive, false);

	} else setCtlAvail(contcontdoc, "Usg2", false, 0);

	height -= setCtlAvail(contcontdoc, "Usr", LstUsrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Usr2", LstUsrAvail && !LstUsrAlt, (LstUsrAvail) ? 71 : 0);
	if (LstUsrAvail) {
		if ( (LstUsrAlt == !contcontdoc.getElementById("ButUsrExpand")) || (!LstUsrAlt == !contcontdoc.getElementById("ButUsrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynUsr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptUsr", retrieveTi(srcdoc, "TagWzskNavAdmin", "CptUsr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstUsrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButUsrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButUsrCollapse", "icon/collapse"));
		};

		if (!LstUsrAlt == !contcontdoc.getElementById("LstUsr")) {
			mytd = contcontdoc.getElementById("rdynUsr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynUsr");
			clearElem(mytd);

			if (LstUsrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstUsr", "./PnlWzskNavAdmin_LstUsr.xml", true));
			};

		} else {
			if (!LstUsrAlt) refreshLst(contcontdoc.getElementById("LstUsr").contentWindow.document, srcdoc, 1, true, false, "FeedFLstUsr",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavAdmin", "LstUsrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numFLstUsr"))]);
		};

		if ((ButUsrViewAvail == !contcontdoc.getElementById("ButUsrView")) || !contcontdoc.getElementById("ButUsrNewcrd")) {
			if (LstUsrAlt) mytd = contcontdoc.getElementById("dynUsr");
			else mytd = contcontdoc.getElementById("rdynUsr");
			clearElem(mytd);

			first = true;

			if (ButUsrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButUsrView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUsrNewcrd", "icon/newcrd"));
		};

		if (ButUsrViewAvail) refreshButicon(contcontdoc, "ButUsrView", "icon/view", ButUsrViewActive, false);

	} else setCtlAvail(contcontdoc, "Usr2", false, 0);

	height -= setCtlAvail(contcontdoc, "Prs", LstPrsAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prs2", LstPrsAvail && !LstPrsAlt, (LstPrsAvail) ? 71 : 0);
	if (LstPrsAvail) {
		if ( (LstPrsAlt == !contcontdoc.getElementById("ButPrsExpand")) || (!LstPrsAlt == !contcontdoc.getElementById("ButPrsCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrs");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrs", retrieveTi(srcdoc, "TagWzskNavAdmin", "CptPrs")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrsAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrsExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrsCollapse", "icon/collapse"));
		};

		if (!LstPrsAlt == !contcontdoc.getElementById("LstPrs")) {
			mytd = contcontdoc.getElementById("rdynPrs");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrs");
			clearElem(mytd);

			if (LstPrsAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrs", "./PnlWzskNavAdmin_LstPrs.xml", true));
			};

		} else {
			if (!LstPrsAlt) refreshLst(contcontdoc.getElementById("LstPrs").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrs",
						parseInt(retrieveSi(srcdoc, "StatAppWzskNavAdmin", "LstPrsNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numFLstPrs"))]);
		};

		if ((ButPrsViewAvail == !contcontdoc.getElementById("ButPrsView")) || !contcontdoc.getElementById("ButPrsNewcrd")) {
			if (LstPrsAlt) mytd = contcontdoc.getElementById("dynPrs");
			else mytd = contcontdoc.getElementById("rdynPrs");
			clearElem(mytd);

			first = true;

			if (ButPrsViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrsView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrsNewcrd", "icon/newcrd"));
		};

		if (ButPrsViewAvail) refreshButicon(contcontdoc, "ButPrsView", "icon/view", ButPrsViewActive, false);

	} else setCtlAvail(contcontdoc, "Prs2", false, 0);

	height -= setCtlAvail(contcontdoc, "Scf", ButScfNewcrdAvail, 25);
	if (ButScfNewcrdAvail) {
		if ((ButScfNewcrdAvail == !contcontdoc.getElementById("ButScfNewcrd"))) {
			mytd = contcontdoc.getElementById("dynScf");
			clearElem(mytd);

			first = true;

			if (ButScfNewcrdAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButScfNewcrd", "icon/newcrd"));
			};
		};

	};

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Admin", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Admin_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Admin_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Admin_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskNavAdmin", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Admin_src").contentDocument;

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
	setSi(srcdoc, "StatAppWzskNavAdmin", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWzskNavAdmin", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavAdminDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavAdminDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzskNavAdmin", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzskNavAdmin", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWzskNavAdmin", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWzskNavAdmin", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskNavAdminData", scrJref, "ContIacWzskNavAdmin");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWzskNavAdmin", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWzskNavAdmin", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWzskNavAdmin", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskNavAdminData", "ContIacWzskNavAdmin", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskNavAdminData", "FeedFLstPrs", srcdoc)) mask.push("feedFLstPrs");
	if (updateSrcblock(dom, "DpchEngWzskNavAdminData", "FeedFLstUsg", srcdoc)) mask.push("feedFLstUsg");
	if (updateSrcblock(dom, "DpchEngWzskNavAdminData", "FeedFLstUsr", srcdoc)) mask.push("feedFLstUsr");
	if (updateSrcblock(dom, "DpchEngWzskNavAdminData", "StatAppWzskNavAdmin", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskNavAdminData", "StatShrWzskNavAdmin", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskNavAdminData", "TagWzskNavAdmin", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskNavAdminData") {
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
			if (blk.nodeName == "DpchEngWzskNavAdminData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Admin");
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

			} else if (blk.nodeName == "DpchEngWzskNavAdminData") {
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

