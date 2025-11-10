// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("TermTivsp", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("TermTivsp_side").setAttribute("height", "30");
	doc.getElementById("TermTivsp_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("TermTivsp_side").src = "./PnlWzskLlvTermTivsp_aside.html";
	doc.getElementById("TermTivsp_cont").src = "./PnlWzskLlvTermTivsp_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("TermTivsp_side").src = "./PnlWzskLlvTermTivsp_bside.html";
	doc.getElementById("TermTivsp_cont").src = "./PnlWzskLlvTermTivsp_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("TermTivsp_side").contentDocument;
	contdoc = doc.getElementById("TermTivsp_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("TermTivsp_side").contentDocument;
	contdoc = doc.getElementById("TermTivsp_cont").contentDocument;
	hdrdoc = contdoc.getElementById("TermTivsp_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("TermTivsp_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "Cpt"));
	initCpt(contcontdoc, "CptCst", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "CptCst"));
	initCpt(contcontdoc, "HdgDio", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "HdgDio"));
	initCpt(contcontdoc, "HdgCex", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "HdgCex"));
	initCpt(contcontdoc, "CptCmd", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "CptCmd"));
	initBut(contcontdoc, "ButApd", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "ButApd"));
	initCpt(contcontdoc, "CptCsq", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "CptCsq"));
	initBut(contcontdoc, "ButSmt", retrieveTi(srcdoc, "TagWzskLlvTermTivsp", "ButSmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermTivsp", "srefIxWzskVExpstate");

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

	var height = 424; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermTivsp", "ButClaimActive") == "true");

	var ButSmtActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermTivsp", "ButSmtActive") == "true");

	// IP refreshBD.vars --- END

// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvTermTivsp", "ButClaimOn") == "true");
	refreshTxt(contcontdoc, "TxtCst", retrieveCi(srcdoc, "ContInfWzskLlvTermTivsp", "TxtCst"));

	refreshPup(contcontdoc, srcdoc, "PupCmd", "", "FeedFPupCmd", retrieveCi(srcdoc, "ContIacWzskLlvTermTivsp", "numFPupCmd"), true, false);

	var myelem;

	myelem = contcontdoc.getElementById("TxtDat");
	refreshTxtt(contcontdoc, "TxtDat", retrieveCi(srcdoc, "ContInfWzskLlvTermTivsp", "TxtDatLog"));
	myelem.scrollTop = myelem.scrollHeight;

	refreshTxft(contcontdoc, "TxfCsq", retrieveCi(srcdoc, "ContIacWzskLlvTermTivsp", "TxfCsq"), true, false, true);

	refreshBut(contcontdoc, "ButSmt", ButSmtActive, false);
// IP refreshBD --- END

	getCrdwnd().changeHeight("TermTivsp", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("TermTivsp_side").setAttribute("height", "" + (height+31));
	doc.getElementById("TermTivsp_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("TermTivsp_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermTivsp", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("TermTivsp_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvTermTivspDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskLlvTermTivsp", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermTivspData", scrJref, "ContIacWzskLlvTermTivsp");
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

	setCi(srcdoc, "ContIacWzskLlvTermTivsp", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermTivspData", scrJref, "ContIacWzskLlvTermTivsp");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskLlvTermTivspData", "ContIacWzskLlvTermTivsp", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermTivspData", "ContInfWzskLlvTermTivsp", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermTivspData", "FeedFPupCmd", srcdoc)) mask.push("feedFPupCmd");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermTivspData", "StatShrWzskLlvTermTivsp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermTivspData", "TagWzskLlvTermTivsp", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvTermTivspData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermTivsp", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermTivsp", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskLlvTermTivspData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("TermTivsp");
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

			} else if (blk.nodeName == "DpchEngWzskLlvTermTivspData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermTivsp", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermTivsp", "srefIxWzskVExpstate");

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
