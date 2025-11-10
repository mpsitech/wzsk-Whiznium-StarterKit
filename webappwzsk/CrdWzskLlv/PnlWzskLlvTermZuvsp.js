// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("TermZuvsp", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("TermZuvsp_side").setAttribute("height", "30");
	doc.getElementById("TermZuvsp_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("TermZuvsp_side").src = "./PnlWzskLlvTermZuvsp_aside.html";
	doc.getElementById("TermZuvsp_cont").src = "./PnlWzskLlvTermZuvsp_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("TermZuvsp_side").src = "./PnlWzskLlvTermZuvsp_bside.html";
	doc.getElementById("TermZuvsp_cont").src = "./PnlWzskLlvTermZuvsp_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("TermZuvsp_side").contentDocument;
	contdoc = doc.getElementById("TermZuvsp_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("TermZuvsp_side").contentDocument;
	contdoc = doc.getElementById("TermZuvsp_cont").contentDocument;
	hdrdoc = contdoc.getElementById("TermZuvsp_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("TermZuvsp_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "Cpt"));
	initCpt(contcontdoc, "CptCst", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "CptCst"));
	initCpt(contcontdoc, "HdgDio", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "HdgDio"));
	initCpt(contcontdoc, "HdgCex", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "HdgCex"));
	initCpt(contcontdoc, "CptCmd", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "CptCmd"));
	initBut(contcontdoc, "ButApd", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "ButApd"));
	initCpt(contcontdoc, "CptCsq", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "CptCsq"));
	initBut(contcontdoc, "ButSmt", retrieveTi(srcdoc, "TagWzskLlvTermZuvsp", "ButSmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermZuvsp", "srefIxWzskVExpstate");

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
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermZuvsp", "ButClaimActive") == "true");

	var ButSmtActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermZuvsp", "ButSmtActive") == "true");

	// IP refreshBD.vars --- END

// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvTermZuvsp", "ButClaimOn") == "true");
	refreshTxt(contcontdoc, "TxtCst", retrieveCi(srcdoc, "ContInfWzskLlvTermZuvsp", "TxtCst"));

	refreshPup(contcontdoc, srcdoc, "PupCmd", "", "FeedFPupCmd", retrieveCi(srcdoc, "ContIacWzskLlvTermZuvsp", "numFPupCmd"), true, false);

	var myelem;

	myelem = contcontdoc.getElementById("TxtDat");
	refreshTxtt(contcontdoc, "TxtDat", retrieveCi(srcdoc, "ContInfWzskLlvTermZuvsp", "TxtDatLog"));
	myelem.scrollTop = myelem.scrollHeight;

	refreshTxft(contcontdoc, "TxfCsq", retrieveCi(srcdoc, "ContIacWzskLlvTermZuvsp", "TxfCsq"), true, false, true);

	refreshBut(contcontdoc, "ButSmt", ButSmtActive, false);
// IP refreshBD --- END

	getCrdwnd().changeHeight("TermZuvsp", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("TermZuvsp_side").setAttribute("height", "" + (height+31));
	doc.getElementById("TermZuvsp_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("TermZuvsp_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermZuvsp", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("TermZuvsp_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvTermZuvspDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskLlvTermZuvsp", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermZuvspData", scrJref, "ContIacWzskLlvTermZuvsp");
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

	setCi(srcdoc, "ContIacWzskLlvTermZuvsp", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermZuvspData", scrJref, "ContIacWzskLlvTermZuvsp");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskLlvTermZuvspData", "ContIacWzskLlvTermZuvsp", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermZuvspData", "ContInfWzskLlvTermZuvsp", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermZuvspData", "FeedFPupCmd", srcdoc)) mask.push("feedFPupCmd");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermZuvspData", "StatShrWzskLlvTermZuvsp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermZuvspData", "TagWzskLlvTermZuvsp", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvTermZuvspData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermZuvsp", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermZuvsp", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskLlvTermZuvspData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("TermZuvsp");
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

			} else if (blk.nodeName == "DpchEngWzskLlvTermZuvspData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermZuvsp", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermZuvsp", "srefIxWzskVExpstate");

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
