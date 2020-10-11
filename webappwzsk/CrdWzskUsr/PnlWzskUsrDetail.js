/**
  * \file PnlWzskUsrDetail.js
  * web client functionality for panel PnlWzskUsrDetail
  * \author Catherine Johnson
  * \date created: 6 Oct 2020
  * \date modified: 6 Oct 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzskUsrDetail", "srefIxWzskVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzskUsrDetail", "srefIxWzskVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWzskUsrDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzskUsrDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzskUsrDetail", "srefIxWzskVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzskUsrDetail", "srefIxWzskVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWzskUsrDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzskUsrDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskUsrDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptPrs", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptPrs"));
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptSrf"));
	initCpt(contcontdoc, "CptUsg", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptUsg"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacWzskUsrDetail", "numFPupSte"), retrieveSi(srcdoc, "StatShrWzskUsrDetail", "PupSteActive"), false);
	initCpt(contcontdoc, "CptLcl", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptLcl"));
	refreshPup(contcontdoc, srcdoc, "PupLcl", "", "FeedFPupLcl", retrieveCi(srcdoc, "ContIacWzskUsrDetail", "numFPupLcl"), retrieveSi(srcdoc, "StatShrWzskUsrDetail", "PupLclActive"), false);
	initCpt(contcontdoc, "CptUlv", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptUlv"));
	refreshPup(contcontdoc, srcdoc, "PupUlv", "", "FeedFPupUlv", retrieveCi(srcdoc, "ContIacWzskUsrDetail", "numFPupUlv"), retrieveSi(srcdoc, "StatShrWzskUsrDetail", "PupUlvActive"), false);
	initCpt(contcontdoc, "CptPwd", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptPwd"));
	initCpt(contcontdoc, "CptFky", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptFky"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWzskUsrDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskUsrDetail", "srefIxWzskVExpstate");

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

	var height = 367; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtPrsActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "TxtPrsActive") == "true");
	var ButPrsViewAvail = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "ButPrsViewAvail") == "true");
	var ButPrsViewActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "ButPrsViewActive") == "true");

	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "TxtSrfActive") == "true");

	var TxtUsgActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "TxtUsgActive") == "true");
	var ButUsgViewAvail = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "ButUsgViewAvail") == "true");
	var ButUsgViewActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "ButUsgViewActive") == "true");

	var PupJActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "PupJActive") == "true");
	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "ButJEditAvail") == "true");

	var PupSteActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "PupSteActive") == "true");

	var PupLclActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "PupLclActive") == "true");

	var PupUlvActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "PupUlvActive") == "true");

	var TxfPwdActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "TxfPwdActive") == "true");

	var TxfFkyActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "TxfFkyActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWzskUsrDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButPrsViewAvail == !contcontdoc.getElementById("ButPrsView"))) {
		mytd = contcontdoc.getElementById("rdynPrs");
		clearElem(mytd);

		first = true;

		if (ButPrsViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrsView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrs", retrieveCi(srcdoc, "ContInfWzskUsrDetail", "TxtPrs"));

	if (ButPrsViewAvail) refreshButicon(contcontdoc, "ButPrsView", "icon/view", ButPrsViewActive, false);

	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWzskUsrDetail", "TxtSrf"));

	if ((ButUsgViewAvail == !contcontdoc.getElementById("ButUsgView"))) {
		mytd = contcontdoc.getElementById("rdynUsg");
		clearElem(mytd);

		first = true;

		if (ButUsgViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUsgView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtUsg", retrieveCi(srcdoc, "ContInfWzskUsrDetail", "TxtUsg"));

	if (ButUsgViewAvail) refreshButicon(contcontdoc, "ButUsgView", "icon/view", ButUsgViewActive, false);

	if ((ButJEditAvail == !contcontdoc.getElementById("ButJEdit"))) {
		mytd = contcontdoc.getElementById("rdynJ");
		clearElem(mytd);

		first = true;

		if (ButJEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacWzskUsrDetail", "numFPupJ"), PupJActive, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacWzskUsrDetail", "numFPupSte");

	contcontdoc.getElementById("PupLcl").value = retrieveCi(srcdoc, "ContIacWzskUsrDetail", "numFPupLcl");

	contcontdoc.getElementById("PupUlv").value = retrieveCi(srcdoc, "ContIacWzskUsrDetail", "numFPupUlv");

	refreshTxf(contcontdoc, "TxfPwd", "s", retrieveCi(srcdoc, "ContIacWzskUsrDetail", "TxfPwd"), TxfPwdActive, false, true);

	refreshTxft(contcontdoc, "TxfFky", retrieveCi(srcdoc, "ContIacWzskUsrDetail", "TxfFky"), TxfFkyActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWzskUsrDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskUsrDetail", "srefIxWzskVExpstate");

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

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskUsrDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskUsrDetailData", scrJref, "ContIacWzskUsrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskUsrDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskUsrDetailData", scrJref, "ContIacWzskUsrDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskUsrDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskUsrDetailData", scrJref, "ContIacWzskUsrDetail");
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

	setCi(srcdoc, "ContIacWzskUsrDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskUsrDetailData", scrJref, "ContIacWzskUsrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "ContIacWzskUsrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "ContInfWzskUsrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "FeedFPupLcl", srcdoc)) mask.push("feedFPupLcl");
	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "FeedFPupUlv", srcdoc)) mask.push("feedFPupUlv");
	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "StatAppWzskUsrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "StatShrWzskUsrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskUsrDetailData", "TagWzskUsrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskUsrDetailData") {
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
			if (blk.nodeName == "DpchEngWzskUsrDetailData") {
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

			} else if (blk.nodeName == "DpchEngWzskUsrDetailData") {
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

