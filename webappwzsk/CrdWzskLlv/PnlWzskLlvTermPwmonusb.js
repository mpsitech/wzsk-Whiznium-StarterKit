// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("TermPwmonusb", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("TermPwmonusb_side").setAttribute("height", "30");
	doc.getElementById("TermPwmonusb_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("TermPwmonusb_side").src = "./PnlWzskLlvTermPwmonusb_aside.html";
	doc.getElementById("TermPwmonusb_cont").src = "./PnlWzskLlvTermPwmonusb_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("TermPwmonusb_side").src = "./PnlWzskLlvTermPwmonusb_bside.html";
	doc.getElementById("TermPwmonusb_cont").src = "./PnlWzskLlvTermPwmonusb_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("TermPwmonusb_side").contentDocument;
	contdoc = doc.getElementById("TermPwmonusb_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("TermPwmonusb_side").contentDocument;
	contdoc = doc.getElementById("TermPwmonusb_cont").contentDocument;
	hdrdoc = contdoc.getElementById("TermPwmonusb_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("TermPwmonusb_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "Cpt"));
	initCpt(contcontdoc, "CptCst", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "CptCst"));
	initCpt(contcontdoc, "HdgDio", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "HdgDio"));
	initCpt(contcontdoc, "HdgCex", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "HdgCex"));
	initCpt(contcontdoc, "CptCmd", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "CptCmd"));
	initBut(contcontdoc, "ButApd", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "ButApd"));
	initCpt(contcontdoc, "CptCsq", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "CptCsq"));
	initBut(contcontdoc, "ButSmt", retrieveTi(srcdoc, "TagWzskLlvTermPwmonusb", "ButSmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonusb", "srefIxWzskVExpstate");

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
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonusb", "ButClaimActive") == "true");

	var ButSmtActive = (retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonusb", "ButSmtActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- RBEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvTermPwmonusb", "ButClaimOn") == "true");
	refreshTxt(contcontdoc, "TxtCst", retrieveCi(srcdoc, "ContInfWzskLlvTermPwmonusb", "TxtCst"));

	refreshPup(contcontdoc, srcdoc, "PupCmd", "", "FeedFPupCmd", retrieveCi(srcdoc, "ContIacWzskLlvTermPwmonusb", "numFPupCmd"), true, false);

	//
	var myelem;

	myelem = contcontdoc.getElementById("TxtDat");
	refreshTxtt(contcontdoc, "TxtDat", retrieveCi(srcdoc, "ContInfWzskLlvTermPwmonusb", "TxtDatLog"));
	myelem.scrollTop = myelem.scrollHeight;
	//
	
	refreshTxft(contcontdoc, "TxfCsq", retrieveCi(srcdoc, "ContIacWzskLlvTermPwmonusb", "TxfCsq"), true, false, true);

	refreshBut(contcontdoc, "ButSmt", ButSmtActive, false);

	// IP refreshBD --- REND

	getCrdwnd().changeHeight("TermPwmonusb", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("TermPwmonusb_side").setAttribute("height", "" + (height+31));
	doc.getElementById("TermPwmonusb_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("TermPwmonusb_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonusb", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("TermPwmonusb_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvTermPwmonusbDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskLlvTermPwmonusb", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermPwmonusbData", scrJref, "ContIacWzskLlvTermPwmonusb");
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

	setCi(srcdoc, "ContIacWzskLlvTermPwmonusb", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvTermPwmonusbData", scrJref, "ContIacWzskLlvTermPwmonusb");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonusbData", "ContIacWzskLlvTermPwmonusb", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonusbData", "ContInfWzskLlvTermPwmonusb", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonusbData", "FeedFPupCmd", srcdoc)) mask.push("feedFPupCmd");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonusbData", "StatShrWzskLlvTermPwmonusb", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvTermPwmonusbData", "TagWzskLlvTermPwmonusb", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvTermPwmonusbData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonusb", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonusb", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskLlvTermPwmonusbData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("TermPwmonusb");
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

			} else if (blk.nodeName == "DpchEngWzskLlvTermPwmonusbData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonusb", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvTermPwmonusb", "srefIxWzskVExpstate");

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
