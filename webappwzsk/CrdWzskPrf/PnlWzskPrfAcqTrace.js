// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("AcqTrace", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("AcqTrace_side").setAttribute("height", "30");
	doc.getElementById("AcqTrace_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("AcqTrace_side").src = "./PnlWzskPrfAcqTrace_aside.html";
	doc.getElementById("AcqTrace_cont").src = "./PnlWzskPrfAcqTrace_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("AcqTrace_side").src = "./PnlWzskPrfAcqTrace_bside.html";
	doc.getElementById("AcqTrace_cont").src = "./PnlWzskPrfAcqTrace_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("AcqTrace_side").contentDocument;
	contdoc = doc.getElementById("AcqTrace_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfAcqTrace", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("AcqTrace_side").contentDocument;
	contdoc = doc.getElementById("AcqTrace_cont").contentDocument;
	hdrdoc = contdoc.getElementById("AcqTrace_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("AcqTrace_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfAcqTrace", "Cpt"));
	initCpt(contcontdoc, "Cpt1", retrieveTi(srcdoc, "TagWzskPrfAcqTrace", "Cpt1"));
	initCpt(contcontdoc, "Cpt2", retrieveTi(srcdoc, "TagWzskPrfAcqTrace", "Cpt2"));
	initCpt(contcontdoc, "Cpt3", retrieveTi(srcdoc, "TagWzskPrfAcqTrace", "Cpt3"));
	initCpt(contcontdoc, "Cpt4", retrieveTi(srcdoc, "TagWzskPrfAcqTrace", "Cpt4"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfAcqTrace", "srefIxWzskVExpstate");

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

	var height = 110; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "Txf1", "s", retrieveCi(srcdoc, "ContIacWzskPrfAcqTrace", "Txf1"), true, false, true);

	refreshTxf(contcontdoc, "Txf2", "s", retrieveCi(srcdoc, "ContIacWzskPrfAcqTrace", "Txf2"), true, false, true);

	refreshTxf(contcontdoc, "Txf3", "s", retrieveCi(srcdoc, "ContIacWzskPrfAcqTrace", "Txf3"), true, false, true);

	refreshTxf(contcontdoc, "Txf4", "s", retrieveCi(srcdoc, "ContIacWzskPrfAcqTrace", "Txf4"), true, false, true);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("AcqTrace", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("AcqTrace_side").setAttribute("height", "" + (height+31));
	doc.getElementById("AcqTrace_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("AcqTrace_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfAcqTrace", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("AcqTrace_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskPrfAcqTraceDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskPrfAcqTrace", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfAcqTraceData", scrJref, "ContIacWzskPrfAcqTrace");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskPrfAcqTrace", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfAcqTraceData", scrJref, "ContIacWzskPrfAcqTrace");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskPrfAcqTraceData", "ContIacWzskPrfAcqTrace", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskPrfAcqTraceData", "StatShrWzskPrfAcqTrace", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskPrfAcqTraceData", "TagWzskPrfAcqTrace", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskPrfAcqTraceData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfAcqTrace", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfAcqTrace", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskPrfAcqTraceData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("AcqTrace");
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

			} else if (blk.nodeName == "DpchEngWzskPrfAcqTraceData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfAcqTrace", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfAcqTrace", "srefIxWzskVExpstate");

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
