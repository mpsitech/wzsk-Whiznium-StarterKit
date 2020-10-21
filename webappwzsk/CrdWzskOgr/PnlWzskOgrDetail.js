/**
  * \file PnlWzskOgrDetail.js
  * web client functionality for panel PnlWzskOgrDetail
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzskOgrDetail", "srefIxWzskVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzskOgrDetail", "srefIxWzskVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWzskOgrDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzskOgrDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzskOgrDetail", "srefIxWzskVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzskOgrDetail", "srefIxWzskVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWzskOgrDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzskOgrDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskOgrDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWzskOgrDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWzskOgrDetail", "CptTit"));
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagWzskOgrDetail", "CptSup"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWzskOgrDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskOgrDetail", "srefIxWzskVExpstate");

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

	var height = 192; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "TxtSrfActive") == "true");

	var PupJActive = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "PupJActive") == "true");
	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "ButJEditAvail") == "true");

	var TxtTitActive = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "TxtTitActive") == "true");

	var TxtSupActive = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "TxtSupActive") == "true");
	var ButSupViewAvail = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "ButSupViewAvail") == "true");
	var ButSupViewActive = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "ButSupViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWzskOgrDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWzskOgrDetail", "TxtSrf"));

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

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacWzskOgrDetail", "numFPupJ"), PupJActive, false);

	refreshTxt(contcontdoc, "TxtTit", retrieveCi(srcdoc, "ContInfWzskOgrDetail", "TxtTit"));

	if ((ButSupViewAvail == !contcontdoc.getElementById("ButSupView"))) {
		mytd = contcontdoc.getElementById("rdynSup");
		clearElem(mytd);

		first = true;

		if (ButSupViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSupView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfWzskOgrDetail", "TxtSup"));

	if (ButSupViewAvail) refreshButicon(contcontdoc, "ButSupView", "icon/view", ButSupViewActive, false);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWzskOgrDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatAppWzskOgrDetail", "srefIxWzskVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskOgrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskOgrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskOgrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskOgrDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskOgrDetailData", scrJref, "ContIacWzskOgrDetail");
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

	setCi(srcdoc, "ContIacWzskOgrDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskOgrDetailData", scrJref, "ContIacWzskOgrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskOgrDetailData", "ContIacWzskOgrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskOgrDetailData", "ContInfWzskOgrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskOgrDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngWzskOgrDetailData", "StatAppWzskOgrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskOgrDetailData", "StatShrWzskOgrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskOgrDetailData", "TagWzskOgrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskOgrDetailData") {
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
			if (blk.nodeName == "DpchEngWzskOgrDetailData") {
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

			} else if (blk.nodeName == "DpchEngWzskOgrDetailData") {
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

