// IP cust --- IBEGIN
function handleCusSchFceSet(angle) {
	setCi(srcdoc, "ContIacWzskLlvRotary", "TxfSchTrg", "" + angle);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvRotaryData", scrJref, "ContIacWzskLlvRotary");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function refreshSvgTxt(contdoc, id, tit) {
	var mytext;

	mytext = contdoc.getElementById(id);
	clearElem(mytext);
	mytext.appendChild(contdoc.createTextNode(tit));
};
// IP cust --- IEND

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Rotary", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Rotary_side").setAttribute("height", "30");
	doc.getElementById("Rotary_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Rotary_side").src = "./PnlWzskLlvRotary_aside.html";
	doc.getElementById("Rotary_cont").src = "./PnlWzskLlvRotary_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Rotary_side").src = "./PnlWzskLlvRotary_bside.html";
	doc.getElementById("Rotary_cont").src = "./PnlWzskLlvRotary_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rotary_side").contentDocument;
	contdoc = doc.getElementById("Rotary_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvRotary", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Rotary_side").contentDocument;
	contdoc = doc.getElementById("Rotary_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rotary_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Rotary_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvRotary", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

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

	var height = 160; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLlvRotary", "ButClaimActive") == "true");
	var CusSchActive = (retrieveSi(srcdoc, "StatShrWzskLlvRotary", "CusSchActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- RBEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvRotary", "ButClaimOn") == "true");

	var target = parseFloat(retrieveCi(srcdoc, "ContIacWzskLlvRotary", "TxfSchTrg")); if (isNaN(target)) target = 0.0;
	var angle = parseFloat(retrieveCi(srcdoc, "ContInfWzskLlvRotary", "TxtSchAng")); if (isNaN(angle)) angle = 0.0;

	for (i = -180; i < 180; i += 5) {
		var elem = contcontdoc.getElementById("CusSchFce" + ((i < 0) ? ("N" + (-i)) : ("" + i)));
		if (CusSchActive) {
			elem.setAttribute("class", "fceline");
			elem.setAttribute("onclick", "handleCusSchFceSet(" + i + ")");
		} else {
			elem.setAttribute("class", "fcelineinact");
			elem.setAttribute("onclick", "");
		};
	};

	contcontdoc.getElementById("CusSchBrd").setAttribute("transform", "rotate(" + (-90-angle) + ")");
	refreshSvgTxt(contcontdoc, "TxfSchTrg", "" + target.toFixed(1) + "\u00b0");
	refreshSvgTxt(contcontdoc, "TxtSchAng", "" + angle.toFixed(1) + "\u00b0");
	refreshCsi(contcontdoc, "CsiSchSte", srcdoc, "FeedFCsiSchSte", retrieveCi(srcdoc, "ContInfWzskLlvRotary", "numFCsiSchSte"));
	// IP refreshBD --- REND

	getCrdwnd().changeHeight("Rotary", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Rotary_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Rotary_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Rotary_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Rotary_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvRotaryDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskLlvRotary", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvRotaryData", scrJref, "ContIacWzskLlvRotary");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskLlvRotary", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvRotaryData", scrJref, "ContIacWzskLlvRotary");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "ContIacWzskLlvRotary", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "ContInfWzskLlvRotary", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "FeedFCsiSchSte", srcdoc)) mask.push("feedFCsiSchSte");
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "StatShrWzskLlvRotary", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "TagWzskLlvRotary", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvRotaryData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskLlvRotaryData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Rotary");
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

			} else if (blk.nodeName == "DpchEngWzskLlvRotaryData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

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
