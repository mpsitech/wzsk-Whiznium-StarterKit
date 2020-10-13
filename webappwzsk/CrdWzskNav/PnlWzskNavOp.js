/**
  * \file PnlWzskNavOp.js
  * web client functionality for panel PnlWzskNavOp
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

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
	initCpt(contcontdoc, "CptLiv", retrieveTi(srcdoc, "TagWzskNavOp", "CptLiv"));
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

	var height = 60; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButLlvNewcrdAvail = (retrieveSi(srcdoc, "StatShrWzskNavOp", "ButLlvNewcrdAvail") == "true");

	var ButLivNewcrdAvail = (retrieveSi(srcdoc, "StatShrWzskNavOp", "ButLivNewcrdAvail") == "true");

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

	height -= setCtlAvail(contcontdoc, "Liv", ButLivNewcrdAvail, 25);
	if (ButLivNewcrdAvail) {
		if ((ButLivNewcrdAvail == !contcontdoc.getElementById("ButLivNewcrd"))) {
			mytd = contcontdoc.getElementById("dynLiv");
			clearElem(mytd);

			first = true;

			if (ButLivNewcrdAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLivNewcrd", "icon/newcrd"));
			};
		};

	};

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

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavOpDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavOpDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskNavOpData", "StatAppWzskNavOp", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskNavOpData", "StatShrWzskNavOp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskNavOpData", "TagWzskNavOp", srcdoc)) mask.push("tag");

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

