// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Debug", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Debug_side").setAttribute("height", "30");
	doc.getElementById("Debug_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Debug_side").src = "./PnlWzskVtrDebug_aside.html";
	doc.getElementById("Debug_cont").src = "./PnlWzskVtrDebug_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Debug_side").src = "./PnlWzskVtrDebug_bside.html";
	doc.getElementById("Debug_cont").src = "./PnlWzskVtrDebug_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Debug_side").contentDocument;
	contdoc = doc.getElementById("Debug_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskVtrDebug", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Debug_side").contentDocument;
	contdoc = doc.getElementById("Debug_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Debug_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Debug_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskVtrDebug", "Cpt"));
	initCpt(contcontdoc, "HdgTrk", retrieveTi(srcdoc, "TagWzskVtrDebug", "HdgTrk"));
	initCpt(contcontdoc, "CptTfr", retrieveTi(srcdoc, "TagWzskVtrDebug", "CptTfr"));
	initCpt(contcontdoc, "CptTst", retrieveTi(srcdoc, "TagWzskVtrDebug", "CptTst"));
	initBut(contcontdoc, "ButTsr", retrieveTi(srcdoc, "TagWzskVtrDebug", "ButTsr"));
	initBut(contcontdoc, "ButTsp", retrieveTi(srcdoc, "TagWzskVtrDebug", "ButTsp"));
	initCpt(contcontdoc, "CptTtf", retrieveTi(srcdoc, "TagWzskVtrDebug", "CptTtf"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrDebug", "srefIxWzskVExpstate");

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

	var height = 135; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskVtrDebug", "ButClaimActive") == "true");

	var TxfTfrActive = (retrieveSi(srcdoc, "StatShrWzskVtrDebug", "TxfTfrActive") == "true");

	var ButTsrActive = (retrieveSi(srcdoc, "StatShrWzskVtrDebug", "ButTsrActive") == "true");
	var ButTspActive = (retrieveSi(srcdoc, "StatShrWzskVtrDebug", "ButTspActive") == "true");

	var ButTtfViewActive = (retrieveSi(srcdoc, "StatShrWzskVtrDebug", "ButTtfViewActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskVtrDebug", "ButClaimOn") == "true");

	refreshTxf(contcontdoc, "TxfTfr", "", retrieveCi(srcdoc, "ContIacWzskVtrDebug", "TxfTfr"), TxfTfrActive, false, true);

	refreshTxt(contcontdoc, "TxtTst", retrieveCi(srcdoc, "ContInfWzskVtrDebug", "TxtTst"));

	refreshBut(contcontdoc, "ButTsr", ButTsrActive, false);
	refreshBut(contcontdoc, "ButTsp", ButTspActive, false);

	refreshTxt(contcontdoc, "TxtTtf", retrieveCi(srcdoc, "ContInfWzskVtrDebug", "TxtTtf"));

	refreshButicon(contcontdoc, "ButTtfView", "icon/view", ButTtfViewActive, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Debug", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Debug_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Debug_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Debug_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrDebug", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Debug_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskVtrDebugDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskVtrDebugDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskVtrDebug", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskVtrDebugData", scrJref, "ContIacWzskVtrDebug");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskVtrDebug", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskVtrDebugData", scrJref, "ContIacWzskVtrDebug");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskVtrDebugData", "ContIacWzskVtrDebug", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskVtrDebugData", "ContInfWzskVtrDebug", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskVtrDebugData", "StatShrWzskVtrDebug", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskVtrDebugData", "TagWzskVtrDebug", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskVtrDebugData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrDebug", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrDebug", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskVtrDebugData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Debug");
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

			} else if (blk.nodeName == "DpchEngWzskVtrDebugData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrDebug", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrDebug", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
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
