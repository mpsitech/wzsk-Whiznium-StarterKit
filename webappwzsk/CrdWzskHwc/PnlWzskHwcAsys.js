// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Asys", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Asys_side").setAttribute("height", "30");
	doc.getElementById("Asys_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Asys_side").src = "./PnlWzskHwcAsys_aside.html";
	doc.getElementById("Asys_cont").src = "./PnlWzskHwcAsys_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Asys_side").src = "./PnlWzskHwcAsys_bside.html";
	doc.getElementById("Asys_cont").src = "./PnlWzskHwcAsys_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Asys_side").contentDocument;
	contdoc = doc.getElementById("Asys_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskHwcAsys", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Asys_side").contentDocument;
	contdoc = doc.getElementById("Asys_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Asys_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Asys_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskHwcAsys", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcAsys", "srefIxWzskVExpstate");

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

	var height = 10; // full cont height

	// IP refreshBD.vars --- BEGIN
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	// IP refreshBD --- END

	getCrdwnd().changeHeight("Asys", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Asys_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Asys_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Asys_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcAsys", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Asys_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskHwcAsysDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskHwcAsysData", "StatShrWzskHwcAsys", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskHwcAsysData", "TagWzskHwcAsys", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskHwcAsysData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcAsys", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcAsys", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskHwcAsysData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Asys");
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

			} else if (blk.nodeName == "DpchEngWzskHwcAsysData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcAsys", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcAsys", "srefIxWzskVExpstate");

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
