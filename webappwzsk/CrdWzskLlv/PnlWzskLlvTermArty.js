// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("TermArty", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("TermArty_side").setAttribute("height", "30");
	doc.getElementById("TermArty_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("TermArty_side").src = "./PnlWzskLlvTermArty_aside.html";
	doc.getElementById("TermArty_cont").src = "./PnlWzskLlvTermArty_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("TermArty_side").src = "./PnlWzskLlvTermArty_bside.html";
	doc.getElementById("TermArty_cont").src = "./PnlWzskLlvTermArty_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("TermArty_side").contentDocument;
	contdoc = doc.getElementById("TermArty_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermArty", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("TermArty_side").contentDocument;
	contdoc = doc.getElementById("TermArty_cont").contentDocument;
	hdrdoc = contdoc.getElementById("TermArty_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("TermArty_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermArty", "Cpt"));
	initCpt(contcontdoc, "CptCst", retrieveTi(srcdoc, "TagWzskLlvTermArty", "CptCst"));
	initCpt(contcontdoc, "HdgDio", retrieveTi(srcdoc, "TagWzskLlvTermArty", "HdgDio"));
	initCpt(contcontdoc, "HdgCex", retrieveTi(srcdoc, "TagWzskLlvTermArty", "HdgCex"));
	initCpt(contcontdoc, "CptCmd", retrieveTi(srcdoc, "TagWzskLlvTermArty", "CptCmd"));
	initBut(contcontdoc, "ButApd", retrieveTi(srcdoc, "TagWzskLlvTermArty", "ButApd"));
	initCpt(contcontdoc, "CptCsq", retrieveTi(srcdoc, "TagWzskLlvTermArty", "CptCsq"));
	initBut(contcontdoc, "ButSmt", retrieveTi(srcdoc, "TagWzskLlvTermArty", "ButSmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermArty", "srefIxWzskVExpstate");

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
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermArty", "ButClaimActive") == "true");

	var ButSmtActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermArty", "ButSmtActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- RBEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvTermArty", "ButClaimOn") == "true");
	refreshTxt(contcontdoc, "TxtCst", retrieveCi(srcdoc, "ContInfWzskLlvTermArty", "TxtCst"));

	refreshPup(contcontdoc, srcdoc, "PupCmd", "", "FeedFPupCmd", retrieveCi(srcdoc, "ContIacWzskLlvTermArty", "numFPupCmd"), true, false);

	//
	var myelem;

	myelem = contcontdoc.getElementById("TxtDat");
	refreshTxtt(contcontdoc, "TxtDat", retrieveCi(srcdoc, "ContInfWzskLlvTermArty", "TxtDatLog"));
	myelem.scrollTop = myelem.scrollHeight;
	//

	refreshTxft(contcontdoc, "TxfCsq", retrieveCi(srcdoc, "ContIacWzskLlvTermArty", "TxfCsq"), true, false, true);

	refreshBut(contcontdoc, "ButSmt", ButSmtActive, false);

	// IP refreshBD --- REND

	getCrdwnd().changeHeight("TermArty", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("TermArty_side").setAttribute("height", "" + (height+31));
	doc.getElementById("TermArty_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("TermArty_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermArty", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("TermArty_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvTermArtyDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskLlvTermArty", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermArtyData", scrJref, "ContIacWzskLlvTermArty");
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

	setCi(srcdoc, "ContIacWzskLlvTermArty", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermArtyData", scrJref, "ContIacWzskLlvTermArty");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLlvTermArtyData", "ContIacWzskLlvTermArty", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermArtyData", "ContInfWzskLlvTermArty", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermArtyData", "FeedFPupCmd", srcdoc)) mask.push("feedFPupCmd");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermArtyData", "StatShrWzskLlvTermArty", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermArtyData", "TagWzskLlvTermArty", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvTermArtyData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermArty", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermArty", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskLlvTermArtyData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("TermArty");
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

			} else if (blk.nodeName == "DpchEngWzskLlvTermArtyData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermArty", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermArty", "srefIxWzskVExpstate");

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
