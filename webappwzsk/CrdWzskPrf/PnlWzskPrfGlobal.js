// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Global", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Global_side").setAttribute("height", "30");
	doc.getElementById("Global_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Global_side").src = "./PnlWzskPrfGlobal_aside.html";
	doc.getElementById("Global_cont").src = "./PnlWzskPrfGlobal_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Global_side").src = "./PnlWzskPrfGlobal_bside.html";
	doc.getElementById("Global_cont").src = "./PnlWzskPrfGlobal_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Global_side").contentDocument;
	contdoc = doc.getElementById("Global_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Global_side").contentDocument;
	contdoc = doc.getElementById("Global_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Global_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Global_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Cpt"));
	initCpt(contcontdoc, "Hdg1", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Hdg1"));
	initCpt(contcontdoc, "Cpt2", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Cpt2"));
	initCpt(contcontdoc, "Cpt3", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Cpt3"));
	initCpt(contcontdoc, "Cpt4", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Cpt4"));
	initCpt(contcontdoc, "Cpt5", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Cpt5"));
	initCpt(contcontdoc, "Cpt6", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Cpt6"));
	initCpt(contcontdoc, "Hdg101", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Hdg101"));
	initCpt(contcontdoc, "Cpt102", retrieveTi(srcdoc, "TagWzskPrfGlobal", "Cpt102"));
	refreshPup(contcontdoc, srcdoc, "Pup102", "", "FeedFPup102", retrieveCi(srcdoc, "ContIacWzskPrfGlobal", "numFPup102"), true, false);
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfGlobal", "srefIxWzskVExpstate");

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

	var height = 217; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN

	refreshTxf(contcontdoc, "Txf2", "s", retrieveCi(srcdoc, "ContIacWzskPrfGlobal", "Txf2"), true, false, true);

	refreshTxf(contcontdoc, "Txf3", "s", retrieveCi(srcdoc, "ContIacWzskPrfGlobal", "Txf3"), true, false, true);

	refreshTxf(contcontdoc, "Txf4", "s", retrieveCi(srcdoc, "ContIacWzskPrfGlobal", "Txf4"), true, false, true);

	refreshTxf(contcontdoc, "Txf5", "s", retrieveCi(srcdoc, "ContIacWzskPrfGlobal", "Txf5"), true, false, true);

	refreshTxf(contcontdoc, "Txf6", "s", retrieveCi(srcdoc, "ContIacWzskPrfGlobal", "Txf6"), true, false, true);

	contcontdoc.getElementById("Pup102").value = retrieveCi(srcdoc, "ContIacWzskPrfGlobal", "numFPup102");

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Global", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Global_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Global_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Global_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfGlobal", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Global_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskPrfGlobalDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskPrfGlobal", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfGlobalData", scrJref, "ContIacWzskPrfGlobal");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskPrfGlobal", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfGlobalData", scrJref, "ContIacWzskPrfGlobal");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskPrfGlobal", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfGlobalData", scrJref, "ContIacWzskPrfGlobal");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskPrfGlobalData", "ContIacWzskPrfGlobal", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskPrfGlobalData", "FeedFPup102", srcdoc)) mask.push("feedFPup102");
	if (updateSrcblock(dom, "DpchEngWzskPrfGlobalData", "StatShrWzskPrfGlobal", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskPrfGlobalData", "TagWzskPrfGlobal", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskPrfGlobalData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfGlobal", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfGlobal", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskPrfGlobalData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Global");
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

			} else if (blk.nodeName == "DpchEngWzskPrfGlobalData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfGlobal", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfGlobal", "srefIxWzskVExpstate");

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
