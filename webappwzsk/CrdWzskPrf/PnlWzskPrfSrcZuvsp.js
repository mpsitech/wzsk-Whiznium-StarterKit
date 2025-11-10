// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("SrcZuvsp", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("SrcZuvsp_side").setAttribute("height", "30");
	doc.getElementById("SrcZuvsp_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("SrcZuvsp_side").src = "./PnlWzskPrfSrcZuvsp_aside.html";
	doc.getElementById("SrcZuvsp_cont").src = "./PnlWzskPrfSrcZuvsp_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("SrcZuvsp_side").src = "./PnlWzskPrfSrcZuvsp_bside.html";
	doc.getElementById("SrcZuvsp_cont").src = "./PnlWzskPrfSrcZuvsp_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("SrcZuvsp_side").contentDocument;
	contdoc = doc.getElementById("SrcZuvsp_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfSrcZuvsp", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("SrcZuvsp_side").contentDocument;
	contdoc = doc.getElementById("SrcZuvsp_cont").contentDocument;
	hdrdoc = contdoc.getElementById("SrcZuvsp_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("SrcZuvsp_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfSrcZuvsp", "Cpt"));
	initCpt(contcontdoc, "Cpt1", retrieveTi(srcdoc, "TagWzskPrfSrcZuvsp", "Cpt1"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcZuvsp", "srefIxWzskVExpstate");

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

	var height = 35; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "Txf1", "", retrieveCi(srcdoc, "ContIacWzskPrfSrcZuvsp", "Txf1"), true, false, true);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("SrcZuvsp", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("SrcZuvsp_side").setAttribute("height", "" + (height+31));
	doc.getElementById("SrcZuvsp_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("SrcZuvsp_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcZuvsp", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("SrcZuvsp_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskPrfSrcZuvspDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskPrfSrcZuvsp", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfSrcZuvspData", scrJref, "ContIacWzskPrfSrcZuvsp");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskPrfSrcZuvsp", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfSrcZuvspData", scrJref, "ContIacWzskPrfSrcZuvsp");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcZuvspData", "ContIacWzskPrfSrcZuvsp", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcZuvspData", "StatShrWzskPrfSrcZuvsp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcZuvspData", "TagWzskPrfSrcZuvsp", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskPrfSrcZuvspData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcZuvsp", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcZuvsp", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskPrfSrcZuvspData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("SrcZuvsp");
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

			} else if (blk.nodeName == "DpchEngWzskPrfSrcZuvspData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcZuvsp", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcZuvsp", "srefIxWzskVExpstate");

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
