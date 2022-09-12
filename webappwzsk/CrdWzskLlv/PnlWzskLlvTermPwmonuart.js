// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("TermPwmonuart", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("TermPwmonuart_side").setAttribute("height", "30");
	doc.getElementById("TermPwmonuart_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("TermPwmonuart_side").src = "./PnlWzskLlvTermPwmonuart_aside.html";
	doc.getElementById("TermPwmonuart_cont").src = "./PnlWzskLlvTermPwmonuart_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("TermPwmonuart_side").src = "./PnlWzskLlvTermPwmonuart_bside.html";
	doc.getElementById("TermPwmonuart_cont").src = "./PnlWzskLlvTermPwmonuart_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("TermPwmonuart_side").contentDocument;
	contdoc = doc.getElementById("TermPwmonuart_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("TermPwmonuart_side").contentDocument;
	contdoc = doc.getElementById("TermPwmonuart_cont").contentDocument;
	hdrdoc = contdoc.getElementById("TermPwmonuart_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("TermPwmonuart_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "Cpt"));
	initCpt(contcontdoc, "CptCst", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "CptCst"));
	initCpt(contcontdoc, "HdgDio", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "HdgDio"));
	initCpt(contcontdoc, "HdgCex", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "HdgCex"));
	initCpt(contcontdoc, "CptCmd", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "CptCmd"));
	initBut(contcontdoc, "ButApd", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "ButApd"));
	initCpt(contcontdoc, "CptCsq", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "CptCsq"));
	initBut(contcontdoc, "ButSmt", retrieveTi(srcdoc, "TagWzskLlvTermPwmonuart", "ButSmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonuart", "srefIxWzskVExpstate");

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
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonuart", "ButClaimActive") == "true");

	var ButSmtActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonuart", "ButSmtActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- RBEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvTermPwmonuart", "ButClaimOn") == "true");
	refreshTxt(contcontdoc, "TxtCst", retrieveCi(srcdoc, "ContInfWzskLlvTermPwmonuart", "TxtCst"));

	refreshPup(contcontdoc, srcdoc, "PupCmd", "", "FeedFPupCmd", retrieveCi(srcdoc, "ContIacWzskLlvTermPwmonuart", "numFPupCmd"), true, false);

	//
	var myelem;

	myelem = contcontdoc.getElementById("TxtDat");
	refreshTxtt(contcontdoc, "TxtDat", retrieveCi(srcdoc, "ContInfWzskLlvTermPwmonuart", "TxtDatLog"));
	myelem.scrollTop = myelem.scrollHeight;
	//

	refreshTxft(contcontdoc, "TxfCsq", retrieveCi(srcdoc, "ContIacWzskLlvTermPwmonuart", "TxfCsq"), true, false, true);

	refreshBut(contcontdoc, "ButSmt", ButSmtActive, false);

	// IP refreshBD --- REND

	getCrdwnd().changeHeight("TermPwmonuart", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("TermPwmonuart_side").setAttribute("height", "" + (height+31));
	doc.getElementById("TermPwmonuart_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("TermPwmonuart_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonuart", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("TermPwmonuart_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvTermPwmonuartDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskLlvTermPwmonuart", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermPwmonuartData", scrJref, "ContIacWzskLlvTermPwmonuart");
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

	setCi(srcdoc, "ContIacWzskLlvTermPwmonuart", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermPwmonuartData", scrJref, "ContIacWzskLlvTermPwmonuart");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonuartData", "ContIacWzskLlvTermPwmonuart", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonuartData", "ContInfWzskLlvTermPwmonuart", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonuartData", "FeedFPupCmd", srcdoc)) mask.push("feedFPupCmd");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonuartData", "StatShrWzskLlvTermPwmonuart", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonuartData", "TagWzskLlvTermPwmonuart", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvTermPwmonuartData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonuart", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonuart", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskLlvTermPwmonuartData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("TermPwmonuart");
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

			} else if (blk.nodeName == "DpchEngWzskLlvTermPwmonuartData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonuart", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonuart", "srefIxWzskVExpstate");

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
