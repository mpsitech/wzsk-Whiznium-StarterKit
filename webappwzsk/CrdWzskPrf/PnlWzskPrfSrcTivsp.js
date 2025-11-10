// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("SrcTivsp", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("SrcTivsp_side").setAttribute("height", "30");
	doc.getElementById("SrcTivsp_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("SrcTivsp_side").src = "./PnlWzskPrfSrcTivsp_aside.html";
	doc.getElementById("SrcTivsp_cont").src = "./PnlWzskPrfSrcTivsp_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("SrcTivsp_side").src = "./PnlWzskPrfSrcTivsp_bside.html";
	doc.getElementById("SrcTivsp_cont").src = "./PnlWzskPrfSrcTivsp_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("SrcTivsp_side").contentDocument;
	contdoc = doc.getElementById("SrcTivsp_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfSrcTivsp", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("SrcTivsp_side").contentDocument;
	contdoc = doc.getElementById("SrcTivsp_cont").contentDocument;
	hdrdoc = contdoc.getElementById("SrcTivsp_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("SrcTivsp_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfSrcTivsp", "Cpt"));
	initCpt(contcontdoc, "Cpt1", retrieveTi(srcdoc, "TagWzskPrfSrcTivsp", "Cpt1"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcTivsp", "srefIxWzskVExpstate");

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
	refreshTxf(contcontdoc, "Txf1", "", retrieveCi(srcdoc, "ContIacWzskPrfSrcTivsp", "Txf1"), true, false, true);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("SrcTivsp", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("SrcTivsp_side").setAttribute("height", "" + (height+31));
	doc.getElementById("SrcTivsp_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("SrcTivsp_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcTivsp", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("SrcTivsp_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskPrfSrcTivspDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskPrfSrcTivsp", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfSrcTivspData", scrJref, "ContIacWzskPrfSrcTivsp");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskPrfSrcTivsp", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfSrcTivspData", scrJref, "ContIacWzskPrfSrcTivsp");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcTivspData", "ContIacWzskPrfSrcTivsp", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcTivspData", "StatShrWzskPrfSrcTivsp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcTivspData", "TagWzskPrfSrcTivsp", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskPrfSrcTivspData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcTivsp", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcTivsp", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskPrfSrcTivspData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("SrcTivsp");
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

			} else if (blk.nodeName == "DpchEngWzskPrfSrcTivspData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcTivsp", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcTivsp", "srefIxWzskVExpstate");

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
