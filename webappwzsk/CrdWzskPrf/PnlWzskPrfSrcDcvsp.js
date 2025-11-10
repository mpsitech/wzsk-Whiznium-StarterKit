// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("SrcDcvsp", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("SrcDcvsp_side").setAttribute("height", "30");
	doc.getElementById("SrcDcvsp_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("SrcDcvsp_side").src = "./PnlWzskPrfSrcDcvsp_aside.html";
	doc.getElementById("SrcDcvsp_cont").src = "./PnlWzskPrfSrcDcvsp_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("SrcDcvsp_side").src = "./PnlWzskPrfSrcDcvsp_bside.html";
	doc.getElementById("SrcDcvsp_cont").src = "./PnlWzskPrfSrcDcvsp_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("SrcDcvsp_side").contentDocument;
	contdoc = doc.getElementById("SrcDcvsp_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfSrcDcvsp", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("SrcDcvsp_side").contentDocument;
	contdoc = doc.getElementById("SrcDcvsp_cont").contentDocument;
	hdrdoc = contdoc.getElementById("SrcDcvsp_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("SrcDcvsp_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfSrcDcvsp", "Cpt"));
	initCpt(contcontdoc, "Cpt1", retrieveTi(srcdoc, "TagWzskPrfSrcDcvsp", "Cpt1"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcDcvsp", "srefIxWzskVExpstate");

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
	refreshTxf(contcontdoc, "Txf1", "", retrieveCi(srcdoc, "ContIacWzskPrfSrcDcvsp", "Txf1"), true, false, true);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("SrcDcvsp", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("SrcDcvsp_side").setAttribute("height", "" + (height+31));
	doc.getElementById("SrcDcvsp_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("SrcDcvsp_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcDcvsp", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("SrcDcvsp_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskPrfSrcDcvspDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskPrfSrcDcvsp", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfSrcDcvspData", scrJref, "ContIacWzskPrfSrcDcvsp");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskPrfSrcDcvsp", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfSrcDcvspData", scrJref, "ContIacWzskPrfSrcDcvsp");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcDcvspData", "ContIacWzskPrfSrcDcvsp", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcDcvspData", "StatShrWzskPrfSrcDcvsp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskPrfSrcDcvspData", "TagWzskPrfSrcDcvsp", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskPrfSrcDcvspData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcDcvsp", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcDcvsp", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskPrfSrcDcvspData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("SrcDcvsp");
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

			} else if (blk.nodeName == "DpchEngWzskPrfSrcDcvspData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcDcvsp", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfSrcDcvsp", "srefIxWzskVExpstate");

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
