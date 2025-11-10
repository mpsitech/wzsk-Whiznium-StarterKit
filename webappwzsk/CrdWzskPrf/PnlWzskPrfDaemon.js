// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Daemon", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Daemon_side").setAttribute("height", "30");
	doc.getElementById("Daemon_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Daemon_side").src = "./PnlWzskPrfDaemon_aside.html";
	doc.getElementById("Daemon_cont").src = "./PnlWzskPrfDaemon_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Daemon_side").src = "./PnlWzskPrfDaemon_bside.html";
	doc.getElementById("Daemon_cont").src = "./PnlWzskPrfDaemon_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Daemon_side").contentDocument;
	contdoc = doc.getElementById("Daemon_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Daemon_side").contentDocument;
	contdoc = doc.getElementById("Daemon_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Daemon_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Daemon_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt"));
	initCpt(contcontdoc, "Hdg1", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Hdg1"));
	initCpt(contcontdoc, "Cpt2", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt2"));
	initCpt(contcontdoc, "Cpt3", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt3"));
	initCpt(contcontdoc, "Cpt4", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt4"));
	initCpt(contcontdoc, "Cpt5", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt5"));
	initCpt(contcontdoc, "Cpt6", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt6"));
	initCpt(contcontdoc, "Hdg101", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Hdg101"));
	initCpt(contcontdoc, "Cpt102", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt102"));
	initCpt(contcontdoc, "Cpt103", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt103"));
	initCpt(contcontdoc, "Cpt104", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt104"));
	initCpt(contcontdoc, "Hdg201", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Hdg201"));
	initCpt(contcontdoc, "Cpt202", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt202"));
	initCpt(contcontdoc, "Cpt203", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt203"));
	initCpt(contcontdoc, "Cpt204", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt204"));
	initCpt(contcontdoc, "Cpt205", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt205"));
	initCpt(contcontdoc, "Cpt206", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt206"));
	initCpt(contcontdoc, "Hdg301", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Hdg301"));
	initCpt(contcontdoc, "Cpt302", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt302"));
	initCpt(contcontdoc, "Cpt303", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt303"));
	initCpt(contcontdoc, "Cpt304", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt304"));
	initCpt(contcontdoc, "Cpt305", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt305"));
	initCpt(contcontdoc, "Cpt306", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt306"));
	initCpt(contcontdoc, "Cpt307", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt307"));
	initCpt(contcontdoc, "Cpt308", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt308"));
	initCpt(contcontdoc, "Hdg401", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Hdg401"));
	initCpt(contcontdoc, "Cpt402", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt402"));
	initCpt(contcontdoc, "Cpt403", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt403"));
	initCpt(contcontdoc, "Cpt404", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt404"));
	initCpt(contcontdoc, "Cpt405", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt405"));
	initCpt(contcontdoc, "Cpt406", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt406"));
	initCpt(contcontdoc, "Cpt407", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt407"));
	initCpt(contcontdoc, "Hdg501", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Hdg501"));
	initCpt(contcontdoc, "Cpt502", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt502"));
	initCpt(contcontdoc, "Cpt503", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt503"));
	initCpt(contcontdoc, "Hdg601", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Hdg601"));
	initCpt(contcontdoc, "Cpt602", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt602"));
	initCpt(contcontdoc, "Cpt603", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt603"));
	initCpt(contcontdoc, "Cpt604", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt604"));
	initCpt(contcontdoc, "Cpt605", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt605"));
	initCpt(contcontdoc, "Cpt606", retrieveTi(srcdoc, "TagWzskPrfDaemon", "Cpt606"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "srefIxWzskVExpstate");

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

	var height = 1052; // full cont height

	// IP refreshBD.vars --- BEGIN

	var Sep2Avail = (retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "Sep2Avail") == "true");

	var Hdg201Avail = (retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "Hdg201Avail") == "true");

	var Txf202Avail = (retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "Txf202Avail") == "true");

	var Txf203Avail = (retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "Txf203Avail") == "true");

	var Chk204Avail = (retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "Chk204Avail") == "true");

	var Chk205Avail = (retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "Chk205Avail") == "true");

	var Chk206Avail = (retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "Chk206Avail") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN

	refreshTxf(contcontdoc, "Txf2", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf2"), true, false, true);

	refreshChk(contcontdoc, "Chk3", (retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Chk3") == "true"), true);

	refreshTxf(contcontdoc, "Txf4", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf4"), true, false, true);

	refreshTxf(contcontdoc, "Txf5", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf5"), true, false, true);

	refreshTxf(contcontdoc, "Txf6", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf6"), true, false, true);

	refreshTxf(contcontdoc, "Txf102", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf102"), true, false, true);

	refreshChk(contcontdoc, "Chk103", (retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Chk103") == "true"), true);

	refreshTxf(contcontdoc, "Txf104", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf104"), true, false, true);

	height -= setCtlAvail(contcontdoc, "21", Sep2Avail, 0);
	setCtlAvail(contcontdoc, "22", Sep2Avail, 7);
	setCtlAvail(contcontdoc, "23", Sep2Avail, 0);
	if (Sep2Avail) {

	};

	height -= setCtlAvail(contcontdoc, "201", Hdg201Avail, 25);
	if (Hdg201Avail) {

	};

	height -= setCtlAvail(contcontdoc, "202", Txf202Avail, 25);
	if (Txf202Avail) {
		refreshTxf(contcontdoc, "Txf202", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf202"), true, false, true);

	};

	height -= setCtlAvail(contcontdoc, "203", Txf203Avail, 25);
	if (Txf203Avail) {
		refreshTxf(contcontdoc, "Txf203", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf203"), true, false, true);

	};

	height -= setCtlAvail(contcontdoc, "204", Chk204Avail, 25);
	if (Chk204Avail) {
		refreshChk(contcontdoc, "Chk204", (retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Chk204") == "true"), true);

	};

	height -= setCtlAvail(contcontdoc, "205", Chk205Avail, 25);
	if (Chk205Avail) {
		refreshChk(contcontdoc, "Chk205", (retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Chk205") == "true"), true);

	};

	height -= setCtlAvail(contcontdoc, "206", Chk206Avail, 25);
	if (Chk206Avail) {
		refreshChk(contcontdoc, "Chk206", (retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Chk206") == "true"), true);

	};

	refreshPup(contcontdoc, srcdoc, "Pup302", "", "FeedFPup302", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "numFPup302"), true, false);

	refreshTxf(contcontdoc, "Txf303", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf303"), true, false, true);

	refreshTxf(contcontdoc, "Txf304", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf304"), true, false, true);

	refreshTxf(contcontdoc, "Txf305", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf305"), true, false, true);

	refreshTxf(contcontdoc, "Txf306", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf306"), true, false, true);

	refreshTxf(contcontdoc, "Txf307", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf307"), true, false, true);

	refreshTxf(contcontdoc, "Txf308", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf308"), true, false, true);

	refreshTxf(contcontdoc, "Txf402", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf402"), true, false, true);

	refreshTxf(contcontdoc, "Txf403", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf403"), true, false, true);

	refreshTxf(contcontdoc, "Txf404", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf404"), true, false, true);

	refreshTxf(contcontdoc, "Txf405", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf405"), true, false, true);

	refreshTxf(contcontdoc, "Txf406", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf406"), true, false, true);

	refreshTxf(contcontdoc, "Txf407", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf407"), true, false, true);

	refreshTxf(contcontdoc, "Txf502", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf502"), true, false, true);

	refreshTxf(contcontdoc, "Txf503", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf503"), true, false, true);

	refreshTxf(contcontdoc, "Txf602", "", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf602"), true, false, true);

	refreshTxf(contcontdoc, "Txf603", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf603"), true, false, true);

	refreshTxf(contcontdoc, "Txf604", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf604"), true, false, true);

	refreshTxf(contcontdoc, "Txf605", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf605"), true, false, true);

	refreshTxf(contcontdoc, "Txf606", "s", retrieveCi(srcdoc, "ContIacWzskPrfDaemon", "Txf606"), true, false, true);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Daemon", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Daemon_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Daemon_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Daemon_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Daemon_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskPrfDaemonDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWzskPrfDaemon", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfDaemonData", scrJref, "ContIacWzskPrfDaemon");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskPrfDaemon", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfDaemonData", scrJref, "ContIacWzskPrfDaemon");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzskPrfDaemon", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfDaemonData", scrJref, "ContIacWzskPrfDaemon");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzskPrfDaemon", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskPrfDaemonData", scrJref, "ContIacWzskPrfDaemon");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskPrfDaemonData", "ContIacWzskPrfDaemon", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskPrfDaemonData", "FeedFPup302", srcdoc)) mask.push("feedFPup302");
	if (updateSrcblock(dom, "DpchEngWzskPrfDaemonData", "StatShrWzskPrfDaemon", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskPrfDaemonData", "TagWzskPrfDaemon", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskPrfDaemonData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskPrfDaemonData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Daemon");
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

			} else if (blk.nodeName == "DpchEngWzskPrfDaemonData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskPrfDaemon", "srefIxWzskVExpstate");

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
