// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("ActLaser", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("ActLaser_side").setAttribute("height", "30");
	doc.getElementById("ActLaser_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("ActLaser_side").src = "./PnlWzskPrfActLaser_aside.html";
	doc.getElementById("ActLaser_cont").src = "./PnlWzskPrfActLaser_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("ActLaser_side").src = "./PnlWzskPrfActLaser_bside.html";
	doc.getElementById("ActLaser_cont").src = "./PnlWzskPrfActLaser_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("ActLaser_side").contentDocument;
	contdoc = doc.getElementById("ActLaser_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfActLaser", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("ActLaser_side").contentDocument;
	contdoc = doc.getElementById("ActLaser_cont").contentDocument;
	hdrdoc = contdoc.getElementById("ActLaser_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("ActLaser_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfActLaser", "Cpt"));
	initCpt(contcontdoc, "Cpt1", retrieveTi(srcdoc, "TagWzskPrfActLaser", "Cpt1"));
	initCpt(contcontdoc, "Cpt2", retrieveTi(srcdoc, "TagWzskPrfActLaser", "Cpt2"));
	initCpt(contcontdoc, "Cpt3", retrieveTi(srcdoc, "TagWzskPrfActLaser", "Cpt3"));
	initCpt(contcontdoc, "Cpt4", retrieveTi(srcdoc, "TagWzskPrfActLaser", "Cpt4"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfActLaser", "srefIxWzskVExpstate");

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
	refreshTxf(contcontdoc, "Txf1", "s", retrieveCi(srcdoc, "ContIacWzskPrfActLaser", "Txf1"), true, false, true);

	refreshTxf(contcontdoc, "Txf2", "s", retrieveCi(srcdoc, "ContIacWzskPrfActLaser", "Txf2"), true, false, true);

	refreshTxf(contcontdoc, "Txf3", "s", retrieveCi(srcdoc, "ContIacWzskPrfActLaser", "Txf3"), true, false, true);

	refreshTxf(contcontdoc, "Txf4", "s", retrieveCi(srcdoc, "ContIacWzskPrfActLaser", "Txf4"), true, false, true);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("ActLaser", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("ActLaser_side").setAttribute("height", "" + (height+31));
	doc.getElementById("ActLaser_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("ActLaser_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfActLaser", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("ActLaser_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskPrfActLaserDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskPrfActLaser", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfActLaserData", scrJref, "ContIacWzskPrfActLaser");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskPrfActLaser", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfActLaserData", scrJref, "ContIacWzskPrfActLaser");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskPrfActLaserData", "ContIacWzskPrfActLaser", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskPrfActLaserData", "StatShrWzskPrfActLaser", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskPrfActLaserData", "TagWzskPrfActLaser", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskPrfActLaserData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfActLaser", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfActLaser", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskPrfActLaserData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("ActLaser");
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

			} else if (blk.nodeName == "DpchEngWzskPrfActLaserData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfActLaser", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfActLaser", "srefIxWzskVExpstate");

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
