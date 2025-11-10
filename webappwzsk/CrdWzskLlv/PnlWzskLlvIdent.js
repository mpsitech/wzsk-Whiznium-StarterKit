// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Ident", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Ident_side").setAttribute("height", "30");
	doc.getElementById("Ident_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Ident_side").src = "./PnlWzskLlvIdent_aside.html";
	doc.getElementById("Ident_cont").src = "./PnlWzskLlvIdent_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Ident_side").src = "./PnlWzskLlvIdent_bside.html";
	doc.getElementById("Ident_cont").src = "./PnlWzskLlvIdent_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Ident_side").contentDocument;
	contdoc = doc.getElementById("Ident_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvIdent", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Ident_side").contentDocument;
	contdoc = doc.getElementById("Ident_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Ident_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Ident_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvIdent", "Cpt"));
	initCpt(contcontdoc, "HdgVsp", retrieveTi(srcdoc, "TagWzskLlvIdent", "HdgVsp"));
	initCpt(contcontdoc, "CptVve", retrieveTi(srcdoc, "TagWzskLlvIdent", "CptVve"));
	initCpt(contcontdoc, "CptVgh", retrieveTi(srcdoc, "TagWzskLlvIdent", "CptVgh"));
	initCpt(contcontdoc, "CptVau", retrieveTi(srcdoc, "TagWzskLlvIdent", "CptVau"));
	initCpt(contcontdoc, "CptVfm", retrieveTi(srcdoc, "TagWzskLlvIdent", "CptVfm"));
	initCpt(contcontdoc, "CptVfd", retrieveTi(srcdoc, "TagWzskLlvIdent", "CptVfd"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvIdent", "srefIxWzskVExpstate");

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

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN

	refreshTxt(contcontdoc, "TxtVve", retrieveCi(srcdoc, "ContInfWzskLlvIdent", "TxtVve"));

	refreshTxt(contcontdoc, "TxtVgh", retrieveCi(srcdoc, "ContInfWzskLlvIdent", "TxtVgh"));

	refreshTxt(contcontdoc, "TxtVau", retrieveCi(srcdoc, "ContInfWzskLlvIdent", "TxtVau"));

	refreshTxt(contcontdoc, "TxtVfm", retrieveCi(srcdoc, "ContInfWzskLlvIdent", "TxtVfm"));

	refreshTxt(contcontdoc, "TxtVfd", retrieveCi(srcdoc, "ContInfWzskLlvIdent", "TxtVfd"));

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Ident", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Ident_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Ident_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Ident_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvIdent", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Ident_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvIdentDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskLlvIdentData", "ContInfWzskLlvIdent", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvIdentData", "StatShrWzskLlvIdent", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvIdentData", "TagWzskLlvIdent", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvIdentData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvIdent", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvIdent", "srefIxWzskVExpstate");

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
			if (blk.nodeName == "DpchEngWzskLlvIdentData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Ident");
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

			} else if (blk.nodeName == "DpchEngWzskLlvIdentData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvIdent", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvIdent", "srefIxWzskVExpstate");

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
